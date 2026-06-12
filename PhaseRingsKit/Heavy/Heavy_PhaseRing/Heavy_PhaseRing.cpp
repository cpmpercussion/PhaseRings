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
  numBytes += sPhasor_k_init(&sPhasor_YLhzpjc3, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_GqJTzMCA);
  numBytes += sPhasor_k_init(&sPhasor_wblYp4M8, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_PcmCnHRn);
  numBytes += sLine_init(&sLine_gtfOXynq);
  numBytes += sLine_init(&sLine_CzagagvU);
  numBytes += sPhasor_k_init(&sPhasor_aaSixRuE, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_MFtpy3Td);
  numBytes += sPhasor_k_init(&sPhasor_0NxYHC5c, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_0wUxw68T);
  numBytes += sLine_init(&sLine_LjfijJlA);
  numBytes += sLine_init(&sLine_ujZTpKFI);
  numBytes += sPhasor_k_init(&sPhasor_nCjkyaID, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_V2J7zuro);
  numBytes += sPhasor_k_init(&sPhasor_Qrl4iP6g, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_1nlmdvZ2);
  numBytes += sLine_init(&sLine_B2v4PPDh);
  numBytes += sLine_init(&sLine_hJdquvdC);
  numBytes += sPhasor_k_init(&sPhasor_R9h1RyvC, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_9LoRcshy);
  numBytes += sPhasor_k_init(&sPhasor_eucO49s8, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_eHhhUdhj);
  numBytes += sLine_init(&sLine_b7IljXY7);
  numBytes += sLine_init(&sLine_PEXfcDRT);
  numBytes += sLine_init(&sLine_Iz6tpKSf);
  numBytes += sLine_init(&sLine_PGc5Wu08);
  numBytes += sPhasor_init(&sPhasor_Lh3wPkwN, sampleRate);
  numBytes += sLine_init(&sLine_EIuT2fqi);
  numBytes += sPhasor_k_init(&sPhasor_KNRXTitf, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_nxs8Ef8l);
  numBytes += sLine_init(&sLine_6mMfceYq);
  numBytes += sRPole_init(&sRPole_M5jnanQR);
  numBytes += sDel1_init(&sDel1_RSjZwAcN);
  numBytes += sLine_init(&sLine_7DBxaSxZ);
  numBytes += sLine_init(&sLine_MY97fxBV);
  numBytes += sLine_init(&sLine_GjTjo5pj);
  numBytes += sTabread_init(&sTabread_IVZ00RuP, &hTable_TuXtPgx8, true);
  numBytes += sRPole_init(&sRPole_LRBRWwfa);
  numBytes += sLine_init(&sLine_H1s5jzQD);
  numBytes += sLine_init(&sLine_8GD4kDMx);
  numBytes += sTabread_init(&sTabread_Eujxg9NG, &hTable_LXOlqpb1, true);
  numBytes += sTabwrite_init(&sTabwrite_YYvPKbAc, &hTable_z8AwhaVi);
  numBytes += sTabread_init(&sTabread_H5ZWsx5N, &hTable_z8AwhaVi, true);
  numBytes += sTabread_init(&sTabread_kFx6KNgb, &hTable_WFX1Ylce, true);
  numBytes += sTabread_init(&sTabread_ke43D03b, &hTable_TpMbhQ1X, true);
  numBytes += sTabread_init(&sTabread_XMB3MeyH, &hTable_aGikgZYl, true);
  numBytes += sTabwrite_init(&sTabwrite_bBhvLuhR, &hTable_CGDYuUWH);
  numBytes += sTabwrite_init(&sTabwrite_D30L1fhK, &hTable_TpMbhQ1X);
  numBytes += sTabwrite_init(&sTabwrite_WhmeSAUN, &hTable_aGikgZYl);
  numBytes += sTabwrite_init(&sTabwrite_opmtYadB, &hTable_LXOlqpb1);
  numBytes += sTabwrite_init(&sTabwrite_rq9uXTGZ, &hTable_WFX1Ylce);
  numBytes += sTabread_init(&sTabread_RxgBrKLe, &hTable_CGDYuUWH, true);
  numBytes += sTabread_init(&sTabread_u6b8GX5M, &hTable_AOmra5OL, true);
  numBytes += sRPole_init(&sRPole_PUzoATNx);
  numBytes += sTabread_init(&sTabread_uyFzNHzc, &hTable_NlwDZDpw, true);
  numBytes += sRPole_init(&sRPole_qgDBunIy);
  numBytes += sTabread_init(&sTabread_X44L1rbi, &hTable_piNFnJJ3, true);
  numBytes += sRPole_init(&sRPole_L7IsPDDg);
  numBytes += sTabwrite_init(&sTabwrite_d43dxlgp, &hTable_NlwDZDpw);
  numBytes += sLine_init(&sLine_ctBqfGM8);
  numBytes += sTabwrite_init(&sTabwrite_tl96AJr6, &hTable_piNFnJJ3);
  numBytes += sTabwrite_init(&sTabwrite_aBIvBVzR, &hTable_TuXtPgx8);
  numBytes += sTabwrite_init(&sTabwrite_He9AEVtp, &hTable_AOmra5OL);
  numBytes += sLine_init(&sLine_18onNJj2);
  numBytes += sTabwrite_init(&sTabwrite_RKxwGm7M, &hTable_T6MbkFIw);
  numBytes += sLine_init(&sLine_mpNzjmv6);
  numBytes += sPhasor_init(&sPhasor_QfiTVqux, sampleRate);
  numBytes += sLine_init(&sLine_SU16ZDGV);
  numBytes += sLine_init(&sLine_acy883LG);
  numBytes += sTabhead_init(&sTabhead_Ln83sILq, &hTable_T6MbkFIw);
  numBytes += sTabread_init(&sTabread_mEwwSNW6, &hTable_T6MbkFIw, false);
  numBytes += sTabread_init(&sTabread_QFAlJ2Jg, &hTable_T6MbkFIw, false);
  numBytes += sTabhead_init(&sTabhead_gN9JQH6K, &hTable_T6MbkFIw);
  numBytes += sTabread_init(&sTabread_cO7fR11o, &hTable_T6MbkFIw, false);
  numBytes += sTabread_init(&sTabread_PFaAMno9, &hTable_T6MbkFIw, false);
  numBytes += sLine_init(&sLine_JQgYV19Q);
  numBytes += sTabhead_init(&sTabhead_XQwIPWwy, &hTable_DNLO2Q6E);
  numBytes += sTabread_init(&sTabread_TIybe00l, &hTable_DNLO2Q6E, false);
  numBytes += sTabread_init(&sTabread_ydlCFgWu, &hTable_DNLO2Q6E, false);
  numBytes += sRPole_init(&sRPole_BchMQ7z3);
  numBytes += sDel1_init(&sDel1_Vb62tRPH);
  numBytes += sRPole_init(&sRPole_7slGirqZ);
  numBytes += sTabwrite_init(&sTabwrite_oqOZrV6L, &hTable_DNLO2Q6E);
  numBytes += sCPole_init(&sCPole_bIrObFVg);
  numBytes += sRPole_init(&sRPole_u7W1CXIK);
  numBytes += sRPole_init(&sRPole_gQe5I4Lp);
  numBytes += sRPole_init(&sRPole_V7h82KBc);
  numBytes += sTabread_init(&sTabread_RQZ3wiSK, &hTable_MRFeGKGv, true);
  numBytes += sRPole_init(&sRPole_5Jlf3VuJ);
  numBytes += sLine_init(&sLine_omlztVwW);
  numBytes += sLine_init(&sLine_gbFnM2vA);
  numBytes += sTabread_init(&sTabread_eb8bh5Tb, &hTable_Ihd8rU1e, true);
  numBytes += sTabread_init(&sTabread_OhUPHtZ3, &hTable_YJmhcxIZ, true);
  numBytes += sTabwrite_init(&sTabwrite_p3r4FpeY, &hTable_VCnxqSqb);
  numBytes += sTabread_init(&sTabread_C5jO4OKu, &hTable_vYYMVUJF, true);
  numBytes += sTabwrite_init(&sTabwrite_vIRt3Yqw, &hTable_YJmhcxIZ);
  numBytes += sTabwrite_init(&sTabwrite_uZ2TRHXw, &hTable_Ihd8rU1e);
  numBytes += sTabread_init(&sTabread_e97hKh4b, &hTable_VCnxqSqb, true);
  numBytes += sTabwrite_init(&sTabwrite_FK7ZY9Zc, &hTable_IthL2pSL);
  numBytes += sTabread_init(&sTabread_nnUdHZyE, &hTable_IthL2pSL, true);
  numBytes += sTabread_init(&sTabread_EdSrWJPJ, &hTable_nXPbjI1C, true);
  numBytes += sTabwrite_init(&sTabwrite_iTQ4HjJE, &hTable_nXPbjI1C);
  numBytes += sTabwrite_init(&sTabwrite_LGgBdvgv, &hTable_vYYMVUJF);
  numBytes += sTabread_init(&sTabread_82O8wVlI, &hTable_xZ2WvPm3, true);
  numBytes += sRPole_init(&sRPole_B7lzNCrH);
  numBytes += sTabread_init(&sTabread_u0MX4kT7, &hTable_HtQXdXmr, true);
  numBytes += sRPole_init(&sRPole_Pi73Oq4y);
  numBytes += sTabread_init(&sTabread_ZI44pPse, &hTable_tA7wg1bb, true);
  numBytes += sRPole_init(&sRPole_7v7RRa89);
  numBytes += sTabwrite_init(&sTabwrite_IfmKn09V, &hTable_tA7wg1bb);
  numBytes += sTabwrite_init(&sTabwrite_fsg929Ns, &hTable_MRFeGKGv);
  numBytes += sLine_init(&sLine_vkCreuW5);
  numBytes += sTabwrite_init(&sTabwrite_7Nv71mpj, &hTable_HtQXdXmr);
  numBytes += sTabwrite_init(&sTabwrite_5jS6srXY, &hTable_xZ2WvPm3);
  numBytes += sLine_init(&sLine_6Is0wh90);
  numBytes += sTabwrite_init(&sTabwrite_h4VFdmgT, &hTable_YXrQA3J2);
  numBytes += sLine_init(&sLine_qs88rzqe);
  numBytes += sPhasor_init(&sPhasor_tQkRkM77, sampleRate);
  numBytes += sLine_init(&sLine_VpW71EE8);
  numBytes += sLine_init(&sLine_mWidUMof);
  numBytes += sTabhead_init(&sTabhead_0dsQpGnI, &hTable_YXrQA3J2);
  numBytes += sTabread_init(&sTabread_dLS78BCo, &hTable_YXrQA3J2, false);
  numBytes += sTabread_init(&sTabread_vLcb7izi, &hTable_YXrQA3J2, false);
  numBytes += sTabhead_init(&sTabhead_ugdcdD7r, &hTable_YXrQA3J2);
  numBytes += sTabread_init(&sTabread_yWSJk6LL, &hTable_YXrQA3J2, false);
  numBytes += sTabread_init(&sTabread_JkOMGOF1, &hTable_YXrQA3J2, false);
  numBytes += sTabhead_init(&sTabhead_HUh5vLd1, &hTable_fKIxix2v);
  numBytes += sTabread_init(&sTabread_Nk71rIHa, &hTable_fKIxix2v, false);
  numBytes += sTabread_init(&sTabread_NXrzbNj7, &hTable_fKIxix2v, false);
  numBytes += sRPole_init(&sRPole_4IJwIwRB);
  numBytes += sDel1_init(&sDel1_cD8vYQ1P);
  numBytes += sLine_init(&sLine_jaBpt9ud);
  numBytes += sRPole_init(&sRPole_Bc20FFO8);
  numBytes += sTabwrite_init(&sTabwrite_oOJEOqMN, &hTable_fKIxix2v);
  numBytes += sLine_init(&sLine_kVQ0MSvK);
  numBytes += sLine_init(&sLine_u6q5iWUE);
  numBytes += cSlice_init(&cSlice_EMqz0gdS, 2, 1);
  numBytes += cSlice_init(&cSlice_4rF4lMsQ, 1, 1);
  numBytes += cSlice_init(&cSlice_PnjK9Ny3, 0, 1);
  numBytes += cVar_init_f(&cVar_Rz1THrHZ, 0.0f);
  numBytes += cIf_init(&cIf_p3xTiunM, false);
  numBytes += cIf_init(&cIf_hXqd1G7b, false);
  numBytes += cIf_init(&cIf_2gknZilc, false);
  numBytes += cIf_init(&cIf_odKTKfBP, false);
  numBytes += cIf_init(&cIf_asABAj4b, false);
  numBytes += cBinop_init(&cBinop_hgJfEikB, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_9CgrFmgG, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_NsY2i96y, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_5b8HQKK4, 5.0f);
  numBytes += cBinop_init(&cBinop_MvbUOE6c, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_eiAtJAV7, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_y8dncuUV, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_QBi57nCB, "floatatom");
  numBytes += cVar_init_s(&cVar_VY1RJkTf, "floatatom");
  numBytes += cIf_init(&cIf_j8wxsOsu, false);
  numBytes += cIf_init(&cIf_saBX0Tr8, false);
  numBytes += cIf_init(&cIf_RyS40cLD, false);
  numBytes += cIf_init(&cIf_5i6ETPTW, false);
  numBytes += cPack_init(&cPack_ZL0ffJl0, 2, 0.0f, 50.0f);
  numBytes += cPack_init(&cPack_DHkTv6Pi, 2, 0.0f, 80.0f);
  numBytes += cPack_init(&cPack_EXJdIf0H, 2, 0.0f, 50.0f);
  numBytes += cRandom_init(&cRandom_IiuiUccC, 1479280588);
  numBytes += cSlice_init(&cSlice_iMod558M, 1, 1);
  numBytes += cVar_init_s(&cVar_zcopOsvk, "floatatom");
  numBytes += cRandom_init(&cRandom_pxGDdggl, 1107905724);
  numBytes += cSlice_init(&cSlice_91ss4Qpz, 1, 1);
  numBytes += cVar_init_s(&cVar_L63sWGh7, "floatatom");
  numBytes += cVar_init_f(&cVar_46ywy8EG, 1.0f);
  numBytes += cVar_init_f(&cVar_nCTRzqbL, 0.0f);
  numBytes += cVar_init_f(&cVar_qEo0hsjx, 0.0f);
  numBytes += cRandom_init(&cRandom_a1fhRjgA, -341142462);
  numBytes += cSlice_init(&cSlice_c1HtEdxq, 1, 1);
  numBytes += cRandom_init(&cRandom_cVKoBcMM, -1035444672);
  numBytes += cSlice_init(&cSlice_LsCDhFTy, 1, 1);
  numBytes += cRandom_init(&cRandom_hPfhognO, 48424560);
  numBytes += cSlice_init(&cSlice_ty5cN7vu, 1, 1);
  numBytes += cBinop_init(&cBinop_zfE6ydR4, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_hx3o5pIP, -408304770);
  numBytes += cSlice_init(&cSlice_D5Ii3GbG, 1, 1);
  numBytes += cPack_init(&cPack_Q08XYhLX, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_O0ifSzPL, "floatatom");
  numBytes += cVar_init_s(&cVar_XXe4aOsj, "floatatom");
  numBytes += cVar_init_s(&cVar_jjcyPKhQ, "floatatom");
  numBytes += cVar_init_f(&cVar_CuLuBKX3, 0.0f);
  numBytes += cVar_init_s(&cVar_USN2S3rY, "floatatom");
  numBytes += cVar_init_s(&cVar_6PgH2iT3, "floatatom");
  numBytes += cVar_init_s(&cVar_DVPkcmop, "floatatom");
  numBytes += cDelay_init(this, &cDelay_RUex5Z1m, 25.0f);
  numBytes += cVar_init_f(&cVar_nh8kiC62, 0.0f);
  numBytes += sVarf_init(&sVarf_LqSJYykp, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_fgINsVdp, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_1xlBOZaL, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_mAE5DoaE, 1, 1);
  numBytes += cSlice_init(&cSlice_nOyokf8c, 0, 1);
  numBytes += cBinop_init(&cBinop_jwCjPNLR, 1.0f); // __mul
  numBytes += cVar_init_f(&cVar_BC9CteRo, 98.0f);
  numBytes += cIf_init(&cIf_YgeTeMXQ, false);
  numBytes += cBinop_init(&cBinop_WKFmhmNL, 0.0f); // __pow
  numBytes += cPack_init(&cPack_kIgi2xU2, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_ir9q0i3c, 0.0f);
  numBytes += cRandom_init(&cRandom_GCrMQcUE, 1218905658);
  numBytes += cSlice_init(&cSlice_ovoxmz8y, 1, 1);
  numBytes += cBinop_init(&cBinop_mRORqICk, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_tJX4MQRi, -844765408);
  numBytes += cSlice_init(&cSlice_SyzwJLFE, 1, 1);
  numBytes += cPack_init(&cPack_aYZNOk2j, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_6jAZbt2l, "floatatom");
  numBytes += cVar_init_s(&cVar_V8ct3CB6, "floatatom");
  numBytes += cVar_init_s(&cVar_AfeRKpIe, "floatatom");
  numBytes += cVar_init_f(&cVar_izyMlUoP, 0.0f);
  numBytes += cVar_init_s(&cVar_lF5sp862, "floatatom");
  numBytes += cVar_init_s(&cVar_B8O8L9sI, "floatatom");
  numBytes += cVar_init_s(&cVar_VREHNS77, "floatatom");
  numBytes += cDelay_init(this, &cDelay_U6Cak3ak, 25.0f);
  numBytes += cVar_init_f(&cVar_dpiVn9og, 0.0f);
  numBytes += sVarf_init(&sVarf_JsRzMHWd, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_9Rs22VvO, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_bpL6axXX, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_GHZlDtTM, 1, 1);
  numBytes += cSlice_init(&cSlice_I6lVVRIC, 0, 1);
  numBytes += cBinop_init(&cBinop_kXzfYu3E, 1.0f); // __mul
  numBytes += cRandom_init(&cRandom_ihKkZyPO, -100515316);
  numBytes += cSlice_init(&cSlice_KXe9xik7, 1, 1);
  numBytes += cBinop_init(&cBinop_DvQkykCf, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_xzqAzSUl, 358123132);
  numBytes += cSlice_init(&cSlice_yz8LlBy0, 1, 1);
  numBytes += cPack_init(&cPack_f4T9ZML1, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_QWxZqDZ9, "floatatom");
  numBytes += cVar_init_s(&cVar_jyVlA3J9, "floatatom");
  numBytes += cVar_init_s(&cVar_nCsacBBJ, "floatatom");
  numBytes += cVar_init_f(&cVar_JRUzHE8k, 0.0f);
  numBytes += cVar_init_s(&cVar_A4BGqHjh, "floatatom");
  numBytes += cVar_init_s(&cVar_URVh5iIh, "floatatom");
  numBytes += cVar_init_s(&cVar_6C985mw3, "floatatom");
  numBytes += cDelay_init(this, &cDelay_dgSC3OJ3, 25.0f);
  numBytes += cVar_init_f(&cVar_AfUQB6J5, 0.0f);
  numBytes += sVarf_init(&sVarf_6tKya33I, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_IwOawX5b, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_PZMNAqEr, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_ovDz7MNZ, 1, 1);
  numBytes += cSlice_init(&cSlice_AqMZxlgk, 0, 1);
  numBytes += cBinop_init(&cBinop_kP6Ij3Go, 1.0f); // __mul
  numBytes += cRandom_init(&cRandom_c2TTrsN9, 1752831495);
  numBytes += cSlice_init(&cSlice_mJ4uoAG3, 1, 1);
  numBytes += cBinop_init(&cBinop_BVhRq1tD, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_agFF2Fzj, 20129892);
  numBytes += cSlice_init(&cSlice_1i3HKFFn, 1, 1);
  numBytes += cPack_init(&cPack_iAkocxD1, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_xZvotm3O, "floatatom");
  numBytes += cVar_init_s(&cVar_Zn1ojjrH, "floatatom");
  numBytes += cVar_init_s(&cVar_le0crv9b, "floatatom");
  numBytes += cVar_init_f(&cVar_rufgXjP1, 0.0f);
  numBytes += cVar_init_s(&cVar_jQdVp78g, "floatatom");
  numBytes += cVar_init_s(&cVar_kFL9HD4I, "floatatom");
  numBytes += cVar_init_s(&cVar_qohOHo7T, "floatatom");
  numBytes += cDelay_init(this, &cDelay_Z7or4RMJ, 25.0f);
  numBytes += cVar_init_f(&cVar_TAwmTnvB, 0.0f);
  numBytes += sVarf_init(&sVarf_ZmzdwXRG, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_P3wS8A0I, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_SvkpEzkg, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_ktV5WUFT, 1, 1);
  numBytes += cSlice_init(&cSlice_FYFzJj9d, 0, 1);
  numBytes += cBinop_init(&cBinop_lCXujieJ, 1.0f); // __mul
  numBytes += cTabhead_init(&cTabhead_DLiYW0yc, &hTable_TuXtPgx8);
  numBytes += cVar_init_s(&cVar_0FiP8cTk, "del-1209-del1");
  numBytes += cDelay_init(this, &cDelay_J1nxD7Bo, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_ynEaXzHI, 0.0f);
  numBytes += cBinop_init(&cBinop_82fhNWaF, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_NqTOrbfD, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_f253eZ1l, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_aAcUWa8w, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_dQ3czwaE, &hTable_AOmra5OL);
  numBytes += cVar_init_s(&cVar_dcr34w93, "del-1209-del2");
  numBytes += cDelay_init(this, &cDelay_kNVLE49t, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_79wgKxRv, 0.0f);
  numBytes += cBinop_init(&cBinop_kZN1w8N7, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_DIJs7fzR, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Sui3wf8E, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_XqozhxqE, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_71Es4iyb, &hTable_NlwDZDpw);
  numBytes += cVar_init_s(&cVar_VTNOHwN0, "del-1209-del3");
  numBytes += cDelay_init(this, &cDelay_YozViMxW, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_ceMPUcYw, 0.0f);
  numBytes += cBinop_init(&cBinop_StASdPUz, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_XbU0e5cR, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_CJNK44x7, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_aJbMkgtr, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_kLk2DX0g, &hTable_piNFnJJ3);
  numBytes += cVar_init_s(&cVar_gYbFrBc4, "del-1209-del4");
  numBytes += cDelay_init(this, &cDelay_TqEc0I18, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_PuPI2lIz, 0.0f);
  numBytes += cBinop_init(&cBinop_qyTvtMHX, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_poDeI2Li, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_DEuc7UtW, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_SZlyNABT, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_hnYy2tkb, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ZnFQ5VXv, 0.0f);
  numBytes += hTable_init(&hTable_TuXtPgx8, 256);
  numBytes += cDelay_init(this, &cDelay_TKspi2Jg, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Majfm0GP, 0.0f);
  numBytes += hTable_init(&hTable_AOmra5OL, 256);
  numBytes += cDelay_init(this, &cDelay_MlACp4XR, 0.0f);
  numBytes += cDelay_init(this, &cDelay_mzXO9VTJ, 0.0f);
  numBytes += hTable_init(&hTable_NlwDZDpw, 256);
  numBytes += cDelay_init(this, &cDelay_gR2oKeIp, 0.0f);
  numBytes += cDelay_init(this, &cDelay_rLxoq68Z, 0.0f);
  numBytes += hTable_init(&hTable_piNFnJJ3, 256);
  numBytes += cIf_init(&cIf_G4UDRA8G, false);
  numBytes += cBinop_init(&cBinop_dJXlauGI, 0.0f); // __pow
  numBytes += cPack_init(&cPack_5IuQexcn, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_EJeLmYVW, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_79eXwPNq, 22050.0f);
  numBytes += cBinop_init(&cBinop_eYfmPTZr, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_C6AFUrsM, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_e1PsRhKq, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_KynI9x7n, 95.0f);
  numBytes += cVar_init_f(&cVar_cmJe2ZF3, 90.0f);
  numBytes += cVar_init_f(&cVar_UUn8tahx, 6000.0f);
  numBytes += cVar_init_f(&cVar_AuTsPu8K, 60.0f);
  numBytes += cIf_init(&cIf_pVu6zRuu, false);
  numBytes += cTabhead_init(&cTabhead_heIpMdiJ, &hTable_CGDYuUWH);
  numBytes += cVar_init_s(&cVar_PQNSHPhM, "del-1209-ref6");
  numBytes += cDelay_init(this, &cDelay_1ACwtKEg, 13.645f);
  numBytes += cDelay_init(this, &cDelay_6fo4mxtY, 0.0f);
  numBytes += cBinop_init(&cBinop_ckz66LTI, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_LLQSv5U0, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_I80szfDg, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_fQgV9Mao, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_w3fySz3T, 0.0f);
  numBytes += cDelay_init(this, &cDelay_WrjWro5Y, 0.0f);
  numBytes += hTable_init(&hTable_CGDYuUWH, 256);
  numBytes += cTabhead_init(&cTabhead_lb5cMSir, &hTable_aGikgZYl);
  numBytes += cVar_init_s(&cVar_3NAiTsmS, "del-1209-ref5");
  numBytes += cDelay_init(this, &cDelay_bVVlBJoS, 16.364f);
  numBytes += cDelay_init(this, &cDelay_uWoGdxz8, 0.0f);
  numBytes += cBinop_init(&cBinop_qimXY1rv, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_90btGSnx, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_xdeW7YyO, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_RWK9duXY, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_iXWNXdBr, 0.0f);
  numBytes += cDelay_init(this, &cDelay_zlt5GtL1, 0.0f);
  numBytes += hTable_init(&hTable_aGikgZYl, 256);
  numBytes += cTabhead_init(&cTabhead_T8w4BbxS, &hTable_TpMbhQ1X);
  numBytes += cVar_init_s(&cVar_ARLoyoKS, "del-1209-ref4");
  numBytes += cDelay_init(this, &cDelay_eLgPr4Lb, 19.392f);
  numBytes += cDelay_init(this, &cDelay_qvgNlC3p, 0.0f);
  numBytes += cBinop_init(&cBinop_8cj8AfBJ, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_ThGNXxTN, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_GkIAmfP8, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_fFH97gwZ, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_2dRHIFgL, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Q7EZs7Yj, 0.0f);
  numBytes += hTable_init(&hTable_TpMbhQ1X, 256);
  numBytes += cTabhead_init(&cTabhead_A7o0J11Z, &hTable_WFX1Ylce);
  numBytes += cVar_init_s(&cVar_Ww33Z3B8, "del-1209-ref3");
  numBytes += cDelay_init(this, &cDelay_yPv4XDiN, 25.796f);
  numBytes += cDelay_init(this, &cDelay_DRyTmypg, 0.0f);
  numBytes += cBinop_init(&cBinop_kBRGOmSe, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_SeWjqHEN, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_gjWlTd1g, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_K5LR0nmw, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_VPA9eOP7, 0.0f);
  numBytes += cDelay_init(this, &cDelay_iQWRFpbP, 0.0f);
  numBytes += hTable_init(&hTable_WFX1Ylce, 256);
  numBytes += cTabhead_init(&cTabhead_F50fcYF4, &hTable_z8AwhaVi);
  numBytes += cVar_init_s(&cVar_VmmijPxO, "del-1209-ref2");
  numBytes += cDelay_init(this, &cDelay_F78RwXD6, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_uqKw2Zl3, 0.0f);
  numBytes += cBinop_init(&cBinop_N8pmwXwC, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_1earnbJr, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Nj6DFvLz, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_NG1rA9r2, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_aUxfDSsm, 0.0f);
  numBytes += cDelay_init(this, &cDelay_eOHSLqSm, 0.0f);
  numBytes += hTable_init(&hTable_z8AwhaVi, 256);
  numBytes += cTabhead_init(&cTabhead_ol9BBsMZ, &hTable_LXOlqpb1);
  numBytes += cVar_init_s(&cVar_QfPiEje7, "del-1209-ref1");
  numBytes += cDelay_init(this, &cDelay_2BrDd1Iv, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_U5sCCMFt, 0.0f);
  numBytes += cBinop_init(&cBinop_OTsyF41f, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_RlHAjnoq, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_rgW0CU60, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_uwVSXi1B, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_qr1ym9Ka, 0.0f);
  numBytes += cDelay_init(this, &cDelay_kZwUvbFE, 0.0f);
  numBytes += hTable_init(&hTable_LXOlqpb1, 256);
  numBytes += cVar_init_f(&cVar_u6GT8Qwv, 0.0f);
  numBytes += cVar_init_f(&cVar_WY3sTZvf, 0.0f);
  numBytes += cPack_init(&cPack_ai1jlsln, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_3ebC2MQw, 22050.0f);
  numBytes += cBinop_init(&cBinop_6bkVM1yt, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_e1Ej1zl2, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_kU0eP2xM, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_HHodeCyW, 22050.0f);
  numBytes += cBinop_init(&cBinop_6F176PMn, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_BQdvT4G6, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_GGMNXada, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_wslmKKEl, 22050.0f);
  numBytes += cBinop_init(&cBinop_zLVv9BmV, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_TI4E0lh3, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Al05hapz, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_hBhJPRe4, false);
  numBytes += cDelay_init(this, &cDelay_Vq1Yeauh, 50.0f);
  numBytes += cVar_init_f(&cVar_PTvS0Ga7, 0.0f);
  numBytes += cVar_init_f(&cVar_VeweU8cf, 12.0f);
  numBytes += cVar_init_s(&cVar_btFEdWc4, "floatatom");
  numBytes += cPack_init(&cPack_C8jbLjm2, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_JkppSsnT, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_IIsJ74BK, "floatatom");
  numBytes += cDelay_init(this, &cDelay_IeWufIYH, 0.0f);
  numBytes += cDelay_init(this, &cDelay_DvAyh2AD, 0.0f);
  numBytes += hTable_init(&hTable_T6MbkFIw, 256);
  numBytes += cVar_init_s(&cVar_VeDuEHXS, "del-1316-del");
  numBytes += sVarf_init(&sVarf_ICOjh6aN, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9MAvnJZr, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_x0YG7uKC, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_eOpK91eD, "del-1316-del");
  numBytes += sVarf_init(&sVarf_7IIeHIti, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_2xUpWFOi, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_P2rfj2uf, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_D2mqMoBp, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_V8U2V56F, 4720.0f);
  numBytes += cBinop_init(&cBinop_RNthU5G9, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_i8SKQmQs, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_L0gANi0M, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_vt9w4O4j, 4720.0f);
  numBytes += cBinop_init(&cBinop_wxX3AjuN, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_lGSq1CVg, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_SaBDUhQk, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_KJy5h15i, 4720.0f);
  numBytes += cBinop_init(&cBinop_onIDdbjZ, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_JjPn5IOz, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_FOWYkAfr, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_c4leJELR, 1.0f);
  numBytes += cIf_init(&cIf_STKaQSPO, false);
  numBytes += sVarf_init(&sVarf_1d3SEdZJ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_S6V2pqU1, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ivtoCaaK, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_LqC25vyA, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_rJYLNPto, 4720.0f, 0.0f, false);
  numBytes += cTabhead_init(&cTabhead_lOupEdQR, &hTable_MRFeGKGv);
  numBytes += cVar_init_s(&cVar_5Int7Eww, "del-1379-del1");
  numBytes += cDelay_init(this, &cDelay_6Ml2QKwo, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_Th0OAbYU, 0.0f);
  numBytes += cBinop_init(&cBinop_EgR7aQyw, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_G4enNZXX, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_JxPNQRyU, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_3LyMW30U, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_6FU7ijsM, &hTable_xZ2WvPm3);
  numBytes += cVar_init_s(&cVar_g0Qcphhf, "del-1379-del2");
  numBytes += cDelay_init(this, &cDelay_7i4fmIt3, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_eEDxcHme, 0.0f);
  numBytes += cBinop_init(&cBinop_z8bvsrEq, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_SSWJflNi, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_89Y0qi5S, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_VNVpctEx, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_wiTpTbLI, &hTable_HtQXdXmr);
  numBytes += cVar_init_s(&cVar_QqD0MpYN, "del-1379-del3");
  numBytes += cDelay_init(this, &cDelay_XBJx0zKQ, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_gvmCffhO, 0.0f);
  numBytes += cBinop_init(&cBinop_poh3Ckgf, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_NAJOJKuS, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_wtirJLRU, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_EHLtzLOc, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_mbFM2wzE, &hTable_tA7wg1bb);
  numBytes += cVar_init_s(&cVar_Lir9aKYE, "del-1379-del4");
  numBytes += cDelay_init(this, &cDelay_ZtOJ3UXg, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_5ICExi00, 0.0f);
  numBytes += cBinop_init(&cBinop_GilxHTcB, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_Bzfl9u96, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_MsB7RNEz, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_1cPikJQS, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_WNLGblAw, 0.0f);
  numBytes += cDelay_init(this, &cDelay_uU6GJ8re, 0.0f);
  numBytes += hTable_init(&hTable_MRFeGKGv, 256);
  numBytes += cDelay_init(this, &cDelay_kqeZyXEj, 0.0f);
  numBytes += cDelay_init(this, &cDelay_mb0EJZND, 0.0f);
  numBytes += hTable_init(&hTable_xZ2WvPm3, 256);
  numBytes += cDelay_init(this, &cDelay_Knj7evc2, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Du1tCGd4, 0.0f);
  numBytes += hTable_init(&hTable_HtQXdXmr, 256);
  numBytes += cDelay_init(this, &cDelay_otqKPZHd, 0.0f);
  numBytes += cDelay_init(this, &cDelay_wuxy6YJR, 0.0f);
  numBytes += hTable_init(&hTable_tA7wg1bb, 256);
  numBytes += cIf_init(&cIf_KTYymZwO, false);
  numBytes += cBinop_init(&cBinop_X6muOth1, 0.0f); // __pow
  numBytes += cPack_init(&cPack_4sH5AWzX, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_g6JH5Xab, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_aNKDDy1w, 22050.0f);
  numBytes += cBinop_init(&cBinop_B7xEYXrU, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_rPo0atmS, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_feZCPZrm, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_JFGPsHUn, 100.0f);
  numBytes += cVar_init_f(&cVar_3YopkI0B, 95.0f);
  numBytes += cVar_init_f(&cVar_Frl5U0tE, 14400.0f);
  numBytes += cVar_init_f(&cVar_ArNlzdTb, 60.0f);
  numBytes += cIf_init(&cIf_5hrMSHjI, false);
  numBytes += cTabhead_init(&cTabhead_DS4N6Am4, &hTable_vYYMVUJF);
  numBytes += cVar_init_s(&cVar_CyZwKvwG, "del-1379-ref6");
  numBytes += cDelay_init(this, &cDelay_kzeQGEWX, 13.645f);
  numBytes += cDelay_init(this, &cDelay_eP92M7yI, 0.0f);
  numBytes += cBinop_init(&cBinop_hfBwD0ul, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_JaJAqPJ1, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_jOZg8GKF, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_r5QMKXHk, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_U0KGgaVu, 0.0f);
  numBytes += cDelay_init(this, &cDelay_g49bXLsX, 0.0f);
  numBytes += hTable_init(&hTable_vYYMVUJF, 256);
  numBytes += cTabhead_init(&cTabhead_B8rsFDCy, &hTable_nXPbjI1C);
  numBytes += cVar_init_s(&cVar_4SIWhr2j, "del-1379-ref5");
  numBytes += cDelay_init(this, &cDelay_XKYrkvpC, 16.364f);
  numBytes += cDelay_init(this, &cDelay_fUsvd0uS, 0.0f);
  numBytes += cBinop_init(&cBinop_ywh5Astp, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_bMr6R5go, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Q2XDi7go, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_tpsURXEj, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_lfIcRWtT, 0.0f);
  numBytes += cDelay_init(this, &cDelay_qi7CmTpO, 0.0f);
  numBytes += hTable_init(&hTable_nXPbjI1C, 256);
  numBytes += cTabhead_init(&cTabhead_3Q6pQxtF, &hTable_IthL2pSL);
  numBytes += cVar_init_s(&cVar_FvajntIJ, "del-1379-ref4");
  numBytes += cDelay_init(this, &cDelay_xG4Rq4hx, 19.392f);
  numBytes += cDelay_init(this, &cDelay_SRvDEJQQ, 0.0f);
  numBytes += cBinop_init(&cBinop_3jqA1lV6, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_29LIlaOf, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_tyHRiS7V, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_Ikzopo2u, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_Y16RGS3Z, 0.0f);
  numBytes += cDelay_init(this, &cDelay_H06iYQaY, 0.0f);
  numBytes += hTable_init(&hTable_IthL2pSL, 256);
  numBytes += cTabhead_init(&cTabhead_QPRA0xEU, &hTable_VCnxqSqb);
  numBytes += cVar_init_s(&cVar_Vm0EydV4, "del-1379-ref3");
  numBytes += cDelay_init(this, &cDelay_be1p6Scl, 25.796f);
  numBytes += cDelay_init(this, &cDelay_gQ3a2Y3o, 0.0f);
  numBytes += cBinop_init(&cBinop_MOQyvpVD, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_SR7hPznG, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_uPF21F3t, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_VyRFaIWy, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_RWHaRdz0, 0.0f);
  numBytes += cDelay_init(this, &cDelay_4Lw6qBIL, 0.0f);
  numBytes += hTable_init(&hTable_VCnxqSqb, 256);
  numBytes += cTabhead_init(&cTabhead_nsk9h2Kd, &hTable_YJmhcxIZ);
  numBytes += cVar_init_s(&cVar_1pKxZobp, "del-1379-ref2");
  numBytes += cDelay_init(this, &cDelay_fb0luNIj, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_ZiHqnTvy, 0.0f);
  numBytes += cBinop_init(&cBinop_gAyoEMk9, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_BYwSiFqd, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_bez6MEJQ, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_SZLN7VJY, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_DAnn0CIu, 0.0f);
  numBytes += cDelay_init(this, &cDelay_23FcSf5Q, 0.0f);
  numBytes += hTable_init(&hTable_YJmhcxIZ, 256);
  numBytes += cTabhead_init(&cTabhead_gkZkViIT, &hTable_Ihd8rU1e);
  numBytes += cVar_init_s(&cVar_NyaNfLkA, "del-1379-ref1");
  numBytes += cDelay_init(this, &cDelay_BlCn8kRL, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_9j5lZpzC, 0.0f);
  numBytes += cBinop_init(&cBinop_iMw3JeXZ, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_pCdhdlef, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_hiFY5jud, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_kKgj26mj, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_vCVoF8Y6, 0.0f);
  numBytes += cDelay_init(this, &cDelay_VoRz2Y14, 0.0f);
  numBytes += hTable_init(&hTable_Ihd8rU1e, 256);
  numBytes += cVar_init_f(&cVar_RAc1gTQk, 0.0f);
  numBytes += cVar_init_f(&cVar_rHnsJZmF, 0.0f);
  numBytes += cPack_init(&cPack_F8HuyRy2, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_uJPgy3G3, 22050.0f);
  numBytes += cBinop_init(&cBinop_Wg55a7ii, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_E5XOmBsT, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ViC9Xs9H, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_n0OW9d5Z, 22050.0f);
  numBytes += cBinop_init(&cBinop_IFEzmF3u, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_dsfmIaoo, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_CbW8VNEK, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_xOKOV2RP, 22050.0f);
  numBytes += cBinop_init(&cBinop_7gFXNw8h, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_pfe4rM8M, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_JqiunZdB, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_5fedlGmy, "del-1478-del1");
  numBytes += sVarf_init(&sVarf_sucPMcJm, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_rSZruvN3, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_3e28mQa2, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_OrIWR535, 10000.0f);
  numBytes += cBinop_init(&cBinop_DuvZOjuv, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_7NwAu0fS, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9Mx8pfod, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_M29kU6Ow, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_g2lHkJLb, 10.0f);
  numBytes += cBinop_init(&cBinop_7cdUX4Hn, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_p26kg6N6, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_oHtZFmjA, "floatatom");
  numBytes += sVarf_init(&sVarf_jh9kKfih, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_yjChgp9C, 0.0f);
  numBytes += cDelay_init(this, &cDelay_a02YFaxE, 0.0f);
  numBytes += hTable_init(&hTable_DNLO2Q6E, 256);
  numBytes += sVarf_init(&sVarf_JPi9YWMY, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_rA537VEj, 2, 0.0f, 50.0f);
  numBytes += cRandom_init(&cRandom_HvwSu4XL, -936999322);
  numBytes += cSlice_init(&cSlice_biJIdm5H, 1, 1);
  numBytes += cRandom_init(&cRandom_MNudm50C, 1098670691);
  numBytes += cSlice_init(&cSlice_QRXbXQQW, 1, 1);
  numBytes += cVar_init_s(&cVar_xwGG8QW5, "floatatom");
  numBytes += cPack_init(&cPack_yuwhPqdi, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_qlL0gyAz, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_JkevEWcv, "floatatom");
  numBytes += cDelay_init(this, &cDelay_5Xwi4n0H, 0.0f);
  numBytes += cDelay_init(this, &cDelay_fB1okubc, 0.0f);
  numBytes += hTable_init(&hTable_YXrQA3J2, 256);
  numBytes += cVar_init_s(&cVar_hJUM360N, "del-1509-del");
  numBytes += sVarf_init(&sVarf_FmB6mlpz, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_hW0ewuZF, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_luxKZucm, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_TvRTzorQ, "del-1509-del");
  numBytes += sVarf_init(&sVarf_R3BZRvfh, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_pmTy7lUW, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_a3KXb97M, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_7TH5z89n, 0.0f); // __div
  numBytes += cVar_init_s(&cVar_KlMuSvkx, "del-1538-del1");
  numBytes += sVarf_init(&sVarf_bjA8VCxW, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_QzYNScNw, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_PltB3Fk5, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Zh5CpgkH, 10000.0f);
  numBytes += cBinop_init(&cBinop_O473cBaw, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_M5amLB0o, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_0g88X1M5, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_XIYPjXY5, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_AEqntZmC, 10.0f);
  numBytes += cBinop_init(&cBinop_R6n18KOG, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_S8KU7ipB, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_BrocUyyB, "floatatom");
  numBytes += sVarf_init(&sVarf_Bs3iy6Sp, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_ac50Efso, 0.0f);
  numBytes += cDelay_init(this, &cDelay_M55PrVFx, 0.0f);
  numBytes += hTable_init(&hTable_fKIxix2v, 256);
  numBytes += sVarf_init(&sVarf_psdgXSjI, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_HF7FDcRU, "floatatom");
  numBytes += cDelay_init(this, &cDelay_5VVWbTi9, 0.0f);
  numBytes += cVar_init_f(&cVar_uFOa9EQn, 20.0f);
  numBytes += cBinop_init(&cBinop_ZEQhUT0Z, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_KSnh2VrC, 0.0f);
  numBytes += cSlice_init(&cSlice_4sIYZMJp, 1, -1);
  numBytes += cSlice_init(&cSlice_Y8Q2VQj4, 1, -1);
  numBytes += cVar_init_f(&cVar_3jPkLwWE, 0.0f);
  numBytes += cVar_init_f(&cVar_Q5I7LvD0, 20.0f);
  numBytes += cVar_init_f(&cVar_Ew8y3Pqu, 0.0f);
  numBytes += cVar_init_f(&cVar_sY9h96TW, 0.0f);
  numBytes += cVar_init_f(&cVar_BP56wJJS, 0.0f);
  numBytes += cSlice_init(&cSlice_x1HTqWzf, 1, 1);
  numBytes += cSlice_init(&cSlice_SqvdjTIO, 0, 1);
  numBytes += cBinop_init(&cBinop_Qtn5eL32, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_AsD9WQLh, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_RQIF9pvT, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_KmtnFRlu, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_WV8A1mpm, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_ipSKlgrs, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_rgtzVtD7, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_0KdTGCJk, 0.0f); // __sub
  numBytes += cVar_init_s(&cVar_2n48kWdV, "floatatom");
  numBytes += cDelay_init(this, &cDelay_CWZ6YOKN, 0.0f);
  numBytes += cVar_init_f(&cVar_NbGYCTWS, 20.0f);
  numBytes += cBinop_init(&cBinop_LzZ3jb9S, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_lEWVh9jG, 0.0f);
  numBytes += cSlice_init(&cSlice_q5CxM0qO, 1, -1);
  numBytes += cSlice_init(&cSlice_8GoZ6z8r, 1, -1);
  numBytes += cVar_init_f(&cVar_0Olyx67a, 0.0f);
  numBytes += cVar_init_f(&cVar_YLXidWTk, 20.0f);
  numBytes += cVar_init_f(&cVar_rWD7gUpk, 0.0f);
  numBytes += cVar_init_f(&cVar_EuKe5ds4, 0.0f);
  numBytes += cVar_init_f(&cVar_Q2qa3OOn, 0.0f);
  numBytes += cSlice_init(&cSlice_uZPb4ILg, 1, 1);
  numBytes += cSlice_init(&cSlice_4R64yKcd, 0, 1);
  numBytes += cBinop_init(&cBinop_BRYOudv7, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_v150O8Xv, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_ItDszn1u, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_w6MBCZjV, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_nzGgo9XU, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_Fajl8BNj, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_THSDvJ2Q, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_7ivKcniV, 0.0f); // __sub
  numBytes += cPack_init(&cPack_T02v7nQ9, 2, 0.0f, 1000.0f);
  numBytes += cPack_init(&cPack_0tHQGQug, 2, 0.0f, 1000.0f);
  numBytes += cPack_init(&cPack_DtPhvPah, 2, 0.0f, 1000.0f);
  numBytes += cVar_init_f(&cVar_2Vwtbwn1, 100.0f);
  numBytes += cIf_init(&cIf_8GBw3dsw, false);
  numBytes += cBinop_init(&cBinop_w5XBQqBX, 0.0f); // __pow
  numBytes += cPack_init(&cPack_WRoR86Nx, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_PIqMfTiA, 0.0f);
  numBytes += cVar_init_f(&cVar_PmTLRsbz, 100.0f);
  numBytes += cIf_init(&cIf_cSvRoqKo, false);
  numBytes += cBinop_init(&cBinop_J6MEm3ou, 0.0f); // __pow
  numBytes += cPack_init(&cPack_kly4W6gL, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_loB0dJrP, 0.0f);
  numBytes += cIf_init(&cIf_eaz7SeMm, false);
  numBytes += cIf_init(&cIf_EiNO2F5N, false);
  numBytes += cVar_init_f(&cVar_iiLdsRJw, 97.0f);
  numBytes += cIf_init(&cIf_7snAldA2, false);
  numBytes += cBinop_init(&cBinop_gs8ZreSM, 0.0f); // __pow
  numBytes += cPack_init(&cPack_7Bb6MkkD, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_8z9Pseml, 0.0f);
  numBytes += cVar_init_f(&cVar_mUArOlqK, 89.0f);
  numBytes += cIf_init(&cIf_uH4vKDRv, false);
  numBytes += cBinop_init(&cBinop_Z2DLbpH9, 0.0f); // __pow
  numBytes += cPack_init(&cPack_qqwJdVRt, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_V7IicSMQ, 0.0f);
  numBytes += cVar_init_f(&cVar_g1TbQbno, 97.0f);
  numBytes += cIf_init(&cIf_wg92yDLt, false);
  numBytes += cBinop_init(&cBinop_19MtzG5q, 0.0f); // __pow
  numBytes += cPack_init(&cPack_QZTG8pD2, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_ZnRuqqxT, 0.0f);
  numBytes += cPack_init(&cPack_7vnpFwWQ, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_BIA73XbY, 1, 1);
  numBytes += cSlice_init(&cSlice_uan6vIB7, 0, 1);
  numBytes += cIf_init(&cIf_899dCYGS, false);
  numBytes += cIf_init(&cIf_eOKUIqlV, false);
  numBytes += cIf_init(&cIf_Tky2vR8S, false);
  numBytes += cSlice_init(&cSlice_rPJtY3Av, 1, 1);
  numBytes += cSlice_init(&cSlice_iep9NulX, 0, 1);
  numBytes += cVar_init_f(&cVar_RVOrQXuy, 0.0f);
  numBytes += cIf_init(&cIf_30tQoujw, false);
  numBytes += cPack_init(&cPack_hmWBbNn7, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_uzWvTynq, 1, -1);
  numBytes += cSlice_init(&cSlice_N2oaa2E2, 1, -1);
  numBytes += cSlice_init(&cSlice_MDr4RZ6v, 1, -1);
  numBytes += cSlice_init(&cSlice_LPTJYrUI, 1, -1);
  numBytes += cIf_init(&cIf_8XwV0nHB, false);
  numBytes += cVar_init_f(&cVar_t5Mweajk, 1.0f);
  numBytes += cPack_init(&cPack_KJ32jbcx, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_B8wk0zVr, 0.0f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_PhaseRing::~Heavy_PhaseRing() {
  cPack_free(&cPack_y8dncuUV);
  cPack_free(&cPack_ZL0ffJl0);
  cPack_free(&cPack_DHkTv6Pi);
  cPack_free(&cPack_EXJdIf0H);
  cPack_free(&cPack_Q08XYhLX);
  cPack_free(&cPack_fgINsVdp);
  cPack_free(&cPack_1xlBOZaL);
  cPack_free(&cPack_kIgi2xU2);
  cPack_free(&cPack_aYZNOk2j);
  cPack_free(&cPack_9Rs22VvO);
  cPack_free(&cPack_bpL6axXX);
  cPack_free(&cPack_f4T9ZML1);
  cPack_free(&cPack_IwOawX5b);
  cPack_free(&cPack_PZMNAqEr);
  cPack_free(&cPack_iAkocxD1);
  cPack_free(&cPack_P3wS8A0I);
  cPack_free(&cPack_SvkpEzkg);
  hTable_free(&hTable_TuXtPgx8);
  hTable_free(&hTable_AOmra5OL);
  hTable_free(&hTable_NlwDZDpw);
  hTable_free(&hTable_piNFnJJ3);
  cPack_free(&cPack_5IuQexcn);
  cPack_free(&cPack_EJeLmYVW);
  hTable_free(&hTable_CGDYuUWH);
  hTable_free(&hTable_aGikgZYl);
  hTable_free(&hTable_TpMbhQ1X);
  hTable_free(&hTable_WFX1Ylce);
  hTable_free(&hTable_z8AwhaVi);
  hTable_free(&hTable_LXOlqpb1);
  cPack_free(&cPack_ai1jlsln);
  cPack_free(&cPack_C8jbLjm2);
  cPack_free(&cPack_JkppSsnT);
  hTable_free(&hTable_T6MbkFIw);
  hTable_free(&hTable_MRFeGKGv);
  hTable_free(&hTable_xZ2WvPm3);
  hTable_free(&hTable_HtQXdXmr);
  hTable_free(&hTable_tA7wg1bb);
  cPack_free(&cPack_4sH5AWzX);
  cPack_free(&cPack_g6JH5Xab);
  hTable_free(&hTable_vYYMVUJF);
  hTable_free(&hTable_nXPbjI1C);
  hTable_free(&hTable_IthL2pSL);
  hTable_free(&hTable_VCnxqSqb);
  hTable_free(&hTable_YJmhcxIZ);
  hTable_free(&hTable_Ihd8rU1e);
  cPack_free(&cPack_F8HuyRy2);
  hTable_free(&hTable_DNLO2Q6E);
  cPack_free(&cPack_rA537VEj);
  cPack_free(&cPack_yuwhPqdi);
  cPack_free(&cPack_qlL0gyAz);
  hTable_free(&hTable_YXrQA3J2);
  hTable_free(&hTable_fKIxix2v);
  cPack_free(&cPack_T02v7nQ9);
  cPack_free(&cPack_0tHQGQug);
  cPack_free(&cPack_DtPhvPah);
  cPack_free(&cPack_WRoR86Nx);
  cPack_free(&cPack_kly4W6gL);
  cPack_free(&cPack_7Bb6MkkD);
  cPack_free(&cPack_qqwJdVRt);
  cPack_free(&cPack_QZTG8pD2);
  cPack_free(&cPack_7vnpFwWQ);
  cPack_free(&cPack_hmWBbNn7);
  cPack_free(&cPack_KJ32jbcx);
}

HvTable *Heavy_PhaseRing::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0xF96F9CBC: return &hTable_TuXtPgx8; // del-1209-del1
    case 0xEAD79ADF: return &hTable_AOmra5OL; // del-1209-del2
    case 0xB1129AA0: return &hTable_NlwDZDpw; // del-1209-del3
    case 0x4F62B33F: return &hTable_piNFnJJ3; // del-1209-del4
    case 0x36047BDC: return &hTable_CGDYuUWH; // del-1209-ref6
    case 0x66BE8A1D: return &hTable_aGikgZYl; // del-1209-ref5
    case 0xD4C64222: return &hTable_TpMbhQ1X; // del-1209-ref4
    case 0xC5A2B81B: return &hTable_WFX1Ylce; // del-1209-ref3
    case 0xE629D5: return &hTable_z8AwhaVi; // del-1209-ref2
    case 0x912EE503: return &hTable_LXOlqpb1; // del-1209-ref1
    case 0xFBB0E240: return &hTable_T6MbkFIw; // del-1316-del
    case 0xDB23006E: return &hTable_MRFeGKGv; // del-1379-del1
    case 0x71D4109E: return &hTable_xZ2WvPm3; // del-1379-del2
    case 0x3209AF80: return &hTable_HtQXdXmr; // del-1379-del3
    case 0x243F6DE3: return &hTable_tA7wg1bb; // del-1379-del4
    case 0x57CE1FFD: return &hTable_vYYMVUJF; // del-1379-ref6
    case 0xE6EB4810: return &hTable_nXPbjI1C; // del-1379-ref5
    case 0x1A778356: return &hTable_IthL2pSL; // del-1379-ref4
    case 0xEAC5B9C7: return &hTable_VCnxqSqb; // del-1379-ref3
    case 0x59B93D98: return &hTable_YJmhcxIZ; // del-1379-ref2
    case 0x29741CDA: return &hTable_Ihd8rU1e; // del-1379-ref1
    case 0xE6E7333E: return &hTable_DNLO2Q6E; // del-1478-del1
    case 0x37C7A3A7: return &hTable_YXrQA3J2; // del-1509-del
    case 0x55F6486C: return &hTable_fKIxix2v; // del-1538-del1
    default: return nullptr;
  }
}

void Heavy_PhaseRing::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0x9DBB052E: { // 1057-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JQ8XH6mX_sendMessage);
      break;
    }
    case 0xF1DE93DD: { // 1057-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_MSUiSskw_sendMessage);
      break;
    }
    case 0x6CD381D4: { // 1057-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_GRC2Y3gO_sendMessage);
      break;
    }
    case 0xCF6D3C3F: { // 1057-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_TRY8bBhd_sendMessage);
      break;
    }
    case 0xEDDFD30D: { // 1057-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_XvEdNmLJ_sendMessage);
      break;
    }
    case 0xF2BA3B2A: { // 1057-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_vfLLOk7l_sendMessage);
      break;
    }
    case 0x4408E690: { // 1093-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JgcBfXCJ_sendMessage);
      break;
    }
    case 0x8AB98019: { // 1093-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_wA9IjUay_sendMessage);
      break;
    }
    case 0x27A42126: { // 1101-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4obOa0kA_sendMessage);
      break;
    }
    case 0xB5E9A65D: { // 1101-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_HmrFwopm_sendMessage);
      break;
    }
    case 0x56934ECA: { // 1101-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UXC71nrx_sendMessage);
      break;
    }
    case 0x7514C9B6: { // 1101-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_9pCuWkDN_sendMessage);
      break;
    }
    case 0xCB831B98: { // 1101-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rnZmDjgm_sendMessage);
      break;
    }
    case 0x3A687221: { // 1101-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_oW5fYvH2_sendMessage);
      break;
    }
    case 0x68EAABD0: { // 1137-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_E2l5nDr2_sendMessage);
      break;
    }
    case 0x20D6E4AD: { // 1137-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_9nbcLdkc_sendMessage);
      break;
    }
    case 0x4BE05FC6: { // 1137-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_MRJzFSvg_sendMessage);
      break;
    }
    case 0xD8FD070D: { // 1137-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_k3qhc7vf_sendMessage);
      break;
    }
    case 0xC65E45B8: { // 1137-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RDsrnpUR_sendMessage);
      break;
    }
    case 0x9349BDCA: { // 1137-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YzDUtlvP_sendMessage);
      break;
    }
    case 0x8A2C77AE: { // 1173-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_iBbrZkJq_sendMessage);
      break;
    }
    case 0xD6F86CC3: { // 1173-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_HPjtQk1P_sendMessage);
      break;
    }
    case 0x2A29490B: { // 1173-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_LPyHGKIm_sendMessage);
      break;
    }
    case 0xFAE8AB: { // 1173-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Icit5MbF_sendMessage);
      break;
    }
    case 0xBFDBA4A2: { // 1173-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_TtciRdhR_sendMessage);
      break;
    }
    case 0x7638E91B: { // 1173-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ZlTLysvX_sendMessage);
      break;
    }
    case 0x83D209A2: { // 1599-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NG3d9ZnJ_sendMessage);
      break;
    }
    case 0x62CA542E: { // 1599-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_3MPn0eo7_sendMessage);
      break;
    }
    case 0xF8E41A5F: { // 1607-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Kt7kKPHH_sendMessage);
      break;
    }
    case 0x9164CD41: { // 1607-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_GNUrXJ9X_sendMessage);
      break;
    }
    case 0x78060116: { // 1619-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_QPrQCP5y_sendMessage);
      break;
    }
    case 0xDDEDC45: { // 1619-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_3bxNm4Ir_sendMessage);
      break;
    }
    case 0x3FF54ADC: { // 1627-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_bsCrqwau_sendMessage);
      break;
    }
    case 0x613389B1: { // 1627-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JGUkR6QZ_sendMessage);
      break;
    }
    case 0xCA661AA: { // 1635-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_E9eaimzv_sendMessage);
      break;
    }
    case 0x33695BEA: { // 1635-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_psluHfVQ_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FOxlk4ls_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NreiNAi5_sendMessage);
      break;
    }
    case 0x40AA4AF1: { // changesound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_y6IcNk58_sendMessage);
      break;
    }
    case 0xA41806F7: { // distortlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qnDRqHnS_sendMessage);
      break;
    }
    case 0xFCD12E4C: { // mastervolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_51yGrh40_sendMessage);
      break;
    }
    case 0xEF5F3308: { // panTranslation
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_i2ZOvpDX_sendMessage);
      break;
    }
    case 0x58FBFA93: { // phaseFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_m6Ye80po_sendMessage);
      break;
    }
    case 0x8B2148DD: { // pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qGYudbvd_sendMessage);
      break;
    }
    case 0x4409C659: { // processeffects
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_MxuQiGAF_sendMessage);
      break;
    }
    case 0x7B795C5A: { // resetsing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NmBa5KkM_sendMessage);
      break;
    }
    case 0xA987B741: { // reverbvolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UlHtggTQ_sendMessage);
      break;
    }
    case 0x7AAE6786: { // sinPanAngle
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_l3aBboEX_sendMessage);
      break;
    }
    case 0x6731B2E0: { // sing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Ooqb3idw_sendMessage);
      break;
    }
    case 0x57292445: { // singlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YXqGEjIK_sendMessage);
      break;
    }
    case 0xC7DE3B07: { // singpitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_i6tzG4cg_sendMessage);
      break;
    }
    case 0x4E809B1C: { // testbutton
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7LPHN0NA_sendMessage);
      break;
    }
    case 0x853B1BE7: { // velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_yRjwNjQN_sendMessage);
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


void Heavy_PhaseRing::cSend_0oDeuJfZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YXqGEjIK_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_L63sWGh7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_0oDeuJfZ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_9mRz4uSg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_i6tzG4cg_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_AW0SMzTt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.8f);
  cSend_ymDh1NQw_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_qEo0hsjx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cMsg_F65pUVNT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_ymDh1NQw_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cRandom_IiuiUccC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 128.0f, 0, m, &cBinop_PsFfRaTO_sendMessage);
}

void Heavy_PhaseRing::cBinop_PsFfRaTO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_mf3dCyzu_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_gE9cj6HO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_iMod558M, 0, m, &cSlice_iMod558M_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_IiuiUccC, 0, m, &cRandom_IiuiUccC_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cSlice_iMod558M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_IiuiUccC, 1, m, &cRandom_IiuiUccC_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cUnop_mf3dCyzu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zcopOsvk, 0, m, &cVar_zcopOsvk_sendMessage);
}

void Heavy_PhaseRing::cSend_Mm7lRkma_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_qGYudbvd_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_x0UEugRC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cCast_YwsyNi1X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_xZPaCe3W_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_ZrIznLtE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_L63sWGh7, 0, m, &cVar_L63sWGh7_sendMessage);
}

void Heavy_PhaseRing::cVar_zcopOsvk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Mm7lRkma_sendMessage(_c, 0, m);
  cSend_9mRz4uSg_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_2SkrOoSn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_46ywy8EG, 1, m, &cVar_46ywy8EG_sendMessage);
}

void Heavy_PhaseRing::cVar_46ywy8EG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_2SkrOoSn_sendMessage);
}

void Heavy_PhaseRing::cCast_6dMXYTkw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_gE9cj6HO_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_r4HxIbMN_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSlice_91ss4Qpz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_pxGDdggl, 1, m, &cRandom_pxGDdggl_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cUnop_NhHDuVnd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1.28f, 0, m, &cBinop_ZrIznLtE_sendMessage);
  cSend_xztl4XRO_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cRandom_pxGDdggl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 128.0f, 0, m, &cBinop_sD6CUjot_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_r4HxIbMN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_91ss4Qpz, 0, m, &cSlice_91ss4Qpz_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_pxGDdggl, 0, m, &cRandom_pxGDdggl_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_sD6CUjot_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_NhHDuVnd_sendMessage);
}

void Heavy_PhaseRing::cVar_nCTRzqbL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_xZPaCe3W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_y6IcNk58_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_xztl4XRO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_yRjwNjQN_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_ymDh1NQw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_i2ZOvpDX_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cReceive_3MPn0eo7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gaisByIG_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1EKsOIxg_sendMessage);
}

void Heavy_PhaseRing::cReceive_3bxNm4Ir_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tbpIIGhY_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YgNzMhZe_sendMessage);
}

void Heavy_PhaseRing::cVar_PTvS0Ga7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_rA537VEj, 0, m, &cPack_rA537VEj_sendMessage);
}

void Heavy_PhaseRing::cMsg_BXXOqjmp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_18onNJj2, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_ClcVTFK7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 500.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_jh9kKfih, m);
}

void Heavy_PhaseRing::cCast_0jTb164h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_7yUBE6lU_sendMessage);
}

void Heavy_PhaseRing::cCast_4QYcVSVZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_v9iArkOQ_sendMessage);
}

void Heavy_PhaseRing::cBinop_7yUBE6lU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vt9w4O4j, 0, m, &cVar_vt9w4O4j_sendMessage);
}

void Heavy_PhaseRing::cBinop_8x0ZfQjD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KJy5h15i, 0, m, &cVar_KJy5h15i_sendMessage);
}

void Heavy_PhaseRing::cBinop_NyfBHUVc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_DTT88hSh_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_SaBDUhQk, m);
}

void Heavy_PhaseRing::cBinop_lSQrAVlP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_NyfBHUVc_sendMessage);
}

void Heavy_PhaseRing::cBinop_DTT88hSh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_lGSq1CVg, m);
}

void Heavy_PhaseRing::cVar_vt9w4O4j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wxX3AjuN, HV_BINOP_MULTIPLY, 0, m, &cBinop_wxX3AjuN_sendMessage);
}

void Heavy_PhaseRing::cMsg_gBDy3SwE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_te413RcP_sendMessage);
}

void Heavy_PhaseRing::cSystem_te413RcP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JsNDXk3i_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_JsNDXk3i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_qjwdR5zu_sendMessage);
}

void Heavy_PhaseRing::cBinop_qjwdR5zu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wxX3AjuN, HV_BINOP_MULTIPLY, 1, m, &cBinop_wxX3AjuN_sendMessage);
}

void Heavy_PhaseRing::cBinop_wxX3AjuN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_lSQrAVlP_sendMessage);
}

void Heavy_PhaseRing::cBinop_6pUjozXE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_JjPn5IOz, m);
}

void Heavy_PhaseRing::cVar_KJy5h15i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_onIDdbjZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_onIDdbjZ_sendMessage);
}

void Heavy_PhaseRing::cBinop_FPB4l5cu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_QXSo6FKJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_QXSo6FKJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_6pUjozXE_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_FOWYkAfr, m);
}

void Heavy_PhaseRing::cBinop_1gy5ErY8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_onIDdbjZ, HV_BINOP_MULTIPLY, 1, m, &cBinop_onIDdbjZ_sendMessage);
}

void Heavy_PhaseRing::cMsg_l2aq8nF3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xuydrICF_sendMessage);
}

void Heavy_PhaseRing::cSystem_xuydrICF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HqkuD6Lx_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_HqkuD6Lx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_1gy5ErY8_sendMessage);
}

void Heavy_PhaseRing::cBinop_onIDdbjZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_FPB4l5cu_sendMessage);
}

void Heavy_PhaseRing::cCast_KzReA7xH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_rJYLNPto, m);
}

void Heavy_PhaseRing::cMsg_50Qv2AIq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_dX0Wdxdk_sendMessage);
}

void Heavy_PhaseRing::cMsg_7uiDpFd4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_S6V2pqU1, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_LqC25vyA, m);
}

void Heavy_PhaseRing::cBinop_UZOVBp1z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ivtoCaaK, m);
}

void Heavy_PhaseRing::cBinop_X1V8wGFw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XJu9k75n_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_XJu9k75n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_kWuy4BN8_sendMessage);
}

void Heavy_PhaseRing::cMsg_Y4hxMcna_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_UZOVBp1z_sendMessage);
}

void Heavy_PhaseRing::cBinop_dX0Wdxdk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_S6V2pqU1, m);
}

void Heavy_PhaseRing::cMsg_hHsgWtJ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_X1V8wGFw_sendMessage);
}

void Heavy_PhaseRing::cBinop_kWuy4BN8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Y4hxMcna_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_n8BJSAmA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_yYNfatI5_sendMessage);
}

void Heavy_PhaseRing::cMsg_rutu4pRj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zCLfxfps_sendMessage);
}

void Heavy_PhaseRing::cSystem_zCLfxfps_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_n8BJSAmA_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_c4leJELR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_paZvFr1u_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_STKaQSPO, 0, m, &cIf_STKaQSPO_sendMessage);
}

void Heavy_PhaseRing::cIf_STKaQSPO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_hHsgWtJ6_sendMessage(_c, 0, m);
      cMsg_7uiDpFd4_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_50Qv2AIq_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_X1V8wGFw_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_LqC25vyA, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_paZvFr1u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_STKaQSPO, 1, m, &cIf_STKaQSPO_sendMessage);
}

void Heavy_PhaseRing::cBinop_yYNfatI5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_1d3SEdZJ, m);
}

void Heavy_PhaseRing::cCast_hdAT2YoH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_8x0ZfQjD_sendMessage);
}

void Heavy_PhaseRing::cVar_V8U2V56F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RNthU5G9, HV_BINOP_MULTIPLY, 0, m, &cBinop_RNthU5G9_sendMessage);
}

void Heavy_PhaseRing::cBinop_0dnQNxrx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_tp36l5d9_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_L0gANi0M, m);
}

void Heavy_PhaseRing::cBinop_DYbP67g4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_0dnQNxrx_sendMessage);
}

void Heavy_PhaseRing::cBinop_tp36l5d9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_i8SKQmQs, m);
}

void Heavy_PhaseRing::cBinop_RNthU5G9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_DYbP67g4_sendMessage);
}

void Heavy_PhaseRing::cMsg_Zwr6Hfpo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_mgH5CSnn_sendMessage);
}

void Heavy_PhaseRing::cSystem_5IGkU8N8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Zwr6Hfpo_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_Eej5cfCi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5IGkU8N8_sendMessage);
}

void Heavy_PhaseRing::cBinop_mgH5CSnn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RNthU5G9, HV_BINOP_MULTIPLY, 1, m, &cBinop_RNthU5G9_sendMessage);
}

void Heavy_PhaseRing::cBinop_v9iArkOQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_V8U2V56F, 0, m, &cVar_V8U2V56F_sendMessage);
}

void Heavy_PhaseRing::cCast_4nALlFI5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_D2mqMoBp, HV_BINOP_DIVIDE, 1, m, &cBinop_D2mqMoBp_sendMessage);
}

void Heavy_PhaseRing::cMsg_5d4tbG8C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_btFEdWc4, 0, m, &cVar_btFEdWc4_sendMessage);
}

void Heavy_PhaseRing::cPack_C8jbLjm2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_SU16ZDGV, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_D2mqMoBp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_j1fug81B_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_5KkNz9hd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_2xUpWFOi, m);
}

void Heavy_PhaseRing::cBinop_E62IxLfI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_P2rfj2uf, m);
}

void Heavy_PhaseRing::cMsg_I8JctwzM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LmBqKizT_sendMessage);
}

void Heavy_PhaseRing::cSystem_LmBqKizT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_5KkNz9hd_sendMessage);
}

void Heavy_PhaseRing::cMsg_fGIqcMcZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uXds3GAT_sendMessage);
}

void Heavy_PhaseRing::cVar_eOpK91eD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fGIqcMcZ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_uXds3GAT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_E62IxLfI_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_7IIeHIti, m);
}

void Heavy_PhaseRing::cBinop_GXEJBEBJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_JkppSsnT, 0, m, &cPack_JkppSsnT_sendMessage);
}

void Heavy_PhaseRing::cMsg_I7jeegSh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_IIsJ74BK, 0, m, &cVar_IIsJ74BK_sendMessage);
}

void Heavy_PhaseRing::cMsg_05msPNT8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gkYZLs8V_sendMessage);
}

void Heavy_PhaseRing::cBinop_CLNEn0DC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_9MAvnJZr, m);
}

void Heavy_PhaseRing::cVar_VeDuEHXS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_05msPNT8_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_gkYZLs8V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_mlL2eYQA_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ICOjh6aN, m);
}

void Heavy_PhaseRing::cMsg_6dHVvDyN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KkRg0DLp_sendMessage);
}

void Heavy_PhaseRing::cSystem_KkRg0DLp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_CLNEn0DC_sendMessage);
}

void Heavy_PhaseRing::cBinop_mlL2eYQA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_x0YG7uKC, m);
}

void Heavy_PhaseRing::cPack_JkppSsnT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_acy883LG, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_Nm2VDzII_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_jaq7UoDM_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_C8jbLjm2, 0, m, &cPack_C8jbLjm2_sendMessage);
}

void Heavy_PhaseRing::cBinop_SOSLB9w9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_vUt3abmG_sendMessage);
}

void Heavy_PhaseRing::cCast_WfZaZC1N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_D2mqMoBp, HV_BINOP_DIVIDE, 0, m, &cBinop_D2mqMoBp_sendMessage);
}

void Heavy_PhaseRing::cVar_IIsJ74BK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_GXEJBEBJ_sendMessage);
}

void Heavy_PhaseRing::cVar_btFEdWc4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_Nm2VDzII_sendMessage);
}

void Heavy_PhaseRing::cMsg_j1fug81B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_mpNzjmv6, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_jXIZLaVa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_r051JzLh_sendMessage);
}

void Heavy_PhaseRing::cBinop_jaq7UoDM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4nALlFI5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WfZaZC1N_sendMessage);
}

void Heavy_PhaseRing::cCast_3HiO7cSt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_IeWufIYH, 0, m, &cDelay_IeWufIYH_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_BeuYz5E4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_IU0YaDfn_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_DvAyh2AD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DvAyh2AD, m);
  cMsg_PCkC4yJ9_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_IEpfh73H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XkpfIO9r_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_IU0YaDfn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_RKxwGm7M, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_IeWufIYH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IeWufIYH, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DvAyh2AD, 0, m, &cDelay_DvAyh2AD_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IeWufIYH, 0, m, &cDelay_IeWufIYH_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_RKxwGm7M, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_PCkC4yJ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_T6MbkFIw, 0, m, &hTable_T6MbkFIw_sendMessage);
}

void Heavy_PhaseRing::hTable_T6MbkFIw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZloLYCGC_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IeWufIYH, 2, m, &cDelay_IeWufIYH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3HiO7cSt_sendMessage);
}

void Heavy_PhaseRing::cMsg_XkpfIO9r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_T6MbkFIw, 0, m, &hTable_T6MbkFIw_sendMessage);
}

void Heavy_PhaseRing::cMsg_ZloLYCGC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_DvAyh2AD, 2, m, &cDelay_DvAyh2AD_sendMessage);
}

void Heavy_PhaseRing::cMsg_1zJ53JCY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SJpHuEE2_sendMessage);
}

void Heavy_PhaseRing::cSystem_SJpHuEE2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_zfpMRGbO_sendMessage);
}

void Heavy_PhaseRing::cBinop_zfpMRGbO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_IEpfh73H_sendMessage);
}

void Heavy_PhaseRing::cBinop_r051JzLh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_zfKN6FGv_sendMessage);
}

void Heavy_PhaseRing::cUnop_zfKN6FGv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_SOSLB9w9_sendMessage);
}

void Heavy_PhaseRing::cBinop_vUt3abmG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_D2mqMoBp, HV_BINOP_DIVIDE, 0, m, &cBinop_D2mqMoBp_sendMessage);
}

void Heavy_PhaseRing::cBinop_LFX6ALvj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_bQmEHkS3_sendMessage);
}

void Heavy_PhaseRing::cBinop_oLEqnRxi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_LFX6ALvj_sendMessage);
}

void Heavy_PhaseRing::cPack_4sH5AWzX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_vkCreuW5, 0, m, NULL);
}

void Heavy_PhaseRing::cSwitchcase_2GYOW1v3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_kRYjVfhM_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_BEh7nvID_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_otqKPZHd, 0, m, &cDelay_otqKPZHd_sendMessage);
}

void Heavy_PhaseRing::cMsg_HrjqxjhO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_tA7wg1bb, 0, m, &hTable_tA7wg1bb_sendMessage);
}

void Heavy_PhaseRing::cBinop_KhCtoqD1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_iAHfQVk2_sendMessage);
}

void Heavy_PhaseRing::cSystem_FQkwkhHy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_KhCtoqD1_sendMessage);
}

void Heavy_PhaseRing::cMsg_oO3Ayabh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FQkwkhHy_sendMessage);
}

void Heavy_PhaseRing::cMsg_PXFF8jUh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_wuxy6YJR, 2, m, &cDelay_wuxy6YJR_sendMessage);
}

void Heavy_PhaseRing::cMsg_Ub6hZTeD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_tA7wg1bb, 0, m, &hTable_tA7wg1bb_sendMessage);
}

void Heavy_PhaseRing::cBinop_iAHfQVk2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HrjqxjhO_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_kRYjVfhM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_IfmKn09V, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_otqKPZHd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_otqKPZHd, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wuxy6YJR, 0, m, &cDelay_wuxy6YJR_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_otqKPZHd, 0, m, &cDelay_otqKPZHd_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_IfmKn09V, 1, m, NULL);
}

void Heavy_PhaseRing::hTable_tA7wg1bb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PXFF8jUh_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_otqKPZHd, 2, m, &cDelay_otqKPZHd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BEh7nvID_sendMessage);
}

void Heavy_PhaseRing::cDelay_wuxy6YJR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wuxy6YJR, m);
  cMsg_Ub6hZTeD_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_1HqYy2pn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_KTYymZwO, 1, m, &cIf_KTYymZwO_sendMessage);
}

void Heavy_PhaseRing::cIf_KTYymZwO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_iwbptpJ2_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_MEzGKBmE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_MEzGKBmE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_NZOhvBHS_sendMessage);
}

void Heavy_PhaseRing::cBinop_NZOhvBHS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_XvcAeCln_sendMessage);
}

void Heavy_PhaseRing::cBinop_X6muOth1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_EI15LN6J_sendMessage);
}

void Heavy_PhaseRing::cBinop_XvcAeCln_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_X6muOth1, HV_BINOP_POW, 1, m, &cBinop_X6muOth1_sendMessage);
  cMsg_awJtMi5f_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_awJtMi5f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_X6muOth1, HV_BINOP_POW, 0, m, &cBinop_X6muOth1_sendMessage);
}

void Heavy_PhaseRing::cMsg_iwbptpJ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_EI15LN6J_sendMessage);
}

void Heavy_PhaseRing::cCast_kMQHZoc2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_1HqYy2pn_sendMessage);
}

void Heavy_PhaseRing::cCast_r8D2hWo4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_KTYymZwO, 0, m, &cIf_KTYymZwO_sendMessage);
}

void Heavy_PhaseRing::cBinop_1KD7b47b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rHnsJZmF, 0, m, &cVar_rHnsJZmF_sendMessage);
}

void Heavy_PhaseRing::cBinop_SMnvom2o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_1KD7b47b_sendMessage);
}

void Heavy_PhaseRing::cVar_ArNlzdTb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_SMnvom2o_sendMessage);
}

void Heavy_PhaseRing::cVar_3YopkI0B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_oLEqnRxi_sendMessage);
}

void Heavy_PhaseRing::cBinop_NKIP7EOa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_bi1g41X8_sendMessage);
}

void Heavy_PhaseRing::cBinop_bi1g41X8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_QtAaF8GU_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_feZCPZrm, m);
}

void Heavy_PhaseRing::cBinop_QtAaF8GU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_rPo0atmS, m);
}

void Heavy_PhaseRing::cVar_aNKDDy1w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_B7xEYXrU, HV_BINOP_MULTIPLY, 0, m, &cBinop_B7xEYXrU_sendMessage);
}

void Heavy_PhaseRing::cMsg_dw3iN5tH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zi8joUav_sendMessage);
}

void Heavy_PhaseRing::cSystem_zi8joUav_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_v3ofwXQv_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_B7xEYXrU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_NKIP7EOa_sendMessage);
}

void Heavy_PhaseRing::cBinop_DxncaxJs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_B7xEYXrU, HV_BINOP_MULTIPLY, 1, m, &cBinop_B7xEYXrU_sendMessage);
}

void Heavy_PhaseRing::cMsg_v3ofwXQv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_DxncaxJs_sendMessage);
}

void Heavy_PhaseRing::cBinop_EI15LN6J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_4sH5AWzX, 0, m, &cPack_4sH5AWzX_sendMessage);
}

void Heavy_PhaseRing::cPack_F8HuyRy2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_omlztVwW, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_n0OW9d5Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IFEzmF3u, HV_BINOP_MULTIPLY, 0, m, &cBinop_IFEzmF3u_sendMessage);
}

void Heavy_PhaseRing::cBinop_B7lNoczL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_dsfmIaoo, m);
}

void Heavy_PhaseRing::cBinop_4tBwaIK5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IFEzmF3u, HV_BINOP_MULTIPLY, 1, m, &cBinop_IFEzmF3u_sendMessage);
}

void Heavy_PhaseRing::cBinop_IFEzmF3u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_g4xXvYc6_sendMessage);
}

void Heavy_PhaseRing::cMsg_VHvSO52y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_4tBwaIK5_sendMessage);
}

void Heavy_PhaseRing::cSystem_2pmToXM2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VHvSO52y_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_Jd1xaoWz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2pmToXM2_sendMessage);
}

void Heavy_PhaseRing::cBinop_BjnY4T2p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_B7lNoczL_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_CbW8VNEK, m);
}

void Heavy_PhaseRing::cBinop_g4xXvYc6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_BjnY4T2p_sendMessage);
}

void Heavy_PhaseRing::cMsg_095wVwXQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WTaKHD3o_sendMessage);
}

void Heavy_PhaseRing::cBinop_1cPikJQS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_swFLVWuT_sendMessage);
}

void Heavy_PhaseRing::cDelay_5ICExi00_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5ICExi00, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ZI44pPse, 0, m, &sTabread_ZI44pPse_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5ICExi00, 0, m, &cDelay_5ICExi00_sendMessage);
}

void Heavy_PhaseRing::cBinop_5MqZjCNj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GilxHTcB, HV_BINOP_MULTIPLY, 0, m, &cBinop_GilxHTcB_sendMessage);
}

void Heavy_PhaseRing::cCast_6xmRTFZy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Lir9aKYE, 0, m, &cVar_Lir9aKYE_sendMessage);
  cMsg_6e7V5BTV_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_mbFM2wzE, 0, m, &cTabhead_mbFM2wzE_sendMessage);
}

void Heavy_PhaseRing::cBinop_Bzfl9u96_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wy6POAbD_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ZI44pPse, 0, m, &sTabread_ZI44pPse_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eirjZr3s_sendMessage);
}

void Heavy_PhaseRing::cBinop_GilxHTcB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MsB7RNEz, HV_BINOP_MAX, 0, m, &cBinop_MsB7RNEz_sendMessage);
}

void Heavy_PhaseRing::cMsg_L3kgoQlT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_MsB7RNEz, HV_BINOP_MAX, 1, m, &cBinop_MsB7RNEz_sendMessage);
}

void Heavy_PhaseRing::cVar_Lir9aKYE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_095wVwXQ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_MsB7RNEz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Bzfl9u96, HV_BINOP_SUBTRACT, 1, m, &cBinop_Bzfl9u96_sendMessage);
}

void Heavy_PhaseRing::cSystem_WTaKHD3o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1cPikJQS, HV_BINOP_SUBTRACT, 1, m, &cBinop_1cPikJQS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5ICExi00, 2, m, &cDelay_5ICExi00_sendMessage);
}

void Heavy_PhaseRing::sTabread_ZI44pPse_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_1cPikJQS, HV_BINOP_SUBTRACT, 0, m, &cBinop_1cPikJQS_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cDelay_ZtOJ3UXg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ZtOJ3UXg, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5ICExi00, 0, m, &cDelay_5ICExi00_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ZI44pPse, 0, m, &sTabread_ZI44pPse_sendMessage);
}

void Heavy_PhaseRing::cMsg_6e7V5BTV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_riNroZT1_sendMessage);
}

void Heavy_PhaseRing::cSystem_riNroZT1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_5MqZjCNj_sendMessage);
}

void Heavy_PhaseRing::cCast_eirjZr3s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZtOJ3UXg, 0, m, &cDelay_ZtOJ3UXg_sendMessage);
}

void Heavy_PhaseRing::cTabhead_mbFM2wzE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Bzfl9u96, HV_BINOP_SUBTRACT, 0, m, &cBinop_Bzfl9u96_sendMessage);
}

void Heavy_PhaseRing::cBinop_swFLVWuT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZtOJ3UXg, 2, m, &cDelay_ZtOJ3UXg_sendMessage);
}

void Heavy_PhaseRing::cMsg_wy6POAbD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZtOJ3UXg, 0, m, &cDelay_ZtOJ3UXg_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5ICExi00, 0, m, &cDelay_5ICExi00_sendMessage);
}

void Heavy_PhaseRing::cMsg_0JvXViD5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_uU6GJ8re, 2, m, &cDelay_uU6GJ8re_sendMessage);
}

void Heavy_PhaseRing::cCast_27ZJ2wY9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_WNLGblAw, 0, m, &cDelay_WNLGblAw_sendMessage);
}

void Heavy_PhaseRing::cBinop_K7EZ0gG9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_k8fW84vq_sendMessage);
}

void Heavy_PhaseRing::hTable_MRFeGKGv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0JvXViD5_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WNLGblAw, 2, m, &cDelay_WNLGblAw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_27ZJ2wY9_sendMessage);
}

void Heavy_PhaseRing::cMsg_MX3WAOkL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_fsg929Ns, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_RCrFQoKW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_MRFeGKGv, 0, m, &hTable_MRFeGKGv_sendMessage);
}

void Heavy_PhaseRing::cDelay_WNLGblAw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WNLGblAw, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uU6GJ8re, 0, m, &cDelay_uU6GJ8re_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WNLGblAw, 0, m, &cDelay_WNLGblAw_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_fsg929Ns, 1, m, NULL);
}

void Heavy_PhaseRing::cSwitchcase_Yi2fYugt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_MX3WAOkL_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cSystem_DwVJLize_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_K7EZ0gG9_sendMessage);
}

void Heavy_PhaseRing::cMsg_K40Zj5Ga_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DwVJLize_sendMessage);
}

void Heavy_PhaseRing::cMsg_hqvQcVaC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_MRFeGKGv, 0, m, &hTable_MRFeGKGv_sendMessage);
}

void Heavy_PhaseRing::cBinop_k8fW84vq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RCrFQoKW_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_uU6GJ8re_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_uU6GJ8re, m);
  cMsg_hqvQcVaC_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_JFGPsHUn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kMQHZoc2_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_r8D2hWo4_sendMessage);
}

void Heavy_PhaseRing::cMsg_0YvZBbQL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_XBJx0zKQ, 0, m, &cDelay_XBJx0zKQ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gvmCffhO, 0, m, &cDelay_gvmCffhO_sendMessage);
}

void Heavy_PhaseRing::cCast_2okz0DiV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QqD0MpYN, 0, m, &cVar_QqD0MpYN_sendMessage);
  cMsg_j5zyOgSC_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_wiTpTbLI, 0, m, &cTabhead_wiTpTbLI_sendMessage);
}

void Heavy_PhaseRing::cSystem_88KB4mBa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EHLtzLOc, HV_BINOP_SUBTRACT, 1, m, &cBinop_EHLtzLOc_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gvmCffhO, 2, m, &cDelay_gvmCffhO_sendMessage);
}

void Heavy_PhaseRing::cBinop_8Bv5ZVyg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XBJx0zKQ, 2, m, &cDelay_XBJx0zKQ_sendMessage);
}

void Heavy_PhaseRing::cBinop_EHLtzLOc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_8Bv5ZVyg_sendMessage);
}

void Heavy_PhaseRing::cSystem_H47Xoozb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Qk9cFBMp_sendMessage);
}

void Heavy_PhaseRing::cMsg_j5zyOgSC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_H47Xoozb_sendMessage);
}

void Heavy_PhaseRing::cBinop_NAJOJKuS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0YvZBbQL_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_u0MX4kT7, 0, m, &sTabread_u0MX4kT7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dYRbDKH8_sendMessage);
}

void Heavy_PhaseRing::cMsg_QU6FQE0w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_wtirJLRU, HV_BINOP_MAX, 1, m, &cBinop_wtirJLRU_sendMessage);
}

void Heavy_PhaseRing::cBinop_Qk9cFBMp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_poh3Ckgf, HV_BINOP_MULTIPLY, 0, m, &cBinop_poh3Ckgf_sendMessage);
}

void Heavy_PhaseRing::cVar_QqD0MpYN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RVApxjGd_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_RVApxjGd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_88KB4mBa_sendMessage);
}

void Heavy_PhaseRing::cDelay_XBJx0zKQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XBJx0zKQ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gvmCffhO, 0, m, &cDelay_gvmCffhO_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_u0MX4kT7, 0, m, &sTabread_u0MX4kT7_sendMessage);
}

void Heavy_PhaseRing::cCast_dYRbDKH8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XBJx0zKQ, 0, m, &cDelay_XBJx0zKQ_sendMessage);
}

void Heavy_PhaseRing::cDelay_gvmCffhO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gvmCffhO, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_u0MX4kT7, 0, m, &sTabread_u0MX4kT7_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gvmCffhO, 0, m, &cDelay_gvmCffhO_sendMessage);
}

void Heavy_PhaseRing::cBinop_poh3Ckgf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wtirJLRU, HV_BINOP_MAX, 0, m, &cBinop_wtirJLRU_sendMessage);
}

void Heavy_PhaseRing::sTabread_u0MX4kT7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_EHLtzLOc, HV_BINOP_SUBTRACT, 0, m, &cBinop_EHLtzLOc_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cTabhead_wiTpTbLI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NAJOJKuS, HV_BINOP_SUBTRACT, 0, m, &cBinop_NAJOJKuS_sendMessage);
}

void Heavy_PhaseRing::cBinop_wtirJLRU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NAJOJKuS, HV_BINOP_SUBTRACT, 1, m, &cBinop_NAJOJKuS_sendMessage);
}

void Heavy_PhaseRing::cBinop_3LyMW30U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_zKYOzcca_sendMessage);
}

void Heavy_PhaseRing::cBinop_3YbyLICf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EgR7aQyw, HV_BINOP_MULTIPLY, 0, m, &cBinop_EgR7aQyw_sendMessage);
}

void Heavy_PhaseRing::cVar_5Int7Eww_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OyLoHW9F_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_6Ml2QKwo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6Ml2QKwo, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Th0OAbYU, 0, m, &cDelay_Th0OAbYU_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_RQZ3wiSK, 0, m, &sTabread_RQZ3wiSK_sendMessage);
}

void Heavy_PhaseRing::cBinop_EgR7aQyw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JxPNQRyU, HV_BINOP_MAX, 0, m, &cBinop_JxPNQRyU_sendMessage);
}

void Heavy_PhaseRing::cBinop_G4enNZXX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NcKfd4xP_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_RQZ3wiSK, 0, m, &sTabread_RQZ3wiSK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XQezQsN3_sendMessage);
}

void Heavy_PhaseRing::cBinop_JxPNQRyU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_G4enNZXX, HV_BINOP_SUBTRACT, 1, m, &cBinop_G4enNZXX_sendMessage);
}

void Heavy_PhaseRing::cMsg_NcKfd4xP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_6Ml2QKwo, 0, m, &cDelay_6Ml2QKwo_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Th0OAbYU, 0, m, &cDelay_Th0OAbYU_sendMessage);
}

void Heavy_PhaseRing::cMsg_rDm5AsVt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zyB5iGBX_sendMessage);
}

void Heavy_PhaseRing::cSystem_zyB5iGBX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_3YbyLICf_sendMessage);
}

void Heavy_PhaseRing::cMsg_OyLoHW9F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nspBAi22_sendMessage);
}

void Heavy_PhaseRing::sTabread_RQZ3wiSK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_3LyMW30U, HV_BINOP_SUBTRACT, 0, m, &cBinop_3LyMW30U_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cDelay_Th0OAbYU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Th0OAbYU, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_RQZ3wiSK, 0, m, &sTabread_RQZ3wiSK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Th0OAbYU, 0, m, &cDelay_Th0OAbYU_sendMessage);
}

void Heavy_PhaseRing::cCast_XQezQsN3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_6Ml2QKwo, 0, m, &cDelay_6Ml2QKwo_sendMessage);
}

void Heavy_PhaseRing::cCast_j5n1Hth5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5Int7Eww, 0, m, &cVar_5Int7Eww_sendMessage);
  cMsg_rDm5AsVt_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_lOupEdQR, 0, m, &cTabhead_lOupEdQR_sendMessage);
}

void Heavy_PhaseRing::cTabhead_lOupEdQR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_G4enNZXX, HV_BINOP_SUBTRACT, 0, m, &cBinop_G4enNZXX_sendMessage);
}

void Heavy_PhaseRing::cSystem_nspBAi22_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3LyMW30U, HV_BINOP_SUBTRACT, 1, m, &cBinop_3LyMW30U_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Th0OAbYU, 2, m, &cDelay_Th0OAbYU_sendMessage);
}

void Heavy_PhaseRing::cMsg_s5UZrpvX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_JxPNQRyU, HV_BINOP_MAX, 1, m, &cBinop_JxPNQRyU_sendMessage);
}

void Heavy_PhaseRing::cBinop_zKYOzcca_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_6Ml2QKwo, 2, m, &cDelay_6Ml2QKwo_sendMessage);
}

void Heavy_PhaseRing::cMsg_2rtNKmHh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_89Y0qi5S, HV_BINOP_MAX, 1, m, &cBinop_89Y0qi5S_sendMessage);
}

void Heavy_PhaseRing::cTabhead_6FU7ijsM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SSWJflNi, HV_BINOP_SUBTRACT, 0, m, &cBinop_SSWJflNi_sendMessage);
}

void Heavy_PhaseRing::cDelay_7i4fmIt3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7i4fmIt3, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eEDxcHme, 0, m, &cDelay_eEDxcHme_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_82O8wVlI, 0, m, &sTabread_82O8wVlI_sendMessage);
}

void Heavy_PhaseRing::cMsg_7p3b329t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_7i4fmIt3, 0, m, &cDelay_7i4fmIt3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eEDxcHme, 0, m, &cDelay_eEDxcHme_sendMessage);
}

void Heavy_PhaseRing::sTabread_82O8wVlI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_VNVpctEx, HV_BINOP_SUBTRACT, 0, m, &cBinop_VNVpctEx_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_89Y0qi5S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SSWJflNi, HV_BINOP_SUBTRACT, 1, m, &cBinop_SSWJflNi_sendMessage);
}

void Heavy_PhaseRing::cBinop_INrxROcs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_z8bvsrEq, HV_BINOP_MULTIPLY, 0, m, &cBinop_z8bvsrEq_sendMessage);
}

void Heavy_PhaseRing::cMsg_MzGqcph5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zYq9EYtv_sendMessage);
}

void Heavy_PhaseRing::cBinop_SSWJflNi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7p3b329t_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_82O8wVlI, 0, m, &sTabread_82O8wVlI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_r6jyvCtO_sendMessage);
}

void Heavy_PhaseRing::cSystem_2RUV3WZL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_INrxROcs_sendMessage);
}

void Heavy_PhaseRing::cMsg_KUpx3UdS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2RUV3WZL_sendMessage);
}

void Heavy_PhaseRing::cBinop_VNVpctEx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_sbqjr0dG_sendMessage);
}

void Heavy_PhaseRing::cCast_Vmm7Wi9B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_g0Qcphhf, 0, m, &cVar_g0Qcphhf_sendMessage);
  cMsg_KUpx3UdS_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_6FU7ijsM, 0, m, &cTabhead_6FU7ijsM_sendMessage);
}

void Heavy_PhaseRing::cDelay_eEDxcHme_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_eEDxcHme, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_82O8wVlI, 0, m, &sTabread_82O8wVlI_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eEDxcHme, 0, m, &cDelay_eEDxcHme_sendMessage);
}

void Heavy_PhaseRing::cVar_g0Qcphhf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MzGqcph5_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_r6jyvCtO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_7i4fmIt3, 0, m, &cDelay_7i4fmIt3_sendMessage);
}

void Heavy_PhaseRing::cBinop_sbqjr0dG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_7i4fmIt3, 2, m, &cDelay_7i4fmIt3_sendMessage);
}

void Heavy_PhaseRing::cBinop_z8bvsrEq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_89Y0qi5S, HV_BINOP_MAX, 0, m, &cBinop_89Y0qi5S_sendMessage);
}

void Heavy_PhaseRing::cSystem_zYq9EYtv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VNVpctEx, HV_BINOP_SUBTRACT, 1, m, &cBinop_VNVpctEx_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eEDxcHme, 2, m, &cDelay_eEDxcHme_sendMessage);
}

void Heavy_PhaseRing::cSystem_CBh5T8lj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dR3Issgm_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_JEmUlSr7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CBh5T8lj_sendMessage);
}

void Heavy_PhaseRing::cBinop_7gFXNw8h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_9QBtFkpz_sendMessage);
}

void Heavy_PhaseRing::cBinop_TUpLUGrK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7gFXNw8h, HV_BINOP_MULTIPLY, 1, m, &cBinop_7gFXNw8h_sendMessage);
}

void Heavy_PhaseRing::cMsg_dR3Issgm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_TUpLUGrK_sendMessage);
}

void Heavy_PhaseRing::cBinop_XE8WwMMf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_pfe4rM8M, m);
}

void Heavy_PhaseRing::cBinop_9QBtFkpz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_N4xjTIvI_sendMessage);
}

void Heavy_PhaseRing::cBinop_N4xjTIvI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_XE8WwMMf_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_JqiunZdB, m);
}

void Heavy_PhaseRing::cVar_xOKOV2RP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7gFXNw8h, HV_BINOP_MULTIPLY, 0, m, &cBinop_7gFXNw8h_sendMessage);
}

void Heavy_PhaseRing::cVar_rHnsJZmF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_u1yWyNXr_sendMessage);
}

void Heavy_PhaseRing::cIf_5hrMSHjI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_gjxfcIYu_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_RAc1gTQk, 0, m, &cVar_RAc1gTQk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_GKgeOSLt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_5hrMSHjI, 1, m, &cIf_5hrMSHjI_sendMessage);
}

void Heavy_PhaseRing::cMsg_11fOa6ve_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Du1tCGd4, 2, m, &cDelay_Du1tCGd4_sendMessage);
}

void Heavy_PhaseRing::cSystem_gvfGqYF2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_E1XDLAi8_sendMessage);
}

void Heavy_PhaseRing::cMsg_nNoHMgri_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gvfGqYF2_sendMessage);
}

void Heavy_PhaseRing::cDelay_Du1tCGd4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Du1tCGd4, m);
  cMsg_WnjfZeMl_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_E1XDLAi8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_YshteAh0_sendMessage);
}

void Heavy_PhaseRing::hTable_HtQXdXmr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_11fOa6ve_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Knj7evc2, 2, m, &cDelay_Knj7evc2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YwaGFhUc_sendMessage);
}

void Heavy_PhaseRing::cDelay_Knj7evc2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Knj7evc2, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Du1tCGd4, 0, m, &cDelay_Du1tCGd4_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Knj7evc2, 0, m, &cDelay_Knj7evc2_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_7Nv71mpj, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_RpxN8fwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_HtQXdXmr, 0, m, &hTable_HtQXdXmr_sendMessage);
}

void Heavy_PhaseRing::cMsg_WnjfZeMl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_HtQXdXmr, 0, m, &hTable_HtQXdXmr_sendMessage);
}

void Heavy_PhaseRing::cMsg_YJTiMYJU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_7Nv71mpj, 1, m, NULL);
}

void Heavy_PhaseRing::cBinop_YshteAh0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RpxN8fwg_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_YwaGFhUc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Knj7evc2, 0, m, &cDelay_Knj7evc2_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_trcvYfv6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_YJTiMYJU_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_bQmEHkS3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_g6JH5Xab, 0, m, &cPack_g6JH5Xab_sendMessage);
}

void Heavy_PhaseRing::cDelay_4Lw6qBIL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4Lw6qBIL, m);
  cMsg_coOqk6Hv_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_6pwWbFDF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pJnY0ooD_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_21cYREHO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_JVHs3374_sendMessage);
}

void Heavy_PhaseRing::cMsg_UFkvbtYD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_21cYREHO_sendMessage);
}

void Heavy_PhaseRing::cMsg_CicYzqYX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_4Lw6qBIL, 2, m, &cDelay_4Lw6qBIL_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_HxChIRUj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_stQyNYdN_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_JVHs3374_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_6pwWbFDF_sendMessage);
}

void Heavy_PhaseRing::cDelay_RWHaRdz0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RWHaRdz0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4Lw6qBIL, 0, m, &cDelay_4Lw6qBIL_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RWHaRdz0, 0, m, &cDelay_RWHaRdz0_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_p3r4FpeY, 1, m, NULL);
}

void Heavy_PhaseRing::hTable_VCnxqSqb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CicYzqYX_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RWHaRdz0, 2, m, &cDelay_RWHaRdz0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tEOBkZds_sendMessage);
}

void Heavy_PhaseRing::cMsg_coOqk6Hv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_VCnxqSqb, 0, m, &hTable_VCnxqSqb_sendMessage);
}

void Heavy_PhaseRing::cMsg_pJnY0ooD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_VCnxqSqb, 0, m, &hTable_VCnxqSqb_sendMessage);
}

void Heavy_PhaseRing::cMsg_stQyNYdN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_p3r4FpeY, 1, m, NULL);
}

void Heavy_PhaseRing::cCast_tEOBkZds_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_RWHaRdz0, 0, m, &cDelay_RWHaRdz0_sendMessage);
}

void Heavy_PhaseRing::cMsg_0JckHJRu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_23FcSf5Q, 2, m, &cDelay_23FcSf5Q_sendMessage);
}

void Heavy_PhaseRing::cDelay_23FcSf5Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_23FcSf5Q, m);
  cMsg_7GkuHEDs_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_3vMJ3ti6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_BFERekNs_sendMessage);
}

void Heavy_PhaseRing::cMsg_5rP4odRF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_vIRt3Yqw, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_7GkuHEDs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_YJmhcxIZ, 0, m, &hTable_YJmhcxIZ_sendMessage);
}

void Heavy_PhaseRing::cBinop_BFERekNs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MDlB0Uve_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_DAnn0CIu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DAnn0CIu, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_23FcSf5Q, 0, m, &cDelay_23FcSf5Q_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DAnn0CIu, 0, m, &cDelay_DAnn0CIu_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_vIRt3Yqw, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_MDlB0Uve_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_YJmhcxIZ, 0, m, &hTable_YJmhcxIZ_sendMessage);
}

void Heavy_PhaseRing::hTable_YJmhcxIZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0JckHJRu_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DAnn0CIu, 2, m, &cDelay_DAnn0CIu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zLOIMMzk_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_l9ubMgXS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_5rP4odRF_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cSystem_GiHmVh9X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_3vMJ3ti6_sendMessage);
}

void Heavy_PhaseRing::cMsg_Iopt7YnK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GiHmVh9X_sendMessage);
}

void Heavy_PhaseRing::cCast_zLOIMMzk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_DAnn0CIu, 0, m, &cDelay_DAnn0CIu_sendMessage);
}

void Heavy_PhaseRing::cBinop_29LIlaOf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dPpdiuon_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_nnUdHZyE, 0, m, &sTabread_nnUdHZyE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VTkRp2LD_sendMessage);
}

void Heavy_PhaseRing::cMsg_32B8qYsX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OxLBFjtH_sendMessage);
}

void Heavy_PhaseRing::cTabhead_3Q6pQxtF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_29LIlaOf, HV_BINOP_SUBTRACT, 0, m, &cBinop_29LIlaOf_sendMessage);
}

void Heavy_PhaseRing::cBinop_3jqA1lV6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tyHRiS7V, HV_BINOP_MAX, 0, m, &cBinop_tyHRiS7V_sendMessage);
}

void Heavy_PhaseRing::cMsg_QKeJjtvr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WsWzdNjF_sendMessage);
}

void Heavy_PhaseRing::cSystem_WsWzdNjF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_xUbeWThw_sendMessage);
}

void Heavy_PhaseRing::cBinop_5vw9qF0Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_xG4Rq4hx, 2, m, &cDelay_xG4Rq4hx_sendMessage);
}

void Heavy_PhaseRing::cVar_FvajntIJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_32B8qYsX_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_Ikzopo2u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_5vw9qF0Z_sendMessage);
}

void Heavy_PhaseRing::cSystem_OxLBFjtH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ikzopo2u, HV_BINOP_SUBTRACT, 1, m, &cBinop_Ikzopo2u_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SRvDEJQQ, 2, m, &cDelay_SRvDEJQQ_sendMessage);
}

void Heavy_PhaseRing::cDelay_SRvDEJQQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SRvDEJQQ, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_nnUdHZyE, 0, m, &sTabread_nnUdHZyE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SRvDEJQQ, 0, m, &cDelay_SRvDEJQQ_sendMessage);
}

void Heavy_PhaseRing::cCast_VTkRp2LD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_xG4Rq4hx, 0, m, &cDelay_xG4Rq4hx_sendMessage);
}

void Heavy_PhaseRing::cMsg_dPpdiuon_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_xG4Rq4hx, 0, m, &cDelay_xG4Rq4hx_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SRvDEJQQ, 0, m, &cDelay_SRvDEJQQ_sendMessage);
}

void Heavy_PhaseRing::cMsg_hwhHDvGW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_tyHRiS7V, HV_BINOP_MAX, 1, m, &cBinop_tyHRiS7V_sendMessage);
}

void Heavy_PhaseRing::sTabread_nnUdHZyE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Ikzopo2u, HV_BINOP_SUBTRACT, 0, m, &cBinop_Ikzopo2u_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_tyHRiS7V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_29LIlaOf, HV_BINOP_SUBTRACT, 1, m, &cBinop_29LIlaOf_sendMessage);
}

void Heavy_PhaseRing::cDelay_xG4Rq4hx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_xG4Rq4hx, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SRvDEJQQ, 0, m, &cDelay_SRvDEJQQ_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_nnUdHZyE, 0, m, &sTabread_nnUdHZyE_sendMessage);
}

void Heavy_PhaseRing::cBinop_xUbeWThw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3jqA1lV6, HV_BINOP_MULTIPLY, 0, m, &cBinop_3jqA1lV6_sendMessage);
}

void Heavy_PhaseRing::cCast_z887Guf5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FvajntIJ, 0, m, &cVar_FvajntIJ_sendMessage);
  cMsg_QKeJjtvr_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_3Q6pQxtF, 0, m, &cTabhead_3Q6pQxtF_sendMessage);
}

void Heavy_PhaseRing::cBinop_BsAy2F7t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FTV48A85_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_E9HsfONy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_MYoPVutt_sendMessage);
}

void Heavy_PhaseRing::cSystem_MYoPVutt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_g98VX1mT_sendMessage);
}

void Heavy_PhaseRing::cMsg_FTV48A85_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Ihd8rU1e, 0, m, &hTable_Ihd8rU1e_sendMessage);
}

void Heavy_PhaseRing::hTable_Ihd8rU1e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VKfvcohg_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vCVoF8Y6, 2, m, &cDelay_vCVoF8Y6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LqnklgtN_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_LeA9LPJZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_Ts7aByXn_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_LqnklgtN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_vCVoF8Y6, 0, m, &cDelay_vCVoF8Y6_sendMessage);
}

void Heavy_PhaseRing::cMsg_Ts7aByXn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_uZ2TRHXw, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_VKfvcohg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_VoRz2Y14, 2, m, &cDelay_VoRz2Y14_sendMessage);
}

void Heavy_PhaseRing::cDelay_VoRz2Y14_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VoRz2Y14, m);
  cMsg_jjMvDeh5_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_g98VX1mT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_BsAy2F7t_sendMessage);
}

void Heavy_PhaseRing::cMsg_jjMvDeh5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Ihd8rU1e, 0, m, &hTable_Ihd8rU1e_sendMessage);
}

void Heavy_PhaseRing::cDelay_vCVoF8Y6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vCVoF8Y6, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VoRz2Y14, 0, m, &cDelay_VoRz2Y14_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vCVoF8Y6, 0, m, &cDelay_vCVoF8Y6_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_uZ2TRHXw, 1, m, NULL);
}

void Heavy_PhaseRing::cSystem_0B0Lib5T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VyRFaIWy, HV_BINOP_SUBTRACT, 1, m, &cBinop_VyRFaIWy_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gQ3a2Y3o, 2, m, &cDelay_gQ3a2Y3o_sendMessage);
}

void Heavy_PhaseRing::cCast_6IzpFg3r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Vm0EydV4, 0, m, &cVar_Vm0EydV4_sendMessage);
  cMsg_fqpPVyly_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_QPRA0xEU, 0, m, &cTabhead_QPRA0xEU_sendMessage);
}

void Heavy_PhaseRing::cBinop_EW9QKgcB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MOQyvpVD, HV_BINOP_MULTIPLY, 0, m, &cBinop_MOQyvpVD_sendMessage);
}

void Heavy_PhaseRing::cBinop_KB1XW69P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_be1p6Scl, 2, m, &cDelay_be1p6Scl_sendMessage);
}

void Heavy_PhaseRing::cBinop_MOQyvpVD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uPF21F3t, HV_BINOP_MAX, 0, m, &cBinop_uPF21F3t_sendMessage);
}

void Heavy_PhaseRing::cTabhead_QPRA0xEU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SR7hPznG, HV_BINOP_SUBTRACT, 0, m, &cBinop_SR7hPznG_sendMessage);
}

void Heavy_PhaseRing::cBinop_SR7hPznG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tq2zCPOa_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_e97hKh4b, 0, m, &sTabread_e97hKh4b_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TSENKbWz_sendMessage);
}

void Heavy_PhaseRing::cCast_TSENKbWz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_be1p6Scl, 0, m, &cDelay_be1p6Scl_sendMessage);
}

void Heavy_PhaseRing::cVar_Vm0EydV4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iE7W71iG_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_VyRFaIWy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_KB1XW69P_sendMessage);
}

void Heavy_PhaseRing::cDelay_be1p6Scl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_be1p6Scl, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gQ3a2Y3o, 0, m, &cDelay_gQ3a2Y3o_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_e97hKh4b, 0, m, &sTabread_e97hKh4b_sendMessage);
}

void Heavy_PhaseRing::cMsg_chdZhT2B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_uPF21F3t, HV_BINOP_MAX, 1, m, &cBinop_uPF21F3t_sendMessage);
}

void Heavy_PhaseRing::sTabread_e97hKh4b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_VyRFaIWy, HV_BINOP_SUBTRACT, 0, m, &cBinop_VyRFaIWy_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSystem_BgwRB1bh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_EW9QKgcB_sendMessage);
}

void Heavy_PhaseRing::cMsg_fqpPVyly_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BgwRB1bh_sendMessage);
}

void Heavy_PhaseRing::cDelay_gQ3a2Y3o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gQ3a2Y3o, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_e97hKh4b, 0, m, &sTabread_e97hKh4b_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gQ3a2Y3o, 0, m, &cDelay_gQ3a2Y3o_sendMessage);
}

void Heavy_PhaseRing::cMsg_iE7W71iG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0B0Lib5T_sendMessage);
}

void Heavy_PhaseRing::cMsg_tq2zCPOa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_be1p6Scl, 0, m, &cDelay_be1p6Scl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gQ3a2Y3o, 0, m, &cDelay_gQ3a2Y3o_sendMessage);
}

void Heavy_PhaseRing::cBinop_uPF21F3t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SR7hPznG, HV_BINOP_SUBTRACT, 1, m, &cBinop_SR7hPznG_sendMessage);
}

void Heavy_PhaseRing::cDelay_9j5lZpzC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9j5lZpzC, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_eb8bh5Tb, 0, m, &sTabread_eb8bh5Tb_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9j5lZpzC, 0, m, &cDelay_9j5lZpzC_sendMessage);
}

void Heavy_PhaseRing::cBinop_A2qdipWP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_BlCn8kRL, 2, m, &cDelay_BlCn8kRL_sendMessage);
}

void Heavy_PhaseRing::cMsg_BSZDvBMc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_hiFY5jud, HV_BINOP_MAX, 1, m, &cBinop_hiFY5jud_sendMessage);
}

void Heavy_PhaseRing::cDelay_BlCn8kRL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BlCn8kRL, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9j5lZpzC, 0, m, &cDelay_9j5lZpzC_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_eb8bh5Tb, 0, m, &sTabread_eb8bh5Tb_sendMessage);
}

void Heavy_PhaseRing::cSystem_zRH4yHyo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_d4SSKImG_sendMessage);
}

void Heavy_PhaseRing::cMsg_zWOm0NvF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zRH4yHyo_sendMessage);
}

void Heavy_PhaseRing::cCast_LMzhOrc9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_BlCn8kRL, 0, m, &cDelay_BlCn8kRL_sendMessage);
}

void Heavy_PhaseRing::cVar_NyaNfLkA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yqNnWETm_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_Z2zEx5te_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kKgj26mj, HV_BINOP_SUBTRACT, 1, m, &cBinop_kKgj26mj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9j5lZpzC, 2, m, &cDelay_9j5lZpzC_sendMessage);
}

void Heavy_PhaseRing::cBinop_d4SSKImG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iMw3JeXZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_iMw3JeXZ_sendMessage);
}

void Heavy_PhaseRing::sTabread_eb8bh5Tb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_kKgj26mj, HV_BINOP_SUBTRACT, 0, m, &cBinop_kKgj26mj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cTabhead_gkZkViIT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pCdhdlef, HV_BINOP_SUBTRACT, 0, m, &cBinop_pCdhdlef_sendMessage);
}

void Heavy_PhaseRing::cBinop_hiFY5jud_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pCdhdlef, HV_BINOP_SUBTRACT, 1, m, &cBinop_pCdhdlef_sendMessage);
}

void Heavy_PhaseRing::cBinop_iMw3JeXZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hiFY5jud, HV_BINOP_MAX, 0, m, &cBinop_hiFY5jud_sendMessage);
}

void Heavy_PhaseRing::cBinop_kKgj26mj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_A2qdipWP_sendMessage);
}

void Heavy_PhaseRing::cMsg_mszd6exa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_BlCn8kRL, 0, m, &cDelay_BlCn8kRL_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9j5lZpzC, 0, m, &cDelay_9j5lZpzC_sendMessage);
}

void Heavy_PhaseRing::cBinop_pCdhdlef_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mszd6exa_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_eb8bh5Tb, 0, m, &sTabread_eb8bh5Tb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LMzhOrc9_sendMessage);
}

void Heavy_PhaseRing::cCast_xKIXZsDW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NyaNfLkA, 0, m, &cVar_NyaNfLkA_sendMessage);
  cMsg_zWOm0NvF_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_gkZkViIT, 0, m, &cTabhead_gkZkViIT_sendMessage);
}

void Heavy_PhaseRing::cMsg_yqNnWETm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Z2zEx5te_sendMessage);
}

void Heavy_PhaseRing::cMsg_29D7opEz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NXnCyZ5Y_sendMessage);
}

void Heavy_PhaseRing::cBinop_6vXGL26j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hfBwD0ul, HV_BINOP_MULTIPLY, 0, m, &cBinop_hfBwD0ul_sendMessage);
}

void Heavy_PhaseRing::sTabread_C5jO4OKu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_r5QMKXHk, HV_BINOP_SUBTRACT, 0, m, &cBinop_r5QMKXHk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_CyZwKvwG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_29D7opEz_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cTabhead_DS4N6Am4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JaJAqPJ1, HV_BINOP_SUBTRACT, 0, m, &cBinop_JaJAqPJ1_sendMessage);
}

void Heavy_PhaseRing::cBinop_JaJAqPJ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qnUvXyt6_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_C5jO4OKu, 0, m, &sTabread_C5jO4OKu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_n4i9wjUG_sendMessage);
}

void Heavy_PhaseRing::cSystem_NXnCyZ5Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_r5QMKXHk, HV_BINOP_SUBTRACT, 1, m, &cBinop_r5QMKXHk_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eP92M7yI, 2, m, &cDelay_eP92M7yI_sendMessage);
}

void Heavy_PhaseRing::cMsg_Sj0NUwr7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_jOZg8GKF, HV_BINOP_MAX, 1, m, &cBinop_jOZg8GKF_sendMessage);
}

void Heavy_PhaseRing::cDelay_eP92M7yI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_eP92M7yI, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_C5jO4OKu, 0, m, &sTabread_C5jO4OKu_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eP92M7yI, 0, m, &cDelay_eP92M7yI_sendMessage);
}

void Heavy_PhaseRing::cCast_go72n3cB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CyZwKvwG, 0, m, &cVar_CyZwKvwG_sendMessage);
  cMsg_byZAZmX0_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_DS4N6Am4, 0, m, &cTabhead_DS4N6Am4_sendMessage);
}

void Heavy_PhaseRing::cBinop_hfBwD0ul_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jOZg8GKF, HV_BINOP_MAX, 0, m, &cBinop_jOZg8GKF_sendMessage);
}

void Heavy_PhaseRing::cBinop_jOZg8GKF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JaJAqPJ1, HV_BINOP_SUBTRACT, 1, m, &cBinop_JaJAqPJ1_sendMessage);
}

void Heavy_PhaseRing::cDelay_kzeQGEWX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kzeQGEWX, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eP92M7yI, 0, m, &cDelay_eP92M7yI_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_C5jO4OKu, 0, m, &sTabread_C5jO4OKu_sendMessage);
}

void Heavy_PhaseRing::cCast_n4i9wjUG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_kzeQGEWX, 0, m, &cDelay_kzeQGEWX_sendMessage);
}

void Heavy_PhaseRing::cMsg_qnUvXyt6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_kzeQGEWX, 0, m, &cDelay_kzeQGEWX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eP92M7yI, 0, m, &cDelay_eP92M7yI_sendMessage);
}

void Heavy_PhaseRing::cBinop_r5QMKXHk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_w4V5NSG4_sendMessage);
}

void Heavy_PhaseRing::cBinop_w4V5NSG4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_kzeQGEWX, 2, m, &cDelay_kzeQGEWX_sendMessage);
}

void Heavy_PhaseRing::cMsg_byZAZmX0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yAX56Pd9_sendMessage);
}

void Heavy_PhaseRing::cSystem_yAX56Pd9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_6vXGL26j_sendMessage);
}

void Heavy_PhaseRing::cMsg_4w972H37_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_IthL2pSL, 0, m, &hTable_IthL2pSL_sendMessage);
}

void Heavy_PhaseRing::cBinop_BCdM9s6b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_jd0QSfwR_sendMessage);
}

void Heavy_PhaseRing::cDelay_H06iYQaY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_H06iYQaY, m);
  cMsg_4w972H37_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_HoklGSkr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_IthL2pSL, 0, m, &hTable_IthL2pSL_sendMessage);
}

void Heavy_PhaseRing::hTable_IthL2pSL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YDIiTzgP_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Y16RGS3Z, 2, m, &cDelay_Y16RGS3Z_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Xy9VOMEQ_sendMessage);
}

void Heavy_PhaseRing::cCast_Xy9VOMEQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Y16RGS3Z, 0, m, &cDelay_Y16RGS3Z_sendMessage);
}

void Heavy_PhaseRing::cDelay_Y16RGS3Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Y16RGS3Z, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_H06iYQaY, 0, m, &cDelay_H06iYQaY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Y16RGS3Z, 0, m, &cDelay_Y16RGS3Z_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_FK7ZY9Zc, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_YDIiTzgP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_H06iYQaY, 2, m, &cDelay_H06iYQaY_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_YVE7kUDu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_vF0MFQF5_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_jd0QSfwR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HoklGSkr_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_MfuI8cIc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_BCdM9s6b_sendMessage);
}

void Heavy_PhaseRing::cMsg_iduPjlsA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_MfuI8cIc_sendMessage);
}

void Heavy_PhaseRing::cMsg_vF0MFQF5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_FK7ZY9Zc, 1, m, NULL);
}

void Heavy_PhaseRing::cVar_1pKxZobp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_i2sWEAqS_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_83uf3TZ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gAyoEMk9, HV_BINOP_MULTIPLY, 0, m, &cBinop_gAyoEMk9_sendMessage);
}

void Heavy_PhaseRing::cBinop_BYwSiFqd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uZzF3Ixh_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_OhUPHtZ3, 0, m, &sTabread_OhUPHtZ3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_u7QN2xJi_sendMessage);
}

void Heavy_PhaseRing::sTabread_OhUPHtZ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_SZLN7VJY, HV_BINOP_SUBTRACT, 0, m, &cBinop_SZLN7VJY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_OnXbEHIO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_fb0luNIj, 2, m, &cDelay_fb0luNIj_sendMessage);
}

void Heavy_PhaseRing::cBinop_SZLN7VJY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_OnXbEHIO_sendMessage);
}

void Heavy_PhaseRing::cSystem_X7MhIFbv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SZLN7VJY, HV_BINOP_SUBTRACT, 1, m, &cBinop_SZLN7VJY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZiHqnTvy, 2, m, &cDelay_ZiHqnTvy_sendMessage);
}

void Heavy_PhaseRing::cDelay_ZiHqnTvy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ZiHqnTvy, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_OhUPHtZ3, 0, m, &sTabread_OhUPHtZ3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZiHqnTvy, 0, m, &cDelay_ZiHqnTvy_sendMessage);
}

void Heavy_PhaseRing::cCast_a74RPXwG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1pKxZobp, 0, m, &cVar_1pKxZobp_sendMessage);
  cMsg_DNX0xulF_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_nsk9h2Kd, 0, m, &cTabhead_nsk9h2Kd_sendMessage);
}

void Heavy_PhaseRing::cBinop_bez6MEJQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BYwSiFqd, HV_BINOP_SUBTRACT, 1, m, &cBinop_BYwSiFqd_sendMessage);
}

void Heavy_PhaseRing::cMsg_DNX0xulF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_e9vwzbnU_sendMessage);
}

void Heavy_PhaseRing::cSystem_e9vwzbnU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_83uf3TZ0_sendMessage);
}

void Heavy_PhaseRing::cDelay_fb0luNIj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fb0luNIj, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZiHqnTvy, 0, m, &cDelay_ZiHqnTvy_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_OhUPHtZ3, 0, m, &sTabread_OhUPHtZ3_sendMessage);
}

void Heavy_PhaseRing::cBinop_gAyoEMk9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bez6MEJQ, HV_BINOP_MAX, 0, m, &cBinop_bez6MEJQ_sendMessage);
}

void Heavy_PhaseRing::cMsg_i2sWEAqS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_X7MhIFbv_sendMessage);
}

void Heavy_PhaseRing::cTabhead_nsk9h2Kd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BYwSiFqd, HV_BINOP_SUBTRACT, 0, m, &cBinop_BYwSiFqd_sendMessage);
}

void Heavy_PhaseRing::cCast_u7QN2xJi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_fb0luNIj, 0, m, &cDelay_fb0luNIj_sendMessage);
}

void Heavy_PhaseRing::cMsg_uZzF3Ixh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_fb0luNIj, 0, m, &cDelay_fb0luNIj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZiHqnTvy, 0, m, &cDelay_ZiHqnTvy_sendMessage);
}

void Heavy_PhaseRing::cMsg_yHzGJqcW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_bez6MEJQ, HV_BINOP_MAX, 1, m, &cBinop_bez6MEJQ_sendMessage);
}

void Heavy_PhaseRing::cMsg_042yoXJ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_XKYrkvpC, 0, m, &cDelay_XKYrkvpC_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fUsvd0uS, 0, m, &cDelay_fUsvd0uS_sendMessage);
}

void Heavy_PhaseRing::cSystem_11Zp0toZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tpsURXEj, HV_BINOP_SUBTRACT, 1, m, &cBinop_tpsURXEj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fUsvd0uS, 2, m, &cDelay_fUsvd0uS_sendMessage);
}

void Heavy_PhaseRing::cVar_4SIWhr2j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_r6nXlxRF_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_9GHlIlKa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ywh5Astp, HV_BINOP_MULTIPLY, 0, m, &cBinop_ywh5Astp_sendMessage);
}

void Heavy_PhaseRing::cTabhead_B8rsFDCy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bMr6R5go, HV_BINOP_SUBTRACT, 0, m, &cBinop_bMr6R5go_sendMessage);
}

void Heavy_PhaseRing::sTabread_EdSrWJPJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_tpsURXEj, HV_BINOP_SUBTRACT, 0, m, &cBinop_tpsURXEj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_LQVVX95x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XKYrkvpC, 2, m, &cDelay_XKYrkvpC_sendMessage);
}

void Heavy_PhaseRing::cCast_ORLQgjdS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4SIWhr2j, 0, m, &cVar_4SIWhr2j_sendMessage);
  cMsg_poRBq8Yk_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_B8rsFDCy, 0, m, &cTabhead_B8rsFDCy_sendMessage);
}

void Heavy_PhaseRing::cBinop_Q2XDi7go_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bMr6R5go, HV_BINOP_SUBTRACT, 1, m, &cBinop_bMr6R5go_sendMessage);
}

void Heavy_PhaseRing::cCast_Qfn39Lqf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XKYrkvpC, 0, m, &cDelay_XKYrkvpC_sendMessage);
}

void Heavy_PhaseRing::cDelay_XKYrkvpC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XKYrkvpC, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fUsvd0uS, 0, m, &cDelay_fUsvd0uS_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_EdSrWJPJ, 0, m, &sTabread_EdSrWJPJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_bMr6R5go_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_042yoXJ3_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_EdSrWJPJ, 0, m, &sTabread_EdSrWJPJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Qfn39Lqf_sendMessage);
}

void Heavy_PhaseRing::cSystem_grkTr9eY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9GHlIlKa_sendMessage);
}

void Heavy_PhaseRing::cMsg_poRBq8Yk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_grkTr9eY_sendMessage);
}

void Heavy_PhaseRing::cDelay_fUsvd0uS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fUsvd0uS, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_EdSrWJPJ, 0, m, &sTabread_EdSrWJPJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fUsvd0uS, 0, m, &cDelay_fUsvd0uS_sendMessage);
}

void Heavy_PhaseRing::cMsg_mBu9oTLu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_Q2XDi7go, HV_BINOP_MAX, 1, m, &cBinop_Q2XDi7go_sendMessage);
}

void Heavy_PhaseRing::cMsg_r6nXlxRF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_11Zp0toZ_sendMessage);
}

void Heavy_PhaseRing::cBinop_tpsURXEj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_LQVVX95x_sendMessage);
}

void Heavy_PhaseRing::cBinop_ywh5Astp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Q2XDi7go, HV_BINOP_MAX, 0, m, &cBinop_Q2XDi7go_sendMessage);
}

void Heavy_PhaseRing::cCast_432Dk4Bc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_lfIcRWtT, 0, m, &cDelay_lfIcRWtT_sendMessage);
}

void Heavy_PhaseRing::cSystem_dfdiRfsP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Z1nbb8tR_sendMessage);
}

void Heavy_PhaseRing::cMsg_fVfsr6BU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dfdiRfsP_sendMessage);
}

void Heavy_PhaseRing::cBinop_KZlqbbt0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lbIiWvQj_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_S57FtT40_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_S5frDtKM_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cMsg_S5frDtKM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_iTQ4HjJE, 1, m, NULL);
}

void Heavy_PhaseRing::cBinop_Z1nbb8tR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_KZlqbbt0_sendMessage);
}

void Heavy_PhaseRing::cMsg_eUadoWDE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_nXPbjI1C, 0, m, &hTable_nXPbjI1C_sendMessage);
}

void Heavy_PhaseRing::cMsg_gJI5XJwD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_qi7CmTpO, 2, m, &cDelay_qi7CmTpO_sendMessage);
}

void Heavy_PhaseRing::cMsg_lbIiWvQj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_nXPbjI1C, 0, m, &hTable_nXPbjI1C_sendMessage);
}

void Heavy_PhaseRing::cDelay_lfIcRWtT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_lfIcRWtT, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_qi7CmTpO, 0, m, &cDelay_qi7CmTpO_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lfIcRWtT, 0, m, &cDelay_lfIcRWtT_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_iTQ4HjJE, 1, m, NULL);
}

void Heavy_PhaseRing::hTable_nXPbjI1C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gJI5XJwD_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lfIcRWtT, 2, m, &cDelay_lfIcRWtT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_432Dk4Bc_sendMessage);
}

void Heavy_PhaseRing::cDelay_qi7CmTpO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_qi7CmTpO, m);
  cMsg_eUadoWDE_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_AekXWSkG_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_XIEBpbZK_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cMsg_IjUpociI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_vYYMVUJF, 0, m, &hTable_vYYMVUJF_sendMessage);
}

void Heavy_PhaseRing::cBinop_LMATvgMi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IjUpociI_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_U0KGgaVu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_U0KGgaVu, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_g49bXLsX, 0, m, &cDelay_g49bXLsX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_U0KGgaVu, 0, m, &cDelay_U0KGgaVu_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_LGgBdvgv, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_XIEBpbZK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_LGgBdvgv, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_XJwhKb1l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_vYYMVUJF, 0, m, &hTable_vYYMVUJF_sendMessage);
}

void Heavy_PhaseRing::cDelay_g49bXLsX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_g49bXLsX, m);
  cMsg_XJwhKb1l_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_mmnyt39j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_g49bXLsX, 2, m, &cDelay_g49bXLsX_sendMessage);
}

void Heavy_PhaseRing::cSystem_8rgrPRoI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_sixAVXL2_sendMessage);
}

void Heavy_PhaseRing::cMsg_bi9h8UQd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8rgrPRoI_sendMessage);
}

void Heavy_PhaseRing::cBinop_sixAVXL2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_LMATvgMi_sendMessage);
}

void Heavy_PhaseRing::hTable_vYYMVUJF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mmnyt39j_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_U0KGgaVu, 2, m, &cDelay_U0KGgaVu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wTGGx3a7_sendMessage);
}

void Heavy_PhaseRing::cCast_wTGGx3a7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_U0KGgaVu, 0, m, &cDelay_U0KGgaVu_sendMessage);
}

void Heavy_PhaseRing::cVar_Frl5U0tE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_GKgeOSLt_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_5hrMSHjI, 0, m, &cIf_5hrMSHjI_sendMessage);
}

void Heavy_PhaseRing::cPack_g6JH5Xab_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_gbFnM2vA, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_gjxfcIYu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_RAc1gTQk, 0, m, &cVar_RAc1gTQk_sendMessage);
}

void Heavy_PhaseRing::cBinop_LNxXOEJe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Wg55a7ii, HV_BINOP_MULTIPLY, 1, m, &cBinop_Wg55a7ii_sendMessage);
}

void Heavy_PhaseRing::cSystem_7tS212Pu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lK794eo9_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_xzVUNQf1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7tS212Pu_sendMessage);
}

void Heavy_PhaseRing::cBinop_Wg55a7ii_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_74Im5Epj_sendMessage);
}

void Heavy_PhaseRing::cMsg_lK794eo9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_LNxXOEJe_sendMessage);
}

void Heavy_PhaseRing::cBinop_0sNdwc3J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_r9l0OfEj_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ViC9Xs9H, m);
}

void Heavy_PhaseRing::cBinop_74Im5Epj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_0sNdwc3J_sendMessage);
}

void Heavy_PhaseRing::cBinop_r9l0OfEj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_E5XOmBsT, m);
}

void Heavy_PhaseRing::cVar_uJPgy3G3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Wg55a7ii, HV_BINOP_MULTIPLY, 0, m, &cBinop_Wg55a7ii_sendMessage);
}

void Heavy_PhaseRing::cVar_RAc1gTQk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aNKDDy1w, 0, m, &cVar_aNKDDy1w_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_uJPgy3G3, 0, m, &cVar_uJPgy3G3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_n0OW9d5Z, 0, m, &cVar_n0OW9d5Z_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_xOKOV2RP, 0, m, &cVar_xOKOV2RP_sendMessage);
}

void Heavy_PhaseRing::cBinop_u1yWyNXr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_F8HuyRy2, 0, m, &cPack_F8HuyRy2_sendMessage);
}

void Heavy_PhaseRing::cBinop_4XvV0GHE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_REUIwa4s_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_8FZC5ZM0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_OsO9JWCJ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_MC0w3sPQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_kqeZyXEj, 0, m, &cDelay_kqeZyXEj_sendMessage);
}

void Heavy_PhaseRing::cMsg_OsO9JWCJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_5jS6srXY, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_REUIwa4s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_xZ2WvPm3, 0, m, &hTable_xZ2WvPm3_sendMessage);
}

void Heavy_PhaseRing::cMsg_ebxfkhqp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_oHSKHBWc_sendMessage);
}

void Heavy_PhaseRing::cSystem_oHSKHBWc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_xKqKKDyL_sendMessage);
}

void Heavy_PhaseRing::cMsg_eAv98oF6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_mb0EJZND, 2, m, &cDelay_mb0EJZND_sendMessage);
}

void Heavy_PhaseRing::cMsg_jy0oEUYt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_xZ2WvPm3, 0, m, &hTable_xZ2WvPm3_sendMessage);
}

void Heavy_PhaseRing::cDelay_kqeZyXEj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kqeZyXEj, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mb0EJZND, 0, m, &cDelay_mb0EJZND_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kqeZyXEj, 0, m, &cDelay_kqeZyXEj_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_5jS6srXY, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_mb0EJZND_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mb0EJZND, m);
  cMsg_jy0oEUYt_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_xKqKKDyL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_4XvV0GHE_sendMessage);
}

void Heavy_PhaseRing::hTable_xZ2WvPm3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eAv98oF6_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kqeZyXEj, 2, m, &cDelay_kqeZyXEj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MC0w3sPQ_sendMessage);
}

void Heavy_PhaseRing::cCast_LcMyXhPg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_rEAPspkj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_09egX2x5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Vq1Yeauh, 0, m, &cDelay_Vq1Yeauh_sendMessage);
}

void Heavy_PhaseRing::cCast_D1Ze6WXd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Vq1Yeauh, 0, m, &cDelay_Vq1Yeauh_sendMessage);
}

void Heavy_PhaseRing::cDelay_Vq1Yeauh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Vq1Yeauh, m);
  cMsg_BXXOqjmp_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_rEAPspkj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_09egX2x5_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_09egX2x5_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_Vq1Yeauh, 1, m, &cDelay_Vq1Yeauh_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_D1Ze6WXd_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cSystem_0R1Knx8w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_O1Zd7m3m_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_sucPMcJm, m);
}

void Heavy_PhaseRing::cSystem_OnXOGtNY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_arcJteX4_sendMessage);
}

void Heavy_PhaseRing::cMsg_sF4ENJM2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OnXOGtNY_sendMessage);
}

void Heavy_PhaseRing::cBinop_O1Zd7m3m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_3e28mQa2, m);
}

void Heavy_PhaseRing::cBinop_arcJteX4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_rSZruvN3, m);
}

void Heavy_PhaseRing::cVar_5fedlGmy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_muWy6S2R_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_muWy6S2R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0R1Knx8w_sendMessage);
}

void Heavy_PhaseRing::cVar_oHtZFmjA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nSEOksCu_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_BApdDvzh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_iVuTIRas_sendMessage);
}

void Heavy_PhaseRing::cBinop_iVuTIRas_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_wBfaLUl9_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_9Mx8pfod, m);
}

void Heavy_PhaseRing::cSystem_BzaMu6CZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cK6PJVWh_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_iQ4XrmSJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BzaMu6CZ_sendMessage);
}

void Heavy_PhaseRing::cBinop_DuvZOjuv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_BApdDvzh_sendMessage);
}

void Heavy_PhaseRing::cBinop_R2lAHbnV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DuvZOjuv, HV_BINOP_MULTIPLY, 1, m, &cBinop_DuvZOjuv_sendMessage);
}

void Heavy_PhaseRing::cMsg_cK6PJVWh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_R2lAHbnV_sendMessage);
}

void Heavy_PhaseRing::cBinop_wBfaLUl9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_7NwAu0fS, m);
}

void Heavy_PhaseRing::cVar_OrIWR535_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DuvZOjuv, HV_BINOP_MULTIPLY, 0, m, &cBinop_DuvZOjuv_sendMessage);
}

void Heavy_PhaseRing::cMsg_GJHlkGse_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_nSEOksCu_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_2tfTFFNa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_DNLO2Q6E, 0, m, &hTable_DNLO2Q6E_sendMessage);
}

void Heavy_PhaseRing::cMsg_6sv97Pn6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_oqOZrV6L, 1, m, NULL);
}

void Heavy_PhaseRing::cSwitchcase_7esazfJL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_6sv97Pn6_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cMsg_8tMHmxhJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_DNLO2Q6E, 0, m, &hTable_DNLO2Q6E_sendMessage);
}

void Heavy_PhaseRing::hTable_DNLO2Q6E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kvtMu9JI_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yjChgp9C, 2, m, &cDelay_yjChgp9C_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QGBaQ4kR_sendMessage);
}

void Heavy_PhaseRing::cCast_QGBaQ4kR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_yjChgp9C, 0, m, &cDelay_yjChgp9C_sendMessage);
}

void Heavy_PhaseRing::cDelay_a02YFaxE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_a02YFaxE, m);
  cMsg_2tfTFFNa_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_fV3JiwAZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8tMHmxhJ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_kvtMu9JI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_a02YFaxE, 2, m, &cDelay_a02YFaxE_sendMessage);
}

void Heavy_PhaseRing::cMsg_4cVpYjLo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kOykDgdy_sendMessage);
}

void Heavy_PhaseRing::cSystem_kOykDgdy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_x1IggyER_sendMessage);
}

void Heavy_PhaseRing::cBinop_x1IggyER_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_fV3JiwAZ_sendMessage);
}

void Heavy_PhaseRing::cDelay_yjChgp9C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_yjChgp9C, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_a02YFaxE, 0, m, &cDelay_a02YFaxE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yjChgp9C, 0, m, &cDelay_yjChgp9C_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_oqOZrV6L, 1, m, NULL);
}

void Heavy_PhaseRing::cBinop_12fulvDw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_Vx8uFmq4_sendMessage);
}

void Heavy_PhaseRing::cBinop_3PJFmvdb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_tLHmnMAO_sendMessage);
}

void Heavy_PhaseRing::cBinop_7cdUX4Hn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_spUPSbLx_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_g2lHkJLb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_12fulvDw_sendMessage);
}

void Heavy_PhaseRing::cBinop_KjwZVBLL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_M29kU6Ow, m);
}

void Heavy_PhaseRing::cBinop_Vx8uFmq4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7cdUX4Hn, HV_BINOP_DIVIDE, 0, m, &cBinop_7cdUX4Hn_sendMessage);
}

void Heavy_PhaseRing::cBinop_x0L5ccDc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_3PJFmvdb_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_KjwZVBLL_sendMessage);
}

void Heavy_PhaseRing::cBinop_ydPhC46D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_x0L5ccDc_sendMessage);
}

void Heavy_PhaseRing::cMsg_3F3lBHb1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5YO3SSRO_sendMessage);
}

void Heavy_PhaseRing::cSystem_5YO3SSRO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7cdUX4Hn, HV_BINOP_DIVIDE, 1, m, &cBinop_7cdUX4Hn_sendMessage);
}

void Heavy_PhaseRing::cBinop_nWLQXqJ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_ydPhC46D_sendMessage);
}

void Heavy_PhaseRing::cMsg_spUPSbLx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_nWLQXqJ2_sendMessage);
}

void Heavy_PhaseRing::cBinop_tLHmnMAO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_p26kg6N6, m);
}

void Heavy_PhaseRing::cMsg_nSEOksCu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_JQgYV19Q, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_3HCrObNu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_hF6qtUiu_sendMessage);
}

void Heavy_PhaseRing::cBinop_hF6qtUiu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_JPi9YWMY, m);
}

void Heavy_PhaseRing::cVar_VeweU8cf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_jXIZLaVa_sendMessage);
}

void Heavy_PhaseRing::cMsg_pcfCC84r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.3f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_3HCrObNu_sendMessage);
}

void Heavy_PhaseRing::cPack_rA537VEj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_18onNJj2, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_yDNqQqM2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_rA537VEj, 0, m, &cPack_rA537VEj_sendMessage);
}

void Heavy_PhaseRing::cReceive_4obOa0kA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_qmEe7gUE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_B8O8L9sI, 0, m, &cVar_B8O8L9sI_sendMessage);
}

void Heavy_PhaseRing::cReceive_51yGrh40_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_k8AwyJ1I_sendMessage);
}

void Heavy_PhaseRing::cReceive_7LPHN0NA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6dMXYTkw_sendMessage);
}

void Heavy_PhaseRing::cSend_8ND0vZJg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_qGYudbvd_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_12m3dBEK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_nJ0ljWw2_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_PIqMfTiA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_BESXMmVO_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_BESXMmVO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_3MPn0eo7_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_WRoR86Nx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_GjTjo5pj, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_2Vwtbwn1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_12m3dBEK_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gaisByIG_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1EKsOIxg_sendMessage);
}

void Heavy_PhaseRing::cSend_nJ0ljWw2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_NG3d9ZnJ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_1EKsOIxg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_8GBw3dsw, 0, m, &cIf_8GBw3dsw_sendMessage);
}

void Heavy_PhaseRing::cBinop_4SGU8R8p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_sKGp46Oq_sendMessage);
}

void Heavy_PhaseRing::cMsg_7g80oYVv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_w5XBQqBX, HV_BINOP_POW, 0, m, &cBinop_w5XBQqBX_sendMessage);
}

void Heavy_PhaseRing::cIf_8GBw3dsw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_9YTau6XD_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_4SGU8R8p_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_9YTau6XD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_WRoR86Nx, 0, m, &cPack_WRoR86Nx_sendMessage);
}

void Heavy_PhaseRing::cBinop_JegajEfW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_8GBw3dsw, 1, m, &cIf_8GBw3dsw_sendMessage);
}

void Heavy_PhaseRing::cCast_gaisByIG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_JegajEfW_sendMessage);
}

void Heavy_PhaseRing::cBinop_qaUhLeR0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_w5XBQqBX, HV_BINOP_POW, 1, m, &cBinop_w5XBQqBX_sendMessage);
  cMsg_7g80oYVv_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_sKGp46Oq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_qaUhLeR0_sendMessage);
}

void Heavy_PhaseRing::cBinop_w5XBQqBX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_WRoR86Nx, 0, m, &cPack_WRoR86Nx_sendMessage);
}

void Heavy_PhaseRing::cReceive_9nbcLdkc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JRUzHE8k, 1, m, &cVar_JRUzHE8k_sendMessage);
}

void Heavy_PhaseRing::cReceive_9pCuWkDN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_aYZNOk2j, 0, m, &cPack_aYZNOk2j_sendMessage);
}

void Heavy_PhaseRing::cSend_BaGdM4qH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cBinop_BwFkibjw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_end46Sci_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cReceive_E2l5nDr2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_snAvqQ4P_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_URVh5iIh, 0, m, &cVar_URVh5iIh_sendMessage);
}

void Heavy_PhaseRing::cReceive_E9eaimzv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZnRuqqxT, 0, m, &cVar_ZnRuqqxT_sendMessage);
}

void Heavy_PhaseRing::cSend_OVJZFiO2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_E9eaimzv_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_ZnRuqqxT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_b1Fmust1_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_QZTG8pD2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_kVQ0MSvK, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_g1TbQbno_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_p5MKmmfg_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Eut0jGmw_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jfIzGcEn_sendMessage);
}

void Heavy_PhaseRing::cSend_b1Fmust1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_psluHfVQ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_19MtzG5q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_QZTG8pD2, 0, m, &cPack_QZTG8pD2_sendMessage);
}

void Heavy_PhaseRing::cMsg_C1fMbftk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_19MtzG5q, HV_BINOP_POW, 0, m, &cBinop_19MtzG5q_sendMessage);
}

void Heavy_PhaseRing::cMsg_DfufxNZa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_QZTG8pD2, 0, m, &cPack_QZTG8pD2_sendMessage);
}

void Heavy_PhaseRing::cCast_Eut0jGmw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_RnWaeGkw_sendMessage);
}

void Heavy_PhaseRing::cBinop_QrLiEZcZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_19MtzG5q, HV_BINOP_POW, 1, m, &cBinop_19MtzG5q_sendMessage);
  cMsg_C1fMbftk_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_RnWaeGkw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_wg92yDLt, 1, m, &cIf_wg92yDLt_sendMessage);
}

void Heavy_PhaseRing::cCast_jfIzGcEn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_wg92yDLt, 0, m, &cIf_wg92yDLt_sendMessage);
}

void Heavy_PhaseRing::cBinop_ku6PHOvt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_nivVNDEV_sendMessage);
}

void Heavy_PhaseRing::cBinop_nivVNDEV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_QrLiEZcZ_sendMessage);
}

void Heavy_PhaseRing::cIf_wg92yDLt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_DfufxNZa_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_ku6PHOvt_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_p5MKmmfg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_OVJZFiO2_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cReceive_FOxlk4ls_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_n1drs6ME_sendMessage(_c, 0, m);
  cMsg_stZaYNFS_sendMessage(_c, 0, m);
  cMsg_S3EzNmf7_sendMessage(_c, 0, m);
  cMsg_hYE2jt41_sendMessage(_c, 0, m);
  cMsg_aMSLNb5u_sendMessage(_c, 0, m);
  cMsg_ORab0XlS_sendMessage(_c, 0, m);
  cMsg_bi9h8UQd_sendMessage(_c, 0, m);
  cMsg_fVfsr6BU_sendMessage(_c, 0, m);
  cMsg_iduPjlsA_sendMessage(_c, 0, m);
  cMsg_UFkvbtYD_sendMessage(_c, 0, m);
  cMsg_Iopt7YnK_sendMessage(_c, 0, m);
  cMsg_E9HsfONy_sendMessage(_c, 0, m);
  cMsg_AQ3aaPPE_sendMessage(_c, 0, m);
  cMsg_lT3yyo1g_sendMessage(_c, 0, m);
  cMsg_bIRRz79x_sendMessage(_c, 0, m);
  cMsg_m8tkTnxv_sendMessage(_c, 0, m);
  cMsg_8EDJoabJ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_79eXwPNq, 0, m, &cVar_79eXwPNq_sendMessage);
  cMsg_Gnuw3zEv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3ebC2MQw, 0, m, &cVar_3ebC2MQw_sendMessage);
  cMsg_lHovu4AG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_HHodeCyW, 0, m, &cVar_HHodeCyW_sendMessage);
  cMsg_Ccent5HC_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_wslmKKEl, 0, m, &cVar_wslmKKEl_sendMessage);
  cMsg_1zJ53JCY_sendMessage(_c, 0, m);
  cMsg_Eej5cfCi_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_V8U2V56F, 0, m, &cVar_V8U2V56F_sendMessage);
  cMsg_gBDy3SwE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_vt9w4O4j, 0, m, &cVar_vt9w4O4j_sendMessage);
  cMsg_l2aq8nF3_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_KJy5h15i, 0, m, &cVar_KJy5h15i_sendMessage);
  cMsg_rutu4pRj_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_c4leJELR, 0, m, &cVar_c4leJELR_sendMessage);
  cMsg_K40Zj5Ga_sendMessage(_c, 0, m);
  cMsg_ebxfkhqp_sendMessage(_c, 0, m);
  cMsg_nNoHMgri_sendMessage(_c, 0, m);
  cMsg_oO3Ayabh_sendMessage(_c, 0, m);
  cMsg_dw3iN5tH_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_aNKDDy1w, 0, m, &cVar_aNKDDy1w_sendMessage);
  cMsg_xzVUNQf1_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_uJPgy3G3, 0, m, &cVar_uJPgy3G3_sendMessage);
  cMsg_Jd1xaoWz_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_n0OW9d5Z, 0, m, &cVar_n0OW9d5Z_sendMessage);
  cMsg_JEmUlSr7_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_xOKOV2RP, 0, m, &cVar_xOKOV2RP_sendMessage);
  cMsg_iQ4XrmSJ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_OrIWR535, 0, m, &cVar_OrIWR535_sendMessage);
  cMsg_3F3lBHb1_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_g2lHkJLb, 0, m, &cVar_g2lHkJLb_sendMessage);
  cMsg_4cVpYjLo_sendMessage(_c, 0, m);
  cMsg_1FXVvnZD_sendMessage(_c, 0, m);
  cMsg_zYWdeEVl_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Zh5CpgkH, 0, m, &cVar_Zh5CpgkH_sendMessage);
  cMsg_8kC8iy6a_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_AEqntZmC, 0, m, &cVar_AEqntZmC_sendMessage);
  cMsg_fGcfnWY5_sendMessage(_c, 0, m);
  cMsg_BXf3gGB2_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_uFOa9EQn, 0, m, &cVar_uFOa9EQn_sendMessage);
  cMsg_3NtscPYZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_NbGYCTWS, 0, m, &cVar_NbGYCTWS_sendMessage);
  cMsg_uS0HGpAT_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5b8HQKK4, 0, m, &cVar_5b8HQKK4_sendMessage);
  cMsg_Z55xr7wA_sendMessage(_c, 0, m);
  cMsg_Bt5rB8Xe_sendMessage(_c, 0, m);
  cMsg_48SBJYG2_sendMessage(_c, 0, m);
  cMsg_DdiPD7yC_sendMessage(_c, 0, m);
  cMsg_ednbj8Hb_sendMessage(_c, 0, m);
  cMsg_lstABI0x_sendMessage(_c, 0, m);
  cMsg_et2BmXfG_sendMessage(_c, 0, m);
  cMsg_90UkU0ro_sendMessage(_c, 0, m);
  cMsg_YYz6qie4_sendMessage(_c, 0, m);
  cMsg_v3IWYFVs_sendMessage(_c, 0, m);
  cMsg_IzpMzzdU_sendMessage(_c, 0, m);
  cMsg_af5JXkiI_sendMessage(_c, 0, m);
  cMsg_pjAnMW0Z_sendMessage(_c, 0, m);
  cMsg_kxfHNcBa_sendMessage(_c, 0, m);
  cMsg_o41EzHYb_sendMessage(_c, 0, m);
  cMsg_BSaQylVh_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_KynI9x7n, 0, m, &cVar_KynI9x7n_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_cmJe2ZF3, 0, m, &cVar_cmJe2ZF3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_UUn8tahx, 0, m, &cVar_UUn8tahx_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_AuTsPu8K, 0, m, &cVar_AuTsPu8K_sendMessage);
  cMsg_5d4tbG8C_sendMessage(_c, 0, m);
  cMsg_I7jeegSh_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_JFGPsHUn, 0, m, &cVar_JFGPsHUn_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_3YopkI0B, 0, m, &cVar_3YopkI0B_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Frl5U0tE, 0, m, &cVar_Frl5U0tE_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ArNlzdTb, 0, m, &cVar_ArNlzdTb_sendMessage);
  cMsg_GJHlkGse_sendMessage(_c, 0, m);
  cMsg_98byR0lf_sendMessage(_c, 0, m);
  cMsg_iNSrJ8qJ_sendMessage(_c, 0, m);
  cMsg_THE8zvck_sendMessage(_c, 0, m);
  cMsg_MmFxET5O_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Ew8y3Pqu, 0, m, &cVar_Ew8y3Pqu_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Q5I7LvD0, 0, m, &cVar_Q5I7LvD0_sendMessage);
  cMsg_fzazrusm_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_rWD7gUpk, 0, m, &cVar_rWD7gUpk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_YLXidWTk, 0, m, &cVar_YLXidWTk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Rz1THrHZ, 0, m, &cVar_Rz1THrHZ_sendMessage);
  cMsg_JLE9Gnum_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BC9CteRo, 0, m, &cVar_BC9CteRo_sendMessage);
  cMsg_09qvXUtI_sendMessage(_c, 0, m);
  cMsg_kymfi3IE_sendMessage(_c, 0, m);
  cMsg_6NZX3shK_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VeweU8cf, 0, m, &cVar_VeweU8cf_sendMessage);
  cMsg_ClcVTFK7_sendMessage(_c, 0, m);
  cMsg_pcfCC84r_sendMessage(_c, 0, m);
  cMsg_wlTj1r3f_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_2Vwtbwn1, 0, m, &cVar_2Vwtbwn1_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_PmTLRsbz, 0, m, &cVar_PmTLRsbz_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_iiLdsRJw, 0, m, &cVar_iiLdsRJw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_mUArOlqK, 0, m, &cVar_mUArOlqK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_g1TbQbno, 0, m, &cVar_g1TbQbno_sendMessage);
  cMsg_P9rxUXcZ_sendMessage(_c, 0, m);
  cSwitchcase_7AyEZaBn_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_1HRfmt7H_onMessage(_c, NULL, 0, m, NULL);
  cMsg_BHxpRmB8_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0FiP8cTk, 0, m, &cVar_0FiP8cTk_sendMessage);
  cMsg_b2BDuKG9_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_DLiYW0yc, 0, m, &cTabhead_DLiYW0yc_sendMessage);
  cMsg_0D2kpuST_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_dcr34w93, 0, m, &cVar_dcr34w93_sendMessage);
  cMsg_E5MjjYrs_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_dQ3czwaE, 0, m, &cTabhead_dQ3czwaE_sendMessage);
  cMsg_gNspD6OU_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VTNOHwN0, 0, m, &cVar_VTNOHwN0_sendMessage);
  cMsg_ezK46nqC_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_71Es4iyb, 0, m, &cTabhead_71Es4iyb_sendMessage);
  cMsg_LxBrcFvv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_gYbFrBc4, 0, m, &cVar_gYbFrBc4_sendMessage);
  cMsg_LXp2Vd2j_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_kLk2DX0g, 0, m, &cTabhead_kLk2DX0g_sendMessage);
  cMsg_MW5IAokN_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_PQNSHPhM, 0, m, &cVar_PQNSHPhM_sendMessage);
  cMsg_pfaPnV1i_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_heIpMdiJ, 0, m, &cTabhead_heIpMdiJ_sendMessage);
  cMsg_qQh6LlcC_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3NAiTsmS, 0, m, &cVar_3NAiTsmS_sendMessage);
  cMsg_WBu661zv_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_lb5cMSir, 0, m, &cTabhead_lb5cMSir_sendMessage);
  cMsg_Uyt9Kp3d_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ARLoyoKS, 0, m, &cVar_ARLoyoKS_sendMessage);
  cMsg_PJW0hS1Y_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_T8w4BbxS, 0, m, &cTabhead_T8w4BbxS_sendMessage);
  cMsg_Nk0dsf1u_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Ww33Z3B8, 0, m, &cVar_Ww33Z3B8_sendMessage);
  cMsg_Vs8eTpBv_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_A7o0J11Z, 0, m, &cTabhead_A7o0J11Z_sendMessage);
  cMsg_ipJqZGMy_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VmmijPxO, 0, m, &cVar_VmmijPxO_sendMessage);
  cMsg_WA1JyZAo_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_F50fcYF4, 0, m, &cTabhead_F50fcYF4_sendMessage);
  cMsg_gDbLMSEB_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_QfPiEje7, 0, m, &cVar_QfPiEje7_sendMessage);
  cMsg_PSPF92vu_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ol9BBsMZ, 0, m, &cTabhead_ol9BBsMZ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VeDuEHXS, 0, m, &cVar_VeDuEHXS_sendMessage);
  cMsg_6dHVvDyN_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_eOpK91eD, 0, m, &cVar_eOpK91eD_sendMessage);
  cMsg_I8JctwzM_sendMessage(_c, 0, m);
  cMsg_s5UZrpvX_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5Int7Eww, 0, m, &cVar_5Int7Eww_sendMessage);
  cMsg_rDm5AsVt_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_lOupEdQR, 0, m, &cTabhead_lOupEdQR_sendMessage);
  cMsg_2rtNKmHh_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_g0Qcphhf, 0, m, &cVar_g0Qcphhf_sendMessage);
  cMsg_KUpx3UdS_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_6FU7ijsM, 0, m, &cTabhead_6FU7ijsM_sendMessage);
  cMsg_QU6FQE0w_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_QqD0MpYN, 0, m, &cVar_QqD0MpYN_sendMessage);
  cMsg_j5zyOgSC_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_wiTpTbLI, 0, m, &cTabhead_wiTpTbLI_sendMessage);
  cMsg_L3kgoQlT_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Lir9aKYE, 0, m, &cVar_Lir9aKYE_sendMessage);
  cMsg_6e7V5BTV_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_mbFM2wzE, 0, m, &cTabhead_mbFM2wzE_sendMessage);
  cMsg_Sj0NUwr7_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_CyZwKvwG, 0, m, &cVar_CyZwKvwG_sendMessage);
  cMsg_byZAZmX0_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_DS4N6Am4, 0, m, &cTabhead_DS4N6Am4_sendMessage);
  cMsg_mBu9oTLu_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4SIWhr2j, 0, m, &cVar_4SIWhr2j_sendMessage);
  cMsg_poRBq8Yk_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_B8rsFDCy, 0, m, &cTabhead_B8rsFDCy_sendMessage);
  cMsg_hwhHDvGW_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_FvajntIJ, 0, m, &cVar_FvajntIJ_sendMessage);
  cMsg_QKeJjtvr_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_3Q6pQxtF, 0, m, &cTabhead_3Q6pQxtF_sendMessage);
  cMsg_chdZhT2B_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Vm0EydV4, 0, m, &cVar_Vm0EydV4_sendMessage);
  cMsg_fqpPVyly_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_QPRA0xEU, 0, m, &cTabhead_QPRA0xEU_sendMessage);
  cMsg_yHzGJqcW_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_1pKxZobp, 0, m, &cVar_1pKxZobp_sendMessage);
  cMsg_DNX0xulF_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_nsk9h2Kd, 0, m, &cTabhead_nsk9h2Kd_sendMessage);
  cMsg_BSZDvBMc_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_NyaNfLkA, 0, m, &cVar_NyaNfLkA_sendMessage);
  cMsg_zWOm0NvF_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_gkZkViIT, 0, m, &cTabhead_gkZkViIT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_5fedlGmy, 0, m, &cVar_5fedlGmy_sendMessage);
  cMsg_sF4ENJM2_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_hJUM360N, 0, m, &cVar_hJUM360N_sendMessage);
  cMsg_HoqWlP8S_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TvRTzorQ, 0, m, &cVar_TvRTzorQ_sendMessage);
  cMsg_Q2Ttx1T7_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_KlMuSvkx, 0, m, &cVar_KlMuSvkx_sendMessage);
  cMsg_RS1dD6wF_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_BC9CteRo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_d6t36hD5_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_76N9iLF6_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2PZMYttX_sendMessage);
}

void Heavy_PhaseRing::cSend_QGdUkzld_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_JgcBfXCJ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_d6t36hD5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_QGdUkzld_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_kIgi2xU2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Iz6tpKSf, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_ir9q0i3c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_vzL8Ewdk_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_1q3Lxu1c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_WuxlG5wL_sendMessage);
}

void Heavy_PhaseRing::cCast_2PZMYttX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_YgeTeMXQ, 0, m, &cIf_YgeTeMXQ_sendMessage);
}

void Heavy_PhaseRing::cMsg_4z9z4qUU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_kIgi2xU2, 0, m, &cPack_kIgi2xU2_sendMessage);
}

void Heavy_PhaseRing::cCast_76N9iLF6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_cbRKxpD7_sendMessage);
}

void Heavy_PhaseRing::cBinop_WKFmhmNL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_kIgi2xU2, 0, m, &cPack_kIgi2xU2_sendMessage);
}

void Heavy_PhaseRing::cBinop_WuxlG5wL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_eh1caV5Q_sendMessage);
}

void Heavy_PhaseRing::cIf_YgeTeMXQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_4z9z4qUU_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_1q3Lxu1c_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_cbRKxpD7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_YgeTeMXQ, 1, m, &cIf_YgeTeMXQ_sendMessage);
}

void Heavy_PhaseRing::cBinop_eh1caV5Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WKFmhmNL, HV_BINOP_POW, 1, m, &cBinop_WKFmhmNL_sendMessage);
  cMsg_njFuXaBD_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_njFuXaBD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_WKFmhmNL, HV_BINOP_POW, 0, m, &cBinop_WKFmhmNL_sendMessage);
}

void Heavy_PhaseRing::cSend_vzL8Ewdk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_wA9IjUay_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_3olEkk1T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hgJfEikB, HV_BINOP_EQ, 0, m, &cBinop_hgJfEikB_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_m8oWlelR_sendMessage);
}

void Heavy_PhaseRing::cUnop_1Khzfx1h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_HIRaYdDq_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hgJfEikB, HV_BINOP_EQ, 1, m, &cBinop_hgJfEikB_sendMessage);
}

void Heavy_PhaseRing::cBinop_Da4MW6gz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_p3xTiunM, 1, m, &cIf_p3xTiunM_sendMessage);
}

void Heavy_PhaseRing::cUnop_MRebhOmM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_HIRaYdDq_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hgJfEikB, HV_BINOP_EQ, 1, m, &cBinop_hgJfEikB_sendMessage);
}

void Heavy_PhaseRing::cVar_Rz1THrHZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Da4MW6gz_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_p3xTiunM, 0, m, &cIf_p3xTiunM_sendMessage);
}

void Heavy_PhaseRing::cIf_p3xTiunM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_1Khzfx1h_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_MRebhOmM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cCast_87WVm2rc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_odKTKfBP, 1, m, &cIf_odKTKfBP_sendMessage);
}

void Heavy_PhaseRing::cIf_hXqd1G7b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_Z6oMLq13_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_4rF4lMsQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_odKTKfBP, 0, m, &cIf_odKTKfBP_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_hXqd1G7b, 0, m, &cIf_hXqd1G7b_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_EMqz0gdS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_3olEkk1T_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_PnjK9Ny3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_asABAj4b, 0, m, &cIf_asABAj4b_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_2gknZilc, 0, m, &cIf_2gknZilc_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_HIRaYdDq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_87WVm2rc_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hLWTNQsl_sendMessage);
}

void Heavy_PhaseRing::cIf_asABAj4b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_8ND0vZJg_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cCast_MfDGS6MN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_asABAj4b, 1, m, &cIf_asABAj4b_sendMessage);
}

void Heavy_PhaseRing::cIf_odKTKfBP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_Z6oMLq13_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cCast_hLWTNQsl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_2gknZilc, 1, m, &cIf_2gknZilc_sendMessage);
}

void Heavy_PhaseRing::cBinop_hgJfEikB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kuDYbjOo_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MfDGS6MN_sendMessage);
}

void Heavy_PhaseRing::cIf_2gknZilc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_8ND0vZJg_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cCast_kuDYbjOo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_hXqd1G7b, 1, m, &cIf_hXqd1G7b_sendMessage);
}

void Heavy_PhaseRing::cBinop_m8oWlelR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_BaGdM4qH_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_1HRfmt7H_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_LsCDhFTy, 0, m, &cSlice_LsCDhFTy_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_cVKoBcMM, 0, m, &cRandom_cVKoBcMM_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cSlice_LsCDhFTy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_cVKoBcMM, 1, m, &cRandom_cVKoBcMM_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cRandom_cVKoBcMM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_j0JbZtTr_sendMessage);
}

void Heavy_PhaseRing::cUnop_h05x8Ui6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 50.0f, 0, m, &cBinop_IOzXwtxg_sendMessage);
}

void Heavy_PhaseRing::cBinop_j0JbZtTr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_h05x8Ui6_sendMessage);
}

void Heavy_PhaseRing::cReceive_GNUrXJ9X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_djbOKddh_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_p6kZOPxX_sendMessage);
}

void Heavy_PhaseRing::cReceive_GRC2Y3gO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LqSJYykp, m);
}

void Heavy_PhaseRing::cReceive_HPjtQk1P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rufgXjP1, 1, m, &cVar_rufgXjP1_sendMessage);
}

void Heavy_PhaseRing::cReceive_HmrFwopm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_izyMlUoP, 1, m, &cVar_izyMlUoP_sendMessage);
}

void Heavy_PhaseRing::cBinop_IOzXwtxg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_RKTzgvRD_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cReceive_Icit5MbF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_iAkocxD1, 0, m, &cPack_iAkocxD1_sendMessage);
}

void Heavy_PhaseRing::cReceive_JGUkR6QZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7lfxwfbV_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zFNBDphz_sendMessage);
}

void Heavy_PhaseRing::cVar_loB0dJrP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_btcvyUQn_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_2AIJ3Swd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_kly4W6gL, 0, m, &cPack_kly4W6gL_sendMessage);
}

void Heavy_PhaseRing::cBinop_6ZJMZDJW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_J6MEm3ou, HV_BINOP_POW, 1, m, &cBinop_J6MEm3ou_sendMessage);
  cMsg_8XHN97hN_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_8XHN97hN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_J6MEm3ou, HV_BINOP_POW, 0, m, &cBinop_J6MEm3ou_sendMessage);
}

void Heavy_PhaseRing::cBinop_J6MEm3ou_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_kly4W6gL, 0, m, &cPack_kly4W6gL_sendMessage);
}

void Heavy_PhaseRing::cBinop_YKTeX6kT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_6ZJMZDJW_sendMessage);
}

void Heavy_PhaseRing::cIf_cSvRoqKo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_2AIJ3Swd_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_doMSd0Oj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cCast_djbOKddh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_yCjIpHmn_sendMessage);
}

void Heavy_PhaseRing::cBinop_doMSd0Oj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_YKTeX6kT_sendMessage);
}

void Heavy_PhaseRing::cCast_p6kZOPxX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_cSvRoqKo, 0, m, &cIf_cSvRoqKo_sendMessage);
}

void Heavy_PhaseRing::cBinop_yCjIpHmn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_cSvRoqKo, 1, m, &cIf_cSvRoqKo_sendMessage);
}

void Heavy_PhaseRing::cSend_btcvyUQn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_GNUrXJ9X_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_PmTLRsbz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fTIETjRa_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_djbOKddh_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_p6kZOPxX_sendMessage);
}

void Heavy_PhaseRing::cMsg_fTIETjRa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_q8k15fnK_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_kly4W6gL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_u6q5iWUE, 0, m, NULL);
}

void Heavy_PhaseRing::cSend_q8k15fnK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Kt7kKPHH_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cReceive_JQ8XH6mX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_KMq9q8yJ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6PgH2iT3, 0, m, &cVar_6PgH2iT3_sendMessage);
}

void Heavy_PhaseRing::cReceive_JgcBfXCJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ir9q0i3c, 0, m, &cVar_ir9q0i3c_sendMessage);
}

void Heavy_PhaseRing::cPack_0tHQGQug_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_C1rNvW6V_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_2mK0yV9t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_6Yd2b0Yo_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cUnop_0JdY56Zn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 10.0f, 0, m, &cBinop_D4yvKrbp_sendMessage);
}

void Heavy_PhaseRing::cBinop_6qPaJtU7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_0JdY56Zn_sendMessage);
}

void Heavy_PhaseRing::cRandom_HvwSu4XL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 80.0f, 0, m, &cBinop_6qPaJtU7_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_N1ASNuL6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_biJIdm5H, 0, m, &cSlice_biJIdm5H_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_HvwSu4XL, 0, m, &cRandom_HvwSu4XL_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cSlice_biJIdm5H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_HvwSu4XL, 1, m, &cRandom_HvwSu4XL_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_JkevEWcv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_mUI5nSUH_sendMessage);
}

void Heavy_PhaseRing::cSystem_8L5yobrA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_8Te28Pwg_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_R3BZRvfh, m);
}

void Heavy_PhaseRing::cBinop_8Te28Pwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_a3KXb97M, m);
}

void Heavy_PhaseRing::cBinop_GxQaiVyt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_pmTy7lUW, m);
}

void Heavy_PhaseRing::cVar_TvRTzorQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_u8Mls4kI_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_DT5Fn2bd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_GxQaiVyt_sendMessage);
}

void Heavy_PhaseRing::cMsg_Q2Ttx1T7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DT5Fn2bd_sendMessage);
}

void Heavy_PhaseRing::cMsg_u8Mls4kI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8L5yobrA_sendMessage);
}

void Heavy_PhaseRing::cDelay_5Xwi4n0H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5Xwi4n0H, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fB1okubc, 0, m, &cDelay_fB1okubc_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5Xwi4n0H, 0, m, &cDelay_5Xwi4n0H_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_h4VFdmgT, 1, m, NULL);
}

void Heavy_PhaseRing::cCast_EusnHKYo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5Xwi4n0H, 0, m, &cDelay_5Xwi4n0H_sendMessage);
}

void Heavy_PhaseRing::cBinop_H5FzhGY8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_kI7llMSj_sendMessage);
}

void Heavy_PhaseRing::cMsg_LZqhwFC8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_h4VFdmgT, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_QyBT0mzm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_YXrQA3J2, 0, m, &hTable_YXrQA3J2_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_URspPdeT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_LZqhwFC8_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::hTable_YXrQA3J2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nEg3xGhJ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5Xwi4n0H, 2, m, &cDelay_5Xwi4n0H_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EusnHKYo_sendMessage);
}

void Heavy_PhaseRing::cDelay_fB1okubc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fB1okubc, m);
  cMsg_gv4JSvvA_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_gv4JSvvA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_YXrQA3J2, 0, m, &hTable_YXrQA3J2_sendMessage);
}

void Heavy_PhaseRing::cBinop_kI7llMSj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QyBT0mzm_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_1FXVvnZD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BYJFqe9K_sendMessage);
}

void Heavy_PhaseRing::cSystem_BYJFqe9K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_H5FzhGY8_sendMessage);
}

void Heavy_PhaseRing::cMsg_nEg3xGhJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_fB1okubc, 2, m, &cDelay_fB1okubc_sendMessage);
}

void Heavy_PhaseRing::cCast_30eRlicE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7TH5z89n, HV_BINOP_DIVIDE, 0, m, &cBinop_7TH5z89n_sendMessage);
}

void Heavy_PhaseRing::cBinop_7TH5z89n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LMOWpzuc_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_98byR0lf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_xwGG8QW5, 0, m, &cVar_xwGG8QW5_sendMessage);
}

void Heavy_PhaseRing::cMsg_LMOWpzuc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_qs88rzqe, 0, m, NULL);
}

void Heavy_PhaseRing::cUnop_4ZmxhYQW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_WQJF5CDF_sendMessage);
}

void Heavy_PhaseRing::cBinop_D3L9gC6E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_4ZmxhYQW_sendMessage);
}

void Heavy_PhaseRing::cBinop_QuKgyp3j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zKlRJF1V_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_30eRlicE_sendMessage);
}

void Heavy_PhaseRing::cBinop_WQJF5CDF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_dClVABnj_sendMessage);
}

void Heavy_PhaseRing::cBinop_WnlrS3dP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_D3L9gC6E_sendMessage);
}

void Heavy_PhaseRing::cBinop_YwouG0R1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_QuKgyp3j_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_yuwhPqdi, 0, m, &cPack_yuwhPqdi_sendMessage);
}

void Heavy_PhaseRing::cBinop_dClVABnj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7TH5z89n, HV_BINOP_DIVIDE, 0, m, &cBinop_7TH5z89n_sendMessage);
}

void Heavy_PhaseRing::cMsg_iNSrJ8qJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_JkevEWcv, 0, m, &cVar_JkevEWcv_sendMessage);
}

void Heavy_PhaseRing::cBinop_6P5vl3Hr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_luxKZucm, m);
}

void Heavy_PhaseRing::cVar_hJUM360N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_brs7OAau_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_GzHvjv97_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_6P5vl3Hr_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_FmB6mlpz, m);
}

void Heavy_PhaseRing::cMsg_brs7OAau_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GzHvjv97_sendMessage);
}

void Heavy_PhaseRing::cMsg_HoqWlP8S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fKzgxDLi_sendMessage);
}

void Heavy_PhaseRing::cSystem_fKzgxDLi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_tWCQi8Gy_sendMessage);
}

void Heavy_PhaseRing::cBinop_tWCQi8Gy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_hW0ewuZF, m);
}

void Heavy_PhaseRing::cBinop_mUI5nSUH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qlL0gyAz, 0, m, &cPack_qlL0gyAz_sendMessage);
}

void Heavy_PhaseRing::cPack_qlL0gyAz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_mWidUMof, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_xwGG8QW5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_YwouG0R1_sendMessage);
}

void Heavy_PhaseRing::cPack_yuwhPqdi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_VpW71EE8, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_zKlRJF1V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7TH5z89n, HV_BINOP_DIVIDE, 1, m, &cBinop_7TH5z89n_sendMessage);
}

void Heavy_PhaseRing::cBinop_97Vqbe7c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 4.0f, 0, m, &cBinop_S97a2am2_sendMessage);
}

void Heavy_PhaseRing::cBinop_D4yvKrbp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_97Vqbe7c_sendMessage);
}

void Heavy_PhaseRing::cPack_DtPhvPah_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_saQVuVb2_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSwitchcase_6Yd2b0Yo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_QRXbXQQW, 0, m, &cSlice_QRXbXQQW_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_MNudm50C, 0, m, &cRandom_MNudm50C_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cUnop_H3KGxhyd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_DtPhvPah, 0, m, &cPack_DtPhvPah_sendMessage);
}

void Heavy_PhaseRing::cRandom_MNudm50C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_kCS2sOHu_sendMessage);
}

void Heavy_PhaseRing::cSlice_QRXbXQQW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_MNudm50C, 1, m, &cRandom_MNudm50C_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_kCS2sOHu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_H3KGxhyd_sendMessage);
}

void Heavy_PhaseRing::cCast_0BbAMPjE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dxrFx7YW_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSlice_8GoZ6z8r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0BbAMPjE_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3XKqMMnl_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0BbAMPjE_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3XKqMMnl_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_q5CxM0qO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_dxrFx7YW_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_dxrFx7YW_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSwitchcase_saQVuVb2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_q5CxM0qO, 0, m, &cSlice_q5CxM0qO_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_8GoZ6z8r, 0, m, &cSlice_8GoZ6z8r_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fO7cTKzD_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_uZPb4ILg, 0, m, &cSlice_uZPb4ILg_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_4R64yKcd, 0, m, &cSlice_4R64yKcd_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hkzAoPV4_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_v2VMq5Sg_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_3WLu8nqg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lEWVh9jG, 1, m, &cVar_lEWVh9jG_sendMessage);
}

void Heavy_PhaseRing::cCast_3XKqMMnl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HLOUtoN5_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_THSDvJ2Q, HV_BINOP_ADD, 0, m, &cBinop_THSDvJ2Q_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Q2qa3OOn, 1, m, &cVar_Q2qa3OOn_sendMessage);
}

void Heavy_PhaseRing::cCast_5KDfQ9kg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nzGgo9XU, HV_BINOP_DIVIDE, 0, m, &cBinop_nzGgo9XU_sendMessage);
}

void Heavy_PhaseRing::cBinop_7ivKcniV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Fajl8BNj, HV_BINOP_DIVIDE, 0, m, &cBinop_Fajl8BNj_sendMessage);
}

void Heavy_PhaseRing::cVar_Q2qa3OOn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_w6MBCZjV, HV_BINOP_ADD, 0, m, &cBinop_w6MBCZjV_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_THSDvJ2Q, HV_BINOP_ADD, 0, m, &cBinop_THSDvJ2Q_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_HF7FDcRU, 0, m, &cVar_HF7FDcRU_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Bs3iy6Sp, m);
}

void Heavy_PhaseRing::cMsg_9p5bqceG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_8Hv6YLUP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_BRYOudv7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_3WLu8nqg_sendMessage);
}

void Heavy_PhaseRing::cVar_EuKe5ds4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Q2qa3OOn, 0, m, &cVar_Q2qa3OOn_sendMessage);
}

void Heavy_PhaseRing::cMsg_CMNOdsLc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_8Hv6YLUP_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_THSDvJ2Q, HV_BINOP_ADD, 1, m, &cBinop_THSDvJ2Q_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_w6MBCZjV, HV_BINOP_ADD, 1, m, &cBinop_w6MBCZjV_sendMessage);
}

void Heavy_PhaseRing::cBinop_CSoM9oba_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_LmFncvUX_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_CWVyibBw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EuKe5ds4, 1, m, &cVar_EuKe5ds4_sendMessage);
}

void Heavy_PhaseRing::cMsg_Dr9aFKAn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_v150O8Xv, HV_BINOP_MULTIPLY, 0, m, &cBinop_v150O8Xv_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nzGgo9XU, HV_BINOP_DIVIDE, 1, m, &cBinop_nzGgo9XU_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_NbGYCTWS, 0, m, &cVar_NbGYCTWS_sendMessage);
}

void Heavy_PhaseRing::cBinop_Fajl8BNj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_THSDvJ2Q, HV_BINOP_ADD, 1, m, &cBinop_THSDvJ2Q_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_w6MBCZjV, HV_BINOP_ADD, 1, m, &cBinop_w6MBCZjV_sendMessage);
}

void Heavy_PhaseRing::cCast_HDbXQ0jY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BRYOudv7, HV_BINOP_MULTIPLY, 0, m, &cBinop_BRYOudv7_sendMessage);
}

void Heavy_PhaseRing::cCast_HLOUtoN5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CMNOdsLc_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_HptlCMEL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ItDszn1u, HV_BINOP_SUBTRACT, 1, m, &cBinop_ItDszn1u_sendMessage);
}

void Heavy_PhaseRing::cBinop_ItDszn1u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lEWVh9jG, 1, m, &cVar_lEWVh9jG_sendMessage);
}

void Heavy_PhaseRing::cMsg_1eZbcsbi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_CWZ6YOKN, 0, m, &cDelay_CWZ6YOKN_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_8Hv6YLUP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_1eZbcsbi_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_1eZbcsbi_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Rs8j4L2f_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cMsg_3NtscPYZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mdQmsWVH_sendMessage);
}

void Heavy_PhaseRing::cSystem_mdQmsWVH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_jP7uUh2Q_sendMessage);
}

void Heavy_PhaseRing::cDelay_CWZ6YOKN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CWZ6YOKN, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CWZ6YOKN, 0, m, &cDelay_CWZ6YOKN_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lEWVh9jG, 0, m, &cVar_lEWVh9jG_sendMessage);
}

void Heavy_PhaseRing::cCast_Rs8j4L2f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1eZbcsbi_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CWZ6YOKN, 0, m, &cDelay_CWZ6YOKN_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lEWVh9jG, 0, m, &cVar_lEWVh9jG_sendMessage);
}

void Heavy_PhaseRing::cBinop_LzZ3jb9S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_hVcQMAdy_sendMessage);
}

void Heavy_PhaseRing::cBinop_hVcQMAdy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_CWZ6YOKN, 2, m, &cDelay_CWZ6YOKN_sendMessage);
}

void Heavy_PhaseRing::cBinop_jP7uUh2Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LzZ3jb9S, HV_BINOP_MULTIPLY, 1, m, &cBinop_LzZ3jb9S_sendMessage);
}

void Heavy_PhaseRing::cVar_NbGYCTWS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LzZ3jb9S, HV_BINOP_MULTIPLY, 0, m, &cBinop_LzZ3jb9S_sendMessage);
}

void Heavy_PhaseRing::cMsg_NFeWEHoB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_0Olyx67a, 1, m, &cVar_0Olyx67a_sendMessage);
}

void Heavy_PhaseRing::cCast_Gx0geJ5n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Dr9aFKAn_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_xSmLKtsH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Gx0geJ5n_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_v150O8Xv, HV_BINOP_MULTIPLY, 0, m, &cBinop_v150O8Xv_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_nzGgo9XU, HV_BINOP_DIVIDE, 1, m, &cBinop_nzGgo9XU_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_NbGYCTWS, 0, m, &cVar_NbGYCTWS_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_Pv7G27AF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EuKe5ds4, 0, m, &cVar_EuKe5ds4_sendMessage);
}

void Heavy_PhaseRing::cBinop_THSDvJ2Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rWD7gUpk, 0, m, &cVar_rWD7gUpk_sendMessage);
}

void Heavy_PhaseRing::cVar_0Olyx67a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HDbXQ0jY_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5KDfQ9kg_sendMessage);
}

void Heavy_PhaseRing::cVar_YLXidWTk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_xSmLKtsH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_dxrFx7YW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_8Hv6YLUP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_fzazrusm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jFpSjkXl_sendMessage);
}

void Heavy_PhaseRing::cSystem_jFpSjkXl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_v150O8Xv, HV_BINOP_MULTIPLY, 1, m, &cBinop_v150O8Xv_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BRYOudv7, HV_BINOP_MULTIPLY, 1, m, &cBinop_BRYOudv7_sendMessage);
}

void Heavy_PhaseRing::cCast_fO7cTKzD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0Olyx67a, 0, m, &cVar_0Olyx67a_sendMessage);
}

void Heavy_PhaseRing::cCast_hkzAoPV4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9p5bqceG_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_LmFncvUX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ed4dzP1v_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qN78NvuA_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_ed4dzP1v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Q2qa3OOn, 0, m, &cVar_Q2qa3OOn_sendMessage);
}

void Heavy_PhaseRing::cCast_qN78NvuA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_k1SKX6aO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Pv7G27AF_sendMessage);
}

void Heavy_PhaseRing::cCast_iFYwRodT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7ivKcniV, HV_BINOP_SUBTRACT, 0, m, &cBinop_7ivKcniV_sendMessage);
}

void Heavy_PhaseRing::cVar_lEWVh9jG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ItDszn1u, HV_BINOP_SUBTRACT, 0, m, &cBinop_ItDszn1u_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_CSoM9oba_sendMessage);
}

void Heavy_PhaseRing::cCast_k1SKX6aO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CMNOdsLc_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_rWD7gUpk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7ivKcniV, HV_BINOP_SUBTRACT, 1, m, &cBinop_7ivKcniV_sendMessage);
}

void Heavy_PhaseRing::cSlice_4R64yKcd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CWVyibBw_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iFYwRodT_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_uZPb4ILg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HDbXQ0jY_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5KDfQ9kg_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_nzGgo9XU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Fajl8BNj, HV_BINOP_DIVIDE, 1, m, &cBinop_Fajl8BNj_sendMessage);
}

void Heavy_PhaseRing::cBinop_v150O8Xv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_HptlCMEL_sendMessage);
}

void Heavy_PhaseRing::cCast_v2VMq5Sg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NFeWEHoB_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_w6MBCZjV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Q2qa3OOn, 1, m, &cVar_Q2qa3OOn_sendMessage);
}

void Heavy_PhaseRing::cBinop_S97a2am2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_0tHQGQug, 0, m, &cPack_0tHQGQug_sendMessage);
}

void Heavy_PhaseRing::cPack_T02v7nQ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_6Is0wh90, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_HF7FDcRU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cBinop_8FJwXGk8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_psdgXSjI, m);
}

void Heavy_PhaseRing::cBinop_NSHiTy1f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_8FJwXGk8_sendMessage);
}

void Heavy_PhaseRing::cBinop_43GFVIez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_S8KU7ipB, m);
}

void Heavy_PhaseRing::cBinop_52ufnuVw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_XIYPjXY5, m);
}

void Heavy_PhaseRing::cVar_AEqntZmC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_ZQf6FPTW_sendMessage);
}

void Heavy_PhaseRing::cMsg_8kC8iy6a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zilm9Vnv_sendMessage);
}

void Heavy_PhaseRing::cSystem_zilm9Vnv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R6n18KOG, HV_BINOP_DIVIDE, 1, m, &cBinop_R6n18KOG_sendMessage);
}

void Heavy_PhaseRing::cBinop_Py206KR2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_pbzo3fNU_sendMessage);
}

void Heavy_PhaseRing::cBinop_R6n18KOG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zcTavk16_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_ZQf6FPTW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_vTJ3WHEo_sendMessage);
}

void Heavy_PhaseRing::cBinop_pbzo3fNU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_wbvrvopX_sendMessage);
}

void Heavy_PhaseRing::cBinop_wbvrvopX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_xwOoW7j6_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_52ufnuVw_sendMessage);
}

void Heavy_PhaseRing::cBinop_vTJ3WHEo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R6n18KOG, HV_BINOP_DIVIDE, 0, m, &cBinop_R6n18KOG_sendMessage);
}

void Heavy_PhaseRing::cBinop_xwOoW7j6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_43GFVIez_sendMessage);
}

void Heavy_PhaseRing::cMsg_zcTavk16_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_Py206KR2_sendMessage);
}

void Heavy_PhaseRing::cMsg_THE8zvck_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_odOeTYrs_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_5YLeMSNG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_M55PrVFx, 2, m, &cDelay_M55PrVFx_sendMessage);
}

void Heavy_PhaseRing::cMsg_7pzPBn0U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_fKIxix2v, 0, m, &hTable_fKIxix2v_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_BAlxU77B_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_vodRmw7S_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_FwjNE226_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oLyqp723_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_M55PrVFx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_M55PrVFx, m);
  cMsg_7pzPBn0U_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_Ohb4dxFX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ac50Efso, 0, m, &cDelay_ac50Efso_sendMessage);
}

void Heavy_PhaseRing::cDelay_ac50Efso_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ac50Efso, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_M55PrVFx, 0, m, &cDelay_M55PrVFx_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ac50Efso, 0, m, &cDelay_ac50Efso_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_oOJEOqMN, 1, m, NULL);
}

void Heavy_PhaseRing::hTable_fKIxix2v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5YLeMSNG_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ac50Efso, 2, m, &cDelay_ac50Efso_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Ohb4dxFX_sendMessage);
}

void Heavy_PhaseRing::cBinop_nVbthqFU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_FwjNE226_sendMessage);
}

void Heavy_PhaseRing::cMsg_fGcfnWY5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lXhWtNJo_sendMessage);
}

void Heavy_PhaseRing::cSystem_lXhWtNJo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_nVbthqFU_sendMessage);
}

void Heavy_PhaseRing::cMsg_oLyqp723_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_fKIxix2v, 0, m, &hTable_fKIxix2v_sendMessage);
}

void Heavy_PhaseRing::cMsg_vodRmw7S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_oOJEOqMN, 1, m, NULL);
}

void Heavy_PhaseRing::cVar_Zh5CpgkH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_O473cBaw, HV_BINOP_MULTIPLY, 0, m, &cBinop_O473cBaw_sendMessage);
}

void Heavy_PhaseRing::cBinop_ZXlbpmAy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_M5amLB0o, m);
}

void Heavy_PhaseRing::cBinop_6l8gQ9R0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ZXlbpmAy_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_0g88X1M5, m);
}

void Heavy_PhaseRing::cBinop_9EIoWekT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_6l8gQ9R0_sendMessage);
}

void Heavy_PhaseRing::cSystem_3kUO64yL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aCwBEsL7_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_zYWdeEVl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3kUO64yL_sendMessage);
}

void Heavy_PhaseRing::cBinop_O473cBaw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_9EIoWekT_sendMessage);
}

void Heavy_PhaseRing::cMsg_aCwBEsL7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_j2IO1XVu_sendMessage);
}

void Heavy_PhaseRing::cBinop_j2IO1XVu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_O473cBaw, HV_BINOP_MULTIPLY, 1, m, &cBinop_O473cBaw_sendMessage);
}

void Heavy_PhaseRing::cMsg_odOeTYrs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_jaBpt9ud, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_BrocUyyB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_odOeTYrs_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_HzRlmEtO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_PltB3Fk5, m);
}

void Heavy_PhaseRing::cMsg_PWEokKLX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mVJUUq26_sendMessage);
}

void Heavy_PhaseRing::cBinop_Skzrj1bk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_QzYNScNw, m);
}

void Heavy_PhaseRing::cSystem_1WfFYHQW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Skzrj1bk_sendMessage);
}

void Heavy_PhaseRing::cMsg_RS1dD6wF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1WfFYHQW_sendMessage);
}

void Heavy_PhaseRing::cSystem_mVJUUq26_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_HzRlmEtO_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_bjA8VCxW, m);
}

void Heavy_PhaseRing::cVar_KlMuSvkx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PWEokKLX_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_oPTmTd9l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_N1ASNuL6_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_0KdTGCJk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ipSKlgrs, HV_BINOP_DIVIDE, 0, m, &cBinop_ipSKlgrs_sendMessage);
}

void Heavy_PhaseRing::cBinop_0zGg7UFs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KSnh2VrC, 1, m, &cVar_KSnh2VrC_sendMessage);
}

void Heavy_PhaseRing::cCast_3wtBBh7s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sY9h96TW, 0, m, &cVar_sY9h96TW_sendMessage);
}

void Heavy_PhaseRing::cSlice_SqvdjTIO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_VvVZpyji_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ivbpaBxS_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_x1HTqWzf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_uD3XkntM_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_blJZpUyG_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cCast_AO1ilv7M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xxk6bUbD_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_7LJ9Qbjc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CWRhSFBx_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_RkG20JaX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7LJ9Qbjc_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_AsD9WQLh, HV_BINOP_MULTIPLY, 0, m, &cBinop_AsD9WQLh_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_WV8A1mpm, HV_BINOP_DIVIDE, 1, m, &cBinop_WV8A1mpm_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_uFOa9EQn, 0, m, &cVar_uFOa9EQn_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_AsD9WQLh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_pK6ib2I5_sendMessage);
}

void Heavy_PhaseRing::cMsg_CWRhSFBx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_AsD9WQLh, HV_BINOP_MULTIPLY, 0, m, &cBinop_AsD9WQLh_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_WV8A1mpm, HV_BINOP_DIVIDE, 1, m, &cBinop_WV8A1mpm_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_uFOa9EQn, 0, m, &cVar_uFOa9EQn_sendMessage);
}

void Heavy_PhaseRing::cCast_CzleO8Qy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_R3byJKy5_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_rgtzVtD7, HV_BINOP_ADD, 0, m, &cBinop_rgtzVtD7_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_BP56wJJS, 1, m, &cVar_BP56wJJS_sendMessage);
}

void Heavy_PhaseRing::cVar_sY9h96TW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BP56wJJS, 0, m, &cVar_BP56wJJS_sendMessage);
}

void Heavy_PhaseRing::cMsg_I2ENwsyn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_C3yoNpW7_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_KmtnFRlu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BP56wJJS, 1, m, &cVar_BP56wJJS_sendMessage);
}

void Heavy_PhaseRing::cMsg_11dQgk1u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_5VVWbTi9, 0, m, &cDelay_5VVWbTi9_sendMessage);
}

void Heavy_PhaseRing::cDelay_5VVWbTi9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5VVWbTi9, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5VVWbTi9, 0, m, &cDelay_5VVWbTi9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_KSnh2VrC, 0, m, &cVar_KSnh2VrC_sendMessage);
}

void Heavy_PhaseRing::cCast_XtWNrH0m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_11dQgk1u_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5VVWbTi9, 0, m, &cDelay_5VVWbTi9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_KSnh2VrC, 0, m, &cVar_KSnh2VrC_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_C3yoNpW7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_11dQgk1u_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_11dQgk1u_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XtWNrH0m_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_G4Qrd1VH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZEQhUT0Z, HV_BINOP_MULTIPLY, 1, m, &cBinop_ZEQhUT0Z_sendMessage);
}

void Heavy_PhaseRing::cSystem_6papvOzO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_G4Qrd1VH_sendMessage);
}

void Heavy_PhaseRing::cMsg_BXf3gGB2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6papvOzO_sendMessage);
}

void Heavy_PhaseRing::cVar_uFOa9EQn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZEQhUT0Z, HV_BINOP_MULTIPLY, 0, m, &cBinop_ZEQhUT0Z_sendMessage);
}

void Heavy_PhaseRing::cBinop_ZEQhUT0Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_hqgUmkVo_sendMessage);
}

void Heavy_PhaseRing::cBinop_hqgUmkVo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5VVWbTi9, 2, m, &cDelay_5VVWbTi9_sendMessage);
}

void Heavy_PhaseRing::cCast_QoyC2qAv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3jPkLwWE, 0, m, &cVar_3jPkLwWE_sendMessage);
}

void Heavy_PhaseRing::cBinop_Qtn5eL32_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_0zGg7UFs_sendMessage);
}

void Heavy_PhaseRing::cCast_R3byJKy5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XzZevGjy_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_BrSFxlbJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BP56wJJS, 0, m, &cVar_BP56wJJS_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_EZ6Je6BJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BrSFxlbJ_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sfndDoMa_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_sfndDoMa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_me34wpxy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3wtBBh7s_sendMessage);
}

void Heavy_PhaseRing::cBinop_RQIF9pvT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KSnh2VrC, 1, m, &cVar_KSnh2VrC_sendMessage);
}

void Heavy_PhaseRing::cVar_3jPkLwWE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_uD3XkntM_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_blJZpUyG_sendMessage);
}

void Heavy_PhaseRing::cMsg_UkHLErmq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_C3yoNpW7_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_VvVZpyji_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sY9h96TW, 1, m, &cVar_sY9h96TW_sendMessage);
}

void Heavy_PhaseRing::cBinop_WV8A1mpm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ipSKlgrs, HV_BINOP_DIVIDE, 1, m, &cBinop_ipSKlgrs_sendMessage);
}

void Heavy_PhaseRing::cVar_BP56wJJS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KmtnFRlu, HV_BINOP_ADD, 0, m, &cBinop_KmtnFRlu_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_rgtzVtD7, HV_BINOP_ADD, 0, m, &cBinop_rgtzVtD7_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_2n48kWdV, 0, m, &cVar_2n48kWdV_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_WnlrS3dP_sendMessage);
}

void Heavy_PhaseRing::cMsg_MmFxET5O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dMm2NBcY_sendMessage);
}

void Heavy_PhaseRing::cSystem_dMm2NBcY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AsD9WQLh, HV_BINOP_MULTIPLY, 1, m, &cBinop_AsD9WQLh_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Qtn5eL32, HV_BINOP_MULTIPLY, 1, m, &cBinop_Qtn5eL32_sendMessage);
}

void Heavy_PhaseRing::cMsg_XzZevGjy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_C3yoNpW7_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_rgtzVtD7, HV_BINOP_ADD, 1, m, &cBinop_rgtzVtD7_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KmtnFRlu, HV_BINOP_ADD, 1, m, &cBinop_KmtnFRlu_sendMessage);
}

void Heavy_PhaseRing::cCast_bcR7beex_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UkHLErmq_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_blJZpUyG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WV8A1mpm, HV_BINOP_DIVIDE, 0, m, &cBinop_WV8A1mpm_sendMessage);
}

void Heavy_PhaseRing::cCast_dWO77fxm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_I2ENwsyn_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_iKxiqkmm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_EZ6Je6BJ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_ipSKlgrs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rgtzVtD7, HV_BINOP_ADD, 1, m, &cBinop_rgtzVtD7_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KmtnFRlu, HV_BINOP_ADD, 1, m, &cBinop_KmtnFRlu_sendMessage);
}

void Heavy_PhaseRing::cCast_ivbpaBxS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0KdTGCJk, HV_BINOP_SUBTRACT, 0, m, &cBinop_0KdTGCJk_sendMessage);
}

void Heavy_PhaseRing::cCast_me34wpxy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XzZevGjy_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_KSnh2VrC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RQIF9pvT, HV_BINOP_SUBTRACT, 0, m, &cBinop_RQIF9pvT_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_iKxiqkmm_sendMessage);
}

void Heavy_PhaseRing::cSlice_4sIYZMJp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_UkHLErmq_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_UkHLErmq_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSwitchcase_C1rNvW6V_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_4sIYZMJp, 0, m, &cSlice_4sIYZMJp_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Y8Q2VQj4, 0, m, &cSlice_Y8Q2VQj4_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QoyC2qAv_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_x1HTqWzf, 0, m, &cSlice_x1HTqWzf_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_SqvdjTIO, 0, m, &cSlice_SqvdjTIO_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dWO77fxm_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AO1ilv7M_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cSlice_Y8Q2VQj4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bcR7beex_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CzleO8Qy_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bcR7beex_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CzleO8Qy_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_pK6ib2I5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RQIF9pvT, HV_BINOP_SUBTRACT, 1, m, &cBinop_RQIF9pvT_sendMessage);
}

void Heavy_PhaseRing::cVar_Ew8y3Pqu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0KdTGCJk, HV_BINOP_SUBTRACT, 1, m, &cBinop_0KdTGCJk_sendMessage);
}

void Heavy_PhaseRing::cBinop_rgtzVtD7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ew8y3Pqu, 0, m, &cVar_Ew8y3Pqu_sendMessage);
}

void Heavy_PhaseRing::cVar_Q5I7LvD0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_RkG20JaX_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_uD3XkntM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Qtn5eL32, HV_BINOP_MULTIPLY, 0, m, &cBinop_Qtn5eL32_sendMessage);
}

void Heavy_PhaseRing::cMsg_xxk6bUbD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_3jPkLwWE, 1, m, &cVar_3jPkLwWE_sendMessage);
}

void Heavy_PhaseRing::cVar_2n48kWdV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cMsg_wlTj1r3f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.15f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_NSHiTy1f_sendMessage);
}

void Heavy_PhaseRing::cReceive_Kt7kKPHH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_loB0dJrP, 0, m, &cVar_loB0dJrP_sendMessage);
}

void Heavy_PhaseRing::cReceive_LPyHGKIm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ZmzdwXRG, m);
}

void Heavy_PhaseRing::cReceive_MRJzFSvg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_6tKya33I, m);
}

void Heavy_PhaseRing::cReceive_MSUiSskw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CuLuBKX3, 1, m, &cVar_CuLuBKX3_sendMessage);
}

void Heavy_PhaseRing::cReceive_MxuQiGAF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_fEqdfucC_sendMessage);
}

void Heavy_PhaseRing::cReceive_NG3d9ZnJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PIqMfTiA, 0, m, &cVar_PIqMfTiA_sendMessage);
}

void Heavy_PhaseRing::cReceive_NmBa5KkM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cReceive_NreiNAi5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_EMqz0gdS, 0, m, &cSlice_EMqz0gdS_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_4rF4lMsQ, 0, m, &cSlice_4rF4lMsQ_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_PnjK9Ny3, 0, m, &cSlice_PnjK9Ny3_sendMessage);
}

void Heavy_PhaseRing::cReceive_Ooqb3idw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_EXJdIf0H, 0, m, &cPack_EXJdIf0H_sendMessage);
}

void Heavy_PhaseRing::cCast_1Ugwu5vN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_lOP5QLLs_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_5t3rWCRI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lCXujieJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_lCXujieJ_sendMessage);
}

void Heavy_PhaseRing::cSend_64NbZ138_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Icit5MbF_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_6NZX3shK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_BwOqV6Ga_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_BwOqV6Ga_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_TtciRdhR_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_HTw9g5Nh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_5t3rWCRI_sendMessage);
}

void Heavy_PhaseRing::cUnop_OZiGaZB6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_UFB23eiR_sendMessage);
}

void Heavy_PhaseRing::cRandom_c2TTrsN9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_dl5y28m4_sendMessage);
}

void Heavy_PhaseRing::cBinop_dl5y28m4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_OZiGaZB6_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_lOP5QLLs_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_mJ4uoAG3, 0, m, &cSlice_mJ4uoAG3_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_c2TTrsN9, 0, m, &cRandom_c2TTrsN9_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cSlice_mJ4uoAG3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_c2TTrsN9, 1, m, &cRandom_c2TTrsN9_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_Zn1ojjrH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_R9h1RyvC, 0, m);
}

void Heavy_PhaseRing::cCast_nH2sYmaW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cBinop_P5BLAPKi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_lEyFGHS6_sendMessage(_c, 0, m);
  cSend_64NbZ138_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_QBYOjv4g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TDBDnu5u_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nH2sYmaW_sendMessage);
}

void Heavy_PhaseRing::cCast_5iwIBwI4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_hJjEjaMc_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_6r36AWRU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TAwmTnvB, 1, m, &cVar_TAwmTnvB_sendMessage);
}

void Heavy_PhaseRing::cSend_95rZnfuk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_HPjtQk1P_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_ActXizl2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_rufgXjP1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nywujxCe_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6r36AWRU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5iwIBwI4_sendMessage);
}

void Heavy_PhaseRing::cVar_jQdVp78g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cCast_TCIjPG2y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_TAwmTnvB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_w9M2pK8I_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_RWYZ9dKs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_HPjtQk1P_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_TDBDnu5u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rufgXjP1, 0, m, &cVar_rufgXjP1_sendMessage);
}

void Heavy_PhaseRing::cMsg_VFVTKNfL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_eHhhUdhj, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_kFL9HD4I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_a312r783_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_LPyHGKIm_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_eaDVrtdO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cDelay_Z7or4RMJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Z7or4RMJ, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TAwmTnvB, 0, m, &cVar_TAwmTnvB_sendMessage);
}

void Heavy_PhaseRing::cMsg_bzAhWiWm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Z7or4RMJ, 0, m, &cDelay_Z7or4RMJ_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_hJjEjaMc_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_bzAhWiWm_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_bzAhWiWm_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_Z7or4RMJ, 1, m, &cDelay_Z7or4RMJ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rEhLkjFh_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_rEhLkjFh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Z7or4RMJ, 0, m, &cDelay_Z7or4RMJ_sendMessage);
}

void Heavy_PhaseRing::cVar_qohOHo7T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cMsg_kxfHNcBa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_RWYZ9dKs_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_nMt4JOpM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_LPyHGKIm_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_nywujxCe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VFVTKNfL_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_o41EzHYb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_a312r783_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_pjAnMW0Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_eaDVrtdO_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_w9M2pK8I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_eHhhUdhj, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_le0crv9b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_eucO49s8, 0, m);
}

void Heavy_PhaseRing::cBinop_UFB23eiR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_yeWF24VB_sendMessage);
}

void Heavy_PhaseRing::cPack_iAkocxD1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_9LoRcshy, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_xZvotm3O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_jQYBJ8IF_sendMessage);
}

void Heavy_PhaseRing::cBinop_jQYBJ8IF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_iAkocxD1, 0, m, &cPack_iAkocxD1_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_1KKNourW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_1i3HKFFn, 0, m, &cSlice_1i3HKFFn_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_agFF2Fzj, 0, m, &cRandom_agFF2Fzj_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cSlice_1i3HKFFn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_agFF2Fzj, 1, m, &cRandom_agFF2Fzj_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_9MbrMac6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_vPiwdbUY_sendMessage);
}

void Heavy_PhaseRing::cRandom_agFF2Fzj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_9MbrMac6_sendMessage);
}

void Heavy_PhaseRing::cUnop_vPiwdbUY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_HTw9g5Nh_sendMessage);
}

void Heavy_PhaseRing::cBinop_lCXujieJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QBYOjv4g_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1Ugwu5vN_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_le0crv9b, 0, m, &cVar_le0crv9b_sendMessage);
}

void Heavy_PhaseRing::cSend_lEyFGHS6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ZlTLysvX_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSlice_FYFzJj9d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oHYbKeSH_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_tGXsCiA9_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_ktV5WUFT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_P5BLAPKi_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cCast_oHYbKeSH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_1KKNourW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cUnop_yzvDUgQe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_P3wS8A0I, 0, m, &cPack_P3wS8A0I_sendMessage);
}

void Heavy_PhaseRing::cUnop_rf2ILT2s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_SvkpEzkg, 0, m, &cPack_SvkpEzkg_sendMessage);
}

void Heavy_PhaseRing::cMsg_BSaQylVh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_nw7IthN6_sendMessage);
}

void Heavy_PhaseRing::cPack_P3wS8A0I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_PEXfcDRT, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_SvkpEzkg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_b7IljXY7, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_nw7IthN6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_rf2ILT2s_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_yzvDUgQe_sendMessage);
}

void Heavy_PhaseRing::cBinop_BVhRq1tD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_igOAoUWy_sendMessage);
}

void Heavy_PhaseRing::cMsg_Zt7VoDZY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BVhRq1tD, HV_BINOP_POW, 0, m, &cBinop_BVhRq1tD_sendMessage);
}

void Heavy_PhaseRing::cBinop_i4vZjgEd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BVhRq1tD, HV_BINOP_POW, 1, m, &cBinop_BVhRq1tD_sendMessage);
  cMsg_Zt7VoDZY_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_igOAoUWy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lCXujieJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_lCXujieJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_tGXsCiA9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_i4vZjgEd_sendMessage);
}

void Heavy_PhaseRing::cBinop_yeWF24VB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_nw7IthN6_sendMessage);
}

void Heavy_PhaseRing::cReceive_QPrQCP5y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8z9Pseml, 0, m, &cVar_8z9Pseml_sendMessage);
}

void Heavy_PhaseRing::cReceive_RDsrnpUR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_cpzsusVR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6C985mw3, 0, m, &cVar_6C985mw3_sendMessage);
}

void Heavy_PhaseRing::cSend_RKTzgvRD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_m6Ye80po_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cReceive_TRY8bBhd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Q08XYhLX, 0, m, &cPack_Q08XYhLX_sendMessage);
}

void Heavy_PhaseRing::cReceive_TtciRdhR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_95rZnfuk_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qohOHo7T, 0, m, &cVar_qohOHo7T_sendMessage);
}

void Heavy_PhaseRing::cReceive_UXC71nrx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_JsRzMHWd, m);
}

void Heavy_PhaseRing::cReceive_UlHtggTQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_y01lKo1A_sendMessage);
}

void Heavy_PhaseRing::cReceive_XvEdNmLJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_prgk3mYa_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_DVPkcmop, 0, m, &cVar_DVPkcmop_sendMessage);
}

void Heavy_PhaseRing::cReceive_YXqGEjIK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_volt9ZhQ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_j8wxsOsu, 0, m, &cIf_j8wxsOsu_sendMessage);
}

void Heavy_PhaseRing::cBinop_8z62mpxw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_EiNO2F5N, 1, m, &cIf_EiNO2F5N_sendMessage);
}

void Heavy_PhaseRing::cBinop_A2HeDVbs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_DcwzACOW_sendMessage);
}

void Heavy_PhaseRing::cBinop_DGYEBDpK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_A2HeDVbs_sendMessage);
}

void Heavy_PhaseRing::cBinop_DcwzACOW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fTIETjRa_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_djbOKddh_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_p6kZOPxX_sendMessage);
}

void Heavy_PhaseRing::cMsg_DirdSHXo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_fTIETjRa_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_djbOKddh_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_p6kZOPxX_sendMessage);
}

void Heavy_PhaseRing::cIf_EiNO2F5N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_DirdSHXo_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_bQLuYHZc_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cCast_ZhjAi2ej_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_EiNO2F5N, 0, m, &cIf_EiNO2F5N_sendMessage);
}

void Heavy_PhaseRing::cUnop_bQLuYHZc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_DGYEBDpK_sendMessage);
}

void Heavy_PhaseRing::cCast_t8WTNE9t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_8z62mpxw_sendMessage);
}

void Heavy_PhaseRing::cBinop_UWvx9csx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_t8WTNE9t_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZhjAi2ej_sendMessage);
}

void Heavy_PhaseRing::cBinop_k8AwyJ1I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_UWvx9csx_sendMessage);
}

void Heavy_PhaseRing::cReceive_YzDUtlvP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_zVAs2wHQ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_A4BGqHjh, 0, m, &cVar_A4BGqHjh_sendMessage);
}

void Heavy_PhaseRing::cSend_Z6oMLq13_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_yRjwNjQN_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_Y3fYBJlC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9tVFSV5F_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YttXSjgB_sendMessage);
}

void Heavy_PhaseRing::cCast_9tVFSV5F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_nf29zP9d_sendMessage);
}

void Heavy_PhaseRing::cBinop_QfYRZAAt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KynI9x7n, 0, m, &cVar_KynI9x7n_sendMessage);
}

void Heavy_PhaseRing::cMsg_Tcwnk59D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_KynI9x7n, 0, m, &cVar_KynI9x7n_sendMessage);
}

void Heavy_PhaseRing::cCast_YttXSjgB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_hBhJPRe4, 0, m, &cIf_hBhJPRe4_sendMessage);
}

void Heavy_PhaseRing::cUnop_ZtZRO6kY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_vPtQRRQh_sendMessage);
}

void Heavy_PhaseRing::cIf_hBhJPRe4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Tcwnk59D_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_ZtZRO6kY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_nf29zP9d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_hBhJPRe4, 1, m, &cIf_hBhJPRe4_sendMessage);
}

void Heavy_PhaseRing::cBinop_siRS5Xy6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_QfYRZAAt_sendMessage);
}

void Heavy_PhaseRing::cBinop_vPtQRRQh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_siRS5Xy6_sendMessage);
}

void Heavy_PhaseRing::cBinop_y01lKo1A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Y3fYBJlC_sendMessage);
}

void Heavy_PhaseRing::cMsg_1G8QLz2k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_u6GT8Qwv, 0, m, &cVar_u6GT8Qwv_sendMessage);
}

void Heavy_PhaseRing::cVar_u6GT8Qwv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_79eXwPNq, 0, m, &cVar_79eXwPNq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_3ebC2MQw, 0, m, &cVar_3ebC2MQw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_HHodeCyW, 0, m, &cVar_HHodeCyW_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wslmKKEl, 0, m, &cVar_wslmKKEl_sendMessage);
}

void Heavy_PhaseRing::cBinop_BIXZnmg1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_pVu6zRuu, 1, m, &cIf_pVu6zRuu_sendMessage);
}

void Heavy_PhaseRing::cIf_pVu6zRuu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_1G8QLz2k_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_u6GT8Qwv, 0, m, &cVar_u6GT8Qwv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cPack_5IuQexcn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_ctBqfGM8, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_6U0Ln26P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_NlwDZDpw, 0, m, &hTable_NlwDZDpw_sendMessage);
}

void Heavy_PhaseRing::cBinop_9GeG4B5s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fs4bw3Zt_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_G4OVySBy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_MlACp4XR, 0, m, &cDelay_MlACp4XR_sendMessage);
}

void Heavy_PhaseRing::cMsg_Icb350iF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_mzXO9VTJ, 2, m, &cDelay_mzXO9VTJ_sendMessage);
}

void Heavy_PhaseRing::cDelay_MlACp4XR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_MlACp4XR, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mzXO9VTJ, 0, m, &cDelay_mzXO9VTJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_MlACp4XR, 0, m, &cDelay_MlACp4XR_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_d43dxlgp, 1, m, NULL);
}

void Heavy_PhaseRing::hTable_NlwDZDpw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Icb350iF_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_MlACp4XR, 2, m, &cDelay_MlACp4XR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_G4OVySBy_sendMessage);
}

void Heavy_PhaseRing::cBinop_WyNCbrcC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_9GeG4B5s_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_X2CTU4lF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_kY6CiwgA_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cMsg_fs4bw3Zt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_NlwDZDpw, 0, m, &hTable_NlwDZDpw_sendMessage);
}

void Heavy_PhaseRing::cMsg_kY6CiwgA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_d43dxlgp, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_mzXO9VTJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mzXO9VTJ, m);
  cMsg_6U0Ln26P_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_bIRRz79x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qcBgEtaq_sendMessage);
}

void Heavy_PhaseRing::cSystem_qcBgEtaq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_WyNCbrcC_sendMessage);
}

void Heavy_PhaseRing::cVar_KynI9x7n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Y32RxzaP_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ubdBPvp7_sendMessage);
}

void Heavy_PhaseRing::cPack_EJeLmYVW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_8GD4kDMx, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_1115YzV3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TqEc0I18, 0, m, &cDelay_TqEc0I18_sendMessage);
}

void Heavy_PhaseRing::cMsg_67wbfJ2g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_TqEc0I18, 0, m, &cDelay_TqEc0I18_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PuPI2lIz, 0, m, &cDelay_PuPI2lIz_sendMessage);
}

void Heavy_PhaseRing::cBinop_DEuc7UtW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_poDeI2Li, HV_BINOP_SUBTRACT, 1, m, &cBinop_poDeI2Li_sendMessage);
}

void Heavy_PhaseRing::cBinop_DuquqJOg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TqEc0I18, 2, m, &cDelay_TqEc0I18_sendMessage);
}

void Heavy_PhaseRing::cCast_HVo32Nnw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gYbFrBc4, 0, m, &cVar_gYbFrBc4_sendMessage);
  cMsg_LXp2Vd2j_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_kLk2DX0g, 0, m, &cTabhead_kLk2DX0g_sendMessage);
}

void Heavy_PhaseRing::cMsg_K1iTqUaI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eKFpH9a2_sendMessage);
}

void Heavy_PhaseRing::cMsg_LxBrcFvv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_DEuc7UtW, HV_BINOP_MAX, 1, m, &cBinop_DEuc7UtW_sendMessage);
}

void Heavy_PhaseRing::cMsg_LXp2Vd2j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NjAhlDw2_sendMessage);
}

void Heavy_PhaseRing::cSystem_NjAhlDw2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_nwVQZ7Iz_sendMessage);
}

void Heavy_PhaseRing::cDelay_PuPI2lIz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_PuPI2lIz, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_X44L1rbi, 0, m, &sTabread_X44L1rbi_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PuPI2lIz, 0, m, &cDelay_PuPI2lIz_sendMessage);
}

void Heavy_PhaseRing::cBinop_SZlyNABT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_DuquqJOg_sendMessage);
}

void Heavy_PhaseRing::cDelay_TqEc0I18_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TqEc0I18, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PuPI2lIz, 0, m, &cDelay_PuPI2lIz_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_X44L1rbi, 0, m, &sTabread_X44L1rbi_sendMessage);
}

void Heavy_PhaseRing::sTabread_X44L1rbi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_SZlyNABT, HV_BINOP_SUBTRACT, 0, m, &cBinop_SZlyNABT_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSystem_eKFpH9a2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SZlyNABT, HV_BINOP_SUBTRACT, 1, m, &cBinop_SZlyNABT_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PuPI2lIz, 2, m, &cDelay_PuPI2lIz_sendMessage);
}

void Heavy_PhaseRing::cVar_gYbFrBc4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_K1iTqUaI_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cTabhead_kLk2DX0g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_poDeI2Li, HV_BINOP_SUBTRACT, 0, m, &cBinop_poDeI2Li_sendMessage);
}

void Heavy_PhaseRing::cBinop_nwVQZ7Iz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qyTvtMHX, HV_BINOP_MULTIPLY, 0, m, &cBinop_qyTvtMHX_sendMessage);
}

void Heavy_PhaseRing::cBinop_poDeI2Li_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_67wbfJ2g_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_X44L1rbi, 0, m, &sTabread_X44L1rbi_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1115YzV3_sendMessage);
}

void Heavy_PhaseRing::cBinop_qyTvtMHX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DEuc7UtW, HV_BINOP_MAX, 0, m, &cBinop_DEuc7UtW_sendMessage);
}

void Heavy_PhaseRing::cBinop_MgYlK9We_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_5IuQexcn, 0, m, &cPack_5IuQexcn_sendMessage);
}

void Heavy_PhaseRing::cBinop_7RNeH53b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_WWTSImWG_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_e1PsRhKq, m);
}

void Heavy_PhaseRing::cBinop_zaKDLKho_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_7RNeH53b_sendMessage);
}

void Heavy_PhaseRing::cVar_79eXwPNq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eYfmPTZr, HV_BINOP_MULTIPLY, 0, m, &cBinop_eYfmPTZr_sendMessage);
}

void Heavy_PhaseRing::cMsg_64xRwxyY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_7mt73e01_sendMessage);
}

void Heavy_PhaseRing::cBinop_7mt73e01_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eYfmPTZr, HV_BINOP_MULTIPLY, 1, m, &cBinop_eYfmPTZr_sendMessage);
}

void Heavy_PhaseRing::cBinop_eYfmPTZr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_zaKDLKho_sendMessage);
}

void Heavy_PhaseRing::cSystem_0N43JE7z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_64xRwxyY_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_8EDJoabJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0N43JE7z_sendMessage);
}

void Heavy_PhaseRing::cBinop_WWTSImWG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_C6AFUrsM, m);
}

void Heavy_PhaseRing::cBinop_ATW5secV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_SG2bcSnR_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Al05hapz, m);
}

void Heavy_PhaseRing::cBinop_wtzCY1uX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ATW5secV_sendMessage);
}

void Heavy_PhaseRing::cBinop_SG2bcSnR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_TI4E0lh3, m);
}

void Heavy_PhaseRing::cMsg_4mlQGE2G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_7Z4Qgs9V_sendMessage);
}

void Heavy_PhaseRing::cBinop_7Z4Qgs9V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zLVv9BmV, HV_BINOP_MULTIPLY, 1, m, &cBinop_zLVv9BmV_sendMessage);
}

void Heavy_PhaseRing::cMsg_Ccent5HC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YsGQXf8I_sendMessage);
}

void Heavy_PhaseRing::cSystem_YsGQXf8I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4mlQGE2G_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_zLVv9BmV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_wtzCY1uX_sendMessage);
}

void Heavy_PhaseRing::cVar_wslmKKEl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zLVv9BmV, HV_BINOP_MULTIPLY, 0, m, &cBinop_zLVv9BmV_sendMessage);
}

void Heavy_PhaseRing::cVar_AuTsPu8K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_iVcBj2d4_sendMessage);
}

void Heavy_PhaseRing::cBinop_SDREH4oa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_EJeLmYVW, 0, m, &cPack_EJeLmYVW_sendMessage);
}

void Heavy_PhaseRing::cVar_0FiP8cTk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hfbH4B17_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_1ufanUhg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_J1nxD7Bo, 0, m, &cDelay_J1nxD7Bo_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ynEaXzHI, 0, m, &cDelay_ynEaXzHI_sendMessage);
}

void Heavy_PhaseRing::cBinop_82fhNWaF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_f253eZ1l, HV_BINOP_MAX, 0, m, &cBinop_f253eZ1l_sendMessage);
}

void Heavy_PhaseRing::cSystem_ATi9TEdf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aAcUWa8w, HV_BINOP_SUBTRACT, 1, m, &cBinop_aAcUWa8w_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ynEaXzHI, 2, m, &cDelay_ynEaXzHI_sendMessage);
}

void Heavy_PhaseRing::cMsg_BHxpRmB8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_f253eZ1l, HV_BINOP_MAX, 1, m, &cBinop_f253eZ1l_sendMessage);
}

void Heavy_PhaseRing::cBinop_C44j8RJg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_J1nxD7Bo, 2, m, &cDelay_J1nxD7Bo_sendMessage);
}

void Heavy_PhaseRing::cTabhead_DLiYW0yc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NqTOrbfD, HV_BINOP_SUBTRACT, 0, m, &cBinop_NqTOrbfD_sendMessage);
}

void Heavy_PhaseRing::sTabread_IVZ00RuP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_aAcUWa8w, HV_BINOP_SUBTRACT, 0, m, &cBinop_aAcUWa8w_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cDelay_J1nxD7Bo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_J1nxD7Bo, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ynEaXzHI, 0, m, &cDelay_ynEaXzHI_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_IVZ00RuP, 0, m, &sTabread_IVZ00RuP_sendMessage);
}

void Heavy_PhaseRing::cSystem_Y94JPdTL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_u5imjPEP_sendMessage);
}

void Heavy_PhaseRing::cMsg_b2BDuKG9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Y94JPdTL_sendMessage);
}

void Heavy_PhaseRing::cCast_MUthzqlo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_J1nxD7Bo, 0, m, &cDelay_J1nxD7Bo_sendMessage);
}

void Heavy_PhaseRing::cBinop_NqTOrbfD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1ufanUhg_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_IVZ00RuP, 0, m, &sTabread_IVZ00RuP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MUthzqlo_sendMessage);
}

void Heavy_PhaseRing::cCast_OZKxp9pw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0FiP8cTk, 0, m, &cVar_0FiP8cTk_sendMessage);
  cMsg_b2BDuKG9_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_DLiYW0yc, 0, m, &cTabhead_DLiYW0yc_sendMessage);
}

void Heavy_PhaseRing::cBinop_aAcUWa8w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_C44j8RJg_sendMessage);
}

void Heavy_PhaseRing::cBinop_f253eZ1l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NqTOrbfD, HV_BINOP_SUBTRACT, 1, m, &cBinop_NqTOrbfD_sendMessage);
}

void Heavy_PhaseRing::cMsg_hfbH4B17_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ATi9TEdf_sendMessage);
}

void Heavy_PhaseRing::cBinop_u5imjPEP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_82fhNWaF, HV_BINOP_MULTIPLY, 0, m, &cBinop_82fhNWaF_sendMessage);
}

void Heavy_PhaseRing::cDelay_ynEaXzHI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ynEaXzHI, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_IVZ00RuP, 0, m, &sTabread_IVZ00RuP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ynEaXzHI, 0, m, &cDelay_ynEaXzHI_sendMessage);
}

void Heavy_PhaseRing::cCast_5rrwxNbA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YozViMxW, 0, m, &cDelay_YozViMxW_sendMessage);
}

void Heavy_PhaseRing::cTabhead_71Es4iyb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XbU0e5cR, HV_BINOP_SUBTRACT, 0, m, &cBinop_XbU0e5cR_sendMessage);
}

void Heavy_PhaseRing::cMsg_7RN2VUle_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_YozViMxW, 0, m, &cDelay_YozViMxW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ceMPUcYw, 0, m, &cDelay_ceMPUcYw_sendMessage);
}

void Heavy_PhaseRing::cSystem_8tM3GqzD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aJbMkgtr, HV_BINOP_SUBTRACT, 1, m, &cBinop_aJbMkgtr_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ceMPUcYw, 2, m, &cDelay_ceMPUcYw_sendMessage);
}

void Heavy_PhaseRing::cBinop_CJNK44x7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XbU0e5cR, HV_BINOP_SUBTRACT, 1, m, &cBinop_XbU0e5cR_sendMessage);
}

void Heavy_PhaseRing::cBinop_QV33UwVu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YozViMxW, 2, m, &cDelay_YozViMxW_sendMessage);
}

void Heavy_PhaseRing::cBinop_Rlngzr2V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_StASdPUz, HV_BINOP_MULTIPLY, 0, m, &cBinop_StASdPUz_sendMessage);
}

void Heavy_PhaseRing::cBinop_StASdPUz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CJNK44x7, HV_BINOP_MAX, 0, m, &cBinop_CJNK44x7_sendMessage);
}

void Heavy_PhaseRing::cVar_VTNOHwN0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wuaCmp1g_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_WXnUNTtm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VTNOHwN0, 0, m, &cVar_VTNOHwN0_sendMessage);
  cMsg_ezK46nqC_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_71Es4iyb, 0, m, &cTabhead_71Es4iyb_sendMessage);
}

void Heavy_PhaseRing::cBinop_XbU0e5cR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7RN2VUle_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_uyFzNHzc, 0, m, &sTabread_uyFzNHzc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5rrwxNbA_sendMessage);
}

void Heavy_PhaseRing::cDelay_YozViMxW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_YozViMxW, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ceMPUcYw, 0, m, &cDelay_ceMPUcYw_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_uyFzNHzc, 0, m, &sTabread_uyFzNHzc_sendMessage);
}

void Heavy_PhaseRing::cBinop_aJbMkgtr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_QV33UwVu_sendMessage);
}

void Heavy_PhaseRing::cDelay_ceMPUcYw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ceMPUcYw, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_uyFzNHzc, 0, m, &sTabread_uyFzNHzc_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ceMPUcYw, 0, m, &cDelay_ceMPUcYw_sendMessage);
}

void Heavy_PhaseRing::cMsg_gNspD6OU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_CJNK44x7, HV_BINOP_MAX, 1, m, &cBinop_CJNK44x7_sendMessage);
}

void Heavy_PhaseRing::cSystem_HDL3ryem_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Rlngzr2V_sendMessage);
}

void Heavy_PhaseRing::cMsg_ezK46nqC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_HDL3ryem_sendMessage);
}

void Heavy_PhaseRing::sTabread_uyFzNHzc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_aJbMkgtr, HV_BINOP_SUBTRACT, 0, m, &cBinop_aJbMkgtr_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_wuaCmp1g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8tM3GqzD_sendMessage);
}

void Heavy_PhaseRing::cVar_cmJe2ZF3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_d7B4bXi2_sendMessage);
}

void Heavy_PhaseRing::cPack_ai1jlsln_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_H1s5jzQD, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_9aEdFzKI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_BQdvT4G6, m);
}

void Heavy_PhaseRing::cBinop_Sai3hU5Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_9aEdFzKI_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_GGMNXada, m);
}

void Heavy_PhaseRing::cBinop_qODW8Edw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Sai3hU5Y_sendMessage);
}

void Heavy_PhaseRing::cVar_HHodeCyW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6F176PMn, HV_BINOP_MULTIPLY, 0, m, &cBinop_6F176PMn_sendMessage);
}

void Heavy_PhaseRing::cBinop_6F176PMn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_qODW8Edw_sendMessage);
}

void Heavy_PhaseRing::cSystem_IgIk2IkY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YB4Ilcxk_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_lHovu4AG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_IgIk2IkY_sendMessage);
}

void Heavy_PhaseRing::cMsg_YB4Ilcxk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_v9Gjd9o4_sendMessage);
}

void Heavy_PhaseRing::cBinop_v9Gjd9o4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6F176PMn, HV_BINOP_MULTIPLY, 1, m, &cBinop_6F176PMn_sendMessage);
}

void Heavy_PhaseRing::cVar_UUn8tahx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_BIXZnmg1_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_pVu6zRuu, 0, m, &cIf_pVu6zRuu_sendMessage);
}

void Heavy_PhaseRing::cMsg_0D2kpuST_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_Sui3wf8E, HV_BINOP_MAX, 1, m, &cBinop_Sui3wf8E_sendMessage);
}

void Heavy_PhaseRing::cCast_3ZOWsDhU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dcr34w93, 0, m, &cVar_dcr34w93_sendMessage);
  cMsg_E5MjjYrs_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_dQ3czwaE, 0, m, &cTabhead_dQ3czwaE_sendMessage);
}

void Heavy_PhaseRing::cDelay_79wgKxRv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_79wgKxRv, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_u6b8GX5M, 0, m, &sTabread_u6b8GX5M_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_79wgKxRv, 0, m, &cDelay_79wgKxRv_sendMessage);
}

void Heavy_PhaseRing::cMsg_8a9gRL90_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_kNVLE49t, 0, m, &cDelay_kNVLE49t_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_79wgKxRv, 0, m, &cDelay_79wgKxRv_sendMessage);
}

void Heavy_PhaseRing::cBinop_DIJs7fzR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8a9gRL90_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_u6b8GX5M, 0, m, &sTabread_u6b8GX5M_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dFGGLTVi_sendMessage);
}

void Heavy_PhaseRing::cMsg_GwyReTK2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iWvALRp0_sendMessage);
}

void Heavy_PhaseRing::cSystem_3qs68nzi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_dfqwTHm9_sendMessage);
}

void Heavy_PhaseRing::cMsg_E5MjjYrs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3qs68nzi_sendMessage);
}

void Heavy_PhaseRing::cBinop_NtklF6lA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_kNVLE49t, 2, m, &cDelay_kNVLE49t_sendMessage);
}

void Heavy_PhaseRing::cBinop_Sui3wf8E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DIJs7fzR, HV_BINOP_SUBTRACT, 1, m, &cBinop_DIJs7fzR_sendMessage);
}

void Heavy_PhaseRing::cBinop_XqozhxqE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_NtklF6lA_sendMessage);
}

void Heavy_PhaseRing::cCast_dFGGLTVi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_kNVLE49t, 0, m, &cDelay_kNVLE49t_sendMessage);
}

void Heavy_PhaseRing::cTabhead_dQ3czwaE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DIJs7fzR, HV_BINOP_SUBTRACT, 0, m, &cBinop_DIJs7fzR_sendMessage);
}

void Heavy_PhaseRing::cVar_dcr34w93_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GwyReTK2_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_dfqwTHm9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kZN1w8N7, HV_BINOP_MULTIPLY, 0, m, &cBinop_kZN1w8N7_sendMessage);
}

void Heavy_PhaseRing::cSystem_iWvALRp0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XqozhxqE, HV_BINOP_SUBTRACT, 1, m, &cBinop_XqozhxqE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_79wgKxRv, 2, m, &cDelay_79wgKxRv_sendMessage);
}

void Heavy_PhaseRing::cDelay_kNVLE49t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kNVLE49t, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_79wgKxRv, 0, m, &cDelay_79wgKxRv_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_u6b8GX5M, 0, m, &sTabread_u6b8GX5M_sendMessage);
}

void Heavy_PhaseRing::cBinop_kZN1w8N7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Sui3wf8E, HV_BINOP_MAX, 0, m, &cBinop_Sui3wf8E_sendMessage);
}

void Heavy_PhaseRing::sTabread_u6b8GX5M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_XqozhxqE, HV_BINOP_SUBTRACT, 0, m, &cBinop_XqozhxqE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_FS4owC4a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_SDREH4oa_sendMessage);
}

void Heavy_PhaseRing::cBinop_d7B4bXi2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_FS4owC4a_sendMessage);
}

void Heavy_PhaseRing::cBinop_DSGeNqGe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_e1Ej1zl2, m);
}

void Heavy_PhaseRing::cVar_3ebC2MQw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6bkVM1yt, HV_BINOP_MULTIPLY, 0, m, &cBinop_6bkVM1yt_sendMessage);
}

void Heavy_PhaseRing::cBinop_KtNQfHg4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_rqBTySv7_sendMessage);
}

void Heavy_PhaseRing::cBinop_rqBTySv7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_DSGeNqGe_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_kU0eP2xM, m);
}

void Heavy_PhaseRing::cMsg_3qPmVpUf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_z5RHvbPg_sendMessage);
}

void Heavy_PhaseRing::cBinop_6bkVM1yt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_KtNQfHg4_sendMessage);
}

void Heavy_PhaseRing::cMsg_Gnuw3zEv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VEQ2WSw0_sendMessage);
}

void Heavy_PhaseRing::cSystem_VEQ2WSw0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3qPmVpUf_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_z5RHvbPg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6bkVM1yt, HV_BINOP_MULTIPLY, 1, m, &cBinop_6bkVM1yt_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_ACJxBT5X_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_VHV4oP1k_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cMsg_BcSVFyaO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_rLxoq68Z, 2, m, &cDelay_rLxoq68Z_sendMessage);
}

void Heavy_PhaseRing::cSystem_VAPRDG9Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_rmw4EA0j_sendMessage);
}

void Heavy_PhaseRing::cMsg_m8tkTnxv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VAPRDG9Z_sendMessage);
}

void Heavy_PhaseRing::cMsg_VHV4oP1k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_tl96AJr6, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_bNylbiLP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_piNFnJJ3, 0, m, &hTable_piNFnJJ3_sendMessage);
}

void Heavy_PhaseRing::cBinop_bkE8MJkt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rp4aa40z_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_gR2oKeIp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gR2oKeIp, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rLxoq68Z, 0, m, &cDelay_rLxoq68Z_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gR2oKeIp, 0, m, &cDelay_gR2oKeIp_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_tl96AJr6, 1, m, NULL);
}

void Heavy_PhaseRing::cCast_nc5IodC2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gR2oKeIp, 0, m, &cDelay_gR2oKeIp_sendMessage);
}

void Heavy_PhaseRing::hTable_piNFnJJ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BcSVFyaO_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gR2oKeIp, 2, m, &cDelay_gR2oKeIp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nc5IodC2_sendMessage);
}

void Heavy_PhaseRing::cDelay_rLxoq68Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rLxoq68Z, m);
  cMsg_bNylbiLP_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_rmw4EA0j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_bkE8MJkt_sendMessage);
}

void Heavy_PhaseRing::cMsg_rp4aa40z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_piNFnJJ3, 0, m, &hTable_piNFnJJ3_sendMessage);
}

void Heavy_PhaseRing::cBinop_o9cWFQb6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ai1jlsln, 0, m, &cPack_ai1jlsln_sendMessage);
}

void Heavy_PhaseRing::cMsg_BdqdGDli_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_z8AwhaVi, 0, m, &hTable_z8AwhaVi_sendMessage);
}

void Heavy_PhaseRing::cMsg_OUxS27Up_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_eOHSLqSm, 2, m, &cDelay_eOHSLqSm_sendMessage);
}

void Heavy_PhaseRing::cMsg_W6oieqmz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_z8AwhaVi, 0, m, &hTable_z8AwhaVi_sendMessage);
}

void Heavy_PhaseRing::cDelay_aUxfDSsm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_aUxfDSsm, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eOHSLqSm, 0, m, &cDelay_eOHSLqSm_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_aUxfDSsm, 0, m, &cDelay_aUxfDSsm_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_YYvPKbAc, 1, m, NULL);
}

void Heavy_PhaseRing::cBinop_adt5ayG8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_lhwRxwnY_sendMessage);
}

void Heavy_PhaseRing::cMsg_dRWbWHQR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_YYvPKbAc, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_eOHSLqSm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_eOHSLqSm, m);
  cMsg_BdqdGDli_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_iplgos9q_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_dRWbWHQR_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_lhwRxwnY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_W6oieqmz_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_Grfu0Ngg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_adt5ayG8_sendMessage);
}

void Heavy_PhaseRing::cMsg_aMSLNb5u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Grfu0Ngg_sendMessage);
}

void Heavy_PhaseRing::cCast_yirNRKnr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_aUxfDSsm, 0, m, &cDelay_aUxfDSsm_sendMessage);
}

void Heavy_PhaseRing::hTable_z8AwhaVi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OUxS27Up_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_aUxfDSsm, 2, m, &cDelay_aUxfDSsm_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yirNRKnr_sendMessage);
}

void Heavy_PhaseRing::cDelay_1ACwtKEg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1ACwtKEg, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6fo4mxtY, 0, m, &cDelay_6fo4mxtY_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_RxgBrKLe, 0, m, &sTabread_RxgBrKLe_sendMessage);
}

void Heavy_PhaseRing::cBinop_4Zy7imgy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ckz66LTI, HV_BINOP_MULTIPLY, 0, m, &cBinop_ckz66LTI_sendMessage);
}

void Heavy_PhaseRing::cMsg_pfaPnV1i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uXD6tslV_sendMessage);
}

void Heavy_PhaseRing::cSystem_uXD6tslV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_4Zy7imgy_sendMessage);
}

void Heavy_PhaseRing::cDelay_6fo4mxtY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6fo4mxtY, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_RxgBrKLe, 0, m, &sTabread_RxgBrKLe_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6fo4mxtY, 0, m, &cDelay_6fo4mxtY_sendMessage);
}

void Heavy_PhaseRing::cBinop_8DnEodvj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_1ACwtKEg, 2, m, &cDelay_1ACwtKEg_sendMessage);
}

void Heavy_PhaseRing::cBinop_I80szfDg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LLQSv5U0, HV_BINOP_SUBTRACT, 1, m, &cBinop_LLQSv5U0_sendMessage);
}

void Heavy_PhaseRing::cBinop_LLQSv5U0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SJXx81kb_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_RxgBrKLe, 0, m, &sTabread_RxgBrKLe_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Ppkwuftz_sendMessage);
}

void Heavy_PhaseRing::cMsg_MW5IAokN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_I80szfDg, HV_BINOP_MAX, 1, m, &cBinop_I80szfDg_sendMessage);
}

void Heavy_PhaseRing::cVar_PQNSHPhM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wm7JtPMK_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_Ppkwuftz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_1ACwtKEg, 0, m, &cDelay_1ACwtKEg_sendMessage);
}

void Heavy_PhaseRing::sTabread_RxgBrKLe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_fQgV9Mao, HV_BINOP_SUBTRACT, 0, m, &cBinop_fQgV9Mao_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_SJXx81kb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_1ACwtKEg, 0, m, &cDelay_1ACwtKEg_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6fo4mxtY, 0, m, &cDelay_6fo4mxtY_sendMessage);
}

void Heavy_PhaseRing::cBinop_ckz66LTI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_I80szfDg, HV_BINOP_MAX, 0, m, &cBinop_I80szfDg_sendMessage);
}

void Heavy_PhaseRing::cBinop_fQgV9Mao_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_8DnEodvj_sendMessage);
}

void Heavy_PhaseRing::cSystem_gjO95SUi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fQgV9Mao, HV_BINOP_SUBTRACT, 1, m, &cBinop_fQgV9Mao_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6fo4mxtY, 2, m, &cDelay_6fo4mxtY_sendMessage);
}

void Heavy_PhaseRing::cTabhead_heIpMdiJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LLQSv5U0, HV_BINOP_SUBTRACT, 0, m, &cBinop_LLQSv5U0_sendMessage);
}

void Heavy_PhaseRing::cCast_kG80vQei_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PQNSHPhM, 0, m, &cVar_PQNSHPhM_sendMessage);
  cMsg_pfaPnV1i_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_heIpMdiJ, 0, m, &cTabhead_heIpMdiJ_sendMessage);
}

void Heavy_PhaseRing::cMsg_wm7JtPMK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gjO95SUi_sendMessage);
}

void Heavy_PhaseRing::cTabhead_A7o0J11Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SeWjqHEN, HV_BINOP_SUBTRACT, 0, m, &cBinop_SeWjqHEN_sendMessage);
}

void Heavy_PhaseRing::cMsg_C95KwuAg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_L70vIPrx_sendMessage);
}

void Heavy_PhaseRing::cDelay_DRyTmypg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DRyTmypg, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_kFx6KNgb, 0, m, &sTabread_kFx6KNgb_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DRyTmypg, 0, m, &cDelay_DRyTmypg_sendMessage);
}

void Heavy_PhaseRing::cMsg_IQg9xqrX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_yPv4XDiN, 0, m, &cDelay_yPv4XDiN_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DRyTmypg, 0, m, &cDelay_DRyTmypg_sendMessage);
}

void Heavy_PhaseRing::cBinop_K5LR0nmw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_X0noFfe2_sendMessage);
}

void Heavy_PhaseRing::cSystem_L70vIPrx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_K5LR0nmw, HV_BINOP_SUBTRACT, 1, m, &cBinop_K5LR0nmw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DRyTmypg, 2, m, &cDelay_DRyTmypg_sendMessage);
}

void Heavy_PhaseRing::cMsg_Nk0dsf1u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_gjWlTd1g, HV_BINOP_MAX, 1, m, &cBinop_gjWlTd1g_sendMessage);
}

void Heavy_PhaseRing::cBinop_SeWjqHEN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IQg9xqrX_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_kFx6KNgb, 0, m, &sTabread_kFx6KNgb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rLXr4Edz_sendMessage);
}

void Heavy_PhaseRing::cVar_Ww33Z3B8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_C95KwuAg_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_X0noFfe2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_yPv4XDiN, 2, m, &cDelay_yPv4XDiN_sendMessage);
}

void Heavy_PhaseRing::cSystem_Tn42qLDm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_kdQjtT8p_sendMessage);
}

void Heavy_PhaseRing::cMsg_Vs8eTpBv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Tn42qLDm_sendMessage);
}

void Heavy_PhaseRing::cBinop_gjWlTd1g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SeWjqHEN, HV_BINOP_SUBTRACT, 1, m, &cBinop_SeWjqHEN_sendMessage);
}

void Heavy_PhaseRing::cBinop_kBRGOmSe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gjWlTd1g, HV_BINOP_MAX, 0, m, &cBinop_gjWlTd1g_sendMessage);
}

void Heavy_PhaseRing::sTabread_kFx6KNgb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_K5LR0nmw, HV_BINOP_SUBTRACT, 0, m, &cBinop_K5LR0nmw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_kdQjtT8p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kBRGOmSe, HV_BINOP_MULTIPLY, 0, m, &cBinop_kBRGOmSe_sendMessage);
}

void Heavy_PhaseRing::cCast_pZ4BZ6UO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ww33Z3B8, 0, m, &cVar_Ww33Z3B8_sendMessage);
  cMsg_Vs8eTpBv_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_A7o0J11Z, 0, m, &cTabhead_A7o0J11Z_sendMessage);
}

void Heavy_PhaseRing::cCast_rLXr4Edz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_yPv4XDiN, 0, m, &cDelay_yPv4XDiN_sendMessage);
}

void Heavy_PhaseRing::cDelay_yPv4XDiN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_yPv4XDiN, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DRyTmypg, 0, m, &cDelay_DRyTmypg_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_kFx6KNgb, 0, m, &sTabread_kFx6KNgb_sendMessage);
}

void Heavy_PhaseRing::cDelay_2BrDd1Iv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2BrDd1Iv, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_U5sCCMFt, 0, m, &cDelay_U5sCCMFt_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Eujxg9NG, 0, m, &sTabread_Eujxg9NG_sendMessage);
}

void Heavy_PhaseRing::cMsg_AxRzuf7e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_sqsw2EZT_sendMessage);
}

void Heavy_PhaseRing::sTabread_Eujxg9NG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_uwVSXi1B, HV_BINOP_SUBTRACT, 0, m, &cBinop_uwVSXi1B_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_NHbGz78k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_2BrDd1Iv, 0, m, &cDelay_2BrDd1Iv_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_U5sCCMFt, 0, m, &cDelay_U5sCCMFt_sendMessage);
}

void Heavy_PhaseRing::cBinop_OTsyF41f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rgW0CU60, HV_BINOP_MAX, 0, m, &cBinop_rgW0CU60_sendMessage);
}

void Heavy_PhaseRing::cVar_QfPiEje7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AxRzuf7e_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_RlHAjnoq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NHbGz78k_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Eujxg9NG, 0, m, &sTabread_Eujxg9NG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WkLBgba0_sendMessage);
}

void Heavy_PhaseRing::cDelay_U5sCCMFt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_U5sCCMFt, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Eujxg9NG, 0, m, &sTabread_Eujxg9NG_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_U5sCCMFt, 0, m, &cDelay_U5sCCMFt_sendMessage);
}

void Heavy_PhaseRing::cCast_WkLBgba0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_2BrDd1Iv, 0, m, &cDelay_2BrDd1Iv_sendMessage);
}

void Heavy_PhaseRing::cMsg_gDbLMSEB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_rgW0CU60, HV_BINOP_MAX, 1, m, &cBinop_rgW0CU60_sendMessage);
}

void Heavy_PhaseRing::cCast_kEJJAuR9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QfPiEje7, 0, m, &cVar_QfPiEje7_sendMessage);
  cMsg_PSPF92vu_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ol9BBsMZ, 0, m, &cTabhead_ol9BBsMZ_sendMessage);
}

void Heavy_PhaseRing::cBinop_m0jn3s0L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_2BrDd1Iv, 2, m, &cDelay_2BrDd1Iv_sendMessage);
}

void Heavy_PhaseRing::cTabhead_ol9BBsMZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RlHAjnoq, HV_BINOP_SUBTRACT, 0, m, &cBinop_RlHAjnoq_sendMessage);
}

void Heavy_PhaseRing::cBinop_pwFS074N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OTsyF41f, HV_BINOP_MULTIPLY, 0, m, &cBinop_OTsyF41f_sendMessage);
}

void Heavy_PhaseRing::cBinop_rgW0CU60_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RlHAjnoq, HV_BINOP_SUBTRACT, 1, m, &cBinop_RlHAjnoq_sendMessage);
}

void Heavy_PhaseRing::cSystem_sqsw2EZT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uwVSXi1B, HV_BINOP_SUBTRACT, 1, m, &cBinop_uwVSXi1B_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_U5sCCMFt, 2, m, &cDelay_U5sCCMFt_sendMessage);
}

void Heavy_PhaseRing::cBinop_uwVSXi1B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_m0jn3s0L_sendMessage);
}

void Heavy_PhaseRing::cMsg_PSPF92vu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vRWNT9iK_sendMessage);
}

void Heavy_PhaseRing::cSystem_vRWNT9iK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_pwFS074N_sendMessage);
}

void Heavy_PhaseRing::cMsg_3XAlCAba_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_CGDYuUWH, 0, m, &hTable_CGDYuUWH_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_AQAf1ant_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_SMf3xEQ5_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::hTable_CGDYuUWH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_E2D4TpTa_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_w3fySz3T, 2, m, &cDelay_w3fySz3T_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Cw7wEHKg_sendMessage);
}

void Heavy_PhaseRing::cCast_Cw7wEHKg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_w3fySz3T, 0, m, &cDelay_w3fySz3T_sendMessage);
}

void Heavy_PhaseRing::cMsg_E2D4TpTa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_WrjWro5Y, 2, m, &cDelay_WrjWro5Y_sendMessage);
}

void Heavy_PhaseRing::cBinop_JRc8LTmf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_omqBk88d_sendMessage);
}

void Heavy_PhaseRing::cMsg_SMf3xEQ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_bBhvLuhR, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_WrjWro5Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WrjWro5Y, m);
  cMsg_u5Iwv7FZ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_n1drs6ME_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zbJngBFJ_sendMessage);
}

void Heavy_PhaseRing::cSystem_zbJngBFJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_JRc8LTmf_sendMessage);
}

void Heavy_PhaseRing::cBinop_omqBk88d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3XAlCAba_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_u5Iwv7FZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_CGDYuUWH, 0, m, &hTable_CGDYuUWH_sendMessage);
}

void Heavy_PhaseRing::cDelay_w3fySz3T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_w3fySz3T, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WrjWro5Y, 0, m, &cDelay_WrjWro5Y_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_w3fySz3T, 0, m, &cDelay_w3fySz3T_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_bBhvLuhR, 1, m, NULL);
}

void Heavy_PhaseRing::cCast_5G7uBBwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_eLgPr4Lb, 0, m, &cDelay_eLgPr4Lb_sendMessage);
}

void Heavy_PhaseRing::cSystem_6QqHrUGU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fFH97gwZ, HV_BINOP_SUBTRACT, 1, m, &cBinop_fFH97gwZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_qvgNlC3p, 2, m, &cDelay_qvgNlC3p_sendMessage);
}

void Heavy_PhaseRing::cBinop_84t5uMf7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_eLgPr4Lb, 2, m, &cDelay_eLgPr4Lb_sendMessage);
}

void Heavy_PhaseRing::cBinop_8cj8AfBJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GkIAmfP8, HV_BINOP_MAX, 0, m, &cBinop_GkIAmfP8_sendMessage);
}

void Heavy_PhaseRing::cVar_ARLoyoKS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jcNCDCLa_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_GkIAmfP8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ThGNXxTN, HV_BINOP_SUBTRACT, 1, m, &cBinop_ThGNXxTN_sendMessage);
}

void Heavy_PhaseRing::cBinop_PgvUywTr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8cj8AfBJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_8cj8AfBJ_sendMessage);
}

void Heavy_PhaseRing::cTabhead_T8w4BbxS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ThGNXxTN, HV_BINOP_SUBTRACT, 0, m, &cBinop_ThGNXxTN_sendMessage);
}

void Heavy_PhaseRing::cBinop_ThGNXxTN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wBz9wSoS_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ke43D03b, 0, m, &sTabread_ke43D03b_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5G7uBBwC_sendMessage);
}

void Heavy_PhaseRing::cMsg_Uyt9Kp3d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_GkIAmfP8, HV_BINOP_MAX, 1, m, &cBinop_GkIAmfP8_sendMessage);
}

void Heavy_PhaseRing::cSystem_LRZqPo9X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_PgvUywTr_sendMessage);
}

void Heavy_PhaseRing::cMsg_PJW0hS1Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LRZqPo9X_sendMessage);
}

void Heavy_PhaseRing::cCast_eHOrNmVO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ARLoyoKS, 0, m, &cVar_ARLoyoKS_sendMessage);
  cMsg_PJW0hS1Y_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_T8w4BbxS, 0, m, &cTabhead_T8w4BbxS_sendMessage);
}

void Heavy_PhaseRing::cDelay_eLgPr4Lb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_eLgPr4Lb, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_qvgNlC3p, 0, m, &cDelay_qvgNlC3p_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ke43D03b, 0, m, &sTabread_ke43D03b_sendMessage);
}

void Heavy_PhaseRing::cBinop_fFH97gwZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_84t5uMf7_sendMessage);
}

void Heavy_PhaseRing::cMsg_jcNCDCLa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6QqHrUGU_sendMessage);
}

void Heavy_PhaseRing::sTabread_ke43D03b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_fFH97gwZ, HV_BINOP_SUBTRACT, 0, m, &cBinop_fFH97gwZ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cDelay_qvgNlC3p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_qvgNlC3p, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ke43D03b, 0, m, &sTabread_ke43D03b_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_qvgNlC3p, 0, m, &cDelay_qvgNlC3p_sendMessage);
}

void Heavy_PhaseRing::cMsg_wBz9wSoS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_eLgPr4Lb, 0, m, &cDelay_eLgPr4Lb_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_qvgNlC3p, 0, m, &cDelay_qvgNlC3p_sendMessage);
}

void Heavy_PhaseRing::cVar_3NAiTsmS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CQJYYjjP_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_8W3wifGY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qimXY1rv, HV_BINOP_MULTIPLY, 0, m, &cBinop_qimXY1rv_sendMessage);
}

void Heavy_PhaseRing::cBinop_90btGSnx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pihpntGc_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_XMB3MeyH, 0, m, &sTabread_XMB3MeyH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ln4JGEOJ_sendMessage);
}

void Heavy_PhaseRing::cMsg_CQJYYjjP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_HdyRMeyi_sendMessage);
}

void Heavy_PhaseRing::cBinop_E4u2AgAz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_bVVlBJoS, 2, m, &cDelay_bVVlBJoS_sendMessage);
}

void Heavy_PhaseRing::cSystem_HdyRMeyi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RWK9duXY, HV_BINOP_SUBTRACT, 1, m, &cBinop_RWK9duXY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uWoGdxz8, 2, m, &cDelay_uWoGdxz8_sendMessage);
}

void Heavy_PhaseRing::cBinop_RWK9duXY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_E4u2AgAz_sendMessage);
}

void Heavy_PhaseRing::sTabread_XMB3MeyH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_RWK9duXY, HV_BINOP_SUBTRACT, 0, m, &cBinop_RWK9duXY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cDelay_bVVlBJoS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bVVlBJoS, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uWoGdxz8, 0, m, &cDelay_uWoGdxz8_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_XMB3MeyH, 0, m, &sTabread_XMB3MeyH_sendMessage);
}

void Heavy_PhaseRing::cTabhead_lb5cMSir_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_90btGSnx, HV_BINOP_SUBTRACT, 0, m, &cBinop_90btGSnx_sendMessage);
}

void Heavy_PhaseRing::cCast_ln4JGEOJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_bVVlBJoS, 0, m, &cDelay_bVVlBJoS_sendMessage);
}

void Heavy_PhaseRing::cMsg_pihpntGc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_bVVlBJoS, 0, m, &cDelay_bVVlBJoS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uWoGdxz8, 0, m, &cDelay_uWoGdxz8_sendMessage);
}

void Heavy_PhaseRing::cMsg_qQh6LlcC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_xdeW7YyO, HV_BINOP_MAX, 1, m, &cBinop_xdeW7YyO_sendMessage);
}

void Heavy_PhaseRing::cBinop_qimXY1rv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xdeW7YyO, HV_BINOP_MAX, 0, m, &cBinop_xdeW7YyO_sendMessage);
}

void Heavy_PhaseRing::cSystem_1Q0fc1xd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_8W3wifGY_sendMessage);
}

void Heavy_PhaseRing::cMsg_WBu661zv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1Q0fc1xd_sendMessage);
}

void Heavy_PhaseRing::cDelay_uWoGdxz8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_uWoGdxz8, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_XMB3MeyH, 0, m, &sTabread_XMB3MeyH_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uWoGdxz8, 0, m, &cDelay_uWoGdxz8_sendMessage);
}

void Heavy_PhaseRing::cCast_uuI8AlL4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3NAiTsmS, 0, m, &cVar_3NAiTsmS_sendMessage);
  cMsg_WBu661zv_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_lb5cMSir, 0, m, &cTabhead_lb5cMSir_sendMessage);
}

void Heavy_PhaseRing::cBinop_xdeW7YyO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_90btGSnx, HV_BINOP_SUBTRACT, 1, m, &cBinop_90btGSnx_sendMessage);
}

void Heavy_PhaseRing::cMsg_1XTcn22c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_TpMbhQ1X, 0, m, &hTable_TpMbhQ1X_sendMessage);
}

void Heavy_PhaseRing::cDelay_2dRHIFgL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2dRHIFgL, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Q7EZs7Yj, 0, m, &cDelay_Q7EZs7Yj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2dRHIFgL, 0, m, &cDelay_2dRHIFgL_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_D30L1fhK, 1, m, NULL);
}

void Heavy_PhaseRing::cBinop_GUKfx5dt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1XTcn22c_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_Q7EZs7Yj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Q7EZs7Yj, m);
  cMsg_kJbUExuH_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_SYuu5iYJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Q7EZs7Yj, 2, m, &cDelay_Q7EZs7Yj_sendMessage);
}

void Heavy_PhaseRing::hTable_TpMbhQ1X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SYuu5iYJ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2dRHIFgL, 2, m, &cDelay_2dRHIFgL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wKa03XuD_sendMessage);
}

void Heavy_PhaseRing::cBinop_V9AclM2w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_GUKfx5dt_sendMessage);
}

void Heavy_PhaseRing::cMsg_d3mfOe8P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_D30L1fhK, 1, m, NULL);
}

void Heavy_PhaseRing::cSystem_9wlJhcS6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_V9AclM2w_sendMessage);
}

void Heavy_PhaseRing::cMsg_S3EzNmf7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9wlJhcS6_sendMessage);
}

void Heavy_PhaseRing::cMsg_kJbUExuH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_TpMbhQ1X, 0, m, &hTable_TpMbhQ1X_sendMessage);
}

void Heavy_PhaseRing::cCast_wKa03XuD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_2dRHIFgL, 0, m, &cDelay_2dRHIFgL_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_xUZp3MPJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_d3mfOe8P_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_8lrd54HH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_bcA4id0C_sendMessage);
}

void Heavy_PhaseRing::cMsg_ATyiAS9b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_zlt5GtL1, 2, m, &cDelay_zlt5GtL1_sendMessage);
}

void Heavy_PhaseRing::cMsg_HWyBuD8F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_aGikgZYl, 0, m, &hTable_aGikgZYl_sendMessage);
}

void Heavy_PhaseRing::cMsg_stZaYNFS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tukvbl1d_sendMessage);
}

void Heavy_PhaseRing::cSystem_tukvbl1d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_8lrd54HH_sendMessage);
}

void Heavy_PhaseRing::cMsg_P20QSp83_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_aGikgZYl, 0, m, &hTable_aGikgZYl_sendMessage);
}

void Heavy_PhaseRing::hTable_aGikgZYl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ATyiAS9b_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iXWNXdBr, 2, m, &cDelay_iXWNXdBr_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mVivvAP5_sendMessage);
}

void Heavy_PhaseRing::cBinop_bcA4id0C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HWyBuD8F_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_iXWNXdBr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_iXWNXdBr, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zlt5GtL1, 0, m, &cDelay_zlt5GtL1_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iXWNXdBr, 0, m, &cDelay_iXWNXdBr_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_WhmeSAUN, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_iiTUjhp9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_WhmeSAUN, 1, m, NULL);
}

void Heavy_PhaseRing::cCast_mVivvAP5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_iXWNXdBr, 0, m, &cDelay_iXWNXdBr_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_sL1r7e6U_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_iiTUjhp9_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_zlt5GtL1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zlt5GtL1, m);
  cMsg_P20QSp83_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_IIsOyJhJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_i5X1itQb_sendMessage);
}

void Heavy_PhaseRing::hTable_LXOlqpb1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ffLmpw6C_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_qr1ym9Ka, 2, m, &cDelay_qr1ym9Ka_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yBohUrD3_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_Pz8kn5MH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_uRwM9GNm_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cMsg_ORab0XlS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zldvKZTW_sendMessage);
}

void Heavy_PhaseRing::cSystem_zldvKZTW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_IIsOyJhJ_sendMessage);
}

void Heavy_PhaseRing::cMsg_ffLmpw6C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_kZwUvbFE, 2, m, &cDelay_kZwUvbFE_sendMessage);
}

void Heavy_PhaseRing::cBinop_i5X1itQb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sY69BtZq_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_kZwUvbFE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kZwUvbFE, m);
  cMsg_q1EmrL66_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_q1EmrL66_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_LXOlqpb1, 0, m, &hTable_LXOlqpb1_sendMessage);
}

void Heavy_PhaseRing::cDelay_qr1ym9Ka_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_qr1ym9Ka, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kZwUvbFE, 0, m, &cDelay_kZwUvbFE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_qr1ym9Ka, 0, m, &cDelay_qr1ym9Ka_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_opmtYadB, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_sY69BtZq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_LXOlqpb1, 0, m, &hTable_LXOlqpb1_sendMessage);
}

void Heavy_PhaseRing::cMsg_uRwM9GNm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_opmtYadB, 1, m, NULL);
}

void Heavy_PhaseRing::cCast_yBohUrD3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_qr1ym9Ka, 0, m, &cDelay_qr1ym9Ka_sendMessage);
}

void Heavy_PhaseRing::cBinop_1earnbJr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cnfmS3IJ_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_H5ZWsx5N, 0, m, &sTabread_H5ZWsx5N_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6C9Y56FE_sendMessage);
}

void Heavy_PhaseRing::cCast_6C9Y56FE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_F78RwXD6, 0, m, &cDelay_F78RwXD6_sendMessage);
}

void Heavy_PhaseRing::cTabhead_F50fcYF4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1earnbJr, HV_BINOP_SUBTRACT, 0, m, &cBinop_1earnbJr_sendMessage);
}

void Heavy_PhaseRing::cDelay_F78RwXD6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_F78RwXD6, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uqKw2Zl3, 0, m, &cDelay_uqKw2Zl3_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_H5ZWsx5N, 0, m, &sTabread_H5ZWsx5N_sendMessage);
}

void Heavy_PhaseRing::sTabread_H5ZWsx5N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_NG1rA9r2, HV_BINOP_SUBTRACT, 0, m, &cBinop_NG1rA9r2_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_N8pmwXwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Nj6DFvLz, HV_BINOP_MAX, 0, m, &cBinop_Nj6DFvLz_sendMessage);
}

void Heavy_PhaseRing::cBinop_NG1rA9r2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_nWqnUC27_sendMessage);
}

void Heavy_PhaseRing::cBinop_Nj6DFvLz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1earnbJr, HV_BINOP_SUBTRACT, 1, m, &cBinop_1earnbJr_sendMessage);
}

void Heavy_PhaseRing::cSystem_NqAlEh4g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NG1rA9r2, HV_BINOP_SUBTRACT, 1, m, &cBinop_NG1rA9r2_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uqKw2Zl3, 2, m, &cDelay_uqKw2Zl3_sendMessage);
}

void Heavy_PhaseRing::cBinop_PpQkn2Vn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_N8pmwXwC, HV_BINOP_MULTIPLY, 0, m, &cBinop_N8pmwXwC_sendMessage);
}

void Heavy_PhaseRing::cVar_VmmijPxO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_be6oqhtN_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_be6oqhtN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NqAlEh4g_sendMessage);
}

void Heavy_PhaseRing::cMsg_cnfmS3IJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_F78RwXD6, 0, m, &cDelay_F78RwXD6_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uqKw2Zl3, 0, m, &cDelay_uqKw2Zl3_sendMessage);
}

void Heavy_PhaseRing::cMsg_ipJqZGMy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_Nj6DFvLz, HV_BINOP_MAX, 1, m, &cBinop_Nj6DFvLz_sendMessage);
}

void Heavy_PhaseRing::cCast_mo6EloTV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VmmijPxO, 0, m, &cVar_VmmijPxO_sendMessage);
  cMsg_WA1JyZAo_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_F50fcYF4, 0, m, &cTabhead_F50fcYF4_sendMessage);
}

void Heavy_PhaseRing::cBinop_nWqnUC27_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_F78RwXD6, 2, m, &cDelay_F78RwXD6_sendMessage);
}

void Heavy_PhaseRing::cSystem_4MjNL4r0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_PpQkn2Vn_sendMessage);
}

void Heavy_PhaseRing::cMsg_WA1JyZAo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4MjNL4r0_sendMessage);
}

void Heavy_PhaseRing::cDelay_uqKw2Zl3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_uqKw2Zl3, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_H5ZWsx5N, 0, m, &sTabread_H5ZWsx5N_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uqKw2Zl3, 0, m, &cDelay_uqKw2Zl3_sendMessage);
}

void Heavy_PhaseRing::cMsg_1fD3OqQY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_rq9uXTGZ, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_3yu34DfP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_WFX1Ylce, 0, m, &hTable_WFX1Ylce_sendMessage);
}

void Heavy_PhaseRing::cCast_9BfSbfVA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_VPA9eOP7, 0, m, &cDelay_VPA9eOP7_sendMessage);
}

void Heavy_PhaseRing::cSystem_B3v7faAs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_vxyreL0j_sendMessage);
}

void Heavy_PhaseRing::cMsg_hYE2jt41_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_B3v7faAs_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_NI1T4PWo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_1fD3OqQY_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cMsg_PoHqV3UQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_WFX1Ylce, 0, m, &hTable_WFX1Ylce_sendMessage);
}

void Heavy_PhaseRing::cDelay_VPA9eOP7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VPA9eOP7, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iQWRFpbP, 0, m, &cDelay_iQWRFpbP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VPA9eOP7, 0, m, &cDelay_VPA9eOP7_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_rq9uXTGZ, 1, m, NULL);
}

void Heavy_PhaseRing::hTable_WFX1Ylce_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_no5oSF1E_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VPA9eOP7, 2, m, &cDelay_VPA9eOP7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9BfSbfVA_sendMessage);
}

void Heavy_PhaseRing::cBinop_giDhiHVP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PoHqV3UQ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_iQWRFpbP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_iQWRFpbP, m);
  cMsg_3yu34DfP_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_no5oSF1E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_iQWRFpbP, 2, m, &cDelay_iQWRFpbP_sendMessage);
}

void Heavy_PhaseRing::cBinop_vxyreL0j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_giDhiHVP_sendMessage);
}

void Heavy_PhaseRing::cVar_WY3sTZvf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_o9cWFQb6_sendMessage);
}

void Heavy_PhaseRing::cMsg_3cUzpd2y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_aBIvBVzR, 1, m, NULL);
}

void Heavy_PhaseRing::cBinop_Kgr6aHNB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_v5MSEa5l_sendMessage);
}

void Heavy_PhaseRing::hTable_TuXtPgx8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_z1SsqQq5_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hnYy2tkb, 2, m, &cDelay_hnYy2tkb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_znGAkzjR_sendMessage);
}

void Heavy_PhaseRing::cDelay_ZnFQ5VXv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ZnFQ5VXv, m);
  cMsg_xZ3h0xCV_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_d7xusZhg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_TuXtPgx8, 0, m, &hTable_TuXtPgx8_sendMessage);
}

void Heavy_PhaseRing::cDelay_hnYy2tkb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hnYy2tkb, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZnFQ5VXv, 0, m, &cDelay_ZnFQ5VXv_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hnYy2tkb, 0, m, &cDelay_hnYy2tkb_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_aBIvBVzR, 1, m, NULL);
}

void Heavy_PhaseRing::cSwitchcase_jUrXYuiX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_3cUzpd2y_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_v5MSEa5l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_d7xusZhg_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_xZ3h0xCV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_TuXtPgx8, 0, m, &hTable_TuXtPgx8_sendMessage);
}

void Heavy_PhaseRing::cSystem_1UxLhA9z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Kgr6aHNB_sendMessage);
}

void Heavy_PhaseRing::cMsg_AQ3aaPPE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1UxLhA9z_sendMessage);
}

void Heavy_PhaseRing::cMsg_z1SsqQq5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZnFQ5VXv, 2, m, &cDelay_ZnFQ5VXv_sendMessage);
}

void Heavy_PhaseRing::cCast_znGAkzjR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_hnYy2tkb, 0, m, &cDelay_hnYy2tkb_sendMessage);
}

void Heavy_PhaseRing::cMsg_1zer0eRT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_He9AEVtp, 1, m, NULL);
}

void Heavy_PhaseRing::cBinop_2h47LjGu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Yk3n9uoQ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_AOmra5OL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_n4lI5xzO_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TKspi2Jg, 2, m, &cDelay_TKspi2Jg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_e6NJyAcp_sendMessage);
}

void Heavy_PhaseRing::cDelay_Majfm0GP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Majfm0GP, m);
  cMsg_Yi8UkOy6_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_TKspi2Jg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TKspi2Jg, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Majfm0GP, 0, m, &cDelay_Majfm0GP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TKspi2Jg, 0, m, &cDelay_TKspi2Jg_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_He9AEVtp, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_Yi8UkOy6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_AOmra5OL, 0, m, &hTable_AOmra5OL_sendMessage);
}

void Heavy_PhaseRing::cMsg_Yk3n9uoQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_AOmra5OL, 0, m, &hTable_AOmra5OL_sendMessage);
}

void Heavy_PhaseRing::cMsg_lT3yyo1g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nb6VTrFm_sendMessage);
}

void Heavy_PhaseRing::cSystem_nb6VTrFm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_mufoUR7L_sendMessage);
}

void Heavy_PhaseRing::cCast_e6NJyAcp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TKspi2Jg, 0, m, &cDelay_TKspi2Jg_sendMessage);
}

void Heavy_PhaseRing::cBinop_mufoUR7L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_2h47LjGu_sendMessage);
}

void Heavy_PhaseRing::cMsg_n4lI5xzO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Majfm0GP, 2, m, &cDelay_Majfm0GP_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_pTFHNMfB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_1zer0eRT_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cIf_G4UDRA8G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_VQPLPN2T_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_ZCwEjOv8_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_Hd8hM02e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_UwHC7l98_sendMessage);
}

void Heavy_PhaseRing::cBinop_UwHC7l98_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dJXlauGI, HV_BINOP_POW, 1, m, &cBinop_dJXlauGI_sendMessage);
  cMsg_mwUeFqx8_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_VQPLPN2T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_MgYlK9We_sendMessage);
}

void Heavy_PhaseRing::cCast_Y32RxzaP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_mCwWjVxC_sendMessage);
}

void Heavy_PhaseRing::cBinop_ZCwEjOv8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_Hd8hM02e_sendMessage);
}

void Heavy_PhaseRing::cBinop_dJXlauGI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_MgYlK9We_sendMessage);
}

void Heavy_PhaseRing::cBinop_mCwWjVxC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_G4UDRA8G, 1, m, &cIf_G4UDRA8G_sendMessage);
}

void Heavy_PhaseRing::cMsg_mwUeFqx8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_dJXlauGI, HV_BINOP_POW, 0, m, &cBinop_dJXlauGI_sendMessage);
}

void Heavy_PhaseRing::cCast_ubdBPvp7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_G4UDRA8G, 0, m, &cIf_G4UDRA8G_sendMessage);
}

void Heavy_PhaseRing::cBinop_5qKhvvY8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WY3sTZvf, 0, m, &cVar_WY3sTZvf_sendMessage);
}

void Heavy_PhaseRing::cBinop_iVcBj2d4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_5qKhvvY8_sendMessage);
}

void Heavy_PhaseRing::cReceive_ZlTLysvX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_nMt4JOpM_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jQdVp78g, 0, m, &cVar_jQdVp78g_sendMessage);
}

void Heavy_PhaseRing::cSend_5YNTznFC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_QPrQCP5y_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_7Bb6MkkD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_MY97fxBV, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_3gKYUMQj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_AQ6SM33L_sendMessage);
}

void Heavy_PhaseRing::cIf_7snAldA2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_PES1jBNz_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_3gKYUMQj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_AQ6SM33L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_CAD8cIyT_sendMessage);
}

void Heavy_PhaseRing::cBinop_CAD8cIyT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gs8ZreSM, HV_BINOP_POW, 1, m, &cBinop_gs8ZreSM_sendMessage);
  cMsg_l2En9LsM_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_NZUTOy0x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_7snAldA2, 1, m, &cIf_7snAldA2_sendMessage);
}

void Heavy_PhaseRing::cMsg_PES1jBNz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_7Bb6MkkD, 0, m, &cPack_7Bb6MkkD_sendMessage);
}

void Heavy_PhaseRing::cCast_YgNzMhZe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_7snAldA2, 0, m, &cIf_7snAldA2_sendMessage);
}

void Heavy_PhaseRing::cBinop_gs8ZreSM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_7Bb6MkkD, 0, m, &cPack_7Bb6MkkD_sendMessage);
}

void Heavy_PhaseRing::cMsg_l2En9LsM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_gs8ZreSM, HV_BINOP_POW, 0, m, &cBinop_gs8ZreSM_sendMessage);
}

void Heavy_PhaseRing::cCast_tbpIIGhY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_NZUTOy0x_sendMessage);
}

void Heavy_PhaseRing::cSend_ZiEnNeAD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_3bxNm4Ir_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_iiLdsRJw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xdr0FEFS_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tbpIIGhY_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YgNzMhZe_sendMessage);
}

void Heavy_PhaseRing::cVar_8z9Pseml_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ZiEnNeAD_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_xdr0FEFS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_5YNTznFC_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_aYEBZH6C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_7AyEZaBn_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_1HRfmt7H_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cReceive_bsCrqwau_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_V7IicSMQ, 0, m, &cVar_V7IicSMQ_sendMessage);
}

void Heavy_PhaseRing::cSend_end46Sci_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cBinop_2IxfkxHo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.1f, 0, m, &cBinop_RC1w7gsV_sendMessage);
}

void Heavy_PhaseRing::cPack_DHkTv6Pi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_nxs8Ef8l, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_EXJdIf0H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_6mMfceYq, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_VY1RJkTf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_KNRXTitf, 0, m);
}

void Heavy_PhaseRing::cMsg_RovwkIw2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_DHkTv6Pi, 0, m, &cPack_DHkTv6Pi_sendMessage);
}

void Heavy_PhaseRing::cMsg_VhLwdwpO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_DHkTv6Pi, 0, m, &cPack_DHkTv6Pi_sendMessage);
}

void Heavy_PhaseRing::cIf_RyS40cLD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_jgjsbrVI_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_5i6ETPTW, 0, m, &cIf_5i6ETPTW_sendMessage);
      break;
    }
    case 1: {
      cMsg_RovwkIw2_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_bp961vPM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_RyS40cLD, 1, m, &cIf_RyS40cLD_sendMessage);
}

void Heavy_PhaseRing::cIf_5i6ETPTW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_VhLwdwpO_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_DHkTv6Pi, 0, m, &cPack_DHkTv6Pi_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_jgjsbrVI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_5i6ETPTW, 1, m, &cIf_5i6ETPTW_sendMessage);
}

void Heavy_PhaseRing::cVar_QBi57nCB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_2IxfkxHo_sendMessage);
}

void Heavy_PhaseRing::cBinop_RC1w7gsV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_y8dncuUV, 0, m, &cPack_y8dncuUV_sendMessage);
}

void Heavy_PhaseRing::cBinop_TeJWlABt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QBi57nCB, 0, m, &cVar_QBi57nCB_sendMessage);
}

void Heavy_PhaseRing::cBinop_UwnKRHQN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5f, 0, m, &cBinop_nsjzxmlq_sendMessage);
}

void Heavy_PhaseRing::cMsg_07mI5Zm2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_UwnKRHQN_sendMessage);
}

void Heavy_PhaseRing::cBinop_1rdsyL1V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_saBX0Tr8, 1, m, &cIf_saBX0Tr8_sendMessage);
}

void Heavy_PhaseRing::cIf_saBX0Tr8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Ivxh18KH_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_UwnKRHQN_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_Ivxh18KH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_UwnKRHQN_sendMessage);
}

void Heavy_PhaseRing::cIf_j8wxsOsu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_1rdsyL1V_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_saBX0Tr8, 0, m, &cIf_saBX0Tr8_sendMessage);
      break;
    }
    case 1: {
      cMsg_07mI5Zm2_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_volt9ZhQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_j8wxsOsu, 1, m, &cIf_j8wxsOsu_sendMessage);
}

void Heavy_PhaseRing::cPack_ZL0ffJl0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_PGc5Wu08, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_9CgrFmgG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_qZvPub3H_sendMessage);
}

void Heavy_PhaseRing::cMsg_XA9Islg7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9CgrFmgG, HV_BINOP_POW, 0, m, &cBinop_9CgrFmgG_sendMessage);
}

void Heavy_PhaseRing::cBinop_leI1EkhV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_urvmPGFa_sendMessage);
}

void Heavy_PhaseRing::cBinop_qZvPub3H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VY1RJkTf, 0, m, &cVar_VY1RJkTf_sendMessage);
}

void Heavy_PhaseRing::cBinop_urvmPGFa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9CgrFmgG, HV_BINOP_POW, 1, m, &cBinop_9CgrFmgG_sendMessage);
  cMsg_XA9Islg7_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_21PTp1p6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_cSPlOhpL_sendMessage);
}

void Heavy_PhaseRing::cBinop_3QntzRYW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_vFEZkAsQ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_aM7Y2OdJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_A1uLXMxH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_3QntzRYW_sendMessage);
}

void Heavy_PhaseRing::cMsg_6TgSkHc0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_ipYoyxvd_sendMessage);
}

void Heavy_PhaseRing::cSystem_mzK2TUx2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MvbUOE6c, HV_BINOP_DIVIDE, 1, m, &cBinop_MvbUOE6c_sendMessage);
}

void Heavy_PhaseRing::cMsg_uS0HGpAT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mzK2TUx2_sendMessage);
}

void Heavy_PhaseRing::cBinop_MvbUOE6c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6TgSkHc0_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_aM7Y2OdJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_NsY2i96y, m);
}

void Heavy_PhaseRing::cBinop_cSPlOhpL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MvbUOE6c, HV_BINOP_DIVIDE, 0, m, &cBinop_MvbUOE6c_sendMessage);
}

void Heavy_PhaseRing::cVar_5b8HQKK4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_21PTp1p6_sendMessage);
}

void Heavy_PhaseRing::cBinop_ipYoyxvd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_A1uLXMxH_sendMessage);
}

void Heavy_PhaseRing::cBinop_pbBsjPQm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_eiAtJAV7, m);
}

void Heavy_PhaseRing::cBinop_vFEZkAsQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_pbBsjPQm_sendMessage);
}

void Heavy_PhaseRing::cBinop_nsjzxmlq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_bp961vPM_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_RyS40cLD, 0, m, &cIf_RyS40cLD_sendMessage);
}

void Heavy_PhaseRing::cPack_y8dncuUV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_EIuT2fqi, 0, m, NULL);
}

void Heavy_PhaseRing::cSend_64NZTOML_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_bsCrqwau_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_ALe7ZojB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_JGUkR6QZ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_V7IicSMQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ALe7ZojB_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_mUArOlqK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_b9sOQFW1_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7lfxwfbV_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zFNBDphz_sendMessage);
}

void Heavy_PhaseRing::cMsg_b9sOQFW1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_64NZTOML_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_7lfxwfbV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_fDYrPmO6_sendMessage);
}

void Heavy_PhaseRing::cBinop_FkF7X4OI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_armelQe2_sendMessage);
}

void Heavy_PhaseRing::cBinop_Z2DLbpH9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qqwJdVRt, 0, m, &cPack_qqwJdVRt_sendMessage);
}

void Heavy_PhaseRing::cBinop_armelQe2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z2DLbpH9, HV_BINOP_POW, 1, m, &cBinop_Z2DLbpH9_sendMessage);
  cMsg_wQmW9iku_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_fDYrPmO6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_uH4vKDRv, 1, m, &cIf_uH4vKDRv_sendMessage);
}

void Heavy_PhaseRing::cBinop_qMNGaEC0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_FkF7X4OI_sendMessage);
}

void Heavy_PhaseRing::cMsg_sSG2sUZE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_qqwJdVRt, 0, m, &cPack_qqwJdVRt_sendMessage);
}

void Heavy_PhaseRing::cIf_uH4vKDRv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_sSG2sUZE_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_qMNGaEC0_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_wQmW9iku_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z2DLbpH9, HV_BINOP_POW, 0, m, &cBinop_Z2DLbpH9_sendMessage);
}

void Heavy_PhaseRing::cCast_zFNBDphz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_uH4vKDRv, 0, m, &cIf_uH4vKDRv_sendMessage);
}

void Heavy_PhaseRing::cPack_qqwJdVRt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_7DBxaSxZ, 0, m, NULL);
}

void Heavy_PhaseRing::cReceive_i2ZOvpDX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yDNqQqM2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LcMyXhPg_sendMessage);
}

void Heavy_PhaseRing::cReceive_i6tzG4cg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_leI1EkhV_sendMessage);
}

void Heavy_PhaseRing::cReceive_iBbrZkJq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ActXizl2_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_kFL9HD4I, 0, m, &cVar_kFL9HD4I_sendMessage);
}

void Heavy_PhaseRing::cReceive_k3qhc7vf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_f4T9ZML1, 0, m, &cPack_f4T9ZML1_sendMessage);
}

void Heavy_PhaseRing::cBinop_0FDZo04z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_XBOus50k_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_1RvtilXu_sendMessage);
}

void Heavy_PhaseRing::cPack_IwOawX5b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_B2v4PPDh, 0, m, NULL);
}

void Heavy_PhaseRing::cUnop_XBOus50k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_PZMNAqEr, 0, m, &cPack_PZMNAqEr_sendMessage);
}

void Heavy_PhaseRing::cPack_PZMNAqEr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_hJdquvdC, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_af5JXkiI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_0FDZo04z_sendMessage);
}

void Heavy_PhaseRing::cUnop_1RvtilXu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_IwOawX5b, 0, m, &cPack_IwOawX5b_sendMessage);
}

void Heavy_PhaseRing::cVar_nCsacBBJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_Qrl4iP6g, 0, m);
}

void Heavy_PhaseRing::cSend_1zPJCCPO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_k3qhc7vf_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_1bFSirnx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_KXe9xik7, 0, m, &cSlice_KXe9xik7_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ihKkZyPO, 0, m, &cRandom_ihKkZyPO_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cSlice_KXe9xik7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ihKkZyPO, 1, m, &cRandom_ihKkZyPO_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cUnop_XchJv8at_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_scwDdBXK_sendMessage);
}

void Heavy_PhaseRing::cBinop_Z0vBsWbw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_XchJv8at_sendMessage);
}

void Heavy_PhaseRing::cRandom_ihKkZyPO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_Z0vBsWbw_sendMessage);
}

void Heavy_PhaseRing::cSend_AJnwceAy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RDsrnpUR_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_F0RbQ9jq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_uPJzjc45_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cUnop_2fVMajaA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_YKovKCZj_sendMessage);
}

void Heavy_PhaseRing::cBinop_8zUTbBrq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_2fVMajaA_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_uPJzjc45_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_yz8LlBy0, 0, m, &cSlice_yz8LlBy0_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_xzqAzSUl, 0, m, &cRandom_xzqAzSUl_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cRandom_xzqAzSUl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_8zUTbBrq_sendMessage);
}

void Heavy_PhaseRing::cSlice_yz8LlBy0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_xzqAzSUl, 1, m, &cRandom_xzqAzSUl_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cCast_QVwN18h0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2Zx4pJ62_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UPcCF4Er_sendMessage);
}

void Heavy_PhaseRing::cBinop_UVzEpJIk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kP6Ij3Go, HV_BINOP_MULTIPLY, 1, m, &cBinop_kP6Ij3Go_sendMessage);
}

void Heavy_PhaseRing::cBinop_DvQkykCf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_twgcsRnd_sendMessage);
}

void Heavy_PhaseRing::cBinop_RIp5X4lw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DvQkykCf, HV_BINOP_POW, 1, m, &cBinop_DvQkykCf_sendMessage);
  cMsg_c39DOpNZ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_c39DOpNZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_DvQkykCf, HV_BINOP_POW, 0, m, &cBinop_DvQkykCf_sendMessage);
}

void Heavy_PhaseRing::cBinop_ta1BCMca_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_RIp5X4lw_sendMessage);
}

void Heavy_PhaseRing::cBinop_twgcsRnd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kP6Ij3Go, HV_BINOP_MULTIPLY, 0, m, &cBinop_kP6Ij3Go_sendMessage);
}

void Heavy_PhaseRing::cCast_UPcCF4Er_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cBinop_YKovKCZj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_UVzEpJIk_sendMessage);
}

void Heavy_PhaseRing::cCast_ZjDpd5s6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_1bFSirnx_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_aT0m7Cx6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_f4T9ZML1, 0, m, &cPack_f4T9ZML1_sendMessage);
}

void Heavy_PhaseRing::cPack_f4T9ZML1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_V2J7zuro, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_kP6Ij3Go_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QVwN18h0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZjDpd5s6_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_nCsacBBJ, 0, m, &cVar_nCsacBBJ_sendMessage);
}

void Heavy_PhaseRing::cMsg_kymfi3IE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_AJnwceAy_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_AfUQB6J5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sNm3K30R_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_2Zx4pJ62_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JRUzHE8k, 0, m, &cVar_JRUzHE8k_sendMessage);
}

void Heavy_PhaseRing::cCast_3zGslyvo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AfUQB6J5, 1, m, &cVar_AfUQB6J5_sendMessage);
}

void Heavy_PhaseRing::cVar_6C985mw3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cCast_D5m1z7gq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_b74TjSwu_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_IzpMzzdU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_RbG2TLPM_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_A4BGqHjh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_JRUzHE8k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OTOJ6CJ6_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3zGslyvo_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_D5m1z7gq_sendMessage);
}

void Heavy_PhaseRing::cCast_19TtWUOq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_dgSC3OJ3, 0, m, &cDelay_dgSC3OJ3_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_b74TjSwu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_c4ZWt11r_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_c4ZWt11r_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_dgSC3OJ3, 1, m, &cDelay_dgSC3OJ3_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_19TtWUOq_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cMsg_c4ZWt11r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_dgSC3OJ3, 0, m, &cDelay_dgSC3OJ3_sendMessage);
}

void Heavy_PhaseRing::cDelay_dgSC3OJ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_dgSC3OJ3, m);
  cVar_onMessage(_c, &Context(_c)->cVar_AfUQB6J5, 0, m, &cVar_AfUQB6J5_sendMessage);
}

void Heavy_PhaseRing::cCast_OTOJ6CJ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qFbmcLcR_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_dOo93zXX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_RbG2TLPM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_MRJzFSvg_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_URVh5iIh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cMsg_YYz6qie4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_iNHrBkwB_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_cpzsusVR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9nbcLdkc_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_iNHrBkwB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cMsg_qFbmcLcR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_1nlmdvZ2, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_sNm3K30R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_1nlmdvZ2, 0, m, NULL);
}

void Heavy_PhaseRing::cSend_snAvqQ4P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cMsg_v3IWYFVs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_z6v25Nvj_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_z6v25Nvj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9nbcLdkc_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_zVAs2wHQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_MRJzFSvg_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_pZr4IJYc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_0FDZo04z_sendMessage);
}

void Heavy_PhaseRing::cVar_QWxZqDZ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_aT0m7Cx6_sendMessage);
}

void Heavy_PhaseRing::cBinop_scwDdBXK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_pZr4IJYc_sendMessage);
}

void Heavy_PhaseRing::cBinop_tRALRFZl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_tknm2mH3_sendMessage(_c, 0, m);
  cSend_1zPJCCPO_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_tknm2mH3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YzDUtlvP_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSlice_AqMZxlgk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_F0RbQ9jq_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_ta1BCMca_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_ovDz7MNZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_tRALRFZl_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_jyVlA3J9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_nCjkyaID, 0, m);
}

void Heavy_PhaseRing::cReceive_l3aBboEX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_TeJWlABt_sendMessage);
}

void Heavy_PhaseRing::cBinop_CG0wZFS4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QZpIx2bq_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aXleD2RC_sendMessage);
}

void Heavy_PhaseRing::cBinop_fEqdfucC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_CG0wZFS4_sendMessage);
}

void Heavy_PhaseRing::cUnop_8j3KsQL7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_Ll9GNorC_sendMessage);
}

void Heavy_PhaseRing::cBinop_93TfI35w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_eaz7SeMm, 1, m, &cIf_eaz7SeMm_sendMessage);
}

void Heavy_PhaseRing::cBinop_IBWKmbCT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_12m3dBEK_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gaisByIG_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1EKsOIxg_sendMessage);
}

void Heavy_PhaseRing::cBinop_Ll9GNorC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_UvVdZMhk_sendMessage);
}

void Heavy_PhaseRing::cCast_QZpIx2bq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_93TfI35w_sendMessage);
}

void Heavy_PhaseRing::cBinop_UvVdZMhk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_IBWKmbCT_sendMessage);
}

void Heavy_PhaseRing::cMsg_ZjcSTAe1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_12m3dBEK_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gaisByIG_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1EKsOIxg_sendMessage);
}

void Heavy_PhaseRing::cCast_aXleD2RC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_eaz7SeMm, 0, m, &cIf_eaz7SeMm_sendMessage);
}

void Heavy_PhaseRing::cIf_eaz7SeMm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_ZjcSTAe1_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_8j3KsQL7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cReceive_m6Ye80po_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XXe4aOsj, 0, m, &cVar_XXe4aOsj_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_V8ct3CB6, 0, m, &cVar_V8ct3CB6_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_jyVlA3J9, 0, m, &cVar_jyVlA3J9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Zn1ojjrH, 0, m, &cVar_Zn1ojjrH_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_ZL0ffJl0, 0, m, &cPack_ZL0ffJl0_sendMessage);
}

void Heavy_PhaseRing::cCast_2HStWATz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_KJ32jbcx, 1, m, &cPack_KJ32jbcx_sendMessage);
}

void Heavy_PhaseRing::cIf_8XwV0nHB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_rPJtY3Av, 0, m, &cSlice_rPJtY3Av_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_iep9NulX, 0, m, &cSlice_iep9NulX_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_30tQoujw, 0, m, &cIf_30tQoujw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_Kic1l2wI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_t5Mweajk, 0, m, &cVar_t5Mweajk_sendMessage);
}

void Heavy_PhaseRing::cCast_8LH0q25C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mz6JBFLg_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_kycAtuID_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8LH0q25C_sendMessage);
      break;
    }
    default: {
      cMsg_Kic1l2wI_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_PhaseRing::cMsg_mz6JBFLg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_t5Mweajk, 0, m, &cVar_t5Mweajk_sendMessage);
}

void Heavy_PhaseRing::cBinop_KPqIY7Xw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_t5Mweajk, 1, m, &cVar_t5Mweajk_sendMessage);
}

void Heavy_PhaseRing::cVar_t5Mweajk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_KPqIY7Xw_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_8XwV0nHB, 1, m, &cIf_8XwV0nHB_sendMessage);
}

void Heavy_PhaseRing::cBinop_7Xvxu4rE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 4.0f, 0, m, &cBinop_v5HeQKNL_sendMessage);
}

void Heavy_PhaseRing::cPack_7vnpFwWQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_8XwV0nHB, 0, m, &cIf_8XwV0nHB_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_8Luag3CS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_uzWvTynq, 0, m, &cSlice_uzWvTynq_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_N2oaa2E2, 0, m, &cSlice_N2oaa2E2_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_MDr4RZ6v, 0, m, &cSlice_MDr4RZ6v_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_LPTJYrUI, 0, m, &cSlice_LPTJYrUI_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cSlice_LPTJYrUI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_GHZlDtTM, 0, m, &cSlice_GHZlDtTM_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_I6lVVRIC, 0, m, &cSlice_I6lVVRIC_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_GHZlDtTM, 0, m, &cSlice_GHZlDtTM_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_I6lVVRIC, 0, m, &cSlice_I6lVVRIC_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_MDr4RZ6v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_ktV5WUFT, 0, m, &cSlice_ktV5WUFT_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_FYFzJj9d, 0, m, &cSlice_FYFzJj9d_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_ktV5WUFT, 0, m, &cSlice_ktV5WUFT_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_FYFzJj9d, 0, m, &cSlice_FYFzJj9d_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_N2oaa2E2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_ovDz7MNZ, 0, m, &cSlice_ovDz7MNZ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_AqMZxlgk, 0, m, &cSlice_AqMZxlgk_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_ovDz7MNZ, 0, m, &cSlice_ovDz7MNZ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_AqMZxlgk, 0, m, &cSlice_AqMZxlgk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_uzWvTynq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_mAE5DoaE, 0, m, &cSlice_mAE5DoaE_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_nOyokf8c, 0, m, &cSlice_nOyokf8c_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_mAE5DoaE, 0, m, &cSlice_mAE5DoaE_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_nOyokf8c, 0, m, &cSlice_nOyokf8c_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cPack_KJ32jbcx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_8Luag3CS_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_P9rxUXcZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_kycAtuID_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_hezYtxLh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_B8wk0zVr, 0, m, &cVar_B8wk0zVr_sendMessage);
}

void Heavy_PhaseRing::cVar_B8wk0zVr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_KJ32jbcx, 0, m, &cPack_KJ32jbcx_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_7Xvxu4rE_sendMessage);
}

void Heavy_PhaseRing::cCast_8K9NIuUt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_N7qKqvxi_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cIf_899dCYGS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2HStWATz_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hezYtxLh_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_30tQoujw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_BIA73XbY, 0, m, &cSlice_BIA73XbY_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_uan6vIB7, 0, m, &cSlice_uan6vIB7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cCast_KMy9GpdV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_hmWBbNn7, 0, m, &cPack_hmWBbNn7_sendMessage);
}

void Heavy_PhaseRing::cCast_LB2XcOiB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_eOKUIqlV, 0, m, &cIf_eOKUIqlV_sendMessage);
}

void Heavy_PhaseRing::cMsg_N7qKqvxi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_RVOrQXuy, 1, m, &cVar_RVOrQXuy_sendMessage);
}

void Heavy_PhaseRing::cIf_Tky2vR8S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_BIA73XbY, 0, m, &cSlice_BIA73XbY_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_uan6vIB7, 0, m, &cSlice_uan6vIB7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_RVOrQXuy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_30tQoujw, 1, m, &cIf_30tQoujw_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_dYzXVGuk_sendMessage);
}

void Heavy_PhaseRing::cSlice_BIA73XbY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_c3Mwp4Ae_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LB2XcOiB_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_uan6vIB7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_899dCYGS, 0, m, &cIf_899dCYGS_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cCast_c3Mwp4Ae_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_lKx5SvJV_sendMessage);
}

void Heavy_PhaseRing::cBinop_dYzXVGuk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Tky2vR8S, 1, m, &cIf_Tky2vR8S_sendMessage);
}

void Heavy_PhaseRing::cMsg_eT05Xfs4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_RVOrQXuy, 1, m, &cVar_RVOrQXuy_sendMessage);
}

void Heavy_PhaseRing::cPack_hmWBbNn7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Tky2vR8S, 0, m, &cIf_Tky2vR8S_sendMessage);
}

void Heavy_PhaseRing::cIf_eOKUIqlV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_KJ32jbcx, 2, m, &cPack_KJ32jbcx_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_hmWBbNn7, 1, m, &cPack_hmWBbNn7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_lKx5SvJV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_899dCYGS, 1, m, &cIf_899dCYGS_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_eOKUIqlV, 1, m, &cIf_eOKUIqlV_sendMessage);
}

void Heavy_PhaseRing::cSlice_iep9NulX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_svZJianT_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KMy9GpdV_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8K9NIuUt_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_rPJtY3Av_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_eT05Xfs4_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cCast_svZJianT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RVOrQXuy, 0, m, &cVar_RVOrQXuy_sendMessage);
}

void Heavy_PhaseRing::cBinop_v5HeQKNL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_B8wk0zVr, 1, m, &cVar_B8wk0zVr_sendMessage);
}

void Heavy_PhaseRing::cReceive_oW5fYvH2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_RD3TA3ay_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_lF5sp862, 0, m, &cVar_lF5sp862_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_7AyEZaBn_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_c1HtEdxq, 0, m, &cSlice_c1HtEdxq_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_a1fhRjgA, 0, m, &cRandom_a1fhRjgA_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_NfQZvcVn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_sqMYdqc0_sendMessage);
}

void Heavy_PhaseRing::cRandom_a1fhRjgA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 900.0f, 0, m, &cBinop_NfQZvcVn_sendMessage);
}

void Heavy_PhaseRing::cSlice_c1HtEdxq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_a1fhRjgA, 1, m, &cRandom_a1fhRjgA_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cUnop_sqMYdqc0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 50.0f, 0, m, &cBinop_BwFkibjw_sendMessage);
}

void Heavy_PhaseRing::cReceive_psluHfVQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Eut0jGmw_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jfIzGcEn_sendMessage);
}

void Heavy_PhaseRing::cReceive_qGYudbvd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_7vnpFwWQ, 0, m, &cPack_7vnpFwWQ_sendMessage);
}

void Heavy_PhaseRing::cReceive_qnDRqHnS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2mK0yV9t_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oPTmTd9l_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_T02v7nQ9, 0, m, &cPack_T02v7nQ9_sendMessage);
}

void Heavy_PhaseRing::cMsg_09qvXUtI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_1ZKqbXHh_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_1ZKqbXHh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_rnZmDjgm_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_6jAZbt2l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_TZe0Xq0A_sendMessage);
}

void Heavy_PhaseRing::cCast_9Tv1LgJm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSlice_GHZlDtTM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_lENHFwfO_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_I6lVVRIC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZaFBbkEN_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_txbvRkCZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_SyzwJLFE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_tJX4MQRi, 1, m, &cRandom_tJX4MQRi_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cUnop_hN4KpLnc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ipuSaE7h_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_htQtLxlX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_SyzwJLFE, 0, m, &cSlice_SyzwJLFE_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_tJX4MQRi, 0, m, &cRandom_tJX4MQRi_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_oV3VlpYU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_hN4KpLnc_sendMessage);
}

void Heavy_PhaseRing::cRandom_tJX4MQRi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_oV3VlpYU_sendMessage);
}

void Heavy_PhaseRing::cSend_9hSlCGMu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9pCuWkDN_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cRandom_GCrMQcUE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_M9Ko9qZd_sendMessage);
}

void Heavy_PhaseRing::cBinop_M9Ko9qZd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_MF9B2Ugd_sendMessage);
}

void Heavy_PhaseRing::cUnop_MF9B2Ugd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_QY0UbdAb_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_O56yWMaQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ovoxmz8y, 0, m, &cSlice_ovoxmz8y_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_GCrMQcUE, 0, m, &cRandom_GCrMQcUE_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cSlice_ovoxmz8y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_GCrMQcUE, 1, m, &cRandom_GCrMQcUE_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_SSzBTeHO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mRORqICk, HV_BINOP_POW, 1, m, &cBinop_mRORqICk_sendMessage);
  cMsg_dDu29jSQ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_dDu29jSQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_mRORqICk, HV_BINOP_POW, 0, m, &cBinop_mRORqICk_sendMessage);
}

void Heavy_PhaseRing::cBinop_mRORqICk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_r6xA7dxb_sendMessage);
}

void Heavy_PhaseRing::cBinop_r6xA7dxb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kXzfYu3E, HV_BINOP_MULTIPLY, 0, m, &cBinop_kXzfYu3E_sendMessage);
}

void Heavy_PhaseRing::cBinop_txbvRkCZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_SSzBTeHO_sendMessage);
}

void Heavy_PhaseRing::cCast_7GQC9IHU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_BuPOSOsb_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_7GaOmHfc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dpiVn9og, 1, m, &cVar_dpiVn9og_sendMessage);
}

void Heavy_PhaseRing::cCast_7GnpMUma_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ahP5nvHe_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_B9ckPcS7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_izyMlUoP, 0, m, &cVar_izyMlUoP_sendMessage);
}

void Heavy_PhaseRing::cSend_DusEsVqB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_HmrFwopm_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_VREHNS77_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_QEculenM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_UXC71nrx_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_RD3TA3ay_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_UXC71nrx_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_dpiVn9og_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cIhczkdU_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_ahP5nvHe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_0wUxw68T, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_lF5sp862_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cMsg_cIhczkdU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_0wUxw68T, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_izyMlUoP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7GnpMUma_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7GaOmHfc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7GQC9IHU_sendMessage);
}

void Heavy_PhaseRing::cMsg_ednbj8Hb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_utN4bFnH_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_et2BmXfG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_QEculenM_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_B8O8L9sI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_l1V304Fe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_HmrFwopm_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_lstABI0x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_l1V304Fe_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_qmEe7gUE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSwitchcase_BuPOSOsb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_yavFzGBw_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_yavFzGBw_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_U6Cak3ak, 1, m, &cDelay_U6Cak3ak_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qzGAhwZb_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_U6Cak3ak_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_U6Cak3ak, m);
  cVar_onMessage(_c, &Context(_c)->cVar_dpiVn9og, 0, m, &cVar_dpiVn9og_sendMessage);
}

void Heavy_PhaseRing::cCast_qzGAhwZb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_U6Cak3ak, 0, m, &cDelay_U6Cak3ak_sendMessage);
}

void Heavy_PhaseRing::cMsg_yavFzGBw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_U6Cak3ak, 0, m, &cDelay_U6Cak3ak_sendMessage);
}

void Heavy_PhaseRing::cSend_utN4bFnH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cCast_mRyhIqQk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_OV0SgqMi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_oW5fYvH2_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_QY0UbdAb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_jLygAK47_sendMessage);
}

void Heavy_PhaseRing::cBinop_TZe0Xq0A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_aYZNOk2j, 0, m, &cPack_aYZNOk2j_sendMessage);
}

void Heavy_PhaseRing::cCast_TkixvxJ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_O56yWMaQ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_ZaFBbkEN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_htQtLxlX_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_aYZNOk2j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_MFtpy3Td, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_V8ct3CB6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_aaSixRuE, 0, m);
}

void Heavy_PhaseRing::cBinop_ipuSaE7h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_xaUcP9MD_sendMessage);
}

void Heavy_PhaseRing::cBinop_jLygAK47_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_sqjYeSmK_sendMessage);
}

void Heavy_PhaseRing::cBinop_kXzfYu3E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uVGeLF0I_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TkixvxJ8_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_AfeRKpIe, 0, m, &cVar_AfeRKpIe_sendMessage);
}

void Heavy_PhaseRing::cVar_AfeRKpIe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_0NxYHC5c, 0, m);
}

void Heavy_PhaseRing::cBinop_lENHFwfO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_OV0SgqMi_sendMessage(_c, 0, m);
  cSend_9hSlCGMu_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_uVGeLF0I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_B9ckPcS7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9Tv1LgJm_sendMessage);
}

void Heavy_PhaseRing::cMsg_90UkU0ro_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_sqjYeSmK_sendMessage);
}

void Heavy_PhaseRing::cPack_9Rs22VvO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_ujZTpKFI, 0, m, NULL);
}

void Heavy_PhaseRing::cUnop_lDgSXVzJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_9Rs22VvO, 0, m, &cPack_9Rs22VvO_sendMessage);
}

void Heavy_PhaseRing::cUnop_SqFaCkpw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_bpL6axXX, 0, m, &cPack_bpL6axXX_sendMessage);
}

void Heavy_PhaseRing::cPack_bpL6axXX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_LjfijJlA, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_sqjYeSmK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_SqFaCkpw_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_lDgSXVzJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_xaUcP9MD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kXzfYu3E, HV_BINOP_MULTIPLY, 1, m, &cBinop_kXzfYu3E_sendMessage);
}

void Heavy_PhaseRing::cReceive_rnZmDjgm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_DusEsVqB_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VREHNS77, 0, m, &cVar_VREHNS77_sendMessage);
}

void Heavy_PhaseRing::cReceive_vfLLOk7l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_tU0bMIR3_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_USN2S3rY, 0, m, &cVar_USN2S3rY_sendMessage);
}

void Heavy_PhaseRing::cReceive_wA9IjUay_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_76N9iLF6_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2PZMYttX_sendMessage);
}

void Heavy_PhaseRing::cReceive_y6IcNk58_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aYEBZH6C_sendMessage);
}

void Heavy_PhaseRing::cReceive_yRjwNjQN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_7vnpFwWQ, 1, m, &cPack_7vnpFwWQ_sendMessage);
}

void Heavy_PhaseRing::cBinop_1qFXhGx3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_cdnqXVYS_sendMessage);
}

void Heavy_PhaseRing::cBinop_3JRf1TQP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_yJOjuJ77_sendMessage);
}

void Heavy_PhaseRing::cSend_3cn4XT2x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_vfLLOk7l_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSlice_mAE5DoaE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_HLKBy9vj_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_nOyokf8c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VonJiSbe_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_IwrSG83b_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSend_5ONQQ3Z7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_TRY8bBhd_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_jjcyPKhQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_wblYp4M8, 0, m);
}

void Heavy_PhaseRing::cSend_H4ZFS6qP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_XvEdNmLJ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_HLKBy9vj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_3cn4XT2x_sendMessage(_c, 0, m);
  cSend_5ONQQ3Z7_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_JLE9Gnum_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_H4ZFS6qP_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_JSLpJ3mH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Q08XYhLX, 0, m, &cPack_Q08XYhLX_sendMessage);
}

void Heavy_PhaseRing::cPack_Q08XYhLX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_GqJTzMCA, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_O0ifSzPL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_JSLpJ3mH_sendMessage);
}

void Heavy_PhaseRing::cCast_VonJiSbe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_zmMSVCwk_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_GkyoYgi9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_zay33Qzk_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_RmkxJ1wT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ty5cN7vu, 0, m, &cSlice_ty5cN7vu_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_hPfhognO, 0, m, &cRandom_hPfhognO_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cRandom_hPfhognO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_GkyoYgi9_sendMessage);
}

void Heavy_PhaseRing::cSlice_ty5cN7vu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_hPfhognO, 1, m, &cRandom_hPfhognO_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cUnop_zay33Qzk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_sLxNrGYD_sendMessage);
}

void Heavy_PhaseRing::cCast_b9nCEUjy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_RmkxJ1wT_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_cdnqXVYS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jwCjPNLR, HV_BINOP_MULTIPLY, 1, m, &cBinop_jwCjPNLR_sendMessage);
}

void Heavy_PhaseRing::cVar_XXe4aOsj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_YLhzpjc3, 0, m);
}

void Heavy_PhaseRing::cPack_1xlBOZaL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_gtfOXynq, 0, m, NULL);
}

void Heavy_PhaseRing::cUnop_BtuNU6mv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_1xlBOZaL, 0, m, &cPack_1xlBOZaL_sendMessage);
}

void Heavy_PhaseRing::cUnop_gfJZCiga_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_fgINsVdp, 0, m, &cPack_fgINsVdp_sendMessage);
}

void Heavy_PhaseRing::cMsg_DdiPD7yC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_yJOjuJ77_sendMessage);
}

void Heavy_PhaseRing::cPack_fgINsVdp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_CzagagvU, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_yJOjuJ77_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_BtuNU6mv_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_gfJZCiga_sendMessage);
}

void Heavy_PhaseRing::cSend_2T2XUMBf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cMsg_48SBJYG2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_VrB8ARAH_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_4TNTyrIf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_PcmCnHRn, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_9nOi7YA2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4TNTyrIf_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_Bt5rB8Xe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_CwOYbibd_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_CwOYbibd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_MSUiSskw_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_6PgH2iT3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_USN2S3rY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cMsg_I6ZLVnbP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_PcmCnHRn, 0, m, NULL);
}

void Heavy_PhaseRing::cSend_KMq9q8yJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cCast_Nj7Lw63A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nh8kiC62, 1, m, &cVar_nh8kiC62_sendMessage);
}

void Heavy_PhaseRing::cVar_CuLuBKX3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9nOi7YA2_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Nj7Lw63A_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TxsY5KDN_sendMessage);
}

void Heavy_PhaseRing::cCast_TxsY5KDN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_2bFsjH2O_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSend_VrB8ARAH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_GRC2Y3gO_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_Z55xr7wA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_2T2XUMBf_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_34mrsk6l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_nh8kiC62_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_I6ZLVnbP_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_p3rXESzs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CuLuBKX3, 0, m, &cVar_CuLuBKX3_sendMessage);
}

void Heavy_PhaseRing::cSend_prgk3mYa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_MSUiSskw_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_2bFsjH2O_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_Zc4PZoDI_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_Zc4PZoDI_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_RUex5Z1m, 1, m, &cDelay_RUex5Z1m_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eZhL58XS_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_RUex5Z1m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RUex5Z1m, m);
  cVar_onMessage(_c, &Context(_c)->cVar_nh8kiC62, 0, m, &cVar_nh8kiC62_sendMessage);
}

void Heavy_PhaseRing::cMsg_Zc4PZoDI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_RUex5Z1m, 0, m, &cDelay_RUex5Z1m_sendMessage);
}

void Heavy_PhaseRing::cCast_eZhL58XS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_RUex5Z1m, 0, m, &cDelay_RUex5Z1m_sendMessage);
}

void Heavy_PhaseRing::cSend_tU0bMIR3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_GRC2Y3gO_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_DVPkcmop_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cCast_NDKXqLAc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cBinop_jwCjPNLR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xWtsXNRW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_b9nCEUjy_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_jjcyPKhQ, 0, m, &cVar_jjcyPKhQ_sendMessage);
}

void Heavy_PhaseRing::cSlice_D5Ii3GbG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_hx3o5pIP, 1, m, &cRandom_hx3o5pIP_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cUnop_NpizS3ct_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_1qFXhGx3_sendMessage);
}

void Heavy_PhaseRing::cBinop_Vh4u8kX4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_NpizS3ct_sendMessage);
}

void Heavy_PhaseRing::cRandom_hx3o5pIP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_Vh4u8kX4_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_zmMSVCwk_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_D5Ii3GbG, 0, m, &cSlice_D5Ii3GbG_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_hx3o5pIP, 0, m, &cRandom_hx3o5pIP_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_sLxNrGYD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_3JRf1TQP_sendMessage);
}

void Heavy_PhaseRing::cBinop_IwrSG83b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_ZXmNHalA_sendMessage);
}

void Heavy_PhaseRing::cBinop_ZXmNHalA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zfE6ydR4, HV_BINOP_POW, 1, m, &cBinop_zfE6ydR4_sendMessage);
  cMsg_dU4OaLNw_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_dU4OaLNw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zfE6ydR4, HV_BINOP_POW, 0, m, &cBinop_zfE6ydR4_sendMessage);
}

void Heavy_PhaseRing::cBinop_jSDZxOTT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jwCjPNLR, HV_BINOP_MULTIPLY, 0, m, &cBinop_jwCjPNLR_sendMessage);
}

void Heavy_PhaseRing::cBinop_zfE6ydR4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_jSDZxOTT_sendMessage);
}

void Heavy_PhaseRing::cCast_xWtsXNRW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_p3rXESzs_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NDKXqLAc_sendMessage);
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
    __hv_phasor_k_f(&sPhasor_YLhzpjc3, VOf(Bf0));
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
    __hv_line_f(&sLine_GqJTzMCA, VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_wblYp4M8, VOf(Bf0));
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
    __hv_line_f(&sLine_PcmCnHRn, VOf(Bf5));
    __hv_varread_f(&sVarf_LqSJYykp, VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_gtfOXynq, VOf(Bf6));
    __hv_mul_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_CzagagvU, VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_phasor_k_f(&sPhasor_aaSixRuE, VOf(Bf3));
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
    __hv_line_f(&sLine_MFtpy3Td, VOf(Bf4));
    __hv_phasor_k_f(&sPhasor_0NxYHC5c, VOf(Bf3));
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
    __hv_line_f(&sLine_0wUxw68T, VOf(Bf1));
    __hv_varread_f(&sVarf_JsRzMHWd, VOf(Bf4));
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_LjfijJlA, VOf(Bf8));
    __hv_mul_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_ujZTpKFI, VOf(Bf1));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_phasor_k_f(&sPhasor_nCjkyaID, VOf(Bf6));
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
    __hv_line_f(&sLine_V2J7zuro, VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_Qrl4iP6g, VOf(Bf6));
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
    __hv_line_f(&sLine_1nlmdvZ2, VOf(Bf3));
    __hv_varread_f(&sVarf_6tKya33I, VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_B2v4PPDh, VOf(Bf7));
    __hv_mul_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_hJdquvdC, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_R9h1RyvC, VOf(Bf8));
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
    __hv_line_f(&sLine_9LoRcshy, VOf(Bf9));
    __hv_phasor_k_f(&sPhasor_eucO49s8, VOf(Bf8));
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
    __hv_line_f(&sLine_eHhhUdhj, VOf(Bf6));
    __hv_varread_f(&sVarf_ZmzdwXRG, VOf(Bf9));
    __hv_mul_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_b7IljXY7, VOf(Bf4));
    __hv_mul_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_PEXfcDRT, VOf(Bf6));
    __hv_mul_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_Iz6tpKSf, VOf(Bf7));
    __hv_mul_f(VIf(Bf4), VIf(Bf7), VOf(Bf4));
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_PGc5Wu08, VOf(Bf6));
    __hv_phasor_f(&sPhasor_Lh3wPkwN, VIf(Bf6), VOf(Bf6));
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
    __hv_var_k_f(VOf(Bf3), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf9), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf5), VIf(Bf9), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf6), VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_EIuT2fqi, VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_KNRXTitf, VOf(Bf6));
    __hv_fma_f(VIf(Bf1), VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_floor_f(VIf(Bf6), VOf(Bf3));
    __hv_sub_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf6), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf3));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf3), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf11), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf10), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf0), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf9), VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf10), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf3), VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_nxs8Ef8l, VOf(Bf11));
    __hv_mul_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_6mMfceYq, VOf(Bf10));
    __hv_mul_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_NsY2i96y, VOf(Bf11));
    __hv_rpole_f(&sRPole_M5jnanQR, VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf10), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_RSjZwAcN, VIf(Bf11), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_eiAtJAV7, VOf(Bf11));
    __hv_mul_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_7DBxaSxZ, VOf(Bf10));
    __hv_mul_f(VIf(Bf11), VIf(Bf10), VOf(Bf3));
    __hv_mul_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf4), VIf(Bf3), VOf(Bf4));
    __hv_add_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_MY97fxBV, VOf(Bf11));
    __hv_mul_f(VIf(Bf10), VIf(Bf11), VOf(Bf10));
    __hv_mul_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_GjTjo5pj, VOf(Bf7));
    __hv_mul_f(VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_tabread_f(&sTabread_IVZ00RuP, VOf(Bf3));
    __hv_varread_f(&sVarf_e1PsRhKq, VOf(Bf4));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_C6AFUrsM, VOf(Bf0));
    __hv_rpole_f(&sRPole_LRBRWwfa, VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf0), VIf(Bf3), VOf(Bf0));
    __hv_line_f(&sLine_H1s5jzQD, VOf(Bf4));
    __hv_fma_f(VIf(Bf0), VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_8GD4kDMx, VOf(Bf0));
    __hv_tabread_f(&sTabread_Eujxg9NG, VOf(Bf5));
    __hv_sub_f(VIf(Bf7), VIf(Bf5), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_YYvPKbAc, VIf(Bf9));
    __hv_add_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_tabread_f(&sTabread_H5ZWsx5N, VOf(Bf9));
    __hv_add_f(VIf(Bf5), VIf(Bf9), VOf(Bf6));
    __hv_tabread_f(&sTabread_kFx6KNgb, VOf(Bf1));
    __hv_add_f(VIf(Bf6), VIf(Bf1), VOf(Bf8));
    __hv_tabread_f(&sTabread_ke43D03b, VOf(Bf2));
    __hv_add_f(VIf(Bf8), VIf(Bf2), VOf(Bf12));
    __hv_tabread_f(&sTabread_XMB3MeyH, VOf(Bf13));
    __hv_sub_f(VIf(Bf12), VIf(Bf13), VOf(Bf14));
    __hv_tabwrite_f(&sTabwrite_bBhvLuhR, VIf(Bf14));
    __hv_sub_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_tabwrite_f(&sTabwrite_D30L1fhK, VIf(Bf1));
    __hv_sub_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_WhmeSAUN, VIf(Bf2));
    __hv_add_f(VIf(Bf12), VIf(Bf13), VOf(Bf13));
    __hv_tabwrite_f(&sTabwrite_opmtYadB, VIf(Bf7));
    __hv_sub_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_rq9uXTGZ, VIf(Bf9));
    __hv_tabread_f(&sTabread_RxgBrKLe, VOf(Bf9));
    __hv_fma_f(VIf(Bf3), VIf(Bf0), VIf(Bf13), VOf(Bf13));
    __hv_tabread_f(&sTabread_u6b8GX5M, VOf(Bf3));
    __hv_varread_f(&sVarf_kU0eP2xM, VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_e1Ej1zl2, VOf(Bf12));
    __hv_rpole_f(&sRPole_PUzoATNx, VIf(Bf5), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf12), VIf(Bf3), VOf(Bf12));
    __hv_fma_f(VIf(Bf12), VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf3), VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf13), VIf(Bf9), VOf(Bf3));
    __hv_tabread_f(&sTabread_uyFzNHzc, VOf(Bf12));
    __hv_varread_f(&sVarf_GGMNXada, VOf(Bf5));
    __hv_mul_f(VIf(Bf12), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_BQdvT4G6, VOf(Bf2));
    __hv_rpole_f(&sRPole_qgDBunIy, VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf2), VIf(Bf12), VOf(Bf2));
    __hv_fma_f(VIf(Bf2), VIf(Bf4), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf0), VOf(Bf12));
    __hv_tabread_f(&sTabread_X44L1rbi, VOf(Bf2));
    __hv_varread_f(&sVarf_Al05hapz, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_TI4E0lh3, VOf(Bf8));
    __hv_rpole_f(&sRPole_L7IsPDDg, VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf8), VIf(Bf2), VOf(Bf8));
    __hv_fma_f(VIf(Bf8), VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf12), VIf(Bf0), VOf(Bf2));
    __hv_sub_f(VIf(Bf3), VIf(Bf2), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_d43dxlgp, VIf(Bf4));
    __hv_line_f(&sLine_ctBqfGM8, VOf(Bf4));
    __hv_mul_f(VIf(Bf13), VIf(Bf4), VOf(Bf8));
    __hv_mul_f(VIf(Bf0), VIf(Bf4), VOf(Bf5));
    __hv_mul_f(VIf(Bf9), VIf(Bf4), VOf(Bf1));
    __hv_sub_f(VIf(Bf13), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf12), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf9), VIf(Bf0), VOf(Bf13));
    __hv_tabwrite_f(&sTabwrite_tl96AJr6, VIf(Bf13));
    __hv_mul_f(VIf(Bf12), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_aBIvBVzR, VIf(Bf2));
    __hv_add_f(VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_He9AEVtp, VIf(Bf0));
    __hv_line_f(&sLine_18onNJj2, VOf(Bf5));
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf4), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_RKxwGm7M, VIf(Bf4));
    __hv_line_f(&sLine_mpNzjmv6, VOf(Bf5));
    __hv_phasor_f(&sPhasor_QfiTVqux, VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf9), VOf(Bf0));
    __hv_sub_f(VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_abs_f(VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf9), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf9), VOf(Bf0));
    __hv_mul_f(VIf(Bf9), VIf(Bf0), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf13), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf6), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf14), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf2), VIf(Bf14), VOf(Bf14));
    __hv_sub_f(VIf(Bf9), VIf(Bf14), VOf(Bf14));
    __hv_fma_f(VIf(Bf3), VIf(Bf6), VIf(Bf14), VOf(Bf14));
    __hv_var_k_f(VOf(Bf6), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf12), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf0), VIf(Bf13), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_SU16ZDGV, VOf(Bf13));
    __hv_line_f(&sLine_acy883LG, VOf(Bf0));
    __hv_fma_f(VIf(Bf5), VIf(Bf13), VIf(Bf0), VOf(Bf14));
    __hv_tabhead_f(&sTabhead_Ln83sILq, VOf(Bf12));
    __hv_var_k_f_r(VOf(Bf3), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_9MAvnJZr, VOf(Bf12));
    __hv_mul_f(VIf(Bf14), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_x0YG7uKC, VOf(Bf14));
    __hv_min_f(VIf(Bf12), VIf(Bf14), VOf(Bf14));
    __hv_zero_f(VOf(Bf12));
    __hv_max_f(VIf(Bf14), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_floor_f(VIf(Bf12), VOf(Bf3));
    __hv_varread_f(&sVarf_ICOjh6aN, VOf(Bf14));
    __hv_zero_f(VOf(Bf9));
    __hv_lt_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_and_f(VIf(Bf14), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_cast_fi(VIf(Bf9), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_mEwwSNW6, VIi(Bi1), VOf(Bf9));
    __hv_tabread_if(&sTabread_QFAlJ2Jg, VIi(Bi0), VOf(Bf14));
    __hv_sub_f(VIf(Bf9), VIf(Bf14), VOf(Bf9));
    __hv_sub_f(VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf9), VIf(Bf3), VIf(Bf14), VOf(Bf14));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf9), VOf(Bf3));
    __hv_sub_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_abs_f(VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf9), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf9), VOf(Bf3));
    __hv_mul_f(VIf(Bf9), VIf(Bf3), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf3), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf15));
    __hv_mul_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf16), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf17), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf18), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf12), VIf(Bf18), VOf(Bf18));
    __hv_sub_f(VIf(Bf9), VIf(Bf18), VOf(Bf18));
    __hv_fma_f(VIf(Bf2), VIf(Bf17), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf17), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf15), VIf(Bf17), VOf(Bf17));
    __hv_sub_f(VIf(Bf18), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf3), VIf(Bf16), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf5), VIf(Bf13), VIf(Bf0), VOf(Bf0));
    __hv_tabhead_f(&sTabhead_gN9JQH6K, VOf(Bf13));
    __hv_var_k_f_r(VOf(Bf5), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf13), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_2xUpWFOi, VOf(Bf13));
    __hv_mul_f(VIf(Bf0), VIf(Bf13), VOf(Bf13));
    __hv_varread_f(&sVarf_P2rfj2uf, VOf(Bf0));
    __hv_min_f(VIf(Bf13), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf13));
    __hv_max_f(VIf(Bf0), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf5), VIf(Bf13), VOf(Bf13));
    __hv_floor_f(VIf(Bf13), VOf(Bf5));
    __hv_varread_f(&sVarf_7IIeHIti, VOf(Bf0));
    __hv_zero_f(VOf(Bf16));
    __hv_lt_f(VIf(Bf5), VIf(Bf16), VOf(Bf16));
    __hv_and_f(VIf(Bf0), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf5), VIf(Bf16), VOf(Bf16));
    __hv_cast_fi(VIf(Bf16), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_cO7fR11o, VIi(Bi1), VOf(Bf16));
    __hv_tabread_if(&sTabread_PFaAMno9, VIi(Bi0), VOf(Bf0));
    __hv_sub_f(VIf(Bf16), VIf(Bf0), VOf(Bf16));
    __hv_sub_f(VIf(Bf13), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf16), VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf6), VIf(Bf14), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_JQgYV19Q, VOf(Bf14));
    __hv_varread_f(&sVarf_jh9kKfih, VOf(Bf6));
    __hv_tabhead_f(&sTabhead_XQwIPWwy, VOf(Bf17));
    __hv_var_k_f_r(VOf(Bf5), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_rSZruvN3, VOf(Bf17));
    __hv_mul_f(VIf(Bf6), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_3e28mQa2, VOf(Bf6));
    __hv_min_f(VIf(Bf17), VIf(Bf6), VOf(Bf6));
    __hv_zero_f(VOf(Bf17));
    __hv_max_f(VIf(Bf6), VIf(Bf17), VOf(Bf17));
    __hv_sub_f(VIf(Bf5), VIf(Bf17), VOf(Bf17));
    __hv_floor_f(VIf(Bf17), VOf(Bf5));
    __hv_varread_f(&sVarf_sucPMcJm, VOf(Bf6));
    __hv_zero_f(VOf(Bf16));
    __hv_lt_f(VIf(Bf5), VIf(Bf16), VOf(Bf16));
    __hv_and_f(VIf(Bf6), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf5), VIf(Bf16), VOf(Bf16));
    __hv_cast_fi(VIf(Bf16), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_TIybe00l, VIi(Bi1), VOf(Bf16));
    __hv_tabread_if(&sTabread_ydlCFgWu, VIi(Bi0), VOf(Bf6));
    __hv_sub_f(VIf(Bf16), VIf(Bf6), VOf(Bf16));
    __hv_sub_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf16), VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_M29kU6Ow, VOf(Bf5));
    __hv_rpole_f(&sRPole_BchMQ7z3, VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_Vb62tRPH, VIf(Bf5), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_p26kg6N6, VOf(Bf5));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_JPi9YWMY, VOf(Bf6));
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_9Mx8pfod, VOf(Bf5));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_7NwAu0fS, VOf(Bf16));
    __hv_rpole_f(&sRPole_7slGirqZ, VIf(Bf5), VIf(Bf16), VOf(Bf16));
    __hv_fma_f(VIf(Bf0), VIf(Bf14), VIf(Bf16), VOf(Bf16));
    __hv_tabwrite_f(&sTabwrite_oqOZrV6L, VIf(Bf16));
    __hv_add_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_rJYLNPto, VOf(Bf6));
    __hv_varread_f(&sVarf_1d3SEdZJ, VOf(Bf0));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf6), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_LqC25vyA, VOf(Bf0));
    __hv_min_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_S6V2pqU1, VOf(Bf16));
    __hv_mul_f(VIf(Bf0), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf4), VIf(Bf16), VOf(Bf4));
    __hv_varread_f(&sVarf_ivtoCaaK, VOf(Bf0));
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf16), VIf(Bf4), VOf(Bf16));
    __hv_cos_f(VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf16), VIf(Bf6), VOf(Bf14));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_zero_f(VOf(Bf4));
    __hv_gt_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_sqrt_f(VIf(Bf6), VOf(Bf6));
    __hv_and_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf16), VIf(Bf6), VOf(Bf6));
    __hv_cpole_f(&sCPole_bIrObFVg, VIf(Bf0), VIf(ZERO), VIf(Bf14), VIf(Bf6), VOf(Bf6), VOf(Bf14));
    __hv_varread_f(&sVarf_L0gANi0M, VOf(Bf14));
    __hv_mul_f(VIf(Bf6), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_i8SKQmQs, VOf(Bf6));
    __hv_rpole_f(&sRPole_u7W1CXIK, VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_SaBDUhQk, VOf(Bf14));
    __hv_mul_f(VIf(Bf6), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_lGSq1CVg, VOf(Bf6));
    __hv_rpole_f(&sRPole_gQe5I4Lp, VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_FOWYkAfr, VOf(Bf14));
    __hv_mul_f(VIf(Bf6), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_JjPn5IOz, VOf(Bf6));
    __hv_rpole_f(&sRPole_V7h82KBc, VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_tabread_f(&sTabread_RQZ3wiSK, VOf(Bf14));
    __hv_varread_f(&sVarf_feZCPZrm, VOf(Bf0));
    __hv_mul_f(VIf(Bf14), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_rPo0atmS, VOf(Bf16));
    __hv_rpole_f(&sRPole_5Jlf3VuJ, VIf(Bf0), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf16), VIf(Bf14), VOf(Bf16));
    __hv_line_f(&sLine_omlztVwW, VOf(Bf0));
    __hv_fma_f(VIf(Bf16), VIf(Bf0), VIf(Bf14), VOf(Bf14));
    __hv_line_f(&sLine_gbFnM2vA, VOf(Bf16));
    __hv_tabread_f(&sTabread_eb8bh5Tb, VOf(Bf4));
    __hv_add_f(VIf(Bf6), VIf(Bf4), VOf(Bf5));
    __hv_tabread_f(&sTabread_OhUPHtZ3, VOf(Bf17));
    __hv_sub_f(VIf(Bf5), VIf(Bf17), VOf(Bf13));
    __hv_tabwrite_f(&sTabwrite_p3r4FpeY, VIf(Bf13));
    __hv_tabread_f(&sTabread_C5jO4OKu, VOf(Bf13));
    __hv_sub_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_vIRt3Yqw, VIf(Bf4));
    __hv_tabwrite_f(&sTabwrite_uZ2TRHXw, VIf(Bf6));
    __hv_add_f(VIf(Bf5), VIf(Bf17), VOf(Bf17));
    __hv_tabread_f(&sTabread_e97hKh4b, VOf(Bf5));
    __hv_sub_f(VIf(Bf17), VIf(Bf5), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_FK7ZY9Zc, VIf(Bf4));
    __hv_add_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_tabread_f(&sTabread_nnUdHZyE, VOf(Bf17));
    __hv_add_f(VIf(Bf5), VIf(Bf17), VOf(Bf4));
    __hv_tabread_f(&sTabread_EdSrWJPJ, VOf(Bf3));
    __hv_add_f(VIf(Bf4), VIf(Bf3), VOf(Bf18));
    __hv_sub_f(VIf(Bf5), VIf(Bf17), VOf(Bf17));
    __hv_tabwrite_f(&sTabwrite_iTQ4HjJE, VIf(Bf17));
    __hv_sub_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_LGgBdvgv, VIf(Bf3));
    __hv_fma_f(VIf(Bf14), VIf(Bf16), VIf(Bf18), VOf(Bf18));
    __hv_tabread_f(&sTabread_82O8wVlI, VOf(Bf14));
    __hv_varread_f(&sVarf_ViC9Xs9H, VOf(Bf3));
    __hv_mul_f(VIf(Bf14), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_E5XOmBsT, VOf(Bf4));
    __hv_rpole_f(&sRPole_B7lzNCrH, VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf4), VIf(Bf14), VOf(Bf4));
    __hv_fma_f(VIf(Bf4), VIf(Bf0), VIf(Bf14), VOf(Bf14));
    __hv_fma_f(VIf(Bf14), VIf(Bf16), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf18), VIf(Bf13), VOf(Bf14));
    __hv_tabread_f(&sTabread_u0MX4kT7, VOf(Bf4));
    __hv_varread_f(&sVarf_CbW8VNEK, VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_dsfmIaoo, VOf(Bf17));
    __hv_rpole_f(&sRPole_Pi73Oq4y, VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_sub_f(VIf(Bf17), VIf(Bf4), VOf(Bf17));
    __hv_fma_f(VIf(Bf17), VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf16), VOf(Bf4));
    __hv_tabread_f(&sTabread_ZI44pPse, VOf(Bf17));
    __hv_varread_f(&sVarf_JqiunZdB, VOf(Bf3));
    __hv_mul_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_pfe4rM8M, VOf(Bf5));
    __hv_rpole_f(&sRPole_7v7RRa89, VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf5), VIf(Bf17), VOf(Bf5));
    __hv_fma_f(VIf(Bf5), VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf17), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf4), VIf(Bf16), VOf(Bf17));
    __hv_sub_f(VIf(Bf14), VIf(Bf17), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_IfmKn09V, VIf(Bf0));
    __hv_add_f(VIf(Bf18), VIf(Bf13), VOf(Bf0));
    __hv_add_f(VIf(Bf4), VIf(Bf16), VOf(Bf5));
    __hv_add_f(VIf(Bf0), VIf(Bf5), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_fsg929Ns, VIf(Bf3));
    __hv_line_f(&sLine_vkCreuW5, VOf(Bf3));
    __hv_mul_f(VIf(Bf16), VIf(Bf3), VOf(Bf16));
    __hv_mul_f(VIf(Bf13), VIf(Bf3), VOf(Bf13));
    __hv_mul_f(VIf(Bf18), VIf(Bf3), VOf(Bf18));
    __hv_sub_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_7Nv71mpj, VIf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf14), VIf(Bf17), VOf(Bf17));
    __hv_tabwrite_f(&sTabwrite_5jS6srXY, VIf(Bf17));
    __hv_add_f(VIf(Bf6), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf18), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf8), VIf(Bf6), VOf(Bf8));
    __hv_line_f(&sLine_6Is0wh90, VOf(Bf18));
    __hv_mul_f(VIf(Bf7), VIf(Bf18), VOf(Bf18));
    __hv_tabwrite_f(&sTabwrite_h4VFdmgT, VIf(Bf18));
    __hv_line_f(&sLine_qs88rzqe, VOf(Bf18));
    __hv_phasor_f(&sPhasor_tQkRkM77, VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf18), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf16), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf7), VIf(Bf16), VOf(Bf16));
    __hv_floor_f(VIf(Bf16), VOf(Bf7));
    __hv_sub_f(VIf(Bf16), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf16), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf7), VIf(Bf16), VOf(Bf16));
    __hv_abs_f(VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf16), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf16), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf7), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf16), VOf(Bf7));
    __hv_mul_f(VIf(Bf16), VIf(Bf7), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf7), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf7), VOf(Bf17));
    __hv_mul_f(VIf(Bf17), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf14), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf4), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf5), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf16), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf13), VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf4), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf7), VIf(Bf14), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_VpW71EE8, VOf(Bf14));
    __hv_line_f(&sLine_mWidUMof, VOf(Bf7));
    __hv_fma_f(VIf(Bf18), VIf(Bf14), VIf(Bf7), VOf(Bf5));
    __hv_tabhead_f(&sTabhead_0dsQpGnI, VOf(Bf17));
    __hv_var_k_f_r(VOf(Bf13), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf17), VIf(Bf13), VOf(Bf13));
    __hv_varread_f(&sVarf_hW0ewuZF, VOf(Bf17));
    __hv_mul_f(VIf(Bf5), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_luxKZucm, VOf(Bf5));
    __hv_min_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_zero_f(VOf(Bf17));
    __hv_max_f(VIf(Bf5), VIf(Bf17), VOf(Bf17));
    __hv_sub_f(VIf(Bf13), VIf(Bf17), VOf(Bf17));
    __hv_floor_f(VIf(Bf17), VOf(Bf13));
    __hv_varread_f(&sVarf_FmB6mlpz, VOf(Bf5));
    __hv_zero_f(VOf(Bf16));
    __hv_lt_f(VIf(Bf13), VIf(Bf16), VOf(Bf16));
    __hv_and_f(VIf(Bf5), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf13), VIf(Bf16), VOf(Bf16));
    __hv_cast_fi(VIf(Bf16), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_dLS78BCo, VIi(Bi1), VOf(Bf16));
    __hv_tabread_if(&sTabread_vLcb7izi, VIi(Bi0), VOf(Bf5));
    __hv_sub_f(VIf(Bf16), VIf(Bf5), VOf(Bf16));
    __hv_sub_f(VIf(Bf17), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf16), VIf(Bf13), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf13), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf18), VIf(Bf13), VOf(Bf13));
    __hv_floor_f(VIf(Bf13), VOf(Bf18));
    __hv_sub_f(VIf(Bf13), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf13), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf18), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf16), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf13), VIf(Bf16), VOf(Bf16));
    __hv_floor_f(VIf(Bf16), VOf(Bf13));
    __hv_sub_f(VIf(Bf16), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf16), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf13), VIf(Bf16), VOf(Bf16));
    __hv_abs_f(VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf13), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf16), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf16), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf13), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf16), VOf(Bf13));
    __hv_mul_f(VIf(Bf16), VIf(Bf13), VOf(Bf17));
    __hv_mul_f(VIf(Bf17), VIf(Bf13), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf13), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf15), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf2), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf9), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf16), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf2), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf13), VIf(Bf15), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf18), VIf(Bf14), VIf(Bf7), VOf(Bf7));
    __hv_tabhead_f(&sTabhead_ugdcdD7r, VOf(Bf14));
    __hv_var_k_f_r(VOf(Bf18), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf14), VIf(Bf18), VOf(Bf18));
    __hv_varread_f(&sVarf_pmTy7lUW, VOf(Bf14));
    __hv_mul_f(VIf(Bf7), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_a3KXb97M, VOf(Bf7));
    __hv_min_f(VIf(Bf14), VIf(Bf7), VOf(Bf7));
    __hv_zero_f(VOf(Bf14));
    __hv_max_f(VIf(Bf7), VIf(Bf14), VOf(Bf14));
    __hv_sub_f(VIf(Bf18), VIf(Bf14), VOf(Bf14));
    __hv_floor_f(VIf(Bf14), VOf(Bf18));
    __hv_varread_f(&sVarf_R3BZRvfh, VOf(Bf7));
    __hv_zero_f(VOf(Bf15));
    __hv_lt_f(VIf(Bf18), VIf(Bf15), VOf(Bf15));
    __hv_and_f(VIf(Bf7), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf18), VIf(Bf15), VOf(Bf15));
    __hv_cast_fi(VIf(Bf15), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_yWSJk6LL, VIi(Bi1), VOf(Bf15));
    __hv_tabread_if(&sTabread_JkOMGOF1, VIi(Bi0), VOf(Bf7));
    __hv_sub_f(VIf(Bf15), VIf(Bf7), VOf(Bf15));
    __hv_sub_f(VIf(Bf14), VIf(Bf18), VOf(Bf18));
    __hv_fma_f(VIf(Bf15), VIf(Bf18), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf4), VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_Bs3iy6Sp, VOf(Bf5));
    __hv_tabhead_f(&sTabhead_HUh5vLd1, VOf(Bf4));
    __hv_var_k_f_r(VOf(Bf2), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_QzYNScNw, VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_PltB3Fk5, VOf(Bf5));
    __hv_min_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_zero_f(VOf(Bf4));
    __hv_max_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf2));
    __hv_varread_f(&sVarf_bjA8VCxW, VOf(Bf5));
    __hv_zero_f(VOf(Bf18));
    __hv_lt_f(VIf(Bf2), VIf(Bf18), VOf(Bf18));
    __hv_and_f(VIf(Bf5), VIf(Bf18), VOf(Bf18));
    __hv_add_f(VIf(Bf2), VIf(Bf18), VOf(Bf18));
    __hv_cast_fi(VIf(Bf18), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_Nk71rIHa, VIi(Bi1), VOf(Bf18));
    __hv_tabread_if(&sTabread_NXrzbNj7, VIi(Bi0), VOf(Bf5));
    __hv_sub_f(VIf(Bf18), VIf(Bf5), VOf(Bf18));
    __hv_sub_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf18), VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_XIYPjXY5, VOf(Bf2));
    __hv_rpole_f(&sRPole_4IJwIwRB, VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_cD8vYQ1P, VIf(Bf2), VOf(Bf18));
    __hv_mul_f(VIf(Bf18), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_S8KU7ipB, VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_psdgXSjI, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf7), VIf(Bf5), VOf(Bf2));
    __hv_line_f(&sLine_jaBpt9ud, VOf(Bf18));
    __hv_varread_f(&sVarf_0g88X1M5, VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_M5amLB0o, VOf(Bf5));
    __hv_rpole_f(&sRPole_Bc20FFO8, VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf7), VIf(Bf18), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_oOJEOqMN, VIf(Bf5));
    __hv_var_k_f(VOf(Bf5), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf8), VIf(Bf5), VOf(Bf8));
    __hv_add_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_kVQ0MSvK, VOf(Bf6));
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf5));
    __hv_mul_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf11), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf10), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_u6q5iWUE, VOf(Bf10));
    __hv_mul_f(VIf(Bf6), VIf(Bf10), VOf(Bf6));
    __hv_mul_f(VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf10), VIf(O1), VOf(O1));
    __hv_add_f(VIf(Bf6), VIf(O0), VOf(O0));

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

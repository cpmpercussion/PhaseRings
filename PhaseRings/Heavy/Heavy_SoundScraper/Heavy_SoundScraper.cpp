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
  numBytes += sRPole_init(&sRPole_REAcZgxD);
  numBytes += sDel1_init(&sDel1_avNgKOko);
  numBytes += sSamphold_init(&sSamphold_hf0BVFEO);
  numBytes += sDel1_init(&sDel1_RL9EkALw);
  numBytes += sSamphold_init(&sSamphold_TteAZqk8);
  numBytes += sTabread_init(&sTabread_vlLQy8ak, &hTable_7oIywVCj, false);
  numBytes += sTabread_init(&sTabread_FyKFdTX9, &hTable_7oIywVCj, false);
  numBytes += sDel1_init(&sDel1_A5hV73wu);
  numBytes += sSamphold_init(&sSamphold_qxYIEFRl);
  numBytes += sDel1_init(&sDel1_OXmCLyAF);
  numBytes += sSamphold_init(&sSamphold_BLB5TwRn);
  numBytes += sTabread_init(&sTabread_hIGy1oJE, &hTable_7oIywVCj, false);
  numBytes += sTabread_init(&sTabread_kT3lBcar, &hTable_7oIywVCj, false);
  numBytes += sPhasor_k_init(&sPhasor_T8DireCs, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_MufGthIR);
  numBytes += sDel1_init(&sDel1_Zc6uPlfW);
  numBytes += sLine_init(&sLine_eQmLPtLE);
  numBytes += sSample_init(&sSample_qfX4NsAm);
  numBytes += sLine_init(&sLine_nWA9yvBT);
  numBytes += sTabread_init(&sTabread_JJz0K9bS, &hTable_ceQ9QuNA, false);
  numBytes += sTabread_init(&sTabread_yxf0z2nC, &hTable_ceQ9QuNA, false);
  numBytes += sLine_init(&sLine_pQCPywbP);
  numBytes += sLine_init(&sLine_ndtWHWbl);
  numBytes += sLine_init(&sLine_G6aTEmZn);
  numBytes += sLine_init(&sLine_Pde39p7Q);
  numBytes += sLine_init(&sLine_Axs38sYp);
  numBytes += sTabread_init(&sTabread_7mvICwz4, &hTable_7wRHRReH, false);
  numBytes += sTabread_init(&sTabread_Cp63gcdE, &hTable_7wRHRReH, false);
  numBytes += sLine_init(&sLine_xg7MmMDM);
  numBytes += sLine_init(&sLine_syzJTS98);
  numBytes += sLine_init(&sLine_i1ex9pJ7);
  numBytes += sLine_init(&sLine_T6Mlz6Y1);
  numBytes += sLine_init(&sLine_J98fEpZC);
  numBytes += sTabread_init(&sTabread_PWZ9B5X7, &hTable_siO20AT6, false);
  numBytes += sTabread_init(&sTabread_FxOjctYX, &hTable_siO20AT6, false);
  numBytes += sLine_init(&sLine_DrgcZC63);
  numBytes += sLine_init(&sLine_rGxkbxrG);
  numBytes += sLine_init(&sLine_s7IGP6lo);
  numBytes += sLine_init(&sLine_NpAvF5mi);
  numBytes += sLine_init(&sLine_3O2T0Ncj);
  numBytes += sTabread_init(&sTabread_2AsUebY9, &hTable_jMxmuK8G, false);
  numBytes += sTabread_init(&sTabread_ZjauuE5S, &hTable_jMxmuK8G, false);
  numBytes += sLine_init(&sLine_eAlBvMDj);
  numBytes += sLine_init(&sLine_BjQp1kDM);
  numBytes += sLine_init(&sLine_cYlxwKAd);
  numBytes += sLine_init(&sLine_TZ8DWVp5);
  numBytes += sLine_init(&sLine_MssnHypt);
  numBytes += sLine_init(&sLine_PaEhWcRP);
  numBytes += sLine_init(&sLine_PRxRrdbY);
  numBytes += sLine_init(&sLine_x4oiRlkn);
  numBytes += sLine_init(&sLine_p63Cfj8k);
  numBytes += sTabwrite_init(&sTabwrite_4DVarWqT, &hTable_oRoHtg9E);
  numBytes += sLine_init(&sLine_7uXeASB6);
  numBytes += sPhasor_init(&sPhasor_8KsYNpbH, sampleRate);
  numBytes += sLine_init(&sLine_mvZgh5qa);
  numBytes += sLine_init(&sLine_IZW5pwvx);
  numBytes += sTabhead_init(&sTabhead_BZYRnMpg, &hTable_oRoHtg9E);
  numBytes += sTabread_init(&sTabread_s7W01vuN, &hTable_oRoHtg9E, false);
  numBytes += sTabread_init(&sTabread_pqjSVmB0, &hTable_oRoHtg9E, false);
  numBytes += sTabhead_init(&sTabhead_yzKWSgUW, &hTable_oRoHtg9E);
  numBytes += sTabread_init(&sTabread_s3nT7gy6, &hTable_oRoHtg9E, false);
  numBytes += sTabread_init(&sTabread_peDIxRAT, &hTable_oRoHtg9E, false);
  numBytes += sTabhead_init(&sTabhead_SaDABZLJ, &hTable_3s6UTbxa);
  numBytes += sTabread_init(&sTabread_uoQScs8E, &hTable_3s6UTbxa, false);
  numBytes += sTabread_init(&sTabread_XYdqXMwo, &hTable_3s6UTbxa, false);
  numBytes += sRPole_init(&sRPole_rY855utR);
  numBytes += sDel1_init(&sDel1_9SRWdW4j);
  numBytes += sLine_init(&sLine_ElWsOhlv);
  numBytes += sRPole_init(&sRPole_PV2KiYum);
  numBytes += sTabwrite_init(&sTabwrite_RP7IA2je, &hTable_3s6UTbxa);
  numBytes += sTabread_init(&sTabread_LGsOmfpX, &hTable_EfQ3r6vv, true);
  numBytes += sRPole_init(&sRPole_TVXdpm1d);
  numBytes += sLine_init(&sLine_5MJun8Bl);
  numBytes += sLine_init(&sLine_PiBRAEvF);
  numBytes += sTabread_init(&sTabread_6kNivzLP, &hTable_gYNAhlyb, true);
  numBytes += sTabread_init(&sTabread_hGu1xi2l, &hTable_j4I5AoYy, true);
  numBytes += sTabread_init(&sTabread_3EAeJgdk, &hTable_Qk4Aw7or, true);
  numBytes += sTabread_init(&sTabread_sCROyNou, &hTable_3hU40Lfe, true);
  numBytes += sTabread_init(&sTabread_NPayNecx, &hTable_d8pDnroX, true);
  numBytes += sTabwrite_init(&sTabwrite_VH2XTCj3, &hTable_XJkV9INz);
  numBytes += sTabwrite_init(&sTabwrite_zIZH708J, &hTable_d8pDnroX);
  numBytes += sTabwrite_init(&sTabwrite_tR4UuY3m, &hTable_3hU40Lfe);
  numBytes += sTabwrite_init(&sTabwrite_QbsSxHTs, &hTable_Qk4Aw7or);
  numBytes += sTabwrite_init(&sTabwrite_m9Hu7Ufg, &hTable_j4I5AoYy);
  numBytes += sTabwrite_init(&sTabwrite_Ne0UkebX, &hTable_gYNAhlyb);
  numBytes += sTabread_init(&sTabread_fti8cOzu, &hTable_XJkV9INz, true);
  numBytes += sTabread_init(&sTabread_qYxCSyOB, &hTable_29SNVBBY, true);
  numBytes += sRPole_init(&sRPole_s7e3w0aj);
  numBytes += sTabread_init(&sTabread_24YroOvM, &hTable_xRTC2smU, true);
  numBytes += sRPole_init(&sRPole_gO6OFOva);
  numBytes += sTabread_init(&sTabread_dBcW5fTF, &hTable_rOK83OZK, true);
  numBytes += sRPole_init(&sRPole_kVZ8FxZB);
  numBytes += sTabwrite_init(&sTabwrite_4smFJoMr, &hTable_EfQ3r6vv);
  numBytes += sTabwrite_init(&sTabwrite_5icomM8V, &hTable_29SNVBBY);
  numBytes += sTabwrite_init(&sTabwrite_9EGvsKhJ, &hTable_xRTC2smU);
  numBytes += sTabwrite_init(&sTabwrite_J5jbD6iy, &hTable_rOK83OZK);
  numBytes += sLine_init(&sLine_s8PbC4XD);
  numBytes += sLine_init(&sLine_E9hKNxIE);
  numBytes += sTabwrite_init(&sTabwrite_jOiTAEpf, &hTable_PLZ3kGJM);
  numBytes += sLine_init(&sLine_vkHwMN4p);
  numBytes += sPhasor_init(&sPhasor_jF0OvVa4, sampleRate);
  numBytes += sLine_init(&sLine_SIcupqdZ);
  numBytes += sLine_init(&sLine_pmOERWvQ);
  numBytes += sTabhead_init(&sTabhead_G1KgJpKX, &hTable_PLZ3kGJM);
  numBytes += sTabread_init(&sTabread_6ytYgQwh, &hTable_PLZ3kGJM, false);
  numBytes += sTabread_init(&sTabread_E4c43C1S, &hTable_PLZ3kGJM, false);
  numBytes += sTabhead_init(&sTabhead_WFXibZey, &hTable_PLZ3kGJM);
  numBytes += sTabread_init(&sTabread_RPmj098s, &hTable_PLZ3kGJM, false);
  numBytes += sTabread_init(&sTabread_moUeHUQI, &hTable_PLZ3kGJM, false);
  numBytes += sTabhead_init(&sTabhead_dzH0u6Xx, &hTable_M3hk39fh);
  numBytes += sTabread_init(&sTabread_DF3ezimX, &hTable_M3hk39fh, false);
  numBytes += sTabread_init(&sTabread_NyGZOKyS, &hTable_M3hk39fh, false);
  numBytes += sRPole_init(&sRPole_JLMV3aYr);
  numBytes += sDel1_init(&sDel1_wKJnijnu);
  numBytes += sLine_init(&sLine_2r9cKhjn);
  numBytes += sRPole_init(&sRPole_XTJXlNXz);
  numBytes += sTabwrite_init(&sTabwrite_dOrcyMDJ, &hTable_M3hk39fh);
  numBytes += sCPole_init(&sCPole_H0z1qwZ0);
  numBytes += sRPole_init(&sRPole_G0ySlggy);
  numBytes += sRPole_init(&sRPole_kjacatx3);
  numBytes += sRPole_init(&sRPole_Wczuv1cu);
  numBytes += sTabread_init(&sTabread_wGHbTAlV, &hTable_81Fwh5Ik, true);
  numBytes += sRPole_init(&sRPole_RAyFq0yv);
  numBytes += sLine_init(&sLine_tOzwtFMn);
  numBytes += sLine_init(&sLine_tgclqmTa);
  numBytes += sTabread_init(&sTabread_GOaCxfn8, &hTable_xFxj5K73, true);
  numBytes += sTabread_init(&sTabread_16qKnAjk, &hTable_uyDJyNjy, true);
  numBytes += sTabread_init(&sTabread_p95TiwPm, &hTable_uhLL7yho, true);
  numBytes += sTabread_init(&sTabread_CbgqKfNV, &hTable_1NYZsr90, true);
  numBytes += sTabread_init(&sTabread_LRFqKfxm, &hTable_f71PlYKv, true);
  numBytes += sTabwrite_init(&sTabwrite_GMUK5TX5, &hTable_LfXGvwTh);
  numBytes += sTabwrite_init(&sTabwrite_juL3lEB7, &hTable_f71PlYKv);
  numBytes += sTabwrite_init(&sTabwrite_f1CCwUY8, &hTable_1NYZsr90);
  numBytes += sTabwrite_init(&sTabwrite_Nhj3k8sX, &hTable_uhLL7yho);
  numBytes += sTabwrite_init(&sTabwrite_qHgNkAEQ, &hTable_uyDJyNjy);
  numBytes += sTabwrite_init(&sTabwrite_cOTmnE8q, &hTable_xFxj5K73);
  numBytes += sTabread_init(&sTabread_jYEApCTm, &hTable_LfXGvwTh, true);
  numBytes += sTabread_init(&sTabread_eLOXIhvE, &hTable_ftHhTyVL, true);
  numBytes += sRPole_init(&sRPole_AhKY22qB);
  numBytes += sTabread_init(&sTabread_9w7FF8pZ, &hTable_7EeCKKBz, true);
  numBytes += sRPole_init(&sRPole_rpxWkhf9);
  numBytes += sTabread_init(&sTabread_EcvHPTpu, &hTable_FLvNlyM6, true);
  numBytes += sRPole_init(&sRPole_EPGSRd45);
  numBytes += sTabwrite_init(&sTabwrite_jwRTTVc7, &hTable_81Fwh5Ik);
  numBytes += sTabwrite_init(&sTabwrite_V6dDYAF7, &hTable_ftHhTyVL);
  numBytes += sTabwrite_init(&sTabwrite_RHL8PbPg, &hTable_7EeCKKBz);
  numBytes += sTabwrite_init(&sTabwrite_Udjy761d, &hTable_FLvNlyM6);
  numBytes += sLine_init(&sLine_6FwER0B6);
  numBytes += sLine_init(&sLine_DhZXQLQd);
  numBytes += sLine_init(&sLine_vYEOsQ6y);
  numBytes += cVar_init_s(&cVar_2h0Uh776, "floatatom");
  numBytes += cVar_init_f(&cVar_lKNjrLfM, 98.0f);
  numBytes += cIf_init(&cIf_LO8k9a4b, false);
  numBytes += cBinop_init(&cBinop_gcmsU87E, 0.0f); // __pow
  numBytes += cPack_init(&cPack_IgxbbTx7, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_0tCFaBTJ, 0.0f);
  numBytes += cRandom_init(&cRandom_n3Aps0Yj, 1135778655);
  numBytes += cSlice_init(&cSlice_SQZMtDw7, 1, 1);
  numBytes += cBinop_init(&cBinop_rxs6Og9A, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_5WfrWILh, 1979850620);
  numBytes += cSlice_init(&cSlice_UgRKejiy, 1, 1);
  numBytes += cSlice_init(&cSlice_3E0hLPsR, 1, 1);
  numBytes += cSlice_init(&cSlice_DDRuaejs, 0, 1);
  numBytes += cPack_init(&cPack_W23DECPO, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_bDY1cuAj, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_GIYs6YNp, 0.0f);
  numBytes += cDelay_init(this, &cDelay_DZLFltpN, 25.0f);
  numBytes += cVar_init_f(&cVar_dFATVY1t, 0.0f);
  numBytes += sVarf_init(&sVarf_S3c4S773, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_jgqlhHX6, 1.0f);
  numBytes += cVar_init_f(&cVar_1E2PfF8X, 0.0f);
  numBytes += cDelay_init(this, &cDelay_4KDiJL3J, 2.0f);
  numBytes += cPack_init(&cPack_B79tBmzC, 2, 0.0f, 2.0f);
  numBytes += cPack_init(&cPack_T57rZjw3, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_7L2pgzHj, 2, 0.0f, 4410000.0f);
  numBytes += cVar_init_f(&cVar_tTohaA88, 1.0f);
  numBytes += cVar_init_s(&cVar_TMQXX1zz, "floatatom");
  numBytes += cVar_init_f(&cVar_GoAyydBO, 0.0f);
  numBytes += cVar_init_f(&cVar_OpQmf9GU, 1.0f);
  numBytes += cBinop_init(&cBinop_3B2XwYzD, 0.0f); // __div
  numBytes += cSlice_init(&cSlice_j01okeAy, 1, 1);
  numBytes += cSlice_init(&cSlice_GeeT22px, 0, 1);
  numBytes += cVar_init_s(&cVar_YM7jReps, "1013_default");
  numBytes += cSlice_init(&cSlice_xC5pmgEI, 1, 1);
  numBytes += sVarf_init(&sVarf_3GiXktsj, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_uR0T5SUa, 1, 1);
  numBytes += cSlice_init(&cSlice_Kg316Csk, 0, 1);
  numBytes += cVar_init_s(&cVar_9IZ3GKPr, "floatatom");
  numBytes += cVar_init_s(&cVar_KI0xS9hr, "floatatom");
  numBytes += hTable_init(&hTable_ceQ9QuNA, 1000);
  numBytes += cSlice_init(&cSlice_lsDM8HNQ, 1, 1);
  numBytes += cSlice_init(&cSlice_R5nAmq1w, 0, 1);
  numBytes += cVar_init_f(&cVar_nWT84UvH, 0.0f);
  numBytes += cPack_init(&cPack_piirR5JZ, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_kFfFIVp8, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_aQgkKa9T, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_xSAgXEqq, -38582474);
  numBytes += cSlice_init(&cSlice_JUXUi1h3, 1, 1);
  numBytes += cBinop_init(&cBinop_vtQjhXYh, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_u2EhvR7X, -41889944);
  numBytes += cSlice_init(&cSlice_CfZ6o2xf, 1, 1);
  numBytes += cSlice_init(&cSlice_HjGSsOiG, 1, 1);
  numBytes += cSlice_init(&cSlice_DKegY29b, 0, 1);
  numBytes += cPack_init(&cPack_tOyN0Gjy, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_4iaIHis5, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_2JhScW0D, 0.0f);
  numBytes += cDelay_init(this, &cDelay_i7ke7hny, 25.0f);
  numBytes += cVar_init_f(&cVar_4zLJzuIg, 0.0f);
  numBytes += sVarf_init(&sVarf_JmtFakDs, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_dkAF7ILJ, 1.0f);
  numBytes += cVar_init_f(&cVar_aXk7hnS5, 0.0f);
  numBytes += cDelay_init(this, &cDelay_HwRqHMpE, 2.0f);
  numBytes += cPack_init(&cPack_pdBYY8St, 2, 0.0f, 2.0f);
  numBytes += cPack_init(&cPack_nToIjZzo, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_YDPrQHxG, 2, 0.0f, 4410000.0f);
  numBytes += cVar_init_f(&cVar_tBV5VHTX, 1.0f);
  numBytes += cVar_init_s(&cVar_nmV0iIeU, "floatatom");
  numBytes += cVar_init_f(&cVar_GRQx4o0B, 0.0f);
  numBytes += cVar_init_f(&cVar_U1wH9rP2, 1.0f);
  numBytes += cBinop_init(&cBinop_sBNwwEwQ, 0.0f); // __div
  numBytes += cSlice_init(&cSlice_1ZFEDvJ0, 1, 1);
  numBytes += cSlice_init(&cSlice_9j4Sl9B4, 0, 1);
  numBytes += cVar_init_s(&cVar_k7Fj0yOb, "1051_default");
  numBytes += cSlice_init(&cSlice_Si0Z6UvF, 1, 1);
  numBytes += sVarf_init(&sVarf_rbJ6mJMu, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_ybqVxD9K, 1, 1);
  numBytes += cSlice_init(&cSlice_OzfNoFZp, 0, 1);
  numBytes += cVar_init_s(&cVar_JicBALXA, "floatatom");
  numBytes += cVar_init_s(&cVar_FVLC6Azr, "floatatom");
  numBytes += hTable_init(&hTable_7wRHRReH, 1000);
  numBytes += cSlice_init(&cSlice_fKaJ4NKP, 1, 1);
  numBytes += cSlice_init(&cSlice_bw3tO1aC, 0, 1);
  numBytes += cVar_init_f(&cVar_0yteDdcT, 0.0f);
  numBytes += cPack_init(&cPack_XHazheC5, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_AR5zpttj, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_YnAnRMqN, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_TM7ECDPY, -567484926);
  numBytes += cSlice_init(&cSlice_yetpvml7, 1, 1);
  numBytes += cBinop_init(&cBinop_QDc2MRQh, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_vPoJyQpS, 1411473131);
  numBytes += cSlice_init(&cSlice_im73BVm6, 1, 1);
  numBytes += cSlice_init(&cSlice_Df0ixTcC, 1, 1);
  numBytes += cSlice_init(&cSlice_BBzctUjR, 0, 1);
  numBytes += cPack_init(&cPack_swVSa0y7, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_GHTfcJPU, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_33LyGD7p, 0.0f);
  numBytes += cDelay_init(this, &cDelay_1LJpCVvf, 25.0f);
  numBytes += cVar_init_f(&cVar_R8AFpVnY, 0.0f);
  numBytes += sVarf_init(&sVarf_1o4hL0k3, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_cK9lINjk, 1.0f);
  numBytes += cVar_init_f(&cVar_bo4z3V4Y, 0.0f);
  numBytes += cDelay_init(this, &cDelay_P96dxXTW, 2.0f);
  numBytes += cPack_init(&cPack_rrQfTZgn, 2, 0.0f, 2.0f);
  numBytes += cPack_init(&cPack_jrEC6nB1, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_0wAeGhld, 2, 0.0f, 4410000.0f);
  numBytes += cVar_init_f(&cVar_7ITbNDNg, 1.0f);
  numBytes += cVar_init_s(&cVar_O9uzOy2s, "floatatom");
  numBytes += cVar_init_f(&cVar_eEr04pD7, 0.0f);
  numBytes += cVar_init_f(&cVar_3U1pZuUm, 1.0f);
  numBytes += cBinop_init(&cBinop_GF7HOdvg, 0.0f); // __div
  numBytes += cSlice_init(&cSlice_KBKQjq6g, 1, 1);
  numBytes += cSlice_init(&cSlice_N4Fc101n, 0, 1);
  numBytes += cVar_init_s(&cVar_wvP4HmK3, "1089_default");
  numBytes += cSlice_init(&cSlice_hLiGoZJU, 1, 1);
  numBytes += sVarf_init(&sVarf_TdIqQIuP, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_N1UnJyZC, 1, 1);
  numBytes += cSlice_init(&cSlice_bJY6kOax, 0, 1);
  numBytes += cVar_init_s(&cVar_JCtUlwLr, "floatatom");
  numBytes += cVar_init_s(&cVar_dhfr4PrC, "floatatom");
  numBytes += hTable_init(&hTable_siO20AT6, 1000);
  numBytes += cSlice_init(&cSlice_mBfvagEW, 1, 1);
  numBytes += cSlice_init(&cSlice_E29p9X9W, 0, 1);
  numBytes += cVar_init_f(&cVar_Hs0HkWxb, 0.0f);
  numBytes += cPack_init(&cPack_63bWuysM, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_lULqb2L5, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_fhES9jZ4, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_0WiuicHi, 1831888360);
  numBytes += cSlice_init(&cSlice_tqW8R4Go, 1, 1);
  numBytes += cBinop_init(&cBinop_81RcjXOM, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_70HGdZoN, -1607867885);
  numBytes += cSlice_init(&cSlice_f080Payt, 1, 1);
  numBytes += cSlice_init(&cSlice_iUBxvauI, 1, 1);
  numBytes += cSlice_init(&cSlice_eKD3Mqw1, 0, 1);
  numBytes += cPack_init(&cPack_C12c4gDc, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_w8eIN2zG, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_CeR6OvLH, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ZziOHvdS, 25.0f);
  numBytes += cVar_init_f(&cVar_qinq1uVd, 0.0f);
  numBytes += sVarf_init(&sVarf_Epq16a2o, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_mbvqhiIe, 1.0f);
  numBytes += cVar_init_f(&cVar_soc2d4lS, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Oo443YrA, 2.0f);
  numBytes += cPack_init(&cPack_EZrqJn3i, 2, 0.0f, 2.0f);
  numBytes += cPack_init(&cPack_bnGE3sMi, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_9UZZCODM, 2, 0.0f, 4410000.0f);
  numBytes += cVar_init_f(&cVar_zqjP8VWE, 1.0f);
  numBytes += cVar_init_s(&cVar_w3fFPjaW, "floatatom");
  numBytes += cVar_init_f(&cVar_sFgTU62D, 0.0f);
  numBytes += cVar_init_f(&cVar_ll6nCTTl, 1.0f);
  numBytes += cBinop_init(&cBinop_wCtjg07t, 0.0f); // __div
  numBytes += cSlice_init(&cSlice_AwaJrZB0, 1, 1);
  numBytes += cSlice_init(&cSlice_2tGdidtH, 0, 1);
  numBytes += cVar_init_s(&cVar_f1CdBkdk, "1127_default");
  numBytes += cSlice_init(&cSlice_QYXAA0ky, 1, 1);
  numBytes += sVarf_init(&sVarf_e7japoAN, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_D77GWzkz, 1, 1);
  numBytes += cSlice_init(&cSlice_Lijy9Qfb, 0, 1);
  numBytes += cVar_init_s(&cVar_1qnKFQ50, "floatatom");
  numBytes += cVar_init_s(&cVar_KKhVWDeL, "floatatom");
  numBytes += hTable_init(&hTable_jMxmuK8G, 1000);
  numBytes += cSlice_init(&cSlice_8068ygxl, 1, 1);
  numBytes += cSlice_init(&cSlice_dZzzOY3A, 0, 1);
  numBytes += cVar_init_f(&cVar_30c6wUDh, 0.0f);
  numBytes += cPack_init(&cPack_4NS0pbix, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_kOIt0toz, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_MFMyfDm0, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_vRxqgq9S, 98.0f);
  numBytes += cIf_init(&cIf_PuVE8iQ5, false);
  numBytes += cBinop_init(&cBinop_0rQonpY8, 0.0f); // __pow
  numBytes += cPack_init(&cPack_W4OqzlDa, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_xeXP7cvP, 0.0f);
  numBytes += cVar_init_f(&cVar_tQMJpxkN, 100.0f);
  numBytes += cIf_init(&cIf_wOgeAP27, false);
  numBytes += cBinop_init(&cBinop_jPc7ykt3, 0.0f); // __pow
  numBytes += cPack_init(&cPack_pQTZkrIu, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_9hFb5Zei, 0.0f);
  numBytes += cIf_init(&cIf_aVWaGoCl, false);
  numBytes += cVar_init_f(&cVar_AjJ4B8zP, 97.0f);
  numBytes += cIf_init(&cIf_SG6rqOkY, false);
  numBytes += cBinop_init(&cBinop_fxp9b9yi, 0.0f); // __pow
  numBytes += cPack_init(&cPack_E2yLb7b2, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_qH6JGXZw, 0.0f);
  numBytes += cVar_init_f(&cVar_wZQyT7Ko, 97.0f);
  numBytes += cIf_init(&cIf_39HFbFhX, false);
  numBytes += cBinop_init(&cBinop_zdRA3fKB, 0.0f); // __pow
  numBytes += cPack_init(&cPack_ldjFJthh, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_EVEb9CdE, 0.0f);
  numBytes += cPack_init(&cPack_AKsbjDOX, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_nQpTMTYG, 1, 1);
  numBytes += cSlice_init(&cSlice_Txo6ydh9, 0, 1);
  numBytes += cIf_init(&cIf_RWnJwhe9, false);
  numBytes += cIf_init(&cIf_XuzeMJqy, false);
  numBytes += cIf_init(&cIf_QAOfQfTS, false);
  numBytes += cSlice_init(&cSlice_TTw7UIhe, 1, 1);
  numBytes += cSlice_init(&cSlice_DzsC7L2V, 0, 1);
  numBytes += cVar_init_f(&cVar_BusnRLzI, 0.0f);
  numBytes += cIf_init(&cIf_prb2T3mh, false);
  numBytes += cPack_init(&cPack_cvetfj9F, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_P4sjauXt, 1, -1);
  numBytes += cSlice_init(&cSlice_xf6BB6Wm, 1, -1);
  numBytes += cSlice_init(&cSlice_BcCdlevP, 1, -1);
  numBytes += cSlice_init(&cSlice_a5xxJ9gr, 1, -1);
  numBytes += cIf_init(&cIf_dhU9TARl, false);
  numBytes += cVar_init_f(&cVar_kRTCDiYz, 1.0f);
  numBytes += cPack_init(&cPack_TwcOGk3U, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_MpzueeO0, 0.0f);
  numBytes += hTable_init(&hTable_amCL36fy, 36000);
  numBytes += hTable_init(&hTable_UYG6pvuw, 290000);
  numBytes += hTable_init(&hTable_z3kP5qh2, 288000);
  numBytes += hTable_init(&hTable_TFx144L5, 66000);
  numBytes += hTable_init(&hTable_gQNN9nGV, 25000);
  numBytes += hTable_init(&hTable_1xHT5NDV, 384000);
  numBytes += cSlice_init(&cSlice_z1UlBdIJ, 2, 1);
  numBytes += cSlice_init(&cSlice_SmS9GaGH, 1, 1);
  numBytes += cSlice_init(&cSlice_5C2HXS0B, 0, 1);
  numBytes += cVar_init_f(&cVar_fcIqxhNK, 0.0f);
  numBytes += cIf_init(&cIf_URTmEOnH, false);
  numBytes += cIf_init(&cIf_KWtwlnGM, false);
  numBytes += cIf_init(&cIf_zterQ7Pk, false);
  numBytes += cIf_init(&cIf_dNImdQcy, false);
  numBytes += cIf_init(&cIf_2Rf2CTD8, false);
  numBytes += cBinop_init(&cBinop_uvW1IgTh, 0.0f); // __eq
  numBytes += cRandom_init(&cRandom_qkztsDYV, 1144514620);
  numBytes += cSlice_init(&cSlice_RLN9mP6F, 1, 1);
  numBytes += cRandom_init(&cRandom_Kii8NuQ3, 1771151530);
  numBytes += cSlice_init(&cSlice_NcXPTfvy, 1, 1);
  numBytes += cRandom_init(&cRandom_KgiZuCcH, 998613244);
  numBytes += cSlice_init(&cSlice_8PbICwYz, 1, 1);
  numBytes += cVar_init_s(&cVar_rNfpiePK, "floatatom");
  numBytes += cPack_init(&cPack_eoMjGEAu, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_ZieZL1xR, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_5FG0Ag5z, "floatatom");
  numBytes += cDelay_init(this, &cDelay_OBPQSiWQ, 0.0f);
  numBytes += cDelay_init(this, &cDelay_m5SDsPhd, 0.0f);
  numBytes += hTable_init(&hTable_oRoHtg9E, 256);
  numBytes += cVar_init_s(&cVar_dW1NHeJ6, "del-1228-del");
  numBytes += sVarf_init(&sVarf_GcZzNGCY, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_8irt6XdM, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_iN3OEegO, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_355T4jD2, "del-1228-del");
  numBytes += sVarf_init(&sVarf_NYS8uaw0, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_OuHCKlac, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_VRpEdLyn, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_r1YYYDJd, 0.0f); // __div
  numBytes += cVar_init_s(&cVar_bzu2vw0t, "del-1257-del1");
  numBytes += sVarf_init(&sVarf_JJwa1h1d, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_4ULtgp3v, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_0jirQ8Dl, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_bTI3bFr5, 10000.0f);
  numBytes += cBinop_init(&cBinop_3UVm8ic6, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_764QpYzG, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_gfRmyWQe, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_nNRbulIl, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_VK0ooZFX, 10.0f);
  numBytes += cBinop_init(&cBinop_Onpypumb, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_rgnkoBBl, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_do1I6mfP, "floatatom");
  numBytes += sVarf_init(&sVarf_IKss2HMD, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_FZqLrvrt, 0.0f);
  numBytes += cDelay_init(this, &cDelay_lkc4Su4Z, 0.0f);
  numBytes += hTable_init(&hTable_3s6UTbxa, 256);
  numBytes += sVarf_init(&sVarf_SRHqRpj8, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_xMES6WPq, "floatatom");
  numBytes += cDelay_init(this, &cDelay_M0UaVWO2, 0.0f);
  numBytes += cVar_init_f(&cVar_rZAJzj2N, 20.0f);
  numBytes += cBinop_init(&cBinop_ocHC5l4s, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_sRPVPhoe, 0.0f);
  numBytes += cSlice_init(&cSlice_ZUEcKwez, 1, -1);
  numBytes += cSlice_init(&cSlice_cDUZkQIh, 1, -1);
  numBytes += cVar_init_f(&cVar_ey6cIaW0, 0.0f);
  numBytes += cVar_init_f(&cVar_axV3FCr3, 20.0f);
  numBytes += cVar_init_f(&cVar_iSuPtPBp, 0.0f);
  numBytes += cVar_init_f(&cVar_Fk8fXxHd, 0.0f);
  numBytes += cVar_init_f(&cVar_aDhkvIgs, 0.0f);
  numBytes += cSlice_init(&cSlice_hzxX9syw, 1, 1);
  numBytes += cSlice_init(&cSlice_au6glezj, 0, 1);
  numBytes += cBinop_init(&cBinop_5wPDF0ye, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Q2wUw3Dy, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_1xULACqT, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_SW3ysAR1, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_rJsc3KT8, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_0UvNhUn9, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_mZzHQwBz, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_J5DhpX9w, 0.0f); // __sub
  numBytes += cVar_init_s(&cVar_jNXzDXgG, "floatatom");
  numBytes += cPack_init(&cPack_qG9WTs91, 2, 0.0f, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_jUg3TBVd, 0.0f);
  numBytes += cVar_init_f(&cVar_lq0ZeuWF, 20.0f);
  numBytes += cBinop_init(&cBinop_1RH6BlPs, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_99IcP7YQ, 0.0f);
  numBytes += cSlice_init(&cSlice_Tc018gGc, 1, -1);
  numBytes += cSlice_init(&cSlice_3PQJi93r, 1, -1);
  numBytes += cVar_init_f(&cVar_E4KGjYVQ, 0.0f);
  numBytes += cVar_init_f(&cVar_RPGNKu60, 20.0f);
  numBytes += cVar_init_f(&cVar_67dHZIe4, 0.0f);
  numBytes += cVar_init_f(&cVar_9AnCsGFn, 0.0f);
  numBytes += cVar_init_f(&cVar_VStxO6V3, 0.0f);
  numBytes += cSlice_init(&cSlice_znC82660, 1, 1);
  numBytes += cSlice_init(&cSlice_UZa0n1T9, 0, 1);
  numBytes += cBinop_init(&cBinop_jRD01h2r, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_NVhEP288, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Jr5ZmVF4, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_8JAnkFso, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_MlMD3BYD, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_G5CTjLOb, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_zXcUxeMC, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_P98OWV7X, 0.0f); // __sub
  numBytes += cPack_init(&cPack_WE1w8xe6, 2, 0.0f, 1000.0f);
  numBytes += cPack_init(&cPack_ae3xyAfY, 2, 0.0f, 1000.0f);
  numBytes += cTabhead_init(&cTabhead_g3PCOzNZ, &hTable_EfQ3r6vv);
  numBytes += cVar_init_s(&cVar_fH6aAUco, "del-1318-del1");
  numBytes += cDelay_init(this, &cDelay_tOrKbjoJ, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_Buvmpqwm, 0.0f);
  numBytes += cBinop_init(&cBinop_iWi566uD, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_Z6uhmgsK, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_VaLj28Ed, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_R9e0s6B1, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_AsHJtCmo, &hTable_29SNVBBY);
  numBytes += cVar_init_s(&cVar_6jfaf4QE, "del-1318-del2");
  numBytes += cDelay_init(this, &cDelay_EM8SKTJ5, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_A8Ug1NOM, 0.0f);
  numBytes += cBinop_init(&cBinop_HEnxbPb1, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_caTZs9RU, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_X4a26lHQ, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_Fr63WfGn, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_LQP9Us35, &hTable_xRTC2smU);
  numBytes += cVar_init_s(&cVar_b68GLqBA, "del-1318-del3");
  numBytes += cDelay_init(this, &cDelay_9iBIEjbE, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_owMnlbpq, 0.0f);
  numBytes += cBinop_init(&cBinop_CYET5KGB, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_cKnLvpo9, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_NkJAeDZT, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_VhwX8dGB, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_Skrp7sdn, &hTable_rOK83OZK);
  numBytes += cVar_init_s(&cVar_DHPHC5Ky, "del-1318-del4");
  numBytes += cDelay_init(this, &cDelay_g1LR5Yyr, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_xljfed7f, 0.0f);
  numBytes += cBinop_init(&cBinop_tykB8oH9, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_1ZL9nMqH, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_xNny8rLX, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_DmNbstYJ, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_g1otyzfD, 0.0f);
  numBytes += cDelay_init(this, &cDelay_YXlJRMAG, 0.0f);
  numBytes += hTable_init(&hTable_EfQ3r6vv, 256);
  numBytes += cDelay_init(this, &cDelay_5PHmuHVa, 0.0f);
  numBytes += cDelay_init(this, &cDelay_rKBYP7Gn, 0.0f);
  numBytes += hTable_init(&hTable_29SNVBBY, 256);
  numBytes += cDelay_init(this, &cDelay_PCPIkxZt, 0.0f);
  numBytes += cDelay_init(this, &cDelay_SjFt6v6p, 0.0f);
  numBytes += hTable_init(&hTable_xRTC2smU, 256);
  numBytes += cDelay_init(this, &cDelay_YDEoTNip, 0.0f);
  numBytes += cDelay_init(this, &cDelay_uNlc5YNE, 0.0f);
  numBytes += hTable_init(&hTable_rOK83OZK, 256);
  numBytes += cIf_init(&cIf_cMuFIteP, false);
  numBytes += cBinop_init(&cBinop_n7r7Ygrm, 0.0f); // __pow
  numBytes += cPack_init(&cPack_KRvfoe96, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_f2lH268q, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_aOQ9OlCb, 22050.0f);
  numBytes += cBinop_init(&cBinop_WDHuPXuO, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_E868jMd7, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_bVMYZ015, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_YSTFFx4C, 95.0f);
  numBytes += cVar_init_f(&cVar_yJzowiDV, 90.0f);
  numBytes += cVar_init_f(&cVar_XgN9UCBQ, 6000.0f);
  numBytes += cVar_init_f(&cVar_I3vAVxsQ, 60.0f);
  numBytes += cIf_init(&cIf_BylArrXd, false);
  numBytes += cTabhead_init(&cTabhead_Gy16jHUe, &hTable_XJkV9INz);
  numBytes += cVar_init_s(&cVar_0Be0FaQ5, "del-1318-ref6");
  numBytes += cDelay_init(this, &cDelay_fwCw9U1P, 13.645f);
  numBytes += cDelay_init(this, &cDelay_jz9JNZyW, 0.0f);
  numBytes += cBinop_init(&cBinop_4vJlABzX, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_8nhNjU0w, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_OMDm8DCO, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_ZWfbD4Vh, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_cHndQfS4, 0.0f);
  numBytes += cDelay_init(this, &cDelay_wRyonlly, 0.0f);
  numBytes += hTable_init(&hTable_XJkV9INz, 256);
  numBytes += cTabhead_init(&cTabhead_UQWPnZWy, &hTable_d8pDnroX);
  numBytes += cVar_init_s(&cVar_ZZxe0UrA, "del-1318-ref5");
  numBytes += cDelay_init(this, &cDelay_WEJrUFZ0, 16.364f);
  numBytes += cDelay_init(this, &cDelay_KLExhJzL, 0.0f);
  numBytes += cBinop_init(&cBinop_1MzqNeCN, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_QTCvj0bB, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_ygd0ik7l, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_sYdRcwgd, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_4CLqT6ya, 0.0f);
  numBytes += cDelay_init(this, &cDelay_cPdDxgPc, 0.0f);
  numBytes += hTable_init(&hTable_d8pDnroX, 256);
  numBytes += cTabhead_init(&cTabhead_ih5GnYAW, &hTable_3hU40Lfe);
  numBytes += cVar_init_s(&cVar_h3IcUmL7, "del-1318-ref4");
  numBytes += cDelay_init(this, &cDelay_XhSLtOMi, 19.392f);
  numBytes += cDelay_init(this, &cDelay_Tg57vlRw, 0.0f);
  numBytes += cBinop_init(&cBinop_MqQ29EMi, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_vLbyUb7u, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_L89ru6Zw, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_ROHT4qz6, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_UjQMPD72, 0.0f);
  numBytes += cDelay_init(this, &cDelay_MKnIWlgl, 0.0f);
  numBytes += hTable_init(&hTable_3hU40Lfe, 256);
  numBytes += cTabhead_init(&cTabhead_8RQheQpP, &hTable_Qk4Aw7or);
  numBytes += cVar_init_s(&cVar_3wJR809q, "del-1318-ref3");
  numBytes += cDelay_init(this, &cDelay_ZjTnwxEP, 25.796f);
  numBytes += cDelay_init(this, &cDelay_QGH6DjFZ, 0.0f);
  numBytes += cBinop_init(&cBinop_Ti0lR88O, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_FkRzvFQV, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_ZyRehKXi, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_QhuDa71d, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_uaVUEcla, 0.0f);
  numBytes += cDelay_init(this, &cDelay_K0M1Azgn, 0.0f);
  numBytes += hTable_init(&hTable_Qk4Aw7or, 256);
  numBytes += cTabhead_init(&cTabhead_lgfETbHV, &hTable_j4I5AoYy);
  numBytes += cVar_init_s(&cVar_TEvax844, "del-1318-ref2");
  numBytes += cDelay_init(this, &cDelay_1JDYpUAl, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_Tc2kTUOA, 0.0f);
  numBytes += cBinop_init(&cBinop_EpCa9iwe, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_RDiEEeLi, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_cJ7RqRHw, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_baItZxnJ, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_uDO5liSr, 0.0f);
  numBytes += cDelay_init(this, &cDelay_lG0bcxz8, 0.0f);
  numBytes += hTable_init(&hTable_j4I5AoYy, 256);
  numBytes += cTabhead_init(&cTabhead_qjsp8uUK, &hTable_gYNAhlyb);
  numBytes += cVar_init_s(&cVar_4JzXAX0n, "del-1318-ref1");
  numBytes += cDelay_init(this, &cDelay_cfEeG9ju, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_iUh80htx, 0.0f);
  numBytes += cBinop_init(&cBinop_XXtSH7Ue, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_DhUBz3Yx, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_0o8UXXFn, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_mvMtr3Lt, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_fZvVKWUA, 0.0f);
  numBytes += cDelay_init(this, &cDelay_gMEspcE3, 0.0f);
  numBytes += hTable_init(&hTable_gYNAhlyb, 256);
  numBytes += cVar_init_f(&cVar_eWJNR6xq, 0.0f);
  numBytes += cVar_init_f(&cVar_3X3wCO5K, 0.0f);
  numBytes += cPack_init(&cPack_7Wdneohs, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_k8fKOk59, 22050.0f);
  numBytes += cBinop_init(&cBinop_6JiqAYoa, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_xUkq45e0, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_1b2ZvpmZ, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_8s99bkvX, 22050.0f);
  numBytes += cBinop_init(&cBinop_43VADeMk, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_PrO89gA7, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Cnyv8C4m, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_ddMXOMJQ, 22050.0f);
  numBytes += cBinop_init(&cBinop_H78cGDRS, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_uGnRSPLb, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_0bVHqkST, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_qRMdyRZj, 100.0f);
  numBytes += cIf_init(&cIf_X2FUDHaP, false);
  numBytes += cBinop_init(&cBinop_CRXcbWfo, 0.0f); // __pow
  numBytes += cPack_init(&cPack_W4ch99U0, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_JLO0nmGt, 0.0f);
  numBytes += cIf_init(&cIf_2MpAXMQB, false);
  numBytes += cIf_init(&cIf_R7uVv4DZ, false);
  numBytes += cDelay_init(this, &cDelay_9oKLVgOb, 50.0f);
  numBytes += cVar_init_f(&cVar_lBDIfJsn, 0.0f);
  numBytes += cVar_init_f(&cVar_IS0NihHG, 12.0f);
  numBytes += cVar_init_s(&cVar_I9W43AtX, "floatatom");
  numBytes += cPack_init(&cPack_WF2ByexI, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_Q3zcj6Kc, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_IPdiXj6Z, "floatatom");
  numBytes += cDelay_init(this, &cDelay_vp3NG1PI, 0.0f);
  numBytes += cDelay_init(this, &cDelay_bMj3hH0j, 0.0f);
  numBytes += hTable_init(&hTable_PLZ3kGJM, 256);
  numBytes += cVar_init_s(&cVar_mgXjKRnt, "del-1436-del");
  numBytes += sVarf_init(&sVarf_N52pBKt9, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_mKbyEBUK, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_hJwc8Iw8, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_YbrdOzca, "del-1436-del");
  numBytes += sVarf_init(&sVarf_BzDZDqFR, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_lyyP7vsQ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_7p2f9ozt, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_Fx1UQGzP, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_R26pb7J2, 4720.0f);
  numBytes += cBinop_init(&cBinop_ftxYhjb7, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_1IoVrxsD, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_jUTLBWjZ, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_cIB6hrj3, 4720.0f);
  numBytes += cBinop_init(&cBinop_IEezAQMa, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_zzn1Axzn, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_BDCf0aA3, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_VQ083g8a, 4720.0f);
  numBytes += cBinop_init(&cBinop_hcYJAAW5, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_4O86NrNp, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_j7Zs79ku, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_sW8nmyIk, 1.0f);
  numBytes += cIf_init(&cIf_QQ8N9LZX, false);
  numBytes += sVarf_init(&sVarf_BD6qXRGY, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_LEK9L4BP, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_FGL19iji, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_F2X9ObRM, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_mxCDPLDB, 4720.0f, 0.0f, false);
  numBytes += cTabhead_init(&cTabhead_SXkhJBY3, &hTable_81Fwh5Ik);
  numBytes += cVar_init_s(&cVar_HH6Xr0A7, "del-1499-del1");
  numBytes += cDelay_init(this, &cDelay_p9HXfHML, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_n0FqqA96, 0.0f);
  numBytes += cBinop_init(&cBinop_KozkQX76, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_wM7SplKq, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_KLyJcFf5, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_nStqW3SN, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_NR3xuXrv, &hTable_ftHhTyVL);
  numBytes += cVar_init_s(&cVar_O4t0wLSg, "del-1499-del2");
  numBytes += cDelay_init(this, &cDelay_qY9SCDIu, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_6g9D0Mw0, 0.0f);
  numBytes += cBinop_init(&cBinop_3jsqqjEy, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_klLddm2f, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_38hAhIl0, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_vO1PCmBr, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_kXwel3YH, &hTable_7EeCKKBz);
  numBytes += cVar_init_s(&cVar_cSpwGDa1, "del-1499-del3");
  numBytes += cDelay_init(this, &cDelay_R2apNQpI, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_Iu4uaL7v, 0.0f);
  numBytes += cBinop_init(&cBinop_BKiqzatt, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_RZFxQmbT, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_48Q1yh1f, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_z1gUj4on, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_sFyzHI0n, &hTable_FLvNlyM6);
  numBytes += cVar_init_s(&cVar_eFC51iED, "del-1499-del4");
  numBytes += cDelay_init(this, &cDelay_rz4UI3iD, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_DJnipM8B, 0.0f);
  numBytes += cBinop_init(&cBinop_nx4mLjMF, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_aOCPX9pV, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_YBOwAvTT, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_WIGW6qNv, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_xARKvSlF, 0.0f);
  numBytes += cDelay_init(this, &cDelay_VNMs9plb, 0.0f);
  numBytes += hTable_init(&hTable_81Fwh5Ik, 256);
  numBytes += cDelay_init(this, &cDelay_YUaEaRZf, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Uq36K0BH, 0.0f);
  numBytes += hTable_init(&hTable_ftHhTyVL, 256);
  numBytes += cDelay_init(this, &cDelay_jeZG5Rqb, 0.0f);
  numBytes += cDelay_init(this, &cDelay_cSI0Z9Af, 0.0f);
  numBytes += hTable_init(&hTable_7EeCKKBz, 256);
  numBytes += cDelay_init(this, &cDelay_GZ7Jc06O, 0.0f);
  numBytes += cDelay_init(this, &cDelay_tnsYRRR1, 0.0f);
  numBytes += hTable_init(&hTable_FLvNlyM6, 256);
  numBytes += cIf_init(&cIf_om10kpwV, false);
  numBytes += cBinop_init(&cBinop_CpMu0ke7, 0.0f); // __pow
  numBytes += cPack_init(&cPack_EQfGpw4o, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_ImCmEvxS, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_vgwh6SfN, 22050.0f);
  numBytes += cBinop_init(&cBinop_1QFGDfEM, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_nrO3sP4M, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_M5iGRofl, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_OLpM7ZL1, 100.0f);
  numBytes += cVar_init_f(&cVar_8Usvu6Ky, 95.0f);
  numBytes += cVar_init_f(&cVar_UhJUy96q, 14400.0f);
  numBytes += cVar_init_f(&cVar_BzxHXOCF, 60.0f);
  numBytes += cIf_init(&cIf_aQIll2GA, false);
  numBytes += cTabhead_init(&cTabhead_Vf7MCSSc, &hTable_LfXGvwTh);
  numBytes += cVar_init_s(&cVar_SVNkmjVv, "del-1499-ref6");
  numBytes += cDelay_init(this, &cDelay_iEJnU2pS, 13.645f);
  numBytes += cDelay_init(this, &cDelay_dvw6Hfc8, 0.0f);
  numBytes += cBinop_init(&cBinop_pLLbKFIv, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_5Y8mHuUQ, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_j3I7amDx, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_DBSJi3Nc, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_hP5mCYnE, 0.0f);
  numBytes += cDelay_init(this, &cDelay_BZlzFxyU, 0.0f);
  numBytes += hTable_init(&hTable_LfXGvwTh, 256);
  numBytes += cTabhead_init(&cTabhead_MRJoq79y, &hTable_f71PlYKv);
  numBytes += cVar_init_s(&cVar_STZtxlja, "del-1499-ref5");
  numBytes += cDelay_init(this, &cDelay_L2sbCw35, 16.364f);
  numBytes += cDelay_init(this, &cDelay_jwMjzahx, 0.0f);
  numBytes += cBinop_init(&cBinop_IdzVNjV5, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_CtiR58tA, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_l7lcJLjW, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_YfzK1l5T, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_KCEa8AB3, 0.0f);
  numBytes += cDelay_init(this, &cDelay_X2BgZ4wY, 0.0f);
  numBytes += hTable_init(&hTable_f71PlYKv, 256);
  numBytes += cTabhead_init(&cTabhead_J4Ps2RAU, &hTable_1NYZsr90);
  numBytes += cVar_init_s(&cVar_17rsssFG, "del-1499-ref4");
  numBytes += cDelay_init(this, &cDelay_LDF8I6ac, 19.392f);
  numBytes += cDelay_init(this, &cDelay_WXaoYQev, 0.0f);
  numBytes += cBinop_init(&cBinop_fbzy73OI, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_TzQXKiTq, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_X3XP7OJU, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_jcgk2Gj0, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_hioO4Njp, 0.0f);
  numBytes += cDelay_init(this, &cDelay_TSA6z9ge, 0.0f);
  numBytes += hTable_init(&hTable_1NYZsr90, 256);
  numBytes += cTabhead_init(&cTabhead_B8Gbhmkw, &hTable_uhLL7yho);
  numBytes += cVar_init_s(&cVar_SuZ5xyqC, "del-1499-ref3");
  numBytes += cDelay_init(this, &cDelay_jYFK4hgT, 25.796f);
  numBytes += cDelay_init(this, &cDelay_xd1tcJKw, 0.0f);
  numBytes += cBinop_init(&cBinop_FkpmvZwX, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_OtGlPzf5, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_3vUjt3B8, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_JSijZNMG, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_u8gAWuRy, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Kux4l09R, 0.0f);
  numBytes += hTable_init(&hTable_uhLL7yho, 256);
  numBytes += cTabhead_init(&cTabhead_Cwtwr1LJ, &hTable_uyDJyNjy);
  numBytes += cVar_init_s(&cVar_Mxp21e5Z, "del-1499-ref2");
  numBytes += cDelay_init(this, &cDelay_IBHMHVwV, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_Rcfv4Cby, 0.0f);
  numBytes += cBinop_init(&cBinop_YW0eomxC, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_gJ8Wgjjn, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_NcuXryEt, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_3xSGxozA, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_LaK8lVzo, 0.0f);
  numBytes += cDelay_init(this, &cDelay_BRzlxP80, 0.0f);
  numBytes += hTable_init(&hTable_uyDJyNjy, 256);
  numBytes += cTabhead_init(&cTabhead_itxTn9nv, &hTable_xFxj5K73);
  numBytes += cVar_init_s(&cVar_hA6Ojs56, "del-1499-ref1");
  numBytes += cDelay_init(this, &cDelay_pOwgt7z3, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_mtyBGVRP, 0.0f);
  numBytes += cBinop_init(&cBinop_Nsqsfo5U, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_YY9lnK0O, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_TI4XdwT1, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_Eh29dqbB, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_FkJv10Kg, 0.0f);
  numBytes += cDelay_init(this, &cDelay_pgdtaBDB, 0.0f);
  numBytes += hTable_init(&hTable_xFxj5K73, 256);
  numBytes += cVar_init_f(&cVar_KHbvhN8P, 0.0f);
  numBytes += cVar_init_f(&cVar_9vm71zek, 0.0f);
  numBytes += cPack_init(&cPack_u9IBeWUl, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_tUl2MrOD, 22050.0f);
  numBytes += cBinop_init(&cBinop_sOB89OZi, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_JL28iLCy, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_iPqSFKzE, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_tiXmJjxq, 22050.0f);
  numBytes += cBinop_init(&cBinop_k2zcZFcq, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_PX9sAeJU, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_wyZQYuip, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_IK0Wuvlg, 22050.0f);
  numBytes += cBinop_init(&cBinop_KBgrEVaE, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_254jGMzq, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_4q5MYVHv, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_Rp1tnQDo, "del-1598-del1");
  numBytes += sVarf_init(&sVarf_4L4Lh9BM, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_tEtfpbec, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_YIKpyQZw, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_v8V26Hd2, 10000.0f);
  numBytes += cBinop_init(&cBinop_8qBwKL4C, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_D3Mcg0iI, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_zNW0KTUv, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_XslEbU7V, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_x5cBU2Qp, 10.0f);
  numBytes += cBinop_init(&cBinop_KpHOaY9J, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_AnH1cdIn, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_Mqg3llS9, "floatatom");
  numBytes += sVarf_init(&sVarf_Gr1RpTtY, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_gqLsfqZR, 0.0f);
  numBytes += cDelay_init(this, &cDelay_1Z2sWVqU, 0.0f);
  numBytes += hTable_init(&hTable_M3hk39fh, 256);
  numBytes += sVarf_init(&sVarf_X3efWxy3, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_X4Sq55vo, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_o0Yxg6gR, 1.0f);
  numBytes += cPack_init(&cPack_79PXwRbh, 2, 0.0f, 50.0f);
  numBytes += cRandom_init(&cRandom_PaLr9tRb, -147468619);
  numBytes += cSlice_init(&cSlice_1bzdjMY0, 1, 1);
  numBytes += cRandom_init(&cRandom_aQGDLbMN, -1575864083);
  numBytes += cSlice_init(&cSlice_VlihNGi2, 1, 1);
  numBytes += cRandom_init(&cRandom_A7nlqwoJ, 1535717259);
  numBytes += cSlice_init(&cSlice_0z2x7JB5, 1, 1);
  numBytes += cPack_init(&cPack_J0axeTcT, 4, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_MepZ0Kil, "floatatom");
  numBytes += cVar_init_s(&cVar_E614orWO, "floatatom");
  numBytes += cIf_init(&cIf_XhAa5SuK, false);
  numBytes += cVar_init_s(&cVar_WOQc499a, "floatatom");
  numBytes += cBinop_init(&cBinop_aclplYbk, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_dsnL65UT, 72.07f); // __sub
  numBytes += cSlice_init(&cSlice_3M00gR2I, 1, -1);
  numBytes += cSlice_init(&cSlice_5h5wI2gI, 1, -1);
  numBytes += cVar_init_f(&cVar_Ht51AKFF, 5.0f);
  numBytes += cBinop_init(&cBinop_J7vJ7SvU, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_XqbHAxnG, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_FnCQzVKY, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_WH21fbod, 1, 1);
  numBytes += cSlice_init(&cSlice_l1XFrSv9, 0, 1);
  numBytes += sVarf_init(&sVarf_sY7TkwYC, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_EzSt5EAO, 5.0f);
  numBytes += cBinop_init(&cBinop_EFYSSgQA, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_969N79dX, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_LAwxoK6C, 50.0f);
  numBytes += cVar_init_s(&cVar_AmN9XE0X, "floatatom");
  numBytes += cDelay_init(this, &cDelay_E1nKngZa, 350.0f);
  numBytes += cVar_init_s(&cVar_XIKu30sk, "floatatom");
  numBytes += cVar_init_s(&cVar_DVyLaWtT, "floatatom");
  numBytes += cVar_init_s(&cVar_ddeKu5Uy, "floatatom");
  numBytes += cExpr_init(&cExpr_Wu4O9RP8, &Heavy_SoundScraper::cExpr_Wu4O9RP8_evaluate);
  numBytes += cVar_init_s(&cVar_Xnc5fB8l, "floatatom");
  numBytes += cVar_init_f(&cVar_2WZJIx2x, 0.0f);
  numBytes += cVar_init_f(&cVar_cGw52fC2, 0.0f);
  numBytes += cVar_init_s(&cVar_acmDYJ74, "1674_default");
  numBytes += cSlice_init(&cSlice_KWR8LjXy, 1, 1);
  numBytes += sVarf_init(&sVarf_pATykqdu, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_haDH1Pig, "1674_default");
  numBytes += cSlice_init(&cSlice_jDepmzjK, 1, 1);
  numBytes += sVarf_init(&sVarf_uukg2iBw, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_MU47EpYE, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_cHg7e1FU, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_xcKnWpSn, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_3u58kmUr, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_naTSwdir, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_l9AsDQq5, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_KbFZevaz, 0.0f); // __div
  numBytes += hTable_init(&hTable_7oIywVCj, 10000);
  numBytes += sVarf_init(&sVarf_d5Xdc7XF, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_SoundScraper::~Heavy_SoundScraper() {
  cPack_free(&cPack_IgxbbTx7);
  cPack_free(&cPack_W23DECPO);
  cPack_free(&cPack_bDY1cuAj);
  cPack_free(&cPack_B79tBmzC);
  cPack_free(&cPack_T57rZjw3);
  cPack_free(&cPack_7L2pgzHj);
  hTable_free(&hTable_ceQ9QuNA);
  cPack_free(&cPack_piirR5JZ);
  cPack_free(&cPack_tOyN0Gjy);
  cPack_free(&cPack_4iaIHis5);
  cPack_free(&cPack_pdBYY8St);
  cPack_free(&cPack_nToIjZzo);
  cPack_free(&cPack_YDPrQHxG);
  hTable_free(&hTable_7wRHRReH);
  cPack_free(&cPack_XHazheC5);
  cPack_free(&cPack_swVSa0y7);
  cPack_free(&cPack_GHTfcJPU);
  cPack_free(&cPack_rrQfTZgn);
  cPack_free(&cPack_jrEC6nB1);
  cPack_free(&cPack_0wAeGhld);
  hTable_free(&hTable_siO20AT6);
  cPack_free(&cPack_63bWuysM);
  cPack_free(&cPack_C12c4gDc);
  cPack_free(&cPack_w8eIN2zG);
  cPack_free(&cPack_EZrqJn3i);
  cPack_free(&cPack_bnGE3sMi);
  cPack_free(&cPack_9UZZCODM);
  hTable_free(&hTable_jMxmuK8G);
  cPack_free(&cPack_4NS0pbix);
  cPack_free(&cPack_W4OqzlDa);
  cPack_free(&cPack_pQTZkrIu);
  cPack_free(&cPack_E2yLb7b2);
  cPack_free(&cPack_ldjFJthh);
  cPack_free(&cPack_AKsbjDOX);
  cPack_free(&cPack_cvetfj9F);
  cPack_free(&cPack_TwcOGk3U);
  hTable_free(&hTable_amCL36fy);
  hTable_free(&hTable_UYG6pvuw);
  hTable_free(&hTable_z3kP5qh2);
  hTable_free(&hTable_TFx144L5);
  hTable_free(&hTable_gQNN9nGV);
  hTable_free(&hTable_1xHT5NDV);
  cPack_free(&cPack_eoMjGEAu);
  cPack_free(&cPack_ZieZL1xR);
  hTable_free(&hTable_oRoHtg9E);
  hTable_free(&hTable_3s6UTbxa);
  cPack_free(&cPack_qG9WTs91);
  cPack_free(&cPack_WE1w8xe6);
  cPack_free(&cPack_ae3xyAfY);
  hTable_free(&hTable_EfQ3r6vv);
  hTable_free(&hTable_29SNVBBY);
  hTable_free(&hTable_xRTC2smU);
  hTable_free(&hTable_rOK83OZK);
  cPack_free(&cPack_KRvfoe96);
  cPack_free(&cPack_f2lH268q);
  hTable_free(&hTable_XJkV9INz);
  hTable_free(&hTable_d8pDnroX);
  hTable_free(&hTable_3hU40Lfe);
  hTable_free(&hTable_Qk4Aw7or);
  hTable_free(&hTable_j4I5AoYy);
  hTable_free(&hTable_gYNAhlyb);
  cPack_free(&cPack_7Wdneohs);
  cPack_free(&cPack_W4ch99U0);
  cPack_free(&cPack_WF2ByexI);
  cPack_free(&cPack_Q3zcj6Kc);
  hTable_free(&hTable_PLZ3kGJM);
  hTable_free(&hTable_81Fwh5Ik);
  hTable_free(&hTable_ftHhTyVL);
  hTable_free(&hTable_7EeCKKBz);
  hTable_free(&hTable_FLvNlyM6);
  cPack_free(&cPack_EQfGpw4o);
  cPack_free(&cPack_ImCmEvxS);
  hTable_free(&hTable_LfXGvwTh);
  hTable_free(&hTable_f71PlYKv);
  hTable_free(&hTable_1NYZsr90);
  hTable_free(&hTable_uhLL7yho);
  hTable_free(&hTable_uyDJyNjy);
  hTable_free(&hTable_xFxj5K73);
  cPack_free(&cPack_u9IBeWUl);
  hTable_free(&hTable_M3hk39fh);
  cPack_free(&cPack_X4Sq55vo);
  cPack_free(&cPack_79PXwRbh);
  cPack_free(&cPack_J0axeTcT);
  cExpr_free(&cExpr_Wu4O9RP8);
  hTable_free(&hTable_7oIywVCj);
}

HvTable *Heavy_SoundScraper::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x58D371AD: return &hTable_ceQ9QuNA; // 1013_default
    case 0x565019FD: return &hTable_7wRHRReH; // 1051_default
    case 0x262582C8: return &hTable_siO20AT6; // 1089_default
    case 0x161BC6D4: return &hTable_jMxmuK8G; // 1127_default
    case 0x9BCAD111: return &hTable_amCL36fy; // bowl
    case 0x782CD90: return &hTable_UYG6pvuw; // crotale
    case 0x53C964B5: return &hTable_z3kP5qh2; // gong
    case 0xAC13AE99: return &hTable_TFx144L5; // marimba
    case 0x1FD931DF: return &hTable_gQNN9nGV; // xylo
    case 0x6F52CA74: return &hTable_1xHT5NDV; // almglocken
    case 0xE52DB2F5: return &hTable_oRoHtg9E; // del-1228-del
    case 0x7877CEE7: return &hTable_3s6UTbxa; // del-1257-del1
    case 0xE3492292: return &hTable_EfQ3r6vv; // del-1318-del1
    case 0x2DF102BD: return &hTable_29SNVBBY; // del-1318-del2
    case 0xEBD4F3B1: return &hTable_xRTC2smU; // del-1318-del3
    case 0x447E84A6: return &hTable_rOK83OZK; // del-1318-del4
    case 0xE998EFF7: return &hTable_XJkV9INz; // del-1318-ref6
    case 0xD5FADC2B: return &hTable_d8pDnroX; // del-1318-ref5
    case 0x56C3B41A: return &hTable_3hU40Lfe; // del-1318-ref4
    case 0x6832F2BA: return &hTable_Qk4Aw7or; // del-1318-ref3
    case 0x9EC1C279: return &hTable_j4I5AoYy; // del-1318-ref2
    case 0x4118789A: return &hTable_gYNAhlyb; // del-1318-ref1
    case 0x29E6AB85: return &hTable_PLZ3kGJM; // del-1436-del
    case 0xB9E5E01C: return &hTable_81Fwh5Ik; // del-1499-del1
    case 0x63C2268: return &hTable_ftHhTyVL; // del-1499-del2
    case 0xDBF320BC: return &hTable_7EeCKKBz; // del-1499-del3
    case 0x225643E: return &hTable_FLvNlyM6; // del-1499-del4
    case 0xB93A9FFB: return &hTable_LfXGvwTh; // del-1499-ref6
    case 0xAD23DE07: return &hTable_f71PlYKv; // del-1499-ref5
    case 0x76D4D2B8: return &hTable_1NYZsr90; // del-1499-ref4
    case 0x93E20AE1: return &hTable_uhLL7yho; // del-1499-ref3
    case 0x48A066F: return &hTable_uyDJyNjy; // del-1499-ref2
    case 0x73942DD6: return &hTable_xFxj5K73; // del-1499-ref1
    case 0x63F3A24F: return &hTable_M3hk39fh; // del-1598-del1
    case 0x93F54B3C: return &hTable_7oIywVCj; // 1674_default
    default: return nullptr;
  }
}

void Heavy_SoundScraper::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0x676151E5: { // 1005-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_DNjqk3UM_sendMessage);
      break;
    }
    case 0x4518BA34: { // 1005-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_H9BHVkDc_sendMessage);
      break;
    }
    case 0xF2645EF2: { // 1013-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WcE88BIr_sendMessage);
      break;
    }
    case 0x349D3D62: { // 1013-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_PCM1uxC7_sendMessage);
      break;
    }
    case 0x6AE0114A: { // 1013-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7HBi5u7c_sendMessage);
      break;
    }
    case 0x14D190E8: { // 1013-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_fCf0x2Jq_sendMessage);
      break;
    }
    case 0xC268AA1B: { // 1013-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_XQTzou6E_sendMessage);
      break;
    }
    case 0xE7AF8038: { // 1013-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_fmDgQybQ_sendMessage);
      break;
    }
    case 0x64DCFC2F: { // 1013-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EYKkvHFY_sendMessage);
      break;
    }
    case 0x76EF1A3A: { // 1051-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_CR9nAzwW_sendMessage);
      break;
    }
    case 0x7AB5A036: { // 1051-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_cQ4iDoKO_sendMessage);
      break;
    }
    case 0x729AEC23: { // 1051-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Vo0k0SLh_sendMessage);
      break;
    }
    case 0x78E1F133: { // 1051-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_yG0OGGFa_sendMessage);
      break;
    }
    case 0x6CE4754: { // 1051-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_28QRvpe5_sendMessage);
      break;
    }
    case 0xFD6A3B2A: { // 1051-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_W7lhEMOP_sendMessage);
      break;
    }
    case 0x6CE9CED9: { // 1051-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_E59rlgCX_sendMessage);
      break;
    }
    case 0xFA29A439: { // 1089-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_MU9CtXOL_sendMessage);
      break;
    }
    case 0xAA863EF6: { // 1089-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UYoZ4LEK_sendMessage);
      break;
    }
    case 0xAAA0A75E: { // 1089-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_tKFoZgd1_sendMessage);
      break;
    }
    case 0xCB432715: { // 1089-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RQkxS75Y_sendMessage);
      break;
    }
    case 0xB7D5A2D4: { // 1089-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2HP2M7U2_sendMessage);
      break;
    }
    case 0xBBC64E67: { // 1089-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ed1ZXPQk_sendMessage);
      break;
    }
    case 0x720CB109: { // 1089-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_pwD37V0x_sendMessage);
      break;
    }
    case 0x49109026: { // 1127-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YI1OkFFM_sendMessage);
      break;
    }
    case 0x1ED22B32: { // 1127-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8p6suCTx_sendMessage);
      break;
    }
    case 0xB70E01AA: { // 1127-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mTcEXrbq_sendMessage);
      break;
    }
    case 0x47F0CA40: { // 1127-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_w374SGYK_sendMessage);
      break;
    }
    case 0x212E3ED2: { // 1127-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_fUUemDKx_sendMessage);
      break;
    }
    case 0xD654287F: { // 1127-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UzSVeQZO_sendMessage);
      break;
    }
    case 0x4B190B33: { // 1127-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_aT6SSRYd_sendMessage);
      break;
    }
    case 0x1345C8C4: { // 1165-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7EebAh28_sendMessage);
      break;
    }
    case 0x352D518B: { // 1165-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_U5a6KK2m_sendMessage);
      break;
    }
    case 0x1B80BC63: { // 1173-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_d567VDRH_sendMessage);
      break;
    }
    case 0x85C9C328: { // 1173-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xiKPPpdb_sendMessage);
      break;
    }
    case 0x7FA13EC5: { // 1183-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_AI2JReoa_sendMessage);
      break;
    }
    case 0xD9AC1997: { // 1183-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8iVWwQQZ_sendMessage);
      break;
    }
    case 0xE3801E94: { // 1191-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jvY0hAW0_sendMessage);
      break;
    }
    case 0x4DA02B5A: { // 1191-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zfBOUqGM_sendMessage);
      break;
    }
    case 0x8DC08092: { // 1417-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Gbqetf5p_sendMessage);
      break;
    }
    case 0xA51F5BFF: { // 1417-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_HkBRXcJh_sendMessage);
      break;
    }
    case 0x382EB97A: { // 1626-bend
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_LCvspGBQ_sendMessage);
      break;
    }
    case 0xD613858: { // 1626-chunk-size
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NrPJjStY_sendMessage);
      break;
    }
    case 0x2952A082: { // 1626-level
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_OFHV3Wae_sendMessage);
      break;
    }
    case 0xCC3056CB: { // 1626-loopstart
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UnzLi4Sb_sendMessage);
      break;
    }
    case 0x484C6410: { // 1626-pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_GCKL6sTs_sendMessage);
      break;
    }
    case 0x83CDC26B: { // 1626-reset
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NMT6WM1H_sendMessage);
      break;
    }
    case 0xD475E50C: { // 1626-sample
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_1uJpXrOx_sendMessage);
      break;
    }
    case 0xAFE56AD8: { // 1626-sample-pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RgdYQmKY_sendMessage);
      break;
    }
    case 0x739592F2: { // 1626-start
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7t5fPbvs_sendMessage);
      break;
    }
    case 0x31B2C381: { // 1626-stop
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_wlK28fcT_sendMessage);
      break;
    }
    case 0xD2002891: { // 1626-table
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_0LNExEPw_sendMessage);
      break;
    }
    case 0xEA3AE85E: { // 1626-transposition
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_r1xblk35_sendMessage);
      break;
    }
    case 0x692F7CB8: { // 1674-cents
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_32BwWPVb_sendMessage);
      break;
    }
    case 0x72CEA287: { // 1674-chunk-size
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_eBfzSXPm_sendMessage);
      break;
    }
    case 0xA99117E0: { // 1674-chunk-size-samples
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_9EnESZLv_sendMessage);
      break;
    }
    case 0xEA9C1FF4: { // 1674-read-point
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_PNKBZpev_sendMessage);
      break;
    }
    case 0x995DB636: { // 1674-read-pt
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_L3U17zaA_sendMessage);
      break;
    }
    case 0xD40026D1: { // 1674-size
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_1Ryv7W5c_sendMessage);
      break;
    }
    case 0x2460F295: { // 1674-table
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_aQfICTuo_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ZjLtdyuY_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_XcxYcXUV_sendMessage);
      break;
    }
    case 0x40AA4AF1: { // changesound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qIUgtov0_sendMessage);
      break;
    }
    case 0xA41806F7: { // distortlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_QdTahO2g_sendMessage);
      break;
    }
    case 0xFCD12E4C: { // mastervolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qkjeZqTp_sendMessage);
      break;
    }
    case 0xEF5F3308: { // panTranslation
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_79wejaji_sendMessage);
      break;
    }
    case 0x8B2148DD: { // pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_CxBBmUQ6_sendMessage);
      break;
    }
    case 0x4409C659: { // processeffects
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_HgZaT4cB_sendMessage);
      break;
    }
    case 0x7B795C5A: { // resetsing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YTOooiKX_sendMessage);
      break;
    }
    case 0xA987B741: { // reverbvolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_909wVkaQ_sendMessage);
      break;
    }
    case 0x7FFAC478: { // sampleNameFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_sbOb3eYG_sendMessage);
      break;
    }
    case 0x62D6FDDE: { // selectsound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_DMCzyIRi_sendMessage);
      break;
    }
    case 0x7AAE6786: { // sinPanAngle
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_nGTK2DON_sendMessage);
      break;
    }
    case 0x6731B2E0: { // sing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_wLnGyhnT_sendMessage);
      break;
    }
    case 0x57292445: { // singlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_gwhRNYli_sendMessage);
      break;
    }
    case 0xC7DE3B07: { // singpitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JHPQCjK7_sendMessage);
      break;
    }
    case 0x853B1BE7: { // velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_nw0MBJwa_sendMessage);
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


void Heavy_SoundScraper::cVar_2h0Uh776_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_lKNjrLfM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_K5yoJiXC_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bkpPYwKO_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Ox6WpxKg_sendMessage);
}

void Heavy_SoundScraper::cIf_LO8k9a4b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_5LlSaZGx_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_qeSVOWst_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_5o9kwLgB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_gcmsU87E, HV_BINOP_POW, 0, m, &cBinop_gcmsU87E_sendMessage);
}

void Heavy_SoundScraper::cBinop_gcmsU87E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_IgxbbTx7, 0, m, &cPack_IgxbbTx7_sendMessage);
}

void Heavy_SoundScraper::cBinop_J1y4gNkE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_jWvAgGLY_sendMessage);
}

void Heavy_SoundScraper::cCast_Ox6WpxKg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_LO8k9a4b, 0, m, &cIf_LO8k9a4b_sendMessage);
}

void Heavy_SoundScraper::cCast_bkpPYwKO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_MIbkBe9W_sendMessage);
}

void Heavy_SoundScraper::cBinop_MIbkBe9W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_LO8k9a4b, 1, m, &cIf_LO8k9a4b_sendMessage);
}

void Heavy_SoundScraper::cBinop_qeSVOWst_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_J1y4gNkE_sendMessage);
}

void Heavy_SoundScraper::cMsg_5LlSaZGx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_IgxbbTx7, 0, m, &cPack_IgxbbTx7_sendMessage);
}

void Heavy_SoundScraper::cBinop_jWvAgGLY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gcmsU87E, HV_BINOP_POW, 1, m, &cBinop_gcmsU87E_sendMessage);
  cMsg_5o9kwLgB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_IgxbbTx7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_PRxRrdbY, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_0tCFaBTJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_lZokyakL_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_K5yoJiXC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_yJJ8fiM8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_yJJ8fiM8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_DNjqk3UM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_lZokyakL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_H9BHVkDc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_K5Sr845e_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_SQZMtDw7, 0, m, &cSlice_SQZMtDw7_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_n3Aps0Yj, 0, m, &cRandom_n3Aps0Yj_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_3J2HPrsX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_51CTNpU8_sendMessage);
}

void Heavy_SoundScraper::cUnop_51CTNpU8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_2eqyZH8f_sendMessage);
}

void Heavy_SoundScraper::cRandom_n3Aps0Yj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_3J2HPrsX_sendMessage);
}

void Heavy_SoundScraper::cSlice_SQZMtDw7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_n3Aps0Yj, 1, m, &cRandom_n3Aps0Yj_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_Syk048HW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aQgkKa9T, HV_BINOP_DIVIDE, 0, m, &cBinop_aQgkKa9T_sendMessage);
}

void Heavy_SoundScraper::cBinop_36J9E6r6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_vUWcPBLK_sendMessage);
}

void Heavy_SoundScraper::cBinop_vUWcPBLK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rxs6Og9A, HV_BINOP_POW, 1, m, &cBinop_rxs6Og9A_sendMessage);
  cMsg_BYzDx7n8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_rxs6Og9A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_Syk048HW_sendMessage);
}

void Heavy_SoundScraper::cMsg_BYzDx7n8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_rxs6Og9A, HV_BINOP_POW, 0, m, &cBinop_rxs6Og9A_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_oAwHEq3q_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_UgRKejiy, 0, m, &cSlice_UgRKejiy_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_5WfrWILh, 0, m, &cRandom_5WfrWILh_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_SDxK1Va3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_9mPeMGxv_sendMessage);
}

void Heavy_SoundScraper::cUnop_9mPeMGxv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_4TaTQtm0_sendMessage);
}

void Heavy_SoundScraper::cRandom_5WfrWILh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_SDxK1Va3_sendMessage);
}

void Heavy_SoundScraper::cSlice_UgRKejiy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_5WfrWILh, 1, m, &cRandom_5WfrWILh_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_3E0hLPsR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_R6pX4Wui_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_DDRuaejs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_6Fc7NsJ9_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_E3CYFz6Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_bDY1cuAj, 0, m, &cPack_bDY1cuAj_sendMessage);
}

void Heavy_SoundScraper::cUnop_H4NoB8v7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_W23DECPO, 0, m, &cPack_W23DECPO_sendMessage);
}

void Heavy_SoundScraper::cPack_W23DECPO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Pde39p7Q, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_bDY1cuAj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_G6aTEmZn, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_apC55cWr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_E3CYFz6Q_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_H4NoB8v7_sendMessage);
}

void Heavy_SoundScraper::cMsg_rltx3JmI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_apC55cWr_sendMessage);
}

void Heavy_SoundScraper::cCast_9wt6WHLd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_GIYs6YNp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WyHt0j2Q_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_roITBWLh_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2zy8lhCr_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_ryk3Qgcu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_WO4gFu3T_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_WO4gFu3T_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_DZLFltpN, 1, m, &cDelay_DZLFltpN_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8ctBeDat_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_DZLFltpN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DZLFltpN, m);
  cVar_onMessage(_c, &Context(_c)->cVar_dFATVY1t, 0, m, &cVar_dFATVY1t_sendMessage);
}

void Heavy_SoundScraper::cMsg_WO4gFu3T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_DZLFltpN, 0, m, &cDelay_DZLFltpN_sendMessage);
}

void Heavy_SoundScraper::cCast_8ctBeDat_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_DZLFltpN, 0, m, &cDelay_DZLFltpN_sendMessage);
}

void Heavy_SoundScraper::cVar_dFATVY1t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4Ve9gTFV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_NAOTjJMF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GIYs6YNp, 0, m, &cVar_GIYs6YNp_sendMessage);
}

void Heavy_SoundScraper::cSend_bRxNuNaz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_SyzvTiiF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_7HBi5u7c_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_t1xo40GW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_bRxNuNaz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_Yt4DU51J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_SyzvTiiF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_5P31A5hR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_EYKkvHFY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_vbOpwuyT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_5P31A5hR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_7bGITYBy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_EYKkvHFY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_42RBAmZl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ndtWHWbl, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_4Ve9gTFV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_ndtWHWbl, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_roITBWLh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dFATVY1t, 1, m, &cVar_dFATVY1t_sendMessage);
}

void Heavy_SoundScraper::cCast_2zy8lhCr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ryk3Qgcu_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_WyHt0j2Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_42RBAmZl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_jgqlhHX6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100000.0f, 0, m, &cBinop_XjLjzUkU_sendMessage);
}

void Heavy_SoundScraper::cVar_1E2PfF8X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_PbcsclxI_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_bm1GxxJh_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_yjA3fyoS_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_yjA3fyoS_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_4KDiJL3J, 1, m, &cDelay_4KDiJL3J_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LEWi0ki9_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_4KDiJL3J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4KDiJL3J, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vn6AWMQV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DLHgPcaA_sendMessage);
}

void Heavy_SoundScraper::cMsg_yjA3fyoS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_4KDiJL3J, 0, m, &cDelay_4KDiJL3J_sendMessage);
}

void Heavy_SoundScraper::cCast_LEWi0ki9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_4KDiJL3J, 0, m, &cDelay_4KDiJL3J_sendMessage);
}

void Heavy_SoundScraper::cPack_B79tBmzC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_tTT9UZzQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_T57rZjw3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ggNlqgll_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_7L2pgzHj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lt80MFAJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_tTohaA88_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_T57rZjw3, 0, m, &cPack_T57rZjw3_sendMessage);
}

void Heavy_SoundScraper::cVar_TMQXX1zz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_GoAyydBO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3B2XwYzD, HV_BINOP_DIVIDE, 1, m, &cBinop_3B2XwYzD_sendMessage);
}

void Heavy_SoundScraper::cVar_OpQmf9GU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3B2XwYzD, HV_BINOP_DIVIDE, 0, m, &cBinop_3B2XwYzD_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_PbcsclxI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MP5sgNdw_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6ji5Bz6H_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MnRKUfc0_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gZeJlPfG_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_6ji5Bz6H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OpQmf9GU, 0, m, &cVar_OpQmf9GU_sendMessage);
}

void Heavy_SoundScraper::cCast_MP5sgNdw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GoAyydBO, 0, m, &cVar_GoAyydBO_sendMessage);
}

void Heavy_SoundScraper::cCast_gZeJlPfG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OpQmf9GU, 0, m, &cVar_OpQmf9GU_sendMessage);
}

void Heavy_SoundScraper::cCast_MnRKUfc0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GoAyydBO, 0, m, &cVar_GoAyydBO_sendMessage);
}

void Heavy_SoundScraper::cCast_DLHgPcaA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tTohaA88, 0, m, &cVar_tTohaA88_sendMessage);
}

void Heavy_SoundScraper::cCast_vn6AWMQV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1E2PfF8X, 0, m, &cVar_1E2PfF8X_sendMessage);
}

void Heavy_SoundScraper::cSend_wHoXi6Tq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_PCM1uxC7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_ggNlqgll_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_WcE88BIr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_tTT9UZzQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_WcE88BIr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_hGcs9tgI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_B79tBmzC, 0, m, &cPack_B79tBmzC_sendMessage);
}

void Heavy_SoundScraper::cCast_DwBLQxLu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_bm1GxxJh_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_XjLjzUkU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_7L2pgzHj, 0, m, &cPack_7L2pgzHj_sendMessage);
}

void Heavy_SoundScraper::cBinop_v6ZawbLV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_7L2pgzHj, 1, m, &cPack_7L2pgzHj_sendMessage);
}

void Heavy_SoundScraper::cMsg_lt80MFAJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSend_wHoXi6Tq_sendMessage(_c, 0, m);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSend_wHoXi6Tq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_H27OKJHh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hGcs9tgI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DwBLQxLu_sendMessage);
}

void Heavy_SoundScraper::cCast_YVrzbkZQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cCast_NS1vJPwh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1E2PfF8X, 1, m, &cVar_1E2PfF8X_sendMessage);
}

void Heavy_SoundScraper::cBinop_3B2XwYzD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jgqlhHX6, 0, m, &cVar_jgqlhHX6_sendMessage);
}

void Heavy_SoundScraper::cMsg_5sYt4vyT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_v6ZawbLV_sendMessage);
}

void Heavy_SoundScraper::cSlice_j01okeAy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_vYcHslsP_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_GeeT22px_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YVrzbkZQ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NS1vJPwh_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_H27OKJHh_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_TMQXX1zz, 0, m, &cVar_TMQXX1zz_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_DJau1mlp_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_xC5pmgEI, 0, m, &cSlice_xC5pmgEI_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_YM7jReps_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9VZa4E8d_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_rvcRt0Oi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_fSTUFHmP_sendMessage);
}

void Heavy_SoundScraper::cBinop_fSTUFHmP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_3GiXktsj, m);
}

void Heavy_SoundScraper::cMsg_9VZa4E8d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rvcRt0Oi_sendMessage);
}

void Heavy_SoundScraper::cSlice_xC5pmgEI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_JJz0K9bS, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_yxf0z2nC, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_YM7jReps, 0, m, &cVar_YM7jReps_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_uR0T5SUa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_5Zg7AhNZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_Kg316Csk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 44100.0f, 0, m, &cBinop_GIGH4Mq9_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_9IZ3GKPr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_KI0xS9hr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cMsg_vYcHslsP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_DJau1mlp_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::hTable_ceQ9QuNA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cBinop_5Zg7AhNZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9IZ3GKPr, 0, m, &cVar_9IZ3GKPr_sendMessage);
}

void Heavy_SoundScraper::cBinop_GIGH4Mq9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KI0xS9hr, 0, m, &cVar_KI0xS9hr_sendMessage);
}

void Heavy_SoundScraper::cSlice_lsDM8HNQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_EHSdkqqj_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_R5nAmq1w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZZu3DBif_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_36J9E6r6_sendMessage);
      cPrint_onMessage(_c, m, "PERCSAMPLER_NOTE");
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_nWT84UvH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_piirR5JZ, 1, m, &cPack_piirR5JZ_sendMessage);
}

void Heavy_SoundScraper::cPack_piirR5JZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ykhJ0FPE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lCZYsfAF_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_j01okeAy, 0, m, &cSlice_j01okeAy_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_GeeT22px, 0, m, &cSlice_GeeT22px_sendMessage);
  cPrint_onMessage(_c, m, "TABLEPLAYER_COMMAND");
}

void Heavy_SoundScraper::cCast_aDdEAruq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_piirR5JZ, 0, m, &cPack_piirR5JZ_sendMessage);
}

void Heavy_SoundScraper::cCast_LQkW2B4f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nWT84UvH, 0, m, &cVar_nWT84UvH_sendMessage);
}

void Heavy_SoundScraper::cBinop_2eqyZH8f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_keKN9lWT_sendMessage);
}

void Heavy_SoundScraper::cBinop_keKN9lWT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_apC55cWr_sendMessage);
}

void Heavy_SoundScraper::cBinop_EHSdkqqj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_g23btBZJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_kFfFIVp8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LQkW2B4f_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aDdEAruq_sendMessage);
}

void Heavy_SoundScraper::cBinop_4TaTQtm0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_k8u0ZpAM_sendMessage);
}

void Heavy_SoundScraper::cBinop_k8u0ZpAM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kFfFIVp8, HV_BINOP_MULTIPLY, 1, m, &cBinop_kFfFIVp8_sendMessage);
}

void Heavy_SoundScraper::cCast_ZZu3DBif_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_oAwHEq3q_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_ykhJ0FPE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_K5Sr845e_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9wt6WHLd_sendMessage);
}

void Heavy_SoundScraper::cCast_lCZYsfAF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NAOTjJMF_sendMessage);
}

void Heavy_SoundScraper::cSend_6Fc7NsJ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_XQTzou6E_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_R6pX4Wui_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_fCf0x2Jq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_aQgkKa9T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kFfFIVp8, HV_BINOP_MULTIPLY, 0, m, &cBinop_kFfFIVp8_sendMessage);
}

void Heavy_SoundScraper::cSend_g23btBZJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_fmDgQybQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_8GTBwJob_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_JUXUi1h3, 0, m, &cSlice_JUXUi1h3_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_xSAgXEqq, 0, m, &cRandom_xSAgXEqq_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_dEBsYqtF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_HTEI47bg_sendMessage);
}

void Heavy_SoundScraper::cUnop_HTEI47bg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_i4aRxBd8_sendMessage);
}

void Heavy_SoundScraper::cRandom_xSAgXEqq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_dEBsYqtF_sendMessage);
}

void Heavy_SoundScraper::cSlice_JUXUi1h3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_xSAgXEqq, 1, m, &cRandom_xSAgXEqq_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_HbmHX97e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YnAnRMqN, HV_BINOP_DIVIDE, 0, m, &cBinop_YnAnRMqN_sendMessage);
}

void Heavy_SoundScraper::cBinop_MLpFEQng_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_MM2CW567_sendMessage);
}

void Heavy_SoundScraper::cBinop_MM2CW567_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vtQjhXYh, HV_BINOP_POW, 1, m, &cBinop_vtQjhXYh_sendMessage);
  cMsg_kbLFZ5hl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_vtQjhXYh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_HbmHX97e_sendMessage);
}

void Heavy_SoundScraper::cMsg_kbLFZ5hl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_vtQjhXYh, HV_BINOP_POW, 0, m, &cBinop_vtQjhXYh_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_M1EiOoHL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_CfZ6o2xf, 0, m, &cSlice_CfZ6o2xf_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_u2EhvR7X, 0, m, &cRandom_u2EhvR7X_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_ZEe3oizP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_qckboyHw_sendMessage);
}

void Heavy_SoundScraper::cUnop_qckboyHw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_3uVnbb49_sendMessage);
}

void Heavy_SoundScraper::cRandom_u2EhvR7X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_ZEe3oizP_sendMessage);
}

void Heavy_SoundScraper::cSlice_CfZ6o2xf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_u2EhvR7X, 1, m, &cRandom_u2EhvR7X_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_HjGSsOiG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_sTB9qXEA_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_DKegY29b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_hxNSNuyC_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_KPxoIhjS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_4iaIHis5, 0, m, &cPack_4iaIHis5_sendMessage);
}

void Heavy_SoundScraper::cUnop_O9gqU689_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_tOyN0Gjy, 0, m, &cPack_tOyN0Gjy_sendMessage);
}

void Heavy_SoundScraper::cPack_tOyN0Gjy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_T6Mlz6Y1, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_4iaIHis5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_i1ex9pJ7, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_wOUnoVwp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_KPxoIhjS_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_O9gqU689_sendMessage);
}

void Heavy_SoundScraper::cMsg_XxMqmjEe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_wOUnoVwp_sendMessage);
}

void Heavy_SoundScraper::cCast_9MidfgRL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_2JhScW0D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1sCBEzAw_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_b00LUOH5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_p0VDZ4S7_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_KACqhHzn_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_QJBnQmQp_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_QJBnQmQp_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_i7ke7hny, 1, m, &cDelay_i7ke7hny_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2ndkf9fE_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_i7ke7hny_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_i7ke7hny, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4zLJzuIg, 0, m, &cVar_4zLJzuIg_sendMessage);
}

void Heavy_SoundScraper::cMsg_QJBnQmQp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_i7ke7hny, 0, m, &cDelay_i7ke7hny_sendMessage);
}

void Heavy_SoundScraper::cCast_2ndkf9fE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_i7ke7hny, 0, m, &cDelay_i7ke7hny_sendMessage);
}

void Heavy_SoundScraper::cVar_4zLJzuIg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nIdCS5oD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_M7pT65aX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2JhScW0D, 0, m, &cVar_2JhScW0D_sendMessage);
}

void Heavy_SoundScraper::cSend_FeFdOhfi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_47tMaPj4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Vo0k0SLh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_iq3qQUj0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_FeFdOhfi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_2cc7htRO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_47tMaPj4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_tk1Y194m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_E59rlgCX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_Mmhiy5Wr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_tk1Y194m_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_0pFpzUtk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_E59rlgCX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_3pVdMjj2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_syzJTS98, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_nIdCS5oD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_syzJTS98, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_b00LUOH5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4zLJzuIg, 1, m, &cVar_4zLJzuIg_sendMessage);
}

void Heavy_SoundScraper::cCast_1sCBEzAw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3pVdMjj2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_p0VDZ4S7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_KACqhHzn_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_dkAF7ILJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100000.0f, 0, m, &cBinop_3k8HkHjv_sendMessage);
}

void Heavy_SoundScraper::cVar_aXk7hnS5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_zUivPdcQ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_khEaHmPF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_mlUD1qpZ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_mlUD1qpZ_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_HwRqHMpE, 1, m, &cDelay_HwRqHMpE_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WUnQNUzV_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_HwRqHMpE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HwRqHMpE, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Vb67dfSG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XJol5Ibg_sendMessage);
}

void Heavy_SoundScraper::cMsg_mlUD1qpZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_HwRqHMpE, 0, m, &cDelay_HwRqHMpE_sendMessage);
}

void Heavy_SoundScraper::cCast_WUnQNUzV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_HwRqHMpE, 0, m, &cDelay_HwRqHMpE_sendMessage);
}

void Heavy_SoundScraper::cPack_pdBYY8St_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_q47TOJsE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_nToIjZzo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_sY4GMKN5_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_YDPrQHxG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ehoW9Myr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_tBV5VHTX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_nToIjZzo, 0, m, &cPack_nToIjZzo_sendMessage);
}

void Heavy_SoundScraper::cVar_nmV0iIeU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_GRQx4o0B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sBNwwEwQ, HV_BINOP_DIVIDE, 1, m, &cBinop_sBNwwEwQ_sendMessage);
}

void Heavy_SoundScraper::cVar_U1wH9rP2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sBNwwEwQ, HV_BINOP_DIVIDE, 0, m, &cBinop_sBNwwEwQ_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_zUivPdcQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wy7w2FlX_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_18umC7Ao_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XnYOIQpd_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EH2yv1fJ_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_18umC7Ao_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_U1wH9rP2, 0, m, &cVar_U1wH9rP2_sendMessage);
}

void Heavy_SoundScraper::cCast_wy7w2FlX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GRQx4o0B, 0, m, &cVar_GRQx4o0B_sendMessage);
}

void Heavy_SoundScraper::cCast_EH2yv1fJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_U1wH9rP2, 0, m, &cVar_U1wH9rP2_sendMessage);
}

void Heavy_SoundScraper::cCast_XnYOIQpd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GRQx4o0B, 0, m, &cVar_GRQx4o0B_sendMessage);
}

void Heavy_SoundScraper::cCast_Vb67dfSG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aXk7hnS5, 0, m, &cVar_aXk7hnS5_sendMessage);
}

void Heavy_SoundScraper::cCast_XJol5Ibg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tBV5VHTX, 0, m, &cVar_tBV5VHTX_sendMessage);
}

void Heavy_SoundScraper::cSend_lUguhBwb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_cQ4iDoKO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_sY4GMKN5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_CR9nAzwW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_q47TOJsE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_CR9nAzwW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_IZeyMMFL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_pdBYY8St, 0, m, &cPack_pdBYY8St_sendMessage);
}

void Heavy_SoundScraper::cCast_nJsb84EJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_khEaHmPF_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_3k8HkHjv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_YDPrQHxG, 0, m, &cPack_YDPrQHxG_sendMessage);
}

void Heavy_SoundScraper::cBinop_QveqqoSZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_YDPrQHxG, 1, m, &cPack_YDPrQHxG_sendMessage);
}

void Heavy_SoundScraper::cMsg_ehoW9Myr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSend_lUguhBwb_sendMessage(_c, 0, m);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSend_lUguhBwb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_uYguoAkl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IZeyMMFL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nJsb84EJ_sendMessage);
}

void Heavy_SoundScraper::cCast_9MQcwqK8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cCast_VbFBGt0D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aXk7hnS5, 1, m, &cVar_aXk7hnS5_sendMessage);
}

void Heavy_SoundScraper::cBinop_sBNwwEwQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dkAF7ILJ, 0, m, &cVar_dkAF7ILJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_vVR2GmkZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_QveqqoSZ_sendMessage);
}

void Heavy_SoundScraper::cSlice_1ZFEDvJ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_tLjDWpXI_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_9j4Sl9B4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9MQcwqK8_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_VbFBGt0D_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uYguoAkl_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_nmV0iIeU, 0, m, &cVar_nmV0iIeU_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_87pRNfpt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Si0Z6UvF, 0, m, &cSlice_Si0Z6UvF_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_k7Fj0yOb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JgzmyglP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_p5E5aCjp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_fpq5KkII_sendMessage);
}

void Heavy_SoundScraper::cBinop_fpq5KkII_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_rbJ6mJMu, m);
}

void Heavy_SoundScraper::cMsg_JgzmyglP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_p5E5aCjp_sendMessage);
}

void Heavy_SoundScraper::cSlice_Si0Z6UvF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_7mvICwz4, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_Cp63gcdE, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_k7Fj0yOb, 0, m, &cVar_k7Fj0yOb_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_ybqVxD9K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_yNQLDvNV_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_OzfNoFZp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 44100.0f, 0, m, &cBinop_b0nS58tZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_JicBALXA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_FVLC6Azr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cMsg_tLjDWpXI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_87pRNfpt_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::hTable_7wRHRReH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cBinop_yNQLDvNV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JicBALXA, 0, m, &cVar_JicBALXA_sendMessage);
}

void Heavy_SoundScraper::cBinop_b0nS58tZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FVLC6Azr, 0, m, &cVar_FVLC6Azr_sendMessage);
}

void Heavy_SoundScraper::cSlice_fKaJ4NKP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_0lVulYUW_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_bw3tO1aC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TBf4adWB_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_MLpFEQng_sendMessage);
      cPrint_onMessage(_c, m, "PERCSAMPLER_NOTE");
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_0yteDdcT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_XHazheC5, 1, m, &cPack_XHazheC5_sendMessage);
}

void Heavy_SoundScraper::cPack_XHazheC5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rvAo993n_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UID3XUd2_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_1ZFEDvJ0, 0, m, &cSlice_1ZFEDvJ0_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_9j4Sl9B4, 0, m, &cSlice_9j4Sl9B4_sendMessage);
  cPrint_onMessage(_c, m, "TABLEPLAYER_COMMAND");
}

void Heavy_SoundScraper::cCast_1ngxdyaU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0yteDdcT, 0, m, &cVar_0yteDdcT_sendMessage);
}

void Heavy_SoundScraper::cCast_CyQIKF5x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_XHazheC5, 0, m, &cPack_XHazheC5_sendMessage);
}

void Heavy_SoundScraper::cBinop_i4aRxBd8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_zYSz4F7Z_sendMessage);
}

void Heavy_SoundScraper::cBinop_zYSz4F7Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_wOUnoVwp_sendMessage);
}

void Heavy_SoundScraper::cBinop_0lVulYUW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_9soq513F_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_AR5zpttj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1ngxdyaU_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CyQIKF5x_sendMessage);
}

void Heavy_SoundScraper::cBinop_3uVnbb49_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_qZ1iIWjp_sendMessage);
}

void Heavy_SoundScraper::cBinop_qZ1iIWjp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AR5zpttj, HV_BINOP_MULTIPLY, 1, m, &cBinop_AR5zpttj_sendMessage);
}

void Heavy_SoundScraper::cCast_TBf4adWB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_M1EiOoHL_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_UID3XUd2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_M7pT65aX_sendMessage);
}

void Heavy_SoundScraper::cCast_rvAo993n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_8GTBwJob_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9MidfgRL_sendMessage);
}

void Heavy_SoundScraper::cSend_hxNSNuyC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_28QRvpe5_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_sTB9qXEA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_yG0OGGFa_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_YnAnRMqN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AR5zpttj, HV_BINOP_MULTIPLY, 0, m, &cBinop_AR5zpttj_sendMessage);
}

void Heavy_SoundScraper::cSend_9soq513F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_W7lhEMOP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_ZcrZIZJc_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_yetpvml7, 0, m, &cSlice_yetpvml7_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_TM7ECDPY, 0, m, &cRandom_TM7ECDPY_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_SVifLnSb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_FZe9LcXA_sendMessage);
}

void Heavy_SoundScraper::cUnop_FZe9LcXA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_YOEV0dEc_sendMessage);
}

void Heavy_SoundScraper::cRandom_TM7ECDPY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_SVifLnSb_sendMessage);
}

void Heavy_SoundScraper::cSlice_yetpvml7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_TM7ECDPY, 1, m, &cRandom_TM7ECDPY_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_vBuQN0l5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fhES9jZ4, HV_BINOP_DIVIDE, 0, m, &cBinop_fhES9jZ4_sendMessage);
}

void Heavy_SoundScraper::cBinop_1ybFdZsK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_RTGmJ00T_sendMessage);
}

void Heavy_SoundScraper::cBinop_RTGmJ00T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QDc2MRQh, HV_BINOP_POW, 1, m, &cBinop_QDc2MRQh_sendMessage);
  cMsg_uDfJJEG4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_QDc2MRQh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_vBuQN0l5_sendMessage);
}

void Heavy_SoundScraper::cMsg_uDfJJEG4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_QDc2MRQh, HV_BINOP_POW, 0, m, &cBinop_QDc2MRQh_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_U6KTS3xy_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_im73BVm6, 0, m, &cSlice_im73BVm6_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_vPoJyQpS, 0, m, &cRandom_vPoJyQpS_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_QgBKl27v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_8wdALqYY_sendMessage);
}

void Heavy_SoundScraper::cUnop_8wdALqYY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_WLjcErU4_sendMessage);
}

void Heavy_SoundScraper::cRandom_vPoJyQpS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_QgBKl27v_sendMessage);
}

void Heavy_SoundScraper::cSlice_im73BVm6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_vPoJyQpS, 1, m, &cRandom_vPoJyQpS_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_Df0ixTcC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_Uex6pOVD_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_BBzctUjR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_x2inGbDt_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_a9qFqwF8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_GHTfcJPU, 0, m, &cPack_GHTfcJPU_sendMessage);
}

void Heavy_SoundScraper::cUnop_Bc5X1Q17_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_swVSa0y7, 0, m, &cPack_swVSa0y7_sendMessage);
}

void Heavy_SoundScraper::cPack_swVSa0y7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_NpAvF5mi, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_GHTfcJPU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_s7IGP6lo, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_BFACmosf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_a9qFqwF8_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_Bc5X1Q17_sendMessage);
}

void Heavy_SoundScraper::cMsg_tGaQTkSv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_BFACmosf_sendMessage);
}

void Heavy_SoundScraper::cCast_jcc9Dk26_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_33LyGD7p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OWUNq39t_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hCuwqQme_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BZOjl5x3_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_DVNGAufu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_JWXEn6Cl_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_JWXEn6Cl_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_1LJpCVvf, 1, m, &cDelay_1LJpCVvf_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_W5jHaZL4_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_1LJpCVvf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1LJpCVvf, m);
  cVar_onMessage(_c, &Context(_c)->cVar_R8AFpVnY, 0, m, &cVar_R8AFpVnY_sendMessage);
}

void Heavy_SoundScraper::cMsg_JWXEn6Cl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_1LJpCVvf, 0, m, &cDelay_1LJpCVvf_sendMessage);
}

void Heavy_SoundScraper::cCast_W5jHaZL4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_1LJpCVvf, 0, m, &cDelay_1LJpCVvf_sendMessage);
}

void Heavy_SoundScraper::cVar_R8AFpVnY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kP5BTXmw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_LVPuvfoi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_33LyGD7p, 0, m, &cVar_33LyGD7p_sendMessage);
}

void Heavy_SoundScraper::cSend_DPBPyl0G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_n1RVVlOr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_tKFoZgd1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_01h4tdPa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_DPBPyl0G_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_KnL4RaBb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_n1RVVlOr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_txdiov5P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_pwD37V0x_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_rAgRme8f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_txdiov5P_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_z4JDc2PC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_pwD37V0x_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_v8J6mbej_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_rGxkbxrG, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_kP5BTXmw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_rGxkbxrG, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_BZOjl5x3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_DVNGAufu_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_OWUNq39t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_v8J6mbej_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_hCuwqQme_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_R8AFpVnY, 1, m, &cVar_R8AFpVnY_sendMessage);
}

void Heavy_SoundScraper::cVar_cK9lINjk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100000.0f, 0, m, &cBinop_7zZiT4b4_sendMessage);
}

void Heavy_SoundScraper::cVar_bo4z3V4Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_cmAohsVP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_WqUlmCcf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_yhxIT0lQ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_yhxIT0lQ_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_P96dxXTW, 1, m, &cDelay_P96dxXTW_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lUCphsuZ_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_P96dxXTW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_P96dxXTW, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_b2OXYJ1k_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4fuMzl1A_sendMessage);
}

void Heavy_SoundScraper::cMsg_yhxIT0lQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_P96dxXTW, 0, m, &cDelay_P96dxXTW_sendMessage);
}

void Heavy_SoundScraper::cCast_lUCphsuZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_P96dxXTW, 0, m, &cDelay_P96dxXTW_sendMessage);
}

void Heavy_SoundScraper::cPack_rrQfTZgn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_kz0ft898_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_jrEC6nB1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_i8j6nzqE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_0wAeGhld_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sOgNE7Nb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_7ITbNDNg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_jrEC6nB1, 0, m, &cPack_jrEC6nB1_sendMessage);
}

void Heavy_SoundScraper::cVar_O9uzOy2s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_eEr04pD7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GF7HOdvg, HV_BINOP_DIVIDE, 1, m, &cBinop_GF7HOdvg_sendMessage);
}

void Heavy_SoundScraper::cVar_3U1pZuUm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GF7HOdvg, HV_BINOP_DIVIDE, 0, m, &cBinop_GF7HOdvg_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_cmAohsVP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GMCEvaSq_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AqGlyANN_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_io6ej19b_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TiR3oLur_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_GMCEvaSq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eEr04pD7, 0, m, &cVar_eEr04pD7_sendMessage);
}

void Heavy_SoundScraper::cCast_AqGlyANN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3U1pZuUm, 0, m, &cVar_3U1pZuUm_sendMessage);
}

void Heavy_SoundScraper::cCast_TiR3oLur_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3U1pZuUm, 0, m, &cVar_3U1pZuUm_sendMessage);
}

void Heavy_SoundScraper::cCast_io6ej19b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eEr04pD7, 0, m, &cVar_eEr04pD7_sendMessage);
}

void Heavy_SoundScraper::cCast_b2OXYJ1k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bo4z3V4Y, 0, m, &cVar_bo4z3V4Y_sendMessage);
}

void Heavy_SoundScraper::cCast_4fuMzl1A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7ITbNDNg, 0, m, &cVar_7ITbNDNg_sendMessage);
}

void Heavy_SoundScraper::cSend_5UoQ49nn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_UYoZ4LEK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_i8j6nzqE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_MU9CtXOL_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_kz0ft898_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_MU9CtXOL_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_fAHJnqvK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_WqUlmCcf_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_puaM8DIt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_rrQfTZgn, 0, m, &cPack_rrQfTZgn_sendMessage);
}

void Heavy_SoundScraper::cBinop_7zZiT4b4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_0wAeGhld, 0, m, &cPack_0wAeGhld_sendMessage);
}

void Heavy_SoundScraper::cBinop_7rSqDGjQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_0wAeGhld, 1, m, &cPack_0wAeGhld_sendMessage);
}

void Heavy_SoundScraper::cMsg_sOgNE7Nb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSend_5UoQ49nn_sendMessage(_c, 0, m);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSend_5UoQ49nn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_381hgP6l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cCast_E5ZLGsVZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bo4z3V4Y, 1, m, &cVar_bo4z3V4Y_sendMessage);
}

void Heavy_SoundScraper::cCast_haAV9dDS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_puaM8DIt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fAHJnqvK_sendMessage);
}

void Heavy_SoundScraper::cBinop_GF7HOdvg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cK9lINjk, 0, m, &cVar_cK9lINjk_sendMessage);
}

void Heavy_SoundScraper::cMsg_xLvKxhqH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_7rSqDGjQ_sendMessage);
}

void Heavy_SoundScraper::cSlice_KBKQjq6g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_NLRDA6Gz_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_N4Fc101n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_381hgP6l_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_E5ZLGsVZ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_haAV9dDS_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_O9uzOy2s, 0, m, &cVar_O9uzOy2s_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_QwG7YlLW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_hLiGoZJU, 0, m, &cSlice_hLiGoZJU_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_wvP4HmK3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yaP3vV3f_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_ulEZIsPo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_Tx5NrkOx_sendMessage);
}

void Heavy_SoundScraper::cBinop_Tx5NrkOx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_TdIqQIuP, m);
}

void Heavy_SoundScraper::cMsg_yaP3vV3f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ulEZIsPo_sendMessage);
}

void Heavy_SoundScraper::cSlice_hLiGoZJU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_PWZ9B5X7, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_FxOjctYX, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_wvP4HmK3, 0, m, &cVar_wvP4HmK3_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_N1UnJyZC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_6P3S64p9_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_bJY6kOax_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 44100.0f, 0, m, &cBinop_4ayWLDmQ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_JCtUlwLr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_dhfr4PrC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cMsg_NLRDA6Gz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_QwG7YlLW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::hTable_siO20AT6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cBinop_6P3S64p9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JCtUlwLr, 0, m, &cVar_JCtUlwLr_sendMessage);
}

void Heavy_SoundScraper::cBinop_4ayWLDmQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dhfr4PrC, 0, m, &cVar_dhfr4PrC_sendMessage);
}

void Heavy_SoundScraper::cSlice_mBfvagEW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_S6NTUpzw_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_E29p9X9W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vxaaqWAl_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_1ybFdZsK_sendMessage);
      cPrint_onMessage(_c, m, "PERCSAMPLER_NOTE");
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_Hs0HkWxb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_63bWuysM, 1, m, &cPack_63bWuysM_sendMessage);
}

void Heavy_SoundScraper::cPack_63bWuysM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OfviMVZt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jXnU690B_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_KBKQjq6g, 0, m, &cSlice_KBKQjq6g_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_N4Fc101n, 0, m, &cSlice_N4Fc101n_sendMessage);
  cPrint_onMessage(_c, m, "TABLEPLAYER_COMMAND");
}

void Heavy_SoundScraper::cCast_xNVDXGbv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Hs0HkWxb, 0, m, &cVar_Hs0HkWxb_sendMessage);
}

void Heavy_SoundScraper::cCast_wQIPCFJN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_63bWuysM, 0, m, &cPack_63bWuysM_sendMessage);
}

void Heavy_SoundScraper::cBinop_YOEV0dEc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_pteMx0Sw_sendMessage);
}

void Heavy_SoundScraper::cBinop_pteMx0Sw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_BFACmosf_sendMessage);
}

void Heavy_SoundScraper::cBinop_S6NTUpzw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_I4e6DanV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_lULqb2L5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xNVDXGbv_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wQIPCFJN_sendMessage);
}

void Heavy_SoundScraper::cBinop_WLjcErU4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_nCaoeCGC_sendMessage);
}

void Heavy_SoundScraper::cBinop_nCaoeCGC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lULqb2L5, HV_BINOP_MULTIPLY, 1, m, &cBinop_lULqb2L5_sendMessage);
}

void Heavy_SoundScraper::cCast_vxaaqWAl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_U6KTS3xy_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_jXnU690B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LVPuvfoi_sendMessage);
}

void Heavy_SoundScraper::cCast_OfviMVZt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ZcrZIZJc_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jcc9Dk26_sendMessage);
}

void Heavy_SoundScraper::cSend_x2inGbDt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_2HP2M7U2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_Uex6pOVD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RQkxS75Y_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_fhES9jZ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lULqb2L5, HV_BINOP_MULTIPLY, 0, m, &cBinop_lULqb2L5_sendMessage);
}

void Heavy_SoundScraper::cSend_I4e6DanV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ed1ZXPQk_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_TOEZY18p_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_tqW8R4Go, 0, m, &cSlice_tqW8R4Go_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_0WiuicHi, 0, m, &cRandom_0WiuicHi_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_UUIP7r2z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_cB8x1xKG_sendMessage);
}

void Heavy_SoundScraper::cUnop_cB8x1xKG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_TiYjuSul_sendMessage);
}

void Heavy_SoundScraper::cRandom_0WiuicHi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_UUIP7r2z_sendMessage);
}

void Heavy_SoundScraper::cSlice_tqW8R4Go_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_0WiuicHi, 1, m, &cRandom_0WiuicHi_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_Y1Ozfpt4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MFMyfDm0, HV_BINOP_DIVIDE, 0, m, &cBinop_MFMyfDm0_sendMessage);
}

void Heavy_SoundScraper::cBinop_pAF2tA1q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_Eou2svZ3_sendMessage);
}

void Heavy_SoundScraper::cBinop_Eou2svZ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_81RcjXOM, HV_BINOP_POW, 1, m, &cBinop_81RcjXOM_sendMessage);
  cMsg_t8ZCMPjz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_81RcjXOM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_Y1Ozfpt4_sendMessage);
}

void Heavy_SoundScraper::cMsg_t8ZCMPjz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_81RcjXOM, HV_BINOP_POW, 0, m, &cBinop_81RcjXOM_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_Xekwg8YX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_f080Payt, 0, m, &cSlice_f080Payt_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_70HGdZoN, 0, m, &cRandom_70HGdZoN_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_6VTN95bD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_26RvTHJU_sendMessage);
}

void Heavy_SoundScraper::cUnop_26RvTHJU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_JUlZxcPc_sendMessage);
}

void Heavy_SoundScraper::cRandom_70HGdZoN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_6VTN95bD_sendMessage);
}

void Heavy_SoundScraper::cSlice_f080Payt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_70HGdZoN, 1, m, &cRandom_70HGdZoN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_iUBxvauI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_1sxpwA9s_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_eKD3Mqw1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_peehBgRm_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_4e2yc250_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_w8eIN2zG, 0, m, &cPack_w8eIN2zG_sendMessage);
}

void Heavy_SoundScraper::cUnop_xf6Pyq5V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_C12c4gDc, 0, m, &cPack_C12c4gDc_sendMessage);
}

void Heavy_SoundScraper::cPack_C12c4gDc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_TZ8DWVp5, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_w8eIN2zG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_cYlxwKAd, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_6ih9vvPA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_4e2yc250_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_xf6Pyq5V_sendMessage);
}

void Heavy_SoundScraper::cMsg_nzOG0VAI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_6ih9vvPA_sendMessage);
}

void Heavy_SoundScraper::cCast_OVHDorH6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_CeR6OvLH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SoecHmWj_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ybDhBXhc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CcbFUlnZ_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_TzmWAr2u_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_BIHnQLNm_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_BIHnQLNm_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_ZziOHvdS, 1, m, &cDelay_ZziOHvdS_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lGomOUvb_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_ZziOHvdS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ZziOHvdS, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qinq1uVd, 0, m, &cVar_qinq1uVd_sendMessage);
}

void Heavy_SoundScraper::cMsg_BIHnQLNm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZziOHvdS, 0, m, &cDelay_ZziOHvdS_sendMessage);
}

void Heavy_SoundScraper::cCast_lGomOUvb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZziOHvdS, 0, m, &cDelay_ZziOHvdS_sendMessage);
}

void Heavy_SoundScraper::cVar_qinq1uVd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_b1CXyzy2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_qe9b3od4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CeR6OvLH, 0, m, &cVar_CeR6OvLH_sendMessage);
}

void Heavy_SoundScraper::cSend_IbHALnTq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_yt1NkkbA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_mTcEXrbq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_N5Z0nEYJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_IbHALnTq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_6AA6CICN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_yt1NkkbA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_Ytr5UA3M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_aT6SSRYd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_aJtEETrQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_Ytr5UA3M_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_4UyJdzMf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_aT6SSRYd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_L1K7aCYk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_BjQp1kDM, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_b1CXyzy2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_BjQp1kDM, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_ybDhBXhc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qinq1uVd, 1, m, &cVar_qinq1uVd_sendMessage);
}

void Heavy_SoundScraper::cCast_CcbFUlnZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_TzmWAr2u_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_SoecHmWj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_L1K7aCYk_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_mbvqhiIe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100000.0f, 0, m, &cBinop_2MYutn0D_sendMessage);
}

void Heavy_SoundScraper::cVar_soc2d4lS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_4QBjg1YY_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_k3DfKfHJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_w7kLbIYi_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_w7kLbIYi_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_Oo443YrA, 1, m, &cDelay_Oo443YrA_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oyqozmji_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_Oo443YrA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Oo443YrA, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jAI7v74U_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_i8ImAmmH_sendMessage);
}

void Heavy_SoundScraper::cMsg_w7kLbIYi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Oo443YrA, 0, m, &cDelay_Oo443YrA_sendMessage);
}

void Heavy_SoundScraper::cCast_oyqozmji_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Oo443YrA, 0, m, &cDelay_Oo443YrA_sendMessage);
}

void Heavy_SoundScraper::cPack_EZrqJn3i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_bH6nrnbx_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_bnGE3sMi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_pU3u2KYP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_9UZZCODM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vtc1paAs_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_zqjP8VWE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_bnGE3sMi, 0, m, &cPack_bnGE3sMi_sendMessage);
}

void Heavy_SoundScraper::cVar_w3fFPjaW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_sFgTU62D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wCtjg07t, HV_BINOP_DIVIDE, 1, m, &cBinop_wCtjg07t_sendMessage);
}

void Heavy_SoundScraper::cVar_ll6nCTTl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wCtjg07t, HV_BINOP_DIVIDE, 0, m, &cBinop_wCtjg07t_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_4QBjg1YY_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mjbkGKDU_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QjYraSwh_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jyi9aVxu_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_adFZ6KVp_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_mjbkGKDU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sFgTU62D, 0, m, &cVar_sFgTU62D_sendMessage);
}

void Heavy_SoundScraper::cCast_QjYraSwh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ll6nCTTl, 0, m, &cVar_ll6nCTTl_sendMessage);
}

void Heavy_SoundScraper::cCast_adFZ6KVp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ll6nCTTl, 0, m, &cVar_ll6nCTTl_sendMessage);
}

void Heavy_SoundScraper::cCast_jyi9aVxu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sFgTU62D, 0, m, &cVar_sFgTU62D_sendMessage);
}

void Heavy_SoundScraper::cCast_jAI7v74U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_soc2d4lS, 0, m, &cVar_soc2d4lS_sendMessage);
}

void Heavy_SoundScraper::cCast_i8ImAmmH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zqjP8VWE, 0, m, &cVar_zqjP8VWE_sendMessage);
}

void Heavy_SoundScraper::cSend_AX83IofK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_8p6suCTx_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_pU3u2KYP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YI1OkFFM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_bH6nrnbx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YI1OkFFM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_QsfnHwz0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_k3DfKfHJ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_ohjcirDD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_EZrqJn3i, 0, m, &cPack_EZrqJn3i_sendMessage);
}

void Heavy_SoundScraper::cBinop_2MYutn0D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_9UZZCODM, 0, m, &cPack_9UZZCODM_sendMessage);
}

void Heavy_SoundScraper::cBinop_2TARYsGG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_9UZZCODM, 1, m, &cPack_9UZZCODM_sendMessage);
}

void Heavy_SoundScraper::cMsg_vtc1paAs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSend_AX83IofK_sendMessage(_c, 0, m);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSend_AX83IofK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_4lycZ32b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_soc2d4lS, 1, m, &cVar_soc2d4lS_sendMessage);
}

void Heavy_SoundScraper::cCast_eANUzncZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cCast_sHKre8Ml_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ohjcirDD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QsfnHwz0_sendMessage);
}

void Heavy_SoundScraper::cBinop_wCtjg07t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mbvqhiIe, 0, m, &cVar_mbvqhiIe_sendMessage);
}

void Heavy_SoundScraper::cMsg_U1I1cI4H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_2TARYsGG_sendMessage);
}

void Heavy_SoundScraper::cSlice_AwaJrZB0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_UO4Fy0Zh_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_2tGdidtH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eANUzncZ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4lycZ32b_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sHKre8Ml_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_w3fFPjaW, 0, m, &cVar_w3fFPjaW_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_eRYPKN7Z_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_QYXAA0ky, 0, m, &cSlice_QYXAA0ky_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_f1CdBkdk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8fmmWamt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_ao6CMJFl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_lVtcbyGM_sendMessage);
}

void Heavy_SoundScraper::cBinop_lVtcbyGM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_e7japoAN, m);
}

void Heavy_SoundScraper::cMsg_8fmmWamt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ao6CMJFl_sendMessage);
}

void Heavy_SoundScraper::cSlice_QYXAA0ky_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_2AsUebY9, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_ZjauuE5S, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_f1CdBkdk, 0, m, &cVar_f1CdBkdk_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_D77GWzkz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_gIB7AkyW_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_Lijy9Qfb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 44100.0f, 0, m, &cBinop_BoTPNmIX_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_1qnKFQ50_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_KKhVWDeL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cMsg_UO4Fy0Zh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_eRYPKN7Z_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::hTable_jMxmuK8G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cBinop_gIB7AkyW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1qnKFQ50, 0, m, &cVar_1qnKFQ50_sendMessage);
}

void Heavy_SoundScraper::cBinop_BoTPNmIX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KKhVWDeL, 0, m, &cVar_KKhVWDeL_sendMessage);
}

void Heavy_SoundScraper::cSlice_8068ygxl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_lymtm18w_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_dZzzOY3A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jiM5Qovg_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_pAF2tA1q_sendMessage);
      cPrint_onMessage(_c, m, "PERCSAMPLER_NOTE");
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_30c6wUDh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_4NS0pbix, 1, m, &cPack_4NS0pbix_sendMessage);
}

void Heavy_SoundScraper::cPack_4NS0pbix_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vWf7S150_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mgZHDetK_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_AwaJrZB0, 0, m, &cSlice_AwaJrZB0_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_2tGdidtH, 0, m, &cSlice_2tGdidtH_sendMessage);
  cPrint_onMessage(_c, m, "TABLEPLAYER_COMMAND");
}

void Heavy_SoundScraper::cCast_BAKOHqW3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_30c6wUDh, 0, m, &cVar_30c6wUDh_sendMessage);
}

void Heavy_SoundScraper::cCast_izCKvQqQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_4NS0pbix, 0, m, &cPack_4NS0pbix_sendMessage);
}

void Heavy_SoundScraper::cBinop_TiYjuSul_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_LhK6QzUq_sendMessage);
}

void Heavy_SoundScraper::cBinop_LhK6QzUq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_6ih9vvPA_sendMessage);
}

void Heavy_SoundScraper::cBinop_lymtm18w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_IADkEZIq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_kOIt0toz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BAKOHqW3_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_izCKvQqQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_JUlZxcPc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_hwhGmS9F_sendMessage);
}

void Heavy_SoundScraper::cBinop_hwhGmS9F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kOIt0toz, HV_BINOP_MULTIPLY, 1, m, &cBinop_kOIt0toz_sendMessage);
}

void Heavy_SoundScraper::cCast_jiM5Qovg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Xekwg8YX_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_vWf7S150_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_TOEZY18p_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OVHDorH6_sendMessage);
}

void Heavy_SoundScraper::cCast_mgZHDetK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qe9b3od4_sendMessage);
}

void Heavy_SoundScraper::cSend_peehBgRm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_fUUemDKx_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_1sxpwA9s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_w374SGYK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_MFMyfDm0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kOIt0toz, HV_BINOP_MULTIPLY, 0, m, &cBinop_kOIt0toz_sendMessage);
}

void Heavy_SoundScraper::cSend_IADkEZIq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_UzSVeQZO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_vRxqgq9S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_118VNwFu_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MSQGYxlC_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1Kewn6PP_sendMessage);
}

void Heavy_SoundScraper::cIf_PuVE8iQ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_ZxZiIB3i_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_hFZMlufN_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_VCHcxEZL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0rQonpY8, HV_BINOP_POW, 0, m, &cBinop_0rQonpY8_sendMessage);
}

void Heavy_SoundScraper::cBinop_0rQonpY8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_W4OqzlDa, 0, m, &cPack_W4OqzlDa_sendMessage);
}

void Heavy_SoundScraper::cBinop_CnE0SF2i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_XrQXE1TL_sendMessage);
}

void Heavy_SoundScraper::cCast_1Kewn6PP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_PuVE8iQ5, 0, m, &cIf_PuVE8iQ5_sendMessage);
}

void Heavy_SoundScraper::cCast_MSQGYxlC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_d53zQKwx_sendMessage);
}

void Heavy_SoundScraper::cBinop_d53zQKwx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_PuVE8iQ5, 1, m, &cIf_PuVE8iQ5_sendMessage);
}

void Heavy_SoundScraper::cBinop_hFZMlufN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_CnE0SF2i_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZxZiIB3i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_W4OqzlDa, 0, m, &cPack_W4OqzlDa_sendMessage);
}

void Heavy_SoundScraper::cBinop_XrQXE1TL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0rQonpY8, HV_BINOP_POW, 1, m, &cBinop_0rQonpY8_sendMessage);
  cMsg_VCHcxEZL_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_W4OqzlDa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_DhZXQLQd, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_xeXP7cvP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_6GWiu0fo_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_118VNwFu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_FHkTnU8b_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_FHkTnU8b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_7EebAh28_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_6GWiu0fo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_U5a6KK2m_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_tQMJpxkN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5xzD83JC_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AWqOKYaQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JN3Y6eJL_sendMessage);
}

void Heavy_SoundScraper::cIf_wOgeAP27_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_9bY4Rekq_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_3GwFiYS4_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_5hntvPsn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jPc7ykt3, HV_BINOP_POW, 0, m, &cBinop_jPc7ykt3_sendMessage);
}

void Heavy_SoundScraper::cBinop_jPc7ykt3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_pQTZkrIu, 0, m, &cPack_pQTZkrIu_sendMessage);
}

void Heavy_SoundScraper::cBinop_EvrlrkFf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_ChY8psKu_sendMessage);
}

void Heavy_SoundScraper::cCast_AWqOKYaQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_LtFW2Ioh_sendMessage);
}

void Heavy_SoundScraper::cCast_JN3Y6eJL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_wOgeAP27, 0, m, &cIf_wOgeAP27_sendMessage);
}

void Heavy_SoundScraper::cBinop_LtFW2Ioh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_wOgeAP27, 1, m, &cIf_wOgeAP27_sendMessage);
}

void Heavy_SoundScraper::cBinop_3GwFiYS4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_EvrlrkFf_sendMessage);
}

void Heavy_SoundScraper::cMsg_9bY4Rekq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_pQTZkrIu, 0, m, &cPack_pQTZkrIu_sendMessage);
}

void Heavy_SoundScraper::cBinop_ChY8psKu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jPc7ykt3, HV_BINOP_POW, 1, m, &cBinop_jPc7ykt3_sendMessage);
  cMsg_5hntvPsn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_pQTZkrIu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_vYEOsQ6y, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_9hFb5Zei_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_666b9gbW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_5xzD83JC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_R2vGC8wZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_R2vGC8wZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_d567VDRH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_666b9gbW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_xiKPPpdb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cIf_aVWaGoCl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Ir5TEI0E_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_pSL1RCCa_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_pSL1RCCa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_SG7SYu10_sendMessage);
}

void Heavy_SoundScraper::cCast_DXno7W5X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_aVWaGoCl, 0, m, &cIf_aVWaGoCl_sendMessage);
}

void Heavy_SoundScraper::cCast_NuoicfDD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_vFUNJa1x_sendMessage);
}

void Heavy_SoundScraper::cMsg_Ir5TEI0E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_5xzD83JC_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AWqOKYaQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JN3Y6eJL_sendMessage);
}

void Heavy_SoundScraper::cBinop_SG7SYu10_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_NnWbrG3H_sendMessage);
}

void Heavy_SoundScraper::cBinop_NnWbrG3H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_bkAntBpb_sendMessage);
}

void Heavy_SoundScraper::cBinop_bkAntBpb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5xzD83JC_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AWqOKYaQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JN3Y6eJL_sendMessage);
}

void Heavy_SoundScraper::cBinop_vFUNJa1x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_aVWaGoCl, 1, m, &cIf_aVWaGoCl_sendMessage);
}

void Heavy_SoundScraper::cBinop_BzQUpHLq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NuoicfDD_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DXno7W5X_sendMessage);
}

void Heavy_SoundScraper::cBinop_78zT3gJ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_BzQUpHLq_sendMessage);
}

void Heavy_SoundScraper::cVar_AjJ4B8zP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uc7LHNvL_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9JYP0BjF_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PilrNlYj_sendMessage);
}

void Heavy_SoundScraper::cIf_SG6rqOkY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_FSOGhLWF_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_bnUcWR2v_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_TBupMFle_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fxp9b9yi, HV_BINOP_POW, 0, m, &cBinop_fxp9b9yi_sendMessage);
}

void Heavy_SoundScraper::cBinop_fxp9b9yi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_E2yLb7b2, 0, m, &cPack_E2yLb7b2_sendMessage);
}

void Heavy_SoundScraper::cBinop_829gJhs7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_hdJe6kDk_sendMessage);
}

void Heavy_SoundScraper::cCast_PilrNlYj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_SG6rqOkY, 0, m, &cIf_SG6rqOkY_sendMessage);
}

void Heavy_SoundScraper::cCast_9JYP0BjF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_BbWg2x8q_sendMessage);
}

void Heavy_SoundScraper::cBinop_BbWg2x8q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_SG6rqOkY, 1, m, &cIf_SG6rqOkY_sendMessage);
}

void Heavy_SoundScraper::cBinop_bnUcWR2v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_829gJhs7_sendMessage);
}

void Heavy_SoundScraper::cMsg_FSOGhLWF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_E2yLb7b2, 0, m, &cPack_E2yLb7b2_sendMessage);
}

void Heavy_SoundScraper::cBinop_hdJe6kDk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fxp9b9yi, HV_BINOP_POW, 1, m, &cBinop_fxp9b9yi_sendMessage);
  cMsg_TBupMFle_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_E2yLb7b2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_MssnHypt, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_qH6JGXZw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_25Mdn79S_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_uc7LHNvL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_DUGjAqei_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_DUGjAqei_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_AI2JReoa_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_25Mdn79S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_8iVWwQQZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_wZQyT7Ko_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_B3NddBFO_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2CQ7UGPo_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GldCNZsI_sendMessage);
}

void Heavy_SoundScraper::cIf_39HFbFhX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_d79ga3VK_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_aFizVBKi_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_n611VXIk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zdRA3fKB, HV_BINOP_POW, 0, m, &cBinop_zdRA3fKB_sendMessage);
}

void Heavy_SoundScraper::cBinop_zdRA3fKB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ldjFJthh, 0, m, &cPack_ldjFJthh_sendMessage);
}

void Heavy_SoundScraper::cBinop_8egULMMI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_ljDtMbOY_sendMessage);
}

void Heavy_SoundScraper::cCast_GldCNZsI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_39HFbFhX, 0, m, &cIf_39HFbFhX_sendMessage);
}

void Heavy_SoundScraper::cCast_2CQ7UGPo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_VL2VJFRq_sendMessage);
}

void Heavy_SoundScraper::cBinop_VL2VJFRq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_39HFbFhX, 1, m, &cIf_39HFbFhX_sendMessage);
}

void Heavy_SoundScraper::cBinop_aFizVBKi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_8egULMMI_sendMessage);
}

void Heavy_SoundScraper::cMsg_d79ga3VK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_ldjFJthh, 0, m, &cPack_ldjFJthh_sendMessage);
}

void Heavy_SoundScraper::cBinop_ljDtMbOY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zdRA3fKB, HV_BINOP_POW, 1, m, &cBinop_zdRA3fKB_sendMessage);
  cMsg_n611VXIk_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_ldjFJthh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_PaEhWcRP, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_EVEb9CdE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_cVdsK2u3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_B3NddBFO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_Cfe8hHCq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_Cfe8hHCq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_jvY0hAW0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_cVdsK2u3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_zfBOUqGM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_AKsbjDOX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_dhU9TARl, 0, m, &cIf_dhU9TARl_sendMessage);
}

void Heavy_SoundScraper::cSlice_nQpTMTYG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yX7b46IS_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bm7RbKLy_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_Txo6ydh9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_RWnJwhe9, 0, m, &cIf_RWnJwhe9_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_RWnJwhe9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TizEmz2M_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dsGZfAFC_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_XuzeMJqy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_TwcOGk3U, 2, m, &cPack_TwcOGk3U_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_cvetfj9F, 1, m, &cPack_cvetfj9F_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_QAOfQfTS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_nQpTMTYG, 0, m, &cSlice_nQpTMTYG_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Txo6ydh9, 0, m, &cSlice_Txo6ydh9_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_TTw7UIhe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_z3n33t60_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_DzsC7L2V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ftxntyKQ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PTAU98xA_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hyOUm6ju_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_BusnRLzI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_prb2T3mh, 1, m, &cIf_prb2T3mh_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_E203pfZC_sendMessage);
}

void Heavy_SoundScraper::cIf_prb2T3mh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_nQpTMTYG, 0, m, &cSlice_nQpTMTYG_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Txo6ydh9, 0, m, &cSlice_Txo6ydh9_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cPack_cvetfj9F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_QAOfQfTS, 0, m, &cIf_QAOfQfTS_sendMessage);
}

void Heavy_SoundScraper::cBinop_2dRHcZ0T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_RWnJwhe9, 1, m, &cIf_RWnJwhe9_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_XuzeMJqy, 1, m, &cIf_XuzeMJqy_sendMessage);
}

void Heavy_SoundScraper::cCast_bm7RbKLy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_XuzeMJqy, 0, m, &cIf_XuzeMJqy_sendMessage);
}

void Heavy_SoundScraper::cCast_yX7b46IS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_2dRHcZ0T_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZudPDQuY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_BusnRLzI, 1, m, &cVar_BusnRLzI_sendMessage);
}

void Heavy_SoundScraper::cMsg_z3n33t60_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_BusnRLzI, 1, m, &cVar_BusnRLzI_sendMessage);
}

void Heavy_SoundScraper::cCast_hyOUm6ju_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZudPDQuY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_PTAU98xA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_cvetfj9F, 0, m, &cPack_cvetfj9F_sendMessage);
}

void Heavy_SoundScraper::cCast_ftxntyKQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BusnRLzI, 0, m, &cVar_BusnRLzI_sendMessage);
}

void Heavy_SoundScraper::cBinop_E203pfZC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_QAOfQfTS, 1, m, &cIf_QAOfQfTS_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_P4igNCob_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_P4sjauXt, 0, m, &cSlice_P4sjauXt_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_xf6BB6Wm, 0, m, &cSlice_xf6BB6Wm_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_BcCdlevP, 0, m, &cSlice_BcCdlevP_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_a5xxJ9gr, 0, m, &cSlice_a5xxJ9gr_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_P4sjauXt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_lsDM8HNQ, 0, m, &cSlice_lsDM8HNQ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_R5nAmq1w, 0, m, &cSlice_R5nAmq1w_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_lsDM8HNQ, 0, m, &cSlice_lsDM8HNQ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_R5nAmq1w, 0, m, &cSlice_R5nAmq1w_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_xf6BB6Wm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_fKaJ4NKP, 0, m, &cSlice_fKaJ4NKP_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_bw3tO1aC, 0, m, &cSlice_bw3tO1aC_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_fKaJ4NKP, 0, m, &cSlice_fKaJ4NKP_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_bw3tO1aC, 0, m, &cSlice_bw3tO1aC_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_BcCdlevP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_mBfvagEW, 0, m, &cSlice_mBfvagEW_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_E29p9X9W, 0, m, &cSlice_E29p9X9W_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_mBfvagEW, 0, m, &cSlice_mBfvagEW_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_E29p9X9W, 0, m, &cSlice_E29p9X9W_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_a5xxJ9gr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_8068ygxl, 0, m, &cSlice_8068ygxl_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_dZzzOY3A, 0, m, &cSlice_dZzzOY3A_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_8068ygxl, 0, m, &cSlice_8068ygxl_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_dZzzOY3A, 0, m, &cSlice_dZzzOY3A_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_lw7K09UR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MIADjmOB_sendMessage);
      break;
    }
    default: {
      cMsg_9QO6dJxs_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_MIADjmOB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1f2tQcoS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cIf_dhU9TARl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_TTw7UIhe, 0, m, &cSlice_TTw7UIhe_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_DzsC7L2V, 0, m, &cSlice_DzsC7L2V_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_prb2T3mh, 0, m, &cIf_prb2T3mh_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_kRTCDiYz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_M7UrKBFv_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_dhU9TARl, 1, m, &cIf_dhU9TARl_sendMessage);
}

void Heavy_SoundScraper::cBinop_M7UrKBFv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kRTCDiYz, 1, m, &cVar_kRTCDiYz_sendMessage);
}

void Heavy_SoundScraper::cMsg_1f2tQcoS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_kRTCDiYz, 0, m, &cVar_kRTCDiYz_sendMessage);
}

void Heavy_SoundScraper::cMsg_9QO6dJxs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_kRTCDiYz, 0, m, &cVar_kRTCDiYz_sendMessage);
}

void Heavy_SoundScraper::cPack_TwcOGk3U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_P4igNCob_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_MpzueeO0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_TwcOGk3U, 0, m, &cPack_TwcOGk3U_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_VXJ9hpAG_sendMessage);
}

void Heavy_SoundScraper::cBinop_VXJ9hpAG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 4.0f, 0, m, &cBinop_RctGyfZQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_RctGyfZQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MpzueeO0, 1, m, &cVar_MpzueeO0_sendMessage);
}

void Heavy_SoundScraper::cMsg_2wY6hVmP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_lw7K09UR_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_dsGZfAFC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MpzueeO0, 0, m, &cVar_MpzueeO0_sendMessage);
}

void Heavy_SoundScraper::cCast_TizEmz2M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_TwcOGk3U, 1, m, &cPack_TwcOGk3U_sendMessage);
}

void Heavy_SoundScraper::hTable_amCL36fy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_UYG6pvuw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_z3kP5qh2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_TFx144L5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_gQNN9nGV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_1xHT5NDV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSlice_z1UlBdIJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_n3hJuhPL_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_SmS9GaGH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_dNImdQcy, 0, m, &cIf_dNImdQcy_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_KWtwlnGM, 0, m, &cIf_KWtwlnGM_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_5C2HXS0B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_2Rf2CTD8, 0, m, &cIf_2Rf2CTD8_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_zterQ7Pk, 0, m, &cIf_zterQ7Pk_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_fcIqxhNK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_H5QywXqo_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_URTmEOnH, 0, m, &cIf_URTmEOnH_sendMessage);
}

void Heavy_SoundScraper::cUnop_m9tFu7Qy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_DDvSdILV_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_uvW1IgTh, HV_BINOP_EQ, 1, m, &cBinop_uvW1IgTh_sendMessage);
}

void Heavy_SoundScraper::cUnop_aCY4U93E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_DDvSdILV_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_uvW1IgTh, HV_BINOP_EQ, 1, m, &cBinop_uvW1IgTh_sendMessage);
}

void Heavy_SoundScraper::cIf_URTmEOnH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_aCY4U93E_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_m9tFu7Qy_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_H5QywXqo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_URTmEOnH, 1, m, &cIf_URTmEOnH_sendMessage);
}

void Heavy_SoundScraper::cIf_KWtwlnGM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_gojlPn4R_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_zterQ7Pk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_AovKE5EX_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_dNImdQcy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_gojlPn4R_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_2Rf2CTD8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_AovKE5EX_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_n3hJuhPL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uvW1IgTh, HV_BINOP_EQ, 0, m, &cBinop_uvW1IgTh_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_0G2it6UX_sendMessage);
}

void Heavy_SoundScraper::cBinop_DDvSdILV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ASI4C38t_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PhSREe9s_sendMessage);
}

void Heavy_SoundScraper::cBinop_uvW1IgTh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MGlWgAgr_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kTyFP8oj_sendMessage);
}

void Heavy_SoundScraper::cCast_kTyFP8oj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_2Rf2CTD8, 1, m, &cIf_2Rf2CTD8_sendMessage);
}

void Heavy_SoundScraper::cCast_MGlWgAgr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_KWtwlnGM, 1, m, &cIf_KWtwlnGM_sendMessage);
}

void Heavy_SoundScraper::cCast_PhSREe9s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zterQ7Pk, 1, m, &cIf_zterQ7Pk_sendMessage);
}

void Heavy_SoundScraper::cCast_ASI4C38t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_dNImdQcy, 1, m, &cIf_dNImdQcy_sendMessage);
}

void Heavy_SoundScraper::cBinop_0G2it6UX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_0Jak9WIh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_AovKE5EX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_CxBBmUQ6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_gojlPn4R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_nw0MBJwa_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_0Jak9WIh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_OAPsrT6s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_DMCzyIRi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_2sPskGVt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cSend_OAPsrT6s_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_sm7ld76z_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x40000000: { // "2.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_O25kRqUS_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lyPbqTR6_sendMessage);
      break;
    }
    case 0x40800000: { // "4.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mle6LYJA_sendMessage);
      break;
    }
    case 0x40A00000: { // "5.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0idMGRZU_sendMessage);
      break;
    }
    case 0x40C00000: { // "6.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OfGBUcvK_sendMessage);
      break;
    }
    case 0x40E00000: { // "7.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HuGfv5MI_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_O25kRqUS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_M6CVQ2Mu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_lyPbqTR6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gsVE1Lcl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_mle6LYJA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NOPXpUv2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_0idMGRZU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LwpnUx3w_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_OfGBUcvK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cKp3H6VZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_HuGfv5MI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_V2d92aRB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_2t2WULYO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_RLN9mP6F, 0, m, &cSlice_RLN9mP6F_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_qkztsDYV, 0, m, &cRandom_qkztsDYV_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_OqrrNVPR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_HP2ReG7H_sendMessage);
}

void Heavy_SoundScraper::cUnop_HP2ReG7H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_oMdg8mJB_sendMessage);
}

void Heavy_SoundScraper::cRandom_qkztsDYV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5.0f, 0, m, &cBinop_OqrrNVPR_sendMessage);
}

void Heavy_SoundScraper::cSlice_RLN9mP6F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_qkztsDYV, 1, m, &cRandom_qkztsDYV_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_cKp3H6VZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "marimba");
  msg_setFloat(m, 1, 264.0f);
  cSend_gdgosHTH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_V2d92aRB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "xylo");
  msg_setFloat(m, 1, 2116.9f);
  cSend_gdgosHTH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_LwpnUx3w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "bowl");
  msg_setFloat(m, 1, 705.52f);
  cSend_gdgosHTH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_gsVE1Lcl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "gong");
  msg_setFloat(m, 1, 179.88f);
  cSend_gdgosHTH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_gdgosHTH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_sbOb3eYG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_NOPXpUv2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "crotale");
  msg_setFloat(m, 1, 1058.39f);
  cSend_gdgosHTH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_oMdg8mJB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SOUND_CHOICE");
  cSwitchcase_sm7ld76z_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_M6CVQ2Mu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "almglocken");
  msg_setFloat(m, 1, 262.6f);
  cSend_gdgosHTH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_FifJBIti_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_NcXPTfvy, 0, m, &cSlice_NcXPTfvy_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Kii8NuQ3, 0, m, &cRandom_Kii8NuQ3_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_gvDn5s4e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_imvNtm6U_sendMessage);
}

void Heavy_SoundScraper::cUnop_imvNtm6U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 10.0f, 0, m, &cBinop_yWzxR8fM_sendMessage);
}

void Heavy_SoundScraper::cRandom_Kii8NuQ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 80.0f, 0, m, &cBinop_gvDn5s4e_sendMessage);
}

void Heavy_SoundScraper::cSlice_NcXPTfvy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Kii8NuQ3, 1, m, &cRandom_Kii8NuQ3_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_T0889Qnm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_8PbICwYz, 0, m, &cSlice_8PbICwYz_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_KgiZuCcH, 0, m, &cRandom_KgiZuCcH_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_lxXOrOqm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_FwYPnA6w_sendMessage);
}

void Heavy_SoundScraper::cUnop_FwYPnA6w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_WE1w8xe6, 0, m, &cPack_WE1w8xe6_sendMessage);
}

void Heavy_SoundScraper::cRandom_KgiZuCcH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_lxXOrOqm_sendMessage);
}

void Heavy_SoundScraper::cSlice_8PbICwYz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_KgiZuCcH, 1, m, &cRandom_KgiZuCcH_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_rNfpiePK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_hclL0xPq_sendMessage);
}

void Heavy_SoundScraper::cPack_eoMjGEAu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_mvZgh5qa, 0, m, NULL);
}

void Heavy_SoundScraper::cUnop_jCTkS9Tb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_bgNYvypn_sendMessage);
}

void Heavy_SoundScraper::cBinop_PzaAG5J9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_jCTkS9Tb_sendMessage);
}

void Heavy_SoundScraper::cPack_ZieZL1xR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_IZW5pwvx, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_5FG0Ag5z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_x7neRElO_sendMessage);
}

void Heavy_SoundScraper::cMsg_bnXokAx1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CGfanD1z_sendMessage);
}

void Heavy_SoundScraper::cSystem_CGfanD1z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_4m6RY3GI_sendMessage);
}

void Heavy_SoundScraper::cDelay_OBPQSiWQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_OBPQSiWQ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_m5SDsPhd, 0, m, &cDelay_m5SDsPhd_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OBPQSiWQ, 0, m, &cDelay_OBPQSiWQ_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_4DVarWqT, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_m5SDsPhd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_m5SDsPhd, m);
  cMsg_owj7ukUl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_CDBeaul9_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_jZpDicyj_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_Do81f8HW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3yrXqAvQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_oRoHtg9E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ICAbDykg_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OBPQSiWQ, 2, m, &cDelay_OBPQSiWQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xKFmQ4Mk_sendMessage);
}

void Heavy_SoundScraper::cMsg_3yrXqAvQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_oRoHtg9E, 0, m, &hTable_oRoHtg9E_sendMessage);
}

void Heavy_SoundScraper::cBinop_4m6RY3GI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_Do81f8HW_sendMessage);
}

void Heavy_SoundScraper::cMsg_owj7ukUl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_oRoHtg9E, 0, m, &hTable_oRoHtg9E_sendMessage);
}

void Heavy_SoundScraper::cCast_xKFmQ4Mk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_OBPQSiWQ, 0, m, &cDelay_OBPQSiWQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_ICAbDykg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_m5SDsPhd, 2, m, &cDelay_m5SDsPhd_sendMessage);
}

void Heavy_SoundScraper::cMsg_jZpDicyj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_4DVarWqT, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_gez0P1Be_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FwXZLAhV_sendMessage);
}

void Heavy_SoundScraper::cSystem_FwXZLAhV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_IoZSFE84_sendMessage);
}

void Heavy_SoundScraper::cVar_dW1NHeJ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DQNF7W80_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_RxY42Aui_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_BAImgffB_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_GcZzNGCY, m);
}

void Heavy_SoundScraper::cBinop_IoZSFE84_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_8irt6XdM, m);
}

void Heavy_SoundScraper::cMsg_DQNF7W80_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RxY42Aui_sendMessage);
}

void Heavy_SoundScraper::cBinop_BAImgffB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_iN3OEegO, m);
}

void Heavy_SoundScraper::cMsg_QXC57HOG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TefRjmKA_sendMessage);
}

void Heavy_SoundScraper::cSystem_TefRjmKA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_kFhHUgeR_sendMessage);
}

void Heavy_SoundScraper::cVar_355T4jD2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_l5l6sbVn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_Zb1YR21S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_s2HmgLAM_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_NYS8uaw0, m);
}

void Heavy_SoundScraper::cBinop_kFhHUgeR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_OuHCKlac, m);
}

void Heavy_SoundScraper::cMsg_l5l6sbVn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Zb1YR21S_sendMessage);
}

void Heavy_SoundScraper::cBinop_s2HmgLAM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_VRpEdLyn, m);
}

void Heavy_SoundScraper::cBinop_r1YYYDJd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uedlTInA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_yG3Masla_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NIVWfdyb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_boAME0aH_sendMessage);
}

void Heavy_SoundScraper::cCast_NIVWfdyb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_r1YYYDJd, HV_BINOP_DIVIDE, 1, m, &cBinop_r1YYYDJd_sendMessage);
}

void Heavy_SoundScraper::cCast_boAME0aH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_r1YYYDJd, HV_BINOP_DIVIDE, 0, m, &cBinop_r1YYYDJd_sendMessage);
}

void Heavy_SoundScraper::cBinop_bgNYvypn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_8OTVmtIu_sendMessage);
}

void Heavy_SoundScraper::cBinop_3YTmJmSQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_PzaAG5J9_sendMessage);
}

void Heavy_SoundScraper::cBinop_8OTVmtIu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_r1YYYDJd, HV_BINOP_DIVIDE, 0, m, &cBinop_r1YYYDJd_sendMessage);
}

void Heavy_SoundScraper::cBinop_x7neRElO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ZieZL1xR, 0, m, &cPack_ZieZL1xR_sendMessage);
}

void Heavy_SoundScraper::cBinop_hclL0xPq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_yG3Masla_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_eoMjGEAu, 0, m, &cPack_eoMjGEAu_sendMessage);
}

void Heavy_SoundScraper::cMsg_khPdb6jj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_rNfpiePK, 0, m, &cVar_rNfpiePK_sendMessage);
}

void Heavy_SoundScraper::cMsg_G99sOwTV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_5FG0Ag5z, 0, m, &cVar_5FG0Ag5z_sendMessage);
}

void Heavy_SoundScraper::cMsg_uedlTInA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_7uXeASB6, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_zU46ArFC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JjECmYFS_sendMessage);
}

void Heavy_SoundScraper::cSystem_JjECmYFS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_8J74B8tI_sendMessage);
}

void Heavy_SoundScraper::cVar_bzu2vw0t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IKotfWR5_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_VYOgrWtH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_n51g4FMp_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_JJwa1h1d, m);
}

void Heavy_SoundScraper::cBinop_8J74B8tI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_4ULtgp3v, m);
}

void Heavy_SoundScraper::cMsg_IKotfWR5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VYOgrWtH_sendMessage);
}

void Heavy_SoundScraper::cBinop_n51g4FMp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_0jirQ8Dl, m);
}

void Heavy_SoundScraper::cVar_bTI3bFr5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3UVm8ic6, HV_BINOP_MULTIPLY, 0, m, &cBinop_3UVm8ic6_sendMessage);
}

void Heavy_SoundScraper::cMsg_hLCfqcDD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DTTiEHrR_sendMessage);
}

void Heavy_SoundScraper::cSystem_DTTiEHrR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kaPY3mNY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_3UVm8ic6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_M5TCvYYl_sendMessage);
}

void Heavy_SoundScraper::cBinop_2Gyu3ffM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3UVm8ic6, HV_BINOP_MULTIPLY, 1, m, &cBinop_3UVm8ic6_sendMessage);
}

void Heavy_SoundScraper::cMsg_kaPY3mNY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_2Gyu3ffM_sendMessage);
}

void Heavy_SoundScraper::cBinop_M5TCvYYl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_jV0Iopl1_sendMessage);
}

void Heavy_SoundScraper::cBinop_jV0Iopl1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_3PFFrGio_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_gfRmyWQe, m);
}

void Heavy_SoundScraper::cBinop_3PFFrGio_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_764QpYzG, m);
}

void Heavy_SoundScraper::cBinop_It0hd7na_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_xXuE72A7_sendMessage);
}

void Heavy_SoundScraper::cBinop_xXuE72A7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_SRHqRpj8, m);
}

void Heavy_SoundScraper::cBinop_zd8s1bsK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_yfLGLtbW_sendMessage);
}

void Heavy_SoundScraper::cBinop_yfLGLtbW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_ervN9cEL_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Z9cIbw4L_sendMessage);
}

void Heavy_SoundScraper::cVar_VK0ooZFX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_62YFGrPQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_2CosRh4F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gGzYsybi_sendMessage);
}

void Heavy_SoundScraper::cSystem_gGzYsybi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Onpypumb, HV_BINOP_DIVIDE, 1, m, &cBinop_Onpypumb_sendMessage);
}

void Heavy_SoundScraper::cBinop_ervN9cEL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_PVVydMT1_sendMessage);
}

void Heavy_SoundScraper::cBinop_PVVydMT1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_rgnkoBBl, m);
}

void Heavy_SoundScraper::cMsg_Nzlx7bMy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_MTUMqdTd_sendMessage);
}

void Heavy_SoundScraper::cBinop_MTUMqdTd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_zd8s1bsK_sendMessage);
}

void Heavy_SoundScraper::cBinop_Z9cIbw4L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_nNRbulIl, m);
}

void Heavy_SoundScraper::cBinop_62YFGrPQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_Wm4DpIZG_sendMessage);
}

void Heavy_SoundScraper::cBinop_Wm4DpIZG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Onpypumb, HV_BINOP_DIVIDE, 0, m, &cBinop_Onpypumb_sendMessage);
}

void Heavy_SoundScraper::cBinop_Onpypumb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Nzlx7bMy_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_do1I6mfP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UADvffzl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_SO8NFMqB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Jy8zeVOk_sendMessage);
}

void Heavy_SoundScraper::cSystem_Jy8zeVOk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_WEMFrhbQ_sendMessage);
}

void Heavy_SoundScraper::cDelay_FZqLrvrt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FZqLrvrt, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lkc4Su4Z, 0, m, &cDelay_lkc4Su4Z_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FZqLrvrt, 0, m, &cDelay_FZqLrvrt_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_RP7IA2je, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_lkc4Su4Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_lkc4Su4Z, m);
  cMsg_KWeLow0n_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_zkrTbL18_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_M1WGE9t4_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_wSjxjkts_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BUSHgBNU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_3s6UTbxa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Zxu6FTbT_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FZqLrvrt, 2, m, &cDelay_FZqLrvrt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_u9wFadFk_sendMessage);
}

void Heavy_SoundScraper::cMsg_BUSHgBNU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_3s6UTbxa, 0, m, &hTable_3s6UTbxa_sendMessage);
}

void Heavy_SoundScraper::cBinop_WEMFrhbQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_wSjxjkts_sendMessage);
}

void Heavy_SoundScraper::cMsg_KWeLow0n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_3s6UTbxa, 0, m, &hTable_3s6UTbxa_sendMessage);
}

void Heavy_SoundScraper::cCast_u9wFadFk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_FZqLrvrt, 0, m, &cDelay_FZqLrvrt_sendMessage);
}

void Heavy_SoundScraper::cMsg_Zxu6FTbT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_lkc4Su4Z, 2, m, &cDelay_lkc4Su4Z_sendMessage);
}

void Heavy_SoundScraper::cMsg_M1WGE9t4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_RP7IA2je, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_ybKgi1HZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_UADvffzl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_UADvffzl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ElWsOhlv, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_xMES6WPq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cMsg_1o2DeA9K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FLENHLGB_sendMessage);
}

void Heavy_SoundScraper::cSystem_FLENHLGB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Q2wUw3Dy, HV_BINOP_MULTIPLY, 1, m, &cBinop_Q2wUw3Dy_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5wPDF0ye, HV_BINOP_MULTIPLY, 1, m, &cBinop_5wPDF0ye_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_YPfT6m1l_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_YRTHIeAu_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_YRTHIeAu_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IjqPUdPB_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_M0UaVWO2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_M0UaVWO2, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_M0UaVWO2, 0, m, &cDelay_M0UaVWO2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_sRPVPhoe, 0, m, &cVar_sRPVPhoe_sendMessage);
}

void Heavy_SoundScraper::cCast_IjqPUdPB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YRTHIeAu_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_M0UaVWO2, 0, m, &cDelay_M0UaVWO2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_sRPVPhoe, 0, m, &cVar_sRPVPhoe_sendMessage);
}

void Heavy_SoundScraper::cMsg_jtC1jntz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KzNtYF8c_sendMessage);
}

void Heavy_SoundScraper::cSystem_KzNtYF8c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_xZiuoKM1_sendMessage);
}

void Heavy_SoundScraper::cVar_rZAJzj2N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ocHC5l4s, HV_BINOP_MULTIPLY, 0, m, &cBinop_ocHC5l4s_sendMessage);
}

void Heavy_SoundScraper::cMsg_YRTHIeAu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_M0UaVWO2, 0, m, &cDelay_M0UaVWO2_sendMessage);
}

void Heavy_SoundScraper::cBinop_gZN1yvA4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_M0UaVWO2, 2, m, &cDelay_M0UaVWO2_sendMessage);
}

void Heavy_SoundScraper::cBinop_xZiuoKM1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ocHC5l4s, HV_BINOP_MULTIPLY, 1, m, &cBinop_ocHC5l4s_sendMessage);
}

void Heavy_SoundScraper::cBinop_ocHC5l4s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_gZN1yvA4_sendMessage);
}

void Heavy_SoundScraper::cVar_sRPVPhoe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1xULACqT, HV_BINOP_SUBTRACT, 0, m, &cBinop_1xULACqT_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_UtEDbXsi_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_4Q3mQypa_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6U7P6DEY_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CZJ32966_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_6U7P6DEY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aDhkvIgs, 0, m, &cVar_aDhkvIgs_sendMessage);
}

void Heavy_SoundScraper::cCast_CZJ32966_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_C44nxeyB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XLDQc35e_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_uQOScsFd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ZUEcKwez, 0, m, &cSlice_ZUEcKwez_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_cDUZkQIh, 0, m, &cSlice_cDUZkQIh_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VGGUJJMr_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_hzxX9syw, 0, m, &cSlice_hzxX9syw_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_au6glezj, 0, m, &cSlice_au6glezj_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zXBHowSq_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4XIC9dtn_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_ZUEcKwez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_H3jb9csg_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_H3jb9csg_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_cDUZkQIh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aumM02oz_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Og4s2gWi_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aumM02oz_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Og4s2gWi_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_ey6cIaW0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lESBk4wF_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_B23skvsK_sendMessage);
}

void Heavy_SoundScraper::cVar_axV3FCr3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_4e5JPmXx_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_4e5JPmXx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hp0lZ9if_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Q2wUw3Dy, HV_BINOP_MULTIPLY, 0, m, &cBinop_Q2wUw3Dy_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_rJsc3KT8, HV_BINOP_DIVIDE, 1, m, &cBinop_rJsc3KT8_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_rZAJzj2N, 0, m, &cVar_rZAJzj2N_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_hp0lZ9if_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_m6k5uOiB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_iSuPtPBp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_J5DhpX9w, HV_BINOP_SUBTRACT, 1, m, &cBinop_J5DhpX9w_sendMessage);
}

void Heavy_SoundScraper::cVar_Fk8fXxHd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aDhkvIgs, 0, m, &cVar_aDhkvIgs_sendMessage);
}

void Heavy_SoundScraper::cVar_aDhkvIgs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SW3ysAR1, HV_BINOP_ADD, 0, m, &cBinop_SW3ysAR1_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_mZzHQwBz, HV_BINOP_ADD, 0, m, &cBinop_mZzHQwBz_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_jNXzDXgG, 0, m, &cVar_jNXzDXgG_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_3YTmJmSQ_sendMessage);
}

void Heavy_SoundScraper::cSlice_hzxX9syw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lESBk4wF_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_B23skvsK_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_au6glezj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WRlLhMfR_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AEdVkxSo_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_oiksiB6Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sRPVPhoe, 1, m, &cVar_sRPVPhoe_sendMessage);
}

void Heavy_SoundScraper::cBinop_5wPDF0ye_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_oiksiB6Z_sendMessage);
}

void Heavy_SoundScraper::cBinop_Q2wUw3Dy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_t1CoghHT_sendMessage);
}

void Heavy_SoundScraper::cBinop_t1CoghHT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1xULACqT, HV_BINOP_SUBTRACT, 1, m, &cBinop_1xULACqT_sendMessage);
}

void Heavy_SoundScraper::cBinop_1xULACqT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sRPVPhoe, 1, m, &cVar_sRPVPhoe_sendMessage);
}

void Heavy_SoundScraper::cMsg_Q6EnWj03_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_YPfT6m1l_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_12KLPObi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_YPfT6m1l_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_mZzHQwBz, HV_BINOP_ADD, 1, m, &cBinop_mZzHQwBz_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_SW3ysAR1, HV_BINOP_ADD, 1, m, &cBinop_SW3ysAR1_sendMessage);
}

void Heavy_SoundScraper::cBinop_UtEDbXsi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_4Q3mQypa_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_SW3ysAR1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aDhkvIgs, 1, m, &cVar_aDhkvIgs_sendMessage);
}

void Heavy_SoundScraper::cBinop_rJsc3KT8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0UvNhUn9, HV_BINOP_DIVIDE, 1, m, &cBinop_0UvNhUn9_sendMessage);
}

void Heavy_SoundScraper::cBinop_0UvNhUn9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mZzHQwBz, HV_BINOP_ADD, 1, m, &cBinop_mZzHQwBz_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_SW3ysAR1, HV_BINOP_ADD, 1, m, &cBinop_SW3ysAR1_sendMessage);
}

void Heavy_SoundScraper::cCast_lESBk4wF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5wPDF0ye, HV_BINOP_MULTIPLY, 0, m, &cBinop_5wPDF0ye_sendMessage);
}

void Heavy_SoundScraper::cCast_B23skvsK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rJsc3KT8, HV_BINOP_DIVIDE, 0, m, &cBinop_rJsc3KT8_sendMessage);
}

void Heavy_SoundScraper::cCast_WRlLhMfR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Fk8fXxHd, 1, m, &cVar_Fk8fXxHd_sendMessage);
}

void Heavy_SoundScraper::cCast_AEdVkxSo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_J5DhpX9w, HV_BINOP_SUBTRACT, 0, m, &cBinop_J5DhpX9w_sendMessage);
}

void Heavy_SoundScraper::cCast_C44nxeyB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_12KLPObi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_XLDQc35e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Fk8fXxHd, 0, m, &cVar_Fk8fXxHd_sendMessage);
}

void Heavy_SoundScraper::cBinop_mZzHQwBz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iSuPtPBp, 0, m, &cVar_iSuPtPBp_sendMessage);
}

void Heavy_SoundScraper::cMsg_H3jb9csg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_YPfT6m1l_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_2xTOYDh4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_ey6cIaW0, 1, m, &cVar_ey6cIaW0_sendMessage);
}

void Heavy_SoundScraper::cMsg_m6k5uOiB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Q2wUw3Dy, HV_BINOP_MULTIPLY, 0, m, &cBinop_Q2wUw3Dy_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_rJsc3KT8, HV_BINOP_DIVIDE, 1, m, &cBinop_rJsc3KT8_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rZAJzj2N, 0, m, &cVar_rZAJzj2N_sendMessage);
}

void Heavy_SoundScraper::cCast_aumM02oz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_H3jb9csg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_Og4s2gWi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dvnUut2s_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_mZzHQwBz, HV_BINOP_ADD, 0, m, &cBinop_mZzHQwBz_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_aDhkvIgs, 1, m, &cVar_aDhkvIgs_sendMessage);
}

void Heavy_SoundScraper::cBinop_J5DhpX9w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0UvNhUn9, HV_BINOP_DIVIDE, 0, m, &cBinop_0UvNhUn9_sendMessage);
}

void Heavy_SoundScraper::cCast_dvnUut2s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_12KLPObi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_zXBHowSq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Q6EnWj03_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_4XIC9dtn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2xTOYDh4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_VGGUJJMr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ey6cIaW0, 0, m, &cVar_ey6cIaW0_sendMessage);
}

void Heavy_SoundScraper::cVar_jNXzDXgG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cPack_qG9WTs91_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_uQOScsFd_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_tKXXYZKG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_cvmnnBWo_sendMessage);
}

void Heavy_SoundScraper::cSystem_cvmnnBWo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NVhEP288, HV_BINOP_MULTIPLY, 1, m, &cBinop_NVhEP288_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jRD01h2r, HV_BINOP_MULTIPLY, 1, m, &cBinop_jRD01h2r_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_TUCU1Eha_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_x6tgNzpl_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_x6tgNzpl_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3UvqYyPP_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_jUg3TBVd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_jUg3TBVd, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jUg3TBVd, 0, m, &cDelay_jUg3TBVd_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_99IcP7YQ, 0, m, &cVar_99IcP7YQ_sendMessage);
}

void Heavy_SoundScraper::cCast_3UvqYyPP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_x6tgNzpl_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jUg3TBVd, 0, m, &cDelay_jUg3TBVd_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_99IcP7YQ, 0, m, &cVar_99IcP7YQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_KFOeusDy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SzQNDsj2_sendMessage);
}

void Heavy_SoundScraper::cSystem_SzQNDsj2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_r9IWiy0C_sendMessage);
}

void Heavy_SoundScraper::cVar_lq0ZeuWF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1RH6BlPs, HV_BINOP_MULTIPLY, 0, m, &cBinop_1RH6BlPs_sendMessage);
}

void Heavy_SoundScraper::cMsg_x6tgNzpl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_jUg3TBVd, 0, m, &cDelay_jUg3TBVd_sendMessage);
}

void Heavy_SoundScraper::cBinop_TrAUn0wy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_jUg3TBVd, 2, m, &cDelay_jUg3TBVd_sendMessage);
}

void Heavy_SoundScraper::cBinop_r9IWiy0C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1RH6BlPs, HV_BINOP_MULTIPLY, 1, m, &cBinop_1RH6BlPs_sendMessage);
}

void Heavy_SoundScraper::cBinop_1RH6BlPs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_TrAUn0wy_sendMessage);
}

void Heavy_SoundScraper::cVar_99IcP7YQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Jr5ZmVF4, HV_BINOP_SUBTRACT, 0, m, &cBinop_Jr5ZmVF4_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_Cnpfu7Nn_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_VnfyySTj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SeiCcOof_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IFlVyGHR_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_SeiCcOof_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VStxO6V3, 0, m, &cVar_VStxO6V3_sendMessage);
}

void Heavy_SoundScraper::cCast_IFlVyGHR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zvhMA6wm_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZfQxwqGO_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_OpefLW0W_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Tc018gGc, 0, m, &cSlice_Tc018gGc_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_3PQJi93r, 0, m, &cSlice_3PQJi93r_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_u6tCRSdr_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_znC82660, 0, m, &cSlice_znC82660_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_UZa0n1T9, 0, m, &cSlice_UZa0n1T9_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UndtSrm6_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bO7RWsB7_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_Tc018gGc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_c8VaBFHD_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_c8VaBFHD_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_3PQJi93r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_W6wEkOHS_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cC2SayEE_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_W6wEkOHS_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cC2SayEE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_E4KGjYVQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_krTqfLDW_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_O6bk9nGD_sendMessage);
}

void Heavy_SoundScraper::cVar_RPGNKu60_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_fFKqJ5s7_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_fFKqJ5s7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NQHOrp2n_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_NVhEP288, HV_BINOP_MULTIPLY, 0, m, &cBinop_NVhEP288_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_MlMD3BYD, HV_BINOP_DIVIDE, 1, m, &cBinop_MlMD3BYD_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_lq0ZeuWF, 0, m, &cVar_lq0ZeuWF_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_NQHOrp2n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ymSFFjAv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_67dHZIe4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_P98OWV7X, HV_BINOP_SUBTRACT, 1, m, &cBinop_P98OWV7X_sendMessage);
}

void Heavy_SoundScraper::cVar_9AnCsGFn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VStxO6V3, 0, m, &cVar_VStxO6V3_sendMessage);
}

void Heavy_SoundScraper::cVar_VStxO6V3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8JAnkFso, HV_BINOP_ADD, 0, m, &cBinop_8JAnkFso_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zXcUxeMC, HV_BINOP_ADD, 0, m, &cBinop_zXcUxeMC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_xMES6WPq, 0, m, &cVar_xMES6WPq_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_IKss2HMD, m);
}

void Heavy_SoundScraper::cSlice_znC82660_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_krTqfLDW_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_O6bk9nGD_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_UZa0n1T9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1w5t8QVC_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5k6AXLPQ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_FUU5Zhb7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_99IcP7YQ, 1, m, &cVar_99IcP7YQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_jRD01h2r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_FUU5Zhb7_sendMessage);
}

void Heavy_SoundScraper::cBinop_NVhEP288_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_HBnr7iTD_sendMessage);
}

void Heavy_SoundScraper::cBinop_HBnr7iTD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Jr5ZmVF4, HV_BINOP_SUBTRACT, 1, m, &cBinop_Jr5ZmVF4_sendMessage);
}

void Heavy_SoundScraper::cBinop_Jr5ZmVF4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_99IcP7YQ, 1, m, &cVar_99IcP7YQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_Q5eBp4nB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_TUCU1Eha_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_eDCwJU4u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_TUCU1Eha_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zXcUxeMC, HV_BINOP_ADD, 1, m, &cBinop_zXcUxeMC_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8JAnkFso, HV_BINOP_ADD, 1, m, &cBinop_8JAnkFso_sendMessage);
}

void Heavy_SoundScraper::cBinop_Cnpfu7Nn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_VnfyySTj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_8JAnkFso_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VStxO6V3, 1, m, &cVar_VStxO6V3_sendMessage);
}

void Heavy_SoundScraper::cBinop_MlMD3BYD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_G5CTjLOb, HV_BINOP_DIVIDE, 1, m, &cBinop_G5CTjLOb_sendMessage);
}

void Heavy_SoundScraper::cBinop_G5CTjLOb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zXcUxeMC, HV_BINOP_ADD, 1, m, &cBinop_zXcUxeMC_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8JAnkFso, HV_BINOP_ADD, 1, m, &cBinop_8JAnkFso_sendMessage);
}

void Heavy_SoundScraper::cCast_O6bk9nGD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MlMD3BYD, HV_BINOP_DIVIDE, 0, m, &cBinop_MlMD3BYD_sendMessage);
}

void Heavy_SoundScraper::cCast_krTqfLDW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jRD01h2r, HV_BINOP_MULTIPLY, 0, m, &cBinop_jRD01h2r_sendMessage);
}

void Heavy_SoundScraper::cCast_1w5t8QVC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9AnCsGFn, 1, m, &cVar_9AnCsGFn_sendMessage);
}

void Heavy_SoundScraper::cCast_5k6AXLPQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_P98OWV7X, HV_BINOP_SUBTRACT, 0, m, &cBinop_P98OWV7X_sendMessage);
}

void Heavy_SoundScraper::cCast_ZfQxwqGO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9AnCsGFn, 0, m, &cVar_9AnCsGFn_sendMessage);
}

void Heavy_SoundScraper::cCast_zvhMA6wm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eDCwJU4u_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_zXcUxeMC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_67dHZIe4, 0, m, &cVar_67dHZIe4_sendMessage);
}

void Heavy_SoundScraper::cMsg_c8VaBFHD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_TUCU1Eha_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_8JqA46WM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_E4KGjYVQ, 1, m, &cVar_E4KGjYVQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_ymSFFjAv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_NVhEP288, HV_BINOP_MULTIPLY, 0, m, &cBinop_NVhEP288_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_MlMD3BYD, HV_BINOP_DIVIDE, 1, m, &cBinop_MlMD3BYD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lq0ZeuWF, 0, m, &cVar_lq0ZeuWF_sendMessage);
}

void Heavy_SoundScraper::cCast_W6wEkOHS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_c8VaBFHD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_cC2SayEE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Ffip56nk_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zXcUxeMC, HV_BINOP_ADD, 0, m, &cBinop_zXcUxeMC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VStxO6V3, 1, m, &cVar_VStxO6V3_sendMessage);
}

void Heavy_SoundScraper::cBinop_P98OWV7X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_G5CTjLOb, HV_BINOP_DIVIDE, 0, m, &cBinop_G5CTjLOb_sendMessage);
}

void Heavy_SoundScraper::cCast_Ffip56nk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eDCwJU4u_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_u6tCRSdr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_E4KGjYVQ, 0, m, &cVar_E4KGjYVQ_sendMessage);
}

void Heavy_SoundScraper::cCast_bO7RWsB7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8JqA46WM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_UndtSrm6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Q5eBp4nB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_WE1w8xe6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_OpefLW0W_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_ae3xyAfY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_p63Cfj8k, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_HNP5wgQ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 4.0f, 0, m, &cBinop_CJeMtzQo_sendMessage);
}

void Heavy_SoundScraper::cBinop_CJeMtzQo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qG9WTs91, 0, m, &cPack_qG9WTs91_sendMessage);
}

void Heavy_SoundScraper::cBinop_yWzxR8fM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_HNP5wgQ3_sendMessage);
}

void Heavy_SoundScraper::cCast_cAvRT3ov_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_FifJBIti_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_CpbqemE4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_T0889Qnm_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_ibRUtByE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.15f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_It0hd7na_sendMessage);
}

void Heavy_SoundScraper::cTabhead_g3PCOzNZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z6uhmgsK, HV_BINOP_SUBTRACT, 0, m, &cBinop_Z6uhmgsK_sendMessage);
}

void Heavy_SoundScraper::cMsg_FyJsi2xJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eUuDiaY5_sendMessage);
}

void Heavy_SoundScraper::cSystem_eUuDiaY5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_jSi1mm1d_sendMessage);
}

void Heavy_SoundScraper::cVar_fH6aAUco_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cAL65UxP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_tOrKbjoJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tOrKbjoJ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Buvmpqwm, 0, m, &cDelay_Buvmpqwm_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_LGsOmfpX, 0, m, &sTabread_LGsOmfpX_sendMessage);
}

void Heavy_SoundScraper::cDelay_Buvmpqwm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Buvmpqwm, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_LGsOmfpX, 0, m, &sTabread_LGsOmfpX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Buvmpqwm, 0, m, &cDelay_Buvmpqwm_sendMessage);
}

void Heavy_SoundScraper::sTabread_LGsOmfpX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_R9e0s6B1, HV_BINOP_SUBTRACT, 0, m, &cBinop_R9e0s6B1_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_iWi566uD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VaLj28Ed, HV_BINOP_MAX, 0, m, &cBinop_VaLj28Ed_sendMessage);
}

void Heavy_SoundScraper::cBinop_jSi1mm1d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iWi566uD, HV_BINOP_MULTIPLY, 0, m, &cBinop_iWi566uD_sendMessage);
}

void Heavy_SoundScraper::cBinop_Z6uhmgsK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0luoQI71_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_LGsOmfpX, 0, m, &sTabread_LGsOmfpX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TievV9Ij_sendMessage);
}

void Heavy_SoundScraper::cSystem_7crgNNxr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R9e0s6B1, HV_BINOP_SUBTRACT, 1, m, &cBinop_R9e0s6B1_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Buvmpqwm, 2, m, &cDelay_Buvmpqwm_sendMessage);
}

void Heavy_SoundScraper::cMsg_cAL65UxP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7crgNNxr_sendMessage);
}

void Heavy_SoundScraper::cMsg_0luoQI71_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_tOrKbjoJ, 0, m, &cDelay_tOrKbjoJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Buvmpqwm, 0, m, &cDelay_Buvmpqwm_sendMessage);
}

void Heavy_SoundScraper::cMsg_SBq5PRZt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_VaLj28Ed, HV_BINOP_MAX, 1, m, &cBinop_VaLj28Ed_sendMessage);
}

void Heavy_SoundScraper::cBinop_VaLj28Ed_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z6uhmgsK, HV_BINOP_SUBTRACT, 1, m, &cBinop_Z6uhmgsK_sendMessage);
}

void Heavy_SoundScraper::cCast_TievV9Ij_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tOrKbjoJ, 0, m, &cDelay_tOrKbjoJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_loDE7Krq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tOrKbjoJ, 2, m, &cDelay_tOrKbjoJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_R9e0s6B1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_loDE7Krq_sendMessage);
}

void Heavy_SoundScraper::cCast_170kn5vf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fH6aAUco, 0, m, &cVar_fH6aAUco_sendMessage);
  cMsg_FyJsi2xJ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_g3PCOzNZ, 0, m, &cTabhead_g3PCOzNZ_sendMessage);
}

void Heavy_SoundScraper::cTabhead_AsHJtCmo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_caTZs9RU, HV_BINOP_SUBTRACT, 0, m, &cBinop_caTZs9RU_sendMessage);
}

void Heavy_SoundScraper::cMsg_7MJnDTBo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ub5MFUaT_sendMessage);
}

void Heavy_SoundScraper::cSystem_ub5MFUaT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_EBQvWjZi_sendMessage);
}

void Heavy_SoundScraper::cVar_6jfaf4QE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gzNZRN0H_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_EM8SKTJ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_EM8SKTJ5, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_A8Ug1NOM, 0, m, &cDelay_A8Ug1NOM_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qYxCSyOB, 0, m, &sTabread_qYxCSyOB_sendMessage);
}

void Heavy_SoundScraper::cDelay_A8Ug1NOM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_A8Ug1NOM, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qYxCSyOB, 0, m, &sTabread_qYxCSyOB_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_A8Ug1NOM, 0, m, &cDelay_A8Ug1NOM_sendMessage);
}

void Heavy_SoundScraper::sTabread_qYxCSyOB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Fr63WfGn, HV_BINOP_SUBTRACT, 0, m, &cBinop_Fr63WfGn_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_HEnxbPb1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_X4a26lHQ, HV_BINOP_MAX, 0, m, &cBinop_X4a26lHQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_EBQvWjZi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HEnxbPb1, HV_BINOP_MULTIPLY, 0, m, &cBinop_HEnxbPb1_sendMessage);
}

void Heavy_SoundScraper::cBinop_caTZs9RU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2iBLhsg8_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qYxCSyOB, 0, m, &sTabread_qYxCSyOB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Mqd69SuQ_sendMessage);
}

void Heavy_SoundScraper::cSystem_ZvIsxcju_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Fr63WfGn, HV_BINOP_SUBTRACT, 1, m, &cBinop_Fr63WfGn_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_A8Ug1NOM, 2, m, &cDelay_A8Ug1NOM_sendMessage);
}

void Heavy_SoundScraper::cMsg_gzNZRN0H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZvIsxcju_sendMessage);
}

void Heavy_SoundScraper::cMsg_2iBLhsg8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_EM8SKTJ5, 0, m, &cDelay_EM8SKTJ5_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_A8Ug1NOM, 0, m, &cDelay_A8Ug1NOM_sendMessage);
}

void Heavy_SoundScraper::cMsg_Vt7SUgrt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_X4a26lHQ, HV_BINOP_MAX, 1, m, &cBinop_X4a26lHQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_X4a26lHQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_caTZs9RU, HV_BINOP_SUBTRACT, 1, m, &cBinop_caTZs9RU_sendMessage);
}

void Heavy_SoundScraper::cCast_Mqd69SuQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_EM8SKTJ5, 0, m, &cDelay_EM8SKTJ5_sendMessage);
}

void Heavy_SoundScraper::cBinop_a9Ofr08z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_EM8SKTJ5, 2, m, &cDelay_EM8SKTJ5_sendMessage);
}

void Heavy_SoundScraper::cBinop_Fr63WfGn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_a9Ofr08z_sendMessage);
}

void Heavy_SoundScraper::cCast_vr1Z859v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6jfaf4QE, 0, m, &cVar_6jfaf4QE_sendMessage);
  cMsg_7MJnDTBo_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_AsHJtCmo, 0, m, &cTabhead_AsHJtCmo_sendMessage);
}

void Heavy_SoundScraper::cTabhead_LQP9Us35_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cKnLvpo9, HV_BINOP_SUBTRACT, 0, m, &cBinop_cKnLvpo9_sendMessage);
}

void Heavy_SoundScraper::cMsg_1FGaC00x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ovt5fG2G_sendMessage);
}

void Heavy_SoundScraper::cSystem_ovt5fG2G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_UqlZI8MX_sendMessage);
}

void Heavy_SoundScraper::cVar_b68GLqBA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Je4H3N0Y_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_9iBIEjbE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9iBIEjbE, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_owMnlbpq, 0, m, &cDelay_owMnlbpq_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_24YroOvM, 0, m, &sTabread_24YroOvM_sendMessage);
}

void Heavy_SoundScraper::cDelay_owMnlbpq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_owMnlbpq, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_24YroOvM, 0, m, &sTabread_24YroOvM_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_owMnlbpq, 0, m, &cDelay_owMnlbpq_sendMessage);
}

void Heavy_SoundScraper::sTabread_24YroOvM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_VhwX8dGB, HV_BINOP_SUBTRACT, 0, m, &cBinop_VhwX8dGB_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_CYET5KGB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NkJAeDZT, HV_BINOP_MAX, 0, m, &cBinop_NkJAeDZT_sendMessage);
}

void Heavy_SoundScraper::cBinop_UqlZI8MX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CYET5KGB, HV_BINOP_MULTIPLY, 0, m, &cBinop_CYET5KGB_sendMessage);
}

void Heavy_SoundScraper::cBinop_cKnLvpo9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4IAQpDYI_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_24YroOvM, 0, m, &sTabread_24YroOvM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_h7vzR8mQ_sendMessage);
}

void Heavy_SoundScraper::cSystem_17f9GJID_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VhwX8dGB, HV_BINOP_SUBTRACT, 1, m, &cBinop_VhwX8dGB_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_owMnlbpq, 2, m, &cDelay_owMnlbpq_sendMessage);
}

void Heavy_SoundScraper::cMsg_Je4H3N0Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_17f9GJID_sendMessage);
}

void Heavy_SoundScraper::cMsg_4IAQpDYI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_9iBIEjbE, 0, m, &cDelay_9iBIEjbE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_owMnlbpq, 0, m, &cDelay_owMnlbpq_sendMessage);
}

void Heavy_SoundScraper::cMsg_pmUh3ayz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_NkJAeDZT, HV_BINOP_MAX, 1, m, &cBinop_NkJAeDZT_sendMessage);
}

void Heavy_SoundScraper::cBinop_NkJAeDZT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cKnLvpo9, HV_BINOP_SUBTRACT, 1, m, &cBinop_cKnLvpo9_sendMessage);
}

void Heavy_SoundScraper::cCast_h7vzR8mQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_9iBIEjbE, 0, m, &cDelay_9iBIEjbE_sendMessage);
}

void Heavy_SoundScraper::cBinop_8NPPZOLk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_9iBIEjbE, 2, m, &cDelay_9iBIEjbE_sendMessage);
}

void Heavy_SoundScraper::cBinop_VhwX8dGB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_8NPPZOLk_sendMessage);
}

void Heavy_SoundScraper::cCast_9gBnYujF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_b68GLqBA, 0, m, &cVar_b68GLqBA_sendMessage);
  cMsg_1FGaC00x_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_LQP9Us35, 0, m, &cTabhead_LQP9Us35_sendMessage);
}

void Heavy_SoundScraper::cTabhead_Skrp7sdn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1ZL9nMqH, HV_BINOP_SUBTRACT, 0, m, &cBinop_1ZL9nMqH_sendMessage);
}

void Heavy_SoundScraper::cMsg_bQRTA6jb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lHfOZw2L_sendMessage);
}

void Heavy_SoundScraper::cSystem_lHfOZw2L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_JufBq9JH_sendMessage);
}

void Heavy_SoundScraper::cVar_DHPHC5Ky_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IjYtY4WW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_g1LR5Yyr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_g1LR5Yyr, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xljfed7f, 0, m, &cDelay_xljfed7f_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_dBcW5fTF, 0, m, &sTabread_dBcW5fTF_sendMessage);
}

void Heavy_SoundScraper::cDelay_xljfed7f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_xljfed7f, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_dBcW5fTF, 0, m, &sTabread_dBcW5fTF_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xljfed7f, 0, m, &cDelay_xljfed7f_sendMessage);
}

void Heavy_SoundScraper::sTabread_dBcW5fTF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_DmNbstYJ, HV_BINOP_SUBTRACT, 0, m, &cBinop_DmNbstYJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_tykB8oH9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xNny8rLX, HV_BINOP_MAX, 0, m, &cBinop_xNny8rLX_sendMessage);
}

void Heavy_SoundScraper::cBinop_JufBq9JH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tykB8oH9, HV_BINOP_MULTIPLY, 0, m, &cBinop_tykB8oH9_sendMessage);
}

void Heavy_SoundScraper::cBinop_1ZL9nMqH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2QfrAnPH_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_dBcW5fTF, 0, m, &sTabread_dBcW5fTF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XcykWEcL_sendMessage);
}

void Heavy_SoundScraper::cSystem_0E5oQs2G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DmNbstYJ, HV_BINOP_SUBTRACT, 1, m, &cBinop_DmNbstYJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xljfed7f, 2, m, &cDelay_xljfed7f_sendMessage);
}

void Heavy_SoundScraper::cMsg_IjYtY4WW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0E5oQs2G_sendMessage);
}

void Heavy_SoundScraper::cMsg_2QfrAnPH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_g1LR5Yyr, 0, m, &cDelay_g1LR5Yyr_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xljfed7f, 0, m, &cDelay_xljfed7f_sendMessage);
}

void Heavy_SoundScraper::cMsg_HY4I9FRO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_xNny8rLX, HV_BINOP_MAX, 1, m, &cBinop_xNny8rLX_sendMessage);
}

void Heavy_SoundScraper::cBinop_xNny8rLX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1ZL9nMqH, HV_BINOP_SUBTRACT, 1, m, &cBinop_1ZL9nMqH_sendMessage);
}

void Heavy_SoundScraper::cCast_XcykWEcL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_g1LR5Yyr, 0, m, &cDelay_g1LR5Yyr_sendMessage);
}

void Heavy_SoundScraper::cBinop_7q28kMT2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_g1LR5Yyr, 2, m, &cDelay_g1LR5Yyr_sendMessage);
}

void Heavy_SoundScraper::cBinop_DmNbstYJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_7q28kMT2_sendMessage);
}

void Heavy_SoundScraper::cCast_Kd9YHUbe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DHPHC5Ky, 0, m, &cVar_DHPHC5Ky_sendMessage);
  cMsg_bQRTA6jb_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Skrp7sdn, 0, m, &cTabhead_Skrp7sdn_sendMessage);
}

void Heavy_SoundScraper::cMsg_TClg80ov_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CNkmtAyk_sendMessage);
}

void Heavy_SoundScraper::cSystem_CNkmtAyk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_0IfJHKZy_sendMessage);
}

void Heavy_SoundScraper::cDelay_g1otyzfD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_g1otyzfD, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_YXlJRMAG, 0, m, &cDelay_YXlJRMAG_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_g1otyzfD, 0, m, &cDelay_g1otyzfD_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_4smFJoMr, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_YXlJRMAG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_YXlJRMAG, m);
  cMsg_dXuerztA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_ujyKNZwd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_oUfDrlTe_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_2WGB4Flk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oxqy5L2A_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_EfQ3r6vv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EjJEr4QK_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_g1otyzfD, 2, m, &cDelay_g1otyzfD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cVqO1rtR_sendMessage);
}

void Heavy_SoundScraper::cMsg_oxqy5L2A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_EfQ3r6vv, 0, m, &hTable_EfQ3r6vv_sendMessage);
}

void Heavy_SoundScraper::cBinop_0IfJHKZy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_2WGB4Flk_sendMessage);
}

void Heavy_SoundScraper::cMsg_dXuerztA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_EfQ3r6vv, 0, m, &hTable_EfQ3r6vv_sendMessage);
}

void Heavy_SoundScraper::cCast_cVqO1rtR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_g1otyzfD, 0, m, &cDelay_g1otyzfD_sendMessage);
}

void Heavy_SoundScraper::cMsg_EjJEr4QK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_YXlJRMAG, 2, m, &cDelay_YXlJRMAG_sendMessage);
}

void Heavy_SoundScraper::cMsg_oUfDrlTe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_4smFJoMr, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_olqWoLDC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BQZsHGzU_sendMessage);
}

void Heavy_SoundScraper::cSystem_BQZsHGzU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_w3OfQEuI_sendMessage);
}

void Heavy_SoundScraper::cDelay_5PHmuHVa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5PHmuHVa, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rKBYP7Gn, 0, m, &cDelay_rKBYP7Gn_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5PHmuHVa, 0, m, &cDelay_5PHmuHVa_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_5icomM8V, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_rKBYP7Gn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rKBYP7Gn, m);
  cMsg_hzH7bL4g_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_vwybLi5r_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_oK8Ihjej_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_2uYHSAID_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_u8CROuFS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_29SNVBBY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6ba8G7uM_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5PHmuHVa, 2, m, &cDelay_5PHmuHVa_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2ESJ7tm4_sendMessage);
}

void Heavy_SoundScraper::cMsg_u8CROuFS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_29SNVBBY, 0, m, &hTable_29SNVBBY_sendMessage);
}

void Heavy_SoundScraper::cBinop_w3OfQEuI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_2uYHSAID_sendMessage);
}

void Heavy_SoundScraper::cMsg_hzH7bL4g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_29SNVBBY, 0, m, &hTable_29SNVBBY_sendMessage);
}

void Heavy_SoundScraper::cCast_2ESJ7tm4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5PHmuHVa, 0, m, &cDelay_5PHmuHVa_sendMessage);
}

void Heavy_SoundScraper::cMsg_6ba8G7uM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_rKBYP7Gn, 2, m, &cDelay_rKBYP7Gn_sendMessage);
}

void Heavy_SoundScraper::cMsg_oK8Ihjej_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_5icomM8V, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_MH9KRoXU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_az7q43Y0_sendMessage);
}

void Heavy_SoundScraper::cSystem_az7q43Y0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_2banCvps_sendMessage);
}

void Heavy_SoundScraper::cDelay_PCPIkxZt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_PCPIkxZt, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SjFt6v6p, 0, m, &cDelay_SjFt6v6p_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PCPIkxZt, 0, m, &cDelay_PCPIkxZt_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_9EGvsKhJ, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_SjFt6v6p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SjFt6v6p, m);
  cMsg_teqOqETF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_n1vTKWcI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_XAkv87PQ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_OalNEdWT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RTubKcMZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_xRTC2smU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0NW2xvYQ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PCPIkxZt, 2, m, &cDelay_PCPIkxZt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nZpbCdIL_sendMessage);
}

void Heavy_SoundScraper::cMsg_RTubKcMZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_xRTC2smU, 0, m, &hTable_xRTC2smU_sendMessage);
}

void Heavy_SoundScraper::cBinop_2banCvps_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_OalNEdWT_sendMessage);
}

void Heavy_SoundScraper::cMsg_teqOqETF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_xRTC2smU, 0, m, &hTable_xRTC2smU_sendMessage);
}

void Heavy_SoundScraper::cCast_nZpbCdIL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_PCPIkxZt, 0, m, &cDelay_PCPIkxZt_sendMessage);
}

void Heavy_SoundScraper::cMsg_0NW2xvYQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_SjFt6v6p, 2, m, &cDelay_SjFt6v6p_sendMessage);
}

void Heavy_SoundScraper::cMsg_XAkv87PQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_9EGvsKhJ, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_IKZaG5aV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_EhJMRCyI_sendMessage);
}

void Heavy_SoundScraper::cSystem_EhJMRCyI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_xVo9xKqc_sendMessage);
}

void Heavy_SoundScraper::cDelay_YDEoTNip_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_YDEoTNip, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uNlc5YNE, 0, m, &cDelay_uNlc5YNE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_YDEoTNip, 0, m, &cDelay_YDEoTNip_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_J5jbD6iy, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_uNlc5YNE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_uNlc5YNE, m);
  cMsg_BSuiDC8I_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_wBBq3zbh_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_zxdMh4UQ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_9J2RQY3q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_J1xWAqwq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_rOK83OZK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FF19ZCf0_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_YDEoTNip, 2, m, &cDelay_YDEoTNip_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_63i7sbYD_sendMessage);
}

void Heavy_SoundScraper::cMsg_J1xWAqwq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_rOK83OZK, 0, m, &hTable_rOK83OZK_sendMessage);
}

void Heavy_SoundScraper::cBinop_xVo9xKqc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_9J2RQY3q_sendMessage);
}

void Heavy_SoundScraper::cMsg_BSuiDC8I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_rOK83OZK, 0, m, &hTable_rOK83OZK_sendMessage);
}

void Heavy_SoundScraper::cCast_63i7sbYD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YDEoTNip, 0, m, &cDelay_YDEoTNip_sendMessage);
}

void Heavy_SoundScraper::cMsg_FF19ZCf0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_uNlc5YNE, 2, m, &cDelay_uNlc5YNE_sendMessage);
}

void Heavy_SoundScraper::cMsg_zxdMh4UQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_J5jbD6iy, 1, m, NULL);
}

void Heavy_SoundScraper::cIf_cMuFIteP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_oC5Ubxra_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_nZF5OXZ2_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_53Hv8ARU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_n7r7Ygrm, HV_BINOP_POW, 0, m, &cBinop_n7r7Ygrm_sendMessage);
}

void Heavy_SoundScraper::cBinop_n7r7Ygrm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_lOr2JnlF_sendMessage);
}

void Heavy_SoundScraper::cBinop_iOD2qcKt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_zhcl7Stm_sendMessage);
}

void Heavy_SoundScraper::cCast_ighqRCKn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_jskJ5178_sendMessage);
}

void Heavy_SoundScraper::cCast_WkbrfEhy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_cMuFIteP, 0, m, &cIf_cMuFIteP_sendMessage);
}

void Heavy_SoundScraper::cBinop_jskJ5178_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_cMuFIteP, 1, m, &cIf_cMuFIteP_sendMessage);
}

void Heavy_SoundScraper::cBinop_nZF5OXZ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_iOD2qcKt_sendMessage);
}

void Heavy_SoundScraper::cMsg_oC5Ubxra_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_lOr2JnlF_sendMessage);
}

void Heavy_SoundScraper::cBinop_zhcl7Stm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n7r7Ygrm, HV_BINOP_POW, 1, m, &cBinop_n7r7Ygrm_sendMessage);
  cMsg_53Hv8ARU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_KRvfoe96_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_s8PbC4XD, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_f2lH268q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_PiBRAEvF, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_g8aqUxzH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ixHTycjC_sendMessage);
}

void Heavy_SoundScraper::cBinop_ixHTycjC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_qTTD7dOm_sendMessage);
}

void Heavy_SoundScraper::cVar_aOQ9OlCb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WDHuPXuO, HV_BINOP_MULTIPLY, 0, m, &cBinop_WDHuPXuO_sendMessage);
}

void Heavy_SoundScraper::cMsg_RUcN0Zpk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SB8TbCxw_sendMessage);
}

void Heavy_SoundScraper::cSystem_SB8TbCxw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OOxPrlO4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_WDHuPXuO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_hWd84Uuk_sendMessage);
}

void Heavy_SoundScraper::cBinop_PXZ5eByq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WDHuPXuO, HV_BINOP_MULTIPLY, 1, m, &cBinop_WDHuPXuO_sendMessage);
}

void Heavy_SoundScraper::cMsg_OOxPrlO4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_PXZ5eByq_sendMessage);
}

void Heavy_SoundScraper::cBinop_hWd84Uuk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_3efkuH4m_sendMessage);
}

void Heavy_SoundScraper::cBinop_3efkuH4m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_xOn5tQyZ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_bVMYZ015, m);
}

void Heavy_SoundScraper::cBinop_xOn5tQyZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_E868jMd7, m);
}

void Heavy_SoundScraper::cVar_YSTFFx4C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ighqRCKn_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WkbrfEhy_sendMessage);
}

void Heavy_SoundScraper::cVar_yJzowiDV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_g8aqUxzH_sendMessage);
}

void Heavy_SoundScraper::cVar_XgN9UCBQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_PlmpHrci_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_BylArrXd, 0, m, &cIf_BylArrXd_sendMessage);
}

void Heavy_SoundScraper::cVar_I3vAVxsQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_AqXDPB0q_sendMessage);
}

void Heavy_SoundScraper::cIf_BylArrXd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_EtJut6fV_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_eWJNR6xq, 0, m, &cVar_eWJNR6xq_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_PlmpHrci_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_BylArrXd, 1, m, &cIf_BylArrXd_sendMessage);
}

void Heavy_SoundScraper::cBinop_AqXDPB0q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_d58GitP5_sendMessage);
}

void Heavy_SoundScraper::cBinop_d58GitP5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3X3wCO5K, 0, m, &cVar_3X3wCO5K_sendMessage);
}

void Heavy_SoundScraper::cTabhead_Gy16jHUe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8nhNjU0w, HV_BINOP_SUBTRACT, 0, m, &cBinop_8nhNjU0w_sendMessage);
}

void Heavy_SoundScraper::cMsg_TFVlrPQF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YfBeQF7J_sendMessage);
}

void Heavy_SoundScraper::cSystem_YfBeQF7J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_HGVI9oQf_sendMessage);
}

void Heavy_SoundScraper::cVar_0Be0FaQ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0JcXL8Eb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_fwCw9U1P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fwCw9U1P, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jz9JNZyW, 0, m, &cDelay_jz9JNZyW_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fti8cOzu, 0, m, &sTabread_fti8cOzu_sendMessage);
}

void Heavy_SoundScraper::cDelay_jz9JNZyW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_jz9JNZyW, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fti8cOzu, 0, m, &sTabread_fti8cOzu_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jz9JNZyW, 0, m, &cDelay_jz9JNZyW_sendMessage);
}

void Heavy_SoundScraper::sTabread_fti8cOzu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ZWfbD4Vh, HV_BINOP_SUBTRACT, 0, m, &cBinop_ZWfbD4Vh_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_4vJlABzX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OMDm8DCO, HV_BINOP_MAX, 0, m, &cBinop_OMDm8DCO_sendMessage);
}

void Heavy_SoundScraper::cBinop_HGVI9oQf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4vJlABzX, HV_BINOP_MULTIPLY, 0, m, &cBinop_4vJlABzX_sendMessage);
}

void Heavy_SoundScraper::cBinop_8nhNjU0w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yFwBMnSH_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fti8cOzu, 0, m, &sTabread_fti8cOzu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_431AqmxN_sendMessage);
}

void Heavy_SoundScraper::cSystem_EDeiIcUR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZWfbD4Vh, HV_BINOP_SUBTRACT, 1, m, &cBinop_ZWfbD4Vh_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jz9JNZyW, 2, m, &cDelay_jz9JNZyW_sendMessage);
}

void Heavy_SoundScraper::cMsg_0JcXL8Eb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_EDeiIcUR_sendMessage);
}

void Heavy_SoundScraper::cMsg_yFwBMnSH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_fwCw9U1P, 0, m, &cDelay_fwCw9U1P_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jz9JNZyW, 0, m, &cDelay_jz9JNZyW_sendMessage);
}

void Heavy_SoundScraper::cMsg_WQCJuMwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_OMDm8DCO, HV_BINOP_MAX, 1, m, &cBinop_OMDm8DCO_sendMessage);
}

void Heavy_SoundScraper::cBinop_OMDm8DCO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8nhNjU0w, HV_BINOP_SUBTRACT, 1, m, &cBinop_8nhNjU0w_sendMessage);
}

void Heavy_SoundScraper::cCast_431AqmxN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_fwCw9U1P, 0, m, &cDelay_fwCw9U1P_sendMessage);
}

void Heavy_SoundScraper::cBinop_7zTP8S4J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_fwCw9U1P, 2, m, &cDelay_fwCw9U1P_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZWfbD4Vh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_7zTP8S4J_sendMessage);
}

void Heavy_SoundScraper::cCast_HNnYC6TT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0Be0FaQ5, 0, m, &cVar_0Be0FaQ5_sendMessage);
  cMsg_TFVlrPQF_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Gy16jHUe, 0, m, &cTabhead_Gy16jHUe_sendMessage);
}

void Heavy_SoundScraper::cMsg_N80OSpb9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qzuYXGFv_sendMessage);
}

void Heavy_SoundScraper::cSystem_qzuYXGFv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_8baipqbF_sendMessage);
}

void Heavy_SoundScraper::cDelay_cHndQfS4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cHndQfS4, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wRyonlly, 0, m, &cDelay_wRyonlly_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cHndQfS4, 0, m, &cDelay_cHndQfS4_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_VH2XTCj3, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_wRyonlly_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wRyonlly, m);
  cMsg_yBGhfXr3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_kyxci8Va_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_RKVaLRaj_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_f4FyXAdA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_b0YjbrFN_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_XJkV9INz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TPYOzb4d_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cHndQfS4, 2, m, &cDelay_cHndQfS4_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BtALykxu_sendMessage);
}

void Heavy_SoundScraper::cMsg_b0YjbrFN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_XJkV9INz, 0, m, &hTable_XJkV9INz_sendMessage);
}

void Heavy_SoundScraper::cBinop_8baipqbF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_f4FyXAdA_sendMessage);
}

void Heavy_SoundScraper::cMsg_yBGhfXr3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_XJkV9INz, 0, m, &hTable_XJkV9INz_sendMessage);
}

void Heavy_SoundScraper::cCast_BtALykxu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_cHndQfS4, 0, m, &cDelay_cHndQfS4_sendMessage);
}

void Heavy_SoundScraper::cMsg_TPYOzb4d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_wRyonlly, 2, m, &cDelay_wRyonlly_sendMessage);
}

void Heavy_SoundScraper::cMsg_RKVaLRaj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_VH2XTCj3, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_UQWPnZWy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QTCvj0bB, HV_BINOP_SUBTRACT, 0, m, &cBinop_QTCvj0bB_sendMessage);
}

void Heavy_SoundScraper::cMsg_6dYylrfm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SLDf8Jge_sendMessage);
}

void Heavy_SoundScraper::cSystem_SLDf8Jge_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_PqNp2pXH_sendMessage);
}

void Heavy_SoundScraper::cVar_ZZxe0UrA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cGi5oQV6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_WEJrUFZ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WEJrUFZ0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KLExhJzL, 0, m, &cDelay_KLExhJzL_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_NPayNecx, 0, m, &sTabread_NPayNecx_sendMessage);
}

void Heavy_SoundScraper::cDelay_KLExhJzL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KLExhJzL, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_NPayNecx, 0, m, &sTabread_NPayNecx_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KLExhJzL, 0, m, &cDelay_KLExhJzL_sendMessage);
}

void Heavy_SoundScraper::sTabread_NPayNecx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_sYdRcwgd, HV_BINOP_SUBTRACT, 0, m, &cBinop_sYdRcwgd_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_1MzqNeCN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ygd0ik7l, HV_BINOP_MAX, 0, m, &cBinop_ygd0ik7l_sendMessage);
}

void Heavy_SoundScraper::cBinop_PqNp2pXH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1MzqNeCN, HV_BINOP_MULTIPLY, 0, m, &cBinop_1MzqNeCN_sendMessage);
}

void Heavy_SoundScraper::cBinop_QTCvj0bB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KZIvsAxn_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_NPayNecx, 0, m, &sTabread_NPayNecx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jHzSo7wH_sendMessage);
}

void Heavy_SoundScraper::cSystem_Ze1YPWIx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sYdRcwgd, HV_BINOP_SUBTRACT, 1, m, &cBinop_sYdRcwgd_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KLExhJzL, 2, m, &cDelay_KLExhJzL_sendMessage);
}

void Heavy_SoundScraper::cMsg_cGi5oQV6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Ze1YPWIx_sendMessage);
}

void Heavy_SoundScraper::cMsg_KZIvsAxn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_WEJrUFZ0, 0, m, &cDelay_WEJrUFZ0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KLExhJzL, 0, m, &cDelay_KLExhJzL_sendMessage);
}

void Heavy_SoundScraper::cMsg_qmo7ShAQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_ygd0ik7l, HV_BINOP_MAX, 1, m, &cBinop_ygd0ik7l_sendMessage);
}

void Heavy_SoundScraper::cBinop_ygd0ik7l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QTCvj0bB, HV_BINOP_SUBTRACT, 1, m, &cBinop_QTCvj0bB_sendMessage);
}

void Heavy_SoundScraper::cCast_jHzSo7wH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_WEJrUFZ0, 0, m, &cDelay_WEJrUFZ0_sendMessage);
}

void Heavy_SoundScraper::cBinop_YBVkPWM0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_WEJrUFZ0, 2, m, &cDelay_WEJrUFZ0_sendMessage);
}

void Heavy_SoundScraper::cBinop_sYdRcwgd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_YBVkPWM0_sendMessage);
}

void Heavy_SoundScraper::cCast_vwfHZ3Qx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZZxe0UrA, 0, m, &cVar_ZZxe0UrA_sendMessage);
  cMsg_6dYylrfm_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_UQWPnZWy, 0, m, &cTabhead_UQWPnZWy_sendMessage);
}

void Heavy_SoundScraper::cMsg_Qy430MmB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7t41Wm8U_sendMessage);
}

void Heavy_SoundScraper::cSystem_7t41Wm8U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_UnIHqAUQ_sendMessage);
}

void Heavy_SoundScraper::cDelay_4CLqT6ya_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4CLqT6ya, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cPdDxgPc, 0, m, &cDelay_cPdDxgPc_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4CLqT6ya, 0, m, &cDelay_4CLqT6ya_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_zIZH708J, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_cPdDxgPc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cPdDxgPc, m);
  cMsg_s9FtIqOi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_2kpxIgb8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_UvwPAsjS_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_WIuLg0lT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_M125rwF3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_d8pDnroX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iU6t3HxO_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4CLqT6ya, 2, m, &cDelay_4CLqT6ya_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gVClRYyz_sendMessage);
}

void Heavy_SoundScraper::cMsg_M125rwF3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_d8pDnroX, 0, m, &hTable_d8pDnroX_sendMessage);
}

void Heavy_SoundScraper::cBinop_UnIHqAUQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_WIuLg0lT_sendMessage);
}

void Heavy_SoundScraper::cMsg_s9FtIqOi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_d8pDnroX, 0, m, &hTable_d8pDnroX_sendMessage);
}

void Heavy_SoundScraper::cCast_gVClRYyz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_4CLqT6ya, 0, m, &cDelay_4CLqT6ya_sendMessage);
}

void Heavy_SoundScraper::cMsg_iU6t3HxO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_cPdDxgPc, 2, m, &cDelay_cPdDxgPc_sendMessage);
}

void Heavy_SoundScraper::cMsg_UvwPAsjS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_zIZH708J, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_ih5GnYAW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vLbyUb7u, HV_BINOP_SUBTRACT, 0, m, &cBinop_vLbyUb7u_sendMessage);
}

void Heavy_SoundScraper::cMsg_KkqyEtNV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WBoTTNUB_sendMessage);
}

void Heavy_SoundScraper::cSystem_WBoTTNUB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Ao2hr7s1_sendMessage);
}

void Heavy_SoundScraper::cVar_h3IcUmL7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NFE5JaRB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_XhSLtOMi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XhSLtOMi, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Tg57vlRw, 0, m, &cDelay_Tg57vlRw_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_sCROyNou, 0, m, &sTabread_sCROyNou_sendMessage);
}

void Heavy_SoundScraper::cDelay_Tg57vlRw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Tg57vlRw, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_sCROyNou, 0, m, &sTabread_sCROyNou_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Tg57vlRw, 0, m, &cDelay_Tg57vlRw_sendMessage);
}

void Heavy_SoundScraper::sTabread_sCROyNou_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ROHT4qz6, HV_BINOP_SUBTRACT, 0, m, &cBinop_ROHT4qz6_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_MqQ29EMi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_L89ru6Zw, HV_BINOP_MAX, 0, m, &cBinop_L89ru6Zw_sendMessage);
}

void Heavy_SoundScraper::cBinop_Ao2hr7s1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MqQ29EMi, HV_BINOP_MULTIPLY, 0, m, &cBinop_MqQ29EMi_sendMessage);
}

void Heavy_SoundScraper::cBinop_vLbyUb7u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_E26ur4Gc_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_sCROyNou, 0, m, &sTabread_sCROyNou_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3tw3YI9P_sendMessage);
}

void Heavy_SoundScraper::cSystem_iaTZvK1y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ROHT4qz6, HV_BINOP_SUBTRACT, 1, m, &cBinop_ROHT4qz6_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Tg57vlRw, 2, m, &cDelay_Tg57vlRw_sendMessage);
}

void Heavy_SoundScraper::cMsg_NFE5JaRB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iaTZvK1y_sendMessage);
}

void Heavy_SoundScraper::cMsg_E26ur4Gc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_XhSLtOMi, 0, m, &cDelay_XhSLtOMi_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Tg57vlRw, 0, m, &cDelay_Tg57vlRw_sendMessage);
}

void Heavy_SoundScraper::cMsg_nzJoNems_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_L89ru6Zw, HV_BINOP_MAX, 1, m, &cBinop_L89ru6Zw_sendMessage);
}

void Heavy_SoundScraper::cBinop_L89ru6Zw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vLbyUb7u, HV_BINOP_SUBTRACT, 1, m, &cBinop_vLbyUb7u_sendMessage);
}

void Heavy_SoundScraper::cCast_3tw3YI9P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XhSLtOMi, 0, m, &cDelay_XhSLtOMi_sendMessage);
}

void Heavy_SoundScraper::cBinop_S9g0DwAW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XhSLtOMi, 2, m, &cDelay_XhSLtOMi_sendMessage);
}

void Heavy_SoundScraper::cBinop_ROHT4qz6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_S9g0DwAW_sendMessage);
}

void Heavy_SoundScraper::cCast_Q71D9RNr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_h3IcUmL7, 0, m, &cVar_h3IcUmL7_sendMessage);
  cMsg_KkqyEtNV_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ih5GnYAW, 0, m, &cTabhead_ih5GnYAW_sendMessage);
}

void Heavy_SoundScraper::cMsg_izNPN0tE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yK7QHr4w_sendMessage);
}

void Heavy_SoundScraper::cSystem_yK7QHr4w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_hWIv5Kbt_sendMessage);
}

void Heavy_SoundScraper::cDelay_UjQMPD72_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UjQMPD72, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_MKnIWlgl, 0, m, &cDelay_MKnIWlgl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UjQMPD72, 0, m, &cDelay_UjQMPD72_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_tR4UuY3m, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_MKnIWlgl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_MKnIWlgl, m);
  cMsg_hwsPGc59_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_cIOCPpu4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_2lSPoLyX_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_Ts2NgqOG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eIVjejbj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_3hU40Lfe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Hy47ZeVD_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UjQMPD72, 2, m, &cDelay_UjQMPD72_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JaX6EZnZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_eIVjejbj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_3hU40Lfe, 0, m, &hTable_3hU40Lfe_sendMessage);
}

void Heavy_SoundScraper::cBinop_hWIv5Kbt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_Ts2NgqOG_sendMessage);
}

void Heavy_SoundScraper::cMsg_hwsPGc59_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_3hU40Lfe, 0, m, &hTable_3hU40Lfe_sendMessage);
}

void Heavy_SoundScraper::cCast_JaX6EZnZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_UjQMPD72, 0, m, &cDelay_UjQMPD72_sendMessage);
}

void Heavy_SoundScraper::cMsg_Hy47ZeVD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_MKnIWlgl, 2, m, &cDelay_MKnIWlgl_sendMessage);
}

void Heavy_SoundScraper::cMsg_2lSPoLyX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_tR4UuY3m, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_8RQheQpP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FkRzvFQV, HV_BINOP_SUBTRACT, 0, m, &cBinop_FkRzvFQV_sendMessage);
}

void Heavy_SoundScraper::cMsg_jZpzwFlS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8dwbamCC_sendMessage);
}

void Heavy_SoundScraper::cSystem_8dwbamCC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_RafGiCTC_sendMessage);
}

void Heavy_SoundScraper::cVar_3wJR809q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rPP2Eq4t_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_ZjTnwxEP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ZjTnwxEP, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QGH6DjFZ, 0, m, &cDelay_QGH6DjFZ_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3EAeJgdk, 0, m, &sTabread_3EAeJgdk_sendMessage);
}

void Heavy_SoundScraper::cDelay_QGH6DjFZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_QGH6DjFZ, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3EAeJgdk, 0, m, &sTabread_3EAeJgdk_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QGH6DjFZ, 0, m, &cDelay_QGH6DjFZ_sendMessage);
}

void Heavy_SoundScraper::sTabread_3EAeJgdk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_QhuDa71d, HV_BINOP_SUBTRACT, 0, m, &cBinop_QhuDa71d_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_Ti0lR88O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZyRehKXi, HV_BINOP_MAX, 0, m, &cBinop_ZyRehKXi_sendMessage);
}

void Heavy_SoundScraper::cBinop_RafGiCTC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ti0lR88O, HV_BINOP_MULTIPLY, 0, m, &cBinop_Ti0lR88O_sendMessage);
}

void Heavy_SoundScraper::cBinop_FkRzvFQV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_faxEFRRq_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3EAeJgdk, 0, m, &sTabread_3EAeJgdk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5oPx2KR2_sendMessage);
}

void Heavy_SoundScraper::cSystem_B2H5cFRh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QhuDa71d, HV_BINOP_SUBTRACT, 1, m, &cBinop_QhuDa71d_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QGH6DjFZ, 2, m, &cDelay_QGH6DjFZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_rPP2Eq4t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_B2H5cFRh_sendMessage);
}

void Heavy_SoundScraper::cMsg_faxEFRRq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZjTnwxEP, 0, m, &cDelay_ZjTnwxEP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QGH6DjFZ, 0, m, &cDelay_QGH6DjFZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_Pm6BgNnu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZyRehKXi, HV_BINOP_MAX, 1, m, &cBinop_ZyRehKXi_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZyRehKXi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FkRzvFQV, HV_BINOP_SUBTRACT, 1, m, &cBinop_FkRzvFQV_sendMessage);
}

void Heavy_SoundScraper::cCast_5oPx2KR2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZjTnwxEP, 0, m, &cDelay_ZjTnwxEP_sendMessage);
}

void Heavy_SoundScraper::cBinop_Rtf4ecis_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZjTnwxEP, 2, m, &cDelay_ZjTnwxEP_sendMessage);
}

void Heavy_SoundScraper::cBinop_QhuDa71d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Rtf4ecis_sendMessage);
}

void Heavy_SoundScraper::cCast_1ErIFoes_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3wJR809q, 0, m, &cVar_3wJR809q_sendMessage);
  cMsg_jZpzwFlS_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_8RQheQpP, 0, m, &cTabhead_8RQheQpP_sendMessage);
}

void Heavy_SoundScraper::cMsg_2hqU7Ygt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UBnh0Egm_sendMessage);
}

void Heavy_SoundScraper::cSystem_UBnh0Egm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_RnRG0dLH_sendMessage);
}

void Heavy_SoundScraper::cDelay_uaVUEcla_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_uaVUEcla, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_K0M1Azgn, 0, m, &cDelay_K0M1Azgn_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uaVUEcla, 0, m, &cDelay_uaVUEcla_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_QbsSxHTs, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_K0M1Azgn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_K0M1Azgn, m);
  cMsg_s8BH5NzO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_cby7Hfyo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_jpnLOLfJ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_bhbOo5qg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xtBGkY1E_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_Qk4Aw7or_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XI10veBw_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uaVUEcla, 2, m, &cDelay_uaVUEcla_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_s60RMS3Y_sendMessage);
}

void Heavy_SoundScraper::cMsg_xtBGkY1E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Qk4Aw7or, 0, m, &hTable_Qk4Aw7or_sendMessage);
}

void Heavy_SoundScraper::cBinop_RnRG0dLH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_bhbOo5qg_sendMessage);
}

void Heavy_SoundScraper::cMsg_s8BH5NzO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Qk4Aw7or, 0, m, &hTable_Qk4Aw7or_sendMessage);
}

void Heavy_SoundScraper::cCast_s60RMS3Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_uaVUEcla, 0, m, &cDelay_uaVUEcla_sendMessage);
}

void Heavy_SoundScraper::cMsg_XI10veBw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_K0M1Azgn, 2, m, &cDelay_K0M1Azgn_sendMessage);
}

void Heavy_SoundScraper::cMsg_jpnLOLfJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_QbsSxHTs, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_lgfETbHV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RDiEEeLi, HV_BINOP_SUBTRACT, 0, m, &cBinop_RDiEEeLi_sendMessage);
}

void Heavy_SoundScraper::cMsg_N2lVLt1f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AGYjIsSr_sendMessage);
}

void Heavy_SoundScraper::cSystem_AGYjIsSr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_FEl5ymbb_sendMessage);
}

void Heavy_SoundScraper::cVar_TEvax844_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GHyyWtPL_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_1JDYpUAl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1JDYpUAl, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Tc2kTUOA, 0, m, &cDelay_Tc2kTUOA_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_hGu1xi2l, 0, m, &sTabread_hGu1xi2l_sendMessage);
}

void Heavy_SoundScraper::cDelay_Tc2kTUOA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Tc2kTUOA, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_hGu1xi2l, 0, m, &sTabread_hGu1xi2l_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Tc2kTUOA, 0, m, &cDelay_Tc2kTUOA_sendMessage);
}

void Heavy_SoundScraper::sTabread_hGu1xi2l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_baItZxnJ, HV_BINOP_SUBTRACT, 0, m, &cBinop_baItZxnJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_EpCa9iwe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cJ7RqRHw, HV_BINOP_MAX, 0, m, &cBinop_cJ7RqRHw_sendMessage);
}

void Heavy_SoundScraper::cBinop_FEl5ymbb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EpCa9iwe, HV_BINOP_MULTIPLY, 0, m, &cBinop_EpCa9iwe_sendMessage);
}

void Heavy_SoundScraper::cBinop_RDiEEeLi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6Vqf8ybl_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_hGu1xi2l, 0, m, &sTabread_hGu1xi2l_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3Bt6avkv_sendMessage);
}

void Heavy_SoundScraper::cSystem_eIVqOCKM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_baItZxnJ, HV_BINOP_SUBTRACT, 1, m, &cBinop_baItZxnJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Tc2kTUOA, 2, m, &cDelay_Tc2kTUOA_sendMessage);
}

void Heavy_SoundScraper::cMsg_GHyyWtPL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eIVqOCKM_sendMessage);
}

void Heavy_SoundScraper::cMsg_6Vqf8ybl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_1JDYpUAl, 0, m, &cDelay_1JDYpUAl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Tc2kTUOA, 0, m, &cDelay_Tc2kTUOA_sendMessage);
}

void Heavy_SoundScraper::cMsg_x8C2PuEG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_cJ7RqRHw, HV_BINOP_MAX, 1, m, &cBinop_cJ7RqRHw_sendMessage);
}

void Heavy_SoundScraper::cBinop_cJ7RqRHw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RDiEEeLi, HV_BINOP_SUBTRACT, 1, m, &cBinop_RDiEEeLi_sendMessage);
}

void Heavy_SoundScraper::cCast_3Bt6avkv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_1JDYpUAl, 0, m, &cDelay_1JDYpUAl_sendMessage);
}

void Heavy_SoundScraper::cBinop_dHBqQYBk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_1JDYpUAl, 2, m, &cDelay_1JDYpUAl_sendMessage);
}

void Heavy_SoundScraper::cBinop_baItZxnJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_dHBqQYBk_sendMessage);
}

void Heavy_SoundScraper::cCast_Da3gAVMx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TEvax844, 0, m, &cVar_TEvax844_sendMessage);
  cMsg_N2lVLt1f_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_lgfETbHV, 0, m, &cTabhead_lgfETbHV_sendMessage);
}

void Heavy_SoundScraper::cMsg_z1OcXc5g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3eBa8FTr_sendMessage);
}

void Heavy_SoundScraper::cSystem_3eBa8FTr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ITKNgk3d_sendMessage);
}

void Heavy_SoundScraper::cDelay_uDO5liSr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_uDO5liSr, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lG0bcxz8, 0, m, &cDelay_lG0bcxz8_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uDO5liSr, 0, m, &cDelay_uDO5liSr_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_m9Hu7Ufg, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_lG0bcxz8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_lG0bcxz8, m);
  cMsg_qyxYgZ1m_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_cC2cUnqg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_AdmRDBZC_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_oc8vJOaD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ewa52bHF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_j4I5AoYy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Z4vpRb8t_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uDO5liSr, 2, m, &cDelay_uDO5liSr_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_p3elmTle_sendMessage);
}

void Heavy_SoundScraper::cMsg_ewa52bHF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_j4I5AoYy, 0, m, &hTable_j4I5AoYy_sendMessage);
}

void Heavy_SoundScraper::cBinop_ITKNgk3d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_oc8vJOaD_sendMessage);
}

void Heavy_SoundScraper::cMsg_qyxYgZ1m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_j4I5AoYy, 0, m, &hTable_j4I5AoYy_sendMessage);
}

void Heavy_SoundScraper::cCast_p3elmTle_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_uDO5liSr, 0, m, &cDelay_uDO5liSr_sendMessage);
}

void Heavy_SoundScraper::cMsg_Z4vpRb8t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_lG0bcxz8, 2, m, &cDelay_lG0bcxz8_sendMessage);
}

void Heavy_SoundScraper::cMsg_AdmRDBZC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_m9Hu7Ufg, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_qjsp8uUK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DhUBz3Yx, HV_BINOP_SUBTRACT, 0, m, &cBinop_DhUBz3Yx_sendMessage);
}

void Heavy_SoundScraper::cMsg_eHnUVbtd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4BBEt4d2_sendMessage);
}

void Heavy_SoundScraper::cSystem_4BBEt4d2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_x7WvqIDX_sendMessage);
}

void Heavy_SoundScraper::cVar_4JzXAX0n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kNtpsguZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_cfEeG9ju_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cfEeG9ju, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iUh80htx, 0, m, &cDelay_iUh80htx_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_6kNivzLP, 0, m, &sTabread_6kNivzLP_sendMessage);
}

void Heavy_SoundScraper::cDelay_iUh80htx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_iUh80htx, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_6kNivzLP, 0, m, &sTabread_6kNivzLP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iUh80htx, 0, m, &cDelay_iUh80htx_sendMessage);
}

void Heavy_SoundScraper::sTabread_6kNivzLP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_mvMtr3Lt, HV_BINOP_SUBTRACT, 0, m, &cBinop_mvMtr3Lt_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_XXtSH7Ue_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0o8UXXFn, HV_BINOP_MAX, 0, m, &cBinop_0o8UXXFn_sendMessage);
}

void Heavy_SoundScraper::cBinop_x7WvqIDX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XXtSH7Ue, HV_BINOP_MULTIPLY, 0, m, &cBinop_XXtSH7Ue_sendMessage);
}

void Heavy_SoundScraper::cBinop_DhUBz3Yx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uGgcsHQ6_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_6kNivzLP, 0, m, &sTabread_6kNivzLP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Uqy5ZGzN_sendMessage);
}

void Heavy_SoundScraper::cSystem_nO86WIqk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mvMtr3Lt, HV_BINOP_SUBTRACT, 1, m, &cBinop_mvMtr3Lt_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iUh80htx, 2, m, &cDelay_iUh80htx_sendMessage);
}

void Heavy_SoundScraper::cMsg_kNtpsguZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nO86WIqk_sendMessage);
}

void Heavy_SoundScraper::cMsg_uGgcsHQ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_cfEeG9ju, 0, m, &cDelay_cfEeG9ju_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iUh80htx, 0, m, &cDelay_iUh80htx_sendMessage);
}

void Heavy_SoundScraper::cMsg_42uo092h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_0o8UXXFn, HV_BINOP_MAX, 1, m, &cBinop_0o8UXXFn_sendMessage);
}

void Heavy_SoundScraper::cBinop_0o8UXXFn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DhUBz3Yx, HV_BINOP_SUBTRACT, 1, m, &cBinop_DhUBz3Yx_sendMessage);
}

void Heavy_SoundScraper::cCast_Uqy5ZGzN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_cfEeG9ju, 0, m, &cDelay_cfEeG9ju_sendMessage);
}

void Heavy_SoundScraper::cBinop_gF7GCLgm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_cfEeG9ju, 2, m, &cDelay_cfEeG9ju_sendMessage);
}

void Heavy_SoundScraper::cBinop_mvMtr3Lt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_gF7GCLgm_sendMessage);
}

void Heavy_SoundScraper::cCast_dmeVfmkJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4JzXAX0n, 0, m, &cVar_4JzXAX0n_sendMessage);
  cMsg_eHnUVbtd_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_qjsp8uUK, 0, m, &cTabhead_qjsp8uUK_sendMessage);
}

void Heavy_SoundScraper::cMsg_5WdfHL2l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uUjYk07r_sendMessage);
}

void Heavy_SoundScraper::cSystem_uUjYk07r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_f50oLspn_sendMessage);
}

void Heavy_SoundScraper::cDelay_fZvVKWUA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fZvVKWUA, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gMEspcE3, 0, m, &cDelay_gMEspcE3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fZvVKWUA, 0, m, &cDelay_fZvVKWUA_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Ne0UkebX, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_gMEspcE3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gMEspcE3, m);
  cMsg_zoYDKnbO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_VIZkx9Ul_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_5kmMmBTy_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_QPXhcFEq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XJeQQ8xE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_gYNAhlyb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tdYfu9C2_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fZvVKWUA, 2, m, &cDelay_fZvVKWUA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iJxY2G1g_sendMessage);
}

void Heavy_SoundScraper::cMsg_XJeQQ8xE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_gYNAhlyb, 0, m, &hTable_gYNAhlyb_sendMessage);
}

void Heavy_SoundScraper::cBinop_f50oLspn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_QPXhcFEq_sendMessage);
}

void Heavy_SoundScraper::cMsg_zoYDKnbO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_gYNAhlyb, 0, m, &hTable_gYNAhlyb_sendMessage);
}

void Heavy_SoundScraper::cCast_iJxY2G1g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_fZvVKWUA, 0, m, &cDelay_fZvVKWUA_sendMessage);
}

void Heavy_SoundScraper::cMsg_tdYfu9C2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_gMEspcE3, 2, m, &cDelay_gMEspcE3_sendMessage);
}

void Heavy_SoundScraper::cMsg_5kmMmBTy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Ne0UkebX, 1, m, NULL);
}

void Heavy_SoundScraper::cVar_eWJNR6xq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aOQ9OlCb, 0, m, &cVar_aOQ9OlCb_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_k8fKOk59, 0, m, &cVar_k8fKOk59_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_8s99bkvX, 0, m, &cVar_8s99bkvX_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ddMXOMJQ, 0, m, &cVar_ddMXOMJQ_sendMessage);
}

void Heavy_SoundScraper::cVar_3X3wCO5K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_MwTTfTik_sendMessage);
}

void Heavy_SoundScraper::cPack_7Wdneohs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_5MJun8Bl, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_k8fKOk59_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6JiqAYoa, HV_BINOP_MULTIPLY, 0, m, &cBinop_6JiqAYoa_sendMessage);
}

void Heavy_SoundScraper::cMsg_or62QWCn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_98zvWJBW_sendMessage);
}

void Heavy_SoundScraper::cSystem_98zvWJBW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bZAThrG1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_6JiqAYoa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_YjfT339i_sendMessage);
}

void Heavy_SoundScraper::cBinop_5yeyUrKA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6JiqAYoa, HV_BINOP_MULTIPLY, 1, m, &cBinop_6JiqAYoa_sendMessage);
}

void Heavy_SoundScraper::cMsg_bZAThrG1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_5yeyUrKA_sendMessage);
}

void Heavy_SoundScraper::cBinop_YjfT339i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_EtCYayDq_sendMessage);
}

void Heavy_SoundScraper::cBinop_EtCYayDq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_T2Q9At7n_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_1b2ZvpmZ, m);
}

void Heavy_SoundScraper::cBinop_T2Q9At7n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xUkq45e0, m);
}

void Heavy_SoundScraper::cVar_8s99bkvX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_43VADeMk, HV_BINOP_MULTIPLY, 0, m, &cBinop_43VADeMk_sendMessage);
}

void Heavy_SoundScraper::cMsg_jkW7uzYD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8pdKzrn9_sendMessage);
}

void Heavy_SoundScraper::cSystem_8pdKzrn9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IoAkCwXA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_43VADeMk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_j2kfqoeN_sendMessage);
}

void Heavy_SoundScraper::cBinop_VlSr6Lsr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_43VADeMk, HV_BINOP_MULTIPLY, 1, m, &cBinop_43VADeMk_sendMessage);
}

void Heavy_SoundScraper::cMsg_IoAkCwXA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_VlSr6Lsr_sendMessage);
}

void Heavy_SoundScraper::cBinop_j2kfqoeN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_mVVi1484_sendMessage);
}

void Heavy_SoundScraper::cBinop_mVVi1484_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_DmTkCtQ7_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Cnyv8C4m, m);
}

void Heavy_SoundScraper::cBinop_DmTkCtQ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_PrO89gA7, m);
}

void Heavy_SoundScraper::cVar_ddMXOMJQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_H78cGDRS, HV_BINOP_MULTIPLY, 0, m, &cBinop_H78cGDRS_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZBdEYGTa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_t1zWyk7z_sendMessage);
}

void Heavy_SoundScraper::cSystem_t1zWyk7z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_deLpY2yo_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_H78cGDRS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_KhV0NiN4_sendMessage);
}

void Heavy_SoundScraper::cBinop_h7M3lK12_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_H78cGDRS, HV_BINOP_MULTIPLY, 1, m, &cBinop_H78cGDRS_sendMessage);
}

void Heavy_SoundScraper::cMsg_deLpY2yo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_h7M3lK12_sendMessage);
}

void Heavy_SoundScraper::cBinop_KhV0NiN4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_fmZCplkG_sendMessage);
}

void Heavy_SoundScraper::cBinop_fmZCplkG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ikY9vWem_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_0bVHqkST, m);
}

void Heavy_SoundScraper::cBinop_ikY9vWem_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_uGnRSPLb, m);
}

void Heavy_SoundScraper::cBinop_qTTD7dOm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_f2lH268q, 0, m, &cPack_f2lH268q_sendMessage);
}

void Heavy_SoundScraper::cMsg_EtJut6fV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_eWJNR6xq, 0, m, &cVar_eWJNR6xq_sendMessage);
}

void Heavy_SoundScraper::cBinop_MwTTfTik_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_7Wdneohs, 0, m, &cPack_7Wdneohs_sendMessage);
}

void Heavy_SoundScraper::cBinop_lOr2JnlF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_KRvfoe96, 0, m, &cPack_KRvfoe96_sendMessage);
}

void Heavy_SoundScraper::cVar_qRMdyRZj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_twYerL70_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dGwyNLi3_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Kl719D7F_sendMessage);
}

void Heavy_SoundScraper::cIf_X2FUDHaP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_0vHO2IkC_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_jAEobqz6_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_UvqSZVS3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_CRXcbWfo, HV_BINOP_POW, 0, m, &cBinop_CRXcbWfo_sendMessage);
}

void Heavy_SoundScraper::cBinop_CRXcbWfo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_W4ch99U0, 0, m, &cPack_W4ch99U0_sendMessage);
}

void Heavy_SoundScraper::cBinop_L9EqdA51_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_WKUiVURs_sendMessage);
}

void Heavy_SoundScraper::cCast_Kl719D7F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_X2FUDHaP, 0, m, &cIf_X2FUDHaP_sendMessage);
}

void Heavy_SoundScraper::cCast_dGwyNLi3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_0nzRMysi_sendMessage);
}

void Heavy_SoundScraper::cBinop_0nzRMysi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_X2FUDHaP, 1, m, &cIf_X2FUDHaP_sendMessage);
}

void Heavy_SoundScraper::cBinop_jAEobqz6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_L9EqdA51_sendMessage);
}

void Heavy_SoundScraper::cMsg_0vHO2IkC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_W4ch99U0, 0, m, &cPack_W4ch99U0_sendMessage);
}

void Heavy_SoundScraper::cBinop_WKUiVURs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CRXcbWfo, HV_BINOP_POW, 1, m, &cBinop_CRXcbWfo_sendMessage);
  cMsg_UvqSZVS3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_W4ch99U0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_x4oiRlkn, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_JLO0nmGt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ZqMHgiQU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_twYerL70_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_DISiPP3N_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_DISiPP3N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Gbqetf5p_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_ZqMHgiQU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_HkBRXcJh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cIf_2MpAXMQB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_9EStkq7N_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_06WnYLiN_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_06WnYLiN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_jyrL2jE4_sendMessage);
}

void Heavy_SoundScraper::cCast_vvOQGGsc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_2MpAXMQB, 0, m, &cIf_2MpAXMQB_sendMessage);
}

void Heavy_SoundScraper::cCast_AwuHdE3L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_LwddXjFy_sendMessage);
}

void Heavy_SoundScraper::cMsg_9EStkq7N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_YSTFFx4C, 0, m, &cVar_YSTFFx4C_sendMessage);
}

void Heavy_SoundScraper::cBinop_jyrL2jE4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_COYvdSCN_sendMessage);
}

void Heavy_SoundScraper::cBinop_COYvdSCN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_AHv7tc1z_sendMessage);
}

void Heavy_SoundScraper::cBinop_AHv7tc1z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YSTFFx4C, 0, m, &cVar_YSTFFx4C_sendMessage);
}

void Heavy_SoundScraper::cBinop_LwddXjFy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_2MpAXMQB, 1, m, &cIf_2MpAXMQB_sendMessage);
}

void Heavy_SoundScraper::cBinop_VBaGeWT3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AwuHdE3L_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vvOQGGsc_sendMessage);
}

void Heavy_SoundScraper::cBinop_wMhQgIle_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_VBaGeWT3_sendMessage);
}

void Heavy_SoundScraper::cIf_R7uVv4DZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_E0GTWqVp_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_I166t4Cw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_I166t4Cw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_3BbgTKDy_sendMessage);
}

void Heavy_SoundScraper::cCast_ZtRSoBIu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_R7uVv4DZ, 0, m, &cIf_R7uVv4DZ_sendMessage);
}

void Heavy_SoundScraper::cCast_sEipLibm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_IYkINa8h_sendMessage);
}

void Heavy_SoundScraper::cMsg_E0GTWqVp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_twYerL70_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dGwyNLi3_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Kl719D7F_sendMessage);
}

void Heavy_SoundScraper::cBinop_3BbgTKDy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_Fxr0Vhqi_sendMessage);
}

void Heavy_SoundScraper::cBinop_Fxr0Vhqi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Lq3Vuav3_sendMessage);
}

void Heavy_SoundScraper::cBinop_Lq3Vuav3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_twYerL70_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dGwyNLi3_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Kl719D7F_sendMessage);
}

void Heavy_SoundScraper::cBinop_IYkINa8h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_R7uVv4DZ, 1, m, &cIf_R7uVv4DZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_tggTLocD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_sEipLibm_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZtRSoBIu_sendMessage);
}

void Heavy_SoundScraper::cBinop_UzC1bS57_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_tggTLocD_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_ZlZ1PDfV_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_w3IBs7wY_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_w3IBs7wY_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_9oKLVgOb, 1, m, &cDelay_9oKLVgOb_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_79zqB9So_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_9oKLVgOb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9oKLVgOb, m);
  cMsg_A0Fd6ySR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_w3IBs7wY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_9oKLVgOb, 0, m, &cDelay_9oKLVgOb_sendMessage);
}

void Heavy_SoundScraper::cCast_79zqB9So_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_9oKLVgOb, 0, m, &cDelay_9oKLVgOb_sendMessage);
}

void Heavy_SoundScraper::cVar_lBDIfJsn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_X4Sq55vo, 0, m, &cPack_X4Sq55vo_sendMessage);
}

void Heavy_SoundScraper::cVar_IS0NihHG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_7577oxSY_sendMessage);
}

void Heavy_SoundScraper::cVar_I9W43AtX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_xFuXI1fD_sendMessage);
}

void Heavy_SoundScraper::cPack_WF2ByexI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_SIcupqdZ, 0, m, NULL);
}

void Heavy_SoundScraper::cUnop_qdJhbw5O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_6nu5RrTs_sendMessage);
}

void Heavy_SoundScraper::cBinop_AFs7o3YP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_qdJhbw5O_sendMessage);
}

void Heavy_SoundScraper::cPack_Q3zcj6Kc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_pmOERWvQ, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_IPdiXj6Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_sYjNRiAb_sendMessage);
}

void Heavy_SoundScraper::cMsg_NnwVeGLU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wtX4Yd5K_sendMessage);
}

void Heavy_SoundScraper::cSystem_wtX4Yd5K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ZKq7Y4sk_sendMessage);
}

void Heavy_SoundScraper::cDelay_vp3NG1PI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vp3NG1PI, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bMj3hH0j, 0, m, &cDelay_bMj3hH0j_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vp3NG1PI, 0, m, &cDelay_vp3NG1PI_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_jOiTAEpf, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_bMj3hH0j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bMj3hH0j, m);
  cMsg_k05QOcfB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_bQuDsaP8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_yYMOX8Mi_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_ahdeaejL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yZ8U9gii_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_PLZ3kGJM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Lpwq2M5s_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vp3NG1PI, 2, m, &cDelay_vp3NG1PI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_l7nkQ2o8_sendMessage);
}

void Heavy_SoundScraper::cMsg_yZ8U9gii_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_PLZ3kGJM, 0, m, &hTable_PLZ3kGJM_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZKq7Y4sk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_ahdeaejL_sendMessage);
}

void Heavy_SoundScraper::cMsg_k05QOcfB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_PLZ3kGJM, 0, m, &hTable_PLZ3kGJM_sendMessage);
}

void Heavy_SoundScraper::cCast_l7nkQ2o8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_vp3NG1PI, 0, m, &cDelay_vp3NG1PI_sendMessage);
}

void Heavy_SoundScraper::cMsg_Lpwq2M5s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_bMj3hH0j, 2, m, &cDelay_bMj3hH0j_sendMessage);
}

void Heavy_SoundScraper::cMsg_yYMOX8Mi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_jOiTAEpf, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_mdZB2Lx2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7lGWh9Kn_sendMessage);
}

void Heavy_SoundScraper::cSystem_7lGWh9Kn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Je5yQf6J_sendMessage);
}

void Heavy_SoundScraper::cVar_mgXjKRnt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_t5OBXmyT_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_XhxcpHo3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_OyFY6DVt_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_N52pBKt9, m);
}

void Heavy_SoundScraper::cBinop_Je5yQf6J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_mKbyEBUK, m);
}

void Heavy_SoundScraper::cMsg_t5OBXmyT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XhxcpHo3_sendMessage);
}

void Heavy_SoundScraper::cBinop_OyFY6DVt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_hJwc8Iw8, m);
}

void Heavy_SoundScraper::cMsg_Z3xrUzGJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1rG2rmqg_sendMessage);
}

void Heavy_SoundScraper::cSystem_1rG2rmqg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_oTk7ZB8t_sendMessage);
}

void Heavy_SoundScraper::cVar_YbrdOzca_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jQ7Sl4I8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_4YIbcW5Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_YXLNNYjp_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_BzDZDqFR, m);
}

void Heavy_SoundScraper::cBinop_oTk7ZB8t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_lyyP7vsQ, m);
}

void Heavy_SoundScraper::cMsg_jQ7Sl4I8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4YIbcW5Q_sendMessage);
}

void Heavy_SoundScraper::cBinop_YXLNNYjp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_7p2f9ozt, m);
}

void Heavy_SoundScraper::cBinop_Fx1UQGzP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mkAI0SRX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_KV5bXIQK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BZAoZsDn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kKgiemVO_sendMessage);
}

void Heavy_SoundScraper::cCast_kKgiemVO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Fx1UQGzP, HV_BINOP_DIVIDE, 0, m, &cBinop_Fx1UQGzP_sendMessage);
}

void Heavy_SoundScraper::cCast_BZAoZsDn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Fx1UQGzP, HV_BINOP_DIVIDE, 1, m, &cBinop_Fx1UQGzP_sendMessage);
}

void Heavy_SoundScraper::cBinop_6nu5RrTs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_2ygk5MD0_sendMessage);
}

void Heavy_SoundScraper::cBinop_7577oxSY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_AFs7o3YP_sendMessage);
}

void Heavy_SoundScraper::cBinop_2ygk5MD0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Fx1UQGzP, HV_BINOP_DIVIDE, 0, m, &cBinop_Fx1UQGzP_sendMessage);
}

void Heavy_SoundScraper::cBinop_sYjNRiAb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Q3zcj6Kc, 0, m, &cPack_Q3zcj6Kc_sendMessage);
}

void Heavy_SoundScraper::cBinop_xFuXI1fD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_KV5bXIQK_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_WF2ByexI, 0, m, &cPack_WF2ByexI_sendMessage);
}

void Heavy_SoundScraper::cMsg_dvcTCq8g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_I9W43AtX, 0, m, &cVar_I9W43AtX_sendMessage);
}

void Heavy_SoundScraper::cMsg_QPIxSrQT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_IPdiXj6Z, 0, m, &cVar_IPdiXj6Z_sendMessage);
}

void Heavy_SoundScraper::cMsg_mkAI0SRX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_vkHwMN4p, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_R26pb7J2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ftxYhjb7, HV_BINOP_MULTIPLY, 0, m, &cBinop_ftxYhjb7_sendMessage);
}

void Heavy_SoundScraper::cMsg_nkFzeAid_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_moYn3bL2_sendMessage);
}

void Heavy_SoundScraper::cSystem_moYn3bL2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xnAfdSXA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_ftxYhjb7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_pFYqejqf_sendMessage);
}

void Heavy_SoundScraper::cBinop_TTkiUk0E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ftxYhjb7, HV_BINOP_MULTIPLY, 1, m, &cBinop_ftxYhjb7_sendMessage);
}

void Heavy_SoundScraper::cMsg_xnAfdSXA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_TTkiUk0E_sendMessage);
}

void Heavy_SoundScraper::cBinop_pFYqejqf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_GSVQS0dr_sendMessage);
}

void Heavy_SoundScraper::cBinop_GSVQS0dr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_HjhZ3L2O_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_jUTLBWjZ, m);
}

void Heavy_SoundScraper::cBinop_HjhZ3L2O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_1IoVrxsD, m);
}

void Heavy_SoundScraper::cVar_cIB6hrj3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IEezAQMa, HV_BINOP_MULTIPLY, 0, m, &cBinop_IEezAQMa_sendMessage);
}

void Heavy_SoundScraper::cMsg_i5IE9f9v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qyUXErSy_sendMessage);
}

void Heavy_SoundScraper::cSystem_qyUXErSy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dIw0OvbE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_IEezAQMa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_NI4yCnfL_sendMessage);
}

void Heavy_SoundScraper::cBinop_3azSQDap_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IEezAQMa, HV_BINOP_MULTIPLY, 1, m, &cBinop_IEezAQMa_sendMessage);
}

void Heavy_SoundScraper::cMsg_dIw0OvbE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_3azSQDap_sendMessage);
}

void Heavy_SoundScraper::cBinop_NI4yCnfL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_5rbDR1fM_sendMessage);
}

void Heavy_SoundScraper::cBinop_5rbDR1fM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ZCrnKJbu_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_BDCf0aA3, m);
}

void Heavy_SoundScraper::cBinop_ZCrnKJbu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_zzn1Axzn, m);
}

void Heavy_SoundScraper::cVar_VQ083g8a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hcYJAAW5, HV_BINOP_MULTIPLY, 0, m, &cBinop_hcYJAAW5_sendMessage);
}

void Heavy_SoundScraper::cMsg_s2okftnM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_H68e1gSJ_sendMessage);
}

void Heavy_SoundScraper::cSystem_H68e1gSJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iUnCXmCW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_hcYJAAW5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_ww87e9f7_sendMessage);
}

void Heavy_SoundScraper::cBinop_TeyXLqBo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hcYJAAW5, HV_BINOP_MULTIPLY, 1, m, &cBinop_hcYJAAW5_sendMessage);
}

void Heavy_SoundScraper::cMsg_iUnCXmCW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_TeyXLqBo_sendMessage);
}

void Heavy_SoundScraper::cBinop_ww87e9f7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_KZNjwKPd_sendMessage);
}

void Heavy_SoundScraper::cBinop_KZNjwKPd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_pDy9Ct0r_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_j7Zs79ku, m);
}

void Heavy_SoundScraper::cBinop_pDy9Ct0r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_4O86NrNp, m);
}

void Heavy_SoundScraper::cMsg_1UgLHtPF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UBBFWP4o_sendMessage);
}

void Heavy_SoundScraper::cSystem_UBBFWP4o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VPsNYN0a_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_sW8nmyIk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_2G9ZrBgu_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_QQ8N9LZX, 0, m, &cIf_QQ8N9LZX_sendMessage);
}

void Heavy_SoundScraper::cIf_QQ8N9LZX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_754cMVLx_sendMessage(_c, 0, m);
      cMsg_rIiDmLGG_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_ZO78HDPr_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_JzCqtF8A_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_F2X9ObRM, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_2G9ZrBgu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_QQ8N9LZX, 1, m, &cIf_QQ8N9LZX_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZO78HDPr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_gd8TYG4g_sendMessage);
}

void Heavy_SoundScraper::cBinop_gd8TYG4g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LEK9L4BP, m);
}

void Heavy_SoundScraper::cBinop_JzCqtF8A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TpYPNh7q_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_TpYPNh7q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_ZlrduCT1_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZlrduCT1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_q16xIv2A_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_q16xIv2A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_xSgDa41E_sendMessage);
}

void Heavy_SoundScraper::cBinop_xSgDa41E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_FGL19iji, m);
}

void Heavy_SoundScraper::cBinop_YXQeh0up_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_BD6qXRGY, m);
}

void Heavy_SoundScraper::cMsg_VPsNYN0a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_YXQeh0up_sendMessage);
}

void Heavy_SoundScraper::cMsg_754cMVLx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_JzCqtF8A_sendMessage);
}

void Heavy_SoundScraper::cMsg_rIiDmLGG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_LEK9L4BP, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_F2X9ObRM, m);
}

void Heavy_SoundScraper::cBinop_CCrwaA0I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cIB6hrj3, 0, m, &cVar_cIB6hrj3_sendMessage);
}

void Heavy_SoundScraper::cBinop_DVEmXJSE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_R26pb7J2, 0, m, &cVar_R26pb7J2_sendMessage);
}

void Heavy_SoundScraper::cBinop_zkw6q3oV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VQ083g8a, 0, m, &cVar_VQ083g8a_sendMessage);
}

void Heavy_SoundScraper::cCast_xuRfup7J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_CCrwaA0I_sendMessage);
}

void Heavy_SoundScraper::cCast_N2OIsNvw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_DVEmXJSE_sendMessage);
}

void Heavy_SoundScraper::cCast_jFirp7Fz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_zkw6q3oV_sendMessage);
}

void Heavy_SoundScraper::cCast_VBR7Y837_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_mxCDPLDB, m);
}

void Heavy_SoundScraper::cTabhead_SXkhJBY3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wM7SplKq, HV_BINOP_SUBTRACT, 0, m, &cBinop_wM7SplKq_sendMessage);
}

void Heavy_SoundScraper::cMsg_UHBv5r8J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8nOqJFKG_sendMessage);
}

void Heavy_SoundScraper::cSystem_8nOqJFKG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_5szbNlC0_sendMessage);
}

void Heavy_SoundScraper::cVar_HH6Xr0A7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DxPg6Q7Y_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_p9HXfHML_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_p9HXfHML, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_n0FqqA96, 0, m, &cDelay_n0FqqA96_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_wGHbTAlV, 0, m, &sTabread_wGHbTAlV_sendMessage);
}

void Heavy_SoundScraper::cDelay_n0FqqA96_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_n0FqqA96, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_wGHbTAlV, 0, m, &sTabread_wGHbTAlV_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_n0FqqA96, 0, m, &cDelay_n0FqqA96_sendMessage);
}

void Heavy_SoundScraper::sTabread_wGHbTAlV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_nStqW3SN, HV_BINOP_SUBTRACT, 0, m, &cBinop_nStqW3SN_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_KozkQX76_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KLyJcFf5, HV_BINOP_MAX, 0, m, &cBinop_KLyJcFf5_sendMessage);
}

void Heavy_SoundScraper::cBinop_5szbNlC0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KozkQX76, HV_BINOP_MULTIPLY, 0, m, &cBinop_KozkQX76_sendMessage);
}

void Heavy_SoundScraper::cBinop_wM7SplKq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_F0wFWNc8_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_wGHbTAlV, 0, m, &sTabread_wGHbTAlV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cXjakIXx_sendMessage);
}

void Heavy_SoundScraper::cSystem_qE284uUv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nStqW3SN, HV_BINOP_SUBTRACT, 1, m, &cBinop_nStqW3SN_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_n0FqqA96, 2, m, &cDelay_n0FqqA96_sendMessage);
}

void Heavy_SoundScraper::cMsg_DxPg6Q7Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qE284uUv_sendMessage);
}

void Heavy_SoundScraper::cMsg_F0wFWNc8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_p9HXfHML, 0, m, &cDelay_p9HXfHML_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_n0FqqA96, 0, m, &cDelay_n0FqqA96_sendMessage);
}

void Heavy_SoundScraper::cMsg_ucLAfFwI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_KLyJcFf5, HV_BINOP_MAX, 1, m, &cBinop_KLyJcFf5_sendMessage);
}

void Heavy_SoundScraper::cBinop_KLyJcFf5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wM7SplKq, HV_BINOP_SUBTRACT, 1, m, &cBinop_wM7SplKq_sendMessage);
}

void Heavy_SoundScraper::cCast_cXjakIXx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_p9HXfHML, 0, m, &cDelay_p9HXfHML_sendMessage);
}

void Heavy_SoundScraper::cBinop_5h4AkesP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_p9HXfHML, 2, m, &cDelay_p9HXfHML_sendMessage);
}

void Heavy_SoundScraper::cBinop_nStqW3SN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_5h4AkesP_sendMessage);
}

void Heavy_SoundScraper::cCast_F055G7Eo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HH6Xr0A7, 0, m, &cVar_HH6Xr0A7_sendMessage);
  cMsg_UHBv5r8J_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_SXkhJBY3, 0, m, &cTabhead_SXkhJBY3_sendMessage);
}

void Heavy_SoundScraper::cTabhead_NR3xuXrv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_klLddm2f, HV_BINOP_SUBTRACT, 0, m, &cBinop_klLddm2f_sendMessage);
}

void Heavy_SoundScraper::cMsg_RN7Rga2n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Dx8UZzMp_sendMessage);
}

void Heavy_SoundScraper::cSystem_Dx8UZzMp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_wr7tR9Na_sendMessage);
}

void Heavy_SoundScraper::cVar_O4t0wLSg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3y2HHEz3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_qY9SCDIu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_qY9SCDIu, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6g9D0Mw0, 0, m, &cDelay_6g9D0Mw0_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_eLOXIhvE, 0, m, &sTabread_eLOXIhvE_sendMessage);
}

void Heavy_SoundScraper::cDelay_6g9D0Mw0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6g9D0Mw0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_eLOXIhvE, 0, m, &sTabread_eLOXIhvE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6g9D0Mw0, 0, m, &cDelay_6g9D0Mw0_sendMessage);
}

void Heavy_SoundScraper::sTabread_eLOXIhvE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_vO1PCmBr, HV_BINOP_SUBTRACT, 0, m, &cBinop_vO1PCmBr_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_3jsqqjEy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_38hAhIl0, HV_BINOP_MAX, 0, m, &cBinop_38hAhIl0_sendMessage);
}

void Heavy_SoundScraper::cBinop_wr7tR9Na_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3jsqqjEy, HV_BINOP_MULTIPLY, 0, m, &cBinop_3jsqqjEy_sendMessage);
}

void Heavy_SoundScraper::cBinop_klLddm2f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_i8egjcP3_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_eLOXIhvE, 0, m, &sTabread_eLOXIhvE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3SmIQgE1_sendMessage);
}

void Heavy_SoundScraper::cSystem_W5cifNke_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vO1PCmBr, HV_BINOP_SUBTRACT, 1, m, &cBinop_vO1PCmBr_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6g9D0Mw0, 2, m, &cDelay_6g9D0Mw0_sendMessage);
}

void Heavy_SoundScraper::cMsg_3y2HHEz3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_W5cifNke_sendMessage);
}

void Heavy_SoundScraper::cMsg_i8egjcP3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_qY9SCDIu, 0, m, &cDelay_qY9SCDIu_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6g9D0Mw0, 0, m, &cDelay_6g9D0Mw0_sendMessage);
}

void Heavy_SoundScraper::cMsg_PI8zT0Ru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_38hAhIl0, HV_BINOP_MAX, 1, m, &cBinop_38hAhIl0_sendMessage);
}

void Heavy_SoundScraper::cBinop_38hAhIl0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_klLddm2f, HV_BINOP_SUBTRACT, 1, m, &cBinop_klLddm2f_sendMessage);
}

void Heavy_SoundScraper::cCast_3SmIQgE1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_qY9SCDIu, 0, m, &cDelay_qY9SCDIu_sendMessage);
}

void Heavy_SoundScraper::cBinop_aRvln4Ls_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_qY9SCDIu, 2, m, &cDelay_qY9SCDIu_sendMessage);
}

void Heavy_SoundScraper::cBinop_vO1PCmBr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_aRvln4Ls_sendMessage);
}

void Heavy_SoundScraper::cCast_YsBYhOnQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_O4t0wLSg, 0, m, &cVar_O4t0wLSg_sendMessage);
  cMsg_RN7Rga2n_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_NR3xuXrv, 0, m, &cTabhead_NR3xuXrv_sendMessage);
}

void Heavy_SoundScraper::cTabhead_kXwel3YH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RZFxQmbT, HV_BINOP_SUBTRACT, 0, m, &cBinop_RZFxQmbT_sendMessage);
}

void Heavy_SoundScraper::cMsg_sYnTgkcZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5UOm39sp_sendMessage);
}

void Heavy_SoundScraper::cSystem_5UOm39sp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_FNtA3amV_sendMessage);
}

void Heavy_SoundScraper::cVar_cSpwGDa1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ALY1bONi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_R2apNQpI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_R2apNQpI, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Iu4uaL7v, 0, m, &cDelay_Iu4uaL7v_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_9w7FF8pZ, 0, m, &sTabread_9w7FF8pZ_sendMessage);
}

void Heavy_SoundScraper::cDelay_Iu4uaL7v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Iu4uaL7v, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_9w7FF8pZ, 0, m, &sTabread_9w7FF8pZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Iu4uaL7v, 0, m, &cDelay_Iu4uaL7v_sendMessage);
}

void Heavy_SoundScraper::sTabread_9w7FF8pZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_z1gUj4on, HV_BINOP_SUBTRACT, 0, m, &cBinop_z1gUj4on_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_BKiqzatt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_48Q1yh1f, HV_BINOP_MAX, 0, m, &cBinop_48Q1yh1f_sendMessage);
}

void Heavy_SoundScraper::cBinop_FNtA3amV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BKiqzatt, HV_BINOP_MULTIPLY, 0, m, &cBinop_BKiqzatt_sendMessage);
}

void Heavy_SoundScraper::cBinop_RZFxQmbT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_472ws7i5_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_9w7FF8pZ, 0, m, &sTabread_9w7FF8pZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AASnw7G2_sendMessage);
}

void Heavy_SoundScraper::cSystem_7Cxi56bw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_z1gUj4on, HV_BINOP_SUBTRACT, 1, m, &cBinop_z1gUj4on_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Iu4uaL7v, 2, m, &cDelay_Iu4uaL7v_sendMessage);
}

void Heavy_SoundScraper::cMsg_ALY1bONi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7Cxi56bw_sendMessage);
}

void Heavy_SoundScraper::cMsg_472ws7i5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_R2apNQpI, 0, m, &cDelay_R2apNQpI_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Iu4uaL7v, 0, m, &cDelay_Iu4uaL7v_sendMessage);
}

void Heavy_SoundScraper::cMsg_nO4mL71H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_48Q1yh1f, HV_BINOP_MAX, 1, m, &cBinop_48Q1yh1f_sendMessage);
}

void Heavy_SoundScraper::cBinop_48Q1yh1f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RZFxQmbT, HV_BINOP_SUBTRACT, 1, m, &cBinop_RZFxQmbT_sendMessage);
}

void Heavy_SoundScraper::cCast_AASnw7G2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_R2apNQpI, 0, m, &cDelay_R2apNQpI_sendMessage);
}

void Heavy_SoundScraper::cBinop_n5bz21lO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_R2apNQpI, 2, m, &cDelay_R2apNQpI_sendMessage);
}

void Heavy_SoundScraper::cBinop_z1gUj4on_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_n5bz21lO_sendMessage);
}

void Heavy_SoundScraper::cCast_Ig1C2Hqn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cSpwGDa1, 0, m, &cVar_cSpwGDa1_sendMessage);
  cMsg_sYnTgkcZ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_kXwel3YH, 0, m, &cTabhead_kXwel3YH_sendMessage);
}

void Heavy_SoundScraper::cTabhead_sFyzHI0n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aOCPX9pV, HV_BINOP_SUBTRACT, 0, m, &cBinop_aOCPX9pV_sendMessage);
}

void Heavy_SoundScraper::cMsg_tB7TBX5j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fsHqL26b_sendMessage);
}

void Heavy_SoundScraper::cSystem_fsHqL26b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_YC8Zx4n5_sendMessage);
}

void Heavy_SoundScraper::cVar_eFC51iED_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wVPsT0ZU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_rz4UI3iD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rz4UI3iD, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DJnipM8B, 0, m, &cDelay_DJnipM8B_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_EcvHPTpu, 0, m, &sTabread_EcvHPTpu_sendMessage);
}

void Heavy_SoundScraper::cDelay_DJnipM8B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DJnipM8B, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_EcvHPTpu, 0, m, &sTabread_EcvHPTpu_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DJnipM8B, 0, m, &cDelay_DJnipM8B_sendMessage);
}

void Heavy_SoundScraper::sTabread_EcvHPTpu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_WIGW6qNv, HV_BINOP_SUBTRACT, 0, m, &cBinop_WIGW6qNv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_nx4mLjMF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YBOwAvTT, HV_BINOP_MAX, 0, m, &cBinop_YBOwAvTT_sendMessage);
}

void Heavy_SoundScraper::cBinop_YC8Zx4n5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nx4mLjMF, HV_BINOP_MULTIPLY, 0, m, &cBinop_nx4mLjMF_sendMessage);
}

void Heavy_SoundScraper::cBinop_aOCPX9pV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Jd3tk0Wk_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_EcvHPTpu, 0, m, &sTabread_EcvHPTpu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rAA7rEM3_sendMessage);
}

void Heavy_SoundScraper::cSystem_tn3Gl9vW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WIGW6qNv, HV_BINOP_SUBTRACT, 1, m, &cBinop_WIGW6qNv_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DJnipM8B, 2, m, &cDelay_DJnipM8B_sendMessage);
}

void Heavy_SoundScraper::cMsg_wVPsT0ZU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tn3Gl9vW_sendMessage);
}

void Heavy_SoundScraper::cMsg_Jd3tk0Wk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_rz4UI3iD, 0, m, &cDelay_rz4UI3iD_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DJnipM8B, 0, m, &cDelay_DJnipM8B_sendMessage);
}

void Heavy_SoundScraper::cMsg_Ml0r1OMs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_YBOwAvTT, HV_BINOP_MAX, 1, m, &cBinop_YBOwAvTT_sendMessage);
}

void Heavy_SoundScraper::cBinop_YBOwAvTT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aOCPX9pV, HV_BINOP_SUBTRACT, 1, m, &cBinop_aOCPX9pV_sendMessage);
}

void Heavy_SoundScraper::cCast_rAA7rEM3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_rz4UI3iD, 0, m, &cDelay_rz4UI3iD_sendMessage);
}

void Heavy_SoundScraper::cBinop_fgsmHel8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_rz4UI3iD, 2, m, &cDelay_rz4UI3iD_sendMessage);
}

void Heavy_SoundScraper::cBinop_WIGW6qNv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_fgsmHel8_sendMessage);
}

void Heavy_SoundScraper::cCast_aCYaV3bx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eFC51iED, 0, m, &cVar_eFC51iED_sendMessage);
  cMsg_tB7TBX5j_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_sFyzHI0n, 0, m, &cTabhead_sFyzHI0n_sendMessage);
}

void Heavy_SoundScraper::cMsg_nIaEFQvi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fTqpAJaZ_sendMessage);
}

void Heavy_SoundScraper::cSystem_fTqpAJaZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_qqrfv5Cg_sendMessage);
}

void Heavy_SoundScraper::cDelay_xARKvSlF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_xARKvSlF, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VNMs9plb, 0, m, &cDelay_VNMs9plb_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xARKvSlF, 0, m, &cDelay_xARKvSlF_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_jwRTTVc7, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_VNMs9plb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VNMs9plb, m);
  cMsg_DtpoP0yX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_OqyiFhNs_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_DyJ4jPw4_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_OmQr6cQR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WScBrFIt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_81Fwh5Ik_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_otW3toE8_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xARKvSlF, 2, m, &cDelay_xARKvSlF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_p4Ds7GN3_sendMessage);
}

void Heavy_SoundScraper::cMsg_WScBrFIt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_81Fwh5Ik, 0, m, &hTable_81Fwh5Ik_sendMessage);
}

void Heavy_SoundScraper::cBinop_qqrfv5Cg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_OmQr6cQR_sendMessage);
}

void Heavy_SoundScraper::cMsg_DtpoP0yX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_81Fwh5Ik, 0, m, &hTable_81Fwh5Ik_sendMessage);
}

void Heavy_SoundScraper::cCast_p4Ds7GN3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_xARKvSlF, 0, m, &cDelay_xARKvSlF_sendMessage);
}

void Heavy_SoundScraper::cMsg_otW3toE8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_VNMs9plb, 2, m, &cDelay_VNMs9plb_sendMessage);
}

void Heavy_SoundScraper::cMsg_DyJ4jPw4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_jwRTTVc7, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_DOkYqMH0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_98smjzzW_sendMessage);
}

void Heavy_SoundScraper::cSystem_98smjzzW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_FU11C6Us_sendMessage);
}

void Heavy_SoundScraper::cDelay_YUaEaRZf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_YUaEaRZf, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Uq36K0BH, 0, m, &cDelay_Uq36K0BH_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_YUaEaRZf, 0, m, &cDelay_YUaEaRZf_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_V6dDYAF7, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_Uq36K0BH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Uq36K0BH, m);
  cMsg_lDgqdEHk_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_RsEz3SFQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_L0Ggq5gu_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_eGM7aM3Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_q26xhWUA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_ftHhTyVL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fx4ptEDW_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_YUaEaRZf, 2, m, &cDelay_YUaEaRZf_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jqaBoEiL_sendMessage);
}

void Heavy_SoundScraper::cMsg_q26xhWUA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_ftHhTyVL, 0, m, &hTable_ftHhTyVL_sendMessage);
}

void Heavy_SoundScraper::cBinop_FU11C6Us_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_eGM7aM3Q_sendMessage);
}

void Heavy_SoundScraper::cMsg_lDgqdEHk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_ftHhTyVL, 0, m, &hTable_ftHhTyVL_sendMessage);
}

void Heavy_SoundScraper::cCast_jqaBoEiL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YUaEaRZf, 0, m, &cDelay_YUaEaRZf_sendMessage);
}

void Heavy_SoundScraper::cMsg_fx4ptEDW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Uq36K0BH, 2, m, &cDelay_Uq36K0BH_sendMessage);
}

void Heavy_SoundScraper::cMsg_L0Ggq5gu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_V6dDYAF7, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_Vuv8J8ds_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_MBFXQYtH_sendMessage);
}

void Heavy_SoundScraper::cSystem_MBFXQYtH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_VWNVcNRx_sendMessage);
}

void Heavy_SoundScraper::cDelay_jeZG5Rqb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_jeZG5Rqb, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cSI0Z9Af, 0, m, &cDelay_cSI0Z9Af_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jeZG5Rqb, 0, m, &cDelay_jeZG5Rqb_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_RHL8PbPg, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_cSI0Z9Af_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cSI0Z9Af, m);
  cMsg_QRLEgAc5_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_kvu6fiyq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_FUp33hXz_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_gfpEy9hg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_m1Rd6BZJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_7EeCKKBz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8tdxbpCH_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jeZG5Rqb, 2, m, &cDelay_jeZG5Rqb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vYkbqHYa_sendMessage);
}

void Heavy_SoundScraper::cMsg_m1Rd6BZJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_7EeCKKBz, 0, m, &hTable_7EeCKKBz_sendMessage);
}

void Heavy_SoundScraper::cBinop_VWNVcNRx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_gfpEy9hg_sendMessage);
}

void Heavy_SoundScraper::cMsg_QRLEgAc5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_7EeCKKBz, 0, m, &hTable_7EeCKKBz_sendMessage);
}

void Heavy_SoundScraper::cCast_vYkbqHYa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_jeZG5Rqb, 0, m, &cDelay_jeZG5Rqb_sendMessage);
}

void Heavy_SoundScraper::cMsg_8tdxbpCH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_cSI0Z9Af, 2, m, &cDelay_cSI0Z9Af_sendMessage);
}

void Heavy_SoundScraper::cMsg_FUp33hXz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_RHL8PbPg, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_zq5pSJqe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_s2AX7MBt_sendMessage);
}

void Heavy_SoundScraper::cSystem_s2AX7MBt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_XqfPO0O8_sendMessage);
}

void Heavy_SoundScraper::cDelay_GZ7Jc06O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_GZ7Jc06O, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tnsYRRR1, 0, m, &cDelay_tnsYRRR1_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GZ7Jc06O, 0, m, &cDelay_GZ7Jc06O_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Udjy761d, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_tnsYRRR1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tnsYRRR1, m);
  cMsg_X5DebTHs_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_O5q2snlc_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_7P81V7Ut_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_EvOuyc0i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dUjmnAsx_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_FLvNlyM6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LNY8fEfI_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GZ7Jc06O, 2, m, &cDelay_GZ7Jc06O_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lTBNdZmD_sendMessage);
}

void Heavy_SoundScraper::cMsg_dUjmnAsx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_FLvNlyM6, 0, m, &hTable_FLvNlyM6_sendMessage);
}

void Heavy_SoundScraper::cBinop_XqfPO0O8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_EvOuyc0i_sendMessage);
}

void Heavy_SoundScraper::cMsg_X5DebTHs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_FLvNlyM6, 0, m, &hTable_FLvNlyM6_sendMessage);
}

void Heavy_SoundScraper::cCast_lTBNdZmD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_GZ7Jc06O, 0, m, &cDelay_GZ7Jc06O_sendMessage);
}

void Heavy_SoundScraper::cMsg_LNY8fEfI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_tnsYRRR1, 2, m, &cDelay_tnsYRRR1_sendMessage);
}

void Heavy_SoundScraper::cMsg_7P81V7Ut_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Udjy761d, 1, m, NULL);
}

void Heavy_SoundScraper::cIf_om10kpwV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_IPOrjva9_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_Xj51Jiic_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_9jKq0UkN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_CpMu0ke7, HV_BINOP_POW, 0, m, &cBinop_CpMu0ke7_sendMessage);
}

void Heavy_SoundScraper::cBinop_CpMu0ke7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_1QtV2BrC_sendMessage);
}

void Heavy_SoundScraper::cBinop_NauLwwVo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_RwkkDsaM_sendMessage);
}

void Heavy_SoundScraper::cCast_o9l3bxx3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_om10kpwV, 0, m, &cIf_om10kpwV_sendMessage);
}

void Heavy_SoundScraper::cCast_hGVWYULU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Ql8855Xm_sendMessage);
}

void Heavy_SoundScraper::cBinop_Ql8855Xm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_om10kpwV, 1, m, &cIf_om10kpwV_sendMessage);
}

void Heavy_SoundScraper::cBinop_Xj51Jiic_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_NauLwwVo_sendMessage);
}

void Heavy_SoundScraper::cMsg_IPOrjva9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_1QtV2BrC_sendMessage);
}

void Heavy_SoundScraper::cBinop_RwkkDsaM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CpMu0ke7, HV_BINOP_POW, 1, m, &cBinop_CpMu0ke7_sendMessage);
  cMsg_9jKq0UkN_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_EQfGpw4o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_6FwER0B6, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_ImCmEvxS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_tgclqmTa, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_ZkPUv15v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ePpQLq1b_sendMessage);
}

void Heavy_SoundScraper::cBinop_ePpQLq1b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_2MrVWzsv_sendMessage);
}

void Heavy_SoundScraper::cVar_vgwh6SfN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1QFGDfEM, HV_BINOP_MULTIPLY, 0, m, &cBinop_1QFGDfEM_sendMessage);
}

void Heavy_SoundScraper::cMsg_Gasc5WTC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_x3Xuaqvl_sendMessage);
}

void Heavy_SoundScraper::cSystem_x3Xuaqvl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mTFH6GMC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_1QFGDfEM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_DGZVwbOc_sendMessage);
}

void Heavy_SoundScraper::cBinop_9CXLcraN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1QFGDfEM, HV_BINOP_MULTIPLY, 1, m, &cBinop_1QFGDfEM_sendMessage);
}

void Heavy_SoundScraper::cMsg_mTFH6GMC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_9CXLcraN_sendMessage);
}

void Heavy_SoundScraper::cBinop_DGZVwbOc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_jeaZrpuw_sendMessage);
}

void Heavy_SoundScraper::cBinop_jeaZrpuw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_5SAqLjK9_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_M5iGRofl, m);
}

void Heavy_SoundScraper::cBinop_5SAqLjK9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_nrO3sP4M, m);
}

void Heavy_SoundScraper::cVar_OLpM7ZL1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hGVWYULU_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_o9l3bxx3_sendMessage);
}

void Heavy_SoundScraper::cVar_8Usvu6Ky_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_ZkPUv15v_sendMessage);
}

void Heavy_SoundScraper::cVar_UhJUy96q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_awAJwtHi_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_aQIll2GA, 0, m, &cIf_aQIll2GA_sendMessage);
}

void Heavy_SoundScraper::cVar_BzxHXOCF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_8W5SDryv_sendMessage);
}

void Heavy_SoundScraper::cIf_aQIll2GA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_krMrFgwD_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_KHbvhN8P, 0, m, &cVar_KHbvhN8P_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_awAJwtHi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_aQIll2GA, 1, m, &cIf_aQIll2GA_sendMessage);
}

void Heavy_SoundScraper::cBinop_8W5SDryv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_iWf7o3HX_sendMessage);
}

void Heavy_SoundScraper::cBinop_iWf7o3HX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9vm71zek, 0, m, &cVar_9vm71zek_sendMessage);
}

void Heavy_SoundScraper::cTabhead_Vf7MCSSc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5Y8mHuUQ, HV_BINOP_SUBTRACT, 0, m, &cBinop_5Y8mHuUQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_6ALqfEvH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_MaIMGOen_sendMessage);
}

void Heavy_SoundScraper::cSystem_MaIMGOen_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_PpyVjEQp_sendMessage);
}

void Heavy_SoundScraper::cVar_SVNkmjVv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4PX2FH0X_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_iEJnU2pS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_iEJnU2pS, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dvw6Hfc8, 0, m, &cDelay_dvw6Hfc8_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_jYEApCTm, 0, m, &sTabread_jYEApCTm_sendMessage);
}

void Heavy_SoundScraper::cDelay_dvw6Hfc8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_dvw6Hfc8, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_jYEApCTm, 0, m, &sTabread_jYEApCTm_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dvw6Hfc8, 0, m, &cDelay_dvw6Hfc8_sendMessage);
}

void Heavy_SoundScraper::sTabread_jYEApCTm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_DBSJi3Nc, HV_BINOP_SUBTRACT, 0, m, &cBinop_DBSJi3Nc_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_pLLbKFIv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_j3I7amDx, HV_BINOP_MAX, 0, m, &cBinop_j3I7amDx_sendMessage);
}

void Heavy_SoundScraper::cBinop_PpyVjEQp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pLLbKFIv, HV_BINOP_MULTIPLY, 0, m, &cBinop_pLLbKFIv_sendMessage);
}

void Heavy_SoundScraper::cBinop_5Y8mHuUQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kk4RMZuL_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_jYEApCTm, 0, m, &sTabread_jYEApCTm_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZMC3UdEj_sendMessage);
}

void Heavy_SoundScraper::cSystem_5fGAXKjC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DBSJi3Nc, HV_BINOP_SUBTRACT, 1, m, &cBinop_DBSJi3Nc_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dvw6Hfc8, 2, m, &cDelay_dvw6Hfc8_sendMessage);
}

void Heavy_SoundScraper::cMsg_4PX2FH0X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5fGAXKjC_sendMessage);
}

void Heavy_SoundScraper::cMsg_kk4RMZuL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_iEJnU2pS, 0, m, &cDelay_iEJnU2pS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dvw6Hfc8, 0, m, &cDelay_dvw6Hfc8_sendMessage);
}

void Heavy_SoundScraper::cMsg_Al7tWu1i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_j3I7amDx, HV_BINOP_MAX, 1, m, &cBinop_j3I7amDx_sendMessage);
}

void Heavy_SoundScraper::cBinop_j3I7amDx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5Y8mHuUQ, HV_BINOP_SUBTRACT, 1, m, &cBinop_5Y8mHuUQ_sendMessage);
}

void Heavy_SoundScraper::cCast_ZMC3UdEj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_iEJnU2pS, 0, m, &cDelay_iEJnU2pS_sendMessage);
}

void Heavy_SoundScraper::cBinop_HlQRvIeI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_iEJnU2pS, 2, m, &cDelay_iEJnU2pS_sendMessage);
}

void Heavy_SoundScraper::cBinop_DBSJi3Nc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_HlQRvIeI_sendMessage);
}

void Heavy_SoundScraper::cCast_xnlM3jWz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SVNkmjVv, 0, m, &cVar_SVNkmjVv_sendMessage);
  cMsg_6ALqfEvH_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Vf7MCSSc, 0, m, &cTabhead_Vf7MCSSc_sendMessage);
}

void Heavy_SoundScraper::cMsg_cNEks9Pv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_d4KKp395_sendMessage);
}

void Heavy_SoundScraper::cSystem_d4KKp395_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_cQxHdcv7_sendMessage);
}

void Heavy_SoundScraper::cDelay_hP5mCYnE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hP5mCYnE, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BZlzFxyU, 0, m, &cDelay_BZlzFxyU_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hP5mCYnE, 0, m, &cDelay_hP5mCYnE_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_GMUK5TX5, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_BZlzFxyU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BZlzFxyU, m);
  cMsg_0GujTkqi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_0iHDybNC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_JRo7ehtr_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_38RHAU7u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NkiqflW6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_LfXGvwTh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5sb4SGoX_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hP5mCYnE, 2, m, &cDelay_hP5mCYnE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FHmU6Dkx_sendMessage);
}

void Heavy_SoundScraper::cMsg_NkiqflW6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_LfXGvwTh, 0, m, &hTable_LfXGvwTh_sendMessage);
}

void Heavy_SoundScraper::cBinop_cQxHdcv7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_38RHAU7u_sendMessage);
}

void Heavy_SoundScraper::cMsg_0GujTkqi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_LfXGvwTh, 0, m, &hTable_LfXGvwTh_sendMessage);
}

void Heavy_SoundScraper::cCast_FHmU6Dkx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_hP5mCYnE, 0, m, &cDelay_hP5mCYnE_sendMessage);
}

void Heavy_SoundScraper::cMsg_5sb4SGoX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_BZlzFxyU, 2, m, &cDelay_BZlzFxyU_sendMessage);
}

void Heavy_SoundScraper::cMsg_JRo7ehtr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_GMUK5TX5, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_MRJoq79y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CtiR58tA, HV_BINOP_SUBTRACT, 0, m, &cBinop_CtiR58tA_sendMessage);
}

void Heavy_SoundScraper::cMsg_jljnO4TN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vEO2aTrq_sendMessage);
}

void Heavy_SoundScraper::cSystem_vEO2aTrq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_vix5Dr5G_sendMessage);
}

void Heavy_SoundScraper::cVar_STZtxlja_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MlfVLm58_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_L2sbCw35_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_L2sbCw35, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jwMjzahx, 0, m, &cDelay_jwMjzahx_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_LRFqKfxm, 0, m, &sTabread_LRFqKfxm_sendMessage);
}

void Heavy_SoundScraper::cDelay_jwMjzahx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_jwMjzahx, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_LRFqKfxm, 0, m, &sTabread_LRFqKfxm_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jwMjzahx, 0, m, &cDelay_jwMjzahx_sendMessage);
}

void Heavy_SoundScraper::sTabread_LRFqKfxm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_YfzK1l5T, HV_BINOP_SUBTRACT, 0, m, &cBinop_YfzK1l5T_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_IdzVNjV5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l7lcJLjW, HV_BINOP_MAX, 0, m, &cBinop_l7lcJLjW_sendMessage);
}

void Heavy_SoundScraper::cBinop_vix5Dr5G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IdzVNjV5, HV_BINOP_MULTIPLY, 0, m, &cBinop_IdzVNjV5_sendMessage);
}

void Heavy_SoundScraper::cBinop_CtiR58tA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_phA2Ehse_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_LRFqKfxm, 0, m, &sTabread_LRFqKfxm_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_s0lz64eQ_sendMessage);
}

void Heavy_SoundScraper::cSystem_MT7XgLs2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YfzK1l5T, HV_BINOP_SUBTRACT, 1, m, &cBinop_YfzK1l5T_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jwMjzahx, 2, m, &cDelay_jwMjzahx_sendMessage);
}

void Heavy_SoundScraper::cMsg_MlfVLm58_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_MT7XgLs2_sendMessage);
}

void Heavy_SoundScraper::cMsg_phA2Ehse_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_L2sbCw35, 0, m, &cDelay_L2sbCw35_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jwMjzahx, 0, m, &cDelay_jwMjzahx_sendMessage);
}

void Heavy_SoundScraper::cMsg_pcLF8SWH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_l7lcJLjW, HV_BINOP_MAX, 1, m, &cBinop_l7lcJLjW_sendMessage);
}

void Heavy_SoundScraper::cBinop_l7lcJLjW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CtiR58tA, HV_BINOP_SUBTRACT, 1, m, &cBinop_CtiR58tA_sendMessage);
}

void Heavy_SoundScraper::cCast_s0lz64eQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_L2sbCw35, 0, m, &cDelay_L2sbCw35_sendMessage);
}

void Heavy_SoundScraper::cBinop_W0YDJz9f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_L2sbCw35, 2, m, &cDelay_L2sbCw35_sendMessage);
}

void Heavy_SoundScraper::cBinop_YfzK1l5T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_W0YDJz9f_sendMessage);
}

void Heavy_SoundScraper::cCast_k6mUceAc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_STZtxlja, 0, m, &cVar_STZtxlja_sendMessage);
  cMsg_jljnO4TN_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_MRJoq79y, 0, m, &cTabhead_MRJoq79y_sendMessage);
}

void Heavy_SoundScraper::cMsg_YJnc2z71_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GaVRxWJL_sendMessage);
}

void Heavy_SoundScraper::cSystem_GaVRxWJL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_wrPrhjr4_sendMessage);
}

void Heavy_SoundScraper::cDelay_KCEa8AB3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KCEa8AB3, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_X2BgZ4wY, 0, m, &cDelay_X2BgZ4wY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KCEa8AB3, 0, m, &cDelay_KCEa8AB3_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_juL3lEB7, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_X2BgZ4wY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_X2BgZ4wY, m);
  cMsg_Ln5YqmIK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_VMVI2tc8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_H1dloWL2_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_yNYrLzVi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QL93Q5rn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_f71PlYKv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fV17E4W1_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KCEa8AB3, 2, m, &cDelay_KCEa8AB3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_orXOmjb7_sendMessage);
}

void Heavy_SoundScraper::cMsg_QL93Q5rn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_f71PlYKv, 0, m, &hTable_f71PlYKv_sendMessage);
}

void Heavy_SoundScraper::cBinop_wrPrhjr4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_yNYrLzVi_sendMessage);
}

void Heavy_SoundScraper::cMsg_Ln5YqmIK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_f71PlYKv, 0, m, &hTable_f71PlYKv_sendMessage);
}

void Heavy_SoundScraper::cCast_orXOmjb7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KCEa8AB3, 0, m, &cDelay_KCEa8AB3_sendMessage);
}

void Heavy_SoundScraper::cMsg_fV17E4W1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_X2BgZ4wY, 2, m, &cDelay_X2BgZ4wY_sendMessage);
}

void Heavy_SoundScraper::cMsg_H1dloWL2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_juL3lEB7, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_J4Ps2RAU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TzQXKiTq, HV_BINOP_SUBTRACT, 0, m, &cBinop_TzQXKiTq_sendMessage);
}

void Heavy_SoundScraper::cMsg_E10OcyiY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_30SD0SqJ_sendMessage);
}

void Heavy_SoundScraper::cSystem_30SD0SqJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_DD5Pdzqh_sendMessage);
}

void Heavy_SoundScraper::cVar_17rsssFG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kiASXR5f_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_LDF8I6ac_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LDF8I6ac, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WXaoYQev, 0, m, &cDelay_WXaoYQev_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_CbgqKfNV, 0, m, &sTabread_CbgqKfNV_sendMessage);
}

void Heavy_SoundScraper::cDelay_WXaoYQev_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WXaoYQev, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_CbgqKfNV, 0, m, &sTabread_CbgqKfNV_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WXaoYQev, 0, m, &cDelay_WXaoYQev_sendMessage);
}

void Heavy_SoundScraper::sTabread_CbgqKfNV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_jcgk2Gj0, HV_BINOP_SUBTRACT, 0, m, &cBinop_jcgk2Gj0_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_fbzy73OI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_X3XP7OJU, HV_BINOP_MAX, 0, m, &cBinop_X3XP7OJU_sendMessage);
}

void Heavy_SoundScraper::cBinop_DD5Pdzqh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fbzy73OI, HV_BINOP_MULTIPLY, 0, m, &cBinop_fbzy73OI_sendMessage);
}

void Heavy_SoundScraper::cBinop_TzQXKiTq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_i6Nq9gFj_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_CbgqKfNV, 0, m, &sTabread_CbgqKfNV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3nn2cdko_sendMessage);
}

void Heavy_SoundScraper::cSystem_KwrlddE9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jcgk2Gj0, HV_BINOP_SUBTRACT, 1, m, &cBinop_jcgk2Gj0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WXaoYQev, 2, m, &cDelay_WXaoYQev_sendMessage);
}

void Heavy_SoundScraper::cMsg_kiASXR5f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KwrlddE9_sendMessage);
}

void Heavy_SoundScraper::cMsg_i6Nq9gFj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_LDF8I6ac, 0, m, &cDelay_LDF8I6ac_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WXaoYQev, 0, m, &cDelay_WXaoYQev_sendMessage);
}

void Heavy_SoundScraper::cMsg_Y3Fc2xAS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_X3XP7OJU, HV_BINOP_MAX, 1, m, &cBinop_X3XP7OJU_sendMessage);
}

void Heavy_SoundScraper::cBinop_X3XP7OJU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TzQXKiTq, HV_BINOP_SUBTRACT, 1, m, &cBinop_TzQXKiTq_sendMessage);
}

void Heavy_SoundScraper::cCast_3nn2cdko_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_LDF8I6ac, 0, m, &cDelay_LDF8I6ac_sendMessage);
}

void Heavy_SoundScraper::cBinop_pSZrxwPv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_LDF8I6ac, 2, m, &cDelay_LDF8I6ac_sendMessage);
}

void Heavy_SoundScraper::cBinop_jcgk2Gj0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_pSZrxwPv_sendMessage);
}

void Heavy_SoundScraper::cCast_dV0bf06e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_17rsssFG, 0, m, &cVar_17rsssFG_sendMessage);
  cMsg_E10OcyiY_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_J4Ps2RAU, 0, m, &cTabhead_J4Ps2RAU_sendMessage);
}

void Heavy_SoundScraper::cMsg_QtGPxqRH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nW3NBTb2_sendMessage);
}

void Heavy_SoundScraper::cSystem_nW3NBTb2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_KnvbOxwG_sendMessage);
}

void Heavy_SoundScraper::cDelay_hioO4Njp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hioO4Njp, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TSA6z9ge, 0, m, &cDelay_TSA6z9ge_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hioO4Njp, 0, m, &cDelay_hioO4Njp_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_f1CCwUY8, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_TSA6z9ge_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TSA6z9ge, m);
  cMsg_VwAv4HT9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_ishW1vy6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_K9WY7jqL_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_OucWkkRq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DQnb92N2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_1NYZsr90_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3lSvTJug_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hioO4Njp, 2, m, &cDelay_hioO4Njp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Ie3nkqHN_sendMessage);
}

void Heavy_SoundScraper::cMsg_DQnb92N2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_1NYZsr90, 0, m, &hTable_1NYZsr90_sendMessage);
}

void Heavy_SoundScraper::cBinop_KnvbOxwG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_OucWkkRq_sendMessage);
}

void Heavy_SoundScraper::cMsg_VwAv4HT9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_1NYZsr90, 0, m, &hTable_1NYZsr90_sendMessage);
}

void Heavy_SoundScraper::cCast_Ie3nkqHN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_hioO4Njp, 0, m, &cDelay_hioO4Njp_sendMessage);
}

void Heavy_SoundScraper::cMsg_3lSvTJug_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_TSA6z9ge, 2, m, &cDelay_TSA6z9ge_sendMessage);
}

void Heavy_SoundScraper::cMsg_K9WY7jqL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_f1CCwUY8, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_B8Gbhmkw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OtGlPzf5, HV_BINOP_SUBTRACT, 0, m, &cBinop_OtGlPzf5_sendMessage);
}

void Heavy_SoundScraper::cMsg_LLyJafxZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_bRM0qZcq_sendMessage);
}

void Heavy_SoundScraper::cSystem_bRM0qZcq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_p6ErMqJc_sendMessage);
}

void Heavy_SoundScraper::cVar_SuZ5xyqC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dHhwapXb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_jYFK4hgT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_jYFK4hgT, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xd1tcJKw, 0, m, &cDelay_xd1tcJKw_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_p95TiwPm, 0, m, &sTabread_p95TiwPm_sendMessage);
}

void Heavy_SoundScraper::cDelay_xd1tcJKw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_xd1tcJKw, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_p95TiwPm, 0, m, &sTabread_p95TiwPm_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xd1tcJKw, 0, m, &cDelay_xd1tcJKw_sendMessage);
}

void Heavy_SoundScraper::sTabread_p95TiwPm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_JSijZNMG, HV_BINOP_SUBTRACT, 0, m, &cBinop_JSijZNMG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_FkpmvZwX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3vUjt3B8, HV_BINOP_MAX, 0, m, &cBinop_3vUjt3B8_sendMessage);
}

void Heavy_SoundScraper::cBinop_p6ErMqJc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FkpmvZwX, HV_BINOP_MULTIPLY, 0, m, &cBinop_FkpmvZwX_sendMessage);
}

void Heavy_SoundScraper::cBinop_OtGlPzf5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JKT58DoJ_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_p95TiwPm, 0, m, &sTabread_p95TiwPm_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8wkmQBJJ_sendMessage);
}

void Heavy_SoundScraper::cSystem_eelBKUHv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JSijZNMG, HV_BINOP_SUBTRACT, 1, m, &cBinop_JSijZNMG_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xd1tcJKw, 2, m, &cDelay_xd1tcJKw_sendMessage);
}

void Heavy_SoundScraper::cMsg_dHhwapXb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eelBKUHv_sendMessage);
}

void Heavy_SoundScraper::cMsg_JKT58DoJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_jYFK4hgT, 0, m, &cDelay_jYFK4hgT_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xd1tcJKw, 0, m, &cDelay_xd1tcJKw_sendMessage);
}

void Heavy_SoundScraper::cMsg_WaYqjlDH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_3vUjt3B8, HV_BINOP_MAX, 1, m, &cBinop_3vUjt3B8_sendMessage);
}

void Heavy_SoundScraper::cBinop_3vUjt3B8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OtGlPzf5, HV_BINOP_SUBTRACT, 1, m, &cBinop_OtGlPzf5_sendMessage);
}

void Heavy_SoundScraper::cCast_8wkmQBJJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_jYFK4hgT, 0, m, &cDelay_jYFK4hgT_sendMessage);
}

void Heavy_SoundScraper::cBinop_4wzjrjYy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_jYFK4hgT, 2, m, &cDelay_jYFK4hgT_sendMessage);
}

void Heavy_SoundScraper::cBinop_JSijZNMG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_4wzjrjYy_sendMessage);
}

void Heavy_SoundScraper::cCast_tp2OnVDT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SuZ5xyqC, 0, m, &cVar_SuZ5xyqC_sendMessage);
  cMsg_LLyJafxZ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_B8Gbhmkw, 0, m, &cTabhead_B8Gbhmkw_sendMessage);
}

void Heavy_SoundScraper::cMsg_kIrKx4AQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_d5ThpLsL_sendMessage);
}

void Heavy_SoundScraper::cSystem_d5ThpLsL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_4riWY0vc_sendMessage);
}

void Heavy_SoundScraper::cDelay_u8gAWuRy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_u8gAWuRy, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Kux4l09R, 0, m, &cDelay_Kux4l09R_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_u8gAWuRy, 0, m, &cDelay_u8gAWuRy_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Nhj3k8sX, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_Kux4l09R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Kux4l09R, m);
  cMsg_Ymh7PdjM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_cb1bMQd1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_hhX6cDqp_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_2pVCvvkt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_C2Xah7dq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_uhLL7yho_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8aKVqnPf_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_u8gAWuRy, 2, m, &cDelay_u8gAWuRy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tenWzK6o_sendMessage);
}

void Heavy_SoundScraper::cMsg_C2Xah7dq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_uhLL7yho, 0, m, &hTable_uhLL7yho_sendMessage);
}

void Heavy_SoundScraper::cBinop_4riWY0vc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_2pVCvvkt_sendMessage);
}

void Heavy_SoundScraper::cMsg_Ymh7PdjM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_uhLL7yho, 0, m, &hTable_uhLL7yho_sendMessage);
}

void Heavy_SoundScraper::cCast_tenWzK6o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_u8gAWuRy, 0, m, &cDelay_u8gAWuRy_sendMessage);
}

void Heavy_SoundScraper::cMsg_8aKVqnPf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Kux4l09R, 2, m, &cDelay_Kux4l09R_sendMessage);
}

void Heavy_SoundScraper::cMsg_hhX6cDqp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Nhj3k8sX, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_Cwtwr1LJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gJ8Wgjjn, HV_BINOP_SUBTRACT, 0, m, &cBinop_gJ8Wgjjn_sendMessage);
}

void Heavy_SoundScraper::cMsg_QthOvPXW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zHoW9yB9_sendMessage);
}

void Heavy_SoundScraper::cSystem_zHoW9yB9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_EJPf0sA5_sendMessage);
}

void Heavy_SoundScraper::cVar_Mxp21e5Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cwZpHJHO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_IBHMHVwV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IBHMHVwV, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Rcfv4Cby, 0, m, &cDelay_Rcfv4Cby_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_16qKnAjk, 0, m, &sTabread_16qKnAjk_sendMessage);
}

void Heavy_SoundScraper::cDelay_Rcfv4Cby_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Rcfv4Cby, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_16qKnAjk, 0, m, &sTabread_16qKnAjk_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Rcfv4Cby, 0, m, &cDelay_Rcfv4Cby_sendMessage);
}

void Heavy_SoundScraper::sTabread_16qKnAjk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_3xSGxozA, HV_BINOP_SUBTRACT, 0, m, &cBinop_3xSGxozA_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_YW0eomxC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NcuXryEt, HV_BINOP_MAX, 0, m, &cBinop_NcuXryEt_sendMessage);
}

void Heavy_SoundScraper::cBinop_EJPf0sA5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YW0eomxC, HV_BINOP_MULTIPLY, 0, m, &cBinop_YW0eomxC_sendMessage);
}

void Heavy_SoundScraper::cBinop_gJ8Wgjjn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gteXjVbs_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_16qKnAjk, 0, m, &sTabread_16qKnAjk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SwsILAtv_sendMessage);
}

void Heavy_SoundScraper::cSystem_samhEDPV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3xSGxozA, HV_BINOP_SUBTRACT, 1, m, &cBinop_3xSGxozA_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Rcfv4Cby, 2, m, &cDelay_Rcfv4Cby_sendMessage);
}

void Heavy_SoundScraper::cMsg_cwZpHJHO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_samhEDPV_sendMessage);
}

void Heavy_SoundScraper::cMsg_gteXjVbs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_IBHMHVwV, 0, m, &cDelay_IBHMHVwV_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Rcfv4Cby, 0, m, &cDelay_Rcfv4Cby_sendMessage);
}

void Heavy_SoundScraper::cMsg_0SibBmsn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_NcuXryEt, HV_BINOP_MAX, 1, m, &cBinop_NcuXryEt_sendMessage);
}

void Heavy_SoundScraper::cBinop_NcuXryEt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gJ8Wgjjn, HV_BINOP_SUBTRACT, 1, m, &cBinop_gJ8Wgjjn_sendMessage);
}

void Heavy_SoundScraper::cCast_SwsILAtv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_IBHMHVwV, 0, m, &cDelay_IBHMHVwV_sendMessage);
}

void Heavy_SoundScraper::cBinop_Qk7MxtnH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_IBHMHVwV, 2, m, &cDelay_IBHMHVwV_sendMessage);
}

void Heavy_SoundScraper::cBinop_3xSGxozA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Qk7MxtnH_sendMessage);
}

void Heavy_SoundScraper::cCast_VRga2wuh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Mxp21e5Z, 0, m, &cVar_Mxp21e5Z_sendMessage);
  cMsg_QthOvPXW_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Cwtwr1LJ, 0, m, &cTabhead_Cwtwr1LJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_CDXGkAJJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_k5j3Pqr3_sendMessage);
}

void Heavy_SoundScraper::cSystem_k5j3Pqr3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_5UzWqkUw_sendMessage);
}

void Heavy_SoundScraper::cDelay_LaK8lVzo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LaK8lVzo, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BRzlxP80, 0, m, &cDelay_BRzlxP80_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LaK8lVzo, 0, m, &cDelay_LaK8lVzo_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_qHgNkAEQ, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_BRzlxP80_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BRzlxP80, m);
  cMsg_bNAaQzkN_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_zqiX9Aqo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_EQ9UX2fJ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_2EsYvQpk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Vw5oCcvD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_uyDJyNjy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JX8xuKt8_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LaK8lVzo, 2, m, &cDelay_LaK8lVzo_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_r6xTHudw_sendMessage);
}

void Heavy_SoundScraper::cMsg_Vw5oCcvD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_uyDJyNjy, 0, m, &hTable_uyDJyNjy_sendMessage);
}

void Heavy_SoundScraper::cBinop_5UzWqkUw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_2EsYvQpk_sendMessage);
}

void Heavy_SoundScraper::cMsg_bNAaQzkN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_uyDJyNjy, 0, m, &hTable_uyDJyNjy_sendMessage);
}

void Heavy_SoundScraper::cCast_r6xTHudw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_LaK8lVzo, 0, m, &cDelay_LaK8lVzo_sendMessage);
}

void Heavy_SoundScraper::cMsg_JX8xuKt8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_BRzlxP80, 2, m, &cDelay_BRzlxP80_sendMessage);
}

void Heavy_SoundScraper::cMsg_EQ9UX2fJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_qHgNkAEQ, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_itxTn9nv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YY9lnK0O, HV_BINOP_SUBTRACT, 0, m, &cBinop_YY9lnK0O_sendMessage);
}

void Heavy_SoundScraper::cMsg_U9iCZFW9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QuATh4nl_sendMessage);
}

void Heavy_SoundScraper::cSystem_QuATh4nl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_I6AvMWve_sendMessage);
}

void Heavy_SoundScraper::cVar_hA6Ojs56_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oXnmkxmT_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_pOwgt7z3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pOwgt7z3, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mtyBGVRP, 0, m, &cDelay_mtyBGVRP_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_GOaCxfn8, 0, m, &sTabread_GOaCxfn8_sendMessage);
}

void Heavy_SoundScraper::cDelay_mtyBGVRP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mtyBGVRP, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_GOaCxfn8, 0, m, &sTabread_GOaCxfn8_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mtyBGVRP, 0, m, &cDelay_mtyBGVRP_sendMessage);
}

void Heavy_SoundScraper::sTabread_GOaCxfn8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Eh29dqbB, HV_BINOP_SUBTRACT, 0, m, &cBinop_Eh29dqbB_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_Nsqsfo5U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TI4XdwT1, HV_BINOP_MAX, 0, m, &cBinop_TI4XdwT1_sendMessage);
}

void Heavy_SoundScraper::cBinop_I6AvMWve_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Nsqsfo5U, HV_BINOP_MULTIPLY, 0, m, &cBinop_Nsqsfo5U_sendMessage);
}

void Heavy_SoundScraper::cBinop_YY9lnK0O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yhcNhuME_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_GOaCxfn8, 0, m, &sTabread_GOaCxfn8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_X5OtIoLL_sendMessage);
}

void Heavy_SoundScraper::cSystem_QwVKfPqp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Eh29dqbB, HV_BINOP_SUBTRACT, 1, m, &cBinop_Eh29dqbB_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mtyBGVRP, 2, m, &cDelay_mtyBGVRP_sendMessage);
}

void Heavy_SoundScraper::cMsg_oXnmkxmT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QwVKfPqp_sendMessage);
}

void Heavy_SoundScraper::cMsg_yhcNhuME_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_pOwgt7z3, 0, m, &cDelay_pOwgt7z3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mtyBGVRP, 0, m, &cDelay_mtyBGVRP_sendMessage);
}

void Heavy_SoundScraper::cMsg_0HumCUyi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_TI4XdwT1, HV_BINOP_MAX, 1, m, &cBinop_TI4XdwT1_sendMessage);
}

void Heavy_SoundScraper::cBinop_TI4XdwT1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YY9lnK0O, HV_BINOP_SUBTRACT, 1, m, &cBinop_YY9lnK0O_sendMessage);
}

void Heavy_SoundScraper::cCast_X5OtIoLL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pOwgt7z3, 0, m, &cDelay_pOwgt7z3_sendMessage);
}

void Heavy_SoundScraper::cBinop_5SfQLilf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pOwgt7z3, 2, m, &cDelay_pOwgt7z3_sendMessage);
}

void Heavy_SoundScraper::cBinop_Eh29dqbB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_5SfQLilf_sendMessage);
}

void Heavy_SoundScraper::cCast_uTKQwIqW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hA6Ojs56, 0, m, &cVar_hA6Ojs56_sendMessage);
  cMsg_U9iCZFW9_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_itxTn9nv, 0, m, &cTabhead_itxTn9nv_sendMessage);
}

void Heavy_SoundScraper::cMsg_TcykXE5x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_M4PwciXM_sendMessage);
}

void Heavy_SoundScraper::cSystem_M4PwciXM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_sv0Ecgoz_sendMessage);
}

void Heavy_SoundScraper::cDelay_FkJv10Kg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FkJv10Kg, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pgdtaBDB, 0, m, &cDelay_pgdtaBDB_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FkJv10Kg, 0, m, &cDelay_FkJv10Kg_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_cOTmnE8q, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_pgdtaBDB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pgdtaBDB, m);
  cMsg_QU0YI2QM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_bgMpMLgd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_iaTfVOzV_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_XryXopNg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zRh65UG9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_xFxj5K73_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4ydfSR66_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FkJv10Kg, 2, m, &cDelay_FkJv10Kg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_H5nUphYy_sendMessage);
}

void Heavy_SoundScraper::cMsg_zRh65UG9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_xFxj5K73, 0, m, &hTable_xFxj5K73_sendMessage);
}

void Heavy_SoundScraper::cBinop_sv0Ecgoz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_XryXopNg_sendMessage);
}

void Heavy_SoundScraper::cMsg_QU0YI2QM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_xFxj5K73, 0, m, &hTable_xFxj5K73_sendMessage);
}

void Heavy_SoundScraper::cCast_H5nUphYy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_FkJv10Kg, 0, m, &cDelay_FkJv10Kg_sendMessage);
}

void Heavy_SoundScraper::cMsg_4ydfSR66_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_pgdtaBDB, 2, m, &cDelay_pgdtaBDB_sendMessage);
}

void Heavy_SoundScraper::cMsg_iaTfVOzV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_cOTmnE8q, 1, m, NULL);
}

void Heavy_SoundScraper::cVar_KHbvhN8P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vgwh6SfN, 0, m, &cVar_vgwh6SfN_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_tUl2MrOD, 0, m, &cVar_tUl2MrOD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_tiXmJjxq, 0, m, &cVar_tiXmJjxq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_IK0Wuvlg, 0, m, &cVar_IK0Wuvlg_sendMessage);
}

void Heavy_SoundScraper::cVar_9vm71zek_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_TofQj6Da_sendMessage);
}

void Heavy_SoundScraper::cPack_u9IBeWUl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_tOzwtFMn, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_tUl2MrOD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sOB89OZi, HV_BINOP_MULTIPLY, 0, m, &cBinop_sOB89OZi_sendMessage);
}

void Heavy_SoundScraper::cMsg_JIREBJmJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hzOk8Ocq_sendMessage);
}

void Heavy_SoundScraper::cSystem_hzOk8Ocq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WMa68n57_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_sOB89OZi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_duIeRIPP_sendMessage);
}

void Heavy_SoundScraper::cBinop_4GsaaOt8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sOB89OZi, HV_BINOP_MULTIPLY, 1, m, &cBinop_sOB89OZi_sendMessage);
}

void Heavy_SoundScraper::cMsg_WMa68n57_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_4GsaaOt8_sendMessage);
}

void Heavy_SoundScraper::cBinop_duIeRIPP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_CIbORM5a_sendMessage);
}

void Heavy_SoundScraper::cBinop_CIbORM5a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_lz9IT1eP_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_iPqSFKzE, m);
}

void Heavy_SoundScraper::cBinop_lz9IT1eP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_JL28iLCy, m);
}

void Heavy_SoundScraper::cVar_tiXmJjxq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_k2zcZFcq, HV_BINOP_MULTIPLY, 0, m, &cBinop_k2zcZFcq_sendMessage);
}

void Heavy_SoundScraper::cMsg_g8UmmVO4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mt3ORIPg_sendMessage);
}

void Heavy_SoundScraper::cSystem_mt3ORIPg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_L6rMrAZD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_k2zcZFcq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_LdYpbVKn_sendMessage);
}

void Heavy_SoundScraper::cBinop_ACQ2RcAI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_k2zcZFcq, HV_BINOP_MULTIPLY, 1, m, &cBinop_k2zcZFcq_sendMessage);
}

void Heavy_SoundScraper::cMsg_L6rMrAZD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_ACQ2RcAI_sendMessage);
}

void Heavy_SoundScraper::cBinop_LdYpbVKn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_DwfASxHi_sendMessage);
}

void Heavy_SoundScraper::cBinop_DwfASxHi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_kHplNUI1_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_wyZQYuip, m);
}

void Heavy_SoundScraper::cBinop_kHplNUI1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_PX9sAeJU, m);
}

void Heavy_SoundScraper::cVar_IK0Wuvlg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KBgrEVaE, HV_BINOP_MULTIPLY, 0, m, &cBinop_KBgrEVaE_sendMessage);
}

void Heavy_SoundScraper::cMsg_LdyhBGqm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jqx1pFtT_sendMessage);
}

void Heavy_SoundScraper::cSystem_jqx1pFtT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5YLXFfP4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_KBgrEVaE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_ZP5ZCpL0_sendMessage);
}

void Heavy_SoundScraper::cBinop_KT3L0QHB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KBgrEVaE, HV_BINOP_MULTIPLY, 1, m, &cBinop_KBgrEVaE_sendMessage);
}

void Heavy_SoundScraper::cMsg_5YLXFfP4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_KT3L0QHB_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZP5ZCpL0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_4wFIQsSC_sendMessage);
}

void Heavy_SoundScraper::cBinop_4wFIQsSC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_CVKwsa87_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_4q5MYVHv, m);
}

void Heavy_SoundScraper::cBinop_CVKwsa87_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_254jGMzq, m);
}

void Heavy_SoundScraper::cBinop_2MrVWzsv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ImCmEvxS, 0, m, &cPack_ImCmEvxS_sendMessage);
}

void Heavy_SoundScraper::cMsg_krMrFgwD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_KHbvhN8P, 0, m, &cVar_KHbvhN8P_sendMessage);
}

void Heavy_SoundScraper::cBinop_TofQj6Da_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_u9IBeWUl, 0, m, &cPack_u9IBeWUl_sendMessage);
}

void Heavy_SoundScraper::cBinop_1QtV2BrC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_EQfGpw4o, 0, m, &cPack_EQfGpw4o_sendMessage);
}

void Heavy_SoundScraper::cMsg_CPeVVXWC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_p3pVpMzc_sendMessage);
}

void Heavy_SoundScraper::cSystem_p3pVpMzc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_apfZLWGi_sendMessage);
}

void Heavy_SoundScraper::cVar_Rp1tnQDo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_u9CkVD8l_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_BQX0eBr1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_M02y52Vk_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_4L4Lh9BM, m);
}

void Heavy_SoundScraper::cBinop_apfZLWGi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_tEtfpbec, m);
}

void Heavy_SoundScraper::cMsg_u9CkVD8l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BQX0eBr1_sendMessage);
}

void Heavy_SoundScraper::cBinop_M02y52Vk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_YIKpyQZw, m);
}

void Heavy_SoundScraper::cVar_v8V26Hd2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8qBwKL4C, HV_BINOP_MULTIPLY, 0, m, &cBinop_8qBwKL4C_sendMessage);
}

void Heavy_SoundScraper::cMsg_stypFTfS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tC59rETh_sendMessage);
}

void Heavy_SoundScraper::cSystem_tC59rETh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TkEUi41Z_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_8qBwKL4C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_e1kXetu8_sendMessage);
}

void Heavy_SoundScraper::cBinop_KzmJQrQH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8qBwKL4C, HV_BINOP_MULTIPLY, 1, m, &cBinop_8qBwKL4C_sendMessage);
}

void Heavy_SoundScraper::cMsg_TkEUi41Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_KzmJQrQH_sendMessage);
}

void Heavy_SoundScraper::cBinop_e1kXetu8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_EYWtS4mG_sendMessage);
}

void Heavy_SoundScraper::cBinop_EYWtS4mG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_oa9d4ZFT_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_zNW0KTUv, m);
}

void Heavy_SoundScraper::cBinop_oa9d4ZFT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_D3Mcg0iI, m);
}

void Heavy_SoundScraper::cBinop_5NIiMBbp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_bBHOczSz_sendMessage);
}

void Heavy_SoundScraper::cBinop_bBHOczSz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_X3efWxy3, m);
}

void Heavy_SoundScraper::cBinop_NNoHlZXP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_6vl1FfJI_sendMessage);
}

void Heavy_SoundScraper::cBinop_6vl1FfJI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_MzyjZfHm_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_8m6Fdyy4_sendMessage);
}

void Heavy_SoundScraper::cVar_x5cBU2Qp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_dY8DKJvd_sendMessage);
}

void Heavy_SoundScraper::cMsg_I7wg7SH9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_EFGishkY_sendMessage);
}

void Heavy_SoundScraper::cSystem_EFGishkY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KpHOaY9J, HV_BINOP_DIVIDE, 1, m, &cBinop_KpHOaY9J_sendMessage);
}

void Heavy_SoundScraper::cBinop_MzyjZfHm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_tg416fDE_sendMessage);
}

void Heavy_SoundScraper::cBinop_tg416fDE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_AnH1cdIn, m);
}

void Heavy_SoundScraper::cMsg_eEvRkP9x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_G4VDP08J_sendMessage);
}

void Heavy_SoundScraper::cBinop_G4VDP08J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_NNoHlZXP_sendMessage);
}

void Heavy_SoundScraper::cBinop_8m6Fdyy4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_XslEbU7V, m);
}

void Heavy_SoundScraper::cBinop_dY8DKJvd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_4w2uKSjt_sendMessage);
}

void Heavy_SoundScraper::cBinop_4w2uKSjt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KpHOaY9J, HV_BINOP_DIVIDE, 0, m, &cBinop_KpHOaY9J_sendMessage);
}

void Heavy_SoundScraper::cBinop_KpHOaY9J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eEvRkP9x_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_Mqg3llS9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_J6iIxVlP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_c9ZnSBKh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_bHuanGUx_sendMessage);
}

void Heavy_SoundScraper::cSystem_bHuanGUx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_zC71bHZc_sendMessage);
}

void Heavy_SoundScraper::cDelay_gqLsfqZR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gqLsfqZR, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1Z2sWVqU, 0, m, &cDelay_1Z2sWVqU_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gqLsfqZR, 0, m, &cDelay_gqLsfqZR_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_dOrcyMDJ, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_1Z2sWVqU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1Z2sWVqU, m);
  cMsg_XeUXT0Kn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_CYMtwQgO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_ZZYliETP_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_WwKuv3JG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Fkh8x2PO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_M3hk39fh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zfNc5Dew_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gqLsfqZR, 2, m, &cDelay_gqLsfqZR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IfbL89Fl_sendMessage);
}

void Heavy_SoundScraper::cMsg_Fkh8x2PO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_M3hk39fh, 0, m, &hTable_M3hk39fh_sendMessage);
}

void Heavy_SoundScraper::cBinop_zC71bHZc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_WwKuv3JG_sendMessage);
}

void Heavy_SoundScraper::cMsg_XeUXT0Kn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_M3hk39fh, 0, m, &hTable_M3hk39fh_sendMessage);
}

void Heavy_SoundScraper::cCast_IfbL89Fl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gqLsfqZR, 0, m, &cDelay_gqLsfqZR_sendMessage);
}

void Heavy_SoundScraper::cMsg_zfNc5Dew_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_1Z2sWVqU, 2, m, &cDelay_1Z2sWVqU_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZZYliETP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_dOrcyMDJ, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_WlPomojG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_J6iIxVlP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_J6iIxVlP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_2r9cKhjn, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_X4Sq55vo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_E9hKNxIE, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_5nR2Cy1w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_X4Sq55vo, 0, m, &cPack_X4Sq55vo_sendMessage);
}

void Heavy_SoundScraper::cCast_RvozrQJ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ZlZ1PDfV_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_A0Fd6ySR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_E9hKNxIE, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_oIHlfWfW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 500.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Gr1RpTtY, m);
}

void Heavy_SoundScraper::cMsg_ZZfz5ChN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.3f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_5NIiMBbp_sendMessage);
}

void Heavy_SoundScraper::cVar_o0Yxg6gR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_Nt42WWc2_sendMessage);
}

void Heavy_SoundScraper::cBinop_Nt42WWc2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_o0Yxg6gR, 1, m, &cVar_o0Yxg6gR_sendMessage);
}

void Heavy_SoundScraper::cPack_79PXwRbh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_eQmLPtLE, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_SDbjxm3y_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_1bzdjMY0, 0, m, &cSlice_1bzdjMY0_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_PaLr9tRb, 0, m, &cRandom_PaLr9tRb_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_erlr0SiZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_EPzGfl5y_sendMessage);
}

void Heavy_SoundScraper::cUnop_EPzGfl5y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 25.0f, 0, m, &cBinop_GBonw8PT_sendMessage);
}

void Heavy_SoundScraper::cRandom_PaLr9tRb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 30.0f, 0, m, &cBinop_erlr0SiZ_sendMessage);
}

void Heavy_SoundScraper::cSlice_1bzdjMY0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_PaLr9tRb, 1, m, &cRandom_PaLr9tRb_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_I5qo2ebz_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_VlihNGi2, 0, m, &cSlice_VlihNGi2_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_aQGDLbMN, 0, m, &cRandom_aQGDLbMN_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_20nVirTb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_AvwAs4jQ_sendMessage);
}

void Heavy_SoundScraper::cUnop_AvwAs4jQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 10.0f, 0, m, &cBinop_v8wRbbWg_sendMessage);
}

void Heavy_SoundScraper::cRandom_aQGDLbMN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 40.0f, 0, m, &cBinop_20nVirTb_sendMessage);
}

void Heavy_SoundScraper::cSlice_VlihNGi2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_aQGDLbMN, 1, m, &cRandom_aQGDLbMN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_tDG9ss1M_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_0z2x7JB5, 0, m, &cSlice_0z2x7JB5_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_A7nlqwoJ, 0, m, &cRandom_A7nlqwoJ_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_d63MkNan_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_ol0YtwQw_sendMessage);
}

void Heavy_SoundScraper::cUnop_ol0YtwQw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_ZMhMs5Ra_sendMessage);
}

void Heavy_SoundScraper::cRandom_A7nlqwoJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_d63MkNan_sendMessage);
}

void Heavy_SoundScraper::cSlice_0z2x7JB5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_A7nlqwoJ, 1, m, &cRandom_A7nlqwoJ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cPack_J0axeTcT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SCRAPER_RESET");
}

void Heavy_SoundScraper::cBinop_GBonw8PT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_5wmCQkf6_sendMessage(_c, 0, m);
  cPack_onMessage(_c, &Context(_c)->cPack_J0axeTcT, 1, m, &cPack_J0axeTcT_sendMessage);
}

void Heavy_SoundScraper::cBinop_v8wRbbWg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_cAmWFMhr_sendMessage(_c, 0, m);
  cPack_onMessage(_c, &Context(_c)->cPack_J0axeTcT, 0, m, &cPack_J0axeTcT_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZMhMs5Ra_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_LGHgmz0e_sendMessage(_c, 0, m);
  cPack_onMessage(_c, &Context(_c)->cPack_J0axeTcT, 2, m, &cPack_J0axeTcT_sendMessage);
}

void Heavy_SoundScraper::cCast_4BzgW2Ok_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GuQBuKaA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_DAmTW3Wl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_SDbjxm3y_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_pPBTZmE5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_I5qo2ebz_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_K5wZbcJc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_tDG9ss1M_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_GuQBuKaA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_hpGeMUca_sendMessage(_c, 0, m);
  cPack_onMessage(_c, &Context(_c)->cPack_J0axeTcT, 3, m, &cPack_J0axeTcT_sendMessage);
}

void Heavy_SoundScraper::cSend_hpGeMUca_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_LCvspGBQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_LGHgmz0e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_NrPJjStY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_cAmWFMhr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_5wmCQkf6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_UnzLi4Sb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_MepZ0Kil_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_2TWhlPNK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_E614orWO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cDuRkgFQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CvKnnLg3_sendMessage);
}

void Heavy_SoundScraper::cIf_XhAa5SuK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Chs6OoWf_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 440.0f, 0, m, &cBinop_OHsmVhY5_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_qSfLmvja_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 12.0f, 0, m, &cBinop_jHVNCy8c_sendMessage);
}

void Heavy_SoundScraper::cBinop_OHsmVhY5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_LOG2, m, &cUnop_qSfLmvja_sendMessage);
}

void Heavy_SoundScraper::cBinop_jHVNCy8c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 69.0f, 0, m, &cBinop_IhLa5Xji_sendMessage);
}

void Heavy_SoundScraper::cBinop_IhLa5Xji_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WOQc499a, 0, m, &cVar_WOQc499a_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_dsnL65UT, HV_BINOP_SUBTRACT, 1, m, &cBinop_dsnL65UT_sendMessage);
}

void Heavy_SoundScraper::cCast_CvKnnLg3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_XhAa5SuK, 0, m, &cIf_XhAa5SuK_sendMessage);
}

void Heavy_SoundScraper::cCast_cDuRkgFQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_kfMpbW0J_sendMessage);
}

void Heavy_SoundScraper::cBinop_kfMpbW0J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_XhAa5SuK, 1, m, &cIf_XhAa5SuK_sendMessage);
}

void Heavy_SoundScraper::cMsg_Chs6OoWf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1500.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_WOQc499a, 0, m, &cVar_WOQc499a_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_dsnL65UT, HV_BINOP_SUBTRACT, 1, m, &cBinop_dsnL65UT_sendMessage);
}

void Heavy_SoundScraper::cVar_WOQc499a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cCast_afF7thHS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dsnL65UT, HV_BINOP_SUBTRACT, 0, m, &cBinop_dsnL65UT_sendMessage);
}

void Heavy_SoundScraper::cBinop_aclplYbk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MepZ0Kil, 0, m, &cVar_MepZ0Kil_sendMessage);
}

void Heavy_SoundScraper::cBinop_7oMwRnG5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aclplYbk, HV_BINOP_ADD, 1, m, &cBinop_aclplYbk_sendMessage);
}

void Heavy_SoundScraper::cBinop_dsnL65UT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aclplYbk, HV_BINOP_ADD, 0, m, &cBinop_aclplYbk_sendMessage);
}

void Heavy_SoundScraper::cSend_2TWhlPNK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_r1xblk35_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_CteyzjQO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_3M00gR2I, 0, m, &cSlice_3M00gR2I_sendMessage);
      break;
    }
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_5h5wI2gI, 0, m, &cSlice_5h5wI2gI_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_3M00gR2I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ftELdHEE_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ftELdHEE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_5h5wI2gI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YtosqeML_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_w8XFZ5xI_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YtosqeML_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_w8XFZ5xI_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_Ht51AKFF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_J7vJ7SvU, HV_BINOP_MULTIPLY, 0, m, &cBinop_J7vJ7SvU_sendMessage);
}

void Heavy_SoundScraper::cMsg_1jXdto5s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_s3wxNYAq_sendMessage);
}

void Heavy_SoundScraper::cSystem_s3wxNYAq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_v6jpsQmr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_J7vJ7SvU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_h0cHkzky_sendMessage);
}

void Heavy_SoundScraper::cBinop_yBHmZ1m8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_J7vJ7SvU, HV_BINOP_MULTIPLY, 1, m, &cBinop_J7vJ7SvU_sendMessage);
}

void Heavy_SoundScraper::cMsg_v6jpsQmr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_yBHmZ1m8_sendMessage);
}

void Heavy_SoundScraper::cBinop_h0cHkzky_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_USaKWX2B_sendMessage);
}

void Heavy_SoundScraper::cBinop_USaKWX2B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_nIwgI05u_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_FnCQzVKY, m);
}

void Heavy_SoundScraper::cBinop_nIwgI05u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_XqbHAxnG, m);
}

void Heavy_SoundScraper::cSlice_WH21fbod_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_93gZXeMp_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_l1XFrSv9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_aFWPNTTj_sendMessage(_c, 0, m);
      cPrint_onMessage(_c, m, "SCRAPER_TAB");
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_02RtrtOr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_w17EFK4S_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_w17EFK4S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_r1xblk35_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_Bn6RCybH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_NrPJjStY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_b6AYegqN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 5.0f);
  cSend_Bn6RCybH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_c1vDNHzl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cSend_xXe5hqo7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_xXe5hqo7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cMsg_qTliqafF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_67eAmt0i_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_67eAmt0i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_OFHV3Wae_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_rPRE98C6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_NIA9lr9l_sendMessage);
}

void Heavy_SoundScraper::cBinop_NIA9lr9l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_U1l1uAQa_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_fSDioTnh_sendMessage);
}

void Heavy_SoundScraper::cVar_EzSt5EAO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_h1UTfZuF_sendMessage);
}

void Heavy_SoundScraper::cMsg_Z63KZ7fR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PF4O6lRe_sendMessage);
}

void Heavy_SoundScraper::cSystem_PF4O6lRe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EFYSSgQA, HV_BINOP_DIVIDE, 1, m, &cBinop_EFYSSgQA_sendMessage);
}

void Heavy_SoundScraper::cBinop_U1l1uAQa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_W36MOKFA_sendMessage);
}

void Heavy_SoundScraper::cBinop_W36MOKFA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_969N79dX, m);
}

void Heavy_SoundScraper::cMsg_6yXitCTV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_bUHTa1Jz_sendMessage);
}

void Heavy_SoundScraper::cBinop_bUHTa1Jz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_rPRE98C6_sendMessage);
}

void Heavy_SoundScraper::cBinop_fSDioTnh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_sY7TkwYC, m);
}

void Heavy_SoundScraper::cBinop_h1UTfZuF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_I1Cg3skG_sendMessage);
}

void Heavy_SoundScraper::cBinop_I1Cg3skG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EFYSSgQA, HV_BINOP_DIVIDE, 0, m, &cBinop_EFYSSgQA_sendMessage);
}

void Heavy_SoundScraper::cBinop_EFYSSgQA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6yXitCTV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::sSample_qfX4NsAm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AmN9XE0X, 0, m, &cVar_AmN9XE0X_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_IBNPzuC4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_ASI12R6g_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_ASI12R6g_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_LAwxoK6C, 1, m, &cDelay_LAwxoK6C_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mM9pkjah_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_LAwxoK6C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LAwxoK6C, m);
  sSample_onMessage(_c, &Context(_c)->sSample_qfX4NsAm, 1, m);
}

void Heavy_SoundScraper::cMsg_ASI12R6g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_LAwxoK6C, 0, m, &cDelay_LAwxoK6C_sendMessage);
}

void Heavy_SoundScraper::cCast_mM9pkjah_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_LAwxoK6C, 0, m, &cDelay_LAwxoK6C_sendMessage);
}

void Heavy_SoundScraper::cVar_AmN9XE0X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SCRAPER_SIG");
}

void Heavy_SoundScraper::cCast_EQPvW0no_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sSample_onMessage(_c, &Context(_c)->sSample_qfX4NsAm, 1, m);
}

void Heavy_SoundScraper::cSwitchcase_CuSxWlwp_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_n0iIX906_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_n0iIX906_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_E1nKngZa, 1, m, &cDelay_E1nKngZa_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FwpxTqTX_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_E1nKngZa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_E1nKngZa, m);
  sSample_onMessage(_c, &Context(_c)->sSample_qfX4NsAm, 1, m);
}

void Heavy_SoundScraper::cMsg_n0iIX906_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_E1nKngZa, 0, m, &cDelay_E1nKngZa_sendMessage);
}

void Heavy_SoundScraper::cCast_FwpxTqTX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_E1nKngZa, 0, m, &cDelay_E1nKngZa_sendMessage);
}

void Heavy_SoundScraper::cVar_XIKu30sk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 44.1f, 0, m, &cBinop_2tcmb09u_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_aPNvr5sK_sendMessage);
}

void Heavy_SoundScraper::cVar_DVyLaWtT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 44.1f, 0, m, &cBinop_JTkiZ1br_sendMessage);
}

void Heavy_SoundScraper::cVar_ddeKu5Uy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_Wu4O9RP8, 0, m, &cExpr_Wu4O9RP8_sendMessage);
}

void Heavy_SoundScraper::cExpr_Wu4O9RP8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KbFZevaz, HV_BINOP_DIVIDE, 0, m, &cBinop_KbFZevaz_sendMessage);
}

float Heavy_SoundScraper::cExpr_Wu4O9RP8_evaluate(const float* args) {
  	return hv_pow_f(2 , ((float)(args[0]))/1200);
}

void Heavy_SoundScraper::cVar_Xnc5fB8l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_T8DireCs, 0, m);
}

void Heavy_SoundScraper::cMsg_gZoXnTfb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_znjKPcMP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_m0ojY2xU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_U2uFqqNZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_HhBrOtzR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cSend_jxbEJ5bu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_znjKPcMP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_32BwWPVb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_U2uFqqNZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_PNKBZpev_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_jxbEJ5bu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_1Ryv7W5c_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_2WZJIx2x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XIKu30sk, 0, m, &cVar_XIKu30sk_sendMessage);
}

void Heavy_SoundScraper::cVar_cGw52fC2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DVyLaWtT, 0, m, &cVar_DVyLaWtT_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_3J1igV7m_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_KWR8LjXy, 0, m, &cSlice_KWR8LjXy_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_acmDYJ74_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KKtjEm2A_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_QyPrcZ9O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_YcwJCiS0_sendMessage);
}

void Heavy_SoundScraper::cBinop_YcwJCiS0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_pATykqdu, m);
}

void Heavy_SoundScraper::cMsg_KKtjEm2A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QyPrcZ9O_sendMessage);
}

void Heavy_SoundScraper::cSlice_KWR8LjXy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_hIGy1oJE, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_kT3lBcar, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_acmDYJ74, 0, m, &cVar_acmDYJ74_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_NEdsLrA9_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_jDepmzjK, 0, m, &cSlice_jDepmzjK_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_haDH1Pig_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_41X9cD1m_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_wKSc4TGM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_BRMs9Len_sendMessage);
}

void Heavy_SoundScraper::cBinop_BRMs9Len_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_uukg2iBw, m);
}

void Heavy_SoundScraper::cMsg_41X9cD1m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wKSc4TGM_sendMessage);
}

void Heavy_SoundScraper::cSlice_jDepmzjK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_vlLQy8ak, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_FyKFdTX9, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_haDH1Pig, 0, m, &cVar_haDH1Pig_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_8wtpw67V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KbFZevaz, HV_BINOP_DIVIDE, 0, m, &cBinop_KbFZevaz_sendMessage);
}

void Heavy_SoundScraper::cCast_0F15r7sN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KbFZevaz, HV_BINOP_DIVIDE, 1, m, &cBinop_KbFZevaz_sendMessage);
}

void Heavy_SoundScraper::cBinop_KbFZevaz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Xnc5fB8l, 0, m, &cVar_Xnc5fB8l_sendMessage);
}

void Heavy_SoundScraper::cBinop_2tcmb09u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_CKNGeeNZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_JTkiZ1br_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_lTSeWxR8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_aPNvr5sK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_e3nreOhT_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_e3nreOhT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_eBfzSXPm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_CKNGeeNZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9EnESZLv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_lTSeWxR8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_L3U17zaA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_6wlHyB4j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_NEdsLrA9_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSend_5ldlAEfr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_aQfICTuo_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_fqEFix0y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_3J1igV7m_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::hTable_7oIywVCj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_d5H4IXVD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_GCKL6sTs_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_K7UyFoFL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_OFHV3Wae_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_M8qGcqtA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_1uJpXrOx_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_ORYFkxWn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_NMT6WM1H_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_PZwV8Qvh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_LCvspGBQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_SHL6IFFO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_DpsnjsdP_sendMessage);
}

void Heavy_SoundScraper::cBinop_DpsnjsdP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_79PXwRbh, 0, m, &cPack_79PXwRbh_sendMessage);
}

void Heavy_SoundScraper::cSend_VqbpZXq0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_NMT6WM1H_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_BH27rrL5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_7t5fPbvs_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_9nFzZDG9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_wlK28fcT_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_ftELdHEE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_BH27rrL5_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_kqgArgJ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cPrint_onMessage(_c, m, "SCRAPER_RUNNING");
  sVarf_onMessage(_c, &Context(_c)->sVarf_d5Xdc7XF, m);
}

void Heavy_SoundScraper::cMsg_lSJp93lF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPrint_onMessage(_c, m, "SCRAPER_RUNNING");
  sVarf_onMessage(_c, &Context(_c)->sVarf_d5Xdc7XF, m);
}

void Heavy_SoundScraper::cSend_aFWPNTTj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_0LNExEPw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_93gZXeMp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RgdYQmKY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_YtosqeML_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_VqbpZXq0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_w8XFZ5xI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_9nFzZDG9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_PeztPEIx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DVyLaWtT, 0, m, &cVar_DVyLaWtT_sendMessage);
}

void Heavy_SoundScraper::cBinop_WRX4MsJe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XIKu30sk, 0, m, &cVar_XIKu30sk_sendMessage);
}

void Heavy_SoundScraper::cBinop_PqeaNF9g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_Wu4O9RP8, 0, m, &cExpr_Wu4O9RP8_sendMessage);
}

void Heavy_SoundScraper::cReceive_CxBBmUQ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_AKsbjDOX, 0, m, &cPack_AKsbjDOX_sendMessage);
}

void Heavy_SoundScraper::cReceive_nw0MBJwa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_AKsbjDOX, 1, m, &cPack_AKsbjDOX_sendMessage);
}

void Heavy_SoundScraper::cReceive_sbOb3eYG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SET_TABLE");
  cSlice_onMessage(_c, &Context(_c)->cSlice_3E0hLPsR, 0, m, &cSlice_3E0hLPsR_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_DDRuaejs, 0, m, &cSlice_DDRuaejs_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_HjGSsOiG, 0, m, &cSlice_HjGSsOiG_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_DKegY29b, 0, m, &cSlice_DKegY29b_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Df0ixTcC, 0, m, &cSlice_Df0ixTcC_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_BBzctUjR, 0, m, &cSlice_BBzctUjR_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_iUBxvauI, 0, m, &cSlice_iUBxvauI_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_eKD3Mqw1, 0, m, &cSlice_eKD3Mqw1_sendMessage);
  cSend_M8qGcqtA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_gwhRNYli_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_K7UyFoFL_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_JHPQCjK7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_d5H4IXVD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_wLnGyhnT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_o0Yxg6gR, 0, m, &cVar_o0Yxg6gR_sendMessage);
  cSwitchcase_CteyzjQO_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_nGTK2DON_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_PZwV8Qvh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_YTOooiKX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ORYFkxWn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_ZjLtdyuY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cNEks9Pv_sendMessage(_c, 0, m);
  cMsg_YJnc2z71_sendMessage(_c, 0, m);
  cMsg_QtGPxqRH_sendMessage(_c, 0, m);
  cMsg_kIrKx4AQ_sendMessage(_c, 0, m);
  cMsg_CDXGkAJJ_sendMessage(_c, 0, m);
  cMsg_TcykXE5x_sendMessage(_c, 0, m);
  cMsg_bnXokAx1_sendMessage(_c, 0, m);
  cMsg_hLCfqcDD_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_bTI3bFr5, 0, m, &cVar_bTI3bFr5_sendMessage);
  cMsg_2CosRh4F_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VK0ooZFX, 0, m, &cVar_VK0ooZFX_sendMessage);
  cMsg_SO8NFMqB_sendMessage(_c, 0, m);
  cMsg_jtC1jntz_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_rZAJzj2N, 0, m, &cVar_rZAJzj2N_sendMessage);
  cMsg_KFOeusDy_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_lq0ZeuWF, 0, m, &cVar_lq0ZeuWF_sendMessage);
  cMsg_N80OSpb9_sendMessage(_c, 0, m);
  cMsg_Qy430MmB_sendMessage(_c, 0, m);
  cMsg_izNPN0tE_sendMessage(_c, 0, m);
  cMsg_2hqU7Ygt_sendMessage(_c, 0, m);
  cMsg_z1OcXc5g_sendMessage(_c, 0, m);
  cMsg_5WdfHL2l_sendMessage(_c, 0, m);
  cMsg_NnwVeGLU_sendMessage(_c, 0, m);
  cMsg_nkFzeAid_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_R26pb7J2, 0, m, &cVar_R26pb7J2_sendMessage);
  cMsg_i5IE9f9v_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_cIB6hrj3, 0, m, &cVar_cIB6hrj3_sendMessage);
  cMsg_s2okftnM_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VQ083g8a, 0, m, &cVar_VQ083g8a_sendMessage);
  cMsg_1UgLHtPF_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_sW8nmyIk, 0, m, &cVar_sW8nmyIk_sendMessage);
  cMsg_nIaEFQvi_sendMessage(_c, 0, m);
  cMsg_DOkYqMH0_sendMessage(_c, 0, m);
  cMsg_Vuv8J8ds_sendMessage(_c, 0, m);
  cMsg_zq5pSJqe_sendMessage(_c, 0, m);
  cMsg_Gasc5WTC_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_vgwh6SfN, 0, m, &cVar_vgwh6SfN_sendMessage);
  cMsg_JIREBJmJ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_tUl2MrOD, 0, m, &cVar_tUl2MrOD_sendMessage);
  cMsg_g8UmmVO4_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_tiXmJjxq, 0, m, &cVar_tiXmJjxq_sendMessage);
  cMsg_LdyhBGqm_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_IK0Wuvlg, 0, m, &cVar_IK0Wuvlg_sendMessage);
  cMsg_stypFTfS_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_v8V26Hd2, 0, m, &cVar_v8V26Hd2_sendMessage);
  cMsg_I7wg7SH9_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_x5cBU2Qp, 0, m, &cVar_x5cBU2Qp_sendMessage);
  cMsg_c9ZnSBKh_sendMessage(_c, 0, m);
  cMsg_5sYt4vyT_sendMessage(_c, 0, m);
  cMsg_vVR2GmkZ_sendMessage(_c, 0, m);
  cMsg_xLvKxhqH_sendMessage(_c, 0, m);
  cMsg_U1I1cI4H_sendMessage(_c, 0, m);
  cMsg_khPdb6jj_sendMessage(_c, 0, m);
  cMsg_G99sOwTV_sendMessage(_c, 0, m);
  cMsg_ybKgi1HZ_sendMessage(_c, 0, m);
  cMsg_1o2DeA9K_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_iSuPtPBp, 0, m, &cVar_iSuPtPBp_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_axV3FCr3, 0, m, &cVar_axV3FCr3_sendMessage);
  cMsg_tKXXYZKG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_67dHZIe4, 0, m, &cVar_67dHZIe4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_RPGNKu60, 0, m, &cVar_RPGNKu60_sendMessage);
  cMsg_TClg80ov_sendMessage(_c, 0, m);
  cMsg_olqWoLDC_sendMessage(_c, 0, m);
  cMsg_MH9KRoXU_sendMessage(_c, 0, m);
  cMsg_IKZaG5aV_sendMessage(_c, 0, m);
  cMsg_RUcN0Zpk_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_aOQ9OlCb, 0, m, &cVar_aOQ9OlCb_sendMessage);
  cMsg_or62QWCn_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_k8fKOk59, 0, m, &cVar_k8fKOk59_sendMessage);
  cMsg_jkW7uzYD_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8s99bkvX, 0, m, &cVar_8s99bkvX_sendMessage);
  cMsg_ZBdEYGTa_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ddMXOMJQ, 0, m, &cVar_ddMXOMJQ_sendMessage);
  cMsg_dvcTCq8g_sendMessage(_c, 0, m);
  cMsg_QPIxSrQT_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_OLpM7ZL1, 0, m, &cVar_OLpM7ZL1_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_8Usvu6Ky, 0, m, &cVar_8Usvu6Ky_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_UhJUy96q, 0, m, &cVar_UhJUy96q_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_BzxHXOCF, 0, m, &cVar_BzxHXOCF_sendMessage);
  cMsg_WlPomojG_sendMessage(_c, 0, m);
  cMsg_gZoXnTfb_sendMessage(_c, 0, m);
  cMsg_m0ojY2xU_sendMessage(_c, 0, m);
  cMsg_HhBrOtzR_sendMessage(_c, 0, m);
  cMsg_rltx3JmI_sendMessage(_c, 0, m);
  cMsg_t1xo40GW_sendMessage(_c, 0, m);
  cMsg_Yt4DU51J_sendMessage(_c, 0, m);
  cMsg_vbOpwuyT_sendMessage(_c, 0, m);
  cMsg_XxMqmjEe_sendMessage(_c, 0, m);
  cMsg_iq3qQUj0_sendMessage(_c, 0, m);
  cMsg_2cc7htRO_sendMessage(_c, 0, m);
  cMsg_Mmhiy5Wr_sendMessage(_c, 0, m);
  cMsg_tGaQTkSv_sendMessage(_c, 0, m);
  cMsg_01h4tdPa_sendMessage(_c, 0, m);
  cMsg_KnL4RaBb_sendMessage(_c, 0, m);
  cMsg_rAgRme8f_sendMessage(_c, 0, m);
  cMsg_nzOG0VAI_sendMessage(_c, 0, m);
  cMsg_N5Z0nEYJ_sendMessage(_c, 0, m);
  cMsg_6AA6CICN_sendMessage(_c, 0, m);
  cMsg_aJtEETrQ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_fcIqxhNK, 0, m, &cVar_fcIqxhNK_sendMessage);
  cMsg_ibRUtByE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YSTFFx4C, 0, m, &cVar_YSTFFx4C_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_yJzowiDV, 0, m, &cVar_yJzowiDV_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_XgN9UCBQ, 0, m, &cVar_XgN9UCBQ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_I3vAVxsQ, 0, m, &cVar_I3vAVxsQ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qRMdyRZj, 0, m, &cVar_qRMdyRZj_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_IS0NihHG, 0, m, &cVar_IS0NihHG_sendMessage);
  cMsg_oIHlfWfW_sendMessage(_c, 0, m);
  cMsg_ZZfz5ChN_sendMessage(_c, 0, m);
  cMsg_1jXdto5s_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Ht51AKFF, 0, m, &cVar_Ht51AKFF_sendMessage);
  cMsg_02RtrtOr_sendMessage(_c, 0, m);
  cMsg_b6AYegqN_sendMessage(_c, 0, m);
  cMsg_c1vDNHzl_sendMessage(_c, 0, m);
  cMsg_qTliqafF_sendMessage(_c, 0, m);
  cMsg_Z63KZ7fR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_EzSt5EAO, 0, m, &cVar_EzSt5EAO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lKNjrLfM, 0, m, &cVar_lKNjrLfM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_vRxqgq9S, 0, m, &cVar_vRxqgq9S_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_tQMJpxkN, 0, m, &cVar_tQMJpxkN_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_AjJ4B8zP, 0, m, &cVar_AjJ4B8zP_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wZQyT7Ko, 0, m, &cVar_wZQyT7Ko_sendMessage);
  cMsg_2wY6hVmP_sendMessage(_c, 0, m);
  cMsg_2sPskGVt_sendMessage(_c, 0, m);
  cSend_ORYFkxWn_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YM7jReps, 0, m, &cVar_YM7jReps_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_k7Fj0yOb, 0, m, &cVar_k7Fj0yOb_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wvP4HmK3, 0, m, &cVar_wvP4HmK3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_f1CdBkdk, 0, m, &cVar_f1CdBkdk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_dW1NHeJ6, 0, m, &cVar_dW1NHeJ6_sendMessage);
  cMsg_gez0P1Be_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_355T4jD2, 0, m, &cVar_355T4jD2_sendMessage);
  cMsg_QXC57HOG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_bzu2vw0t, 0, m, &cVar_bzu2vw0t_sendMessage);
  cMsg_zU46ArFC_sendMessage(_c, 0, m);
  cMsg_SBq5PRZt_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_fH6aAUco, 0, m, &cVar_fH6aAUco_sendMessage);
  cMsg_FyJsi2xJ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_g3PCOzNZ, 0, m, &cTabhead_g3PCOzNZ_sendMessage);
  cMsg_Vt7SUgrt_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6jfaf4QE, 0, m, &cVar_6jfaf4QE_sendMessage);
  cMsg_7MJnDTBo_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_AsHJtCmo, 0, m, &cTabhead_AsHJtCmo_sendMessage);
  cMsg_pmUh3ayz_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_b68GLqBA, 0, m, &cVar_b68GLqBA_sendMessage);
  cMsg_1FGaC00x_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_LQP9Us35, 0, m, &cTabhead_LQP9Us35_sendMessage);
  cMsg_HY4I9FRO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_DHPHC5Ky, 0, m, &cVar_DHPHC5Ky_sendMessage);
  cMsg_bQRTA6jb_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Skrp7sdn, 0, m, &cTabhead_Skrp7sdn_sendMessage);
  cMsg_WQCJuMwg_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0Be0FaQ5, 0, m, &cVar_0Be0FaQ5_sendMessage);
  cMsg_TFVlrPQF_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Gy16jHUe, 0, m, &cTabhead_Gy16jHUe_sendMessage);
  cMsg_qmo7ShAQ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ZZxe0UrA, 0, m, &cVar_ZZxe0UrA_sendMessage);
  cMsg_6dYylrfm_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_UQWPnZWy, 0, m, &cTabhead_UQWPnZWy_sendMessage);
  cMsg_nzJoNems_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_h3IcUmL7, 0, m, &cVar_h3IcUmL7_sendMessage);
  cMsg_KkqyEtNV_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ih5GnYAW, 0, m, &cTabhead_ih5GnYAW_sendMessage);
  cMsg_Pm6BgNnu_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3wJR809q, 0, m, &cVar_3wJR809q_sendMessage);
  cMsg_jZpzwFlS_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_8RQheQpP, 0, m, &cTabhead_8RQheQpP_sendMessage);
  cMsg_x8C2PuEG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TEvax844, 0, m, &cVar_TEvax844_sendMessage);
  cMsg_N2lVLt1f_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_lgfETbHV, 0, m, &cTabhead_lgfETbHV_sendMessage);
  cMsg_42uo092h_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4JzXAX0n, 0, m, &cVar_4JzXAX0n_sendMessage);
  cMsg_eHnUVbtd_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_qjsp8uUK, 0, m, &cTabhead_qjsp8uUK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_mgXjKRnt, 0, m, &cVar_mgXjKRnt_sendMessage);
  cMsg_mdZB2Lx2_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YbrdOzca, 0, m, &cVar_YbrdOzca_sendMessage);
  cMsg_Z3xrUzGJ_sendMessage(_c, 0, m);
  cMsg_ucLAfFwI_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_HH6Xr0A7, 0, m, &cVar_HH6Xr0A7_sendMessage);
  cMsg_UHBv5r8J_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_SXkhJBY3, 0, m, &cTabhead_SXkhJBY3_sendMessage);
  cMsg_PI8zT0Ru_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_O4t0wLSg, 0, m, &cVar_O4t0wLSg_sendMessage);
  cMsg_RN7Rga2n_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_NR3xuXrv, 0, m, &cTabhead_NR3xuXrv_sendMessage);
  cMsg_nO4mL71H_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_cSpwGDa1, 0, m, &cVar_cSpwGDa1_sendMessage);
  cMsg_sYnTgkcZ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_kXwel3YH, 0, m, &cTabhead_kXwel3YH_sendMessage);
  cMsg_Ml0r1OMs_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_eFC51iED, 0, m, &cVar_eFC51iED_sendMessage);
  cMsg_tB7TBX5j_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_sFyzHI0n, 0, m, &cTabhead_sFyzHI0n_sendMessage);
  cMsg_Al7tWu1i_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_SVNkmjVv, 0, m, &cVar_SVNkmjVv_sendMessage);
  cMsg_6ALqfEvH_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Vf7MCSSc, 0, m, &cTabhead_Vf7MCSSc_sendMessage);
  cMsg_pcLF8SWH_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_STZtxlja, 0, m, &cVar_STZtxlja_sendMessage);
  cMsg_jljnO4TN_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_MRJoq79y, 0, m, &cTabhead_MRJoq79y_sendMessage);
  cMsg_Y3Fc2xAS_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_17rsssFG, 0, m, &cVar_17rsssFG_sendMessage);
  cMsg_E10OcyiY_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_J4Ps2RAU, 0, m, &cTabhead_J4Ps2RAU_sendMessage);
  cMsg_WaYqjlDH_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_SuZ5xyqC, 0, m, &cVar_SuZ5xyqC_sendMessage);
  cMsg_LLyJafxZ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_B8Gbhmkw, 0, m, &cTabhead_B8Gbhmkw_sendMessage);
  cMsg_0SibBmsn_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Mxp21e5Z, 0, m, &cVar_Mxp21e5Z_sendMessage);
  cMsg_QthOvPXW_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Cwtwr1LJ, 0, m, &cTabhead_Cwtwr1LJ_sendMessage);
  cMsg_0HumCUyi_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_hA6Ojs56, 0, m, &cVar_hA6Ojs56_sendMessage);
  cMsg_U9iCZFW9_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_itxTn9nv, 0, m, &cTabhead_itxTn9nv_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Rp1tnQDo, 0, m, &cVar_Rp1tnQDo_sendMessage);
  cMsg_CPeVVXWC_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_acmDYJ74, 0, m, &cVar_acmDYJ74_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_haDH1Pig, 0, m, &cVar_haDH1Pig_sendMessage);
}

void Heavy_SoundScraper::cReceive_DNjqk3UM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0tCFaBTJ, 0, m, &cVar_0tCFaBTJ_sendMessage);
}

void Heavy_SoundScraper::cReceive_H9BHVkDc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bkpPYwKO_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Ox6WpxKg_sendMessage);
}

void Heavy_SoundScraper::cReceive_XQTzou6E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nWT84UvH, 1, m, &cVar_nWT84UvH_sendMessage);
}

void Heavy_SoundScraper::cReceive_fCf0x2Jq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aQgkKa9T, HV_BINOP_DIVIDE, 1, m, &cBinop_aQgkKa9T_sendMessage);
}

void Heavy_SoundScraper::cReceive_fmDgQybQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_7bGITYBy_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_7HBi5u7c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GIYs6YNp, 1, m, &cVar_GIYs6YNp_sendMessage);
}

void Heavy_SoundScraper::cReceive_EYKkvHFY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_S3c4S773, m);
}

void Heavy_SoundScraper::cReceive_PCM1uxC7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_nWA9yvBT, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_PHASE");
  cSlice_onMessage(_c, &Context(_c)->cSlice_uR0T5SUa, 0, m, &cSlice_uR0T5SUa_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Kg316Csk, 0, m, &cSlice_Kg316Csk_sendMessage);
}

void Heavy_SoundScraper::cReceive_WcE88BIr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_pQCPywbP, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_CUTOFF");
}

void Heavy_SoundScraper::cReceive_28QRvpe5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0yteDdcT, 1, m, &cVar_0yteDdcT_sendMessage);
}

void Heavy_SoundScraper::cReceive_yG0OGGFa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YnAnRMqN, HV_BINOP_DIVIDE, 1, m, &cBinop_YnAnRMqN_sendMessage);
}

void Heavy_SoundScraper::cReceive_W7lhEMOP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_0pFpzUtk_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_Vo0k0SLh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2JhScW0D, 1, m, &cVar_2JhScW0D_sendMessage);
}

void Heavy_SoundScraper::cReceive_E59rlgCX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_JmtFakDs, m);
}

void Heavy_SoundScraper::cReceive_cQ4iDoKO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Axs38sYp, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_PHASE");
  cSlice_onMessage(_c, &Context(_c)->cSlice_ybqVxD9K, 0, m, &cSlice_ybqVxD9K_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_OzfNoFZp, 0, m, &cSlice_OzfNoFZp_sendMessage);
}

void Heavy_SoundScraper::cReceive_CR9nAzwW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_xg7MmMDM, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_CUTOFF");
}

void Heavy_SoundScraper::cReceive_2HP2M7U2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Hs0HkWxb, 1, m, &cVar_Hs0HkWxb_sendMessage);
}

void Heavy_SoundScraper::cReceive_RQkxS75Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fhES9jZ4, HV_BINOP_DIVIDE, 1, m, &cBinop_fhES9jZ4_sendMessage);
}

void Heavy_SoundScraper::cReceive_ed1ZXPQk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_z4JDc2PC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_tKFoZgd1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_33LyGD7p, 1, m, &cVar_33LyGD7p_sendMessage);
}

void Heavy_SoundScraper::cReceive_pwD37V0x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_1o4hL0k3, m);
}

void Heavy_SoundScraper::cReceive_UYoZ4LEK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_J98fEpZC, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_PHASE");
  cSlice_onMessage(_c, &Context(_c)->cSlice_N1UnJyZC, 0, m, &cSlice_N1UnJyZC_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_bJY6kOax, 0, m, &cSlice_bJY6kOax_sendMessage);
}

void Heavy_SoundScraper::cReceive_MU9CtXOL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_DrgcZC63, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_CUTOFF");
}

void Heavy_SoundScraper::cReceive_fUUemDKx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_30c6wUDh, 1, m, &cVar_30c6wUDh_sendMessage);
}

void Heavy_SoundScraper::cReceive_w374SGYK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MFMyfDm0, HV_BINOP_DIVIDE, 1, m, &cBinop_MFMyfDm0_sendMessage);
}

void Heavy_SoundScraper::cReceive_UzSVeQZO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_4UyJdzMf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_mTcEXrbq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CeR6OvLH, 1, m, &cVar_CeR6OvLH_sendMessage);
}

void Heavy_SoundScraper::cReceive_aT6SSRYd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Epq16a2o, m);
}

void Heavy_SoundScraper::cReceive_8p6suCTx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_3O2T0Ncj, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_PHASE");
  cSlice_onMessage(_c, &Context(_c)->cSlice_D77GWzkz, 0, m, &cSlice_D77GWzkz_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Lijy9Qfb, 0, m, &cSlice_Lijy9Qfb_sendMessage);
}

void Heavy_SoundScraper::cReceive_YI1OkFFM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_eAlBvMDj, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_CUTOFF");
}

void Heavy_SoundScraper::cReceive_7EebAh28_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xeXP7cvP, 0, m, &cVar_xeXP7cvP_sendMessage);
}

void Heavy_SoundScraper::cReceive_U5a6KK2m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MSQGYxlC_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1Kewn6PP_sendMessage);
}

void Heavy_SoundScraper::cReceive_d567VDRH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9hFb5Zei, 0, m, &cVar_9hFb5Zei_sendMessage);
}

void Heavy_SoundScraper::cReceive_xiKPPpdb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AWqOKYaQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JN3Y6eJL_sendMessage);
}

void Heavy_SoundScraper::cReceive_qkjeZqTp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_78zT3gJ5_sendMessage);
}

void Heavy_SoundScraper::cReceive_AI2JReoa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qH6JGXZw, 0, m, &cVar_qH6JGXZw_sendMessage);
}

void Heavy_SoundScraper::cReceive_8iVWwQQZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9JYP0BjF_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PilrNlYj_sendMessage);
}

void Heavy_SoundScraper::cReceive_jvY0hAW0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EVEb9CdE, 0, m, &cVar_EVEb9CdE_sendMessage);
}

void Heavy_SoundScraper::cReceive_zfBOUqGM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2CQ7UGPo_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GldCNZsI_sendMessage);
}

void Heavy_SoundScraper::cReceive_XcxYcXUV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_z1UlBdIJ, 0, m, &cSlice_z1UlBdIJ_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_SmS9GaGH, 0, m, &cSlice_SmS9GaGH_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_5C2HXS0B, 0, m, &cSlice_5C2HXS0B_sendMessage);
}

void Heavy_SoundScraper::cReceive_DMCzyIRi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SOUND_CHOICE");
  cSwitchcase_sm7ld76z_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_qIUgtov0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_2t2WULYO_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_QdTahO2g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CpbqemE4_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cAvRT3ov_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_ae3xyAfY, 0, m, &cPack_ae3xyAfY_sendMessage);
}

void Heavy_SoundScraper::cReceive_79wejaji_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5nR2Cy1w_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RvozrQJ1_sendMessage);
}

void Heavy_SoundScraper::cReceive_909wVkaQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_wMhQgIle_sendMessage);
}

void Heavy_SoundScraper::cReceive_Gbqetf5p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JLO0nmGt, 0, m, &cVar_JLO0nmGt_sendMessage);
}

void Heavy_SoundScraper::cReceive_HkBRXcJh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dGwyNLi3_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Kl719D7F_sendMessage);
}

void Heavy_SoundScraper::cReceive_HgZaT4cB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_UzC1bS57_sendMessage);
}

void Heavy_SoundScraper::cReceive_GCKL6sTs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dsnL65UT, HV_BINOP_SUBTRACT, 0, m, &cBinop_dsnL65UT_sendMessage);
}

void Heavy_SoundScraper::cReceive_OFHV3Wae_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_SHL6IFFO_sendMessage);
  cPrint_onMessage(_c, m, "SCRAPER_LEVEL");
  cVar_onMessage(_c, &Context(_c)->cVar_2h0Uh776, 0, m, &cVar_2h0Uh776_sendMessage);
}

void Heavy_SoundScraper::cReceive_1uJpXrOx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_WH21fbod, 0, m, &cSlice_WH21fbod_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_l1XFrSv9, 0, m, &cSlice_l1XFrSv9_sendMessage);
}

void Heavy_SoundScraper::cReceive_NMT6WM1H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4BzgW2Ok_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_K5wZbcJc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DAmTW3Wl_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pPBTZmE5_sendMessage);
}

void Heavy_SoundScraper::cReceive_LCvspGBQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.25f, 0, m, &cBinop_7oMwRnG5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_afF7thHS_sendMessage);
}

void Heavy_SoundScraper::cReceive_NrPJjStY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10.0f, 0, m, &cBinop_WRX4MsJe_sendMessage);
}

void Heavy_SoundScraper::cReceive_UnzLi4Sb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10.0f, 0, m, &cBinop_PeztPEIx_sendMessage);
}

void Heavy_SoundScraper::cReceive_r1xblk35_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SCRAPER_TRANSPOSITION");
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_PqeaNF9g_sendMessage);
}

void Heavy_SoundScraper::cReceive_RgdYQmKY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_E614orWO, 0, m, &cVar_E614orWO_sendMessage);
}

void Heavy_SoundScraper::cReceive_7t5fPbvs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kqgArgJ9_sendMessage(_c, 0, m);
  cSwitchcase_IBNPzuC4_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_wlK28fcT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lSJp93lF_sendMessage(_c, 0, m);
  cSwitchcase_CuSxWlwp_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_0LNExEPw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_5ldlAEfr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_32BwWPVb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ddeKu5Uy, 0, m, &cVar_ddeKu5Uy_sendMessage);
}

void Heavy_SoundScraper::cReceive_PNKBZpev_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cGw52fC2, 0, m, &cVar_cGw52fC2_sendMessage);
}

void Heavy_SoundScraper::cReceive_1Ryv7W5c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2WZJIx2x, 0, m, &cVar_2WZJIx2x_sendMessage);
}

void Heavy_SoundScraper::cReceive_eBfzSXPm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0F15r7sN_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8wtpw67V_sendMessage);
}

void Heavy_SoundScraper::cReceive_9EnESZLv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_MU47EpYE, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_cHg7e1FU, m);
}

void Heavy_SoundScraper::cReceive_L3U17zaA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xcKnWpSn, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_3u58kmUr, m);
}

void Heavy_SoundScraper::cReceive_aQfICTuo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6wlHyB4j_sendMessage(_c, 0, m);
  cMsg_fqEFix0y_sendMessage(_c, 0, m);
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
    __hv_varread_f(&sVarf_d5Xdc7XF, VOf(Bf0));
    __hv_varread_f(&sVarf_FnCQzVKY, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_XqbHAxnG, VOf(Bf0));
    __hv_rpole_f(&sRPole_REAcZgxD, VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_MU47EpYE, VOf(Bf1));
    __hv_varread_f(&sVarf_naTSwdir, VOf(Bf2));
    __hv_del1_f(&sDel1_avNgKOko, VIf(Bf2), VOf(Bf3));
    __hv_lt_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_samphold_f(&sSamphold_hf0BVFEO, VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_naTSwdir, VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fma_f(VIf(Bf3), VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_xcKnWpSn, VOf(Bf1));
    __hv_varread_f(&sVarf_naTSwdir, VOf(Bf3));
    __hv_del1_f(&sDel1_RL9EkALw, VIf(Bf3), VOf(Bf4));
    __hv_lt_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_samphold_f(&sSamphold_TteAZqk8, VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_uukg2iBw, VOf(Bf2));
    __hv_min_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf4));
    __hv_max_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf2));
    __hv_cast_fi(VIf(Bf2), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_vlLQy8ak, VIi(Bi1), VOf(Bf1));
    __hv_tabread_if(&sTabread_FyKFdTX9, VIi(Bi0), VOf(Bf3));
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf1));
    __hv_sub_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf1), VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_naTSwdir, VOf(Bf2));
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
    __hv_varread_f(&sVarf_cHg7e1FU, VOf(Bf7));
    __hv_varread_f(&sVarf_l9AsDQq5, VOf(Bf1));
    __hv_del1_f(&sDel1_A5hV73wu, VIf(Bf1), VOf(Bf9));
    __hv_lt_f(VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_samphold_f(&sSamphold_qxYIEFRl, VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_l9AsDQq5, VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fma_f(VIf(Bf9), VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_3u58kmUr, VOf(Bf7));
    __hv_varread_f(&sVarf_l9AsDQq5, VOf(Bf9));
    __hv_del1_f(&sDel1_OXmCLyAF, VIf(Bf9), VOf(Bf6));
    __hv_lt_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_samphold_f(&sSamphold_BLB5TwRn, VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_pATykqdu, VOf(Bf1));
    __hv_min_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_zero_f(VOf(Bf6));
    __hv_max_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_floor_f(VIf(Bf6), VOf(Bf1));
    __hv_cast_fi(VIf(Bf1), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_hIGy1oJE, VIi(Bi1), VOf(Bf7));
    __hv_tabread_if(&sTabread_kT3lBcar, VIi(Bi0), VOf(Bf9));
    __hv_sub_f(VIf(Bf7), VIf(Bf9), VOf(Bf7));
    __hv_sub_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf7), VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_l9AsDQq5, VOf(Bf1));
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
    __hv_phasor_k_f(&sPhasor_T8DireCs, VOf(Bf8));
    __hv_varwrite_f(&sVarf_naTSwdir, VIf(Bf8));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf8));
    __hv_sub_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_varwrite_f(&sVarf_l9AsDQq5, VIf(Bf8));
    __hv_varread_f(&sVarf_sY7TkwYC, VOf(Bf8));
    __hv_rpole_f(&sRPole_MufGthIR, VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf10), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_Zc6uPlfW, VIf(Bf8), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_969N79dX, VOf(Bf8));
    __hv_mul_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_eQmLPtLE, VOf(Bf0));
    __hv_mul_f(VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_sample_f(this, &sSample_qfX4NsAm, VIf(Bf8), &sSample_qfX4NsAm_sendMessage);
    __hv_line_f(&sLine_nWA9yvBT, VOf(Bf8));
    __hv_varread_f(&sVarf_3GiXktsj, VOf(Bf10));
    __hv_min_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_zero_f(VOf(Bf8));
    __hv_max_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_JJz0K9bS, VIi(Bi1), VOf(Bf3));
    __hv_tabread_if(&sTabread_yxf0z2nC, VIi(Bi0), VOf(Bf9));
    __hv_sub_f(VIf(Bf3), VIf(Bf9), VOf(Bf3));
    __hv_sub_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf3), VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_pQCPywbP, VOf(Bf10));
    __hv_mul_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_ndtWHWbl, VOf(Bf9));
    __hv_varread_f(&sVarf_S3c4S773, VOf(Bf3));
    __hv_mul_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_G6aTEmZn, VOf(Bf10));
    __hv_mul_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_Pde39p7Q, VOf(Bf9));
    __hv_mul_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_Axs38sYp, VOf(Bf3));
    __hv_varread_f(&sVarf_rbJ6mJMu, VOf(Bf8));
    __hv_min_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf8));
    __hv_cast_fi(VIf(Bf8), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_7mvICwz4, VIi(Bi1), VOf(Bf4));
    __hv_tabread_if(&sTabread_Cp63gcdE, VIi(Bi0), VOf(Bf7));
    __hv_sub_f(VIf(Bf4), VIf(Bf7), VOf(Bf4));
    __hv_sub_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf4), VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_xg7MmMDM, VOf(Bf8));
    __hv_mul_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_syzJTS98, VOf(Bf7));
    __hv_varread_f(&sVarf_JmtFakDs, VOf(Bf4));
    __hv_mul_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_i1ex9pJ7, VOf(Bf8));
    __hv_mul_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_T6Mlz6Y1, VOf(Bf7));
    __hv_mul_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_J98fEpZC, VOf(Bf10));
    __hv_varread_f(&sVarf_TdIqQIuP, VOf(Bf4));
    __hv_min_f(VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf10));
    __hv_max_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf4));
    __hv_cast_fi(VIf(Bf4), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_PWZ9B5X7, VIi(Bi1), VOf(Bf3));
    __hv_tabread_if(&sTabread_FxOjctYX, VIi(Bi0), VOf(Bf11));
    __hv_sub_f(VIf(Bf3), VIf(Bf11), VOf(Bf3));
    __hv_sub_f(VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf3), VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_DrgcZC63, VOf(Bf4));
    __hv_mul_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_rGxkbxrG, VOf(Bf11));
    __hv_varread_f(&sVarf_1o4hL0k3, VOf(Bf3));
    __hv_mul_f(VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_s7IGP6lo, VOf(Bf4));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_NpAvF5mi, VOf(Bf11));
    __hv_mul_f(VIf(Bf3), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_3O2T0Ncj, VOf(Bf8));
    __hv_varread_f(&sVarf_e7japoAN, VOf(Bf3));
    __hv_min_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf8));
    __hv_max_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf3));
    __hv_cast_fi(VIf(Bf3), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_2AsUebY9, VIi(Bi1), VOf(Bf10));
    __hv_tabread_if(&sTabread_ZjauuE5S, VIi(Bi0), VOf(Bf2));
    __hv_sub_f(VIf(Bf10), VIf(Bf2), VOf(Bf10));
    __hv_sub_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf10), VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_eAlBvMDj, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_BjQp1kDM, VOf(Bf2));
    __hv_varread_f(&sVarf_Epq16a2o, VOf(Bf10));
    __hv_mul_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_cYlxwKAd, VOf(Bf3));
    __hv_mul_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_TZ8DWVp5, VOf(Bf2));
    __hv_mul_f(VIf(Bf10), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_MssnHypt, VOf(Bf11));
    __hv_mul_f(VIf(Bf3), VIf(Bf11), VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_PaEhWcRP, VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf0));
    __hv_add_f(VIf(Bf11), VIf(Bf2), VOf(Bf11));
    __hv_line_f(&sLine_PRxRrdbY, VOf(Bf7));
    __hv_mul_f(VIf(Bf0), VIf(Bf7), VOf(Bf0));
    __hv_mul_f(VIf(Bf11), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_x4oiRlkn, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_p63Cfj8k, VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_4DVarWqT, VIf(Bf2));
    __hv_line_f(&sLine_7uXeASB6, VOf(Bf2));
    __hv_phasor_f(&sPhasor_8KsYNpbH, VIf(Bf2), VOf(Bf2));
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
    __hv_line_f(&sLine_mvZgh5qa, VOf(Bf5));
    __hv_line_f(&sLine_IZW5pwvx, VOf(Bf11));
    __hv_fma_f(VIf(Bf2), VIf(Bf5), VIf(Bf11), VOf(Bf6));
    __hv_tabhead_f(&sTabhead_BZYRnMpg, VOf(Bf8));
    __hv_var_k_f_r(VOf(Bf10), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_8irt6XdM, VOf(Bf8));
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_iN3OEegO, VOf(Bf6));
    __hv_min_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_zero_f(VOf(Bf8));
    __hv_max_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf10));
    __hv_varread_f(&sVarf_GcZzNGCY, VOf(Bf6));
    __hv_zero_f(VOf(Bf9));
    __hv_lt_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_and_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_cast_fi(VIf(Bf9), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_s7W01vuN, VIi(Bi1), VOf(Bf9));
    __hv_tabread_if(&sTabread_pqjSVmB0, VIi(Bi0), VOf(Bf6));
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
    __hv_tabhead_f(&sTabhead_yzKWSgUW, VOf(Bf5));
    __hv_var_k_f_r(VOf(Bf2), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_OuHCKlac, VOf(Bf5));
    __hv_mul_f(VIf(Bf11), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_VRpEdLyn, VOf(Bf11));
    __hv_min_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_zero_f(VOf(Bf5));
    __hv_max_f(VIf(Bf11), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf2));
    __hv_varread_f(&sVarf_NYS8uaw0, VOf(Bf11));
    __hv_zero_f(VOf(Bf13));
    __hv_lt_f(VIf(Bf2), VIf(Bf13), VOf(Bf13));
    __hv_and_f(VIf(Bf11), VIf(Bf13), VOf(Bf13));
    __hv_add_f(VIf(Bf2), VIf(Bf13), VOf(Bf13));
    __hv_cast_fi(VIf(Bf13), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_s3nT7gy6, VIi(Bi1), VOf(Bf13));
    __hv_tabread_if(&sTabread_peDIxRAT, VIi(Bi0), VOf(Bf11));
    __hv_sub_f(VIf(Bf13), VIf(Bf11), VOf(Bf13));
    __hv_sub_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf13), VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf14), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf1), VIf(Bf6), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_IKss2HMD, VOf(Bf6));
    __hv_tabhead_f(&sTabhead_SaDABZLJ, VOf(Bf1));
    __hv_var_k_f_r(VOf(Bf14), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_4ULtgp3v, VOf(Bf1));
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_0jirQ8Dl, VOf(Bf6));
    __hv_min_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf14), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf14));
    __hv_varread_f(&sVarf_JJwa1h1d, VOf(Bf6));
    __hv_zero_f(VOf(Bf2));
    __hv_lt_f(VIf(Bf14), VIf(Bf2), VOf(Bf2));
    __hv_and_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf14), VIf(Bf2), VOf(Bf2));
    __hv_cast_fi(VIf(Bf2), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_uoQScs8E, VIi(Bi1), VOf(Bf2));
    __hv_tabread_if(&sTabread_XYdqXMwo, VIi(Bi0), VOf(Bf6));
    __hv_sub_f(VIf(Bf2), VIf(Bf6), VOf(Bf2));
    __hv_sub_f(VIf(Bf1), VIf(Bf14), VOf(Bf14));
    __hv_fma_f(VIf(Bf2), VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_nNRbulIl, VOf(Bf14));
    __hv_rpole_f(&sRPole_rY855utR, VIf(Bf6), VIf(Bf14), VOf(Bf14));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_9SRWdW4j, VIf(Bf14), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_rgnkoBBl, VOf(Bf14));
    __hv_mul_f(VIf(Bf6), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_SRHqRpj8, VOf(Bf6));
    __hv_mul_f(VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf11), VIf(Bf6), VOf(Bf14));
    __hv_line_f(&sLine_ElWsOhlv, VOf(Bf2));
    __hv_varread_f(&sVarf_gfRmyWQe, VOf(Bf1));
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_764QpYzG, VOf(Bf6));
    __hv_rpole_f(&sRPole_PV2KiYum, VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf11), VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_RP7IA2je, VIf(Bf6));
    __hv_var_k_f(VOf(Bf6), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_tabread_f(&sTabread_LGsOmfpX, VOf(Bf14));
    __hv_varread_f(&sVarf_bVMYZ015, VOf(Bf2));
    __hv_mul_f(VIf(Bf14), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_E868jMd7, VOf(Bf11));
    __hv_rpole_f(&sRPole_TVXdpm1d, VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf11), VIf(Bf14), VOf(Bf11));
    __hv_line_f(&sLine_5MJun8Bl, VOf(Bf2));
    __hv_fma_f(VIf(Bf11), VIf(Bf2), VIf(Bf14), VOf(Bf14));
    __hv_line_f(&sLine_PiBRAEvF, VOf(Bf11));
    __hv_tabread_f(&sTabread_6kNivzLP, VOf(Bf1));
    __hv_add_f(VIf(Bf3), VIf(Bf1), VOf(Bf13));
    __hv_tabread_f(&sTabread_hGu1xi2l, VOf(Bf5));
    __hv_add_f(VIf(Bf13), VIf(Bf5), VOf(Bf10));
    __hv_tabread_f(&sTabread_3EAeJgdk, VOf(Bf15));
    __hv_add_f(VIf(Bf10), VIf(Bf15), VOf(Bf12));
    __hv_tabread_f(&sTabread_sCROyNou, VOf(Bf4));
    __hv_add_f(VIf(Bf12), VIf(Bf4), VOf(Bf9));
    __hv_tabread_f(&sTabread_NPayNecx, VOf(Bf8));
    __hv_sub_f(VIf(Bf9), VIf(Bf8), VOf(Bf16));
    __hv_tabwrite_f(&sTabwrite_VH2XTCj3, VIf(Bf16));
    __hv_sub_f(VIf(Bf12), VIf(Bf4), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_zIZH708J, VIf(Bf4));
    __hv_sub_f(VIf(Bf10), VIf(Bf15), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_tR4UuY3m, VIf(Bf15));
    __hv_sub_f(VIf(Bf13), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_QbsSxHTs, VIf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_tabwrite_f(&sTabwrite_m9Hu7Ufg, VIf(Bf1));
    __hv_tabwrite_f(&sTabwrite_Ne0UkebX, VIf(Bf3));
    __hv_add_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_tabread_f(&sTabread_fti8cOzu, VOf(Bf9));
    __hv_fma_f(VIf(Bf14), VIf(Bf11), VIf(Bf8), VOf(Bf8));
    __hv_tabread_f(&sTabread_qYxCSyOB, VOf(Bf14));
    __hv_varread_f(&sVarf_1b2ZvpmZ, VOf(Bf1));
    __hv_mul_f(VIf(Bf14), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_xUkq45e0, VOf(Bf5));
    __hv_rpole_f(&sRPole_s7e3w0aj, VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf5), VIf(Bf14), VOf(Bf5));
    __hv_fma_f(VIf(Bf5), VIf(Bf2), VIf(Bf14), VOf(Bf14));
    __hv_fma_f(VIf(Bf14), VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf8), VIf(Bf9), VOf(Bf14));
    __hv_tabread_f(&sTabread_24YroOvM, VOf(Bf5));
    __hv_varread_f(&sVarf_Cnyv8C4m, VOf(Bf1));
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_PrO89gA7, VOf(Bf13));
    __hv_rpole_f(&sRPole_gO6OFOva, VIf(Bf1), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf13), VIf(Bf5), VOf(Bf13));
    __hv_fma_f(VIf(Bf13), VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf5));
    __hv_tabread_f(&sTabread_dBcW5fTF, VOf(Bf13));
    __hv_varread_f(&sVarf_0bVHqkST, VOf(Bf1));
    __hv_mul_f(VIf(Bf13), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_uGnRSPLb, VOf(Bf15));
    __hv_rpole_f(&sRPole_kVZ8FxZB, VIf(Bf1), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf15), VIf(Bf13), VOf(Bf15));
    __hv_fma_f(VIf(Bf15), VIf(Bf2), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf5), VIf(Bf11), VOf(Bf13));
    __hv_add_f(VIf(Bf14), VIf(Bf13), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_4smFJoMr, VIf(Bf2));
    __hv_sub_f(VIf(Bf8), VIf(Bf9), VOf(Bf2));
    __hv_sub_f(VIf(Bf5), VIf(Bf11), VOf(Bf15));
    __hv_add_f(VIf(Bf2), VIf(Bf15), VOf(Bf1));
    __hv_tabwrite_f(&sTabwrite_5icomM8V, VIf(Bf1));
    __hv_sub_f(VIf(Bf14), VIf(Bf13), VOf(Bf13));
    __hv_tabwrite_f(&sTabwrite_9EGvsKhJ, VIf(Bf13));
    __hv_sub_f(VIf(Bf2), VIf(Bf15), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_J5jbD6iy, VIf(Bf15));
    __hv_line_f(&sLine_s8PbC4XD, VOf(Bf15));
    __hv_mul_f(VIf(Bf8), VIf(Bf15), VOf(Bf8));
    __hv_mul_f(VIf(Bf9), VIf(Bf15), VOf(Bf9));
    __hv_mul_f(VIf(Bf5), VIf(Bf15), VOf(Bf5));
    __hv_mul_f(VIf(Bf11), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_E9hKNxIE, VOf(Bf15));
    __hv_mul_f(VIf(Bf3), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf3), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_jOiTAEpf, VIf(Bf3));
    __hv_line_f(&sLine_vkHwMN4p, VOf(Bf15));
    __hv_phasor_f(&sPhasor_jF0OvVa4, VIf(Bf15), VOf(Bf15));
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
    __hv_line_f(&sLine_SIcupqdZ, VOf(Bf1));
    __hv_line_f(&sLine_pmOERWvQ, VOf(Bf5));
    __hv_fma_f(VIf(Bf15), VIf(Bf1), VIf(Bf5), VOf(Bf4));
    __hv_tabhead_f(&sTabhead_G1KgJpKX, VOf(Bf14));
    __hv_var_k_f_r(VOf(Bf13), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf14), VIf(Bf13), VOf(Bf13));
    __hv_varread_f(&sVarf_mKbyEBUK, VOf(Bf14));
    __hv_mul_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_hJwc8Iw8, VOf(Bf4));
    __hv_min_f(VIf(Bf14), VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf14));
    __hv_max_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_sub_f(VIf(Bf13), VIf(Bf14), VOf(Bf14));
    __hv_floor_f(VIf(Bf14), VOf(Bf13));
    __hv_varread_f(&sVarf_N52pBKt9, VOf(Bf4));
    __hv_zero_f(VOf(Bf11));
    __hv_lt_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_and_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_cast_fi(VIf(Bf11), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_6ytYgQwh, VIi(Bi1), VOf(Bf11));
    __hv_tabread_if(&sTabread_E4c43C1S, VIi(Bi0), VOf(Bf4));
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
    __hv_tabhead_f(&sTabhead_WFXibZey, VOf(Bf1));
    __hv_var_k_f_r(VOf(Bf15), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_lyyP7vsQ, VOf(Bf1));
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_7p2f9ozt, VOf(Bf5));
    __hv_min_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf15), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf15));
    __hv_varread_f(&sVarf_BzDZDqFR, VOf(Bf5));
    __hv_zero_f(VOf(Bf16));
    __hv_lt_f(VIf(Bf15), VIf(Bf16), VOf(Bf16));
    __hv_and_f(VIf(Bf5), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf15), VIf(Bf16), VOf(Bf16));
    __hv_cast_fi(VIf(Bf16), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_RPmj098s, VIi(Bi1), VOf(Bf16));
    __hv_tabread_if(&sTabread_moUeHUQI, VIi(Bi0), VOf(Bf5));
    __hv_sub_f(VIf(Bf16), VIf(Bf5), VOf(Bf16));
    __hv_sub_f(VIf(Bf1), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf16), VIf(Bf15), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf10), VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_Gr1RpTtY, VOf(Bf4));
    __hv_tabhead_f(&sTabhead_dzH0u6Xx, VOf(Bf10));
    __hv_var_k_f_r(VOf(Bf17), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf10), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_tEtfpbec, VOf(Bf10));
    __hv_mul_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_YIKpyQZw, VOf(Bf4));
    __hv_min_f(VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf10));
    __hv_max_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf17), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf17));
    __hv_varread_f(&sVarf_4L4Lh9BM, VOf(Bf4));
    __hv_zero_f(VOf(Bf15));
    __hv_lt_f(VIf(Bf17), VIf(Bf15), VOf(Bf15));
    __hv_and_f(VIf(Bf4), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf17), VIf(Bf15), VOf(Bf15));
    __hv_cast_fi(VIf(Bf15), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_DF3ezimX, VIi(Bi1), VOf(Bf15));
    __hv_tabread_if(&sTabread_NyGZOKyS, VIi(Bi0), VOf(Bf4));
    __hv_sub_f(VIf(Bf15), VIf(Bf4), VOf(Bf15));
    __hv_sub_f(VIf(Bf10), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf15), VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_XslEbU7V, VOf(Bf17));
    __hv_rpole_f(&sRPole_JLMV3aYr, VIf(Bf4), VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_wKJnijnu, VIf(Bf17), VOf(Bf15));
    __hv_mul_f(VIf(Bf15), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_AnH1cdIn, VOf(Bf17));
    __hv_mul_f(VIf(Bf4), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_X3efWxy3, VOf(Bf4));
    __hv_mul_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf5), VIf(Bf4), VOf(Bf17));
    __hv_line_f(&sLine_2r9cKhjn, VOf(Bf15));
    __hv_varread_f(&sVarf_zNW0KTUv, VOf(Bf10));
    __hv_mul_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_D3Mcg0iI, VOf(Bf4));
    __hv_rpole_f(&sRPole_XTJXlNXz, VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf5), VIf(Bf15), VIf(Bf4), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_dOrcyMDJ, VIf(Bf4));
    __hv_add_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_mxCDPLDB, VOf(Bf17));
    __hv_varread_f(&sVarf_BD6qXRGY, VOf(Bf4));
    __hv_mul_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf17), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf4), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_F2X9ObRM, VOf(Bf4));
    __hv_min_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_LEK9L4BP, VOf(Bf15));
    __hv_mul_f(VIf(Bf4), VIf(Bf15), VOf(Bf15));
    __hv_mul_f(VIf(Bf3), VIf(Bf15), VOf(Bf3));
    __hv_varread_f(&sVarf_FGL19iji, VOf(Bf4));
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
    __hv_cpole_f(&sCPole_H0z1qwZ0, VIf(Bf4), VIf(ZERO), VIf(Bf5), VIf(Bf17), VOf(Bf17), VOf(Bf5));
    __hv_varread_f(&sVarf_jUTLBWjZ, VOf(Bf5));
    __hv_mul_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_1IoVrxsD, VOf(Bf17));
    __hv_rpole_f(&sRPole_G0ySlggy, VIf(Bf5), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_BDCf0aA3, VOf(Bf5));
    __hv_mul_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_zzn1Axzn, VOf(Bf17));
    __hv_rpole_f(&sRPole_kjacatx3, VIf(Bf5), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_j7Zs79ku, VOf(Bf5));
    __hv_mul_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_4O86NrNp, VOf(Bf17));
    __hv_rpole_f(&sRPole_Wczuv1cu, VIf(Bf5), VIf(Bf17), VOf(Bf17));
    __hv_tabread_f(&sTabread_wGHbTAlV, VOf(Bf5));
    __hv_varread_f(&sVarf_M5iGRofl, VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_nrO3sP4M, VOf(Bf15));
    __hv_rpole_f(&sRPole_RAyFq0yv, VIf(Bf4), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf15), VIf(Bf5), VOf(Bf15));
    __hv_line_f(&sLine_tOzwtFMn, VOf(Bf4));
    __hv_fma_f(VIf(Bf15), VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_tgclqmTa, VOf(Bf15));
    __hv_tabread_f(&sTabread_GOaCxfn8, VOf(Bf3));
    __hv_add_f(VIf(Bf17), VIf(Bf3), VOf(Bf10));
    __hv_tabread_f(&sTabread_16qKnAjk, VOf(Bf16));
    __hv_add_f(VIf(Bf10), VIf(Bf16), VOf(Bf1));
    __hv_tabread_f(&sTabread_p95TiwPm, VOf(Bf13));
    __hv_add_f(VIf(Bf1), VIf(Bf13), VOf(Bf18));
    __hv_tabread_f(&sTabread_CbgqKfNV, VOf(Bf12));
    __hv_add_f(VIf(Bf18), VIf(Bf12), VOf(Bf2));
    __hv_tabread_f(&sTabread_LRFqKfxm, VOf(Bf11));
    __hv_sub_f(VIf(Bf2), VIf(Bf11), VOf(Bf14));
    __hv_tabwrite_f(&sTabwrite_GMUK5TX5, VIf(Bf14));
    __hv_sub_f(VIf(Bf18), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_juL3lEB7, VIf(Bf12));
    __hv_sub_f(VIf(Bf1), VIf(Bf13), VOf(Bf13));
    __hv_tabwrite_f(&sTabwrite_f1CCwUY8, VIf(Bf13));
    __hv_sub_f(VIf(Bf10), VIf(Bf16), VOf(Bf16));
    __hv_tabwrite_f(&sTabwrite_Nhj3k8sX, VIf(Bf16));
    __hv_sub_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_qHgNkAEQ, VIf(Bf3));
    __hv_tabwrite_f(&sTabwrite_cOTmnE8q, VIf(Bf17));
    __hv_add_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_tabread_f(&sTabread_jYEApCTm, VOf(Bf2));
    __hv_fma_f(VIf(Bf5), VIf(Bf15), VIf(Bf11), VOf(Bf11));
    __hv_tabread_f(&sTabread_eLOXIhvE, VOf(Bf5));
    __hv_varread_f(&sVarf_iPqSFKzE, VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_JL28iLCy, VOf(Bf16));
    __hv_rpole_f(&sRPole_AhKY22qB, VIf(Bf3), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf16), VIf(Bf5), VOf(Bf16));
    __hv_fma_f(VIf(Bf16), VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf5), VIf(Bf15), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf11), VIf(Bf2), VOf(Bf5));
    __hv_tabread_f(&sTabread_9w7FF8pZ, VOf(Bf16));
    __hv_varread_f(&sVarf_wyZQYuip, VOf(Bf3));
    __hv_mul_f(VIf(Bf16), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_PX9sAeJU, VOf(Bf10));
    __hv_rpole_f(&sRPole_rpxWkhf9, VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf10), VIf(Bf16), VOf(Bf10));
    __hv_fma_f(VIf(Bf10), VIf(Bf4), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf15), VOf(Bf16));
    __hv_tabread_f(&sTabread_EcvHPTpu, VOf(Bf10));
    __hv_varread_f(&sVarf_4q5MYVHv, VOf(Bf3));
    __hv_mul_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_254jGMzq, VOf(Bf13));
    __hv_rpole_f(&sRPole_EPGSRd45, VIf(Bf3), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf13), VIf(Bf10), VOf(Bf13));
    __hv_fma_f(VIf(Bf13), VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf16), VIf(Bf15), VOf(Bf10));
    __hv_add_f(VIf(Bf5), VIf(Bf10), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_jwRTTVc7, VIf(Bf4));
    __hv_sub_f(VIf(Bf11), VIf(Bf2), VOf(Bf4));
    __hv_sub_f(VIf(Bf16), VIf(Bf15), VOf(Bf13));
    __hv_add_f(VIf(Bf4), VIf(Bf13), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_V6dDYAF7, VIf(Bf3));
    __hv_sub_f(VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_tabwrite_f(&sTabwrite_RHL8PbPg, VIf(Bf10));
    __hv_sub_f(VIf(Bf4), VIf(Bf13), VOf(Bf13));
    __hv_tabwrite_f(&sTabwrite_Udjy761d, VIf(Bf13));
    __hv_line_f(&sLine_6FwER0B6, VOf(Bf13));
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
    __hv_line_f(&sLine_DhZXQLQd, VOf(Bf9));
    __hv_mul_f(VIf(Bf8), VIf(Bf9), VOf(Bf8));
    __hv_mul_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_vYEOsQ6y, VOf(Bf7));
    __hv_mul_f(VIf(Bf8), VIf(Bf7), VOf(Bf8));
    __hv_mul_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf8), VIf(O0), VOf(O0));
    __hv_add_f(VIf(Bf7), VIf(O1), VOf(O1));

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

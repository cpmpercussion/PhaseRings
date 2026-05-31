/** Copyright (c) 2026 Charles Martin. Generated from Pure Data by hvcc (https://github.com/Wasted-Audio/hvcc). */

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
  numBytes += sTabread_init(&sTabread_7N4SehJC, &hTable_T2Zb4m8z, true);
  numBytes += sRPole_init(&sRPole_PoigosCf);
  numBytes += sLine_init(&sLine_91isat8C);
  numBytes += sTabwrite_init(&sTabwrite_xCDJfxaQ, &hTable_T2Zb4m8z);
  numBytes += sLine_init(&sLine_5IIrk8lH);
  numBytes += sLine_init(&sLine_VHBfW4AP);
  numBytes += sLine_init(&sLine_ZjyvyVY3);
  numBytes += sPhasor_k_init(&sPhasor_NlYSr6l6, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_pmYKKTqj);
  numBytes += sTabread_init(&sTabread_Kjfh628Y, &hTable_NOntZksZ, true);
  numBytes += sRPole_init(&sRPole_Gg6je7Bc);
  numBytes += sLine_init(&sLine_mkFuhsgQ);
  numBytes += sTabwrite_init(&sTabwrite_2V2BIoAi, &hTable_NOntZksZ);
  numBytes += sLine_init(&sLine_VS2mA4YT);
  numBytes += sLine_init(&sLine_fdPKu1sh);
  numBytes += sLine_init(&sLine_R1nVLPdz);
  numBytes += sPhasor_k_init(&sPhasor_VjKLOCtv, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_WxJtWyuZ);
  numBytes += sTabread_init(&sTabread_qQIVIWrm, &hTable_U4YYujfG, true);
  numBytes += sRPole_init(&sRPole_M3SExIU8);
  numBytes += sLine_init(&sLine_1tzHbdLI);
  numBytes += sTabwrite_init(&sTabwrite_T5eZQDmB, &hTable_U4YYujfG);
  numBytes += sLine_init(&sLine_WyjyMzUx);
  numBytes += sLine_init(&sLine_qoFQk9Jd);
  numBytes += sLine_init(&sLine_VxaDnpNz);
  numBytes += sPhasor_k_init(&sPhasor_UlKuPlOy, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_4dIOp7T2);
  numBytes += sTabread_init(&sTabread_3bM6auom, &hTable_jbRSuQoA, true);
  numBytes += sRPole_init(&sRPole_FoMmBXiN);
  numBytes += sLine_init(&sLine_dL33Nybz);
  numBytes += sTabwrite_init(&sTabwrite_wmtdAQf5, &hTable_jbRSuQoA);
  numBytes += sLine_init(&sLine_DSKpEbr9);
  numBytes += sLine_init(&sLine_aInKJIke);
  numBytes += sLine_init(&sLine_wM9hMYAQ);
  numBytes += sPhasor_k_init(&sPhasor_L14MNyBC, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_hVhjyV3v);
  numBytes += sLine_init(&sLine_zYCBhSzM);
  numBytes += sTabread_init(&sTabread_HDwvRVpY, &hTable_3VwDfFas, true);
  numBytes += sRPole_init(&sRPole_D3MD5a4Q);
  numBytes += sLine_init(&sLine_5roWFc9V);
  numBytes += sTabwrite_init(&sTabwrite_zwygWby1, &hTable_3VwDfFas);
  numBytes += sLine_init(&sLine_Y6DRCJ34);
  numBytes += sLine_init(&sLine_K8cYsBc9);
  numBytes += sRPole_init(&sRPole_fCSILDJM);
  numBytes += sDel1_init(&sDel1_CT7N50Ur);
  numBytes += sLine_init(&sLine_nv8148p4);
  numBytes += sLine_init(&sLine_0wjPaWHA);
  numBytes += sLine_init(&sLine_YXSnrxI5);
  numBytes += sTabread_init(&sTabread_x9m4h6ZG, &hTable_tF72jLxD, true);
  numBytes += sRPole_init(&sRPole_aFxXMpGj);
  numBytes += sLine_init(&sLine_cdJCmkYF);
  numBytes += sLine_init(&sLine_5UP2AEDg);
  numBytes += sTabread_init(&sTabread_vnSavNzS, &hTable_dLmHrCPa, true);
  numBytes += sTabread_init(&sTabread_7HAQFNy7, &hTable_5tceBofY, true);
  numBytes += sTabread_init(&sTabread_ADJ4E8Aa, &hTable_SA4QtDyC, true);
  numBytes += sTabread_init(&sTabread_z6exZkKw, &hTable_1d9Pk3Lj, true);
  numBytes += sTabread_init(&sTabread_ewlwumIS, &hTable_PeXzR7Y8, true);
  numBytes += sTabwrite_init(&sTabwrite_SJUWITpc, &hTable_7eTEkNjZ);
  numBytes += sTabwrite_init(&sTabwrite_cgdHBny3, &hTable_PeXzR7Y8);
  numBytes += sTabwrite_init(&sTabwrite_Ly4JY4Uz, &hTable_1d9Pk3Lj);
  numBytes += sTabwrite_init(&sTabwrite_3K4y4xq5, &hTable_SA4QtDyC);
  numBytes += sTabwrite_init(&sTabwrite_lhnEtGVC, &hTable_5tceBofY);
  numBytes += sTabwrite_init(&sTabwrite_qTcizVOy, &hTable_dLmHrCPa);
  numBytes += sTabread_init(&sTabread_kg18CcEz, &hTable_7eTEkNjZ, true);
  numBytes += sTabread_init(&sTabread_dtVPkZAP, &hTable_7nrSdsCY, true);
  numBytes += sRPole_init(&sRPole_okwJBq88);
  numBytes += sTabread_init(&sTabread_PZfknumT, &hTable_J6L0k6K1, true);
  numBytes += sRPole_init(&sRPole_K4FwHGiP);
  numBytes += sTabread_init(&sTabread_Ir64mdiY, &hTable_P2MvgdzR, true);
  numBytes += sRPole_init(&sRPole_ELI6Lo8B);
  numBytes += sTabwrite_init(&sTabwrite_yOCoPsi8, &hTable_tF72jLxD);
  numBytes += sTabwrite_init(&sTabwrite_EFIjaKYf, &hTable_7nrSdsCY);
  numBytes += sTabwrite_init(&sTabwrite_zrqCHOpG, &hTable_J6L0k6K1);
  numBytes += sTabwrite_init(&sTabwrite_P1eCsL7Y, &hTable_P2MvgdzR);
  numBytes += sLine_init(&sLine_tQYMYoyu);
  numBytes += sLine_init(&sLine_vDMXpyZL);
  numBytes += sTabwrite_init(&sTabwrite_l2RShlhk, &hTable_7pd6l9l0);
  numBytes += sLine_init(&sLine_q51XVYIe);
  numBytes += sPhasor_init(&sPhasor_O5xBFFkj, sampleRate);
  numBytes += sLine_init(&sLine_VtQlkvAg);
  numBytes += sLine_init(&sLine_bhZshD8N);
  numBytes += sTabhead_init(&sTabhead_nxQIOlhB, &hTable_7pd6l9l0);
  numBytes += sTabread_init(&sTabread_nXMVYqam, &hTable_7pd6l9l0, false);
  numBytes += sTabread_init(&sTabread_dhFQspfN, &hTable_7pd6l9l0, false);
  numBytes += sTabhead_init(&sTabhead_yVOVKgFw, &hTable_7pd6l9l0);
  numBytes += sTabread_init(&sTabread_WhmpX0JY, &hTable_7pd6l9l0, false);
  numBytes += sTabread_init(&sTabread_RcoxPOyx, &hTable_7pd6l9l0, false);
  numBytes += sTabhead_init(&sTabhead_tv6KhYZr, &hTable_gluxEKKN);
  numBytes += sTabread_init(&sTabread_sVLNPpbo, &hTable_gluxEKKN, false);
  numBytes += sTabread_init(&sTabread_mxYI7Bwi, &hTable_gluxEKKN, false);
  numBytes += sRPole_init(&sRPole_X0gd5Ajk);
  numBytes += sDel1_init(&sDel1_rANjZi1C);
  numBytes += sLine_init(&sLine_PFx9aq9R);
  numBytes += sRPole_init(&sRPole_zbaAkQ0T);
  numBytes += sTabwrite_init(&sTabwrite_RZS08580, &hTable_gluxEKKN);
  numBytes += sCPole_init(&sCPole_XuStt4Ms);
  numBytes += sRPole_init(&sRPole_JcrsE2nf);
  numBytes += sRPole_init(&sRPole_zNTtIrtc);
  numBytes += sRPole_init(&sRPole_dRdrEHnN);
  numBytes += sTabread_init(&sTabread_2mcQ7TTy, &hTable_H2niNe6T, true);
  numBytes += sRPole_init(&sRPole_fOkSROBP);
  numBytes += sLine_init(&sLine_rUnCkvbJ);
  numBytes += sLine_init(&sLine_OZl8cLDT);
  numBytes += sTabread_init(&sTabread_r3wDWdW9, &hTable_GPApmXrg, true);
  numBytes += sTabread_init(&sTabread_kRpTNi7r, &hTable_0ARm2QU2, true);
  numBytes += sTabread_init(&sTabread_f9PfGxJH, &hTable_EuFIUT7N, true);
  numBytes += sTabread_init(&sTabread_mbL6YwyO, &hTable_D17gvZtz, true);
  numBytes += sTabread_init(&sTabread_h2YIJv5g, &hTable_RQ7veuOM, true);
  numBytes += sTabwrite_init(&sTabwrite_1cB7ngHC, &hTable_MKOVheRb);
  numBytes += sTabwrite_init(&sTabwrite_jspvYLv4, &hTable_RQ7veuOM);
  numBytes += sTabwrite_init(&sTabwrite_HY2K3S61, &hTable_D17gvZtz);
  numBytes += sTabwrite_init(&sTabwrite_oPvrzAUY, &hTable_EuFIUT7N);
  numBytes += sTabwrite_init(&sTabwrite_ckH1H8Yl, &hTable_0ARm2QU2);
  numBytes += sTabwrite_init(&sTabwrite_Afuitgor, &hTable_GPApmXrg);
  numBytes += sTabread_init(&sTabread_qoY8korK, &hTable_MKOVheRb, true);
  numBytes += sTabread_init(&sTabread_witvQ5Vz, &hTable_iNNujHUH, true);
  numBytes += sRPole_init(&sRPole_D6Y98iGq);
  numBytes += sTabread_init(&sTabread_yY6X7Nds, &hTable_bjKuW1do, true);
  numBytes += sRPole_init(&sRPole_drHo05RK);
  numBytes += sTabread_init(&sTabread_nCJgAvj8, &hTable_vWahfTBD, true);
  numBytes += sRPole_init(&sRPole_ZVLdtxK6);
  numBytes += sTabwrite_init(&sTabwrite_6Rg202Ze, &hTable_H2niNe6T);
  numBytes += sTabwrite_init(&sTabwrite_jntCVGRQ, &hTable_iNNujHUH);
  numBytes += sTabwrite_init(&sTabwrite_NJk4KNph, &hTable_bjKuW1do);
  numBytes += sTabwrite_init(&sTabwrite_vzaHST7l, &hTable_vWahfTBD);
  numBytes += sLine_init(&sLine_oRjRJtGh);
  numBytes += sLine_init(&sLine_WPYgXQjR);
  numBytes += sTabwrite_init(&sTabwrite_tlRwJRhq, &hTable_kxCIxlxO);
  numBytes += sLine_init(&sLine_zfeQ5o9Q);
  numBytes += sPhasor_init(&sPhasor_oINwRhPc, sampleRate);
  numBytes += sLine_init(&sLine_Es9kD62b);
  numBytes += sLine_init(&sLine_wwF3p7q5);
  numBytes += sTabhead_init(&sTabhead_6iJth3kh, &hTable_kxCIxlxO);
  numBytes += sTabread_init(&sTabread_nqBH7E5Q, &hTable_kxCIxlxO, false);
  numBytes += sTabread_init(&sTabread_fSKrVupi, &hTable_kxCIxlxO, false);
  numBytes += sTabhead_init(&sTabhead_xGJFmdmX, &hTable_kxCIxlxO);
  numBytes += sTabread_init(&sTabread_FH604BU4, &hTable_kxCIxlxO, false);
  numBytes += sTabread_init(&sTabread_Mi6vPf3w, &hTable_kxCIxlxO, false);
  numBytes += sTabhead_init(&sTabhead_263RXy5i, &hTable_VBU3oJzZ);
  numBytes += sTabread_init(&sTabread_pTPL9qBY, &hTable_VBU3oJzZ, false);
  numBytes += sTabread_init(&sTabread_0MCC57Bx, &hTable_VBU3oJzZ, false);
  numBytes += sRPole_init(&sRPole_dQLNvxbv);
  numBytes += sDel1_init(&sDel1_RnwQbFMY);
  numBytes += sLine_init(&sLine_fRnLX3Ss);
  numBytes += sRPole_init(&sRPole_KeoQMUG9);
  numBytes += sTabwrite_init(&sTabwrite_esRKSqBh, &hTable_VBU3oJzZ);
  numBytes += sLine_init(&sLine_JQQA3LuM);
  numBytes += sLine_init(&sLine_OLt1EviP);
  numBytes += cSlice_init(&cSlice_HKPZr0qj, 2, 1);
  numBytes += cSlice_init(&cSlice_RFRCPipE, 1, 1);
  numBytes += cSlice_init(&cSlice_aLnvaTwv, 0, 1);
  numBytes += cVar_init_f(&cVar_5HRueZcU, 0.0f);
  numBytes += cIf_init(&cIf_CjsIqQii, false);
  numBytes += cIf_init(&cIf_NQGY3h0R, false);
  numBytes += cIf_init(&cIf_WynmliCp, false);
  numBytes += cIf_init(&cIf_5KqWZKRf, false);
  numBytes += cIf_init(&cIf_mbG2C8uD, false);
  numBytes += cBinop_init(&cBinop_TjDtJi3z, 0.0f); // __eq
  numBytes += cTabhead_init(&cTabhead_kIUUkF3b, &hTable_tF72jLxD);
  numBytes += cVar_init_s(&cVar_5j1fsrI9, "del-1011-del1");
  numBytes += cDelay_init(this, &cDelay_QaIHz2tN, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_5nalfOoD, 0.0f);
  numBytes += cBinop_init(&cBinop_hPTcDax0, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_xDNuG4Kk, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_SqBeCt2F, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_9CluecRu, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_av6pSjq1, &hTable_7nrSdsCY);
  numBytes += cVar_init_s(&cVar_xXOK1dHc, "del-1011-del2");
  numBytes += cDelay_init(this, &cDelay_Bdojczm2, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_WDtzSxru, 0.0f);
  numBytes += cBinop_init(&cBinop_ttbeu3Iq, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_IbGnNs5J, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_NfCpvIqY, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_7YmeOeXM, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_WC8z9Hmn, &hTable_J6L0k6K1);
  numBytes += cVar_init_s(&cVar_AIGKHj7e, "del-1011-del3");
  numBytes += cDelay_init(this, &cDelay_ZyRui00x, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_yxSubJUs, 0.0f);
  numBytes += cBinop_init(&cBinop_SQascMui, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_PKVQ6lXZ, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_csiaJxok, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_MyL6BodP, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_mYnK0tAu, &hTable_P2MvgdzR);
  numBytes += cVar_init_s(&cVar_5HSpMBj1, "del-1011-del4");
  numBytes += cDelay_init(this, &cDelay_t5oR0vUL, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_PtMpfVsO, 0.0f);
  numBytes += cBinop_init(&cBinop_rmBbhg7l, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_HLpI4KUw, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Jdihwlui, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_z2rjrwGw, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_z87Dh8Tt, 0.0f);
  numBytes += cDelay_init(this, &cDelay_r8OGdDcn, 0.0f);
  numBytes += hTable_init(&hTable_tF72jLxD, 256);
  numBytes += cDelay_init(this, &cDelay_4rvjLqIO, 0.0f);
  numBytes += cDelay_init(this, &cDelay_n5BVPYq7, 0.0f);
  numBytes += hTable_init(&hTable_7nrSdsCY, 256);
  numBytes += cDelay_init(this, &cDelay_N3KudGG7, 0.0f);
  numBytes += cDelay_init(this, &cDelay_rrG98Bwv, 0.0f);
  numBytes += hTable_init(&hTable_J6L0k6K1, 256);
  numBytes += cDelay_init(this, &cDelay_ZfjdhF1L, 0.0f);
  numBytes += cDelay_init(this, &cDelay_EOpXC1W4, 0.0f);
  numBytes += hTable_init(&hTable_P2MvgdzR, 256);
  numBytes += cIf_init(&cIf_h9fsvoa8, false);
  numBytes += cBinop_init(&cBinop_znbhiJ7q, 0.0f); // __pow
  numBytes += cPack_init(&cPack_kqRLkns0, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_4rXMETIp, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_XAMVlRva, 22050.0f);
  numBytes += cBinop_init(&cBinop_FZaFfzSA, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_8PIcDixP, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9N99uJQo, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_y0NVUvgc, 95.0f);
  numBytes += cVar_init_f(&cVar_c1l2Btyy, 90.0f);
  numBytes += cVar_init_f(&cVar_mfOqSYJr, 6000.0f);
  numBytes += cVar_init_f(&cVar_MiiDkY87, 60.0f);
  numBytes += cIf_init(&cIf_O2PWEEpt, false);
  numBytes += cTabhead_init(&cTabhead_CuoYbRfc, &hTable_7eTEkNjZ);
  numBytes += cVar_init_s(&cVar_c5DRnk7T, "del-1011-ref6");
  numBytes += cDelay_init(this, &cDelay_Gxxln8iC, 13.645f);
  numBytes += cDelay_init(this, &cDelay_QpPKeRxL, 0.0f);
  numBytes += cBinop_init(&cBinop_Hp9R4mCJ, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_4hPrLGiY, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_RObSsiV5, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_a98IUOet, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_wBZcLlID, 0.0f);
  numBytes += cDelay_init(this, &cDelay_drOH7R8m, 0.0f);
  numBytes += hTable_init(&hTable_7eTEkNjZ, 256);
  numBytes += cTabhead_init(&cTabhead_VCs3GKXV, &hTable_PeXzR7Y8);
  numBytes += cVar_init_s(&cVar_V60o2kg6, "del-1011-ref5");
  numBytes += cDelay_init(this, &cDelay_UMLyX8Ct, 16.364f);
  numBytes += cDelay_init(this, &cDelay_Xfri0Pyh, 0.0f);
  numBytes += cBinop_init(&cBinop_MX2rMrFL, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_TLnCDuYF, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_G7xiE0Rp, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_zhn2SFEz, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_8M0SuqD0, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ppxb3bze, 0.0f);
  numBytes += hTable_init(&hTable_PeXzR7Y8, 256);
  numBytes += cTabhead_init(&cTabhead_PLUfVxIB, &hTable_1d9Pk3Lj);
  numBytes += cVar_init_s(&cVar_PMByxuth, "del-1011-ref4");
  numBytes += cDelay_init(this, &cDelay_gqJCNVTd, 19.392f);
  numBytes += cDelay_init(this, &cDelay_8jglIGRG, 0.0f);
  numBytes += cBinop_init(&cBinop_pyBn6H8I, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_ai2IH2og, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_TOfNNYyM, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_UN97iPuq, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_5OAvWcs2, 0.0f);
  numBytes += cDelay_init(this, &cDelay_DNKHeYk9, 0.0f);
  numBytes += hTable_init(&hTable_1d9Pk3Lj, 256);
  numBytes += cTabhead_init(&cTabhead_jZeiPhad, &hTable_SA4QtDyC);
  numBytes += cVar_init_s(&cVar_3M0C3fcL, "del-1011-ref3");
  numBytes += cDelay_init(this, &cDelay_BZBtISZC, 25.796f);
  numBytes += cDelay_init(this, &cDelay_V45rRlZa, 0.0f);
  numBytes += cBinop_init(&cBinop_KpJQxEo6, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_aejPcpw3, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_6eoylmrU, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_25CQc7gH, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_fIcMy63j, 0.0f);
  numBytes += cDelay_init(this, &cDelay_cIdiLorX, 0.0f);
  numBytes += hTable_init(&hTable_SA4QtDyC, 256);
  numBytes += cTabhead_init(&cTabhead_maWMKIGC, &hTable_5tceBofY);
  numBytes += cVar_init_s(&cVar_OwltTNXy, "del-1011-ref2");
  numBytes += cDelay_init(this, &cDelay_Al7JX1Sm, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_vc3f3pmH, 0.0f);
  numBytes += cBinop_init(&cBinop_A8ubiPYp, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_JBE1lQNm, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_wd3QDUyF, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_yTDKfpaG, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_hBsfoo5b, 0.0f);
  numBytes += cDelay_init(this, &cDelay_nXJVovvK, 0.0f);
  numBytes += hTable_init(&hTable_5tceBofY, 256);
  numBytes += cTabhead_init(&cTabhead_g3X0oNQK, &hTable_dLmHrCPa);
  numBytes += cVar_init_s(&cVar_7WMxPwCV, "del-1011-ref1");
  numBytes += cDelay_init(this, &cDelay_wWjBweMY, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_ML2prmuF, 0.0f);
  numBytes += cBinop_init(&cBinop_6psaCQY0, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_y1JmMg6Z, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_pPySnQUP, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_V3wjye24, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_3EH3n1tm, 0.0f);
  numBytes += cDelay_init(this, &cDelay_h8H3m3EN, 0.0f);
  numBytes += hTable_init(&hTable_dLmHrCPa, 256);
  numBytes += cVar_init_f(&cVar_bVOVqcAb, 0.0f);
  numBytes += cVar_init_f(&cVar_7TBiYVzc, 0.0f);
  numBytes += cPack_init(&cPack_PKF7PVhU, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_z3Zmlm2Z, 22050.0f);
  numBytes += cBinop_init(&cBinop_N1ACoR8R, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_brQlZRWU, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_a4pJ4tBl, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_SfS2LCdm, 22050.0f);
  numBytes += cBinop_init(&cBinop_6b4PKSTS, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Jlo5XtCL, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_mcHitFHU, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_JDmMifvj, 22050.0f);
  numBytes += cBinop_init(&cBinop_Z3WMiBk7, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_RKOEHNn6, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_EhS0NGur, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_CiLdjMWU, false);
  numBytes += cDelay_init(this, &cDelay_sZqgkG00, 50.0f);
  numBytes += cVar_init_f(&cVar_eXMH4m8j, 0.0f);
  numBytes += cVar_init_f(&cVar_fGDcFREV, 12.0f);
  numBytes += cVar_init_s(&cVar_aXRUd8Q0, "floatatom");
  numBytes += cPack_init(&cPack_JPXLwiTS, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_HaWqh4wh, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_MI7nGxP0, "floatatom");
  numBytes += cDelay_init(this, &cDelay_Zod67Idy, 0.0f);
  numBytes += cDelay_init(this, &cDelay_UyaJAj3F, 0.0f);
  numBytes += hTable_init(&hTable_7pd6l9l0, 256);
  numBytes += cVar_init_s(&cVar_avBng3Ba, "del-1118-del");
  numBytes += sVarf_init(&sVarf_FQCx2ezb, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_cT3Kw7cW, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_em0hUoV4, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_w7tZvEtH, "del-1118-del");
  numBytes += sVarf_init(&sVarf_EOhHSEso, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_LAWICRd4, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_d1IbXx7G, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_mnx6kSMZ, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_oTbLg06O, 4720.0f);
  numBytes += cBinop_init(&cBinop_6Umr0WeK, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_vHaM0Yj2, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_HweexQ0D, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_BbOWz0oz, 4720.0f);
  numBytes += cBinop_init(&cBinop_SnpasltI, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_dfZuOA8O, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_o0WZYLOy, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_LcsWtpaK, 4720.0f);
  numBytes += cBinop_init(&cBinop_pGh4hS16, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_WFEO5EsB, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_pG2pWCWO, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_EOf4mgEx, 1.0f);
  numBytes += cIf_init(&cIf_s0bjndjn, false);
  numBytes += sVarf_init(&sVarf_vx7ryrAT, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_UIee5DUI, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_KRgqb7cJ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_2kyiKVyj, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_2M97mHRR, 4720.0f, 0.0f, false);
  numBytes += cTabhead_init(&cTabhead_NAISSBs9, &hTable_H2niNe6T);
  numBytes += cVar_init_s(&cVar_338lqcMq, "del-1181-del1");
  numBytes += cDelay_init(this, &cDelay_iiFO9Qam, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_9xu8HRIH, 0.0f);
  numBytes += cBinop_init(&cBinop_UIVjcG6e, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_BFwBdnNC, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_8QiX75mH, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_uCDo9BZW, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_g9YQT7pb, &hTable_iNNujHUH);
  numBytes += cVar_init_s(&cVar_GSqwYHnM, "del-1181-del2");
  numBytes += cDelay_init(this, &cDelay_yGf1eehY, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_SMJAKoSE, 0.0f);
  numBytes += cBinop_init(&cBinop_kiAQH46F, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_wqBX4nnk, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_9E8jTcoQ, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_ptifLpdp, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_MAMw6hWl, &hTable_bjKuW1do);
  numBytes += cVar_init_s(&cVar_GCGsJSYu, "del-1181-del3");
  numBytes += cDelay_init(this, &cDelay_dCBPuy7f, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_sYpXCy5F, 0.0f);
  numBytes += cBinop_init(&cBinop_BdelcCN4, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_8g5rtl6F, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_QmOJFA93, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_8Z6XKY1k, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_B9v9CFfV, &hTable_vWahfTBD);
  numBytes += cVar_init_s(&cVar_FnFwiL3O, "del-1181-del4");
  numBytes += cDelay_init(this, &cDelay_fZrgNdnM, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_Amtzd2WT, 0.0f);
  numBytes += cBinop_init(&cBinop_Irmoovil, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_ENW9nD56, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_BLfpx2ij, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_yJ75sqCw, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_crpitYuk, 0.0f);
  numBytes += cDelay_init(this, &cDelay_fg0Bqh2R, 0.0f);
  numBytes += hTable_init(&hTable_H2niNe6T, 256);
  numBytes += cDelay_init(this, &cDelay_wuYQmUjj, 0.0f);
  numBytes += cDelay_init(this, &cDelay_XQHtYtEj, 0.0f);
  numBytes += hTable_init(&hTable_iNNujHUH, 256);
  numBytes += cDelay_init(this, &cDelay_sdWgbqos, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Z3X6Wbhm, 0.0f);
  numBytes += hTable_init(&hTable_bjKuW1do, 256);
  numBytes += cDelay_init(this, &cDelay_YaPEui71, 0.0f);
  numBytes += cDelay_init(this, &cDelay_LCqK6Kfo, 0.0f);
  numBytes += hTable_init(&hTable_vWahfTBD, 256);
  numBytes += cIf_init(&cIf_mkEqc8ZT, false);
  numBytes += cBinop_init(&cBinop_ZrckHz4X, 0.0f); // __pow
  numBytes += cPack_init(&cPack_0wYDFwxi, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_EWSF7kuW, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_BN8SblCZ, 22050.0f);
  numBytes += cBinop_init(&cBinop_8tLQpT8s, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_EOa1DYUM, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Y8EXrTFK, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_TDYXfXib, 100.0f);
  numBytes += cVar_init_f(&cVar_q7t9aMkq, 95.0f);
  numBytes += cVar_init_f(&cVar_xijUO3KL, 14400.0f);
  numBytes += cVar_init_f(&cVar_PuI38dFq, 60.0f);
  numBytes += cIf_init(&cIf_TxioUVy5, false);
  numBytes += cTabhead_init(&cTabhead_Psf7wxCL, &hTable_MKOVheRb);
  numBytes += cVar_init_s(&cVar_4OJmUKgn, "del-1181-ref6");
  numBytes += cDelay_init(this, &cDelay_GSZk0vCS, 13.645f);
  numBytes += cDelay_init(this, &cDelay_Z2RkmCxh, 0.0f);
  numBytes += cBinop_init(&cBinop_mku7vcdJ, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_hMMcMDhh, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_WEYOyy9A, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_wgMHlltW, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_L3lRjqLF, 0.0f);
  numBytes += cDelay_init(this, &cDelay_2hSz4mbe, 0.0f);
  numBytes += hTable_init(&hTable_MKOVheRb, 256);
  numBytes += cTabhead_init(&cTabhead_unNDbdF3, &hTable_RQ7veuOM);
  numBytes += cVar_init_s(&cVar_r8gF6GJZ, "del-1181-ref5");
  numBytes += cDelay_init(this, &cDelay_7FT5E9Y1, 16.364f);
  numBytes += cDelay_init(this, &cDelay_aGtxj0Wo, 0.0f);
  numBytes += cBinop_init(&cBinop_6TIEiPFX, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_63pfUuZT, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_0N8emxpN, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_loZxjTuZ, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_jhCDb12o, 0.0f);
  numBytes += cDelay_init(this, &cDelay_8nfeyA7z, 0.0f);
  numBytes += hTable_init(&hTable_RQ7veuOM, 256);
  numBytes += cTabhead_init(&cTabhead_1f2tzRoW, &hTable_D17gvZtz);
  numBytes += cVar_init_s(&cVar_v0qrsGGX, "del-1181-ref4");
  numBytes += cDelay_init(this, &cDelay_f7AyPfdd, 19.392f);
  numBytes += cDelay_init(this, &cDelay_86IEySAv, 0.0f);
  numBytes += cBinop_init(&cBinop_JzrRbLob, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_NWzxEgr1, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_FgSIzjdB, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_G7GZQ0B7, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_pNHCjgjK, 0.0f);
  numBytes += cDelay_init(this, &cDelay_2JMxHNnj, 0.0f);
  numBytes += hTable_init(&hTable_D17gvZtz, 256);
  numBytes += cTabhead_init(&cTabhead_fPcCs3Bu, &hTable_EuFIUT7N);
  numBytes += cVar_init_s(&cVar_5itQXJJu, "del-1181-ref3");
  numBytes += cDelay_init(this, &cDelay_S93tiKiW, 25.796f);
  numBytes += cDelay_init(this, &cDelay_6gs0ZgS1, 0.0f);
  numBytes += cBinop_init(&cBinop_XiXTW8uV, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_EevPJCTX, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_HlT210TI, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_CSwnsttm, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_0mGPuN7s, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ynmCY4Ij, 0.0f);
  numBytes += hTable_init(&hTable_EuFIUT7N, 256);
  numBytes += cTabhead_init(&cTabhead_3IDarXnm, &hTable_0ARm2QU2);
  numBytes += cVar_init_s(&cVar_dea5lSVH, "del-1181-ref2");
  numBytes += cDelay_init(this, &cDelay_IHe90Hj1, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_0aJMDue3, 0.0f);
  numBytes += cBinop_init(&cBinop_HtfFHE07, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_9EySJxR5, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_w7Rv1Ium, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_8JBI8OHd, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_YAHNC1eQ, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Oe4rpeE2, 0.0f);
  numBytes += hTable_init(&hTable_0ARm2QU2, 256);
  numBytes += cTabhead_init(&cTabhead_KcZmeVMg, &hTable_GPApmXrg);
  numBytes += cVar_init_s(&cVar_bmgnBiPI, "del-1181-ref1");
  numBytes += cDelay_init(this, &cDelay_j3IBeWm5, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_l4xW20aQ, 0.0f);
  numBytes += cBinop_init(&cBinop_H98hwKmN, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_LnkVt4G8, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_WiYgjvPm, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_1SCtKeE7, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_KdK1mT02, 0.0f);
  numBytes += cDelay_init(this, &cDelay_eNGzrEXS, 0.0f);
  numBytes += hTable_init(&hTable_GPApmXrg, 256);
  numBytes += cVar_init_f(&cVar_wRuT1ncK, 0.0f);
  numBytes += cVar_init_f(&cVar_oXvkQX2r, 0.0f);
  numBytes += cPack_init(&cPack_gVjARBwx, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_u1QFAeIg, 22050.0f);
  numBytes += cBinop_init(&cBinop_FcebQgsp, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Fr8eI7SJ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_kRTIIinM, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_5XeB1hlH, 22050.0f);
  numBytes += cBinop_init(&cBinop_VfeqUVnL, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_4Lucl2o7, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_VEu7WKRh, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_YufBLxpG, 22050.0f);
  numBytes += cBinop_init(&cBinop_lCUBc7mU, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_UJWln8Ax, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_4JUn7Iix, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_gDqw19Uh, "del-1280-del1");
  numBytes += sVarf_init(&sVarf_Cmbj3Yxq, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_STzbPVCH, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_YgAVwZmN, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_lFKnOJ8b, 10000.0f);
  numBytes += cBinop_init(&cBinop_rpgoCOCx, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_ku1pjJYS, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_uIu0dZQc, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_EWOZELwx, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Pdo5FwNb, 10.0f);
  numBytes += cBinop_init(&cBinop_CTpViEKE, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_0KVveVQ4, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_Sv63HcZD, "floatatom");
  numBytes += sVarf_init(&sVarf_A6DNjj7z, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_TAtYJvzA, 0.0f);
  numBytes += cDelay_init(this, &cDelay_XExETrRb, 0.0f);
  numBytes += hTable_init(&hTable_gluxEKKN, 256);
  numBytes += sVarf_init(&sVarf_NHEAesR6, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_M3d0YYPw, 2, 0.0f, 50.0f);
  numBytes += cRandom_init(&cRandom_cVjGgGRU, -79610773);
  numBytes += cSlice_init(&cSlice_kE9FQJWs, 1, 1);
  numBytes += cRandom_init(&cRandom_rUsox3tx, 1930796382);
  numBytes += cSlice_init(&cSlice_xgCOtpT4, 1, 1);
  numBytes += cVar_init_s(&cVar_nXI6nsuw, "floatatom");
  numBytes += cPack_init(&cPack_EXRPNR9z, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_SB6rq4TJ, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_xH8v4xqU, "floatatom");
  numBytes += cDelay_init(this, &cDelay_6kMeBGAm, 0.0f);
  numBytes += cDelay_init(this, &cDelay_lMO0B3Ma, 0.0f);
  numBytes += hTable_init(&hTable_kxCIxlxO, 256);
  numBytes += cVar_init_s(&cVar_hzOrUdyI, "del-1311-del");
  numBytes += sVarf_init(&sVarf_8SWCOGJz, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_J3VvS4yU, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_zZanAN94, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_ffn5tknD, "del-1311-del");
  numBytes += sVarf_init(&sVarf_IwXDkzAY, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Aw8vxnnU, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_RCPs6bHG, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_fjrj5i6t, 0.0f); // __div
  numBytes += cVar_init_s(&cVar_kMPT6E1m, "del-1340-del1");
  numBytes += sVarf_init(&sVarf_c9ypxp2y, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_p3eDQAFy, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_MI6OJ1LF, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_G8jrQs1J, 10000.0f);
  numBytes += cBinop_init(&cBinop_te52h2ST, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_QsyUIIvc, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ThZXZHAT, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_A5pVkXMo, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_aNJuv9nj, 10.0f);
  numBytes += cBinop_init(&cBinop_2AQzqpR9, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_HNx8Qzxt, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_lLoppnQY, "floatatom");
  numBytes += sVarf_init(&sVarf_1fIo3oEh, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_ch2VAmh2, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Ip4oYwDK, 0.0f);
  numBytes += hTable_init(&hTable_VBU3oJzZ, 256);
  numBytes += sVarf_init(&sVarf_63gqenBH, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_gW7494OR, "floatatom");
  numBytes += cDelay_init(this, &cDelay_vp9tGRme, 0.0f);
  numBytes += cVar_init_f(&cVar_Uynq530P, 20.0f);
  numBytes += cBinop_init(&cBinop_GOUxF8Qv, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_6TqVLbNk, 0.0f);
  numBytes += cSlice_init(&cSlice_7jpQacey, 1, -1);
  numBytes += cSlice_init(&cSlice_MDn66eZA, 1, -1);
  numBytes += cVar_init_f(&cVar_ExrZRXYO, 0.0f);
  numBytes += cVar_init_f(&cVar_8UjNKdi6, 20.0f);
  numBytes += cVar_init_f(&cVar_mDYSGxXq, 0.0f);
  numBytes += cVar_init_f(&cVar_A4ETXT8r, 0.0f);
  numBytes += cVar_init_f(&cVar_cP3GRcSx, 0.0f);
  numBytes += cSlice_init(&cSlice_Q6qW0Xb9, 1, 1);
  numBytes += cSlice_init(&cSlice_hQ0RcpM4, 0, 1);
  numBytes += cBinop_init(&cBinop_RnE2aaF3, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_VY3OfCJU, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_kpDTEmMt, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_meZg2LwW, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_Hl46gOXY, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_qn66d3IK, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_RUqK2zQ0, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_1Tau0NLH, 0.0f); // __sub
  numBytes += cVar_init_s(&cVar_oHaGEbZO, "floatatom");
  numBytes += cPack_init(&cPack_s5Sfe3h5, 2, 0.0f, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_40dvEclx, 0.0f);
  numBytes += cVar_init_f(&cVar_R0pcyLuB, 20.0f);
  numBytes += cBinop_init(&cBinop_Ze92IlFp, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_gv4uLgW0, 0.0f);
  numBytes += cSlice_init(&cSlice_3FcG2eP6, 1, -1);
  numBytes += cSlice_init(&cSlice_hzxHCUvd, 1, -1);
  numBytes += cVar_init_f(&cVar_OSOWVX3F, 0.0f);
  numBytes += cVar_init_f(&cVar_PK8cZwxn, 20.0f);
  numBytes += cVar_init_f(&cVar_3Gl8TCrA, 0.0f);
  numBytes += cVar_init_f(&cVar_qIRn0zTO, 0.0f);
  numBytes += cVar_init_f(&cVar_aE2sbu0Y, 0.0f);
  numBytes += cSlice_init(&cSlice_SSrEV2P9, 1, 1);
  numBytes += cSlice_init(&cSlice_sKzkXWhJ, 0, 1);
  numBytes += cBinop_init(&cBinop_zUrtvA3b, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_NTvVOp5O, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_1MCleYou, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_JfnAC6vL, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_WakJ39ux, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_9y8LGWO8, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_If5CaFi5, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_ttKEN1A5, 0.0f); // __sub
  numBytes += cPack_init(&cPack_pM9lzrWZ, 2, 0.0f, 1000.0f);
  numBytes += cPack_init(&cPack_p5W4lEzM, 2, 0.0f, 1000.0f);
  numBytes += sVarf_init(&sVarf_gCaZXOIc, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_BBz2VrJD, 5.0f);
  numBytes += cBinop_init(&cBinop_OJErSLAh, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_HoxPe96z, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_IbvxVxyB, "floatatom");
  numBytes += cIf_init(&cIf_MKWmybUd, false);
  numBytes += cIf_init(&cIf_6vTEKeu0, false);
  numBytes += cIf_init(&cIf_EzqhaleF, false);
  numBytes += cIf_init(&cIf_RCBr8eA3, false);
  numBytes += cRandom_init(&cRandom_2fNkv4Oi, -1100420796);
  numBytes += cSlice_init(&cSlice_u2JOnIh0, 1, 1);
  numBytes += sVari_init(&sVari_imSFUkZK, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_PIRTcLF5, &hTable_3VwDfFas);
  numBytes += cVar_init_s(&cVar_OeTUhH3r, "del-1418-delay");
  numBytes += cDelay_init(this, &cDelay_lcR1OtSv, 12.0f);
  numBytes += cDelay_init(this, &cDelay_WmmDrW4e, 0.0f);
  numBytes += cBinop_init(&cBinop_MlOkrRKT, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_CyzUsgAK, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_drkt3Wkh, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_8U5bnbTx, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_PzrxcvzK, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_Qf6owR4J, "floatatom");
  numBytes += cDelay_init(this, &cDelay_d1lvyhXv, 5.0f);
  numBytes += cVar_init_f(&cVar_nYgxT2Ub, 3800.0f);
  numBytes += cBinop_init(&cBinop_AaqJX4YH, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_IaFSZ6XV, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_1umjGuSQ, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_wOgy7IS2, 0.0f);
  numBytes += cDelay_init(this, &cDelay_A3jm9Jcp, 0.0f);
  numBytes += hTable_init(&hTable_3VwDfFas, 256);
  numBytes += cBinop_init(&cBinop_PqEEF3aq, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_THiWq8rS, 0.999f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_OGdSgNum, 1.0f);
  numBytes += cDelay_init(this, &cDelay_5A5eNh5O, 0.0f);
  numBytes += cVar_init_f(&cVar_OtXf2NGF, 2000.0f);
  numBytes += cBinop_init(&cBinop_mjDNokV1, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_QhchSK7Q, 60.0f);
  numBytes += cRandom_init(&cRandom_DCGfYeak, 1255741372);
  numBytes += cSlice_init(&cSlice_0Hy7nkHZ, 1, 1);
  numBytes += cVar_init_f(&cVar_6cXDqffS, 0.0f);
  numBytes += cIf_init(&cIf_dfixUOX6, false);
  numBytes += cIf_init(&cIf_7tBGhXkj, false);
  numBytes += cIf_init(&cIf_ipB21fYo, false);
  numBytes += cIf_init(&cIf_Qunc2MVB, false);
  numBytes += cPack_init(&cPack_5GPJyP0F, 2, 0.0f, 50.0f);
  numBytes += cPack_init(&cPack_zzAVI3kb, 2, 0.0f, 80.0f);
  numBytes += cVar_init_s(&cVar_gXuHmMkT, "floatatom");
  numBytes += cRandom_init(&cRandom_M18YHlgf, -721515502);
  numBytes += cSlice_init(&cSlice_B7BRgCX1, 1, 1);
  numBytes += cVar_init_s(&cVar_UBbjGlJr, "floatatom");
  numBytes += cVar_init_f(&cVar_JfowikST, 1.0f);
  numBytes += cVar_init_f(&cVar_rnidVc9v, 0.0f);
  numBytes += cVar_init_f(&cVar_y7777dEW, 0.0f);
  numBytes += cRandom_init(&cRandom_EYcAnYeo, -1921684931);
  numBytes += cSlice_init(&cSlice_54jTwGcL, 1, 1);
  numBytes += cRandom_init(&cRandom_MJu0619A, -1357810085);
  numBytes += cSlice_init(&cSlice_8yx6aV99, 1, 1);
  numBytes += cRandom_init(&cRandom_27s3Ojzg, 1829548097);
  numBytes += cSlice_init(&cSlice_kh092qHC, 1, 1);
  numBytes += cBinop_init(&cBinop_ima0qRFV, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_rART4y8z, 1705876954);
  numBytes += cSlice_init(&cSlice_RAhlGjyD, 1, 1);
  numBytes += cPack_init(&cPack_rAFydJof, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_vhxpxuvP, "floatatom");
  numBytes += cVar_init_s(&cVar_L1JcSeR9, "floatatom");
  numBytes += cVar_init_f(&cVar_tuHE2vSN, 0.0f);
  numBytes += cVar_init_s(&cVar_KS8cxS9w, "floatatom");
  numBytes += cVar_init_s(&cVar_stUsVq2g, "floatatom");
  numBytes += cVar_init_s(&cVar_WR9akQL7, "floatatom");
  numBytes += cDelay_init(this, &cDelay_Y8FgzI5v, 25.0f);
  numBytes += cVar_init_f(&cVar_k34M7PdE, 0.0f);
  numBytes += sVarf_init(&sVarf_lVKP3cbj, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_BqKWc8vk, -1798536827);
  numBytes += cSlice_init(&cSlice_vaBC4uPt, 1, 1);
  numBytes += sVari_init(&sVari_mTxzKFMn, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_7eYUWruq, &hTable_T2Zb4m8z);
  numBytes += cVar_init_s(&cVar_II7cyevt, "del-1497-delay");
  numBytes += cDelay_init(this, &cDelay_IPWBuSJ6, 12.0f);
  numBytes += cDelay_init(this, &cDelay_ko33FrQ0, 0.0f);
  numBytes += cBinop_init(&cBinop_m786xWiG, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_yX8vBeQ0, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_eQo2tGPK, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_A7dU69Nr, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_pBHdTb54, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_lBwSWIfq, "floatatom");
  numBytes += cDelay_init(this, &cDelay_hSLMjdWx, 5.0f);
  numBytes += cVar_init_f(&cVar_Oju8PReC, 3800.0f);
  numBytes += cBinop_init(&cBinop_amK5yKTL, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_XlX97RdE, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_wHh4zhxt, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_XrnrD8IM, 0.0f);
  numBytes += cDelay_init(this, &cDelay_EBQWLloJ, 0.0f);
  numBytes += hTable_init(&hTable_T2Zb4m8z, 256);
  numBytes += cBinop_init(&cBinop_nwpOHDmM, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_pfaoN5RQ, 0.999f, 0.0f, false);
  numBytes += cPack_init(&cPack_W2RjhcLT, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_PHVE7EB9, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_jpXYpQpM, 1, 1);
  numBytes += cSlice_init(&cSlice_Y8v0pQKb, 0, 1);
  numBytes += cBinop_init(&cBinop_YFRGxe7u, 1.0f); // __mul
  numBytes += cVar_init_f(&cVar_ODWpAQfD, 98.0f);
  numBytes += cIf_init(&cIf_K4Bnx4VS, false);
  numBytes += cBinop_init(&cBinop_N9KyPOTQ, 0.0f); // __pow
  numBytes += cPack_init(&cPack_W5YII2ZU, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_ewn0qCkA, 0.0f);
  numBytes += cVar_init_f(&cVar_zdgJDFxf, 98.0f);
  numBytes += cIf_init(&cIf_3HLhqs9Q, false);
  numBytes += cBinop_init(&cBinop_myxobhs3, 0.0f); // __pow
  numBytes += cPack_init(&cPack_R5aCcF9I, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_in4G2pe5, 0.0f);
  numBytes += cRandom_init(&cRandom_07VtCaq3, -1453345451);
  numBytes += cSlice_init(&cSlice_V7u2YPWs, 1, 1);
  numBytes += cBinop_init(&cBinop_cvsvzwn4, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_pmYgav4t, -1863619788);
  numBytes += cSlice_init(&cSlice_in8BqYCr, 1, 1);
  numBytes += cPack_init(&cPack_llm7U96a, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_3w2bTWXV, "floatatom");
  numBytes += cVar_init_s(&cVar_OKREmgC7, "floatatom");
  numBytes += cVar_init_f(&cVar_zXVelbzx, 0.0f);
  numBytes += cVar_init_s(&cVar_7hD2Nprw, "floatatom");
  numBytes += cVar_init_s(&cVar_IlmsQzp2, "floatatom");
  numBytes += cVar_init_s(&cVar_oOUXJBpu, "floatatom");
  numBytes += cDelay_init(this, &cDelay_NE6ngpFU, 25.0f);
  numBytes += cVar_init_f(&cVar_kqsjeCjo, 0.0f);
  numBytes += sVarf_init(&sVarf_gWCQCHXY, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_L2HOtwQ0, 126506814);
  numBytes += cSlice_init(&cSlice_1rKxr3Sm, 1, 1);
  numBytes += sVari_init(&sVari_oTtvC7BD, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_I137dHsl, &hTable_NOntZksZ);
  numBytes += cVar_init_s(&cVar_N6CoGYI1, "del-1564-delay");
  numBytes += cDelay_init(this, &cDelay_z7RWhAmp, 12.0f);
  numBytes += cDelay_init(this, &cDelay_FfCucnpg, 0.0f);
  numBytes += cBinop_init(&cBinop_aWrI7E4n, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_rJQipifR, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Ze4Tv9GZ, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_SRD0GaJB, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_6jX1gpLm, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_suWQMfCn, "floatatom");
  numBytes += cDelay_init(this, &cDelay_qtv0ayRD, 5.0f);
  numBytes += cVar_init_f(&cVar_6WcN0BUW, 3800.0f);
  numBytes += cBinop_init(&cBinop_Tr6oQXfl, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_lSbAOmrg, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_8RUx8Bd6, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_4xogpkp6, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ShhUzkAO, 0.0f);
  numBytes += hTable_init(&hTable_NOntZksZ, 256);
  numBytes += cBinop_init(&cBinop_AV80OxCF, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_gZTQ3djx, 0.999f, 0.0f, false);
  numBytes += cPack_init(&cPack_oziuCjUo, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_3862M1I1, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_0bG2aPGk, 1, 1);
  numBytes += cSlice_init(&cSlice_CSWs3v21, 0, 1);
  numBytes += cBinop_init(&cBinop_9E6IQM4A, 1.0f); // __mul
  numBytes += cRandom_init(&cRandom_g956zFn6, -72965983);
  numBytes += cSlice_init(&cSlice_p3VH5C0t, 1, 1);
  numBytes += cBinop_init(&cBinop_MCtrup7a, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_7LN4f0lw, -2052572238);
  numBytes += cSlice_init(&cSlice_SdsXYBVJ, 1, 1);
  numBytes += cPack_init(&cPack_ZDrTJJON, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_K7GyhhvU, "floatatom");
  numBytes += cVar_init_s(&cVar_7GpGI3TD, "floatatom");
  numBytes += cVar_init_f(&cVar_8lWsQlfe, 0.0f);
  numBytes += cVar_init_s(&cVar_nSz4l5UX, "floatatom");
  numBytes += cVar_init_s(&cVar_4wJQh9gk, "floatatom");
  numBytes += cVar_init_s(&cVar_ziHKfjQL, "floatatom");
  numBytes += cDelay_init(this, &cDelay_ClzSHiyY, 25.0f);
  numBytes += cVar_init_f(&cVar_1krK8gnS, 0.0f);
  numBytes += sVarf_init(&sVarf_jYXNZU9t, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_msLWPt09, -1525354791);
  numBytes += cSlice_init(&cSlice_DSk7p9zC, 1, 1);
  numBytes += sVari_init(&sVari_ikRTBjKN, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_GcuaQrBT, &hTable_U4YYujfG);
  numBytes += cVar_init_s(&cVar_jCbrhYXm, "del-1615-delay");
  numBytes += cDelay_init(this, &cDelay_TokOZSCs, 12.0f);
  numBytes += cDelay_init(this, &cDelay_ojGWhouB, 0.0f);
  numBytes += cBinop_init(&cBinop_SfK4qf50, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_7L2UOFbV, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_ArMLrnfB, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_l00ltTti, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Eb1EEh6k, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_35LvyqsK, "floatatom");
  numBytes += cDelay_init(this, &cDelay_8v03FZwg, 5.0f);
  numBytes += cVar_init_f(&cVar_bT3aOXEE, 3800.0f);
  numBytes += cBinop_init(&cBinop_S6e0qOhR, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_LpPyEMvp, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ncsts9O1, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_sXBiFYUH, 0.0f);
  numBytes += cDelay_init(this, &cDelay_aMIcwry5, 0.0f);
  numBytes += hTable_init(&hTable_U4YYujfG, 256);
  numBytes += cBinop_init(&cBinop_OPWDyLgX, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_w5PuOACo, 0.999f, 0.0f, false);
  numBytes += cPack_init(&cPack_ysxZGKcT, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_4QBdNQEV, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_qhhqy6VU, 1, 1);
  numBytes += cSlice_init(&cSlice_Xhdvy25o, 0, 1);
  numBytes += cBinop_init(&cBinop_Idpn54iP, 1.0f); // __mul
  numBytes += cRandom_init(&cRandom_z4h4YX8J, -404984620);
  numBytes += cSlice_init(&cSlice_OKzS54HQ, 1, 1);
  numBytes += cBinop_init(&cBinop_oPamYJDf, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_RsB8YAQH, -1247855555);
  numBytes += cSlice_init(&cSlice_vSnJnNyF, 1, 1);
  numBytes += cPack_init(&cPack_fLYWNz5o, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_omk7Cw9A, "floatatom");
  numBytes += cVar_init_s(&cVar_lXKU5YO0, "floatatom");
  numBytes += cVar_init_f(&cVar_X373zqMA, 0.0f);
  numBytes += cVar_init_s(&cVar_ASuXEL5J, "floatatom");
  numBytes += cVar_init_s(&cVar_F16qcfDR, "floatatom");
  numBytes += cVar_init_s(&cVar_o8hEl584, "floatatom");
  numBytes += cDelay_init(this, &cDelay_WOymj7zb, 25.0f);
  numBytes += cVar_init_f(&cVar_ewuaYIWZ, 0.0f);
  numBytes += sVarf_init(&sVarf_DvW9787N, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_F0WSUJ3D, 1800279024);
  numBytes += cSlice_init(&cSlice_JHavUH0s, 1, 1);
  numBytes += sVari_init(&sVari_uMgsv9Dq, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_lpn6N5H2, &hTable_jbRSuQoA);
  numBytes += cVar_init_s(&cVar_sheJmEXS, "del-1666-delay");
  numBytes += cDelay_init(this, &cDelay_YdHVzVrz, 12.0f);
  numBytes += cDelay_init(this, &cDelay_P0emgaxE, 0.0f);
  numBytes += cBinop_init(&cBinop_jOdEeeMN, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_tOG3lDr0, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_IyHX8KBU, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_CXtPcSzJ, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_1FwAuNI7, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_kNfMEbRm, "floatatom");
  numBytes += cDelay_init(this, &cDelay_Xik6pFmv, 5.0f);
  numBytes += cVar_init_f(&cVar_nOzzZo07, 3800.0f);
  numBytes += cBinop_init(&cBinop_S3QuEjUN, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_i3WZOCxM, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_2jUZNcBL, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_k7tpb9BW, 0.0f);
  numBytes += cDelay_init(this, &cDelay_bIXIyheA, 0.0f);
  numBytes += hTable_init(&hTable_jbRSuQoA, 256);
  numBytes += cBinop_init(&cBinop_DsMKCkK4, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_FDvLCmUs, 0.999f, 0.0f, false);
  numBytes += cPack_init(&cPack_sZ4e1iT1, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_LpO6e77h, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_jJqlwEor, 1, 1);
  numBytes += cSlice_init(&cSlice_gyTwnZQ8, 0, 1);
  numBytes += cBinop_init(&cBinop_UnkaATq4, 1.0f); // __mul
  numBytes += cVar_init_f(&cVar_4awtKk01, 100.0f);
  numBytes += cIf_init(&cIf_75x3CruJ, false);
  numBytes += cBinop_init(&cBinop_sgoYgPyt, 0.0f); // __pow
  numBytes += cPack_init(&cPack_QHe78A3C, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_5sxza9cH, 0.0f);
  numBytes += cVar_init_f(&cVar_nRvNsAen, 100.0f);
  numBytes += cIf_init(&cIf_b5DILz8B, false);
  numBytes += cBinop_init(&cBinop_q7kcLDVK, 0.0f); // __pow
  numBytes += cPack_init(&cPack_Naorkc2G, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_KVZmfw2i, 0.0f);
  numBytes += cVar_init_f(&cVar_VMs9TkcM, 98.0f);
  numBytes += cIf_init(&cIf_bou0rp1y, false);
  numBytes += cBinop_init(&cBinop_JCV539Ly, 0.0f); // __pow
  numBytes += cPack_init(&cPack_ijhTpQps, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_S6koGsfZ, 0.0f);
  numBytes += cIf_init(&cIf_BgnSFCzE, false);
  numBytes += cIf_init(&cIf_31O9fJq4, false);
  numBytes += cVar_init_f(&cVar_2oEEqlVB, 89.0f);
  numBytes += cIf_init(&cIf_wfxB4ES0, false);
  numBytes += cBinop_init(&cBinop_rwEdFdFp, 0.0f); // __pow
  numBytes += cPack_init(&cPack_fTD6v2FM, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_GtXUaDqb, 0.0f);
  numBytes += cPack_init(&cPack_KhheXSBq, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_cEZ5Ybc4, 1, 1);
  numBytes += cSlice_init(&cSlice_cJonp05J, 0, 1);
  numBytes += cIf_init(&cIf_6BsToJNc, false);
  numBytes += cIf_init(&cIf_RXMqfEqq, false);
  numBytes += cIf_init(&cIf_P6KIwksz, false);
  numBytes += cSlice_init(&cSlice_mSTqs3Ss, 1, 1);
  numBytes += cSlice_init(&cSlice_NdmFVrz4, 0, 1);
  numBytes += cVar_init_f(&cVar_v3PPdNzm, 0.0f);
  numBytes += cIf_init(&cIf_X7PtE6y1, false);
  numBytes += cPack_init(&cPack_z5LFSMWT, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_uEPkBz8w, 1, -1);
  numBytes += cSlice_init(&cSlice_li0p7INZ, 1, -1);
  numBytes += cSlice_init(&cSlice_a7Kvb0s9, 1, -1);
  numBytes += cSlice_init(&cSlice_5djnKwsA, 1, -1);
  numBytes += cIf_init(&cIf_4HcoiZX9, false);
  numBytes += cVar_init_f(&cVar_7htb47gg, 1.0f);
  numBytes += cPack_init(&cPack_tdvuGjRQ, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_spIZlEdf, 0.0f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_CircleStrings::~Heavy_CircleStrings() {
  hTable_free(&hTable_tF72jLxD);
  hTable_free(&hTable_7nrSdsCY);
  hTable_free(&hTable_J6L0k6K1);
  hTable_free(&hTable_P2MvgdzR);
  cPack_free(&cPack_kqRLkns0);
  cPack_free(&cPack_4rXMETIp);
  hTable_free(&hTable_7eTEkNjZ);
  hTable_free(&hTable_PeXzR7Y8);
  hTable_free(&hTable_1d9Pk3Lj);
  hTable_free(&hTable_SA4QtDyC);
  hTable_free(&hTable_5tceBofY);
  hTable_free(&hTable_dLmHrCPa);
  cPack_free(&cPack_PKF7PVhU);
  cPack_free(&cPack_JPXLwiTS);
  cPack_free(&cPack_HaWqh4wh);
  hTable_free(&hTable_7pd6l9l0);
  hTable_free(&hTable_H2niNe6T);
  hTable_free(&hTable_iNNujHUH);
  hTable_free(&hTable_bjKuW1do);
  hTable_free(&hTable_vWahfTBD);
  cPack_free(&cPack_0wYDFwxi);
  cPack_free(&cPack_EWSF7kuW);
  hTable_free(&hTable_MKOVheRb);
  hTable_free(&hTable_RQ7veuOM);
  hTable_free(&hTable_D17gvZtz);
  hTable_free(&hTable_EuFIUT7N);
  hTable_free(&hTable_0ARm2QU2);
  hTable_free(&hTable_GPApmXrg);
  cPack_free(&cPack_gVjARBwx);
  hTable_free(&hTable_gluxEKKN);
  cPack_free(&cPack_M3d0YYPw);
  cPack_free(&cPack_EXRPNR9z);
  cPack_free(&cPack_SB6rq4TJ);
  hTable_free(&hTable_kxCIxlxO);
  hTable_free(&hTable_VBU3oJzZ);
  cPack_free(&cPack_s5Sfe3h5);
  cPack_free(&cPack_pM9lzrWZ);
  cPack_free(&cPack_p5W4lEzM);
  hTable_free(&hTable_3VwDfFas);
  cPack_free(&cPack_5GPJyP0F);
  cPack_free(&cPack_zzAVI3kb);
  cPack_free(&cPack_rAFydJof);
  hTable_free(&hTable_T2Zb4m8z);
  cPack_free(&cPack_W2RjhcLT);
  cPack_free(&cPack_PHVE7EB9);
  cPack_free(&cPack_W5YII2ZU);
  cPack_free(&cPack_R5aCcF9I);
  cPack_free(&cPack_llm7U96a);
  hTable_free(&hTable_NOntZksZ);
  cPack_free(&cPack_oziuCjUo);
  cPack_free(&cPack_3862M1I1);
  cPack_free(&cPack_ZDrTJJON);
  hTable_free(&hTable_U4YYujfG);
  cPack_free(&cPack_ysxZGKcT);
  cPack_free(&cPack_4QBdNQEV);
  cPack_free(&cPack_fLYWNz5o);
  hTable_free(&hTable_jbRSuQoA);
  cPack_free(&cPack_sZ4e1iT1);
  cPack_free(&cPack_LpO6e77h);
  cPack_free(&cPack_QHe78A3C);
  cPack_free(&cPack_Naorkc2G);
  cPack_free(&cPack_ijhTpQps);
  cPack_free(&cPack_fTD6v2FM);
  cPack_free(&cPack_KhheXSBq);
  cPack_free(&cPack_z5LFSMWT);
  cPack_free(&cPack_tdvuGjRQ);
}

HvTable *Heavy_CircleStrings::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0xCA4BE954: return &hTable_tF72jLxD; // del-1011-del1
    case 0x244CE923: return &hTable_7nrSdsCY; // del-1011-del2
    case 0xBF68886F: return &hTable_J6L0k6K1; // del-1011-del3
    case 0x55632928: return &hTable_P2MvgdzR; // del-1011-del4
    case 0x96995032: return &hTable_7eTEkNjZ; // del-1011-ref6
    case 0xBDA899C7: return &hTable_PeXzR7Y8; // del-1011-ref5
    case 0xC66C0031: return &hTable_1d9Pk3Lj; // del-1011-ref4
    case 0x87263188: return &hTable_SA4QtDyC; // del-1011-ref3
    case 0xABC596E9: return &hTable_5tceBofY; // del-1011-ref2
    case 0x4E55A0D9: return &hTable_dLmHrCPa; // del-1011-ref1
    case 0x1F09EB02: return &hTable_7pd6l9l0; // del-1118-del
    case 0xB5F303E3: return &hTable_H2niNe6T; // del-1181-del1
    case 0x6E18225F: return &hTable_iNNujHUH; // del-1181-del2
    case 0x272AEAC5: return &hTable_bjKuW1do; // del-1181-del3
    case 0x1EF3B8AB: return &hTable_vWahfTBD; // del-1181-del4
    case 0x908630F0: return &hTable_MKOVheRb; // del-1181-ref6
    case 0x571D5EBB: return &hTable_RQ7veuOM; // del-1181-ref5
    case 0xCD1DF3EE: return &hTable_D17gvZtz; // del-1181-ref4
    case 0x32F70D4: return &hTable_EuFIUT7N; // del-1181-ref3
    case 0x2649C1A0: return &hTable_0ARm2QU2; // del-1181-ref2
    case 0x2A4E9F1A: return &hTable_GPApmXrg; // del-1181-ref1
    case 0xCDA70ACE: return &hTable_gluxEKKN; // del-1280-del1
    case 0x1880FCC4: return &hTable_kxCIxlxO; // del-1311-del
    case 0xDA0DD3E: return &hTable_VBU3oJzZ; // del-1340-del1
    case 0xF059E6C5: return &hTable_3VwDfFas; // del-1418-delay
    case 0x1B841D52: return &hTable_T2Zb4m8z; // del-1497-delay
    case 0xDDCE7CE3: return &hTable_NOntZksZ; // del-1564-delay
    case 0x267B6FA5: return &hTable_U4YYujfG; // del-1615-delay
    case 0xA939BCAF: return &hTable_jbRSuQoA; // del-1666-delay
    default: return nullptr;
  }
}

void Heavy_CircleStrings::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xE9CDF196: { // 1474-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_1krYfiuI_sendMessage);
      break;
    }
    case 0x318534AD: { // 1474-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_LrV1qEG8_sendMessage);
      break;
    }
    case 0x73BE02B2: { // 1474-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_CaBFlCMx_sendMessage);
      break;
    }
    case 0x20FBEFA2: { // 1474-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_OJW32dt5_sendMessage);
      break;
    }
    case 0xB3D2781B: { // 1474-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_btfxZSV9_sendMessage);
      break;
    }
    case 0xEB419491: { // 1474-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_OWiIP9Hi_sendMessage);
      break;
    }
    case 0x287969C8: { // 1525-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_hs1AYf2L_sendMessage);
      break;
    }
    case 0xF758C0B7: { // 1525-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NBVaHytN_sendMessage);
      break;
    }
    case 0xEC622ADF: { // 1533-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_cltzsQBc_sendMessage);
      break;
    }
    case 0x706EBE7F: { // 1533-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_5Ye6ENuY_sendMessage);
      break;
    }
    case 0x961222E8: { // 1541-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_dmvH3riW_sendMessage);
      break;
    }
    case 0x5DFAB282: { // 1541-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_T1mZNjrD_sendMessage);
      break;
    }
    case 0xA73CF987: { // 1541-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_fOW6BxY7_sendMessage);
      break;
    }
    case 0xDE176410: { // 1541-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rZHYtPol_sendMessage);
      break;
    }
    case 0x8027D6B0: { // 1541-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RdjUOu7F_sendMessage);
      break;
    }
    case 0x5F30AB7: { // 1541-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_fSA64V8b_sendMessage);
      break;
    }
    case 0xDAF501EE: { // 1592-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_f9uBL7lX_sendMessage);
      break;
    }
    case 0x97DF0634: { // 1592-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zThL6YIP_sendMessage);
      break;
    }
    case 0xED939F1D: { // 1592-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_DoSJnQeD_sendMessage);
      break;
    }
    case 0x6824A5FB: { // 1592-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_9sFEbxH3_sendMessage);
      break;
    }
    case 0xD73B2171: { // 1592-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_pOYJ3K81_sendMessage);
      break;
    }
    case 0x42AF91EE: { // 1592-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Ct2oC0HR_sendMessage);
      break;
    }
    case 0xA1F992A3: { // 1643-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_q1WawPg5_sendMessage);
      break;
    }
    case 0x3A383FAD: { // 1643-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_9z8rJdN4_sendMessage);
      break;
    }
    case 0x5381C841: { // 1643-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_j8IQx296_sendMessage);
      break;
    }
    case 0x17698774: { // 1643-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_keerNrT4_sendMessage);
      break;
    }
    case 0xB064A0B2: { // 1643-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_IwcGKp9J_sendMessage);
      break;
    }
    case 0x48B0D745: { // 1643-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WXW8PZkj_sendMessage);
      break;
    }
    case 0xA97D2594: { // 1694-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_tUAVJ27W_sendMessage);
      break;
    }
    case 0x17BA9CFD: { // 1694-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4givbUdk_sendMessage);
      break;
    }
    case 0x563C50D1: { // 1702-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zzYAcezJ_sendMessage);
      break;
    }
    case 0x50C55BB2: { // 1702-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_aZVjgCWP_sendMessage);
      break;
    }
    case 0x60821E7E: { // 1710-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rzspvuVD_sendMessage);
      break;
    }
    case 0x2917EC99: { // 1710-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_gTFZarPP_sendMessage);
      break;
    }
    case 0xA773C924: { // 1722-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_PhnBTP9W_sendMessage);
      break;
    }
    case 0xCA11C605: { // 1722-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_tIBBdh1V_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_z15lKRD7_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_paFXzS1u_sendMessage);
      break;
    }
    case 0x40AA4AF1: { // changesound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Ua4JpGNy_sendMessage);
      break;
    }
    case 0xA41806F7: { // distortlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_TLdJkZ1G_sendMessage);
      break;
    }
    case 0xFCD12E4C: { // mastervolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_M2mBCAbA_sendMessage);
      break;
    }
    case 0xEF5F3308: { // panTranslation
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Q1srhvcR_sendMessage);
      break;
    }
    case 0x58FBFA93: { // phaseFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_XiEIWyN0_sendMessage);
      break;
    }
    case 0x8B2148DD: { // pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mun6KkPl_sendMessage);
      break;
    }
    case 0x4409C659: { // processeffects
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_i6IzAjGn_sendMessage);
      break;
    }
    case 0x7B795C5A: { // resetsing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_9b1R5hr7_sendMessage);
      break;
    }
    case 0xA987B741: { // reverbvolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_HwDrfPs2_sendMessage);
      break;
    }
    case 0x7AAE6786: { // sinPanAngle
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_VdQttYAI_sendMessage);
      break;
    }
    case 0x6731B2E0: { // sing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jmv2yw84_sendMessage);
      break;
    }
    case 0x57292445: { // singlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YsoAiR4E_sendMessage);
      break;
    }
    case 0xC7DE3B07: { // singpitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8BTEDG3f_sendMessage);
      break;
    }
    case 0x4E809B1C: { // testbutton
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_G6Ob6Ssc_sendMessage);
      break;
    }
    case 0x853B1BE7: { // velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_HTrUDWdv_sendMessage);
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


void Heavy_CircleStrings::cSlice_HKPZr0qj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_oqnpPqfR_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_RFRCPipE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_5KqWZKRf, 0, m, &cIf_5KqWZKRf_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_NQGY3h0R, 0, m, &cIf_NQGY3h0R_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_aLnvaTwv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_mbG2C8uD, 0, m, &cIf_mbG2C8uD_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_WynmliCp, 0, m, &cIf_WynmliCp_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_5HRueZcU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_8diG6sam_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_CjsIqQii, 0, m, &cIf_CjsIqQii_sendMessage);
}

void Heavy_CircleStrings::cUnop_AXWupoqf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_gWxAZYzI_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_TjDtJi3z, HV_BINOP_EQ, 1, m, &cBinop_TjDtJi3z_sendMessage);
}

void Heavy_CircleStrings::cUnop_nfLMOwyh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_gWxAZYzI_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_TjDtJi3z, HV_BINOP_EQ, 1, m, &cBinop_TjDtJi3z_sendMessage);
}

void Heavy_CircleStrings::cIf_CjsIqQii_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_nfLMOwyh_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_AXWupoqf_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_8diG6sam_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_CjsIqQii, 1, m, &cIf_CjsIqQii_sendMessage);
}

void Heavy_CircleStrings::cIf_NQGY3h0R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_2xoOe2wZ_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_WynmliCp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_0NUHkcKU_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_5KqWZKRf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_2xoOe2wZ_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_mbG2C8uD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_0NUHkcKU_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_oqnpPqfR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TjDtJi3z, HV_BINOP_EQ, 0, m, &cBinop_TjDtJi3z_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_kR4UNPgl_sendMessage);
}

void Heavy_CircleStrings::cBinop_gWxAZYzI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Hb8g6SRN_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_L778pcrI_sendMessage);
}

void Heavy_CircleStrings::cBinop_TjDtJi3z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DDd6X9iC_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_oQYDneeJ_sendMessage);
}

void Heavy_CircleStrings::cCast_DDd6X9iC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NQGY3h0R, 1, m, &cIf_NQGY3h0R_sendMessage);
}

void Heavy_CircleStrings::cCast_oQYDneeJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_mbG2C8uD, 1, m, &cIf_mbG2C8uD_sendMessage);
}

void Heavy_CircleStrings::cCast_L778pcrI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_WynmliCp, 1, m, &cIf_WynmliCp_sendMessage);
}

void Heavy_CircleStrings::cCast_Hb8g6SRN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_5KqWZKRf, 1, m, &cIf_5KqWZKRf_sendMessage);
}

void Heavy_CircleStrings::cBinop_kR4UNPgl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ctzHxdje_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cTabhead_kIUUkF3b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xDNuG4Kk, HV_BINOP_SUBTRACT, 0, m, &cBinop_xDNuG4Kk_sendMessage);
}

void Heavy_CircleStrings::cMsg_mleAknBD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UDWIPLsM_sendMessage);
}

void Heavy_CircleStrings::cSystem_UDWIPLsM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_G3vX1f5i_sendMessage);
}

void Heavy_CircleStrings::cVar_5j1fsrI9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yyH9YD7w_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_QaIHz2tN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_QaIHz2tN, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5nalfOoD, 0, m, &cDelay_5nalfOoD_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_x9m4h6ZG, 0, m, &sTabread_x9m4h6ZG_sendMessage);
}

void Heavy_CircleStrings::cDelay_5nalfOoD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5nalfOoD, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_x9m4h6ZG, 0, m, &sTabread_x9m4h6ZG_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5nalfOoD, 0, m, &cDelay_5nalfOoD_sendMessage);
}

void Heavy_CircleStrings::sTabread_x9m4h6ZG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_9CluecRu, HV_BINOP_SUBTRACT, 0, m, &cBinop_9CluecRu_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_hPTcDax0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SqBeCt2F, HV_BINOP_MAX, 0, m, &cBinop_SqBeCt2F_sendMessage);
}

void Heavy_CircleStrings::cBinop_G3vX1f5i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hPTcDax0, HV_BINOP_MULTIPLY, 0, m, &cBinop_hPTcDax0_sendMessage);
}

void Heavy_CircleStrings::cBinop_xDNuG4Kk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SDS025ra_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_x9m4h6ZG, 0, m, &sTabread_x9m4h6ZG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_968Njoia_sendMessage);
}

void Heavy_CircleStrings::cSystem_5pYAKXes_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9CluecRu, HV_BINOP_SUBTRACT, 1, m, &cBinop_9CluecRu_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5nalfOoD, 2, m, &cDelay_5nalfOoD_sendMessage);
}

void Heavy_CircleStrings::cMsg_yyH9YD7w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5pYAKXes_sendMessage);
}

void Heavy_CircleStrings::cMsg_SDS025ra_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_QaIHz2tN, 0, m, &cDelay_QaIHz2tN_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5nalfOoD, 0, m, &cDelay_5nalfOoD_sendMessage);
}

void Heavy_CircleStrings::cMsg_qu52Pgzy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_SqBeCt2F, HV_BINOP_MAX, 1, m, &cBinop_SqBeCt2F_sendMessage);
}

void Heavy_CircleStrings::cBinop_SqBeCt2F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xDNuG4Kk, HV_BINOP_SUBTRACT, 1, m, &cBinop_xDNuG4Kk_sendMessage);
}

void Heavy_CircleStrings::cCast_968Njoia_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_QaIHz2tN, 0, m, &cDelay_QaIHz2tN_sendMessage);
}

void Heavy_CircleStrings::cBinop_F6srl925_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_QaIHz2tN, 2, m, &cDelay_QaIHz2tN_sendMessage);
}

void Heavy_CircleStrings::cBinop_9CluecRu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_F6srl925_sendMessage);
}

void Heavy_CircleStrings::cCast_UCQKRibQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5j1fsrI9, 0, m, &cVar_5j1fsrI9_sendMessage);
  cMsg_mleAknBD_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_kIUUkF3b, 0, m, &cTabhead_kIUUkF3b_sendMessage);
}

void Heavy_CircleStrings::cTabhead_av6pSjq1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IbGnNs5J, HV_BINOP_SUBTRACT, 0, m, &cBinop_IbGnNs5J_sendMessage);
}

void Heavy_CircleStrings::cMsg_ckIRTuyA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_pVMD1ohP_sendMessage);
}

void Heavy_CircleStrings::cSystem_pVMD1ohP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Ge3aNd2u_sendMessage);
}

void Heavy_CircleStrings::cVar_xXOK1dHc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DPpmMwvm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_Bdojczm2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Bdojczm2, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WDtzSxru, 0, m, &cDelay_WDtzSxru_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_dtVPkZAP, 0, m, &sTabread_dtVPkZAP_sendMessage);
}

void Heavy_CircleStrings::cDelay_WDtzSxru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WDtzSxru, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_dtVPkZAP, 0, m, &sTabread_dtVPkZAP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WDtzSxru, 0, m, &cDelay_WDtzSxru_sendMessage);
}

void Heavy_CircleStrings::sTabread_dtVPkZAP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_7YmeOeXM, HV_BINOP_SUBTRACT, 0, m, &cBinop_7YmeOeXM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_ttbeu3Iq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NfCpvIqY, HV_BINOP_MAX, 0, m, &cBinop_NfCpvIqY_sendMessage);
}

void Heavy_CircleStrings::cBinop_Ge3aNd2u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ttbeu3Iq, HV_BINOP_MULTIPLY, 0, m, &cBinop_ttbeu3Iq_sendMessage);
}

void Heavy_CircleStrings::cBinop_IbGnNs5J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Qtt3AGkh_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_dtVPkZAP, 0, m, &sTabread_dtVPkZAP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_n3VpByK5_sendMessage);
}

void Heavy_CircleStrings::cSystem_tIgE1mPJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7YmeOeXM, HV_BINOP_SUBTRACT, 1, m, &cBinop_7YmeOeXM_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WDtzSxru, 2, m, &cDelay_WDtzSxru_sendMessage);
}

void Heavy_CircleStrings::cMsg_DPpmMwvm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tIgE1mPJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_Qtt3AGkh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Bdojczm2, 0, m, &cDelay_Bdojczm2_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WDtzSxru, 0, m, &cDelay_WDtzSxru_sendMessage);
}

void Heavy_CircleStrings::cMsg_mqQSqgMQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_NfCpvIqY, HV_BINOP_MAX, 1, m, &cBinop_NfCpvIqY_sendMessage);
}

void Heavy_CircleStrings::cBinop_NfCpvIqY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IbGnNs5J, HV_BINOP_SUBTRACT, 1, m, &cBinop_IbGnNs5J_sendMessage);
}

void Heavy_CircleStrings::cCast_n3VpByK5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Bdojczm2, 0, m, &cDelay_Bdojczm2_sendMessage);
}

void Heavy_CircleStrings::cBinop_MMSyMRuw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Bdojczm2, 2, m, &cDelay_Bdojczm2_sendMessage);
}

void Heavy_CircleStrings::cBinop_7YmeOeXM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_MMSyMRuw_sendMessage);
}

void Heavy_CircleStrings::cCast_boSHwOF2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xXOK1dHc, 0, m, &cVar_xXOK1dHc_sendMessage);
  cMsg_ckIRTuyA_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_av6pSjq1, 0, m, &cTabhead_av6pSjq1_sendMessage);
}

void Heavy_CircleStrings::cTabhead_WC8z9Hmn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PKVQ6lXZ, HV_BINOP_SUBTRACT, 0, m, &cBinop_PKVQ6lXZ_sendMessage);
}

void Heavy_CircleStrings::cMsg_piHRMNSv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lR0XwI2G_sendMessage);
}

void Heavy_CircleStrings::cSystem_lR0XwI2G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_3c7zWubC_sendMessage);
}

void Heavy_CircleStrings::cVar_AIGKHj7e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hKWzuxQ0_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_ZyRui00x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ZyRui00x, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yxSubJUs, 0, m, &cDelay_yxSubJUs_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_PZfknumT, 0, m, &sTabread_PZfknumT_sendMessage);
}

void Heavy_CircleStrings::cDelay_yxSubJUs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_yxSubJUs, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_PZfknumT, 0, m, &sTabread_PZfknumT_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yxSubJUs, 0, m, &cDelay_yxSubJUs_sendMessage);
}

void Heavy_CircleStrings::sTabread_PZfknumT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_MyL6BodP, HV_BINOP_SUBTRACT, 0, m, &cBinop_MyL6BodP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_SQascMui_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_csiaJxok, HV_BINOP_MAX, 0, m, &cBinop_csiaJxok_sendMessage);
}

void Heavy_CircleStrings::cBinop_3c7zWubC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SQascMui, HV_BINOP_MULTIPLY, 0, m, &cBinop_SQascMui_sendMessage);
}

void Heavy_CircleStrings::cBinop_PKVQ6lXZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZEhKVlTx_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_PZfknumT, 0, m, &sTabread_PZfknumT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wn4vLU41_sendMessage);
}

void Heavy_CircleStrings::cSystem_1gnIGI77_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MyL6BodP, HV_BINOP_SUBTRACT, 1, m, &cBinop_MyL6BodP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yxSubJUs, 2, m, &cDelay_yxSubJUs_sendMessage);
}

void Heavy_CircleStrings::cMsg_hKWzuxQ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1gnIGI77_sendMessage);
}

void Heavy_CircleStrings::cMsg_ZEhKVlTx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZyRui00x, 0, m, &cDelay_ZyRui00x_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yxSubJUs, 0, m, &cDelay_yxSubJUs_sendMessage);
}

void Heavy_CircleStrings::cMsg_TyOAdaoz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_csiaJxok, HV_BINOP_MAX, 1, m, &cBinop_csiaJxok_sendMessage);
}

void Heavy_CircleStrings::cBinop_csiaJxok_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PKVQ6lXZ, HV_BINOP_SUBTRACT, 1, m, &cBinop_PKVQ6lXZ_sendMessage);
}

void Heavy_CircleStrings::cCast_wn4vLU41_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZyRui00x, 0, m, &cDelay_ZyRui00x_sendMessage);
}

void Heavy_CircleStrings::cBinop_KDIX2EsO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZyRui00x, 2, m, &cDelay_ZyRui00x_sendMessage);
}

void Heavy_CircleStrings::cBinop_MyL6BodP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_KDIX2EsO_sendMessage);
}

void Heavy_CircleStrings::cCast_liMAAEF5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AIGKHj7e, 0, m, &cVar_AIGKHj7e_sendMessage);
  cMsg_piHRMNSv_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_WC8z9Hmn, 0, m, &cTabhead_WC8z9Hmn_sendMessage);
}

void Heavy_CircleStrings::cTabhead_mYnK0tAu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HLpI4KUw, HV_BINOP_SUBTRACT, 0, m, &cBinop_HLpI4KUw_sendMessage);
}

void Heavy_CircleStrings::cMsg_oRsRUyqb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gSuE9zqv_sendMessage);
}

void Heavy_CircleStrings::cSystem_gSuE9zqv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Iku0Flpq_sendMessage);
}

void Heavy_CircleStrings::cVar_5HSpMBj1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_00bYMx9B_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_t5oR0vUL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_t5oR0vUL, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PtMpfVsO, 0, m, &cDelay_PtMpfVsO_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Ir64mdiY, 0, m, &sTabread_Ir64mdiY_sendMessage);
}

void Heavy_CircleStrings::cDelay_PtMpfVsO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_PtMpfVsO, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Ir64mdiY, 0, m, &sTabread_Ir64mdiY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PtMpfVsO, 0, m, &cDelay_PtMpfVsO_sendMessage);
}

void Heavy_CircleStrings::sTabread_Ir64mdiY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_z2rjrwGw, HV_BINOP_SUBTRACT, 0, m, &cBinop_z2rjrwGw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_rmBbhg7l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Jdihwlui, HV_BINOP_MAX, 0, m, &cBinop_Jdihwlui_sendMessage);
}

void Heavy_CircleStrings::cBinop_Iku0Flpq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rmBbhg7l, HV_BINOP_MULTIPLY, 0, m, &cBinop_rmBbhg7l_sendMessage);
}

void Heavy_CircleStrings::cBinop_HLpI4KUw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qcYf4sr7_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Ir64mdiY, 0, m, &sTabread_Ir64mdiY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_58IX4NzQ_sendMessage);
}

void Heavy_CircleStrings::cSystem_4PbCDnFB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_z2rjrwGw, HV_BINOP_SUBTRACT, 1, m, &cBinop_z2rjrwGw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PtMpfVsO, 2, m, &cDelay_PtMpfVsO_sendMessage);
}

void Heavy_CircleStrings::cMsg_00bYMx9B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4PbCDnFB_sendMessage);
}

void Heavy_CircleStrings::cMsg_qcYf4sr7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_t5oR0vUL, 0, m, &cDelay_t5oR0vUL_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PtMpfVsO, 0, m, &cDelay_PtMpfVsO_sendMessage);
}

void Heavy_CircleStrings::cMsg_iFQrai8M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_Jdihwlui, HV_BINOP_MAX, 1, m, &cBinop_Jdihwlui_sendMessage);
}

void Heavy_CircleStrings::cBinop_Jdihwlui_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HLpI4KUw, HV_BINOP_SUBTRACT, 1, m, &cBinop_HLpI4KUw_sendMessage);
}

void Heavy_CircleStrings::cCast_58IX4NzQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_t5oR0vUL, 0, m, &cDelay_t5oR0vUL_sendMessage);
}

void Heavy_CircleStrings::cBinop_a49FbJtG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_t5oR0vUL, 2, m, &cDelay_t5oR0vUL_sendMessage);
}

void Heavy_CircleStrings::cBinop_z2rjrwGw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_a49FbJtG_sendMessage);
}

void Heavy_CircleStrings::cCast_Fg28pKnx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5HSpMBj1, 0, m, &cVar_5HSpMBj1_sendMessage);
  cMsg_oRsRUyqb_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_mYnK0tAu, 0, m, &cTabhead_mYnK0tAu_sendMessage);
}

void Heavy_CircleStrings::cMsg_Kk0137OX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PBQWdpCQ_sendMessage);
}

void Heavy_CircleStrings::cSystem_PBQWdpCQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_fBM9Qs5Z_sendMessage);
}

void Heavy_CircleStrings::cDelay_z87Dh8Tt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_z87Dh8Tt, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_r8OGdDcn, 0, m, &cDelay_r8OGdDcn_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_z87Dh8Tt, 0, m, &cDelay_z87Dh8Tt_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_yOCoPsi8, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_r8OGdDcn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_r8OGdDcn, m);
  cMsg_EYTsgVFN_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_J5g29FUg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_1t54lwP9_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_UfqBsxtN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kOvJfTCj_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_tF72jLxD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FA6htYBh_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_z87Dh8Tt, 2, m, &cDelay_z87Dh8Tt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_onC7UJeI_sendMessage);
}

void Heavy_CircleStrings::cMsg_kOvJfTCj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_tF72jLxD, 0, m, &hTable_tF72jLxD_sendMessage);
}

void Heavy_CircleStrings::cBinop_fBM9Qs5Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_UfqBsxtN_sendMessage);
}

void Heavy_CircleStrings::cMsg_EYTsgVFN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_tF72jLxD, 0, m, &hTable_tF72jLxD_sendMessage);
}

void Heavy_CircleStrings::cCast_onC7UJeI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_z87Dh8Tt, 0, m, &cDelay_z87Dh8Tt_sendMessage);
}

void Heavy_CircleStrings::cMsg_FA6htYBh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_r8OGdDcn, 2, m, &cDelay_r8OGdDcn_sendMessage);
}

void Heavy_CircleStrings::cMsg_1t54lwP9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_yOCoPsi8, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_gwPbZWaw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dzoRlbkC_sendMessage);
}

void Heavy_CircleStrings::cSystem_dzoRlbkC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_SVzSn2nE_sendMessage);
}

void Heavy_CircleStrings::cDelay_4rvjLqIO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4rvjLqIO, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_n5BVPYq7, 0, m, &cDelay_n5BVPYq7_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4rvjLqIO, 0, m, &cDelay_4rvjLqIO_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_EFIjaKYf, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_n5BVPYq7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_n5BVPYq7, m);
  cMsg_mMmuhTjD_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_nH0JQMlF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_Ya2OEzTF_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_sVOzStdm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RqJbChJG_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_7nrSdsCY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ow6xvdt1_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4rvjLqIO, 2, m, &cDelay_4rvjLqIO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mVDgAQvr_sendMessage);
}

void Heavy_CircleStrings::cMsg_RqJbChJG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_7nrSdsCY, 0, m, &hTable_7nrSdsCY_sendMessage);
}

void Heavy_CircleStrings::cBinop_SVzSn2nE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_sVOzStdm_sendMessage);
}

void Heavy_CircleStrings::cMsg_mMmuhTjD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_7nrSdsCY, 0, m, &hTable_7nrSdsCY_sendMessage);
}

void Heavy_CircleStrings::cCast_mVDgAQvr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_4rvjLqIO, 0, m, &cDelay_4rvjLqIO_sendMessage);
}

void Heavy_CircleStrings::cMsg_Ow6xvdt1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_n5BVPYq7, 2, m, &cDelay_n5BVPYq7_sendMessage);
}

void Heavy_CircleStrings::cMsg_Ya2OEzTF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_EFIjaKYf, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_ygYyviTm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ulhzAyqi_sendMessage);
}

void Heavy_CircleStrings::cSystem_ulhzAyqi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Be55txWe_sendMessage);
}

void Heavy_CircleStrings::cDelay_N3KudGG7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_N3KudGG7, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rrG98Bwv, 0, m, &cDelay_rrG98Bwv_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_N3KudGG7, 0, m, &cDelay_N3KudGG7_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_zrqCHOpG, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_rrG98Bwv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rrG98Bwv, m);
  cMsg_yTTCjaPZ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_ALSSUAG0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_BoHChiWx_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_yWs2rPEL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eHluWxnw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_J6L0k6K1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LSJU2lJ0_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_N3KudGG7, 2, m, &cDelay_N3KudGG7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vNvSEEGi_sendMessage);
}

void Heavy_CircleStrings::cMsg_eHluWxnw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_J6L0k6K1, 0, m, &hTable_J6L0k6K1_sendMessage);
}

void Heavy_CircleStrings::cBinop_Be55txWe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_yWs2rPEL_sendMessage);
}

void Heavy_CircleStrings::cMsg_yTTCjaPZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_J6L0k6K1, 0, m, &hTable_J6L0k6K1_sendMessage);
}

void Heavy_CircleStrings::cCast_vNvSEEGi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_N3KudGG7, 0, m, &cDelay_N3KudGG7_sendMessage);
}

void Heavy_CircleStrings::cMsg_LSJU2lJ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_rrG98Bwv, 2, m, &cDelay_rrG98Bwv_sendMessage);
}

void Heavy_CircleStrings::cMsg_BoHChiWx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_zrqCHOpG, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_2M1qUQoG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Kogqk5uc_sendMessage);
}

void Heavy_CircleStrings::cSystem_Kogqk5uc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_WzaN0nAr_sendMessage);
}

void Heavy_CircleStrings::cDelay_ZfjdhF1L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ZfjdhF1L, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EOpXC1W4, 0, m, &cDelay_EOpXC1W4_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZfjdhF1L, 0, m, &cDelay_ZfjdhF1L_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_P1eCsL7Y, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_EOpXC1W4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_EOpXC1W4, m);
  cMsg_JQHioHPv_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_Ca1qSOmN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_gZ8kzSHs_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_YDQkIUhn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xcemI69E_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_P2MvgdzR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1v9H4B4b_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZfjdhF1L, 2, m, &cDelay_ZfjdhF1L_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UnYRDTq7_sendMessage);
}

void Heavy_CircleStrings::cMsg_xcemI69E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_P2MvgdzR, 0, m, &hTable_P2MvgdzR_sendMessage);
}

void Heavy_CircleStrings::cBinop_WzaN0nAr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_YDQkIUhn_sendMessage);
}

void Heavy_CircleStrings::cMsg_JQHioHPv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_P2MvgdzR, 0, m, &hTable_P2MvgdzR_sendMessage);
}

void Heavy_CircleStrings::cCast_UnYRDTq7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZfjdhF1L, 0, m, &cDelay_ZfjdhF1L_sendMessage);
}

void Heavy_CircleStrings::cMsg_1v9H4B4b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_EOpXC1W4, 2, m, &cDelay_EOpXC1W4_sendMessage);
}

void Heavy_CircleStrings::cMsg_gZ8kzSHs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_P1eCsL7Y, 1, m, NULL);
}

void Heavy_CircleStrings::cIf_h9fsvoa8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_ivmZlMw2_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_3dJO74My_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_F6S9vmjG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_znbhiJ7q, HV_BINOP_POW, 0, m, &cBinop_znbhiJ7q_sendMessage);
}

void Heavy_CircleStrings::cBinop_znbhiJ7q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_boDE35qT_sendMessage);
}

void Heavy_CircleStrings::cBinop_Kqz9rNn9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_KCWIIvvO_sendMessage);
}

void Heavy_CircleStrings::cCast_AfBX9Ql2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_h9fsvoa8, 0, m, &cIf_h9fsvoa8_sendMessage);
}

void Heavy_CircleStrings::cCast_JNxuWVKg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Klsaf36A_sendMessage);
}

void Heavy_CircleStrings::cBinop_Klsaf36A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_h9fsvoa8, 1, m, &cIf_h9fsvoa8_sendMessage);
}

void Heavy_CircleStrings::cBinop_3dJO74My_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_Kqz9rNn9_sendMessage);
}

void Heavy_CircleStrings::cMsg_ivmZlMw2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_boDE35qT_sendMessage);
}

void Heavy_CircleStrings::cBinop_KCWIIvvO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_znbhiJ7q, HV_BINOP_POW, 1, m, &cBinop_znbhiJ7q_sendMessage);
  cMsg_F6S9vmjG_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_kqRLkns0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_tQYMYoyu, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_4rXMETIp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_5UP2AEDg, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_AJWdXXcs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_GpA2KWuE_sendMessage);
}

void Heavy_CircleStrings::cBinop_GpA2KWuE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_0edz74iL_sendMessage);
}

void Heavy_CircleStrings::cVar_XAMVlRva_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FZaFfzSA, HV_BINOP_MULTIPLY, 0, m, &cBinop_FZaFfzSA_sendMessage);
}

void Heavy_CircleStrings::cMsg_eY6aZjmT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vyF5qQhp_sendMessage);
}

void Heavy_CircleStrings::cSystem_vyF5qQhp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Q5OvaFDl_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_FZaFfzSA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_bBrtInES_sendMessage);
}

void Heavy_CircleStrings::cBinop_nsJexiwd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FZaFfzSA, HV_BINOP_MULTIPLY, 1, m, &cBinop_FZaFfzSA_sendMessage);
}

void Heavy_CircleStrings::cMsg_Q5OvaFDl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_nsJexiwd_sendMessage);
}

void Heavy_CircleStrings::cBinop_bBrtInES_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_d1FiZwUK_sendMessage);
}

void Heavy_CircleStrings::cBinop_d1FiZwUK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_hdy1muFF_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_9N99uJQo, m);
}

void Heavy_CircleStrings::cBinop_hdy1muFF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_8PIcDixP, m);
}

void Heavy_CircleStrings::cVar_y0NVUvgc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JNxuWVKg_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AfBX9Ql2_sendMessage);
}

void Heavy_CircleStrings::cVar_c1l2Btyy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_AJWdXXcs_sendMessage);
}

void Heavy_CircleStrings::cVar_mfOqSYJr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_fbwFwAzo_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_O2PWEEpt, 0, m, &cIf_O2PWEEpt_sendMessage);
}

void Heavy_CircleStrings::cVar_MiiDkY87_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_PeCaRqVO_sendMessage);
}

void Heavy_CircleStrings::cIf_O2PWEEpt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_fCXa49Bx_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_bVOVqcAb, 0, m, &cVar_bVOVqcAb_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_fbwFwAzo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_O2PWEEpt, 1, m, &cIf_O2PWEEpt_sendMessage);
}

void Heavy_CircleStrings::cBinop_PeCaRqVO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_AfItOn6x_sendMessage);
}

void Heavy_CircleStrings::cBinop_AfItOn6x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7TBiYVzc, 0, m, &cVar_7TBiYVzc_sendMessage);
}

void Heavy_CircleStrings::cTabhead_CuoYbRfc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4hPrLGiY, HV_BINOP_SUBTRACT, 0, m, &cBinop_4hPrLGiY_sendMessage);
}

void Heavy_CircleStrings::cMsg_23bm6hwN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NDQvW3xi_sendMessage);
}

void Heavy_CircleStrings::cSystem_NDQvW3xi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_IlhfXNry_sendMessage);
}

void Heavy_CircleStrings::cVar_c5DRnk7T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CKN4apmU_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_Gxxln8iC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Gxxln8iC, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QpPKeRxL, 0, m, &cDelay_QpPKeRxL_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_kg18CcEz, 0, m, &sTabread_kg18CcEz_sendMessage);
}

void Heavy_CircleStrings::cDelay_QpPKeRxL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_QpPKeRxL, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_kg18CcEz, 0, m, &sTabread_kg18CcEz_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QpPKeRxL, 0, m, &cDelay_QpPKeRxL_sendMessage);
}

void Heavy_CircleStrings::sTabread_kg18CcEz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_a98IUOet, HV_BINOP_SUBTRACT, 0, m, &cBinop_a98IUOet_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_Hp9R4mCJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RObSsiV5, HV_BINOP_MAX, 0, m, &cBinop_RObSsiV5_sendMessage);
}

void Heavy_CircleStrings::cBinop_IlhfXNry_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Hp9R4mCJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_Hp9R4mCJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_4hPrLGiY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yTYASH5J_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_kg18CcEz, 0, m, &sTabread_kg18CcEz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EeDZ7DpT_sendMessage);
}

void Heavy_CircleStrings::cSystem_1UKis2E7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_a98IUOet, HV_BINOP_SUBTRACT, 1, m, &cBinop_a98IUOet_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QpPKeRxL, 2, m, &cDelay_QpPKeRxL_sendMessage);
}

void Heavy_CircleStrings::cMsg_CKN4apmU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1UKis2E7_sendMessage);
}

void Heavy_CircleStrings::cMsg_yTYASH5J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Gxxln8iC, 0, m, &cDelay_Gxxln8iC_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QpPKeRxL, 0, m, &cDelay_QpPKeRxL_sendMessage);
}

void Heavy_CircleStrings::cMsg_S0u2W3N0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_RObSsiV5, HV_BINOP_MAX, 1, m, &cBinop_RObSsiV5_sendMessage);
}

void Heavy_CircleStrings::cBinop_RObSsiV5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4hPrLGiY, HV_BINOP_SUBTRACT, 1, m, &cBinop_4hPrLGiY_sendMessage);
}

void Heavy_CircleStrings::cCast_EeDZ7DpT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Gxxln8iC, 0, m, &cDelay_Gxxln8iC_sendMessage);
}

void Heavy_CircleStrings::cBinop_U7elYj7V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Gxxln8iC, 2, m, &cDelay_Gxxln8iC_sendMessage);
}

void Heavy_CircleStrings::cBinop_a98IUOet_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_U7elYj7V_sendMessage);
}

void Heavy_CircleStrings::cCast_a2QjvNGC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_c5DRnk7T, 0, m, &cVar_c5DRnk7T_sendMessage);
  cMsg_23bm6hwN_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_CuoYbRfc, 0, m, &cTabhead_CuoYbRfc_sendMessage);
}

void Heavy_CircleStrings::cMsg_PgLznuSx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Ov90Qzgn_sendMessage);
}

void Heavy_CircleStrings::cSystem_Ov90Qzgn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_IAV0igPx_sendMessage);
}

void Heavy_CircleStrings::cDelay_wBZcLlID_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wBZcLlID, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_drOH7R8m, 0, m, &cDelay_drOH7R8m_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wBZcLlID, 0, m, &cDelay_wBZcLlID_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_SJUWITpc, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_drOH7R8m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_drOH7R8m, m);
  cMsg_S2otTH8e_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_95m3web6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_OcQojqzz_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_iJLNWZCp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jT6xY81v_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_7eTEkNjZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BV6MMFdu_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wBZcLlID, 2, m, &cDelay_wBZcLlID_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zw8pY7Zi_sendMessage);
}

void Heavy_CircleStrings::cMsg_jT6xY81v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_7eTEkNjZ, 0, m, &hTable_7eTEkNjZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_IAV0igPx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_iJLNWZCp_sendMessage);
}

void Heavy_CircleStrings::cMsg_S2otTH8e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_7eTEkNjZ, 0, m, &hTable_7eTEkNjZ_sendMessage);
}

void Heavy_CircleStrings::cCast_zw8pY7Zi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wBZcLlID, 0, m, &cDelay_wBZcLlID_sendMessage);
}

void Heavy_CircleStrings::cMsg_BV6MMFdu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_drOH7R8m, 2, m, &cDelay_drOH7R8m_sendMessage);
}

void Heavy_CircleStrings::cMsg_OcQojqzz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_SJUWITpc, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_VCs3GKXV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TLnCDuYF, HV_BINOP_SUBTRACT, 0, m, &cBinop_TLnCDuYF_sendMessage);
}

void Heavy_CircleStrings::cMsg_7mEbylLK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NhYcCe1i_sendMessage);
}

void Heavy_CircleStrings::cSystem_NhYcCe1i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_c4dM9PAQ_sendMessage);
}

void Heavy_CircleStrings::cVar_V60o2kg6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_e08at0kx_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_UMLyX8Ct_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UMLyX8Ct, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Xfri0Pyh, 0, m, &cDelay_Xfri0Pyh_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ewlwumIS, 0, m, &sTabread_ewlwumIS_sendMessage);
}

void Heavy_CircleStrings::cDelay_Xfri0Pyh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Xfri0Pyh, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ewlwumIS, 0, m, &sTabread_ewlwumIS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Xfri0Pyh, 0, m, &cDelay_Xfri0Pyh_sendMessage);
}

void Heavy_CircleStrings::sTabread_ewlwumIS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_zhn2SFEz, HV_BINOP_SUBTRACT, 0, m, &cBinop_zhn2SFEz_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_MX2rMrFL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_G7xiE0Rp, HV_BINOP_MAX, 0, m, &cBinop_G7xiE0Rp_sendMessage);
}

void Heavy_CircleStrings::cBinop_c4dM9PAQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MX2rMrFL, HV_BINOP_MULTIPLY, 0, m, &cBinop_MX2rMrFL_sendMessage);
}

void Heavy_CircleStrings::cBinop_TLnCDuYF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9A3LT2f3_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ewlwumIS, 0, m, &sTabread_ewlwumIS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FBnQLtd9_sendMessage);
}

void Heavy_CircleStrings::cSystem_A06EOErU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zhn2SFEz, HV_BINOP_SUBTRACT, 1, m, &cBinop_zhn2SFEz_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Xfri0Pyh, 2, m, &cDelay_Xfri0Pyh_sendMessage);
}

void Heavy_CircleStrings::cMsg_e08at0kx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_A06EOErU_sendMessage);
}

void Heavy_CircleStrings::cMsg_9A3LT2f3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_UMLyX8Ct, 0, m, &cDelay_UMLyX8Ct_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Xfri0Pyh, 0, m, &cDelay_Xfri0Pyh_sendMessage);
}

void Heavy_CircleStrings::cMsg_IgpieN4C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_G7xiE0Rp, HV_BINOP_MAX, 1, m, &cBinop_G7xiE0Rp_sendMessage);
}

void Heavy_CircleStrings::cBinop_G7xiE0Rp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TLnCDuYF, HV_BINOP_SUBTRACT, 1, m, &cBinop_TLnCDuYF_sendMessage);
}

void Heavy_CircleStrings::cCast_FBnQLtd9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_UMLyX8Ct, 0, m, &cDelay_UMLyX8Ct_sendMessage);
}

void Heavy_CircleStrings::cBinop_RdJGXrhJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_UMLyX8Ct, 2, m, &cDelay_UMLyX8Ct_sendMessage);
}

void Heavy_CircleStrings::cBinop_zhn2SFEz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_RdJGXrhJ_sendMessage);
}

void Heavy_CircleStrings::cCast_ODC1ox6M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_V60o2kg6, 0, m, &cVar_V60o2kg6_sendMessage);
  cMsg_7mEbylLK_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_VCs3GKXV, 0, m, &cTabhead_VCs3GKXV_sendMessage);
}

void Heavy_CircleStrings::cMsg_E6hzZEXn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tPq56uLL_sendMessage);
}

void Heavy_CircleStrings::cSystem_tPq56uLL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ihnsPHml_sendMessage);
}

void Heavy_CircleStrings::cDelay_8M0SuqD0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8M0SuqD0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ppxb3bze, 0, m, &cDelay_ppxb3bze_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8M0SuqD0, 0, m, &cDelay_8M0SuqD0_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_cgdHBny3, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_ppxb3bze_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ppxb3bze, m);
  cMsg_ZtYrJAe1_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_1esmZNfc_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_nny7jp1Y_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_H0jTv7da_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sXmsH4p5_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_PeXzR7Y8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_c39lox3J_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8M0SuqD0, 2, m, &cDelay_8M0SuqD0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UmubHRsN_sendMessage);
}

void Heavy_CircleStrings::cMsg_sXmsH4p5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_PeXzR7Y8, 0, m, &hTable_PeXzR7Y8_sendMessage);
}

void Heavy_CircleStrings::cBinop_ihnsPHml_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_H0jTv7da_sendMessage);
}

void Heavy_CircleStrings::cMsg_ZtYrJAe1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_PeXzR7Y8, 0, m, &hTable_PeXzR7Y8_sendMessage);
}

void Heavy_CircleStrings::cCast_UmubHRsN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8M0SuqD0, 0, m, &cDelay_8M0SuqD0_sendMessage);
}

void Heavy_CircleStrings::cMsg_c39lox3J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_ppxb3bze, 2, m, &cDelay_ppxb3bze_sendMessage);
}

void Heavy_CircleStrings::cMsg_nny7jp1Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_cgdHBny3, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_PLUfVxIB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ai2IH2og, HV_BINOP_SUBTRACT, 0, m, &cBinop_ai2IH2og_sendMessage);
}

void Heavy_CircleStrings::cMsg_ahKukNUl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_pzkKOoGy_sendMessage);
}

void Heavy_CircleStrings::cSystem_pzkKOoGy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_NEtkHEnf_sendMessage);
}

void Heavy_CircleStrings::cVar_PMByxuth_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_85Fi06oO_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_gqJCNVTd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gqJCNVTd, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8jglIGRG, 0, m, &cDelay_8jglIGRG_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_z6exZkKw, 0, m, &sTabread_z6exZkKw_sendMessage);
}

void Heavy_CircleStrings::cDelay_8jglIGRG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8jglIGRG, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_z6exZkKw, 0, m, &sTabread_z6exZkKw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8jglIGRG, 0, m, &cDelay_8jglIGRG_sendMessage);
}

void Heavy_CircleStrings::sTabread_z6exZkKw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_UN97iPuq, HV_BINOP_SUBTRACT, 0, m, &cBinop_UN97iPuq_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_pyBn6H8I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TOfNNYyM, HV_BINOP_MAX, 0, m, &cBinop_TOfNNYyM_sendMessage);
}

void Heavy_CircleStrings::cBinop_NEtkHEnf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pyBn6H8I, HV_BINOP_MULTIPLY, 0, m, &cBinop_pyBn6H8I_sendMessage);
}

void Heavy_CircleStrings::cBinop_ai2IH2og_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_azcOz6Mz_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_z6exZkKw, 0, m, &sTabread_z6exZkKw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FCRecADQ_sendMessage);
}

void Heavy_CircleStrings::cSystem_zQcDck0L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UN97iPuq, HV_BINOP_SUBTRACT, 1, m, &cBinop_UN97iPuq_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8jglIGRG, 2, m, &cDelay_8jglIGRG_sendMessage);
}

void Heavy_CircleStrings::cMsg_85Fi06oO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zQcDck0L_sendMessage);
}

void Heavy_CircleStrings::cMsg_azcOz6Mz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_gqJCNVTd, 0, m, &cDelay_gqJCNVTd_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8jglIGRG, 0, m, &cDelay_8jglIGRG_sendMessage);
}

void Heavy_CircleStrings::cMsg_7kzcVlRE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_TOfNNYyM, HV_BINOP_MAX, 1, m, &cBinop_TOfNNYyM_sendMessage);
}

void Heavy_CircleStrings::cBinop_TOfNNYyM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ai2IH2og, HV_BINOP_SUBTRACT, 1, m, &cBinop_ai2IH2og_sendMessage);
}

void Heavy_CircleStrings::cCast_FCRecADQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gqJCNVTd, 0, m, &cDelay_gqJCNVTd_sendMessage);
}

void Heavy_CircleStrings::cBinop_NW0L8ZlR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gqJCNVTd, 2, m, &cDelay_gqJCNVTd_sendMessage);
}

void Heavy_CircleStrings::cBinop_UN97iPuq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_NW0L8ZlR_sendMessage);
}

void Heavy_CircleStrings::cCast_e5N1Rtsk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PMByxuth, 0, m, &cVar_PMByxuth_sendMessage);
  cMsg_ahKukNUl_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_PLUfVxIB, 0, m, &cTabhead_PLUfVxIB_sendMessage);
}

void Heavy_CircleStrings::cMsg_0MvhqiQP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1PXhrOzw_sendMessage);
}

void Heavy_CircleStrings::cSystem_1PXhrOzw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_PekwkkUr_sendMessage);
}

void Heavy_CircleStrings::cDelay_5OAvWcs2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5OAvWcs2, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DNKHeYk9, 0, m, &cDelay_DNKHeYk9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5OAvWcs2, 0, m, &cDelay_5OAvWcs2_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Ly4JY4Uz, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_DNKHeYk9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DNKHeYk9, m);
  cMsg_jan3jR2y_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_riFx6RJt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_rUX2BL3E_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_xFAISEvZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pbPqr4dW_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_1d9Pk3Lj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_y40cO2KG_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5OAvWcs2, 2, m, &cDelay_5OAvWcs2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EIcgFJop_sendMessage);
}

void Heavy_CircleStrings::cMsg_pbPqr4dW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_1d9Pk3Lj, 0, m, &hTable_1d9Pk3Lj_sendMessage);
}

void Heavy_CircleStrings::cBinop_PekwkkUr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_xFAISEvZ_sendMessage);
}

void Heavy_CircleStrings::cMsg_jan3jR2y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_1d9Pk3Lj, 0, m, &hTable_1d9Pk3Lj_sendMessage);
}

void Heavy_CircleStrings::cCast_EIcgFJop_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5OAvWcs2, 0, m, &cDelay_5OAvWcs2_sendMessage);
}

void Heavy_CircleStrings::cMsg_y40cO2KG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_DNKHeYk9, 2, m, &cDelay_DNKHeYk9_sendMessage);
}

void Heavy_CircleStrings::cMsg_rUX2BL3E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Ly4JY4Uz, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_jZeiPhad_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aejPcpw3, HV_BINOP_SUBTRACT, 0, m, &cBinop_aejPcpw3_sendMessage);
}

void Heavy_CircleStrings::cMsg_JFeds759_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_99biHUpp_sendMessage);
}

void Heavy_CircleStrings::cSystem_99biHUpp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_u1fojxbv_sendMessage);
}

void Heavy_CircleStrings::cVar_3M0C3fcL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aFG4cPOl_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_BZBtISZC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BZBtISZC, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_V45rRlZa, 0, m, &cDelay_V45rRlZa_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ADJ4E8Aa, 0, m, &sTabread_ADJ4E8Aa_sendMessage);
}

void Heavy_CircleStrings::cDelay_V45rRlZa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_V45rRlZa, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ADJ4E8Aa, 0, m, &sTabread_ADJ4E8Aa_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_V45rRlZa, 0, m, &cDelay_V45rRlZa_sendMessage);
}

void Heavy_CircleStrings::sTabread_ADJ4E8Aa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_25CQc7gH, HV_BINOP_SUBTRACT, 0, m, &cBinop_25CQc7gH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_KpJQxEo6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6eoylmrU, HV_BINOP_MAX, 0, m, &cBinop_6eoylmrU_sendMessage);
}

void Heavy_CircleStrings::cBinop_u1fojxbv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KpJQxEo6, HV_BINOP_MULTIPLY, 0, m, &cBinop_KpJQxEo6_sendMessage);
}

void Heavy_CircleStrings::cBinop_aejPcpw3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_spuxezHv_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ADJ4E8Aa, 0, m, &sTabread_ADJ4E8Aa_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EMPgohBJ_sendMessage);
}

void Heavy_CircleStrings::cSystem_12j2aUw1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_25CQc7gH, HV_BINOP_SUBTRACT, 1, m, &cBinop_25CQc7gH_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_V45rRlZa, 2, m, &cDelay_V45rRlZa_sendMessage);
}

void Heavy_CircleStrings::cMsg_aFG4cPOl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_12j2aUw1_sendMessage);
}

void Heavy_CircleStrings::cMsg_spuxezHv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_BZBtISZC, 0, m, &cDelay_BZBtISZC_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_V45rRlZa, 0, m, &cDelay_V45rRlZa_sendMessage);
}

void Heavy_CircleStrings::cMsg_4Bb6W8OR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_6eoylmrU, HV_BINOP_MAX, 1, m, &cBinop_6eoylmrU_sendMessage);
}

void Heavy_CircleStrings::cBinop_6eoylmrU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aejPcpw3, HV_BINOP_SUBTRACT, 1, m, &cBinop_aejPcpw3_sendMessage);
}

void Heavy_CircleStrings::cCast_EMPgohBJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_BZBtISZC, 0, m, &cDelay_BZBtISZC_sendMessage);
}

void Heavy_CircleStrings::cBinop_hae1JYGp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_BZBtISZC, 2, m, &cDelay_BZBtISZC_sendMessage);
}

void Heavy_CircleStrings::cBinop_25CQc7gH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_hae1JYGp_sendMessage);
}

void Heavy_CircleStrings::cCast_VxWj8tWr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3M0C3fcL, 0, m, &cVar_3M0C3fcL_sendMessage);
  cMsg_JFeds759_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_jZeiPhad, 0, m, &cTabhead_jZeiPhad_sendMessage);
}

void Heavy_CircleStrings::cMsg_lkLxvsYr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NnA2KjoH_sendMessage);
}

void Heavy_CircleStrings::cSystem_NnA2KjoH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_flDswWro_sendMessage);
}

void Heavy_CircleStrings::cDelay_fIcMy63j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fIcMy63j, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cIdiLorX, 0, m, &cDelay_cIdiLorX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fIcMy63j, 0, m, &cDelay_fIcMy63j_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_3K4y4xq5, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_cIdiLorX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cIdiLorX, m);
  cMsg_wspo42Zl_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_y9rkWTLd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_buVdTJJt_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_aPPiH2te_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uUmmQbhf_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_SA4QtDyC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wqYqVj9D_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fIcMy63j, 2, m, &cDelay_fIcMy63j_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aoPx7wQ2_sendMessage);
}

void Heavy_CircleStrings::cMsg_uUmmQbhf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_SA4QtDyC, 0, m, &hTable_SA4QtDyC_sendMessage);
}

void Heavy_CircleStrings::cBinop_flDswWro_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_aPPiH2te_sendMessage);
}

void Heavy_CircleStrings::cMsg_wspo42Zl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_SA4QtDyC, 0, m, &hTable_SA4QtDyC_sendMessage);
}

void Heavy_CircleStrings::cCast_aoPx7wQ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_fIcMy63j, 0, m, &cDelay_fIcMy63j_sendMessage);
}

void Heavy_CircleStrings::cMsg_wqYqVj9D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_cIdiLorX, 2, m, &cDelay_cIdiLorX_sendMessage);
}

void Heavy_CircleStrings::cMsg_buVdTJJt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_3K4y4xq5, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_maWMKIGC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JBE1lQNm, HV_BINOP_SUBTRACT, 0, m, &cBinop_JBE1lQNm_sendMessage);
}

void Heavy_CircleStrings::cMsg_3DE1aU21_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PBIPsqPZ_sendMessage);
}

void Heavy_CircleStrings::cSystem_PBIPsqPZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9LgXnDIo_sendMessage);
}

void Heavy_CircleStrings::cVar_OwltTNXy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_V5yiWXH2_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_Al7JX1Sm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Al7JX1Sm, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vc3f3pmH, 0, m, &cDelay_vc3f3pmH_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_7HAQFNy7, 0, m, &sTabread_7HAQFNy7_sendMessage);
}

void Heavy_CircleStrings::cDelay_vc3f3pmH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vc3f3pmH, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_7HAQFNy7, 0, m, &sTabread_7HAQFNy7_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vc3f3pmH, 0, m, &cDelay_vc3f3pmH_sendMessage);
}

void Heavy_CircleStrings::sTabread_7HAQFNy7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_yTDKfpaG, HV_BINOP_SUBTRACT, 0, m, &cBinop_yTDKfpaG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_A8ubiPYp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wd3QDUyF, HV_BINOP_MAX, 0, m, &cBinop_wd3QDUyF_sendMessage);
}

void Heavy_CircleStrings::cBinop_9LgXnDIo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A8ubiPYp, HV_BINOP_MULTIPLY, 0, m, &cBinop_A8ubiPYp_sendMessage);
}

void Heavy_CircleStrings::cBinop_JBE1lQNm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rMX1dkiA_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_7HAQFNy7, 0, m, &sTabread_7HAQFNy7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6REq93nu_sendMessage);
}

void Heavy_CircleStrings::cSystem_1QLWw1PW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yTDKfpaG, HV_BINOP_SUBTRACT, 1, m, &cBinop_yTDKfpaG_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vc3f3pmH, 2, m, &cDelay_vc3f3pmH_sendMessage);
}

void Heavy_CircleStrings::cMsg_V5yiWXH2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1QLWw1PW_sendMessage);
}

void Heavy_CircleStrings::cMsg_rMX1dkiA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Al7JX1Sm, 0, m, &cDelay_Al7JX1Sm_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vc3f3pmH, 0, m, &cDelay_vc3f3pmH_sendMessage);
}

void Heavy_CircleStrings::cMsg_HwlT9UdO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_wd3QDUyF, HV_BINOP_MAX, 1, m, &cBinop_wd3QDUyF_sendMessage);
}

void Heavy_CircleStrings::cBinop_wd3QDUyF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JBE1lQNm, HV_BINOP_SUBTRACT, 1, m, &cBinop_JBE1lQNm_sendMessage);
}

void Heavy_CircleStrings::cCast_6REq93nu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Al7JX1Sm, 0, m, &cDelay_Al7JX1Sm_sendMessage);
}

void Heavy_CircleStrings::cBinop_MssT6oVj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Al7JX1Sm, 2, m, &cDelay_Al7JX1Sm_sendMessage);
}

void Heavy_CircleStrings::cBinop_yTDKfpaG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_MssT6oVj_sendMessage);
}

void Heavy_CircleStrings::cCast_wkN4TKrf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OwltTNXy, 0, m, &cVar_OwltTNXy_sendMessage);
  cMsg_3DE1aU21_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_maWMKIGC, 0, m, &cTabhead_maWMKIGC_sendMessage);
}

void Heavy_CircleStrings::cMsg_i0i6UmxR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VPOfZtlE_sendMessage);
}

void Heavy_CircleStrings::cSystem_VPOfZtlE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_M95SwQWw_sendMessage);
}

void Heavy_CircleStrings::cDelay_hBsfoo5b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hBsfoo5b, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nXJVovvK, 0, m, &cDelay_nXJVovvK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hBsfoo5b, 0, m, &cDelay_hBsfoo5b_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_lhnEtGVC, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_nXJVovvK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nXJVovvK, m);
  cMsg_9ebXianD_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_4vUSBJbt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_sOOmbaAR_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_qKOn7rLF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_99mVjTEF_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_5tceBofY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KSIVxYfF_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hBsfoo5b, 2, m, &cDelay_hBsfoo5b_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nV48ukAi_sendMessage);
}

void Heavy_CircleStrings::cMsg_99mVjTEF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_5tceBofY, 0, m, &hTable_5tceBofY_sendMessage);
}

void Heavy_CircleStrings::cBinop_M95SwQWw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_qKOn7rLF_sendMessage);
}

void Heavy_CircleStrings::cMsg_9ebXianD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_5tceBofY, 0, m, &hTable_5tceBofY_sendMessage);
}

void Heavy_CircleStrings::cCast_nV48ukAi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_hBsfoo5b, 0, m, &cDelay_hBsfoo5b_sendMessage);
}

void Heavy_CircleStrings::cMsg_KSIVxYfF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_nXJVovvK, 2, m, &cDelay_nXJVovvK_sendMessage);
}

void Heavy_CircleStrings::cMsg_sOOmbaAR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_lhnEtGVC, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_g3X0oNQK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_y1JmMg6Z, HV_BINOP_SUBTRACT, 0, m, &cBinop_y1JmMg6Z_sendMessage);
}

void Heavy_CircleStrings::cMsg_MAgD4Fnd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CldUjFV2_sendMessage);
}

void Heavy_CircleStrings::cSystem_CldUjFV2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_yHTwTQ1A_sendMessage);
}

void Heavy_CircleStrings::cVar_7WMxPwCV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_riFaUGvp_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_wWjBweMY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wWjBweMY, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ML2prmuF, 0, m, &cDelay_ML2prmuF_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_vnSavNzS, 0, m, &sTabread_vnSavNzS_sendMessage);
}

void Heavy_CircleStrings::cDelay_ML2prmuF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ML2prmuF, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_vnSavNzS, 0, m, &sTabread_vnSavNzS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ML2prmuF, 0, m, &cDelay_ML2prmuF_sendMessage);
}

void Heavy_CircleStrings::sTabread_vnSavNzS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_V3wjye24, HV_BINOP_SUBTRACT, 0, m, &cBinop_V3wjye24_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_6psaCQY0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pPySnQUP, HV_BINOP_MAX, 0, m, &cBinop_pPySnQUP_sendMessage);
}

void Heavy_CircleStrings::cBinop_yHTwTQ1A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6psaCQY0, HV_BINOP_MULTIPLY, 0, m, &cBinop_6psaCQY0_sendMessage);
}

void Heavy_CircleStrings::cBinop_y1JmMg6Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MUI9CfeA_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_vnSavNzS, 0, m, &sTabread_vnSavNzS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4DoBcvwG_sendMessage);
}

void Heavy_CircleStrings::cSystem_CLdOkVwM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_V3wjye24, HV_BINOP_SUBTRACT, 1, m, &cBinop_V3wjye24_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ML2prmuF, 2, m, &cDelay_ML2prmuF_sendMessage);
}

void Heavy_CircleStrings::cMsg_riFaUGvp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CLdOkVwM_sendMessage);
}

void Heavy_CircleStrings::cMsg_MUI9CfeA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_wWjBweMY, 0, m, &cDelay_wWjBweMY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ML2prmuF, 0, m, &cDelay_ML2prmuF_sendMessage);
}

void Heavy_CircleStrings::cMsg_JUdUUjxI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_pPySnQUP, HV_BINOP_MAX, 1, m, &cBinop_pPySnQUP_sendMessage);
}

void Heavy_CircleStrings::cBinop_pPySnQUP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_y1JmMg6Z, HV_BINOP_SUBTRACT, 1, m, &cBinop_y1JmMg6Z_sendMessage);
}

void Heavy_CircleStrings::cCast_4DoBcvwG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wWjBweMY, 0, m, &cDelay_wWjBweMY_sendMessage);
}

void Heavy_CircleStrings::cBinop_ksRzUXxx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wWjBweMY, 2, m, &cDelay_wWjBweMY_sendMessage);
}

void Heavy_CircleStrings::cBinop_V3wjye24_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ksRzUXxx_sendMessage);
}

void Heavy_CircleStrings::cCast_9ds0lv70_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7WMxPwCV, 0, m, &cVar_7WMxPwCV_sendMessage);
  cMsg_MAgD4Fnd_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_g3X0oNQK, 0, m, &cTabhead_g3X0oNQK_sendMessage);
}

void Heavy_CircleStrings::cMsg_IpG7KGBy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iYMQXfRD_sendMessage);
}

void Heavy_CircleStrings::cSystem_iYMQXfRD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_vCD9Udgm_sendMessage);
}

void Heavy_CircleStrings::cDelay_3EH3n1tm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3EH3n1tm, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_h8H3m3EN, 0, m, &cDelay_h8H3m3EN_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3EH3n1tm, 0, m, &cDelay_3EH3n1tm_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_qTcizVOy, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_h8H3m3EN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_h8H3m3EN, m);
  cMsg_FqaM6dQb_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_M5SAsrli_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_Le7vw6oD_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_m6vhxXBP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QcmmOSCM_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_dLmHrCPa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kGz9VM9s_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3EH3n1tm, 2, m, &cDelay_3EH3n1tm_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RojxzRDu_sendMessage);
}

void Heavy_CircleStrings::cMsg_QcmmOSCM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_dLmHrCPa, 0, m, &hTable_dLmHrCPa_sendMessage);
}

void Heavy_CircleStrings::cBinop_vCD9Udgm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_m6vhxXBP_sendMessage);
}

void Heavy_CircleStrings::cMsg_FqaM6dQb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_dLmHrCPa, 0, m, &hTable_dLmHrCPa_sendMessage);
}

void Heavy_CircleStrings::cCast_RojxzRDu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_3EH3n1tm, 0, m, &cDelay_3EH3n1tm_sendMessage);
}

void Heavy_CircleStrings::cMsg_kGz9VM9s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_h8H3m3EN, 2, m, &cDelay_h8H3m3EN_sendMessage);
}

void Heavy_CircleStrings::cMsg_Le7vw6oD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_qTcizVOy, 1, m, NULL);
}

void Heavy_CircleStrings::cVar_bVOVqcAb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XAMVlRva, 0, m, &cVar_XAMVlRva_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_z3Zmlm2Z, 0, m, &cVar_z3Zmlm2Z_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_SfS2LCdm, 0, m, &cVar_SfS2LCdm_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_JDmMifvj, 0, m, &cVar_JDmMifvj_sendMessage);
}

void Heavy_CircleStrings::cVar_7TBiYVzc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_g6CIt6kW_sendMessage);
}

void Heavy_CircleStrings::cPack_PKF7PVhU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_cdJCmkYF, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_z3Zmlm2Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_N1ACoR8R, HV_BINOP_MULTIPLY, 0, m, &cBinop_N1ACoR8R_sendMessage);
}

void Heavy_CircleStrings::cMsg_Ey42lQN1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iNxDNgF3_sendMessage);
}

void Heavy_CircleStrings::cSystem_iNxDNgF3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3rVDI83L_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_N1ACoR8R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_eoYClw9q_sendMessage);
}

void Heavy_CircleStrings::cBinop_4Nah49o5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_N1ACoR8R, HV_BINOP_MULTIPLY, 1, m, &cBinop_N1ACoR8R_sendMessage);
}

void Heavy_CircleStrings::cMsg_3rVDI83L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_4Nah49o5_sendMessage);
}

void Heavy_CircleStrings::cBinop_eoYClw9q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_AzdAKfVZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_AzdAKfVZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_SecPrPmw_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_a4pJ4tBl, m);
}

void Heavy_CircleStrings::cBinop_SecPrPmw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_brQlZRWU, m);
}

void Heavy_CircleStrings::cVar_SfS2LCdm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6b4PKSTS, HV_BINOP_MULTIPLY, 0, m, &cBinop_6b4PKSTS_sendMessage);
}

void Heavy_CircleStrings::cMsg_Y0dctD9L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fK8pUo2p_sendMessage);
}

void Heavy_CircleStrings::cSystem_fK8pUo2p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YKUhS8TH_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_6b4PKSTS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_YU3tRUcm_sendMessage);
}

void Heavy_CircleStrings::cBinop_DDtifl0d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6b4PKSTS, HV_BINOP_MULTIPLY, 1, m, &cBinop_6b4PKSTS_sendMessage);
}

void Heavy_CircleStrings::cMsg_YKUhS8TH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_DDtifl0d_sendMessage);
}

void Heavy_CircleStrings::cBinop_YU3tRUcm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_pFCJASf9_sendMessage);
}

void Heavy_CircleStrings::cBinop_pFCJASf9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_CkeDhNPd_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_mcHitFHU, m);
}

void Heavy_CircleStrings::cBinop_CkeDhNPd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Jlo5XtCL, m);
}

void Heavy_CircleStrings::cVar_JDmMifvj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z3WMiBk7, HV_BINOP_MULTIPLY, 0, m, &cBinop_Z3WMiBk7_sendMessage);
}

void Heavy_CircleStrings::cMsg_EbMkKzYS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jmaw9tM0_sendMessage);
}

void Heavy_CircleStrings::cSystem_jmaw9tM0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sjKUrrT7_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_Z3WMiBk7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_rZuwIC6V_sendMessage);
}

void Heavy_CircleStrings::cBinop_BOXBYXUi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z3WMiBk7, HV_BINOP_MULTIPLY, 1, m, &cBinop_Z3WMiBk7_sendMessage);
}

void Heavy_CircleStrings::cMsg_sjKUrrT7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_BOXBYXUi_sendMessage);
}

void Heavy_CircleStrings::cBinop_rZuwIC6V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Q9rGrWAQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_Q9rGrWAQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_mONY4ICA_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_EhS0NGur, m);
}

void Heavy_CircleStrings::cBinop_mONY4ICA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_RKOEHNn6, m);
}

void Heavy_CircleStrings::cBinop_0edz74iL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_4rXMETIp, 0, m, &cPack_4rXMETIp_sendMessage);
}

void Heavy_CircleStrings::cMsg_fCXa49Bx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_bVOVqcAb, 0, m, &cVar_bVOVqcAb_sendMessage);
}

void Heavy_CircleStrings::cBinop_g6CIt6kW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_PKF7PVhU, 0, m, &cPack_PKF7PVhU_sendMessage);
}

void Heavy_CircleStrings::cBinop_boDE35qT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_kqRLkns0, 0, m, &cPack_kqRLkns0_sendMessage);
}

void Heavy_CircleStrings::cIf_CiLdjMWU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_TbXPdjK2_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_YUpRWXbO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cUnop_YUpRWXbO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_cRpzNXBh_sendMessage);
}

void Heavy_CircleStrings::cCast_It5CUmFn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_CiLdjMWU, 0, m, &cIf_CiLdjMWU_sendMessage);
}

void Heavy_CircleStrings::cCast_sRbVEDyN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_patHKk8u_sendMessage);
}

void Heavy_CircleStrings::cMsg_TbXPdjK2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_y0NVUvgc, 0, m, &cVar_y0NVUvgc_sendMessage);
}

void Heavy_CircleStrings::cBinop_cRpzNXBh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_YYVbOIV5_sendMessage);
}

void Heavy_CircleStrings::cBinop_YYVbOIV5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_37bJOG5N_sendMessage);
}

void Heavy_CircleStrings::cBinop_37bJOG5N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_y0NVUvgc, 0, m, &cVar_y0NVUvgc_sendMessage);
}

void Heavy_CircleStrings::cBinop_patHKk8u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_CiLdjMWU, 1, m, &cIf_CiLdjMWU_sendMessage);
}

void Heavy_CircleStrings::cBinop_buFpM9zT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_sRbVEDyN_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_It5CUmFn_sendMessage);
}

void Heavy_CircleStrings::cBinop_RO3BXbOp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_buFpM9zT_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_EZ9L39DR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_JB06C96E_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_JB06C96E_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_sZqgkG00, 1, m, &cDelay_sZqgkG00_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_paQwnSQk_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_sZqgkG00_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sZqgkG00, m);
  cMsg_b9g17FAm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_JB06C96E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_sZqgkG00, 0, m, &cDelay_sZqgkG00_sendMessage);
}

void Heavy_CircleStrings::cCast_paQwnSQk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_sZqgkG00, 0, m, &cDelay_sZqgkG00_sendMessage);
}

void Heavy_CircleStrings::cVar_eXMH4m8j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_M3d0YYPw, 0, m, &cPack_M3d0YYPw_sendMessage);
}

void Heavy_CircleStrings::cVar_fGDcFREV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_SimGoFBc_sendMessage);
}

void Heavy_CircleStrings::cVar_aXRUd8Q0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_0zaNXyxt_sendMessage);
}

void Heavy_CircleStrings::cPack_JPXLwiTS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_VtQlkvAg, 0, m, NULL);
}

void Heavy_CircleStrings::cUnop_vbGqTHDk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_tjE9Ag1b_sendMessage);
}

void Heavy_CircleStrings::cBinop_yN7LaAqh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_vbGqTHDk_sendMessage);
}

void Heavy_CircleStrings::cPack_HaWqh4wh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_bhZshD8N, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_MI7nGxP0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_XdyqLjdB_sendMessage);
}

void Heavy_CircleStrings::cMsg_bGNig5OW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZFQWj5JU_sendMessage);
}

void Heavy_CircleStrings::cSystem_ZFQWj5JU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_lk1d5idT_sendMessage);
}

void Heavy_CircleStrings::cDelay_Zod67Idy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Zod67Idy, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UyaJAj3F, 0, m, &cDelay_UyaJAj3F_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Zod67Idy, 0, m, &cDelay_Zod67Idy_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_l2RShlhk, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_UyaJAj3F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UyaJAj3F, m);
  cMsg_z0hSs3og_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_Jl6p5ADJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_X28GPGL7_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_au0PwxpS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PggasYs6_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_7pd6l9l0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0fGSgMbv_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Zod67Idy, 2, m, &cDelay_Zod67Idy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Wagk4FlB_sendMessage);
}

void Heavy_CircleStrings::cMsg_PggasYs6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_7pd6l9l0, 0, m, &hTable_7pd6l9l0_sendMessage);
}

void Heavy_CircleStrings::cBinop_lk1d5idT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_au0PwxpS_sendMessage);
}

void Heavy_CircleStrings::cMsg_z0hSs3og_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_7pd6l9l0, 0, m, &hTable_7pd6l9l0_sendMessage);
}

void Heavy_CircleStrings::cCast_Wagk4FlB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Zod67Idy, 0, m, &cDelay_Zod67Idy_sendMessage);
}

void Heavy_CircleStrings::cMsg_0fGSgMbv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_UyaJAj3F, 2, m, &cDelay_UyaJAj3F_sendMessage);
}

void Heavy_CircleStrings::cMsg_X28GPGL7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_l2RShlhk, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_6DhUNtsl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3WRdkH52_sendMessage);
}

void Heavy_CircleStrings::cSystem_3WRdkH52_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_PNWOh3A4_sendMessage);
}

void Heavy_CircleStrings::cVar_avBng3Ba_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SCW4hfC4_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_fyhjuCiz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_hzR9qwlM_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_FQCx2ezb, m);
}

void Heavy_CircleStrings::cBinop_PNWOh3A4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_cT3Kw7cW, m);
}

void Heavy_CircleStrings::cMsg_SCW4hfC4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fyhjuCiz_sendMessage);
}

void Heavy_CircleStrings::cBinop_hzR9qwlM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_em0hUoV4, m);
}

void Heavy_CircleStrings::cMsg_vb2DwimO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Paod1h2Q_sendMessage);
}

void Heavy_CircleStrings::cSystem_Paod1h2Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_VI2Efqt7_sendMessage);
}

void Heavy_CircleStrings::cVar_w7tZvEtH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PcRXZSmD_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_eb43bgY9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_hPTUscKW_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_EOhHSEso, m);
}

void Heavy_CircleStrings::cBinop_VI2Efqt7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LAWICRd4, m);
}

void Heavy_CircleStrings::cMsg_PcRXZSmD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eb43bgY9_sendMessage);
}

void Heavy_CircleStrings::cBinop_hPTUscKW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_d1IbXx7G, m);
}

void Heavy_CircleStrings::cBinop_mnx6kSMZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HkhDlHUX_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_5CKDsjgE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_pZsc3cBw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_L0lM95En_sendMessage);
}

void Heavy_CircleStrings::cCast_pZsc3cBw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mnx6kSMZ, HV_BINOP_DIVIDE, 1, m, &cBinop_mnx6kSMZ_sendMessage);
}

void Heavy_CircleStrings::cCast_L0lM95En_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mnx6kSMZ, HV_BINOP_DIVIDE, 0, m, &cBinop_mnx6kSMZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_tjE9Ag1b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ckrgqE7S_sendMessage);
}

void Heavy_CircleStrings::cBinop_SimGoFBc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_yN7LaAqh_sendMessage);
}

void Heavy_CircleStrings::cBinop_ckrgqE7S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mnx6kSMZ, HV_BINOP_DIVIDE, 0, m, &cBinop_mnx6kSMZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_XdyqLjdB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_HaWqh4wh, 0, m, &cPack_HaWqh4wh_sendMessage);
}

void Heavy_CircleStrings::cBinop_0zaNXyxt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_5CKDsjgE_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_JPXLwiTS, 0, m, &cPack_JPXLwiTS_sendMessage);
}

void Heavy_CircleStrings::cMsg_D1LiZIcv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_aXRUd8Q0, 0, m, &cVar_aXRUd8Q0_sendMessage);
}

void Heavy_CircleStrings::cMsg_SvJBgjSN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_MI7nGxP0, 0, m, &cVar_MI7nGxP0_sendMessage);
}

void Heavy_CircleStrings::cMsg_HkhDlHUX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_q51XVYIe, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_oTbLg06O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6Umr0WeK, HV_BINOP_MULTIPLY, 0, m, &cBinop_6Umr0WeK_sendMessage);
}

void Heavy_CircleStrings::cMsg_3DQ3sY9y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ruY4O9lB_sendMessage);
}

void Heavy_CircleStrings::cSystem_ruY4O9lB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aWU2Sbuy_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_6Umr0WeK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_aQp9ZZob_sendMessage);
}

void Heavy_CircleStrings::cBinop_M42HKjn7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6Umr0WeK, HV_BINOP_MULTIPLY, 1, m, &cBinop_6Umr0WeK_sendMessage);
}

void Heavy_CircleStrings::cMsg_aWU2Sbuy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_M42HKjn7_sendMessage);
}

void Heavy_CircleStrings::cBinop_aQp9ZZob_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Igd3iYQE_sendMessage);
}

void Heavy_CircleStrings::cBinop_Igd3iYQE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_juN3C07b_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_HweexQ0D, m);
}

void Heavy_CircleStrings::cBinop_juN3C07b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_vHaM0Yj2, m);
}

void Heavy_CircleStrings::cVar_BbOWz0oz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SnpasltI, HV_BINOP_MULTIPLY, 0, m, &cBinop_SnpasltI_sendMessage);
}

void Heavy_CircleStrings::cMsg_Ck7wBAPk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_c7FKuDVA_sendMessage);
}

void Heavy_CircleStrings::cSystem_c7FKuDVA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eCCPPUTY_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_SnpasltI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_RZhR7W47_sendMessage);
}

void Heavy_CircleStrings::cBinop_DTjTV7XU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SnpasltI, HV_BINOP_MULTIPLY, 1, m, &cBinop_SnpasltI_sendMessage);
}

void Heavy_CircleStrings::cMsg_eCCPPUTY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_DTjTV7XU_sendMessage);
}

void Heavy_CircleStrings::cBinop_RZhR7W47_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_VA7Hqz68_sendMessage);
}

void Heavy_CircleStrings::cBinop_VA7Hqz68_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_vBcaEAZD_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_o0WZYLOy, m);
}

void Heavy_CircleStrings::cBinop_vBcaEAZD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_dfZuOA8O, m);
}

void Heavy_CircleStrings::cVar_LcsWtpaK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pGh4hS16, HV_BINOP_MULTIPLY, 0, m, &cBinop_pGh4hS16_sendMessage);
}

void Heavy_CircleStrings::cMsg_Ord1Ac5H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TPl5uWOl_sendMessage);
}

void Heavy_CircleStrings::cSystem_TPl5uWOl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Go89Gm2K_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_pGh4hS16_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_jqVeeecV_sendMessage);
}

void Heavy_CircleStrings::cBinop_QK1XWyT0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pGh4hS16, HV_BINOP_MULTIPLY, 1, m, &cBinop_pGh4hS16_sendMessage);
}

void Heavy_CircleStrings::cMsg_Go89Gm2K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_QK1XWyT0_sendMessage);
}

void Heavy_CircleStrings::cBinop_jqVeeecV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_L75xlgCV_sendMessage);
}

void Heavy_CircleStrings::cBinop_L75xlgCV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_2v63vXeq_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_pG2pWCWO, m);
}

void Heavy_CircleStrings::cBinop_2v63vXeq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_WFEO5EsB, m);
}

void Heavy_CircleStrings::cMsg_wlxQM0ah_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AsthP2H8_sendMessage);
}

void Heavy_CircleStrings::cSystem_AsthP2H8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Qn4me8jB_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_EOf4mgEx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_nHlBOLF8_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_s0bjndjn, 0, m, &cIf_s0bjndjn_sendMessage);
}

void Heavy_CircleStrings::cIf_s0bjndjn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_EMlB2wx3_sendMessage(_c, 0, m);
      cMsg_tJP1ZWAp_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_k3Ngizyv_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_m6uDiBeP_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_2kyiKVyj, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_nHlBOLF8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_s0bjndjn, 1, m, &cIf_s0bjndjn_sendMessage);
}

void Heavy_CircleStrings::cMsg_k3Ngizyv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_zLpu6IXT_sendMessage);
}

void Heavy_CircleStrings::cBinop_zLpu6IXT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_UIee5DUI, m);
}

void Heavy_CircleStrings::cBinop_m6uDiBeP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ASunWU2g_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_ASunWU2g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_u7fjy4Vy_sendMessage);
}

void Heavy_CircleStrings::cBinop_u7fjy4Vy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bqTlcnH0_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_bqTlcnH0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_C0pvJT0d_sendMessage);
}

void Heavy_CircleStrings::cBinop_C0pvJT0d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_KRgqb7cJ, m);
}

void Heavy_CircleStrings::cBinop_1y98J5yB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_vx7ryrAT, m);
}

void Heavy_CircleStrings::cMsg_Qn4me8jB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_1y98J5yB_sendMessage);
}

void Heavy_CircleStrings::cMsg_EMlB2wx3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_m6uDiBeP_sendMessage);
}

void Heavy_CircleStrings::cMsg_tJP1ZWAp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_UIee5DUI, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_2kyiKVyj, m);
}

void Heavy_CircleStrings::cBinop_h5K3m3Ph_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BbOWz0oz, 0, m, &cVar_BbOWz0oz_sendMessage);
}

void Heavy_CircleStrings::cBinop_w2GNZaVB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oTbLg06O, 0, m, &cVar_oTbLg06O_sendMessage);
}

void Heavy_CircleStrings::cBinop_WoJXDSTL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LcsWtpaK, 0, m, &cVar_LcsWtpaK_sendMessage);
}

void Heavy_CircleStrings::cCast_kv0Ug3AN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_2M97mHRR, m);
}

void Heavy_CircleStrings::cCast_ZcE7g7BI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_w2GNZaVB_sendMessage);
}

void Heavy_CircleStrings::cCast_7bNSJvQ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_h5K3m3Ph_sendMessage);
}

void Heavy_CircleStrings::cCast_LzRGLE57_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_WoJXDSTL_sendMessage);
}

void Heavy_CircleStrings::cTabhead_NAISSBs9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BFwBdnNC, HV_BINOP_SUBTRACT, 0, m, &cBinop_BFwBdnNC_sendMessage);
}

void Heavy_CircleStrings::cMsg_a461nEda_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TryE9aQN_sendMessage);
}

void Heavy_CircleStrings::cSystem_TryE9aQN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_AM9XiPZv_sendMessage);
}

void Heavy_CircleStrings::cVar_338lqcMq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1bUWh6sD_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_iiFO9Qam_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_iiFO9Qam, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9xu8HRIH, 0, m, &cDelay_9xu8HRIH_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_2mcQ7TTy, 0, m, &sTabread_2mcQ7TTy_sendMessage);
}

void Heavy_CircleStrings::cDelay_9xu8HRIH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9xu8HRIH, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_2mcQ7TTy, 0, m, &sTabread_2mcQ7TTy_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9xu8HRIH, 0, m, &cDelay_9xu8HRIH_sendMessage);
}

void Heavy_CircleStrings::sTabread_2mcQ7TTy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_uCDo9BZW, HV_BINOP_SUBTRACT, 0, m, &cBinop_uCDo9BZW_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_UIVjcG6e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8QiX75mH, HV_BINOP_MAX, 0, m, &cBinop_8QiX75mH_sendMessage);
}

void Heavy_CircleStrings::cBinop_AM9XiPZv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UIVjcG6e, HV_BINOP_MULTIPLY, 0, m, &cBinop_UIVjcG6e_sendMessage);
}

void Heavy_CircleStrings::cBinop_BFwBdnNC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_O6D2ZwWB_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_2mcQ7TTy, 0, m, &sTabread_2mcQ7TTy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HaEoQaSc_sendMessage);
}

void Heavy_CircleStrings::cSystem_OxhZEVEU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uCDo9BZW, HV_BINOP_SUBTRACT, 1, m, &cBinop_uCDo9BZW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9xu8HRIH, 2, m, &cDelay_9xu8HRIH_sendMessage);
}

void Heavy_CircleStrings::cMsg_1bUWh6sD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OxhZEVEU_sendMessage);
}

void Heavy_CircleStrings::cMsg_O6D2ZwWB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_iiFO9Qam, 0, m, &cDelay_iiFO9Qam_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9xu8HRIH, 0, m, &cDelay_9xu8HRIH_sendMessage);
}

void Heavy_CircleStrings::cMsg_7wmNKdly_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_8QiX75mH, HV_BINOP_MAX, 1, m, &cBinop_8QiX75mH_sendMessage);
}

void Heavy_CircleStrings::cBinop_8QiX75mH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BFwBdnNC, HV_BINOP_SUBTRACT, 1, m, &cBinop_BFwBdnNC_sendMessage);
}

void Heavy_CircleStrings::cCast_HaEoQaSc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_iiFO9Qam, 0, m, &cDelay_iiFO9Qam_sendMessage);
}

void Heavy_CircleStrings::cBinop_QHUrqDJJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_iiFO9Qam, 2, m, &cDelay_iiFO9Qam_sendMessage);
}

void Heavy_CircleStrings::cBinop_uCDo9BZW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_QHUrqDJJ_sendMessage);
}

void Heavy_CircleStrings::cCast_koLOMtyE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_338lqcMq, 0, m, &cVar_338lqcMq_sendMessage);
  cMsg_a461nEda_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_NAISSBs9, 0, m, &cTabhead_NAISSBs9_sendMessage);
}

void Heavy_CircleStrings::cTabhead_g9YQT7pb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wqBX4nnk, HV_BINOP_SUBTRACT, 0, m, &cBinop_wqBX4nnk_sendMessage);
}

void Heavy_CircleStrings::cMsg_eIPWsrKU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yeSMoFIG_sendMessage);
}

void Heavy_CircleStrings::cSystem_yeSMoFIG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_xtQbBlRJ_sendMessage);
}

void Heavy_CircleStrings::cVar_GSqwYHnM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Fzh5t5DR_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_yGf1eehY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_yGf1eehY, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SMJAKoSE, 0, m, &cDelay_SMJAKoSE_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_witvQ5Vz, 0, m, &sTabread_witvQ5Vz_sendMessage);
}

void Heavy_CircleStrings::cDelay_SMJAKoSE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SMJAKoSE, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_witvQ5Vz, 0, m, &sTabread_witvQ5Vz_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SMJAKoSE, 0, m, &cDelay_SMJAKoSE_sendMessage);
}

void Heavy_CircleStrings::sTabread_witvQ5Vz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ptifLpdp, HV_BINOP_SUBTRACT, 0, m, &cBinop_ptifLpdp_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_kiAQH46F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9E8jTcoQ, HV_BINOP_MAX, 0, m, &cBinop_9E8jTcoQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_xtQbBlRJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kiAQH46F, HV_BINOP_MULTIPLY, 0, m, &cBinop_kiAQH46F_sendMessage);
}

void Heavy_CircleStrings::cBinop_wqBX4nnk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nam7gFBH_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_witvQ5Vz, 0, m, &sTabread_witvQ5Vz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jkTyKZFv_sendMessage);
}

void Heavy_CircleStrings::cSystem_b62VJ1Sl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ptifLpdp, HV_BINOP_SUBTRACT, 1, m, &cBinop_ptifLpdp_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SMJAKoSE, 2, m, &cDelay_SMJAKoSE_sendMessage);
}

void Heavy_CircleStrings::cMsg_Fzh5t5DR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_b62VJ1Sl_sendMessage);
}

void Heavy_CircleStrings::cMsg_nam7gFBH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_yGf1eehY, 0, m, &cDelay_yGf1eehY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SMJAKoSE, 0, m, &cDelay_SMJAKoSE_sendMessage);
}

void Heavy_CircleStrings::cMsg_JuqK2d1S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_9E8jTcoQ, HV_BINOP_MAX, 1, m, &cBinop_9E8jTcoQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_9E8jTcoQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wqBX4nnk, HV_BINOP_SUBTRACT, 1, m, &cBinop_wqBX4nnk_sendMessage);
}

void Heavy_CircleStrings::cCast_jkTyKZFv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_yGf1eehY, 0, m, &cDelay_yGf1eehY_sendMessage);
}

void Heavy_CircleStrings::cBinop_WjBwsQ5R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_yGf1eehY, 2, m, &cDelay_yGf1eehY_sendMessage);
}

void Heavy_CircleStrings::cBinop_ptifLpdp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_WjBwsQ5R_sendMessage);
}

void Heavy_CircleStrings::cCast_WfozPGHr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GSqwYHnM, 0, m, &cVar_GSqwYHnM_sendMessage);
  cMsg_eIPWsrKU_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_g9YQT7pb, 0, m, &cTabhead_g9YQT7pb_sendMessage);
}

void Heavy_CircleStrings::cTabhead_MAMw6hWl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8g5rtl6F, HV_BINOP_SUBTRACT, 0, m, &cBinop_8g5rtl6F_sendMessage);
}

void Heavy_CircleStrings::cMsg_kdyihSIx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1BW1Y860_sendMessage);
}

void Heavy_CircleStrings::cSystem_1BW1Y860_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_cSCBiNry_sendMessage);
}

void Heavy_CircleStrings::cVar_GCGsJSYu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OJ9kNVlr_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_dCBPuy7f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_dCBPuy7f, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sYpXCy5F, 0, m, &cDelay_sYpXCy5F_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_yY6X7Nds, 0, m, &sTabread_yY6X7Nds_sendMessage);
}

void Heavy_CircleStrings::cDelay_sYpXCy5F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sYpXCy5F, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_yY6X7Nds, 0, m, &sTabread_yY6X7Nds_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sYpXCy5F, 0, m, &cDelay_sYpXCy5F_sendMessage);
}

void Heavy_CircleStrings::sTabread_yY6X7Nds_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_8Z6XKY1k, HV_BINOP_SUBTRACT, 0, m, &cBinop_8Z6XKY1k_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_BdelcCN4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QmOJFA93, HV_BINOP_MAX, 0, m, &cBinop_QmOJFA93_sendMessage);
}

void Heavy_CircleStrings::cBinop_cSCBiNry_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BdelcCN4, HV_BINOP_MULTIPLY, 0, m, &cBinop_BdelcCN4_sendMessage);
}

void Heavy_CircleStrings::cBinop_8g5rtl6F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_28ZRvD4k_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_yY6X7Nds, 0, m, &sTabread_yY6X7Nds_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LSGr6mWW_sendMessage);
}

void Heavy_CircleStrings::cSystem_EDgWs7bz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8Z6XKY1k, HV_BINOP_SUBTRACT, 1, m, &cBinop_8Z6XKY1k_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sYpXCy5F, 2, m, &cDelay_sYpXCy5F_sendMessage);
}

void Heavy_CircleStrings::cMsg_OJ9kNVlr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_EDgWs7bz_sendMessage);
}

void Heavy_CircleStrings::cMsg_28ZRvD4k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_dCBPuy7f, 0, m, &cDelay_dCBPuy7f_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sYpXCy5F, 0, m, &cDelay_sYpXCy5F_sendMessage);
}

void Heavy_CircleStrings::cMsg_2DDtNDZw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_QmOJFA93, HV_BINOP_MAX, 1, m, &cBinop_QmOJFA93_sendMessage);
}

void Heavy_CircleStrings::cBinop_QmOJFA93_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8g5rtl6F, HV_BINOP_SUBTRACT, 1, m, &cBinop_8g5rtl6F_sendMessage);
}

void Heavy_CircleStrings::cCast_LSGr6mWW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_dCBPuy7f, 0, m, &cDelay_dCBPuy7f_sendMessage);
}

void Heavy_CircleStrings::cBinop_KnHnoLHC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_dCBPuy7f, 2, m, &cDelay_dCBPuy7f_sendMessage);
}

void Heavy_CircleStrings::cBinop_8Z6XKY1k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_KnHnoLHC_sendMessage);
}

void Heavy_CircleStrings::cCast_BSvKMfUC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GCGsJSYu, 0, m, &cVar_GCGsJSYu_sendMessage);
  cMsg_kdyihSIx_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_MAMw6hWl, 0, m, &cTabhead_MAMw6hWl_sendMessage);
}

void Heavy_CircleStrings::cTabhead_B9v9CFfV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ENW9nD56, HV_BINOP_SUBTRACT, 0, m, &cBinop_ENW9nD56_sendMessage);
}

void Heavy_CircleStrings::cMsg_WdnEMARq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hABYkxLj_sendMessage);
}

void Heavy_CircleStrings::cSystem_hABYkxLj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_DawKTBxV_sendMessage);
}

void Heavy_CircleStrings::cVar_FnFwiL3O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sHVxCtc2_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_fZrgNdnM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fZrgNdnM, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Amtzd2WT, 0, m, &cDelay_Amtzd2WT_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_nCJgAvj8, 0, m, &sTabread_nCJgAvj8_sendMessage);
}

void Heavy_CircleStrings::cDelay_Amtzd2WT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Amtzd2WT, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_nCJgAvj8, 0, m, &sTabread_nCJgAvj8_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Amtzd2WT, 0, m, &cDelay_Amtzd2WT_sendMessage);
}

void Heavy_CircleStrings::sTabread_nCJgAvj8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_yJ75sqCw, HV_BINOP_SUBTRACT, 0, m, &cBinop_yJ75sqCw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_Irmoovil_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BLfpx2ij, HV_BINOP_MAX, 0, m, &cBinop_BLfpx2ij_sendMessage);
}

void Heavy_CircleStrings::cBinop_DawKTBxV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Irmoovil, HV_BINOP_MULTIPLY, 0, m, &cBinop_Irmoovil_sendMessage);
}

void Heavy_CircleStrings::cBinop_ENW9nD56_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5LJra2Yx_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_nCJgAvj8, 0, m, &sTabread_nCJgAvj8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_l7eHTcVV_sendMessage);
}

void Heavy_CircleStrings::cSystem_djHLrXGT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yJ75sqCw, HV_BINOP_SUBTRACT, 1, m, &cBinop_yJ75sqCw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Amtzd2WT, 2, m, &cDelay_Amtzd2WT_sendMessage);
}

void Heavy_CircleStrings::cMsg_sHVxCtc2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_djHLrXGT_sendMessage);
}

void Heavy_CircleStrings::cMsg_5LJra2Yx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_fZrgNdnM, 0, m, &cDelay_fZrgNdnM_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Amtzd2WT, 0, m, &cDelay_Amtzd2WT_sendMessage);
}

void Heavy_CircleStrings::cMsg_oR04lfqE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_BLfpx2ij, HV_BINOP_MAX, 1, m, &cBinop_BLfpx2ij_sendMessage);
}

void Heavy_CircleStrings::cBinop_BLfpx2ij_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ENW9nD56, HV_BINOP_SUBTRACT, 1, m, &cBinop_ENW9nD56_sendMessage);
}

void Heavy_CircleStrings::cCast_l7eHTcVV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_fZrgNdnM, 0, m, &cDelay_fZrgNdnM_sendMessage);
}

void Heavy_CircleStrings::cBinop_GQsZHflN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_fZrgNdnM, 2, m, &cDelay_fZrgNdnM_sendMessage);
}

void Heavy_CircleStrings::cBinop_yJ75sqCw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_GQsZHflN_sendMessage);
}

void Heavy_CircleStrings::cCast_P6VdDRaa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FnFwiL3O, 0, m, &cVar_FnFwiL3O_sendMessage);
  cMsg_WdnEMARq_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_B9v9CFfV, 0, m, &cTabhead_B9v9CFfV_sendMessage);
}

void Heavy_CircleStrings::cMsg_ZGZM2rar_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gXP0wznY_sendMessage);
}

void Heavy_CircleStrings::cSystem_gXP0wznY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_V27SjBBG_sendMessage);
}

void Heavy_CircleStrings::cDelay_crpitYuk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_crpitYuk, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fg0Bqh2R, 0, m, &cDelay_fg0Bqh2R_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_crpitYuk, 0, m, &cDelay_crpitYuk_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_6Rg202Ze, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_fg0Bqh2R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fg0Bqh2R, m);
  cMsg_1lBRo2Aw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_klkWdhOm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_yqdTUdBB_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_9iDCLoBM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9Cq1GT5D_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_H2niNe6T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_79JNNrI0_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_crpitYuk, 2, m, &cDelay_crpitYuk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vi8xCwpY_sendMessage);
}

void Heavy_CircleStrings::cMsg_9Cq1GT5D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_H2niNe6T, 0, m, &hTable_H2niNe6T_sendMessage);
}

void Heavy_CircleStrings::cBinop_V27SjBBG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_9iDCLoBM_sendMessage);
}

void Heavy_CircleStrings::cMsg_1lBRo2Aw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_H2niNe6T, 0, m, &hTable_H2niNe6T_sendMessage);
}

void Heavy_CircleStrings::cCast_vi8xCwpY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_crpitYuk, 0, m, &cDelay_crpitYuk_sendMessage);
}

void Heavy_CircleStrings::cMsg_79JNNrI0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_fg0Bqh2R, 2, m, &cDelay_fg0Bqh2R_sendMessage);
}

void Heavy_CircleStrings::cMsg_yqdTUdBB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_6Rg202Ze, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_fpsqCfVa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yLwQCUbY_sendMessage);
}

void Heavy_CircleStrings::cSystem_yLwQCUbY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_yKmuiT7i_sendMessage);
}

void Heavy_CircleStrings::cDelay_wuYQmUjj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wuYQmUjj, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XQHtYtEj, 0, m, &cDelay_XQHtYtEj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wuYQmUjj, 0, m, &cDelay_wuYQmUjj_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_jntCVGRQ, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_XQHtYtEj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XQHtYtEj, m);
  cMsg_OVGO7Dng_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_xwyRF39f_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_6KNTBrZr_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_xmF87ebG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_H931fkBd_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_iNNujHUH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5mZomny2_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wuYQmUjj, 2, m, &cDelay_wuYQmUjj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_THDKWf22_sendMessage);
}

void Heavy_CircleStrings::cMsg_H931fkBd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_iNNujHUH, 0, m, &hTable_iNNujHUH_sendMessage);
}

void Heavy_CircleStrings::cBinop_yKmuiT7i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_xmF87ebG_sendMessage);
}

void Heavy_CircleStrings::cMsg_OVGO7Dng_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_iNNujHUH, 0, m, &hTable_iNNujHUH_sendMessage);
}

void Heavy_CircleStrings::cCast_THDKWf22_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wuYQmUjj, 0, m, &cDelay_wuYQmUjj_sendMessage);
}

void Heavy_CircleStrings::cMsg_5mZomny2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_XQHtYtEj, 2, m, &cDelay_XQHtYtEj_sendMessage);
}

void Heavy_CircleStrings::cMsg_6KNTBrZr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_jntCVGRQ, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_a2NUMzhB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uVG3YGLa_sendMessage);
}

void Heavy_CircleStrings::cSystem_uVG3YGLa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_69WqzHmu_sendMessage);
}

void Heavy_CircleStrings::cDelay_sdWgbqos_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sdWgbqos, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Z3X6Wbhm, 0, m, &cDelay_Z3X6Wbhm_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sdWgbqos, 0, m, &cDelay_sdWgbqos_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_NJk4KNph, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_Z3X6Wbhm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Z3X6Wbhm, m);
  cMsg_j3dCKe1i_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_ENTv4bVA_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_JfSU3lpI_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_1KjjMicn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7i1YnKtC_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_bjKuW1do_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_s34wn3Zo_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sdWgbqos, 2, m, &cDelay_sdWgbqos_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tnO9pdqv_sendMessage);
}

void Heavy_CircleStrings::cMsg_7i1YnKtC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_bjKuW1do, 0, m, &hTable_bjKuW1do_sendMessage);
}

void Heavy_CircleStrings::cBinop_69WqzHmu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_1KjjMicn_sendMessage);
}

void Heavy_CircleStrings::cMsg_j3dCKe1i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_bjKuW1do, 0, m, &hTable_bjKuW1do_sendMessage);
}

void Heavy_CircleStrings::cCast_tnO9pdqv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_sdWgbqos, 0, m, &cDelay_sdWgbqos_sendMessage);
}

void Heavy_CircleStrings::cMsg_s34wn3Zo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Z3X6Wbhm, 2, m, &cDelay_Z3X6Wbhm_sendMessage);
}

void Heavy_CircleStrings::cMsg_JfSU3lpI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_NJk4KNph, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_XsypfDNc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_b7rFi7qG_sendMessage);
}

void Heavy_CircleStrings::cSystem_b7rFi7qG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_DATi4i3u_sendMessage);
}

void Heavy_CircleStrings::cDelay_YaPEui71_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_YaPEui71, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LCqK6Kfo, 0, m, &cDelay_LCqK6Kfo_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_YaPEui71, 0, m, &cDelay_YaPEui71_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_vzaHST7l, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_LCqK6Kfo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LCqK6Kfo, m);
  cMsg_J7fYQ0QR_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_QgRMjMga_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_aHJOpuw8_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_4ccJxStQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rqbyhNyi_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_vWahfTBD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YyQglAXK_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_YaPEui71, 2, m, &cDelay_YaPEui71_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QDkZ7hiU_sendMessage);
}

void Heavy_CircleStrings::cMsg_rqbyhNyi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_vWahfTBD, 0, m, &hTable_vWahfTBD_sendMessage);
}

void Heavy_CircleStrings::cBinop_DATi4i3u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_4ccJxStQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_J7fYQ0QR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_vWahfTBD, 0, m, &hTable_vWahfTBD_sendMessage);
}

void Heavy_CircleStrings::cCast_QDkZ7hiU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YaPEui71, 0, m, &cDelay_YaPEui71_sendMessage);
}

void Heavy_CircleStrings::cMsg_YyQglAXK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_LCqK6Kfo, 2, m, &cDelay_LCqK6Kfo_sendMessage);
}

void Heavy_CircleStrings::cMsg_aHJOpuw8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_vzaHST7l, 1, m, NULL);
}

void Heavy_CircleStrings::cIf_mkEqc8ZT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_ksB69esv_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_ODDLoZFz_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_qlRpOias_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZrckHz4X, HV_BINOP_POW, 0, m, &cBinop_ZrckHz4X_sendMessage);
}

void Heavy_CircleStrings::cBinop_ZrckHz4X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_HgVSm79e_sendMessage);
}

void Heavy_CircleStrings::cBinop_Hv68NEHs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_1RqcNgXw_sendMessage);
}

void Heavy_CircleStrings::cCast_Ism5TTun_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_mkEqc8ZT, 0, m, &cIf_mkEqc8ZT_sendMessage);
}

void Heavy_CircleStrings::cCast_z71jJtZo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_baco0jvs_sendMessage);
}

void Heavy_CircleStrings::cBinop_baco0jvs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_mkEqc8ZT, 1, m, &cIf_mkEqc8ZT_sendMessage);
}

void Heavy_CircleStrings::cBinop_ODDLoZFz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_Hv68NEHs_sendMessage);
}

void Heavy_CircleStrings::cMsg_ksB69esv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_HgVSm79e_sendMessage);
}

void Heavy_CircleStrings::cBinop_1RqcNgXw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZrckHz4X, HV_BINOP_POW, 1, m, &cBinop_ZrckHz4X_sendMessage);
  cMsg_qlRpOias_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_0wYDFwxi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_oRjRJtGh, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_EWSF7kuW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_OZl8cLDT, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_dBbEnU0y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_arFspn5t_sendMessage);
}

void Heavy_CircleStrings::cBinop_arFspn5t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_SQVQSGWY_sendMessage);
}

void Heavy_CircleStrings::cVar_BN8SblCZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8tLQpT8s, HV_BINOP_MULTIPLY, 0, m, &cBinop_8tLQpT8s_sendMessage);
}

void Heavy_CircleStrings::cMsg_jzzw95Gl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uyjGKMYj_sendMessage);
}

void Heavy_CircleStrings::cSystem_uyjGKMYj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jdTW9Kr1_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_8tLQpT8s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_6WFpaFW9_sendMessage);
}

void Heavy_CircleStrings::cBinop_lHC5XDQV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8tLQpT8s, HV_BINOP_MULTIPLY, 1, m, &cBinop_8tLQpT8s_sendMessage);
}

void Heavy_CircleStrings::cMsg_jdTW9Kr1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_lHC5XDQV_sendMessage);
}

void Heavy_CircleStrings::cBinop_6WFpaFW9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Vd7a8Ya1_sendMessage);
}

void Heavy_CircleStrings::cBinop_Vd7a8Ya1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_lsW9jZP8_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Y8EXrTFK, m);
}

void Heavy_CircleStrings::cBinop_lsW9jZP8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_EOa1DYUM, m);
}

void Heavy_CircleStrings::cVar_TDYXfXib_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_z71jJtZo_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Ism5TTun_sendMessage);
}

void Heavy_CircleStrings::cVar_q7t9aMkq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_dBbEnU0y_sendMessage);
}

void Heavy_CircleStrings::cVar_xijUO3KL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_exGqyjEN_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_TxioUVy5, 0, m, &cIf_TxioUVy5_sendMessage);
}

void Heavy_CircleStrings::cVar_PuI38dFq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_Obe6WhRL_sendMessage);
}

void Heavy_CircleStrings::cIf_TxioUVy5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_qHI4eXjw_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_wRuT1ncK, 0, m, &cVar_wRuT1ncK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_exGqyjEN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TxioUVy5, 1, m, &cIf_TxioUVy5_sendMessage);
}

void Heavy_CircleStrings::cBinop_Obe6WhRL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_IDUm09z0_sendMessage);
}

void Heavy_CircleStrings::cBinop_IDUm09z0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oXvkQX2r, 0, m, &cVar_oXvkQX2r_sendMessage);
}

void Heavy_CircleStrings::cTabhead_Psf7wxCL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hMMcMDhh, HV_BINOP_SUBTRACT, 0, m, &cBinop_hMMcMDhh_sendMessage);
}

void Heavy_CircleStrings::cMsg_Nlal8TiZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4xHbC4PZ_sendMessage);
}

void Heavy_CircleStrings::cSystem_4xHbC4PZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_0Pr0ensW_sendMessage);
}

void Heavy_CircleStrings::cVar_4OJmUKgn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_x4urpr6E_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_GSZk0vCS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_GSZk0vCS, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Z2RkmCxh, 0, m, &cDelay_Z2RkmCxh_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qoY8korK, 0, m, &sTabread_qoY8korK_sendMessage);
}

void Heavy_CircleStrings::cDelay_Z2RkmCxh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Z2RkmCxh, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qoY8korK, 0, m, &sTabread_qoY8korK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Z2RkmCxh, 0, m, &cDelay_Z2RkmCxh_sendMessage);
}

void Heavy_CircleStrings::sTabread_qoY8korK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_wgMHlltW, HV_BINOP_SUBTRACT, 0, m, &cBinop_wgMHlltW_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_mku7vcdJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WEYOyy9A, HV_BINOP_MAX, 0, m, &cBinop_WEYOyy9A_sendMessage);
}

void Heavy_CircleStrings::cBinop_0Pr0ensW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mku7vcdJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_mku7vcdJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_hMMcMDhh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1AnKMWw3_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qoY8korK, 0, m, &sTabread_qoY8korK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Cu8HkBlw_sendMessage);
}

void Heavy_CircleStrings::cSystem_WvVih0I5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wgMHlltW, HV_BINOP_SUBTRACT, 1, m, &cBinop_wgMHlltW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Z2RkmCxh, 2, m, &cDelay_Z2RkmCxh_sendMessage);
}

void Heavy_CircleStrings::cMsg_x4urpr6E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WvVih0I5_sendMessage);
}

void Heavy_CircleStrings::cMsg_1AnKMWw3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_GSZk0vCS, 0, m, &cDelay_GSZk0vCS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Z2RkmCxh, 0, m, &cDelay_Z2RkmCxh_sendMessage);
}

void Heavy_CircleStrings::cMsg_UwBPsFOf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_WEYOyy9A, HV_BINOP_MAX, 1, m, &cBinop_WEYOyy9A_sendMessage);
}

void Heavy_CircleStrings::cBinop_WEYOyy9A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hMMcMDhh, HV_BINOP_SUBTRACT, 1, m, &cBinop_hMMcMDhh_sendMessage);
}

void Heavy_CircleStrings::cCast_Cu8HkBlw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_GSZk0vCS, 0, m, &cDelay_GSZk0vCS_sendMessage);
}

void Heavy_CircleStrings::cBinop_yxa3EUeg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_GSZk0vCS, 2, m, &cDelay_GSZk0vCS_sendMessage);
}

void Heavy_CircleStrings::cBinop_wgMHlltW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_yxa3EUeg_sendMessage);
}

void Heavy_CircleStrings::cCast_ZZiYXUb5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4OJmUKgn, 0, m, &cVar_4OJmUKgn_sendMessage);
  cMsg_Nlal8TiZ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Psf7wxCL, 0, m, &cTabhead_Psf7wxCL_sendMessage);
}

void Heavy_CircleStrings::cMsg_VHYZi92w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_A4GkoT4x_sendMessage);
}

void Heavy_CircleStrings::cSystem_A4GkoT4x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_eBeButCo_sendMessage);
}

void Heavy_CircleStrings::cDelay_L3lRjqLF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_L3lRjqLF, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2hSz4mbe, 0, m, &cDelay_2hSz4mbe_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_L3lRjqLF, 0, m, &cDelay_L3lRjqLF_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_1cB7ngHC, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_2hSz4mbe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2hSz4mbe, m);
  cMsg_ZZecZvKB_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_EDYbbHUQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_LfGlkvOL_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_Pj13UNpV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_usmiU4Hg_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_MKOVheRb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Qhh6IFyY_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_L3lRjqLF, 2, m, &cDelay_L3lRjqLF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zhvQsqeP_sendMessage);
}

void Heavy_CircleStrings::cMsg_usmiU4Hg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_MKOVheRb, 0, m, &hTable_MKOVheRb_sendMessage);
}

void Heavy_CircleStrings::cBinop_eBeButCo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_Pj13UNpV_sendMessage);
}

void Heavy_CircleStrings::cMsg_ZZecZvKB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_MKOVheRb, 0, m, &hTable_MKOVheRb_sendMessage);
}

void Heavy_CircleStrings::cCast_zhvQsqeP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_L3lRjqLF, 0, m, &cDelay_L3lRjqLF_sendMessage);
}

void Heavy_CircleStrings::cMsg_Qhh6IFyY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_2hSz4mbe, 2, m, &cDelay_2hSz4mbe_sendMessage);
}

void Heavy_CircleStrings::cMsg_LfGlkvOL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_1cB7ngHC, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_unNDbdF3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_63pfUuZT, HV_BINOP_SUBTRACT, 0, m, &cBinop_63pfUuZT_sendMessage);
}

void Heavy_CircleStrings::cMsg_BIwFFWHn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LLNqkRKU_sendMessage);
}

void Heavy_CircleStrings::cSystem_LLNqkRKU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_XFxyti6X_sendMessage);
}

void Heavy_CircleStrings::cVar_r8gF6GJZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XRSj7IX1_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_7FT5E9Y1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7FT5E9Y1, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_aGtxj0Wo, 0, m, &cDelay_aGtxj0Wo_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_h2YIJv5g, 0, m, &sTabread_h2YIJv5g_sendMessage);
}

void Heavy_CircleStrings::cDelay_aGtxj0Wo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_aGtxj0Wo, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_h2YIJv5g, 0, m, &sTabread_h2YIJv5g_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_aGtxj0Wo, 0, m, &cDelay_aGtxj0Wo_sendMessage);
}

void Heavy_CircleStrings::sTabread_h2YIJv5g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_loZxjTuZ, HV_BINOP_SUBTRACT, 0, m, &cBinop_loZxjTuZ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_6TIEiPFX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0N8emxpN, HV_BINOP_MAX, 0, m, &cBinop_0N8emxpN_sendMessage);
}

void Heavy_CircleStrings::cBinop_XFxyti6X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6TIEiPFX, HV_BINOP_MULTIPLY, 0, m, &cBinop_6TIEiPFX_sendMessage);
}

void Heavy_CircleStrings::cBinop_63pfUuZT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_twQb5Wp3_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_h2YIJv5g, 0, m, &sTabread_h2YIJv5g_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IgTvik8C_sendMessage);
}

void Heavy_CircleStrings::cSystem_VPL276Do_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_loZxjTuZ, HV_BINOP_SUBTRACT, 1, m, &cBinop_loZxjTuZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_aGtxj0Wo, 2, m, &cDelay_aGtxj0Wo_sendMessage);
}

void Heavy_CircleStrings::cMsg_XRSj7IX1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VPL276Do_sendMessage);
}

void Heavy_CircleStrings::cMsg_twQb5Wp3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_7FT5E9Y1, 0, m, &cDelay_7FT5E9Y1_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_aGtxj0Wo, 0, m, &cDelay_aGtxj0Wo_sendMessage);
}

void Heavy_CircleStrings::cMsg_JfbcmLH2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_0N8emxpN, HV_BINOP_MAX, 1, m, &cBinop_0N8emxpN_sendMessage);
}

void Heavy_CircleStrings::cBinop_0N8emxpN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_63pfUuZT, HV_BINOP_SUBTRACT, 1, m, &cBinop_63pfUuZT_sendMessage);
}

void Heavy_CircleStrings::cCast_IgTvik8C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_7FT5E9Y1, 0, m, &cDelay_7FT5E9Y1_sendMessage);
}

void Heavy_CircleStrings::cBinop_FUAha0rl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_7FT5E9Y1, 2, m, &cDelay_7FT5E9Y1_sendMessage);
}

void Heavy_CircleStrings::cBinop_loZxjTuZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_FUAha0rl_sendMessage);
}

void Heavy_CircleStrings::cCast_DJKdHUfX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_r8gF6GJZ, 0, m, &cVar_r8gF6GJZ_sendMessage);
  cMsg_BIwFFWHn_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_unNDbdF3, 0, m, &cTabhead_unNDbdF3_sendMessage);
}

void Heavy_CircleStrings::cMsg_XgLCWMWo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AeOkoOG9_sendMessage);
}

void Heavy_CircleStrings::cSystem_AeOkoOG9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_De19oH5t_sendMessage);
}

void Heavy_CircleStrings::cDelay_jhCDb12o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_jhCDb12o, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8nfeyA7z, 0, m, &cDelay_8nfeyA7z_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jhCDb12o, 0, m, &cDelay_jhCDb12o_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_jspvYLv4, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_8nfeyA7z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8nfeyA7z, m);
  cMsg_xMjOCePu_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_RJfJBe7x_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_Fc4e1p6L_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_8q2ifC49_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8vSGx2lV_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_RQ7veuOM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qaXoEpxm_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jhCDb12o, 2, m, &cDelay_jhCDb12o_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_n6uIfl5K_sendMessage);
}

void Heavy_CircleStrings::cMsg_8vSGx2lV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_RQ7veuOM, 0, m, &hTable_RQ7veuOM_sendMessage);
}

void Heavy_CircleStrings::cBinop_De19oH5t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_8q2ifC49_sendMessage);
}

void Heavy_CircleStrings::cMsg_xMjOCePu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_RQ7veuOM, 0, m, &hTable_RQ7veuOM_sendMessage);
}

void Heavy_CircleStrings::cCast_n6uIfl5K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_jhCDb12o, 0, m, &cDelay_jhCDb12o_sendMessage);
}

void Heavy_CircleStrings::cMsg_qaXoEpxm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_8nfeyA7z, 2, m, &cDelay_8nfeyA7z_sendMessage);
}

void Heavy_CircleStrings::cMsg_Fc4e1p6L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_jspvYLv4, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_1f2tzRoW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NWzxEgr1, HV_BINOP_SUBTRACT, 0, m, &cBinop_NWzxEgr1_sendMessage);
}

void Heavy_CircleStrings::cMsg_EsDt989k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wbzuQLGX_sendMessage);
}

void Heavy_CircleStrings::cSystem_wbzuQLGX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_XxUeJjNC_sendMessage);
}

void Heavy_CircleStrings::cVar_v0qrsGGX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oR8NQPpo_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_f7AyPfdd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_f7AyPfdd, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_86IEySAv, 0, m, &cDelay_86IEySAv_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_mbL6YwyO, 0, m, &sTabread_mbL6YwyO_sendMessage);
}

void Heavy_CircleStrings::cDelay_86IEySAv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_86IEySAv, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_mbL6YwyO, 0, m, &sTabread_mbL6YwyO_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_86IEySAv, 0, m, &cDelay_86IEySAv_sendMessage);
}

void Heavy_CircleStrings::sTabread_mbL6YwyO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_G7GZQ0B7, HV_BINOP_SUBTRACT, 0, m, &cBinop_G7GZQ0B7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_JzrRbLob_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FgSIzjdB, HV_BINOP_MAX, 0, m, &cBinop_FgSIzjdB_sendMessage);
}

void Heavy_CircleStrings::cBinop_XxUeJjNC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JzrRbLob, HV_BINOP_MULTIPLY, 0, m, &cBinop_JzrRbLob_sendMessage);
}

void Heavy_CircleStrings::cBinop_NWzxEgr1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_t9egROGW_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_mbL6YwyO, 0, m, &sTabread_mbL6YwyO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OmyrF2ft_sendMessage);
}

void Heavy_CircleStrings::cSystem_kdijSb9Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_G7GZQ0B7, HV_BINOP_SUBTRACT, 1, m, &cBinop_G7GZQ0B7_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_86IEySAv, 2, m, &cDelay_86IEySAv_sendMessage);
}

void Heavy_CircleStrings::cMsg_oR8NQPpo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kdijSb9Q_sendMessage);
}

void Heavy_CircleStrings::cMsg_t9egROGW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_f7AyPfdd, 0, m, &cDelay_f7AyPfdd_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_86IEySAv, 0, m, &cDelay_86IEySAv_sendMessage);
}

void Heavy_CircleStrings::cMsg_IFmLkF6m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_FgSIzjdB, HV_BINOP_MAX, 1, m, &cBinop_FgSIzjdB_sendMessage);
}

void Heavy_CircleStrings::cBinop_FgSIzjdB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NWzxEgr1, HV_BINOP_SUBTRACT, 1, m, &cBinop_NWzxEgr1_sendMessage);
}

void Heavy_CircleStrings::cCast_OmyrF2ft_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_f7AyPfdd, 0, m, &cDelay_f7AyPfdd_sendMessage);
}

void Heavy_CircleStrings::cBinop_LO6mmfYv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_f7AyPfdd, 2, m, &cDelay_f7AyPfdd_sendMessage);
}

void Heavy_CircleStrings::cBinop_G7GZQ0B7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_LO6mmfYv_sendMessage);
}

void Heavy_CircleStrings::cCast_7chCOTed_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_v0qrsGGX, 0, m, &cVar_v0qrsGGX_sendMessage);
  cMsg_EsDt989k_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_1f2tzRoW, 0, m, &cTabhead_1f2tzRoW_sendMessage);
}

void Heavy_CircleStrings::cMsg_4yBoylks_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dxQjf0WB_sendMessage);
}

void Heavy_CircleStrings::cSystem_dxQjf0WB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_A4HMmriS_sendMessage);
}

void Heavy_CircleStrings::cDelay_pNHCjgjK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pNHCjgjK, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2JMxHNnj, 0, m, &cDelay_2JMxHNnj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pNHCjgjK, 0, m, &cDelay_pNHCjgjK_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_HY2K3S61, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_2JMxHNnj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2JMxHNnj, m);
  cMsg_mXvm4uMX_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_cAPPAg6S_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_GL4GdSLs_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_9rAXZjTU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_z4xpQwvn_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_D17gvZtz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jgrMbNuu_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pNHCjgjK, 2, m, &cDelay_pNHCjgjK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jYUY1PCt_sendMessage);
}

void Heavy_CircleStrings::cMsg_z4xpQwvn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_D17gvZtz, 0, m, &hTable_D17gvZtz_sendMessage);
}

void Heavy_CircleStrings::cBinop_A4HMmriS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_9rAXZjTU_sendMessage);
}

void Heavy_CircleStrings::cMsg_mXvm4uMX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_D17gvZtz, 0, m, &hTable_D17gvZtz_sendMessage);
}

void Heavy_CircleStrings::cCast_jYUY1PCt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pNHCjgjK, 0, m, &cDelay_pNHCjgjK_sendMessage);
}

void Heavy_CircleStrings::cMsg_jgrMbNuu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_2JMxHNnj, 2, m, &cDelay_2JMxHNnj_sendMessage);
}

void Heavy_CircleStrings::cMsg_GL4GdSLs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_HY2K3S61, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_fPcCs3Bu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EevPJCTX, HV_BINOP_SUBTRACT, 0, m, &cBinop_EevPJCTX_sendMessage);
}

void Heavy_CircleStrings::cMsg_BbdIeU3I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2W4ZT92b_sendMessage);
}

void Heavy_CircleStrings::cSystem_2W4ZT92b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_NBc9q4kr_sendMessage);
}

void Heavy_CircleStrings::cVar_5itQXJJu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EAGwZ5jc_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_S93tiKiW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_S93tiKiW, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6gs0ZgS1, 0, m, &cDelay_6gs0ZgS1_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_f9PfGxJH, 0, m, &sTabread_f9PfGxJH_sendMessage);
}

void Heavy_CircleStrings::cDelay_6gs0ZgS1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6gs0ZgS1, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_f9PfGxJH, 0, m, &sTabread_f9PfGxJH_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6gs0ZgS1, 0, m, &cDelay_6gs0ZgS1_sendMessage);
}

void Heavy_CircleStrings::sTabread_f9PfGxJH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_CSwnsttm, HV_BINOP_SUBTRACT, 0, m, &cBinop_CSwnsttm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_XiXTW8uV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HlT210TI, HV_BINOP_MAX, 0, m, &cBinop_HlT210TI_sendMessage);
}

void Heavy_CircleStrings::cBinop_NBc9q4kr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XiXTW8uV, HV_BINOP_MULTIPLY, 0, m, &cBinop_XiXTW8uV_sendMessage);
}

void Heavy_CircleStrings::cBinop_EevPJCTX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_y0qBwTWE_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_f9PfGxJH, 0, m, &sTabread_f9PfGxJH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TeEeHBTo_sendMessage);
}

void Heavy_CircleStrings::cSystem_EvkqdR4b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CSwnsttm, HV_BINOP_SUBTRACT, 1, m, &cBinop_CSwnsttm_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6gs0ZgS1, 2, m, &cDelay_6gs0ZgS1_sendMessage);
}

void Heavy_CircleStrings::cMsg_EAGwZ5jc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_EvkqdR4b_sendMessage);
}

void Heavy_CircleStrings::cMsg_y0qBwTWE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_S93tiKiW, 0, m, &cDelay_S93tiKiW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6gs0ZgS1, 0, m, &cDelay_6gs0ZgS1_sendMessage);
}

void Heavy_CircleStrings::cMsg_1nmirBlX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_HlT210TI, HV_BINOP_MAX, 1, m, &cBinop_HlT210TI_sendMessage);
}

void Heavy_CircleStrings::cBinop_HlT210TI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EevPJCTX, HV_BINOP_SUBTRACT, 1, m, &cBinop_EevPJCTX_sendMessage);
}

void Heavy_CircleStrings::cCast_TeEeHBTo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_S93tiKiW, 0, m, &cDelay_S93tiKiW_sendMessage);
}

void Heavy_CircleStrings::cBinop_tQD0Naxm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_S93tiKiW, 2, m, &cDelay_S93tiKiW_sendMessage);
}

void Heavy_CircleStrings::cBinop_CSwnsttm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_tQD0Naxm_sendMessage);
}

void Heavy_CircleStrings::cCast_4fNcT46H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5itQXJJu, 0, m, &cVar_5itQXJJu_sendMessage);
  cMsg_BbdIeU3I_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_fPcCs3Bu, 0, m, &cTabhead_fPcCs3Bu_sendMessage);
}

void Heavy_CircleStrings::cMsg_Abek11p1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AcBwJ8an_sendMessage);
}

void Heavy_CircleStrings::cSystem_AcBwJ8an_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_De6j1Igp_sendMessage);
}

void Heavy_CircleStrings::cDelay_0mGPuN7s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0mGPuN7s, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ynmCY4Ij, 0, m, &cDelay_ynmCY4Ij_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0mGPuN7s, 0, m, &cDelay_0mGPuN7s_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_oPvrzAUY, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_ynmCY4Ij_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ynmCY4Ij, m);
  cMsg_aRd6hzZS_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_jCt2Y9uf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_NocgwXyb_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_nSUw9S74_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_e84kV0xF_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_EuFIUT7N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NW5vj60f_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0mGPuN7s, 2, m, &cDelay_0mGPuN7s_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PgjL5S8q_sendMessage);
}

void Heavy_CircleStrings::cMsg_e84kV0xF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_EuFIUT7N, 0, m, &hTable_EuFIUT7N_sendMessage);
}

void Heavy_CircleStrings::cBinop_De6j1Igp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_nSUw9S74_sendMessage);
}

void Heavy_CircleStrings::cMsg_aRd6hzZS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_EuFIUT7N, 0, m, &hTable_EuFIUT7N_sendMessage);
}

void Heavy_CircleStrings::cCast_PgjL5S8q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_0mGPuN7s, 0, m, &cDelay_0mGPuN7s_sendMessage);
}

void Heavy_CircleStrings::cMsg_NW5vj60f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_ynmCY4Ij, 2, m, &cDelay_ynmCY4Ij_sendMessage);
}

void Heavy_CircleStrings::cMsg_NocgwXyb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_oPvrzAUY, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_3IDarXnm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9EySJxR5, HV_BINOP_SUBTRACT, 0, m, &cBinop_9EySJxR5_sendMessage);
}

void Heavy_CircleStrings::cMsg_HjaB2Xxs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_c78XsCJ0_sendMessage);
}

void Heavy_CircleStrings::cSystem_c78XsCJ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_srl70fRH_sendMessage);
}

void Heavy_CircleStrings::cVar_dea5lSVH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JVeCGEsT_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_IHe90Hj1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IHe90Hj1, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0aJMDue3, 0, m, &cDelay_0aJMDue3_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_kRpTNi7r, 0, m, &sTabread_kRpTNi7r_sendMessage);
}

void Heavy_CircleStrings::cDelay_0aJMDue3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0aJMDue3, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_kRpTNi7r, 0, m, &sTabread_kRpTNi7r_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0aJMDue3, 0, m, &cDelay_0aJMDue3_sendMessage);
}

void Heavy_CircleStrings::sTabread_kRpTNi7r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_8JBI8OHd, HV_BINOP_SUBTRACT, 0, m, &cBinop_8JBI8OHd_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_HtfFHE07_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_w7Rv1Ium, HV_BINOP_MAX, 0, m, &cBinop_w7Rv1Ium_sendMessage);
}

void Heavy_CircleStrings::cBinop_srl70fRH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HtfFHE07, HV_BINOP_MULTIPLY, 0, m, &cBinop_HtfFHE07_sendMessage);
}

void Heavy_CircleStrings::cBinop_9EySJxR5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9nzV6Ndf_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_kRpTNi7r, 0, m, &sTabread_kRpTNi7r_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6UYZfVZr_sendMessage);
}

void Heavy_CircleStrings::cSystem_9LaDRSQD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8JBI8OHd, HV_BINOP_SUBTRACT, 1, m, &cBinop_8JBI8OHd_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0aJMDue3, 2, m, &cDelay_0aJMDue3_sendMessage);
}

void Heavy_CircleStrings::cMsg_JVeCGEsT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9LaDRSQD_sendMessage);
}

void Heavy_CircleStrings::cMsg_9nzV6Ndf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_IHe90Hj1, 0, m, &cDelay_IHe90Hj1_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0aJMDue3, 0, m, &cDelay_0aJMDue3_sendMessage);
}

void Heavy_CircleStrings::cMsg_APglLTf5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_w7Rv1Ium, HV_BINOP_MAX, 1, m, &cBinop_w7Rv1Ium_sendMessage);
}

void Heavy_CircleStrings::cBinop_w7Rv1Ium_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9EySJxR5, HV_BINOP_SUBTRACT, 1, m, &cBinop_9EySJxR5_sendMessage);
}

void Heavy_CircleStrings::cCast_6UYZfVZr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_IHe90Hj1, 0, m, &cDelay_IHe90Hj1_sendMessage);
}

void Heavy_CircleStrings::cBinop_sCBwrfHe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_IHe90Hj1, 2, m, &cDelay_IHe90Hj1_sendMessage);
}

void Heavy_CircleStrings::cBinop_8JBI8OHd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_sCBwrfHe_sendMessage);
}

void Heavy_CircleStrings::cCast_de7X5NLb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dea5lSVH, 0, m, &cVar_dea5lSVH_sendMessage);
  cMsg_HjaB2Xxs_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_3IDarXnm, 0, m, &cTabhead_3IDarXnm_sendMessage);
}

void Heavy_CircleStrings::cMsg_0CWBZzjE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Zhctb4xL_sendMessage);
}

void Heavy_CircleStrings::cSystem_Zhctb4xL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_I3HKU6dW_sendMessage);
}

void Heavy_CircleStrings::cDelay_YAHNC1eQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_YAHNC1eQ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Oe4rpeE2, 0, m, &cDelay_Oe4rpeE2_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_YAHNC1eQ, 0, m, &cDelay_YAHNC1eQ_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ckH1H8Yl, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_Oe4rpeE2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Oe4rpeE2, m);
  cMsg_m66khy2Q_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_2xZolAWu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_h8H3Q0Al_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_cjlO1EYa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4fhDvzqd_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_0ARm2QU2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XGUfWqes_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_YAHNC1eQ, 2, m, &cDelay_YAHNC1eQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WpnIIPmd_sendMessage);
}

void Heavy_CircleStrings::cMsg_4fhDvzqd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_0ARm2QU2, 0, m, &hTable_0ARm2QU2_sendMessage);
}

void Heavy_CircleStrings::cBinop_I3HKU6dW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_cjlO1EYa_sendMessage);
}

void Heavy_CircleStrings::cMsg_m66khy2Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_0ARm2QU2, 0, m, &hTable_0ARm2QU2_sendMessage);
}

void Heavy_CircleStrings::cCast_WpnIIPmd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YAHNC1eQ, 0, m, &cDelay_YAHNC1eQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_XGUfWqes_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Oe4rpeE2, 2, m, &cDelay_Oe4rpeE2_sendMessage);
}

void Heavy_CircleStrings::cMsg_h8H3Q0Al_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ckH1H8Yl, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_KcZmeVMg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LnkVt4G8, HV_BINOP_SUBTRACT, 0, m, &cBinop_LnkVt4G8_sendMessage);
}

void Heavy_CircleStrings::cMsg_8k3PcyPK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lScl098c_sendMessage);
}

void Heavy_CircleStrings::cSystem_lScl098c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_mSFvQRYx_sendMessage);
}

void Heavy_CircleStrings::cVar_bmgnBiPI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_e33uSels_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_j3IBeWm5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_j3IBeWm5, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_l4xW20aQ, 0, m, &cDelay_l4xW20aQ_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_r3wDWdW9, 0, m, &sTabread_r3wDWdW9_sendMessage);
}

void Heavy_CircleStrings::cDelay_l4xW20aQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_l4xW20aQ, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_r3wDWdW9, 0, m, &sTabread_r3wDWdW9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_l4xW20aQ, 0, m, &cDelay_l4xW20aQ_sendMessage);
}

void Heavy_CircleStrings::sTabread_r3wDWdW9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_1SCtKeE7, HV_BINOP_SUBTRACT, 0, m, &cBinop_1SCtKeE7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_H98hwKmN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WiYgjvPm, HV_BINOP_MAX, 0, m, &cBinop_WiYgjvPm_sendMessage);
}

void Heavy_CircleStrings::cBinop_mSFvQRYx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_H98hwKmN, HV_BINOP_MULTIPLY, 0, m, &cBinop_H98hwKmN_sendMessage);
}

void Heavy_CircleStrings::cBinop_LnkVt4G8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4MRuhJhx_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_r3wDWdW9, 0, m, &sTabread_r3wDWdW9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SQmRY4G3_sendMessage);
}

void Heavy_CircleStrings::cSystem_1IrrlzHZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1SCtKeE7, HV_BINOP_SUBTRACT, 1, m, &cBinop_1SCtKeE7_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_l4xW20aQ, 2, m, &cDelay_l4xW20aQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_e33uSels_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1IrrlzHZ_sendMessage);
}

void Heavy_CircleStrings::cMsg_4MRuhJhx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_j3IBeWm5, 0, m, &cDelay_j3IBeWm5_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_l4xW20aQ, 0, m, &cDelay_l4xW20aQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_YqeytZcH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_WiYgjvPm, HV_BINOP_MAX, 1, m, &cBinop_WiYgjvPm_sendMessage);
}

void Heavy_CircleStrings::cBinop_WiYgjvPm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LnkVt4G8, HV_BINOP_SUBTRACT, 1, m, &cBinop_LnkVt4G8_sendMessage);
}

void Heavy_CircleStrings::cCast_SQmRY4G3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_j3IBeWm5, 0, m, &cDelay_j3IBeWm5_sendMessage);
}

void Heavy_CircleStrings::cBinop_zTtjYWx5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_j3IBeWm5, 2, m, &cDelay_j3IBeWm5_sendMessage);
}

void Heavy_CircleStrings::cBinop_1SCtKeE7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_zTtjYWx5_sendMessage);
}

void Heavy_CircleStrings::cCast_S1BbSPdY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bmgnBiPI, 0, m, &cVar_bmgnBiPI_sendMessage);
  cMsg_8k3PcyPK_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_KcZmeVMg, 0, m, &cTabhead_KcZmeVMg_sendMessage);
}

void Heavy_CircleStrings::cMsg_83AJYhzK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VuzxaYxM_sendMessage);
}

void Heavy_CircleStrings::cSystem_VuzxaYxM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_kYMfSAwY_sendMessage);
}

void Heavy_CircleStrings::cDelay_KdK1mT02_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KdK1mT02, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eNGzrEXS, 0, m, &cDelay_eNGzrEXS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KdK1mT02, 0, m, &cDelay_KdK1mT02_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Afuitgor, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_eNGzrEXS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_eNGzrEXS, m);
  cMsg_shz75JpN_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_UPU9scxa_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_Wf6sgLUH_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_7TUA8nZq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_plk5mcML_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_GPApmXrg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zHCp6lis_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KdK1mT02, 2, m, &cDelay_KdK1mT02_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eOAJaME2_sendMessage);
}

void Heavy_CircleStrings::cMsg_plk5mcML_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_GPApmXrg, 0, m, &hTable_GPApmXrg_sendMessage);
}

void Heavy_CircleStrings::cBinop_kYMfSAwY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_7TUA8nZq_sendMessage);
}

void Heavy_CircleStrings::cMsg_shz75JpN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_GPApmXrg, 0, m, &hTable_GPApmXrg_sendMessage);
}

void Heavy_CircleStrings::cCast_eOAJaME2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KdK1mT02, 0, m, &cDelay_KdK1mT02_sendMessage);
}

void Heavy_CircleStrings::cMsg_zHCp6lis_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_eNGzrEXS, 2, m, &cDelay_eNGzrEXS_sendMessage);
}

void Heavy_CircleStrings::cMsg_Wf6sgLUH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Afuitgor, 1, m, NULL);
}

void Heavy_CircleStrings::cVar_wRuT1ncK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BN8SblCZ, 0, m, &cVar_BN8SblCZ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_u1QFAeIg, 0, m, &cVar_u1QFAeIg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_5XeB1hlH, 0, m, &cVar_5XeB1hlH_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_YufBLxpG, 0, m, &cVar_YufBLxpG_sendMessage);
}

void Heavy_CircleStrings::cVar_oXvkQX2r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_dtHCByFG_sendMessage);
}

void Heavy_CircleStrings::cPack_gVjARBwx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_rUnCkvbJ, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_u1QFAeIg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FcebQgsp, HV_BINOP_MULTIPLY, 0, m, &cBinop_FcebQgsp_sendMessage);
}

void Heavy_CircleStrings::cMsg_1A01qLtW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AHhDh1XT_sendMessage);
}

void Heavy_CircleStrings::cSystem_AHhDh1XT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2bRF11Qc_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_FcebQgsp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_lDA8YQwC_sendMessage);
}

void Heavy_CircleStrings::cBinop_u2leWFLF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FcebQgsp, HV_BINOP_MULTIPLY, 1, m, &cBinop_FcebQgsp_sendMessage);
}

void Heavy_CircleStrings::cMsg_2bRF11Qc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_u2leWFLF_sendMessage);
}

void Heavy_CircleStrings::cBinop_lDA8YQwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_S9DxKV2k_sendMessage);
}

void Heavy_CircleStrings::cBinop_S9DxKV2k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_JVpnUECJ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_kRTIIinM, m);
}

void Heavy_CircleStrings::cBinop_JVpnUECJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Fr8eI7SJ, m);
}

void Heavy_CircleStrings::cVar_5XeB1hlH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VfeqUVnL, HV_BINOP_MULTIPLY, 0, m, &cBinop_VfeqUVnL_sendMessage);
}

void Heavy_CircleStrings::cMsg_YSCC8qzC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fx22L5WQ_sendMessage);
}

void Heavy_CircleStrings::cSystem_fx22L5WQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rkdmbN9m_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_VfeqUVnL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_SYYJ0gUc_sendMessage);
}

void Heavy_CircleStrings::cBinop_G2JVhUj3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VfeqUVnL, HV_BINOP_MULTIPLY, 1, m, &cBinop_VfeqUVnL_sendMessage);
}

void Heavy_CircleStrings::cMsg_rkdmbN9m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_G2JVhUj3_sendMessage);
}

void Heavy_CircleStrings::cBinop_SYYJ0gUc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_RhMroEeK_sendMessage);
}

void Heavy_CircleStrings::cBinop_RhMroEeK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_MmCaj7iF_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_VEu7WKRh, m);
}

void Heavy_CircleStrings::cBinop_MmCaj7iF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_4Lucl2o7, m);
}

void Heavy_CircleStrings::cVar_YufBLxpG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lCUBc7mU, HV_BINOP_MULTIPLY, 0, m, &cBinop_lCUBc7mU_sendMessage);
}

void Heavy_CircleStrings::cMsg_YETOrtRC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9t6zCO76_sendMessage);
}

void Heavy_CircleStrings::cSystem_9t6zCO76_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iBaZxOo3_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_lCUBc7mU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_6UMazohm_sendMessage);
}

void Heavy_CircleStrings::cBinop_Dm2vTF9r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lCUBc7mU, HV_BINOP_MULTIPLY, 1, m, &cBinop_lCUBc7mU_sendMessage);
}

void Heavy_CircleStrings::cMsg_iBaZxOo3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Dm2vTF9r_sendMessage);
}

void Heavy_CircleStrings::cBinop_6UMazohm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_PNGmJhxs_sendMessage);
}

void Heavy_CircleStrings::cBinop_PNGmJhxs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_sX9yyPPJ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_4JUn7Iix, m);
}

void Heavy_CircleStrings::cBinop_sX9yyPPJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_UJWln8Ax, m);
}

void Heavy_CircleStrings::cBinop_SQVQSGWY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_EWSF7kuW, 0, m, &cPack_EWSF7kuW_sendMessage);
}

void Heavy_CircleStrings::cMsg_qHI4eXjw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_wRuT1ncK, 0, m, &cVar_wRuT1ncK_sendMessage);
}

void Heavy_CircleStrings::cBinop_dtHCByFG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_gVjARBwx, 0, m, &cPack_gVjARBwx_sendMessage);
}

void Heavy_CircleStrings::cBinop_HgVSm79e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_0wYDFwxi, 0, m, &cPack_0wYDFwxi_sendMessage);
}

void Heavy_CircleStrings::cMsg_0n6NGaNx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AH5XBkj3_sendMessage);
}

void Heavy_CircleStrings::cSystem_AH5XBkj3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_eomPk800_sendMessage);
}

void Heavy_CircleStrings::cVar_gDqw19Uh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_duQssJnf_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_1oqoOyMI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_mPmO4S5I_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Cmbj3Yxq, m);
}

void Heavy_CircleStrings::cBinop_eomPk800_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_STzbPVCH, m);
}

void Heavy_CircleStrings::cMsg_duQssJnf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1oqoOyMI_sendMessage);
}

void Heavy_CircleStrings::cBinop_mPmO4S5I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_YgAVwZmN, m);
}

void Heavy_CircleStrings::cVar_lFKnOJ8b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rpgoCOCx, HV_BINOP_MULTIPLY, 0, m, &cBinop_rpgoCOCx_sendMessage);
}

void Heavy_CircleStrings::cMsg_7oYrtJvP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1SD5g0Qa_sendMessage);
}

void Heavy_CircleStrings::cSystem_1SD5g0Qa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_b6BcK40N_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_rpgoCOCx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_JlyQGxGH_sendMessage);
}

void Heavy_CircleStrings::cBinop_yrkQB8fT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rpgoCOCx, HV_BINOP_MULTIPLY, 1, m, &cBinop_rpgoCOCx_sendMessage);
}

void Heavy_CircleStrings::cMsg_b6BcK40N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_yrkQB8fT_sendMessage);
}

void Heavy_CircleStrings::cBinop_JlyQGxGH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_UGBhBXYG_sendMessage);
}

void Heavy_CircleStrings::cBinop_UGBhBXYG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_tusKxhc8_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_uIu0dZQc, m);
}

void Heavy_CircleStrings::cBinop_tusKxhc8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ku1pjJYS, m);
}

void Heavy_CircleStrings::cBinop_ktaLuKFY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_2eaUpG1o_sendMessage);
}

void Heavy_CircleStrings::cBinop_2eaUpG1o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_NHEAesR6, m);
}

void Heavy_CircleStrings::cBinop_jMzEBRTe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_T8yk889i_sendMessage);
}

void Heavy_CircleStrings::cBinop_T8yk889i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_29hVIpvv_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_CnBNMdRR_sendMessage);
}

void Heavy_CircleStrings::cVar_Pdo5FwNb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_QHRmEZ1e_sendMessage);
}

void Heavy_CircleStrings::cMsg_17yIwOMI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DucBn1Q5_sendMessage);
}

void Heavy_CircleStrings::cSystem_DucBn1Q5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CTpViEKE, HV_BINOP_DIVIDE, 1, m, &cBinop_CTpViEKE_sendMessage);
}

void Heavy_CircleStrings::cBinop_29hVIpvv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_rYiMcxV0_sendMessage);
}

void Heavy_CircleStrings::cBinop_rYiMcxV0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_0KVveVQ4, m);
}

void Heavy_CircleStrings::cMsg_oWs2q51R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_apMfL1PV_sendMessage);
}

void Heavy_CircleStrings::cBinop_apMfL1PV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_jMzEBRTe_sendMessage);
}

void Heavy_CircleStrings::cBinop_CnBNMdRR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_EWOZELwx, m);
}

void Heavy_CircleStrings::cBinop_QHRmEZ1e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_68cAvzr7_sendMessage);
}

void Heavy_CircleStrings::cBinop_68cAvzr7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CTpViEKE, HV_BINOP_DIVIDE, 0, m, &cBinop_CTpViEKE_sendMessage);
}

void Heavy_CircleStrings::cBinop_CTpViEKE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oWs2q51R_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_Sv63HcZD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Rcpv4tEt_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_sCAnaivh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vLlDdOHy_sendMessage);
}

void Heavy_CircleStrings::cSystem_vLlDdOHy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_1kGtFWjy_sendMessage);
}

void Heavy_CircleStrings::cDelay_TAtYJvzA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TAtYJvzA, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XExETrRb, 0, m, &cDelay_XExETrRb_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TAtYJvzA, 0, m, &cDelay_TAtYJvzA_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_RZS08580, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_XExETrRb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XExETrRb, m);
  cMsg_YFrcvUz4_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_F7RLAXvb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_lEqd5I9I_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_qkQUASUK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RhrgA7EG_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_gluxEKKN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mD9GRw1K_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TAtYJvzA, 2, m, &cDelay_TAtYJvzA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BCYIouOM_sendMessage);
}

void Heavy_CircleStrings::cMsg_RhrgA7EG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_gluxEKKN, 0, m, &hTable_gluxEKKN_sendMessage);
}

void Heavy_CircleStrings::cBinop_1kGtFWjy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_qkQUASUK_sendMessage);
}

void Heavy_CircleStrings::cMsg_YFrcvUz4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_gluxEKKN, 0, m, &hTable_gluxEKKN_sendMessage);
}

void Heavy_CircleStrings::cCast_BCYIouOM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TAtYJvzA, 0, m, &cDelay_TAtYJvzA_sendMessage);
}

void Heavy_CircleStrings::cMsg_mD9GRw1K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_XExETrRb, 2, m, &cDelay_XExETrRb_sendMessage);
}

void Heavy_CircleStrings::cMsg_lEqd5I9I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_RZS08580, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_2fUKrrzY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_Rcpv4tEt_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_Rcpv4tEt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_PFx9aq9R, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_M3d0YYPw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_vDMXpyZL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_OyfR06IH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_M3d0YYPw, 0, m, &cPack_M3d0YYPw_sendMessage);
}

void Heavy_CircleStrings::cCast_UAj27hOq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_EZ9L39DR_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_b9g17FAm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_vDMXpyZL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_Cbzreay3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 500.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_A6DNjj7z, m);
}

void Heavy_CircleStrings::cMsg_ucnSEKIY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.3f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_ktaLuKFY_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_qY8Oxy5B_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_kE9FQJWs, 0, m, &cSlice_kE9FQJWs_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_cVjGgGRU, 0, m, &cRandom_cVjGgGRU_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_yIza8MRy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_nweAvXqe_sendMessage);
}

void Heavy_CircleStrings::cUnop_nweAvXqe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 10.0f, 0, m, &cBinop_A9bQmhbd_sendMessage);
}

void Heavy_CircleStrings::cRandom_cVjGgGRU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 80.0f, 0, m, &cBinop_yIza8MRy_sendMessage);
}

void Heavy_CircleStrings::cSlice_kE9FQJWs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_cVjGgGRU, 1, m, &cRandom_cVjGgGRU_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSwitchcase_VTf57QKS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_xgCOtpT4, 0, m, &cSlice_xgCOtpT4_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_rUsox3tx, 0, m, &cRandom_rUsox3tx_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_djePJQNv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_H6zupnjt_sendMessage);
}

void Heavy_CircleStrings::cUnop_H6zupnjt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_pM9lzrWZ, 0, m, &cPack_pM9lzrWZ_sendMessage);
}

void Heavy_CircleStrings::cRandom_rUsox3tx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_djePJQNv_sendMessage);
}

void Heavy_CircleStrings::cSlice_xgCOtpT4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_rUsox3tx, 1, m, &cRandom_rUsox3tx_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_nXI6nsuw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_yKvOOii1_sendMessage);
}

void Heavy_CircleStrings::cPack_EXRPNR9z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Es9kD62b, 0, m, NULL);
}

void Heavy_CircleStrings::cUnop_GJ89wvaO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_bgCL0ooD_sendMessage);
}

void Heavy_CircleStrings::cBinop_vEaQ0oTC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_GJ89wvaO_sendMessage);
}

void Heavy_CircleStrings::cPack_SB6rq4TJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_wwF3p7q5, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_xH8v4xqU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_gvxSs3tX_sendMessage);
}

void Heavy_CircleStrings::cMsg_E24PtVDn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_deaYm5R4_sendMessage);
}

void Heavy_CircleStrings::cSystem_deaYm5R4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_IR5tHkzC_sendMessage);
}

void Heavy_CircleStrings::cDelay_6kMeBGAm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6kMeBGAm, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lMO0B3Ma, 0, m, &cDelay_lMO0B3Ma_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6kMeBGAm, 0, m, &cDelay_6kMeBGAm_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_tlRwJRhq, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_lMO0B3Ma_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_lMO0B3Ma, m);
  cMsg_1GqEHxPt_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_9nqVP0rL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_jEexd4Zr_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_5weFUGpO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nsgoacoe_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_kxCIxlxO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6pkFmrDG_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6kMeBGAm, 2, m, &cDelay_6kMeBGAm_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_44rPu21V_sendMessage);
}

void Heavy_CircleStrings::cMsg_nsgoacoe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_kxCIxlxO, 0, m, &hTable_kxCIxlxO_sendMessage);
}

void Heavy_CircleStrings::cBinop_IR5tHkzC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_5weFUGpO_sendMessage);
}

void Heavy_CircleStrings::cMsg_1GqEHxPt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_kxCIxlxO, 0, m, &hTable_kxCIxlxO_sendMessage);
}

void Heavy_CircleStrings::cCast_44rPu21V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_6kMeBGAm, 0, m, &cDelay_6kMeBGAm_sendMessage);
}

void Heavy_CircleStrings::cMsg_6pkFmrDG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_lMO0B3Ma, 2, m, &cDelay_lMO0B3Ma_sendMessage);
}

void Heavy_CircleStrings::cMsg_jEexd4Zr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_tlRwJRhq, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_Fmoc8BA3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_thXKZF6f_sendMessage);
}

void Heavy_CircleStrings::cSystem_thXKZF6f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ImlAAoRp_sendMessage);
}

void Heavy_CircleStrings::cVar_hzOrUdyI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HTfTvXxa_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_KKpieomk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_msaYBm5R_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_8SWCOGJz, m);
}

void Heavy_CircleStrings::cBinop_ImlAAoRp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_J3VvS4yU, m);
}

void Heavy_CircleStrings::cMsg_HTfTvXxa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KKpieomk_sendMessage);
}

void Heavy_CircleStrings::cBinop_msaYBm5R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_zZanAN94, m);
}

void Heavy_CircleStrings::cMsg_3G2ppjC6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hW3ZLMu1_sendMessage);
}

void Heavy_CircleStrings::cSystem_hW3ZLMu1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Y3kwV5fA_sendMessage);
}

void Heavy_CircleStrings::cVar_ffn5tknD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Depw8mxK_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_oYZb2Zuo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_K6g2Wttf_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_IwXDkzAY, m);
}

void Heavy_CircleStrings::cBinop_Y3kwV5fA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Aw8vxnnU, m);
}

void Heavy_CircleStrings::cMsg_Depw8mxK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_oYZb2Zuo_sendMessage);
}

void Heavy_CircleStrings::cBinop_K6g2Wttf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_RCPs6bHG, m);
}

void Heavy_CircleStrings::cBinop_fjrj5i6t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yrc4G5p7_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_EH4riqGN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DoV2oKV1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5ijjPDRt_sendMessage);
}

void Heavy_CircleStrings::cCast_5ijjPDRt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fjrj5i6t, HV_BINOP_DIVIDE, 0, m, &cBinop_fjrj5i6t_sendMessage);
}

void Heavy_CircleStrings::cCast_DoV2oKV1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fjrj5i6t, HV_BINOP_DIVIDE, 1, m, &cBinop_fjrj5i6t_sendMessage);
}

void Heavy_CircleStrings::cBinop_bgCL0ooD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_fbOThkKL_sendMessage);
}

void Heavy_CircleStrings::cBinop_NYDHHiVv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_vEaQ0oTC_sendMessage);
}

void Heavy_CircleStrings::cBinop_fbOThkKL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fjrj5i6t, HV_BINOP_DIVIDE, 0, m, &cBinop_fjrj5i6t_sendMessage);
}

void Heavy_CircleStrings::cBinop_gvxSs3tX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_SB6rq4TJ, 0, m, &cPack_SB6rq4TJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_yKvOOii1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_EH4riqGN_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_EXRPNR9z, 0, m, &cPack_EXRPNR9z_sendMessage);
}

void Heavy_CircleStrings::cMsg_qRz56KBJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_nXI6nsuw, 0, m, &cVar_nXI6nsuw_sendMessage);
}

void Heavy_CircleStrings::cMsg_1AQohi33_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_xH8v4xqU, 0, m, &cVar_xH8v4xqU_sendMessage);
}

void Heavy_CircleStrings::cMsg_yrc4G5p7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_zfeQ5o9Q, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_7BtuY5Y5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uzejJDgB_sendMessage);
}

void Heavy_CircleStrings::cSystem_uzejJDgB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_vIW95aDY_sendMessage);
}

void Heavy_CircleStrings::cVar_kMPT6E1m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qUQoHsWC_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_2OOJZPEK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_u8SpFrI0_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_c9ypxp2y, m);
}

void Heavy_CircleStrings::cBinop_vIW95aDY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_p3eDQAFy, m);
}

void Heavy_CircleStrings::cMsg_qUQoHsWC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2OOJZPEK_sendMessage);
}

void Heavy_CircleStrings::cBinop_u8SpFrI0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_MI6OJ1LF, m);
}

void Heavy_CircleStrings::cVar_G8jrQs1J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_te52h2ST, HV_BINOP_MULTIPLY, 0, m, &cBinop_te52h2ST_sendMessage);
}

void Heavy_CircleStrings::cMsg_Yszy5QIN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6mPFWpI7_sendMessage);
}

void Heavy_CircleStrings::cSystem_6mPFWpI7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UWlXHkTC_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_te52h2ST_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_RyrwZBfV_sendMessage);
}

void Heavy_CircleStrings::cBinop_Ejs8t6aT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_te52h2ST, HV_BINOP_MULTIPLY, 1, m, &cBinop_te52h2ST_sendMessage);
}

void Heavy_CircleStrings::cMsg_UWlXHkTC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Ejs8t6aT_sendMessage);
}

void Heavy_CircleStrings::cBinop_RyrwZBfV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_6EMmFUS1_sendMessage);
}

void Heavy_CircleStrings::cBinop_6EMmFUS1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_tjCpgAs6_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ThZXZHAT, m);
}

void Heavy_CircleStrings::cBinop_tjCpgAs6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_QsyUIIvc, m);
}

void Heavy_CircleStrings::cBinop_iseV7EID_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_FmLiNSv0_sendMessage);
}

void Heavy_CircleStrings::cBinop_FmLiNSv0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_63gqenBH, m);
}

void Heavy_CircleStrings::cBinop_7SRoSsrk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_5NGjewee_sendMessage);
}

void Heavy_CircleStrings::cBinop_5NGjewee_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_5tt7j5Hi_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_unskPhgA_sendMessage);
}

void Heavy_CircleStrings::cVar_aNJuv9nj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_H4d2B5dB_sendMessage);
}

void Heavy_CircleStrings::cMsg_3TY7y53p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZddV7ajX_sendMessage);
}

void Heavy_CircleStrings::cSystem_ZddV7ajX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2AQzqpR9, HV_BINOP_DIVIDE, 1, m, &cBinop_2AQzqpR9_sendMessage);
}

void Heavy_CircleStrings::cBinop_5tt7j5Hi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_uf6mg9Vl_sendMessage);
}

void Heavy_CircleStrings::cBinop_uf6mg9Vl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_HNx8Qzxt, m);
}

void Heavy_CircleStrings::cMsg_3hWpJAgo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_4XSJmLsT_sendMessage);
}

void Heavy_CircleStrings::cBinop_4XSJmLsT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_7SRoSsrk_sendMessage);
}

void Heavy_CircleStrings::cBinop_unskPhgA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_A5pVkXMo, m);
}

void Heavy_CircleStrings::cBinop_H4d2B5dB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_uwywm4xe_sendMessage);
}

void Heavy_CircleStrings::cBinop_uwywm4xe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2AQzqpR9, HV_BINOP_DIVIDE, 0, m, &cBinop_2AQzqpR9_sendMessage);
}

void Heavy_CircleStrings::cBinop_2AQzqpR9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3hWpJAgo_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_lLoppnQY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iBlmw46V_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_rY1qWc6A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GQkUKQn9_sendMessage);
}

void Heavy_CircleStrings::cSystem_GQkUKQn9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_TQbKi5Bk_sendMessage);
}

void Heavy_CircleStrings::cDelay_ch2VAmh2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ch2VAmh2, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ip4oYwDK, 0, m, &cDelay_Ip4oYwDK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ch2VAmh2, 0, m, &cDelay_ch2VAmh2_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_esRKSqBh, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_Ip4oYwDK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Ip4oYwDK, m);
  cMsg_s2STbGXR_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_7Q04YCfD_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_PP6Ivxme_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_osd2Ggn2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JGrW9t8h_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_VBU3oJzZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_92KNgrqB_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ch2VAmh2, 2, m, &cDelay_ch2VAmh2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vVM8N28j_sendMessage);
}

void Heavy_CircleStrings::cMsg_JGrW9t8h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_VBU3oJzZ, 0, m, &hTable_VBU3oJzZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_TQbKi5Bk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_osd2Ggn2_sendMessage);
}

void Heavy_CircleStrings::cMsg_s2STbGXR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_VBU3oJzZ, 0, m, &hTable_VBU3oJzZ_sendMessage);
}

void Heavy_CircleStrings::cCast_vVM8N28j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ch2VAmh2, 0, m, &cDelay_ch2VAmh2_sendMessage);
}

void Heavy_CircleStrings::cMsg_92KNgrqB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ip4oYwDK, 2, m, &cDelay_Ip4oYwDK_sendMessage);
}

void Heavy_CircleStrings::cMsg_PP6Ivxme_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_esRKSqBh, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_9RCyVg3F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_iBlmw46V_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_iBlmw46V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_fRnLX3Ss, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_gW7494OR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cMsg_DWSmJ25w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_40MMEGC1_sendMessage);
}

void Heavy_CircleStrings::cSystem_40MMEGC1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VY3OfCJU, HV_BINOP_MULTIPLY, 1, m, &cBinop_VY3OfCJU_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_RnE2aaF3, HV_BINOP_MULTIPLY, 1, m, &cBinop_RnE2aaF3_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_jQhFmfiM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_Vu2Uq2gD_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_Vu2Uq2gD_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vNptSLcI_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_vp9tGRme_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vp9tGRme, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vp9tGRme, 0, m, &cDelay_vp9tGRme_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_6TqVLbNk, 0, m, &cVar_6TqVLbNk_sendMessage);
}

void Heavy_CircleStrings::cCast_vNptSLcI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Vu2Uq2gD_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vp9tGRme, 0, m, &cDelay_vp9tGRme_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_6TqVLbNk, 0, m, &cVar_6TqVLbNk_sendMessage);
}

void Heavy_CircleStrings::cMsg_Lv2rUYq0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_azic4DZ4_sendMessage);
}

void Heavy_CircleStrings::cSystem_azic4DZ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_I7N1BvBr_sendMessage);
}

void Heavy_CircleStrings::cVar_Uynq530P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GOUxF8Qv, HV_BINOP_MULTIPLY, 0, m, &cBinop_GOUxF8Qv_sendMessage);
}

void Heavy_CircleStrings::cMsg_Vu2Uq2gD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_vp9tGRme, 0, m, &cDelay_vp9tGRme_sendMessage);
}

void Heavy_CircleStrings::cBinop_9Bo9oVHJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_vp9tGRme, 2, m, &cDelay_vp9tGRme_sendMessage);
}

void Heavy_CircleStrings::cBinop_I7N1BvBr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GOUxF8Qv, HV_BINOP_MULTIPLY, 1, m, &cBinop_GOUxF8Qv_sendMessage);
}

void Heavy_CircleStrings::cBinop_GOUxF8Qv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_9Bo9oVHJ_sendMessage);
}

void Heavy_CircleStrings::cVar_6TqVLbNk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kpDTEmMt, HV_BINOP_SUBTRACT, 0, m, &cBinop_kpDTEmMt_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_wNTlHNtK_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_f422uepM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9JqBGAgc_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RGFqxdWq_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_9JqBGAgc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cP3GRcSx, 0, m, &cVar_cP3GRcSx_sendMessage);
}

void Heavy_CircleStrings::cCast_RGFqxdWq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BjFpKEX0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vgzSQl9C_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_bDYx8sqn_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_7jpQacey, 0, m, &cSlice_7jpQacey_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_MDn66eZA, 0, m, &cSlice_MDn66eZA_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_690IVI4k_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Q6qW0Xb9, 0, m, &cSlice_Q6qW0Xb9_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_hQ0RcpM4, 0, m, &cSlice_hQ0RcpM4_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JztP8TAY_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_J7otzhze_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cSlice_7jpQacey_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_yUlVp7fC_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_yUlVp7fC_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_MDn66eZA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bnTJi5SB_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UGfwSuWK_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bnTJi5SB_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UGfwSuWK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_ExrZRXYO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SZcS9uSF_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_VFIEsr3t_sendMessage);
}

void Heavy_CircleStrings::cVar_8UjNKdi6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_0kKqeyWl_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_0kKqeyWl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ivLmUZNN_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_VY3OfCJU, HV_BINOP_MULTIPLY, 0, m, &cBinop_VY3OfCJU_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_Hl46gOXY, HV_BINOP_DIVIDE, 1, m, &cBinop_Hl46gOXY_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_Uynq530P, 0, m, &cVar_Uynq530P_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_ivLmUZNN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Jk35ZeUe_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_mDYSGxXq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1Tau0NLH, HV_BINOP_SUBTRACT, 1, m, &cBinop_1Tau0NLH_sendMessage);
}

void Heavy_CircleStrings::cVar_A4ETXT8r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cP3GRcSx, 0, m, &cVar_cP3GRcSx_sendMessage);
}

void Heavy_CircleStrings::cVar_cP3GRcSx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_meZg2LwW, HV_BINOP_ADD, 0, m, &cBinop_meZg2LwW_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_RUqK2zQ0, HV_BINOP_ADD, 0, m, &cBinop_RUqK2zQ0_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_oHaGEbZO, 0, m, &cVar_oHaGEbZO_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_NYDHHiVv_sendMessage);
}

void Heavy_CircleStrings::cSlice_Q6qW0Xb9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SZcS9uSF_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_VFIEsr3t_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_hQ0RcpM4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_B6Snt1yE_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XoXOQko3_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_9Jg7yADU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6TqVLbNk, 1, m, &cVar_6TqVLbNk_sendMessage);
}

void Heavy_CircleStrings::cBinop_RnE2aaF3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9Jg7yADU_sendMessage);
}

void Heavy_CircleStrings::cBinop_VY3OfCJU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_6Xt1DL4J_sendMessage);
}

void Heavy_CircleStrings::cBinop_6Xt1DL4J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kpDTEmMt, HV_BINOP_SUBTRACT, 1, m, &cBinop_kpDTEmMt_sendMessage);
}

void Heavy_CircleStrings::cBinop_kpDTEmMt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6TqVLbNk, 1, m, &cVar_6TqVLbNk_sendMessage);
}

void Heavy_CircleStrings::cMsg_dwbFlrNq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_jQhFmfiM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_jUaSuvYl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_jQhFmfiM_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_RUqK2zQ0, HV_BINOP_ADD, 1, m, &cBinop_RUqK2zQ0_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_meZg2LwW, HV_BINOP_ADD, 1, m, &cBinop_meZg2LwW_sendMessage);
}

void Heavy_CircleStrings::cBinop_wNTlHNtK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_f422uepM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_meZg2LwW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cP3GRcSx, 1, m, &cVar_cP3GRcSx_sendMessage);
}

void Heavy_CircleStrings::cBinop_Hl46gOXY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qn66d3IK, HV_BINOP_DIVIDE, 1, m, &cBinop_qn66d3IK_sendMessage);
}

void Heavy_CircleStrings::cBinop_qn66d3IK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RUqK2zQ0, HV_BINOP_ADD, 1, m, &cBinop_RUqK2zQ0_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_meZg2LwW, HV_BINOP_ADD, 1, m, &cBinop_meZg2LwW_sendMessage);
}

void Heavy_CircleStrings::cCast_VFIEsr3t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Hl46gOXY, HV_BINOP_DIVIDE, 0, m, &cBinop_Hl46gOXY_sendMessage);
}

void Heavy_CircleStrings::cCast_SZcS9uSF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RnE2aaF3, HV_BINOP_MULTIPLY, 0, m, &cBinop_RnE2aaF3_sendMessage);
}

void Heavy_CircleStrings::cCast_XoXOQko3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1Tau0NLH, HV_BINOP_SUBTRACT, 0, m, &cBinop_1Tau0NLH_sendMessage);
}

void Heavy_CircleStrings::cCast_B6Snt1yE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_A4ETXT8r, 1, m, &cVar_A4ETXT8r_sendMessage);
}

void Heavy_CircleStrings::cCast_vgzSQl9C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_A4ETXT8r, 0, m, &cVar_A4ETXT8r_sendMessage);
}

void Heavy_CircleStrings::cCast_BjFpKEX0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jUaSuvYl_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_RUqK2zQ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mDYSGxXq, 0, m, &cVar_mDYSGxXq_sendMessage);
}

void Heavy_CircleStrings::cMsg_yUlVp7fC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_jQhFmfiM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_w3meXBP8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_ExrZRXYO, 1, m, &cVar_ExrZRXYO_sendMessage);
}

void Heavy_CircleStrings::cMsg_Jk35ZeUe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_VY3OfCJU, HV_BINOP_MULTIPLY, 0, m, &cBinop_VY3OfCJU_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Hl46gOXY, HV_BINOP_DIVIDE, 1, m, &cBinop_Hl46gOXY_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Uynq530P, 0, m, &cVar_Uynq530P_sendMessage);
}

void Heavy_CircleStrings::cCast_bnTJi5SB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yUlVp7fC_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_UGfwSuWK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IVioTv2V_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_RUqK2zQ0, HV_BINOP_ADD, 0, m, &cBinop_RUqK2zQ0_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_cP3GRcSx, 1, m, &cVar_cP3GRcSx_sendMessage);
}

void Heavy_CircleStrings::cBinop_1Tau0NLH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qn66d3IK, HV_BINOP_DIVIDE, 0, m, &cBinop_qn66d3IK_sendMessage);
}

void Heavy_CircleStrings::cCast_IVioTv2V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jUaSuvYl_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_J7otzhze_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_w3meXBP8_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_690IVI4k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ExrZRXYO, 0, m, &cVar_ExrZRXYO_sendMessage);
}

void Heavy_CircleStrings::cCast_JztP8TAY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dwbFlrNq_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_oHaGEbZO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cPack_s5Sfe3h5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_bDYx8sqn_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_8w76cRsN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ocuKKhqb_sendMessage);
}

void Heavy_CircleStrings::cSystem_ocuKKhqb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NTvVOp5O, HV_BINOP_MULTIPLY, 1, m, &cBinop_NTvVOp5O_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zUrtvA3b, HV_BINOP_MULTIPLY, 1, m, &cBinop_zUrtvA3b_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_WrHUa3Jf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_qOIBVjnR_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_qOIBVjnR_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Kd01lqul_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_40dvEclx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_40dvEclx, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_40dvEclx, 0, m, &cDelay_40dvEclx_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_gv4uLgW0, 0, m, &cVar_gv4uLgW0_sendMessage);
}

void Heavy_CircleStrings::cCast_Kd01lqul_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qOIBVjnR_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_40dvEclx, 0, m, &cDelay_40dvEclx_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_gv4uLgW0, 0, m, &cVar_gv4uLgW0_sendMessage);
}

void Heavy_CircleStrings::cMsg_JvOhUwAt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yizRiIzd_sendMessage);
}

void Heavy_CircleStrings::cSystem_yizRiIzd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_L8lCDLoC_sendMessage);
}

void Heavy_CircleStrings::cVar_R0pcyLuB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ze92IlFp, HV_BINOP_MULTIPLY, 0, m, &cBinop_Ze92IlFp_sendMessage);
}

void Heavy_CircleStrings::cMsg_qOIBVjnR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_40dvEclx, 0, m, &cDelay_40dvEclx_sendMessage);
}

void Heavy_CircleStrings::cBinop_8KEaHzkY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_40dvEclx, 2, m, &cDelay_40dvEclx_sendMessage);
}

void Heavy_CircleStrings::cBinop_L8lCDLoC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ze92IlFp, HV_BINOP_MULTIPLY, 1, m, &cBinop_Ze92IlFp_sendMessage);
}

void Heavy_CircleStrings::cBinop_Ze92IlFp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_8KEaHzkY_sendMessage);
}

void Heavy_CircleStrings::cVar_gv4uLgW0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1MCleYou, HV_BINOP_SUBTRACT, 0, m, &cBinop_1MCleYou_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_b6sQlQ3x_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_vZCAWSdb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3r4GJFcB_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6mqcIPuV_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_3r4GJFcB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aE2sbu0Y, 0, m, &cVar_aE2sbu0Y_sendMessage);
}

void Heavy_CircleStrings::cCast_6mqcIPuV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_klHSItIE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RVruq6MD_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_VgwgeX4j_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_3FcG2eP6, 0, m, &cSlice_3FcG2eP6_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_hzxHCUvd, 0, m, &cSlice_hzxHCUvd_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wkC8isF2_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_SSrEV2P9, 0, m, &cSlice_SSrEV2P9_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_sKzkXWhJ, 0, m, &cSlice_sKzkXWhJ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2FM9jfmt_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Z7KjNm5E_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cSlice_3FcG2eP6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_8jWn5GY8_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_8jWn5GY8_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_hzxHCUvd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hPAV1NXa_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nLNhw2lg_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hPAV1NXa_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nLNhw2lg_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_OSOWVX3F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XTMgkl0F_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7dYR3tf4_sendMessage);
}

void Heavy_CircleStrings::cVar_PK8cZwxn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_P66g77qQ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_P66g77qQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_maeil4Kl_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_NTvVOp5O, HV_BINOP_MULTIPLY, 0, m, &cBinop_NTvVOp5O_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_WakJ39ux, HV_BINOP_DIVIDE, 1, m, &cBinop_WakJ39ux_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_R0pcyLuB, 0, m, &cVar_R0pcyLuB_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_maeil4Kl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_m59V73Fi_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_3Gl8TCrA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ttKEN1A5, HV_BINOP_SUBTRACT, 1, m, &cBinop_ttKEN1A5_sendMessage);
}

void Heavy_CircleStrings::cVar_qIRn0zTO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aE2sbu0Y, 0, m, &cVar_aE2sbu0Y_sendMessage);
}

void Heavy_CircleStrings::cVar_aE2sbu0Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JfnAC6vL, HV_BINOP_ADD, 0, m, &cBinop_JfnAC6vL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_If5CaFi5, HV_BINOP_ADD, 0, m, &cBinop_If5CaFi5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_gW7494OR, 0, m, &cVar_gW7494OR_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_1fIo3oEh, m);
}

void Heavy_CircleStrings::cSlice_SSrEV2P9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XTMgkl0F_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7dYR3tf4_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_sKzkXWhJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_R4xhuYGM_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jTk3OgMi_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_sWNl3A0l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gv4uLgW0, 1, m, &cVar_gv4uLgW0_sendMessage);
}

void Heavy_CircleStrings::cBinop_zUrtvA3b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_sWNl3A0l_sendMessage);
}

void Heavy_CircleStrings::cBinop_NTvVOp5O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_NeL4eN2Y_sendMessage);
}

void Heavy_CircleStrings::cBinop_NeL4eN2Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1MCleYou, HV_BINOP_SUBTRACT, 1, m, &cBinop_1MCleYou_sendMessage);
}

void Heavy_CircleStrings::cBinop_1MCleYou_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gv4uLgW0, 1, m, &cVar_gv4uLgW0_sendMessage);
}

void Heavy_CircleStrings::cMsg_q2agLrnu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_WrHUa3Jf_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_061zudvC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_WrHUa3Jf_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_If5CaFi5, HV_BINOP_ADD, 1, m, &cBinop_If5CaFi5_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JfnAC6vL, HV_BINOP_ADD, 1, m, &cBinop_JfnAC6vL_sendMessage);
}

void Heavy_CircleStrings::cBinop_b6sQlQ3x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_vZCAWSdb_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_JfnAC6vL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aE2sbu0Y, 1, m, &cVar_aE2sbu0Y_sendMessage);
}

void Heavy_CircleStrings::cBinop_WakJ39ux_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9y8LGWO8, HV_BINOP_DIVIDE, 1, m, &cBinop_9y8LGWO8_sendMessage);
}

void Heavy_CircleStrings::cBinop_9y8LGWO8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_If5CaFi5, HV_BINOP_ADD, 1, m, &cBinop_If5CaFi5_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JfnAC6vL, HV_BINOP_ADD, 1, m, &cBinop_JfnAC6vL_sendMessage);
}

void Heavy_CircleStrings::cCast_XTMgkl0F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zUrtvA3b, HV_BINOP_MULTIPLY, 0, m, &cBinop_zUrtvA3b_sendMessage);
}

void Heavy_CircleStrings::cCast_7dYR3tf4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WakJ39ux, HV_BINOP_DIVIDE, 0, m, &cBinop_WakJ39ux_sendMessage);
}

void Heavy_CircleStrings::cCast_jTk3OgMi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ttKEN1A5, HV_BINOP_SUBTRACT, 0, m, &cBinop_ttKEN1A5_sendMessage);
}

void Heavy_CircleStrings::cCast_R4xhuYGM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qIRn0zTO, 1, m, &cVar_qIRn0zTO_sendMessage);
}

void Heavy_CircleStrings::cCast_klHSItIE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_061zudvC_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_RVruq6MD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qIRn0zTO, 0, m, &cVar_qIRn0zTO_sendMessage);
}

void Heavy_CircleStrings::cBinop_If5CaFi5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3Gl8TCrA, 0, m, &cVar_3Gl8TCrA_sendMessage);
}

void Heavy_CircleStrings::cMsg_8jWn5GY8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_WrHUa3Jf_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_ApPrajnS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_OSOWVX3F, 1, m, &cVar_OSOWVX3F_sendMessage);
}

void Heavy_CircleStrings::cMsg_m59V73Fi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_NTvVOp5O, HV_BINOP_MULTIPLY, 0, m, &cBinop_NTvVOp5O_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_WakJ39ux, HV_BINOP_DIVIDE, 1, m, &cBinop_WakJ39ux_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_R0pcyLuB, 0, m, &cVar_R0pcyLuB_sendMessage);
}

void Heavy_CircleStrings::cCast_hPAV1NXa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8jWn5GY8_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_nLNhw2lg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YOuxyPwn_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_If5CaFi5, HV_BINOP_ADD, 0, m, &cBinop_If5CaFi5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_aE2sbu0Y, 1, m, &cVar_aE2sbu0Y_sendMessage);
}

void Heavy_CircleStrings::cBinop_ttKEN1A5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9y8LGWO8, HV_BINOP_DIVIDE, 0, m, &cBinop_9y8LGWO8_sendMessage);
}

void Heavy_CircleStrings::cCast_YOuxyPwn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_061zudvC_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_Z7KjNm5E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ApPrajnS_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_wkC8isF2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OSOWVX3F, 0, m, &cVar_OSOWVX3F_sendMessage);
}

void Heavy_CircleStrings::cCast_2FM9jfmt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_q2agLrnu_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_pM9lzrWZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_VgwgeX4j_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_p5W4lEzM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_WPYgXQjR, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_Sp0sOuNj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 4.0f, 0, m, &cBinop_Xxexs43M_sendMessage);
}

void Heavy_CircleStrings::cBinop_Xxexs43M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_s5Sfe3h5, 0, m, &cPack_s5Sfe3h5_sendMessage);
}

void Heavy_CircleStrings::cBinop_A9bQmhbd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Sp0sOuNj_sendMessage);
}

void Heavy_CircleStrings::cCast_q52goVgN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_VTf57QKS_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_tBMOvBoZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_qY8Oxy5B_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_faLU9lvh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.15f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_iseV7EID_sendMessage);
}

void Heavy_CircleStrings::cBinop_XeqCoCZo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_cXErTds9_sendMessage);
}

void Heavy_CircleStrings::cBinop_cXErTds9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_dQAc5eAI_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ry7HyJJ3_sendMessage);
}

void Heavy_CircleStrings::cVar_BBz2VrJD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_ycR38kmO_sendMessage);
}

void Heavy_CircleStrings::cMsg_GvE7FZ51_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Jw8bK3rp_sendMessage);
}

void Heavy_CircleStrings::cSystem_Jw8bK3rp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OJErSLAh, HV_BINOP_DIVIDE, 1, m, &cBinop_OJErSLAh_sendMessage);
}

void Heavy_CircleStrings::cBinop_dQAc5eAI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_NHw7avuG_sendMessage);
}

void Heavy_CircleStrings::cBinop_NHw7avuG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_HoxPe96z, m);
}

void Heavy_CircleStrings::cMsg_qnAPlUyF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_Q0tqtW2n_sendMessage);
}

void Heavy_CircleStrings::cBinop_Q0tqtW2n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_XeqCoCZo_sendMessage);
}

void Heavy_CircleStrings::cBinop_ry7HyJJ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_gCaZXOIc, m);
}

void Heavy_CircleStrings::cBinop_ycR38kmO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_nHJtkLMS_sendMessage);
}

void Heavy_CircleStrings::cBinop_nHJtkLMS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OJErSLAh, HV_BINOP_DIVIDE, 0, m, &cBinop_OJErSLAh_sendMessage);
}

void Heavy_CircleStrings::cBinop_OJErSLAh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qnAPlUyF_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_IbvxVxyB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cIf_MKWmybUd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_F8w1NWy4_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_6vTEKeu0, 0, m, &cIf_6vTEKeu0_sendMessage);
      break;
    }
    case 1: {
      cMsg_kgvnFDBL_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_CD109Vwp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_MKWmybUd, 1, m, &cIf_MKWmybUd_sendMessage);
}

void Heavy_CircleStrings::cIf_6vTEKeu0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_t4Im3Ir3_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_AMhouR2A_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_F8w1NWy4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_6vTEKeu0, 1, m, &cIf_6vTEKeu0_sendMessage);
}

void Heavy_CircleStrings::cMsg_kgvnFDBL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_AMhouR2A_sendMessage);
}

void Heavy_CircleStrings::cMsg_t4Im3Ir3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_AMhouR2A_sendMessage);
}

void Heavy_CircleStrings::cIf_EzqhaleF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_xCbd1CWu_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_RCBr8eA3, 0, m, &cIf_RCBr8eA3_sendMessage);
      break;
    }
    case 1: {
      cMsg_5ucPjgE4_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_BiaSpywp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_EzqhaleF, 1, m, &cIf_EzqhaleF_sendMessage);
}

void Heavy_CircleStrings::cIf_RCBr8eA3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_LriYBtBw_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_zzAVI3kb, 0, m, &cPack_zzAVI3kb_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_xCbd1CWu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_RCBr8eA3, 1, m, &cIf_RCBr8eA3_sendMessage);
}

void Heavy_CircleStrings::cMsg_5ucPjgE4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_zzAVI3kb, 0, m, &cPack_zzAVI3kb_sendMessage);
}

void Heavy_CircleStrings::cMsg_LriYBtBw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_zzAVI3kb, 0, m, &cPack_zzAVI3kb_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_qTaogUTf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_u2JOnIh0, 0, m, &cSlice_u2JOnIh0_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_2fNkv4Oi, 0, m, &cRandom_2fNkv4Oi_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_qDKkdr77_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_NRGZ78iA_sendMessage);
}

void Heavy_CircleStrings::cUnop_NRGZ78iA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_txxcirLj_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_2fNkv4Oi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_qDKkdr77_sendMessage);
}

void Heavy_CircleStrings::cSlice_u2JOnIh0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_2fNkv4Oi, 1, m, &cRandom_2fNkv4Oi_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_txxcirLj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_imSFUkZK, m);
}

void Heavy_CircleStrings::cTabhead_PIRTcLF5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CyzUsgAK, HV_BINOP_SUBTRACT, 0, m, &cBinop_CyzUsgAK_sendMessage);
}

void Heavy_CircleStrings::cMsg_5mOBspZF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TQjGgypS_sendMessage);
}

void Heavy_CircleStrings::cSystem_TQjGgypS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_o1Dcq7gO_sendMessage);
}

void Heavy_CircleStrings::cVar_OeTUhH3r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UGLG2PeU_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_lcR1OtSv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_lcR1OtSv, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WmmDrW4e, 0, m, &cDelay_WmmDrW4e_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_HDwvRVpY, 0, m, &sTabread_HDwvRVpY_sendMessage);
}

void Heavy_CircleStrings::cDelay_WmmDrW4e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WmmDrW4e, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_HDwvRVpY, 0, m, &sTabread_HDwvRVpY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WmmDrW4e, 0, m, &cDelay_WmmDrW4e_sendMessage);
}

void Heavy_CircleStrings::sTabread_HDwvRVpY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_8U5bnbTx, HV_BINOP_SUBTRACT, 0, m, &cBinop_8U5bnbTx_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_MlOkrRKT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_drkt3Wkh, HV_BINOP_MAX, 0, m, &cBinop_drkt3Wkh_sendMessage);
}

void Heavy_CircleStrings::cBinop_o1Dcq7gO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MlOkrRKT, HV_BINOP_MULTIPLY, 0, m, &cBinop_MlOkrRKT_sendMessage);
}

void Heavy_CircleStrings::cBinop_CyzUsgAK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_y203D8j5_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_HDwvRVpY, 0, m, &sTabread_HDwvRVpY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bKkEX9Qt_sendMessage);
}

void Heavy_CircleStrings::cSystem_WI788WtB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8U5bnbTx, HV_BINOP_SUBTRACT, 1, m, &cBinop_8U5bnbTx_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WmmDrW4e, 2, m, &cDelay_WmmDrW4e_sendMessage);
}

void Heavy_CircleStrings::cMsg_UGLG2PeU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WI788WtB_sendMessage);
}

void Heavy_CircleStrings::cMsg_y203D8j5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_lcR1OtSv, 0, m, &cDelay_lcR1OtSv_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WmmDrW4e, 0, m, &cDelay_WmmDrW4e_sendMessage);
}

void Heavy_CircleStrings::cMsg_pxvSbewf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_drkt3Wkh, HV_BINOP_MAX, 1, m, &cBinop_drkt3Wkh_sendMessage);
}

void Heavy_CircleStrings::cBinop_drkt3Wkh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CyzUsgAK, HV_BINOP_SUBTRACT, 1, m, &cBinop_CyzUsgAK_sendMessage);
}

void Heavy_CircleStrings::cCast_bKkEX9Qt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_lcR1OtSv, 0, m, &cDelay_lcR1OtSv_sendMessage);
}

void Heavy_CircleStrings::cBinop_nSb07jDt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_lcR1OtSv, 2, m, &cDelay_lcR1OtSv_sendMessage);
}

void Heavy_CircleStrings::cBinop_8U5bnbTx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_nSb07jDt_sendMessage);
}

void Heavy_CircleStrings::cCast_wFRUAidY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OeTUhH3r, 0, m, &cVar_OeTUhH3r_sendMessage);
  cMsg_5mOBspZF_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_PIRTcLF5, 0, m, &cTabhead_PIRTcLF5_sendMessage);
}

void Heavy_CircleStrings::cBinop_VvbgdrAk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HxBzSSDJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oKLaQK3o_sendMessage);
}

void Heavy_CircleStrings::cBinop_X9jCwxm1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_MaTpYgEX_sendMessage);
}

void Heavy_CircleStrings::cBinop_MaTpYgEX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PzrxcvzK, HV_BINOP_POW, 1, m, &cBinop_PzrxcvzK_sendMessage);
  cMsg_hJm8HocJ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_PzrxcvzK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_VvbgdrAk_sendMessage);
}

void Heavy_CircleStrings::cMsg_hJm8HocJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_PzrxcvzK, HV_BINOP_POW, 0, m, &cBinop_PzrxcvzK_sendMessage);
}

void Heavy_CircleStrings::cVar_Qf6owR4J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_X9jCwxm1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7rv53t9B_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NOp7ql3W_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_UeBSDlT8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_UheLACQj_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_UheLACQj_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_d1lvyhXv, 1, m, &cDelay_d1lvyhXv_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_X02PVTRO_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_d1lvyhXv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_d1lvyhXv, m);
  cMsg_REOo4rjv_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_UheLACQj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_d1lvyhXv, 0, m, &cDelay_d1lvyhXv_sendMessage);
}

void Heavy_CircleStrings::cCast_X02PVTRO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_d1lvyhXv, 0, m, &cDelay_d1lvyhXv_sendMessage);
}

void Heavy_CircleStrings::cVar_nYgxT2Ub_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AaqJX4YH, HV_BINOP_MULTIPLY, 0, m, &cBinop_AaqJX4YH_sendMessage);
}

void Heavy_CircleStrings::cMsg_jVEfEQ2J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rSvwdYYu_sendMessage);
}

void Heavy_CircleStrings::cSystem_rSvwdYYu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_io9RGo4R_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_AaqJX4YH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_oJeZFOpw_sendMessage);
}

void Heavy_CircleStrings::cBinop_FMdcR3D7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AaqJX4YH, HV_BINOP_MULTIPLY, 1, m, &cBinop_AaqJX4YH_sendMessage);
}

void Heavy_CircleStrings::cMsg_io9RGo4R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_FMdcR3D7_sendMessage);
}

void Heavy_CircleStrings::cBinop_oJeZFOpw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_gv1YF94v_sendMessage);
}

void Heavy_CircleStrings::cBinop_gv1YF94v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_IlWEb4VJ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_1umjGuSQ, m);
}

void Heavy_CircleStrings::cBinop_IlWEb4VJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_IaFSZ6XV, m);
}

void Heavy_CircleStrings::cMsg_nr5HY5lq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dYEHhaMk_sendMessage);
}

void Heavy_CircleStrings::cSystem_dYEHhaMk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_dQQd9Fwj_sendMessage);
}

void Heavy_CircleStrings::cDelay_wOgy7IS2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wOgy7IS2, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_A3jm9Jcp, 0, m, &cDelay_A3jm9Jcp_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wOgy7IS2, 0, m, &cDelay_wOgy7IS2_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_zwygWby1, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_A3jm9Jcp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_A3jm9Jcp, m);
  cMsg_IOJ2cDM0_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_oHu3RRWs_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_2E9sgxMl_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_Tivw6jOh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JfmiRc8M_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_3VwDfFas_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sMw3Zo0n_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wOgy7IS2, 2, m, &cDelay_wOgy7IS2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_a5hCtDUA_sendMessage);
}

void Heavy_CircleStrings::cMsg_JfmiRc8M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_3VwDfFas, 0, m, &hTable_3VwDfFas_sendMessage);
}

void Heavy_CircleStrings::cBinop_dQQd9Fwj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_Tivw6jOh_sendMessage);
}

void Heavy_CircleStrings::cMsg_IOJ2cDM0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_3VwDfFas, 0, m, &hTable_3VwDfFas_sendMessage);
}

void Heavy_CircleStrings::cCast_a5hCtDUA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wOgy7IS2, 0, m, &cDelay_wOgy7IS2_sendMessage);
}

void Heavy_CircleStrings::cMsg_sMw3Zo0n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_A3jm9Jcp, 2, m, &cDelay_A3jm9Jcp_sendMessage);
}

void Heavy_CircleStrings::cMsg_2E9sgxMl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_zwygWby1, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_V24NIA9j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_5roWFc9V, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_REOo4rjv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_5roWFc9V, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_7rv53t9B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_UeBSDlT8_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_NOp7ql3W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_V24NIA9j_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_H3kNgD83_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_X9jCwxm1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7rv53t9B_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NOp7ql3W_sendMessage);
}

void Heavy_CircleStrings::cBinop_PqEEF3aq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MlOkrRKT, HV_BINOP_MULTIPLY, 1, m, &cBinop_MlOkrRKT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wFRUAidY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_d1lvyhXv, 1, m, &cDelay_d1lvyhXv_sendMessage);
}

void Heavy_CircleStrings::cMsg_z1YjvNrE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_PqEEF3aq, HV_BINOP_DIVIDE, 0, m, &cBinop_PqEEF3aq_sendMessage);
}

void Heavy_CircleStrings::cCast_HxBzSSDJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PqEEF3aq, HV_BINOP_DIVIDE, 1, m, &cBinop_PqEEF3aq_sendMessage);
}

void Heavy_CircleStrings::cCast_oKLaQK3o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_z1YjvNrE_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_OGdSgNum_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_G1DCgtRM_sendMessage);
  cSwitchcase_suxNSMFy_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_G1DCgtRM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OGdSgNum, 1, m, &cVar_OGdSgNum_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_suxNSMFy_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_Wjzl68UX_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_Wjzl68UX_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_V7tgQxfC_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_5A5eNh5O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5A5eNh5O, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5A5eNh5O, 0, m, &cDelay_5A5eNh5O_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_QhchSK7Q, 0, m, &cVar_QhchSK7Q_sendMessage);
  cSwitchcase_dmfcothH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_V7tgQxfC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Wjzl68UX_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5A5eNh5O, 0, m, &cDelay_5A5eNh5O_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_QhchSK7Q, 0, m, &cVar_QhchSK7Q_sendMessage);
  cSwitchcase_dmfcothH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_fzmAZoD0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LilqbDHi_sendMessage);
}

void Heavy_CircleStrings::cSystem_LilqbDHi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_IjAH3bDS_sendMessage);
}

void Heavy_CircleStrings::cVar_OtXf2NGF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mjDNokV1, HV_BINOP_MULTIPLY, 0, m, &cBinop_mjDNokV1_sendMessage);
}

void Heavy_CircleStrings::cMsg_Wjzl68UX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_5A5eNh5O, 0, m, &cDelay_5A5eNh5O_sendMessage);
}

void Heavy_CircleStrings::cBinop_FrcSGy1q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5A5eNh5O, 2, m, &cDelay_5A5eNh5O_sendMessage);
}

void Heavy_CircleStrings::cBinop_IjAH3bDS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mjDNokV1, HV_BINOP_MULTIPLY, 1, m, &cBinop_mjDNokV1_sendMessage);
}

void Heavy_CircleStrings::cBinop_mjDNokV1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_FrcSGy1q_sendMessage);
}

void Heavy_CircleStrings::cVar_QhchSK7Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_X9jCwxm1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7rv53t9B_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NOp7ql3W_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_dmfcothH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_0Hy7nkHZ, 0, m, &cSlice_0Hy7nkHZ_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_DCGfYeak, 0, m, &cRandom_DCGfYeak_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_ndxLiiZv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_mCuCHOjS_sendMessage);
}

void Heavy_CircleStrings::cUnop_mCuCHOjS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 40.0f, 0, m, &cBinop_jzEm1Fax_sendMessage);
}

void Heavy_CircleStrings::cRandom_DCGfYeak_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.0f, 0, m, &cBinop_ndxLiiZv_sendMessage);
}

void Heavy_CircleStrings::cSlice_0Hy7nkHZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_DCGfYeak, 1, m, &cRandom_DCGfYeak_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_6cXDqffS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cIf_dfixUOX6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, -1.0f, 0, m, &cBinop_yPDzNYoN_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_7tBGhXkj, 0, m, &cIf_7tBGhXkj_sendMessage);
      break;
    }
    case 1: {
      cMsg_n18gmDlC_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_mB3jZkYD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_dfixUOX6, 1, m, &cIf_dfixUOX6_sendMessage);
}

void Heavy_CircleStrings::cIf_7tBGhXkj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_46yYJVXb_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.049f, 0, m, &cBinop_MvoLLbiT_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_yPDzNYoN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_7tBGhXkj, 1, m, &cIf_7tBGhXkj_sendMessage);
}

void Heavy_CircleStrings::cMsg_n18gmDlC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.049f, 0, m, &cBinop_MvoLLbiT_sendMessage);
}

void Heavy_CircleStrings::cMsg_46yYJVXb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.049f, 0, m, &cBinop_MvoLLbiT_sendMessage);
}

void Heavy_CircleStrings::cIf_ipB21fYo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_kk53XaBi_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_Qunc2MVB, 0, m, &cIf_Qunc2MVB_sendMessage);
      break;
    }
    case 1: {
      cMsg_sMdxgvKw_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_3wSKtJTU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ipB21fYo, 1, m, &cIf_ipB21fYo_sendMessage);
}

void Heavy_CircleStrings::cIf_Qunc2MVB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_tzjs49uG_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4600.0f, 0, m, &cBinop_Wj7QFZJ0_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_kk53XaBi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Qunc2MVB, 1, m, &cIf_Qunc2MVB_sendMessage);
}

void Heavy_CircleStrings::cMsg_sMdxgvKw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4600.0f, 0, m, &cBinop_Wj7QFZJ0_sendMessage);
}

void Heavy_CircleStrings::cMsg_tzjs49uG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4600.0f, 0, m, &cBinop_Wj7QFZJ0_sendMessage);
}

void Heavy_CircleStrings::cPack_5GPJyP0F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_K8cYsBc9, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_zzAVI3kb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Y6DRCJ34, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_RGHPRDk2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IbvxVxyB, 0, m, &cVar_IbvxVxyB_sendMessage);
}

void Heavy_CircleStrings::cBinop_AMhouR2A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5f, 0, m, &cBinop_99drQywp_sendMessage);
}

void Heavy_CircleStrings::cBinop_99drQywp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_BiaSpywp_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_EzqhaleF, 0, m, &cIf_EzqhaleF_sendMessage);
}

void Heavy_CircleStrings::cBinop_jzEm1Fax_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OtXf2NGF, 0, m, &cVar_OtXf2NGF_sendMessage);
}

void Heavy_CircleStrings::cBinop_AgbGdGmc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_THiWq8rS, m);
}

void Heavy_CircleStrings::cBinop_MvoLLbiT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.95f, 0, m, &cBinop_AgbGdGmc_sendMessage);
}

void Heavy_CircleStrings::cBinop_kusWzUfu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nYgxT2Ub, 0, m, &cVar_nYgxT2Ub_sendMessage);
}

void Heavy_CircleStrings::cBinop_Wj7QFZJ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2200.0f, 0, m, &cBinop_kusWzUfu_sendMessage);
}

void Heavy_CircleStrings::cCast_HFQawIg5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Vxf3SdJE_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_X3XoYm3P_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_gXuHmMkT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_5wf6nFFQ_sendMessage(_c, 0, m);
  cSend_Xjd3PzCr_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_Vxf3SdJE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_B7BRgCX1, 0, m, &cSlice_B7BRgCX1_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_M18YHlgf, 0, m, &cRandom_M18YHlgf_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_HJM9xxUp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_RiCCNLbn_sendMessage);
}

void Heavy_CircleStrings::cUnop_RiCCNLbn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1.28f, 0, m, &cBinop_3ZqgWM4V_sendMessage);
  cSend_peH1dWaw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_M18YHlgf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 128.0f, 0, m, &cBinop_HJM9xxUp_sendMessage);
}

void Heavy_CircleStrings::cSlice_B7BRgCX1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_M18YHlgf, 1, m, &cRandom_M18YHlgf_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_UBbjGlJr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_92LmqkRA_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_JfowikST_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_JLNecoq8_sendMessage);
}

void Heavy_CircleStrings::cBinop_JLNecoq8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JfowikST, 1, m, &cVar_JfowikST_sendMessage);
}

void Heavy_CircleStrings::cCast_zQkTilfh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_rnidVc9v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_y7777dEW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cCast_gAJmSBri_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_aaY5jV1I_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_X3XoYm3P_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_54jTwGcL, 0, m, &cSlice_54jTwGcL_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_EYcAnYeo, 0, m, &cRandom_EYcAnYeo_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_zozlU4h8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_fyKRSo0H_sendMessage);
}

void Heavy_CircleStrings::cUnop_fyKRSo0H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 20.0f, 0, m, &cBinop_b1P3rNQs_sendMessage);
}

void Heavy_CircleStrings::cRandom_EYcAnYeo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_zozlU4h8_sendMessage);
}

void Heavy_CircleStrings::cSlice_54jTwGcL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_EYcAnYeo, 1, m, &cRandom_EYcAnYeo_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cCast_menx8PGK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uk5Yz3uH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9VmFAB3l_sendMessage);
}

void Heavy_CircleStrings::cBinop_3ZqgWM4V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UBbjGlJr, 0, m, &cVar_UBbjGlJr_sendMessage);
}

void Heavy_CircleStrings::cSend_92LmqkRA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YsoAiR4E_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_5wf6nFFQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_mun6KkPl_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_peH1dWaw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_HTrUDWdv_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_Xjd3PzCr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_8BTEDG3f_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_87X5IkR8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.8f);
  cSend_2pWZNwOf_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_2pWZNwOf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Q1srhvcR_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_XH2WdP0f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_2pWZNwOf_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_aaY5jV1I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Ua4JpGNy_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_b1P3rNQs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gXuHmMkT, 0, m, &cVar_gXuHmMkT_sendMessage);
}

void Heavy_CircleStrings::cCast_uk5Yz3uH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_c1HEeiRP_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_9VmFAB3l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bTjvakvm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_bTjvakvm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 64.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_gXuHmMkT, 0, m, &cVar_gXuHmMkT_sendMessage);
}

void Heavy_CircleStrings::cMsg_c1HEeiRP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 127.0f);
  cSend_peH1dWaw_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1.28f, 0, m, &cBinop_3ZqgWM4V_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_rTp6sb07_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_8yx6aV99, 0, m, &cSlice_8yx6aV99_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_MJu0619A, 0, m, &cRandom_MJu0619A_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_C1NXvPdC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_7g1TqJkw_sendMessage);
}

void Heavy_CircleStrings::cUnop_7g1TqJkw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 50.0f, 0, m, &cBinop_BX2Tag67_sendMessage);
}

void Heavy_CircleStrings::cRandom_MJu0619A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_C1NXvPdC_sendMessage);
}

void Heavy_CircleStrings::cSlice_8yx6aV99_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_MJu0619A, 1, m, &cRandom_MJu0619A_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSwitchcase_Ul1DaEER_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_kh092qHC, 0, m, &cSlice_kh092qHC_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_27s3Ojzg, 0, m, &cRandom_27s3Ojzg_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_gaqUzibr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_vrrrpDZp_sendMessage);
}

void Heavy_CircleStrings::cUnop_vrrrpDZp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_nz0wrPek_sendMessage);
}

void Heavy_CircleStrings::cRandom_27s3Ojzg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_gaqUzibr_sendMessage);
}

void Heavy_CircleStrings::cSlice_kh092qHC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_27s3Ojzg, 1, m, &cRandom_27s3Ojzg_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_xyicWMiN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YFRGxe7u, HV_BINOP_MULTIPLY, 0, m, &cBinop_YFRGxe7u_sendMessage);
}

void Heavy_CircleStrings::cBinop_1JSkVvl3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_XJd9AAB8_sendMessage);
}

void Heavy_CircleStrings::cBinop_XJd9AAB8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ima0qRFV, HV_BINOP_POW, 1, m, &cBinop_ima0qRFV_sendMessage);
  cMsg_2yBQSJDE_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_ima0qRFV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_xyicWMiN_sendMessage);
}

void Heavy_CircleStrings::cMsg_2yBQSJDE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ima0qRFV, HV_BINOP_POW, 0, m, &cBinop_ima0qRFV_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_yDSgqJfe_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_RAhlGjyD, 0, m, &cSlice_RAhlGjyD_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_rART4y8z, 0, m, &cRandom_rART4y8z_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_XhbEVjmJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_qyOkhKdH_sendMessage);
}

void Heavy_CircleStrings::cUnop_qyOkhKdH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_oDrZdPSj_sendMessage);
}

void Heavy_CircleStrings::cRandom_rART4y8z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_XhbEVjmJ_sendMessage);
}

void Heavy_CircleStrings::cSlice_RAhlGjyD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_rART4y8z, 1, m, &cRandom_rART4y8z_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cPack_rAFydJof_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_pmYKKTqj, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_vhxpxuvP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_noWyaKn2_sendMessage);
}

void Heavy_CircleStrings::cVar_L1JcSeR9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_NlYSr6l6, 0, m);
}

void Heavy_CircleStrings::cVar_tuHE2vSN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FZNtbF9t_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xN6Ebmuh_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SilxpzA0_sendMessage);
}

void Heavy_CircleStrings::cVar_KS8cxS9w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_stUsVq2g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_WR9akQL7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSwitchcase_ellxB98r_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_PkTPGezf_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_PkTPGezf_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_Y8FgzI5v, 1, m, &cDelay_Y8FgzI5v_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hYkiUE8X_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_Y8FgzI5v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Y8FgzI5v, m);
  cVar_onMessage(_c, &Context(_c)->cVar_k34M7PdE, 0, m, &cVar_k34M7PdE_sendMessage);
}

void Heavy_CircleStrings::cMsg_PkTPGezf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Y8FgzI5v, 0, m, &cDelay_Y8FgzI5v_sendMessage);
}

void Heavy_CircleStrings::cCast_hYkiUE8X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Y8FgzI5v, 0, m, &cDelay_Y8FgzI5v_sendMessage);
}

void Heavy_CircleStrings::cVar_k34M7PdE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8Ih4cMn5_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_O8bXxTxt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tuHE2vSN, 0, m, &cVar_tuHE2vSN_sendMessage);
}

void Heavy_CircleStrings::cMsg_32mKshzV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_p06PZ4vL_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_FWkzHKOS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_j4ZBBeDH_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_D39JvJRc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_qCl0QC70_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_rrmXpqmV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_LrV1qEG8_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_4LzuomlI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_VV7MYDku_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_CaBFlCMx_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_p06PZ4vL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_j4ZBBeDH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_LrV1qEG8_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_qCl0QC70_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_CaBFlCMx_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_9OANVAuh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_5IIrk8lH, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_8Ih4cMn5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_5IIrk8lH, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_xN6Ebmuh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_k34M7PdE, 1, m, &cVar_k34M7PdE_sendMessage);
}

void Heavy_CircleStrings::cCast_SilxpzA0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ellxB98r_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_FZNtbF9t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9OANVAuh_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_EOi3pX6j_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_vaBC4uPt, 0, m, &cSlice_vaBC4uPt_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_BqKWc8vk, 0, m, &cRandom_BqKWc8vk_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_ji5tVQ4g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_9CwiHA2E_sendMessage);
}

void Heavy_CircleStrings::cUnop_9CwiHA2E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xHa1ML9F_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_BqKWc8vk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_ji5tVQ4g_sendMessage);
}

void Heavy_CircleStrings::cSlice_vaBC4uPt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_BqKWc8vk, 1, m, &cRandom_BqKWc8vk_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_xHa1ML9F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_mTxzKFMn, m);
}

void Heavy_CircleStrings::cTabhead_7eYUWruq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yX8vBeQ0, HV_BINOP_SUBTRACT, 0, m, &cBinop_yX8vBeQ0_sendMessage);
}

void Heavy_CircleStrings::cMsg_7AoNzPug_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WubMe9dx_sendMessage);
}

void Heavy_CircleStrings::cSystem_WubMe9dx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_WRfO463K_sendMessage);
}

void Heavy_CircleStrings::cVar_II7cyevt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ztP7DxfP_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_IPWBuSJ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IPWBuSJ6, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ko33FrQ0, 0, m, &cDelay_ko33FrQ0_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_7N4SehJC, 0, m, &sTabread_7N4SehJC_sendMessage);
}

void Heavy_CircleStrings::cDelay_ko33FrQ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ko33FrQ0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_7N4SehJC, 0, m, &sTabread_7N4SehJC_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ko33FrQ0, 0, m, &cDelay_ko33FrQ0_sendMessage);
}

void Heavy_CircleStrings::sTabread_7N4SehJC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_A7dU69Nr, HV_BINOP_SUBTRACT, 0, m, &cBinop_A7dU69Nr_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_m786xWiG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eQo2tGPK, HV_BINOP_MAX, 0, m, &cBinop_eQo2tGPK_sendMessage);
}

void Heavy_CircleStrings::cBinop_WRfO463K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m786xWiG, HV_BINOP_MULTIPLY, 0, m, &cBinop_m786xWiG_sendMessage);
}

void Heavy_CircleStrings::cBinop_yX8vBeQ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ooPNRt7L_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_7N4SehJC, 0, m, &sTabread_7N4SehJC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uGYv083i_sendMessage);
}

void Heavy_CircleStrings::cSystem_W7ciozkh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A7dU69Nr, HV_BINOP_SUBTRACT, 1, m, &cBinop_A7dU69Nr_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ko33FrQ0, 2, m, &cDelay_ko33FrQ0_sendMessage);
}

void Heavy_CircleStrings::cMsg_ztP7DxfP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_W7ciozkh_sendMessage);
}

void Heavy_CircleStrings::cMsg_ooPNRt7L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_IPWBuSJ6, 0, m, &cDelay_IPWBuSJ6_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ko33FrQ0, 0, m, &cDelay_ko33FrQ0_sendMessage);
}

void Heavy_CircleStrings::cMsg_oeTz9NWB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_eQo2tGPK, HV_BINOP_MAX, 1, m, &cBinop_eQo2tGPK_sendMessage);
}

void Heavy_CircleStrings::cBinop_eQo2tGPK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yX8vBeQ0, HV_BINOP_SUBTRACT, 1, m, &cBinop_yX8vBeQ0_sendMessage);
}

void Heavy_CircleStrings::cCast_uGYv083i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_IPWBuSJ6, 0, m, &cDelay_IPWBuSJ6_sendMessage);
}

void Heavy_CircleStrings::cBinop_FkKi0EEm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_IPWBuSJ6, 2, m, &cDelay_IPWBuSJ6_sendMessage);
}

void Heavy_CircleStrings::cBinop_A7dU69Nr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_FkKi0EEm_sendMessage);
}

void Heavy_CircleStrings::cCast_xH1AZWuE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_II7cyevt, 0, m, &cVar_II7cyevt_sendMessage);
  cMsg_7AoNzPug_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_7eYUWruq, 0, m, &cTabhead_7eYUWruq_sendMessage);
}

void Heavy_CircleStrings::cBinop_mv8QcIK7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KJ2QCYiT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_s3eDNHZL_sendMessage);
}

void Heavy_CircleStrings::cBinop_RBeHCgJz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_2QrFbbTI_sendMessage);
}

void Heavy_CircleStrings::cBinop_2QrFbbTI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pBHdTb54, HV_BINOP_POW, 1, m, &cBinop_pBHdTb54_sendMessage);
  cMsg_dRpL9CGt_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_pBHdTb54_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_mv8QcIK7_sendMessage);
}

void Heavy_CircleStrings::cMsg_dRpL9CGt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_pBHdTb54, HV_BINOP_POW, 0, m, &cBinop_pBHdTb54_sendMessage);
}

void Heavy_CircleStrings::cVar_lBwSWIfq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_RBeHCgJz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ME0y4r1H_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TknxiABO_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_0Rq5QqqL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_9iWJYrOC_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_9iWJYrOC_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_hSLMjdWx, 1, m, &cDelay_hSLMjdWx_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_B3G7A8gF_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_hSLMjdWx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hSLMjdWx, m);
  cMsg_olCiIjfT_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_9iWJYrOC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_hSLMjdWx, 0, m, &cDelay_hSLMjdWx_sendMessage);
}

void Heavy_CircleStrings::cCast_B3G7A8gF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_hSLMjdWx, 0, m, &cDelay_hSLMjdWx_sendMessage);
}

void Heavy_CircleStrings::cVar_Oju8PReC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_amK5yKTL, HV_BINOP_MULTIPLY, 0, m, &cBinop_amK5yKTL_sendMessage);
}

void Heavy_CircleStrings::cMsg_frSDY1YG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8Mf9R7Ql_sendMessage);
}

void Heavy_CircleStrings::cSystem_8Mf9R7Ql_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_copHFlaJ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_amK5yKTL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_dnNLoIvg_sendMessage);
}

void Heavy_CircleStrings::cBinop_Y1X7sxyD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_amK5yKTL, HV_BINOP_MULTIPLY, 1, m, &cBinop_amK5yKTL_sendMessage);
}

void Heavy_CircleStrings::cMsg_copHFlaJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Y1X7sxyD_sendMessage);
}

void Heavy_CircleStrings::cBinop_dnNLoIvg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_aNKrD4Ev_sendMessage);
}

void Heavy_CircleStrings::cBinop_aNKrD4Ev_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_6u8RBJLm_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_wHh4zhxt, m);
}

void Heavy_CircleStrings::cBinop_6u8RBJLm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_XlX97RdE, m);
}

void Heavy_CircleStrings::cMsg_NYc7BM7g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NHUnXbmt_sendMessage);
}

void Heavy_CircleStrings::cSystem_NHUnXbmt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_zdOcmhZV_sendMessage);
}

void Heavy_CircleStrings::cDelay_XrnrD8IM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XrnrD8IM, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EBQWLloJ, 0, m, &cDelay_EBQWLloJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XrnrD8IM, 0, m, &cDelay_XrnrD8IM_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_xCDJfxaQ, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_EBQWLloJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_EBQWLloJ, m);
  cMsg_x4kzsMt2_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_otjYLygr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_O0GhnjRz_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_d7M3fQOm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wK4rzIFW_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_T2Zb4m8z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VQNASG6v_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XrnrD8IM, 2, m, &cDelay_XrnrD8IM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YIKYctG3_sendMessage);
}

void Heavy_CircleStrings::cMsg_wK4rzIFW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_T2Zb4m8z, 0, m, &hTable_T2Zb4m8z_sendMessage);
}

void Heavy_CircleStrings::cBinop_zdOcmhZV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_d7M3fQOm_sendMessage);
}

void Heavy_CircleStrings::cMsg_x4kzsMt2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_T2Zb4m8z, 0, m, &hTable_T2Zb4m8z_sendMessage);
}

void Heavy_CircleStrings::cCast_YIKYctG3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XrnrD8IM, 0, m, &cDelay_XrnrD8IM_sendMessage);
}

void Heavy_CircleStrings::cMsg_VQNASG6v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_EBQWLloJ, 2, m, &cDelay_EBQWLloJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_O0GhnjRz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_xCDJfxaQ, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_wI7oIuUo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_91isat8C, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_olCiIjfT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_91isat8C, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_TknxiABO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wI7oIuUo_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_ME0y4r1H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_0Rq5QqqL_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_bPnsqSeF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_RBeHCgJz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ME0y4r1H_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TknxiABO_sendMessage);
}

void Heavy_CircleStrings::cBinop_nwpOHDmM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m786xWiG, HV_BINOP_MULTIPLY, 1, m, &cBinop_m786xWiG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xH1AZWuE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hSLMjdWx, 1, m, &cDelay_hSLMjdWx_sendMessage);
}

void Heavy_CircleStrings::cMsg_uoue6MpK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nwpOHDmM, HV_BINOP_DIVIDE, 0, m, &cBinop_nwpOHDmM_sendMessage);
}

void Heavy_CircleStrings::cCast_s3eDNHZL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uoue6MpK_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_KJ2QCYiT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nwpOHDmM, HV_BINOP_DIVIDE, 1, m, &cBinop_nwpOHDmM_sendMessage);
}

void Heavy_CircleStrings::cUnop_R7Feayg3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_PHVE7EB9, 0, m, &cPack_PHVE7EB9_sendMessage);
}

void Heavy_CircleStrings::cUnop_OMvckuzQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_W2RjhcLT, 0, m, &cPack_W2RjhcLT_sendMessage);
}

void Heavy_CircleStrings::cPack_W2RjhcLT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_ZjyvyVY3, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_PHVE7EB9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_VHBfW4AP, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_T7WbayDY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_R7Feayg3_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_OMvckuzQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_R2aHnIlg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_T7WbayDY_sendMessage);
}

void Heavy_CircleStrings::cSlice_jpXYpQpM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_P6lIcxIx_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_Y8v0pQKb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hmnfZXUi_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_1JSkVvl3_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_RBeHCgJz_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ME0y4r1H_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TknxiABO_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_nz0wrPek_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_VxqcHQur_sendMessage);
}

void Heavy_CircleStrings::cBinop_VxqcHQur_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_T7WbayDY_sendMessage);
}

void Heavy_CircleStrings::cBinop_P6lIcxIx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_pX4J7wPU_sendMessage(_c, 0, m);
  cSend_vnOyKMKU_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_YFRGxe7u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0qlI1S2N_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UJar9rIt_sendMessage);
}

void Heavy_CircleStrings::cBinop_oDrZdPSj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_MSzuVjTD_sendMessage);
}

void Heavy_CircleStrings::cBinop_MSzuVjTD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YFRGxe7u, HV_BINOP_MULTIPLY, 1, m, &cBinop_YFRGxe7u_sendMessage);
}

void Heavy_CircleStrings::cSend_pX4J7wPU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_OWiIP9Hi_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_UJar9rIt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_O8bXxTxt_sendMessage);
}

void Heavy_CircleStrings::cCast_0qlI1S2N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Ul1DaEER_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_noWyaKn2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_rAFydJof, 0, m, &cPack_rAFydJof_sendMessage);
}

void Heavy_CircleStrings::cSend_vnOyKMKU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_OJW32dt5_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_T00QFRbX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_btfxZSV9_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_zLtnekYy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_T00QFRbX_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_Umkk2CVP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.999f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_pfaoN5RQ, m);
}

void Heavy_CircleStrings::cCast_hmnfZXUi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_yDSgqJfe_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_ODWpAQfD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GzkBqtkZ_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_EFrnylsV_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Pqnas3sc_sendMessage);
}

void Heavy_CircleStrings::cIf_K4Bnx4VS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_tTd0QNTw_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_wUmuJITN_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_pRpfAEDF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_N9KyPOTQ, HV_BINOP_POW, 0, m, &cBinop_N9KyPOTQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_N9KyPOTQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_W5YII2ZU, 0, m, &cPack_W5YII2ZU_sendMessage);
}

void Heavy_CircleStrings::cBinop_ywCXrDc8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_WAMIb3OC_sendMessage);
}

void Heavy_CircleStrings::cCast_Pqnas3sc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_K4Bnx4VS, 0, m, &cIf_K4Bnx4VS_sendMessage);
}

void Heavy_CircleStrings::cCast_EFrnylsV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_gBv6Ntrq_sendMessage);
}

void Heavy_CircleStrings::cBinop_gBv6Ntrq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_K4Bnx4VS, 1, m, &cIf_K4Bnx4VS_sendMessage);
}

void Heavy_CircleStrings::cBinop_wUmuJITN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_ywCXrDc8_sendMessage);
}

void Heavy_CircleStrings::cMsg_tTd0QNTw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_W5YII2ZU, 0, m, &cPack_W5YII2ZU_sendMessage);
}

void Heavy_CircleStrings::cBinop_WAMIb3OC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_N9KyPOTQ, HV_BINOP_POW, 1, m, &cBinop_N9KyPOTQ_sendMessage);
  cMsg_pRpfAEDF_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_W5YII2ZU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_zYCBhSzM, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_ewn0qCkA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_DosN14gB_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_GzkBqtkZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_HY8Jys80_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_HY8Jys80_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_hs1AYf2L_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_DosN14gB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_NBVaHytN_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_zdgJDFxf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6ab1TwtI_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ETXSpJXb_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qcum7bsb_sendMessage);
}

void Heavy_CircleStrings::cIf_3HLhqs9Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_dldDXVJE_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_4XCrM0Gh_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_h2Kc46GM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_myxobhs3, HV_BINOP_POW, 0, m, &cBinop_myxobhs3_sendMessage);
}

void Heavy_CircleStrings::cBinop_myxobhs3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_R5aCcF9I, 0, m, &cPack_R5aCcF9I_sendMessage);
}

void Heavy_CircleStrings::cBinop_y7LTlpu2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_1eIW2XDQ_sendMessage);
}

void Heavy_CircleStrings::cCast_ETXSpJXb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_tKr4FHO9_sendMessage);
}

void Heavy_CircleStrings::cCast_qcum7bsb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_3HLhqs9Q, 0, m, &cIf_3HLhqs9Q_sendMessage);
}

void Heavy_CircleStrings::cBinop_tKr4FHO9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_3HLhqs9Q, 1, m, &cIf_3HLhqs9Q_sendMessage);
}

void Heavy_CircleStrings::cBinop_4XCrM0Gh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_y7LTlpu2_sendMessage);
}

void Heavy_CircleStrings::cMsg_dldDXVJE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_R5aCcF9I, 0, m, &cPack_R5aCcF9I_sendMessage);
}

void Heavy_CircleStrings::cBinop_1eIW2XDQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_myxobhs3, HV_BINOP_POW, 1, m, &cBinop_myxobhs3_sendMessage);
  cMsg_h2Kc46GM_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_R5aCcF9I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_0wjPaWHA, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_in4G2pe5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_C4D3KGMk_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_6ab1TwtI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_JY90Z4NW_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_JY90Z4NW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_cltzsQBc_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_C4D3KGMk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_5Ye6ENuY_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_JHRrbbsv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_V7u2YPWs, 0, m, &cSlice_V7u2YPWs_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_07VtCaq3, 0, m, &cRandom_07VtCaq3_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_iazFxD4l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_LMRRizh5_sendMessage);
}

void Heavy_CircleStrings::cUnop_LMRRizh5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_XF34n8Gq_sendMessage);
}

void Heavy_CircleStrings::cRandom_07VtCaq3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_iazFxD4l_sendMessage);
}

void Heavy_CircleStrings::cSlice_V7u2YPWs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_07VtCaq3, 1, m, &cRandom_07VtCaq3_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_oEKHvjlB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9E6IQM4A, HV_BINOP_MULTIPLY, 0, m, &cBinop_9E6IQM4A_sendMessage);
}

void Heavy_CircleStrings::cBinop_GDD3jAH0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_mlwW2hen_sendMessage);
}

void Heavy_CircleStrings::cBinop_mlwW2hen_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cvsvzwn4, HV_BINOP_POW, 1, m, &cBinop_cvsvzwn4_sendMessage);
  cMsg_Dr1LG1Vm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_cvsvzwn4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_oEKHvjlB_sendMessage);
}

void Heavy_CircleStrings::cMsg_Dr1LG1Vm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_cvsvzwn4, HV_BINOP_POW, 0, m, &cBinop_cvsvzwn4_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_YrJYKAV7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_in8BqYCr, 0, m, &cSlice_in8BqYCr_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_pmYgav4t, 0, m, &cRandom_pmYgav4t_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_V2pHzxjt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_nuBkatQQ_sendMessage);
}

void Heavy_CircleStrings::cUnop_nuBkatQQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_NAYes2ig_sendMessage);
}

void Heavy_CircleStrings::cRandom_pmYgav4t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_V2pHzxjt_sendMessage);
}

void Heavy_CircleStrings::cSlice_in8BqYCr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_pmYgav4t, 1, m, &cRandom_pmYgav4t_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cPack_llm7U96a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_WxJtWyuZ, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_3w2bTWXV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_av2dCNko_sendMessage);
}

void Heavy_CircleStrings::cVar_OKREmgC7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_VjKLOCtv, 0, m);
}

void Heavy_CircleStrings::cVar_zXVelbzx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PbsKvMPN_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wCQT3g0T_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UBATzfwk_sendMessage);
}

void Heavy_CircleStrings::cVar_7hD2Nprw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_IlmsQzp2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_oOUXJBpu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSwitchcase_lr6Ggupx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_I2vRkAoS_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_I2vRkAoS_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_NE6ngpFU, 1, m, &cDelay_NE6ngpFU_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mEK2Nr3A_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_NE6ngpFU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NE6ngpFU, m);
  cVar_onMessage(_c, &Context(_c)->cVar_kqsjeCjo, 0, m, &cVar_kqsjeCjo_sendMessage);
}

void Heavy_CircleStrings::cMsg_I2vRkAoS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_NE6ngpFU, 0, m, &cDelay_NE6ngpFU_sendMessage);
}

void Heavy_CircleStrings::cCast_mEK2Nr3A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_NE6ngpFU, 0, m, &cDelay_NE6ngpFU_sendMessage);
}

void Heavy_CircleStrings::cVar_kqsjeCjo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2BS4RBM1_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_XmCZApxg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zXVelbzx, 0, m, &cVar_zXVelbzx_sendMessage);
}

void Heavy_CircleStrings::cMsg_fIh4s1kf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_zjhxsp6B_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_GxUW5Mga_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_q44yaKWr_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_xrpMSHKE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_oKaxzY92_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_RGfkI5YB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_T1mZNjrD_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_EPr7Ug5k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_inqYLsdu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_fOW6BxY7_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_zjhxsp6B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_q44yaKWr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_T1mZNjrD_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_oKaxzY92_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_fOW6BxY7_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_O2BowCQ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_VS2mA4YT, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_2BS4RBM1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_VS2mA4YT, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_UBATzfwk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_lr6Ggupx_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_wCQT3g0T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kqsjeCjo, 1, m, &cVar_kqsjeCjo_sendMessage);
}

void Heavy_CircleStrings::cCast_PbsKvMPN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_O2BowCQ5_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_jmgMcw2z_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_1rKxr3Sm, 0, m, &cSlice_1rKxr3Sm_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_L2HOtwQ0, 0, m, &cRandom_L2HOtwQ0_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_2VVCrtmq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_GQyppsd8_sendMessage);
}

void Heavy_CircleStrings::cUnop_GQyppsd8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ahE5IHJf_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_L2HOtwQ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_2VVCrtmq_sendMessage);
}

void Heavy_CircleStrings::cSlice_1rKxr3Sm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_L2HOtwQ0, 1, m, &cRandom_L2HOtwQ0_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_ahE5IHJf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_oTtvC7BD, m);
}

void Heavy_CircleStrings::cTabhead_I137dHsl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rJQipifR, HV_BINOP_SUBTRACT, 0, m, &cBinop_rJQipifR_sendMessage);
}

void Heavy_CircleStrings::cMsg_IwnzB0ae_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FM4XFyCf_sendMessage);
}

void Heavy_CircleStrings::cSystem_FM4XFyCf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_TD54rcCX_sendMessage);
}

void Heavy_CircleStrings::cVar_N6CoGYI1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WdtAEm8Z_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_z7RWhAmp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_z7RWhAmp, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FfCucnpg, 0, m, &cDelay_FfCucnpg_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Kjfh628Y, 0, m, &sTabread_Kjfh628Y_sendMessage);
}

void Heavy_CircleStrings::cDelay_FfCucnpg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FfCucnpg, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Kjfh628Y, 0, m, &sTabread_Kjfh628Y_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FfCucnpg, 0, m, &cDelay_FfCucnpg_sendMessage);
}

void Heavy_CircleStrings::sTabread_Kjfh628Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_SRD0GaJB, HV_BINOP_SUBTRACT, 0, m, &cBinop_SRD0GaJB_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_aWrI7E4n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ze4Tv9GZ, HV_BINOP_MAX, 0, m, &cBinop_Ze4Tv9GZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_TD54rcCX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aWrI7E4n, HV_BINOP_MULTIPLY, 0, m, &cBinop_aWrI7E4n_sendMessage);
}

void Heavy_CircleStrings::cBinop_rJQipifR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_axABepYM_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Kjfh628Y, 0, m, &sTabread_Kjfh628Y_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gzMHZnPL_sendMessage);
}

void Heavy_CircleStrings::cSystem_NiagcaxK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SRD0GaJB, HV_BINOP_SUBTRACT, 1, m, &cBinop_SRD0GaJB_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FfCucnpg, 2, m, &cDelay_FfCucnpg_sendMessage);
}

void Heavy_CircleStrings::cMsg_WdtAEm8Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NiagcaxK_sendMessage);
}

void Heavy_CircleStrings::cMsg_axABepYM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_z7RWhAmp, 0, m, &cDelay_z7RWhAmp_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FfCucnpg, 0, m, &cDelay_FfCucnpg_sendMessage);
}

void Heavy_CircleStrings::cMsg_hxuzSydj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ze4Tv9GZ, HV_BINOP_MAX, 1, m, &cBinop_Ze4Tv9GZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_Ze4Tv9GZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rJQipifR, HV_BINOP_SUBTRACT, 1, m, &cBinop_rJQipifR_sendMessage);
}

void Heavy_CircleStrings::cCast_gzMHZnPL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_z7RWhAmp, 0, m, &cDelay_z7RWhAmp_sendMessage);
}

void Heavy_CircleStrings::cBinop_qBQgB4Pv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_z7RWhAmp, 2, m, &cDelay_z7RWhAmp_sendMessage);
}

void Heavy_CircleStrings::cBinop_SRD0GaJB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_qBQgB4Pv_sendMessage);
}

void Heavy_CircleStrings::cCast_tGvInCuB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_N6CoGYI1, 0, m, &cVar_N6CoGYI1_sendMessage);
  cMsg_IwnzB0ae_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_I137dHsl, 0, m, &cTabhead_I137dHsl_sendMessage);
}

void Heavy_CircleStrings::cBinop_TxzheIsL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jr1PcxIf_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rSCk2sIu_sendMessage);
}

void Heavy_CircleStrings::cBinop_Lmwrfozg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_9vs5e1sN_sendMessage);
}

void Heavy_CircleStrings::cBinop_9vs5e1sN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6jX1gpLm, HV_BINOP_POW, 1, m, &cBinop_6jX1gpLm_sendMessage);
  cMsg_gCmi2kYF_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_6jX1gpLm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_TxzheIsL_sendMessage);
}

void Heavy_CircleStrings::cMsg_gCmi2kYF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6jX1gpLm, HV_BINOP_POW, 0, m, &cBinop_6jX1gpLm_sendMessage);
}

void Heavy_CircleStrings::cVar_suWQMfCn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_Lmwrfozg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_m9O4HTEd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ArSVoBEL_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_ANS4oN9g_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_ENLPkMmR_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_ENLPkMmR_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_qtv0ayRD, 1, m, &cDelay_qtv0ayRD_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bWvzUdXI_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_qtv0ayRD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_qtv0ayRD, m);
  cMsg_YfLIFCgT_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_ENLPkMmR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_qtv0ayRD, 0, m, &cDelay_qtv0ayRD_sendMessage);
}

void Heavy_CircleStrings::cCast_bWvzUdXI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_qtv0ayRD, 0, m, &cDelay_qtv0ayRD_sendMessage);
}

void Heavy_CircleStrings::cVar_6WcN0BUW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Tr6oQXfl, HV_BINOP_MULTIPLY, 0, m, &cBinop_Tr6oQXfl_sendMessage);
}

void Heavy_CircleStrings::cMsg_zB1Ku52Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_I2mPV8OT_sendMessage);
}

void Heavy_CircleStrings::cSystem_I2mPV8OT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WPs0eS24_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_Tr6oQXfl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_2skhX8Mu_sendMessage);
}

void Heavy_CircleStrings::cBinop_QrmpWx5t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Tr6oQXfl, HV_BINOP_MULTIPLY, 1, m, &cBinop_Tr6oQXfl_sendMessage);
}

void Heavy_CircleStrings::cMsg_WPs0eS24_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_QrmpWx5t_sendMessage);
}

void Heavy_CircleStrings::cBinop_2skhX8Mu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_HVYZ4dcd_sendMessage);
}

void Heavy_CircleStrings::cBinop_HVYZ4dcd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_X3ozgDcg_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_8RUx8Bd6, m);
}

void Heavy_CircleStrings::cBinop_X3ozgDcg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_lSbAOmrg, m);
}

void Heavy_CircleStrings::cMsg_WBvw5uWu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JfM0cpH8_sendMessage);
}

void Heavy_CircleStrings::cSystem_JfM0cpH8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_mQVJLYqv_sendMessage);
}

void Heavy_CircleStrings::cDelay_4xogpkp6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4xogpkp6, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ShhUzkAO, 0, m, &cDelay_ShhUzkAO_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4xogpkp6, 0, m, &cDelay_4xogpkp6_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_2V2BIoAi, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_ShhUzkAO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ShhUzkAO, m);
  cMsg_QrShpMcY_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_qCnzDOGn_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_zBlTzMVt_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_FMb65kh7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_n2trJ5Od_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_NOntZksZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QU1fCwhM_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4xogpkp6, 2, m, &cDelay_4xogpkp6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7XXJgUhG_sendMessage);
}

void Heavy_CircleStrings::cMsg_n2trJ5Od_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_NOntZksZ, 0, m, &hTable_NOntZksZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_mQVJLYqv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_FMb65kh7_sendMessage);
}

void Heavy_CircleStrings::cMsg_QrShpMcY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_NOntZksZ, 0, m, &hTable_NOntZksZ_sendMessage);
}

void Heavy_CircleStrings::cCast_7XXJgUhG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_4xogpkp6, 0, m, &cDelay_4xogpkp6_sendMessage);
}

void Heavy_CircleStrings::cMsg_QU1fCwhM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_ShhUzkAO, 2, m, &cDelay_ShhUzkAO_sendMessage);
}

void Heavy_CircleStrings::cMsg_zBlTzMVt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_2V2BIoAi, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_bPHFsBX0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_mkFuhsgQ, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_YfLIFCgT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_mkFuhsgQ, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_ArSVoBEL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bPHFsBX0_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_m9O4HTEd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ANS4oN9g_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_AP7osfko_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_Lmwrfozg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_m9O4HTEd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ArSVoBEL_sendMessage);
}

void Heavy_CircleStrings::cBinop_AV80OxCF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aWrI7E4n, HV_BINOP_MULTIPLY, 1, m, &cBinop_aWrI7E4n_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tGvInCuB_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_qtv0ayRD, 1, m, &cDelay_qtv0ayRD_sendMessage);
}

void Heavy_CircleStrings::cMsg_pN3RI6Zu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_AV80OxCF, HV_BINOP_DIVIDE, 0, m, &cBinop_AV80OxCF_sendMessage);
}

void Heavy_CircleStrings::cCast_rSCk2sIu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pN3RI6Zu_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_jr1PcxIf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AV80OxCF, HV_BINOP_DIVIDE, 1, m, &cBinop_AV80OxCF_sendMessage);
}

void Heavy_CircleStrings::cUnop_t3GAoHS7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_3862M1I1, 0, m, &cPack_3862M1I1_sendMessage);
}

void Heavy_CircleStrings::cUnop_FJDdu4Ck_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_oziuCjUo, 0, m, &cPack_oziuCjUo_sendMessage);
}

void Heavy_CircleStrings::cPack_oziuCjUo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_R1nVLPdz, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_3862M1I1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_fdPKu1sh, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_27RRgkMm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_t3GAoHS7_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_FJDdu4Ck_sendMessage);
}

void Heavy_CircleStrings::cMsg_6oUHHGBR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_27RRgkMm_sendMessage);
}

void Heavy_CircleStrings::cSlice_0bG2aPGk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_To2AJFog_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_CSWs3v21_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UQg5v5RH_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_GDD3jAH0_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_Lmwrfozg_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_m9O4HTEd_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ArSVoBEL_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_XF34n8Gq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_R8vLVpgw_sendMessage);
}

void Heavy_CircleStrings::cBinop_R8vLVpgw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_27RRgkMm_sendMessage);
}

void Heavy_CircleStrings::cBinop_To2AJFog_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_kIiRblnh_sendMessage(_c, 0, m);
  cSend_MHFITerp_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_9E6IQM4A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tQx2F2MM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4BbNFCyv_sendMessage);
}

void Heavy_CircleStrings::cBinop_NAYes2ig_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_oExcC6Ra_sendMessage);
}

void Heavy_CircleStrings::cBinop_oExcC6Ra_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9E6IQM4A, HV_BINOP_MULTIPLY, 1, m, &cBinop_9E6IQM4A_sendMessage);
}

void Heavy_CircleStrings::cSend_kIiRblnh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_fSA64V8b_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_4BbNFCyv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XmCZApxg_sendMessage);
}

void Heavy_CircleStrings::cCast_tQx2F2MM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_JHRrbbsv_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_av2dCNko_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_llm7U96a, 0, m, &cPack_llm7U96a_sendMessage);
}

void Heavy_CircleStrings::cSend_MHFITerp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_rZHYtPol_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_o281Llpu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RdjUOu7F_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_TuEgV2g8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_o281Llpu_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_nhBR4nr5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.999f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_gZTQ3djx, m);
}

void Heavy_CircleStrings::cCast_UQg5v5RH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_YrJYKAV7_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_g5KLQoQW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_p3VH5C0t, 0, m, &cSlice_p3VH5C0t_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_g956zFn6, 0, m, &cRandom_g956zFn6_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_n3MZa5TT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Iz7NyJTZ_sendMessage);
}

void Heavy_CircleStrings::cUnop_Iz7NyJTZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_nF8WBi2t_sendMessage);
}

void Heavy_CircleStrings::cRandom_g956zFn6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_n3MZa5TT_sendMessage);
}

void Heavy_CircleStrings::cSlice_p3VH5C0t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_g956zFn6, 1, m, &cRandom_g956zFn6_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_ubNSYutA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Idpn54iP, HV_BINOP_MULTIPLY, 0, m, &cBinop_Idpn54iP_sendMessage);
}

void Heavy_CircleStrings::cBinop_MExHNM9f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_wfjhQomV_sendMessage);
}

void Heavy_CircleStrings::cBinop_wfjhQomV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MCtrup7a, HV_BINOP_POW, 1, m, &cBinop_MCtrup7a_sendMessage);
  cMsg_QmKoaD9u_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_MCtrup7a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_ubNSYutA_sendMessage);
}

void Heavy_CircleStrings::cMsg_QmKoaD9u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_MCtrup7a, HV_BINOP_POW, 0, m, &cBinop_MCtrup7a_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_au1mNxOn_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_SdsXYBVJ, 0, m, &cSlice_SdsXYBVJ_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_7LN4f0lw, 0, m, &cRandom_7LN4f0lw_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_xZdurNMS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_4IU1ldS7_sendMessage);
}

void Heavy_CircleStrings::cUnop_4IU1ldS7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_eCW7Kq8k_sendMessage);
}

void Heavy_CircleStrings::cRandom_7LN4f0lw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_xZdurNMS_sendMessage);
}

void Heavy_CircleStrings::cSlice_SdsXYBVJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_7LN4f0lw, 1, m, &cRandom_7LN4f0lw_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cPack_ZDrTJJON_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_4dIOp7T2, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_K7GyhhvU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_7mb1LC3Y_sendMessage);
}

void Heavy_CircleStrings::cVar_7GpGI3TD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_UlKuPlOy, 0, m);
}

void Heavy_CircleStrings::cVar_8lWsQlfe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Lgtrozjl_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mNAOZoCK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TbWCsmoK_sendMessage);
}

void Heavy_CircleStrings::cVar_nSz4l5UX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_4wJQh9gk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_ziHKfjQL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSwitchcase_tgb3bFVs_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_cmcXLQb5_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_cmcXLQb5_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_ClzSHiyY, 1, m, &cDelay_ClzSHiyY_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eu9HWzSY_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_ClzSHiyY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ClzSHiyY, m);
  cVar_onMessage(_c, &Context(_c)->cVar_1krK8gnS, 0, m, &cVar_1krK8gnS_sendMessage);
}

void Heavy_CircleStrings::cMsg_cmcXLQb5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ClzSHiyY, 0, m, &cDelay_ClzSHiyY_sendMessage);
}

void Heavy_CircleStrings::cCast_eu9HWzSY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ClzSHiyY, 0, m, &cDelay_ClzSHiyY_sendMessage);
}

void Heavy_CircleStrings::cVar_1krK8gnS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SYcY9WnL_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_Z5EedAmN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8lWsQlfe, 0, m, &cVar_8lWsQlfe_sendMessage);
}

void Heavy_CircleStrings::cMsg_L9DYZv3j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_93dWVJkH_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_uAxxuoBy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_rB1mOVOL_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_inp4SkBG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_7UTJ2Rqw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_w2jzcmMO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_zThL6YIP_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_dO1SLrLv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_9TfDJhSx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_DoSJnQeD_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_93dWVJkH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_rB1mOVOL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_zThL6YIP_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_7UTJ2Rqw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_DoSJnQeD_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_6Dw2hqqY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_WyjyMzUx, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_SYcY9WnL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_WyjyMzUx, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_mNAOZoCK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1krK8gnS, 1, m, &cVar_1krK8gnS_sendMessage);
}

void Heavy_CircleStrings::cCast_Lgtrozjl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6Dw2hqqY_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_TbWCsmoK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_tgb3bFVs_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_AJsjC4QN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_DSk7p9zC, 0, m, &cSlice_DSk7p9zC_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_msLWPt09, 0, m, &cRandom_msLWPt09_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_k7L2ZXUR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_5teBZiWz_sendMessage);
}

void Heavy_CircleStrings::cUnop_5teBZiWz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3PtPN3jX_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_msLWPt09_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_k7L2ZXUR_sendMessage);
}

void Heavy_CircleStrings::cSlice_DSk7p9zC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_msLWPt09, 1, m, &cRandom_msLWPt09_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_3PtPN3jX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_ikRTBjKN, m);
}

void Heavy_CircleStrings::cTabhead_GcuaQrBT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7L2UOFbV, HV_BINOP_SUBTRACT, 0, m, &cBinop_7L2UOFbV_sendMessage);
}

void Heavy_CircleStrings::cMsg_zRGEIr8Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WNRm0X1F_sendMessage);
}

void Heavy_CircleStrings::cSystem_WNRm0X1F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_mRniPhL5_sendMessage);
}

void Heavy_CircleStrings::cVar_jCbrhYXm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rzdAsGOA_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_TokOZSCs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TokOZSCs, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ojGWhouB, 0, m, &cDelay_ojGWhouB_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qQIVIWrm, 0, m, &sTabread_qQIVIWrm_sendMessage);
}

void Heavy_CircleStrings::cDelay_ojGWhouB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ojGWhouB, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qQIVIWrm, 0, m, &sTabread_qQIVIWrm_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ojGWhouB, 0, m, &cDelay_ojGWhouB_sendMessage);
}

void Heavy_CircleStrings::sTabread_qQIVIWrm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_l00ltTti, HV_BINOP_SUBTRACT, 0, m, &cBinop_l00ltTti_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_SfK4qf50_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ArMLrnfB, HV_BINOP_MAX, 0, m, &cBinop_ArMLrnfB_sendMessage);
}

void Heavy_CircleStrings::cBinop_mRniPhL5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SfK4qf50, HV_BINOP_MULTIPLY, 0, m, &cBinop_SfK4qf50_sendMessage);
}

void Heavy_CircleStrings::cBinop_7L2UOFbV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qdqIwcnJ_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qQIVIWrm, 0, m, &sTabread_qQIVIWrm_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fTdALZJM_sendMessage);
}

void Heavy_CircleStrings::cSystem_yf4IIS0Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l00ltTti, HV_BINOP_SUBTRACT, 1, m, &cBinop_l00ltTti_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ojGWhouB, 2, m, &cDelay_ojGWhouB_sendMessage);
}

void Heavy_CircleStrings::cMsg_rzdAsGOA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yf4IIS0Q_sendMessage);
}

void Heavy_CircleStrings::cMsg_qdqIwcnJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_TokOZSCs, 0, m, &cDelay_TokOZSCs_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ojGWhouB, 0, m, &cDelay_ojGWhouB_sendMessage);
}

void Heavy_CircleStrings::cMsg_NYpZa9AJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_ArMLrnfB, HV_BINOP_MAX, 1, m, &cBinop_ArMLrnfB_sendMessage);
}

void Heavy_CircleStrings::cBinop_ArMLrnfB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7L2UOFbV, HV_BINOP_SUBTRACT, 1, m, &cBinop_7L2UOFbV_sendMessage);
}

void Heavy_CircleStrings::cCast_fTdALZJM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TokOZSCs, 0, m, &cDelay_TokOZSCs_sendMessage);
}

void Heavy_CircleStrings::cBinop_PkDCDWmY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TokOZSCs, 2, m, &cDelay_TokOZSCs_sendMessage);
}

void Heavy_CircleStrings::cBinop_l00ltTti_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_PkDCDWmY_sendMessage);
}

void Heavy_CircleStrings::cCast_2aIUIheZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jCbrhYXm, 0, m, &cVar_jCbrhYXm_sendMessage);
  cMsg_zRGEIr8Y_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_GcuaQrBT, 0, m, &cTabhead_GcuaQrBT_sendMessage);
}

void Heavy_CircleStrings::cBinop_pmM6it02_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0K6gQVvW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GXzNn6D7_sendMessage);
}

void Heavy_CircleStrings::cBinop_tTc1OZuQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_rIV332nF_sendMessage);
}

void Heavy_CircleStrings::cBinop_rIV332nF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Eb1EEh6k, HV_BINOP_POW, 1, m, &cBinop_Eb1EEh6k_sendMessage);
  cMsg_7sOpXqyw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_Eb1EEh6k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_pmM6it02_sendMessage);
}

void Heavy_CircleStrings::cMsg_7sOpXqyw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Eb1EEh6k, HV_BINOP_POW, 0, m, &cBinop_Eb1EEh6k_sendMessage);
}

void Heavy_CircleStrings::cVar_35LvyqsK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_tTc1OZuQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dfSi7jK1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Qk4GDwHj_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_gbfBMgLE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_h1C1bPOc_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_h1C1bPOc_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_8v03FZwg, 1, m, &cDelay_8v03FZwg_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bSewHvpz_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_8v03FZwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8v03FZwg, m);
  cMsg_9Ql73AcT_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_h1C1bPOc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_8v03FZwg, 0, m, &cDelay_8v03FZwg_sendMessage);
}

void Heavy_CircleStrings::cCast_bSewHvpz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8v03FZwg, 0, m, &cDelay_8v03FZwg_sendMessage);
}

void Heavy_CircleStrings::cVar_bT3aOXEE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_S6e0qOhR, HV_BINOP_MULTIPLY, 0, m, &cBinop_S6e0qOhR_sendMessage);
}

void Heavy_CircleStrings::cMsg_HfwAW5m1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nAt4dvFm_sendMessage);
}

void Heavy_CircleStrings::cSystem_nAt4dvFm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JPXg5mOC_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_S6e0qOhR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_PcR2zqTw_sendMessage);
}

void Heavy_CircleStrings::cBinop_HN5nx0sk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_S6e0qOhR, HV_BINOP_MULTIPLY, 1, m, &cBinop_S6e0qOhR_sendMessage);
}

void Heavy_CircleStrings::cMsg_JPXg5mOC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_HN5nx0sk_sendMessage);
}

void Heavy_CircleStrings::cBinop_PcR2zqTw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_pVYkHcX0_sendMessage);
}

void Heavy_CircleStrings::cBinop_pVYkHcX0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_dGXQNKxQ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ncsts9O1, m);
}

void Heavy_CircleStrings::cBinop_dGXQNKxQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LpPyEMvp, m);
}

void Heavy_CircleStrings::cMsg_VtIFulVs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_sMKBr6m7_sendMessage);
}

void Heavy_CircleStrings::cSystem_sMKBr6m7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_0LDSlogw_sendMessage);
}

void Heavy_CircleStrings::cDelay_sXBiFYUH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sXBiFYUH, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_aMIcwry5, 0, m, &cDelay_aMIcwry5_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sXBiFYUH, 0, m, &cDelay_sXBiFYUH_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_T5eZQDmB, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_aMIcwry5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_aMIcwry5, m);
  cMsg_D1fa9IBT_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_1zm8tmLB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_LJZgxZAU_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_uFZirymt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PWNG3Bec_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_U4YYujfG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rwKw7GOq_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sXBiFYUH, 2, m, &cDelay_sXBiFYUH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_08KmE65n_sendMessage);
}

void Heavy_CircleStrings::cMsg_PWNG3Bec_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_U4YYujfG, 0, m, &hTable_U4YYujfG_sendMessage);
}

void Heavy_CircleStrings::cBinop_0LDSlogw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_uFZirymt_sendMessage);
}

void Heavy_CircleStrings::cMsg_D1fa9IBT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_U4YYujfG, 0, m, &hTable_U4YYujfG_sendMessage);
}

void Heavy_CircleStrings::cCast_08KmE65n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_sXBiFYUH, 0, m, &cDelay_sXBiFYUH_sendMessage);
}

void Heavy_CircleStrings::cMsg_rwKw7GOq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_aMIcwry5, 2, m, &cDelay_aMIcwry5_sendMessage);
}

void Heavy_CircleStrings::cMsg_LJZgxZAU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_T5eZQDmB, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_CH7gEQHj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_1tzHbdLI, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_9Ql73AcT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_1tzHbdLI, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_Qk4GDwHj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CH7gEQHj_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_dfSi7jK1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_gbfBMgLE_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_k1RqFs6U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_tTc1OZuQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dfSi7jK1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Qk4GDwHj_sendMessage);
}

void Heavy_CircleStrings::cBinop_OPWDyLgX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SfK4qf50, HV_BINOP_MULTIPLY, 1, m, &cBinop_SfK4qf50_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2aIUIheZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8v03FZwg, 1, m, &cDelay_8v03FZwg_sendMessage);
}

void Heavy_CircleStrings::cMsg_6EpldEdE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_OPWDyLgX, HV_BINOP_DIVIDE, 0, m, &cBinop_OPWDyLgX_sendMessage);
}

void Heavy_CircleStrings::cCast_GXzNn6D7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6EpldEdE_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_0K6gQVvW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OPWDyLgX, HV_BINOP_DIVIDE, 1, m, &cBinop_OPWDyLgX_sendMessage);
}

void Heavy_CircleStrings::cUnop_G07UYbAb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_4QBdNQEV, 0, m, &cPack_4QBdNQEV_sendMessage);
}

void Heavy_CircleStrings::cUnop_nQmOsmMt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ysxZGKcT, 0, m, &cPack_ysxZGKcT_sendMessage);
}

void Heavy_CircleStrings::cPack_ysxZGKcT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_VxaDnpNz, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_4QBdNQEV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_qoFQk9Jd, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_Bs7wPwsT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_G07UYbAb_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_nQmOsmMt_sendMessage);
}

void Heavy_CircleStrings::cMsg_Dx5pIBG2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_Bs7wPwsT_sendMessage);
}

void Heavy_CircleStrings::cSlice_qhhqy6VU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_fsdRWUft_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_Xhdvy25o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Y6gwz7ZG_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_MExHNM9f_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_tTc1OZuQ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dfSi7jK1_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Qk4GDwHj_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_nF8WBi2t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_u2JshMnu_sendMessage);
}

void Heavy_CircleStrings::cBinop_u2JshMnu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_Bs7wPwsT_sendMessage);
}

void Heavy_CircleStrings::cBinop_fsdRWUft_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ci8DsAQs_sendMessage(_c, 0, m);
  cSend_0kyimAlB_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_Idpn54iP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zvuxB0In_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4yXuufpX_sendMessage);
}

void Heavy_CircleStrings::cBinop_eCW7Kq8k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_OTm2PSGV_sendMessage);
}

void Heavy_CircleStrings::cBinop_OTm2PSGV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Idpn54iP, HV_BINOP_MULTIPLY, 1, m, &cBinop_Idpn54iP_sendMessage);
}

void Heavy_CircleStrings::cSend_ci8DsAQs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Ct2oC0HR_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_zvuxB0In_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_g5KLQoQW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_4yXuufpX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Z5EedAmN_sendMessage);
}

void Heavy_CircleStrings::cBinop_7mb1LC3Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ZDrTJJON, 0, m, &cPack_ZDrTJJON_sendMessage);
}

void Heavy_CircleStrings::cSend_0kyimAlB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9sFEbxH3_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_HSqRyBt0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_pOYJ3K81_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_bW17opAL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_HSqRyBt0_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_6UiGxr0L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.999f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_w5PuOACo, m);
}

void Heavy_CircleStrings::cCast_Y6gwz7ZG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_au1mNxOn_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_pqQrxBQo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_OKzS54HQ, 0, m, &cSlice_OKzS54HQ_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_z4h4YX8J, 0, m, &cRandom_z4h4YX8J_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_VYcFn3ab_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_7vieRTS1_sendMessage);
}

void Heavy_CircleStrings::cUnop_7vieRTS1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_L4qTW0n4_sendMessage);
}

void Heavy_CircleStrings::cRandom_z4h4YX8J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_VYcFn3ab_sendMessage);
}

void Heavy_CircleStrings::cSlice_OKzS54HQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_z4h4YX8J, 1, m, &cRandom_z4h4YX8J_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_mQtc2lHx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UnkaATq4, HV_BINOP_MULTIPLY, 0, m, &cBinop_UnkaATq4_sendMessage);
}

void Heavy_CircleStrings::cBinop_LI22ZwjP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_SYqAflKs_sendMessage);
}

void Heavy_CircleStrings::cBinop_SYqAflKs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oPamYJDf, HV_BINOP_POW, 1, m, &cBinop_oPamYJDf_sendMessage);
  cMsg_t9j065GA_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_oPamYJDf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_mQtc2lHx_sendMessage);
}

void Heavy_CircleStrings::cMsg_t9j065GA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_oPamYJDf, HV_BINOP_POW, 0, m, &cBinop_oPamYJDf_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_a0DCiFa1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_vSnJnNyF, 0, m, &cSlice_vSnJnNyF_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_RsB8YAQH, 0, m, &cRandom_RsB8YAQH_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_nNSmMyxo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_iqBYu6Wc_sendMessage);
}

void Heavy_CircleStrings::cUnop_iqBYu6Wc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_4QoedAuh_sendMessage);
}

void Heavy_CircleStrings::cRandom_RsB8YAQH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_nNSmMyxo_sendMessage);
}

void Heavy_CircleStrings::cSlice_vSnJnNyF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_RsB8YAQH, 1, m, &cRandom_RsB8YAQH_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cPack_fLYWNz5o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_hVhjyV3v, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_omk7Cw9A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_m9BMmEVk_sendMessage);
}

void Heavy_CircleStrings::cVar_lXKU5YO0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_L14MNyBC, 0, m);
}

void Heavy_CircleStrings::cVar_X373zqMA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TFLX9A4l_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SRtAMmot_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rTNrEoqn_sendMessage);
}

void Heavy_CircleStrings::cVar_ASuXEL5J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_F16qcfDR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_o8hEl584_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSwitchcase_Q5YKt819_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_aHIYIlb5_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_aHIYIlb5_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_WOymj7zb, 1, m, &cDelay_WOymj7zb_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AxSQsXTg_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_WOymj7zb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WOymj7zb, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ewuaYIWZ, 0, m, &cVar_ewuaYIWZ_sendMessage);
}

void Heavy_CircleStrings::cMsg_aHIYIlb5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_WOymj7zb, 0, m, &cDelay_WOymj7zb_sendMessage);
}

void Heavy_CircleStrings::cCast_AxSQsXTg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_WOymj7zb, 0, m, &cDelay_WOymj7zb_sendMessage);
}

void Heavy_CircleStrings::cVar_ewuaYIWZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xUKPHt3P_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_wpTuozAk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_X373zqMA, 0, m, &cVar_X373zqMA_sendMessage);
}

void Heavy_CircleStrings::cMsg_MAQ1c9gX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_bUgK3He5_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_KIYZN7A6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_hXUZKtlN_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_cMLWgE7g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_CNsLmJAB_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_vIkah4W4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9z8rJdN4_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_oVJk8yS5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_1j588rdr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_j8IQx296_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_bUgK3He5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_hXUZKtlN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9z8rJdN4_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_CNsLmJAB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_j8IQx296_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_YV9dz51N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_DSKpEbr9, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_xUKPHt3P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_DSKpEbr9, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_rTNrEoqn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Q5YKt819_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_TFLX9A4l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YV9dz51N_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_SRtAMmot_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ewuaYIWZ, 1, m, &cVar_ewuaYIWZ_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_8F13ayPI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_JHavUH0s, 0, m, &cSlice_JHavUH0s_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_F0WSUJ3D, 0, m, &cRandom_F0WSUJ3D_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_ClVoioAK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_2J1eKCL4_sendMessage);
}

void Heavy_CircleStrings::cUnop_2J1eKCL4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rpFmv2vB_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_F0WSUJ3D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_ClVoioAK_sendMessage);
}

void Heavy_CircleStrings::cSlice_JHavUH0s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_F0WSUJ3D, 1, m, &cRandom_F0WSUJ3D_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_rpFmv2vB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_uMgsv9Dq, m);
}

void Heavy_CircleStrings::cTabhead_lpn6N5H2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tOG3lDr0, HV_BINOP_SUBTRACT, 0, m, &cBinop_tOG3lDr0_sendMessage);
}

void Heavy_CircleStrings::cMsg_JF13GsVb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nYhnYOVz_sendMessage);
}

void Heavy_CircleStrings::cSystem_nYhnYOVz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_isO1w62w_sendMessage);
}

void Heavy_CircleStrings::cVar_sheJmEXS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TAg3o3YX_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_YdHVzVrz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_YdHVzVrz, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_P0emgaxE, 0, m, &cDelay_P0emgaxE_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3bM6auom, 0, m, &sTabread_3bM6auom_sendMessage);
}

void Heavy_CircleStrings::cDelay_P0emgaxE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_P0emgaxE, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3bM6auom, 0, m, &sTabread_3bM6auom_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_P0emgaxE, 0, m, &cDelay_P0emgaxE_sendMessage);
}

void Heavy_CircleStrings::sTabread_3bM6auom_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_CXtPcSzJ, HV_BINOP_SUBTRACT, 0, m, &cBinop_CXtPcSzJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_jOdEeeMN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IyHX8KBU, HV_BINOP_MAX, 0, m, &cBinop_IyHX8KBU_sendMessage);
}

void Heavy_CircleStrings::cBinop_isO1w62w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jOdEeeMN, HV_BINOP_MULTIPLY, 0, m, &cBinop_jOdEeeMN_sendMessage);
}

void Heavy_CircleStrings::cBinop_tOG3lDr0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7AjoKdV1_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3bM6auom, 0, m, &sTabread_3bM6auom_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zdEOzVnz_sendMessage);
}

void Heavy_CircleStrings::cSystem_RzY3xfo8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CXtPcSzJ, HV_BINOP_SUBTRACT, 1, m, &cBinop_CXtPcSzJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_P0emgaxE, 2, m, &cDelay_P0emgaxE_sendMessage);
}

void Heavy_CircleStrings::cMsg_TAg3o3YX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RzY3xfo8_sendMessage);
}

void Heavy_CircleStrings::cMsg_7AjoKdV1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_YdHVzVrz, 0, m, &cDelay_YdHVzVrz_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_P0emgaxE, 0, m, &cDelay_P0emgaxE_sendMessage);
}

void Heavy_CircleStrings::cMsg_a4EkuIRA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_IyHX8KBU, HV_BINOP_MAX, 1, m, &cBinop_IyHX8KBU_sendMessage);
}

void Heavy_CircleStrings::cBinop_IyHX8KBU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tOG3lDr0, HV_BINOP_SUBTRACT, 1, m, &cBinop_tOG3lDr0_sendMessage);
}

void Heavy_CircleStrings::cCast_zdEOzVnz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YdHVzVrz, 0, m, &cDelay_YdHVzVrz_sendMessage);
}

void Heavy_CircleStrings::cBinop_FIE3HjR1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YdHVzVrz, 2, m, &cDelay_YdHVzVrz_sendMessage);
}

void Heavy_CircleStrings::cBinop_CXtPcSzJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_FIE3HjR1_sendMessage);
}

void Heavy_CircleStrings::cCast_e2CKM1TO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sheJmEXS, 0, m, &cVar_sheJmEXS_sendMessage);
  cMsg_JF13GsVb_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_lpn6N5H2, 0, m, &cTabhead_lpn6N5H2_sendMessage);
}

void Heavy_CircleStrings::cBinop_xi9yvlyk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LN4za9GX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_isgB7vve_sendMessage);
}

void Heavy_CircleStrings::cBinop_mMWSF5Oe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_q2PHOVSw_sendMessage);
}

void Heavy_CircleStrings::cBinop_q2PHOVSw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1FwAuNI7, HV_BINOP_POW, 1, m, &cBinop_1FwAuNI7_sendMessage);
  cMsg_QGIu5i3M_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_1FwAuNI7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_xi9yvlyk_sendMessage);
}

void Heavy_CircleStrings::cMsg_QGIu5i3M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1FwAuNI7, HV_BINOP_POW, 0, m, &cBinop_1FwAuNI7_sendMessage);
}

void Heavy_CircleStrings::cVar_kNfMEbRm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_mMWSF5Oe_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_v6eiGewa_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HQrZnBkx_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_yrYmU1wH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_KWh7YejA_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_KWh7YejA_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_Xik6pFmv, 1, m, &cDelay_Xik6pFmv_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yueUr8ax_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_Xik6pFmv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Xik6pFmv, m);
  cMsg_kEfhc8Cq_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_KWh7YejA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Xik6pFmv, 0, m, &cDelay_Xik6pFmv_sendMessage);
}

void Heavy_CircleStrings::cCast_yueUr8ax_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Xik6pFmv, 0, m, &cDelay_Xik6pFmv_sendMessage);
}

void Heavy_CircleStrings::cVar_nOzzZo07_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_S3QuEjUN, HV_BINOP_MULTIPLY, 0, m, &cBinop_S3QuEjUN_sendMessage);
}

void Heavy_CircleStrings::cMsg_VRWE3pmy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_c9op3pVY_sendMessage);
}

void Heavy_CircleStrings::cSystem_c9op3pVY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TSXxr3ZA_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_S3QuEjUN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_xbqM1Sxe_sendMessage);
}

void Heavy_CircleStrings::cBinop_mdVxw6Cm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_S3QuEjUN, HV_BINOP_MULTIPLY, 1, m, &cBinop_S3QuEjUN_sendMessage);
}

void Heavy_CircleStrings::cMsg_TSXxr3ZA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_mdVxw6Cm_sendMessage);
}

void Heavy_CircleStrings::cBinop_xbqM1Sxe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_EA3dcueu_sendMessage);
}

void Heavy_CircleStrings::cBinop_EA3dcueu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_pzoL42Rm_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_2jUZNcBL, m);
}

void Heavy_CircleStrings::cBinop_pzoL42Rm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_i3WZOCxM, m);
}

void Heavy_CircleStrings::cMsg_ul82nTfl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_MhS6jFrn_sendMessage);
}

void Heavy_CircleStrings::cSystem_MhS6jFrn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_22hnza1h_sendMessage);
}

void Heavy_CircleStrings::cDelay_k7tpb9BW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_k7tpb9BW, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bIXIyheA, 0, m, &cDelay_bIXIyheA_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_k7tpb9BW, 0, m, &cDelay_k7tpb9BW_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_wmtdAQf5, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_bIXIyheA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bIXIyheA, m);
  cMsg_3IJPRH3D_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_eH1Y9H49_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_u4RKd9gp_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_GmUsEId6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LYBqcPWd_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_jbRSuQoA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fLRl4tZ6_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_k7tpb9BW, 2, m, &cDelay_k7tpb9BW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qM8cPwKi_sendMessage);
}

void Heavy_CircleStrings::cMsg_LYBqcPWd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_jbRSuQoA, 0, m, &hTable_jbRSuQoA_sendMessage);
}

void Heavy_CircleStrings::cBinop_22hnza1h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_GmUsEId6_sendMessage);
}

void Heavy_CircleStrings::cMsg_3IJPRH3D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_jbRSuQoA, 0, m, &hTable_jbRSuQoA_sendMessage);
}

void Heavy_CircleStrings::cCast_qM8cPwKi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_k7tpb9BW, 0, m, &cDelay_k7tpb9BW_sendMessage);
}

void Heavy_CircleStrings::cMsg_fLRl4tZ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_bIXIyheA, 2, m, &cDelay_bIXIyheA_sendMessage);
}

void Heavy_CircleStrings::cMsg_u4RKd9gp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_wmtdAQf5, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_O7S5hbFt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_dL33Nybz, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_kEfhc8Cq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_dL33Nybz, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_HQrZnBkx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_O7S5hbFt_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_v6eiGewa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_yrYmU1wH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_KfjgAXfc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_mMWSF5Oe_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_v6eiGewa_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HQrZnBkx_sendMessage);
}

void Heavy_CircleStrings::cBinop_DsMKCkK4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jOdEeeMN, HV_BINOP_MULTIPLY, 1, m, &cBinop_jOdEeeMN_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_e2CKM1TO_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Xik6pFmv, 1, m, &cDelay_Xik6pFmv_sendMessage);
}

void Heavy_CircleStrings::cMsg_BdzZSZfi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_DsMKCkK4, HV_BINOP_DIVIDE, 0, m, &cBinop_DsMKCkK4_sendMessage);
}

void Heavy_CircleStrings::cCast_LN4za9GX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DsMKCkK4, HV_BINOP_DIVIDE, 1, m, &cBinop_DsMKCkK4_sendMessage);
}

void Heavy_CircleStrings::cCast_isgB7vve_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BdzZSZfi_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cUnop_lgOumdgy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_LpO6e77h, 0, m, &cPack_LpO6e77h_sendMessage);
}

void Heavy_CircleStrings::cUnop_P6h8yHQQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_sZ4e1iT1, 0, m, &cPack_sZ4e1iT1_sendMessage);
}

void Heavy_CircleStrings::cPack_sZ4e1iT1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_wM9hMYAQ, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_LpO6e77h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_aInKJIke, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_qAlHOz9N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_lgOumdgy_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_P6h8yHQQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_maSYQLDH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_qAlHOz9N_sendMessage);
}

void Heavy_CircleStrings::cSlice_jJqlwEor_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_D9ikHDX4_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_gyTwnZQ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_B7uRQakh_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_LI22ZwjP_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_mMWSF5Oe_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_v6eiGewa_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HQrZnBkx_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_L4qTW0n4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_wsYiOosw_sendMessage);
}

void Heavy_CircleStrings::cBinop_wsYiOosw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_qAlHOz9N_sendMessage);
}

void Heavy_CircleStrings::cBinop_D9ikHDX4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_1uoeJcRM_sendMessage(_c, 0, m);
  cSend_3jldUd5Y_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_UnkaATq4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZYJZIcnx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_r6x6Dhpj_sendMessage);
}

void Heavy_CircleStrings::cBinop_4QoedAuh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_qiqQIq17_sendMessage);
}

void Heavy_CircleStrings::cBinop_qiqQIq17_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UnkaATq4, HV_BINOP_MULTIPLY, 1, m, &cBinop_UnkaATq4_sendMessage);
}

void Heavy_CircleStrings::cSend_1uoeJcRM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_WXW8PZkj_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_ZYJZIcnx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_pqQrxBQo_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_r6x6Dhpj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wpTuozAk_sendMessage);
}

void Heavy_CircleStrings::cBinop_m9BMmEVk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_fLYWNz5o, 0, m, &cPack_fLYWNz5o_sendMessage);
}

void Heavy_CircleStrings::cSend_3jldUd5Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_keerNrT4_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_D64Yu3JR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_IwcGKp9J_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_my5Nfkir_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_D64Yu3JR_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_DrihvFQb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.999f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_FDvLCmUs, m);
}

void Heavy_CircleStrings::cCast_B7uRQakh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_a0DCiFa1_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_4awtKk01_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3lIUPeJt_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_e6qSJrJr_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SEzX3V8J_sendMessage);
}

void Heavy_CircleStrings::cIf_75x3CruJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_BTUtDBiV_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_xneQVN2j_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_sHsCXIK9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sgoYgPyt, HV_BINOP_POW, 0, m, &cBinop_sgoYgPyt_sendMessage);
}

void Heavy_CircleStrings::cBinop_sgoYgPyt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_QHe78A3C, 0, m, &cPack_QHe78A3C_sendMessage);
}

void Heavy_CircleStrings::cBinop_KBrssG67_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_IbDYvmsk_sendMessage);
}

void Heavy_CircleStrings::cCast_e6qSJrJr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_1HBBySeq_sendMessage);
}

void Heavy_CircleStrings::cCast_SEzX3V8J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_75x3CruJ, 0, m, &cIf_75x3CruJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_1HBBySeq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_75x3CruJ, 1, m, &cIf_75x3CruJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_xneQVN2j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_KBrssG67_sendMessage);
}

void Heavy_CircleStrings::cMsg_BTUtDBiV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_QHe78A3C, 0, m, &cPack_QHe78A3C_sendMessage);
}

void Heavy_CircleStrings::cBinop_IbDYvmsk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sgoYgPyt, HV_BINOP_POW, 1, m, &cBinop_sgoYgPyt_sendMessage);
  cMsg_sHsCXIK9_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_QHe78A3C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_YXSnrxI5, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_5sxza9cH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_645YhmOj_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_3lIUPeJt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_oUjxHdp7_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_oUjxHdp7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_tUAVJ27W_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_645YhmOj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_4givbUdk_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_nRvNsAen_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HtZYp7WK_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Kn8JPFqw_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OEBVvjby_sendMessage);
}

void Heavy_CircleStrings::cIf_b5DILz8B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_dGBArEJU_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_eY7WoiiI_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_kVWX0Xui_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_q7kcLDVK, HV_BINOP_POW, 0, m, &cBinop_q7kcLDVK_sendMessage);
}

void Heavy_CircleStrings::cBinop_q7kcLDVK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Naorkc2G, 0, m, &cPack_Naorkc2G_sendMessage);
}

void Heavy_CircleStrings::cBinop_yoNWy0Rk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_l9vxV9Pe_sendMessage);
}

void Heavy_CircleStrings::cCast_Kn8JPFqw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_PGL2UPkP_sendMessage);
}

void Heavy_CircleStrings::cCast_OEBVvjby_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_b5DILz8B, 0, m, &cIf_b5DILz8B_sendMessage);
}

void Heavy_CircleStrings::cBinop_PGL2UPkP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_b5DILz8B, 1, m, &cIf_b5DILz8B_sendMessage);
}

void Heavy_CircleStrings::cBinop_eY7WoiiI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_yoNWy0Rk_sendMessage);
}

void Heavy_CircleStrings::cMsg_dGBArEJU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_Naorkc2G, 0, m, &cPack_Naorkc2G_sendMessage);
}

void Heavy_CircleStrings::cBinop_l9vxV9Pe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_q7kcLDVK, HV_BINOP_POW, 1, m, &cBinop_q7kcLDVK_sendMessage);
  cMsg_kVWX0Xui_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_Naorkc2G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_OLt1EviP, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_KVZmfw2i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Vl8UkiGa_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_HtZYp7WK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_ZveaR9BJ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_ZveaR9BJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_zzYAcezJ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_Vl8UkiGa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_aZVjgCWP_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_VMs9TkcM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1LjWCV6l_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jjMrXkqL_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CGmyYilV_sendMessage);
}

void Heavy_CircleStrings::cIf_bou0rp1y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_05hKbifC_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_pr0EABgT_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_jJAgxcT1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JCV539Ly, HV_BINOP_POW, 0, m, &cBinop_JCV539Ly_sendMessage);
}

void Heavy_CircleStrings::cBinop_JCV539Ly_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ijhTpQps, 0, m, &cPack_ijhTpQps_sendMessage);
}

void Heavy_CircleStrings::cBinop_qbTbaXwH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_0dEOcJvd_sendMessage);
}

void Heavy_CircleStrings::cCast_CGmyYilV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_bou0rp1y, 0, m, &cIf_bou0rp1y_sendMessage);
}

void Heavy_CircleStrings::cCast_jjMrXkqL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_MJcqay2D_sendMessage);
}

void Heavy_CircleStrings::cBinop_MJcqay2D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_bou0rp1y, 1, m, &cIf_bou0rp1y_sendMessage);
}

void Heavy_CircleStrings::cBinop_pr0EABgT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_qbTbaXwH_sendMessage);
}

void Heavy_CircleStrings::cMsg_05hKbifC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_ijhTpQps, 0, m, &cPack_ijhTpQps_sendMessage);
}

void Heavy_CircleStrings::cBinop_0dEOcJvd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JCV539Ly, HV_BINOP_POW, 1, m, &cBinop_JCV539Ly_sendMessage);
  cMsg_jJAgxcT1_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_ijhTpQps_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_JQQA3LuM, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_S6koGsfZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_vGdyTy0p_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_1LjWCV6l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_3pzQ4yEu_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_3pzQ4yEu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_rzspvuVD_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_vGdyTy0p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_gTFZarPP_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cIf_BgnSFCzE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_fEwtMRK9_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_esjsgFWv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cUnop_esjsgFWv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_g1JonOAk_sendMessage);
}

void Heavy_CircleStrings::cCast_SAhtfuXp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_BgnSFCzE, 0, m, &cIf_BgnSFCzE_sendMessage);
}

void Heavy_CircleStrings::cCast_eeqowzCV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_mbj93EvW_sendMessage);
}

void Heavy_CircleStrings::cMsg_fEwtMRK9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_3lIUPeJt_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_e6qSJrJr_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SEzX3V8J_sendMessage);
}

void Heavy_CircleStrings::cBinop_g1JonOAk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_2DQAbRQR_sendMessage);
}

void Heavy_CircleStrings::cBinop_2DQAbRQR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_KirxYrRD_sendMessage);
}

void Heavy_CircleStrings::cBinop_KirxYrRD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3lIUPeJt_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_e6qSJrJr_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SEzX3V8J_sendMessage);
}

void Heavy_CircleStrings::cBinop_mbj93EvW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_BgnSFCzE, 1, m, &cIf_BgnSFCzE_sendMessage);
}

void Heavy_CircleStrings::cBinop_Eh3Qfh32_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_eeqowzCV_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SAhtfuXp_sendMessage);
}

void Heavy_CircleStrings::cBinop_xTjU03yM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Eh3Qfh32_sendMessage);
}

void Heavy_CircleStrings::cIf_31O9fJq4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_CfGayVCi_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_oYwge4A5_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cUnop_oYwge4A5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_eS8J4aHf_sendMessage);
}

void Heavy_CircleStrings::cCast_Wl7ktqtW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_31O9fJq4, 0, m, &cIf_31O9fJq4_sendMessage);
}

void Heavy_CircleStrings::cCast_ieyoLuIG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_hoiVLVzP_sendMessage);
}

void Heavy_CircleStrings::cMsg_CfGayVCi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_HtZYp7WK_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Kn8JPFqw_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OEBVvjby_sendMessage);
}

void Heavy_CircleStrings::cBinop_eS8J4aHf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_FVmBqX8M_sendMessage);
}

void Heavy_CircleStrings::cBinop_FVmBqX8M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_2ZCq1XBP_sendMessage);
}

void Heavy_CircleStrings::cBinop_2ZCq1XBP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HtZYp7WK_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Kn8JPFqw_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OEBVvjby_sendMessage);
}

void Heavy_CircleStrings::cBinop_hoiVLVzP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_31O9fJq4, 1, m, &cIf_31O9fJq4_sendMessage);
}

void Heavy_CircleStrings::cBinop_VFOojwxp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ieyoLuIG_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Wl7ktqtW_sendMessage);
}

void Heavy_CircleStrings::cBinop_gEUJvVj1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_VFOojwxp_sendMessage);
}

void Heavy_CircleStrings::cVar_2oEEqlVB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4lobzQQ5_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iH0pwOCG_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hDmKvsNQ_sendMessage);
}

void Heavy_CircleStrings::cIf_wfxB4ES0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_NUvrcz0J_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_wfjwfxkg_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_9E6ztahJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_rwEdFdFp, HV_BINOP_POW, 0, m, &cBinop_rwEdFdFp_sendMessage);
}

void Heavy_CircleStrings::cBinop_rwEdFdFp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_fTD6v2FM, 0, m, &cPack_fTD6v2FM_sendMessage);
}

void Heavy_CircleStrings::cBinop_ADMFufw3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_9Q9RT0ve_sendMessage);
}

void Heavy_CircleStrings::cCast_hDmKvsNQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_wfxB4ES0, 0, m, &cIf_wfxB4ES0_sendMessage);
}

void Heavy_CircleStrings::cCast_iH0pwOCG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_ApPudWn7_sendMessage);
}

void Heavy_CircleStrings::cBinop_ApPudWn7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_wfxB4ES0, 1, m, &cIf_wfxB4ES0_sendMessage);
}

void Heavy_CircleStrings::cBinop_wfjwfxkg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_ADMFufw3_sendMessage);
}

void Heavy_CircleStrings::cMsg_NUvrcz0J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_fTD6v2FM, 0, m, &cPack_fTD6v2FM_sendMessage);
}

void Heavy_CircleStrings::cBinop_9Q9RT0ve_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rwEdFdFp, HV_BINOP_POW, 1, m, &cBinop_rwEdFdFp_sendMessage);
  cMsg_9E6ztahJ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_fTD6v2FM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_nv8148p4, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_GtXUaDqb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_5aosGoZD_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_4lobzQQ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_viZmru7E_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_viZmru7E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_PhnBTP9W_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_5aosGoZD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_tIBBdh1V_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_KhheXSBq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_4HcoiZX9, 0, m, &cIf_4HcoiZX9_sendMessage);
}

void Heavy_CircleStrings::cSlice_cEZ5Ybc4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fTEIcKff_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bvJqSCO7_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_cJonp05J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_6BsToJNc, 0, m, &cIf_6BsToJNc_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_6BsToJNc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PX7L3RE1_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4k9gUL4T_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_RXMqfEqq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_tdvuGjRQ, 2, m, &cPack_tdvuGjRQ_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_z5LFSMWT, 1, m, &cPack_z5LFSMWT_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_P6KIwksz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_cEZ5Ybc4, 0, m, &cSlice_cEZ5Ybc4_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_cJonp05J, 0, m, &cSlice_cJonp05J_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_mSTqs3Ss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_5JoPha5K_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_NdmFVrz4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Hhjy2nsZ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cGY3R4Gz_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_G0KkhwhL_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_v3PPdNzm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_X7PtE6y1, 1, m, &cIf_X7PtE6y1_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_NQl0AMTo_sendMessage);
}

void Heavy_CircleStrings::cIf_X7PtE6y1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_cEZ5Ybc4, 0, m, &cSlice_cEZ5Ybc4_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_cJonp05J, 0, m, &cSlice_cJonp05J_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cPack_z5LFSMWT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_P6KIwksz, 0, m, &cIf_P6KIwksz_sendMessage);
}

void Heavy_CircleStrings::cBinop_WtucyTMK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_6BsToJNc, 1, m, &cIf_6BsToJNc_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_RXMqfEqq, 1, m, &cIf_RXMqfEqq_sendMessage);
}

void Heavy_CircleStrings::cCast_fTEIcKff_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_WtucyTMK_sendMessage);
}

void Heavy_CircleStrings::cCast_bvJqSCO7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_RXMqfEqq, 0, m, &cIf_RXMqfEqq_sendMessage);
}

void Heavy_CircleStrings::cMsg_d9toatBv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_v3PPdNzm, 1, m, &cVar_v3PPdNzm_sendMessage);
}

void Heavy_CircleStrings::cMsg_5JoPha5K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_v3PPdNzm, 1, m, &cVar_v3PPdNzm_sendMessage);
}

void Heavy_CircleStrings::cCast_G0KkhwhL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_d9toatBv_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_Hhjy2nsZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_v3PPdNzm, 0, m, &cVar_v3PPdNzm_sendMessage);
}

void Heavy_CircleStrings::cCast_cGY3R4Gz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_z5LFSMWT, 0, m, &cPack_z5LFSMWT_sendMessage);
}

void Heavy_CircleStrings::cBinop_NQl0AMTo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_P6KIwksz, 1, m, &cIf_P6KIwksz_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_T5rAeT6G_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_uEPkBz8w, 0, m, &cSlice_uEPkBz8w_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_li0p7INZ, 0, m, &cSlice_li0p7INZ_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_a7Kvb0s9, 0, m, &cSlice_a7Kvb0s9_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_5djnKwsA, 0, m, &cSlice_5djnKwsA_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cSlice_uEPkBz8w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_jpXYpQpM, 0, m, &cSlice_jpXYpQpM_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Y8v0pQKb, 0, m, &cSlice_Y8v0pQKb_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_jpXYpQpM, 0, m, &cSlice_jpXYpQpM_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Y8v0pQKb, 0, m, &cSlice_Y8v0pQKb_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_li0p7INZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_qhhqy6VU, 0, m, &cSlice_qhhqy6VU_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Xhdvy25o, 0, m, &cSlice_Xhdvy25o_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_qhhqy6VU, 0, m, &cSlice_qhhqy6VU_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Xhdvy25o, 0, m, &cSlice_Xhdvy25o_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_a7Kvb0s9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_jJqlwEor, 0, m, &cSlice_jJqlwEor_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_gyTwnZQ8, 0, m, &cSlice_gyTwnZQ8_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_jJqlwEor, 0, m, &cSlice_jJqlwEor_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_gyTwnZQ8, 0, m, &cSlice_gyTwnZQ8_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_5djnKwsA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_0bG2aPGk, 0, m, &cSlice_0bG2aPGk_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_CSWs3v21, 0, m, &cSlice_CSWs3v21_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_0bG2aPGk, 0, m, &cSlice_0bG2aPGk_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_CSWs3v21, 0, m, &cSlice_CSWs3v21_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSwitchcase_R3srInKr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7UNv1qDw_sendMessage);
      break;
    }
    default: {
      cMsg_cqGNRr3l_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_7UNv1qDw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cKDdrhpJ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cIf_4HcoiZX9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_mSTqs3Ss, 0, m, &cSlice_mSTqs3Ss_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_NdmFVrz4, 0, m, &cSlice_NdmFVrz4_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_X7PtE6y1, 0, m, &cIf_X7PtE6y1_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_7htb47gg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_BwIcfdGz_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_4HcoiZX9, 1, m, &cIf_4HcoiZX9_sendMessage);
}

void Heavy_CircleStrings::cBinop_BwIcfdGz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7htb47gg, 1, m, &cVar_7htb47gg_sendMessage);
}

void Heavy_CircleStrings::cMsg_cKDdrhpJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_7htb47gg, 0, m, &cVar_7htb47gg_sendMessage);
}

void Heavy_CircleStrings::cMsg_cqGNRr3l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_7htb47gg, 0, m, &cVar_7htb47gg_sendMessage);
}

void Heavy_CircleStrings::cPack_tdvuGjRQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_T5rAeT6G_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_spIZlEdf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_tdvuGjRQ, 0, m, &cPack_tdvuGjRQ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_aEHWQICK_sendMessage);
}

void Heavy_CircleStrings::cBinop_aEHWQICK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 4.0f, 0, m, &cBinop_o4IDtSOS_sendMessage);
}

void Heavy_CircleStrings::cBinop_o4IDtSOS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_spIZlEdf, 1, m, &cVar_spIZlEdf_sendMessage);
}

void Heavy_CircleStrings::cMsg_022CEW2H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_R3srInKr_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_4k9gUL4T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_spIZlEdf, 0, m, &cVar_spIZlEdf_sendMessage);
}

void Heavy_CircleStrings::cCast_PX7L3RE1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_tdvuGjRQ, 1, m, &cPack_tdvuGjRQ_sendMessage);
}

void Heavy_CircleStrings::cSend_0NUHkcKU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_mun6KkPl_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_2xoOe2wZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_HTrUDWdv_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_ctzHxdje_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cBinop_BX2Tag67_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_AOR4iRbk_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_AOR4iRbk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_XiEIWyN0_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_BevmVgPQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_rTp6sb07_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cReceive_z15lKRD7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PgLznuSx_sendMessage(_c, 0, m);
  cMsg_E6hzZEXn_sendMessage(_c, 0, m);
  cMsg_0MvhqiQP_sendMessage(_c, 0, m);
  cMsg_lkLxvsYr_sendMessage(_c, 0, m);
  cMsg_i0i6UmxR_sendMessage(_c, 0, m);
  cMsg_IpG7KGBy_sendMessage(_c, 0, m);
  cMsg_VHYZi92w_sendMessage(_c, 0, m);
  cMsg_XgLCWMWo_sendMessage(_c, 0, m);
  cMsg_4yBoylks_sendMessage(_c, 0, m);
  cMsg_Abek11p1_sendMessage(_c, 0, m);
  cMsg_0CWBZzjE_sendMessage(_c, 0, m);
  cMsg_83AJYhzK_sendMessage(_c, 0, m);
  cMsg_Kk0137OX_sendMessage(_c, 0, m);
  cMsg_gwPbZWaw_sendMessage(_c, 0, m);
  cMsg_ygYyviTm_sendMessage(_c, 0, m);
  cMsg_2M1qUQoG_sendMessage(_c, 0, m);
  cMsg_eY6aZjmT_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_XAMVlRva, 0, m, &cVar_XAMVlRva_sendMessage);
  cMsg_Ey42lQN1_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_z3Zmlm2Z, 0, m, &cVar_z3Zmlm2Z_sendMessage);
  cMsg_Y0dctD9L_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_SfS2LCdm, 0, m, &cVar_SfS2LCdm_sendMessage);
  cMsg_EbMkKzYS_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_JDmMifvj, 0, m, &cVar_JDmMifvj_sendMessage);
  cMsg_bGNig5OW_sendMessage(_c, 0, m);
  cMsg_3DQ3sY9y_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_oTbLg06O, 0, m, &cVar_oTbLg06O_sendMessage);
  cMsg_Ck7wBAPk_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BbOWz0oz, 0, m, &cVar_BbOWz0oz_sendMessage);
  cMsg_Ord1Ac5H_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_LcsWtpaK, 0, m, &cVar_LcsWtpaK_sendMessage);
  cMsg_wlxQM0ah_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_EOf4mgEx, 0, m, &cVar_EOf4mgEx_sendMessage);
  cMsg_ZGZM2rar_sendMessage(_c, 0, m);
  cMsg_fpsqCfVa_sendMessage(_c, 0, m);
  cMsg_a2NUMzhB_sendMessage(_c, 0, m);
  cMsg_XsypfDNc_sendMessage(_c, 0, m);
  cMsg_jzzw95Gl_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BN8SblCZ, 0, m, &cVar_BN8SblCZ_sendMessage);
  cMsg_1A01qLtW_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_u1QFAeIg, 0, m, &cVar_u1QFAeIg_sendMessage);
  cMsg_YSCC8qzC_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5XeB1hlH, 0, m, &cVar_5XeB1hlH_sendMessage);
  cMsg_YETOrtRC_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YufBLxpG, 0, m, &cVar_YufBLxpG_sendMessage);
  cMsg_7oYrtJvP_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_lFKnOJ8b, 0, m, &cVar_lFKnOJ8b_sendMessage);
  cMsg_17yIwOMI_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Pdo5FwNb, 0, m, &cVar_Pdo5FwNb_sendMessage);
  cMsg_sCAnaivh_sendMessage(_c, 0, m);
  cMsg_E24PtVDn_sendMessage(_c, 0, m);
  cMsg_Yszy5QIN_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_G8jrQs1J, 0, m, &cVar_G8jrQs1J_sendMessage);
  cMsg_3TY7y53p_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_aNJuv9nj, 0, m, &cVar_aNJuv9nj_sendMessage);
  cMsg_rY1qWc6A_sendMessage(_c, 0, m);
  cMsg_Lv2rUYq0_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Uynq530P, 0, m, &cVar_Uynq530P_sendMessage);
  cMsg_JvOhUwAt_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_R0pcyLuB, 0, m, &cVar_R0pcyLuB_sendMessage);
  cSwitchcase_qTaogUTf_onMessage(_c, NULL, 0, m, NULL);
  cMsg_jVEfEQ2J_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_nYgxT2Ub, 0, m, &cVar_nYgxT2Ub_sendMessage);
  cMsg_nr5HY5lq_sendMessage(_c, 0, m);
  cSwitchcase_EOi3pX6j_onMessage(_c, NULL, 0, m, NULL);
  cMsg_frSDY1YG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Oju8PReC, 0, m, &cVar_Oju8PReC_sendMessage);
  cMsg_NYc7BM7g_sendMessage(_c, 0, m);
  cSwitchcase_jmgMcw2z_onMessage(_c, NULL, 0, m, NULL);
  cMsg_zB1Ku52Q_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6WcN0BUW, 0, m, &cVar_6WcN0BUW_sendMessage);
  cMsg_WBvw5uWu_sendMessage(_c, 0, m);
  cSwitchcase_AJsjC4QN_onMessage(_c, NULL, 0, m, NULL);
  cMsg_HfwAW5m1_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_bT3aOXEE, 0, m, &cVar_bT3aOXEE_sendMessage);
  cMsg_VtIFulVs_sendMessage(_c, 0, m);
  cSwitchcase_8F13ayPI_onMessage(_c, NULL, 0, m, NULL);
  cMsg_VRWE3pmy_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_nOzzZo07, 0, m, &cVar_nOzzZo07_sendMessage);
  cMsg_ul82nTfl_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_y0NVUvgc, 0, m, &cVar_y0NVUvgc_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_c1l2Btyy, 0, m, &cVar_c1l2Btyy_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_mfOqSYJr, 0, m, &cVar_mfOqSYJr_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_MiiDkY87, 0, m, &cVar_MiiDkY87_sendMessage);
  cMsg_D1LiZIcv_sendMessage(_c, 0, m);
  cMsg_SvJBgjSN_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TDYXfXib, 0, m, &cVar_TDYXfXib_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_q7t9aMkq, 0, m, &cVar_q7t9aMkq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_xijUO3KL, 0, m, &cVar_xijUO3KL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_PuI38dFq, 0, m, &cVar_PuI38dFq_sendMessage);
  cMsg_2fUKrrzY_sendMessage(_c, 0, m);
  cMsg_qRz56KBJ_sendMessage(_c, 0, m);
  cMsg_1AQohi33_sendMessage(_c, 0, m);
  cMsg_9RCyVg3F_sendMessage(_c, 0, m);
  cMsg_DWSmJ25w_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mDYSGxXq, 0, m, &cVar_mDYSGxXq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_8UjNKdi6, 0, m, &cVar_8UjNKdi6_sendMessage);
  cMsg_8w76cRsN_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3Gl8TCrA, 0, m, &cVar_3Gl8TCrA_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_PK8cZwxn, 0, m, &cVar_PK8cZwxn_sendMessage);
  cMsg_GvE7FZ51_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BBz2VrJD, 0, m, &cVar_BBz2VrJD_sendMessage);
  cMsg_fzmAZoD0_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_OtXf2NGF, 0, m, &cVar_OtXf2NGF_sendMessage);
  cMsg_32mKshzV_sendMessage(_c, 0, m);
  cMsg_FWkzHKOS_sendMessage(_c, 0, m);
  cMsg_D39JvJRc_sendMessage(_c, 0, m);
  cMsg_R2aHnIlg_sendMessage(_c, 0, m);
  cMsg_fIh4s1kf_sendMessage(_c, 0, m);
  cMsg_GxUW5Mga_sendMessage(_c, 0, m);
  cMsg_xrpMSHKE_sendMessage(_c, 0, m);
  cMsg_6oUHHGBR_sendMessage(_c, 0, m);
  cMsg_L9DYZv3j_sendMessage(_c, 0, m);
  cMsg_uAxxuoBy_sendMessage(_c, 0, m);
  cMsg_inp4SkBG_sendMessage(_c, 0, m);
  cMsg_Dx5pIBG2_sendMessage(_c, 0, m);
  cMsg_MAQ1c9gX_sendMessage(_c, 0, m);
  cMsg_KIYZN7A6_sendMessage(_c, 0, m);
  cMsg_cMLWgE7g_sendMessage(_c, 0, m);
  cMsg_maSYQLDH_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5HRueZcU, 0, m, &cVar_5HRueZcU_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_fGDcFREV, 0, m, &cVar_fGDcFREV_sendMessage);
  cMsg_Cbzreay3_sendMessage(_c, 0, m);
  cMsg_ucnSEKIY_sendMessage(_c, 0, m);
  cMsg_faLU9lvh_sendMessage(_c, 0, m);
  cMsg_zLtnekYy_sendMessage(_c, 0, m);
  cMsg_Umkk2CVP_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ODWpAQfD, 0, m, &cVar_ODWpAQfD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_zdgJDFxf, 0, m, &cVar_zdgJDFxf_sendMessage);
  cMsg_TuEgV2g8_sendMessage(_c, 0, m);
  cMsg_nhBR4nr5_sendMessage(_c, 0, m);
  cMsg_bW17opAL_sendMessage(_c, 0, m);
  cMsg_6UiGxr0L_sendMessage(_c, 0, m);
  cMsg_my5Nfkir_sendMessage(_c, 0, m);
  cMsg_DrihvFQb_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4awtKk01, 0, m, &cVar_4awtKk01_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_nRvNsAen, 0, m, &cVar_nRvNsAen_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VMs9TkcM, 0, m, &cVar_VMs9TkcM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_2oEEqlVB, 0, m, &cVar_2oEEqlVB_sendMessage);
  cMsg_022CEW2H_sendMessage(_c, 0, m);
  cSwitchcase_rTp6sb07_onMessage(_c, NULL, 0, m, NULL);
  cMsg_qu52Pgzy_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5j1fsrI9, 0, m, &cVar_5j1fsrI9_sendMessage);
  cMsg_mleAknBD_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_kIUUkF3b, 0, m, &cTabhead_kIUUkF3b_sendMessage);
  cMsg_mqQSqgMQ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_xXOK1dHc, 0, m, &cVar_xXOK1dHc_sendMessage);
  cMsg_ckIRTuyA_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_av6pSjq1, 0, m, &cTabhead_av6pSjq1_sendMessage);
  cMsg_TyOAdaoz_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_AIGKHj7e, 0, m, &cVar_AIGKHj7e_sendMessage);
  cMsg_piHRMNSv_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_WC8z9Hmn, 0, m, &cTabhead_WC8z9Hmn_sendMessage);
  cMsg_iFQrai8M_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5HSpMBj1, 0, m, &cVar_5HSpMBj1_sendMessage);
  cMsg_oRsRUyqb_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_mYnK0tAu, 0, m, &cTabhead_mYnK0tAu_sendMessage);
  cMsg_S0u2W3N0_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_c5DRnk7T, 0, m, &cVar_c5DRnk7T_sendMessage);
  cMsg_23bm6hwN_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_CuoYbRfc, 0, m, &cTabhead_CuoYbRfc_sendMessage);
  cMsg_IgpieN4C_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_V60o2kg6, 0, m, &cVar_V60o2kg6_sendMessage);
  cMsg_7mEbylLK_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_VCs3GKXV, 0, m, &cTabhead_VCs3GKXV_sendMessage);
  cMsg_7kzcVlRE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_PMByxuth, 0, m, &cVar_PMByxuth_sendMessage);
  cMsg_ahKukNUl_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_PLUfVxIB, 0, m, &cTabhead_PLUfVxIB_sendMessage);
  cMsg_4Bb6W8OR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3M0C3fcL, 0, m, &cVar_3M0C3fcL_sendMessage);
  cMsg_JFeds759_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_jZeiPhad, 0, m, &cTabhead_jZeiPhad_sendMessage);
  cMsg_HwlT9UdO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_OwltTNXy, 0, m, &cVar_OwltTNXy_sendMessage);
  cMsg_3DE1aU21_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_maWMKIGC, 0, m, &cTabhead_maWMKIGC_sendMessage);
  cMsg_JUdUUjxI_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_7WMxPwCV, 0, m, &cVar_7WMxPwCV_sendMessage);
  cMsg_MAgD4Fnd_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_g3X0oNQK, 0, m, &cTabhead_g3X0oNQK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_avBng3Ba, 0, m, &cVar_avBng3Ba_sendMessage);
  cMsg_6DhUNtsl_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_w7tZvEtH, 0, m, &cVar_w7tZvEtH_sendMessage);
  cMsg_vb2DwimO_sendMessage(_c, 0, m);
  cMsg_7wmNKdly_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_338lqcMq, 0, m, &cVar_338lqcMq_sendMessage);
  cMsg_a461nEda_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_NAISSBs9, 0, m, &cTabhead_NAISSBs9_sendMessage);
  cMsg_JuqK2d1S_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_GSqwYHnM, 0, m, &cVar_GSqwYHnM_sendMessage);
  cMsg_eIPWsrKU_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_g9YQT7pb, 0, m, &cTabhead_g9YQT7pb_sendMessage);
  cMsg_2DDtNDZw_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_GCGsJSYu, 0, m, &cVar_GCGsJSYu_sendMessage);
  cMsg_kdyihSIx_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_MAMw6hWl, 0, m, &cTabhead_MAMw6hWl_sendMessage);
  cMsg_oR04lfqE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_FnFwiL3O, 0, m, &cVar_FnFwiL3O_sendMessage);
  cMsg_WdnEMARq_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_B9v9CFfV, 0, m, &cTabhead_B9v9CFfV_sendMessage);
  cMsg_UwBPsFOf_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4OJmUKgn, 0, m, &cVar_4OJmUKgn_sendMessage);
  cMsg_Nlal8TiZ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Psf7wxCL, 0, m, &cTabhead_Psf7wxCL_sendMessage);
  cMsg_JfbcmLH2_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_r8gF6GJZ, 0, m, &cVar_r8gF6GJZ_sendMessage);
  cMsg_BIwFFWHn_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_unNDbdF3, 0, m, &cTabhead_unNDbdF3_sendMessage);
  cMsg_IFmLkF6m_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_v0qrsGGX, 0, m, &cVar_v0qrsGGX_sendMessage);
  cMsg_EsDt989k_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_1f2tzRoW, 0, m, &cTabhead_1f2tzRoW_sendMessage);
  cMsg_1nmirBlX_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5itQXJJu, 0, m, &cVar_5itQXJJu_sendMessage);
  cMsg_BbdIeU3I_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_fPcCs3Bu, 0, m, &cTabhead_fPcCs3Bu_sendMessage);
  cMsg_APglLTf5_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_dea5lSVH, 0, m, &cVar_dea5lSVH_sendMessage);
  cMsg_HjaB2Xxs_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_3IDarXnm, 0, m, &cTabhead_3IDarXnm_sendMessage);
  cMsg_YqeytZcH_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_bmgnBiPI, 0, m, &cVar_bmgnBiPI_sendMessage);
  cMsg_8k3PcyPK_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_KcZmeVMg, 0, m, &cTabhead_KcZmeVMg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_gDqw19Uh, 0, m, &cVar_gDqw19Uh_sendMessage);
  cMsg_0n6NGaNx_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_hzOrUdyI, 0, m, &cVar_hzOrUdyI_sendMessage);
  cMsg_Fmoc8BA3_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ffn5tknD, 0, m, &cVar_ffn5tknD_sendMessage);
  cMsg_3G2ppjC6_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_kMPT6E1m, 0, m, &cVar_kMPT6E1m_sendMessage);
  cMsg_7BtuY5Y5_sendMessage(_c, 0, m);
  cMsg_pxvSbewf_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_OeTUhH3r, 0, m, &cVar_OeTUhH3r_sendMessage);
  cMsg_5mOBspZF_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_PIRTcLF5, 0, m, &cTabhead_PIRTcLF5_sendMessage);
  cMsg_oeTz9NWB_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_II7cyevt, 0, m, &cVar_II7cyevt_sendMessage);
  cMsg_7AoNzPug_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_7eYUWruq, 0, m, &cTabhead_7eYUWruq_sendMessage);
  cMsg_hxuzSydj_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_N6CoGYI1, 0, m, &cVar_N6CoGYI1_sendMessage);
  cMsg_IwnzB0ae_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_I137dHsl, 0, m, &cTabhead_I137dHsl_sendMessage);
  cMsg_NYpZa9AJ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jCbrhYXm, 0, m, &cVar_jCbrhYXm_sendMessage);
  cMsg_zRGEIr8Y_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_GcuaQrBT, 0, m, &cTabhead_GcuaQrBT_sendMessage);
  cMsg_a4EkuIRA_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_sheJmEXS, 0, m, &cVar_sheJmEXS_sendMessage);
  cMsg_JF13GsVb_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_lpn6N5H2, 0, m, &cTabhead_lpn6N5H2_sendMessage);
}

void Heavy_CircleStrings::cReceive_paFXzS1u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_HKPZr0qj, 0, m, &cSlice_HKPZr0qj_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_RFRCPipE, 0, m, &cSlice_RFRCPipE_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_aLnvaTwv, 0, m, &cSlice_aLnvaTwv_sendMessage);
}

void Heavy_CircleStrings::cReceive_mun6KkPl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_KhheXSBq, 0, m, &cPack_KhheXSBq_sendMessage);
}

void Heavy_CircleStrings::cReceive_HTrUDWdv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_KhheXSBq, 1, m, &cPack_KhheXSBq_sendMessage);
}

void Heavy_CircleStrings::cReceive_HwDrfPs2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_RO3BXbOp_sendMessage);
}

void Heavy_CircleStrings::cReceive_Q1srhvcR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OyfR06IH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UAj27hOq_sendMessage);
}

void Heavy_CircleStrings::cReceive_TLdJkZ1G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_q52goVgN_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tBMOvBoZ_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_p5W4lEzM, 0, m, &cPack_p5W4lEzM_sendMessage);
}

void Heavy_CircleStrings::cReceive_YsoAiR4E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_CD109Vwp_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_MKWmybUd, 0, m, &cIf_MKWmybUd_sendMessage);
}

void Heavy_CircleStrings::cReceive_8BTEDG3f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QhchSK7Q, 1, m, &cVar_QhchSK7Q_sendMessage);
}

void Heavy_CircleStrings::cReceive_jmv2yw84_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OGdSgNum, 0, m, &cVar_OGdSgNum_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_5GPJyP0F, 0, m, &cPack_5GPJyP0F_sendMessage);
}

void Heavy_CircleStrings::cReceive_VdQttYAI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_RGHPRDk2_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_3wSKtJTU_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ipB21fYo, 0, m, &cIf_ipB21fYo_sendMessage);
}

void Heavy_CircleStrings::cReceive_9b1R5hr7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cReceive_G6Ob6Ssc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HFQawIg5_sendMessage);
}

void Heavy_CircleStrings::cReceive_Ua4JpGNy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BevmVgPQ_sendMessage);
}

void Heavy_CircleStrings::cReceive_XiEIWyN0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_L1JcSeR9, 0, m, &cVar_L1JcSeR9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_OKREmgC7, 0, m, &cVar_OKREmgC7_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_7GpGI3TD, 0, m, &cVar_7GpGI3TD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lXKU5YO0, 0, m, &cVar_lXKU5YO0_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_mB3jZkYD_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_dfixUOX6, 0, m, &cIf_dfixUOX6_sendMessage);
}

void Heavy_CircleStrings::cReceive_OWiIP9Hi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_VV7MYDku_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_KS8cxS9w, 0, m, &cVar_KS8cxS9w_sendMessage);
}

void Heavy_CircleStrings::cReceive_OJW32dt5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_rAFydJof, 0, m, &cPack_rAFydJof_sendMessage);
}

void Heavy_CircleStrings::cReceive_LrV1qEG8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tuHE2vSN, 1, m, &cVar_tuHE2vSN_sendMessage);
}

void Heavy_CircleStrings::cReceive_CaBFlCMx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_lVKP3cbj, m);
}

void Heavy_CircleStrings::cReceive_1krYfiuI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_4LzuomlI_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_stUsVq2g, 0, m, &cVar_stUsVq2g_sendMessage);
}

void Heavy_CircleStrings::cReceive_btfxZSV9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_rrmXpqmV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_WR9akQL7, 0, m, &cVar_WR9akQL7_sendMessage);
}

void Heavy_CircleStrings::cReceive_hs1AYf2L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ewn0qCkA, 0, m, &cVar_ewn0qCkA_sendMessage);
}

void Heavy_CircleStrings::cReceive_NBVaHytN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_EFrnylsV_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Pqnas3sc_sendMessage);
}

void Heavy_CircleStrings::cReceive_cltzsQBc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_in4G2pe5, 0, m, &cVar_in4G2pe5_sendMessage);
}

void Heavy_CircleStrings::cReceive_5Ye6ENuY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ETXSpJXb_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qcum7bsb_sendMessage);
}

void Heavy_CircleStrings::cReceive_fSA64V8b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_inqYLsdu_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_7hD2Nprw, 0, m, &cVar_7hD2Nprw_sendMessage);
}

void Heavy_CircleStrings::cReceive_rZHYtPol_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_llm7U96a, 0, m, &cPack_llm7U96a_sendMessage);
}

void Heavy_CircleStrings::cReceive_T1mZNjrD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zXVelbzx, 1, m, &cVar_zXVelbzx_sendMessage);
}

void Heavy_CircleStrings::cReceive_fOW6BxY7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_gWCQCHXY, m);
}

void Heavy_CircleStrings::cReceive_dmvH3riW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_EPr7Ug5k_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_IlmsQzp2, 0, m, &cVar_IlmsQzp2_sendMessage);
}

void Heavy_CircleStrings::cReceive_RdjUOu7F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_RGfkI5YB_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_oOUXJBpu, 0, m, &cVar_oOUXJBpu_sendMessage);
}

void Heavy_CircleStrings::cReceive_Ct2oC0HR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_9TfDJhSx_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_nSz4l5UX, 0, m, &cVar_nSz4l5UX_sendMessage);
}

void Heavy_CircleStrings::cReceive_9sFEbxH3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ZDrTJJON, 0, m, &cPack_ZDrTJJON_sendMessage);
}

void Heavy_CircleStrings::cReceive_zThL6YIP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8lWsQlfe, 1, m, &cVar_8lWsQlfe_sendMessage);
}

void Heavy_CircleStrings::cReceive_DoSJnQeD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_jYXNZU9t, m);
}

void Heavy_CircleStrings::cReceive_f9uBL7lX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_dO1SLrLv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4wJQh9gk, 0, m, &cVar_4wJQh9gk_sendMessage);
}

void Heavy_CircleStrings::cReceive_pOYJ3K81_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_w2jzcmMO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ziHKfjQL, 0, m, &cVar_ziHKfjQL_sendMessage);
}

void Heavy_CircleStrings::cReceive_WXW8PZkj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_1j588rdr_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ASuXEL5J, 0, m, &cVar_ASuXEL5J_sendMessage);
}

void Heavy_CircleStrings::cReceive_keerNrT4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_fLYWNz5o, 0, m, &cPack_fLYWNz5o_sendMessage);
}

void Heavy_CircleStrings::cReceive_9z8rJdN4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_X373zqMA, 1, m, &cVar_X373zqMA_sendMessage);
}

void Heavy_CircleStrings::cReceive_j8IQx296_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_DvW9787N, m);
}

void Heavy_CircleStrings::cReceive_q1WawPg5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_oVJk8yS5_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_F16qcfDR, 0, m, &cVar_F16qcfDR_sendMessage);
}

void Heavy_CircleStrings::cReceive_IwcGKp9J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_vIkah4W4_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_o8hEl584, 0, m, &cVar_o8hEl584_sendMessage);
}

void Heavy_CircleStrings::cReceive_tUAVJ27W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5sxza9cH, 0, m, &cVar_5sxza9cH_sendMessage);
}

void Heavy_CircleStrings::cReceive_4givbUdk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_e6qSJrJr_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SEzX3V8J_sendMessage);
}

void Heavy_CircleStrings::cReceive_i6IzAjGn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_xTjU03yM_sendMessage);
}

void Heavy_CircleStrings::cReceive_zzYAcezJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KVZmfw2i, 0, m, &cVar_KVZmfw2i_sendMessage);
}

void Heavy_CircleStrings::cReceive_aZVjgCWP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Kn8JPFqw_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OEBVvjby_sendMessage);
}

void Heavy_CircleStrings::cReceive_M2mBCAbA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_gEUJvVj1_sendMessage);
}

void Heavy_CircleStrings::cReceive_rzspvuVD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_S6koGsfZ, 0, m, &cVar_S6koGsfZ_sendMessage);
}

void Heavy_CircleStrings::cReceive_gTFZarPP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jjMrXkqL_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CGmyYilV_sendMessage);
}

void Heavy_CircleStrings::cReceive_PhnBTP9W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GtXUaDqb, 0, m, &cVar_GtXUaDqb_sendMessage);
}

void Heavy_CircleStrings::cReceive_tIBBdh1V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iH0pwOCG_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hDmKvsNQ_sendMessage);
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
    __hv_tabread_f(&sTabread_7N4SehJC, VOf(Bf0));
    __hv_varread_f(&sVarf_wHh4zhxt, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_XlX97RdE, VOf(Bf0));
    __hv_rpole_f(&sRPole_PoigosCf, VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_pfaoN5RQ, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_91isat8C, VOf(Bf0));
    __hv_varread_i(&sVari_mTxzKFMn, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varwrite_i(&sVari_mTxzKFMn, VIi(Bi1));
    __hv_fma_f(VIf(Bf0), VIf(Bf3), VIf(Bf1), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_xCDJfxaQ, VIf(Bf3));
    __hv_line_f(&sLine_5IIrk8lH, VOf(Bf3));
    __hv_varread_f(&sVarf_lVKP3cbj, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_VHBfW4AP, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_ZjyvyVY3, VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_NlYSr6l6, VOf(Bf0));
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
    __hv_line_f(&sLine_pmYKKTqj, VOf(Bf2));
    __hv_tabread_f(&sTabread_Kjfh628Y, VOf(Bf2));
    __hv_varread_f(&sVarf_8RUx8Bd6, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_lSbAOmrg, VOf(Bf2));
    __hv_rpole_f(&sRPole_Gg6je7Bc, VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_gZTQ3djx, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_mkFuhsgQ, VOf(Bf2));
    __hv_varread_i(&sVari_oTtvC7BD, VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_cast_if(VIi(Bi0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf6), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_varwrite_i(&sVari_oTtvC7BD, VIi(Bi0));
    __hv_fma_f(VIf(Bf2), VIf(Bf6), VIf(Bf5), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_2V2BIoAi, VIf(Bf6));
    __hv_line_f(&sLine_VS2mA4YT, VOf(Bf6));
    __hv_varread_f(&sVarf_gWCQCHXY, VOf(Bf2));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_fdPKu1sh, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_R1nVLPdz, VOf(Bf6));
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_phasor_k_f(&sPhasor_VjKLOCtv, VOf(Bf2));
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
    __hv_line_f(&sLine_WxJtWyuZ, VOf(Bf0));
    __hv_add_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_tabread_f(&sTabread_qQIVIWrm, VOf(Bf1));
    __hv_varread_f(&sVarf_ncsts9O1, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_LpPyEMvp, VOf(Bf1));
    __hv_rpole_f(&sRPole_M3SExIU8, VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_w5PuOACo, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_1tzHbdLI, VOf(Bf1));
    __hv_varread_i(&sVari_ikRTBjKN, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf7));
    __hv_var_k_f(VOf(Bf2), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_varwrite_i(&sVari_ikRTBjKN, VIi(Bi1));
    __hv_fma_f(VIf(Bf1), VIf(Bf2), VIf(Bf0), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_T5eZQDmB, VIf(Bf2));
    __hv_line_f(&sLine_WyjyMzUx, VOf(Bf2));
    __hv_varread_f(&sVarf_jYXNZU9t, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_qoFQk9Jd, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_VxaDnpNz, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_UlKuPlOy, VOf(Bf1));
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
    __hv_line_f(&sLine_4dIOp7T2, VOf(Bf7));
    __hv_add_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_tabread_f(&sTabread_3bM6auom, VOf(Bf5));
    __hv_varread_f(&sVarf_2jUZNcBL, VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_i3WZOCxM, VOf(Bf5));
    __hv_rpole_f(&sRPole_FoMmBXiN, VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_FDvLCmUs, VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_dL33Nybz, VOf(Bf5));
    __hv_varread_i(&sVari_uMgsv9Dq, VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_cast_if(VIi(Bi0), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_i(&sVari_uMgsv9Dq, VIi(Bi0));
    __hv_fma_f(VIf(Bf5), VIf(Bf1), VIf(Bf7), VOf(Bf1));
    __hv_tabwrite_f(&sTabwrite_wmtdAQf5, VIf(Bf1));
    __hv_line_f(&sLine_DSKpEbr9, VOf(Bf1));
    __hv_varread_f(&sVarf_DvW9787N, VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_aInKJIke, VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_wM9hMYAQ, VOf(Bf1));
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_L14MNyBC, VOf(Bf5));
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
    __hv_line_f(&sLine_hVhjyV3v, VOf(Bf4));
    __hv_add_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_zYCBhSzM, VOf(Bf2));
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf7));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_tabread_f(&sTabread_HDwvRVpY, VOf(Bf1));
    __hv_varread_f(&sVarf_1umjGuSQ, VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_IaFSZ6XV, VOf(Bf1));
    __hv_rpole_f(&sRPole_D3MD5a4Q, VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_THiWq8rS, VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_5roWFc9V, VOf(Bf1));
    __hv_varread_i(&sVari_imSFUkZK, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varwrite_i(&sVari_imSFUkZK, VIi(Bi1));
    __hv_fma_f(VIf(Bf1), VIf(Bf0), VIf(Bf6), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_zwygWby1, VIf(Bf0));
    __hv_line_f(&sLine_Y6DRCJ34, VOf(Bf0));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_K8cYsBc9, VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_gCaZXOIc, VOf(Bf0));
    __hv_rpole_f(&sRPole_fCSILDJM, VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_CT7N50Ur, VIf(Bf0), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_HoxPe96z, VOf(Bf0));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_nv8148p4, VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf7), VIf(Bf6), VOf(Bf7));
    __hv_add_f(VIf(Bf2), VIf(Bf6), VOf(Bf0));
    __hv_line_f(&sLine_0wjPaWHA, VOf(Bf1));
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf7));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_YXSnrxI5, VOf(Bf2));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_tabread_f(&sTabread_x9m4h6ZG, VOf(Bf6));
    __hv_varread_f(&sVarf_9N99uJQo, VOf(Bf0));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_8PIcDixP, VOf(Bf3));
    __hv_rpole_f(&sRPole_aFxXMpGj, VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf3), VIf(Bf6), VOf(Bf3));
    __hv_line_f(&sLine_cdJCmkYF, VOf(Bf0));
    __hv_fma_f(VIf(Bf3), VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_5UP2AEDg, VOf(Bf3));
    __hv_tabread_f(&sTabread_vnSavNzS, VOf(Bf4));
    __hv_add_f(VIf(Bf2), VIf(Bf4), VOf(Bf8));
    __hv_tabread_f(&sTabread_7HAQFNy7, VOf(Bf5));
    __hv_add_f(VIf(Bf8), VIf(Bf5), VOf(Bf10));
    __hv_tabread_f(&sTabread_ADJ4E8Aa, VOf(Bf9));
    __hv_add_f(VIf(Bf10), VIf(Bf9), VOf(Bf11));
    __hv_tabread_f(&sTabread_z6exZkKw, VOf(Bf12));
    __hv_add_f(VIf(Bf11), VIf(Bf12), VOf(Bf13));
    __hv_tabread_f(&sTabread_ewlwumIS, VOf(Bf14));
    __hv_sub_f(VIf(Bf13), VIf(Bf14), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_SJUWITpc, VIf(Bf15));
    __hv_sub_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_cgdHBny3, VIf(Bf12));
    __hv_sub_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_Ly4JY4Uz, VIf(Bf9));
    __hv_sub_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_3K4y4xq5, VIf(Bf5));
    __hv_sub_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_lhnEtGVC, VIf(Bf4));
    __hv_tabwrite_f(&sTabwrite_qTcizVOy, VIf(Bf2));
    __hv_add_f(VIf(Bf13), VIf(Bf14), VOf(Bf14));
    __hv_tabread_f(&sTabread_kg18CcEz, VOf(Bf13));
    __hv_fma_f(VIf(Bf6), VIf(Bf3), VIf(Bf14), VOf(Bf14));
    __hv_tabread_f(&sTabread_dtVPkZAP, VOf(Bf6));
    __hv_varread_f(&sVarf_a4pJ4tBl, VOf(Bf4));
    __hv_mul_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_brQlZRWU, VOf(Bf5));
    __hv_rpole_f(&sRPole_okwJBq88, VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf5));
    __hv_fma_f(VIf(Bf5), VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf6), VIf(Bf3), VIf(Bf13), VOf(Bf13));
    __hv_add_f(VIf(Bf14), VIf(Bf13), VOf(Bf6));
    __hv_tabread_f(&sTabread_PZfknumT, VOf(Bf5));
    __hv_varread_f(&sVarf_mcHitFHU, VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_Jlo5XtCL, VOf(Bf8));
    __hv_rpole_f(&sRPole_K4FwHGiP, VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf8), VIf(Bf5), VOf(Bf8));
    __hv_fma_f(VIf(Bf8), VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf5));
    __hv_tabread_f(&sTabread_Ir64mdiY, VOf(Bf8));
    __hv_varread_f(&sVarf_EhS0NGur, VOf(Bf4));
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_RKOEHNn6, VOf(Bf9));
    __hv_rpole_f(&sRPole_ELI6Lo8B, VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf9), VIf(Bf8), VOf(Bf9));
    __hv_fma_f(VIf(Bf9), VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf5), VIf(Bf3), VOf(Bf8));
    __hv_add_f(VIf(Bf6), VIf(Bf8), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_yOCoPsi8, VIf(Bf0));
    __hv_sub_f(VIf(Bf14), VIf(Bf13), VOf(Bf0));
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf9));
    __hv_add_f(VIf(Bf0), VIf(Bf9), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_EFIjaKYf, VIf(Bf4));
    __hv_sub_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_tabwrite_f(&sTabwrite_zrqCHOpG, VIf(Bf8));
    __hv_sub_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_P1eCsL7Y, VIf(Bf9));
    __hv_line_f(&sLine_tQYMYoyu, VOf(Bf9));
    __hv_mul_f(VIf(Bf14), VIf(Bf9), VOf(Bf14));
    __hv_mul_f(VIf(Bf13), VIf(Bf9), VOf(Bf13));
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_vDMXpyZL, VOf(Bf9));
    __hv_mul_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf5), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_l2RShlhk, VIf(Bf5));
    __hv_line_f(&sLine_q51XVYIe, VOf(Bf9));
    __hv_phasor_f(&sPhasor_O5xBFFkj, VIf(Bf9), VOf(Bf9));
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
    __hv_line_f(&sLine_VtQlkvAg, VOf(Bf10));
    __hv_line_f(&sLine_bhZshD8N, VOf(Bf3));
    __hv_fma_f(VIf(Bf9), VIf(Bf10), VIf(Bf3), VOf(Bf11));
    __hv_tabhead_f(&sTabhead_nxQIOlhB, VOf(Bf4));
    __hv_var_k_f_r(VOf(Bf6), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_cT3Kw7cW, VOf(Bf4));
    __hv_mul_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_em0hUoV4, VOf(Bf11));
    __hv_min_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_zero_f(VOf(Bf4));
    __hv_max_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf6));
    __hv_varread_f(&sVarf_FQCx2ezb, VOf(Bf11));
    __hv_zero_f(VOf(Bf0));
    __hv_lt_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_and_f(VIf(Bf11), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_cast_fi(VIf(Bf0), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_nXMVYqam, VIi(Bi0), VOf(Bf0));
    __hv_tabread_if(&sTabread_dhFQspfN, VIi(Bi1), VOf(Bf11));
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
    __hv_tabhead_f(&sTabhead_yVOVKgFw, VOf(Bf10));
    __hv_var_k_f_r(VOf(Bf9), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_LAWICRd4, VOf(Bf10));
    __hv_mul_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_d1IbXx7G, VOf(Bf3));
    __hv_min_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf10));
    __hv_max_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf9));
    __hv_varread_f(&sVarf_EOhHSEso, VOf(Bf3));
    __hv_zero_f(VOf(Bf16));
    __hv_lt_f(VIf(Bf9), VIf(Bf16), VOf(Bf16));
    __hv_and_f(VIf(Bf3), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf9), VIf(Bf16), VOf(Bf16));
    __hv_cast_fi(VIf(Bf16), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_WhmpX0JY, VIi(Bi0), VOf(Bf16));
    __hv_tabread_if(&sTabread_RcoxPOyx, VIi(Bi1), VOf(Bf3));
    __hv_sub_f(VIf(Bf16), VIf(Bf3), VOf(Bf16));
    __hv_sub_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf16), VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf12), VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_A6DNjj7z, VOf(Bf11));
    __hv_tabhead_f(&sTabhead_tv6KhYZr, VOf(Bf12));
    __hv_var_k_f_r(VOf(Bf17), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_STzbPVCH, VOf(Bf12));
    __hv_mul_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_YgAVwZmN, VOf(Bf11));
    __hv_min_f(VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_zero_f(VOf(Bf12));
    __hv_max_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf17), VIf(Bf12), VOf(Bf12));
    __hv_floor_f(VIf(Bf12), VOf(Bf17));
    __hv_varread_f(&sVarf_Cmbj3Yxq, VOf(Bf11));
    __hv_zero_f(VOf(Bf9));
    __hv_lt_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_and_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_cast_fi(VIf(Bf9), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_sVLNPpbo, VIi(Bi0), VOf(Bf9));
    __hv_tabread_if(&sTabread_mxYI7Bwi, VIi(Bi1), VOf(Bf11));
    __hv_sub_f(VIf(Bf9), VIf(Bf11), VOf(Bf9));
    __hv_sub_f(VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf9), VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_EWOZELwx, VOf(Bf17));
    __hv_rpole_f(&sRPole_X0gd5Ajk, VIf(Bf11), VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf11), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_rANjZi1C, VIf(Bf17), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_0KVveVQ4, VOf(Bf17));
    __hv_mul_f(VIf(Bf11), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_NHEAesR6, VOf(Bf11));
    __hv_mul_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf3), VIf(Bf11), VOf(Bf17));
    __hv_line_f(&sLine_PFx9aq9R, VOf(Bf9));
    __hv_varread_f(&sVarf_uIu0dZQc, VOf(Bf12));
    __hv_mul_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_ku1pjJYS, VOf(Bf11));
    __hv_rpole_f(&sRPole_zbaAkQ0T, VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf3), VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_tabwrite_f(&sTabwrite_RZS08580, VIf(Bf11));
    __hv_add_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_2M97mHRR, VOf(Bf17));
    __hv_varread_f(&sVarf_vx7ryrAT, VOf(Bf11));
    __hv_mul_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf17), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf11), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_2kyiKVyj, VOf(Bf11));
    __hv_min_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_UIee5DUI, VOf(Bf9));
    __hv_mul_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf5));
    __hv_varread_f(&sVarf_KRgqb7cJ, VOf(Bf11));
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
    __hv_cpole_f(&sCPole_XuStt4Ms, VIf(Bf11), VIf(ZERO), VIf(Bf3), VIf(Bf17), VOf(Bf17), VOf(Bf3));
    __hv_varread_f(&sVarf_HweexQ0D, VOf(Bf3));
    __hv_mul_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_vHaM0Yj2, VOf(Bf17));
    __hv_rpole_f(&sRPole_JcrsE2nf, VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_o0WZYLOy, VOf(Bf3));
    __hv_mul_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_dfZuOA8O, VOf(Bf17));
    __hv_rpole_f(&sRPole_zNTtIrtc, VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_pG2pWCWO, VOf(Bf3));
    __hv_mul_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_WFEO5EsB, VOf(Bf17));
    __hv_rpole_f(&sRPole_dRdrEHnN, VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_tabread_f(&sTabread_2mcQ7TTy, VOf(Bf3));
    __hv_varread_f(&sVarf_Y8EXrTFK, VOf(Bf11));
    __hv_mul_f(VIf(Bf3), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_EOa1DYUM, VOf(Bf9));
    __hv_rpole_f(&sRPole_fOkSROBP, VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf9), VIf(Bf3), VOf(Bf9));
    __hv_line_f(&sLine_rUnCkvbJ, VOf(Bf11));
    __hv_fma_f(VIf(Bf9), VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_OZl8cLDT, VOf(Bf9));
    __hv_tabread_f(&sTabread_r3wDWdW9, VOf(Bf5));
    __hv_add_f(VIf(Bf17), VIf(Bf5), VOf(Bf12));
    __hv_tabread_f(&sTabread_kRpTNi7r, VOf(Bf16));
    __hv_add_f(VIf(Bf12), VIf(Bf16), VOf(Bf10));
    __hv_tabread_f(&sTabread_f9PfGxJH, VOf(Bf6));
    __hv_add_f(VIf(Bf10), VIf(Bf6), VOf(Bf18));
    __hv_tabread_f(&sTabread_mbL6YwyO, VOf(Bf15));
    __hv_add_f(VIf(Bf18), VIf(Bf15), VOf(Bf8));
    __hv_tabread_f(&sTabread_h2YIJv5g, VOf(Bf0));
    __hv_sub_f(VIf(Bf8), VIf(Bf0), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_1cB7ngHC, VIf(Bf4));
    __hv_sub_f(VIf(Bf18), VIf(Bf15), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_jspvYLv4, VIf(Bf15));
    __hv_sub_f(VIf(Bf10), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_HY2K3S61, VIf(Bf6));
    __hv_sub_f(VIf(Bf12), VIf(Bf16), VOf(Bf16));
    __hv_tabwrite_f(&sTabwrite_oPvrzAUY, VIf(Bf16));
    __hv_sub_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_ckH1H8Yl, VIf(Bf5));
    __hv_tabwrite_f(&sTabwrite_Afuitgor, VIf(Bf17));
    __hv_add_f(VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_tabread_f(&sTabread_qoY8korK, VOf(Bf8));
    __hv_fma_f(VIf(Bf3), VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_tabread_f(&sTabread_witvQ5Vz, VOf(Bf3));
    __hv_varread_f(&sVarf_kRTIIinM, VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_Fr8eI7SJ, VOf(Bf16));
    __hv_rpole_f(&sRPole_D6Y98iGq, VIf(Bf5), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf16), VIf(Bf3), VOf(Bf16));
    __hv_fma_f(VIf(Bf16), VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf3), VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf0), VIf(Bf8), VOf(Bf3));
    __hv_tabread_f(&sTabread_yY6X7Nds, VOf(Bf16));
    __hv_varread_f(&sVarf_VEu7WKRh, VOf(Bf5));
    __hv_mul_f(VIf(Bf16), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_4Lucl2o7, VOf(Bf12));
    __hv_rpole_f(&sRPole_drHo05RK, VIf(Bf5), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf12), VIf(Bf16), VOf(Bf12));
    __hv_fma_f(VIf(Bf12), VIf(Bf11), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf9), VOf(Bf16));
    __hv_tabread_f(&sTabread_nCJgAvj8, VOf(Bf12));
    __hv_varread_f(&sVarf_4JUn7Iix, VOf(Bf5));
    __hv_mul_f(VIf(Bf12), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_UJWln8Ax, VOf(Bf6));
    __hv_rpole_f(&sRPole_ZVLdtxK6, VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf6), VIf(Bf12), VOf(Bf6));
    __hv_fma_f(VIf(Bf6), VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf16), VIf(Bf9), VOf(Bf12));
    __hv_add_f(VIf(Bf3), VIf(Bf12), VOf(Bf11));
    __hv_tabwrite_f(&sTabwrite_6Rg202Ze, VIf(Bf11));
    __hv_sub_f(VIf(Bf0), VIf(Bf8), VOf(Bf11));
    __hv_sub_f(VIf(Bf16), VIf(Bf9), VOf(Bf6));
    __hv_add_f(VIf(Bf11), VIf(Bf6), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_jntCVGRQ, VIf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_NJk4KNph, VIf(Bf12));
    __hv_sub_f(VIf(Bf11), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_vzaHST7l, VIf(Bf6));
    __hv_line_f(&sLine_oRjRJtGh, VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf0));
    __hv_mul_f(VIf(Bf8), VIf(Bf6), VOf(Bf8));
    __hv_mul_f(VIf(Bf16), VIf(Bf6), VOf(Bf16));
    __hv_mul_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf17), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf14), VIf(Bf17), VOf(Bf14));
    __hv_line_f(&sLine_WPYgXQjR, VOf(Bf0));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_tlRwJRhq, VIf(Bf0));
    __hv_line_f(&sLine_zfeQ5o9Q, VOf(Bf0));
    __hv_phasor_f(&sPhasor_oINwRhPc, VIf(Bf0), VOf(Bf0));
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
    __hv_line_f(&sLine_Es9kD62b, VOf(Bf11));
    __hv_line_f(&sLine_wwF3p7q5, VOf(Bf2));
    __hv_fma_f(VIf(Bf0), VIf(Bf11), VIf(Bf2), VOf(Bf3));
    __hv_tabhead_f(&sTabhead_6iJth3kh, VOf(Bf9));
    __hv_var_k_f_r(VOf(Bf8), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_J3VvS4yU, VOf(Bf9));
    __hv_mul_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_zZanAN94, VOf(Bf3));
    __hv_min_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf9));
    __hv_max_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf9), VOf(Bf8));
    __hv_varread_f(&sVarf_8SWCOGJz, VOf(Bf3));
    __hv_zero_f(VOf(Bf6));
    __hv_lt_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_and_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_cast_fi(VIf(Bf6), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_nqBH7E5Q, VIi(Bi0), VOf(Bf6));
    __hv_tabread_if(&sTabread_fSKrVupi, VIi(Bi1), VOf(Bf3));
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
    __hv_tabhead_f(&sTabhead_xGJFmdmX, VOf(Bf11));
    __hv_var_k_f_r(VOf(Bf0), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf11), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_Aw8vxnnU, VOf(Bf11));
    __hv_mul_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_RCPs6bHG, VOf(Bf2));
    __hv_min_f(VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf11));
    __hv_max_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf0), VIf(Bf11), VOf(Bf11));
    __hv_floor_f(VIf(Bf11), VOf(Bf0));
    __hv_varread_f(&sVarf_IwXDkzAY, VOf(Bf2));
    __hv_zero_f(VOf(Bf10));
    __hv_lt_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_and_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_FH604BU4, VIi(Bi0), VOf(Bf10));
    __hv_tabread_if(&sTabread_Mi6vPf3w, VIi(Bi1), VOf(Bf2));
    __hv_sub_f(VIf(Bf10), VIf(Bf2), VOf(Bf10));
    __hv_sub_f(VIf(Bf11), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf10), VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf15), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf12), VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_1fIo3oEh, VOf(Bf3));
    __hv_tabhead_f(&sTabhead_263RXy5i, VOf(Bf12));
    __hv_var_k_f_r(VOf(Bf15), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_p3eDQAFy, VOf(Bf12));
    __hv_mul_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_MI6OJ1LF, VOf(Bf3));
    __hv_min_f(VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf12));
    __hv_max_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf15), VIf(Bf12), VOf(Bf12));
    __hv_floor_f(VIf(Bf12), VOf(Bf15));
    __hv_varread_f(&sVarf_c9ypxp2y, VOf(Bf3));
    __hv_zero_f(VOf(Bf0));
    __hv_lt_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_and_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_cast_fi(VIf(Bf0), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_pTPL9qBY, VIi(Bi0), VOf(Bf0));
    __hv_tabread_if(&sTabread_0MCC57Bx, VIi(Bi1), VOf(Bf3));
    __hv_sub_f(VIf(Bf0), VIf(Bf3), VOf(Bf0));
    __hv_sub_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf0), VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_A5pVkXMo, VOf(Bf15));
    __hv_rpole_f(&sRPole_dQLNvxbv, VIf(Bf3), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_RnwQbFMY, VIf(Bf15), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_HNx8Qzxt, VOf(Bf15));
    __hv_mul_f(VIf(Bf3), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_63gqenBH, VOf(Bf3));
    __hv_mul_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf15));
    __hv_line_f(&sLine_fRnLX3Ss, VOf(Bf0));
    __hv_varread_f(&sVarf_ThZXZHAT, VOf(Bf12));
    __hv_mul_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_QsyUIIvc, VOf(Bf3));
    __hv_rpole_f(&sRPole_KeoQMUG9, VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf2), VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_esRKSqBh, VIf(Bf3));
    __hv_var_k_f(VOf(Bf3), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf14), VIf(Bf3), VOf(Bf14));
    __hv_add_f(VIf(Bf13), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_JQQA3LuM, VOf(Bf17));
    __hv_mul_f(VIf(Bf14), VIf(Bf17), VOf(Bf14));
    __hv_mul_f(VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf7), VIf(Bf14), VOf(Bf14));
    __hv_add_f(VIf(Bf1), VIf(Bf17), VOf(Bf17));
    __hv_line_f(&sLine_OLt1EviP, VOf(Bf1));
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

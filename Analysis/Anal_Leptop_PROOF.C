#define Anal_Leptop_PROOF_cxx
// The class definition in Anal_Leptop_PROOF.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// Root > T->Process("Anal_Leptop_PROOF.C")
// Root > T->Process("Anal_Leptop_PROOF.C","some options")
// Root > T->Process("Anal_Leptop_PROOF.C+")
//

#include "Anal_Leptop_PROOF.h"
#include <TH2.h>
#include <TStyle.h>

#define TRAINING

void Anal_Leptop_PROOF::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void Anal_Leptop_PROOF::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

  TString option = GetOption();
   
   OutFile = new TProofOutputFile("Output.root");
 // fOutput->Add(OutFile);

   fileOut = OutFile->OpenFile("RECREATE");

   if ( !(fileOut = OutFile->OpenFile("RECREATE")) )
   {
	  Warning("SlaveBegin", "problems opening file: %s/%s",
      OutFile->GetDir(), OutFile->GetFileName());
   }
   
  isMC = true;
  
  Tout = new TTree("leptop","leptop");
   
  Tout->Branch("event_pt_weight",&event_pt_weight,"event_pt_weight/F");
  Tout->Branch("weight",&weight,"weight/F");
   /*
  Tout->Branch("selpfjetAK8pt",selpfjetAK8pt,"selpfjetAK8pt[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8y",selpfjetAK8y,"selpfjetAK8y[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8phi",selpfjetAK8phi,"selpfjetAK8phi[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8mass",selpfjetAK8mass,"selpfjetAK8mass[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8btag_CMVA",selpfjetAK8btag_CMVA,"selpfjetAK8btag_CMVA[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8btag_CSV",selpfjetAK8btag_CSV,"selpfjetAK8btag_CSV[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8btag_DeepCSV",selpfjetAK8btag_DeepCSV,"selpfjetAK8btag_DeepCSV[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8matchAK4deepb",selpfjetAK8matchAK4deepb,"selpfjetAK8matchAK4deepb[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8DeepTag_TvsQCD",selpfjetAK8DeepTag_TvsQCD,"selpfjetAK8DeepTag_TvsQCD[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8DeepTag_WvsQCD",selpfjetAK8DeepTag_WvsQCD,"selpfjetAK8DeepTag_WvsQCD[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8DeepTag_ZvsQCD",selpfjetAK8DeepTag_ZvsQCD,"selpfjetAK8DeepTag_ZvsQCD[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8CHF",selpfjetAK8CHF,"selpfjetAK8CHF[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8NHF",selpfjetAK8NHF,"selpfjetAK8NHF[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8CEMF",selpfjetAK8CEMF,"selpfjetAK8CEMF[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8NEMF",selpfjetAK8NEMF,"selpfjetAK8NEMF[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8MUF",selpfjetAK8MUF,"selpfjetAK8MUF[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8HOF",selpfjetAK8HOF,"selpfjetAK8HOF[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8HadF",selpfjetAK8HadF,"selpfjetAK8HadF[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8NHadF",selpfjetAK8NHadF,"selpfjetAK8NHadF[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8EmF",selpfjetAK8EmF,"selpfjetAK8EmF[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8neuemfrac",selpfjetAK8neuemfrac,"selpfjetAK8neuemfrac[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8CHM",selpfjetAK8CHM,"selpfjetAK8CHM[npfjetAK8]/I");
  Tout->Branch("selpfjetAK8NHM",selpfjetAK8NHM,"selpfjetAK8NHM[npfjetAK8]/I");
  Tout->Branch("selpfjetAK8CEMM",selpfjetAK8CEMM,"selpfjetAK8CEMM[npfjetAK8]/I");
  Tout->Branch("selpfjetAK8NEMM",selpfjetAK8NEMM,"selpfjetAK8NEMM[npfjetAK8]/I");
  Tout->Branch("selpfjetAK8MUM",selpfjetAK8MUM,"selpfjetAK8MUM[npfjetAK8]/I");
  Tout->Branch("selpfjetAK8Neucons",selpfjetAK8Neucons,"selpfjetAK8Neucons[npfjetAK8]/I");
  Tout->Branch("selpfjetAK8Chcons",selpfjetAK8Chcons,"selpfjetAK8Chcons[npfjetAK8]/I");
  
  Tout->Branch("selpfjetAK8chrad",selpfjetAK8chrad,"selpfjetAK8chrad[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8pTD",selpfjetAK8pTD,"selpfjetAK8pTD[npfjetAK8]/F");
  
  Tout->Branch("selpfjetAK8sdmass",selpfjetAK8sdmass,"selpfjetAK8sdmass[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8tau21",selpfjetAK8tau21,"selpfjetAK8tau21[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8tau32",selpfjetAK8tau32,"selpfjetAK8tau32[npfjetAK8]/F");
  
  Tout->Branch("selpfjetAK8sub1mass",selpfjetAK8sub1mass,"selpfjetAK8sub1mass[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8sub1btag",selpfjetAK8sub1btag,"selpfjetAK8sub1btag[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8sub1hadfrac",selpfjetAK8sub1hadfrac,"selpfjetAK8sub1hadfrac[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8sub1emfrac",selpfjetAK8sub1emfrac,"selpfjetAK8sub1emfrac[npfjetAK8]/F");
  
  Tout->Branch("selpfjetAK8sub2mass",selpfjetAK8sub2mass,"selpfjetAK8sub2mass[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8sub2btag",selpfjetAK8sub2btag,"selpfjetAK8sub2btag[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8sub2hadfrac",selpfjetAK8sub2hadfrac,"selpfjetAK8sub2hadfrac[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8sub2emfrac",selpfjetAK8sub2emfrac,"selpfjetAK8sub2emfrac[npfjetAK8]/F");
  
  Tout->Branch("selpfjetAK8subhaddiff",selpfjetAK8subhaddiff,"selpfjetAK8subhaddiff[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8subemdiff",selpfjetAK8subemdiff,"selpfjetAK8subemdiff[npfjetAK8]/F");
  Tout->Branch("selpfjetAK8subptdiff",selpfjetAK8subptdiff,"selpfjetAK8subptdiff[npfjetAK8]/F");
  */
  
  #ifdef TRAINING
  
  Tout1 = new TTree("leptop_e","leptop_e");
   
  Tout1->Branch("event_pt_weight",&event_pt_weight,"event_pt_weight/F");
  Tout1->Branch("weight",&weight,"weight/F");
  
  Tout1->Branch("DiLeptt",&DiLeptt,"DiLeptt/O");
  Tout1->Branch("SemiLeptt",&SemiLeptt,"SemiLeptt/O");
  Tout1->Branch("Hadtt",&Hadtt,"Hadtt/O");
  
  Tout1->Branch("npfjetAK8_te",&npfjetAK8_te, "npfjetAK8_te/I");  
  Tout1->Branch("selpfjetAK8pt",selpfjetAK8pt,"selpfjetAK8pt[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8y",selpfjetAK8y,"selpfjetAK8y[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8phi",selpfjetAK8phi,"selpfjetAK8phi[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8mass",selpfjetAK8mass,"selpfjetAK8mass[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8btag_CMVA",selpfjetAK8btag_CMVA,"selpfjetAK8btag_CMVA[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8btag_CSV",selpfjetAK8btag_CSV,"selpfjetAK8btag_CSV[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8btag_DeepCSV",selpfjetAK8btag_DeepCSV,"selpfjetAK8btag_DeepCSV[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchAK4deepb",selpfjetAK8matchAK4deepb,"selpfjetAK8matchAK4deepb[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8matchAK4deepCSVb",selpfjetAK8matchAK4deepCSVb,"selpfjetAK8matchAK4deepCSVb[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8DeepTag_TvsQCD",selpfjetAK8DeepTag_TvsQCD,"selpfjetAK8DeepTag_TvsQCD[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8DeepTag_WvsQCD",selpfjetAK8DeepTag_WvsQCD,"selpfjetAK8DeepTag_WvsQCD[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8DeepTag_ZvsQCD",selpfjetAK8DeepTag_ZvsQCD,"selpfjetAK8DeepTag_ZvsQCD[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8CHF",selpfjetAK8CHF,"selpfjetAK8CHF[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8NHF",selpfjetAK8NHF,"selpfjetAK8NHF[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8CEMF",selpfjetAK8CEMF,"selpfjetAK8CEMF[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8NEMF",selpfjetAK8NEMF,"selpfjetAK8NEMF[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8MUF",selpfjetAK8MUF,"selpfjetAK8MUF[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8HOF",selpfjetAK8HOF,"selpfjetAK8HOF[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8HadF",selpfjetAK8HadF,"selpfjetAK8HadF[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8NHadF",selpfjetAK8NHadF,"selpfjetAK8NHadF[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8EmF",selpfjetAK8EmF,"selpfjetAK8EmF[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8neuemfrac",selpfjetAK8neuemfrac,"selpfjetAK8neuemfrac[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8neunhadfrac",selpfjetAK8neunhadfrac,"selpfjetAK8neunhadfrac[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8CHM",selpfjetAK8CHM,"selpfjetAK8CHM[npfjetAK8_te]/I");
  Tout1->Branch("selpfjetAK8NHM",selpfjetAK8NHM,"selpfjetAK8NHM[npfjetAK8_te]/I");
  Tout1->Branch("selpfjetAK8CEMM",selpfjetAK8CEMM,"selpfjetAK8CEMM[npfjetAK8_te]/I");
  Tout1->Branch("selpfjetAK8NEMM",selpfjetAK8NEMM,"selpfjetAK8NEMM[npfjetAK8_te]/I");
  Tout1->Branch("selpfjetAK8EEM",selpfjetAK8EEM,"selpfjetAK8EEM[npfjetAK8_te]/I");
  Tout1->Branch("selpfjetAK8MUM",selpfjetAK8MUM,"selpfjetAK8MUM[npfjetAK8_te]/I");
  Tout1->Branch("selpfjetAK8Neucons",selpfjetAK8Neucons,"selpfjetAK8Neucons[npfjetAK8_te]/I");
  Tout1->Branch("selpfjetAK8Chcons",selpfjetAK8Chcons,"selpfjetAK8Chcons[npfjetAK8_te]/I");
  
  Tout1->Branch("selpfjetAK8chrad",selpfjetAK8chrad,"selpfjetAK8chrad[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8pTD",selpfjetAK8pTD,"selpfjetAK8pTD[npfjetAK8_te]/F");
  
  Tout1->Branch("selpfjetAK8sdmass",selpfjetAK8sdmass,"selpfjetAK8sdmass[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8tau21",selpfjetAK8tau21,"selpfjetAK8tau21[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8tau32",selpfjetAK8tau32,"selpfjetAK8tau32[npfjetAK8_te]/F");
  
  Tout1->Branch("selpfjetAK8sub1mass",selpfjetAK8sub1mass,"selpfjetAK8sub1mass[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8sub1btag",selpfjetAK8sub1btag,"selpfjetAK8sub1btag[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8sub1hadfrac",selpfjetAK8sub1hadfrac,"selpfjetAK8sub1hadfrac[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8sub1emfrac",selpfjetAK8sub1emfrac,"selpfjetAK8sub1emfrac[npfjetAK8_te]/F");
  
  Tout1->Branch("selpfjetAK8sub2mass",selpfjetAK8sub2mass,"selpfjetAK8sub2mass[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8sub2btag",selpfjetAK8sub2btag,"selpfjetAK8sub2btag[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8sub2hadfrac",selpfjetAK8sub2hadfrac,"selpfjetAK8sub2hadfrac[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8sub2emfrac",selpfjetAK8sub2emfrac,"selpfjetAK8sub2emfrac[npfjetAK8_te]/F");
  
  Tout1->Branch("selpfjetAK8subbtag", pfjetAK8subbtag,"selpfjetAK8subbtag[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8subhaddiff",selpfjetAK8subhaddiff,"selpfjetAK8subhaddiff[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8subemdiff",selpfjetAK8subemdiff,"selpfjetAK8subemdiff[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8subptdiff",selpfjetAK8subptdiff,"selpfjetAK8subptdiff[npfjetAK8_te]/F");
  
  Tout1->Branch("selpfjetAK8_bbyW_E", selpfjetAK8_bbyW_E,"selpfjetAK8_bbyW_E[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8_Kfactor", selpfjetAK8_Kfactor,"selpfjetAK8_Kfactor[npfjetAK8_te]/F");
  Tout1->Branch("selpfjetAK8_Rnew", selpfjetAK8_Rnew,"selpfjetAK8_Rnew[npfjetAK8_te]/F");
  
  Tout1->Branch("selpfjetAK8haselectron",selpfjetAK8haselectron,"selpfjetAK8haselectron[npfjetAK8_te]/O");
  Tout1->Branch("selpfjetAK8hasmuon",selpfjetAK8hasmuon,"selpfjetAK8hasmuon[npfjetAK8_te]/O");
  Tout1->Branch("selpfjetAK8hasb",selpfjetAK8hasb,"selpfjetAK8hasb[npfjetAK8_te]/O");
  Tout1->Branch("selpfjetAK8hasqg",selpfjetAK8hasqg,"selpfjetAK8hasqg[npfjetAK8_te]/O");
  Tout1->Branch("selpfjetAK8hashadtop",selpfjetAK8hashadtop,"selpfjetAK8hashadtop[npfjetAK8_te]/O");
  Tout1->Branch("selpfjetAK8hasleptop",selpfjetAK8hasleptop,"selpfjetAK8hasleptop[npfjetAK8_te]/O");
  Tout1->Branch("selpfjetAK8hastop",selpfjetAK8hastop,"selpfjetAK8hastop[npfjetAK8_te]/O");
  
  #endif
  
  #ifdef All_Trees
  
  Tout1->Branch("selpfjetAK8hashadtop_alldecay",selpfjetAK8hashadtop_alldecay,"selpfjetAK8hashadtop_alldecay[npfjetAK8_te]/O");
  Tout1->Branch("selpfjetAK8hasleptop_alldecay",selpfjetAK8hasleptop_alldecay,"selpfjetAK8hasleptop_alldecay[npfjetAK8_te]/O");
  
  Tout2 = new TTree("leptop_mu","leptop_mu");
   
  Tout2->Branch("event_pt_weight",&event_pt_weight,"event_pt_weight/F");
  Tout2->Branch("weight",&weight,"weight/F");
  
  Tout2->Branch("DiLeptt",&DiLeptt,"DiLeptt/O");
  Tout2->Branch("SemiLeptt",&SemiLeptt,"SemiLeptt/O");
  Tout2->Branch("Hadtt",&Hadtt,"Hadtt/O");
   
  Tout2->Branch("npfjetAK8_tmu",&npfjetAK8_tmu, "npfjetAK8_tmu/I");  
  Tout2->Branch("selpfjetAK8pt",selpfjetAK8pt,"selpfjetAK8pt[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8y",selpfjetAK8y,"selpfjetAK8y[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8phi",selpfjetAK8phi,"selpfjetAK8phi[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8mass",selpfjetAK8mass,"selpfjetAK8mass[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8btag_CMVA",selpfjetAK8btag_CMVA,"selpfjetAK8btag_CMVA[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8btag_CSV",selpfjetAK8btag_CSV,"selpfjetAK8btag_CSV[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8btag_DeepCSV",selpfjetAK8btag_DeepCSV,"selpfjetAK8btag_DeepCSV[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchAK4deepb",selpfjetAK8matchAK4deepb,"selpfjetAK8matchAK4deepb[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8matchAK4deepCSVb",selpfjetAK8matchAK4deepCSVb,"selpfjetAK8matchAK4deepCSVb[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8DeepTag_TvsQCD",selpfjetAK8DeepTag_TvsQCD,"selpfjetAK8DeepTag_TvsQCD[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8DeepTag_WvsQCD",selpfjetAK8DeepTag_WvsQCD,"selpfjetAK8DeepTag_WvsQCD[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8DeepTag_ZvsQCD",selpfjetAK8DeepTag_ZvsQCD,"selpfjetAK8DeepTag_ZvsQCD[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8CHF",selpfjetAK8CHF,"selpfjetAK8CHF[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8NHF",selpfjetAK8NHF,"selpfjetAK8NHF[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8CEMF",selpfjetAK8CEMF,"selpfjetAK8CEMF[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8NEMF",selpfjetAK8NEMF,"selpfjetAK8NEMF[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8MUF",selpfjetAK8MUF,"selpfjetAK8MUF[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8HOF",selpfjetAK8HOF,"selpfjetAK8HOF[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8HadF",selpfjetAK8HadF,"selpfjetAK8HadF[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8NHadF",selpfjetAK8NHadF,"selpfjetAK8NHadF[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8EmF",selpfjetAK8EmF,"selpfjetAK8EmF[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8neuemfrac",selpfjetAK8neuemfrac,"selpfjetAK8neuemfrac[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8neunhadfrac",selpfjetAK8neunhadfrac,"selpfjetAK8neunhadfrac[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8CHM",selpfjetAK8CHM,"selpfjetAK8CHM[npfjetAK8_tmu]/I");
  Tout2->Branch("selpfjetAK8NHM",selpfjetAK8NHM,"selpfjetAK8NHM[npfjetAK8_tmu]/I");
  Tout2->Branch("selpfjetAK8CEMM",selpfjetAK8CEMM,"selpfjetAK8CEMM[npfjetAK8_tmu]/I");
  Tout2->Branch("selpfjetAK8NEMM",selpfjetAK8NEMM,"selpfjetAK8NEMM[npfjetAK8_tmu]/I");
  Tout2->Branch("selpfjetAK8MUM",selpfjetAK8MUM,"selpfjetAK8MUM[npfjetAK8_tmu]/I");
  Tout2->Branch("selpfjetAK8Neucons",selpfjetAK8Neucons,"selpfjetAK8Neucons[npfjetAK8_tmu]/I");
  Tout2->Branch("selpfjetAK8Chcons",selpfjetAK8Chcons,"selpfjetAK8Chcons[npfjetAK8_tmu]/I");
  
  Tout2->Branch("selpfjetAK8chrad",selpfjetAK8chrad,"selpfjetAK8chrad[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8pTD",selpfjetAK8pTD,"selpfjetAK8pTD[npfjetAK8_tmu]/F");
  
  Tout2->Branch("selpfjetAK8sdmass",selpfjetAK8sdmass,"selpfjetAK8sdmass[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8tau21",selpfjetAK8tau21,"selpfjetAK8tau21[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8tau32",selpfjetAK8tau32,"selpfjetAK8tau32[npfjetAK8_tmu]/F");
  
  Tout2->Branch("selpfjetAK8sub1mass",selpfjetAK8sub1mass,"selpfjetAK8sub1mass[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8sub1btag",selpfjetAK8sub1btag,"selpfjetAK8sub1btag[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8sub1hadfrac",selpfjetAK8sub1hadfrac,"selpfjetAK8sub1hadfrac[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8sub1emfrac",selpfjetAK8sub1emfrac,"selpfjetAK8sub1emfrac[npfjetAK8_tmu]/F");
  
  Tout2->Branch("selpfjetAK8sub2mass",selpfjetAK8sub2mass,"selpfjetAK8sub2mass[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8sub2btag",selpfjetAK8sub2btag,"selpfjetAK8sub2btag[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8sub2hadfrac",selpfjetAK8sub2hadfrac,"selpfjetAK8sub2hadfrac[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8sub2emfrac",selpfjetAK8sub2emfrac,"selpfjetAK8sub2emfrac[npfjetAK8_tmu]/F");
  
  Tout2->Branch("selpfjetAK8subbtag", pfjetAK8subbtag,"selpfjetAK8subbtag[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8subhaddiff",selpfjetAK8subhaddiff,"selpfjetAK8subhaddiff[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8subemdiff",selpfjetAK8subemdiff,"selpfjetAK8subemdiff[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8subptdiff",selpfjetAK8subptdiff,"selpfjetAK8subptdiff[npfjetAK8_tmu]/F");
  
  Tout2->Branch("selpfjetAK8_bbyW_E", selpfjetAK8_bbyW_E,"selpfjetAK8_bbyW_E[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8_Kfactor", selpfjetAK8_Kfactor,"selpfjetAK8_Kfactor[npfjetAK8_tmu]/F");
  Tout2->Branch("selpfjetAK8_Rnew", selpfjetAK8_Rnew,"selpfjetAK8_Rnew[npfjetAK8_tmu]/F");
  
  Tout2->Branch("selpfjetAK8haselectron",selpfjetAK8haselectron,"selpfjetAK8haselectron[npfjetAK8_tmu]/O");
  Tout2->Branch("selpfjetAK8hasmuon",selpfjetAK8hasmuon,"selpfjetAK8hasmuon[npfjetAK8_tmu]/O");
  Tout2->Branch("selpfjetAK8hasb",selpfjetAK8hasb,"selpfjetAK8hasb[npfjetAK8_tmu]/O");
  Tout2->Branch("selpfjetAK8hasqg",selpfjetAK8hasqg,"selpfjetAK8hasqg[npfjetAK8_tmu]/O");
  Tout2->Branch("selpfjetAK8hashadtop",selpfjetAK8hashadtop,"selpfjetAK8hashadtop[npfjetAK8_tmu]/O");
  Tout2->Branch("selpfjetAK8hasleptop",selpfjetAK8hasleptop,"selpfjetAK8hasleptop[npfjetAK8_tmu]/O");
  Tout2->Branch("selpfjetAK8hastop",selpfjetAK8hastop,"selpfjetAK8hastop[npfjetAK8_tmu]/O");
  
  Tout2->Branch("selpfjetAK8hashadtop_alldecay",selpfjetAK8hashadtop_alldecay,"selpfjetAK8hashadtop_alldecay[npfjetAK8_tmu]/O");
  Tout2->Branch("selpfjetAK8hasleptop_alldecay",selpfjetAK8hasleptop_alldecay,"selpfjetAK8hasleptop_alldecay[npfjetAK8_tmu]/O");
  
  Tout3 = new TTree("hadtop","hadtop");
   
  Tout3->Branch("event_pt_weight",&event_pt_weight,"event_pt_weight/F");
  Tout3->Branch("weight",&weight,"weight/F");
  
  Tout3->Branch("DiLeptt",&DiLeptt,"DiLeptt/O");
  Tout3->Branch("SemiLeptt",&SemiLeptt,"SemiLeptt/O");
  Tout3->Branch("Hadtt",&Hadtt,"Hadtt/O");
  
  Tout3->Branch("npfjetAK8_thad",&npfjetAK8_thad, "npfjetAK8_thad/I");  
  Tout3->Branch("selpfjetAK8pt",selpfjetAK8pt,"selpfjetAK8pt[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8y",selpfjetAK8y,"selpfjetAK8y[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8phi",selpfjetAK8phi,"selpfjetAK8phi[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8mass",selpfjetAK8mass,"selpfjetAK8mass[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8btag_CMVA",selpfjetAK8btag_CMVA,"selpfjetAK8btag_CMVA[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8btag_CSV",selpfjetAK8btag_CSV,"selpfjetAK8btag_CSV[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8btag_DeepCSV",selpfjetAK8btag_DeepCSV,"selpfjetAK8btag_DeepCSV[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8matchAK4deepb",selpfjetAK8matchAK4deepb,"selpfjetAK8matchAK4deepb[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8matchAK4deepCSVb",selpfjetAK8matchAK4deepCSVb,"selpfjetAK8matchAK4deepCSVb[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8DeepTag_TvsQCD",selpfjetAK8DeepTag_TvsQCD,"selpfjetAK8DeepTag_TvsQCD[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8DeepTag_WvsQCD",selpfjetAK8DeepTag_WvsQCD,"selpfjetAK8DeepTag_WvsQCD[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8DeepTag_ZvsQCD",selpfjetAK8DeepTag_ZvsQCD,"selpfjetAK8DeepTag_ZvsQCD[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8CHF",selpfjetAK8CHF,"selpfjetAK8CHF[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8NHF",selpfjetAK8NHF,"selpfjetAK8NHF[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8CEMF",selpfjetAK8CEMF,"selpfjetAK8CEMF[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8NEMF",selpfjetAK8NEMF,"selpfjetAK8NEMF[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8MUF",selpfjetAK8MUF,"selpfjetAK8MUF[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8HOF",selpfjetAK8HOF,"selpfjetAK8HOF[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8HadF",selpfjetAK8HadF,"selpfjetAK8HadF[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8NHadF",selpfjetAK8NHadF,"selpfjetAK8NHadF[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8EmF",selpfjetAK8EmF,"selpfjetAK8EmF[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8neuemfrac",selpfjetAK8neuemfrac,"selpfjetAK8neuemfrac[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8neunhadfrac",selpfjetAK8neunhadfrac,"selpfjetAK8neunhadfrac[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8CHM",selpfjetAK8CHM,"selpfjetAK8CHM[npfjetAK8_thad]/I");
  Tout3->Branch("selpfjetAK8NHM",selpfjetAK8NHM,"selpfjetAK8NHM[npfjetAK8_thad]/I");
  Tout3->Branch("selpfjetAK8CEMM",selpfjetAK8CEMM,"selpfjetAK8CEMM[npfjetAK8_thad]/I");
  Tout3->Branch("selpfjetAK8NEMM",selpfjetAK8NEMM,"selpfjetAK8NEMM[npfjetAK8_thad]/I");
  Tout3->Branch("selpfjetAK8MUM",selpfjetAK8MUM,"selpfjetAK8MUM[npfjetAK8_thad]/I");
  Tout3->Branch("selpfjetAK8Neucons",selpfjetAK8Neucons,"selpfjetAK8Neucons[npfjetAK8_thad]/I");
  Tout3->Branch("selpfjetAK8Chcons",selpfjetAK8Chcons,"selpfjetAK8Chcons[npfjetAK8_thad]/I");
  
  Tout3->Branch("selpfjetAK8chrad",selpfjetAK8chrad,"selpfjetAK8chrad[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8pTD",selpfjetAK8pTD,"selpfjetAK8pTD[npfjetAK8_thad]/F");
  
  Tout3->Branch("selpfjetAK8sdmass",selpfjetAK8sdmass,"selpfjetAK8sdmass[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8tau21",selpfjetAK8tau21,"selpfjetAK8tau21[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8tau32",selpfjetAK8tau32,"selpfjetAK8tau32[npfjetAK8_thad]/F");
  
  Tout3->Branch("selpfjetAK8sub1mass",selpfjetAK8sub1mass,"selpfjetAK8sub1mass[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8sub1btag",selpfjetAK8sub1btag,"selpfjetAK8sub1btag[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8sub1hadfrac",selpfjetAK8sub1hadfrac,"selpfjetAK8sub1hadfrac[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8sub1emfrac",selpfjetAK8sub1emfrac,"selpfjetAK8sub1emfrac[npfjetAK8_thad]/F");
  
  Tout3->Branch("selpfjetAK8sub2mass",selpfjetAK8sub2mass,"selpfjetAK8sub2mass[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8sub2btag",selpfjetAK8sub2btag,"selpfjetAK8sub2btag[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8sub2hadfrac",selpfjetAK8sub2hadfrac,"selpfjetAK8sub2hadfrac[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8sub2emfrac",selpfjetAK8sub2emfrac,"selpfjetAK8sub2emfrac[npfjetAK8_thad]/F");
  
  Tout3->Branch("selpfjetAK8subbtag", pfjetAK8subbtag,"selpfjetAK8subbtag[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8subhaddiff",selpfjetAK8subhaddiff,"selpfjetAK8subhaddiff[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8subemdiff",selpfjetAK8subemdiff,"selpfjetAK8subemdiff[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8subptdiff",selpfjetAK8subptdiff,"selpfjetAK8subptdiff[npfjetAK8_thad]/F");
  
  Tout3->Branch("selpfjetAK8_bbyW_E", selpfjetAK8_bbyW_E,"selpfjetAK8_bbyW_E[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8_Kfactor", selpfjetAK8_Kfactor,"selpfjetAK8_Kfactor[npfjetAK8_thad]/F");
  Tout3->Branch("selpfjetAK8_Rnew", selpfjetAK8_Rnew,"selpfjetAK8_Rnew[npfjetAK8_thad]/F");
  
  Tout3->Branch("selpfjetAK8haselectron",selpfjetAK8haselectron,"selpfjetAK8haselectron[npfjetAK8_thad]/O");
  Tout3->Branch("selpfjetAK8hasmuon",selpfjetAK8hasmuon,"selpfjetAK8hasmuon[npfjetAK8_thad]/O");
  Tout3->Branch("selpfjetAK8hasb",selpfjetAK8hasb,"selpfjetAK8hasb[npfjetAK8_thad]/O");
  Tout3->Branch("selpfjetAK8hasqg",selpfjetAK8hasqg,"selpfjetAK8hasqg[npfjetAK8_thad]/O");
  Tout3->Branch("selpfjetAK8hashadtop",selpfjetAK8hashadtop,"selpfjetAK8hashadtop[npfjetAK8_thad]/O");
  Tout3->Branch("selpfjetAK8hasleptop",selpfjetAK8hasleptop,"selpfjetAK8hasleptop[npfjetAK8_thad]/O");
  Tout3->Branch("selpfjetAK8hastop",selpfjetAK8hastop,"selpfjetAK8hastop[npfjetAK8_thad]/O");
  
  Tout3->Branch("selpfjetAK8hashadtop_alldecay",selpfjetAK8hashadtop_alldecay,"selpfjetAK8hashadtop_alldecay[npfjetAK8_thad]/O");
  Tout3->Branch("selpfjetAK8hasleptop_alldecay",selpfjetAK8hasleptop_alldecay,"selpfjetAK8hasleptop_alldecay[npfjetAK8_thad]/O");
  
  Tout4 = new TTree("qg","qg");
   
  Tout4->Branch("event_pt_weight",&event_pt_weight,"event_pt_weight/F");
  Tout4->Branch("weight",&weight,"weight/F");
  
  Tout4->Branch("DiLeptt",&DiLeptt,"DiLeptt/O");
  Tout4->Branch("SemiLeptt",&SemiLeptt,"SemiLeptt/O");
  Tout4->Branch("Hadtt",&Hadtt,"Hadtt/O");
  
  Tout4->Branch("npfjetAK8_qg",&npfjetAK8_qg, "npfjetAK8_qg/I");  
  Tout4->Branch("selpfjetAK8pt",selpfjetAK8pt,"selpfjetAK8pt[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8y",selpfjetAK8y,"selpfjetAK8y[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8phi",selpfjetAK8phi,"selpfjetAK8phi[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8mass",selpfjetAK8mass,"selpfjetAK8mass[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8btag_CMVA",selpfjetAK8btag_CMVA,"selpfjetAK8btag_CMVA[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8btag_CSV",selpfjetAK8btag_CSV,"selpfjetAK8btag_CSV[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8btag_DeepCSV",selpfjetAK8btag_DeepCSV,"selpfjetAK8btag_DeepCSV[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8matchAK4deepb",selpfjetAK8matchAK4deepb,"selpfjetAK8matchAK4deepb[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8matchAK4deepCSVb",selpfjetAK8matchAK4deepCSVb,"selpfjetAK8matchAK4deepCSVb[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8DeepTag_TvsQCD",selpfjetAK8DeepTag_TvsQCD,"selpfjetAK8DeepTag_TvsQCD[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8DeepTag_WvsQCD",selpfjetAK8DeepTag_WvsQCD,"selpfjetAK8DeepTag_WvsQCD[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8DeepTag_ZvsQCD",selpfjetAK8DeepTag_ZvsQCD,"selpfjetAK8DeepTag_ZvsQCD[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8CHF",selpfjetAK8CHF,"selpfjetAK8CHF[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8NHF",selpfjetAK8NHF,"selpfjetAK8NHF[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8CEMF",selpfjetAK8CEMF,"selpfjetAK8CEMF[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8NEMF",selpfjetAK8NEMF,"selpfjetAK8NEMF[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8MUF",selpfjetAK8MUF,"selpfjetAK8MUF[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8HOF",selpfjetAK8HOF,"selpfjetAK8HOF[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8HadF",selpfjetAK8HadF,"selpfjetAK8HadF[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8NHadF",selpfjetAK8NHadF,"selpfjetAK8NHadF[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8EmF",selpfjetAK8EmF,"selpfjetAK8EmF[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8neuemfrac",selpfjetAK8neuemfrac,"selpfjetAK8neuemfrac[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8neunhadfrac",selpfjetAK8neunhadfrac,"selpfjetAK8neunhadfrac[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8CHM",selpfjetAK8CHM,"selpfjetAK8CHM[npfjetAK8_qg]/I");
  Tout4->Branch("selpfjetAK8NHM",selpfjetAK8NHM,"selpfjetAK8NHM[npfjetAK8_qg]/I");
  Tout4->Branch("selpfjetAK8CEMM",selpfjetAK8CEMM,"selpfjetAK8CEMM[npfjetAK8_qg]/I");
  Tout4->Branch("selpfjetAK8NEMM",selpfjetAK8NEMM,"selpfjetAK8NEMM[npfjetAK8_qg]/I");
  Tout4->Branch("selpfjetAK8MUM",selpfjetAK8MUM,"selpfjetAK8MUM[npfjetAK8_qg]/I");
  Tout4->Branch("selpfjetAK8Neucons",selpfjetAK8Neucons,"selpfjetAK8Neucons[npfjetAK8_qg]/I");
  Tout4->Branch("selpfjetAK8Chcons",selpfjetAK8Chcons,"selpfjetAK8Chcons[npfjetAK8_qg]/I");
  
  Tout4->Branch("selpfjetAK8chrad",selpfjetAK8chrad,"selpfjetAK8chrad[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8pTD",selpfjetAK8pTD,"selpfjetAK8pTD[npfjetAK8_qg]/F");
  
  Tout4->Branch("selpfjetAK8sdmass",selpfjetAK8sdmass,"selpfjetAK8sdmass[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8tau21",selpfjetAK8tau21,"selpfjetAK8tau21[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8tau32",selpfjetAK8tau32,"selpfjetAK8tau32[npfjetAK8_qg]/F");
  
  Tout4->Branch("selpfjetAK8sub1mass",selpfjetAK8sub1mass,"selpfjetAK8sub1mass[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8sub1btag",selpfjetAK8sub1btag,"selpfjetAK8sub1btag[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8sub1hadfrac",selpfjetAK8sub1hadfrac,"selpfjetAK8sub1hadfrac[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8sub1emfrac",selpfjetAK8sub1emfrac,"selpfjetAK8sub1emfrac[npfjetAK8_qg]/F");
  
  Tout4->Branch("selpfjetAK8sub2mass",selpfjetAK8sub2mass,"selpfjetAK8sub2mass[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8sub2btag",selpfjetAK8sub2btag,"selpfjetAK8sub2btag[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8sub2hadfrac",selpfjetAK8sub2hadfrac,"selpfjetAK8sub2hadfrac[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8sub2emfrac",selpfjetAK8sub2emfrac,"selpfjetAK8sub2emfrac[npfjetAK8_qg]/F");
  
  Tout4->Branch("selpfjetAK8subbtag", pfjetAK8subbtag,"selpfjetAK8subbtag[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8subhaddiff",selpfjetAK8subhaddiff,"selpfjetAK8subhaddiff[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8subemdiff",selpfjetAK8subemdiff,"selpfjetAK8subemdiff[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8subptdiff",selpfjetAK8subptdiff,"selpfjetAK8subptdiff[npfjetAK8_qg]/F");
  
  Tout4->Branch("selpfjetAK8_bbyW_E", selpfjetAK8_bbyW_E,"selpfjetAK8_bbyW_E[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8_Kfactor", selpfjetAK8_Kfactor,"selpfjetAK8_Kfactor[npfjetAK8_qg]/F");
  Tout4->Branch("selpfjetAK8_Rnew", selpfjetAK8_Rnew,"selpfjetAK8_Rnew[npfjetAK8_qg]/F");
  
  Tout4->Branch("selpfjetAK8haselectron",selpfjetAK8haselectron,"selpfjetAK8haselectron[npfjetAK8_qg]/O");
  Tout4->Branch("selpfjetAK8hasmuon",selpfjetAK8hasmuon,"selpfjetAK8hasmuon[npfjetAK8_qg]/O");
  Tout4->Branch("selpfjetAK8hasqg",selpfjetAK8hasqg,"selpfjetAK8hasqg[npfjetAK8_qg]/O");
  Tout4->Branch("selpfjetAK8hasb",selpfjetAK8hasb,"selpfjetAK8hasb[npfjetAK8_qg]/O");
  Tout4->Branch("selpfjetAK8hashadtop",selpfjetAK8hashadtop,"selpfjetAK8hashadtop[npfjetAK8_qg]/O");
  Tout4->Branch("selpfjetAK8hasleptop",selpfjetAK8hasleptop,"selpfjetAK8hasleptop[npfjetAK8_qg]/O");
  Tout4->Branch("selpfjetAK8hastop",selpfjetAK8hastop,"selpfjetAK8hastop[npfjetAK8_qg]/O");
  
  
  #endif
  
  #ifdef TRAINING
  
  Tout5 = new TTree("bq","bq");
   
  Tout5->Branch("event_pt_weight",&event_pt_weight,"event_pt_weight/F");
  Tout5->Branch("weight",&weight,"weight/F");
  
  Tout5->Branch("DiLeptt",&DiLeptt,"DiLeptt/O");
  Tout5->Branch("SemiLeptt",&SemiLeptt,"SemiLeptt/O");
  Tout5->Branch("Hadtt",&Hadtt,"Hadtt/O");
  
  Tout5->Branch("npfjetAK8_b",&npfjetAK8_b, "npfjetAK8_b/I"); 
  Tout5->Branch("selpfjetAK8pt",selpfjetAK8pt,"selpfjetAK8pt[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8y",selpfjetAK8y,"selpfjetAK8y[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8phi",selpfjetAK8phi,"selpfjetAK8phi[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8mass",selpfjetAK8mass,"selpfjetAK8mass[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8btag_CMVA",selpfjetAK8btag_CMVA,"selpfjetAK8btag_CMVA[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8btag_CSV",selpfjetAK8btag_CSV,"selpfjetAK8btag_CSV[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8btag_DeepCSV",selpfjetAK8btag_DeepCSV,"selpfjetAK8btag_DeepCSV[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchAK4deepb",selpfjetAK8matchAK4deepb,"selpfjetAK8matchAK4deepb[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8matchAK4deepCSVb",selpfjetAK8matchAK4deepCSVb,"selpfjetAK8matchAK4deepCSVb[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8DeepTag_TvsQCD",selpfjetAK8DeepTag_TvsQCD,"selpfjetAK8DeepTag_TvsQCD[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8DeepTag_WvsQCD",selpfjetAK8DeepTag_WvsQCD,"selpfjetAK8DeepTag_WvsQCD[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8DeepTag_ZvsQCD",selpfjetAK8DeepTag_ZvsQCD,"selpfjetAK8DeepTag_ZvsQCD[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8CHF",selpfjetAK8CHF,"selpfjetAK8CHF[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8NHF",selpfjetAK8NHF,"selpfjetAK8NHF[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8CEMF",selpfjetAK8CEMF,"selpfjetAK8CEMF[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8NEMF",selpfjetAK8NEMF,"selpfjetAK8NEMF[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8MUF",selpfjetAK8MUF,"selpfjetAK8MUF[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8HOF",selpfjetAK8HOF,"selpfjetAK8HOF[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8HadF",selpfjetAK8HadF,"selpfjetAK8HadF[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8NHadF",selpfjetAK8NHadF,"selpfjetAK8NHadF[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8EmF",selpfjetAK8EmF,"selpfjetAK8EmF[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8neuemfrac",selpfjetAK8neuemfrac,"selpfjetAK8neuemfrac[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8neunhadfrac",selpfjetAK8neunhadfrac,"selpfjetAK8neunhadfrac[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8CHM",selpfjetAK8CHM,"selpfjetAK8CHM[npfjetAK8_b]/I");
  Tout5->Branch("selpfjetAK8NHM",selpfjetAK8NHM,"selpfjetAK8NHM[npfjetAK8_b]/I");
  Tout5->Branch("selpfjetAK8CEMM",selpfjetAK8CEMM,"selpfjetAK8CEMM[npfjetAK8_b]/I");
  Tout5->Branch("selpfjetAK8NEMM",selpfjetAK8NEMM,"selpfjetAK8NEMM[npfjetAK8_b]/I");
  Tout5->Branch("selpfjetAK8MUM",selpfjetAK8MUM,"selpfjetAK8MUM[npfjetAK8_b]/I");
  Tout5->Branch("selpfjetAK8EEM",selpfjetAK8EEM,"selpfjetAK8EEM[npfjetAK8_b]/I");
  Tout5->Branch("selpfjetAK8Neucons",selpfjetAK8Neucons,"selpfjetAK8Neucons[npfjetAK8_b]/I");
  Tout5->Branch("selpfjetAK8Chcons",selpfjetAK8Chcons,"selpfjetAK8Chcons[npfjetAK8_b]/I");
  
  Tout5->Branch("selpfjetAK8chrad",selpfjetAK8chrad,"selpfjetAK8chrad[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8pTD",selpfjetAK8pTD,"selpfjetAK8pTD[npfjetAK8_b]/F");
  
  Tout5->Branch("selpfjetAK8sdmass",selpfjetAK8sdmass,"selpfjetAK8sdmass[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8tau21",selpfjetAK8tau21,"selpfjetAK8tau21[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8tau32",selpfjetAK8tau32,"selpfjetAK8tau32[npfjetAK8_b]/F");
  
  Tout5->Branch("selpfjetAK8sub1mass",selpfjetAK8sub1mass,"selpfjetAK8sub1mass[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8sub1btag",selpfjetAK8sub1btag,"selpfjetAK8sub1btag[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8sub1hadfrac",selpfjetAK8sub1hadfrac,"selpfjetAK8sub1hadfrac[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8sub1emfrac",selpfjetAK8sub1emfrac,"selpfjetAK8sub1emfrac[npfjetAK8_b]/F");
  
  Tout5->Branch("selpfjetAK8sub2mass",selpfjetAK8sub2mass,"selpfjetAK8sub2mass[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8sub2btag",selpfjetAK8sub2btag,"selpfjetAK8sub2btag[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8sub2hadfrac",selpfjetAK8sub2hadfrac,"selpfjetAK8sub2hadfrac[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8sub2emfrac",selpfjetAK8sub2emfrac,"selpfjetAK8sub2emfrac[npfjetAK8_b]/F");
  
  Tout5->Branch("selpfjetAK8subbtag", pfjetAK8subbtag,"selpfjetAK8subbtag[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8subhaddiff",selpfjetAK8subhaddiff,"selpfjetAK8subhaddiff[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8subemdiff",selpfjetAK8subemdiff,"selpfjetAK8subemdiff[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8subptdiff",selpfjetAK8subptdiff,"selpfjetAK8subptdiff[npfjetAK8_b]/F");
  
  Tout5->Branch("selpfjetAK8_bbyW_E", selpfjetAK8_bbyW_E,"selpfjetAK8_bbyW_E[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8_Kfactor", selpfjetAK8_Kfactor,"selpfjetAK8_Kfactor[npfjetAK8_b]/F");
  Tout5->Branch("selpfjetAK8_Rnew", selpfjetAK8_Rnew,"selpfjetAK8_Rnew[npfjetAK8_b]/F");
  
  Tout5->Branch("selpfjetAK8haselectron",selpfjetAK8haselectron,"selpfjetAK8haselectron[npfjetAK8_b]/O");
  Tout5->Branch("selpfjetAK8hasmuon",selpfjetAK8hasmuon,"selpfjetAK8hasmuon[npfjetAK8_b]/O");
  Tout5->Branch("selpfjetAK8hasqg",selpfjetAK8hasqg,"selpfjetAK8hasqg[npfjetAK8_b]/O");
  Tout5->Branch("selpfjetAK8hasb",selpfjetAK8hasb,"selpfjetAK8hasb[npfjetAK8_b]/O");
  Tout5->Branch("selpfjetAK8hashadtop",selpfjetAK8hashadtop,"selpfjetAK8hashadtop[npfjetAK8_b]/O");
  Tout5->Branch("selpfjetAK8hasleptop",selpfjetAK8hasleptop,"selpfjetAK8hasleptop[npfjetAK8_b]/O");
  Tout5->Branch("selpfjetAK8hastop",selpfjetAK8hastop,"selpfjetAK8hastop[npfjetAK8_b]/O");
  
   #endif
  
  
  Tout6 = new TTree("inclusive","inclusive");
   
  Tout6->Branch("event_pt_weight",&event_pt_weight,"event_pt_weight/F");
  Tout6->Branch("weight",&weight,"weight/F");
  
  Tout6->Branch("DiLeptt",&DiLeptt,"DiLeptt/O");
  Tout6->Branch("SemiLeptt",&SemiLeptt,"SemiLeptt/O");
  Tout6->Branch("Hadtt",&Hadtt,"Hadtt/O");
  Tout6->Branch("nleptop",&nleptop,"nleptop/I");
  Tout6->Branch("PFMET",&PFMET,"PFMET/F");
  
  Tout6->Branch("npfjetAK8_all",&npfjetAK8_all, "npfjetAK8_all/I"); 
  Tout6->Branch("selpfjetAK8pt",selpfjetAK8pt,"selpfjetAK8pt[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8y",selpfjetAK8y,"selpfjetAK8y[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8phi",selpfjetAK8phi,"selpfjetAK8phi[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8mass",selpfjetAK8mass,"selpfjetAK8mass[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8btag_CMVA",selpfjetAK8btag_CMVA,"selpfjetAK8btag_CMVA[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8btag_CSV",selpfjetAK8btag_CSV,"selpfjetAK8btag_CSV[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8btag_DeepCSV",selpfjetAK8btag_DeepCSV,"selpfjetAK8btag_DeepCSV[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8matchAK4deepb",selpfjetAK8matchAK4deepb,"selpfjetAK8matchAK4deepb[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8matchAK4deepCSVb",selpfjetAK8matchAK4deepCSVb,"selpfjetAK8matchAK4deepCSVb[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8DeepTag_TvsQCD",selpfjetAK8DeepTag_TvsQCD,"selpfjetAK8DeepTag_TvsQCD[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8DeepTag_WvsQCD",selpfjetAK8DeepTag_WvsQCD,"selpfjetAK8DeepTag_WvsQCD[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8DeepTag_ZvsQCD",selpfjetAK8DeepTag_ZvsQCD,"selpfjetAK8DeepTag_ZvsQCD[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8CHF",selpfjetAK8CHF,"selpfjetAK8CHF[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8NHF",selpfjetAK8NHF,"selpfjetAK8NHF[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8CEMF",selpfjetAK8CEMF,"selpfjetAK8CEMF[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8NEMF",selpfjetAK8NEMF,"selpfjetAK8NEMF[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8MUF",selpfjetAK8MUF,"selpfjetAK8MUF[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8HOF",selpfjetAK8HOF,"selpfjetAK8HOF[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8HadF",selpfjetAK8HadF,"selpfjetAK8HadF[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8NHadF",selpfjetAK8NHadF,"selpfjetAK8NHadF[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8EmF",selpfjetAK8EmF,"selpfjetAK8EmF[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8neuemfrac",selpfjetAK8neuemfrac,"selpfjetAK8neuemfrac[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8neunhadfrac",selpfjetAK8neunhadfrac,"selpfjetAK8neunhadfrac[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8CHM",selpfjetAK8CHM,"selpfjetAK8CHM[npfjetAK8_all]/I");
  Tout6->Branch("selpfjetAK8NHM",selpfjetAK8NHM,"selpfjetAK8NHM[npfjetAK8_all]/I");
  Tout6->Branch("selpfjetAK8CEMM",selpfjetAK8CEMM,"selpfjetAK8CEMM[npfjetAK8_all]/I");
  Tout6->Branch("selpfjetAK8NEMM",selpfjetAK8NEMM,"selpfjetAK8NEMM[npfjetAK8_all]/I");
  Tout6->Branch("selpfjetAK8MUM",selpfjetAK8MUM,"selpfjetAK8MUM[npfjetAK8_all]/I");
  Tout6->Branch("selpfjetAK8EEM",selpfjetAK8EEM,"selpfjetAK8EEM[npfjetAK8_all]/I");
  Tout6->Branch("selpfjetAK8Neucons",selpfjetAK8Neucons,"selpfjetAK8Neucons[npfjetAK8_all]/I");
  Tout6->Branch("selpfjetAK8Chcons",selpfjetAK8Chcons,"selpfjetAK8Chcons[npfjetAK8_all]/I");
  
  Tout6->Branch("selpfjetAK8chrad",selpfjetAK8chrad,"selpfjetAK8chrad[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8pTD",selpfjetAK8pTD,"selpfjetAK8pTD[npfjetAK8_all]/F");
  
  Tout6->Branch("selpfjetAK8sdmass",selpfjetAK8sdmass,"selpfjetAK8sdmass[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8tau21",selpfjetAK8tau21,"selpfjetAK8tau21[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8tau32",selpfjetAK8tau32,"selpfjetAK8tau32[npfjetAK8_all]/F");
  
  Tout6->Branch("selpfjetAK8sub1mass",selpfjetAK8sub1mass,"selpfjetAK8sub1mass[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8sub1btag",selpfjetAK8sub1btag,"selpfjetAK8sub1btag[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8sub1hadfrac",selpfjetAK8sub1hadfrac,"selpfjetAK8sub1hadfrac[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8sub1emfrac",selpfjetAK8sub1emfrac,"selpfjetAK8sub1emfrac[npfjetAK8_all]/F");
  
  Tout6->Branch("selpfjetAK8sub2mass",selpfjetAK8sub2mass,"selpfjetAK8sub2mass[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8sub2btag",selpfjetAK8sub2btag,"selpfjetAK8sub2btag[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8sub2hadfrac",selpfjetAK8sub2hadfrac,"selpfjetAK8sub2hadfrac[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8sub2emfrac",selpfjetAK8sub2emfrac,"selpfjetAK8sub2emfrac[npfjetAK8_all]/F");
  
  Tout6->Branch("selpfjetAK8subbtag", pfjetAK8subbtag,"selpfjetAK8subbtag[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8subhaddiff",selpfjetAK8subhaddiff,"selpfjetAK8subhaddiff[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8subemdiff",selpfjetAK8subemdiff,"selpfjetAK8subemdiff[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8subptdiff",selpfjetAK8subptdiff,"selpfjetAK8subptdiff[npfjetAK8_all]/F");
  
  Tout6->Branch("selpfjetAK8_bbyW_E", selpfjetAK8_bbyW_E,"selpfjetAK8_bbyW_E[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8_Kfactor", selpfjetAK8_Kfactor,"selpfjetAK8_Kfactor[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8_Rnew", selpfjetAK8_Rnew,"selpfjetAK8_Rnew[npfjetAK8_all]/F");
  
  Tout6->Branch("selpfjetAK8re_tvsb", selpfjetAK8re_tvsb,"selpfjetAK8re_tvsb[npfjetAK8_all]/F");
  Tout6->Branch("selpfjetAK8rnu_tvsb", selpfjetAK8rnu_tvsb,"selpfjetAK8rnu_tvsb[npfjetAK8_all]/F");
  
  Tout6->Branch("selpfjetAK8haselectron",selpfjetAK8haselectron,"selpfjetAK8haselectron[npfjetAK8_all]/O");
  Tout6->Branch("selpfjetAK8hasmuon",selpfjetAK8hasmuon,"selpfjetAK8hasmuon[npfjetAK8_all]/O");
  Tout6->Branch("selpfjetAK8hasqg",selpfjetAK8hasqg,"selpfjetAK8hasqg[npfjetAK8_all]/O");
  Tout6->Branch("selpfjetAK8hasb",selpfjetAK8hasb,"selpfjetAK8hasb[npfjetAK8_all]/O");
  Tout6->Branch("selpfjetAK8hashadtop",selpfjetAK8hashadtop,"selpfjetAK8hashadtop[npfjetAK8_all]/O");
  Tout6->Branch("selpfjetAK8hasleptop",selpfjetAK8hasleptop,"selpfjetAK8hasleptop[npfjetAK8_all]/O");
  Tout6->Branch("selpfjetAK8hastop",selpfjetAK8hastop,"selpfjetAK8hastop[npfjetAK8_all]/O");
  
  Tout6->Branch("selpfjetAK8hashadtop_alldecay",selpfjetAK8hashadtop_alldecay,"selpfjetAK8hashadtop_alldecay[npfjetAK8_all]/O");
  Tout6->Branch("selpfjetAK8hasleptop_alldecay",selpfjetAK8hasleptop_alldecay,"selpfjetAK8hasleptop_alldecay[npfjetAK8_all]/O");
  
  Tout_el = new TTree("electron","electron");
  Tout_el->Branch("nselec",&nselec,"nselec/I");
  Tout_el->Branch("selelrelpT",selelrelpT,"selelrelpT[nselec]/F");
  Tout_el->Branch("selelnearjdR",selelnearjdR,"selelnearjdR[nselec]/F");
  
  char name[1000];
  char title[1000];
  
  for(int ihist=0; ihist<nhist; ihist++){
	  
	  sprintf(name,"%s_tlepe",branchnames[ihist]);
	  hist_1[ihist] = new TH1D(name,name,hist_nbins[ihist],hist_low[ihist],hist_up[ihist]);
	  hist_1[ihist]->Sumw2();
	  
	  sprintf(name,"%s_tlepmu",branchnames[ihist]);
	  hist_2[ihist] = new TH1D(name,name,hist_nbins[ihist],hist_low[ihist],hist_up[ihist]);
	  hist_2[ihist]->Sumw2();
	  
	  sprintf(name,"%s_thad",branchnames[ihist]);
	  hist_3[ihist] = new TH1D(name,name,hist_nbins[ihist],hist_low[ihist],hist_up[ihist]);
	  hist_3[ihist]->Sumw2();
	  
	  sprintf(name,"%s_qg",branchnames[ihist]);
	  hist_4[ihist] = new TH1D(name,name,hist_nbins[ihist],hist_low[ihist],hist_up[ihist]);
	  hist_4[ihist]->Sumw2();
	  
	  sprintf(name,"%s_b",branchnames[ihist]);
	  hist_5[ihist] = new TH1D(name,name,hist_nbins[ihist],hist_low[ihist],hist_up[ihist]);
	  hist_5[ihist]->Sumw2();
	  
	  sprintf(name,"%s_topcand",branchnames[ihist]);
	  hist_6[ihist] = new TH1D(name,name,hist_nbins[ihist],hist_low[ihist],hist_up[ihist]);
	  hist_6[ihist]->Sumw2();
  }
  
  sprintf(name,"H2D_re_rnu_tlepe");
  h2d_re_rnu_1 = new TH2D(name,name,900, -1.0, 1.0, 80, -1.0, 1.0);
  sprintf(name,"H2D_re_rnu_tlepmu");
  h2d_re_rnu_2 = new TH2D(name,name,900, -1.0, 1.0, 80, -1.0, 1.0);
  sprintf(name,"H2D_re_rnu_thad");
  h2d_re_rnu_3 = new TH2D(name,name,900, -1.0, 1.0, 80, -1.0, 1.0);
  sprintf(name,"H2D_re_rnu_qg");
  h2d_re_rnu_4 = new TH2D(name,name,900, -1.0, 1.0, 80, -1.0, 1.0);
  sprintf(name,"H2D_re_rnu_b");
  h2d_re_rnu_5 = new TH2D(name,name,900, -1.0, 1.0, 80, -1.0, 1.0);
  sprintf(name,"H2D_re_rnu_topcand");
  h2d_re_rnu_6 = new TH2D(name,name,900, -1.0, 1.0, 80, -1.0, 1.0);
  
  sprintf(name,"N_PV");
  sprintf(title,"# of Primary Vertices");
  hist_npv = new TH1D(name,title,100,-0.1,99.9);//80,-0.1,79.9);
  hist_npv->Sumw2();
   
  sprintf(name,"N_PU");
  sprintf(title,"# of Pileup Vertices");
  hist_npu = new TH1D(name,title,100,0,100);//80,-0.1,79.9);
  hist_npu->Sumw2();
  
  sprintf(name,"H2D_dR_lb_LepTop");
  sprintf(title,"Top p_{T} vs #Delta R(l,b)");
  h2d_pt_lb = new TH2D(name,title,noptbins,ptbins,75,0,1.57);
  h2d_pt_lb->Sumw2();
  
  sprintf(name,"H2D_dR_lt_LepTop");
  sprintf(title,"Top p_{T} vs #Delta R(l,t)");
  h2d_pt_lt = new TH2D(name,title,noptbins,ptbins,75,0,1.57);
  h2d_pt_lt->Sumw2();
  
  sprintf(name,"H2D_dR_lb_HadTop");
  sprintf(title,"Top p_{T} vs #Delta R(d/s,b)");
  h2d_pt_qb = new TH2D(name,title,noptbins,ptbins,75,0,1.57);
  h2d_pt_qb->Sumw2();
  
  sprintf(name,"H2D_dR_lt_HadTop");
  sprintf(title,"Top p_{T} vs #Delta R(d/s,t)");
  h2d_pt_qt = new TH2D(name,title,noptbins,ptbins,75,0,1.57);
  h2d_pt_qt->Sumw2();
  
  sprintf(name,"H2D_dRmax_daught_top_LepTop");
  sprintf(title,"Top p_{T} vs Max(#Delta R(d,t))");
  h2d_pt_qt_lep = new TH2D(name,title,noptbins,ptbins,75,0,1.57);
  h2d_pt_qt_lep->Sumw2();
  
  sprintf(name,"H2D_dRmax_daught_top_HadTop");
  sprintf(title,"Top p_{T} vs Max(#Delta R(d,t))");
  h2d_pt_qt_had = new TH2D(name,title,noptbins,ptbins,75,0,1.57);
  h2d_pt_qt_had->Sumw2();
  
  sprintf(name,"Pt_LepTop");
  sprintf(title,"P_{T} of leptonic top");
  h_pt_leptop = new TH1D(name,title,noptbins,ptbins);
  h_pt_leptop->Sumw2();
  
  sprintf(name,"Pt_hadTop");
  sprintf(title,"P_{T} of hadronic top");
  h_pt_hadtop = new TH1D(name,title,noptbins,ptbins);
  h_pt_hadtop->Sumw2();
  
  sprintf(name,"Pt_LepTop_matchedtojet");
  sprintf(title,"P_{T} of leptonic top (#Delta R(t,j) < 0.6)");
  h_pt_leptop_matchedJet = new TH1D(name,title,noptbins,ptbins);
  h_pt_leptop_matchedJet->Sumw2();
  
  sprintf(name,"Pt_hadTop_matchedtojet");
  sprintf(title,"P_{T} of hadronic top (#Delta R(t,j) < 0.6)");
  h_pt_hadtop_matchedJet = new TH1D(name,title,noptbins,ptbins);
  h_pt_hadtop_matchedJet->Sumw2();
  
  sprintf(name,"H2D_dRmin_top_jet_LepTop");
  sprintf(title,"Top p_{T} vs Min(#Delta R(t,j))");
  h2d_pt_dR_leptop_Jet = new TH2D(name,title,noptbins,ptbins,75,0,1.57);
  h2d_pt_dR_leptop_Jet->Sumw2();
  
  sprintf(name,"H2D_dRmin_top_jet_HadTop");
  sprintf(title,"Top p_{T} vs Min(#Delta R(t,j))");
  h2d_pt_dR_hadtop_Jet = new TH2D(name,title,noptbins,ptbins,75,0,1.57);
  h2d_pt_dR_hadtop_Jet->Sumw2();
  
  sprintf(name,"Counter_event");
  hist_event_count = new TH1D(name,title,2,-0.5,1.5);
  hist_event_count->Sumw2();
  
  sprintf(name,"Counter_event_truthtop");
  hist_event_count_truth = new TH1D(name,title,2,-0.5,1.5);
  hist_event_count_truth->Sumw2();
  
  sprintf(name,"Counter_event_pass_re");
  hist_event_top_pass = new TH1D(name,title,nre+1,-0.5,101.5);
  hist_event_top_pass->Sumw2();
  
  sprintf(name,"Elec_2DIso");
  h_el_2diso = new TH1D(name,name,2,-0.5,1.5);
  h_el_2diso->Sumw2();
  
  sprintf(name,"Elec_RelpT");
  h_el_relpt = new TH1D(name,name,50,0,250);
  h_el_relpt->Sumw2();
  
  sprintf(name,"Elec_Closeby_bjet");
  h_closebjet = new TH1D(name,name,2,-0.5,1.5);
  h_closebjet->Sumw2();
  
  sprintf(name,"Elec_Closeby_bjet_p8");
  h_closebjet_dRp8 = new TH1D(name,name,2,-0.5,1.5);
  h_closebjet_dRp8->Sumw2();
  
  sprintf(name,"NElectron");
  hist_nelec = new TH1D(name,name,10,-0.5,9.5);
  hist_nelec->Sumw2();
  
  reader1 = new TMVA::Reader( "BDTG_Re" );

  reader1->AddVariable( "selpfjetAK8NHadF", &in_pfjetAK8NHadF);
  reader1->AddVariable( "selpfjetAK8neunhadfrac", &in_pfjetAK8neunhadfrac);
  reader1->AddVariable( "selpfjetAK8subhaddiff", &in_pfjetAK8subhaddiff);
  reader1->AddVariable( "selpfjetAK8tau21", &in_pfjetAK8tau21);
  reader1->AddVariable( "selpfjetAK8chrad", &in_pfjetAK8chrad);
  reader1->AddVariable( "selpfjetAK8sdmass", &in_pfjetAK8sdmass);
  
  reader1->BookMVA("BDTG method", weightfile1);
  
  reader2 = new TMVA::Reader( "BDTG_Rnu" );
  
  reader2->AddVariable( "selpfjetAK8_bbyW_E", &in_pfjetAK8_bbyW_E);
  reader2->AddVariable( "selpfjetAK8_Kfactor", &in_pfjetAK8_Kfactor);
  
  reader2->BookMVA("BDTG method", weightfile2);
  
}

Bool_t Anal_Leptop_PROOF::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either Anal_Leptop_PROOF::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

   GetEntry(entry);
   if(isMC){
	weight = event_weight;
	}else{
		weight = 1;
		 }
		 
   int ngenelc = 0;
   int ngenmu = 0;
   int ngenqg = 0;
   int ngenb = 0;
   
   hist_event_count->Fill(1,weight);
   
   TLorentzVector leptop4v[2];
   TLorentzVector leptop4v_daught[3][2];
   TLorentzVector hadtop4v[2];
   TLorentzVector hadtop4v_daught[3][2];
   
   if(isMC){
   
   for(int igen=0; igen<ngenparticles; igen++){
	   if(abs(genpartstatus[igen])!=23 && genpartstatus[igen]!=1) continue;
	   if(!(genpartfromhard[igen]) /*|| !(genpartfromhardbFSR[igen])*/) continue;
	   if(abs(genpartpdg[igen])==11) { 
		   genelectronpt[ngenelc] = genpartpt[igen];
		   genelectroneta[ngenelc] = genparteta[igen];
		   genelectronphi[ngenelc] = genpartphi[igen];
		   genelectronm[ngenelc] = genpartm[igen];
		   ngenelc++; 
		   }
	   if(abs(genpartpdg[igen])==13) { 
		   genmuonpt[ngenmu] = genpartpt[igen];
		   genmuoneta[ngenmu] = genparteta[igen];
		   genmuonphi[ngenmu] = genpartphi[igen];
		   genmuonm[ngenmu] = genpartm[igen];
		   ngenmu++; 
		   }
		if((abs(genpartpdg[igen])>=1 && abs(genpartpdg[igen])<5)||(abs(genpartpdg[igen])==21)) {    
		   genqgpt[ngenqg] = genpartpt[igen];
		   genqgeta[ngenqg] = genparteta[igen];
		   genqgphi[ngenqg] = genpartphi[igen];
		   genqgm[ngenqg] = genpartm[igen];
		   ngenqg++;
	   }
	   if(abs(genpartpdg[igen])==5) {    
		   genbpt[ngenb] = genpartpt[igen];
		   genbeta[ngenb] = genparteta[igen];
		   genbphi[ngenb] = genpartphi[igen];
		   genbm[ngenb] = genpartm[igen];
		   ngenb++;
	   }
   }
   
   ngenelectrons = ngenelc;
   ngenmuons = ngenmu;
   ngenqgs = ngenqg;
   ngenbs = ngenb;
   
   int ngent = 0;
   
   for(int igen=0; igen<ngenparticles; igen++){
	  
	   if(abs(genpartstatus[igen])!=22) continue;
	   if(!(genpartfromhard[igen])) continue;
//	   if(genpartdaugno[igen]!=2) continue;
	   if(abs(genpartpdg[igen])!=6) continue;
		
	   gentoppt[ngent] = genpartpt[igen];
	   gentopeta[ngent] = genparteta[igen];
	   gentopphi[ngent] = genpartphi[igen];
	   gentopm[ngent] = genpartm[igen];
	   gentopid[ngent] = igen;
	   
	   ngent++;
	}
   
   ngentops = ngent;
   
   int top_dp[6];
   int idp = 0;
   int ndq = 0; int ndb = 0; int ndl = 0;
   int top_dqp[4] = {-1,-1,-1,-1};
   int top_dbp[2] = {-1,-1};
   int top_dlp[4] = {-1,-1,-1,-1};
   
   for(int igen=0; igen<ngenparticles; igen++){
	  
	   if(!(genpartstatus[igen]==23 || genpartstatus[igen]==1)) continue;
	   if(!(genpartfromhard[igen])) continue;
	   
	   if(!((abs(genpartpdg[igen])>=1 && abs(genpartpdg[igen])<=5)||(abs(genpartpdg[igen])>=11 && abs(genpartpdg[igen])<=14))) continue;
	   if(!(abs(genpartmompdg[igen])==6 || abs(genpartmompdg[igen])==24)) continue;
	   top_dp[idp] = igen;
	   if(abs(genpartpdg[igen])>=1 && abs(genpartpdg[igen])<5 && abs(genpartmompdg[igen])==24) {  top_dqp[ndq] = igen;  ndq++; }
	   if(abs(genpartpdg[igen])>=11 && abs(genpartpdg[igen])<=16 && abs(genpartmompdg[igen])==24) {  top_dlp[ndl] = igen;  ndl++; }
	   if(abs(genpartpdg[igen])==5 && abs(genpartmompdg[igen])==6) {  top_dbp[ndb] = igen;  ndb++; }
	   idp++;
//	   if(idp>=6) break;
//	   if(ndq>=4 && ndl>=4 && ndb>=2) break;
   }
   
   
   nleptop = nhadtop = -1;
   
   if(ndq==4 && ndl==0) { nleptop = 0; nhadtop = 2; }
   if(ndq==2 && ndl==2) { nleptop = 1; nhadtop = 1; }
   if(ndq==0 && ndl==4) { nleptop = 2; nhadtop = 0; }
   if(ndq==0 && ndl==2) { nleptop = 1; nhadtop = 0; }
   if(ndq==2 && ndl==0) { nleptop = 0; nhadtop = 1; }
   if(ndq==0 && ndl==0) { nleptop = 0; nhadtop = 0; }
   
 //  TString str = TString::Format("entry %lli nleptop %i nhadtop %i ngentops %i\n",entry,nleptop,nhadtop,ngentops);
 //  if(gProofServ) gProofServ->SendAsynMessage(str);
   
	 
   for(int ilep=0; ilep<ndl; ilep++){
	   for(int jlep=(ilep+1); jlep<ndl; jlep++){
		if((abs(abs(genpartpdg[top_dlp[ilep]])-abs(genpartpdg[top_dlp[jlep]]))==1) && (genpartpdg[top_dlp[ilep]]*genpartpdg[top_dlp[jlep]]<0) && (genpartmompdg[top_dlp[ilep]]==genpartmompdg[top_dlp[jlep]]))
		{
			genpartpair[top_dlp[ilep]] = top_dlp[jlep];
			genpartpair[top_dlp[jlep]] = top_dlp[ilep];
		}
	   }
   }
   
   for(int iq=0; iq<ndq; iq++){
	   for(int jq=(iq+1); jq<ndq; jq++){
		if( ( (abs(abs(genpartpdg[top_dqp[iq]])-abs(genpartpdg[top_dqp[jq]]))==1)||(abs(abs(genpartpdg[top_dqp[iq]])-abs(genpartpdg[top_dqp[jq]]))==3) ) && (genpartpdg[top_dqp[iq]]*genpartpdg[top_dqp[jq]]<0) && (genpartmompdg[top_dqp[iq]]==genpartmompdg[top_dqp[jq]]) )
		{
			genpartpair[top_dqp[iq]] = top_dqp[jq];
			genpartpair[top_dqp[jq]] = top_dqp[iq];
		}
	   }
   }
   
   
   int ileptop = 0;
   int ihadtop = 0;
   
   if(nleptop>0){
   
   for(int ilep=0; ilep<ndl; ilep++){
	   if(!((abs(genpartpdg[top_dlp[ilep]])==11 /*|| abs(genpartpdg[top_dlp[ilep]])==13*/ ) && genpartpair[top_dlp[ilep]]>=0)) continue;
	
	   for(int ib=0; ib<ndb; ib++){
	
		   if(genpartmompdg[top_dbp[ib]]*genpartmompdg[top_dlp[ilep]]>0){
			   TLorentzVector b4; b4.SetPtEtaPhiM(genpartpt[top_dbp[ib]],genparteta[top_dbp[ib]],genpartphi[top_dbp[ib]],genpartm[top_dbp[ib]]);
			   int ipar = top_dlp[ilep];
			   if(ipar>=0){
				TLorentzVector q1; q1.SetPtEtaPhiM(genpartpt[ipar],genparteta[ipar],genpartphi[ipar],genpartm[ipar]);
				int jpar = genpartpair[top_dlp[ilep]];
				TLorentzVector q2; q2.SetPtEtaPhiM(genpartpt[jpar],genparteta[jpar],genpartphi[jpar],genpartm[jpar]);
				leptop4v[ileptop] = (b4+q1+q2);
				leptop4v_daught[0][ileptop] = q1;
				leptop4v_daught[1][ileptop] = q2;
				leptop4v_daught[2][ileptop] = b4;
				h2d_pt_lb->Fill(leptop4v[ileptop].Pt(),delta2R(b4.Rapidity(),b4.Phi(),q1.Rapidity(),q1.Phi()), weight);
				h2d_pt_lt->Fill(leptop4v[ileptop].Pt(),delta2R(leptop4v[ileptop].Rapidity(),leptop4v[ileptop].Phi(),q1.Rapidity(),q1.Phi()),weight);
				
				ileptop++;
				break;
			   }
			 }
		   
		   }
		   if(ileptop>=nleptop) break;
	   }
   }
   
   if(nhadtop>0){
   
   for(int iq=0; iq<ndq; iq++){
	   
	   if(!(( (abs(genpartpdg[top_dqp[iq]])==1) || (abs(genpartpdg[top_dqp[iq]])==3) ) && genpartpair[top_dqp[iq]]>=0)) continue;
	
	   for(int ib=0; ib<ndb; ib++){
		   
		   if(genpartmompdg[top_dbp[ib]]*genpartmompdg[top_dqp[iq]]>0){
			   TLorentzVector b4; b4.SetPtEtaPhiM(genpartpt[top_dbp[ib]],genparteta[top_dbp[ib]],genpartphi[top_dbp[ib]],genpartm[top_dbp[ib]]);
			   int ipar = top_dqp[iq];
			   if(ipar>=0){
				TLorentzVector q1; q1.SetPtEtaPhiM(genpartpt[ipar],genparteta[ipar],genpartphi[ipar],genpartm[ipar]);
				int jpar = genpartpair[top_dqp[iq]];
				TLorentzVector q2; q2.SetPtEtaPhiM(genpartpt[jpar],genparteta[jpar],genpartphi[jpar],genpartm[jpar]);
				hadtop4v[ihadtop] = (b4+q1+q2);
				hadtop4v_daught[0][ihadtop] = q1;
				hadtop4v_daught[1][ihadtop] = q2;
				hadtop4v_daught[2][ihadtop] = b4;
				h2d_pt_qb->Fill(hadtop4v[ihadtop].Pt(),delta2R(b4.Rapidity(),b4.Phi(),q1.Rapidity(),q1.Phi()), weight);
				h2d_pt_qt->Fill(hadtop4v[ihadtop].Pt(),delta2R(hadtop4v[ihadtop].Rapidity(),hadtop4v[ihadtop].Phi(),q1.Rapidity(),q1.Phi()), weight);
				
				ihadtop++;
				break;
				}
			   }
			   
		   }
		   if(ihadtop>=nhadtop) break;
	   }
   
	}

	nleptop = ileptop;
	nhadtop = ihadtop;

//   str = TString::Format("entry %lli ileptop %i ihadtop %i\n",entry,ileptop,ihadtop);
//   if(gProofServ) gProofServ->SendAsynMessage(str);
 }//isMC

   DiLeptt = SemiLeptt = Hadtt = false;

   if(nleptop==2 && nhadtop==0) { DiLeptt = true; }
   if(nleptop==1 && nhadtop==1) { SemiLeptt = true; }
   if(nleptop==0 && nhadtop==2) { Hadtt = true; }
   
   if(nleptop>=1) { hist_event_count_truth->Fill(1,weight); }
   
for(int ilep=0; ilep<nleptop; ilep++){
	
 h_pt_leptop->Fill(leptop4v[ilep].Pt(),weight);
 	
 for(int ijet=0; ijet< npfjetAK8; ijet++){	
	if(delta2R(leptop4v[ilep].Rapidity(),leptop4v[ilep].Phi(),pfjetAK8y[ijet],pfjetAK8phi[ijet])<0.6){
	h_pt_leptop_matchedJet->Fill(leptop4v[ilep].Pt(),weight);
	break;
	}
  }
  
  double dRmin = 100;
  for(int ijet=0; ijet< npfjetAK8; ijet++){	
	  if(delta2R(leptop4v[ilep].Rapidity(),leptop4v[ilep].Phi(),pfjetAK8y[ijet],pfjetAK8phi[ijet])<dRmin){
		  dRmin = delta2R(leptop4v[ilep].Rapidity(),leptop4v[ilep].Phi(),pfjetAK8y[ijet],pfjetAK8phi[ijet]);
		 }
	}
  h2d_pt_dR_leptop_Jet->Fill(leptop4v[ilep].Pt(),dRmin,weight);
  
  float dRmax = std::max({delta2R(leptop4v_daught[0][ilep].Rapidity(),leptop4v_daught[0][ilep].Phi(),leptop4v[ilep].Rapidity(),leptop4v[ilep].Phi()),
						  delta2R(leptop4v_daught[1][ilep].Rapidity(),leptop4v_daught[1][ilep].Phi(),leptop4v[ilep].Rapidity(),leptop4v[ilep].Phi()),
						  delta2R(leptop4v_daught[2][ilep].Rapidity(),leptop4v_daught[2][ilep].Phi(),leptop4v[ilep].Rapidity(),leptop4v[ilep].Phi())});
  
  h2d_pt_qt_lep->Fill(leptop4v[ilep].Pt(),dRmax, weight);
}

for(int ihad=0; ihad<nhadtop; ihad++){
	
 h_pt_hadtop->Fill(hadtop4v[ihad].Pt(),weight);
	
 for(int ijet=0; ijet< npfjetAK8; ijet++){	
	if(delta2R(hadtop4v[ihad].Rapidity(),hadtop4v[ihad].Phi(),pfjetAK8y[ijet],pfjetAK8phi[ijet])<0.6){
	h_pt_hadtop_matchedJet->Fill(hadtop4v[ihad].Pt(),weight);
	break;
	}
  }
  
  double dRmin = 100;
  for(int ijet=0; ijet< npfjetAK8; ijet++){	
	  if(delta2R(hadtop4v[ihad].Rapidity(),hadtop4v[ihad].Phi(),pfjetAK8y[ijet],pfjetAK8phi[ijet])<dRmin){
		  dRmin = delta2R(hadtop4v[ihad].Rapidity(),hadtop4v[ihad].Phi(),pfjetAK8y[ijet],pfjetAK8phi[ijet]);
		 }
	}
  h2d_pt_dR_hadtop_Jet->Fill(hadtop4v[ihad].Pt(),dRmin,weight);
  
  float dRmax = std::max({delta2R(hadtop4v_daught[0][ihad].Rapidity(),hadtop4v_daught[0][ihad].Phi(),hadtop4v[ihad].Rapidity(),hadtop4v[ihad].Phi()),
						  delta2R(hadtop4v_daught[1][ihad].Rapidity(),hadtop4v_daught[1][ihad].Phi(),hadtop4v[ihad].Rapidity(),hadtop4v[ihad].Phi()),
						  delta2R(hadtop4v_daught[2][ihad].Rapidity(),hadtop4v_daught[2][ihad].Phi(),hadtop4v[ihad].Rapidity(),hadtop4v[ihad].Phi())});
  
  h2d_pt_qt_had->Fill(hadtop4v[ihad].Pt(),dRmax, weight);
}
   
   int fjet = 0;
      
   for(int ijet=0; ijet<npfjetAK8; ijet++){
		  
	  if(!pfjetAK8looseID[ijet]) continue;
		  
	  if(fabs(pfjetAK8y[ijet])>2.5) continue;
		  
	  pfjetAK8pt[ijet] *= pfjetAK8JEC[ijet] ;
	  pfjetAK8mass[ijet] *= pfjetAK8JEC[ijet];
	  if(isMC){
		pfjetAK8pt[ijet] *= (1+pfjetAK8reso[ijet]) ;
		pfjetAK8mass[ijet] *= (1+pfjetAK8reso[ijet]) ;
		pfjetAK8sdmass[ijet] *= (1+pfjetAK8reso[ijet]) ;
	  }
	  
	  if(pfjetAK8pt[ijet] < ptcut) continue;
		  
	  pfjetAK8pt[fjet] = pfjetAK8pt[ijet];
	  pfjetAK8mass[fjet] = pfjetAK8mass[ijet];
	  pfjetAK8y[fjet] = pfjetAK8y[ijet];
	  pfjetAK8phi[fjet] = pfjetAK8phi[ijet];
	  pfjetAK8chrad[fjet] = pfjetAK8chrad[ijet];
	  pfjetAK8tau21[fjet] = pfjetAK8tau2[ijet]*1./pfjetAK8tau1[ijet];
	  pfjetAK8tau32[fjet] = pfjetAK8tau3[ijet]*1./pfjetAK8tau2[ijet];
	  pfjetAK8DeepTag_TvsQCD[fjet] = pfjetAK8DeepTag_TvsQCD[ijet];
	  pfjetAK8DeepTag_WvsQCD[fjet] = pfjetAK8DeepTag_WvsQCD[ijet];
	  pfjetAK8DeepTag_ZvsQCD[fjet] = pfjetAK8DeepTag_ZvsQCD[ijet];
	  pfjetAK8btag_DeepCSV[fjet] = pfjetAK8btag_DeepCSV[ijet];
	  pfjetAK8btag_CMVA[fjet] = pfjetAK8btag_CMVA[ijet];
	  pfjetAK8CHF[fjet] = pfjetAK8CHF[ijet];
	  pfjetAK8NHF[fjet] = pfjetAK8NHF[ijet];
	  pfjetAK8CEMF[fjet] = pfjetAK8CEMF[ijet];
	  pfjetAK8NEMF[fjet] = pfjetAK8NEMF[ijet];
	  pfjetAK8MUF[fjet] = pfjetAK8MUF[ijet];
	  pfjetAK8PHF[fjet] = pfjetAK8PHF[ijet];
	  pfjetAK8HadF[fjet] = (pfjetAK8NHF[fjet]+pfjetAK8CHF[fjet]);
	  pfjetAK8NHadF[fjet] = (1.-pfjetAK8HadF[fjet]);
	  pfjetAK8EmF[fjet] = (pfjetAK8NEMF[fjet]+pfjetAK8CEMF[fjet]);
	  pfjetAK8EEM[fjet] = pfjetAK8EEM[ijet];
	  pfjetAK8ncons[fjet] = pfjetAK8Chcons[ijet]+pfjetAK8Chcons[ijet];
	  pfjetAK8Chcons[fjet] = pfjetAK8Chcons[ijet];
	  pfjetAK8neuemfrac[fjet] = (pfjetAK8NEMF[fjet]*1./pfjetAK8EmF[fjet]);
	  pfjetAK8neunhadfrac[fjet] = (pfjetAK8NEMF[fjet]*1./pfjetAK8NHadF[fjet]);
	  pfjetAK8sdmass[fjet] = pfjetAK8sdmass[ijet];
		  
	  pfjetAK8sub1pt[fjet] = pfjetAK8sub1pt[ijet];
	  pfjetAK8sub1eta[fjet] = pfjetAK8sub1eta[ijet];
	  pfjetAK8sub1phi[fjet] = pfjetAK8sub1phi[ijet];
	  pfjetAK8sub1mass[fjet] = pfjetAK8sub1mass[ijet];
	  pfjetAK8sub1btag[fjet] = pfjetAK8sub1btag[ijet];
	  pfjetAK8sub1hadfrac[fjet] = pfjetAK8sub1chhadfrac[ijet]+pfjetAK8sub1neuhadfrac[ijet];
	  pfjetAK8sub1emfrac[fjet] = pfjetAK8sub1emfrac[ijet];//pfjetAK8sub1chemfrac[ijet]+pfjetAK8sub1frac[ijet];
		  
	  pfjetAK8sub2pt[fjet] = pfjetAK8sub2pt[ijet];
	  pfjetAK8sub2eta[fjet] = pfjetAK8sub2eta[ijet];
	  pfjetAK8sub2phi[fjet] = pfjetAK8sub2phi[ijet];
	  pfjetAK8sub2mass[fjet] = pfjetAK8sub2mass[ijet];
	  pfjetAK8sub2btag[fjet] = pfjetAK8sub2btag[ijet];
	  pfjetAK8sub2hadfrac[fjet] = pfjetAK8sub2chhadfrac[ijet]+pfjetAK8sub2neuhadfrac[ijet];
	  pfjetAK8sub2emfrac[fjet] = pfjetAK8sub2emfrac[ijet];//pfjetAK8sub2chemfrac[ijet]+pfjetAK8sub2neuemfrac[ijet];
		  
	  pfjetAK8subbtag[fjet] =   (pfjetAK8sub2hadfrac[fjet] > pfjetAK8sub1hadfrac[fjet])? pfjetAK8sub2btag[fjet] : pfjetAK8sub1btag[fjet];
	  pfjetAK8subhaddiff[fjet] = diff_func(pfjetAK8sub1hadfrac[fjet],pfjetAK8sub2hadfrac[fjet]);
	  pfjetAK8subemdiff[fjet] = diff_func(pfjetAK8sub1emfrac[fjet],pfjetAK8sub2emfrac[fjet]);
	  pfjetAK8subptdiff[fjet] = diff_func(pfjetAK8sub1pt[fjet],pfjetAK8sub2pt[fjet]);
	  
	  
	  pfjetAK8_leppt[fjet] = pfjetAK8_leppt[ijet];
	  pfjetAK8_lepeta[fjet] = pfjetAK8_lepeta[ijet];
	  pfjetAK8_lepphi[fjet] = pfjetAK8_lepphi[ijet];
	  pfjetAK8_lepe[fjet] = pfjetAK8_lepe[ijet];
	  
	  pfjetAK8_bpt[fjet] = pfjetAK8_bpt[ijet];
	  pfjetAK8_beta[fjet] = pfjetAK8_beta[ijet];
	  pfjetAK8_bphi[fjet] = pfjetAK8_bphi[ijet];
	  pfjetAK8_be[fjet] = pfjetAK8_be[ijet];
	  
	  pfjetAK8_nupt[fjet] = pfjetAK8_nupt[ijet];
	  pfjetAK8_nueta[fjet] = pfjetAK8_nueta[ijet];
	  pfjetAK8_nuphi[fjet] = pfjetAK8_nuphi[ijet];
	  pfjetAK8_nue[fjet] = pfjetAK8_nue[ijet];
	  
	  pfjetAK8_bbyW_E[fjet] = pfjetAK8_bbyW_E[ijet];
	  pfjetAK8_Kfactor[fjet] = pfjetAK8_Kfactor[ijet];
	  pfjetAK8_Rnew[fjet] = pfjetAK8_Rnew[ijet];
	  
	  pfjetAK8_bbyW_E[fjet] = pfjetAK8_bbyW_E[ijet];
	  pfjetAK8_Kfactor[fjet] = pfjetAK8_Kfactor[ijet];
	  pfjetAK8_Rnew[fjet] = pfjetAK8_Rnew[ijet];
	  
	  
	  pfjetAK8haselectron[fjet] = pfjetAK8hasmuon[fjet] = pfjetAK8hasqg[fjet] = pfjetAK8hasb[fjet] = pfjetAK8hasleptop[fjet] = pfjetAK8hashadtop[fjet] = pfjetAK8hastop[fjet] = false;
	  pfjetAK8hasleptop_alldecay[fjet] = pfjetAK8hashadtop_alldecay[fjet] = false;
	  
	if(isMC){
	  
	  for(int ngen=0; ngen<ngenelectrons; ngen++){
		  if(delta2R(pfjetAK8y[fjet],pfjetAK8phi[fjet],genelectroneta[ngen],genelectronphi[ngen])<0.6){
		  pfjetAK8haselectron[fjet] = true;
		  break;
		}
	  }
	  
	  for(int ngen=0; ngen<ngenmuons; ngen++){
		  if(delta2R(pfjetAK8y[fjet],pfjetAK8phi[fjet],genmuoneta[ngen],genmuonphi[ngen])<0.6){
		  pfjetAK8hasmuon[fjet] = true;
		  break;
		}
	  }
	  
	  for(int ngen=0; ngen<ngenqgs; ngen++){
		  if(delta2R(pfjetAK8y[fjet],pfjetAK8phi[fjet],genqgeta[ngen],genqgphi[ngen])<0.6){
		  pfjetAK8hasqg[fjet] = true;
		  break;
		}
	  }
	  
	   for(int ngen=0; ngen<ngenbs; ngen++){
		  if(delta2R(pfjetAK8y[fjet],pfjetAK8phi[fjet],genbeta[ngen],genbphi[ngen])<0.6){
		  pfjetAK8hasb[fjet] = true;
		  break;
		}
	  }
	  
	  for(int ngen=0; ngen<ngentops; ngen++){
		  if(delta2R(pfjetAK8y[fjet],pfjetAK8phi[fjet],gentopeta[ngen],gentopphi[ngen])<0.6){
		  pfjetAK8hastop[fjet] = true;
		  break;
		}
	  }
	  
	  for(int ilept=0; ilept<nleptop; ilept++){
		   if(delta2R(pfjetAK8y[fjet],pfjetAK8phi[fjet],leptop4v[ilept].Rapidity(),leptop4v[ilept].Phi())<0.6){
			pfjetAK8hasleptop[fjet] = true;
			break;
		}
	  }
	  
	  for(int ilept=0; ilept<nleptop; ilept++){
//		  if(!pfjetAK8hasleptop[fjet]) continue;
		  bool match[3] = {0};
		  for(int idaut=0; idaut<3; idaut++){
			if(delta2R(pfjetAK8y[fjet],pfjetAK8phi[fjet],leptop4v_daught[idaut][ilept].Rapidity(),leptop4v_daught[idaut][ilept].Phi())<0.8){
				match[idaut] = true;
			}
		}
			if(match[0]&&match[1]&&match[2]){
				pfjetAK8hasleptop_alldecay[fjet] = true;
				break;
			}
	  }
	  
	  for(int ihadt=0; ihadt<nhadtop; ihadt++){
		   if(delta2R(pfjetAK8y[fjet],pfjetAK8phi[fjet],hadtop4v[ihadt].Rapidity(),hadtop4v[ihadt].Phi())<0.6){
			pfjetAK8hashadtop[fjet] = true;
			break;
		}
	  }
	  
	  for(int ihadt=0; ihadt<nhadtop; ihadt++){
//		  if(!pfjetAK8hashadtop[fjet]) continue;
		   bool match[3] = {0};
		   for(int idaut=0; idaut<3; idaut++){
			if(delta2R(pfjetAK8y[fjet],pfjetAK8phi[fjet],hadtop4v_daught[idaut][ihadt].Rapidity(),hadtop4v_daught[idaut][ihadt].Phi())<0.8){
				match[idaut] = true;
			}
		}
			if(match[0]&&match[1]&&match[2]){
				pfjetAK8hashadtop_alldecay[fjet] = true;
				break;
			}
	  }
	  
	}//isMC
	  
	  float minR = 0.4;
	  int pfjetAK8mactAK4_i = -1;
		  
	  for(int kjet=0; kjet<npfjetAK4; kjet++){
		if(delta2R(pfjetAK8y[fjet],pfjetAK8phi[fjet],pfjetAK4y[kjet],pfjetAK4phi[kjet])<minR){
			minR = delta2R(pfjetAK8y[fjet],pfjetAK8phi[fjet],pfjetAK4y[kjet],pfjetAK4phi[kjet]);
			pfjetAK8mactAK4_i = kjet;
		}
	  }
	  
	  if(pfjetAK8mactAK4_i>=0){
		pfjetAK8matchAK4deepb[fjet] = pfjetAK4btag_DeepFlav[pfjetAK8mactAK4_i];
	  }else{
		pfjetAK8matchAK4deepb[fjet] = -100;
	  }
	  
	   if(pfjetAK8mactAK4_i>=0){
		pfjetAK8matchAK4deepCSVb[fjet] = pfjetAK4btag_DeepCSV[pfjetAK8mactAK4_i];
	  }else{
		pfjetAK8matchAK4deepCSVb[fjet] = -100;
	  }
		 
	  fjet++;
	  if(fjet>=njetmxAK8) break;
		 
	  }
      
	  npfjetAK8 = fjet;
/*		  
	  for(int ijet=0; ijet<	npfjetAK8; ijet++){
		for(int kjet=(ijet+1); kjet < npfjetAK8; kjet++){
		   
			if(pfjetAK8pt[kjet]>pfjetAK8pt[ijet]){
			
				float tmppt;
				
				tmppt = pfjetAK8pt[ijet];
				pfjetAK8pt[ijet] = pfjetAK8pt[kjet];
				pfjetAK8pt[kjet] = tmppt;
			  
				tmppt = pfjetAK8y[ijet];
				pfjetAK8y[ijet] = pfjetAK8y[kjet];
				pfjetAK8y[kjet] = tmppt;
					
				tmppt = pfjetAK8phi[ijet];
				pfjetAK8phi[ijet] = pfjetAK8phi[kjet];
				pfjetAK8phi[kjet] = tmppt;
					
				tmppt = pfjetAK8mass[ijet];
				pfjetAK8mass[ijet] = pfjetAK8mass[kjet];
				pfjetAK8mass[kjet] = tmppt;
					
				tmppt = pfjetAK8btag_CMVA[ijet];
				pfjetAK8btag_CMVA[ijet] = pfjetAK8btag_CMVA[kjet];
				pfjetAK8btag_CMVA[kjet] = tmppt;
						
				tmppt = pfjetAK8btag_DeepCSV[ijet];
				pfjetAK8btag_DeepCSV[ijet] = pfjetAK8btag_DeepCSV[kjet];
				pfjetAK8btag_DeepCSV[kjet] = tmppt;
					
				tmppt = pfjetAK8matchAK4deepb[ijet];
				pfjetAK8matchAK4deepb[ijet] = pfjetAK8matchAK4deepb[kjet];
				pfjetAK8matchAK4deepb[kjet] = tmppt;
					
				tmppt = pfjetAK8DeepTag_TvsQCD[ijet];
				pfjetAK8DeepTag_TvsQCD[ijet] = pfjetAK8DeepTag_TvsQCD[kjet];
				pfjetAK8DeepTag_TvsQCD[kjet] = tmppt;
					
				tmppt = pfjetAK8DeepTag_WvsQCD[ijet];
				pfjetAK8DeepTag_WvsQCD[ijet] = pfjetAK8DeepTag_WvsQCD[kjet];
				pfjetAK8DeepTag_WvsQCD[kjet] = tmppt;
					
				tmppt = pfjetAK8DeepTag_ZvsQCD[ijet];
				pfjetAK8DeepTag_ZvsQCD[ijet] = pfjetAK8DeepTag_ZvsQCD[kjet];
				pfjetAK8DeepTag_ZvsQCD[kjet] = tmppt;
					
				tmppt = pfjetAK8CHF[ijet];
				pfjetAK8CHF[ijet] = pfjetAK8CHF[kjet];
				pfjetAK8CHF[kjet] = tmppt;
					
				tmppt = pfjetAK8NHF[ijet];
				pfjetAK8NHF[ijet] = pfjetAK8NHF[kjet];
				pfjetAK8NHF[kjet] = tmppt;
				
				tmppt = pfjetAK8CEMF[ijet];
				pfjetAK8CEMF[ijet] = pfjetAK8CEMF[kjet];
				pfjetAK8CEMF[kjet] = tmppt;
					
				tmppt = pfjetAK8NEMF[ijet];
				pfjetAK8NEMF[ijet] = pfjetAK8NEMF[kjet];
				pfjetAK8NEMF[kjet] = tmppt;
					
				tmppt = pfjetAK8MUF[ijet];
				pfjetAK8MUF[ijet] = pfjetAK8MUF[kjet];
				pfjetAK8MUF[kjet] = tmppt;
					
				tmppt = pfjetAK8PHF[ijet];
				pfjetAK8PHF[ijet] = pfjetAK8PHF[kjet];
				pfjetAK8PHF[kjet] = tmppt;
					
				tmppt = pfjetAK8HOF[ijet];
				pfjetAK8HOF[ijet] = pfjetAK8HOF[kjet];
				pfjetAK8HOF[kjet] = tmppt;
					
				tmppt = pfjetAK8chrad[ijet];
				pfjetAK8chrad[ijet] = pfjetAK8chrad[kjet];
				pfjetAK8chrad[kjet] = tmppt;
					
				tmppt = pfjetAK8pTD[ijet];
				pfjetAK8pTD[ijet] = pfjetAK8pTD[kjet];
				pfjetAK8pTD[kjet] = tmppt;
					
				tmppt = pfjetAK8sdmass[ijet];
				pfjetAK8sdmass[ijet] = pfjetAK8sdmass[kjet];
				pfjetAK8sdmass[kjet] = tmppt;
					
				tmppt = pfjetAK8tau21[ijet];
				pfjetAK8tau21[ijet] = pfjetAK8tau21[kjet];
				pfjetAK8tau21[kjet] = tmppt;
					
				tmppt = pfjetAK8tau32[ijet];
				pfjetAK8tau32[ijet] = pfjetAK8tau32[kjet];
				pfjetAK8tau32[kjet] = tmppt;
					
				tmppt = pfjetAK8sub1mass[ijet];
				pfjetAK8sub1mass[ijet] = pfjetAK8sub1mass[kjet];
				pfjetAK8sub1mass[kjet] = tmppt;
					
				tmppt = pfjetAK8sub1btag[ijet];
				pfjetAK8sub1btag[ijet] = pfjetAK8sub1btag[kjet];
				pfjetAK8sub1btag[kjet] = tmppt;
					
				tmppt = pfjetAK8sub1hadfrac[ijet];
				pfjetAK8sub1hadfrac[ijet] = pfjetAK8sub1hadfrac[kjet];
				pfjetAK8sub1hadfrac[kjet] = tmppt;
				
				tmppt = pfjetAK8sub1emfrac[ijet];
				pfjetAK8sub1emfrac[ijet] = pfjetAK8sub1emfrac[kjet];
				pfjetAK8sub1emfrac[kjet] = tmppt;
					
				tmppt = pfjetAK8sub2mass[ijet];
				pfjetAK8sub2mass[ijet] = pfjetAK8sub2mass[kjet];
				pfjetAK8sub2mass[kjet] = tmppt;
					
				tmppt = pfjetAK8sub2btag[ijet];
				pfjetAK8sub2btag[ijet] = pfjetAK8sub2btag[kjet];
				pfjetAK8sub2btag[kjet] = tmppt;
					
				tmppt = pfjetAK8sub2hadfrac[ijet];
				pfjetAK8sub2hadfrac[ijet] = pfjetAK8sub2hadfrac[kjet];
				pfjetAK8sub2hadfrac[kjet] = tmppt;
					
				tmppt = pfjetAK8sub2emfrac[ijet];
				pfjetAK8sub2emfrac[ijet] = pfjetAK8sub2emfrac[kjet];
				pfjetAK8sub2emfrac[kjet] = tmppt;
					
				tmppt = pfjetAK8subhaddiff[ijet];
				pfjetAK8subhaddiff[ijet] = pfjetAK8subhaddiff[kjet];
				pfjetAK8subhaddiff[kjet] = tmppt;
				
				tmppt = pfjetAK8subemdiff[ijet];
				pfjetAK8subemdiff[ijet] = pfjetAK8subemdiff[kjet];
				pfjetAK8subemdiff[kjet] = tmppt;
				
				tmppt = pfjetAK8subptdiff[ijet];
				pfjetAK8subptdiff[ijet] = pfjetAK8subptdiff[kjet];
				pfjetAK8subptdiff[kjet] = tmppt;
				
				int tmpid = pfjetAK8CHM[ijet];
				pfjetAK8CHM[ijet] = pfjetAK8CHM[kjet];
				pfjetAK8CHM[kjet] = tmpid;
					
				tmpid = pfjetAK8NHM[ijet];
				pfjetAK8NHM[ijet] = pfjetAK8NHM[kjet];
				pfjetAK8NHM[kjet] = tmpid;
					
				tmpid = pfjetAK8CEMM[ijet];
				pfjetAK8CEMM[ijet] = pfjetAK8CEMM[kjet];
				pfjetAK8CEMM[kjet] = tmpid;
					
				tmpid = pfjetAK8NEMM[ijet];
				pfjetAK8NEMM[ijet] = pfjetAK8NEMM[kjet];
				pfjetAK8NEMM[kjet] = tmpid;
				
				tmpid = pfjetAK8MUM[ijet];
				pfjetAK8MUM[ijet] = pfjetAK8MUM[kjet];
				pfjetAK8MUM[kjet] = tmpid;
					
				tmpid = pfjetAK8Neucons[ijet];
				pfjetAK8Neucons[ijet] = pfjetAK8Neucons[kjet];
				pfjetAK8Neucons[kjet] = tmpid;
					
				tmpid = pfjetAK8Chcons[ijet];
				pfjetAK8Chcons[ijet] = pfjetAK8Chcons[kjet];
				pfjetAK8Chcons[kjet] = tmpid;
				
				bool tmpbool = pfjetAK8haselectron[ijet];
				pfjetAK8haselectron[ijet] = pfjetAK8haselectron[kjet];
				pfjetAK8haselectron[kjet] = tmpbool;
				
				tmpbool = pfjetAK8hasmuon[ijet];
				pfjetAK8hasmuon[ijet] = pfjetAK8hasmuon[kjet];
				pfjetAK8hasmuon[kjet] = tmpbool;
				
				tmpbool = pfjetAK8hasleptop[ijet];
				pfjetAK8hasleptop[ijet] = pfjetAK8hasleptop[kjet];
				pfjetAK8hasleptop[kjet] = tmpbool;
				
				tmpbool = pfjetAK8hashadtop[ijet];
				pfjetAK8hashadtop[ijet] = pfjetAK8hashadtop[kjet];
				pfjetAK8hashadtop[kjet] = tmpbool;
				
				tmpbool = pfjetAK8hastop[ijet];
				pfjetAK8hastop[ijet] = pfjetAK8hastop[kjet];
				pfjetAK8hastop[kjet] = tmpbool;
				
				tmpbool = pfjetAK8hasqg[ijet];
				pfjetAK8hasqg[ijet] = pfjetAK8hasqg[kjet];
				pfjetAK8hasqg[kjet] = tmpbool;
				
			  }
		   } //kjet
		}//ijet
*/		

hist_npv->Fill(nchict,weight);
if(isMC){
	hist_npu->Fill(npu_vert,weight);
}

//PFMET = PFMET;

for(int ijet=0; ijet< npfjetAK8; ijet++){
	
	if(ijet>(nmaxjet-1)) break;
	
	if(isnan(pfjetAK8pt[ijet])) { pfjetAK8pt[ijet] = -100; }
	if(isnan(pfjetAK8y[ijet])) { pfjetAK8y[ijet] = -100; }
	if(isnan(pfjetAK8mass[ijet])) { pfjetAK8mass[ijet] = -100; }
	if(isnan(pfjetAK8phi[ijet])) { pfjetAK8phi[ijet] = -100; }
	if(isnan(pfjetAK8btag_CMVA[ijet])) { pfjetAK8btag_CMVA[ijet] = -100; }
	if(isnan(pfjetAK8btag_CSV[ijet])) { pfjetAK8btag_CSV[ijet] = -100; }
	if(isnan(pfjetAK8btag_DeepCSV[ijet])) { pfjetAK8btag_DeepCSV[ijet] = -100; }
	if(isnan(pfjetAK8matchAK4deepb[ijet])) { pfjetAK8matchAK4deepb[ijet] = -100; }
	if(isnan(pfjetAK8matchAK4deepCSVb[ijet])) { pfjetAK8matchAK4deepCSVb[ijet] = -100; }
	if(isnan(pfjetAK8DeepTag_TvsQCD[ijet])) { pfjetAK8DeepTag_TvsQCD[ijet] = -100; }
	if(isnan(pfjetAK8DeepTag_WvsQCD[ijet])) { pfjetAK8DeepTag_WvsQCD[ijet] = -100; }
	if(isnan(pfjetAK8DeepTag_ZvsQCD[ijet])) { pfjetAK8DeepTag_ZvsQCD[ijet] = -100; }
	if(isnan(pfjetAK8CHF[ijet])) { pfjetAK8CHF[ijet] = -100; }
	if(isnan(pfjetAK8NHF[ijet])) { pfjetAK8NHF[ijet] = -100; }
	if(isnan(pfjetAK8CEMF[ijet])) { pfjetAK8CEMF[ijet] = -100; }
	if(isnan(pfjetAK8NEMF[ijet])) { pfjetAK8NEMF[ijet] = -100; }
	if(isnan(pfjetAK8MUF[ijet])) { pfjetAK8MUF[ijet] = -100; }
	if(isnan(pfjetAK8HOF[ijet])) { pfjetAK8HOF[ijet] = -100; }
	if(isnan(pfjetAK8HadF[ijet])) { pfjetAK8HadF[ijet] = -100; }
	if(isnan(pfjetAK8NHadF[ijet])) { pfjetAK8NHadF[ijet] = -100; }
	if(isnan(pfjetAK8EmF[ijet])) { pfjetAK8EmF[ijet] = -100; }
	if(isnan(pfjetAK8neuemfrac[ijet])) { pfjetAK8neuemfrac[ijet] = -100; }
	if(isnan(pfjetAK8neunhadfrac[ijet])) { pfjetAK8neunhadfrac[ijet] = -100; }
	if(isnan(pfjetAK8EEM[ijet])) { pfjetAK8EEM[ijet] = -100; }
	if(isnan(pfjetAK8chrad[ijet])) { pfjetAK8chrad[ijet] = -100; }
	if(isnan(pfjetAK8pTD[ijet])) { pfjetAK8pTD[ijet] = -100; }
	if(isnan(pfjetAK8sdmass[ijet])) { pfjetAK8sdmass[ijet] = -100; }
	if(isnan(pfjetAK8tau21[ijet])) { pfjetAK8tau21[ijet] = -100; }
	if(isnan(pfjetAK8tau32[ijet])) { pfjetAK8tau32[ijet] = -100; }
	if(isnan(pfjetAK8sub1mass[ijet])) { pfjetAK8sub1mass[ijet] = -100; }
	if(isnan(pfjetAK8sub1btag[ijet])) { pfjetAK8sub1btag[ijet] = -100; }
	if(isnan(pfjetAK8sub1hadfrac[ijet])) { pfjetAK8sub1hadfrac[ijet] = -100; }
	if(isnan(pfjetAK8sub1emfrac[ijet])) { pfjetAK8sub1emfrac[ijet] = -100; }
	if(isnan(pfjetAK8sub2mass[ijet])) { pfjetAK8sub2mass[ijet] = -100; }
	if(isnan(pfjetAK8sub2btag[ijet])) { pfjetAK8sub2btag[ijet] = -100; }
	if(isnan(pfjetAK8sub2hadfrac[ijet])) { pfjetAK8sub2hadfrac[ijet] = -100; }
	if(isnan(pfjetAK8sub2emfrac[ijet])) { pfjetAK8sub2emfrac[ijet] = -100; }
	if(isnan(pfjetAK8subhaddiff[ijet])) { pfjetAK8subhaddiff[ijet] = -100; }
	if(isnan(pfjetAK8subemdiff[ijet])) { pfjetAK8subemdiff[ijet] = -100; }
	if(isnan(pfjetAK8subptdiff[ijet])) { pfjetAK8subptdiff[ijet] = -100; }
	if(isnan(pfjetAK8subbtag[ijet])) { pfjetAK8subbtag[ijet] = -100; }
	if(isnan(pfjetAK8haselectron[ijet])) { pfjetAK8haselectron[ijet] = -100; }
	if(isnan(pfjetAK8hasmuon[ijet])) { pfjetAK8hasmuon[ijet] = -100; }
	if(isnan(pfjetAK8hasleptop[ijet])) { pfjetAK8hasleptop[ijet] = -100; }
	if(isnan(pfjetAK8hashadtop[ijet])) { pfjetAK8hashadtop[ijet] = -100; }
	if(isnan(pfjetAK8hasqg[ijet])) { pfjetAK8hasqg[ijet] = -100; }
	if(isnan(pfjetAK8hasb[ijet])) { pfjetAK8hasb[ijet] = -100; }
	if(isnan(pfjetAK8hashadtop_alldecay[ijet])) { pfjetAK8hashadtop_alldecay[ijet] = -100; }
	if(isnan(pfjetAK8hasleptop_alldecay[ijet])) { pfjetAK8hasleptop_alldecay[ijet] = -100; }
	if(isnan(pfjetAK8_bbyW_E[ijet])) { pfjetAK8_bbyW_E[ijet] = -100; }
	if(isnan(pfjetAK8_Kfactor[ijet])) { pfjetAK8_Kfactor[ijet] = -100; }
	if(isnan(pfjetAK8_Rnew[ijet])) { pfjetAK8_Rnew[ijet] = -100; }
	if(isnan(pfjetAK8_leppt[ijet])) { pfjetAK8_leppt[ijet] = -100; }
	if(isnan(pfjetAK8_bpt[ijet])) { pfjetAK8_bpt[ijet] = -100; }
	if(isnan(pfjetAK8_nupt[ijet])) { pfjetAK8_nupt[ijet] = -100; }
	
    Float_t Re(-100);
    
	in_pfjetAK8NHadF = pfjetAK8NHadF[ijet];
	in_pfjetAK8neunhadfrac = pfjetAK8neunhadfrac[ijet];
	in_pfjetAK8subhaddiff = pfjetAK8subhaddiff[ijet];
	in_pfjetAK8tau21 = pfjetAK8tau21[ijet];
	in_pfjetAK8chrad = pfjetAK8chrad[ijet];
	in_pfjetAK8sdmass = pfjetAK8sdmass[ijet];
	
//	Re = reader1->EvaluateMVA("BDTG method");
	pfjetAK8re_tvsb[ijet] = Re;
	
	in_pfjetAK8_bbyW_E = pfjetAK8_bbyW_E[ijet];
	in_pfjetAK8_Kfactor = pfjetAK8_Kfactor[ijet];
	
    Float_t Rnu(-100);
	
//	Rnu = reader2->EvaluateMVA("BDTG method");
    pfjetAK8rnu_tvsb[ijet] = Rnu;
	
	bool te_cond = false;
	bool tmu_cond = false;
	bool thad_cond = false;
	bool qg_cond = false;
	bool b_cond = false;
	
	te_cond  = (pfjetAK8haselectron[ijet] && pfjetAK8hasleptop[ijet] && pfjetAK8hastop[ijet] && pfjetAK8hasleptop_alldecay[ijet]);
	tmu_cond = (pfjetAK8hasmuon[ijet] && pfjetAK8hasleptop[ijet] && pfjetAK8hastop[ijet] && pfjetAK8hasleptop_alldecay[ijet]);
	thad_cond = (pfjetAK8hashadtop[ijet] && pfjetAK8hastop[ijet] && pfjetAK8hashadtop_alldecay[ijet]);
	qg_cond = (pfjetAK8hasqg[ijet] && !(pfjetAK8hashadtop[ijet]) && !(pfjetAK8hasleptop[ijet]) && !(pfjetAK8hastop[ijet]));
	b_cond = (pfjetAK8hasb[ijet] && !(pfjetAK8hashadtop[ijet]) && !(pfjetAK8hasleptop[ijet]) && !(pfjetAK8hastop[ijet]));
	
if(te_cond){
	
hist_1[0]->Fill(pfjetAK8pt[ijet],weight);
hist_1[1]->Fill(pfjetAK8y[ijet],weight);
hist_1[2]->Fill(pfjetAK8phi[ijet],weight);
hist_1[3]->Fill(pfjetAK8mass[ijet],weight);
hist_1[4]->Fill(pfjetAK8btag_CMVA[ijet],weight);
hist_1[5]->Fill(pfjetAK8btag_CSV[ijet],weight);
hist_1[6]->Fill(pfjetAK8btag_DeepCSV[ijet],weight);
hist_1[7]->Fill(pfjetAK8matchAK4deepb[ijet],weight);
hist_1[8]->Fill(pfjetAK8DeepTag_TvsQCD[ijet],weight);
hist_1[9]->Fill(pfjetAK8DeepTag_WvsQCD[ijet],weight);
hist_1[10]->Fill(pfjetAK8DeepTag_ZvsQCD[ijet],weight);
hist_1[11]->Fill(pfjetAK8CHF[ijet],weight);
hist_1[12]->Fill(pfjetAK8NHF[ijet],weight);
hist_1[13]->Fill(pfjetAK8CEMF[ijet],weight);
hist_1[14]->Fill(pfjetAK8NEMF[ijet],weight);
hist_1[15]->Fill(pfjetAK8MUF[ijet],weight);
hist_1[16]->Fill(pfjetAK8HOF[ijet],weight);
hist_1[17]->Fill(pfjetAK8HadF[ijet],weight);
hist_1[18]->Fill(pfjetAK8NHadF[ijet],weight);
hist_1[19]->Fill(pfjetAK8EmF[ijet],weight);
hist_1[20]->Fill(pfjetAK8neuemfrac[ijet],weight);
hist_1[21]->Fill(pfjetAK8neunhadfrac[ijet],weight);
hist_1[22]->Fill(pfjetAK8chrad[ijet],weight);
hist_1[23]->Fill(pfjetAK8pTD[ijet],weight);
hist_1[24]->Fill(pfjetAK8sdmass[ijet],weight);
hist_1[25]->Fill(pfjetAK8tau21[ijet],weight);
hist_1[26]->Fill(pfjetAK8tau32[ijet],weight);
hist_1[27]->Fill(pfjetAK8sub1mass[ijet],weight);
hist_1[28]->Fill(pfjetAK8sub1btag[ijet],weight);
hist_1[29]->Fill(pfjetAK8sub1hadfrac[ijet],weight);
hist_1[30]->Fill(pfjetAK8sub1emfrac[ijet],weight);
hist_1[31]->Fill(pfjetAK8sub2mass[ijet],weight);
hist_1[32]->Fill(pfjetAK8sub2btag[ijet],weight);
hist_1[33]->Fill(pfjetAK8sub2hadfrac[ijet],weight);
hist_1[34]->Fill(pfjetAK8sub2emfrac[ijet],weight);
hist_1[35]->Fill(pfjetAK8subhaddiff[ijet],weight);
hist_1[36]->Fill(pfjetAK8subemdiff[ijet],weight);
hist_1[37]->Fill(pfjetAK8subptdiff[ijet],weight);
hist_1[38]->Fill(pfjetAK8subbtag[ijet],weight);
hist_1[39]->Fill(pfjetAK8_leppt[ijet],weight);
hist_1[40]->Fill(pfjetAK8_bpt[ijet],weight);
hist_1[41]->Fill(pfjetAK8_nupt[ijet],weight);
hist_1[42]->Fill(pfjetAK8_Rnew[ijet],weight);
hist_1[43]->Fill(pfjetAK8_bbyW_E[ijet],weight);
hist_1[44]->Fill(pfjetAK8_Kfactor[ijet],weight);
hist_1[45]->Fill(pfjetAK8re_tvsb[ijet],weight);
hist_1[46]->Fill(pfjetAK8rnu_tvsb[ijet],weight);

h2d_re_rnu_1->Fill(pfjetAK8re_tvsb[ijet],pfjetAK8rnu_tvsb[ijet],weight);
}

if(tmu_cond){

hist_2[0]->Fill(pfjetAK8pt[ijet],weight);
hist_2[1]->Fill(pfjetAK8y[ijet],weight);
hist_2[2]->Fill(pfjetAK8phi[ijet],weight);
hist_2[3]->Fill(pfjetAK8mass[ijet],weight);
hist_2[4]->Fill(pfjetAK8btag_CMVA[ijet],weight);
hist_2[5]->Fill(pfjetAK8btag_CSV[ijet],weight);
hist_2[6]->Fill(pfjetAK8btag_DeepCSV[ijet],weight);
hist_2[7]->Fill(pfjetAK8matchAK4deepb[ijet],weight);
hist_2[8]->Fill(pfjetAK8DeepTag_TvsQCD[ijet],weight);
hist_2[9]->Fill(pfjetAK8DeepTag_WvsQCD[ijet],weight);
hist_2[10]->Fill(pfjetAK8DeepTag_ZvsQCD[ijet],weight);
hist_2[11]->Fill(pfjetAK8CHF[ijet],weight);
hist_2[12]->Fill(pfjetAK8NHF[ijet],weight);
hist_2[13]->Fill(pfjetAK8CEMF[ijet],weight);
hist_2[14]->Fill(pfjetAK8NEMF[ijet],weight);
hist_2[15]->Fill(pfjetAK8MUF[ijet],weight);
hist_2[16]->Fill(pfjetAK8HOF[ijet],weight);
hist_2[17]->Fill(pfjetAK8HadF[ijet],weight);
hist_2[18]->Fill(pfjetAK8NHadF[ijet],weight);
hist_2[19]->Fill(pfjetAK8EmF[ijet],weight);
hist_2[20]->Fill(pfjetAK8neuemfrac[ijet],weight);
hist_2[21]->Fill(pfjetAK8neunhadfrac[ijet],weight);
hist_2[22]->Fill(pfjetAK8chrad[ijet],weight);
hist_2[23]->Fill(pfjetAK8pTD[ijet],weight);
hist_2[24]->Fill(pfjetAK8sdmass[ijet],weight);
hist_2[25]->Fill(pfjetAK8tau21[ijet],weight);
hist_2[26]->Fill(pfjetAK8tau32[ijet],weight);
hist_2[27]->Fill(pfjetAK8sub1mass[ijet],weight);
hist_2[28]->Fill(pfjetAK8sub1btag[ijet],weight);
hist_2[29]->Fill(pfjetAK8sub1hadfrac[ijet],weight);
hist_2[30]->Fill(pfjetAK8sub1emfrac[ijet],weight);
hist_2[31]->Fill(pfjetAK8sub2mass[ijet],weight);
hist_2[32]->Fill(pfjetAK8sub2btag[ijet],weight);
hist_2[33]->Fill(pfjetAK8sub2hadfrac[ijet],weight);
hist_2[34]->Fill(pfjetAK8sub2emfrac[ijet],weight);
hist_2[35]->Fill(pfjetAK8subhaddiff[ijet],weight);
hist_2[36]->Fill(pfjetAK8subemdiff[ijet],weight);
hist_2[37]->Fill(pfjetAK8subptdiff[ijet],weight);
hist_2[38]->Fill(pfjetAK8subbtag[ijet],weight);
hist_2[39]->Fill(pfjetAK8_leppt[ijet],weight);
hist_2[40]->Fill(pfjetAK8_bpt[ijet],weight);
hist_2[41]->Fill(pfjetAK8_nupt[ijet],weight);
hist_2[42]->Fill(pfjetAK8_Rnew[ijet],weight);
hist_2[43]->Fill(pfjetAK8_bbyW_E[ijet],weight);
hist_2[44]->Fill(pfjetAK8_Kfactor[ijet],weight);
hist_2[45]->Fill(pfjetAK8re_tvsb[ijet],weight);
hist_2[46]->Fill(pfjetAK8rnu_tvsb[ijet],weight);

h2d_re_rnu_2->Fill(pfjetAK8re_tvsb[ijet],pfjetAK8rnu_tvsb[ijet],weight);
}

if(thad_cond){

hist_3[0]->Fill(pfjetAK8pt[ijet],weight);
hist_3[1]->Fill(pfjetAK8y[ijet],weight);
hist_3[2]->Fill(pfjetAK8phi[ijet],weight);
hist_3[3]->Fill(pfjetAK8mass[ijet],weight);
hist_3[4]->Fill(pfjetAK8btag_CMVA[ijet],weight);
hist_3[5]->Fill(pfjetAK8btag_CSV[ijet],weight);
hist_3[6]->Fill(pfjetAK8btag_DeepCSV[ijet],weight);
hist_3[7]->Fill(pfjetAK8matchAK4deepb[ijet],weight);
hist_3[8]->Fill(pfjetAK8DeepTag_TvsQCD[ijet],weight);
hist_3[9]->Fill(pfjetAK8DeepTag_WvsQCD[ijet],weight);
hist_3[10]->Fill(pfjetAK8DeepTag_ZvsQCD[ijet],weight);
hist_3[11]->Fill(pfjetAK8CHF[ijet],weight);
hist_3[12]->Fill(pfjetAK8NHF[ijet],weight);
hist_3[13]->Fill(pfjetAK8CEMF[ijet],weight);
hist_3[14]->Fill(pfjetAK8NEMF[ijet],weight);
hist_3[15]->Fill(pfjetAK8MUF[ijet],weight);
hist_3[16]->Fill(pfjetAK8HOF[ijet],weight);
hist_3[17]->Fill(pfjetAK8HadF[ijet],weight);
hist_3[18]->Fill(pfjetAK8NHadF[ijet],weight);
hist_3[19]->Fill(pfjetAK8EmF[ijet],weight);
hist_3[20]->Fill(pfjetAK8neuemfrac[ijet],weight);
hist_3[21]->Fill(pfjetAK8neunhadfrac[ijet],weight);
hist_3[22]->Fill(pfjetAK8chrad[ijet],weight);
hist_3[23]->Fill(pfjetAK8pTD[ijet],weight);
hist_3[24]->Fill(pfjetAK8sdmass[ijet],weight);
hist_3[25]->Fill(pfjetAK8tau21[ijet],weight);
hist_3[26]->Fill(pfjetAK8tau32[ijet],weight);
hist_3[27]->Fill(pfjetAK8sub1mass[ijet],weight);
hist_3[28]->Fill(pfjetAK8sub1btag[ijet],weight);
hist_3[29]->Fill(pfjetAK8sub1hadfrac[ijet],weight);
hist_3[30]->Fill(pfjetAK8sub1emfrac[ijet],weight);
hist_3[31]->Fill(pfjetAK8sub2mass[ijet],weight);
hist_3[32]->Fill(pfjetAK8sub2btag[ijet],weight);
hist_3[33]->Fill(pfjetAK8sub2hadfrac[ijet],weight);
hist_3[34]->Fill(pfjetAK8sub2emfrac[ijet],weight);
hist_3[35]->Fill(pfjetAK8subhaddiff[ijet],weight);
hist_3[36]->Fill(pfjetAK8subemdiff[ijet],weight);
hist_3[37]->Fill(pfjetAK8subptdiff[ijet],weight);
hist_3[38]->Fill(pfjetAK8subbtag[ijet],weight);
hist_3[39]->Fill(pfjetAK8_leppt[ijet],weight);
hist_3[40]->Fill(pfjetAK8_bpt[ijet],weight);
hist_3[41]->Fill(pfjetAK8_nupt[ijet],weight);
hist_3[42]->Fill(pfjetAK8_Rnew[ijet],weight);
hist_3[43]->Fill(pfjetAK8_bbyW_E[ijet],weight);
hist_3[44]->Fill(pfjetAK8_Kfactor[ijet],weight);
hist_3[45]->Fill(pfjetAK8re_tvsb[ijet],weight);
hist_3[46]->Fill(pfjetAK8rnu_tvsb[ijet],weight);

h2d_re_rnu_3->Fill(pfjetAK8re_tvsb[ijet],pfjetAK8rnu_tvsb[ijet],weight);
}

if(qg_cond){

hist_4[0]->Fill(pfjetAK8pt[ijet],weight);
hist_4[1]->Fill(pfjetAK8y[ijet],weight);
hist_4[2]->Fill(pfjetAK8phi[ijet],weight);
hist_4[3]->Fill(pfjetAK8mass[ijet],weight);
hist_4[4]->Fill(pfjetAK8btag_CMVA[ijet],weight);
hist_4[5]->Fill(pfjetAK8btag_CSV[ijet],weight);
hist_4[6]->Fill(pfjetAK8btag_DeepCSV[ijet],weight);
hist_4[7]->Fill(pfjetAK8matchAK4deepb[ijet],weight);
hist_4[8]->Fill(pfjetAK8DeepTag_TvsQCD[ijet],weight);
hist_4[9]->Fill(pfjetAK8DeepTag_WvsQCD[ijet],weight);
hist_4[10]->Fill(pfjetAK8DeepTag_ZvsQCD[ijet],weight);
hist_4[11]->Fill(pfjetAK8CHF[ijet],weight);
hist_4[12]->Fill(pfjetAK8NHF[ijet],weight);
hist_4[13]->Fill(pfjetAK8CEMF[ijet],weight);
hist_4[14]->Fill(pfjetAK8NEMF[ijet],weight);
hist_4[15]->Fill(pfjetAK8MUF[ijet],weight);
hist_4[16]->Fill(pfjetAK8HOF[ijet],weight);
hist_4[17]->Fill(pfjetAK8HadF[ijet],weight);
hist_4[18]->Fill(pfjetAK8NHadF[ijet],weight);
hist_4[19]->Fill(pfjetAK8EmF[ijet],weight);
hist_4[20]->Fill(pfjetAK8neuemfrac[ijet],weight);
hist_4[21]->Fill(pfjetAK8neunhadfrac[ijet],weight);
hist_4[22]->Fill(pfjetAK8chrad[ijet],weight);
hist_4[23]->Fill(pfjetAK8pTD[ijet],weight);
hist_4[24]->Fill(pfjetAK8sdmass[ijet],weight);
hist_4[25]->Fill(pfjetAK8tau21[ijet],weight);
hist_4[26]->Fill(pfjetAK8tau32[ijet],weight);
hist_4[27]->Fill(pfjetAK8sub1mass[ijet],weight);
hist_4[28]->Fill(pfjetAK8sub1btag[ijet],weight);
hist_4[29]->Fill(pfjetAK8sub1hadfrac[ijet],weight);
hist_4[30]->Fill(pfjetAK8sub1emfrac[ijet],weight);
hist_4[31]->Fill(pfjetAK8sub2mass[ijet],weight);
hist_4[32]->Fill(pfjetAK8sub2btag[ijet],weight);
hist_4[33]->Fill(pfjetAK8sub2hadfrac[ijet],weight);
hist_4[34]->Fill(pfjetAK8sub2emfrac[ijet],weight);
hist_4[35]->Fill(pfjetAK8subhaddiff[ijet],weight);
hist_4[36]->Fill(pfjetAK8subemdiff[ijet],weight);
hist_4[37]->Fill(pfjetAK8subptdiff[ijet],weight);
hist_4[38]->Fill(pfjetAK8subbtag[ijet],weight);
hist_4[39]->Fill(pfjetAK8_leppt[ijet],weight);
hist_4[40]->Fill(pfjetAK8_bpt[ijet],weight);
hist_4[41]->Fill(pfjetAK8_nupt[ijet],weight);
hist_4[42]->Fill(pfjetAK8_Rnew[ijet],weight);
hist_4[43]->Fill(pfjetAK8_bbyW_E[ijet],weight);
hist_4[44]->Fill(pfjetAK8_Kfactor[ijet],weight);
hist_4[45]->Fill(pfjetAK8re_tvsb[ijet],weight);
hist_4[46]->Fill(pfjetAK8rnu_tvsb[ijet],weight);

h2d_re_rnu_4->Fill(pfjetAK8re_tvsb[ijet],pfjetAK8rnu_tvsb[ijet],weight);
}

if(b_cond){

hist_5[0]->Fill(pfjetAK8pt[ijet],weight);
hist_5[1]->Fill(pfjetAK8y[ijet],weight);
hist_5[2]->Fill(pfjetAK8phi[ijet],weight);
hist_5[3]->Fill(pfjetAK8mass[ijet],weight);
hist_5[4]->Fill(pfjetAK8btag_CMVA[ijet],weight);
hist_5[5]->Fill(pfjetAK8btag_CSV[ijet],weight);
hist_5[6]->Fill(pfjetAK8btag_DeepCSV[ijet],weight);
hist_5[7]->Fill(pfjetAK8matchAK4deepb[ijet],weight);
hist_5[8]->Fill(pfjetAK8DeepTag_TvsQCD[ijet],weight);
hist_5[9]->Fill(pfjetAK8DeepTag_WvsQCD[ijet],weight);
hist_5[10]->Fill(pfjetAK8DeepTag_ZvsQCD[ijet],weight);
hist_5[11]->Fill(pfjetAK8CHF[ijet],weight);
hist_5[12]->Fill(pfjetAK8NHF[ijet],weight);
hist_5[13]->Fill(pfjetAK8CEMF[ijet],weight);
hist_5[14]->Fill(pfjetAK8NEMF[ijet],weight);
hist_5[15]->Fill(pfjetAK8MUF[ijet],weight);
hist_5[16]->Fill(pfjetAK8HOF[ijet],weight);
hist_5[17]->Fill(pfjetAK8HadF[ijet],weight);
hist_5[18]->Fill(pfjetAK8NHadF[ijet],weight);
hist_5[19]->Fill(pfjetAK8EmF[ijet],weight);
hist_5[20]->Fill(pfjetAK8neuemfrac[ijet],weight);
hist_5[21]->Fill(pfjetAK8neunhadfrac[ijet],weight);
hist_5[22]->Fill(pfjetAK8chrad[ijet],weight);
hist_5[23]->Fill(pfjetAK8pTD[ijet],weight);
hist_5[24]->Fill(pfjetAK8sdmass[ijet],weight);
hist_5[25]->Fill(pfjetAK8tau21[ijet],weight);
hist_5[26]->Fill(pfjetAK8tau32[ijet],weight);
hist_5[27]->Fill(pfjetAK8sub1mass[ijet],weight);
hist_5[28]->Fill(pfjetAK8sub1btag[ijet],weight);
hist_5[29]->Fill(pfjetAK8sub1hadfrac[ijet],weight);
hist_5[30]->Fill(pfjetAK8sub1emfrac[ijet],weight);
hist_5[31]->Fill(pfjetAK8sub2mass[ijet],weight);
hist_5[32]->Fill(pfjetAK8sub2btag[ijet],weight);
hist_5[33]->Fill(pfjetAK8sub2hadfrac[ijet],weight);
hist_5[34]->Fill(pfjetAK8sub2emfrac[ijet],weight);
hist_5[35]->Fill(pfjetAK8subhaddiff[ijet],weight);
hist_5[36]->Fill(pfjetAK8subemdiff[ijet],weight);
hist_5[37]->Fill(pfjetAK8subptdiff[ijet],weight);
hist_5[38]->Fill(pfjetAK8subbtag[ijet],weight);
hist_5[39]->Fill(pfjetAK8_leppt[ijet],weight);
hist_5[40]->Fill(pfjetAK8_bpt[ijet],weight);
hist_5[41]->Fill(pfjetAK8_nupt[ijet],weight);
hist_5[42]->Fill(pfjetAK8_Rnew[ijet],weight);
hist_5[43]->Fill(pfjetAK8_bbyW_E[ijet],weight);
hist_5[44]->Fill(pfjetAK8_Kfactor[ijet],weight);
hist_5[45]->Fill(pfjetAK8re_tvsb[ijet],weight);
hist_5[46]->Fill(pfjetAK8rnu_tvsb[ijet],weight);

h2d_re_rnu_5->Fill(pfjetAK8re_tvsb[ijet],pfjetAK8rnu_tvsb[ijet],weight);
}

}//ijet

int t_cand = -1;
float remax = -200;

for(int ijet=0; ijet < npfjetAK8; ijet++){
	if(pfjetAK8re_tvsb[ijet] > remax){
		remax = pfjetAK8re_tvsb[ijet];
		t_cand = ijet;
	}
}
	
hist_6[0]->Fill(pfjetAK8pt[t_cand],weight);
hist_6[1]->Fill(pfjetAK8y[t_cand],weight);
hist_6[2]->Fill(pfjetAK8phi[t_cand],weight);
hist_6[3]->Fill(pfjetAK8mass[t_cand],weight);
hist_6[4]->Fill(pfjetAK8btag_CMVA[t_cand],weight);
hist_6[5]->Fill(pfjetAK8btag_CSV[t_cand],weight);
hist_6[6]->Fill(pfjetAK8btag_DeepCSV[t_cand],weight);
hist_6[7]->Fill(pfjetAK8matchAK4deepb[t_cand],weight);
hist_6[8]->Fill(pfjetAK8DeepTag_TvsQCD[t_cand],weight);
hist_6[9]->Fill(pfjetAK8DeepTag_WvsQCD[t_cand],weight);
hist_6[10]->Fill(pfjetAK8DeepTag_ZvsQCD[t_cand],weight);
hist_6[11]->Fill(pfjetAK8CHF[t_cand],weight);
hist_6[12]->Fill(pfjetAK8NHF[t_cand],weight);
hist_6[13]->Fill(pfjetAK8CEMF[t_cand],weight);
hist_6[14]->Fill(pfjetAK8NEMF[t_cand],weight);
hist_6[15]->Fill(pfjetAK8MUF[t_cand],weight);
hist_6[16]->Fill(pfjetAK8HOF[t_cand],weight);
hist_6[17]->Fill(pfjetAK8HadF[t_cand],weight);
hist_6[18]->Fill(pfjetAK8NHadF[t_cand],weight);
hist_6[19]->Fill(pfjetAK8EmF[t_cand],weight);
hist_6[20]->Fill(pfjetAK8neuemfrac[t_cand],weight);
hist_6[21]->Fill(pfjetAK8neunhadfrac[t_cand],weight);
hist_6[22]->Fill(pfjetAK8chrad[t_cand],weight);
hist_6[23]->Fill(pfjetAK8pTD[t_cand],weight);
hist_6[24]->Fill(pfjetAK8sdmass[t_cand],weight);
hist_6[25]->Fill(pfjetAK8tau21[t_cand],weight);
hist_6[26]->Fill(pfjetAK8tau32[t_cand],weight);
hist_6[27]->Fill(pfjetAK8sub1mass[t_cand],weight);
hist_6[28]->Fill(pfjetAK8sub1btag[t_cand],weight);
hist_6[29]->Fill(pfjetAK8sub1hadfrac[t_cand],weight);
hist_6[30]->Fill(pfjetAK8sub1emfrac[t_cand],weight);
hist_6[31]->Fill(pfjetAK8sub2mass[t_cand],weight);
hist_6[32]->Fill(pfjetAK8sub2btag[t_cand],weight);
hist_6[33]->Fill(pfjetAK8sub2hadfrac[t_cand],weight);
hist_6[34]->Fill(pfjetAK8sub2emfrac[t_cand],weight);
hist_6[35]->Fill(pfjetAK8subhaddiff[t_cand],weight);
hist_6[36]->Fill(pfjetAK8subemdiff[t_cand],weight);
hist_6[37]->Fill(pfjetAK8subptdiff[t_cand],weight);
hist_6[38]->Fill(pfjetAK8subbtag[t_cand],weight);
hist_6[39]->Fill(pfjetAK8_leppt[t_cand],weight);
hist_6[40]->Fill(pfjetAK8_bpt[t_cand],weight);
hist_6[41]->Fill(pfjetAK8_nupt[t_cand],weight);
hist_6[42]->Fill(pfjetAK8_Rnew[t_cand],weight);
hist_6[43]->Fill(pfjetAK8_bbyW_E[t_cand],weight);
hist_6[44]->Fill(pfjetAK8_Kfactor[t_cand],weight);
hist_6[45]->Fill(pfjetAK8re_tvsb[t_cand],weight);
hist_6[46]->Fill(pfjetAK8rnu_tvsb[t_cand],weight);

h2d_re_rnu_6->Fill(pfjetAK8re_tvsb[t_cand],pfjetAK8rnu_tvsb[t_cand],weight);

Tout->Fill();

double dRmax = -100;

for(int ijet=0; ijet< npfjetAK8; ijet++){
	if(pfjetAK8re_tvsb[ijet] > dRmax){
		dRmax = pfjetAK8re_tvsb[ijet];
		}
}

if(nleptop>=1) { 
	for(int ire=0; ire<(nre+1); ire++){
		if(dRmax >= (-1.+ ire*2/nre)){
			hist_event_top_pass->Fill(1*(ire+1),weight); 
		}
	}
}


fjet = 0;
      
for(int ijet=0; ijet<npfjetAK4; ijet++){
                  
  if(!pfjetAK4looseID[ijet]) continue;
                  
  pfjetAK4pt[ijet] *= pfjetAK4JEC[ijet] ; 
  pfjetAK4mass[ijet] *= pfjetAK4JEC[ijet];
  if(isMC){
        pfjetAK4pt[ijet] *= (1+pfjetAK4reso[ijet]) ;
        pfjetAK4mass[ijet] *= (1+pfjetAK4reso[ijet]) ;
  }
  
  pfjetAK4pt[fjet] = pfjetAK4pt[ijet];
  pfjetAK4mass[fjet] = pfjetAK4mass[ijet];
  pfjetAK4eta[fjet] = pfjetAK4eta[ijet];
  pfjetAK4phi[fjet] = pfjetAK4phi[ijet];
  pfjetAK4btag_DeepCSV[fjet] = pfjetAK4btag_DeepCSV[ijet];
  pfjetAK4btag_DeepFlav[fjet] = pfjetAK4btag_DeepFlav[ijet];
  
  fjet++;
  if(fjet>=njetmx) break;
}

npfjetAK4 = fjet;


int fel = 0;

for(int iel=0; iel<nelecs; iel++){

        if(elmvaid_noIso[iel]) continue;
        if(abs(elpt[iel]) < 35) continue;
        if(fabs(eleta[iel]) > 2.5) continue;
        
        elpt[fel] = abs(elpt[iel]) ;
        eleta[fel] = eleta[iel] ;
        elphi[fel] = elphi[iel] ;
        ele[fel] = abs(ele[iel]) ;
        
        elrelpT[fel] = -100;
        
        // 2d iso //
    float dR_min = 1000;
    int nearjet = -1;
    for(int kjet=0; kjet<npfjetAK4; kjet++){
        if(delta2R(pfjetAK4eta[kjet],pfjetAK4phi[kjet],eleta[fel],elphi[fel]) < dR_min){
            dR_min = delta2R(pfjetAK4eta[kjet],pfjetAK4phi[kjet],eleta[fel],elphi[fel]) ;
            nearjet = kjet;
        }
    }
    
    elpairj[fel] = nearjet;
    elrelpT[fel] = 0;
    
    if(nearjet>=0){
        TLorentzVector e_mom; e_mom.SetPtEtaPhiE(elpt[fel],eleta[fel],elphi[fel],ele[fel]);
        TLorentzVector j_mom; j_mom.SetPtEtaPhiM(pfjetAK4pt[nearjet],pfjetAK4eta[nearjet],pfjetAK4phi[nearjet],pfjetAK4mass[nearjet]);
        elrelpT[fel] = ((e_mom.Vect()).Perp(j_mom.Vect()));
     }
    
    if((dR_min > 0.4 ||  elrelpT[fel] > 15.)){
                el2diso[fel] = true;
                }else{
                        el2diso[fel] = false;
                         }
    // 2d iso ends //
        
        fel++;
        
        if(fel>=njetmx) break;

}

	nelecs = fel;

	if(nelecs > 0){

	for(int iel=0; iel<nelecs; iel++){
		if(iel!=0) break;       
		selelrelpT[iel] = elrelpT[iel];
		if(elpairj[iel]>=0){
			selelnearjdR[iel] = delta2R(eleta[iel],elphi[iel],pfjetAK4eta[elpairj[iel]],pfjetAK4phi[elpairj[iel]]);
		}else{
			selelnearjdR[iel]  = -100;
			}
	}

	nselec = 1;

	}else{
		
		nselec = 0;
		selelrelpT[0] = -100;
		selelnearjdR[0] = -100;
		}

   Tout_el->Fill();

   hist_nelec->Fill(nelecs,weight);

	if(nelecs > 0){

		h_el_2diso->Fill(el2diso[0],weight);
		h_el_relpt->Fill(elrelpT[0],weight);
		if(el2diso[0]>0 && elpairj[0]>=0 && pfjetAK4btag_DeepCSV[elpairj[0]]>0.1241){
			h_closebjet->Fill(1,weight);
			if(delta2R(eleta[0],elphi[0],pfjetAK4eta[elpairj[0]],pfjetAK4phi[elpairj[0]]) < 0.8){
                h_closebjet_dRp8->Fill(1,weight);
               }
			}else{
                h_closebjet->Fill(double(0),weight);
                }

	}


#ifdef TRAINING

int iseljet = 0;
npfjetAK8_te = 0;

for(int ijet=0; ijet< npfjetAK8; ijet++){
	
	if(ijet>(nmaxjet-1)) break;
	
	bool te_cond = false;
	te_cond  = (pfjetAK8haselectron[ijet] && pfjetAK8hasleptop[ijet] && pfjetAK8hastop[ijet] && pfjetAK8hasleptop_alldecay[ijet]);
	
	if(te_cond){
	
	selpfjetAK8pt[iseljet] = pfjetAK8pt[ijet];
	selpfjetAK8y[iseljet] = pfjetAK8y[ijet];
	selpfjetAK8mass[iseljet] = pfjetAK8mass[ijet];
	selpfjetAK8phi[iseljet] = pfjetAK8phi[ijet];
	selpfjetAK8btag_CMVA[iseljet] = pfjetAK8btag_CMVA[ijet];
	selpfjetAK8btag_CSV[iseljet] = pfjetAK8btag_CSV[ijet];
	selpfjetAK8btag_DeepCSV[iseljet] = pfjetAK8btag_DeepCSV[ijet];
	selpfjetAK8matchAK4deepb[iseljet] = pfjetAK8matchAK4deepb[ijet];
	selpfjetAK8matchAK4deepCSVb[iseljet] = pfjetAK8matchAK4deepCSVb[ijet];
	selpfjetAK8DeepTag_TvsQCD[iseljet] =  pfjetAK8DeepTag_TvsQCD[ijet];
	selpfjetAK8DeepTag_WvsQCD[iseljet] = pfjetAK8DeepTag_WvsQCD[ijet];
	selpfjetAK8DeepTag_ZvsQCD[iseljet] = pfjetAK8DeepTag_ZvsQCD[ijet];
	selpfjetAK8CHF[iseljet] = pfjetAK8CHF[ijet];
	selpfjetAK8NHF[iseljet] = pfjetAK8NHF[ijet];
	selpfjetAK8CEMF[iseljet] = pfjetAK8CEMF[ijet];
	selpfjetAK8NEMF[iseljet] = pfjetAK8NEMF[ijet];
	selpfjetAK8MUF[iseljet] = pfjetAK8MUF[ijet];
	selpfjetAK8HOF[iseljet] = pfjetAK8HOF[ijet];
	selpfjetAK8HadF[iseljet] = pfjetAK8HadF[ijet];
	selpfjetAK8NHadF[iseljet] = pfjetAK8NHadF[ijet];
	selpfjetAK8EmF[iseljet] = pfjetAK8EmF[ijet];
	selpfjetAK8neuemfrac[iseljet] = pfjetAK8neuemfrac[ijet];
	selpfjetAK8neunhadfrac[iseljet] = pfjetAK8neunhadfrac[ijet];
	selpfjetAK8CHM[iseljet] = pfjetAK8CHM[ijet];
	selpfjetAK8NHM[iseljet] = pfjetAK8NHM[ijet];
	selpfjetAK8CEMM[iseljet] = pfjetAK8CEMM[ijet];
	selpfjetAK8NEMM[iseljet] =  pfjetAK8NEMM[ijet];
	selpfjetAK8EEM[iseljet] = pfjetAK8EEM[ijet];
	selpfjetAK8MUM[iseljet] = pfjetAK8MUM[ijet];
	selpfjetAK8Neucons[iseljet] = pfjetAK8Neucons[ijet];
	selpfjetAK8Chcons[iseljet] = pfjetAK8Chcons[ijet] ;
	selpfjetAK8chrad[iseljet] =  pfjetAK8chrad[ijet];
	selpfjetAK8pTD[iseljet] = pfjetAK8pTD[ijet];
	selpfjetAK8sdmass[iseljet] = pfjetAK8sdmass[ijet];
	selpfjetAK8tau21[iseljet] = pfjetAK8tau21[ijet];
	selpfjetAK8tau32[iseljet] = pfjetAK8tau32[ijet];
	selpfjetAK8sub1mass[iseljet] = pfjetAK8sub1mass[ijet];
	selpfjetAK8sub1btag[iseljet] = pfjetAK8sub1btag[ijet];
	selpfjetAK8sub1hadfrac[iseljet] =  pfjetAK8sub1hadfrac[ijet];
	selpfjetAK8sub1emfrac[iseljet] = pfjetAK8sub1emfrac[ijet];
	selpfjetAK8sub2mass[iseljet] = pfjetAK8sub2mass[ijet];
	selpfjetAK8sub2btag[iseljet] =  pfjetAK8sub2btag[ijet];
	selpfjetAK8sub2hadfrac[iseljet] = pfjetAK8sub2hadfrac[ijet];
	selpfjetAK8sub2emfrac[iseljet] = pfjetAK8sub2emfrac[ijet];
	selpfjetAK8subbtag[iseljet] = pfjetAK8subbtag[ijet];
	selpfjetAK8subhaddiff[iseljet] =  pfjetAK8subhaddiff[ijet];
	selpfjetAK8subemdiff[iseljet] = pfjetAK8subemdiff[ijet];
	selpfjetAK8subptdiff[iseljet] = pfjetAK8subptdiff[ijet];
	selpfjetAK8_bbyW_E[iseljet] = pfjetAK8_bbyW_E[ijet];
	selpfjetAK8_Kfactor[iseljet] = pfjetAK8_Kfactor[ijet];
	selpfjetAK8_Rnew[iseljet] = selpfjetAK8_Rnew[ijet];
	selpfjetAK8haselectron[iseljet] =  pfjetAK8haselectron[ijet];
	selpfjetAK8hasmuon[iseljet] =  pfjetAK8hasmuon[ijet];
	selpfjetAK8hasqg[iseljet] =  pfjetAK8hasqg[ijet];
	selpfjetAK8hasb[iseljet] =  pfjetAK8hasb[ijet];
	selpfjetAK8hashadtop[iseljet] =  pfjetAK8hashadtop[ijet];
	selpfjetAK8hasleptop[iseljet] = pfjetAK8hasleptop[ijet];
	selpfjetAK8hastop[iseljet] = pfjetAK8hastop[ijet];
	selpfjetAK8hashadtop_alldecay[iseljet] = pfjetAK8hashadtop_alldecay[ijet];
	selpfjetAK8hasleptop_alldecay[iseljet] = pfjetAK8hasleptop_alldecay[ijet];
	selpfjetAK8re_tvsb[iseljet] = pfjetAK8re_tvsb[ijet];
	selpfjetAK8rnu_tvsb[iseljet] = pfjetAK8rnu_tvsb[ijet];
	
	iseljet++;
	if(iseljet>=njetmxAK8) break;
	}
}

npfjetAK8_te = iseljet;
Tout1->Fill();

#endif

iseljet = 0;
npfjetAK8_tmu = 0;

for(int ijet=0; ijet< npfjetAK8; ijet++){
	
	if(ijet>(nmaxjet-1)) break;
	
	bool tmu_cond = false;
	tmu_cond = (pfjetAK8hasmuon[ijet] && pfjetAK8hasleptop[ijet] && pfjetAK8hastop[ijet] && pfjetAK8hasleptop_alldecay[ijet]);
	
	if(tmu_cond){
	
	selpfjetAK8pt[iseljet] = pfjetAK8pt[ijet];
	selpfjetAK8y[iseljet] = pfjetAK8y[ijet];
	selpfjetAK8mass[iseljet] = pfjetAK8mass[ijet];
	selpfjetAK8phi[iseljet] = pfjetAK8phi[ijet];
	selpfjetAK8btag_CMVA[iseljet] = pfjetAK8btag_CMVA[ijet];
	selpfjetAK8btag_CSV[iseljet] = pfjetAK8btag_CSV[ijet];
	selpfjetAK8btag_DeepCSV[iseljet] = pfjetAK8btag_DeepCSV[ijet];
	selpfjetAK8matchAK4deepb[iseljet] = pfjetAK8matchAK4deepb[ijet];
	selpfjetAK8matchAK4deepCSVb[iseljet] = pfjetAK8matchAK4deepCSVb[ijet];
	selpfjetAK8DeepTag_TvsQCD[iseljet] =  pfjetAK8DeepTag_TvsQCD[ijet];
	selpfjetAK8DeepTag_WvsQCD[iseljet] = pfjetAK8DeepTag_WvsQCD[ijet];
	selpfjetAK8DeepTag_ZvsQCD[iseljet] = pfjetAK8DeepTag_ZvsQCD[ijet];
	selpfjetAK8CHF[iseljet] = pfjetAK8CHF[ijet];
	selpfjetAK8NHF[iseljet] = pfjetAK8NHF[ijet];
	selpfjetAK8CEMF[iseljet] = pfjetAK8CEMF[ijet];
	selpfjetAK8NEMF[iseljet] = pfjetAK8NEMF[ijet];
	selpfjetAK8MUF[iseljet] = pfjetAK8MUF[ijet];
	selpfjetAK8HOF[iseljet] = pfjetAK8HOF[ijet];
	selpfjetAK8HadF[iseljet] = pfjetAK8HadF[ijet];
	selpfjetAK8NHadF[iseljet] = pfjetAK8NHadF[ijet];
	selpfjetAK8EmF[iseljet] = pfjetAK8EmF[ijet];
	selpfjetAK8neuemfrac[iseljet] = pfjetAK8neuemfrac[ijet];
	selpfjetAK8neunhadfrac[iseljet] = pfjetAK8neunhadfrac[ijet];
	selpfjetAK8CHM[iseljet] = pfjetAK8CHM[ijet];
	selpfjetAK8NHM[iseljet] = pfjetAK8NHM[ijet];
	selpfjetAK8CEMM[iseljet] = pfjetAK8CEMM[ijet];
	selpfjetAK8NEMM[iseljet] =  pfjetAK8NEMM[ijet];
	selpfjetAK8EEM[iseljet] = pfjetAK8EEM[ijet];
	selpfjetAK8MUM[iseljet] = pfjetAK8MUM[ijet];
	selpfjetAK8Neucons[iseljet] = pfjetAK8Neucons[ijet];
	selpfjetAK8Chcons[iseljet] = pfjetAK8Chcons[ijet] ;
	selpfjetAK8chrad[iseljet] =  pfjetAK8chrad[ijet];
	selpfjetAK8pTD[iseljet] = pfjetAK8pTD[ijet];
	selpfjetAK8sdmass[iseljet] = pfjetAK8sdmass[ijet];
	selpfjetAK8tau21[iseljet] = pfjetAK8tau21[ijet];
	selpfjetAK8tau32[iseljet] = pfjetAK8tau32[ijet];
	selpfjetAK8sub1mass[iseljet] = pfjetAK8sub1mass[ijet];
	selpfjetAK8sub1btag[iseljet] = pfjetAK8sub1btag[ijet];
	selpfjetAK8sub1hadfrac[iseljet] =  pfjetAK8sub1hadfrac[ijet];
	selpfjetAK8sub1emfrac[iseljet] = pfjetAK8sub1emfrac[ijet];
	selpfjetAK8sub2mass[iseljet] = pfjetAK8sub2mass[ijet];
	selpfjetAK8sub2btag[iseljet] =  pfjetAK8sub2btag[ijet];
	selpfjetAK8sub2hadfrac[iseljet] = pfjetAK8sub2hadfrac[ijet];
	selpfjetAK8sub2emfrac[iseljet] = pfjetAK8sub2emfrac[ijet];
	selpfjetAK8subbtag[iseljet] = pfjetAK8subbtag[ijet];
	selpfjetAK8subhaddiff[iseljet] =  pfjetAK8subhaddiff[ijet];
	selpfjetAK8subemdiff[iseljet] = pfjetAK8subemdiff[ijet];
	selpfjetAK8subptdiff[iseljet] = pfjetAK8subptdiff[ijet];
	selpfjetAK8_bbyW_E[iseljet] = pfjetAK8_bbyW_E[ijet];
	selpfjetAK8_Kfactor[iseljet] = pfjetAK8_Kfactor[ijet];
	selpfjetAK8_Rnew[iseljet] = selpfjetAK8_Rnew[ijet];
	selpfjetAK8haselectron[iseljet] =  pfjetAK8haselectron[ijet];
	selpfjetAK8hasmuon[iseljet] =  pfjetAK8hasmuon[ijet];
	selpfjetAK8hasqg[iseljet] =  pfjetAK8hasqg[ijet];
	selpfjetAK8hasb[iseljet] =  pfjetAK8hasb[ijet];
	selpfjetAK8hashadtop[iseljet] =  pfjetAK8hashadtop[ijet];
	selpfjetAK8hasleptop[iseljet] = pfjetAK8hasleptop[ijet];
	selpfjetAK8hastop[iseljet] = pfjetAK8hastop[ijet];
	selpfjetAK8hashadtop_alldecay[iseljet] = pfjetAK8hashadtop_alldecay[ijet];
	selpfjetAK8hasleptop_alldecay[iseljet] = pfjetAK8hasleptop_alldecay[ijet];
	selpfjetAK8re_tvsb[iseljet] = pfjetAK8re_tvsb[ijet];
	selpfjetAK8rnu_tvsb[iseljet] = pfjetAK8rnu_tvsb[ijet];
	
	iseljet++;
	if(iseljet>=njetmxAK8) break;
	
	}	

}
	npfjetAK8_tmu = iseljet;
#ifdef All_Trees
	Tout2->Fill();
#endif

iseljet = 0;
npfjetAK8_thad = 0;

for(int ijet=0; ijet< npfjetAK8; ijet++){
	
	if(ijet>(nmaxjet-1)) break;
	
	bool thad_cond = false;
	thad_cond = (pfjetAK8hashadtop[ijet] && pfjetAK8hastop[ijet] && pfjetAK8hashadtop_alldecay[ijet]);
	
	if(thad_cond){
	
	selpfjetAK8pt[iseljet] = pfjetAK8pt[ijet];
	selpfjetAK8y[iseljet] = pfjetAK8y[ijet];
	selpfjetAK8mass[iseljet] = pfjetAK8mass[ijet];
	selpfjetAK8phi[iseljet] = pfjetAK8phi[ijet];
	selpfjetAK8btag_CMVA[iseljet] = pfjetAK8btag_CMVA[ijet];
	selpfjetAK8btag_CSV[iseljet] = pfjetAK8btag_CSV[ijet];
	selpfjetAK8btag_DeepCSV[iseljet] = pfjetAK8btag_DeepCSV[ijet];
	selpfjetAK8matchAK4deepb[iseljet] = pfjetAK8matchAK4deepb[ijet];
	selpfjetAK8matchAK4deepCSVb[iseljet] = pfjetAK8matchAK4deepCSVb[ijet];
	selpfjetAK8DeepTag_TvsQCD[iseljet] =  pfjetAK8DeepTag_TvsQCD[ijet];
	selpfjetAK8DeepTag_WvsQCD[iseljet] = pfjetAK8DeepTag_WvsQCD[ijet];
	selpfjetAK8DeepTag_ZvsQCD[iseljet] = pfjetAK8DeepTag_ZvsQCD[ijet];
	selpfjetAK8CHF[iseljet] = pfjetAK8CHF[ijet];
	selpfjetAK8NHF[iseljet] = pfjetAK8NHF[ijet];
	selpfjetAK8CEMF[iseljet] = pfjetAK8CEMF[ijet];
	selpfjetAK8NEMF[iseljet] = pfjetAK8NEMF[ijet];
	selpfjetAK8MUF[iseljet] = pfjetAK8MUF[ijet];
	selpfjetAK8HOF[iseljet] = pfjetAK8HOF[ijet];
	selpfjetAK8HadF[iseljet] = pfjetAK8HadF[ijet];
	selpfjetAK8NHadF[iseljet] = pfjetAK8NHadF[ijet];
	selpfjetAK8EmF[iseljet] = pfjetAK8EmF[ijet];
	selpfjetAK8neuemfrac[iseljet] = pfjetAK8neuemfrac[ijet];
	selpfjetAK8neunhadfrac[iseljet] = pfjetAK8neunhadfrac[ijet];
	selpfjetAK8CHM[iseljet] = pfjetAK8CHM[ijet];
	selpfjetAK8NHM[iseljet] = pfjetAK8NHM[ijet];
	selpfjetAK8CEMM[iseljet] = pfjetAK8CEMM[ijet];
	selpfjetAK8NEMM[iseljet] =  pfjetAK8NEMM[ijet];
	selpfjetAK8EEM[iseljet] = pfjetAK8EEM[ijet];
	selpfjetAK8MUM[iseljet] = pfjetAK8MUM[ijet];
	selpfjetAK8Neucons[iseljet] = pfjetAK8Neucons[ijet];
	selpfjetAK8Chcons[iseljet] = pfjetAK8Chcons[ijet] ;
	selpfjetAK8chrad[iseljet] =  pfjetAK8chrad[ijet];
	selpfjetAK8pTD[iseljet] = pfjetAK8pTD[ijet];
	selpfjetAK8sdmass[iseljet] = pfjetAK8sdmass[ijet];
	selpfjetAK8tau21[iseljet] = pfjetAK8tau21[ijet];
	selpfjetAK8tau32[iseljet] = pfjetAK8tau32[ijet];
	selpfjetAK8sub1mass[iseljet] = pfjetAK8sub1mass[ijet];
	selpfjetAK8sub1btag[iseljet] = pfjetAK8sub1btag[ijet];
	selpfjetAK8sub1hadfrac[iseljet] =  pfjetAK8sub1hadfrac[ijet];
	selpfjetAK8sub1emfrac[iseljet] = pfjetAK8sub1emfrac[ijet];
	selpfjetAK8sub2mass[iseljet] = pfjetAK8sub2mass[ijet];
	selpfjetAK8sub2btag[iseljet] =  pfjetAK8sub2btag[ijet];
	selpfjetAK8sub2hadfrac[iseljet] = pfjetAK8sub2hadfrac[ijet];
	selpfjetAK8sub2emfrac[iseljet] = pfjetAK8sub2emfrac[ijet];
	selpfjetAK8subbtag[iseljet] = pfjetAK8subbtag[ijet];
	selpfjetAK8subhaddiff[iseljet] =  pfjetAK8subhaddiff[ijet];
	selpfjetAK8subemdiff[iseljet] = pfjetAK8subemdiff[ijet];
	selpfjetAK8subptdiff[iseljet] = pfjetAK8subptdiff[ijet];
	selpfjetAK8_bbyW_E[iseljet] = pfjetAK8_bbyW_E[ijet];
	selpfjetAK8_Kfactor[iseljet] = pfjetAK8_Kfactor[ijet];
	selpfjetAK8_Rnew[iseljet] = selpfjetAK8_Rnew[ijet];
	selpfjetAK8haselectron[iseljet] =  pfjetAK8haselectron[ijet];
	selpfjetAK8hasmuon[iseljet] =  pfjetAK8hasmuon[ijet];
	selpfjetAK8hasqg[iseljet] =  pfjetAK8hasqg[ijet];
	selpfjetAK8hasb[iseljet] =  pfjetAK8hasb[ijet];
	selpfjetAK8hashadtop[iseljet] =  pfjetAK8hashadtop[ijet];
	selpfjetAK8hasleptop[iseljet] = pfjetAK8hasleptop[ijet];
	selpfjetAK8hastop[iseljet] = pfjetAK8hastop[ijet];
	selpfjetAK8hashadtop_alldecay[iseljet] = pfjetAK8hashadtop_alldecay[ijet];
	selpfjetAK8hasleptop_alldecay[iseljet] = pfjetAK8hasleptop_alldecay[ijet];
	selpfjetAK8re_tvsb[iseljet] = pfjetAK8re_tvsb[ijet];
	selpfjetAK8rnu_tvsb[iseljet] = pfjetAK8rnu_tvsb[ijet];
	
	iseljet++;
	if(iseljet>=njetmxAK8) break;
	}	

}
	npfjetAK8_thad = iseljet;
	#ifdef All_Trees
	Tout3->Fill();
	#endif

iseljet = 0;
npfjetAK8_qg = 0;

for(int ijet=0; ijet< npfjetAK8; ijet++){
	
	if(ijet>(nmaxjet-1)) break;
	
	bool qg_cond = false;
	qg_cond = (pfjetAK8hasqg[ijet] && !(pfjetAK8hashadtop[ijet]) && !(pfjetAK8hasleptop[ijet]) && !(pfjetAK8hastop[ijet]));
	
	if(qg_cond){
	
	selpfjetAK8pt[iseljet] = pfjetAK8pt[ijet];
	selpfjetAK8y[iseljet] = pfjetAK8y[ijet];
	selpfjetAK8mass[iseljet] = pfjetAK8mass[ijet];
	selpfjetAK8phi[iseljet] = pfjetAK8phi[ijet];
	selpfjetAK8btag_CMVA[iseljet] = pfjetAK8btag_CMVA[ijet];
	selpfjetAK8btag_CSV[iseljet] = pfjetAK8btag_CSV[ijet];
	selpfjetAK8btag_DeepCSV[iseljet] = pfjetAK8btag_DeepCSV[ijet];
	selpfjetAK8matchAK4deepb[iseljet] = pfjetAK8matchAK4deepb[ijet];
	selpfjetAK8matchAK4deepCSVb[iseljet] = pfjetAK8matchAK4deepCSVb[ijet];
	selpfjetAK8DeepTag_TvsQCD[iseljet] =  pfjetAK8DeepTag_TvsQCD[ijet];
	selpfjetAK8DeepTag_WvsQCD[iseljet] = pfjetAK8DeepTag_WvsQCD[ijet];
	selpfjetAK8DeepTag_ZvsQCD[iseljet] = pfjetAK8DeepTag_ZvsQCD[ijet];
	selpfjetAK8CHF[iseljet] = pfjetAK8CHF[ijet];
	selpfjetAK8NHF[iseljet] = pfjetAK8NHF[ijet];
	selpfjetAK8CEMF[iseljet] = pfjetAK8CEMF[ijet];
	selpfjetAK8NEMF[iseljet] = pfjetAK8NEMF[ijet];
	selpfjetAK8MUF[iseljet] = pfjetAK8MUF[ijet];
	selpfjetAK8HOF[iseljet] = pfjetAK8HOF[ijet];
	selpfjetAK8HadF[iseljet] = pfjetAK8HadF[ijet];
	selpfjetAK8NHadF[iseljet] = pfjetAK8NHadF[ijet];
	selpfjetAK8EmF[iseljet] = pfjetAK8EmF[ijet];
	selpfjetAK8neuemfrac[iseljet] = pfjetAK8neuemfrac[ijet];
	selpfjetAK8neunhadfrac[iseljet] = pfjetAK8neunhadfrac[ijet];
	selpfjetAK8CHM[iseljet] = pfjetAK8CHM[ijet];
	selpfjetAK8NHM[iseljet] = pfjetAK8NHM[ijet];
	selpfjetAK8CEMM[iseljet] = pfjetAK8CEMM[ijet];
	selpfjetAK8NEMM[iseljet] =  pfjetAK8NEMM[ijet];
	selpfjetAK8EEM[iseljet] = pfjetAK8EEM[ijet];
	selpfjetAK8MUM[iseljet] = pfjetAK8MUM[ijet];
	selpfjetAK8Neucons[iseljet] = pfjetAK8Neucons[ijet];
	selpfjetAK8Chcons[iseljet] = pfjetAK8Chcons[ijet] ;
	selpfjetAK8chrad[iseljet] =  pfjetAK8chrad[ijet];
	selpfjetAK8pTD[iseljet] = pfjetAK8pTD[ijet];
	selpfjetAK8sdmass[iseljet] = pfjetAK8sdmass[ijet];
	selpfjetAK8tau21[iseljet] = pfjetAK8tau21[ijet];
	selpfjetAK8tau32[iseljet] = pfjetAK8tau32[ijet];
	selpfjetAK8sub1mass[iseljet] = pfjetAK8sub1mass[ijet];
	selpfjetAK8sub1btag[iseljet] = pfjetAK8sub1btag[ijet];
	selpfjetAK8sub1hadfrac[iseljet] =  pfjetAK8sub1hadfrac[ijet];
	selpfjetAK8sub1emfrac[iseljet] = pfjetAK8sub1emfrac[ijet];
	selpfjetAK8sub2mass[iseljet] = pfjetAK8sub2mass[ijet];
	selpfjetAK8sub2btag[iseljet] =  pfjetAK8sub2btag[ijet];
	selpfjetAK8sub2hadfrac[iseljet] = pfjetAK8sub2hadfrac[ijet];
	selpfjetAK8sub2emfrac[iseljet] = pfjetAK8sub2emfrac[ijet];
	selpfjetAK8subbtag[iseljet] = pfjetAK8subbtag[ijet];
	selpfjetAK8subhaddiff[iseljet] =  pfjetAK8subhaddiff[ijet];
	selpfjetAK8subemdiff[iseljet] = pfjetAK8subemdiff[ijet];
	selpfjetAK8subptdiff[iseljet] = pfjetAK8subptdiff[ijet];
	selpfjetAK8_bbyW_E[iseljet] = pfjetAK8_bbyW_E[ijet];
	selpfjetAK8_Kfactor[iseljet] = pfjetAK8_Kfactor[ijet];
	selpfjetAK8_Rnew[iseljet] = selpfjetAK8_Rnew[ijet];
	selpfjetAK8haselectron[iseljet] =  pfjetAK8haselectron[ijet];
	selpfjetAK8hasmuon[iseljet] =  pfjetAK8hasmuon[ijet];
	selpfjetAK8hasqg[iseljet] =  pfjetAK8hasqg[ijet];
	selpfjetAK8hasb[iseljet] =  pfjetAK8hasb[ijet];
	selpfjetAK8hashadtop[iseljet] =  pfjetAK8hashadtop[ijet];
	selpfjetAK8hasleptop[iseljet] = pfjetAK8hasleptop[ijet];
	selpfjetAK8hastop[iseljet] = pfjetAK8hastop[ijet];
	selpfjetAK8re_tvsb[iseljet] = pfjetAK8re_tvsb[ijet];
	selpfjetAK8rnu_tvsb[iseljet] = pfjetAK8rnu_tvsb[ijet];
	
	iseljet++;
	if(iseljet>=njetmxAK8) break;
	}	

}
	#ifdef All_Trees
	npfjetAK8_qg = iseljet;
	Tout4->Fill();
	#endif	
	
iseljet = 0;
npfjetAK8_b = 0;

#ifdef TRAINING

for(int ijet=0; ijet< npfjetAK8; ijet++){
	
	if(ijet>(nmaxjet-1)) break;
	
	bool b_cond = false;
	b_cond = (pfjetAK8hasb[ijet] && !(pfjetAK8hashadtop[ijet]) && !(pfjetAK8hasleptop[ijet]) && !(pfjetAK8hastop[ijet]));
	
	if(b_cond){
	
	selpfjetAK8pt[iseljet] = pfjetAK8pt[ijet];
	selpfjetAK8y[iseljet] = pfjetAK8y[ijet];
	selpfjetAK8mass[iseljet] = pfjetAK8mass[ijet];
	selpfjetAK8phi[iseljet] = pfjetAK8phi[ijet];
	selpfjetAK8btag_CMVA[iseljet] = pfjetAK8btag_CMVA[ijet];
	selpfjetAK8btag_CSV[iseljet] = pfjetAK8btag_CSV[ijet];
	selpfjetAK8btag_DeepCSV[iseljet] = pfjetAK8btag_DeepCSV[ijet];
	selpfjetAK8matchAK4deepb[iseljet] = pfjetAK8matchAK4deepb[ijet];
	selpfjetAK8matchAK4deepCSVb[iseljet] = pfjetAK8matchAK4deepCSVb[ijet];
	selpfjetAK8DeepTag_TvsQCD[iseljet] =  pfjetAK8DeepTag_TvsQCD[ijet];
	selpfjetAK8DeepTag_WvsQCD[iseljet] = pfjetAK8DeepTag_WvsQCD[ijet];
	selpfjetAK8DeepTag_ZvsQCD[iseljet] = pfjetAK8DeepTag_ZvsQCD[ijet];
	selpfjetAK8CHF[iseljet] = pfjetAK8CHF[ijet];
	selpfjetAK8NHF[iseljet] = pfjetAK8NHF[ijet];
	selpfjetAK8CEMF[iseljet] = pfjetAK8CEMF[ijet];
	selpfjetAK8NEMF[iseljet] = pfjetAK8NEMF[ijet];
	selpfjetAK8MUF[iseljet] = pfjetAK8MUF[ijet];
	selpfjetAK8HOF[iseljet] = pfjetAK8HOF[ijet];
	selpfjetAK8HadF[iseljet] = pfjetAK8HadF[ijet];
	selpfjetAK8NHadF[iseljet] = pfjetAK8NHadF[ijet];
	selpfjetAK8EmF[iseljet] = pfjetAK8EmF[ijet];
	selpfjetAK8neuemfrac[iseljet] = pfjetAK8neuemfrac[ijet];
	selpfjetAK8neunhadfrac[iseljet] = pfjetAK8neunhadfrac[ijet];
	selpfjetAK8CHM[iseljet] = pfjetAK8CHM[ijet];
	selpfjetAK8NHM[iseljet] = pfjetAK8NHM[ijet];
	selpfjetAK8CEMM[iseljet] = pfjetAK8CEMM[ijet];
	selpfjetAK8NEMM[iseljet] =  pfjetAK8NEMM[ijet];
	selpfjetAK8EEM[iseljet] = pfjetAK8EEM[ijet];
	selpfjetAK8MUM[iseljet] = pfjetAK8MUM[ijet];
	selpfjetAK8Neucons[iseljet] = pfjetAK8Neucons[ijet];
	selpfjetAK8Chcons[iseljet] = pfjetAK8Chcons[ijet] ;
	selpfjetAK8chrad[iseljet] =  pfjetAK8chrad[ijet];
	selpfjetAK8pTD[iseljet] = pfjetAK8pTD[ijet];
	selpfjetAK8sdmass[iseljet] = pfjetAK8sdmass[ijet];
	selpfjetAK8tau21[iseljet] = pfjetAK8tau21[ijet];
	selpfjetAK8tau32[iseljet] = pfjetAK8tau32[ijet];
	selpfjetAK8sub1mass[iseljet] = pfjetAK8sub1mass[ijet];
	selpfjetAK8sub1btag[iseljet] = pfjetAK8sub1btag[ijet];
	selpfjetAK8sub1hadfrac[iseljet] =  pfjetAK8sub1hadfrac[ijet];
	selpfjetAK8sub1emfrac[iseljet] = pfjetAK8sub1emfrac[ijet];
	selpfjetAK8sub2mass[iseljet] = pfjetAK8sub2mass[ijet];
	selpfjetAK8sub2btag[iseljet] =  pfjetAK8sub2btag[ijet];
	selpfjetAK8sub2hadfrac[iseljet] = pfjetAK8sub2hadfrac[ijet];
	selpfjetAK8sub2emfrac[iseljet] = pfjetAK8sub2emfrac[ijet];
	selpfjetAK8subbtag[iseljet] = pfjetAK8subbtag[ijet];
	selpfjetAK8subhaddiff[iseljet] =  pfjetAK8subhaddiff[ijet];
	selpfjetAK8subemdiff[iseljet] = pfjetAK8subemdiff[ijet];
	selpfjetAK8subptdiff[iseljet] = pfjetAK8subptdiff[ijet];
	selpfjetAK8_bbyW_E[iseljet] = pfjetAK8_bbyW_E[ijet];
	selpfjetAK8_Kfactor[iseljet] = pfjetAK8_Kfactor[ijet];
	selpfjetAK8_Rnew[iseljet] = selpfjetAK8_Rnew[ijet];
	selpfjetAK8haselectron[iseljet] =  pfjetAK8haselectron[ijet];
	selpfjetAK8hasmuon[iseljet] =  pfjetAK8hasmuon[ijet];
	selpfjetAK8hasqg[iseljet] =  pfjetAK8hasqg[ijet];
	selpfjetAK8hasb[iseljet] =  pfjetAK8hasb[ijet];
	selpfjetAK8hashadtop[iseljet] =  pfjetAK8hashadtop[ijet];
	selpfjetAK8hasleptop[iseljet] = pfjetAK8hasleptop[ijet];
	selpfjetAK8hastop[iseljet] = pfjetAK8hastop[ijet];
	selpfjetAK8re_tvsb[iseljet] = pfjetAK8re_tvsb[ijet];
	selpfjetAK8rnu_tvsb[iseljet] = pfjetAK8rnu_tvsb[ijet];
	
	iseljet++;
	if(iseljet>=njetmxAK8) break;
	}	

}
	npfjetAK8_b = iseljet;
	
	Tout5->Fill();
	
#endif		

iseljet = 0;
npfjetAK8_all = 0;

for(int ijet=0; ijet< npfjetAK8; ijet++){
	
	if(ijet>(nmaxjet-1)) break;
	
	selpfjetAK8pt[iseljet] = pfjetAK8pt[ijet];
	selpfjetAK8y[iseljet] = pfjetAK8y[ijet];
	selpfjetAK8mass[iseljet] = pfjetAK8mass[ijet];
	selpfjetAK8phi[iseljet] = pfjetAK8phi[ijet];
	selpfjetAK8btag_CMVA[iseljet] = pfjetAK8btag_CMVA[ijet];
	selpfjetAK8btag_CSV[iseljet] = pfjetAK8btag_CSV[ijet];
	selpfjetAK8btag_DeepCSV[iseljet] = pfjetAK8btag_DeepCSV[ijet];
	selpfjetAK8matchAK4deepb[iseljet] = pfjetAK8matchAK4deepb[ijet];
	selpfjetAK8matchAK4deepCSVb[iseljet] = pfjetAK8matchAK4deepCSVb[ijet];
	selpfjetAK8DeepTag_TvsQCD[iseljet] =  pfjetAK8DeepTag_TvsQCD[ijet];
	selpfjetAK8DeepTag_WvsQCD[iseljet] = pfjetAK8DeepTag_WvsQCD[ijet];
	selpfjetAK8DeepTag_ZvsQCD[iseljet] = pfjetAK8DeepTag_ZvsQCD[ijet];
	selpfjetAK8CHF[iseljet] = pfjetAK8CHF[ijet];
	selpfjetAK8NHF[iseljet] = pfjetAK8NHF[ijet];
	selpfjetAK8CEMF[iseljet] = pfjetAK8CEMF[ijet];
	selpfjetAK8NEMF[iseljet] = pfjetAK8NEMF[ijet];
	selpfjetAK8MUF[iseljet] = pfjetAK8MUF[ijet];
	selpfjetAK8HOF[iseljet] = pfjetAK8HOF[ijet];
	selpfjetAK8HadF[iseljet] = pfjetAK8HadF[ijet];
	selpfjetAK8NHadF[iseljet] = pfjetAK8NHadF[ijet];
	selpfjetAK8EmF[iseljet] = pfjetAK8EmF[ijet];
	selpfjetAK8neuemfrac[iseljet] = pfjetAK8neuemfrac[ijet];
	selpfjetAK8neunhadfrac[iseljet] = pfjetAK8neunhadfrac[ijet];
	selpfjetAK8CHM[iseljet] = pfjetAK8CHM[ijet];
	selpfjetAK8NHM[iseljet] = pfjetAK8NHM[ijet];
	selpfjetAK8CEMM[iseljet] = pfjetAK8CEMM[ijet];
	selpfjetAK8NEMM[iseljet] =  pfjetAK8NEMM[ijet];
	selpfjetAK8EEM[iseljet] = pfjetAK8EEM[ijet];
	selpfjetAK8MUM[iseljet] = pfjetAK8MUM[ijet];
	selpfjetAK8Neucons[iseljet] = pfjetAK8Neucons[ijet];
	selpfjetAK8Chcons[iseljet] = pfjetAK8Chcons[ijet] ;
	selpfjetAK8chrad[iseljet] =  pfjetAK8chrad[ijet];
	selpfjetAK8pTD[iseljet] = pfjetAK8pTD[ijet];
	selpfjetAK8sdmass[iseljet] = pfjetAK8sdmass[ijet];
	selpfjetAK8tau21[iseljet] = pfjetAK8tau21[ijet];
	selpfjetAK8tau32[iseljet] = pfjetAK8tau32[ijet];
	selpfjetAK8sub1mass[iseljet] = pfjetAK8sub1mass[ijet];
	selpfjetAK8sub1btag[iseljet] = pfjetAK8sub1btag[ijet];
	selpfjetAK8sub1hadfrac[iseljet] =  pfjetAK8sub1hadfrac[ijet];
	selpfjetAK8sub1emfrac[iseljet] = pfjetAK8sub1emfrac[ijet];
	selpfjetAK8sub2mass[iseljet] = pfjetAK8sub2mass[ijet];
	selpfjetAK8sub2btag[iseljet] =  pfjetAK8sub2btag[ijet];
	selpfjetAK8sub2hadfrac[iseljet] = pfjetAK8sub2hadfrac[ijet];
	selpfjetAK8sub2emfrac[iseljet] = pfjetAK8sub2emfrac[ijet];
	selpfjetAK8subbtag[iseljet] = pfjetAK8subbtag[ijet];
	selpfjetAK8subhaddiff[iseljet] =  pfjetAK8subhaddiff[ijet];
	selpfjetAK8subemdiff[iseljet] = pfjetAK8subemdiff[ijet];
	selpfjetAK8subptdiff[iseljet] = pfjetAK8subptdiff[ijet];
	selpfjetAK8_bbyW_E[iseljet] = pfjetAK8_bbyW_E[ijet];
	selpfjetAK8_Kfactor[iseljet] = pfjetAK8_Kfactor[ijet];
	selpfjetAK8_Rnew[iseljet] = selpfjetAK8_Rnew[ijet];
	selpfjetAK8haselectron[iseljet] =  pfjetAK8haselectron[ijet];
	selpfjetAK8hasmuon[iseljet] =  pfjetAK8hasmuon[ijet];
	selpfjetAK8hasqg[iseljet] =  pfjetAK8hasqg[ijet];
	selpfjetAK8hasb[iseljet] =  pfjetAK8hasb[ijet];
	selpfjetAK8hashadtop[iseljet] =  pfjetAK8hashadtop[ijet];
	selpfjetAK8hasleptop[iseljet] = pfjetAK8hasleptop[ijet];
	selpfjetAK8hastop[iseljet] = pfjetAK8hastop[ijet];
	selpfjetAK8hashadtop_alldecay[iseljet] = pfjetAK8hashadtop_alldecay[ijet];
	selpfjetAK8hasleptop_alldecay[iseljet] = pfjetAK8hasleptop_alldecay[ijet];
	selpfjetAK8re_tvsb[iseljet] = pfjetAK8re_tvsb[ijet];
	selpfjetAK8rnu_tvsb[iseljet] = pfjetAK8rnu_tvsb[ijet];
	
	iseljet++;
	if(iseljet>=njetmxAK8) break;
}
	npfjetAK8_all = iseljet;
	
	Tout6->Fill();	


return kTRUE;
}

void Anal_Leptop_PROOF::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.
   
   fileOut->cd();
   fileOut->Write();

   fOutput->Add(OutFile);

   fileOut->Close();

}

void Anal_Leptop_PROOF::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}

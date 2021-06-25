#include <string>
#include <cmath>
#include <cassert>
#include <sstream>
#include <string>

#include <iostream>
#include <fstream>

#include "Functions.h"

using namespace std;

class AK4Jet {

  public:
    
    float  area;
    float  btagCMVA;
    float  btagCSVV2;
    float  btagDeepB;
    float  btagDeepC;
    float  btagDeepFlavB;
    float  chEmEF;
    float  chHEF;
    float  eta;
    float  mass;
    float  muEF;
    float  neEmEF;
    float  neHEF;
    float  phi;
    float  pt;
    float  qgl;
    float  rawFactor;
    float  bRegCorr;
    float  bRegRes;
    int  electronIdx1;
    int  electronIdx2;
    int  jetId;
    int  muonIdx1;
    int  muonIdx2;
    int  nConstituents;
    int  nElectrons;
    int  nMuons;
    float  puId;
    float  CSVv2MCeff;
    float  DeepCSVMCeff;
    float  DeepFlavBMCeff;
    int    genJetIdx;  
    int    hadronFlavour;   
    int    partonFlavour; 
     
    float   deepflavbtagSF;
    float   deepflavbtagSF_up;
    float   deepflavbtagSF_down;
    float   deepflavbtagSF_shape;
    float   deepflavbtagSF_shape_up_jes;
    float   deepflavbtagSF_shape_down_jes;
    float   deepflavbtagSF_shape_up_lf;
    float   deepflavbtagSF_shape_down_lf;
    float   deepflavbtagSF_shape_up_hf;
    float   deepflavbtagSF_shape_down_hf;
    float   deepflavbtagSF_shape_up_hfstats1;
    float   deepflavbtagSF_shape_down_hfstats1;
    float   deepflavbtagSF_shape_up_hfstats2;
    float   deepflavbtagSF_shape_down_hfstats2;
    float   deepflavbtagSF_shape_up_lfstats1;
    float   deepflavbtagSF_shape_down_lfstats1;
    float   deepflavbtagSF_shape_up_lfstats2;
    float   deepflavbtagSF_shape_down_lfstats2;
    float   deepflavbtagSF_shape_up_cferr1;
    float   deepflavbtagSF_shape_down_cferr1;
    float   deepflavbtagSF_shape_up_cferr2;
    float   deepflavbtagSF_shape_down_cferr2;
    
    float pt_jes_up;
    float pt_jes_dn;
    float pt_jer_up;
    float pt_jer_dn;
    
    float mass_jes_up;
    float mass_jes_dn;
    float mass_jer_up;
    float mass_jer_dn;
    
    int  MatchGenJet;
    float GenJetpt;
    float GenJeteta;
    float GenJetphi;
    float GenJetmass;
    
    int MatchFatJet;
    int jettag;
    
    TLorentzVector p4;
    TLorentzVector jesup_p4;
    TLorentzVector jesdn_p4;
    TLorentzVector jerup_p4;
    TLorentzVector jerdn_p4;
}; 

class AK8Jet {

  public:
    
    float  area;
    float  btagCMVA;
    float  btagCSVV2;
    float  btagDeepB;
    float  btagHbb;
    float  deepTagMD_H4qvsQCD;
    float  deepTagMD_HbbvsQCD;
    float  deepTagMD_TvsQCD;
    float  deepTagMD_WvsQCD;
    float  deepTagMD_ZHbbvsQCD;
    float  deepTagMD_ZHccvsQCD;
    float  deepTagMD_ZbbvsQCD;
    float  deepTagMD_ZvsQCD;
    float  deepTagMD_ZccvsQCD;
    float  deepTagMD_bbvsLight;
    float  deepTagMD_ccvsLight;
    float  deepTag_H;
    float  deepTag_QCD;
    float  deepTag_QCDothers;
    float  deepTag_TvsQCD;
    float  deepTag_WvsQCD;
    float  deepTag_ZvsQCD;
    float  eta;
    float  mass;
    float  msoftdrop;
    float  n2b1;
    float  n3b1;
    float  phi;
    float  pt;
    float  rawFactor;
    float  tau1;
    float  tau2;
    float  tau3;
    float  tau4;
    float  subbtagCSVV2;
    float  subbtagDeepB;
    float  jetId;
    int  subJetIdx1;
    int  subJetIdx2;
    int  nConstituents;
    int  nElectrons;
    int  nMuons;
    int  puId;
    float  CSVv2MCeff;
    float  DeepCSVMCeff;
    float  DeepFlavBMCeff;
    
    float pt_jes_up;
    float pt_jes_dn;
    float pt_jer_up;
    float pt_jer_dn;
    
    float mass_jes_up;
    float mass_jes_dn;
    float mass_jer_up;
    float mass_jer_dn;
    
    int  MatchGenJet;
    float GenJetpt;
    float GenJeteta;
    float GenJetphi;
    float GenJetmass;
    
    int MatchJet;
    int jettag;
    
    TLorentzVector p4;
    TLorentzVector jesup_p4;
    TLorentzVector jesdn_p4;
    TLorentzVector jerup_p4;
    TLorentzVector jerdn_p4;
}; 

class Muon {

  public:
    
    float  dxy;
    float  dxyErr;
    float  dz;
    float  dzErr;
    float  eta;
    float  ip3d;
    float  jetPtRelv2;
    float  jetRelIso;
    float  mass;
    float  miniPFRelIso_all;
    float  miniPFRelIso_chg;
    float  pfRelIso03_all;
    float  pfRelIso03_chg;
    float  pfRelIso04_all;
    float  phi;
    float  pt;
    float  ptErr;
    float  segmentComp;
    float  sip3d;
    int  mvaTTH;
    int  mvaTOP;
    int  charge;
    int  jetIdx;
    int  nStations;
    int  nTrackerLayers;
    int  pdgId;
    int  tightCharge;
    int  highPtId;
    bool inTimeMuon;
    bool isGlobal;
    bool isPFcand;
    bool isTracker;
    bool mediumId;
    bool mediumPromptId;
    unsigned char miniIsoId;
    unsigned char multiIsoId;
    unsigned char mvaId;
    unsigned char pfIsoId;
    unsigned char softId;
    bool softMvaId;
    bool tightId;
    bool tkIsoId;
    bool triggerIdLoose;
    
    TLorentzVector p4;
    
} ;

class Electron {

  public:
    
    float  deltaEtaSC;
    float  dr03EcalRecHitSumEt;
    float  dr03HcalDepth1TowerSumEt;
    float  dr03TkSumPt;
    float  dr03TkSumPtHEEP;
    float  dxy;
    float  dxyErr;
    float  dz;
    float  dzErr;
    float  eInvMinusPInv;
    float  energyErr;
    float  eta;
    float  hoe;
    float  ip3d;
    float  jetRelIso;
    float  mass;
    float  miniPFRelIso_all;
    float  miniPFRelIso_chg;
    float  mvaFall17V1Iso;
    float  mvaFall17V1noIso;
    float  mvaFall17V2noIso;
    float  pfRelIso03_all;
    float  pfRelIso03_chg;
    float  phi;
    float  pt;
    float  r9;
    float  sieie;
    float  sip3d;
    float  mvaTTH;
    float  mvaTOP;
    float  eCorr;
    int  charge;
    int  cutBased;
    int  cutBased_Fall17_V1;
    int  jetIdx;
    int  pdgId;
    int  photonIdx;
    int  tightCharge;
    int  vidNestedWPBitmap;
    bool convVeto;
//    bool cutBased;
	bool cutBased_HEEP;
    bool isPFcand;
    unsigned char lostHits;
    bool mvaFall17V1Iso_WP80;
    bool mvaFall17V1Iso_WP90;
    bool mvaFall17V1Iso_WPL;
    bool mvaFall17V1noIso_WP80;
    bool mvaFall17V1noIso_WP90;
    bool mvaFall17V1noIso_WPL;
    bool mvaFall17V2Iso_WP80;
    bool mvaFall17V2Iso_WP90;
    bool mvaFall17V2Iso_WPL;
    bool mvaFall17V2noIso_WP80;
    bool mvaFall17V2noIso_WP90;
    bool mvaFall17V2noIso_WPL;   
    unsigned char ecalBadCalibFilterV2;
    
    TLorentzVector p4;
    
} ;


class Photon {

  public:
   
    float  energyErr;
    float  eta;
    float  hoe;
    float  mass;
    float  mvaID;
    float  mvaIDV1;
    float  pfRelIso03_all;
    float  pfRelIso03_chg;
    float  phi;
    float  pt;
    float  r9;
    float  sieie;
    float  eCorr;
    int  charge;
    int  cutBasedBitmap;
    int  cutBasedV1Bitmap;
    int  jetIdx;
    int  pdgId;
    int  electronIdx;
    int  vidNestedWPBitmap;
    bool electronVeto;
    bool isScEtaEB;
    bool isScEtaEE;
    bool mvaID_WP80;
    bool mvaID_WP90;
    bool pixelSeed;
    
    TLorentzVector p4;
    
} ;

class SubJet {
   
  public:   
   
    float  btagCMVA;
    float  btagCSVV2;
    float  btagDeepB;
    float  eta;
    float  mass;
    float  n2b1;
    float  n3b1;
    float  pfRelIso03_all;
    float  pfRelIso03_chg;
    float  phi;
    float  pt;
    float  r9;
    float  rawFactor;
    float  tau1;
    float  tau2;
    float  tau3;
    float  tau4;
    
    TLorentzVector p4;
    
} ;

class AK4GenJet {

  public:
   
    float  eta;
    float  mass;
    float  phi;
    float  pt;
    int hadronFlavor;
    int partonFlavor;
    
    TLorentzVector p4;
    
}; 

class AK8GenJet {

  public:
     
    float  eta;
    float  mass;
    float  phi;
    float  pt;
    int hadronFlavor;
    int partonFlavor;
    
    TLorentzVector p4;
  
} ;

class GenParton{
  
  public:
   
    float  eta;
    float  mass;
    float  phi;
    float  pt;
    int genPartIdxMother;
    int pdgId;
    int status;
    int statusFlags;
    
    TLorentzVector p4;
    
} ;

class Tau{

   public:

   float  chargedIso;
   float  dxy;
   float  dz;
   float  eta;
   float  leadTkDeltaEta;
   float  leadTkDeltaPhi;
   float  leadTkPtOverTauPt;
   float  mass;
   float  neutralIso;
   float  phi;
   float  photonsOutsideSignalCone;
   float  pt;
   float  puCorr;
   float  rawAntiEle;
   float  rawIso;
   float  rawIsodR03;
   float  rawMVAnewDM2017v2;
   float  rawMVAoldDM;
   float  rawMVAoldDM2017v1;
   float  rawMVAoldDM2017v2;
   float  rawMVAoldDMdR032017v2;
   int    charge;
   int    decayMode;
   int    jetIdx;
   int    rawAntiEleCat;
   unsigned char idAntiEle;
   unsigned char idAntiMu;
   bool  idDecayMode;
   bool  idDecayModeNewDMs;
   unsigned char idMVAnewDM2017v2;
   unsigned char idMVAoldDM;
   unsigned char idMVAoldDM2017v1;
   unsigned char idMVAoldDM2017v2;
   unsigned char idMVAoldDMdR032017v2;	
   
   TLorentzVector p4;
    	
};

bool Muon_sort_by_pt(Muon i1, Muon i2) 
{ 
    return (i1.pt > i2.pt); 
}

void sorted_by_pt(vector<Muon> & objs) {
  sort(objs.begin(), objs.end(), Muon_sort_by_pt);
}

bool Electron_sort_by_pt(Electron i1, Electron i2) 
{ 
    return (i1.pt > i2.pt); 
}

void sorted_by_pt(vector<Electron> & objs) {
  sort(objs.begin(), objs.end(), Electron_sort_by_pt);
}


bool Photon_sort_by_pt(Photon i1, Photon i2) 
{ 
    return (i1.pt > i2.pt); 
}

void sorted_by_pt(vector<Photon> & objs) {
  sort(objs.begin(), objs.end(), Photon_sort_by_pt);
}


bool AK4Jet_sort_by_pt(AK4Jet i1, AK4Jet i2) 
{ 
    return (i1.pt > i2.pt); 
}

void sorted_by_pt(vector<AK4Jet> & objs) {
  sort(objs.begin(), objs.end(), AK4Jet_sort_by_pt);
}

bool AK4Jet_sort_by_DeepFlav(AK4Jet i1, AK4Jet i2) 
{ 
    return (i1.btagDeepFlavB > i2.btagDeepFlavB); 
}

void sorted_by_DeepFlav(vector<AK4Jet> & objs) {
  sort(objs.begin(), objs.end(), AK4Jet_sort_by_DeepFlav);
}

bool AK8Jet_sort_by_DeepAK8_Htag(AK8Jet i1, AK8Jet i2) 
{ 
    return (i1.deepTagMD_bbvsLight > i2.deepTagMD_bbvsLight); 
}

void sorted_by_DeepAK8_Htag(vector<AK8Jet> & objs) {
  sort(objs.begin(), objs.end(), AK8Jet_sort_by_DeepAK8_Htag);
}

bool GenAK4Jet_sort_by_pt(AK4GenJet i1, AK4GenJet i2) 
{ 
    return (i1.pt > i2.pt); 
}

void sorted_by_pt(vector<AK4GenJet> & objs) {
  sort(objs.begin(), objs.end(), GenAK4Jet_sort_by_pt);
}

bool AK8Jet_sort_by_pt(AK8Jet i1, AK8Jet i2) 
{ 
    return (i1.pt > i2.pt); 
}

void sorted_by_pt(vector<AK8Jet> & objs) {
  sort(objs.begin(), objs.end(), AK8Jet_sort_by_pt);
}

bool GenAK8Jet_sort_by_pt(AK8GenJet i1, AK8GenJet i2) 
{ 
    return (i1.pt > i2.pt); 
}

void sorted_by_pt(vector<AK8GenJet> & objs) {
  sort(objs.begin(), objs.end(), GenAK8Jet_sort_by_pt);
}


int get_nearest_GenJet_AK8(vector<AK8GenJet>  & objs, TLorentzVector tmp_vec) {
	
	float minR = 0.8;
	int nearest = -1;
	
	for(unsigned iobs=0; iobs<objs.size(); iobs++){
		
	   if(delta2R(objs[iobs].eta,objs[iobs].phi,tmp_vec.Eta(),tmp_vec.Phi()) < minR){
		   
		   minR = delta2R(objs[iobs].eta,objs[iobs].phi,tmp_vec.Eta(),tmp_vec.Phi()) ;
		   nearest = iobs;
		   
		   }
	   
	   }
	   
	return  nearest;
}

int get_nearest_GenJet_AK4(vector<AK4GenJet>  & objs, TLorentzVector tmp_vec) {
	
	float minR = 0.4;
	int nearest = -1;
	
	for(unsigned iobs=0; iobs<objs.size(); iobs++){
		
	   if(delta2R(objs[iobs].eta,objs[iobs].phi,tmp_vec.Eta(),tmp_vec.Phi()) < minR){
		   
		   minR = delta2R(objs[iobs].eta,objs[iobs].phi,tmp_vec.Eta(),tmp_vec.Phi()) ;
		   nearest = iobs;
		   
		   }
	   
	   }
	   
	return  nearest;
}


int get_nearest_AK8(vector<AK8Jet>  & objs, TLorentzVector tmp_vec) {
	
	float minR = 0.8;
	int nearest = -1;
	
	for(unsigned iobs=0; iobs<objs.size(); iobs++){
		
	   if(delta2R(objs[iobs].eta,objs[iobs].phi,tmp_vec.Eta(),tmp_vec.Phi()) < minR){
		   
		   minR = delta2R(objs[iobs].eta,objs[iobs].phi,tmp_vec.Eta(),tmp_vec.Phi()) ;
		   nearest = iobs;
		   
		   }
	   
	   }
	   
	return  nearest;
}

int get_nearest_AK4(vector<AK4Jet>  & objs, TLorentzVector tmp_vec) {
	
	float minR = 0.4;
	int nearest = -1;
	
	for(unsigned iobs=0; iobs<objs.size(); iobs++){
		
	   if(delta2R(objs[iobs].eta,objs[iobs].phi,tmp_vec.Eta(),tmp_vec.Phi()) < minR){
		   
		   minR = delta2R(objs[iobs].eta,objs[iobs].phi,tmp_vec.Eta(),tmp_vec.Phi()) ;
		   nearest = iobs;
		   
		   }
	   
	   }
	   
	return  nearest;
}


float compute_HT(vector<AK4Jet>  & objs, float ptcut, float etacut){
	
	float HT = 0;
	
	for(unsigned iobs=0; iobs<objs.size(); iobs++){
		
		if(objs[iobs].pt > ptcut && abs(objs[iobs].eta)<=etacut){
			
			HT += objs[iobs].pt;
			
		}
	}
	
	return HT;
}

void Z_selection_from_muons(vector<Muon>  & objs, float low_mass, float high_mass, vector<int> & Z_cand){
	
	int lep_1 = -1;
	int lep_2 = -1;
	
	for(unsigned iobs=0; iobs<objs.size(); iobs++){
		   
		   TLorentzVector t1 = objs[iobs].p4;
		   
		   for(unsigned jobs=(iobs+1); jobs<objs.size(); jobs++){
			   
			    if(!((objs[iobs].charge * objs[jobs].charge) < 0)) continue;
			   
				TLorentzVector t2 = objs[jobs].p4;
				
				if((t1+t2).M()>low_mass && (t1+t2).M()<high_mass){
					
					lep_1 = iobs;
					lep_2 = jobs;
					
					break;
					
					}
			   
			   }
		   }
		   
   Z_cand.push_back(lep_1);
   Z_cand.push_back(lep_2);
	
}

void Z_selection_from_electrons(vector<Electron>  & objs, float low_mass, float high_mass, vector<int> & Z_cand){
	
	int lep_1 = -1;
	int lep_2 = -1;
	
	for(unsigned iobs=0; iobs<objs.size(); iobs++){
		   
		   TLorentzVector t1 = objs[iobs].p4;
		   
		   for(unsigned jobs=(iobs+1); jobs<objs.size(); jobs++){
			   
			    if(!((objs[iobs].charge * objs[jobs].charge) < 0)) continue;
			   
				TLorentzVector t2 = objs[jobs].p4;
				
				if((t1+t2).M()>low_mass && (t1+t2).M()<high_mass){
					
					lep_1 = iobs;
					lep_2 = jobs;
					
					break;
					
					}
			   
			   }
		   }
		   
   Z_cand.push_back(lep_1);
   Z_cand.push_back(lep_2);
	
}

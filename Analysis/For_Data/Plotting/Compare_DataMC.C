#include "iostream"
#include "TFile.h"
#include "TMath.h"
#include "TTree.h"
#include "TH1F.h"
#include "TH1D.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "THStack.h"
#include <iomanip>

#include "My_Style.C"

//#define Matching
//#define No_Matching

static const int nfiles = 8;

const char *filenames[nfiles] = {
				//				"/home/suman/CMS_Physics/Leptop/New_version/Data_MC/EMU/Total_SingleElectron_Data.root",
								"/home/suman/CMS_Physics/Leptop/New_version/Data_MC/EJets_JetHT/JetHT_Data_2018D_nogen.root",//Muon_Data_2018D.root",
		//					    "/home/suman/CMS_Physics/Leptop/New_version/Data_MC/EMU/TT_SemiLep_ej.root",
		//					    "/home/suman/CMS_Physics/Leptop/New_version/Data_MC/EJets_JetHT/Total_TT_nogen.root",
							    "/home/suman/CMS_Physics/Leptop/New_version/Data_MC/EJets_JetHT/TT_Lep_ej.root",
							    "/home/suman/CMS_Physics/Leptop/New_version/Data_MC/EJets_JetHT/TT_Had_noej_nogen.root",
							    "/home/suman/CMS_Physics/Leptop/New_version/Data_MC/EJets_JetHT/Total_QCD.root",
								"/home/suman/CMS_Physics/Leptop/New_version/Data_MC/EJets_JetHT/Total_ST.root",
								"/home/suman/CMS_Physics/Leptop/New_version/Data_MC/EJets_JetHT/Total_DYJets.root",
								"/home/suman/CMS_Physics/Leptop/New_version/Data_MC/EJets_JetHT/Total_WJets.root",
								"/home/suman/CMS_Physics/Leptop/New_version/Data_MC/EJets_JetHT/Total_DiBoson.root"
								};								
/*

const char *filenames[nfiles] = {
				//				"/home/suman/CMS_Physics/Leptop/New_version/Total_SingleElectron_Data.root",
								"/home/suman/CMS_Physics/Leptop/New_version/Data_MC/EMU_Muon/SingleMuon_Data_2018D.root",//Muon_Data_2018D.root",
		//					    "/home/suman/CMS_Physics/Leptop/New_version/Data_MC/EMU_Muon/TT_DiLep_emu.root",
		//					    "/home/suman/CMS_Physics/Leptop/New_version/Data_MC/EMU_Muon/Total_TT.root",
							    "/home/suman/CMS_Physics/Leptop/New_version/Data_MC/EMU_Muon/TT_Lep_emu.root",
							    "/home/suman/CMS_Physics/Leptop/New_version/Data_MC/EMU_Muon/TT_Had_emu_nogen.root",
							    "/home/suman/CMS_Physics/Leptop/New_version/Data_MC/EMU_Muon/Total_QCD.root",
								"/home/suman/CMS_Physics/Leptop/New_version/Data_MC/EMU_Muon/Total_ST.root",
								"/home/suman/CMS_Physics/Leptop/New_version/Data_MC/EMU_Muon/Total_DYJets.root",
								"/home/suman/CMS_Physics/Leptop/New_version/Data_MC/EMU_Muon/Total_WJets.root",
								"/home/suman/CMS_Physics/Leptop/New_version/Data_MC/EMU_Muon/Total_DiBoson.root"
								};	
*/

float lumi_fac[nfiles] = 	  {		1.,// 0.875,
//									0.00000607799,
//									0.0000190505,
									1,
									0.00000604081,
									1,
									1,
									1,
									1,
									1
							  };

float data_lumi = 31.9;//31.9;//59.7;

void Compare_DataMC()
{

static const int nobshist = 29;

int ncat = nobshist-12;

TH1D *hist_obs[nobshist][nfiles] ;
TH1D *hist_obs_1[nobshist][nfiles] ;
TH1D *hist_obs_2[nobshist][nfiles] ;

const char *obsnames[nobshist] = {
	  "pt","y","mass",
	  "NHad","neuhad","sdmass","chrad","subhaddiff","tau21",
	  "DAK8_topvsQCD","bbyW_E","Kfactor",
	  "re","rnu",
	  "hadsdmass",
	 "haspfelectron",
	 "rt",
	 "N_PV_sel",
	 "hist_PFMET","hist_PFMET_pass",
	 "HTop_pt","HTop_y","HTop_sdmass","HTop_DAK8","HTop_tau32",
	 "Counter",
	 "NJets_AK8","NJets_AK4","NBJets_AK4",
	  };
 
const char *obstitles[nobshist] = {
	  "P_{T} (GeV)","y","Mass (GeV)",
	  "1-f_{h}","f_{1-h}^{N}","M_{SD} (GeV)","r_{C}","A_{h}","#tau_{21}",
	  "Mass decorrelated DeepAK8 score","Z_{b}","#Theta_{b/e}",
	  "r_{e}","r_{#nu}",
	  "M_{SD} (GeV) of hadronic top",
	  "haspfelectron",
	  "r_{ne}",
	  "N_{PV}","p^{miss}_{T} (GeV)","p^{miss}_{T} (GeV)",
	  "p^{th}_{T} (GeV)","y^{th}","M^{th}_{SD} (GeV)","DeepAK8 score of hadronic top","#tau_{32} of hadronic top",
	  "Counter",
	  "# of AK8 jets","# of AK4 jets","# of AK4 b jets"
	  }; 

const char *obslabels[nobshist] = {
	  "P_{T}","y","M",
	  "(1-f_{h})","(f_{1-h}^{N})","M_{SD}","r_{C}","A_h","#tau_{21}",
	  "(MD DeepAK8)","Z_b","#Theta_{b/e}",
	  "r_e","r_{#nu}",
	  "M^{th}_{SD}",
	  "haspfelectron",
	  "r_t"
	  "N_{PV}","p^{miss}_{T}","p^{miss}_{T}"
	  }; 
 
TH1D *h_Nvert[nfiles];

TFile *filein;

char name[200];

for(int fg=0; fg<nfiles; fg++){
	
if(fg>0){ lumi_fac[fg] *= data_lumi; }
 
 cout<<filenames[fg]<<" "<<lumi_fac[fg]<<endl;
 
 sprintf(name,"%s",filenames[fg]);
 filein = new TFile(name,"read");
 
 for(int ihist=0; ihist<nobshist; ihist++){
 
    if(ihist<(ncat)){
		#ifdef Matching
		sprintf(name,"Obs_%s_match",obsnames[ihist]);
		#elif defined No_Matching
		sprintf(name,"Obs_%s_nomatch",obsnames[ihist]);
		#else
		sprintf(name,"Obs_%s",obsnames[ihist]);
		#endif
	}else{
		sprintf(name,"%s",obsnames[ihist]);
		}
	hist_obs[ihist][fg] = (TH1D*)filein->Get(name);
	hist_obs[ihist][fg]->Scale(lumi_fac[fg]);
    
    if(ihist<(ncat)){
    
    #ifdef Matching
	sprintf(name,"Obs_%s_match_pass",obsnames[ihist]);
	#elif defined No_Matching
	sprintf(name,"Obs_%s_nomatch_pass",obsnames[ihist]);
	#else
	sprintf(name,"Obs_%s_pass",obsnames[ihist]);
	#endif
	hist_obs_1[ihist][fg] = (TH1D*)filein->Get(name);
	hist_obs_1[ihist][fg]->Scale(lumi_fac[fg]);
 
	#ifdef Matching
	sprintf(name,"Obs_%s_match_fail",obsnames[ihist]);
	#elif defined No_Matching
	sprintf(name,"Obs_%s_nomatch_fail",obsnames[ihist]);
	#else
	sprintf(name,"Obs_%s_fail",obsnames[ihist]);
	#endif
	hist_obs_2[ihist][fg] = (TH1D*)filein->Get(name);
	hist_obs_2[ihist][fg]->Scale(lumi_fac[fg]);
 
		}
 
	}
}

     
//int col[nfiles-1]  = {kRed,kGreen+4,kBlue,kOrange+7,kCyan+1,kMagenta-7};
int col[nfiles-1]  = {kRed,kMagenta-7,kGreen+4,kBlue,kOrange+7,kCyan+1,kRed-5};

const char *dataname[nfiles] = {"Data",/*"t #bar{t} (e+j)",*/"t #bar{t} (leptonic)","t #bar{t} (hadronic)","QCD","Single t","Z+j","W+j","DiBoson"};
//const char *dataname[nfiles] = {"Data","t #bar{t} (SemiLep)","t #bar{t} (DiLep)","t #bar{t} (Had)","QCD","Single t","Z+j","W+j","DiBoson"};

 THStack *hist_obs_stack[nobshist];
 THStack *hist_obs_1_stack[nobshist];
 THStack *hist_obs_2_stack[nobshist];
 
 TH1D *hist_obs_bkg[nobshist];
 TH1D *rat_obs[nobshist];
 
 TH1D *hist_obs_1_bkg[nobshist];
 TH1D *rat_obs_1[nobshist];
 
 TH1D *hist_obs_2_bkg[nobshist];
 TH1D *rat_obs_2[nobshist];
 
 TCanvas *cv[nobshist];
 TLegend *legv[nobshist];
 
 TCanvas *cv_1[nobshist];
 TLegend *legv_1[nobshist];
 
 TCanvas *cv_2[nobshist];
 TLegend *legv_2[nobshist];
 
 for(int iv=0; iv<nobshist; iv++){
 	 
	sprintf(name,"Stack_%s",obsnames[iv]);
	hist_obs_stack[iv] = new THStack(name,"");
	
	if(iv<(ncat)){
	
	sprintf(name,"Stack_pass_%s",obsnames[iv]);
	hist_obs_1_stack[iv] = new THStack(name,"");
	
	sprintf(name,"Stack_fail_%s",obsnames[iv]);
	hist_obs_2_stack[iv] = new THStack(name,"");
	 
	}
	 
	for(int bkg=1; bkg<(nfiles); bkg++){ 
		
		hist_obs[iv][nfiles-bkg]->SetFillColor(col[nfiles-bkg-1]);
		hist_obs[iv][nfiles-bkg]->SetLineColor(col[nfiles-bkg-1]);
		hist_obs[iv][nfiles-bkg]->GetYaxis()->SetTitleOffset(1.2);
		hist_obs_stack[iv]->Add(hist_obs[iv][nfiles-bkg]);
	
		if(iv<(ncat)){
		
		hist_obs_1[iv][nfiles-bkg]->SetFillColor(col[nfiles-bkg-1]);
		hist_obs_1[iv][nfiles-bkg]->SetLineColor(col[nfiles-bkg-1]);
		hist_obs_1_stack[iv]->Add(hist_obs_1[iv][nfiles-bkg]);
		
		hist_obs_2[iv][nfiles-bkg]->SetFillColor(col[nfiles-bkg-1]);
		hist_obs_2[iv][nfiles-bkg]->SetLineColor(col[nfiles-bkg-1]);
		hist_obs_2_stack[iv]->Add(hist_obs_2[iv][nfiles-bkg]);
		
		}
	}
	
	
	for(int bkg=0; bkg<(nfiles-1); bkg++){ 	
		
		if(bkg==0) { hist_obs_bkg[iv] = (TH1D*)hist_obs[iv][bkg+1]->Clone(); }
		else { hist_obs_bkg[iv]->Add(hist_obs[iv][bkg+1]); }
		
		if(iv<(ncat)){
		
		if(bkg==0) { hist_obs_1_bkg[iv] = (TH1D*)hist_obs_1[iv][bkg+1]->Clone(); }
		else { hist_obs_1_bkg[iv]->Add(hist_obs_1[iv][bkg+1]); }
		
		if(bkg==0) { hist_obs_2_bkg[iv] = (TH1D*)hist_obs_2[iv][bkg+1]->Clone(); }
		else { hist_obs_2_bkg[iv]->Add(hist_obs_2[iv][bkg+1]); }
	
		}
	}
	
//	h_var_sb[iv][0]->Scale(h_var_bkg[iv]->Integral()*1./h_var_sb[iv][0]->Integral());
	
	sprintf(name,"%s",obstitles[iv]);
	hist_obs[iv][0]->GetXaxis()->SetTitle(name);
	hist_obs[iv][0]->GetXaxis()->SetTitleSize(0.045);
	hist_obs[iv][0]->GetXaxis()->SetLabelSize(0.045);
	hist_obs[iv][0]->GetXaxis()->CenterTitle();
	
//	sprintf(name,"d#sigma / d%s (in fb/unit)",obslabels[iv]);
	sprintf(name,"No. of events");
	hist_obs[iv][0]->GetYaxis()->SetTitle(name);
	hist_obs[iv][0]->GetYaxis()->SetTitleSize(0.04);
	hist_obs[iv][0]->GetYaxis()->SetLabelSize(0.04);
	hist_obs[iv][0]->GetYaxis()->SetTitleOffset(1.4);
	hist_obs[iv][0]->GetYaxis()->CenterTitle();
	
	if(iv<(ncat)){
	
	sprintf(name,"%s",obstitles[iv]);
	hist_obs_1[iv][0]->GetXaxis()->SetTitle(name);
	hist_obs_1[iv][0]->GetXaxis()->SetTitleSize(0.045);
	hist_obs_1[iv][0]->GetXaxis()->SetLabelSize(0.045);
	hist_obs_1[iv][0]->GetXaxis()->CenterTitle();
	
//	sprintf(name,"d#sigma / d%s (in fb/unit)",obslabels[iv]);
	sprintf(name,"No. of events");
	hist_obs_1[iv][0]->GetYaxis()->SetTitle(name);
	hist_obs_1[iv][0]->GetYaxis()->SetTitleSize(0.04);
	hist_obs_1[iv][0]->GetYaxis()->SetLabelSize(0.04);
	hist_obs_1[iv][0]->GetYaxis()->SetTitleOffset(1.4);
	hist_obs_1[iv][0]->GetYaxis()->CenterTitle();
	
	sprintf(name,"%s",obstitles[iv]);
	hist_obs_2[iv][0]->GetXaxis()->SetTitle(name);
	hist_obs_2[iv][0]->GetXaxis()->SetTitleSize(0.045);
	hist_obs_2[iv][0]->GetXaxis()->SetLabelSize(0.045);
	hist_obs_2[iv][0]->GetXaxis()->CenterTitle();
	
//	sprintf(name,"d#sigma / d%s (in fb/unit)",obslabels[iv]);
	sprintf(name,"No. of events");
	hist_obs_2[iv][0]->GetYaxis()->SetTitle(name);
	hist_obs_2[iv][0]->GetYaxis()->SetTitleSize(0.04);
	hist_obs_2[iv][0]->GetYaxis()->SetLabelSize(0.04);
	hist_obs_2[iv][0]->GetYaxis()->SetTitleOffset(1.4);
	hist_obs_2[iv][0]->GetYaxis()->CenterTitle();
	
	}
	
	// canv obs //
	
	sprintf(name,"Canv_%s",obsnames[iv]);
	hist_obs[iv][0]->SetMaximum(1.1 * max(hist_obs[iv][0]->GetMaximum(),hist_obs_bkg[iv]->GetMaximum()));
	if(iv==15){
		hist_obs[iv][0]->SetMinimum(0);
	}
	else{
		hist_obs[iv][0]->SetMinimum(0.5);
		}
		
	cv[iv] = tdrDiCanvas(name,hist_obs[iv][0],hist_obs_bkg[iv],8,0);
	
	if(iv==3||iv==14||iv==8){
		legv[iv] = tdrLeg(0.2,0.65,0.395,0.915);
	}else{
		legv[iv] = tdrLeg(0.65,0.65,0.875,0.915);
	}
	
	legv[iv]->SetTextFont(42);
	legv[iv]->SetTextSize(0.045);
	legv[iv]->SetBorderSize(0);

	for(int bkg=0; bkg<(nfiles); bkg++){ 
		if(bkg==0){ legv[iv]->AddEntry(hist_obs[iv][bkg],dataname[bkg],"ep"); }
		else{	
		legv[iv]->AddEntry(hist_obs[iv][bkg],dataname[bkg],"f");
			}
	}

	cv[iv]->cd(1);

	if(iv==0||iv==4||iv==5||iv==7||iv==9||iv==10||iv==12||iv==13||iv==16||iv==17||iv==18||iv==19||iv==23||iv==24||iv==25||iv==26) 
	{ 
		gPad->SetLogy(1);
		hist_obs[iv][0]->SetMaximum(20*hist_obs[iv][0]->GetMaximum());
	}
	if(iv==0){
		gPad->SetLogx(1);
		}

	hist_obs[iv][0]->SetFillStyle(0);
	hist_obs[iv][0]->SetFillColor(0);
	hist_obs[iv][0]->SetMarkerStyle(kFullCircle);
	hist_obs[iv][0]->SetMarkerColor(kBlack);
	hist_obs[iv][0]->SetMarkerSize(0.7);
	hist_obs[iv][0]->SetLineColor(kBlack);
	
//	hist_obs_stack[iv]->SetMinimum(0.5);

	hist_obs[iv][0]->GetYaxis()->SetTitleOffset(1.5);

	hist_obs_stack[iv]->Draw("histSAME");
	hist_obs[iv][0]->Draw("PSAME");
	
	gPad->RedrawAxis();
	
	cv[iv]->cd(2);
	
//	rat_obs[iv] = (TH1D*)hist_obs_bkg[iv]->Clone();
//	rat_obs[iv]->Divide(hist_obs[iv][0]);
	rat_obs[iv] = (TH1D*)hist_obs[iv][0]->Clone();
	rat_obs[iv]->Divide(hist_obs_bkg[iv]);
	
	if(iv==0){
		gPad->SetLogx(1);
		rat_obs[iv]->GetXaxis()->SetMoreLogLabels(kTRUE);
		rat_obs[iv]->GetXaxis()->SetNoExponent(kTRUE);
		}
	
	sprintf(name,"%s",obstitles[iv]);
	rat_obs[iv]->GetXaxis()->SetTitle(name);
	rat_obs[iv]->GetXaxis()->SetTitleSize(0.1);
	rat_obs[iv]->GetXaxis()->SetLabelSize(0.1);
	rat_obs[iv]->GetXaxis()->CenterTitle();
	
	rat_obs[iv]->GetYaxis()->SetTitle("Data / MC");
	rat_obs[iv]->GetYaxis()->SetTitleSize(0.1);
	rat_obs[iv]->GetYaxis()->SetLabelSize(0.1);
	rat_obs[iv]->GetYaxis()->SetTitleOffset(0.75);
	rat_obs[iv]->GetYaxis()->SetNdivisions(406);
	rat_obs[iv]->GetYaxis()->CenterTitle();
	
	rat_obs[iv]->SetMinimum(0);
	rat_obs[iv]->SetMaximum(2.);
	
	rat_obs[iv]->SetFillStyle(0);
	rat_obs[iv]->SetFillColor(0);
	rat_obs[iv]->SetMarkerStyle(kFullCircle);
	rat_obs[iv]->SetMarkerColor(kBlack);
	rat_obs[iv]->SetMarkerSize(0.7);
	rat_obs[iv]->SetLineColor(kBlack);
	
	rat_obs[iv]->Draw("e,p");

	TLine *line = new TLine(rat_obs[iv]->GetBinLowEdge(1),1.,rat_obs[iv]->GetBinLowEdge(rat_obs[iv]->GetNbinsX()),1.);
	line->SetLineColor(7);
	line->Draw("sames");
	
	#ifdef Matching
	sprintf(name,"Data_MC/EJets_JetHT/%s_match.pdf",cv[iv]->GetName());
	#elif defined(No_Matching)
	sprintf(name,"Data_MC/EJets_JetHT/%s_nomatch.pdf",cv[iv]->GetName());
	#else
	sprintf(name,"Data_MC/EJets_JetHT/%s.pdf",cv[iv]->GetName());
	#endif
	
	cv[iv]->SaveAs(name);
	
	if(iv<(ncat)){
	
	// canv obs_1 //
	
	sprintf(name,"Canv_pass_%s",obsnames[iv]);
	hist_obs_1[iv][0]->SetMaximum(1.1 * max(hist_obs_1[iv][0]->GetMaximum(),hist_obs_1_bkg[iv]->GetMaximum()));
	cv_1[iv] = tdrDiCanvas(name,hist_obs_1[iv][0],hist_obs_1_bkg[iv],8,0);
	
	if(iv==3||iv==14){
		legv_1[iv] = tdrLeg(0.2,0.65,0.395,0.915);
	}else{
		legv_1[iv] = tdrLeg(0.65,0.65,0.875,0.915);
	}
	
	legv_1[iv]->SetTextFont(42);
	legv_1[iv]->SetTextSize(0.045);
	legv_1[iv]->SetBorderSize(0);

	for(int bkg=0; bkg<(nfiles); bkg++){ 
		if(bkg==0){ legv_1[iv]->AddEntry(hist_obs_1[iv][bkg],dataname[bkg],"ep"); }
		else{	
		legv_1[iv]->AddEntry(hist_obs_1[iv][bkg],dataname[bkg],"f");
			}
	}

	cv_1[iv]->cd(1);
	
	if(iv==0||iv==4||iv==5||iv==7||iv==9||iv==10||iv==12||iv==13||iv==17||iv==18||iv==19||iv==23||iv==24||iv==25||iv==26) 
	{ 
		gPad->SetLogy(1);
		hist_obs_1[iv][0]->SetMaximum(20*hist_obs_1[iv][0]->GetMaximum());
	}
	
	if(iv==15){
		hist_obs_1[iv][0]->SetMinimum(0);
	}
	
	hist_obs_1[iv][0]->SetFillStyle(0);
	hist_obs_1[iv][0]->SetFillColor(0);
	hist_obs_1[iv][0]->SetMarkerStyle(kFullCircle);
	hist_obs_1[iv][0]->SetMarkerColor(kBlack);
	hist_obs_1[iv][0]->SetMarkerSize(0.7);
	hist_obs_1[iv][0]->SetLineColor(kBlack);

	hist_obs_1[iv][0]->GetYaxis()->SetTitleOffset(1.5);

	hist_obs_1_stack[iv]->Draw("histSAME");
	hist_obs_1[iv][0]->Draw("PSAME");
	
	gPad->RedrawAxis();
	
	cv_1[iv]->cd(2);
	
//	rat_obs_1[iv] = (TH1D*)hist_obs_1_bkg[iv]->Clone();
//	rat_obs_1[iv]->Divide(hist_obs_1[iv][0]);
	rat_obs_1[iv] = (TH1D*)hist_obs_1[iv][0]->Clone();
	rat_obs_1[iv]->Divide(hist_obs_1_bkg[iv]);
	
	sprintf(name,"%s",obstitles[iv]);
	rat_obs_1[iv]->GetXaxis()->SetTitle(name);
	rat_obs_1[iv]->GetXaxis()->SetTitleSize(0.1);
	rat_obs_1[iv]->GetXaxis()->SetLabelSize(0.1);
	rat_obs_1[iv]->GetXaxis()->CenterTitle();
	
	rat_obs_1[iv]->GetYaxis()->SetTitle("Data / MC");
	rat_obs_1[iv]->GetYaxis()->SetTitleSize(0.1);
	rat_obs_1[iv]->GetYaxis()->SetLabelSize(0.1);
	rat_obs_1[iv]->GetYaxis()->SetTitleOffset(0.75);
	rat_obs_1[iv]->GetYaxis()->SetNdivisions(406);
	rat_obs_1[iv]->GetYaxis()->CenterTitle();
	
	rat_obs_1[iv]->SetMinimum(0);
	rat_obs_1[iv]->SetMaximum(2.);
	
	rat_obs_1[iv]->SetFillStyle(0);
	rat_obs_1[iv]->SetFillColor(0);
	rat_obs_1[iv]->SetMarkerStyle(kFullCircle);
	rat_obs_1[iv]->SetMarkerColor(kBlack);
	rat_obs_1[iv]->SetMarkerSize(0.7);
	rat_obs_1[iv]->SetLineColor(kBlack);
	
	rat_obs_1[iv]->Draw("e,p");

	TLine *line_1 = new TLine(rat_obs_1[iv]->GetBinLowEdge(1),1.,rat_obs_1[iv]->GetBinLowEdge(rat_obs_1[iv]->GetNbinsX()),1.);
	line_1->SetLineColor(7);
	line_1->Draw("sames");
	
	#ifdef Matching
	sprintf(name,"Data_MC/EJets_JetHT/%s_match.pdf",cv_1[iv]->GetName());
	#elif defined(No_Matching)
	sprintf(name,"Data_MC/EJets_JetHT/%s_nomatch.pdf",cv_1[iv]->GetName());
	#else
	sprintf(name,"Data_MC/EJets_JetHT/%s.pdf",cv_1[iv]->GetName());
	#endif
	
	cv_1[iv]->SaveAs(name);
	
	
	// canv obs_2 //
	
	sprintf(name,"Canv_fail_%s",obsnames[iv]);
	hist_obs_2[iv][0]->SetMaximum(1.1 * max(hist_obs_2[iv][0]->GetMaximum(),hist_obs_2_bkg[iv]->GetMaximum()));
	cv_2[iv] = tdrDiCanvas(name,hist_obs_2[iv][0],hist_obs_2_bkg[iv],8,0);
	
	if(iv==3||iv==14){
		legv_2[iv] = tdrLeg(0.2,0.65,0.395,0.915);
	}else{
		legv_2[iv] = tdrLeg(0.65,0.65,0.875,0.915);
	}
	
	legv_2[iv]->SetTextFont(42);
	legv_2[iv]->SetTextSize(0.045);
	legv_2[iv]->SetBorderSize(0);

	for(int bkg=0; bkg<(nfiles); bkg++){ 
		if(bkg==0){ legv_2[iv]->AddEntry(hist_obs_2[iv][bkg],dataname[bkg],"ep"); }
		else{	
		legv_2[iv]->AddEntry(hist_obs_2[iv][bkg],dataname[bkg],"f");
			}
	}

	cv_2[iv]->cd(1);

	if(iv==0||iv==4||iv==5||iv==7||iv==9||iv==10||iv==12||iv==13||iv==17||iv==18||iv==19||iv==23||iv==24||iv==25||iv==26) 
	{ 
		gPad->SetLogy(1);
		hist_obs_2[iv][0]->SetMaximum(20*hist_obs_2[iv][0]->GetMaximum());
	}
	
	if(iv==15){
		hist_obs_2[iv][0]->SetMinimum(1.e-9);
	}

	hist_obs_2[iv][0]->SetFillStyle(0);
	hist_obs_2[iv][0]->SetFillColor(0);
	hist_obs_2[iv][0]->SetMarkerStyle(kFullCircle);
	hist_obs_2[iv][0]->SetMarkerColor(kBlack);
	hist_obs_2[iv][0]->SetMarkerSize(0.7);
	hist_obs_2[iv][0]->SetLineColor(kBlack);

	hist_obs_2[iv][0]->GetYaxis()->SetTitleOffset(1.5);

	hist_obs_2_stack[iv]->Draw("histSAME");
	hist_obs_2[iv][0]->Draw("PSAME");
	
	gPad->RedrawAxis();
	
	cv_2[iv]->cd(2);
	
//	rat_obs_2[iv] = (TH1D*)hist_obs_2_bkg[iv]->Clone();
//	rat_obs_2[iv]->Divide(hist_obs_2[iv][0]);
	rat_obs_2[iv] = (TH1D*)hist_obs_2[iv][0]->Clone();
	rat_obs_2[iv]->Divide(hist_obs_2_bkg[iv]);
	
	sprintf(name,"%s",obstitles[iv]);
	rat_obs_2[iv]->GetXaxis()->SetTitle(name);
	rat_obs_2[iv]->GetXaxis()->SetTitleSize(0.1);
	rat_obs_2[iv]->GetXaxis()->SetLabelSize(0.1);
	rat_obs_2[iv]->GetXaxis()->CenterTitle();
	
	rat_obs_2[iv]->GetYaxis()->SetTitle("Data / MC");
	rat_obs_2[iv]->GetYaxis()->SetTitleSize(0.1);
	rat_obs_2[iv]->GetYaxis()->SetLabelSize(0.1);
	rat_obs_2[iv]->GetYaxis()->SetTitleOffset(0.75);
	rat_obs_2[iv]->GetYaxis()->SetNdivisions(406);
	rat_obs_2[iv]->GetYaxis()->CenterTitle();
	
	rat_obs_2[iv]->SetMinimum(0);
	rat_obs_2[iv]->SetMaximum(2.);
	
	rat_obs_2[iv]->SetFillStyle(0);
	rat_obs_2[iv]->SetFillColor(0);
	rat_obs_2[iv]->SetMarkerStyle(kFullCircle);
	rat_obs_2[iv]->SetMarkerColor(kBlack);
	rat_obs_2[iv]->SetMarkerSize(0.7);
	rat_obs_2[iv]->SetLineColor(kBlack);
	
	rat_obs_2[iv]->Draw("e,p");

	TLine *line_2 = new TLine(rat_obs_2[iv]->GetBinLowEdge(1),1.,rat_obs_2[iv]->GetBinLowEdge(rat_obs_2[iv]->GetNbinsX()),1.);
	line_2->SetLineColor(7);
	line_2->Draw("sames");
	
	#ifdef Matching
	sprintf(name,"Data_MC/EJets_JetHT/%s_match.pdf",cv_2[iv]->GetName());
	#elif defined(No_Matching)
	sprintf(name,"Data_MC/EJets_JetHT/%s_nomatch.pdf",cv_2[iv]->GetName());
	#else
	sprintf(name,"Data_MC/EJets_JetHT/%s.pdf",cv_2[iv]->GetName());
	#endif
	
	cv_2[iv]->SaveAs(name);
	
   }
  }
  
}

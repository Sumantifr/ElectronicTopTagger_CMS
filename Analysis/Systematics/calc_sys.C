//#include "/home/suman/CPlusPlus/CMS_Files/Jets_in_CMS/Plot_Maker/My_Style_Suman.C"
#include "TFile.h"
#include "TH1D.h"
#include <fstream>
#include <iostream>
#include <TLatex.h>
#include <TLegend.h>
#include <TCanvas.h>

#define Rebin_Mtb
//#define PDF_Hessian

#define Signal

#define YEAR_2017

using namespace std;

void output_err(double b0, double berr, double b1, double b2, double* c1, double* c2){
	// b0: nominal yield, berr: stat error on nominal yield, b1 and b2: yield with systmatic source vaired upward and downward respectively, c1 and c2: output up and down unc

	double a1,a2;

	a1 = (b1-b0)*1./b0;
	a2 = (b2-b0)*1./b0;

	berr = 0.1*berr*1./b0;
	
	if(a1*a2<0){
		if(a1>0){
			a1 = a1;
			a2 = abs(a2);			
		}else{
			a1 = a2;
			a2 = abs(a1);
		}
	}else{
		if(a1*a2>0) {
			if(a1>0){
				a1 = max(a1,a2);
				a2 = 0;
			}
			else{
				a1 = 0;
				a2 = abs(min(a1,a2));	
			}
		}
	}

	a1 = abs(a1);
	a2 = abs(a2);

	//if(a1<berr){ a1 = 0; }
	//if(a2<berr){ a2 = 0; }
	a1 = sqrt(a1*a1-berr*berr);
	a2 = sqrt(a2*a2-berr*berr);

	if(abs(a1)>1) { a1 = 1; }
	if(abs(a2)>1) { a2 = 1; }
	if(!(a1>=0)) { a1 = 0; }
	if(!(a2>=0)) { a2 = 0; }
	//if(isnan(a1)) { a1 = 0; }
	//if(isnan(a2)) { a2 = 0; }

	//cout<<a1<<" "<<a2<<endl;
	*c1 = a1;
	*c2 = a2;
}


void calc_sys(TH1D *hist, TFile *filein, TFile *fileout)
{
	static const int npdfmax = 33;
	static const int nscalemax = 9;

	static const int nbinmax = 60;

	double sys_JESup[nbinmax]={0};
	double sys_JESdn[nbinmax]={0};

	double sys_JERup[nbinmax]={0};
	double sys_JERdn[nbinmax]={0};

	double sys_PUup[nbinmax]={0};
	double sys_PUdn[nbinmax]={0};

	char name[1000];

	TH1D *hist_jes_up;
	sprintf(name,"%s_JESup",hist->GetName());
	hist_jes_up = (TH1D*)filein->Get(name);
	
	TH1D *hist_jes_dn;
	sprintf(name,"%s_JESdn",hist->GetName());
	hist_jes_dn = (TH1D*)filein->Get(name);
		
	TH1D *hist_jer_up;
	sprintf(name,"%s_JERup",hist->GetName());
	hist_jer_up = (TH1D*)filein->Get(name);
	
	TH1D *hist_jer_dn;	
	sprintf(name,"%s_JERdn",hist->GetName());
	hist_jer_dn = (TH1D*)filein->Get(name);
		
	TH1D *hist_pu_up;	
	sprintf(name,"%s_PUup",hist->GetName());
	hist_pu_up = (TH1D*)filein->Get(name);
	
	TH1D *hist_pu_dn;	
	sprintf(name,"%s_PUdn",hist->GetName());
	hist_pu_dn = (TH1D*)filein->Get(name);
	
	for(int bn=0; bn<(hist->GetNbinsX()); bn++){ 

		output_err(hist->GetBinContent(bn+1),0.1*hist->GetBinError(bn+1),hist_jes_up->GetBinContent(bn+1),hist_jes_dn->GetBinContent(bn+1),&sys_JESup[bn],&sys_JESdn[bn]);
					
		sys_JESup[bn] = abs(sys_JESup[bn]);
		sys_JESdn[bn] = -1.*abs(sys_JESdn[bn]);
		
		output_err(hist->GetBinContent(bn+1),0.1*hist->GetBinError(bn+1),hist_jer_up->GetBinContent(bn+1),hist_jer_dn->GetBinContent(bn+1),&sys_JERup[bn],&sys_JERdn[bn]);
					
		sys_JERup[bn] = abs(sys_JERup[bn]);
		sys_JERdn[bn] = -1.*abs(sys_JERdn[bn]);
			
		output_err(hist->GetBinContent(bn+1),0.1*hist->GetBinError(bn+1),hist_pu_up->GetBinContent(bn+1),hist_pu_dn->GetBinContent(bn+1),&sys_PUup[bn],&sys_PUdn[bn]);
					
		sys_PUup[bn] = abs(sys_PUup[bn]);
		sys_PUdn[bn] = -1.*abs(sys_PUdn[bn]);
					
		}


	TH1D *h_JES_unc_up;
	TH1D *h_JES_unc_dn;

	TH1D *h_JER_unc_up;
	TH1D *h_JER_unc_dn;

	TH1D *h_pu_unc_up;
	TH1D *h_pu_unc_dn;

	TH1D *h_total_unc_up;
	TH1D *h_total_unc_dn;

	
	h_JES_unc_up = (TH1D*)hist->Clone();
	sprintf(name,"JES_Unc_up_%s",hist->GetName());
	h_JES_unc_up->SetName(name);
	
	h_JES_unc_dn = (TH1D*)hist->Clone();
	sprintf(name,"JES_Unc_dn_%s",hist->GetName());
	h_JES_unc_dn->SetName(name);
	
	h_JER_unc_up = (TH1D*)hist->Clone();
	sprintf(name,"JER_Unc_up_%s",hist->GetName());
	h_JER_unc_up->SetName(name);
	
	h_JER_unc_dn = (TH1D*)hist->Clone();
	sprintf(name,"JER_Unc_dn_%s",hist->GetName());
	h_JER_unc_dn->SetName(name);
	
	h_pu_unc_up = (TH1D*)hist->Clone();
	sprintf(name,"PU_Unc_up_%s",hist->GetName());
	h_pu_unc_up->SetName(name);
	
	h_pu_unc_dn = (TH1D*)hist->Clone();
	sprintf(name,"PU_Unc_dn_%s",hist->GetName());
	h_pu_unc_dn->SetName(name);
	
	
	for(int bn=0; bn<(hist->GetNbinsX()); bn++){
		
		h_JES_unc_up->SetBinContent(bn+1,100.*sys_JESup[bn]);
		h_JES_unc_dn->SetBinContent(bn+1,100.*sys_JESdn[bn]);
		h_JER_unc_up->SetBinContent(bn+1,100.*sys_JERup[bn]);
		h_JER_unc_dn->SetBinContent(bn+1,100.*sys_JERdn[bn]);
		h_pu_unc_up->SetBinContent(bn+1,100.*sys_PUup[bn]);
		h_pu_unc_dn->SetBinContent(bn+1,100.*sys_PUdn[bn]);
		
		h_JES_unc_up->SetBinError(bn+1,0);
		h_JES_unc_dn->SetBinError(bn+1,0);
		h_JER_unc_up->SetBinError(bn+1,0);
		h_JER_unc_dn->SetBinError(bn+1,0);
		h_pu_unc_up->SetBinError(bn+1,0);
		h_pu_unc_dn->SetBinError(bn+1,0);
	}
	
	
	// add all systematics //
	
	h_total_unc_up = (TH1D*)hist->Clone();	
	sprintf(name,"Total_Unc_up_%s",hist->GetName());
	h_total_unc_up->SetName(name);
		
	h_total_unc_dn = (TH1D*)hist->Clone();	
	sprintf(name,"Total_Unc_dn_%s",hist->GetName());
	h_total_unc_dn->SetName(name);
		
	h_JES_unc_up->Smooth(); h_JES_unc_dn->Smooth();
	h_JER_unc_up->Smooth(); h_JER_unc_dn->Smooth();
	h_pu_unc_up->Smooth(); h_pu_unc_dn->Smooth();
		
	for(int bn=0; bn<(hist->GetNbinsX()); bn++){
			
		double up_sys = 0;
			
		up_sys = (
		 pow(h_JES_unc_up->GetBinContent(bn+1),2) +
		 pow(h_JER_unc_up->GetBinContent(bn+1),2) +
		 pow(h_pu_unc_up->GetBinContent(bn+1),2) 
		);
			 
		up_sys = sqrt(up_sys);
			 
		double dn_sys = 0;
			
		dn_sys = (
		 pow(h_JES_unc_dn->GetBinContent(bn+1),2) +
		 pow(h_JER_unc_dn->GetBinContent(bn+1),2) +
		 pow(h_pu_unc_dn->GetBinContent(bn+1),2) 
		);
			 
		dn_sys = -1.*sqrt(dn_sys);
			
		h_total_unc_up->SetBinContent(bn+1,up_sys);
		h_total_unc_up->SetBinError(bn+1,0);
			
		h_total_unc_dn->SetBinContent(bn+1,dn_sys);
		h_total_unc_dn->SetBinError(bn+1,0);
	}
		
	// Theory systematics //	
		
	double sys_PDF_up_fac[npdfmax][nbinmax]={{0}};
	double sys_PDF_dn_fac[npdfmax][nbinmax]={{0}};

	double sys_scale_up_fac[nscalemax][nbinmax]={{0}};
	double sys_scale_dn_fac[nscalemax][nbinmax]={{0}};

	double sys_PDF_up[nbinmax]={0};
	double sys_PDF_dn[nbinmax]={0};

	double sys_scale_up[nbinmax]={0};
	double sys_scale_dn[nbinmax]={0};

	double sys_tot_up[nbinmax]={0};
	double sys_tot_dn[nbinmax]={0};

	TH1D *hist_PDF[npdfmax];
	TH1D *hist_scale[nscalemax];

	 for(int ipdf=0; ipdf<npdfmax; ipdf++){
	   sprintf(name,"%s_PDF%i",hist->GetName(),ipdf+1);
	   hist_PDF[ipdf] = (TH1D*)filein->Get(name);
	   hist_PDF[ipdf]->Scale(1./hist_PDF[ipdf]->Integral());
		}
	
	 for(int iscale=0; iscale<nscalemax; iscale++){
	   sprintf(name,"%s_scale%i",hist->GetName(),iscale+1);
	   hist_scale[iscale] = (TH1D*)filein->Get(name);
	
	   hist_scale[iscale]->Scale(1./hist_scale[iscale]->Integral());
		}	
	
	 hist->Scale(1./hist->Integral());
	
	for(int bn=0; bn<(hist->GetNbinsX()); bn++){
			
		#ifdef PDF_Hessian
				
		for(int ipdf=0; ipdf<npdfmax; ipdf++){	
				
			sys_PDF_up_fac[ipdf][bn] = (hist_PDF[ipdf]->GetBinContent(bn+1) - hist->GetBinContent(bn+1))*1./hist->GetBinContent(bn+1);
				
			if(abs(sys_PDF_up_fac[ipdf][bn])>1) { sys_PDF_up_fac[ipdf][bn] = 0; }
			if(!(sys_PDF_up_fac[ipdf][bn]>=0)) { sys_PDF_up_fac[ipdf][bn] = 0; }
					
			sys_PDF_dn_fac[ipdf][bn] = sys_PDF_up_fac[ipdf][bn];
			
		}

#else

		double sum_sq = 0; double sum_mu = 0;
				
		for(int ipdf=0; ipdf<npdfmax; ipdf++){
			sum_sq += hist_PDF[ipdf]->GetBinContent(bn+1)*hist_PDF[ipdf]->GetBinContent(bn+1);
			sum_mu += hist_PDF[ipdf]->GetBinContent(bn+1);
		}
		
		sum_sq *= 1./npdfmax;
		sum_mu *= 1./npdfmax;
				
		double pdf_err = sqrt(sum_sq - sum_mu*sum_mu)*1./hist->GetBinContent(bn+1);
				
		sys_PDF_up[bn] = pdf_err;
		sys_PDF_dn[bn] = pdf_err;
					
		if(abs(sys_PDF_up[bn])>1) { sys_PDF_up[bn] = 1; }
		if(abs(sys_PDF_dn[bn])>1) { sys_PDF_dn[bn] = 1; }
		if(!(sys_PDF_dn[bn]>=0)) { sys_PDF_dn[bn] = 0; }
		if(!(sys_PDF_up[bn]>=0)) { sys_PDF_up[bn] = 0; }
#endif				
			}


		for(int bn=0; bn<(hist->GetNbinsX()); bn++){
			for(int iscale=0; iscale<nscalemax; iscale++){	
				if(iscale==0||iscale==(nscalemax-1)) continue;
				if(hist_scale[iscale]->GetBinContent(bn+1) > hist_scale[4]->GetBinContent(bn+1)){
					sys_scale_up_fac[iscale][bn] = (hist_scale[iscale]->GetBinContent(bn+1) - hist_scale[4]->GetBinContent(bn+1))*1./hist_scale[4]->GetBinContent(bn+1);
					sys_scale_dn_fac[iscale][bn] = 0;
					}
					else{
						sys_scale_up_fac[iscale][bn] = 0;
						sys_scale_dn_fac[iscale][bn] = fabs((hist_scale[iscale]->GetBinContent(bn+1) - hist_scale[4]->GetBinContent(bn+1))*1./hist_scale[4]->GetBinContent(bn+1));			
						}

				if(abs(sys_scale_up_fac[iscale][bn])>1) { sys_scale_up_fac[iscale][bn] = 1; }
				if(abs(sys_scale_dn_fac[iscale][bn])>1) { sys_scale_dn_fac[iscale][bn] = 1; }
				if(!(sys_scale_up_fac[iscale][bn]>=0)) { sys_scale_up_fac[iscale][bn] = 0; }
				if(!(sys_scale_dn_fac[iscale][bn]>=0)) { sys_scale_dn_fac[iscale][bn] = 0; }
			
			}

		}
	
	
	for(int bn=0; bn<(hist->GetNbinsX()); bn++){
		
		for(int iscale=0; iscale<nscalemax; iscale++){
			sys_scale_up[bn] += pow(sys_scale_up_fac[iscale][bn],2);
			sys_scale_dn[bn] += pow(sys_scale_dn_fac[iscale][bn],2);	
		}
	
		#ifdef PDF_Hessian

		for(int ipdf=0; ipdf<npdfmax; ipdf++){
			
			#ifdef PDF_Hessian_Maxvar
			if(sys_PDF_up[bn] < (sys_PDF_up_fac[ipdf][bn]*sys_PDF_up_fac[ipdf][bn])) { sys_PDF_up[bn] = sys_PDF_up_fac[ipdf][bn]*sys_PDF_up_fac[ipdf][bn]; }
			if(sys_PDF_dn[bn] < (sys_PDF_dn_fac[ipdf][bn]*sys_PDF_dn_fac[ipdf][bn])) { sys_PDF_dn[bn] = sys_PDF_dn_fac[ipdf][bn]*sys_PDF_dn_fac[ipdf][bn]; }
			#else
			sys_PDF_up[bn] += pow(sys_PDF_up_fac[ipdf][bn],2);
			sys_PDF_dn[bn] += pow(sys_PDF_dn_fac[ipdf][bn],2);
			#endif
			
		}
			sys_tot_up[bn] +=  sys_PDF_up[bn];//*sys_PDF_up[it][ib][isb][bn];
			sys_tot_dn[bn] +=  sys_PDF_dn[bn];//*sys_PDF_dn[it][ib][isb][bn];
			
			sys_PDF_up[bn] = sqrt(sys_PDF_up[bn]);
			sys_PDF_dnbn] = sqrt(sys_PDF_dn[bn]);

		#else

			sys_tot_up[bn] +=  sys_PDF_up[bn]*sys_PDF_up[bn];
			sys_tot_dn[bn] +=  sys_PDF_dn[bn]*sys_PDF_dn[bn];
	
		#endif

			sys_tot_up[bn] +=  sys_scale_up[bn];
			sys_tot_dn[bn] +=  sys_scale_dn[bn];

			sys_scale_up[bn] = sqrt(sys_scale_up[bn]);
			sys_scale_dn[bn] = sqrt(sys_scale_dn[bn]);
			
			sys_tot_up[bn] = sqrt(sys_tot_up[bn]);
			sys_tot_dn[bn] = sqrt(sys_tot_dn[bn]);
	
			if(!(sys_tot_dn[bn]>=0)) { sys_tot_dn[bn] = 0; }
			if(!(sys_tot_up[bn]>=0)) { sys_tot_up[bn] = 0; }
			

	}

	TH1D *h_scale_unc_up;
	TH1D *h_pdf_unc_up;
	TH1D *h_theory_unc_up;

	TH1D *h_scale_unc_dn;
	TH1D *h_pdf_unc_dn;
	TH1D *h_theory_unc_dn;

	h_scale_unc_up = (TH1D*)hist->Clone();
	sprintf(name,"Scale_Unc_up_%s",hist->GetName());
	h_scale_unc_up->SetName(name);

	h_scale_unc_dn = (TH1D*)hist->Clone();
	sprintf(name,"Scale_Unc_dn_%s",hist->GetName());
	h_scale_unc_dn->SetName(name);
	
	h_pdf_unc_up = (TH1D*)hist->Clone();
	sprintf(name,"PDF_Unc_up_%s",hist->GetName());
	h_pdf_unc_up->SetName(name);
	
	h_pdf_unc_dn = (TH1D*)hist->Clone();
	sprintf(name,"PDF_Unc_dn_%s",hist->GetName());
	h_pdf_unc_dn->SetName(name);
	
	h_theory_unc_up = (TH1D*)hist->Clone();
	sprintf(name,"Theory_Unc_up_%s",hist->GetName());
	h_theory_unc_up->SetName(name);
	
	h_theory_unc_dn = (TH1D*)hist->Clone();
	sprintf(name,"Theory_Unc_dn_%s",hist->GetName());
	h_theory_unc_dn->SetName(name);
			
	for(int bn=0; bn<(hist->GetNbinsX()); bn++){
	
		h_scale_unc_up->SetBinContent(bn+1,100.*sys_scale_up[bn]);
		h_scale_unc_dn->SetBinContent(bn+1,100.*sys_scale_dn[bn]);
		h_pdf_unc_up->SetBinContent(bn+1,100.*sys_PDF_up[bn]);
		h_pdf_unc_dn->SetBinContent(bn+1,100.*sys_PDF_dn[bn]);
		h_theory_unc_up->SetBinContent(bn+1,100.*sys_tot_up[bn]);
		h_theory_unc_dn->SetBinContent(bn+1,100.*sys_tot_up[bn]);
		h_theory_unc_dn->SetBinError(bn+1,0);
		
		h_scale_unc_up->SetBinError(bn+1,0);
		h_scale_unc_dn->SetBinError(bn+1,0);
		h_pdf_unc_up->SetBinError(bn+1,0);
		h_pdf_unc_dn->SetBinError(bn+1,0);
		h_theory_unc_up->SetBinError(bn+1,0);
	}
			
		


/*
TFile *fileout;
#ifdef YEAR_2016
sprintf(name,"Sig_uncertainty_2016_Wp_LH_CompHEP_2016_M%i.root",input_mass);
#endif
#ifdef YEAR_2017
sprintf(name,"Sig_uncertainty_2017_Wp_LH_CompHEP_2017_M%i.root",input_mass);
#endif
#ifdef YEAR_2018
sprintf(name,"Sig_uncertainty_2018_Wp_LH_CompHEP_2018_M%i.root",input_mass);
#endif
fileout = new TFile(name,"RECREATE");
*/

	fileout->cd();

	h_JES_unc_up->Scale(1./100);		h_JES_unc_dn->Scale(1./100);
	h_JER_unc_up->Scale(1./100);		h_JER_unc_dn->Scale(1./100);
	h_pu_unc_up->Scale(1./100);		h_pu_unc_dn->Scale(1./100);
	h_total_unc_up->Scale(1./100);		h_total_unc_dn->Scale(1./100);
		
	h_pdf_unc_up->Scale(1./100);		h_pdf_unc_dn->Scale(1./100);
	h_scale_unc_up->Scale(1./100);		h_scale_unc_dn->Scale(1./100);
		
	h_JES_unc_up->Write();
	h_JER_unc_up->Write();
	h_pu_unc_up->Write();
	h_total_unc_up->Write();
	h_pdf_unc_up->Write();
	h_scale_unc_up->Write();
		
	h_JES_unc_dn->Write();
	h_JER_unc_dn->Write();
	h_pu_unc_dn->Write();
	h_total_unc_dn->Write();
	h_pdf_unc_dn->Write();
	h_scale_unc_dn->Write();

	// end of calc_sys()
	
}

int main(int argc, char **argv)
{

TFile *filein;
char in_filename[1000], out_filename[1000];

sprintf(in_filename,"PROOF/Singlelep/Output_%s.root",(argv[1]));
filein = new TFile(in_filename,"read");

TH1D *hist = (TH1D*)filein->Get("Resolved_SR_VH_m_EFT1");

static const int nreg = 1;
const char *reg_names[nreg] = {"SR"};

#ifdef EFT_SIG
   static const int nEFTs = 13;
#else
	static const int nEFTs = 1;
#endif

static const int nphibins = 4;
static const int nthetabins = 4;

TH1D *hist_resolved_VH_m[nreg][nEFTs];
TH1D *hist_resolved_V_pt[nreg][nEFTs];
TH1D *hist_resolved_V_pt_phibins[nphibins][nreg][nEFTs];
TH1D *hist_resolved_VH_m_phibins[nphibins][nreg][nEFTs];
TH1D *hist_resolved_V_pt_thetabins[nthetabins][nreg][nEFTs];
TH1D *hist_resolved_VH_m_thetabins[nthetabins][nreg][nEFTs];
TH1D *hist_resolved_V_pt_Thetabins[nthetabins][nreg][nEFTs];
TH1D *hist_resolved_VH_m_Thetabins[nthetabins][nreg][nEFTs];

TH1D *hist_boosted_VH_m[nreg][nEFTs];
TH1D *hist_boosted_V_pt[nreg][nEFTs];
TH1D *hist_boosted_V_pt_phibins[nphibins][nreg][nEFTs];
TH1D *hist_boosted_VH_m_phibins[nphibins][nreg][nEFTs];
TH1D *hist_boosted_V_pt_thetabins[nphibins][nreg][nEFTs];
TH1D *hist_boosted_VH_m_thetabins[nthetabins][nreg][nEFTs];
TH1D *hist_boosted_V_pt_Thetabins[nthetabins][nreg][nEFTs];
TH1D *hist_boosted_VH_m_Thetabins[nthetabins][nreg][nEFTs];

char name[1000];

for(int ireg=0; ireg<nreg; ireg++){
	for(int ieft=0; ieft<nEFTs; ieft++){

		sprintf(name,"Resolved_%s_V_pt_EFT%i",reg_names[ireg],ieft+1);
		hist_resolved_V_pt[ireg][ieft] = (TH1D*)filein->Get(name);

		sprintf(name,"Resolved_%s_VH_m_EFT%i",reg_names[ireg],ieft+1);
		hist_resolved_VH_m[ireg][ieft] = (TH1D*)filein->Get(name);

		for(int iphi=0; iphi<nphibins; iphi++){

			sprintf(name,"Resolved_%s_V_pt_EFT%i_phibin%i",reg_names[ireg],ieft+1,iphi+1);
			hist_resolved_V_pt_phibins[iphi][ireg][ieft] = (TH1D*)filein->Get(name);

			sprintf(name,"Resolved_%s_VH_m_EFT%i_phibin%i",reg_names[ireg],ieft+1,iphi+1);
			hist_resolved_VH_m_phibins[iphi][ireg][ieft] = (TH1D*)filein->Get(name);
		
		}

		for(int itheta=0; itheta<nphibins; itheta++){

			sprintf(name,"Resolved_%s_V_pt_EFT%i_thetabin%i",reg_names[ireg],ieft+1,itheta+1);
			hist_resolved_V_pt_thetabins[itheta][ireg][ieft] = (TH1D*)filein->Get(name);

			sprintf(name,"Resolved_%s_VH_m_EFT%i_thetabin%i",reg_names[ireg],ieft+1,itheta+1);
			hist_resolved_VH_m_thetabins[itheta][ireg][ieft] = (TH1D*)filein->Get(name);

			sprintf(name,"Resolved_%s_V_pt_EFT%i_Thetabin%i",reg_names[ireg],ieft+1,itheta+1);
			hist_resolved_V_pt_Thetabins[itheta][ireg][ieft] = (TH1D*)filein->Get(name);

			sprintf(name,"Resolved_%s_VH_m_EFT%i_Thetabin%i",reg_names[ireg],ieft+1,itheta+1);
			hist_resolved_VH_m_Thetabins[itheta][ireg][ieft] = (TH1D*)filein->Get(name);

		}
		
		sprintf(name,"Boosted_%s_V_pt_EFT%i",reg_names[ireg],ieft+1);
		hist_boosted_V_pt[ireg][ieft] = (TH1D*)filein->Get(name);

		sprintf(name,"Boosted_%s_VH_m_EFT%i",reg_names[ireg],ieft+1);
		hist_boosted_VH_m[ireg][ieft] = (TH1D*)filein->Get(name);

		for(int iphi=0; iphi<nphibins; iphi++){

			sprintf(name,"Boosted_%s_V_pt_EFT%i_phibin%i",reg_names[ireg],ieft+1,iphi+1);
			hist_boosted_V_pt_phibins[iphi][ireg][ieft] = (TH1D*)filein->Get(name);

			sprintf(name,"Boosted_%s_VH_m_EFT%i_phibin%i",reg_names[ireg],ieft+1,iphi+1);
			hist_boosted_VH_m_phibins[iphi][ireg][ieft] = (TH1D*)filein->Get(name);
		
		}

		for(int itheta=0; itheta<nphibins; itheta++){

			sprintf(name,"Boosted_%s_V_pt_EFT%i_thetabin%i",reg_names[ireg],ieft+1,itheta+1);
			hist_boosted_V_pt_thetabins[itheta][ireg][ieft] = (TH1D*)filein->Get(name);

			sprintf(name,"Boosted_%s_VH_m_EFT%i_thetabin%i",reg_names[ireg],ieft+1,itheta+1);
			hist_boosted_VH_m_thetabins[itheta][ireg][ieft] = (TH1D*)filein->Get(name);

			sprintf(name,"Boosted_%s_V_pt_EFT%i_Thetabin%i",reg_names[ireg],ieft+1,itheta+1);
			hist_boosted_V_pt_Thetabins[itheta][ireg][ieft] = (TH1D*)filein->Get(name);

			sprintf(name,"Boosted_%s_VH_m_EFT%i_Thetabin%i",reg_names[ireg],ieft+1,itheta+1);
			hist_boosted_VH_m_Thetabins[itheta][ireg][ieft] = (TH1D*)filein->Get(name);

		}
		
	}
}

TFile *fileout;
sprintf(out_filename,"PROOF/Singlelep/Sys_%s.root",(argv[1]));
fileout = new TFile(out_filename,"RECREATE");

for(int ireg=0; ireg<nreg; ireg++){
	for(int ieft=0; ieft<nEFTs; ieft++){
		
		calc_sys(hist_resolved_V_pt[ireg][ieft],filein,fileout);
		calc_sys(hist_resolved_VH_m[ireg][ieft],filein,fileout);
		
		for(int iphi=0; iphi<nphibins; iphi++){
			calc_sys(hist_resolved_V_pt_phibins[iphi][ireg][ieft],filein,fileout);
			calc_sys(hist_resolved_VH_m_phibins[iphi][ireg][ieft],filein,fileout);
		}
		for(int itheta=0; itheta<nphibins; itheta++){
			calc_sys(hist_resolved_V_pt_thetabins[itheta][ireg][ieft],filein,fileout);
			calc_sys(hist_resolved_VH_m_thetabins[itheta][ireg][ieft],filein,fileout);
			calc_sys(hist_resolved_V_pt_Thetabins[itheta][ireg][ieft],filein,fileout);
			calc_sys(hist_resolved_VH_m_Thetabins[itheta][ireg][ieft],filein,fileout);
		}
		
		calc_sys(hist_boosted_V_pt[ireg][ieft],filein,fileout);
		calc_sys(hist_boosted_VH_m[ireg][ieft],filein,fileout);
		
		for(int iphi=0; iphi<nphibins; iphi++){
			calc_sys(hist_boosted_V_pt_phibins[iphi][ireg][ieft],filein,fileout);
			calc_sys(hist_boosted_VH_m_phibins[iphi][ireg][ieft],filein,fileout);
		}
		for(int itheta=0; itheta<nphibins; itheta++){
			calc_sys(hist_boosted_V_pt_thetabins[itheta][ireg][ieft],filein,fileout);
			calc_sys(hist_boosted_VH_m_thetabins[itheta][ireg][ieft],filein,fileout);
			calc_sys(hist_boosted_V_pt_Thetabins[itheta][ireg][ieft],filein,fileout);
			calc_sys(hist_boosted_VH_m_Thetabins[itheta][ireg][ieft],filein,fileout);
		}
		
	}
}

fileout->Write();
fileout->Close();
}

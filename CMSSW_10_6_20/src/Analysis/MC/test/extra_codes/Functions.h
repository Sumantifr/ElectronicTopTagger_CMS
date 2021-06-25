#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

#include <TH1D.h>
#include <TH2D.h>
#include <TH3D.h>
#include <TF1.h>
#include <math.h>
#include "TLorentzVector.h"
#include <TProofOutputFile.h>
#include <TProofServ.h>

#include <string>
#include <cmath>
#include <cassert>
#include <sstream>
#include <string>
#include "TFileCollection.h"
#include "THashList.h"
#include "TBenchmark.h"

#include <iostream>
#include <fstream>

#include "TSystem.h"

//#include "boost/config.hpp"
//#include "boost/lexical_cast.hpp"

#include "TMatrixDBase.h"
#include "TMatrixD.h"
#include "TVectorD.h"
#include "TDecompSVD.h"

#include <TRandom3.h>

#include <iostream>
#include <fstream>

int Sign(float xx)
{
if(xx<0) { return -1; }
else { return +1; }	
}

double getphi(TLorentzVector lep1, TLorentzVector lep2, TLorentzVector tmp_H)
{
	if(lep1.Eta()<-10 || lep2.Eta()<-10 || tmp_H.Eta()<-10) return -100;
	
	TLorentzVector beam;
	beam.SetPxPyPzE(0,0,6500,6500);
			
	TLorentzVector V_mom = lep1+lep2;
	TVector3 bVH = (lep1+lep2+tmp_H).BoostVector();
    
	lep1.Boost(-bVH);
	lep2.Boost(-bVH);
	V_mom.Boost(-bVH);
//	beam.Boost(-bVH);
	
	//TVector3 n_scatter = (V_mom.Vect().Cross(beam.Vect().Unit())).Unit();
	TVector3 n_scatter = (beam.Vect().Unit().Cross(V_mom.Vect())).Unit();
	TVector3 n_decay   = (lep1.Vect().Cross(lep2.Vect())).Unit();
	
	double phi;
	double sign_flip =  double(Sign((n_scatter.Cross(n_decay))*(V_mom.Vect())));
	phi = sign_flip*acos(n_scatter.Dot(n_decay));
	
	TVector3 Xi = (n_scatter).Cross(V_mom.Vect().Unit());
//  phi = atan2((lep1.Vect()).Dot(n_scatter),(lep1.Vect().Dot(Xi)));

	return phi;
}


double getTheta(TLorentzVector lep1, TLorentzVector lep2, TLorentzVector tmp_H)
{

   if(lep1.Eta()<-10 || lep2.Eta()<-10 || tmp_H.Eta()<-10) return -100;

   TLorentzVector beam;
   beam.SetPxPyPzE(0,0,6500,6500);
			
   TLorentzVector V_mom = lep1+lep2;
   TVector3 bVH = (lep1+lep2+tmp_H).BoostVector();

   V_mom.Boost(-bVH);
//   beam.Boost(-bVH);

   double Theta  = acos((V_mom.Vect().Unit()).Dot(beam.Vect().Unit()));

   return Theta;

}

double gettheta(TLorentzVector lep1, TLorentzVector lep2, TLorentzVector tmp_H)
{
if(lep1.Eta()<-10 || lep2.Eta()<-10) return -100;

TVector3 bVH = (lep1+lep2+tmp_H).BoostVector();

TLorentzVector V_mom = lep1+lep2;

V_mom.Boost(-bVH);
lep1.Boost(-bVH);

TVector3 bV = V_mom.BoostVector();
lep1.Boost(-bV);

double theta = (V_mom).Angle(lep1.Vect());
return theta;
}

int* decToBinary(int n)
{
	const int length = 15;
    static int binaryNum[length];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    int sum=0;
    
    return binaryNum;
    /*
    if(i>10) { i = 10; }
    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--) { sum += binaryNum[j]*pow(10,j); }
    return sum;
    */ 
} 

int getbinid(double val, int nbmx, float* array) {
  if (val<array[0]) return -2;
  for (int ix=0; ix<=nbmx; ix++) {
    if (val < array[ix]) return ix-1;
  }
  return -3;
}

int getbinid(double val, int nbmx, double* array) {
  if (val<array[0]) return -2;
  for (int ix=0; ix<=nbmx; ix++) {
    if (val < array[ix]) return ix-1;
  }
  return -3;
}

double theta_to_eta(double theta) { return -log(tan(theta/2.)); }

double eta_to_theta(double eta){
return(2*atan(exp(-2*eta)));
}

double PhiInRange(const double& phi) {
  double phiout = phi;

  if( phiout > 2*M_PI || phiout < -2*M_PI) {
    phiout = fmod( phiout, 2*M_PI);
  }
  if (phiout <= -M_PI) phiout += 2*M_PI;
  else if (phiout >  M_PI) phiout -= 2*M_PI;

  return phiout;
}

double delta2R(double eta1, double phi1, double eta2, double phi2) {
  return sqrt(pow(eta1 - eta2,2) +pow(PhiInRange(phi1 - phi2),2));
}

double delta2R_vec(TLorentzVector vec1, TLorentzVector vec2) {
  return sqrt(pow(vec1.Eta() - vec2.Eta(),2) +pow(PhiInRange(vec1.Phi() - vec2.Phi()),2));
}


double bmasscut_fun(double pt){
//return (0.5*pt-200);	
return 60;
} 

double EW_toppt_cor(double pt){
return (exp(-1.08872-(pt*0.011998)) + 0.895139);
}

Double_t pol4(Double_t* x, Double_t* par){
return (par[4]*pow(x[0],4)+par[3]*pow(x[0],3)+par[2]*pow(x[0],2)+par[1]*pow(x[0],1)+par[0]);
}

Double_t pol3(Double_t* x, Double_t* par){
return (par[3]*pow(x[0],3)+par[2]*pow(x[0],2)+par[1]*pow(x[0],1)+par[0]);
}

Double_t pol2(Double_t* x, Double_t* par){
return (par[2]*pow(x[0],2)+par[1]*pow(x[0],1)+par[0]);
}

Double_t pol1(Double_t* x, Double_t* par){
return (par[1]*pow(x[0],1)+par[0]);
}

double Pol0(double* x, double* par){
return (par[0]);
}

double Pol1(double* x, double* par){
return (par[0]+par[1]*x[0]);
}

double MikkoFunc1(double *x, double *par){
return (par[3]+par[0]*pow(x[0],par[1])+par[2]*log(x[0])/x[0]);
}

double Parabol(double* x, double* par){
double xx = x[0]-par[0] ;
if(xx<0) {return(par[1]+(par[2]*pow(xx,2)));}
else { return(par[1]+(par[3]*pow(xx,2))) ; }
}

double BiFun(double* x, double* par){
double xx = x[0]-par[0] ;
if(xx<0) {return(par[1]+(par[2]*xx)+(par[3]*pow(xx,2)));}
else { return(par[1]+(par[2]*xx)+(par[4]*pow(xx,2))) ; }
}


double SF_TOP(double alpha, double beta, double pt0, double pt1)
{
	double sfwt = sqrt(exp(alpha-beta*pt0) * exp(alpha-beta*pt1));
	return sfwt;
}


float Calc_MT(const TLorentzVector t1, const TLorentzVector t2)
{

float mT2 = 0;

TLorentzVector vec1, vec2;
vec1 = t1;
vec2 = t2;

vec1.SetPz(0);
vec2.SetPz(0);

mT2 = (vec1+vec2).M();

return mT2;
	
}

TLorentzVector neutrino_mom(TLorentzVector vec_lep, float MET_pt, float MET_phi, double seed){

	float W_mass = 80.4;

	TLorentzVector pnu;
	
	if(vec_lep.E()<1.e-6) {pnu.SetPtEtaPhiM(0,-100,-100,0);}
	
	else{
	
		float mT2 = 2*vec_lep.Pt()*MET_pt*(1-cos(PhiInRange(vec_lep.Phi()-MET_phi)));
	
		float Delta2 = (W_mass*W_mass - mT2)*1./(2*MET_pt*vec_lep.Pt());
	
		if(Delta2>=0){
	
			float nueta;
			nueta = (seed>=0.5)?(vec_lep.Eta() + fabs(acosh(1+(Delta2)))):(vec_lep.Eta() - fabs(acosh(1+(Delta2))));
	
			pnu.SetPtEtaPhiM(MET_pt,nueta,MET_phi,0);
	
		}
		else{
			pnu.SetPtEtaPhiM(0,-100,-100,0);
			}
	}
	
	return pnu;
}


int NCR( int n, int k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int get_dof(int nvar, int order){

	int val = 1;
	val *= NCR(nvar+order,order+1);
	val *= (order+1);
	val = val/nvar;
	return val;
};


vector<int> PKL_Reader(int nvar, int ndof)
{

ifstream fp("/mnt/hephy/cms/suman.chatterjee/Higgs_EFT/AnalysisFW/CMSSW_10_2_9/src/PROOF/VH_reweight_card.txt");

string wcnames[11] = {"cpq3i","cpqMi","cpQ3","cpQM","cpu","cpd","cpW","cpWB","cpBB","cpDC","cdp"};

int sum=0;
vector<unsigned> pos;
for(int ij=0; ij<nvar; ij++){
        sum += wcnames[ij].length()+4;
        pos.push_back(sum);
}

vector <int> WCvalues;

string str;
int count = 0;
for(int ij=0; ij<1000; ij++) {
        fp>>str; 
        if(count>=ndof) break;
        if(ij%3==0){
                for (unsigned i=0; i<str.length(); ++i)
                {
                for(int ipos=0; ipos<nvar; ipos++){

                   if(i==pos[ipos]){
                           WCvalues.push_back((int)str[i]-48);
                   }

                }
        }
                count++;
        }
        if(fp.eof()) break;
   }

return WCvalues;

}

vector<double> SetRow(vector<double> & WCs)
{

vector <double> Arow;

Arow.push_back(1);

for(unsigned ivar=0; ivar<WCs.size(); ivar++){
	
	Arow.push_back(WCs[ivar]);
	
	for(unsigned jvar=ivar; jvar<WCs.size(); jvar++){
		
		Arow.push_back(WCs[ivar]*WCs[jvar]);
		
	}
}

return Arow;

}

TMatrix SetMatrix(int nvar, int ndof, vector<int> & WCvalues)
{
	
TMatrix Amat(ndof,ndof);
	
for(int idof=0; idof<ndof; idof++){
	
    vector <double> WCs(nvar);

	for(int ivar=0; ivar<nvar; ivar++){
		WCs[ivar] = (WCvalues[nvar*idof + ivar])*1.;
	}

	vector <double> Arow = SetRow(WCs); 
	// size of Arow should be ndof
	
	for(unsigned icol=0; icol<Arow.size(); icol++){ 
		Amat(idof,icol) = Arow[icol];
		}
	}	

return Amat;
	
}

//   0    1    2    3    4   5   6    7   8    9   10  
//cpq3i cpqM cpQ3 cpQM cpu cpd cpW cpWB cpBB cpDC cdp   

vector<double> Reweight_solver(int ndof, float *LHE_reweight, TMatrix Amat)
{
	
TVectorD WMC(ndof);

for(int idof=0; idof<ndof; idof++){
	
	WMC(idof) = LHE_reweight[idof];
	
	}
	
	TDecompSVD svd(Amat);
//	TDecompQRH svd(Amat);
//	TDecompLU svd(Amat);
    bool ok;
    const TVectorD pars = svd.Solve(WMC,ok);  
    
//    TVectorD sig = svd.GetSig(); sig.Sqr();  // Set of eigevalues
 
	vector<double> coeffs;
	
	for(int ivar=0; ivar<pars.GetNrows(); ivar++){
		coeffs.push_back(double(pars(ivar)));
	}
	
	return coeffs;
}

double GetWeightWC(double *WCval, int nvar, vector<double> & coeffs)
{

vector<double> WCs;

for(int ivar=0; ivar<nvar; ivar++){
	WCs.push_back(WCval[ivar]);
}

vector<double> Arow;
Arow = SetRow(WCs);


double wsum = 0;

for(unsigned ivar=0; ivar<Arow.size(); ivar++){
  wsum += Arow[ivar]*coeffs[ivar];
}

return wsum;

}

double check_fit(int nvar, vector<int> & WCvalues, vector<double> & coeffs, int ndof, float *LHE_reweight){

double chi2 = 0;
	
for(int idof=0; idof<ndof; idof++){
	
    double WCs[nvar];

	for(int ivar=0; ivar<nvar; ivar++){
		WCs[ivar] = (WCvalues[nvar*idof + ivar])*1.;
	}
	
	double wx = GetWeightWC(WCs, nvar, coeffs);
	
	chi2 += (wx-LHE_reweight[idof])*(wx-LHE_reweight[idof]);
 }

 return chi2;

}

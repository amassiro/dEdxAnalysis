#include "langaus.C"


void Draw(std::string nameFile) {
  
  TFile* fileIn = new TFile (nameFile.c_str(), "READ");
  
  TTree* tree = (TTree*) fileIn->Get("tree");
  
   
  TCanvas* mycc2 = new TCanvas ("mycc2", "", 800, 600);
  
  //   
  //   https://root.cern.ch/root/html/tutorials/fit/langaus.C.html
  //   
  //   
  //   //par[0]=Width (scale) parameter of Landau density
  //   //par[1]=Most Probable (MP, location) parameter of Landau density
  //   //par[2]=Total area (integral -inf to inf, normalization constant)
  //   //par[3]=Width (sigma) of convoluted Gaussian function
  //   
//   
//   
//   EXT PARAMETER                                   STEP         FIRST   
//   NO.   NAME      VALUE            ERROR          SIZE      DERIVATIVE 
//   1  p0           2.23944e-01   1.15281e-03   3.17857e-06   8.26056e-02
//   2  p1           2.41976e+00   1.44900e-03   4.77642e-06  -1.57049e-01
//   3  p2           1.04642e-01   2.01036e-04   7.70407e-07   5.29265e-01
//   4  p3           3.53386e-01   2.09308e-03   5.31332e-06   8.05870e-03
//   
  
  
  TF1 *function2 = new TF1("function2",langaufun, 1, 7, 4);
  
  function2->SetParameters(0.22, 2.42, 0.1, 0.35);
  function2->SetLineColor(kBlue);
  function2->SetLineStyle(2);
  function2->SetLineWidth(2);
  
  function2->Draw("PL");
  
  TCanvas* mycc = new TCanvas ("mycc", "", 800, 600);
  
  tree->Draw ("IsoTrack_dedxByHit1[best_track]", "(IsoTrack_layerOrSideByHit1[best_track] == 1) && (IsoTrack_ladderOrBladeByHit1[best_track] == 1) && (IsoTrack_pixByHit1[best_track] == 1 ) && ( (  abs(IsoTrack_eta[best_track] ) >=0.000000) && (  abs(IsoTrack_eta[best_track] ) <2.500000)   ) " );
  
  
  
  TCanvas* mycc3 = new TCanvas ("mycc3", "", 800, 600);


  tree->Draw ("langaus(IsoTrack_dedxByHit1[best_track])", "(IsoTrack_layerOrSideByHit1[best_track] == 1) && (IsoTrack_ladderOrBladeByHit1[best_track] == 1) && (IsoTrack_pixByHit1[best_track] == 1 ) && ( (  abs(IsoTrack_eta[best_track] ) >=0.000000) && (  abs(IsoTrack_eta[best_track] ) <2.500000)   ) " );
  
  
}



    
    
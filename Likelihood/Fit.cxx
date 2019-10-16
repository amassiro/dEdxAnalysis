
Double_t langaufun(Double_t *x, Double_t *par) {
  
  
  //Fit parameters:
  //par[0]=Width (scale) parameter of Landau density
  //par[1]=Most Probable (MP, location) parameter of Landau density
  //par[2]=Total area (integral -inf to inf, normalization constant)
  //par[3]=Width (sigma) of convoluted Gaussian function
  //
  //In the Landau distribution (represented by the CERNLIB approximation),
  //the maximum is located at x=-0.22278298 with the location parameter=0.
  //This shift is corrected within this function, so that the actual
  //maximum is identical to the MP parameter.
  
  // Numeric constants
  Double_t invsq2pi = 0.3989422804014;   // (2 pi)^(-1/2)
  Double_t mpshift  = -0.22278298;       // Landau maximum location
  
  // Control constants
  Double_t np = 100.0;      // number of convolution steps
  Double_t sc =   5.0;      // convolution extends to +-sc Gaussian sigmas
  
  // Variables
  Double_t xx;
  Double_t mpc;
  Double_t fland;
  Double_t sum = 0.0;
  Double_t xlow,xupp;
  Double_t step;
  Double_t i;
  
  
  // MP shift correction
  mpc = par[1] - mpshift * par[0];
  
  // Range of convolution integral
  xlow = x[0] - sc * par[3];
  xupp = x[0] + sc * par[3];
  
  step = (xupp-xlow) / np;
  
  // Convolution integral of Landau and Gaussian by sum
  for(i=1.0; i<=np/2; i++) {
    xx = xlow + (i-.5) * step;
    fland = TMath::Landau(xx,mpc,par[0]) / par[0];
    sum += fland * TMath::Gaus(x[0],xx,par[3]);
    
    xx = xupp - (i-.5) * step;
    fland = TMath::Landau(xx,mpc,par[0]) / par[0];
    sum += fland * TMath::Gaus(x[0],xx,par[3]);
  }
  
  return (par[2] * step * sum * invsq2pi / par[3]);
}

  
  
  
  

void Fit (std::string nameFile) {

  TFile* fileIn = new TFile (nameFile.c_str(), "READ");
  
  TCanvas* cc = (TCanvas*) fileIn->Get("summary");
  TH1F* histo_mc;
  
  
  TList* big_list = (TList*) cc->GetListOfPrimitives();
//   
//   big_list->Print();
//   
  
  TIter next(big_list);
  TObject* object = 0;
  while ((object = next())) {
    if (object->InheritsFrom(TH1F::Class())) {
      std::string name_histo = object->GetName();
      if (name_histo.find("_mc") != std::string::npos) {
        std::cout << " name_histo = " << name_histo << std::endl;
        histo_mc = (TH1F*) object->Clone();
      }
    } 
  }
  
  
//   TH1F* histo_mc = (TH1F*) cc->GetPrimitive("h_ilayer_2__iEdge_0__dedxById_BPIX_mc");
  
  TCanvas* mycc = new TCanvas ("mycc", "simple", 800, 600);
  
//   
//   Double_t      Landau(Double_t x, Double_t mpv = 0, Double_t sigma = 1, Bool_t norm = kFALSE)
//   
//   //    The LANDAU function.
//   mpv is a location parameter and correspond approximatly to the most probable value
//   and sigma is a scale parameter (not the sigma of the full distribution which is not defined)
//   Note that for mpv=0 and sigma=1 (default values) the exact location of the maximum of the distribution (most proble value) is at
//   x = -0.22278
//   This function has been adapted from the CERNLIB routine G110 denlan.
//   If norm=kTRUE (default is kFALSE) the result is divided by sigma
//   
//   
  
  TF1 *function = new TF1("function","[2] * TMath::Landau(x,[0],[1],0)",1,7);
//   TF1 *function = new TF1("function","[2] * TMath::Landau(x,[0],[1],0) + [4] * exp( - x / [3])",1,7);
    function->SetParameters(3.0, 0.3, 0.1);
//   function->SetParameters(3.0, 0.3, 0.1, 2.0, 0.02);
  function->SetLineColor(kBlue);
  function->SetLineStyle(2);
  function->SetLineWidth(2);
  
  histo_mc->Fit("function", "RM");
  
  histo_mc->DrawClone();
  function->Draw("PL same");
  
  
  
  
  
  TCanvas* mycc2 = new TCanvas ("mycc2", "langaus", 800, 600);
  
//   
//   https://root.cern.ch/root/html/tutorials/fit/langaus.C.html
//   
//   
//   //par[0]=Width (scale) parameter of Landau density
//   //par[1]=Most Probable (MP, location) parameter of Landau density
//   //par[2]=Total area (integral -inf to inf, normalization constant)
//   //par[3]=Width (sigma) of convoluted Gaussian function
//   
  
  TF1 *function2 = new TF1("function2",langaufun, 1, 7, 4);
  
  function2->SetParameters(0.3, 3.0, 1.0, 0.5);
  function2->SetLineColor(kBlue);
  function2->SetLineStyle(2);
  function2->SetLineWidth(2);
  
  histo_mc->Fit("function2", "RM");
  
  histo_mc->Draw();
  function2->Draw("PL same");
  
  
  
  
  
  
  
  
  
  
  
  
}




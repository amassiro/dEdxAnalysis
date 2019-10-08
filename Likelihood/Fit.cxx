

void Fit (std::string nameFile) {

  TFile* fileIn = new TFile (nameFile.c_str(), "READ");
  
  TCanvas* cc = (TCanvas*) fileIn->Get("summary");
  
  TH1F* histo_mc = (TH1F*) cc->GetPrimitive("h_ilayer_2__iEdge_0__dedxById_BPIX_mc");
  
  TCanvas* mycc = new TCanvas ("mycc", "", 800, 600);
  TF1 *function = new TF1("function","TMath::Landau(x,[0],[1],0)",0,6);
  function->SetParameters(3.0,0.2);
  function->Draw("PL");
  
  
  
}




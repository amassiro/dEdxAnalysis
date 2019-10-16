#include "langaus.C"


void DrawStrip(int numLayerStrip, std::string nameFile, std::string nameFileSig) {
  
  TFile* fileIn = new TFile (nameFile.c_str(), "READ");
  TTree* tree = (TTree*) fileIn->Get("tree");
  
  
  TFile* fileInSig = new TFile (nameFileSig.c_str(), "READ");
  TTree* treeSig = (TTree*) fileInSig->Get("tree");
  
  
  TCanvas* mycctest_mc = new TCanvas ("mycctest_mc", "", 800, 600);
  
  //   
  //   IsoTrack_pixByHit 
  //      0 = strips
  //      1 = bpix  
  //      2 = fpix
  //      
  //   IsoTrack_layerOrSideByHit
  //      1
  //      2
  //      3
  //      4
  //   
  
  TH1F* histo_dedx_bkg = new TH1F ("histo_dedx_bkg_mc", "", 80, 0, 10);
  TH1F* histo_dedx_sig = new TH1F ("histo_dedx_sig_mc", "", 80, 0, 10);
  
  TString toDraw;
  TString toCut;
  
  for (int ihit = 0; ihit < 4; ihit++) {

    toCut = Form (" (IsoTrack_pixByHit%d[0] == 0 ) && (IsoTrack_layerOrSideByHit%d[0] == %d)", ihit+1, ihit+1, numLayerStrip);
    
    toDraw = Form (" IsoTrack_dedxByHit%d[0] >>+ histo_dedx_bkg_mc   ", ihit+1);
    int num = tree->   Draw (toDraw.Data(), toCut.Data() );
    
    std::cout << " [" << ihit << "] -> bkg = " << num << std::endl;
    
    toDraw = Form (" IsoTrack_dedxByHit%d[0] >>+ histo_dedx_sig_mc   ", ihit+1);
    treeSig->Draw (toDraw.Data(), toCut.Data() );
    
  }
  
  
  histo_dedx_sig->SetLineColor(kRed);
  
  histo_dedx_bkg->GetXaxis()->SetTitle("dE/dx");
  histo_dedx_bkg->DrawNormalized();
  histo_dedx_sig->DrawNormalized("same");
  
  
  TString nameFileOut;
  nameFileOut = Form ("data/strips_%d.root", numLayerStrip);
  
  
  TCanvas* summary = new TCanvas ("summary", "", 800, 600);
  
  histo_dedx_bkg->DrawNormalized();
  summary->SaveAs(nameFileOut.Data());
  
  
  
}






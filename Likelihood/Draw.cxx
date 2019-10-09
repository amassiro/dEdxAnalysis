#include "langaus.C"


void Draw(std::string nameFile, std::string nameFileSig) {
  
  TFile* fileIn = new TFile (nameFile.c_str(), "READ");
  TTree* tree = (TTree*) fileIn->Get("tree");
  
  
  TFile* fileInSig = new TFile (nameFileSig.c_str(), "READ");
  TTree* treeSig = (TTree*) fileInSig->Get("tree");
  

  TCanvas* mycctest = new TCanvas ("mycctest", "", 800, 600);
  
//   
//   IsoTrack_pixByHit 
//      1 = bpix  
//      2 = fpix
//      
//   IsoTrack_layerOrSideByHit
//      1
//      2
//      3
//      4
//   
     
  tree->Draw ("IsoTrack_dedxByHit1[best_track]", "(IsoTrack_layerOrSideByHit1[best_track] == 1) && (IsoTrack_pixByHit1[best_track] == 1 ) " );
  
  
  TCanvas* mycc = new TCanvas ("mycc", "", 800, 600);
  
  
//   tree->Draw ("langausBPIXL1(Alt$(IsoTrack_dedxByHit1[0], -1)) * ( Alt$(IsoTrack_layerOrSideByHit1[0], -1) == 1 )", " (IsoTrack_pixByHit1 == 1 ) " );
  tree->Draw ("langausBPIXL1(Alt$(IsoTrack_dedxByHit1[0], -1))", " (IsoTrack_pixByHit1[0] == 1 ) && (IsoTrack_layerOrSideByHit1[0] == 1)" );
  
  
//   langausBPIXL1
//   langausBPIXL23
//   langausBPIXL4
//   langausFPIX
   
  TCanvas* mycc_prod = new TCanvas ("mycc_prod", "", 800, 600);
  
//   tree->Draw ("langausBPIXL1(Alt$(IsoTrack_dedxByHit1[0], -1))\
              *langausBPIXL1(Alt$(IsoTrack_dedxByHit2[0], -1))\
              *langausBPIXL1(Alt$(IsoTrack_dedxByHit3[0], -1))\
              *langausBPIXL1(Alt$(IsoTrack_dedxByHit4[0], -1))\
              ", " (IsoTrack_pixByHit1[0] == 1 ) && (IsoTrack_layerOrSideByHit1[0] == 1)" );
  
  TH1F* histo_bkg = new TH1F ("histo_bkg", "", 200, 0, 0.01);
  TH1F* histo_bkg_log = new TH1F ("histo_bkg_log", "", 200, 0, 100);
  
  TTreeReader treeReader("tree", fileIn);
  
  TTreeReaderArray<Float_t> IsoTrack_dedxByHit1(treeReader, "IsoTrack_dedxByHit1");
  TTreeReaderArray<Float_t> IsoTrack_dedxByHit2(treeReader, "IsoTrack_dedxByHit2");
  TTreeReaderArray<Float_t> IsoTrack_dedxByHit3(treeReader, "IsoTrack_dedxByHit3");
  TTreeReaderArray<Float_t> IsoTrack_dedxByHit4(treeReader, "IsoTrack_dedxByHit4");

  TTreeReaderArray<int> IsoTrack_layerOrSideByHit1(treeReader, "IsoTrack_layerOrSideByHit1");
  TTreeReaderArray<int> IsoTrack_layerOrSideByHit2(treeReader, "IsoTrack_layerOrSideByHit2");
  TTreeReaderArray<int> IsoTrack_layerOrSideByHit3(treeReader, "IsoTrack_layerOrSideByHit3");
  TTreeReaderArray<int> IsoTrack_layerOrSideByHit4(treeReader, "IsoTrack_layerOrSideByHit4");
  
  TTreeReaderArray<int> IsoTrack_pixByHit1(treeReader, "IsoTrack_pixByHit1");
  TTreeReaderArray<int> IsoTrack_pixByHit2(treeReader, "IsoTrack_pixByHit2");
  TTreeReaderArray<int> IsoTrack_pixByHit3(treeReader, "IsoTrack_pixByHit3");
  TTreeReaderArray<int> IsoTrack_pixByHit4(treeReader, "IsoTrack_pixByHit4");


  
//   int nevents = tree->GetEntries();
//   for (int ievent = 0; ievent < nevents; ievent++) {
//     tree->GetEntry(ievent);
    
  while (treeReader.Next()) {
    
    float product_likelihood = 1.;
    float sum_log_likelihood = 0.;
    
    float temp_product_likelihood;
    
    if ((IsoTrack_pixByHit1[0] == 1 ) && (IsoTrack_layerOrSideByHit1[0] == 1)) {
      temp_product_likelihood = langausBPIXL1( (IsoTrack_dedxByHit1[0]) );
    }
    else if ((IsoTrack_pixByHit1[0] == 1 ) && (IsoTrack_layerOrSideByHit1[0] == 2  ||  IsoTrack_layerOrSideByHit1[0] == 3)) {
      temp_product_likelihood = langausBPIXL23( (IsoTrack_dedxByHit1[0]) );
    }
    else if ((IsoTrack_pixByHit1[0] == 1 ) && (IsoTrack_layerOrSideByHit1[0] == 4)) {
      temp_product_likelihood = langausBPIXL4( (IsoTrack_dedxByHit1[0]) );
    }
    else if (IsoTrack_pixByHit1[0] == 2 ) {
      temp_product_likelihood = langausFPIX( (IsoTrack_dedxByHit1[0]) );
    }
    
    product_likelihood *= temp_product_likelihood;
    sum_log_likelihood -= log(temp_product_likelihood);
   
    //----------
    if ((IsoTrack_pixByHit1[1] == 1 ) && (IsoTrack_layerOrSideByHit1[1] == 1)) {
      temp_product_likelihood = langausBPIXL1( (IsoTrack_dedxByHit1[1]) );
    }
    else if ((IsoTrack_pixByHit1[1] == 1 ) && (IsoTrack_layerOrSideByHit1[1] == 2  ||  IsoTrack_layerOrSideByHit1[1] == 3)) {
      temp_product_likelihood = langausBPIXL23( (IsoTrack_dedxByHit1[1]) );
    }
    else if ((IsoTrack_pixByHit1[1] == 1 ) && (IsoTrack_layerOrSideByHit1[1] == 4)) {
      temp_product_likelihood = langausBPIXL4( (IsoTrack_dedxByHit1[1]) );
    }
    else if (IsoTrack_pixByHit1[1] == 2 ) {
      temp_product_likelihood = langausFPIX( (IsoTrack_dedxByHit1[1]) );
    }
    
    product_likelihood *= temp_product_likelihood;
    sum_log_likelihood -= log(temp_product_likelihood);
    
    //----------
    if ((IsoTrack_pixByHit1[2] == 1 ) && (IsoTrack_layerOrSideByHit1[2] == 1)) {
      temp_product_likelihood = langausBPIXL1( (IsoTrack_dedxByHit1[2]) );
    }
    else if ((IsoTrack_pixByHit1[2] == 1 ) && (IsoTrack_layerOrSideByHit1[2] == 2  ||  IsoTrack_layerOrSideByHit1[2] == 3)) {
      temp_product_likelihood = langausBPIXL23( (IsoTrack_dedxByHit1[2]) );
    }
    else if ((IsoTrack_pixByHit1[2] == 1 ) && (IsoTrack_layerOrSideByHit1[2] == 4)) {
      temp_product_likelihood = langausBPIXL4( (IsoTrack_dedxByHit1[2]) );
    }
    else if (IsoTrack_pixByHit1[2] == 2 ) {
      temp_product_likelihood = langausFPIX( (IsoTrack_dedxByHit1[2]) );
    }
    
    //----------
//     if ((IsoTrack_pixByHit1[3] == 1 ) && (IsoTrack_layerOrSideByHit1[3] == 1)) {
//       temp_product_likelihood = langausBPIXL1( (IsoTrack_dedxByHit1[3]) );
//     }
//     else if ((IsoTrack_pixByHit1[3] == 1 ) && (IsoTrack_layerOrSideByHit1[3] == 2  ||  IsoTrack_layerOrSideByHit1[3] == 3)) {
//       temp_product_likelihood = langausBPIXL23( (IsoTrack_dedxByHit1[3]) );
//     }
//     else if ((IsoTrack_pixByHit1[3] == 1 ) && (IsoTrack_layerOrSideByHit1[3] == 4)) {
//       temp_product_likelihood = langausBPIXL4( (IsoTrack_dedxByHit1[3]) );
//     }
//     else if (IsoTrack_pixByHit1[3] == 2 ) {
//       temp_product_likelihood = langausFPIX( (IsoTrack_dedxByHit1[3]) );
//     }
//     
//     product_likelihood *= temp_product_likelihood;
//     sum_log_likelihood -= log(temp_product_likelihood);
    
    
    
    //----------
    
    histo_bkg->Fill(product_likelihood);
    histo_bkg_log->Fill(sum_log_likelihood);
    
  }
  
  
   
  TH1F* histo_sig = new TH1F ("histo_sig", "", 200, 0, 0.01);
  TH1F* histo_sig_log = new TH1F ("histo_sig_log", "", 200, 0, 100);
  
  
  TTreeReader treeReaderSig("tree", fileInSig);
  
  TTreeReaderArray<Float_t> Sig_IsoTrack_dedxByHit1(treeReaderSig, "IsoTrack_dedxByHit1");
  TTreeReaderArray<Float_t> Sig_IsoTrack_dedxByHit2(treeReaderSig, "IsoTrack_dedxByHit2");
  TTreeReaderArray<Float_t> Sig_IsoTrack_dedxByHit3(treeReaderSig, "IsoTrack_dedxByHit3");
  TTreeReaderArray<Float_t> Sig_IsoTrack_dedxByHit4(treeReaderSig, "IsoTrack_dedxByHit4");
  
  TTreeReaderArray<int> Sig_IsoTrack_layerOrSideByHit1(treeReaderSig, "IsoTrack_layerOrSideByHit1");
  TTreeReaderArray<int> Sig_IsoTrack_layerOrSideByHit2(treeReaderSig, "IsoTrack_layerOrSideByHit2");
  TTreeReaderArray<int> Sig_IsoTrack_layerOrSideByHit3(treeReaderSig, "IsoTrack_layerOrSideByHit3");
  TTreeReaderArray<int> Sig_IsoTrack_layerOrSideByHit4(treeReaderSig, "IsoTrack_layerOrSideByHit4");
  
  TTreeReaderArray<int> Sig_IsoTrack_pixByHit1(treeReaderSig, "IsoTrack_pixByHit1");
  TTreeReaderArray<int> Sig_IsoTrack_pixByHit2(treeReaderSig, "IsoTrack_pixByHit2");
  TTreeReaderArray<int> Sig_IsoTrack_pixByHit3(treeReaderSig, "IsoTrack_pixByHit3");
  TTreeReaderArray<int> Sig_IsoTrack_pixByHit4(treeReaderSig, "IsoTrack_pixByHit4");
  
  
  
  //   int nevents = tree->GetEntries();
  //   for (int ievent = 0; ievent < nevents; ievent++) {
  //     tree->GetEntry(ievent);
  
  while (treeReaderSig.Next()) {
    
    float product_likelihood = 1.;
    float sum_log_likelihood = 0.;
    
    float temp_product_likelihood;
    
    if ((Sig_IsoTrack_pixByHit1[0] == 1 ) && (Sig_IsoTrack_layerOrSideByHit1[0] == 1)) {
      temp_product_likelihood = langausBPIXL1( (Sig_IsoTrack_dedxByHit1[0]) );
    }
    else if ((Sig_IsoTrack_pixByHit1[0] == 1 ) && (Sig_IsoTrack_layerOrSideByHit1[0] == 2  ||  Sig_IsoTrack_layerOrSideByHit1[0] == 3)) {
      temp_product_likelihood = langausBPIXL23( (Sig_IsoTrack_dedxByHit1[0]) );
    }
    else if ((Sig_IsoTrack_pixByHit1[0] == 1 ) && (Sig_IsoTrack_layerOrSideByHit1[0] == 4)) {
      temp_product_likelihood = langausBPIXL4( (Sig_IsoTrack_dedxByHit1[0]) );
    }
    else if (Sig_IsoTrack_pixByHit1[0] == 2 ) {
      temp_product_likelihood = langausFPIX( (Sig_IsoTrack_dedxByHit1[0]) );
    }
    
    product_likelihood *= temp_product_likelihood;
    sum_log_likelihood -= log(temp_product_likelihood);
    
    //----------
    if ((Sig_IsoTrack_pixByHit1[1] == 1 ) && (Sig_IsoTrack_layerOrSideByHit1[1] == 1)) {
      temp_product_likelihood = langausBPIXL1( (Sig_IsoTrack_dedxByHit1[1]) );
    }
    else if ((Sig_IsoTrack_pixByHit1[1] == 1 ) && (Sig_IsoTrack_layerOrSideByHit1[1] == 2  ||  Sig_IsoTrack_layerOrSideByHit1[1] == 3)) {
      temp_product_likelihood = langausBPIXL23( (Sig_IsoTrack_dedxByHit1[1]) );
    }
    else if ((Sig_IsoTrack_pixByHit1[1] == 1 ) && (Sig_IsoTrack_layerOrSideByHit1[1] == 4)) {
      temp_product_likelihood = langausBPIXL4( (Sig_IsoTrack_dedxByHit1[1]) );
    }
    else if (Sig_IsoTrack_pixByHit1[1] == 2 ) {
      temp_product_likelihood = langausFPIX( (Sig_IsoTrack_dedxByHit1[1]) );
    }
    
    product_likelihood *= temp_product_likelihood;
    sum_log_likelihood -= log(temp_product_likelihood);
    
    //----------
    if ((Sig_IsoTrack_pixByHit1[2] == 1 ) && (Sig_IsoTrack_layerOrSideByHit1[2] == 1)) {
      temp_product_likelihood = langausBPIXL1( (Sig_IsoTrack_dedxByHit1[2]) );
    }
    else if ((Sig_IsoTrack_pixByHit1[2] == 1 ) && (Sig_IsoTrack_layerOrSideByHit1[2] == 2  ||  Sig_IsoTrack_layerOrSideByHit1[2] == 3)) {
      temp_product_likelihood = langausBPIXL23( (Sig_IsoTrack_dedxByHit1[2]) );
    }
    else if ((Sig_IsoTrack_pixByHit1[2] == 1 ) && (Sig_IsoTrack_layerOrSideByHit1[2] == 4)) {
      temp_product_likelihood = langausBPIXL4( (Sig_IsoTrack_dedxByHit1[2]) );
    }
    else if (Sig_IsoTrack_pixByHit1[2] == 2 ) {
      temp_product_likelihood = langausFPIX( (Sig_IsoTrack_dedxByHit1[2]) );
    }
    
    //----------
    //     if ((Sig_IsoTrack_pixByHit1[3] == 1 ) && (Sig_IsoTrack_layerOrSideByHit1[3] == 1)) {
    //       temp_product_likelihood = langausBPIXL1( (Sig_IsoTrack_dedxByHit1[3]) );
    //     }
    //     else if ((Sig_IsoTrack_pixByHit1[3] == 1 ) && (Sig_IsoTrack_layerOrSideByHit1[3] == 2  ||  Sig_IsoTrack_layerOrSideByHit1[3] == 3)) {
    //       temp_product_likelihood = langausBPIXL23( (Sig_IsoTrack_dedxByHit1[3]) );
    //     }
    //     else if ((Sig_IsoTrack_pixByHit1[3] == 1 ) && (Sig_IsoTrack_layerOrSideByHit1[3] == 4)) {
    //       temp_product_likelihood = langausBPIXL4( (Sig_IsoTrack_dedxByHit1[3]) );
    //     }
    //     else if (Sig_IsoTrack_pixByHit1[3] == 2 ) {
    //       temp_product_likelihood = langausFPIX( (Sig_IsoTrack_dedxByHit1[3]) );
    //     }
    //     
    //     product_likelihood *= temp_product_likelihood;
    //     sum_log_likelihood -= log(temp_product_likelihood);
    
    
    
    //----------
    
    histo_sig->Fill(product_likelihood);
    histo_sig_log->Fill(sum_log_likelihood);
    
  }
  
  
  
  
  
  
  histo_sig->SetLineColor(kRed);
  histo_sig_log->SetLineColor(kRed);
  
  
  
  
  
  
  
  
  histo_bkg->DrawNormalized();
  histo_sig->DrawNormalized("same");
  
  TCanvas* mycc_prod_log = new TCanvas ("mycc_prod_log", "", 800, 600);
  histo_bkg_log->DrawNormalized();
  histo_sig_log->DrawNormalized("same");
  
}



    
    
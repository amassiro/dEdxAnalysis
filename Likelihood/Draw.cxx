#include "langaus.C"


void Draw(std::string nameFile) {
  
  TFile* fileIn = new TFile (nameFile.c_str(), "READ");
  
  TTree* tree = (TTree*) fileIn->Get("tree");
  
  
  
//   tree->Draw ("IsoTrack_dedxByHit1[best_track]", "(IsoTrack_layerOrSideByHit1[best_track] == 1) && (IsoTrack_ladderOrBladeByHit1[best_track] == 1) && (IsoTrack_pixByHit1[best_track] == 1 ) && ( (run >= 320673) && (run < 325173)  ) && ( (  abs(IsoTrack_eta[best_track] ) >=0.000000) && (  abs(IsoTrack_eta[best_track] ) <2.500000)   ) " )
  
  
}



    
    
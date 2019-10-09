#include "langaus.C"


void DrawValidation() {
  
  TCanvas* mycc_BPIX = new TCanvas ("mycc_BPIX", "", 800, 600);
  
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

//   
//   BPIX   eta ~ [0] 
//   
  
//   
//   Layer 1
//   
//   1  p0           2.36888e-01   1.79104e-03   1.08507e-06   3.84001e-01                    
//   2  p1           1.60308e+00   2.91762e-03   2.40632e-06   3.74515e-02
//   3  p2           1.04992e-01   2.65539e-04   2.19379e-07  -1.58903e+00
//   4  p3           5.54148e-01   5.47328e-03   2.95232e-06   9.70621e-02
//   
  
  
  
  TF1 *function_BPIX_layer_1 = new TF1("function_BPIX_layer_1",langaufun, 0, 7, 4);
  
  function_BPIX_layer_1->SetParameters(0.24, 1.60, 0.1, 0.55);
  function_BPIX_layer_1->SetLineColor(kBlue);
  function_BPIX_layer_1->SetLineStyle(2);
  function_BPIX_layer_1->SetLineWidth(2);
  
  function_BPIX_layer_1->Draw("PL");
  
  
  
//   
//   Layer 2
//   1  p0           2.23944e-01   1.15281e-03   3.17857e-06   8.26056e-02                    
//   2  p1           2.41976e+00   1.44900e-03   4.77642e-06  -1.57049e-01
//   3  p2           1.04642e-01   2.01036e-04   7.70407e-07   5.29265e-01
//   4  p3           3.53386e-01   2.09308e-03   5.31332e-06   8.05870e-03
//   
  
  
  TF1 *function_BPIX_layer_2 = new TF1("function_BPIX_layer_2",langaufun, 0, 7, 4);
  
  function_BPIX_layer_2->SetParameters(0.22, 2.42, 0.1, 0.35);
  function_BPIX_layer_2->SetLineColor(kBlue+1);
  function_BPIX_layer_2->SetLineStyle(2);
  function_BPIX_layer_2->SetLineWidth(2+1);
  
  function_BPIX_layer_2->Draw("PL same");
  
  
  
//   
//   Layer 3
//   
//   1  p0           2.19590e-01   1.05240e-03   2.95610e-06  -2.27250e-02                    
//   2  p1           2.48375e+00   1.29981e-03   8.83464e-07  -8.27157e-03
//   3  p2           1.04933e-01   1.96069e-04   7.67722e-07  -1.03642e-01
//   4  p3           3.14469e-01   1.90256e-03   9.77311e-07  -6.12515e-03
//   
  
  
  
  TF1 *function_BPIX_layer_3 = new TF1("function_BPIX_layer_3",langaufun, 0, 7, 4);
  
  function_BPIX_layer_3->SetParameters(0.22, 2.48, 0.1, 0.31);
  function_BPIX_layer_3->SetLineColor(kBlue+2);
  function_BPIX_layer_3->SetLineStyle(2);
  function_BPIX_layer_3->SetLineWidth(2+2);
  
  function_BPIX_layer_3->Draw("PL same");
  
  
//   
//   Layer 4
//   
//   1  p0           2.32386e-01   1.19067e-03   7.11369e-07   5.08209e-03
//   2  p1           2.71052e+00   1.45298e-03   5.28321e-06  -1.31741e-02
//   3  p2           1.05605e-01   2.12697e-04   8.93284e-07  -2.75761e-01
//   4  p3           3.20481e-01   2.17352e-03   1.17908e-06   4.20823e-03
  
  
  
  TF1 *function_BPIX_layer_4 = new TF1("function_BPIX_layer_4",langaufun, 0, 7, 4);
  
  function_BPIX_layer_4->SetParameters(0.23, 2.70, 0.1, 0.32);
  function_BPIX_layer_4->SetLineColor(kBlue+3);
  function_BPIX_layer_4->SetLineStyle(2);
  function_BPIX_layer_4->SetLineWidth(2+3);
  
  function_BPIX_layer_4->Draw("PL same");
  
  
  
  
  
  
  
  
  
  
  TF1 *function_BPIX = new TF1("function_BPIX",langaufun, 0, 7, 4);
  
  function_BPIX->SetParameters(0.25, 2.50, 0.1, 0.30);
  function_BPIX->SetLineColor(kOrange);
  function_BPIX->SetLineStyle(3);
  function_BPIX->SetLineWidth(8);
  
  function_BPIX->Draw("PL same");
  
  
  
  
  
  
  
  
  
  
  
  
  
  TCanvas* mycc_FPIX = new TCanvas ("mycc_FPIX", "", 800, 600);
  
//   
//   FPIX   eta ~ [1]
//   
  
//   Layer 1
//   
//   1  p0           2.20687e-01   1.58909e-03   3.07126e-06  -1.24968e-01
//   2  p1           2.49269e+00   2.00849e-03   4.66622e-06   1.02207e-01
//   3  p2           1.04979e-01   3.04033e-04   8.27821e-07   1.00350e+00
//   4  p3           3.00941e-01   2.90907e-03   5.05314e-06  -3.81676e-02
//   
  
  
  
  
  TF1 *function_FPIX_layer_1 = new TF1("function_FPIX_layer_1",langaufun, 0, 7, 4);
  
  function_FPIX_layer_1->SetParameters(0.22, 2.5, 0.1, 0.30);
  function_FPIX_layer_1->SetLineColor(kRed);
  function_FPIX_layer_1->SetLineStyle(2);
  function_FPIX_layer_1->SetLineWidth(2);
  
  function_FPIX_layer_1->Draw("PL");
  
  
  
//   Layer 2
//   
//   1  p0           2.24681e-01   2.54766e-03   3.22819e-06  -4.10858e-02
//   2  p1           2.49382e+00   3.18596e-03   4.88546e-06  -2.23736e-02
//   3  p2           1.05130e-01   4.88805e-04   8.69354e-07  -1.04810e-01
//   4  p3           2.94590e-01   4.62242e-03   5.28186e-06  -4.07248e-02
//   
  
  
  TF1 *function_FPIX_layer_2 = new TF1("function_FPIX_layer_2",langaufun, 0, 7, 4);
  
  function_FPIX_layer_2->SetParameters(0.25, 2.49, 0.1, 0.30);
  function_FPIX_layer_2->SetLineColor(kRed+1);
  function_FPIX_layer_2->SetLineStyle(2);
  function_FPIX_layer_2->SetLineWidth(2+1);
  
  function_FPIX_layer_2->Draw("PL same");
  
  
  
//   
//   Layer 3
//   
//   1  p0           2.28485e-01   6.96949e-03   5.94830e-06  -2.08462e-02
//   2  p1           2.47983e+00   9.13567e-03   9.26244e-06  -1.25826e-02
//   3  p2           1.03425e-01   1.34399e-03   1.62269e-06   7.96078e-02
//   4  p3           2.85649e-01   1.36961e-02   1.03178e-05  -2.34025e-03
//   
  
  
  
  TF1 *function_FPIX_layer_3 = new TF1("function_FPIX_layer_3",langaufun, 0, 7, 4);
  
  function_FPIX_layer_3->SetParameters(0.23, 2.48, 0.1, 0.29);
  function_FPIX_layer_3->SetLineColor(kRed+2);
  function_FPIX_layer_3->SetLineStyle(2);
  function_FPIX_layer_3->SetLineWidth(2+2);
  
  function_FPIX_layer_3->Draw("PL same");
  
  
  
  
  
  
  
  TF1 *function_FPIX = new TF1("function_FPIX",langaufun, 0, 7, 4);
  
  function_FPIX->SetParameters(0.24, 2.50, 0.1, 0.30);
  function_FPIX->SetLineColor(kOrange);
  function_FPIX->SetLineStyle(3);
  function_FPIX->SetLineWidth(8);
  
  function_FPIX->Draw("PL same");
  
  
  
  
  
  
 
}



    
    
Likelihood
====

Simple 1D likelihood approach

    cp ../../dEdxCalibration/Plotting/plots_summary_from_cmssw_2018data_RunA/cc_summary_layer_2_eta_0_BPIX.root .
    
    
Fit

    r99t Fit.cxx\(\"cc_summary_layer_2_eta_0_BPIX.root\"\)
    
Draw

    r99t Draw.cxx\(\"../../dEdxCalibration/Plotting/data_calibration/7Sep2019/Calibrated-MC-CR-2018-Hadded/DYJetsToLL_M50_HT100to200/treeProducerXtracks/tree.filtered.skimmed.root\"\)
    r99t Draw.cxx\(\"tree.filtered.skimmed.root\"\)

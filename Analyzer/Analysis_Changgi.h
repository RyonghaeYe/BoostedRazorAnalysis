#ifndef VER
#define VER 1
#endif

#include "TLorentzVector.h"
#include "TMath.h"
#include "common/AnalysisBase.h"

//_______________________________________________________
//                  Calculate variables

void
Analysis::calculate_variables(DataStruct& data, const unsigned int& syst_index)
{
}

  int mGluino[581] ={800,800,800,800,800,800,800,850,900,900,900,900,900,900,900,900,950,950,950,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1050,1050,1050,1050,1050,1100,1100,1100,1100,1100,1100,1100,1100,1100,1100,1100,1100,1150,1150,1150,1150,1150,1150,1150,1200,1200,1200,1200,1200,1200,1200,1200,1200,1200,1200,1200,1200,1200,1200,1200,1250,1250,1250,1250,1250,1250,1250,1250,1250,1250,1250,1250,1250,1250,1250,1250,1250,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1300,1350,1350,1350,1350,1350,1350,1350,1350,1350,1350,1350,1350,1350,1350,1350,1350,1350,1350,1350,1400,1400,1400,1400,1400,1400,1400,1400,1400,1400,1400,1400,1400,1400,1400,1400,1400,1400,1400,1400,1450,1450,1450,1450,1450,1450,1450,1450,1450,1450,1450,1450,1450,1450,1450,1450,1450,1450,1450,1450,1450,1500,1500,1500,1500,1500,1500,1500,1500,1500,1500,1500,1500,1500,1500,1500,1500,1500,1500,1500,1500,1500,1500,1550,1550,1550,1550,1550,1550,1550,1550,1550,1550,1550,1550,1550,1550,1550,1550,1550,1550,1550,1550,1550,1550,1550,1600,1600,1600,1600,1600,1600,1600,1600,1600,1600,1600,1600,1600,1600,1600,1600,1600,1600,1600,1600,1600,1600,1600,1600,1650,1650,1650,1650,1650,1650,1650,1650,1650,1650,1650,1650,1650,1650,1650,1650,1650,1650,1650,1650,1650,1650,1650,1650,1650,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1700,1750,1750,1750,1750,1750,1750,1750,1750,1750,1750,1750,1750,1750,1750,1750,1750,1750,1750,1750,1750,1750,1750,1750,1750,1750,1750,1800,1800,1800,1800,1800,1800,1800,1800,1800,1800,1800,1800,1800,1800,1800,1800,1800,1800,1800,1800,1800,1800,1800,1800,1800,1800,1850,1850,1850,1850,1850,1850,1850,1850,1850,1850,1850,1850,1850,1850,1850,1850,1850,1850,1850,1850,1850,1850,1850,1850,1850,1850,1850,1900,1900,1900,1900,1900,1900,1900,1900,1900,1900,1900,1900,1900,1900,1900,1900,1900,1900,1900,1900,1900,1900,1900,1900,1900,1900,1950,1950,1950,1950,1950,1950,1950,1950,1950,1950,1950,1950,1950,1950,1950,1950,1950,1950,1950,1950,1950,1950,1950,1950,1950,1950,2000,2000,2000,2000,2000,2000,2000,2000,2000,2000,2000,2000,2000,2000,2000,2000,2000,2000,2000,2000,2000,2000,2000,2000,2000,2050,2050,2050,2050,2050,2050,2050,2050,2050,2050,2050,2050,2050,2050,2050,2050,2050,2050,2050,2050,2050,2050,2050,2050,2050,2100,2100,2100,2100,2100,2100,2100,2100,2100,2100,2100,2100,2100,2100,2100,2100,2100,2100,2100,2100,2100,2100,2100,2100,2150,2150,2150,2150,2150,2150,2150,2150,2150,2150,2150,2150,2150,2150,2150,2150,2150,2150,2150,2150,2150,2150,2150,2150,2200,2200,2200,2200,2200,2200,2200,2200,2200,2200,2200,2200,2200,2200,2200,2200,2200,2200,2200,2200,2200,2200,2200,2250,2250,2250,2250,2250,2250,2250,2250,2250,2250,2250,2250,2250,2250,2250,2250,2250,2250,2250,2250,2250,2250,2250,2300,2300,2300,2300,2300,2300,2300,2300,2300,2300,2300,2300,2300,2300,2300,2300,2300,2300,2300,2300,2300,2300};           

  int mLSP[581] = {0,100,200,300,400,500,525,
                   575,
                   0,100,200,300,400,500,600,625,
                   600,650,675,
                   0,100,200,300,400,500,600,650,700,725,
                   600,650,700,750,775,
                   0,100,200,300,400,500,600,650,700,750,800,825,
                   600,650,700,750,800,850,875,
                   0,50,100,150,200,300,400,500,600,650,700,750,800,850,900,925,
                   0,50,100,150,200,300,400,500,600,650,700,750,800,850,900,950,975,
                   0,50,100,150,200,300,400,500,600,650,700,750,800,850,900,950,1000,1025,    
                   0,50,100,150,200,300,400,500,600,650,700,750,800,850,900,950,1000,1050,1075,
                   0,50,100,150,200,300,400,500,600,650,700,750,800,850,900,950,1000,1050,1100,1125,
                   0,50,100,150,200,300,400,500,600,650,700,750,800,850,900,950,1000,1050,1100,1150,1175,
                   0,50,100,150,200,300,400,500,600,650,700,750,800,850,900,950,1000,1050,1100,1150,1200,1225,
                   0,50,100,150,200,300,400,500,600,650,700,750,800,850,900,950,1000,1050,1100,1150,1200,1250,1275,
                   0,50,100,150,200,300,400,500,600,650,700,750,800,850,900,950,1000,1050,1100,1150,1200,1250,1300,1325,
                   0,50,100,150,200,300,400,500,600,650,700,750,800,850,900,950,1000,1050,1100,1150,1200,1250,1300,1350,1375,
                   0,50,100,150,200,300,400,500,600,700,750,800,850,900,950,1000,1050,1100,1150,1200,1250,1300,1350,1400,1425,
                   0,50,100,150,200,300,400,500,600,700,750,800,850,900,950,1000,1050,1100,1150,1200,1250,1300,1350,1400,1450,1475,
                   0,50,100,150,200,300,400,500,600,700,800,850,900,950,1000,1050,1100,1150,1200,1250,1300,1350,1400,1450,1500,1525,
                   0,50,100,150,200,300,400,500,600,700,800,850,900,950,1000,1050,1100,1150,1200,1250,1300,1350,1400,1450,1500,1550,1575,
                   0,50,100,150,200,300,400,500,600,700,800,900,950,1000,1050,1100,1150,1200,1250,1300,1350,1400,1450,1500,1550,1600,
                   0,50,100,150,200,300,400,500,600,700,800,900,950,1000,1050,1100,1150,1200,1250,1300,1350,1400,1450,1500,1550,1600,
                   0,50,100,150,200,300,400,500,600,700,800,900,1000,1050,1100,1150,1200,1250,1300,1350,1400,1450,1500,1550,1600,
                   0,50,100,150,200,300,400,500,600,700,800,900,1000,1050,1100,1150,1200,1250,1300,1350,1400,1450,1500,1550,1600,
                   0,50,100,150,200,300,400,500,600,700,800,900,1000,1100,1150,1200,1250,1300,1350,1400,1450,1500,1550,1600,
                   0,50,100,150,200,300,400,500,600,700,800,900,1000,1100,1150,1200,1250,1300,1350,1400,1450,1500,1550,1600,
                   0,50,100,150,200,300,400,500,600,700,800,900,1000,1100,1200,1250,1300,1350,1400,1450,1500,1550,1600,
                   0,50,100,150,200,300,400,500,600,700,800,900,1000,1100,1200,1250,1300,1350,1400,1450,1500,1550,1600,
                   0,50,100,150,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1350,1400,1450,1500,1550,1600};


//_______________________________________________________
//                Define Skimming cuts
//   (Not needed, unless you want to skim the ntuple)

bool
Analysis::pass_skimming(DataStruct& data)
{
  int NJetAK8 = 0;
  while(data.jetsAK8.Loop()) {
    size_t i = data.jetsAK8.it;
    // pt cut intentionally removed to accept all jets for systematics
    if ( data.jetsAK8.looseJetID[i] == 1 &&
         std::abs(data.jetsAK8.Eta[i])  <  JET_AK8_ETA_CUT ) {
      NJetAK8++;
    }
  }
  if (!(NJetAK8>=1)) return 0;
  if (!(data.evt.R2>=0.04)) return 0;
  return 1;
}

//_______________________________________________________
//          Define Analysis event selection cuts
//     Can define all sorts of Signal/Control regions

void
Analysis::define_selections(const DataStruct& d)
{
  analysis_cuts.clear();

  // Define here cuts that are common in all Signal/Control regions
  // MET Filters, etc. are already applied in AnalysisBase.h, See baseline_cuts

  /*
  // cut0: signal mass region
  baseline_cuts.push_back({ .name="signal_mass_selection",   .func = [&d]{ 
            int num = 1;
            return d.evt.SUSY_Gluino_Mass==mGluino[num] && d.evt.SUSY_LSP_Mass==mLSP[num];
	    } });
  */

  baseline_cuts.push_back({ .name="Skim_1JetAK8",    .func = []    { return nJetAK8>=1;                      }}); // Similar to pt>200, one AK8 jet has pt>200
  baseline_cuts.push_back({ .name="Skim_R2",         .func = [&d]  { return d.evt.R2>=0.04;                  }}); // New skim cut introduced in 2017 february
  //baseline_cuts.push_back({ .name="Baseline_3Jet",   .func = []    { return nJet>=3;                       }}); // Separate cut, so one can exclude (N-1)
  //baseline_cuts.push_back({ .name="Baseline_MR_R2",  .func = [&d]  { return d.evt.MR>800 && d.evt.R2>0.08; }});
  //baseline_cuts.push_back({ .name="Trigger",   .func = []    { return passTrigger==1;}});
  //temporaray
  //baseline_cuts.push_back({ .name="One Electron",       .func = []    { return nEleTight>=1;                  }});
  //baseline_cuts.push_back({ .name="Electron Trigger",   .func = [&d]    { return d.hlt.Ele27_WPTight_Gsf==1;}});
  //baseline_cuts.push_back({ .name="One Muon",       .func = []    { return nMuTight>=1;                  }});
  //baseline_cuts.push_back({ .name="Muon Trigger",   .func = [&d]    { return d.hlt.IsoMu24==1;        }});

  // S: Signal region
  analysis_cuts['S'].push_back({ .name="3Jet",       .func = []    { return nJet>=3;                         }}); // Separate cut, so one can exclude (N-1)
  analysis_cuts['S'].push_back({ .name="MR_R2",      .func = [&d]  { return d.evt.MR>=800 && d.evt.R2>=0.08; }}); 
  analysis_cuts['S'].push_back({ .name="HLT",   .func = [this,&d]  { return isData ? d.hlt.AK8PFJet450==1 || d.hlt.PFHT800==1 || d.hlt.PFHT900==1 : 1; }});
  analysis_cuts['S'].push_back({ .name="0Ele",       .func = []    { return nEleVeto==0;                     }});
  analysis_cuts['S'].push_back({ .name="0Mu",        .func = []    { return nMuVeto==0;                      }});
#if VER != 0
  analysis_cuts['S'].push_back({ .name="0IsoTrk",    .func = [&d]  { return d.evt.NIsoTrk==0;                }});
#endif
  analysis_cuts['S'].push_back({ .name="1b",         .func = []    { return nMediumBTag>=1;                  }});
  analysis_cuts['S'].push_back({ .name="1W",         .func = []    { return nTightWTag>=1;                   }});
  analysis_cuts['S'].push_back({ .name="mDPhi",      .func = []    { return minDeltaPhi>=0.5;                }});

  // S': DPhi Control region of Signal region
  analysis_cuts['s'].push_back({ .name="HLT",   .func = [this,&d]  { return isData ? d.hlt.AK8PFJet450==1 || d.hlt.PFHT800==1 || d.hlt.PFHT900==1 : 1; }});
  analysis_cuts['s'].push_back({ .name="0Ele",       .func = []    { return nEleVeto==0;                     }});
  analysis_cuts['s'].push_back({ .name="0Mu",        .func = []    { return nMuVeto==0;                      }});
#if VER != 0
  analysis_cuts['s'].push_back({ .name="0IsoTrk",    .func = [&d]  { return d.evt.NIsoTrk==0;                }});
#endif
  analysis_cuts['s'].push_back({ .name="1b",         .func = []    { return nMediumBTag>=1;                  }});
  analysis_cuts['s'].push_back({ .name="1W",         .func = []    { return nTightWTag>=1;                   }});
  analysis_cuts['s'].push_back({ .name="InvmDPhi",   .func = []    { return minDeltaPhi<0.5;                 }});

  // Q: QCD enriched control sample
  analysis_cuts['Q'].push_back({ .name="3Jet",       .func = []    { return nJet>=3;                         }});
  analysis_cuts['Q'].push_back({ .name="MR_R2",      .func = [&d]  { return d.evt.MR>=800 && d.evt.R2>=0.08; }});
  analysis_cuts['Q'].push_back({ .name="HLT",   .func = [this,&d]  { return isData ? d.hlt.AK8PFJet450==1 || d.hlt.PFHT800==1 || d.hlt.PFHT900==1 : 1; }});
  analysis_cuts['Q'].push_back({ .name="0Ele",       .func = []    { return nEleVeto==0;                     }});
  analysis_cuts['Q'].push_back({ .name="0Mu",        .func = []    { return nMuVeto==0;                      }});
#if VER != 0
  analysis_cuts['Q'].push_back({ .name="0IsoTrk",    .func = [&d]  { return d.evt.NIsoTrk==0;                }});
#endif
  analysis_cuts['Q'].push_back({ .name="0b",         .func = []    { return nLooseBTag==0;                   }});
  analysis_cuts['Q'].push_back({ .name="1aW",        .func = []    { return nTightWAntiTag>=1;               }});
  analysis_cuts['Q'].push_back({ .name="InvmDPhi0p3",.func = []    { return minDeltaPhi<0.3;                 }});

  // Q': Dphi Control region of QCD enriched sample
  analysis_cuts['q'].push_back({ .name="HLT",   .func = [this,&d]  { return isData ? d.hlt.AK8PFJet450==1 || d.hlt.PFHT800==1 || d.hlt.PFHT900==1 : 1; }});
  analysis_cuts['q'].push_back({ .name="0Ele",       .func = []    { return nEleVeto==0;                     }});
  analysis_cuts['q'].push_back({ .name="0Mu",        .func = []    { return nMuVeto==0;                      }});
#if VER != 0
  analysis_cuts['q'].push_back({ .name="0IsoTrk",    .func = [&d]  { return d.evt.NIsoTrk==0;                }});
#endif
  analysis_cuts['q'].push_back({ .name="0b",         .func = []    { return nLooseBTag==0;                   }});
  analysis_cuts['q'].push_back({ .name="1aW",        .func = []    { return nTightWAntiTag>=1;               }});
  analysis_cuts['q'].push_back({ .name="mDPhi",      .func = []    { return minDeltaPhi>=0.5;                 }});

  // T: Top enriched control sample
  analysis_cuts['T'].push_back({ .name="3Jet",       .func = []    { return nJet>=3;                         }});
  analysis_cuts['T'].push_back({ .name="MR_R2",      .func = [&d]  { return d.evt.MR>=800 && d.evt.R2>=0.08; }});
  analysis_cuts['T'].push_back({ .name="HLT",   .func = [this,&d]  { return isData ? d.hlt.AK8PFJet450==1 || d.hlt.PFHT800==1 || d.hlt.PFHT900==1 : 1; }});
  analysis_cuts['T'].push_back({ .name="1Lep",       .func = []    { return nLepSelect==1;                   }});
  analysis_cuts['T'].push_back({ .name="1b",         .func = []    { return nMediumBTag>=1;                  }});
  analysis_cuts['T'].push_back({ .name="1W",         .func = []    { return nTightWTag>=1;                   }});
  analysis_cuts['T'].push_back({ .name="mDPhi",      .func = []    { return minDeltaPhi>=0.5;                }});
  analysis_cuts['T'].push_back({ .name="MT<100",     .func = []    { return MT<100;                          }});

  // W: W enriched control sample
  analysis_cuts['W'].push_back({ .name="3Jet",       .func = []    { return nJet>=3;                         }});
  analysis_cuts['W'].push_back({ .name="MR_R2",      .func = [&d]  { return d.evt.MR>=800 && d.evt.R2>=0.08; }});
  analysis_cuts['W'].push_back({ .name="HLT",   .func = [this,&d]  { return isData ? d.hlt.AK8PFJet450==1 || d.hlt.PFHT800==1 || d.hlt.PFHT900==1 : 1; }});
  analysis_cuts['W'].push_back({ .name="1Lep",       .func = []    { return nLepSelect==1;                   }});
  analysis_cuts['W'].push_back({ .name="0b",         .func = []    { return nLooseBTag==0;                   }});
  analysis_cuts['W'].push_back({ .name="1mW",        .func = []    { return nWPreTag>=1;                     }});
  analysis_cuts['W'].push_back({ .name="mDPhi",      .func = []    { return minDeltaPhi>=0.5;                }});
  analysis_cuts['W'].push_back({ .name="30<=MT<100", .func = []    { return MT>=30 && MT<100;                }});
  
}

//____________________________________________________
//          Analysis Specific Scale factors
//    (Defined for each search region separately)

void
Analysis::apply_scale_factors(DataStruct& data, const unsigned int& s, const std::vector<std::vector<double> >& nSigmaSFs)
{
  bool isFastSim = TString(sample).Contains("FastSim");
  size_t i = 0;

  // Don't forget to specify the total number of sigmas you use in settings_*.h !

  // Electron SFs (4 sigmas - reco, iso, id, fastsim)
  std::pair<double, double> sf_ele = calc_ele_sf(data, nSigmaSFs[i][s], nSigmaSFs[i+1][s], nSigmaSFs[i+2][s], nSigmaSFs[i+3][s], isFastSim);
  double sf_ele_veto = sf_ele.first, sf_ele_medium = sf_ele.second;  
  i+=4;

  // Muon SFs (7 sigmas - tracking, fullsim id/iso/ip, fastsim id/iso/ip)
  std::pair<double, double> sf_muon = calc_muon_sf(data, nSigmaSFs[i][s], nSigmaSFs[i+1][s], nSigmaSFs[i+2][s], nSigmaSFs[i+3][s],
						   nSigmaSFs[i+4][s], nSigmaSFs[i+5][s], nSigmaSFs[i+6][s], isFastSim);
  double sf_muon_veto = sf_muon.first, sf_muon_medium = sf_muon.second;
  i+=7;

  // W tagging SF  (1 sigma - efficiency)
  double sf_w = calc_w_tagging_sf(data, nSigmaSFs[i][s]);
  i+=1;

  // b tagging SFs (1 sigma)
  std::pair<double, double> sf_btag = calc_b_tagging_sf(data, nSigmaSFs[i][s], isFastSim);
  double sf_btag_loose = sf_btag.first, sf_btag_medium = sf_btag.second;
  i+=1;

  // Select scale factors to use
  for (auto& sf : scale_factors) sf.second.clear();
  scale_factors['S'].push_back(sf_ele_veto);
  scale_factors['S'].push_back(sf_muon_veto);
  scale_factors['S'].push_back(sf_btag_medium);
  scale_factors['S'].push_back(sf_w);

  scale_factors['s'] = scale_factors['S'];

  scale_factors['Q'].push_back(sf_ele_veto);
  scale_factors['Q'].push_back(sf_muon_veto);
  scale_factors['Q'].push_back(sf_btag_loose);
  scale_factors['Q'].push_back(sf_w);

  scale_factors['q'] = scale_factors['Q'];

  scale_factors['T'].push_back(sf_ele_medium);
  scale_factors['T'].push_back(sf_muon_medium);
  scale_factors['T'].push_back(sf_btag_medium);
  scale_factors['T'].push_back(sf_w);

  scale_factors['W'].push_back(sf_ele_medium);
  scale_factors['W'].push_back(sf_muon_medium);
  scale_factors['W'].push_back(sf_btag_loose);
}

//_______________________________________________________
//                 Signal Region
//     Must define it, because we blind it in data!

bool
Analysis::signal_selection(const DataStruct& data) {
  //return apply_all_cuts('S');
  return 0;
}

//_______________________________________________________
//                 List of Histograms

TH1D* h_njet_S;
TH1D* h_njet_S_MRR2;
TH1D* h_njet_S_3Jet;
TH1D* h_njet_Q_3Jet;
TH1D* h_njet_W_3Jet;
TH1D* h_njet_T_3Jet;
TH1D* h_njetAK8_S;
TH1D* h_njetAK8_Q;
TH1D* h_njetAK8_W;
TH1D* h_njetAK8_T;

TH1D* h_njet;
TH1D* h_nb;
TH1D* h_nw;
TH1D* h_ht_gen;
TH1D* h_ht_AK4;
TH1D* h_ht_AK8;

TH1D* h_ht_AK4_S;
TH1D* h_ht_AK8_S;
TH1D* h_jet1_pt_S;
TH1D* h_jet2_pt_S;
TH1D* h_jet3_pt_S;
TH1D* h_MR_S;
TH1D* h_MTR_S;
TH1D* h_R_S;
TH1D* h_R2_S;
TH1D* h_tau21_S;
TH1D* h_MET_S;

TH1D* h_njet_nj35;
TH1D* h_njet_nj5;
TH1D* h_njet_nw1;
TH1D* h_njet_nw2;
TH1D* h_njet_nb1;
TH1D* h_njet_nb2;
TH1D* h_njetAK8_nj35;
TH1D* h_njetAK8_nj5;
TH1D* h_njetAK8_nw1;
TH1D* h_njetAK8_nw2;
TH1D* h_njetAK8_nb1;
TH1D* h_njetAK8_nb2;
TH1D* h_nb_nj35;
TH1D* h_nb_nj5;
TH1D* h_nb_nw1;
TH1D* h_nb_nw2;
TH1D* h_nb_nb1;
TH1D* h_nb_nb2;
TH1D* h_nw_nj35;
TH1D* h_nw_nj5;
TH1D* h_nw_nw1;
TH1D* h_nw_nw2;
TH1D* h_nw_nb1;
TH1D* h_nw_nb2;
TH1D* h_mT_nj35;
TH1D* h_mT_nj5;
TH1D* h_mT_nw1;
TH1D* h_mT_nw2;
TH1D* h_mT_nb1;
TH1D* h_mT_nb2;
TH1D* h_dPhimin_nj35;
TH1D* h_dPhimin_nj5;
TH1D* h_dPhimin_nw1;
TH1D* h_dPhimin_nw2;
TH1D* h_dPhimin_nb1;
TH1D* h_dPhimin_nb2;
TH1D* h_MR_nj35;
TH1D* h_MR_nj5;
TH1D* h_MR_nw1;
TH1D* h_MR_nw2;
TH1D* h_MR_nb1;
TH1D* h_MR_nb2;
TH1D* h_R2_nj35;
TH1D* h_R2_nj5;
TH1D* h_R2_nw1;
TH1D* h_R2_nw2;
TH1D* h_R2_nb1;
TH1D* h_R2_nb2;


TH1D* h_njet_S_nj35;
TH1D* h_njet_S_nj5;
TH1D* h_njet_S_nw1;
TH1D* h_njet_S_nw2;
TH1D* h_njet_S_nb1;
TH1D* h_njet_S_nb2;
TH1D* h_njetAK8_S_nj35;
TH1D* h_njetAK8_S_nj5;
TH1D* h_njetAK8_S_nw1;
TH1D* h_njetAK8_S_nw2;
TH1D* h_njetAK8_S_nb1;
TH1D* h_njetAK8_S_nb2;
TH1D* h_nb_S_nj35;
TH1D* h_nb_S_nj5;
TH1D* h_nb_S_nw1;
TH1D* h_nb_S_nw2;
TH1D* h_nb_S_nb1;
TH1D* h_nb_S_nb2;
TH1D* h_nw_S_nj35;
TH1D* h_nw_S_nj5;
TH1D* h_nw_S_nw1;
TH1D* h_nw_S_nw2;
TH1D* h_nw_S_nb1;
TH1D* h_nw_S_nb2;
TH1D* h_mT_S_nj35;
TH1D* h_mT_S_nj5;
TH1D* h_mT_S_nw1;
TH1D* h_mT_S_nw2;
TH1D* h_mT_S_nb1;
TH1D* h_mT_S_nb2;
TH1D* h_dPhimin_S_nj35;
TH1D* h_dPhimin_S_nj5;
TH1D* h_dPhimin_S_nw1;
TH1D* h_dPhimin_S_nw2;
TH1D* h_dPhimin_S_nb1;
TH1D* h_dPhimin_S_nb2;
TH1D* h_MR_S_nj35;
TH1D* h_MR_S_nj5;
TH1D* h_MR_S_nw1;
TH1D* h_MR_S_nw2;
TH1D* h_MR_S_nb1;
TH1D* h_MR_S_nb2;
TH1D* h_R2_S_nj35;
TH1D* h_R2_S_nj5;
TH1D* h_R2_S_nw1;
TH1D* h_R2_S_nw2;
TH1D* h_R2_S_nb1;
TH1D* h_R2_S_nb2;


TH1D* h_ht_AK4_W;
TH1D* h_ht_AK8_W;
TH1D* h_jet1_pt_W;
TH1D* h_jet2_pt_W;
TH1D* h_jet3_pt_W;
TH1D* h_MR_W;
TH1D* h_MTR_W;
TH1D* h_R_W;
TH1D* h_R2_W;
TH1D* h_tau21_W;
TH1D* h_MET_W;

TH1D* h_ht_AK4_T;
TH1D* h_ht_AK8_T;
TH1D* h_jet1_pt_T;
TH1D* h_jet2_pt_T;
TH1D* h_jet3_pt_T;
TH1D* h_MR_T;
TH1D* h_MTR_T;
TH1D* h_R_T;
TH1D* h_R2_T;
TH1D* h_tau21_T;
TH1D* h_MET_T;

TH1D* h_ht_AK4_Q;
TH1D* h_ht_AK8_Q;
TH1D* h_jet1_pt_Q;
TH1D* h_jet2_pt_Q;
TH1D* h_jet3_pt_Q;
TH1D* h_MR_Q;
TH1D* h_MTR_Q;
TH1D* h_R_Q;
TH1D* h_R2_Q;
TH1D* h_tau21_Q;
TH1D* h_MET_Q;


TH1D* h_softDropMass;
TH1D* h_StopMass;
TH1D* h_GluinoMass;
TH1D* h_LSPMass;
TH2D* h_R2_MR;
TH2D* h_GluinoLSPMass;

//std::vector<TH1D*> vh_jet1_pt;

TH1D* h_njet_pre;
TH1D* h_nb_pre;
TH1D* h_nw_pre;
TH1D* h_j2_pt_pre;
TH1D* h_j3_pt_pre;
TH1D* h_MR_pre;
TH1D* h_R2_pre;
TH1D* h_tau21_pre;
TH1D* h_MET_pre;
TH1D* h_softDropMass_pre;

TH1D* h_njet_pre_pass1;
TH1D* h_nb_pre_pass1;
TH1D* h_nw_pre_pass1;
TH1D* h_j2_pt_pre_pass1;
TH1D* h_j3_pt_pre_pass1;
TH1D* h_MR_pre_pass1;
TH1D* h_R2_pre_pass1;
TH1D* h_tau21_pre_pass1;
TH1D* h_MET_pre_pass1;
TH1D* h_softDropMass_pre_pass1;

TH1D* h_njet_pre_pass2;
TH1D* h_nb_pre_pass2;
TH1D* h_nw_pre_pass2;
TH1D* h_j2_pt_pre_pass2;
TH1D* h_j3_pt_pre_pass2;
TH1D* h_MR_pre_pass2;
TH1D* h_R2_pre_pass2;
TH1D* h_tau21_pre_pass2;
TH1D* h_MET_pre_pass2;
TH1D* h_softDropMass_pre_pass2;

TH1D* h_njet_pre_pass3;
TH1D* h_nb_pre_pass3;
TH1D* h_nw_pre_pass3;
TH1D* h_j2_pt_pre_pass3;
TH1D* h_j3_pt_pre_pass3;
TH1D* h_MR_pre_pass3;
TH1D* h_R2_pre_pass3;
TH1D* h_tau21_pre_pass3;
TH1D* h_MET_pre_pass3;
TH1D* h_softDropMass_pre_pass3;

TH1D* h_njet_pre_passj1pt;
TH1D* h_nb_pre_passj1pt;
TH1D* h_nw_pre_passj1pt;
TH1D* h_j2_pt_pre_passj1pt;
TH1D* h_j3_pt_pre_passj1pt;
TH1D* h_MR_pre_passj1pt;
TH1D* h_R2_pre_passj1pt;
TH1D* h_tau21_pre_passj1pt;
TH1D* h_MET_pre_passj1pt;
TH1D* h_softDropMass_pre_passj1pt;

TH1D* h_njet_pre_passHT;
TH1D* h_nb_pre_passHT;
TH1D* h_nw_pre_passHT;
TH1D* h_j2_pt_pre_passHT;
TH1D* h_j3_pt_pre_passHT;
TH1D* h_MR_pre_passHT;
TH1D* h_R2_pre_passHT;
TH1D* h_tau21_pre_passHT;
TH1D* h_MET_pre_passHT;
TH1D* h_softDropMass_pre_passHT;

TH1D *h_HT_pre;
TH1D *h_HT_pre_pass1;
TH1D *h_HT_pre_pass2;
TH1D *h_HT_pre_pass3;
TH1D *h_HT_pre_passj1pt;
TH1D *h_HT_pre_passHT;
TH1D *h_HT_Q;
TH1D *h_HT_Q_pass;
TH1D *h_HT_Q_passj1pt;
TH1D *h_HT_Q_passHT;
TH1D *h_HT_S;
TH1D *h_HT_S_pass;
TH1D *h_HT_S_passj1pt;
TH1D *h_HT_S_passHT;

TH1D *h_j1_pt_pre;
TH1D *h_j1_pt_pre_pass1;
TH1D *h_j1_pt_pre_pass2;
TH1D *h_j1_pt_pre_pass3;
TH1D *h_j1_pt_pre_passHT;
TH1D *h_j1_pt_pre_passj1pt;
TH1D *h_j1_pt_Q;
TH1D *h_j1_pt_Q_pass;
TH1D *h_j1_pt_Q_passHT;
TH1D *h_j1_pt_Q_passj1pt;
TH1D *h_j1_pt_S;
TH1D *h_j1_pt_S_pass;
TH1D *h_j1_pt_S_passHT;
TH1D *h_j1_pt_S_passj1pt;

TH2D *h_HT_j1pt_pre;
TH2D *h_HT_j1pt_pre_pass1;
TH2D *h_HT_j1pt_pre_pass2;
TH2D *h_HT_j1pt_pre_pass3;
TH2D *h_HT_j1pt_pre_passHT;
TH2D *h_HT_j1pt_pre_passj1pt;
TH2D *h_HT_j1pt_Q;
TH2D *h_HT_j1pt_Q_pass;
TH2D *h_HT_j1pt_Q_passHT;
TH2D *h_HT_j1pt_Q_passj1pt;
TH2D *h_HT_j1pt_S;
TH2D *h_HT_j1pt_S_pass;
TH2D *h_HT_j1pt_S_passHT ;
TH2D *h_HT_j1pt_S_passj1pt;
TH2D *h_HT_j1pt_T;
TH2D *h_HT_j1pt_T_pass;
TH2D *h_HT_j1pt_T_passHT;
TH2D *h_HT_j1pt_T_passj1pt;
TH2D *h_HT_j1pt_W;
TH2D *h_HT_j1pt_W_pass;
TH2D *h_HT_j1pt_W_passHT;
TH2D *h_HT_j1pt_W_passj1pt;

TH2D* h_HT_weight;
//_______________________________________________________
//              Define Histograms here
void
Analysis::init_analysis_histos(const unsigned int& syst_nSyst, const unsigned int& syst_index)
{

  h_njet_S = new TH1D("njet_S",         ";N_{jet}",                20, 0,  20);
  h_njet_S_MRR2 = new TH1D("njet_S_MRR2",         ";N_{jet}",                20, 0,  20);
  h_njet_S_3Jet = new TH1D("njet_S_3Jet",         ";N_{jet}",                20, 0,  20);
  h_njet_Q_3Jet = new TH1D("njet_Q_3Jet",         ";N_{jet}",                20, 0,  20);
  h_njet_W_3Jet = new TH1D("njet_W_3Jet",         ";N_{jet}",                20, 0,  20);
  h_njet_T_3Jet = new TH1D("njet_T_3Jet",         ";N_{jet}",                20, 0,  20);
  h_njetAK8_S = new TH1D("njetAK8_S",         ";N_{jet}",                20, 0,  20);
  h_njetAK8_Q = new TH1D("njetAK8_Q",         ";N_{jet}",                20, 0,  20);
  h_njetAK8_W = new TH1D("njetAK8_W",         ";N_{jet}",                20, 0,  20);
  h_njetAK8_T = new TH1D("njetAK8_T",         ";N_{jet}",                20, 0,  20);

  h_njet         = new TH1D("njet",         ";N_{jet}",                20, 0,  20);
  h_nw           = new TH1D("nw",           ";N_{W tag}",              20, 0,  20);
  h_nb           = new TH1D("nb",           ";N_{b tag}",              20, 0,  20);
  h_ht_gen       = new TH1D("ht_gen",       ";H_{T}^{gen}",            300, 0,3000);

  h_ht_AK4  = new TH1D("ht_AK4",  ";H_{T}",                  300, 0,3000);
  h_ht_AK8  = new TH1D("ht_AK8",  ";H_{T}^{AK8}",            300, 0,3000);

  h_ht_AK4_S = new TH1D("ht_AK4_S",  ";H_{T}",                  300, 0,3000);
  h_ht_AK8_S = new TH1D("ht_AK8_S",  ";H_{T}^{AK8}",            300, 0,3000);
  h_jet1_pt_S = new TH1D("jet1_pt_S",      ";p_{T, jet1}",            200, 0,2000);
  h_jet2_pt_S = new TH1D("jet2_pt_S",      ";p_{T, jet2}",            200, 0,2000);
  h_jet3_pt_S = new TH1D("jet3_pt_S",      ";p_{T, jet3}",            200, 0,2000);
  h_MR_S = new TH1D("MR_S",   ";MR_{AK4}",         200, 0,4000);
  h_MTR_S = new TH1D("MTR_S",  ";MTR_{AK4}",        200, 0,2000);
  h_R_S = new TH1D("R_S",    ";R_{AK4}",          500, 0,1);
  h_R2_S = new TH1D("R2_S",   ";R2_{AK4}",         500, 0,1);
  h_tau21_S = new TH1D("tau21_S", ";tau21", 200,0,1);
  h_MET_S = new TH1D("MET_S", ";MET", 400,0,2000);

  h_njet_nj35 = new TH1D("h_njet_nj35",";N_{jet}", 20,0,20);
  h_njet_nj5 = new TH1D("h_njet_nj5",";N_{jet}", 20,0,20);
  h_njet_nw1 = new TH1D("h_njet_nw1",";N_{jet}", 20,0,20);
  h_njet_nw2 = new TH1D("h_njet_nw2",";N_{jet}", 20,0,20);
  h_njet_nb1 = new TH1D("h_njet_nb1",";N_{jet}", 20,0,20);
  h_njet_nb2 = new TH1D("h_njet_nb2",";N_{jet}", 20,0,20);
  h_njetAK8_nj35 = new TH1D("h_njetAK8_nj35",";N_{AK8jet}", 20,0,20);
  h_njetAK8_nj5 = new TH1D("h_njetAK8_nj5",";N_{AK8jet}", 20,0,20);
  h_njetAK8_nw1 = new TH1D("h_njetAK8_nw1",";N_{AK8jet}", 20,0,20);
  h_njetAK8_nw2 = new TH1D("h_njetAK8_nw2",";N_{AK8jet}", 20,0,20);
  h_njetAK8_nb1 = new TH1D("h_njetAK8_nb1",";N_{AK8jet}", 20,0,20);
  h_njetAK8_nb2 = new TH1D("h_njetAK8_nb2",";N_{AK8jet}", 20,0,20);
  h_nb_nj35 = new TH1D("nb_nj35",";N_{b tag}",20, 0,20);
  h_nb_nj5 = new TH1D("nb_nj5",";N_{b tag}",20, 0,20);
  h_nb_nw1 = new TH1D("nb_nw1",";N_{b tag}",20, 0,20);
  h_nb_nw2 = new TH1D("nb_nw2",";N_{b tag}",20, 0,20);
  h_nb_nb1 = new TH1D("nb_nb1",";N_{b tag}",20, 0,20);
  h_nb_nb2 = new TH1D("nb_nb2",";N_{b tag}",20, 0,20);
  h_nw_nj35 = new TH1D("nw_nj35",";N_{W tag}",20, 0,20);
  h_nw_nj5 = new TH1D("nw_nj5",";N_{W tag}",20, 0,20);
  h_nw_nw1 = new TH1D("nw_nw1",";N_{W tag}",20, 0,20);
  h_nw_nw2 = new TH1D("nw_nw2",";N_{W tag}",20, 0,20);
  h_nw_nb1 = new TH1D("nw_nb1",";N_{W tag}",20, 0,20);
  h_nw_nb2 = new TH1D("nw_nb2",";N_{W tag}",20, 0,20);
  h_mT_nj35 = new TH1D("mT_nj35",";m_{T}",50, 0,500);
  h_mT_nj5 = new TH1D("mT_nj5",";m_{T}",50, 0,500);
  h_mT_nw1 = new TH1D("mT_nw1",";m_{T}",50, 0,500);
  h_mT_nw2 = new TH1D("mT_nw2",";m_{T}",50, 0,500);
  h_mT_nb1 = new TH1D("mT_nb1",";m_{T}",50, 0,500);
  h_mT_nb2 = new TH1D("mT_nb2",";m_{T}",50, 0,500);
h_dPhimin_nj35 = new TH1D("dPhimin_nj35",";min_#Delta#phi(AK4_{1~3}, MET)",320,0,3.2);
  h_dPhimin_nj5 = new TH1D("dPhimin_nj5",";min_#Delta#phi(AK4_{1~3}, MET)",320,0,3.2);
  h_dPhimin_nw1 = new TH1D("dPhimin_nw1",";min_#Delta#phi(AK4_{1~3}, MET)",320,0,3.2);
  h_dPhimin_nw2 = new TH1D("dPhimin_nw2",";min_#Delta#phi(AK4_{1~3}, MET)",320,0,3.2);
  h_dPhimin_nb1 = new TH1D("dPhimin_nb1",";min_#Delta#phi(AK4_{1~3}, MET)",320,0,3.2);
  h_dPhimin_nb2 = new TH1D("dPhimin_nb2",";min_#Delta#phi(AK4_{1~3}, MET)",320,0,3.2);
  h_MR_nj35 = new TH1D("MR_nj35",";MR_{AK4}",200,0,4000);
  h_MR_nj5 = new TH1D("MR_nj5",";MR_{AK4}",200,0,4000);
  h_MR_nw1 = new TH1D("MR_nw1",";MR_{AK4}",200,0,4000);
  h_MR_nw2 = new TH1D("MR_nw2",";MR_{AK4}",200,0,4000);
  h_MR_nb1 = new TH1D("MR_nb1",";MR_{AK4}",200,0,4000);
  h_MR_nb2 = new TH1D("MR_nb2",";MR_{AK4}",200,0,4000);
  h_R2_nj35 = new TH1D("R2_nj35",";R2_{AK4}",500, 0,1);
  h_R2_nj5 = new TH1D("R2_nj5",";R2_{AK4}",500, 0,1);
  h_R2_nw1 = new TH1D("R2_nw1",";R2_{AK4}",500, 0,1);
  h_R2_nw2 = new TH1D("R2_nw2",";R2_{AK4}",500, 0,1);
  h_R2_nb1 = new TH1D("R2_nb1",";R2_{AK4}",500, 0,1);
  h_R2_nb2 = new TH1D("R2_nb2",";R2_{AK4}",500, 0,1);

  h_njet_S_nj35 = new TH1D("h_njet_S_nj35",";N_{jet}", 20,0,20);
  h_njet_S_nj5 = new TH1D("h_njet_S_nj5",";N_{jet}", 20,0,20);
  h_njet_S_nw1 = new TH1D("h_njet_S_nw1",";N_{jet}", 20,0,20);
  h_njet_S_nw2 = new TH1D("h_njet_S_nw2",";N_{jet}", 20,0,20);
  h_njet_S_nb1 = new TH1D("h_njet_S_nb1",";N_{jet}", 20,0,20);
  h_njet_S_nb2 = new TH1D("h_njet_S_nb2",";N_{jet}", 20,0,20);
  h_njetAK8_S_nj35 = new TH1D("h_njetAK8_S_nj35",";N_{AK8jet}", 20,0,20);
  h_njetAK8_S_nj5 = new TH1D("h_njetAK8_S_nj5",";N_{AK8jet}", 20,0,20);
  h_njetAK8_S_nw1 = new TH1D("h_njetAK8_S_nw1",";N_{AK8jet}", 20,0,20);
  h_njetAK8_S_nw2 = new TH1D("h_njetAK8_S_nw2",";N_{AK8jet}", 20,0,20);
  h_njetAK8_S_nb1 = new TH1D("h_njetAK8_S_nb1",";N_{AK8jet}", 20,0,20);
  h_njetAK8_S_nb2 = new TH1D("h_njetAK8_S_nb2",";N_{AK8jet}", 20,0,20);
  h_nb_S_nj35 = new TH1D("nb_S_nj35",";N_{b tag}",20, 0,20);
  h_nb_S_nj5 = new TH1D("nb_S_nj5",";N_{b tag}",20, 0,20);
  h_nb_S_nw1 = new TH1D("nb_S_nw1",";N_{b tag}",20, 0,20);
  h_nb_S_nw2 = new TH1D("nb_S_nw2",";N_{b tag}",20, 0,20);
  h_nb_S_nb1 = new TH1D("nb_S_nb1",";N_{b tag}",20, 0,20);
  h_nb_S_nb2 = new TH1D("nb_S_nb2",";N_{b tag}",20, 0,20);
  h_nw_S_nj35 = new TH1D("nw_S_nj35",";N_{W tag}",20, 0,20);
  h_nw_S_nj5 = new TH1D("nw_S_nj5",";N_{W tag}",20, 0,20);
  h_nw_S_nw1 = new TH1D("nw_S_nw1",";N_{W tag}",20, 0,20);
  h_nw_S_nw2 = new TH1D("nw_S_nw2",";N_{W tag}",20, 0,20);
  h_nw_S_nb1 = new TH1D("nw_S_nb1",";N_{W tag}",20, 0,20);
  h_nw_S_nb2 = new TH1D("nw_S_nb2",";N_{W tag}",20, 0,20);
  h_mT_S_nj35 = new TH1D("mT_S_nj35",";m_{T}",50, 0,500);
  h_mT_S_nj5 = new TH1D("mT_S_nj5",";m_{T}",50, 0,500);
  h_mT_S_nw1 = new TH1D("mT_S_nw1",";m_{T}",50, 0,500);
  h_mT_S_nw2 = new TH1D("mT_S_nw2",";m_{T}",50, 0,500);
  h_mT_S_nb1 = new TH1D("mT_S_nb1",";m_{T}",50, 0,500);
  h_mT_S_nb2 = new TH1D("mT_S_nb2",";m_{T}",50, 0,500);
h_dPhimin_S_nj35 = new TH1D("dPhimin_S_nj35",";min_#Delta#phi(AK4_{1~3}, MET)",320,0,3.2);
  h_dPhimin_S_nj5 = new TH1D("dPhimin_S_nj5",";min_#Delta#phi(AK4_{1~3}, MET)",320,0,3.2);
  h_dPhimin_S_nw1 = new TH1D("dPhimin_S_nw1",";min_#Delta#phi(AK4_{1~3}, MET)",320,0,3.2);
  h_dPhimin_S_nw2 = new TH1D("dPhimin_S_nw2",";min_#Delta#phi(AK4_{1~3}, MET)",320,0,3.2);
  h_dPhimin_S_nb1 = new TH1D("dPhimin_S_nb1",";min_#Delta#phi(AK4_{1~3}, MET)",320,0,3.2);
  h_dPhimin_S_nb2 = new TH1D("dPhimin_S_nb2",";min_#Delta#phi(AK4_{1~3}, MET)",320,0,3.2);
  h_MR_S_nj35 = new TH1D("MR_S_nj35",";MR_{AK4}",200,0,4000);
  h_MR_S_nj5 = new TH1D("MR_S_nj5",";MR_{AK4}",200,0,4000);
  h_MR_S_nw1 = new TH1D("MR_S_nw1",";MR_{AK4}",200,0,4000);
  h_MR_S_nw2 = new TH1D("MR_S_nw2",";MR_{AK4}",200,0,4000);
  h_MR_S_nb1 = new TH1D("MR_S_nb1",";MR_{AK4}",200,0,4000);
  h_MR_S_nb2 = new TH1D("MR_S_nb2",";MR_{AK4}",200,0,4000);
  h_R2_S_nj35 = new TH1D("R2_S_nj35",";R2_{AK4}",500, 0,1);
  h_R2_S_nj5 = new TH1D("R2_S_nj5",";R2_{AK4}",500, 0,1);
  h_R2_S_nw1 = new TH1D("R2_S_nw1",";R2_{AK4}",500, 0,1);
  h_R2_S_nw2 = new TH1D("R2_S_nw2",";R2_{AK4}",500, 0,1);
  h_R2_S_nb1 = new TH1D("R2_S_nb1",";R2_{AK4}",500, 0,1);
  h_R2_S_nb2 = new TH1D("R2_S_nb2",";R2_{AK4}",500, 0,1);

  h_ht_AK4_W = new TH1D("ht_AK4_W",  ";H_{T}",                  300, 0,3000);
  h_ht_AK8_W = new TH1D("ht_AK8_W",  ";H_{T}^{AK8}",            300, 0,3000);
  h_jet1_pt_W = new TH1D("jet1_pt_W",      ";p_{T, jet1}",            200, 0,2000);
  h_jet2_pt_W = new TH1D("jet2_pt_W",      ";p_{T, jet2}",            200, 0,2000);
  h_jet3_pt_W = new TH1D("jet3_pt_W",      ";p_{T, jet3}",            200, 0,2000);
  h_MR_W = new TH1D("MR_W",   ";MR_{AK4}",         200, 0,4000);
  h_MTR_W = new TH1D("MTR_W",  ";MTR_{AK4}",        200, 0,2000);
  h_R_W = new TH1D("R_W",    ";R_{AK4}",          500, 0,1);
  h_R2_W = new TH1D("R2_W",   ";R2_{AK4}",         500, 0,1);
  h_tau21_W = new TH1D("tau21_W", ";tau21", 200,0,1);
  h_MET_W = new TH1D("MET_W", ";MET", 400,0,2000);

  h_ht_AK4_T = new TH1D("ht_AK4_T",  ";H_{T}",                  300, 0,3000);
  h_ht_AK8_T = new TH1D("ht_AK8_T",  ";H_{T}^{AK8}",            300, 0,3000);
  h_jet1_pt_T = new TH1D("jet1_pt_T",      ";p_{T, jet1}",            200, 0,2000);
  h_jet2_pt_T = new TH1D("jet2_pt_T",      ";p_{T, jet2}",            200, 0,2000);
  h_jet3_pt_T = new TH1D("jet3_pt_T",      ";p_{T, jet3}",            200, 0,2000);
  h_MR_T = new TH1D("MR_T",   ";MR_{AK4}",         200, 0,4000);
  h_MTR_T = new TH1D("MTR_T",  ";MTR_{AK4}",        200, 0,2000);
  h_R_T = new TH1D("R_T",    ";R_{AK4}",          500, 0,1);
  h_R2_T = new TH1D("R2_T",   ";R2_{AK4}",         500, 0,1);
  h_tau21_T = new TH1D("tau21_T", ";tau21", 200,0,1);
  h_MET_T = new TH1D("MET_T", ";MET", 400,0,2000);

  h_ht_AK4_Q = new TH1D("ht_AK4_Q",  ";H_{T}",                  300, 0,3000);
  h_ht_AK8_Q = new TH1D("ht_AK8_Q",  ";H_{T}^{AK8}",            300, 0,3000);
  h_jet1_pt_Q = new TH1D("jet1_pt_Q",      ";p_{T, jet1}",            200, 0,2000);
  h_jet2_pt_Q = new TH1D("jet2_pt_Q",      ";p_{T, jet2}",            200, 0,2000);
  h_jet3_pt_Q = new TH1D("jet3_pt_Q",      ";p_{T, jet3}",            200, 0,2000);
  h_MR_Q = new TH1D("MR_Q",   ";MR_{AK4}",         200, 0,4000);
  h_MTR_Q = new TH1D("MTR_Q",  ";MTR_{AK4}",        200, 0,2000);
  h_R_Q = new TH1D("R_Q",    ";R_{AK4}",          500, 0,1);
  h_R2_Q = new TH1D("R2_Q",   ";R2_{AK4}",         500, 0,1);
  h_tau21_Q = new TH1D("tau21_Q", ";tau21", 200,0,1);
  h_MET_Q = new TH1D("MET_Q", ";MET", 400,0,2000);


  h_softDropMass = new TH1D("softDropMass", "", 100,0,500);
  h_GluinoLSPMass = new TH2D("GluinoLSPMass","",34,600,2300,64,0,1600);
  h_StopMass = new TH1D("StopMass", "", 92,0,2300);
  h_GluinoMass = new TH1D("GluinoMass", "", 34,600,2300);
  h_LSPMass = new TH1D("LSPMass", "", 64,0,1600);
  h_R2_MR = new TH2D("R2_MR", ";MR_{AK4};R2_{AK4}", 20,0,4000,10,0,1);
  
/*
  for (unsigned int i=0; i<=syst_nSyst; ++i) {
    std::stringstream histoname, title;
    histoname<<"jet1_pt_syst"<<i;
    title<<"Systematic variation #="<<i;
    vh_jet1_pt.push_back(new TH1D(histoname.str().c_str(), (title.str()+";p_{T, jet1}").c_str(), 200, 0,2000));
  }
*/

  //double htbn = 20;
  //double htmn = 0;
 // double htmx = 1500;

  double j1ptbn = 20;
  double j1ptmn = 0;
  double j1ptmx = 1000;

  //double MRbn = 7;
  //double MRmn = 0;
  //double MRmx = 4000;
  //double Rbn = 7;
  //double Rmn = 0;
  //double Rmx = 1;

  // Variable binning

  int nbn_HT = 19;
  int nbn_j1pt = 12;
  int nbn_MR = 6;
  int nbn_R = 6;
  Double_t  HT_bins[20]  = {0, 200, 300, 400, 500, 600, 650, 700, 750, 800, 900, 1000, 1200, 1500, 2000, 4000, 10000};
  Double_t bn_HT_tmp[] = {0.,50.,100.,150.,200.,250.,300.,350.,400.,450.,500.,550.,600.,650.,700.,750.,800.,900.,1000.,2500.};
  Double_t* bn_HT = 0;
  bn_HT = utils::getVariableBinEdges(nbn_HT+1,bn_HT_tmp);
  Double_t bn_j1pt_tmp[] = {0.,50.,100.,150.,200.,250.,300.,350.,400.,450.,500.,700.,1000.};
  Double_t* bn_j1pt = 0;
  bn_j1pt = utils::getVariableBinEdges(nbn_j1pt+1,bn_j1pt_tmp);
  Double_t bn_MR_tmp[] = {0.,800.,1000.,1200.,1600.,2000.,4000.};
  Double_t* bn_MR = 0;
  bn_MR = utils::getVariableBinEdges(nbn_MR+1,bn_MR_tmp);
  Double_t bn_R_tmp[] = {0.,0.08,.12,.16,0.24,0.5,1.};
  Double_t* bn_R = 0;
  bn_R = utils::getVariableBinEdges(nbn_R+1,bn_R_tmp);
  

  h_njet_pre = new TH1D("h_njet_pre",         ";N_{jet}",                20, 0,  20);
  h_nw_pre = new TH1D("h_nw_pre",           ";N_{W tag}",              20, 0,  20);
  h_nb_pre = new TH1D("h_nb_pre",           ";N_{b tag}",              20, 0,  20);
  h_j2_pt_pre = new TH1D("h_j2_pt_pre",      ";p_{T, jet2}",            j1ptbn,j1ptmn,j1ptmx);
  h_j3_pt_pre = new TH1D("h_j3_pt_pre",      ";p_{T, jet3}",            j1ptbn,j1ptmn,j1ptmx);
  h_MR_pre = new TH1D("h_MR_pre",   ";MR_{AK4}",        nbn_MR,bn_MR);
  h_R2_pre = new TH1D("h_R2_pre",    ";R2_{AK4}",          nbn_R,bn_R);
  h_tau21_pre = new TH1D("h_tau21_pre", ";tau21", 20,0,1);
  h_MET_pre = new TH1D("h_MET_pre", ";MET", j1ptbn,j1ptmn,j1ptmx);
  h_softDropMass_pre = new TH1D("h_softDropMass_pre", "", 20,0,500);

  h_njet_pre_pass1 = new TH1D("h_njet_pre_pass1",         ";N_{jet}",                20, 0,  20);
  h_nw_pre_pass1 = new TH1D("h_nw_pre_pass1",           ";N_{W tag}",              20, 0,  20);
  h_nb_pre_pass1 = new TH1D("h_nb_pre_pass1",           ";N_{b tag}",              20, 0,  20);
  h_j2_pt_pre_pass1 = new TH1D("h_j2_pt_pre_pass1",      ";p_{T, jet2}",            j1ptbn,j1ptmn,j1ptmx);
  h_j3_pt_pre_pass1 = new TH1D("h_j3_pt_pre_pass1",      ";p_{T, jet3}",            j1ptbn,j1ptmn,j1ptmx);
  h_MR_pre_pass1 = new TH1D("h_MR_pre_pass1",   ";MR_{AK4}",        nbn_MR,bn_MR);
  h_R2_pre_pass1 = new TH1D("h_R2_pre_pass1",    ";R2_{AK4}",          nbn_R,bn_R);
  h_tau21_pre_pass1 = new TH1D("h_tau21_pre_pass1", ";tau21", 20,0,1);
  h_MET_pre_pass1 = new TH1D("h_MET_pre_pass1", ";MET", j1ptbn,j1ptmn,j1ptmx);
  h_softDropMass_pre_pass1 = new TH1D("h_softDropMass_pre_pass1", "", 20,0,500);

  h_njet_pre_pass2 = new TH1D("h_njet_pre_pass2",         ";N_{jet}",                20, 0,  20);
  h_nw_pre_pass2 = new TH1D("h_nw_pre_pass2",           ";N_{W tag}",              20, 0,  20);
  h_nb_pre_pass2 = new TH1D("h_nb_pre_pass2",           ";N_{b tag}",              20, 0,  20);
  h_j2_pt_pre_pass2 = new TH1D("h_j2_pt_pre_pass2",      ";p_{T, jet2}",            j1ptbn,j1ptmn,j1ptmx);
  h_j3_pt_pre_pass2 = new TH1D("h_j3_pt_pre_pass2",      ";p_{T, jet3}",            j1ptbn,j1ptmn,j1ptmx);
  h_MR_pre_pass2 = new TH1D("h_MR_pre_pass2",   ";MR_{AK4}",        nbn_MR,bn_MR);
  h_R2_pre_pass2 = new TH1D("h_R2_pre_pass2",    ";R2_{AK4}",          nbn_R,bn_R);
  h_tau21_pre_pass2 = new TH1D("h_tau21_pre_pass2", ";tau21", 20,0,1);
  h_MET_pre_pass2 = new TH1D("h_MET_pre_pass2", ";MET", j1ptbn,j1ptmn,j1ptmx);
  h_softDropMass_pre_pass2 = new TH1D("h_softDropMass_pre_pass2", "", 20,0,500);

  h_njet_pre_pass3 = new TH1D("h_njet_pre_pass3",         ";N_{jet}",                20, 0,  20);
  h_nw_pre_pass3 = new TH1D("h_nw_pre_pass3",           ";N_{W tag}",              20, 0,  20);
  h_nb_pre_pass3 = new TH1D("h_nb_pre_pass3",           ";N_{b tag}",              20, 0,  20);
  h_j2_pt_pre_pass3 = new TH1D("h_j2_pt_pre_pass3",      ";p_{T, jet2}",            j1ptbn,j1ptmn,j1ptmx);
  h_j3_pt_pre_pass3 = new TH1D("h_j3_pt_pre_pass3",      ";p_{T, jet3}",            j1ptbn,j1ptmn,j1ptmx);
  h_MR_pre_pass3 = new TH1D("h_MR_pre_pass3",   ";MR_{AK4}",        nbn_MR,bn_MR);
  h_R2_pre_pass3 = new TH1D("h_R2_pre_pass3",    ";R2_{AK4}",          nbn_R,bn_R);
  h_tau21_pre_pass3 = new TH1D("h_tau21_pre_pass3", ";tau21", 20,0,1);
  h_MET_pre_pass3 = new TH1D("h_MET_pre_pass3", ";MET", j1ptbn,j1ptmn,j1ptmx);
  h_softDropMass_pre_pass3 = new TH1D("h_softDropMass_pre_pass3", "", 20,0,500);

  h_njet_pre_passj1pt = new TH1D("h_njet_pre_passj1pt",         ";N_{jet}",                20, 0,  20);
  h_nw_pre_passj1pt = new TH1D("h_nw_pre_passj1pt",           ";N_{W tag}",              20, 0,  20);
  h_nb_pre_passj1pt = new TH1D("h_nb_pre_passj1pt",           ";N_{b tag}",              20, 0,  20);
  h_j2_pt_pre_passj1pt = new TH1D("h_j2_pt_pre_passj1pt",      ";p_{T, jet2}",            j1ptbn,j1ptmn,j1ptmx);
  h_j3_pt_pre_passj1pt = new TH1D("h_j3_pt_pre_passj1pt",      ";p_{T, jet3}",            j1ptbn,j1ptmn,j1ptmx);
  h_MR_pre_passj1pt = new TH1D("h_MR_pre_passj1pt",   ";MR_{AK4}",        nbn_MR,bn_MR);
  h_R2_pre_passj1pt = new TH1D("h_R2_pre_passj1pt",    ";R2_{AK4}",          nbn_R,bn_R);
  h_tau21_pre_passj1pt = new TH1D("h_tau21_pre_passj1pt", ";tau21", 20,0,1);
  h_MET_pre_passj1pt = new TH1D("h_MET_pre_passj1pt", ";MET", j1ptbn,j1ptmn,j1ptmx);
  h_softDropMass_pre_passj1pt = new TH1D("h_softDropMass_pre_passj1pt", "", 20,0,500);

  h_njet_pre_passHT = new TH1D("h_njet_pre_passHT",         ";N_{jet}",                20, 0,  20);
  h_nw_pre_passHT = new TH1D("h_nw_pre_passHT",           ";N_{W tag}",              20, 0,  20);
  h_nb_pre_passHT = new TH1D("h_nb_pre_passHT",           ";N_{b tag}",              20, 0,  20);
  h_j2_pt_pre_passHT = new TH1D("h_j2_pt_pre_passHT",      ";p_{T, jet2}",            j1ptbn,j1ptmn,j1ptmx);
  h_j3_pt_pre_passHT = new TH1D("h_j3_pt_pre_passHT",      ";p_{T, jet3}",            j1ptbn,j1ptmn,j1ptmx);
  h_MR_pre_passHT = new TH1D("h_MR_pre_passHT",   ";MR_{AK4}",        nbn_MR,bn_MR);
  h_R2_pre_passHT = new TH1D("h_R2_pre_passHT",    ";R2_{AK4}",          nbn_R,bn_R);
  h_tau21_pre_passHT = new TH1D("h_tau21_pre_passHT", ";tau21", 20,0,1);
  h_MET_pre_passHT = new TH1D("h_MET_pre_passHT", ";MET", j1ptbn,j1ptmn,j1ptmx);
  h_softDropMass_pre_passHT = new TH1D("h_softDropMass_pre_passHT", "", 20,0,500);

  // HT
  h_HT_pre = new TH1D("h_HT_pre", "h_HT_pre", 16, HT_bins);
  h_HT_pre_pass1 = new TH1D("h_HT_pre_pass1", "h_HT_pre_pass1", 16, HT_bins);
  h_HT_pre_pass2 = new TH1D("h_HT_pre_pass2", "h_HT_pre_pass2", 16, HT_bins);
  h_HT_pre_pass3 = new TH1D("h_HT_pre_pass3", "h_HT_pre_pass3", 16, HT_bins);
  h_HT_pre_passj1pt = new TH1D("h_HT_pre_passj1pt", "h_HT_pre_passj1pt", 16, HT_bins);
  h_HT_pre_passHT = new TH1D("h_HT_pre_passHT", "h_HT_pre_passHT", 16, HT_bins);

  h_HT_Q = new TH1D("h_HT_Q", "h_HT_Q", 16, HT_bins);
  h_HT_Q_pass = new TH1D("h_HT_Q_pass", "h_HT_Q_pass", 16, HT_bins);
  h_HT_Q_passj1pt = new TH1D("h_HT_Q_passj1pt", "h_HT_Q_passj1pt", 16, HT_bins);
  h_HT_Q_passHT = new TH1D("h_HT_Q_passHT", "h_HT_Q_passHT", 16, HT_bins);

  h_HT_S = new TH1D("h_HT_S", "h_HT_S", 16, HT_bins);
  h_HT_S_pass = new TH1D("h_HT_S_pass", "h_HT_S_pass", 16, HT_bins);
  h_HT_S_passj1pt = new TH1D("h_HT_S_passj1pt", "h_HT_S_passj1pt", 16, HT_bins);
  h_HT_S_passHT = new TH1D("h_HT_S_passHT", "h_HT_S_passHT", 16, HT_bins);


  h_j1_pt_pre = new TH1D("h_j1_pt_pre", ";p_{T, jet1}_AK4_pre", j1ptbn, j1ptmn, j1ptmx);
  h_j1_pt_pre_pass1 = new TH1D("h_j1_pt_pre_pass1", ";p_{T, jet1}_AK4_pre_pass1", j1ptbn, j1ptmn, j1ptmx);
  h_j1_pt_pre_pass2 = new TH1D("h_j1_pt_pre_pass2", ";p_{T, jet1}_AK4_pre_pass2", j1ptbn, j1ptmn, j1ptmx);
  h_j1_pt_pre_pass3 = new TH1D("h_j1_pt_pre_pass3", ";p_{T, jet1}_AK4_pre_pass3", j1ptbn, j1ptmn, j1ptmx);
  h_j1_pt_pre_passHT = new TH1D("h_j1_pt_pre_passHT", ";p_{T, jet1}_AK4_pre_passHT", j1ptbn, j1ptmn, j1ptmx);
  h_j1_pt_pre_passj1pt = new TH1D("h_j1_pt_pre_passj1pt", ";p_{T, jet1}_AK4_pre_passj1pt", j1ptbn, j1ptmn, j1ptmx);

  h_j1_pt_Q = new TH1D("h_j1_pt_Q", ";p_{T, jet1}_AK4_Q", j1ptbn, j1ptmn, j1ptmx);
  h_j1_pt_Q_pass = new TH1D("h_j1_pt_Q_pass", ";p_{T, jet1}_AK4_Q_pass", j1ptbn, j1ptmn, j1ptmx);
  h_j1_pt_Q_passHT = new TH1D("h_j1_pt_Q_passHT", ";p_{T, jet1}_AK4_Q_passHT", j1ptbn, j1ptmn, j1ptmx);
  h_j1_pt_Q_passj1pt = new TH1D("h_j1_pt_Q_passj1pt", ";p_{T, jet1}_AK4_Q_passj1pt", j1ptbn, j1ptmn, j1ptmx);

  h_j1_pt_S = new TH1D("h_j1_pt_S", ";p_{T, jet1}_AK4_S", j1ptbn, j1ptmn, j1ptmx);
  h_j1_pt_S_pass = new TH1D("h_j1_pt_S_pass", ";p_{T, jet1}_AK4_S_pass", j1ptbn, j1ptmn, j1ptmx);
  h_j1_pt_S_passHT = new TH1D("h_j1_pt_S_passHT", ";p_{T, jet1}_AK4_S_passHT", j1ptbn, j1ptmn, j1ptmx);
  h_j1_pt_S_passj1pt = new TH1D("h_j1_pt_S_passj1pt", ";p_{T, jet1}_AK4_S_passj1pt", j1ptbn, j1ptmn, j1ptmx);


  h_HT_j1pt_pre = new TH2D("h_HT_j1pt_pre", "h_HT_j1pt_pre", nbn_HT, bn_HT, nbn_j1pt, bn_j1pt);
  h_HT_j1pt_pre_pass1 = new TH2D("h_HT_j1pt_pre_pass1", "h_HT_j1pt_pre_pass1", nbn_HT, bn_HT, nbn_j1pt, bn_j1pt);
  h_HT_j1pt_pre_pass2 = new TH2D("h_HT_j1pt_pre_pass2", "h_HT_j1pt_pre_pass2", nbn_HT, bn_HT, nbn_j1pt, bn_j1pt);
  h_HT_j1pt_pre_pass3 = new TH2D("h_HT_j1pt_pre_pass3", "h_HT_j1pt_pre_pass3", nbn_HT, bn_HT, nbn_j1pt, bn_j1pt);
  h_HT_j1pt_pre_passHT = new TH2D("h_HT_j1pt_pre_passHT", "h_HT_j1pt_pre_passHT", nbn_HT, bn_HT, nbn_j1pt, bn_j1pt);
  h_HT_j1pt_pre_passj1pt = new TH2D("h_HT_j1pt_pre_passj1pt", "h_HT_j1pt_pre_passj1pt", nbn_HT, bn_HT, nbn_j1pt, bn_j1pt);

  h_HT_j1pt_Q = new TH2D("h_HT_j1pt_Q", "h_HT_j1pt_Q", nbn_HT, bn_HT, nbn_j1pt, bn_j1pt);
  h_HT_j1pt_Q_pass = new TH2D("h_HT_j1pt_Q_pass", "h_HT_j1pt_Q_pass", nbn_HT, bn_HT, nbn_j1pt, bn_j1pt);
  h_HT_j1pt_Q_passHT = new TH2D("h_HT_j1pt_Q_passHT", "h_HT_j1pt_Q_passHT", nbn_HT, bn_HT, nbn_j1pt, bn_j1pt);
  h_HT_j1pt_Q_passj1pt = new TH2D("h_HT_j1pt_Q_passj1pt", "h_HT_j1pt_Q_passj1pt", nbn_HT, bn_HT, nbn_j1pt, bn_j1pt);

  h_HT_j1pt_S = new TH2D("h_HT_j1pt_S", "h_HT_j1pt_S", nbn_HT, bn_HT, nbn_j1pt, bn_j1pt);
  h_HT_j1pt_S_pass = new TH2D("h_HT_j1pt_S_pass", "h_HT_j1pt_S_pass", nbn_HT, bn_HT, nbn_j1pt, bn_j1pt);
  h_HT_j1pt_S_passHT = new TH2D("h_HT_j1pt_S_passHT", "h_HT_j1pt_S_passHT", nbn_HT, bn_HT, nbn_j1pt, bn_j1pt);
  h_HT_j1pt_S_passj1pt = new TH2D("h_HT_j1pt_S_passj1pt", "h_HT_j1pt_S_passj1pt", nbn_HT, bn_HT, nbn_j1pt, bn_j1pt);

  h_HT_j1pt_T = new TH2D("h_HT_j1pt_T", "h_HT_j1pt_T", nbn_HT, bn_HT, nbn_j1pt, bn_j1pt);
  h_HT_j1pt_T_pass = new TH2D("h_HT_j1pt_T_pass", "h_HT_j1pt_T_pass", nbn_HT, bn_HT, nbn_j1pt, bn_j1pt);
  h_HT_j1pt_T_passHT = new TH2D("h_HT_j1pt_T_passHT", "h_HT_j1pt_T_passHT", nbn_HT, bn_HT, nbn_j1pt, bn_j1pt);
  h_HT_j1pt_T_passj1pt = new TH2D("h_HT_j1pt_T_passj1pt", "h_HT_j1pt_T_passj1pt", nbn_HT, bn_HT, nbn_j1pt, bn_j1pt);

  h_HT_j1pt_W = new TH2D("h_HT_j1pt_W", "h_HT_j1pt_W", nbn_HT, bn_HT, nbn_j1pt, bn_j1pt);
  h_HT_j1pt_W_pass = new TH2D("h_HT_j1pt_W_pass", "h_HT_j1pt_W_pass", nbn_HT, bn_HT, nbn_j1pt, bn_j1pt);
  h_HT_j1pt_W_passHT = new TH2D("h_HT_j1pt_W_passHT", "h_HT_j1pt_W_passHT", nbn_HT, bn_HT, nbn_j1pt, bn_j1pt);
  h_HT_j1pt_W_passj1pt = new TH2D("h_HT_j1pt_W_passj1pt", "h_HT_j1pt_W_passj1pt", nbn_HT, bn_HT, nbn_j1pt, bn_j1pt);

}

//_______________________________________________________
//               Fill Histograms here
void
Analysis::fill_analysis_histos(DataStruct& data, const unsigned int& syst_index, const double& weight)
{
  if (syst_index == 0) {
    // syst_index should only be non-0 if settings.varySystematics is true
    // in case of studying systematics, one should fill a different histogram for each syst_index
    // this variable can be used to chose the correct vector element in case there is a vector of histograms
    // It makes sense, to cut on syst_index == 0, for all ordinary plots
    // syst_index == 0 always guarantees, there are no variations in any systematics
    
    // Check what common variables are available in AnalysisBase.h
    // There a good chance a lot of stuff is already calculated!
    // Especially common object selections or variables to cut on in Analysis

    //bool pass = data.hlt.AK8PFJet360_TrimMass30+data.hlt.PFHT800 == 0 ? false : true;
    bool pass1 = (data.hlt.AK8PFJet450 == 1 || data.hlt.PFHT800 == 1 || data.hlt.PFHT900 == 1);
    bool pass2 = (data.hlt.AK8PFJet450 == 1 || data.hlt.PFHT800 == 1);
    bool pass3 = (data.hlt.AK8PFJet450 == 1 || data.hlt.PFHT900 == 1);

    /*
      Weight:
      They now include trigger efficiencies for MC by default
      w is the event weight without any scale factor applied
      Because scale factors are region dependend, then
      in order to apply them, one has to use the sf_weight[region] variable instead
      eg. sf_weight['S']
     */

    // Baseline cuts 
    // Additionally, let's apply the trigger selection
    // since the weight contains the trigger scaling in MC
    // no specific region, so don't apply scale factors
    // Especially for comparison plots with Ufuk/Fatma
    // Alternatively, could apply SF of the Signal regio

    double w = weight; // No scale factor applied
    //double w = sf_weight['S']; // Scale factors applied for the Signal region


      if(nJet>=3 && nJet<5){
        h_njet_nj35->Fill(nJet,        w);
        h_njetAK8_nj35->Fill(nJetAK8,        w);
        h_nb_nj35->Fill(nMediumBTag, w);
        h_nw_nj35->Fill(nTightWTag,  w);
        h_mT_nj35->Fill(MT,w);
        h_dPhimin_nj35->Fill(minDeltaPhi, w);
        h_MR_nj35->Fill(data.evt.MR, w);
        h_R2_nj35->Fill(data.evt.R2, w);
      }
      if(nJet>5){
        h_njet_nj5->Fill(nJet,        w);
        h_njetAK8_nj5->Fill(nJetAK8,        w);
        h_nb_nj5->Fill(nMediumBTag, w);
        h_nw_nj5->Fill(nTightWTag,  w);
        h_mT_nj5->Fill(MT,w);
        h_dPhimin_nj5->Fill(minDeltaPhi, w);
        h_MR_nj5->Fill(data.evt.MR, w);
        h_R2_nj5->Fill(data.evt.R2, w);
      }
      if(nTightWTag==1){
        h_njet_nw1->Fill(nJet,        w);
        h_njetAK8_nw1->Fill(nJetAK8,        w);
        h_nb_nw1->Fill(nMediumBTag, w);
        h_nw_nw1->Fill(nTightWTag,  w);
        h_mT_nw1->Fill(MT,w);
        h_dPhimin_nw1->Fill(minDeltaPhi, w);
        h_MR_nw1->Fill(data.evt.MR, w);
        h_R2_nw1->Fill(data.evt.R2, w);
      }
      if(nTightWTag>1){
        h_njet_nw2->Fill(nJet,        w);
        h_njetAK8_nw2->Fill(nJetAK8,        w);
        h_nb_nw2->Fill(nMediumBTag, w);
        h_nw_nw2->Fill(nTightWTag,  w);
        h_mT_nw2->Fill(MT,w);
        h_dPhimin_nw2->Fill(minDeltaPhi, w);
        h_MR_nw2->Fill(data.evt.MR, w);
        h_R2_nw2->Fill(data.evt.R2, w);
      }
      if(nMediumBTag==1){
        h_njet_nb1->Fill(nJet,        w);
        h_njetAK8_nb1->Fill(nJetAK8,        w);
        h_nb_nb1->Fill(nMediumBTag, w);
        h_nw_nb1->Fill(nTightWTag,  w);
        h_mT_nb1->Fill(MT,w);
        h_dPhimin_nb1->Fill(minDeltaPhi, w);
        h_MR_nb1->Fill(data.evt.MR, w);
        h_R2_nb1->Fill(data.evt.R2, w);
      }
      if(nMediumBTag>1){
        h_njet_nb2->Fill(nJet,        w);
        h_njetAK8_nb2->Fill(nJetAK8,        w);
        h_nb_nb2->Fill(nMediumBTag, w);
        h_nw_nb2->Fill(nTightWTag,  w);
        h_mT_nb2->Fill(MT,w);
        h_dPhimin_nb2->Fill(minDeltaPhi, w);
        h_MR_nb2->Fill(data.evt.MR, w);
        h_R2_nb2->Fill(data.evt.R2, w);
      }

    if (apply_cut('S',"HLT")) {
      //h_HT_weight->Fill(AK4_Ht,1,w);
      h_njet   ->Fill(nJet,        w);
      h_nb     ->Fill(nMediumBTag, w);
      h_nw     ->Fill(nTightWTag,  w);
      h_ht_gen->Fill(data.evt.Gen_Ht,  w);  // in ntuple
      h_ht_AK4->Fill(AK4_Ht, w); // Calculated in AnalysisBase.h
      h_ht_AK8->Fill(AK8_Ht, w); // Calculated in AnalysisBase.h
    }

    w = sf_weight['Q'];
    if (apply_all_cuts('Q')) h_njetAK8_Q->Fill(nJetAK8,w);
    if (apply_all_cuts_except('Q', "3Jet")) h_njet_Q_3Jet->Fill(nJet,w);
    w = sf_weight['S'];
    if (apply_all_cuts('S')) h_njetAK8_S->Fill(nJetAK8,w);
    if (apply_all_cuts('S')) h_njet_S->Fill(nJet,w);
    if (apply_all_cuts_except('S', "3Jet")) h_njet_S_3Jet->Fill(nJet,w);
    if (apply_all_cuts_except('S', "MR_R2")) h_njet_S_MRR2->Fill(nJet,w);
    w = sf_weight['T'];
    if (apply_all_cuts('T')) h_njetAK8_T->Fill(nJetAK8,w);
    if (apply_all_cuts_except('T', "3Jet")) h_njet_T_3Jet->Fill(nJet,w);
    w = sf_weight['W'];
    if (apply_all_cuts('W')) h_njetAK8_W->Fill(nJetAK8,w);
    if (apply_all_cuts_except('W', "3Jet")) h_njet_W_3Jet->Fill(nJet,w);


    // W enriched region
    w = sf_weight['W'];
    if (apply_all_cuts('W')) {
      h_ht_AK4_W->Fill(AK4_Ht, w);
      h_ht_AK8_W->Fill(AK8_Ht, w);
      h_jet1_pt_W->Fill(data.jetsAK4.Pt[iJet[0]], w);
      h_jet2_pt_W->Fill(data.jetsAK4.Pt[iJet[1]], w);
      h_jet3_pt_W->Fill(data.jetsAK4.Pt[iJet[2]], w);
      h_MR_W->Fill(data.evt.MR, w);
      h_MTR_W->Fill(data.evt.MTR, w);
      h_R_W->Fill(data.evt.R, w);
      h_R2_W->Fill(data.evt.R2, w);
      h_tau21_W->Fill(tau21.at(0),w);
      h_MET_W->Fill(data.met.Pt.at(0),w);

      h_HT_j1pt_W->Fill(AK4_Ht,data.jetsAK8.Pt[iJet[0]],w);
    }
    if (apply_all_cuts_except('W', "HLT")) {
      if(data.hlt.PFHT800) h_HT_j1pt_W_passHT->Fill(AK4_Ht,data.jetsAK8.Pt[iJet[0]],w);
      if(data.hlt.AK8PFJet360_TrimMass30) h_HT_j1pt_W_passj1pt->Fill(AK4_Ht,data.jetsAK8.Pt[iJet[0]],w);
      if(pass1) h_HT_j1pt_W_pass->Fill(AK4_Ht,data.jetsAK8.Pt[iJet[0]],w);
    }

    // top enriched region
    w = sf_weight['T'];
    if (apply_all_cuts('T')) {
      h_ht_AK4_T->Fill(AK4_Ht, w);
      h_ht_AK8_T->Fill(AK8_Ht, w);
      h_jet1_pt_T->Fill(data.jetsAK4.Pt[iJet[0]], w);
      h_jet2_pt_T->Fill(data.jetsAK4.Pt[iJet[1]], w);
      h_jet3_pt_T->Fill(data.jetsAK4.Pt[iJet[2]], w);
      h_MR_T->Fill(data.evt.MR, w);
      h_MTR_T->Fill(data.evt.MTR, w);
      h_R_T->Fill(data.evt.R, w);
      h_R2_T->Fill(data.evt.R2, w);
      h_tau21_T->Fill(tau21.at(0),w);
      h_MET_T->Fill(data.met.Pt.at(0),w);

      h_HT_j1pt_T->Fill(AK4_Ht,data.jetsAK8.Pt[iJet[0]],w);
    }
    
    if (apply_all_cuts_except('T', "HLT")) {
      if(data.hlt.PFHT800) h_HT_j1pt_T_passHT->Fill(AK4_Ht,data.jetsAK8.Pt[iJet[0]],w);
      if(data.hlt.AK8PFJet360_TrimMass30) h_HT_j1pt_T_passj1pt->Fill(AK4_Ht,data.jetsAK8.Pt[iJet[0]],w);
      if(pass1) h_HT_j1pt_T_pass->Fill(AK4_Ht,data.jetsAK8.Pt[iJet[0]],w);
    }

    // QCD enriched region
    w = sf_weight['Q'];
    if (apply_all_cuts('Q')) {
      h_ht_AK4_Q->Fill(AK4_Ht, w);
      h_ht_AK8_Q->Fill(AK8_Ht, w);
      h_jet1_pt_Q->Fill(data.jetsAK4.Pt[iJet[0]], w);
      h_jet2_pt_Q->Fill(data.jetsAK4.Pt[iJet[1]], w);
      h_jet3_pt_Q->Fill(data.jetsAK4.Pt[iJet[2]], w);
      h_MR_Q->Fill(data.evt.MR, w);
      h_MTR_Q->Fill(data.evt.MTR, w);
      h_R_Q->Fill(data.evt.R, w);
      h_R2_Q->Fill(data.evt.R2, w);
      h_tau21_Q->Fill(tau21.at(0),w);
      h_MET_Q->Fill(data.met.Pt.at(0),w);

      h_HT_Q->Fill(AK4_Ht,w);
      h_j1_pt_Q->Fill(data.jetsAK8.Pt[iJet[0]],w);
      h_HT_j1pt_Q->Fill(AK4_Ht,data.jetsAK8.Pt[iJet[0]],w);
    }

    if (apply_all_cuts_except('Q', "HLT")) {
      if(data.hlt.PFHT800){
	h_HT_Q_passHT->Fill(AK4_Ht,w);
	h_j1_pt_Q_passHT->Fill(data.jetsAK8.Pt[iJet[0]],w);
	h_HT_j1pt_Q_passHT->Fill(AK4_Ht,data.jetsAK8.Pt[iJet[0]],w);
      }
      if(data.hlt.AK8PFJet360_TrimMass30){
	h_HT_Q_passj1pt->Fill(AK4_Ht,w);
	h_j1_pt_Q_passj1pt->Fill(data.jetsAK8.Pt[iJet[0]],w);
	h_HT_j1pt_Q_passj1pt->Fill(AK4_Ht,data.jetsAK8.Pt[iJet[0]],w);
      }
      if(pass1){
	h_HT_Q_pass->Fill(AK4_Ht,w);
	h_j1_pt_Q_pass->Fill(data.jetsAK8.Pt[iJet[0]],w);
	h_HT_j1pt_Q_pass->Fill(AK4_Ht,data.jetsAK8.Pt[iJet[0]],w);
      }
    }

    // Signal region
    w = sf_weight['S'];
    //if (apply_all_cuts_except('S', "HLT")) {
    if (apply_all_cuts('S')) {
      h_ht_AK4_S->Fill(AK4_Ht, w);
      h_ht_AK8_S->Fill(AK8_Ht, w);
      h_jet1_pt_S->Fill(data.jetsAK4.Pt[iJet[0]], w);
      h_jet2_pt_S->Fill(data.jetsAK4.Pt[iJet[1]], w);
      h_jet3_pt_S->Fill(data.jetsAK4.Pt[iJet[2]], w);
      h_MR_S->Fill(data.evt.MR, w);
      h_R_S->Fill(data.evt.R, w);
      h_MTR_S->Fill(data.evt.MTR, w);
      h_R2_S->Fill(data.evt.R2, w);
      h_tau21_S->Fill(tau21.at(0),w);
      h_MET_S->Fill(data.met.Pt.at(0),w);

      if(nJet>=3 && nJet<5){
        h_njet_S_nj35->Fill(nJet,        w);
        h_njetAK8_S_nj35->Fill(nJetAK8,        w);
        h_nb_S_nj35->Fill(nMediumBTag, w);
        h_nw_S_nj35->Fill(nTightWTag,  w);
        h_mT_S_nj35->Fill(MT,w);
        h_dPhimin_S_nj35->Fill(minDeltaPhi, w);
        h_MR_S_nj35->Fill(data.evt.MR, w);
        h_R2_S_nj35->Fill(data.evt.R2, w);
      }
      if(nJet>5){
        h_njet_S_nj5->Fill(nJet,        w);
        h_njetAK8_S_nj5->Fill(nJetAK8,        w);
        h_nb_S_nj5->Fill(nMediumBTag, w);
        h_nw_S_nj5->Fill(nTightWTag,  w);
        h_mT_S_nj5->Fill(MT,w);
        h_dPhimin_S_nj5->Fill(minDeltaPhi, w);
        h_MR_S_nj5->Fill(data.evt.MR, w);
        h_R2_S_nj5->Fill(data.evt.R2, w);
      }
      if(nTightWTag==1){
        h_njet_S_nw1->Fill(nJet,        w);
        h_njetAK8_S_nw1->Fill(nJetAK8,        w);
        h_nb_S_nw1->Fill(nMediumBTag, w);
        h_nw_S_nw1->Fill(nTightWTag,  w);
        h_mT_S_nw1->Fill(MT,w);
        h_dPhimin_S_nw1->Fill(minDeltaPhi, w);
        h_MR_S_nw1->Fill(data.evt.MR, w);
        h_R2_S_nw1->Fill(data.evt.R2, w);
      }
      if(nTightWTag>1){
        h_njet_S_nw2->Fill(nJet,        w);
        h_njetAK8_S_nw2->Fill(nJetAK8,        w);
        h_nb_S_nw2->Fill(nMediumBTag, w);
        h_nw_S_nw2->Fill(nTightWTag,  w);
        h_mT_S_nw2->Fill(MT,w);
        h_dPhimin_S_nw2->Fill(minDeltaPhi, w);
        h_MR_S_nw2->Fill(data.evt.MR, w);
        h_R2_S_nw2->Fill(data.evt.R2, w);
      }
      if(nMediumBTag==1){
        h_njet_S_nb1->Fill(nJet,        w);
        h_njetAK8_S_nb1->Fill(nJetAK8,        w);
        h_nb_S_nb1->Fill(nMediumBTag, w);
        h_nw_S_nb1->Fill(nTightWTag,  w);
        h_mT_S_nb1->Fill(MT,w);
        h_dPhimin_S_nb1->Fill(minDeltaPhi, w);
        h_MR_S_nb1->Fill(data.evt.MR, w);
        h_R2_S_nb1->Fill(data.evt.R2, w);
      }
      if(nMediumBTag>1){
        h_njet_S_nb2->Fill(nJet,        w);
        h_njetAK8_S_nb2->Fill(nJetAK8,        w);
        h_nb_S_nb2->Fill(nMediumBTag, w);
        h_nw_S_nb2->Fill(nTightWTag,  w);
        h_mT_S_nb2->Fill(MT,w);
        h_dPhimin_S_nb2->Fill(minDeltaPhi, w);
        h_MR_S_nb2->Fill(data.evt.MR, w);
        h_R2_S_nb2->Fill(data.evt.R2, w);
      }


      h_GluinoLSPMass->Fill(data.evt.SUSY_Gluino_Mass,data.evt.SUSY_LSP_Mass,w);
      h_R2_MR->Fill(data.evt.MR, data.evt.R2, w);
      h_softDropMass->Fill(softDropMassW.at(0),w);
      h_StopMass->Fill(data.evt.SUSY_Stop_Mass,w);
      h_GluinoMass->Fill(data.evt.SUSY_Gluino_Mass,w);
      h_LSPMass->Fill(data.evt.SUSY_LSP_Mass,w);

      h_HT_S->Fill(AK4_Ht,w);
      h_j1_pt_S->Fill(data.jetsAK8.Pt[iJet[0]],w);
      h_HT_j1pt_S->Fill(AK4_Ht,data.jetsAK8.Pt[iJet[0]],w);
    }

    if (apply_all_cuts_except('S', "HLT")) { 
      if(data.hlt.PFHT800){
        h_HT_S_passHT->Fill(AK4_Ht,w);
        h_j1_pt_S_passHT->Fill(data.jetsAK8.Pt[iJet[0]],w);
        h_HT_j1pt_S_passHT->Fill(AK4_Ht,data.jetsAK8.Pt[iJet[0]],w);
      }
      if(data.hlt.AK8PFJet360_TrimMass30){
	h_HT_S_passj1pt->Fill(AK4_Ht,w);
	h_j1_pt_S_passj1pt->Fill(data.jetsAK8.Pt[iJet[0]],w);
	h_HT_j1pt_S_passj1pt->Fill(AK4_Ht,data.jetsAK8.Pt[iJet[0]],w);
      }
      if(pass1){
	h_HT_S_pass->Fill(AK4_Ht,w);
	h_j1_pt_S_pass->Fill(data.jetsAK8.Pt[iJet[0]],w);
	h_HT_j1pt_S_pass->Fill(AK4_Ht,data.jetsAK8.Pt[iJet[0]],w);
      }
    }

    // Trigger efficiencies
    // No weighting
 
    // I guess these histots are for data only (trigger efficiencies)
    // One could just use the normal weight  for that ( = 1)
    // Since MC already has trigger efficiency weight applied already
    // one could use simply 1 as the weight there also
    // N-1 weights are not currently supported

    //w = isData ? 1 : sf_weight['S'];
    w = 1;

    h_njet_pre->Fill(nJet,        w);
    h_nb_pre->Fill(nMediumBTag, w);
    h_nw_pre->Fill(nTightWTag,  w);
    h_j2_pt_pre->Fill(data.jetsAK4.Pt[iJet[1]], w);
    h_j3_pt_pre->Fill(data.jetsAK4.Pt[iJet[2]], w);
    h_MR_pre->Fill(data.evt.MR, w);
    h_R2_pre->Fill(data.evt.R2, w);
    h_tau21_pre->Fill(tau21.at(0),w);
    h_MET_pre->Fill(data.met.Pt.at(0),w);
    h_softDropMass_pre->Fill(softDropMassW.at(0),w);
    h_HT_pre->Fill(AK4_Ht,w);
    h_j1_pt_pre->Fill(data.jetsAK4.Pt[iJet[0]],w);
    h_HT_j1pt_pre->Fill(AK4_Ht,data.jetsAK8.Pt[iJet[0]],w);

    if(data.hlt.PFHT800){
      h_njet_pre_passHT->Fill(nJet,        w);
      h_nb_pre_passHT->Fill(nMediumBTag, w);
      h_nw_pre_passHT->Fill(nTightWTag,  w);
      h_j2_pt_pre_passHT->Fill(data.jetsAK4.Pt[iJet[1]], w);
      h_j3_pt_pre_passHT->Fill(data.jetsAK4.Pt[iJet[2]], w);
      h_MR_pre_passHT->Fill(data.evt.MR, w);
      h_R2_pre_passHT->Fill(data.evt.R2, w);
      h_tau21_pre_passHT->Fill(tau21.at(0),w);
      h_MET_pre_passHT->Fill(data.met.Pt.at(0),w);
      h_softDropMass_pre_passHT->Fill(softDropMassW.at(0),w);
      h_HT_pre_passHT->Fill(AK4_Ht,w);
      h_j1_pt_pre_passHT->Fill(data.jetsAK4.Pt[iJet[0]],w);
      h_HT_j1pt_pre_passHT->Fill(AK4_Ht,data.jetsAK8.Pt[iJet[0]],w);
    }
    if(data.hlt.AK8PFJet360_TrimMass30){
      h_njet_pre_passj1pt->Fill(nJet,        w);
      h_nb_pre_passj1pt->Fill(nMediumBTag, w);
      h_nw_pre_passj1pt->Fill(nTightWTag,  w);
      h_j2_pt_pre_passj1pt->Fill(data.jetsAK4.Pt[iJet[1]], w);
      h_j3_pt_pre_passj1pt->Fill(data.jetsAK4.Pt[iJet[2]], w);
      h_MR_pre_passj1pt->Fill(data.evt.MR, w);
      h_R2_pre_passj1pt->Fill(data.evt.R2, w);
      h_tau21_pre_passj1pt->Fill(tau21.at(0),w);
      h_MET_pre_passj1pt->Fill(data.met.Pt.at(0),w);
      h_softDropMass_pre_passj1pt->Fill(softDropMassW.at(0),w);
      h_HT_pre_passj1pt->Fill(AK4_Ht,w);
      h_j1_pt_pre_passj1pt->Fill(data.jetsAK4.Pt[iJet[0]],w);
      h_HT_j1pt_pre_passj1pt->Fill(AK4_Ht,data.jetsAK8.Pt[iJet[0]],w);
    }
    if(pass1){
      h_njet_pre_pass1->Fill(nJet,        w);
      h_nb_pre_pass1->Fill(nMediumBTag, w);
      h_nw_pre_pass1->Fill(nTightWTag,  w);
      h_j2_pt_pre_pass1->Fill(data.jetsAK4.Pt[iJet[1]], w);
      h_j3_pt_pre_pass1->Fill(data.jetsAK4.Pt[iJet[2]], w);
      h_MR_pre_pass1->Fill(data.evt.MR, w);
      h_R2_pre_pass1->Fill(data.evt.R2, w);
      h_tau21_pre_pass1->Fill(tau21.at(0),w);
      h_MET_pre_pass1->Fill(data.met.Pt.at(0),w);
      h_softDropMass_pre_pass1->Fill(softDropMassW.at(0),w);
      h_HT_pre_pass1->Fill(AK4_Ht,w);
      h_j1_pt_pre_pass1->Fill(data.jetsAK4.Pt[iJet[0]],w);
      h_HT_j1pt_pre_pass1->Fill(AK4_Ht,data.jetsAK8.Pt[iJet[0]],w);
    }
    if(pass2){
      h_njet_pre_pass2->Fill(nJet,        w);
      h_nb_pre_pass2->Fill(nMediumBTag, w);
      h_nw_pre_pass2->Fill(nTightWTag,  w);
      h_j2_pt_pre_pass2->Fill(data.jetsAK4.Pt[iJet[1]], w);
      h_j3_pt_pre_pass2->Fill(data.jetsAK4.Pt[iJet[2]], w);
      h_MR_pre_pass2->Fill(data.evt.MR, w);
      h_R2_pre_pass2->Fill(data.evt.R2, w);
      h_tau21_pre_pass2->Fill(tau21.at(0),w);
      h_MET_pre_pass2->Fill(data.met.Pt.at(0),w);
      h_softDropMass_pre_pass2->Fill(softDropMassW.at(0),w);
      h_HT_pre_pass2->Fill(AK4_Ht,w);
      h_j1_pt_pre_pass2->Fill(data.jetsAK4.Pt[iJet[0]],w);
      h_HT_j1pt_pre_pass2->Fill(AK4_Ht,data.jetsAK8.Pt[iJet[0]],w);
    }
    if(pass3){
      h_njet_pre_pass3->Fill(nJet,        w);
      h_nb_pre_pass3->Fill(nMediumBTag, w);
      h_nw_pre_pass3->Fill(nTightWTag,  w);
      h_j2_pt_pre_pass3->Fill(data.jetsAK4.Pt[iJet[1]], w);
      h_j3_pt_pre_pass3->Fill(data.jetsAK4.Pt[iJet[2]], w);
      h_MR_pre_pass3->Fill(data.evt.MR, w);
      h_R2_pre_pass3->Fill(data.evt.R2, w);
      h_tau21_pre_pass3->Fill(tau21.at(0),w);
      h_MET_pre_pass3->Fill(data.met.Pt.at(0),w);
      h_softDropMass_pre_pass3->Fill(softDropMassW.at(0),w);
      h_HT_pre_pass3->Fill(AK4_Ht,w);
      h_j1_pt_pre_pass3->Fill(data.jetsAK4.Pt[iJet[0]],w);
      h_HT_j1pt_pre_pass3->Fill(AK4_Ht,data.jetsAK8.Pt[iJet[0]],w);
    }

    /*
      Other examples to use analysis_cuts object

      if (apply_cut('S',"1W"))                          --> 1 Cut from S region
      if (apply_cut('W',"1Wpre"))                       --> 1 Cut from W region
      if (apply_all_cuts('T'))                          --> All cuts in T region
      if (apply_all_cuts_except('Q', "mDPhi<0.25"))     --> N-1 cut
      if (apply_all_cuts_except('S', {"0Ele", "0Mu" })) --> S without Lep veto

      But be aware: Whatever is defined in the baseline_cuts will apply to all histograms
      Also if you use skimmed ntuples (very likely) then those cuts are already applied
      This is because unskimmed ntuple is 4.3 TB in size, and we cannot have them on EOS
    */
  }
  
/*
    h_njet_pre[syst_index]->Fill(nJet,        w);
    h_nb_pre[syst_index]->Fill(nMediumBTag, w);
    h_nw_pre[syst_index]->Fill(nTightWTag,  w);
    h_j1_pt_pre[syst_index]->Fill(data.jetsAK8.Pt[iJet[0]],w);
    h_j2_pt_pre[syst_index]->Fill(data.jetsAK4.Pt[iJet[1]], w);
    h_j3_pt_pre[syst_index]->Fill(data.jetsAK4.Pt[iJet[2]], w);
    h_MR_pre[syst_index]->Fill(data.evt.MR, w);
    h_R2_pre[syst_index]->Fill(data.evt.R2, w);
    h_tau21_pre[syst_index]->Fill(tau21.at(0),w);
    h_MET_pre[syst_index]->Fill(data.met.Pt.at(0),w);
    h_softDropMass_pre[syst_index]->Fill(softDropMassW.at(0),w);
    h_HT_pre[syst_index]->Fill(AK4_Ht,w);
    h_HT_j1pt_pre[syst_index]->Fill(AK4_Ht,data.jetsAK8.Pt[iJet[0]],w);

    if(pass){
      h_njet_pre_pass[syst_index]->Fill(nJet,        w);
      h_nb_pre_pass[syst_index]->Fill(nMediumBTag, w);
      h_nw_pre_pass[syst_index]->Fill(nTightWTag,  w);
      h_j1 pt_pre_pass[syst_index]->Fill(data.jetsAK8.Pt[iJet[0]],w);
      h_j2_pt_pre_pass[syst_index]->Fill(data.jetsAK4.Pt[iJet[1]], w);
      h_j3_pt_pre_pass[syst_index]->Fill(data.jetsAK4.Pt[iJet[2]], w);
      h_MR_pre_pass[syst_index]->Fill(data.evt.MR, w);
      h_R2_pre_pass[syst_index]->Fill(data.evt.R2, w);
      h_tau21_pre_pass[syst_index]->Fill(tau21.at(0),w);
      h_MET_pre_pass[syst_index]->Fill(data.met.Pt.at(0),w);
      h_softDropMass_pre_pass[syst_index]->Fill(softDropMassW.at(0),w);
      h_HT_pre_pass[syst_index]->Fill(AK4_Ht,w);
      h_HT_j1pt_pre_pass[syst_index]->Fill(AK4_Ht,data.jetsAK8.Pt[iJet[0]],w);
    }
*/
  // Vary systematics and save each variation into a different historgam
  // Switch on settings.varySystematics to be effective
  //if (apply_all_cuts('S')) vh_jet1_pt[syst_index]->Fill(data.jetsAK4.Pt[iJet[0]], w);
}

// Methods used by SmartHistos (Plotter)
// Can leave them empty
void
Analysis::define_histo_options(const double& w, const DataStruct& d, const unsigned int& syst_nSyst,
			       const unsigned int& syst_index, bool runOnSkim=false)
{
}

void
Analysis::load_analysis_histos(std::string inputfile)
{
}

void
Analysis::save_analysis_histos(bool draw=0)
{
}

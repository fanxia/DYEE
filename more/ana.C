void ana(){

  gROOT->Reset();
  gROOT->LoadMacro("EventTree.C+");

  TChain chain("ggNtuplizer/EventTree");
 chain->Add("/eos/uscms/store/user/areinsvo/DYToEE_M-50_Tune4C_13TeV-pythia8/Phys14_ggNtuples_DYToEE/150126_213933/0000/ggtree_mc_*.root");

 std::cout<<"Total number of entries in chain"<<chain->GetEntries()<<std::endl;


chain.SetBranchStatus("*", 1);
if(chain.LoadTree(0) != 0) {
cerr << "Error with input chain. Do the files exist?" << endl;
return;
}

 EventTree * t=new EventTree(chain);


 TStopwatch ts;
 ts.Start();

 t->Loop();

 ts.Stop();

std::cout << "RealTime : " << ts.RealTime()/60.0 << " minutes" << std::endl;
std::cout << "CPUTime : " << ts.CpuTime()/60.0 << " minutes" << std::endl;

}


#define EventTree_cxx
#include "EventTree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void EventTree::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L EventTree.C
//      Root > EventTree t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   TCanvas *c=new TCanvas();
   c->Divide(2,2);
   TH1F *hist=new TH1F("h","pfMET",200,0,100);
   TH1F *hist0=new TH1F("h0","pfMET nEle=0",200,0,100);
   TH1F *hist1=new TH1F("h1","pfMET nEle=1",200,0,100);
   TH1F *hist2=new TH1F("h2","pfMET nEle=2",200,0,100);


   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      hist->Fill(pfMET);
      if(nEle==0){hist0->Fill(pfMET);}
      if(nEle==1){hist1->Fill(pfMET);}
      if(nEle==2){hist2->Fill(pfMET);}
   }

   c->cd(1)->SetTitle("pad1");
   hist->Draw("elp");
   hist->Fit("gaus");
   c->cd(2);
   //hist->Draw();
    hist0->SetFillColor(2);
    hist0->SetTitle("pfMET;nEle0");
hist0->Draw();
 c->cd(3);
 //hist->Draw();
hist1->Draw();
 c->cd(4);
 //hist->Draw();
hist2->Draw();

}

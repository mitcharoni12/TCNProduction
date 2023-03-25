#include "TCanvas.h"
#include "TH1D.h"
#include "TFile.h"
#include "TTree.h"
#include "TLeaf.h"

using namespace std;

void rootAnalysis();

int main()
{
    rootAnalysis();
    return 0;
}

void rootAnalysis()
{
    TFile* myFile = new TFile("/home/jamal/TCNProduction/output.root");

    TTree* myTree;
    myFile->GetObject("Energy", myTree);

    Double_t energy;
    Double_t prevEnergy;
    Int_t detector;
    Int_t prevDetector = 2;

    TH1D* energyHisto = new TH1D("energyHisto", "energyHisto", 1000, 0, 10000);

    myTree->SetBranchAddress("Energies", &energy);
    myTree->SetBranchAddress("detectorNo", &detector);

    Int_t entries = myTree->GetEntries();

    for(int i = 0; i < entries; i++)
    {
        myTree->GetEntry(i);

        if(detector == prevDetector && prevEnergy > 4.0)
        {
            energyHisto->Fill(prevEnergy);
        }
        prevEnergy = energy;
        prevDetector = detector;
    }

    energyHisto->Draw();

}
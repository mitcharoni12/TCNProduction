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
    TFile* myFile = new TFile("output.root");

    TTree* myTree;
    myFile->GetObject("Energy", myTree);
    myTree->Draw("Energies", "Energies < 1", "colz");
}
#include "TCanvas.h"
#include "TH1D.h"
#include "TFile.h"
#include "TTree.h"
#include "TLeaf.h"

using namespace std;

void rootAnalysis();
Int_t classifyParticle(Double_t restEnergy, Double_t charge);

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

    Double_t kineticEnergy;
    Double_t totalEnergy;
    Double_t charge;
    Double_t restEnergy;
    Int_t detector;

    TH1D* energyHisto = new TH1D("energyHisto", "energyHisto", 100000, 0, 10000);

    myTree->SetBranchAddress("KineticEnergy", &kineticEnergy);
    myTree->SetBranchAddress("TotalEnergy", &totalEnergy);
    myTree->SetBranchAddress("Charge", &charge);
    myTree->SetBranchAddress("RestEnergy", &restEnergy);
    myTree->SetBranchAddress("detectorNo", &detector);

    Int_t entries = myTree->GetEntries();
    Int_t particle, numNeutron=0, numProton=0, numElectron=0, numOther=0;
    Int_t aluminumProduction = 0;


    bool haveProton = 0, haveNeutron1 = 0, haveNeutron2 = 0, haveElectron = 0, haveOther = 0;

    for(int i = 0; i < entries; i++)
    {
        myTree->GetEntry(i);
        particle = classifyParticle(restEnergy, charge);
        switch(particle){
            case 0:
                numNeutron++;
                break;
                
            case 1:
                numProton++;
                break;
                
            case 2:
                numElectron++;
                break;
                
            case 3:
                numOther++;
                break;
            }

        if(detector == 1)
        {
            //If we have detected 2 neutrons, a proton, and an electron without any other particles we have that a 26Al was produced
            if(haveNeutron1 && haveNeutron2 && haveElectron && haveProton && !haveOther)
            {
                aluminumProduction++;
            }
            haveProton = false;
            haveNeutron1 = false;
            haveNeutron2 = false;
            haveElectron = false;
            haveOther = false;
        }

        if(detector == 2)
        {
            switch(particle){
                //detected a neutron
                case 0:
                    if(!haveNeutron1)
                    {
                        haveNeutron1 = true;
                        break;
                    }
                    haveNeutron2 = true;
                    break;
                
                //detected a proton
                case 1:
                    haveProton = true;
                    break;
                
                //detected a electron
                case 2:
                    haveElectron = true;
                    break;
                
                //detected another particle which is not a neutron, proton, or electron
                case 3:
                    haveOther = true;
                    break;
            }
        }
    }

    cout << "Aluminum Production: " << aluminumProduction << endl;
    cout << "Neutrons Detected: " << numNeutron << endl;
    cout << "Protons Detected: " << numProton << endl;
    cout << "Electrons Detected: " << numElectron << endl;
    cout << "Other particles Detected: " << numOther << endl;

    energyHisto->Draw();
}


//0 = neutron, 1 = proton, 2 = electron, 3 = other
Int_t classifyParticle(Double_t restEnergy, Double_t charge)
{   
    //if neutron
    if(restEnergy > 939.56 && restEnergy < 939.57 && charge < 0.01 && charge > -0.01)
    {
        return 0;
    }

    //if proton
    if(restEnergy > 938.26 && restEnergy < 938.28 && charge < 1.01 && charge > 0.99)
    {
        return 1;
    }

    //if electron
    if(restEnergy > 0.510 && restEnergy < 0.512 && charge < -0.99 && charge > -1.01)
    {
        return 2;
    }
    
    return 3;
}
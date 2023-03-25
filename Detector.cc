#include "Detector.hh"

Detector::Detector(G4String detectorName) : G4VSensitiveDetector(detectorName)
{

}

Detector::~Detector()
{

}

G4bool Detector::ProcessHits(G4Step *step, G4TouchableHistory *history)
{
    G4Track* track = step->GetTrack();

    G4StepPoint *preStepPoint = step->GetPreStepPoint();
    G4StepPoint *postStepPoint = step->GetPostStepPoint();

    G4double energyEnter = preStepPoint->GetKineticEnergy();
    G4double energyLeave = postStepPoint->GetKineticEnergy();
    G4double interaction = energyEnter - energyLeave;
    G4AnalysisManager *man = G4AnalysisManager::Instance();

    if(interaction < 0.0001 && interaction > -0.0001)
    {
        //G4cout << "No Interaction" << G4endl;
        
    }else{
        //G4cout << "Interaction" << G4endl;
        //G4cout << "Enter Energy: " << energyEnter << G4endl;
        man->FillNtupleDColumn(0, energyEnter);
        man->AddNtupleRow(0);
    }

    //G4cout << "Leave Energy: " << energyLeave << G4endl << G4endl;

    return true;
}
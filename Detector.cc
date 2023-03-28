#include "Detector.hh"

Detector::Detector(G4String detectorName) : G4VSensitiveDetector(detectorName)
{

}

Detector::~Detector()
{

}

G4bool Detector::ProcessHits(G4Step *step, G4TouchableHistory *history)
{
    //G4Track* track = step->GetTrack();

    G4StepPoint *preStepPoint = step->GetPreStepPoint();
    //G4StepPoint *postStepPoint = step->GetPostStepPoint();

    G4double kineticEnergy = preStepPoint->GetKineticEnergy();
    G4double totalEnergy = preStepPoint->GetTotalEnergy();
    G4double charge = preStepPoint->GetCharge();
    G4double restEnergy = totalEnergy - kineticEnergy;
    G4AnalysisManager *man = G4AnalysisManager::Instance();

    const G4VTouchable *touchable = step->GetPreStepPoint()->GetTouchable();
    G4int copyNo = touchable->GetCopyNumber();

    man->FillNtupleDColumn(0, kineticEnergy);
    man->FillNtupleDColumn(1, totalEnergy);
    man->FillNtupleDColumn(2, charge);
    man->FillNtupleDColumn(3, restEnergy);
    man->FillNtupleIColumn(4, copyNo);
    man->AddNtupleRow(0);


    return true;
}
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
    G4AnalysisManager *man = G4AnalysisManager::Instance();

    const G4VTouchable *touchable = step->GetPreStepPoint()->GetTouchable();
    G4int copyNo = touchable->GetCopyNumber();

    man->FillNtupleDColumn(0, energyEnter);
    man->FillNtupleIColumn(1, copyNo);
    man->AddNtupleRow(0);


    return true;
}
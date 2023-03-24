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

    G4double energy = preStepPoint->GetKineticEnergy();

    G4cout << "Neutron Energy: " << energy << G4endl;

    return true;
}
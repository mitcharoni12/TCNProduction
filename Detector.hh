#ifndef Detector_H
#define Detector_H

#include "G4VSensitiveDetector.hh"

class Detector : public G4VSensitiveDetector
{
public:
    Detector(G4String);
    ~Detector();
private:
    virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);
};

#endif

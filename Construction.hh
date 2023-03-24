#ifndef Construction_H
#define Construction_H

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4SystemOfUnits.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4NistManager.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4ThreeVector.hh"
#include "Detector.hh"

class Construction : public G4VUserDetectorConstruction
{
public:
    Construction();
    ~Construction();
    virtual G4VPhysicalVolume* Construct();
private:
    G4LogicalVolume *logicDetector;
    virtual void ConstructSDandField();
};

#endif
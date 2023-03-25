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
#include "G4Sphere.hh"

class Construction : public G4VUserDetectorConstruction
{
public:
    Construction();
    ~Construction();
    virtual G4VPhysicalVolume* Construct();
private:
    G4LogicalVolume *logicDetector;
    G4LogicalVolume *logicDetector2;

    virtual void ConstructSDandField();
};

#endif
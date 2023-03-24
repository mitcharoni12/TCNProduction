#include "Construction.hh"

Construction::Construction()
{

}

Construction::~Construction()
{

}

G4VPhysicalVolume* Construction::Construct()
{
    //Material definitions
    G4NistManager* man = G4NistManager::Instance();
    G4Material* lightAir = man->FindOrBuildMaterial("G4_AIR");
    G4Material* quartz = man->FindOrBuildMaterial("G4_SILICON_DIOXIDE");
    lightAir = new G4Material("lightAir", 0.01*g/m3, lightAir);

    //Mother Volume Definition
    G4Box* SPBox = new G4Box("SPFlow", 1.0*m, 1.0*m, 1.0*m);
    G4LogicalVolume* logicSpFlow = new G4LogicalVolume(SPBox, lightAir, "SPFlow");
    G4VPhysicalVolume* SPFlow = new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, 0.0), logicSpFlow, "logicSpFlow", 0, false, 0, true);

    //Quartz target defintion
    G4Box* quartzBox = new G4Box("quartzBox", 0.005*m, 0.005*m, 0.005*m);
    G4LogicalVolume* logicQuartz = new G4LogicalVolume(quartzBox, quartz, "quartzBox");
    G4VPhysicalVolume* quartzTarget = new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, 0.5*m), logicQuartz, "logicQuartz", logicSpFlow, false, 0, true);

    //Temp detector
    G4Box* tempDetector = new G4Box("tempDetector", 0.005*m, 0.005*m, 0.005*m);
    logicDetector = new G4LogicalVolume(tempDetector, lightAir, "tempDetector");
    G4VPhysicalVolume* detector = new G4PVPlacement(0, G4ThreeVector(0.1*m, 0.1*m, 0.5*m), logicDetector, "logicDetector", logicSpFlow, false, 0, true);

    return SPFlow;
}

void Construction::ConstructSDandField()
{
    Detector *testDetector = new Detector("testingDetector");
    logicDetector->SetSensitiveDetector(testDetector);
}
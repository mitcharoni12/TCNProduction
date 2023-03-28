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
    G4VPhysicalVolume* quartzTarget = new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, 0.9*m), logicQuartz, "logicQuartz", logicSpFlow, false, 0, true);

    //Incident neutron detector
    G4Box* incidentNeutronDetector = new G4Box("incidentNeutronDetector", 0.005*m, 0.005*m, 0.001*cm);
    logicDetector = new G4LogicalVolume(incidentNeutronDetector, lightAir, "incidentNeutronDetector");
    G4VPhysicalVolume* detector = new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, 0.91*m), logicDetector, "logicDetector", logicSpFlow, false, 1, true);

    //Sphereical detector
    G4Sphere* detectorSphere = new G4Sphere("detectorSphere", 0.95*m, 0.96*m, 0, 360*deg, 0, 180*deg);
    logicSphere = new G4LogicalVolume(detectorSphere, lightAir, "detectorSphere");
    G4VPhysicalVolume* sphereDetector = new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, 0.0), logicSphere, "sphereDetector", logicSpFlow, false, 2, true);

    //Temp detector 2
    //G4Box* tempDetector2 = new G4Box("tempDetector2", 0.005*m, 0.005*m, 0.005*m);
    //logicDetector2 = new G4LogicalVolume(tempDetector2, lightAir, "tempDetector2");
    //G4VPhysicalVolume* detector2 = new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, -0.9*m), logicDetector2, "logicDetector2", logicSpFlow, false, 3, true);

    return SPFlow;
}

void Construction::ConstructSDandField()
{
    Detector *testDetector = new Detector("testingDetector");
    //Detector *testDetector2 = new Detector("testingDetector2");
    Detector *sphereDetectorDet = new Detector("sphericalDetectorDet");

    logicDetector->SetSensitiveDetector(testDetector);
    //logicDetector2->SetSensitiveDetector(testDetector2);
    logicSphere->SetSensitiveDetector(sphereDetectorDet);
}
#include <iostream>
#include "G4RunManager.hh"
#include "G4UIExecutive.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4VisManager.hh"
#include "G4PhysListFactory.hh"
#include "G4VUserPhysicsList.hh"
#include <iostream>

#include "Action.hh"
#include "Construction.hh"

int main(int argc, char** argv)
{
    G4RunManager *runManager = new G4RunManager();

    runManager->SetUserInitialization(new Construction());
    G4PhysListFactory *physListFactory = new G4PhysListFactory();
    G4VUserPhysicsList *physicsList = physListFactory->GetReferencePhysList("QGSP_BERT");
    runManager->SetUserInitialization(physicsList);
    runManager->SetUserInitialization(new Action());

    runManager->Initialize();

    G4UIExecutive *ui = new G4UIExecutive(argc, argv);
    G4VisManager *visManager = new G4VisExecutive();

    visManager->Initialize();

    G4UImanager *UImanager = G4UImanager::GetUIpointer();
    UImanager->ApplyCommand("/vis/open OGL");
    UImanager->ApplyCommand("/vis/viewer/set/viewpointVector 1 1 1");
    UImanager->ApplyCommand("/vis/drawVolume");
    UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true");
    UImanager->ApplyCommand("/vis/scene/add/trajectories smooth");
    UImanager->ApplyCommand("/control/execute /home/jamal/TCNProduction/particleGeneration.in");

    ui->SessionStart();

    return 0;
}
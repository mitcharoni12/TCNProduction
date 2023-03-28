#include "RunAction.hh"

RunAction::RunAction()
{

}

RunAction::~RunAction()
{

}

void RunAction::BeginOfRunAction(const G4Run*)
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();

    man->OpenFile("output.root");
    man->CreateNtuple("Energy", "Energy");
    man->CreateNtupleDColumn("KineticEnergy");
    man->CreateNtupleDColumn("TotalEnergy");
    man->CreateNtupleDColumn("Charge");
    man->CreateNtupleDColumn("RestEnergy");
    man->CreateNtupleIColumn("detectorNo");
    man->FinishNtuple(0);
}

void RunAction::EndOfRunAction(const G4Run*)
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();

    man->Write();
    //man->CloseFile();
}
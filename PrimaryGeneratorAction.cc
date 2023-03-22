#include "PrimaryGeneratorAction.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction()
{
    muParticleGun = new G4ParticleGun(1);
    parTable = G4ParticleTable::GetParticleTable();
    muon = parTable->FindParticle("mu+");

    muParticleGun->SetParticleDefinition(muon);
    muParticleGun->SetParticlePosition(G4ThreeVector(0.,0.,0.));
    muParticleGun->SetParticleMomentumDirection(G4ThreeVector(0., 0., 1.));
    muParticleGun->SetParticleMomentum(1000.*GeV);
}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
    delete muParticleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* event)
{
    muParticleGun->GeneratePrimaryVertex(event);
}
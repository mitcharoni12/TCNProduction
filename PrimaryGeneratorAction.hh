#ifndef PrimaryGeneratorAction_H
#define PrimaryGeneratorAction_H

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4GeneralParticleSource.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
    PrimaryGeneratorAction();
    ~PrimaryGeneratorAction();
    virtual void GeneratePrimaries(G4Event*);
private:
    G4ParticleGun* muParticleGun;
    G4ParticleTable* parTable;
    G4ParticleDefinition* muon;
};

#endif
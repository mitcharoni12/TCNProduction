#ifndef PrimaryGeneratorAction_H
#define PrimaryGeneratorAction_H

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4GeneralParticleSource.hh"

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
    PrimaryGeneratorAction();
    ~PrimaryGeneratorAction();
    virtual void GeneratePrimaries(G4Event*);
private:
    G4GeneralParticleSource* particleGun;
};

#endif
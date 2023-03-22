#include "PhysList.hh"

PhysList::PhysList()
{
    RegisterPhysics(new G4EmStandardPhysics());
    RegisterPhysics(new G4OpticalPhysics());
}

PhysList::~PhysList()
{
    //bruh
}
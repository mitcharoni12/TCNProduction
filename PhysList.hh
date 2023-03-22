#ifndef PhysList_H
#define PhysList_H

#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4OpticalPhysics.hh"

class PhysList : public G4VModularPhysicsList
{
public:
    PhysList();
    ~PhysList();
private:

};

#endif
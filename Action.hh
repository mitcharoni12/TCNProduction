#ifndef Action_H
#define Action_H

#include "G4VUserActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"

class Action : public G4VUserActionInitialization
{
public:
    Action();
    ~Action();
    virtual void Build() const;
private:

};

#endif
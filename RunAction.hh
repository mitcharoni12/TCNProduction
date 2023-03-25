#ifndef RunAction_H
#define RunAction_H

#include "G4UserRunAction.hh"
#include "G4AnalysisManager.hh"

class RunAction : public G4UserRunAction
{
public:
    RunAction();
    ~RunAction();
private:
    virtual void BeginOfRunAction(const G4Run*);
    virtual void EndOfRunAction(const G4Run*);
};

#endif

#include "Action.hh"

Action::Action()
{

}

Action::~Action()
{

}

void Action::Build() const
{
    PrimaryGeneratorAction* muonGenerator = new PrimaryGeneratorAction();
    SetUserAction(muonGenerator);

    RunAction* runAction = new RunAction();
    SetUserAction(runAction);
}
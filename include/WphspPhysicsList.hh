#ifndef WPHSPPHYSICSLIST_H
#define WPHSPPHYSICSLIST_H

#include "G4VModularPhysicsList.hh"
#include "globals.hh"

class StepMax;

class WphspPhysicsList: public G4VModularPhysicsList
{
public:

  WphspPhysicsList();
  virtual ~WphspPhysicsList();

  void SetCuts();
  void ConstructProcess();

  void AddStepMax();
  StepMax* GetStepMaxProcess() {return stepMaxProcess;}

private:
  G4double cutForGamma;
  G4double cutForElectron;
  G4double cutForPositron;

  StepMax* stepMaxProcess;
};

#endif

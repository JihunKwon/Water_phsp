#ifndef WPHSPSTEPPINGACTION_H
#define WPHSPSTEPPINGACTION_H

#include "G4UserSteppingAction.hh"

#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"

class PrimaryGeneratorAction;

class WphspSteppingAction : public G4UserSteppingAction {

public:
    WphspSteppingAction()
    {}

    ~WphspSteppingAction()
    {}

    void UserSteppingAction(const G4Step* aStep);
};

#endif

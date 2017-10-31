#ifndef WPHSPRUNACTION_H
#define WPHSPRUNACTION_H

#include "G4UserRunAction.hh"
#include "WphspDetectorConstruction.hh"
#include "globals.hh"
#include <vector>

class WphspRunAction : public G4UserRunAction
{
public:

    WphspRunAction();
    virtual ~WphspRunAction();

    virtual void BeginOfRunAction(const G4Run*);
    virtual void EndOfRunAction(const G4Run*);
};

#endif



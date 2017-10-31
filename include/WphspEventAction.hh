#ifndef WPHSPEVENTACTION_H
#define WPHSPEVENTACTION_H

#include "G4UserEventAction.hh"
#include "G4LogicalVolume.hh"
#include "globals.hh"

class WphspEventAction : public G4UserEventAction
{

public:
    WphspEventAction();
    ~WphspEventAction();

    void BeginOfEventAction(const G4Event* event);
    void EndOfEventAction(const G4Event* event);
};

#endif

    

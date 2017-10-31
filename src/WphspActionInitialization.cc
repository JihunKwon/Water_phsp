#include "WphspPrimaryGeneratorAction.hh"
#include "WphspRunAction.hh"
#include "WphspEventAction.hh"
#include "WphspSteppingAction.hh"
#include "WphspActionInitialization.hh"

WphspActionInitialization::WphspActionInitialization(WphspDetectorConstruction *geometry)
    : G4VUserActionInitialization()
{}

WphspActionInitialization::~WphspActionInitialization()
{}

void WphspActionInitialization::BuildForMaster() const
{
    SetUserAction(new WphspRunAction);
}

void WphspActionInitialization::Build() const
{
    SetUserAction(new WphspPrimaryGeneratorAction);
    SetUserAction(new WphspEventAction);
    SetUserAction(new WphspSteppingAction);
    SetUserAction(new WphspRunAction);
}

#include "WphspRunAction.hh"

#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4Run.hh"
#include "G4TrackingManager.hh"

#include "G4CsvAnalysisManager.hh"
#include "G4IAEAphspWriter.hh"

#include <fstream>
#include <sstream>
#include <iostream>

#define _USE_MATH_DEFINES
#define PHANTOM_SIDE (10.*cm)
#define MICRO_SIDE (50.*um)
//#define SCORE_RADIUS (1.*cm)

WphspRunAction::WphspRunAction() : G4UserRunAction()
{}

WphspRunAction::~WphspRunAction()
{}

void WphspRunAction::BeginOfRunAction(const G4Run* aRun)
{
    G4cout << "### Run " << aRun->GetRunID() << " start." << G4endl;
    G4IAEAphspWriter* Writer = G4IAEAphspWriter::GetInstance();
    Writer->SetZStop(-MICRO_SIDE); // -50um
    //Writer->SetRadius(SCORE_RADIUS*mm);   // SetRadius seems to not work.
    Writer->BeginOfRunAction(aRun);
}

void WphspRunAction::EndOfRunAction(const G4Run* aRun)
{
    G4IAEAphspWriter::GetInstance()->EndOfRunAction(aRun);
}

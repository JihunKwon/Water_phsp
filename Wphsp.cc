#undef G4MULTITHREADED // IAEA Phase Space seems to be not support MT.

#undef G4VIS_USE

#include <cstdio>
#include <ctime>

#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif

#ifdef G4VIS_USE
#include "G4VisExecutive.hh"
#endif

#include "G4UImanager.hh"
#ifdef G4UI_USE
#include "G4UIExecutive.hh"
#endif

#include "WphspPhysicsList.hh"
#include "WphspDetectorConstruction.hh"
#include "WphspPrimaryGeneratorAction.hh"
#include "WphspEventAction.hh"
#include "WphspRunAction.hh"
#include "WphspActionInitialization.hh"

#include "G4CsvAnalysisManager.hh"
#include "G4IAEAphspWriter.hh"

#include "G4ScoringManager.hh"

#include "G4CsvAnalysisManager.hh"
#include <math.h>

static G4double Sigma;

int main(int argc,char** argv)
{
    // Set the custom seed for the random engine
    G4Random::setTheEngine(new CLHEP::RanecuEngine);
    G4long seed = time(NULL);
    G4Random::setTheSeed(seed);

#ifdef G4MULTITHREADED
    G4MTRunManager* runManager = new G4MTRunManager;
    runManager->SetNumberOfThreads(8);
#else
    G4RunManager* runManager = new G4RunManager;
    G4ScoringManager* scoringManager = G4ScoringManager::GetScoringManager();
#endif

    WphspDetectorConstruction* massWorld = new WphspDetectorConstruction;
    runManager->SetUserInitialization(massWorld);

    G4VModularPhysicsList* physicsList = new WphspPhysicsList;
    physicsList->SetVerboseLevel(0);
    runManager->SetUserInitialization(physicsList);

    WphspActionInitialization* actionInit = new WphspActionInitialization(massWorld);
    runManager->SetUserInitialization(actionInit);
    runManager->Initialize(); //Comment for Batch mode

    G4UImanager* UImanager = G4UImanager::GetUIpointer();

#ifdef G4VIS_USE
    G4UIExecutive* ui = new G4UIExecutive(argc, argv);
    G4VisManager* visManager = new G4VisExecutive;
    visManager->Initialize();
    UImanager->ApplyCommand("/control/execute init_vis.mac");
    ui->SessionStart();
    delete ui;
    delete visManager;
#endif

    G4UImanager* pUI = G4UImanager::GetUIpointer();
    if (argc != 1)   // batch mode
    {
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        pUI->ApplyCommand(command + fileName);
    }

    else           //define visualization and UI terminal for interactive mode
    {

    }

      pUI->ApplyCommand("/testem/stepMax 1 mm"); //Comment for Batch mode
      runManager->BeamOn(100000000);                  //Comment for Batch mode

    delete runManager;
    return 0;
}

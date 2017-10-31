#include "WphspDetectorConstruction.hh"

#include "G4Material.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4PVPlacement.hh"
#include "G4PVReplica.hh"
#include "G4NistManager.hh"
#include "G4Transform3D.hh"
#include "G4RotationMatrix.hh"
#include "G4VisAttributes.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4GeometryManager.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4SolidStore.hh"
#include "G4RunManager.hh"
#include "G4VSolid.hh"
#include "G4Sphere.hh"
#include "G4UserLimits.hh"

#define PHANTOM_SIDE (10.*cm)
#define SCORE_DEPTH (2.*cm)
#define MICRO_SIDE (50.*um)

using namespace CLHEP;

WphspDetectorConstruction::WphspDetectorConstruction()
    :fStepLimit(NULL)
{}

//WphspDetectorConstruction::~WphspDetectorConstruction()
//{
//  delete fStepLimit;
//}

G4VPhysicalVolume* WphspDetectorConstruction::Construct()
{
    // Cleanup old geometry
    G4GeometryManager::GetInstance()->OpenGeometry();
    G4PhysicalVolumeStore::GetInstance()->Clean();
    G4LogicalVolumeStore::GetInstance()->Clean();
    G4SolidStore::GetInstance()->Clean();

    G4VisAttributes* visAttributes = new G4VisAttributes;
    visAttributes->SetForceWireframe(true);
    visAttributes->SetForceAuxEdgeVisible(true);

    G4NistManager* nistManager = G4NistManager::Instance();
    G4Material* vacuum = nistManager->FindOrBuildMaterial("G4_Galactic");
    G4Material* water = nistManager->FindOrBuildMaterial("G4_WATER");

    // World
    G4Box* world = new G4Box("World", PHANTOM_SIDE*3, PHANTOM_SIDE*3, PHANTOM_SIDE*3);   //halfx=0.05um
    G4LogicalVolume *worldLogic = new G4LogicalVolume(world, vacuum, "WorldLogic");
    G4VPhysicalVolume *worldPhys = new G4PVPlacement(0, G4ThreeVector(0,0,0), worldLogic, "WorldPhys", 0, false, 0);
    worldLogic->SetVisAttributes(visAttributes);

    // Phantom
    G4Box* phantomSolid = new G4Box("PhatomSolid", PHANTOM_SIDE, PHANTOM_SIDE, PHANTOM_SIDE);
    G4LogicalVolume *phantomLogic = new G4LogicalVolume(phantomSolid, water, "PhantomLogic");
    G4VPhysicalVolume *phantomPhys = new G4PVPlacement(0, G4ThreeVector(0,0,(PHANTOM_SIDE-SCORE_DEPTH-MICRO_SIDE)), // 10cm-2cm-50um
                                                       phantomLogic, "phantomPhys", worldLogic, false, 0);

    // Edist Plate
    G4Box* EdistPlate = new G4Box("EdistPlate", PHANTOM_SIDE, PHANTOM_SIDE, 0.1*um);
    G4LogicalVolume *PlateLogic = new G4LogicalVolume(EdistPlate, water, "PlateLogic");
    G4VPhysicalVolume *PlatePhys = new G4PVPlacement(0, G4ThreeVector(0,0,(-PHANTOM_SIDE+SCORE_DEPTH)), // z=0 is of "Phantom" (mother volume)
                                                     PlateLogic, "PlatePhys", phantomLogic, false, 0);

//    G4Box* test = new G4Box("Test", 10*cm, 10*cm, 0.01*mm);
//    G4LogicalVolume *testLogic = new G4LogicalVolume(test, water, "TestLogic");
//    G4VPhysicalVolume *testPhys = new G4PVPlacement(0, G4ThreeVector(0, 0, -80*mm), testLogic, "TestPhys", phantomLogic, false, 0);

    G4double maxStep = 100*mm; // This doesn't working
    fStepLimit = new G4UserLimits(maxStep);
//    phantomLogic->SetUserLimits(fStepLimit);

    return worldPhys;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void WphspDetectorConstruction::SetMaxStep(G4double maxStep)
{
    if ((fStepLimit)&&(maxStep>0.)) fStepLimit->SetMaxAllowedStep(maxStep);
}

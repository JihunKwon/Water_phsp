#ifndef WPHSPDETECTORCONSTRUCTION_H
#define WPHSPDETECTORCONSTRUCTION_H

#include "G4VUserDetectorConstruction.hh"
#include "G4Material.hh"
#include "tls.hh"

class WphspDetectorMessenger;
class G4LogicalVolume;
class G4VPhysicalVolume;
class G4UserLimits;

using namespace CLHEP;

class WphspDetectorConstruction : public G4VUserDetectorConstruction
{
public:
    WphspDetectorConstruction();
    ~WphspDetectorConstruction() {}

    G4VPhysicalVolume* Construct();

    void SetMaxStep (G4double );

 // void ConstructSDandField();
 // This method is used in multi-threaded applications to build
 // per-worker non-shared objects: SensitiveDetectors and Field managers

private:
    G4UserLimits* fStepLimit;   // pointer to user step limits
};

#endif


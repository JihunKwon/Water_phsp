#include "WphspPrimaryGeneratorAction.hh"

#include "G4Proton.hh"
#include "G4Gamma.hh"
#include "G4Electron.hh"

#include <G4SingleParticleSource.hh>

#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"

#define PHANTOM_SIDE (10.*cm)
#define SCORE_DEPTH (2.*cm)
#define MICRO_SIDE (50.*um)
//#define SOURCE_SIDE (2.5*cm)

using namespace CLHEP;

WphspPrimaryGeneratorAction::WphspPrimaryGeneratorAction()
{
    CircleSource = new G4SingleParticleSource;
    CircleSource->SetParticleDefinition(G4Gamma::Definition());

//    G4SPSEneDistribution* energy = CircleSource->GetEneDist();
    this->setEnergyToGamma();
//    energy->SetMonoEnergy(25*keV);

//    G4SPSPosDistribution* position = CircleSource->GetPosDist();
//    position->SetPosDisType("Plane");
//    position->SetPosDisShape("Circle");
//    position->SetRadius(radius*mm);
//    position->SetCentreCoords(G4ThreeVector(0*m, 0*m, -100*mm));

    G4SPSPosDistribution* position = CircleSource->GetPosDist();
    position->SetPosDisType("Plane");
    position->SetPosDisShape("Square");
    position->SetHalfX(PHANTOM_SIDE);
    position->SetHalfY(PHANTOM_SIDE); // Bombardment is from everywhere of the plane
    position->SetCentreCoords(G4ThreeVector(0*m, 0*m, (-PHANTOM_SIDE+(PHANTOM_SIDE-SCORE_DEPTH)-MICRO_SIDE))); // -10cm+(10cm-2cm)-50um
    G4SPSAngDistribution* angular = CircleSource->GetAngDist();
    angular->SetParticleMomentumDirection(G4ThreeVector(0.0,0.0,1.0));
    angular->DefineAngRefAxes("angref1", G4ThreeVector(-1.0,0.0,0.0));
    CircleSource->SetNumberOfParticles(1);

//    G4String fileName = "Varian_TrueBeam6MV_01";
//    IAEAReader = new G4IAEAphspReader(fileName);

//    G4ThreeVector isoPos(0*mm, 0*mm, -201*mm);
//   // IAEAReader->SetIsocenterPosition(isoPos);
//    IAEAReader->SetGlobalPhspTranslation(G4ThreeVector(0,0,-300*mm-200*mm));
//    IAEAReader->SetTimesRecycled(0);
}

WphspPrimaryGeneratorAction::~WphspPrimaryGeneratorAction()
{
    //if (IAEAReader)
    //    delete IAEAReader;
    delete CircleSource;
}

void WphspPrimaryGeneratorAction::GeneratePrimaries(G4Event* event)
{
    CircleSource->GeneratePrimaryVertex(event);
    //IAEAReader->GeneratePrimaryVertex(event);
}

G4SPSEneDistribution* WphspPrimaryGeneratorAction::setEnergyToGamma() {
    G4SPSEneDistribution* eneDist = CircleSource->GetEneDist();
    eneDist->SetEnergyDisType("Arb");
    eneDist->ArbEnergyHistoFile("220kVp.txt");
    eneDist->ArbInterpolate("Lin");
    return eneDist;
}


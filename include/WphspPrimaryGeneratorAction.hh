#ifndef WPHSPPRIMARYGENERATORACTION_H
#define WPHSPPRIMARYGENERATORACTION_H

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4SPSPosDistribution.hh"
#include "G4Types.hh"
#include "G4ParticleGun.hh"
#include "G4SingleParticleSource.hh"

#include "G4IAEAphspReader.hh"

class G4Event;

class WphspPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{

public:
    WphspPrimaryGeneratorAction();
    ~WphspPrimaryGeneratorAction();

    void GeneratePrimaries(G4Event* event);

    G4SPSEneDistribution* setEnergyToGamma();

private:
    G4SingleParticleSource* CircleSource;
    //G4IAEAphspReader* IAEAReader;
};

#endif



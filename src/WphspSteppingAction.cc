#include "WphspSteppingAction.hh"

#include "G4Track.hh"
#include "G4TrackStatus.hh"
#include "G4CsvAnalysisManager.hh"
#include "G4ThreeVector.hh"
#include "G4VProcess.hh"
#include "G4IAEAphspWriter.hh"

void WphspSteppingAction::UserSteppingAction(const G4Step* aStep)
{

//    if (!aStep->GetTrack()->GetCreatorProcess()&&aStep->IsFirstStepInVolume())
//    {
//        G4cout << aStep->GetPreStepPoint()->GetMomentumDirection().z() << " "
//               << aStep->GetTrack()->GetMomentumDirection().z() << G4endl;
        G4IAEAphspWriter::GetInstance()->UserSteppingAction(aStep);
//    }

}


/*
 * /process/list
     Transportation,              Decay,               phot,              compt
               conv,     LowEnPhotoElec,       LowEnCompton,    LowEnConversion
      LowEnRayleigh,              eBrem,              eIoni,          LowEnBrem
      LowEnergyIoni,                msc,            annihil,             muIoni
            muBrems,         muPairProd,muMinusCaptureAtRest,              hIoni
           LElastic,  PionPlusInelastic, PionMinusInelastic,PiMinusAbsorptionAtRest
  KaonPlusInelastic, KaonMinusInelastic, KaonZeroLInelastic, KaonZeroSInelastic
    ProtonInelastic,AntiProtonInelastic,AntiProtonAnnihilationAtRest,   NeutronInelastic
           LFission,           LCapture,AntiNeutronInelastic,AntiNeutronAnnihilationAtRest
    LambdaInelastic,AntiLambdaInelastic,SigmaMinusInelastic,AntiSigmaMinusInelastic
 SigmaPlusInelastic,AntiSigmaPlusInelastic,   XiMinusInelastic,AntiXiMinusInelastic
    XiZeroInelastic,AntiXiZeroInelastic,OmegaMinusInelastic,AntiOmegaMinusInelastic
  DeuteronInelastic,    TritonInelastic,     AlphaInelastic
  */

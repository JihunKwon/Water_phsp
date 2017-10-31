#ifndef WPHSPACTIONINITIASLIZATION_HH
#define WPHSPACTIONINITIASLIZATION_HH

#include "G4VUserActionInitialization.hh"
#include "WphspDetectorConstruction.hh"

class WphspActionInitialization : public G4VUserActionInitialization
{
  public:

    WphspActionInitialization(WphspDetectorConstruction* geometry);
    virtual ~WphspActionInitialization();

    virtual void BuildForMaster() const;
    virtual void Build() const;
};

#endif // WphspACTIONINITIASLIZATION_HH

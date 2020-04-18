#include "G4UIsession.hh"

class MySession : public G4UIsession
{
    public:
        MySession();
        ~MySession();

        //methods
        G4int ReceiveG4cout(const G4String& coutString);
        G4int ReceiveG4cout(const G4double& coutDouble);
};
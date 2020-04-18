#include "MySession.hh"
#include <ostream>
#include <fstream>
using namespace std;

MySession::MySession(){}

MySession::~MySession(){}

ofstream logFile("MyLogFile");

G4int MySession::ReceiveG4cout(const G4String& coutString)
{
  logFile << coutString << flush;
  return 0;
}

G4int MySession::ReceiveG4cout(const G4double& coutDouble)
{
  logFile << coutDouble << flush;
  return 0;
}
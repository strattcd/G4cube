#include "ExG4PhysicsList00.hh"
#include "G4Geantino.hh"

ExG4PhysicsList00::ExG4PhysicsList00()
 : G4VUserPhysicsList()
{}

ExG4PhysicsList00::~ExG4PhysicsList00()
{}

void ExG4PhysicsList00::ConstructParticle()
{
    G4Geantino::GeantinoDefinition();
}

void ExG4PhysicsList00::ConstructProcess()
{
// Define transportation process
    AddTransportation();
}

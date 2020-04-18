#include "ExG4PhysicsList00.hh"
#include "G4Gamma.hh"
#include "G4Electron.hh"
#include "G4Positron.hh"
#include "G4PhysicsListHelper.hh"
#include "G4PhotoElectricEffect.hh"
#include "G4ComptonScattering.hh"
#include "G4GammaConversion.hh"
#include "G4RayleighScattering.hh"

ExG4PhysicsList00::ExG4PhysicsList00()
 : G4VUserPhysicsList()
{}

ExG4PhysicsList00::~ExG4PhysicsList00()
{}

void ExG4PhysicsList00::ConstructParticle()
{
    G4Gamma::GammaDefinition();
    G4Electron::ElectronDefinition();
    G4Positron::PositronDefinition();
}

void ExG4PhysicsList00::ConstructProcess()
{
    // Define transportation process
    AddTransportation();

    // electromagnetic processes
    G4PhysicsListHelper* ph = G4PhysicsListHelper::GetPhysicsListHelper();

    //  Get pointer to gamma
    G4ParticleDefinition* particle = G4Gamma::GammaDefinition();

    // Construct and register processes for gamma
    ph->RegisterProcess(new G4PhotoElectricEffect(), particle);
    ph->RegisterProcess(new G4ComptonScattering(), particle);
    ph->RegisterProcess(new G4GammaConversion(), particle);
    ph->RegisterProcess(new G4RayleighScattering(), particle);  


}

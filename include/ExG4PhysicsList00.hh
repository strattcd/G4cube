#ifndef ExG4PhysicsList00_h
#define ExG4PhysicsList00_h 1

#include "G4VUserPhysicsList.hh"

class ExG4PhysicsList00 : public G4VUserPhysicsList 
{
  public:
    ExG4PhysicsList00();
    virtual ~ExG4PhysicsList00();

    virtual void ConstructParticle();
    virtual void ConstructProcess();
    virtual void ConstructEM();
};

#endif
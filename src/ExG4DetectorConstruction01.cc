
#include "ExG4DetectorConstruction01.hh"
#include "G4RunManager.hh"
#include "G4Box.hh"
#include "G4SystemOfUnits.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"

ExG4DetectorConstruction01::ExG4DetectorConstruction01()
: G4VUserDetectorConstruction()
{ }

ExG4DetectorConstruction01::~ExG4DetectorConstruction01()
{ }

G4VPhysicalVolume* ExG4DetectorConstruction01::Construct()
{  
    // Get nist material manager
    G4NistManager* nist = G4NistManager::Instance();


    //World
    G4double world_hx = 3.0*m;
    G4double world_hy = 1.0*m;
    G4double world_hz = 1.0*m;
    G4Box* worldBox
        = new G4Box("World", world_hx, world_hy, world_hz);
    G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");
    G4LogicalVolume* worldLog = new G4LogicalVolume(worldBox, world_mat, "World");             
    G4VPhysicalVolume* physWorld = 
        new G4PVPlacement(0,                     //no rotation
                        G4ThreeVector(),       //at (0,0,0)
                        worldLog,            //its logical volume
                        "World",               //its name
                        0,                     //its mother  volume
                        false,                 //no boolean operation
                        0);                     //copy number        

    //Cube
    G4double cube_hx = 0.5*m;
    G4double cube_hy = 0.5*m;
    G4double cube_hz = 0.5*m;        
    G4Box* cube
        = new G4Box("Cube", cube_hx, cube_hy, cube_hz);
    G4Material* cube_mat = nist->FindOrBuildMaterial("G4_WATER");
    G4LogicalVolume* cubeLog
    = new G4LogicalVolume(cube, cube_mat, "Cube");
    G4double pos_x =  0.0*meter;
    G4double pos_y =  0.0*meter;
    G4double pos_z =  0.0*meter;
    new G4PVPlacement(0,    // no rotation
                    G4ThreeVector(pos_x, pos_y, pos_z), // translation position
                    cubeLog,              // its logical volume
                    "Cube",               // its name
                    worldLog,                // its mother (logical) volume
                    false,                   // no boolean operations
                    0);                      // its copy number 

    return physWorld;                        
}             
#include "G4RunManager.hh"
#include "G4TrackingManager.hh"
#include "G4EventManager.hh"
#include "G4UImanager.hh"

 #include "G4VisExecutive.hh"
 #include "G4UIExecutive.hh"


 #include "ExG4DetectorConstruction01.hh"
 //#include "ExG4PhysicsList00.hh"
 #include "ExG4PrimaryGeneratorAction01.hh"

 #include "QBBC.hh"

 #include "G4UIterminal.hh"

 #include "MySession.hh"

 int main()//int argc,char** argv)
 {
  // construct the default run manager
  //G4EventManager* event = new G4EventManager;       
  //event->SetVerboseLevel(2);  
  G4RunManager* runManager = new G4RunManager;


  // set mandatory initialization classes
  runManager->SetUserInitialization(new ExG4DetectorConstruction01);

  // Physics list
  G4VModularPhysicsList* physicsList = new QBBC;
  physicsList->SetVerboseLevel(0);
  runManager->SetUserInitialization(physicsList);
  //runManager->SetUserInitialization(new ExG4PhysicsList00);

  // set mandatory user action class
  runManager->SetUserAction(new ExG4PrimaryGeneratorAction01);

  // get the pointer to the User Interface manager
  G4UImanager* UI = G4UImanager::GetUIpointer();
  UI->ApplyCommand("/tracking/verbose 1");
  // construct a session which receives G4cout/G4cerr
  MySession * LoggedSession = new MySession;
  UI->SetCoutDestination(LoggedSession);


  // initialize G4 kernel
   runManager->Initialize();
   runManager->BeamOn(10);

  // runManager->GenerateEvent(1);
  // const G4Event* event = runManager->GetCurrentEvent();
  // G4PrimaryVertex* vertex = event->GetPrimaryVertex();
  // G4double x0 = vertex->GetX0();
  // LoggedSession->ReceiveG4cout(x0);
  LoggedSession->ReceiveG4cout("Done with a smile :)");

  // if ( argc == 1 ) {
    
  //   // //Initialize visualization    
  //   // G4VisManager* visManager = new G4VisExecutive;
  //   // visManager->Initialize();
  //   // // Get the pointer to the User Interface manager
  //   // G4UImanager* UImanager = G4UImanager::GetUIpointer();

  //   // // interactive mode : define UI session
  //   // G4UIExecutive* ui = new G4UIExecutive(argc, argv);
  //   // UImanager->ApplyCommand("/control/execute init_vis.mac");
  //   // ui->SessionStart();
  //   // delete ui;

  // }
  // else {
  //     // start a run
  //     runManager->BeamOn(1);
  //     const G4Event* event = runManager->GetPreviousEvent(1);

  //}

  // job termination
  delete runManager;
  delete LoggedSession;
  return 0;

 }
#include "G4RunManager.hh"
#include "G4UImanager.hh"

 #include "G4VisExecutive.hh"
 #include "G4UIExecutive.hh"

 #include "ExG4DetectorConstruction01.hh"
 #include "ExG4PrimaryGeneratorAction01.hh"

 #include "ExG4PhysicsList00.hh"
 //#include "QBBC.hh"

 #include "G4UIterminal.hh"

 #include "MySession.hh"

 int main(int argc,char** argv)
 {
  // construct the default run manager
  //G4EventManager* event = new G4EventManager;       
  //event->SetVerboseLevel(2);  
  G4RunManager* runManager = new G4RunManager;


  // set mandatory initialization classes
  runManager->SetUserInitialization(new ExG4DetectorConstruction01);

  // Physics list
  runManager->SetUserInitialization(new ExG4PhysicsList00);
  
  //G4VModularPhysicsList* physicsList = new QBBC;
  //physicsList->SetVerboseLevel(0);
  //runManager->SetUserInitialization(physicsList);
  
  // set mandatory user action class
  runManager->SetUserAction(new ExG4PrimaryGeneratorAction01);

  // initialize G4 kernel
  runManager->Initialize();

  // get the pointer to the User Interface manager
  G4UImanager* UImanager = G4UImanager::GetUIpointer();

  if ( argc == 1 ) {
    
    //Initialize visualization    
    G4VisManager* visManager = new G4VisExecutive;
    visManager->Initialize();

    // interactive mode : define UI session
    G4UIExecutive* ui = new G4UIExecutive(argc, argv);
    UImanager->ApplyCommand("/control/execute init_vis.mac");
    ui->SessionStart();
    delete ui;

  }
  else {
    UImanager->ApplyCommand("/tracking/verbose 1");
    // construct a session which receives G4cout/G4cerr
    MySession * LoggedSession = new MySession;
    UImanager->SetCoutDestination(LoggedSession);

    runManager->BeamOn(10);

    // runManager->GenerateEvent(1);
    // const G4Event* event = runManager->GetCurrentEvent();
    // G4PrimaryVertex* vertex = event->GetPrimaryVertex();
    // G4double x0 = vertex->GetX0();
    // LoggedSession->ReceiveG4cout(x0);
    LoggedSession->ReceiveG4cout("Done with a smile :)");
    delete LoggedSession;
  }

  // job termination
  delete runManager;
  return 0;

 }
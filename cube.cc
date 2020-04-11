 #include "G4RunManager.hh"
 #include "G4UImanager.hh"

 #include "G4VisExecutive.hh"
 #include "G4UIExecutive.hh"


 #include "ExG4DetectorConstruction01.hh"
 //#include "ExG4PhysicsList00.hh"
 #include "ExG4PrimaryGeneratorAction01.hh"

 #include "QBBC.hh"

 int main(int argc,char** argv)
 {
  // construct the default run manager
  G4RunManager* runManager = new G4RunManager;

  // set mandatory initialization classes
  runManager->SetUserInitialization(new ExG4DetectorConstruction01);

  // Physics list
  G4VModularPhysicsList* physicsList = new QBBC;
  physicsList->SetVerboseLevel(1);
  runManager->SetUserInitialization(physicsList);
  //runManager->SetUserInitialization(new ExG4PhysicsList00);

  // set mandatory user action class
  runManager->SetUserAction(new ExG4PrimaryGeneratorAction01);

  // initialize G4 kernel
  runManager->Initialize();

  // Initialize visualization
  //
  G4VisManager* visManager = new G4VisExecutive;
  // G4VisExecutive can take a verbosity argument - see /vis/verbose guidance.
  // G4VisManager* visManager = new G4VisExecutive("Quiet");
  visManager->Initialize();

  // Get the pointer to the User Interface manager
  G4UImanager* UImanager = G4UImanager::GetUIpointer();

  if ( argc == 1 ) {
    
    // interactive mode : define UI session
      G4UIExecutive* ui = new G4UIExecutive(argc, argv);
      UImanager->ApplyCommand("/control/execute init_vis.mac");
      ui->SessionStart();
      delete ui;

  }
  else {
    // batch mode
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UImanager->ApplyCommand(command+fileName);
  }

  // job termination
  delete runManager;
  return 0;
 }
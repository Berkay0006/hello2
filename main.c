#include <stdio.h>

// Control()
// Takes an altitude value and determines wether the thruster
// should be on or off. 
// Returns 1 if the altitude is between 1 and 100 (inclusive),
// otherwise return 0. 
int Control(int altitude) {
    int thruster = 0;

    // If altitude is within the range 1-100, turn thruster on.
    if (altitude > 0 && altitude <= 100) {
        thruster = 1;
    }

    return thruster;    // Return thruster state 
}

// Test()
// Calls Control() with a given altitude and checks if the returned
// thruster state matches expected behavior. 
// Prints the altitude, thruster state, and wether the behavior
// was correct ("y") or not ("n").
void Test(int altitude) {
  int thruster = Control(altitude);

  // check if thruster behavior matches expected rules: 
  // - If altitude > 100 -> thruster should be off (0)
  // - If 0 < altitude <= 100 -> thruster should be on (1)
  // - If altitude <= 0 -> thruster should be off (0)
  int behaviorCorrect = (altitude > 100 && thruster == 0) ||
                        (altitude <= 100 && altitude > 0 && thruster == 1) ||
                        (altitude <= 0 && thruster == 0);

  // Choose "y" for correct behavior, "n" otherwise
  char *behaviorCorrectIcon = behaviorCorrect ? "y" : "n";

  // Print result
  printf("For altitude %3d, your thruster is %d |%s|\n", altitude, thruster,
         behaviorCorrectIcon);
}

// main()
// Tests the control() function with several altitude values
// to verify correct thruster behavior. 
int main(void) {
  Test(150);    // Too high -> thruster off
  Test(100);    // In safe range -> thruster on
  Test(50);     // In safe range -> thruster on 
  Test(0);      // On surface -> thruster off
  Test(-1);     // Below surface -> thruster off
}
/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: [Sebastian A. Feliciano]
 * Lab: 8 - Functions
 * Description: [What this specific program does]
 * Due Date: [10/12/26]
 */
#include <iostream>                                      // Provides cin, cout, and endl
using namespace std;                                     // Allows standard-library names without the std:: prefix

void showProjectedCount(int completedInspections);       // Declares a value-parameter function
void recordCompletedInspection(int &completedInspections); // Declares a reference-parameter function

int main() {                                             // Starts the program
    int completedInspections;                            // Stores the official completed-inspection count

    cout << "Enter completed inspections: ";           // Prompts for the official count
    cin >> completedInspections;                         // Reads the value stored by main

    showProjectedCount(completedInspections);            // Sends a copied count to the first function
    cout << "After projection: " << completedInspections << endl; // Shows that main kept its count
    recordCompletedInspection(completedInspections);     // Sends the original count by reference
    cout << "After recording: " << completedInspections << endl; // Shows that main now stores the update

    return 0;                                            // Ends the program successfully
}                                                        // Ends the main function

void showProjectedCount(int completedInspections) {      // Defines a function that changes only its local copy
    completedInspections++;                              // Adds one only to the copied parameter
    cout << "Projected count: " << completedInspections << endl; // Displays the possible next count
}                                                        // Ends the value-parameter function

void recordCompletedInspection(int &completedInspections) { // Defines a function that accesses the original variable
    completedInspections++;                              // Changes the official count through the reference
    cout << "Inspection recorded." << endl;             // Confirms the permanent update
}                                                        // Ends the reference-parameter function

/*
  FUNCTIONS
  - void showHeader()
      No parameters, no return value. Prints fixed text only.
  - void reportDecision(char answer)
      Pass by value: it gets a copy, so it can read and report the
      answer but cannot modify main's variable.
  - void useFuse(char answer, int &fuseCount)
      Pass by reference: it changes the real inventory in main.
      Decrements fuseCount by one only if answer is 'Y' or 'y'.

  MAIN FLOW
  1. Declare int fuseCount with the starting inventory.
  2. Call showHeader() (always).
  3. Ask the technician for the decision (char answer).
  4. Call reportDecision(answer).
  5. Call useFuse(answer, fuseCount).
  6. Display the number of fuses left in the cabinet.
*/
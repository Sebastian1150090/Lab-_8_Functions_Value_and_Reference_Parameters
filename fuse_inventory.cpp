/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: [Sebastian A. Feliciano]
 * Lab: 8 - Functions
 * Description: [  This program manages the spare-fuse inventory of a maintenance cabinet.]
 * Due Date: [10/12/26]
 */
#include <iostream>                                      // Provides cin, cout, and endl
using namespace std;                                     // Allows standard-library names without the std:: prefix

// TODO: Declare prototypes for the three functions described below.
void showHeader();
void reportDecision(char answer);
void useFuse(char answer, int &fuseCount);

int main() {                                             // Starts the program
    int fuseCount;                                       // Stores the official number of spare fuses
    char usedFuse;                                       // Stores the technician decision

    // TODO: Call the heading function, read fuseCount, and read Y or N.
    showHeader();
    cout << "Enter the number of spare fuses: ";
    cin >> fuseCount;
    cout << "Did the technician use a fuse? (Y/N): ";
    cin >> usedFuse;

    // TODO: Use if/else to decide whether to call the inventory-update function.
    reportDecision(usedFuse);
    useFuse(usedFuse, fuseCount);

    // TODO: Display the final number of spare fuses.
    cout << "Final number of spare fuses: " << fuseCount << endl;

    return 0;                                            // Ends the program successfully
}                                                        // Ends the main function

// TODO: Define a void function that displays the cabinet heading.
void showHeader() {
    cout << "=== Fuse Inventory ===" << endl;
}

// TODO: Define a void function that reports whether the response uses a fuse.
void reportDecision(char answer) {
    if (answer == 'Y' || answer == 'y') {
        cout << "A fuse was used." << endl;
    } else {
        cout << "No fuse was used." << endl;
    }
}

// TODO: Define a void function that receives fuseCount by reference and subtracts one.
void useFuse(char answer, int &fuseCount) {
    if (answer == 'Y' || answer == 'y') {
        fuseCount--;
    }
}

/*
  TEST CASES
  #  | Input (fuseCount, answer) | Expected output
  ---|---------------------------|------------------------------------------
  1  | 10, Y                     | A fuse was used.            Final: 9
  2  | 5,  y                     | A fuse was used.            Final: 4
  3  | 8,  N                     | No fuse was used.           Final: 8
  4  | 3,  n                     | No fuse was used.           Final: 3

  Cases 1-2 check that both uppercase and lowercase "yes" reduce the
  inventory. Cases 3-4 check that both "no" answers leave it unchanged.

  ANALYSIS
  Only useFuse needs the & because it is the only function that must
  change a variable owned by main. A reference makes fuseCount an alias
  of main's real variable, so fuseCount-- updates the official inventory.
  showHeader needs no data at all, so it has no parameters. reportDecision
  only reads the answer, so a by-value copy is enough: it can print the
  decision, but nothing it does can alter main's variables. Using & there
  would be unnecessary and would allow accidental changes. Passing by
  reference only where modification is required keeps each function's
  role clear and protects main's data.
*/

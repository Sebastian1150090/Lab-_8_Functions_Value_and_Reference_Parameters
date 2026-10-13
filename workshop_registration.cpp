/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: [Sebastian A. Feliciano]
 * Lab: 8 - Functions
 * Description: [What this specific program does]
 * Due Date: [10/12/26]
 */
#include <iostream>                                      // Provides cin, cout, and endl
using namespace std;                                     // Allows standard-library names without the std:: prefix

// Prototypes
void showMenu();                                         // No data needed
void registerAttendee(int &availableSeats);              // By reference: changes available seats
void cancelRegistration(int &availableSeats, int maxSeats); // Reference to change seats, value to read capacity

int main() {                                             // Starts the program
    int maxSeats;                                        // Stores the fixed workshop capacity
    int availableSeats;                                  // Stores the changing number of available seats
    int menuChoice;                                      // Stores one selected menu option

    // Read a valid capacity (must be positive) and initialize available seats
    do {
        cout << "Enter the maximum number of seats: ";
        cin >> maxSeats;
        if (maxSeats <= 0) {
            cout << "Capacity must be greater than 0." << endl;
        }
    } while (maxSeats <= 0);
    availableSeats = maxSeats;

    // Repeat the menu and read one option on each pass
    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> menuChoice;

        // Perform the selected action or end the session
        switch (menuChoice) {
            case 1:
                registerAttendee(availableSeats);
                break;
            case 2:
                cancelRegistration(availableSeats, maxSeats);
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (menuChoice != 3);

    return 0;                                            // Ends the program successfully
}                                                        // Ends the main function

// Displays the menu
void showMenu() {
    cout << "\n=== Workshop Registration ===" << endl;
    cout << "1. Register Attendee" << endl;
    cout << "2. Cancel Registration" << endl;
    cout << "3. Exit" << endl;
}

// Registers an attendee only if there is at least one free seat
void registerAttendee(int &availableSeats) {
    if (availableSeats > 0) {
        availableSeats--;
        cout << "Attendee registered successfully." << endl;
    } else {
        cout << "No seats available." << endl;
    }
}

// Cancels a registration only if available seats are below capacity
void cancelRegistration(int &availableSeats, int maxSeats) {
    if (availableSeats < maxSeats) {
        availableSeats++;
        cout << "Registration canceled successfully." << endl;
    } else {
        cout << "No registration to cancel." << endl;
    }
}
/*  ANALYSIS
  maxSeats does not need & because cancelRegistration only reads it to
  compare against availableSeats; it never changes it. maxSeats is the
  fixed workshop capacity, so a copy passed by value is enough, and the
  original in main cannot be altered by accident. availableSeats, in
  contrast, is the changing value: registerAttendee and cancelRegistration
  must update main's real variable, so both receive it as int &availableSeats.
  Without the reference, the functions would modify a copy and the change
  would be lost when they return. Using & only where modification is
  required keeps each function's role clear and protects main's data.
  Both capacity limits are validated: registration stops at 0 available
  seats, and cancellation stops at maxSeats.
*/

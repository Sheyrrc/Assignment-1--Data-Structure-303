#include "functions.h"
#include <iostream>

using namespace std;

int main() {
  int *arr = new int[MAX_SIZE];
  int size = 0;
  cout << "WELCOME!!" << endl;

  try {
    readFile("readfile.txt", arr, size);

    int choice;
    do {
      cout << "\nMenu:\n";
      cout << "1. Find a number\n";
      cout << "2. Modify a number\n";
      cout << "3. Add a number\n";
      cout << "4. Delete a number\n";
      cout << "5. Quit\n\n";
      cout << "Enter your choice: ";
      cin >> choice;
      cout << endl;

      switch (choice) {
      case 1: {
        int numToFind;
        cout << "Enter the number you want to find: ";
        cin >> numToFind;
        int index = funcExist(arr, size, numToFind);
        if (index != -1) {
          cout << "Number " << numToFind << " found at index: " << index
               << endl;
        } else {
          cout << "Number " << numToFind << " not found" << endl;
        }
        break;
      }
      case 2: {
        int indexToModify;
        int newValue;
        cout << "Enter the index to modify: ";
        cin >> indexToModify;
        cout << "Enter the new value: ";
        cin >> newValue;
        int oldValue;
        try {
          int modifiedValue =
              funcModify(arr, size, indexToModify, newValue, oldValue);
          cout << "Old value at index " << indexToModify << ": " << oldValue
               << endl;
          cout << "New value at index " << indexToModify << ": "
               << modifiedValue << endl;
          writeFile("readfile.txt", arr, size);
        } catch (const char *errorMessage) {
          cerr << "Error: " << errorMessage << endl;
        }
        break;
      }
      case 3: {
        int newValueToAdd;
        cout << "Enter the new value to add at the end: ";
        cin >> newValueToAdd;
        try {
          arr = funcAdd(arr, size, newValueToAdd);
          writeFile("readfile.txt", arr, size);
        } catch (const char *errorMessage) {
          cerr << "Error: " << errorMessage << endl;
        }
        break;
      }
      case 4: {
        int indexToDelete;
        int newValueToReplace;
        cout << "Enter the index to delete: ";
        cin >> indexToDelete;
        cout << "Enter the new value to replace with (0 for removal): ";
        cin >> newValueToReplace;
        try {
          arr = funcDel(arr, size, indexToDelete, newValueToReplace);
          writeFile("readfile.txt", arr, size);
        } catch (const char *errorMessage) {
          cerr << "Error: " << errorMessage << endl;
        }
        break;
      }
      case 5: {
        cout << "Quitting the program.\n";
        break;
      }
      default: {
        cout << "Invalid choice. Please enter a valid option.\n\n";
        break;
      }
      }
    } while (choice != 5);

    // Deallocate the dynamically allocated array before exiting
    delete[] arr;

  } catch (const char *errorMessage) {
    cerr << "Fatal error: " << errorMessage << endl;
    delete[] arr; // Ensure the array is deallocated even in case of an error
  }

  return 0;
}
  

#include "CornerGrocer.h"
#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;

ItemAnalyzer::ItemAnalyzer() {}

// Method the load the input data
void ItemAnalyzer::loadItem(string& fileName) {
	ifstream inputFile(fileName);  // Open the input file
	string item;  // Define variable to store item from the file

	// Loop to read each item from the file until end
	while (inputFile >> item) {
		itemFreq[item]++;  // Increment the frequency count of current item
	}

	inputFile.close();  // Close the file
}

// Method to save data into an output text file
void ItemAnalyzer::saveItemFreq() {
	ofstream outputFile("frequency.dat");  // Open the output file for writing

	// Start a loop to write data into the output file
	for (const auto& pair : itemFreq) {
		outputFile << pair.first << " " << pair.second << std::endl;  // Write the data into the file
	}

	outputFile.close();  // Close the output file
}

// Method to get the item frequencies
int ItemAnalyzer::getItemFreq(string& item) {
	// Checking if the item exists in the itemFreq map
	if (itemFreq.count(item) == 0) {
		return 0;
	}
	else {
		return itemFreq[item];
	}
}

// Method the print the item and its frequency in the console window
void ItemAnalyzer::printItemFreq() {	
	// Start a loop to print pair of item and its frequency in the map
	for (auto& pair : itemFreq) {
		cout << pair.first << " " << pair.second << endl;
	}
}

// Method to print the histogram with *
void ItemAnalyzer::printItemHistogram() {
	int maxItemLength = 0;
	
	// Find the maximum length of the item name
	for (auto& pair : itemFreq) {
		int itemLength = pair.first.length();
		if (itemLength > maxItemLength) {
			maxItemLength = itemLength;
		}
	}

	// Loop over each item-frequency pair in the map
	for (const auto& pair : itemFreq) {
		cout << setw(maxItemLength) << left << pair.first << " | ";  // Print the item name

		// Print asterisks (*) based on the item's frequency
		for (int i = 0; i < pair.second; i++) {
			cout << "*";
		}
		cout << endl;
	}
}

// Method to print the information at the beginning of the program
void ItemAnalyzer::displayMenu() {
	cout << "\nMenu" << endl;
	cout << "1. Search for an item" << endl;
	cout << "2. Print item frequecies" << endl;
	cout << "3. Print item histogram" << endl;
	cout << "4. Exit" << endl;
	cout << "Enter your choice: ";
}

// Method to run the program
void ItemAnalyzer::run() {
	int choice;  // Define variable for user's choice

	// Start the while loop program
	do {
		displayMenu();  // Display instructions for program
		cin >> choice;  // Enter user's choice

		// Check if the input is valid
		if (cin.fail()) {
			cout << "Invalid input. Please enter a valid choice." << endl;
			cin.clear();                    // Clear the error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n');   // Ignore the remaining input
			continue;                       // Continue to the next iteration of the loop
		}
		
		switch (choice) {
		case 1: {
			string item;
			cout << "Enter the item to search: ";
			cin >> item;
			int freq = getItemFreq(item);  // Get the item's frequency from the input file
			cout << "Frequency of " << item << ": " << freq << endl;  // Print the result
			break;
		}
		case 2: {
			  cout << "Item Frequencies" << endl;
			  printItemFreq();  // Print all the item-frequency from input file
			  break;
		}
		case 3: {
			cout << "Item Histogram" << endl;
			printItemHistogram();  // Print the histogram based on the data input
			break;
		}
		case 4: {
			cout << "Exiting the program..." << endl;  // Exit the program completely
			break;
		}
		default: {  // Case of choice is number but not from 1-4
			cout << "Invalid choice. Please try again with number from 1 to 4." << endl;
			break;
		}
		}
	} while (choice != 4);  // Program will stop as the user enter 4
}

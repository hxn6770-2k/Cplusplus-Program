#include "CornerGrocer.h"

int main() {
	ItemAnalyzer items;  // Creates an instance of the ItemAnalyzer class named items.

	// Load the data from the file
	string fileName = "CS210_Project_Three_Input_File.txt";
	items.loadItem(fileName);

	// Create data file
	items.saveItemFreq();

	// Start the program
	items.run();

	return 0;
}
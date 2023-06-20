#pragma once
#include <string>
#include <map>

using namespace std;

class ItemAnalyzer {
private:
	map<string, int> itemFreq;
public:
	ItemAnalyzer();
	
	void loadItem(string& fileName);
	void saveItemFreq();
	int getItemFreq(string& item);
	void printItemFreq();
	void printItemHistogram();
	void displayMenu();
	void run();
};
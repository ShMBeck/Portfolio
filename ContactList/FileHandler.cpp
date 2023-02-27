// Corner Grocer.
// Shane Beck, 2/19/2023.
#include "FileHandler.h"
#include <map>
#include <iostream>
#include <fstream>

// Constructor.
FileHandler::FileHandler() {

}

// Opens the files.
void FileHandler::OpenFile(std::string name) {
	filein.open(name);
	fileout.open("frequency.dat");
}

// Closes the files.
void FileHandler::CloseFiles() {
	filein.close();
	fileout.close();
}

// Gets the file contents then organizes it into a frequency map.
std::map<std::string, int> FileHandler::getFrequency() {
	std::string word;
	// Loops through each word and counts them as it puts them into the frequency map.
	while (filein >> word) {
		if (frequency.find(word) == frequency.end()) {
			frequency[word] = 1;
		}
		else {
			frequency[word] += 1;
		}
	}

	// Saves the frequency data into frequency.dat.
	for (auto const& pair : frequency) {
		fileout << pair.first << " " << pair.second << std::endl;
	}

	return frequency;
}
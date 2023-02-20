// Corner Grocer.
// Shane Beck, 2/19/2023.
#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <map>

class FileHandler
{

private:
	std::ifstream filein;
	std::ofstream fileout;
	std::map<std::string, int> frequency;

public:
	// Constructor
	FileHandler();

	void OpenFile(std::string name);
	void CloseFiles();
	std::map<std::string, int> getFrequency();

};


// Corner Grocer.
// Shane Beck, 2/19/2023.
#pragma once

#include <string>;
#include "FileHandler.h"

// Menu Manager header file.
class MenuManagement
{

private:
	FileHandler filehandler;

public:
	// Constructor
	MenuManagement();

	int PrintMenu(std::map<std::string, int> frequency);
	void PrintInfo(std::map<std::string, int> frequency, int type);
	void RunChoice(std::map<std::string, int> frequency, int choice);

};


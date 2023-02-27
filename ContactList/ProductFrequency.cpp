// Corner Grocer.
// Shane Beck, 2/19/2023.
#include <map>
#include "MenuManagement.h"
#include "FileHandler.h"

// Main file.
using namespace std;

// Variables.
FileHandler Filehandler;
MenuManagement Menu;
std::map<std::string, int> frequency;

// Main function.
int main() {
	Filehandler.OpenFile("CS210_Project_Three_Input_File.txt");
	std::map<std::string, int> frequency = Filehandler.getFrequency();

	// if the user chooses to exit it will output a -1 here which will end the program.
	int status = Menu.PrintMenu(frequency);
	if (status == -1) {
		Filehandler.CloseFiles();
	}

	return 0;
}
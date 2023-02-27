// Corner Grocer.
// Shane Beck, 2/19/2023.
#include "MenuManagement.h"
#include "FileHandler.h"
#include <iostream>

// Manu manager file.
MenuManagement::MenuManagement() {
    
}

// Prints the menu.
int MenuManagement::PrintMenu(std::map<std::string, int> frequency) {

    std::cout << "********************" << std::endl;
    std::cout << "        Menu" << std::endl;
    std::cout << "********************" << std::endl;
    std::cout << "1 - Get Frequency Of Inputted Word." << std::endl;
    std::cout << "2 - Prints Normal Information Display." << std::endl;
    std::cout << "3 - Prinits Histogram Information Display." << std::endl;
    std::cout << "4 - Exit The Program." << std::endl;
    std::cout << "********************" << std::endl;

    // Loop for managing the input.
    while (true) {
        std::string input;
        std::cin >> input;

        if (std::stoi(input) == 4) {
            // Exits the program
            std::cout << "System: Exiting Program.";
            return -1;
        }
        else {
            MenuManagement::RunChoice(frequency, std::stoi(input));
        }
    }
}

void MenuManagement::PrintInfo(std::map<std::string, int> frequency, int type) {
    // verify type of information display to print.
    // 1 = normal; 2 = histogram.
    if (type == 1) {
        for (auto const& pair : frequency) {
            std::cout << "" << pair.first << " " << pair.second << "\n";
        }
    }
    else if (type == 2) {
        for (auto const& pair : frequency) {
            std::cout << "" << pair.first << " " << std::string(pair.second, '*') << "\n";
        }
    }
    else {
        std::cout << "Error: Invalid information display.";
    }
}

// Runs the selected menu choice.
void MenuManagement::RunChoice(std::map<std::string, int> frequency, int choice) {
    switch (choice) {
    case 1: {
        std::cout << "Please enter the name of the product." << std::endl;
        std::string name;
        std::cin >> name;
        if (!frequency[name]) {
            std::cout << "Exception: Invalid Item" << std::endl;
        }
        else {
            auto it = frequency.find(name);
            std::cout << it->second << std::endl;
        }
        break;
    }
    case 2:
        // Prints out the normal information display.
        MenuManagement::PrintInfo(frequency, 1);
        break;
    case 3:
        // Prints out the histogram information display
        MenuManagement::PrintInfo(frequency, 2);
        break;
    default:
        // Catches Invalid Choices
        std::cout << "Error: Invalid menu choice.";
        break;
    }
}


/*
    Shane Beck
    Project 1 - Clock
    1/22/23
*/
#include "clock.h"
#include <iostream>
#include <string>

using namespace std;
//Program Variables
int hour;
int minute;
int second;

int width = 26;
int numStrings = 4;
string strings[4] = {"Add One Hour", "Add One Minute", "Add One Second", "Exit Program"};

//Getters and Setters
int getHour() {
    return hour;
}

int getMinute() {
    return minute;
}

int getSecond() {
    return second;
}

void setHour(int n) {
    if (n > 24) {
        n = 0;
    }

    hour = n;
}

void setMinute(int n) {
    minute = n;
}

void setSecond(int n) {
    second = n;
}

//Adds one hour to the clock
void addOneHour() {
    if (getHour() + 1 >= 24) {
        setHour(0);
    }
    else {
        setHour(getHour() + 1);
    }
}

//Adds one minute to the clock
void addOneMinute() {
    if (getMinute() + 1 >= 60) {
        setMinute(0);
        addOneHour();
    }
    else {
        setMinute(getMinute() + 1);
    }
}

//Adds one second to the clock
void addOneSecond() {
    if (getSecond() + 1 >= 60) {
        setSecond(0);
        addOneMinute();
    }
    else {
        setSecond(getSecond() + 1);
    }
}

//Function returns the character (c) the specified times (n)
string nCharString(size_t n, char c) {
    return string(n, c);
}

//Function formats the inputted integer to a two digit in the string format
string twoDigitString(unsigned int n) {
    string numToReturn;
    if (n >= 10 && n <= 59) {
        numToReturn = to_string(n);
    }
    else if (n >= 0 && n <= 9) {
        numToReturn = "0" + to_string(n);
    }
    return numToReturn;
}

//Function returns the given time variables in the 24 hour format
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    if (h == 24) {
        h = 0;
    }
    string formatted_h = twoDigitString(h);
    string formatted_m = twoDigitString(m);
    string formatted_s = twoDigitString(s);
    string formatted_time = formatted_h + ":" + formatted_m + ":" + formatted_s;

    return formatted_time;
}

//Function returns the given time variables in the 12 hour format
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    string timeSuffix = "A M";
    if (h >= 12) {
        timeSuffix = "P M";
        h = h - 12;
    }

    if (h == 0) {
        h = 12;
    }

    string formatted_h = twoDigitString(h);
    string formatted_m = twoDigitString(m);
    string formatted_s = twoDigitString(s);

    string formatted_time = formatted_h + ":" + formatted_m + ":" + formatted_s + " " + timeSuffix;

    return formatted_time;
}

//Looks for the users input and checks whether or not it's valid
unsigned int getMenuChoice(int maxChoice) {
    int userInput;
    while (true) {
        cin >> userInput;
        if (userInput > 0 && userInput <= maxChoice) {
            break;
        }
    }
    return userInput;
}

//Prints the menu options.
void printMenu(string strings[], int numStrings, char width) {
    cout << nCharString(width, '*') << endl;
    for (int i = 0; i < numStrings; ++i) {
        string currentOutput = "* " + to_string(i + 1) + " - " + strings[i];
        currentOutput = currentOutput + nCharString(width - (currentOutput.length()) - 1, ' ');
        currentOutput = currentOutput + "*";
        cout << currentOutput << endl;
        if (i != numStrings - 1) {
            cout << endl;
        }
    }
    cout << nCharString(width, '*') << endl;
}

/**
 * Display the clocks
 *
 * @param h, hours 0 to 23
 * @param m, minutes 0 to 59
 * @param s, seconds 0 to 59
 */
void displayClocks(int h, int m, int s) {
    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
    cout << "*" << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << "*" << nCharString(3, ' ');
    cout << "*" << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << "*" << endl;
    cout << endl;
    cout << "*" << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << "*" << nCharString(3, ' ');
    cout << "*" << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << "*" << endl;
    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
}

//Starts the main menu input
void mainMenu() {
    while (true) {
        int userInput = getMenuChoice(4);

        if (userInput == 4) {
            break;
        }

        switch (userInput) {
            case 1:
                addOneHour();
                system("cls");
                displayClocks(hour, minute, second);
                printMenu(strings, numStrings, width);
                break;
            case 2:
                addOneMinute();
                system("cls");
                displayClocks(hour, minute, second);
                printMenu(strings, numStrings, width);
                break;
            case 3:
                addOneSecond();
                system("cls");
                displayClocks(hour, minute, second);
                printMenu(strings, numStrings, width);
                break;
        }
    }
}

void main() {
    //Enter the current time values
    cin >> hour;
    cin >> minute;
    cin >> second;
    //Start the necessary functions
    displayClocks(hour, minute, second);
    printMenu(strings, numStrings, width);
    mainMenu();
}
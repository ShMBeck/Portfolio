#include <iostream>
#include <iomanip>
#include <string>
#include "Finances.h"

using namespace std;

Finances financial;

// Used to print details when printing the menus.
void printDetails(double year, double yearEndBalance, double interestEarned) {
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	cout << "  " << year << "        $" << yearEndBalance << "           $" << interestEarned << endl;
}

// Calculates the balance without a monthly deposit.
double calculateBalanceWithoutMonthlyDeposit() {
	double balance = financial.getInitialInvestment();
	// Begin For-Loop For Each Year.
	for (int year = 1; year <= financial.getNumYears(); year++) {
		double interestEarned = 0;

		// Calculate Monthly Compounding.
		for (int month = 1; month <= 12; month++) {
			double interest = (balance + interestEarned) * ((financial.getAnnualInterest() / 100) / 12);
			interestEarned += interest;
		}

		// Add Interest to Balance.
		balance += interestEarned;

		// Print Yearly Details.
		printDetails(year, balance + interestEarned, interestEarned);
	}

	return balance;
}

// Calculates the balance with a monthly deposit.
double calculateBalanceWithMonthlyDeposit() {
	double balance = financial.getInitialInvestment();
	// Begin For-Loop For Each Year.
	for (int year = 0; year < financial.getNumYears(); year++) {
		double interestEarned = 0;

		// Calculate Monthly Compounding.
		for (int month = 1; month <= 12; month++) {
			double interest = (balance + interestEarned) * ((financial.getAnnualInterest() / 100) / 12);
			interestEarned += interest;
			balance += financial.getAnnualInterest();
		}

		// Add Interest to Balance Plus Monthly Deposits.
		balance += interestEarned;

		// Print Yearly Details.
		printDetails(year + 1, balance, interestEarned);
	}

	return balance;
}

// Displays the input menu
void displayMenu() {
	// Temporary variables for getting input.
	double initInvestment = 0;
	double monthlyDeposit = 0;
	double annualinterest = 0;
	double numYears = 0;

	while (true) {
		// Below here we display the menu as well as get the user inputs.
		cout << "************************" << endl;
		cout << "****** Data Input ******" << endl;
		cout << endl;
		cout << "Initial Investment Amount: " << endl;
		cin >> initInvestment;
		financial.SetInitInvestment(initInvestment);
		cout << endl << "Monthly Deposit: " << endl;
		cin >> monthlyDeposit;
		financial.SetMonthlyDeposit(monthlyDeposit);
		cout << endl << "Annual Interest: " << endl;
		cin >> annualinterest;
		financial.SetAnnualInterest(annualinterest);
		cout << endl << "Number Of Years: " << endl;
		cin >> numYears;
		financial.SetNumYears(numYears);

		cout << endl;
		cout << "Balance Without Monthly Deposits" << endl;
		cout << "Year	End Of Year Interest	Years" << endl;
		calculateBalanceWithoutMonthlyDeposit();

		cout << endl;
		cout << "Balance With Monthly Deposits" << endl;
		cout << "Year	End Of Year Interest	Years" << endl;
		calculateBalanceWithMonthlyDeposit();

		cout << "Enter N to Enter New Values: " << endl;
		string input;
		cin >> input;
		if (input != "N") {
			break;
		}
		cout << endl;
	}
}

int main() {
	displayMenu();
	return 0;
}
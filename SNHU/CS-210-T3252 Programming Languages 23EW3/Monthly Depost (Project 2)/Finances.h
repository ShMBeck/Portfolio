#pragma once
class Finances
{

private:

	// The variables that we must keep track of for our program to function as intended.
	double initial_investment;
	double monthly_deposit;
	double annual_interest;
	double num_years;


public:

	// Constructor
	Finances();

	// Setters
	void SetInitInvestment(double init);
	void SetMonthlyDeposit(double deposit);
	void SetAnnualInterest(double interest);
	void SetNumYears(double years);

	// Getters
	double getInitialInvestment() { return initial_investment; }
	double getMonthlyDeposit() { return monthly_deposit; }
	double getAnnualInterest() { return annual_interest; }
	double getNumYears() { return num_years; }

};
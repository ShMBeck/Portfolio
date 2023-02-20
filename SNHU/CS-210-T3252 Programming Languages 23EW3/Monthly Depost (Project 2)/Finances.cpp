#include "Finances.h"

Finances::Finances() {
	double initial_investment = 0;
	double monthly_deposit = 0;
	double annual_interest = 0;
	double num_years = 0;
}

void Finances::SetInitInvestment(double init) {
	initial_investment = init;
}
void Finances::SetMonthlyDeposit(double deposit) {
	monthly_deposit = deposit;
}
void Finances::SetAnnualInterest(double interest) {
	annual_interest = interest;
}
void Finances::SetNumYears(double years) {
	num_years = years;
}
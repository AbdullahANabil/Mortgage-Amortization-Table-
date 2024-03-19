//Program listing:

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

//The constant values allow for changes
//without needing to go to the code 
//itself and make changes one by one.
//Assignment say to make the
//constants global variables
const double UPPER_LOAN = 9999999;
const double UPPER_RATE = 30;
const double UPPER_YEAR = 99;
const double UPPER_PRINCIPAL = 9999999;
const double TERMS_IN_YEAR = 12;
const int PERCENTAGE = 100;

int main()
{
	//The date is just the i in the
	//formulas. A better name would
	//probably be term.
	double loan_amount, annual_rate, add_principal, year;
	double monthly_payment, actual_payment, interest, principal, balance;
	string file_name;
	int date = 0;

	//Loops for the input validation
	do
	{
		cout << "Enter Loan amount (0-9999999), for example 300000.90: ";
		cin >> loan_amount;
	} while (loan_amount <= 0 || loan_amount > UPPER_LOAN);
	do
	{
		cout << "Enter annual interest rate(0-30), for example 4.25 meaning 4.25%: ";
		cin >> annual_rate;
	} while (annual_rate <= 0 || annual_rate > UPPER_RATE);
	do
	{
		cout << "Enter no. of years as integer(1-99), for example 30: ";
		cin >> year;
	} while (year <= 1 || year > UPPER_YEAR);
	do
	{
		cout << "Enter additional principal per month (0-9999999), for example 300: ";
		cin >> add_principal;
	} while (add_principal < 0 || add_principal > UPPER_PRINCIPAL);

	cout << "Send the mortgage amortization table to a file (enter file name): ";
	cin >> file_name;
	ofstream outFile;
	outFile.open(file_name + ".txt");

	//The formulas to get the main values
	annual_rate = annual_rate / PERCENTAGE;
	monthly_payment = (loan_amount * annual_rate / TERMS_IN_YEAR) / (1 - 1 / pow(1 + annual_rate / TERMS_IN_YEAR, year * TERMS_IN_YEAR));
	actual_payment = monthly_payment + add_principal;
	balance = loan_amount;


	//Displaying the initial values with proper spacing and format
	//The specific setw numbers were chosen to look
	//similar to the professor's output from the zip file.
	//The default setw should work here as well if placed after
	//the strings. But I was just trying out the left 
	//orientation here. 
	outFile << "\n\n\n" << setw(38) << "MORTGAGE AMORTIZATION TABLE\n\n";
	outFile << setw(24) << left << "Amount: " << fixed << setprecision(2) << showpoint << "$" << loan_amount << endl;
	outFile << setw(24) << left << "Interest Rate: " << fixed << setprecision(3) << showpoint << annual_rate * 100 << "%\n";
	outFile << setw(24) << left << "Term(Years): " << fixed << setprecision(0) << noshowpoint << year << "\n";
	outFile << setw(24) << left << "Monthly Payment: " << fixed << setprecision(2) << showpoint << "$" << monthly_payment << "\n";
	outFile << setw(24) << left << "Additional Principal: " << fixed << setprecision(2) << showpoint << "$" << add_principal << "\n";
	outFile << setw(24) << left << "Actual Payment: " << fixed << setprecision(2) << showpoint << "$" << actual_payment << "\n";
	outFile << "\n\n\n";
	outFile << "\t\t" << "Principal" << "\t\t" << "Interest" << "\t\t" << "Balance";
	outFile << "\n";

	//The loop to calculate the interest, principal, and balance
	//and display them. Uses an if statement to make sure
	//balance does not go into negative when balance goes
	//below principal. Uses an if statement in the output
	//to format the first row in the table since that is
	//the only row that displays the dollar sign.
	while (balance > 0 && date <= year * TERMS_IN_YEAR)
	{
		interest = balance * annual_rate / TERMS_IN_YEAR;
		principal = actual_payment - interest;
		if (balance < principal)
		{
			principal = balance;
		}
		balance = balance - principal;
		date++;
		outFile << fixed << setprecision(2) << showpoint;
		if (date == 1)
		{
			outFile << date;
			outFile << setw(8) << right << "$" << setw(15) << principal;
			outFile << setw(9) << "$" << setw(15) << interest;
			outFile << setw(9) << "$" << setw(17) << balance;
			outFile << endl;
		}
		else
		{
			outFile << setw(4) << left << date;
			outFile << setw(20) << right << principal;
			outFile << setw(24) << interest;
			outFile << setw(26) << balance;
			outFile << endl;
		}
	}
	outFile.close();
	return 0;
}

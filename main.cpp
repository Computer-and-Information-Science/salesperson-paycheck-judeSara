#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string filename;
    cout << "Enter the name of the input file: ";
    cin >> filename;

    ifstream infile(filename);
    if (!infile) {
        cerr << "Error: Cannot open file " << filename << endl;
        return 1;
    }

    // Input variables
    string firstName, lastName;
    double baseSalary, commissionPercent, totalSales, expenses;

    // Read from file
    infile >> firstName >> lastName;
    infile >> baseSalary >> commissionPercent;
    infile >> totalSales;
    infile >> expenses;

    infile.close();

    // Calculations
    double commission = totalSales * (commissionPercent / 100.0);
    double total = baseSalary + commission - expenses;

    // Output
    cout << fixed << setprecision(2);
    cout << "\nPayroll data for " << firstName << " " << lastName << "\n\n";

    cout << "Base Salary:" << setw(11) << baseSalary << endl;
    cout << "Commission:" << setw(11) << commission 
         << " (" << setprecision(1) << commissionPercent << "% of " 
         << fixed << setprecision(2) << totalSales << ")" << endl;
    cout << "Expenses:" << setw(13) << expenses << endl;
    cout << "               --------" << endl;
    cout << "Total:" << setw(16) << total << endl;

    return 0;
}

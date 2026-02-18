#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    // Named constants
    const double PLAN_A_PRICE = 39.99;
    const double PLAN_B_PRICE = 59.99;
    const double PLAN_C_PRICE = 79.99;

    const double PLAN_A_GB = 2.0;
    const double PLAN_B_GB = 8.0;

    const double ADDITIONAL_COST = 8.00;

    string customerName;
    char plan;
    double gigabytesUsed;
    double totalBill = 0.0;

    cout << "Enter customer name: ";
    getline(cin, customerName);

    cout << "Enter plan (A, B, or C): ";
    cin >> plan;

    cout << "Enter gigabytes used: ";
    cin >> gigabytesUsed;

    if (gigabytesUsed < 0) {
        cout << "Data usage cannot be negative." << endl;
        return 1;
    }

    plan = toupper(plan);

    // Calculate bill
    if (plan == 'A') {
        totalBill = PLAN_A_PRICE;
        if (gigabytesUsed > PLAN_A_GB) {
            totalBill += (gigabytesUsed - PLAN_A_GB) * ADDITIONAL_COST;
        }
    }
    else if (plan == 'B') {
        totalBill = PLAN_B_PRICE;
        if (gigabytesUsed > PLAN_B_GB) {
            totalBill += (gigabytesUsed - PLAN_B_GB) * ADDITIONAL_COST;
        }
    }
    else if (plan == 'C') {
        totalBill = PLAN_C_PRICE;
    }
    else {
        cout << "Invalid plan selected." << endl;
        return 1;
    }

    cout << fixed << setprecision(2);

    cout << "\n----- Monthly Bill -----\n";
    cout << "Customer Name: " << customerName << endl;
    cout << "Plan: " << plan << endl;
    cout << "Data Used: " << gigabytesUsed << " GB\n";
    cout << "Total Amount Due: $" << totalBill << endl;

    // Calculate possible savings
    if (plan == 'A') {
        double costWithB = PLAN_B_PRICE;
        if (gigabytesUsed > PLAN_B_GB) {
            costWithB += (gigabytesUsed - PLAN_B_GB) * ADDITIONAL_COST;
        }

        double costWithC = PLAN_C_PRICE;

        if (costWithB < totalBill) {
            cout << "You would save $" << totalBill - costWithB
                 << " by switching to Plan B.\n";
        }

        if (costWithC < totalBill) {
            cout << "You would save $" << totalBill - costWithC
                 << " by switching to Plan C.\n";
        }
    }

    if (plan == 'B') {
        double costWithC = PLAN_C_PRICE;

        if (costWithC < totalBill) {
            cout << "You would save $" << totalBill - costWithC
                 << " by switching to Plan C.\n";
        }
    }

    return 0;
}

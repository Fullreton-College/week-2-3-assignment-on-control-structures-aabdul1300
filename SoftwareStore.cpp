#include <iostream>
#include <iomanip>
using namespace std;
int main()
{

    const double RETAIL_PRICE = 199.00;
    int quantity;
    double discountRate = 0.0;

    cout << "Enter number of units purchased: ";
    cin >> quantity;

    if (quantity <= 0) {
        cout << "Quantity must be greater than 0. " << endl;
        return 1;

    }

    if (quantity >= 100) {
        discountRate = 0.50;

    }
    else if (quantity >= 50) {
        discountRate = 0.40;
    }

    else if (quantity >= 20) {
        discountRate = 0.30;
    }

    else if (quantity >= 10) {
        discountRate = 0.20;
    }

    else {     
        discountRate = 0.0; 
         }
    
    double subtotal = quantity * RETAIL PRICE;
    double totalCost = subtotal * (1.0 - discountRate);

    cout << fixed << setprecision(2);
    cout << "Subtotal: $" << subtotal << endl;
    cout << "Discount Rate: " << discountRate * 100 << "%" << endl;
    cout << "Total Cost: $" << totalCost << endl;







    return 0;

}

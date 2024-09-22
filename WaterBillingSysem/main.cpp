#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Constants for water unit prices and charges
    const int RATE1 = 150;   // For the first 10 units
    const int RATE2 = 175;   // For the next 10 units (11-20)
    const int RATE3 = 200;   // For units beyond 20
    const double SURCHARGE = 0.15;  // 15% surcharge
    const double VAT = 0.18;  // 18% VAT

    double balance, totalCost = 0.0;
    int units;

    // Step (i): Input the user's balance and the number of units consumed
    cout << "Enter the amount of money loaded onto your account (UGX): ";
    cin >> balance;
    cout << "Enter the number of water units consumed: ";
    cin >> units;

    // Step (ii): Calculate total cost based on the tiered pricing structure
    if (units <= 10) {
        totalCost = units * RATE1;
    } else if (units <= 20) {
        totalCost = (10 * RATE1) + (units - 10) * RATE2;
    } else {
        totalCost = (10 * RATE1) + (10 * RATE2) + (units - 20) * RATE3;
    }

    // Step (iii): Apply the 15% surcharge
    double surchargeAmount = totalCost * SURCHARGE;
    totalCost += surchargeAmount;

    // Step (iv): Add 18% VAT to the total cost
    double vatAmount = totalCost * VAT;
    totalCost += vatAmount;

    // Step (iv): Check if the balance is sufficient to cover the total cost
    if (balance >= totalCost) {
        // Step (v): Deduct the total cost from balance and show the remaining balance
        balance -= totalCost;
        cout << fixed << setprecision(2); // Set precision for currency display
        cout << "Total cost (including surcharge and VAT): " << totalCost << " UGX" << endl;
        cout << "Transaction successful! Remaining balance: " << balance << " UGX" << endl;
    } else {
        // If the balance is insufficient, show an error message
        cout << fixed << setprecision(2);
        cout << "Insufficient balance! You need " << totalCost << " UGX but only have " << balance << " UGX." << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int amount {0};
    const int dollar {100};
    const int quarter {25};
    const int dime {10};
    const int penny {5};
    const int nickel {1};
    cout << "Enter amount of cents: " << endl;
    cin >> amount;
    int amount_dollars = amount / dollar;
    amount -= amount_dollars * dollar;
    int amount_quarters = amount / quarter;
    amount -= amount_quarters * quarter;
    int amount_dimes = amount / dime;
    amount -= amount_dimes * dime;
    int amount_pennies = amount / penny;
    amount -= amount_pennies * penny;
    int amount_nickels = amount / nickel;
    
    cout << amount_dollars << endl;
    cout << amount_quarters << endl;
    cout << amount_dimes << endl;
    cout << amount_pennies << endl;
    cout << amount_nickels << endl;
}

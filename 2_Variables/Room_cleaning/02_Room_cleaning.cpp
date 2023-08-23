#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    const int price_large {30};
    const int price_small {25};
    const float tax {0.06};
    int rooms_small {0};
    int rooms_large {0};
    cout << "Please enter the amount of small rooms you would like cleaned: " << endl;
    cin >> rooms_small;
    cout << "Please enter the amount of large rooms you would like cleaned: " << endl;
    cin >> rooms_large;
    int final {0};
    float final_tax {0.0};
    final = price_small * rooms_small + price_large * rooms_large;
    final_tax = final * tax;
    cout << "Tax: " << final_tax << endl;
    cout << "Price: " << final << endl;
}

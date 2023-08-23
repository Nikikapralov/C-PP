#include <iostream>
using namespace std;

void main(int age, bool parental_consent, bool ssn, bool accidents) {
    
    
    if ((age >= 18 || (age > 15 && parental_consent)) && ssn && !accidents)
        cout << "Yes, you can work.";

    return;
}

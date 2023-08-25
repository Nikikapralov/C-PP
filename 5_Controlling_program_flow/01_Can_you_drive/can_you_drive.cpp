#include <iostream>
using namespace std;

void can_you_drive(int age) {
    //----WRITE YOUR CODE BELOW THIS LINE----

    if (age >= 16) {
        cout << "Yes - you can drive!";
    }

    //----WRITE YOUR CODE ABOVE THIS LINE----
}

int main() {
    int age { 23 };
    can_you_drive(age);

}
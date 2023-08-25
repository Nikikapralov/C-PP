#include <iostream>
using namespace std;

int get_remaining_years(int age, int driving_age = 16);

/* The thing above is called a function prototype. It is needed since the compiler must know what the function types are
and how to access the function. We can set default values in the function prototype. */

void can_you_drive(int age) {
    //----WRITE YOUR CODE BELOW THIS LINE----
    if (age >= 16) {
        cout << "Yes - you can drive!";
    }

    else {
        int remaining_years = get_remaining_years(age = age);
        cout << "Sorry, come back in " << age << " years.";
    }




    //----WRITE YOUR CODE ABOVE THIS LINE----
}

void main() {
    int age_1{ 10 };
    int age_2{ 50 };
    can_you_drive(age_1);
    can_you_drive(age_2);
}

int get_remaining_years(int age, int driving_age) {
    int remaining_years = driving_age - age;
    return remaining_years;
}
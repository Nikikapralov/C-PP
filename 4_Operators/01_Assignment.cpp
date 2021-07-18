#include <iostream>
#include <tuple>
using namespace std;

void assignment_operator() {
    int num1 {13};
    int num2 {0};
    num1 = 5;
    num2 = num1;
   
   cout << num1 << " " << num2;
}
#include "dog.h"
#include<iostream>

using std::cout, std::endl;

Dog test_dog();


void main() {
	test_dog();
};

Dog test_dog() {
	Dog spot = Dog();
	spot.name = "Spot";
	spot.age = 5;
	return spot;
};
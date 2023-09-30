#include "Dog.h"
#include<iostream>

using std::cout;

void main() {
	Dog nott = Dog();
	cout << nott.get_age() << " " << nott.get_name() << std::endl;
	Dog spot = Dog("Woooaf", 102);
	cout << spot.get_age() << " " << spot.get_name() << std::endl;
	spot.set_age(10);
	spot.set_name("Spot");
	cout << spot.get_age() << " " << spot.get_name() << " " << spot.speak() << " " << spot.get_human_years() << std::endl;
	Dog new_dog{ spot};
	cout << new_dog.get_age() << " " << new_dog.get_name() << std::endl;
}
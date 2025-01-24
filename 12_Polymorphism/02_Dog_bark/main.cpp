#include<iostream>
#include"Dog.h"
#include<memory>

void main() {
	std::unique_ptr<Animal> my_dog = std::make_unique<Dog>("Russel", 8);
	std::cout << (*my_dog).get_noise();
};
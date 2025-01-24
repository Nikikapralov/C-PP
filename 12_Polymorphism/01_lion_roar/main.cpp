#include<iostream>
#include<memory>
#include"Lion.h"

void main() {
	std::unique_ptr<Animal> my_lion = std::make_unique<Lion>();
	std::cout << (*my_lion).get_noise() << std::endl;
	std::cout << (*my_lion).get_num_legs() << std::endl;
};
#pragma once
#ifndef DOG_H
#define DOG_H

#include "Animal.h"
#include <string>

// Declare the Dog class below this line
class Dog : public Animal {
	public:
		Dog(const std::string&, int);
		virtual std::string get_noise() override;
		virtual int get_num_legs() override;

};

// Declare the Dog class above this line

#endif /* DOG_H */

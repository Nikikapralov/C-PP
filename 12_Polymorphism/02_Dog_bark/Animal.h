#pragma once
/*****************************/
/** DO NOT MODIFY THIS FILE **/
/*****************************/

// Note that we do NOT need an Animal.cpp file since we variable
// implementing the get_name() and get_age() methods inline here
#ifndef ANIMAL_H  
#define ANIMAL_H  

#include <string>  

// Define the base class Animal
class Animal {
protected:
    std::string name;  // Member variable for the animal's name
    int age;           // Member variable for the animal's age
public:
    // Constructor for Animal class that initializes name and age
    Animal(const std::string& name, int age) : name{ name }, age{ age } {}
    virtual ~Animal() {};

    // Pure virtual function for getting the noise an animal makes
    virtual std::string get_noise() = 0;

    // Pure virtual function for getting the number of legs an animal has
    virtual int get_num_legs() = 0;

    // Function for getting the name of the animal
    virtual std::string get_name() { return name; }

    // Function for getting the age of the animal
    virtual int get_age() { return age; }
};

#endif 
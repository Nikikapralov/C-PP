/*****************************/
/** DO NOT MODIFY THIS FILE **/
/*****************************/

#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

// Abstract base class Animal

class Animal {
public:
    virtual std::string get_noise() = 0; // Pure virtual function
    virtual int get_num_legs() = 0; // Pure virtual function
    virtual ~Animal() {};
};

#endif /* ANIMAL_H */
#pragma once

#pragma once
#ifndef _DOG_H_
#define _DOG_H_
#include <string>
using std::string;


class Dog {
    private:
        string name;
        int age;
    public:
        Dog(string name_val = "None", int age_val = 0) : name(name_val), age(age_val) {};
        Dog(const Dog& source) : Dog(source.name, source.age) {};

        string get_name() {
            return name;
        };
        void set_name(string new_name) {
            name = new_name;
        };
        int get_age() {
            return age;
        };
        void set_age(int new_age) {
            age = new_age;
        };
        int get_human_years() {
            return age * 7;
        };
        string speak() {
            return "Woof";
        };

};


#endif
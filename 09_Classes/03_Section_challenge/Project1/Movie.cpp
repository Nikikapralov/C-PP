#include<iostream>
#include"Movie.h"
#include<vector>
#include"utils.cpp"
#include<stdexcept>
using std::cout, std::endl, std::invalid_argument;

const vector<string> Movie::available_ratings{ "G", "PG", "PG-13", "R" };

void Movie::display_data() {
	cout << "=========================" << endl;
	cout << this->name << " " << this->rating << " " << this->watched << endl;
	cout << "=========================" << endl;
};

Movie::Movie(string name, string rating, int watched) : name(name), watched(watched) {
	set_rating(rating);
	cout << "Added movie with name " << name << ", rating: " << rating << " and watched count " << watched << endl;
};

string Movie::get_rating() { return this->rating; };

void Movie::set_rating(string rating) {
	if (contains<string>(this->available_ratings, rating)) {
		this->rating = rating;
	}
	else {
		cout << "Error: Unknown rating." << endl;
		throw invalid_argument("Value not in allowed ratings.");
	}
	
};

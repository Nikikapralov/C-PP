#include <iostream>
#include "utils.cpp"
#include <vector>
#include <string>
#include "Movie.h"
#include "Movies.h"
#include <stdexcept>

using std::cout, std::endl, std::vector, std::string, std::invalid_argument;

vector<string> Movies::get_movies_names() {
	vector<string> result;
	for (auto &entry : this->movies_collection) {
		result.push_back(entry.name);
	}
	return result;
}


Movies* Movies::add_movie(string name, string rating, int watched) {
	vector<string> movies_names_list = get_movies_names();
	if (contains<string>(movies_names_list, name)) {
		throw invalid_argument("This movie has already been added to the list!");
	}
	
	this->movies_collection.push_back(Movie(name, rating, watched));

	return this;
}

Movies* Movies::increment_movie_watch_count(string movie_name){
	vector<string> movies_names_list = get_movies_names();
	if (!(contains<string>(movies_names_list, movie_name))) {
		throw invalid_argument("This movie does not exist!");
	}

	for (auto& movie : this->movies_collection) {
		if (movie.name == movie_name) {
			++movie.watched;
			return this;
		}
	}
}

Movies* Movies::display_all_movies() {
	for (auto& movie : this->movies_collection) {
		movie.display_data();
	}
	return this;
}

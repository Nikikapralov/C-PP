#include <iostream>
#include<string>
#include "Movie.h"
#include "Movies.h"

using std::cout, std::endl, std::string;

void main() {
	Movies my_movie_collection = Movies();
	my_movie_collection.add_movie("Harry Potter", "G", 10)->add_movie("LOTR", "R")->increment_movie_watch_count("Harry Potter")->increment_movie_watch_count("LOTR")->display_all_movies();
};
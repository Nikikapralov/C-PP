#ifndef _MOVIES_H_
#define _MOVIES_H_
#include <iostream>
#include <vector>
#include <string>
#include "Movie.h"
using std::cout, std::endl, std::string, std::vector;

class Movies {
	private:
		vector<Movie> movies_collection;
		vector<string> get_movies_names();

	public:
		Movies* add_movie(string, string, int=0);
		Movies* increment_movie_watch_count(string);
		Movies* display_all_movies();
};

#endif // !

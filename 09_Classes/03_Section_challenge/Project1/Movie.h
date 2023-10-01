#ifndef _MOVIE_H_
#define _MOVIE_H_
#include<string>
#include<vector>
using std::string, std::vector;

class Movie {
	private:
		static const vector<string> available_ratings;
		string rating;

	public:
		string name;
		int watched;
		void display_data();
		string get_rating();
		void set_rating(string);
		Movie(string, string, int=0);
};

#endif _MOVIE_H_


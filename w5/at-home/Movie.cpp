//-------------------------------------------------------------------------------------------------------------
// Name:    Haibo Zheng
// Seneca Student ID:   164732182
// Seneca email:    hzheng62@myseneca.ca
// Date of completion:  2/3/2020
//
// I confirm that the content of this file is created by me,  with the exception of the parts provided to me by my professor.
//-------------------------------------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include "Movie.h"

using namespace std;

namespace sdds {
    Movie::Movie(const string& str) {
        char garbage{};
        stringstream record(str);

        if (record) {
            getline(record, MovieInfo.author, ',');
            eraseSpace(MovieInfo.author);
            getline(record, MovieInfo.title, ',');
            eraseSpace(MovieInfo.title);
            getline(record, MovieInfo.country, ',');
            eraseSpace(MovieInfo.country);
            record >> MovieInfo.price >> garbage
                >> MovieInfo.year >> garbage;
            getline(record, MovieInfo.summary, '\n');
            eraseSpace(MovieInfo.summary);
        }

    }

    void Movie::eraseSpace(string& str) {
        if (!str.empty()) {
            str.erase(0, str.find_first_not_of(" "));
            str.erase(str.find_last_not_of(" ") + 1);
        }
    }

    const std::string& Movie::title() const {
        return MovieInfo.title;
    }
    const string& Movie::country() const {
        return MovieInfo.country;
    }
    const size_t& Movie::year() const {
        return MovieInfo.year;
    }
    double& Movie::price() {
        return MovieInfo.price;
    }





    ostream& operator<<(ostream& os, const Movie& Movie) {
        string str{ " | " };
        os << setw(20) << Movie.MovieInfo.author << str
            << setw(22) << Movie.MovieInfo.title << str
            << setw(5) << Movie.MovieInfo.country << str
            << setw(4) << Movie.MovieInfo.year << str
            << setw(6) << fixed << setprecision(2) << Movie.MovieInfo.price << str
            << Movie.MovieInfo.summary<<endl;


        return os;
    }
}
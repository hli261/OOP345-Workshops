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

        stringstream record(str);
        string temp{};

        if (record) {
            getline(record, m_title, ',');
            eraseSpace(m_title);


            getline(record, temp, ',');
            eraseSpace(temp);
            m_year = stoi(temp);

            getline(record, m_summary, '\n');
            eraseSpace(m_summary);
        }

    }

    void Movie::eraseSpace(string& str) {
        if (!str.empty()) {
            str.erase(0, str.find_first_not_of(" "));
            str.erase(str.find_last_not_of(" ") + 1);
        }
    }

    const std::string& Movie::title() const {
        return m_title;
    }






    ostream& operator<<(ostream& os, const Movie& Movie) {
        string str{ " | " };
        os << setw(40) << Movie.m_title << str
            << setw(4) << Movie.m_year << str
            << Movie.m_summary << endl;


        return os;
    }
}
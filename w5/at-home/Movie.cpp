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
#include "Moive.h"

using namespace std;

namespace sdds {
    Moive::Moive(const string& str) {
        char garbage{};
        stringstream record(str);

        if (record) {
            getline(record, MoiveInfo.author, ',');
            eraseSpace(MoiveInfo.author);
            getline(record, MoiveInfo.title, ',');
            eraseSpace(MoiveInfo.title);
            getline(record, MoiveInfo.country, ',');
            eraseSpace(MoiveInfo.country);
            record >> MoiveInfo.price >> garbage
                >> MoiveInfo.year >> garbage;
            getline(record, MoiveInfo.summary, '\n');
            eraseSpace(MoiveInfo.summary);
        }

    }

    void Moive::eraseSpace(string& str) {
        if (!str.empty()) {
            str.erase(0, str.find_first_not_of(" "));
            str.erase(str.find_last_not_of(" ") + 1);
        }
    }

    const std::string& Moive::title() const {
        return MoiveInfo.title;
    }
    const string& Moive::country() const {
        return MoiveInfo.country;
    }
    const size_t& Moive::year() const {
        return MoiveInfo.year;
    }
    double& Moive::price() {
        return MoiveInfo.price;
    }





    ostream& operator<<(ostream& os, const Moive& Moive) {
        string str{ " | " };
        os << setw(20) << Moive.MoiveInfo.author << str
            << setw(22) << Moive.MoiveInfo.title << str
            << setw(5) << Moive.MoiveInfo.country << str
            << setw(4) << Moive.MoiveInfo.year << str
            << setw(6) << fixed << setprecision(2) << Moive.MoiveInfo.price << str
            << Moive.MoiveInfo.summary<<endl;


        return os;
    }
}
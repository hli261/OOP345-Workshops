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
#include "SpellChecker.h"

using namespace std;

namespace sdds {
    SpellChecker::SpellChecker(const string& str) {
        char garbage{};
        stringstream record(str);

        if (record) {
            getline(record, SpellCheckerInfo.author, ',');
            eraseSpace(SpellCheckerInfo.author);
            getline(record, SpellCheckerInfo.title, ',');
            eraseSpace(SpellCheckerInfo.title);
            getline(record, SpellCheckerInfo.country, ',');
            eraseSpace(SpellCheckerInfo.country);
            record >> SpellCheckerInfo.price >> garbage
                >> SpellCheckerInfo.year >> garbage;
            getline(record, SpellCheckerInfo.summary, '\n');
            eraseSpace(SpellCheckerInfo.summary);
        }

    }

    void SpellChecker::eraseSpace(string& str) {
        if (!str.empty()) {
            str.erase(0, str.find_first_not_of(" "));
            str.erase(str.find_last_not_of(" ") + 1);
        }
    }

    const std::string& SpellChecker::title() const {
        return SpellCheckerInfo.title;
    }
    const string& SpellChecker::country() const {
        return SpellCheckerInfo.country;
    }
    const size_t& SpellChecker::year() const {
        return SpellCheckerInfo.year;
    }
    double& SpellChecker::price() {
        return SpellCheckerInfo.price;
    }





    ostream& operator<<(ostream& os, const SpellChecker& SpellChecker) {
        string str{ " | " };
        os << setw(20) << SpellChecker.SpellCheckerInfo.author << str
            << setw(22) << SpellChecker.SpellCheckerInfo.title << str
            << setw(5) << SpellChecker.SpellCheckerInfo.country << str
            << setw(4) << SpellChecker.SpellCheckerInfo.year << str
            << setw(6) << fixed << setprecision(2) << SpellChecker.SpellCheckerInfo.price << str
            << SpellChecker.SpellCheckerInfo.summary<<endl;


        return os;
    }
}
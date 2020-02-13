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
#include "Collection.h"

using namespace std;

namespace sdds {
    Collection::Collection(const string& str) {
        char garbage{};
        stringstream record(str);

        if (record) {
            getline(record, CollectionInfo.author, ',');
            eraseSpace(CollectionInfo.author);
            getline(record, CollectionInfo.title, ',');
            eraseSpace(CollectionInfo.title);
            getline(record, CollectionInfo.country, ',');
            eraseSpace(CollectionInfo.country);
            record >> CollectionInfo.price >> garbage
                >> CollectionInfo.year >> garbage;
            getline(record, CollectionInfo.summary, '\n');
            eraseSpace(CollectionInfo.summary);
        }

    }

    void Collection::eraseSpace(string& str) {
        if (!str.empty()) {
            str.erase(0, str.find_first_not_of(" "));
            str.erase(str.find_last_not_of(" ") + 1);
        }
    }

    const std::string& Collection::title() const {
        return CollectionInfo.title;
    }
    const string& Collection::country() const {
        return CollectionInfo.country;
    }
    const size_t& Collection::year() const {
        return CollectionInfo.year;
    }
    double& Collection::price() {
        return CollectionInfo.price;
    }





    ostream& operator<<(ostream& os, const Collection& Collection) {
        string str{ " | " };
        os << setw(20) << Collection.CollectionInfo.author << str
            << setw(22) << Collection.CollectionInfo.title << str
            << setw(5) << Collection.CollectionInfo.country << str
            << setw(4) << Collection.CollectionInfo.year << str
            << setw(6) << fixed << setprecision(2) << Collection.CollectionInfo.price << str
            << Collection.CollectionInfo.summary<<endl;


        return os;
    }
}
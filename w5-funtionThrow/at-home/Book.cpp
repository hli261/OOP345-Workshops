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
#include "Book.h"

using namespace std;

namespace sdds {
    Book::Book(const string& str) {
        stringstream record(str);
        string temp;
        if (record) {
            getline(record, bookInfo.author, ',');
            eraseSpace(bookInfo.author);
            getline(record, bookInfo.title, ',');
            eraseSpace(bookInfo.title);
            getline(record, bookInfo.country, ',');
            eraseSpace(bookInfo.country);

            getline(record, temp, ',');
            eraseSpace(temp);
            bookInfo.price = stod(temp);

            getline(record, temp, ',');
            eraseSpace(temp);
            bookInfo.year = stoi(temp);

            getline(record, bookInfo.summary, '\n');
            eraseSpace(bookInfo.summary);
        }

    }

    void Book::eraseSpace(string& str) {
        if (!str.empty()) {
            str.erase(0, str.find_first_not_of(" "));
            str.erase(str.find_last_not_of(" ") + 1);
        }

        /*//////////////////////////////////////////////////////
        //reuse the function from W4 Reservation module
        size_t i = 0;
        for (i = 0; i < string.length() && string[i] == ' '; i++);
        string = string.substr(i);

        for (i = string.length(); i > 0 && string[i - 1] == ' '; i--);
        string = string.substr(0, i);
        *///////////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////////
 /*       while (string.at(0) == ' ')
        {
            string = string.substr(1, string.length() - 1);
        }

        while (string.at(string.length() - 1) == ' ')
        {
            string = string.substr(0, string.length() - 1);
        }*/
        ///////////////////////////////////////////////////////////////
    }

    const std::string& Book::title() const {
        return bookInfo.title;
    }
    const string& Book::country() const {
        return bookInfo.country;
    }
    const size_t& Book::year() const {
        return bookInfo.year;
    }
    double& Book::price() {
        return bookInfo.price;
    }


    ostream& operator<<(ostream& os, const Book& book) {
        string str{ " | " };
        os << setw(20) << book.bookInfo.author << str
            << setw(22) << book.bookInfo.title << str
            << setw(5) << book.bookInfo.country << str
            << setw(4) << book.bookInfo.year << str
            << setw(6) << fixed << setprecision(2) << book.bookInfo.price << str
            << book.bookInfo.summary << endl;


        return os;
    }
}
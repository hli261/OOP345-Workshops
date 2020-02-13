//-------------------------------------------------------------------------------------------------------------
// Name:    Haibo Zheng
// Seneca Student ID:   164732182
// Seneca email:    hzheng62@myseneca.ca
// Date of completion:  2/3/2020
//
// I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.
//-------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <sstream>

#ifndef _SDDS_Movie_HEADER_
#define _SDDS_Movie_HEADER_

using namespace std;

namespace sdds {
    class Movie {
            string m_title{};
            size_t m_year{};
            string m_summary{};
    public:
        Movie() = default;
        Movie(const std::string& strMovie);
        const std::string& title() const;

        void eraseSpace(string& str);

        template<class T>
        void fixSpelling(T spellChecker) {

        }

        friend ostream& operator<<(ostream& os, const Movie& Movies);


    };
}
#endif

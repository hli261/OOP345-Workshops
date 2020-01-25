//-------------------------------------------------------------------------------------------------------------
// Name:    Haibo Zheng
// Seneca Student ID:   164732182
// Seneca email:    hzheng62@myseneca.ca
// Date of completion:  1/25/2020
//
// I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.
//-------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include "Pair.h"

using namespace std;

#ifndef _SDDS_SET_HEADER_
#define _SDDS_SET_HEADER_


namespace sdds {
    template<class T1, int size>
    class Set {
        string m_str{};
        size_t m_size{};
    public:
        Set() {
        }

        size_t size() {

            return 0;
        }

        Set& operator+=(const Pair<std::string, int>& pair) {

            return *this;
        }

        size_t operator[](size_t i) {

            return i;
        }


    };

 //   Ostream& operator<<(Ostream& os, const Set<T1, int>);
}
#endif
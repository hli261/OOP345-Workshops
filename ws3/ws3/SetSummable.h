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
#include "PairSummable.h"

using namespace std;

#ifndef _SDDS_SETSUMMABLE_HEADER_
#define _SDDS_SETSUMMABLE_HEADER_


namespace sdds {
    template<class T1, size_t size, class T2, class T3>
    class SetSummable {

    public:
        SetSummable() {

        }

        template<class T>
        SetSummable& operator+=(const T& record) {

            return *this;
        }

        //SetSummable& operator+=(const PairSummable<std::string, std::string>& record) {

        //    return *this;
        //}


        SetSummable& operator[](size_t i) {

            return *this;
        }

        SetSummable& operator*(double d) {

            return *this;
        }

        size_t size() {


            return 0;
        }

        SetSummable& accumulate(std::string t2) {


            return *this;
        }



    };

    template<class T1>
    ostream& operator<<(ostream& os, const T1& setSummable) {

        return os;
    }

    //ostream& operator<<(ostream& os, const SetSummable<sdds::PairSummable<std::string, int>, 25, std::string, int>& setSummable) {

    //    return os;
    //}
}
#endif
//-------------------------------------------------------------------------------------------------------------
// Name:    Haibo Zheng
// Seneca Student ID:   164732182
// Seneca email:    hzheng62@myseneca.ca
// Date of completion:  1/15/2020
//
// I confirm that the content of this file is created by me,  with the exception of the parts provided to me by my professor.
//-------------------------------------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "RecordSet.h"

using namespace std;

namespace sdds {
    RecordSet::RecordSet() {

    }

    RecordSet::RecordSet(const char* str) {

    }

    RecordSet::RecordSet(const RecordSet&) {

    }

    RecordSet::RecordSet(const RecordSet&& recordSet) {

    }

    RecordSet& RecordSet::operator=(const RecordSet&) {

        return *this;
    }

    RecordSet& RecordSet::operator=(const RecordSet&&) {

        return *this;
    }

    RecordSet::~RecordSet() {

    }

    std::string  RecordSet::getRecord(int a) const {
        std::string  b;

        return b;
    }

    size_t RecordSet::size() const{


        return 0;
    }

    ostream& operator<<(ostream& os, const RecordSet& TimedEvents) {



        return os;
    }

}
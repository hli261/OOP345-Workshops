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
#include "Set.h"
#include "PairSummable.h"

using namespace std;

#ifndef _SDDS_SETSUMMABLE_HEADER_
#define _SDDS_SETSUMMABLE_HEADER_


namespace sdds {
    template<class T, size_t N, class K, class V>
    class SetSummable :public Set<T,N>{

    public:
        SetSummable():Set<T,N>() {

        }

        V accumulate(const K& key) const{
            V temp = this->operator[](0).getInitialValue();
            V temp1 = 0;
            for (size_t i = 0; i < this->size(); i++) {
               temp1=(this->operator[](i)).sum(key, this->operator[](i).getInitialValue());
            }

            return temp1-temp;
        }
        

    };
}
#endif
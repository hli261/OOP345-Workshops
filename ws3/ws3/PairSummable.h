//-------------------------------------------------------------------------------------------------------------
// Name:    Haibo Zheng
// Seneca Student ID:   164732182
// Seneca email:    hzheng62@myseneca.ca
// Date of completion:  1/25/2020
//
// I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.
//-------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
#include "Pair.h"

using namespace std;

#ifndef _SDDS_PAIRSUMMABLE_HEADER_
#define _SDDS_PAIRSUMMABLE_HEADER_


namespace sdds {
    template<class K, class V>
    class PairSummable :public Pair<K, V> {
        static V m_summation;
        static size_t m_minWidth;
    public:
        static const V& getInitialValue() {
            return m_summation;
        }

        PairSummable() :Pair<K, V>() {

        }

        PairSummable(const K& key, const V& value) :Pair<K, V>(key, value) {
            m_minWidth = m_minWidth > key.length() ? m_minWidth : key.length();
        }

        V sum(const K& key, const V& val) const {
            return (this->Key() == key) ? this->Value() + val : val;
        }

        void display(ostream& os) const {
            os << left << setw(m_minWidth);
            Pair<K, V>::display(os);
            os << right;
        }
    };

    template<class K, class V>
    size_t PairSummable<K, V>::m_minWidth = 0u;


    template<class K, class V>
    V PairSummable<K, V>::m_summation = 0u;

    template<>
    string PairSummable<string, string>::m_summation = "";

    template<>
    string PairSummable<string, string>::sum(const string& key, const string& val) const {
        return (this->Key() == key) ? (val == "" ? this->Value() : val + ", " + this->Value()) : val;
    }

}
#endif
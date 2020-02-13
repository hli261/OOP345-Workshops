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

#ifndef _SDDS_SPELLCHECKER_HEADER_
#define _SDDS_SPELLCHECKER_HEADER_

using namespace std;

namespace sdds {
    class SpellChecker {
        string m_badWords[5]{};
        string m_goodWords[5]{};
    public:
        SpellChecker() = default;
        SpellChecker(const char* filename);
        void operator()(std::string& text) const;

    };
}
#endif

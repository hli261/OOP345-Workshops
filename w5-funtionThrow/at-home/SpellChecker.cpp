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
#include <fstream>
#include <algorithm>
#include "SpellChecker.h"

using namespace std;

namespace sdds {

    SpellChecker::SpellChecker(const char* filename) {
        if (filename == nullptr || filename[0] == '\0') {
            throw "Bad file name!";
        }
        else {
            ifstream words(filename);
            if (words) {
                for (auto i : { 0, 1, 2, 3, 4 })
                    words >> m_badWords[i] >> m_goodWords[i];
            }
            else
                throw "Bad file name!";
        }
    }

    void SpellChecker::operator()(std::string& text) const {
        size_t pos{};
        for (auto i : { 0, 1, 2, 3, 4 }) {
            pos = text.find(m_badWords[i]);
            if (pos != std::string::npos) {
                text.replace(pos, m_goodWords[i].length(), m_goodWords[i]);
            }
        }


    }
}
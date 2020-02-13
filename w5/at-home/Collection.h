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

#ifndef _SDDS_COLLECTION_HEADER_
#define _SDDS_COLLECTION_HEADER_

using namespace std;

namespace sdds {
    template<class T>
    class Collection {
        struct CollectionInfo {
            string author{};
            string title{};
            string country{};
            double price{};
            size_t year{};
            string summary{};
        }CollectionInfo{}, library[7]{ {} };
    public:
        //Collection() = default;
        //Collection(const string& str);
        //void eraseSpace(string& str);
        //const std::string& title() const;
        //const string& country() const;
        //const size_t& year() const;
        //double& price();

        //friend ostream& operator<<(ostream& os, const Collection& collection);


    };
}
#endif

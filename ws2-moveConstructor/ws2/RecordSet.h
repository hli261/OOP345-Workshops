//-------------------------------------------------------------------------------------------------------------
// Name:    Haibo Zheng
// Seneca Student ID:   164732182
// Seneca email:    hzheng62@myseneca.ca
// Date of completion:  1/15/2020
//
// I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.
//-------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

#ifndef _SDDS_RecordSet_HEADER_
#define _SDDS_RecordSet_HEADER_


namespace sdds {
    class RecordSet {
        size_t m_recordNumber{};
        string* m_record{};
    public:
        RecordSet();
        RecordSet(const char*);
        RecordSet(const RecordSet&);
        RecordSet& operator=(const RecordSet&);
        RecordSet(RecordSet&&);
        RecordSet& operator=( RecordSet&&);
        ~RecordSet();

        string  getRecord(int ) const;
        size_t  size() const;
    };
}
#endif

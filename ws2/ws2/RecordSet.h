//-------------------------------------------------------------------------------------------------------------
// Name:    Haibo Zheng
// Seneca Student ID:   164732182
// Seneca email:    hzheng62@myseneca.ca
// Date of completion:  1/15/2020
//
// I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.
//-------------------------------------------------------------------------------------------------------------

#include <iostream>

#ifndef _SDDS_RecordSet_HEADER_
#define _SDDS_RecordSet_HEADER_


namespace sdds {
    class RecordSet {
    public:
        RecordSet();
        RecordSet(const char*);
        RecordSet(const RecordSet&);
        RecordSet(const RecordSet&&);
        RecordSet& operator=(const RecordSet&);
        RecordSet& operator=(const RecordSet&&);
        ~RecordSet();

        std::string  getRecord(int ) const;
        size_t  size() const;
    };

    std::ostream& operator<<(std::ostream& os, const RecordSet& TimeEvents);


}
#endif

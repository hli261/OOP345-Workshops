//-------------------------------------------------------------------------------------------------------------
// Name:    Haibo Zheng
// Seneca Student ID:   164732182
// Seneca email:    hzheng62@myseneca.ca
// Date of completion:  1/15/2020
//
// I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.
//-------------------------------------------------------------------------------------------------------------

#include <iostream>

#ifndef _SDDS_EVENT_HEADER_
#define _SDDS_EVENT_HEADER_

extern  unsigned int g_sysClock;
namespace sdds {
    class Event {
        char* m_description{nullptr};
        uint16_t m_time{ 0 };
    public:
        Event();
        Event(const Event& event);
        virtual ~Event();
        Event& operator=(const Event& event);
        int setDescription(const char description[]);
        void display() const;
    };
}

#endif

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
#include "TimedEvents.h"

unsigned int g_sysClock = 0;
using namespace std;

namespace sdds {
    TimedEvents::TimedEvents()//:m_recordsNumber(0),m_startTime(0),m_endTime(0)
    {

    }

    void TimedEvents::startClock() {

    }

    void TimedEvents::stopClock() {

    }
    void TimedEvents::recordEvent(const char* str) {

    }

    ostream& operator<<(ostream& os, TimedEvents& TimedEvents) {
        os << "Execution Times:" << endl;
        os << "--------------------------" << endl;

        os << TimedEvents.m_eventName<<TimedEvents.m_duration<< TimedEvents.m_timeUnit << endl;

        os << "--------------------------" << endl;


        return os;
    }

}
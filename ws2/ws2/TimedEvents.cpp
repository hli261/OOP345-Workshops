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
#include <chrono>
#include "TimedEvents.h"

using namespace std;
using namespace std::chrono;

namespace sdds {
    void TimedEvents::startClock() {
        m_startTime = std::chrono::steady_clock::now();
    }

    void TimedEvents::stopClock() {
        m_endTime = steady_clock::now();
    }

    void TimedEvents::recordEvent(const char* str) {
        if (m_recordsNumber < MAX_RECORDS)
        {
            m_events[m_recordsNumber].m_eventName = str;
            m_events[m_recordsNumber].m_timeUnit = "nanoseconds";
            m_events[m_recordsNumber].m_duration = duration_cast<nanoseconds>(m_endTime - m_startTime);;

            m_recordsNumber++;
        }
    }

    ostream& operator<<(ostream& os, TimedEvents& TimedEvents) {
        os << "--------------------------\n"
            << "Execution Times: \n"
            << "--------------------------\n";

        for (int i = 0; i < TimedEvents.m_recordsNumber; i++)
            os << setw(20) << std::left<< TimedEvents.m_events[i].m_eventName << ' ' 
            << setw(12) << right << TimedEvents.m_events[i].m_duration.count() << ' '
            << TimedEvents.m_events[i].m_timeUnit << '\n';

        os << "--------------------------" << endl;

        return os;
    }

}
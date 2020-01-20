//-------------------------------------------------------------------------------------------------------------
// Name:    Haibo Zheng
// Seneca Student ID:   164732182
// Seneca email:    hzheng62@myseneca.ca
// Date of completion:  1/15/2020
//
// I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.
//-------------------------------------------------------------------------------------------------------------

#include <iostream>
//#include <iomanip>
//#include <ctime>
#include <chrono>
#include "RecordSet.h"


#ifndef _SDDS_TimedEvents_HEADER_
#define _SDDS_TimedEvents_HEADER_

namespace sdds {
    class TimedEvents {
        RecordSet m_recordSet[7]{};
        int m_recordsNumber{};
        std::chrono::steady_clock::time_point m_startTime{};
        std::chrono::steady_clock::time_point m_endTime{};

        struct {
            char* m_eventName{};
            char* m_timeUnit{};
            std::chrono::steady_clock::duration m_duration;
        };


    public:
        TimedEvents();
        void startClock();
        void stopClock();
        void recordEvent(const char*);

        friend std::ostream& operator<<(std::ostream& os, TimedEvents& TimeEvents);
    };



}
#endif

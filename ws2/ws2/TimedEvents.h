//-------------------------------------------------------------------------------------------------------------
// Name:    Haibo Zheng
// Seneca Student ID:   164732182
// Seneca email:    hzheng62@myseneca.ca
// Date of completion:  1/15/2020
//
// I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.
//-------------------------------------------------------------------------------------------------------------

#include <iostream>

#ifndef _SDDS_TimedEvents_HEADER_
#define _SDDS_TimedEvents_HEADER_


namespace sdds {
    class TimedEvents {

    public:
        void startClock();

        void stopClock();
        void recordEvent(const char*);


    };

    std::ostream& operator<<(std::ostream& os, const TimedEvents& TimeEvents);

}
#endif

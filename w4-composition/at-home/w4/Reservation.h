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


#ifndef _SDDS_RESERVATION_HEADER_
#define _SDDS_RESERVATION_HEADER_

using namespace std;

namespace sdds {
    class Reservation {
        char m_reservationID[8]{};
        string m_Name{};
        string m_email{};
        int m_numberOfPeoply{};
        int m_day{};
        int m_hour{};

    public:
        Reservation() {}
        Reservation(const string& reservation);
        bool operator==(const Reservation& reservation);
        Reservation& operator=(const Reservation& reservation);

        friend ostream& operator<<(ostream& os, const Reservation& reservation);
    };
}
#endif

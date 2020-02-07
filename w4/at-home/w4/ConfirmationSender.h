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
#include "Reservation.h"

#ifndef _SDDS_CONFIRMATIONSENDER_HEADER_
#define _SDDS_CONFIRMATIONSENDER_HEADER_

using namespace std;

namespace sdds {
    class ConfirmationSender {
        size_t m_size{};
        Reservation** m_ppReservation{};
    public:
        ConfirmationSender();
        ~ConfirmationSender();
        ConfirmationSender(const ConfirmationSender& sender);
        ConfirmationSender(ConfirmationSender&& sender);
        ConfirmationSender& operator+=(const Reservation& sender);
        ConfirmationSender& operator-=(const Reservation& sender);
        friend ostream& operator<< (ostream& os, const ConfirmationSender& sender);
    };
}
#endif
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

#ifndef _SDDS_RESTAURANT_HEADER_
#define _SDDS_RESTAURANT_HEADER_

using namespace std;

namespace sdds {
    class Restaurant {
        Reservation** m_ppReservation{};
        size_t m_size{};

    public:
        Restaurant(Reservation* reservations[], size_t cnt);

        Restaurant(Restaurant& restaurant);

        Restaurant(Restaurant&& restaurant) noexcept;


        size_t size() const;

        friend ostream& operator<<(ostream& os, const Restaurant& restaurant);

    };


}
#endif

//-------------------------------------------------------------------------------------------------------------
// Name:    Haibo Zheng
// Seneca Student ID:   164732182
// Seneca email:    hzheng62@myseneca.ca
// Date of completion:  2/3/2020
//
// I confirm that the content of this file is created by me,  with the exception of the parts provided to me by my professor.
//-------------------------------------------------------------------------------------------------------------


#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
#include "Restaurant.h"

using namespace std;

namespace sdds {
    Restaurant::Restaurant(Reservation* reservations[], size_t cnt) {
        //m_ppReservation = new Reservation * [cnt] ;
        //m_ppReservation[0] = new Reservation[cnt * sizeof(Reservation)];
        //for (size_t i = 0; i < cnt; i++) {
        //    m_ppReservation[i] = m_ppReservation[i - 1] + sizeof(Reservation);
        //}

        m_ppReservation = reservations;
        m_size = cnt;
    }


    Restaurant::Restaurant(Restaurant& restaurant) {
        m_ppReservation = restaurant.m_ppReservation;
        m_size = restaurant.m_size;
    }

    Restaurant::Restaurant(Restaurant&& restaurant) noexcept {
        m_ppReservation = restaurant.m_ppReservation;
        m_size = restaurant.m_size;
        restaurant.m_ppReservation = nullptr;
        restaurant.m_size = 0;
    }


    size_t Restaurant::size() const {

        return m_size;
    }

    ostream& operator<<(ostream& os, const Restaurant& restaurant) {
        os << "--------------------------\n"
            << "Fancy Restaurant\n"
            << "--------------------------\n";
        if (restaurant.m_size == 0) {
            os << "The object is empty!\n";
        }
        else {
            for (size_t i = 0; i < restaurant.m_size; i++) {
                os << *restaurant.m_ppReservation[i];
            }
        }
        os << "--------------------------\n";
        return os;
    }
}
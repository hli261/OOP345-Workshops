//-------------------------------------------------------------------------------------------------------------
// Name:    Haibo Zheng
// Seneca Student ID:   164732182
// Seneca email:    hzheng62@myseneca.ca
// Date of completion:  2/3/2020
//
// I confirm that the content of this file is created by me,  with the exception of the parts provided to me by my professor.
//-------------------------------------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include "Reservation.h"

using namespace std;

namespace sdds {
    Reservation::Reservation(const string& reservation) {
        string str = reservation;

        size_t pos{};
        pos = str.find(' ');
        while (pos != (size_t)(-1)) {
            str.erase(pos, 1);
            pos = str.find(' ');
        }

        for (size_t i = 0; i < str.length(); i++) {
            if (str[i] == ',' || str[i] == ':')
                str[i] = ' ';
        }

        stringstream record(str);
        record >> m_reservationID >> m_Name >> m_email >> m_numberOfPeoply >> m_day >> m_hour;

    }

    Reservation& Reservation::operator=(const Reservation& reservation) {
        strcpy(m_reservationID, reservation.m_reservationID);
        m_Name = reservation.m_Name;
        m_email = reservation.m_email;
        m_numberOfPeoply = reservation.m_numberOfPeoply;
        m_day = reservation.m_day;
        m_hour = reservation.m_hour;


        return *this;
    }

    bool Reservation::operator==(const Reservation& reservation) {
        string Left = m_reservationID + m_Name + m_email + to_string(m_numberOfPeoply) + to_string(m_day) + to_string(m_hour);

        string Right = reservation.m_reservationID + reservation.m_Name + reservation.m_email + to_string(reservation.m_numberOfPeoply) + to_string(reservation.m_day) + to_string(reservation.m_hour);

        
        return Left == Right ? true : false;
    }



    ostream& operator<<(ostream& os, const Reservation& reservation) {
        string email = " <" + reservation.m_email + ">";
        os << "Reservation " << reservation.m_reservationID << ": "
            << setw(10) << right << reservation.m_Name << " "
            << left << setw(20) << email
            << right << "     ";
        if (reservation.m_hour >= 6 && reservation.m_hour <= 9)
            os << "Breakfast";
        else if (reservation.m_hour >= 11 && reservation.m_hour <= 15)
            os << "Lunch";
        else if (reservation.m_hour >= 17 && reservation.m_hour <= 21)
            os << "Dinner";
        else  os << "Drinks";

        os << " on day " << reservation.m_day << " @ " << reservation.m_hour << ":00 for " << reservation.m_numberOfPeoply << " people." << endl;

        return os;
    }


}
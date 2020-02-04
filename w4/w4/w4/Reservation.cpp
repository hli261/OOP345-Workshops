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
#include <fstream>
#include "Reservation.h"

using namespace std;

namespace sdds {
    Reservation::Reservation(const string reservation) {
        string str = reservation;
        replace(str.begin(), str.end(), ',', ' ');
        replace(str.begin(), str.end(), ':',' ');
        stringstream record(str);
        record >> m_reservationID >> m_Name >> m_email >> m_numberOfPeoply >> m_day >> m_hour;

    }

    ostream& operator<<(ostream& os, const Reservation& reservation) {
        string email = "<" + reservation.m_email + ">";
        os <<reservation.m_reservationID<<":"
            << setw(10)<<right<<reservation.m_Name <<'\t'
            << left<<setw(20)<< email
            << right<<reservation.m_numberOfPeoply << reservation.m_day << reservation.m_hour << endl;

        return os;
    }


}
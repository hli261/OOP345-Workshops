//-------------------------------------------------------------------------------------------------------------
// Name:    Haibo Zheng
// Seneca Student ID:   164732182
// Seneca email:    hzheng62@myseneca.ca
// Date of completion:  2/3/2020
//
// I confirm that the content of this file is created by me,  with the exception of the parts provided to me by my professor.
//-------------------------------------------------------------------------------------------------------------

#include <iomanip>
#include "Reservation.h"

using namespace std;

namespace sdds {
    Reservation::Reservation(const string& reservation) {

        string str = reservation;

        //replace(str.begin(), str.end(), ',', ' ');
        //replace(str.begin(), str.end(), ':', ' ');
        //or:        
        for (size_t i = 0; i < reservation.length(); i++) {
            if (reservation[i] == ',' || reservation[i] == ':')
                str[i] = ' ';
        }
        stringstream record(str);
        record >> m_reservationID >> m_Name >> m_email >> m_numberOfPeoply >> m_day >> m_hour;



        size_t pos{};
        char temp{};
        string tempStr{};
        for (size_t i = 0; i < reservation.length(); i++) {
            if (reservation[i] == ',' || reservation[i] == ':') {
                temp=str[i];
                pos = reservation.find(temp);
                tempStr = reservation.substr(0, pos);
                str.erase(0, pos);
            }
        }



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
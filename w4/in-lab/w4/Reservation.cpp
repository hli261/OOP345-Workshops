//-------------------------------------------------------------------------------------------------------------
// Name:    Haibo Zheng
// Seneca Student ID:   164732182
// Seneca email:    hzheng62@myseneca.ca
// Date of completion:  2/3/2020
//
// I confirm that the content of this file is created by me,  with the exception of the parts provided to me by my professor.
//-------------------------------------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include "Reservation.h"

using namespace std;

namespace sdds {
    Reservation::Reservation(const string& reservation) {

        //string str = reservation;

    
        //size_t pos{};
        //pos = str.find(' ');
        //while (pos != (size_t)(-1)) {
        //    str.erase(pos, 1);
        //    pos = str.find(' ');
        //}

        //for (size_t i = 0; i < str.length(); i++) {
        //    if (str[i] == ',' || str[i] == ':')
        //        str[i] = ' ';
        //}

     
        //stringstream record(str);
        //record >> m_reservationID >> m_Name >> m_email >> m_numberOfPeoply >> m_day >> m_hour;


        string str = reservation;
        size_t pos{}, lastPos{};
        string tempStr[6]{ {} };
        size_t count{};

        pos = str.find(' ');
        while (pos != (size_t)(-1)) {

            str.erase(pos, 1);
            pos = str.find(' ');
        }


        for (size_t i = 0; i < str.length(); i++) {
            if (str[i] == ',' || str[i] == ':') {
                pos = str.find(str[i]);
                tempStr[count++] = str.substr(lastPos + 1, pos - lastPos - 1);
                lastPos = pos;
                str[i] = '*';
            }
        }

        tempStr[count] = str.substr(pos + 1);

        strcpy(m_reservationID, tempStr[0].c_str());
        m_Name = tempStr[1];
        m_email = tempStr[2];
        m_numberOfPeoply = stoi(tempStr[3]);
        m_day = stoi(tempStr[4]);
        m_hour = stoi(tempStr[5]);

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
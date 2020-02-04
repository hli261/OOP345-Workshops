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
#include<algorithm>

using namespace std;

#ifndef _SDDS_RecordSet_HEADER_
#define _SDDS_RecordSet_HEADER_


namespace sdds {
    class Reservation {
        string m_reservationID{};// -**reservation id * *: an array of characters
        string m_Name{};//  - **the name on the reservation * *
        string m_email{};// -**the email * *that can be used to send the confirmation that the reservation can be honored or not
        int m_numberOfPeoply{};// -**the number of people * *in the party
        int m_day{};// - **the day * *when the party is expected to come(for simplicity, the day is an integer between 1 and 31)
        int m_hour{};// - **the hour * *when the party is expected to come(for simplicity, the hour is an integer between 1 and 24)

    public:
        Reservation() { }
        Reservation(const string reservation);

        friend ostream& operator<<(ostream& os, const Reservation& reservation);
    };
}
#endif

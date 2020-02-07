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
#include <string>
#include "ConfirmationSender.h"

using namespace std;

namespace sdds {

    ConfirmationSender::ConfirmationSender() {
    }

    ConfirmationSender::~ConfirmationSender() {
        if (m_ppReservation != nullptr) {
            delete[] m_ppReservation[0];
            delete[] m_ppReservation;
        }
    }

    ConfirmationSender::ConfirmationSender(const ConfirmationSender& restaurant) {
        m_ppReservation = new Reservation * [restaurant.m_size];
        m_ppReservation[0] = new Reservation[restaurant.m_size];
        *m_ppReservation[0] = *restaurant.m_ppReservation[0];

        for (size_t i = 1; i < restaurant.m_size; i++) {
            m_ppReservation[i] = m_ppReservation[i - 1] + 1;
            *m_ppReservation[i] = *restaurant.m_ppReservation[i];
        }
        m_size = restaurant.m_size;
    }


    ConfirmationSender::ConfirmationSender(ConfirmationSender&& sender) {
        m_ppReservation = sender.m_ppReservation;
        m_size = sender.m_size;
        sender.m_ppReservation = nullptr;
        sender.m_size = 0;
    }


    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& sender) {
        size_t founded{};
        for (size_t i = 0; i < m_size; i++) {
            if (m_ppReservation[i]->operator==(sender)) {
                founded = i + 1;//the firs founded
                break;
            }
        }
        if (!founded) {
            m_size++;
            Reservation** temp = new Reservation * [m_size];
            temp[0] = new Reservation[m_size];
            *temp[0] = *m_ppReservation[0];
            if (m_size > 1) {
                for (size_t i = 1; i < m_size - 1; i++) {
                    temp[i] = temp[i - 1] + 1;
                    *temp[i] = *m_ppReservation[i];
                }
                temp[m_size - 1] = temp[m_size - 2] + 1;
                *temp[m_size - 1] = sender;
            }

            if (m_ppReservation != nullptr) {
                delete[] m_ppReservation[0];
                delete[] m_ppReservation;
            }
            m_ppReservation = temp;
        }
        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& sender) {
        size_t founded{};
        for (size_t i = 0; i < m_size; i++) {
            if (m_ppReservation[i]->operator==(sender)) {
                founded = i + 1;//the first founded
                break;
            }
        }

        if (founded) {
            m_size--;
            if (m_size > 0) {
                Reservation** temp = new Reservation * [m_size];
                temp[0] = new Reservation[m_size];
                *temp[0] = *m_ppReservation[0];
                for (size_t i = 1; i < m_size; i++) {
                    temp[i] = temp[i - 1] + 1;

                    if (i < founded - (size_t)1) *temp[i] = *m_ppReservation[i];
                    else *temp[i] = *m_ppReservation[i + 1];
                }
                if (m_ppReservation != nullptr) {
                    delete[] m_ppReservation[0];
                    delete[] m_ppReservation;
                }

                m_ppReservation = temp;
            }
            else {
                delete[] m_ppReservation[0];
                delete[] m_ppReservation;
                m_ppReservation = nullptr;
            }

        }
        return *this;
    }

    ostream& operator<< (ostream& os, const ConfirmationSender& sender) {
        os << "--------------------------\n"
            << "Confirmations to Send\n"
            << "--------------------------\n";
        if (sender.m_size == 0) {
            os << "The object is empty!\n";
        }
        else {
            for (size_t i = 0; i < sender.m_size; i++) {
                os << *sender.m_ppReservation[i];
            }
        }
        os << "--------------------------\n";
        return os;
    }

}
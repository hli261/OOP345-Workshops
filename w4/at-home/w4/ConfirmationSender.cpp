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
        size_t foundedIndex{};
        for (size_t i = 0; i < m_size; i++) {
            if (m_ppReservation[i]->operator==(sender)) {
                foundedIndex = i;//the firs founded
                break;
            }
        }
        if (!foundedIndex) {

            m_size++;

            Reservation** temp{};
            temp = new Reservation * [m_size];
            temp[0] = new Reservation[m_size];
            if (m_size > 1) {
                *temp[0] = *m_ppReservation[0];
                for (size_t i = 1; i < m_size - 1; i++) {
                    temp[i] = temp[i - 1] + 1;
                    *temp[i] = *m_ppReservation[i];
                }
                temp[m_size - 1] = temp[m_size - 2] + 1;
            }
            *temp[m_size - 1] = sender;

            if (m_ppReservation != nullptr) {
                delete[] m_ppReservation[0];
                delete[] m_ppReservation;
            }

            m_ppReservation = temp;

        }
        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& sender) {
        size_t foundedIndex{};
        for (size_t i = 0; i < m_size; i++) {
            if (m_ppReservation[i]->operator==(sender)) {
                foundedIndex = i;//the first founded
                break;
            }
        }

        if (foundedIndex) {
            m_size--;

            Reservation** temp{};
            if (m_size > 0) {
                temp = new Reservation * [m_size];
                temp[0] = new Reservation[m_size];
                if (0 == foundedIndex) *temp[0] = *m_ppReservation[foundedIndex + 1];
                else *temp[0] = *m_ppReservation[foundedIndex];
                for (size_t i = 1; i < m_size; i++) {
                    temp[i] = temp[i - 1] + 1;

                    if (i == foundedIndex) *temp[i] = *m_ppReservation[foundedIndex + 1];
                    else *temp[i] = *m_ppReservation[foundedIndex];
                }
            }
            if (m_ppReservation != nullptr) {
                delete[] m_ppReservation[0];
                delete[] m_ppReservation;
            }

            m_ppReservation = temp;

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
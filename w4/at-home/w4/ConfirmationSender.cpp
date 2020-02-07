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
        for (auto i = 0u; i < m_size; ++i)
            delete m_ppReservation[i];
        delete[] m_ppReservation;
    }

    ConfirmationSender::ConfirmationSender(const ConfirmationSender& sender) {
        m_ppReservation = new Reservation * [sender.m_size];
        for (size_t i = 0; i < sender.m_size; i++) {
            m_ppReservation[i] = new Reservation;
            *m_ppReservation[i] = *sender.m_ppReservation[i];
        }
        m_size = sender.m_size;
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
            Reservation** temp{};
            m_size++;
            if (m_ppReservation != nullptr) {
                temp = new Reservation * [m_size];
                for (size_t i = 0; i < m_size - 1; i++) {
                    temp[i] = new Reservation;
                    *temp[i] = *m_ppReservation[i];
                }
                for (auto i = 0u; i < m_size - 1; ++i)
                    delete m_ppReservation[i];
                delete[] m_ppReservation; 
            }
            else {
                temp = new Reservation * [m_size];
            }
            temp[m_size - 1] = new Reservation;
            *temp[m_size - 1] = sender;

            if (m_ppReservation != nullptr) {

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
            Reservation** temp = new Reservation * [m_size];
            for (size_t i = 0; i < m_size; i++) {
                temp[i] = new Reservation;
                if (i < founded - (size_t)1) *temp[i] = *m_ppReservation[i];
                else *temp[i] = *m_ppReservation[i + 1];
            }
            for (auto i = 0u; i < m_size + 1; ++i)
                delete m_ppReservation[i];
            delete[] m_ppReservation;

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
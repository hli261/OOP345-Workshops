//-------------------------------------------------------------------------------------------------------------
// Name:    Haibo Zheng
// Seneca Student ID:   164732182
// Seneca email:    hzheng62@myseneca.ca
// Date of completion:  1/15/2020
//
// I confirm that the content of this file is created by me,  with the exception of the parts provided to me by my professor.
//-------------------------------------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "event.h"
#include <iostream>
#include <iomanip>
#include <cstring>

unsigned int g_sysClock = 0;
using namespace std;

namespace sdds {
    static uint16_t counters = 1;
    Event::Event() :m_description("[ No Event ]"), m_time(0) {

    }
    int Event::setDescription(char description[]) {
        if (description != nullptr && description[0] != '\0') {
            strncpy(m_description, description,127);
        }
        else
            strcpy(m_description, "[ No Event ]");

        m_time = g_sysClock;

        return 1;
    }

    void Event::display() const {
        cout << setw(3) << setfill(' ') << counters++ << ". ";
        if (strcmp(m_description, "[ No Event ]")) {
            cout << setfill('0') 
                << setw(2) << m_time / 3600 << ":"
                << setw(2) << m_time % 3600 / 60 << ":"
                << setw(2) << m_time % 60 << " -> ";
        }
        cout << m_description << std::endl;
    }
}
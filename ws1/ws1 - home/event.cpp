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
    Event::Event() :m_description(nullptr), m_time(0) { }

    Event::Event(const Event& event) {
        m_description = new char[strlen(event.m_description) + 1];
        strcpy(m_description, event.m_description);
        m_time = event.m_time;
    }

    Event::~Event() {
        delete[] m_description;
    }

    Event& Event::operator=(const Event& event) {
        if (this != &event) {
            m_description = new char[strlen(event.m_description) + 1];
            strcpy(m_description, event.m_description);
            m_time = event.m_time;
        }
        return *this;
    }

    int Event::setDescription(const char description[]) {
        if (description != nullptr && description[0] != '\0') {
            m_description = new char[strlen(description) + 1];
            strcpy(m_description, description);
        }
        else {
            m_description = new char[strlen("[ No Event ]") + 1];
            strcpy(m_description, "[ No Event ]");
        }

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
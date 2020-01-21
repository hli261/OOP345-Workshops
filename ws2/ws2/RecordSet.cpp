//-------------------------------------------------------------------------------------------------------------
// Name:    Haibo Zheng
// Seneca Student ID:   164732182
// Seneca email:    hzheng62@myseneca.ca
// Date of completion:  1/15/2020
//
// I confirm that the content of this file is created by me,  with the exception of the parts provided to me by my professor.
//-------------------------------------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
#include "RecordSet.h"

using namespace std;

namespace sdds {
    RecordSet::RecordSet() :m_recordNumber(0), m_record(nullptr) {

    }

    RecordSet::RecordSet(const char* str) {
        char buffer[50]{};
        char c{};
        m_recordNumber = 0;
        ifstream in(str);
        if (!in.is_open()) {
            std::cout << "failed to open " << str << '\n';
        }
        else {
            while (!cin.fail() && !in.eof()) {
                in.get(c);
                if (c == ' ') m_recordNumber++;
            }
            m_record = new string[m_recordNumber + 1]{};
            in.clear();
            in.seekg(0);
            m_recordNumber = 0;
            while (!cin.fail() && !in.eof()) {
                //cout << in.tellg()<<endl;
                in.getline(buffer, 49, ' ');
                m_record[m_recordNumber] = buffer;
                //if (in.eof() || m_recordNumber == 0 || m_recordNumber == 100 || m_recordNumber == 1000) 
                //    cout <<buffer << endl<< m_record[m_recordNumber]<<endl;
                m_recordNumber++;
            }
            cout << m_recordNumber << endl;
        }
    }

    RecordSet::RecordSet(const RecordSet& recordSet) {
        if (recordSet.m_record != nullptr) {
        m_recordNumber = recordSet.m_recordNumber;
            m_record = new string[m_recordNumber]{};
            for (int i = 0; i < m_recordNumber;i++)
                m_record[i] = recordSet.m_record[i];
        }
        else {
            m_record = nullptr;
            m_recordNumber = 0;
        }

    }

    RecordSet& RecordSet::operator=(const RecordSet& recordSet) {
        if (this != &recordSet) {
            if (recordSet.m_record != nullptr) {
                m_recordNumber = recordSet.m_recordNumber;
                m_record = new string[m_recordNumber]{};
                for (int i = 0; i < m_recordNumber; i++)
                    m_record[i] = recordSet.m_record[i];
            }
            else {
                m_record = nullptr;
                m_recordNumber = 0;
            }
        }
        return *this;
    }

    RecordSet::RecordSet(RecordSet&& recordSet) {
        *this = std::move(recordSet);
        //delete[] m_record;
        //m_record = recordSet.m_record;
        //m_recordNumber = recordSet.m_recordNumber;
        //recordSet.m_record = nullptr;
        //recordSet.m_recordNumber = 0;

    }

    RecordSet& RecordSet::operator=(RecordSet&& recordSet) {
        if (this != &recordSet) {
            delete[] m_record;
            m_record = recordSet.m_record;
            m_recordNumber = recordSet.m_recordNumber;
            recordSet.m_record = nullptr;
            recordSet.m_recordNumber = 0;
        }
        return *this;
    }

    RecordSet::~RecordSet() {
        delete[] m_record;
    }

    std::string  RecordSet::getRecord(int index) const {
        if (m_record != nullptr)
            return m_record[index];
        else return "";
    }

    size_t RecordSet::size() const {
        return m_recordNumber;
    }

}
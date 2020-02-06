//==============================================
// Name:           Xiaozhuan Li
// Student Number: 162683189
// Email:          xli403@myseneca.ca
// Date:           Jan-28-2020
// Section:        OOP244NAA
// Workshop:       3 (diy)
//==============================================
//Train.cpp

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Train.h"
using namespace std;

namespace sdds {
    void Cargo::setWeight(const double cargoWeight) {
        double temp{};
        if (cargoWeight > MAX_WEIGHT || cargoWeight < MIN_WEIGHT) {
            temp = MIN_WEIGHT;
        }
        else temp = cargoWeight;
        m_weight = temp;
    }

    void Cargo::init(const char* cargoName, double cargoWeight) {
        m_description = new char[strlen(cargoName) + 1];
        strcpy(m_description, cargoName);
        setWeight(cargoWeight);
    }

    void Cargo::initPtr(char* cargoName, double cargoWeight) {
        setDescriptionPtr(cargoName);
        setWeight(cargoWeight);
    }

    void Cargo::setDescriptionPtr(char* s_description) {
        m_description = s_description;
    }


    char* Cargo::getDescription() const{
        return m_description;
    }
    
    char* Cargo::getDescriptionArray() {
        return m_descriptionArray;
    }


    double Cargo::getWeight() const {
        return m_weight;
    }

    void Cargo::deleteCargo() {
        delete[] m_description;

    }

    void Train::setTrain(const char* n, int number) {
        if (n == nullptr || number < 1 || n[0] == '\0') {
            m_name[0] = '\0';
            m_id = 0;
        }
        else {
            strcpy(m_name, n);
            m_id = number;
        }
        m_cargo = nullptr;

    }

    bool Train::isEmpty() const {
        bool empty = true;
        if (m_id > 0) {
            empty = false;
        }
        else
            empty = true;
        return empty;
    }

    void Train::display() const {
        cout << "***Train Summary***" << endl;
        if (isEmpty()) {
            cout << "This is an empty train." << endl;
        }
        else {
            cout << "Name: " << m_name << " ID: " << m_id << endl;
            if (m_cargo != nullptr) {
                cout << fixed << setprecision(2) << "Cargo: " << m_cargo->getDescription() << " Weight: " << m_cargo->getWeight() << endl;
            }
            else
                cout << "No cargo on this train." << endl;
        }
    }

    void Train::loadCargo(Cargo c) {
        m_cargo = new Cargo;
        m_cargo->setDescriptionPtr(c.getDescription());
        m_cargo->setWeight(c.getWeight());
    }




    bool Train::swapCargo(Train& trainB) {
        bool isswap = false;
        if (m_cargo != nullptr && trainB.m_cargo != nullptr) {
            Cargo cargo;
            cargo.initPtr(trainB.m_cargo->getDescription(), trainB.m_cargo->getWeight());
            trainB.m_cargo->initPtr(this->m_cargo->getDescription(), this->m_cargo->getWeight());
            m_cargo->initPtr(cargo.getDescription(), cargo.getWeight());
            isswap = true;
        }
        return isswap;
    }

    bool Train::increaseCargo(double increaseWeight) {
        bool isincrease = false;
        if (m_cargo != nullptr) {
            if (m_cargo->getWeight() < MAX_WEIGHT) {
                double cargoWeight = m_cargo->getWeight() + increaseWeight;
                if (cargoWeight > MAX_WEIGHT) {
                    cargoWeight = MAX_WEIGHT;
                }
                m_cargo->setWeight(cargoWeight);
                isincrease = true;
            }
        }
        return isincrease;
    }

    bool Train::decreaseCargo(double decreaseWeight) {
        bool isdecrease = false;
        if (m_cargo != nullptr) {
            double cargoWeight = m_cargo->getWeight() - decreaseWeight;
            if (cargoWeight >= MIN_WEIGHT) {
                m_cargo->setWeight(cargoWeight);
                isdecrease = true;
            }
        }
        return isdecrease;
    }

    void Train::unloadCargo() {
        m_cargo->deleteCargo();
        delete m_cargo;
        m_cargo = nullptr;
    }
}
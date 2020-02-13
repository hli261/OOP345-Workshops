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

#ifndef _SDDS_COLLECTION_HEADER_
#define _SDDS_COLLECTION_HEADER_

using namespace std;

namespace sdds {
    template<class T>
    class Collection {
        string m_collectionName{};
        T* m_items{};
        size_t m_size{};
        void (*m_observer)(const Collection<T>&, const T&);
    public:
        Collection() = default;
        Collection(std::string name) {
            m_collectionName = name;///////////////////
        }
        Collection(const Collection<T>&) = delete;

        ~Collection() {
            delete m_items;
           // delete m_observer(const Collection<T>&, const T&);///////////////
        }

        const std::string& name() const {
            return m_collectionName;
        }

        size_t size() const {
            return m_size;
        }

        void setObserver(void (*observer)(const Collection<T>&, const T&)) {
            m_observer = observer;
        }

        Collection<T>& operator+=(const T& item) {
            if (m_items->title() != T.title()) {
                m_size++;///////////////////
            }
        }

        T& operator[](size_t idx) const {
            string str = "Bad index [" + to_string(idx) + "]. Collection has [" + to_string(m_size) + "] items.";
            if (idx >= m_size) throw str;//type `std::out_of_range`

            return m_items[idx];
        }

        T* operator[](std::string title) const {
            bool isFound{};
            size_t idx{};
            for (size_t i = 0; i < m_size;i++) {
                if (m_items[i].title() == title) {
                    isFound = 1;
                    idx = i;
                    break;
                }
            }
            return isFound?*m_items[idx]:nullptr;
        }
        


    };

    template<class T>
        ostream& operator<<(ostream& os, const Collection<T>& collection) {
        for (size_t i = 0; i < collection.size(); i++) {
            os << collection[i];///////////////////////////////////////////////
        }

        return os;
    }
}
#endif

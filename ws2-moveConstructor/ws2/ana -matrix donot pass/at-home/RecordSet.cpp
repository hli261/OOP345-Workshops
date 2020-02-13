// Name:Anna Chervonnaya
// Seneca Student ID: 12143317
// Seneca email: achervonnaya@myseneca.ca
// Date of completion: January 27, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "RecordSet.h"

using namespace std;

namespace sdds {

	RecordSet::RecordSet() : record_no(0), file_name(nullptr) { }
	
	RecordSet::RecordSet(const char* filename) {
		string temp{};///////////////////////////////////////////
		record_no = 0;
		std::ifstream file;
		//open file
		file.open(filename); 
		if (file.is_open()) {
			while (std::getline(file, temp, ' '))
				++record_no; 
			file_name = new std::string[record_no];
			file.close();
			file.open(filename);
			for (unsigned int i = 0; i < record_no; i++) {
				getline(file, file_name[i], ' ');
			}
			
		}
		else {
			std::cerr << "File failed to open." << std::endl;
			file_name = nullptr;
			record_no = 0;
		}
		file.open(filename);////////////////////////////////////////////////


	}
	RecordSet::RecordSet(const RecordSet& recordSet) {

		
		if (recordSet.file_name != nullptr) {
			record_no = recordSet.record_no;
			file_name = new string[record_no];
			for (unsigned int i = 0; i < record_no; i++) {
				file_name[i] = recordSet.file_name[i];
			}
		}
		else {
			file_name = nullptr;
			record_no = 0;
		}
		
	}
	
	
	RecordSet& RecordSet::operator = (const RecordSet& recordSet) {
		if (this != &recordSet) {
			if (recordSet.file_name != nullptr) {
				delete[] file_name;
				record_no = recordSet.record_no;
				file_name = new string[record_no];
				for (unsigned int i = 0; i < record_no; i++)
					file_name[i] = recordSet.file_name[i];
			}
			else {//////////////////////////////////////
				file_name = nullptr;//////////////////////////////////
				record_no = 0;//////////////////////////////////////
			}

			
		}
		
		return *this;
	}
			
	RecordSet::~RecordSet() {
		delete[] file_name;
	}
	
	
	size_t RecordSet::size() const {
		return record_no;
	}
	string RecordSet::getRecord(size_t index) const {
		return file_name != nullptr ? file_name[index] : "";
	}

	RecordSet::RecordSet(RecordSet&& src) {
		 *this = std::move(src);

	}
	RecordSet& RecordSet::operator=(RecordSet&& srcrec) {
		if (this != &srcrec) {
			delete[] file_name;
			record_no = srcrec.record_no;
			file_name = srcrec.file_name;
			srcrec.record_no = 0u;
			srcrec.file_name = nullptr;
			
		}
		return *this;
	}


}


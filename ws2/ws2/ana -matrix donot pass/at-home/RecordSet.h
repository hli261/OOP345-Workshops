// Name:Anna Chervonnaya
// Seneca Student ID: 12143317
// Seneca email: achervonnaya@myseneca.ca
// Date of completion: January 27, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.



#ifndef SDDS_RECORDSET_H_
#define SDDS_RECORDSET_H_

#include <iostream>
#include <string>
using namespace std;

namespace sdds{

	class RecordSet {
		
		unsigned int record_no{};////////////////////////////////////
		string* file_name{};//////////////////////////////////////

	public:
		RecordSet();
		RecordSet(const char* filename);
		RecordSet(const RecordSet&);
		RecordSet& operator = (const RecordSet&);
		~RecordSet();
		size_t size() const;
		string getRecord(size_t) const;
		RecordSet(RecordSet&&);
		RecordSet& operator =(RecordSet&&);
					
	};



}

#endif


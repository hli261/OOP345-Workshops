// Name:Anna Chervonnaya
// Seneca Student ID: 12143317
// Seneca email: achervonnaya@myseneca.ca
// Date of completion: January 23, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>
#include <chrono>
#include "TimedEvents.h"

using namespace std;

namespace sdds {
	
	TimedEvents::TimedEvents() {
		recordsNo = 0;
		startClock();
		stopClock();
	}
	//start timer
	void TimedEvents::startClock() {
		
		starttime = std::chrono::steady_clock::now();
	}
	//end timer
	void TimedEvents::stopClock() {
		
		endtime = std::chrono::steady_clock::now();

	}
	//record an event
	void TimedEvents::recordEvent(const char* str) {
		
		auto dur = std::chrono::duration_cast<std::chrono::nanoseconds>(endtime - starttime);
		if (recordsNo < MAX_RECORDS) {
			
			this->e_events[recordsNo].e_eventName = str;
			this->e_events[recordsNo].t_timeUnit = "nanoseconds";
			this->e_events[recordsNo].d_duration = dur;
			recordsNo++;
						
		}
	}

	ostream& operator<<(ostream& os, const TimedEvents& events) {
		os << "--------------------------\n";
		os << "Execution Times:\n";
		os << "--------------------------\n";
	
		for (int i = 0; i < events.recordsNo; i++)
			os << setw(20) << std::left << events.e_events[i].e_eventName << ' '
			<< setw(12) << right << events.e_events[i].d_duration.count() << ' '
			<< events.e_events[i].t_timeUnit << '\n';

		os << "--------------------------" << endl;

		return os;
	}



}
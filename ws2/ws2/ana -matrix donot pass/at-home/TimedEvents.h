// Name:Anna Chervonnaya
// Seneca Student ID: 12143317
// Seneca email: achervonnaya@myseneca.ca
// Date of completion: January 23, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_TIMEDEVENTS_H_
#define SDDS_TIMEDEVENTS_H_

#include <iostream>
#include <chrono>
#include "RecordSet.h"


namespace sdds {
	const int MAX_RECORDS = 7;
	class TimedEvents {
		int recordsNo;
		std::chrono::steady_clock::time_point starttime;

		std::chrono::steady_clock::time_point endtime;

		struct {
			std::string e_eventName{};
			std::string t_timeUnit{};
			std::chrono::steady_clock::duration d_duration{};
		} e_events[MAX_RECORDS];
	
	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void recordEvent(const char*);

		friend std::ostream& operator << (std::ostream& os, const TimedEvents& events);
	};
}

#endif
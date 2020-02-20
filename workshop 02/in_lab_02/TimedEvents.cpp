// Name: Arsham Yaghoobi 
// Seneca Student ID: 142927185
// Seneca email: ayaghoobi@myseneca.ca
// Date of completion: jan-23-2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <cstring>
#include <chrono>
#include <iomanip>
#include "TimedEvents.h"

using namespace std;

namespace sdds{

	TimedEvents::TimedEvents(){
		t_numOfRecords = 0;
		t_startTime = {};
		t_endTime = {};
	}

	void TimedEvents::startClock(){
		t_startTime = chrono::steady_clock::now();
	}

	void TimedEvents::stopClock(){
		t_endTime = chrono::steady_clock::now();
	}

	void TimedEvents::recordEvent(const char* nameOfEvent){
    auto dur = chrono::duration_cast<chrono::nanoseconds>(t_endTime - t_startTime);
    if (t_numOfRecords < MAX_REC){
      records[t_numOfRecords].event_name = nameOfEvent;
      records[t_numOfRecords].unitsOfTime = "nanoseconds";
      records[t_numOfRecords].duration = dur;
      t_numOfRecords++;
    }
	}

	ostream& operator<<(ostream& os, const TimedEvents& event){
    os << "--------------------------" << endl;
    os << "Execution Times:" << endl;
		os << "--------------------------" << endl;
		for ( int i = 0; i < event.t_numOfRecords; i++){
			os << setw(20) << left << event.records[i].event_name << " " << setw(12) << right
      << event.records[i].duration.count() << " " << event.records[i].unitsOfTime << endl;
		}
    os << "--------------------------" << endl;
    return os;
  }
}

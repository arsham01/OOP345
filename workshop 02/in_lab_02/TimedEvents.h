// Name: Arsham Yaghoobi 
// Seneca Student ID: 142927185
// Seneca email: ayaghoobi@myseneca.ca
// Date of completion: jan-23-2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_TIMEDEVENTS_H__
#define SDDS_TIMEDEVENTS_H__

#define _CRT_SECURE_NO_WARNINGS

namespace sdds{
  const int MAX_REC = 7;
  class TimedEvents {
    int t_numOfRecords;
    std::chrono::steady_clock::time_point t_startTime;
    std::chrono::steady_clock::time_point t_endTime;
    struct{
      std::string event_name{};
      std::string unitsOfTime{};
      std::chrono::steady_clock::duration duration{};
    }records[MAX_REC];

  public:
      TimedEvents();
      void startClock();
      void stopClock();
      void recordEvent(const char* nameOfEvent);
      friend std::ostream& operator<<(std::ostream& os, const TimedEvents& event);

  };
}
#endif
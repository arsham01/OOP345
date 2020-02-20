// Name: Arsham Yaghoobi
// Seneca Student ID: 142927185
// Seneca email: ayaghoobi@myseneca.ca
// Date of completion: Jan-17-2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef event_h
#define event_h

#include <iostream>

extern size_t g_sysClock;

namespace sdds {

const int MAX_DESC_LEN = 128;

class Event {
    char *e_description;
    unsigned int e_time;
    
public:
    Event();
    void display()const;
    Event& setDescription(const char descr[]);
    ~Event();
 };
}
#endif 


// Name: Arsham Yaghoobi
// Seneca Student ID: 142927185
// Seneca email: ayaghoobi@myseneca.ca
// Date of completion: Jan-17-2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <iomanip>
#include "event.h"
unsigned long g_sysClock;
using namespace std;

namespace sdds {

Event::Event(){
    e_description = nullptr;
    e_time = 0;
}

void Event::display()const {

    static int flag = 1;
    int hh = 0, mm = 0, ss = 0;

    mm = e_time / 60 % 60;
    hh = e_time / 3600;
    ss = e_time % 60;
    if (e_description == nullptr) {
        cout << setw(3) << setfill(' ') << flag << ". " << "[ No Event ]\n";
    }
    else {
        cout << setw(3) << setfill(' ') << flag << ". " << setw(2) << setfill('0') << hh << ":" << setw(2)
             << setfill('0') << mm << ":" << setw(2) << setfill('0') << ss << " -> " << e_description << "\n";
    }
    flag++;
  }

Event& Event::setDescription(const char descr[]){

    if(descr != nullptr){
        e_time = g_sysClock;
        int size = strlen(descr);
        e_description = new char[size + 1];
        strcpy(e_description,descr);
    }
    else {
        e_description = nullptr;
        e_time = 0;
    }

  return *this;
  }

   Event::~Event() {
        if (e_description == nullptr) {
            delete[] e_description;
        }
    }

}

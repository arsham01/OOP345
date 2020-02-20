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
unsigned int g_sysClock;

namespace sdds {

Event::Event(){
    e_description[0] = '\0';
    e_time = 0;
}

void Event::display()const {

    static int count = 0;

    std::cout << std::setw(3) << ++count << ". ";

    if (e_description[0] != '\0'){

        std::cout << std::setfill('0') << std::setw(2) << e_time / 3600 << ':' << std::setw(2) 
        << e_time / 60 % 60 << ':' << std::setw(2) << e_time % 60 << std::setfill(' ') << " -> " 
        << e_description << std::endl;
    }
    else {
        std::cout << "[ No Event ]" << std::endl;
    }
  }

Event& Event::setDescription(const char descr[]){

    if(descr != nullptr && descr[0] != '\0'){
        e_time = g_sysClock;
        strncpy(e_description, descr, MAX_DESC_LEN);
        e_description[MAX_DESC_LEN] = '\0';

    }
    else {
        e_description[0] = '\0';
        e_time = 0;

    }

  return *this;
  }

}

// Name: Arsham Yaghoobi
// Seneca Student ID: 142927185
// Seneca email: ayaghoobi@myseneca.ca
// Date of completion: Feb-11-2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ConfirmationSender.h"

using namespace std;

namespace sdds {
  ConfirmationSender::ConfirmationSender(){
    cs_reservationPtr = nullptr;
    cs_numOfConfirmation = 0;
  }

  ConfirmationSender::ConfirmationSender(const ConfirmationSender& csc){
    cs_numOfConfirmation = csc.cs_numOfConfirmation;
    if (cs_numOfConfirmation > 0) {
			cs_reservationPtr = const_cast<const Reservation**>(new Reservation * [cs_numOfConfirmation]);
			for (size_t i = 0; i < cs_numOfConfirmation; i++) {
				cs_reservationPtr[i] = csc.cs_reservationPtr[i];
			}
    }
		else {
			cs_reservationPtr = nullptr;
		}
  }

  ConfirmationSender::ConfirmationSender(ConfirmationSender&& csm){
    cs_reservationPtr = csm.cs_reservationPtr;
		cs_numOfConfirmation = csm.cs_numOfConfirmation;
		csm.cs_reservationPtr = nullptr;
		csm.cs_numOfConfirmation = 0;
  }

  ConfirmationSender::~ConfirmationSender(){
    delete[] cs_reservationPtr;
  }
  
  ConfirmationSender& ConfirmationSender::operator+=(const Reservation& rsv) {
		bool confirmation = true;

		for (size_t i = 0; i < cs_numOfConfirmation && confirmation; i++) {
			if (cs_reservationPtr[i] == &rsv) {
				confirmation = false; 
			}
		}

		if (confirmation) { 
			Reservation** tmp = new Reservation * [cs_numOfConfirmation + 1];
			for (size_t i = 0; i < cs_numOfConfirmation; i++) {
				tmp[i] = const_cast<Reservation*>(cs_reservationPtr[i]);
			}

			delete[] cs_reservationPtr;
			cs_reservationPtr = const_cast<const Reservation**>(tmp);
			cs_reservationPtr[cs_numOfConfirmation++] = &rsv;
		}


		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& rsv) {
		bool confirmation = true;
    size_t i = 0;


		for (; i < cs_numOfConfirmation && confirmation; i++) {
			if (cs_reservationPtr[i] == &rsv) {
				confirmation = false;
			}
		}

		if (!confirmation) { 
			Reservation** tmp = new Reservation * [cs_numOfConfirmation--];
			if (i > 0) {
				for (size_t j = 0; j < i; j++) { 
					tmp[j] = const_cast<Reservation*>(cs_reservationPtr[j]);
				}
			}
			for (size_t j = i; j < cs_numOfConfirmation; j++) {
				tmp[j] = const_cast<Reservation*>(cs_reservationPtr[j + 1]);
			}
			delete[] cs_reservationPtr;
			cs_reservationPtr = const_cast<const Reservation**>(tmp);
		}
		return *this;
	}

	ostream& operator<<(ostream& os, const ConfirmationSender& cs) {
		os << "--------------------------" << endl;
		os << "Confirmations to Send" << endl;
		os << "--------------------------" << endl;

		if (cs.cs_numOfConfirmation == 0) {
			os << "The object is empty!" << endl;
		}
		else {
			for (size_t i = 0; i < cs.cs_numOfConfirmation; i++) {
				os << *cs.cs_reservationPtr[i];
      }
		}
		os << "--------------------------" << endl;
		return os;
	}
}


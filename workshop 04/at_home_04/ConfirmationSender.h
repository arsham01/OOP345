// Name: Arsham Yaghoobi
// Seneca Student ID: 142927185
// Seneca email: ayaghoobi@myseneca.ca
// Date of completion: Feb-11-2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.



#ifndef SDDS_CONFIRMATIONSENDER_H__
#define SDDS_CONFIRMATIONSENDER_H__
#include <iostream>
#include "Reservation.h"
namespace sdds {
  class ConfirmationSender {
    const Reservation** cs_reservationPtr;
    size_t cs_numOfConfirmation;

    public:
    ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& cs);
		ConfirmationSender(ConfirmationSender&& cs);
		~ConfirmationSender();

    ConfirmationSender& operator+=(const Reservation& res);
    ConfirmationSender& operator-=(const Reservation& res);

    friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& cs);

  };
}
#endif
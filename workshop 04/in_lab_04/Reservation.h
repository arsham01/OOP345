// Name: Arsham Yaghoobi
// Seneca Student ID: 142927185
// Seneca email: ayaghoobi@myseneca.ca
// Date of completion: Feb-07-2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <string>


#ifndef SDDS_RESERVATION_H__
#define SDDS_RESERVATION_H__

namespace sdds {
  class Reservation {
    std::string r_reservationId;
    std::string r_nameOnReservation;
    std::string r_contactEmail;
    int r_numOfPeople;
    int r_dayOfReservation;
    int r_hourOfReservation;

    public:
    Reservation();
    Reservation(const std::string& reservation);
    friend std::ostream& operator<<(std::ostream& os, Reservation& reservation);
  };
}
#endif
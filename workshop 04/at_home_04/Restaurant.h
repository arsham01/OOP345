// Name: Arsham Yaghoobi
// Seneca Student ID: 142927185
// Seneca email: ayaghoobi@myseneca.ca
// Date of completion: Feb-11-2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include "Reservation.h"


#ifndef SDDS_RESTAURANT_H__
#define SDDS_RESTAURANT_H__

namespace sdds {
  class Restaurant {
    Reservation* r_reservation;
    size_t r_numOfReservations;

    public:
    Restaurant();
    Restaurant(Reservation* reservations[], size_t cnt);
    size_t size() const;
    Restaurant(const Restaurant& restaurant);
    Restaurant(Restaurant&& restaurant);
    friend std::ostream& operator<<(std::ostream& os, const Restaurant& restaurant);
  };
}
#endif
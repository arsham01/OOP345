// Name: Arsham Yaghoobi
// Seneca Student ID: 142927185
// Seneca email: ayaghoobi@myseneca.ca
// Date of completion: Feb-11-2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Restaurant.h"

using namespace std;

namespace sdds {
  Restaurant::Restaurant(){
    r_reservation = nullptr;
    r_numOfReservations = 0;
  }

  Restaurant::Restaurant(Reservation* reservations[], size_t cnt){
    r_numOfReservations = cnt;
    r_reservation = new Reservation[r_numOfReservations];

    for (size_t i = 0; i < r_numOfReservations; i++){
      r_reservation[i] = *reservations[i];
    }
  }

  Restaurant::Restaurant(const Restaurant& restaurant){
    if (this != &restaurant) {
			r_numOfReservations= restaurant.r_numOfReservations; 
      if (restaurant.r_reservation != nullptr) {
        r_reservation = new Reservation[r_numOfReservations]; 
        for (size_t i = 0; i < r_numOfReservations; i++) {
					r_reservation[i] = restaurant.r_reservation[i];
				}
			}
      else {
				r_reservation = nullptr;
			}
		}
  }

  Restaurant::Restaurant(Restaurant&& restaurant){
    r_numOfReservations = restaurant.r_numOfReservations;
		restaurant.r_numOfReservations = 0;
		r_reservation = restaurant.r_reservation;
		restaurant.r_reservation = nullptr;
  }

  size_t Restaurant::size() const{
    return r_numOfReservations;
  }

  ostream& operator<<(ostream& os, const Restaurant& restaurant){
    os << "--------------------------" << endl;
    os << "Fancy Restaurant" << endl;
    os << "--------------------------" << endl;
    if (restaurant.r_numOfReservations < 1){
      os << "The object is empty!" << endl;
    }
    else {
      for (size_t i = 0; i < restaurant.r_numOfReservations; i++){
        os << restaurant.r_reservation[i];
      }
    }
    os << "--------------------------" << endl;
    return os;
  }
}
// Name: Arsham Yaghoobi
// Seneca Student ID: 142927185
// Seneca email: ayaghoobi@myseneca.ca
// Date of completion: Feb-07-2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <string>
#include <iomanip>
#include "Reservation.h"
using namespace std;
namespace sdds {
  Reservation::Reservation() {
    r_reservationId = "";
    r_nameOnReservation = "";
    r_contactEmail = "";
    r_numOfPeople = 0;
    r_dayOfReservation = 0;
    r_hourOfReservation = 0;
  }

  Reservation::Reservation(const string& reservation) {
    string reservationId, nameOnReservation, contactEmail, numOfPeople, dayOfReservation, hourOfReservation;
    string str = reservation;

    reservationId = str.substr(0, str.find(':'));
    str.erase(0, str.find(':') + 1);
    nameOnReservation = str.substr(0, str.find(','));
    str.erase(0, str.find(',') + 1);
    contactEmail = str.substr(0, str.find(','));
    str.erase(0, str.find(',') + 1);
    numOfPeople = str.substr(0, str.find(','));
    str.erase(0, str.find(',') + 1);
    dayOfReservation = str.substr(0, str.find(','));
    str.erase(0, str.find(',') + 1);
    hourOfReservation = str.substr(0, str.find(','));
    reservationId.erase(reservationId.find_last_not_of(' ') + 1);
    reservationId.erase(0, reservationId.find_first_not_of(' '));
    nameOnReservation.erase(nameOnReservation.find_last_not_of(' ') + 1);
    nameOnReservation.erase(0, nameOnReservation.find_first_not_of(' '));
    contactEmail.erase(contactEmail.find_last_not_of(' ') + 1);
    contactEmail.erase(0, contactEmail.find_first_not_of(' '));

    contactEmail = "<" + contactEmail + ">";

    r_reservationId= reservationId;
    r_nameOnReservation = nameOnReservation;
    r_contactEmail = contactEmail;
    r_numOfPeople = stoi(numOfPeople);
    r_dayOfReservation = stoi(dayOfReservation);
    r_hourOfReservation = stoi(hourOfReservation);
  }

  ostream& operator<<(ostream& os, Reservation& reservation) {
    string srv[4] = {"Breakfast", "Lunch", "Dinner", "Drinks"};
    int value = 0;
    if (reservation.r_hourOfReservation >= 6 && reservation.r_hourOfReservation <= 9) {
      value = 0;
    } 
    else if (reservation.r_hourOfReservation >= 11 && reservation.r_hourOfReservation <= 15) {
      value = 1;
    } 
    else if (reservation.r_hourOfReservation >= 17 && reservation.r_hourOfReservation <= 21) {
      value = 2;
    } 
    else 
      value = 3;
        

    os << "Reservation " << reservation.r_reservationId << ": ";
    os << setw(10) << setfill(' ') << right << reservation.r_nameOnReservation << "  ";
    os << setw(24) << setfill(' ') << left << reservation.r_contactEmail;
    os << srv[value] << " on day " << reservation.r_dayOfReservation << " @ " << reservation.r_hourOfReservation 
      << ":00" << " for " << reservation.r_numOfPeople << " people." << '\n';
    return os;
  }
}
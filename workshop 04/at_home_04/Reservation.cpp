// Name: Arsham Yaghoobi
// Seneca Student ID: 142927185
// Seneca email: ayaghoobi@myseneca.ca
// Date of completion: Feb-07-2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <algorithm>
#include <iostream>

#include "Reservation.h"
using namespace std;
namespace sdds {

  Reservation::Reservation(){
    r_reservationId = "";
    r_nameOnReservation = "";
    r_contactEmail = "";
    r_numOfPeople = 0;
    r_dayOfReservation = 0;
    r_hourOfReservation = 0;
  }

  Reservation::Reservation(const std::string& res){
    auto id_l = res.find(':') + 1;
    auto name_l = res.find(','); 
    auto email_l = res.find(',', name_l + 1); 
    auto num_l = res.find(',', email_l + 1); 
    auto day_l = res.find(',', num_l + 1); 
    auto time_l = res.length(); 

    r_reservationId = res.substr(0, id_l); 
    r_reservationId.erase(remove( r_reservationId.begin(),  r_reservationId.end(), ' '),  r_reservationId.end()); 
    r_nameOnReservation = res.substr(id_l, name_l - id_l); 
    r_nameOnReservation .erase(remove(r_nameOnReservation .begin(), r_nameOnReservation .end(), ' '), r_nameOnReservation .end()); 
    r_contactEmail = res.substr(name_l + 1, email_l - name_l - 1); 
    r_contactEmail.erase(remove(r_contactEmail.begin(), r_contactEmail.end(), ' '), r_contactEmail.end()); 
    r_contactEmail.append(">"); 
    r_numOfPeople = stoi(res.substr(email_l + 1, num_l - email_l - 1)); 
    r_dayOfReservation = stoi(res.substr(num_l + 1, day_l - num_l - 1)); 
    r_hourOfReservation = stoi(res.substr(day_l + 1, time_l - day_l - 1)); 
    }


    ostream& operator<<(ostream& os, const Reservation& res) 
	{
        string time;
        if (res.r_hourOfReservation >= 6 && res.r_hourOfReservation <= 9){
            time = "Breakfast on day";
        }else if (res.r_hourOfReservation >= 11 && res.r_hourOfReservation <= 15){
            time = "Lunch on day";
        }else if (res.r_hourOfReservation >= 17 && res.r_hourOfReservation <= 21){
            time = "Dinner on day";
        }else {
            time = "Drinks on day";
        }
        os << "Reservation " << res.r_reservationId << setw(11) << right << res.r_nameOnReservation << "  <";
        os << setw(23) << left << res.r_contactEmail << time << " " << res.r_dayOfReservation << " @ " << res.r_hourOfReservation << ":00 for " << res.r_numOfPeople << " people." << endl;
        return os;
    }
    
}

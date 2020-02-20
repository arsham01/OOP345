// Name: Arsham Yaghoobi
// Seneca Student ID: 142927185
// Seneca email: ayaghoobi@myseneca.ca
// Date of completion: Feb-14-2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include "Book.h"

using namespace std;

namespace sdds{
  Book::Book(){
    b_author = "";
    b_title = "";
    b_countryOfPublication = "";
    b_yearOfPublication = 0;
    b_priceOfBook = 0.0;
    b_description = "";
  }

  const string& Book::title() const{
    return b_title;
  }

  const string& Book::country() const{
    return b_countryOfPublication;
  }

  const size_t& Book::year() const{
    return b_yearOfPublication;
  }

  double& Book::price(){
    return b_priceOfBook;
  }

  Book::Book(const string& strBook){
    string author, title, countryOfPublication, priceOfBook, yearOfPublication, description;
    string bstr = strBook;

    author = bstr.substr(0, bstr.find(','));
    bstr.erase(0, bstr.find(',') + 1);
    title = bstr.substr(0, bstr.find(','));
    bstr.erase(0, bstr.find(',') + 1);
    countryOfPublication = bstr.substr(0, bstr.find(','));
    bstr.erase(0, bstr.find(',') + 1);
    priceOfBook = bstr.substr(0, bstr.find(','));
    bstr.erase(0, bstr.find(',') + 1);
    yearOfPublication = bstr.substr(0, bstr.find(','));
    bstr.erase(0, bstr.find(',') + 1);
    description = bstr;

    author.erase(author.find_last_not_of(' ') + 1);
    author.erase(0, author.find_first_not_of(' '));
    title.erase(title.find_last_not_of(' ') + 1);
    title.erase(0, title.find_first_not_of(' '));
    countryOfPublication.erase(countryOfPublication.find_last_not_of(' ') + 1);
    countryOfPublication.erase(0, countryOfPublication.find_first_not_of(' '));
    description.erase(description.find_last_not_of(' ') + 1);
    description.erase(0, description.find_first_not_of(' '));

    b_author = author;
    b_title = title;
    b_countryOfPublication = countryOfPublication;
    b_priceOfBook = stod(priceOfBook);
    b_yearOfPublication = stoi(yearOfPublication);
    b_description = description;
  }

  ostream& operator<<(ostream& os, const Book& book){
    os << setw(20) << setfill(' ') << book.b_author << " | ";
    os << setw(22) << setfill(' ') << book.b_title << " | ";
    os << setw(5) << setfill(' ') << book.b_countryOfPublication << " | ";
    os << setw(4) << setfill(' ') << book.b_yearOfPublication << " | ";
    os << setw(6) << setfill(' ') << fixed << setprecision(2) << book.b_priceOfBook << " | ";
    os << setw(22) << setfill(' ') << book.b_description;
    os << endl;
    return os;
  }
}
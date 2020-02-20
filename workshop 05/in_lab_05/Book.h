// Name: Arsham Yaghoobi
// Seneca Student ID: 142927185
// Seneca email: ayaghoobi@myseneca.ca
// Date of completion: Feb-14-2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__

#include <iostream>
#include <iomanip>
#include <string>

namespace sdds{
  class Book {
    std::string b_author;
    std::string b_title;
    std::string b_countryOfPublication;
    size_t b_yearOfPublication;
    double b_priceOfBook;
    std::string b_description;

    public:

    Book();
    const std::string& title() const;
    const std::string& country() const;
    const size_t& year() const;
    double& price();
    Book(const std::string& strBook);
    friend std::ostream& operator<<(std::ostream& os, const Book& book);
  };
}
#endif
// Name: Arsham Yaghoobi 
// Seneca Student ID: 142927185
// Seneca email: ayaghoobi@myseneca.ca
// Date of completion: jan-23-2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_RECORDSET_H
#define SDDS_RECORDSET_H

#include <iostream>
#include <string>
#include <fstream>

namespace sdds{
  class RecordSet{
    size_t r_numOfStrings = 0;
    std::string* r_recs = nullptr;
    
  public:
    RecordSet();
    RecordSet(const char* name);
    RecordSet(const RecordSet& record);
    RecordSet(RecordSet&& record);
    RecordSet& operator=(const RecordSet& record);
    RecordSet& operator=(RecordSet&& record);
    ~RecordSet();
    size_t size();
    std::string getRecord(size_t idx);
  };
}



#endif


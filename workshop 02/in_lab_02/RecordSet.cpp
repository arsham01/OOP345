// Name: Arsham Yaghoobi 
// Seneca Student ID: 142927185
// Seneca email: ayaghoobi@myseneca.ca
// Date of completion: jan-23-2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include "RecordSet.h"

using namespace std;

namespace sdds{
  RecordSet::RecordSet(){
    r_numOfStrings = 0;
    r_recs = nullptr;
  }

  RecordSet::RecordSet(const char* name){
    string word;
    ifstream TestFile(name);
    while (!TestFile.eof() && TestFile.good()){
      getline(TestFile, word, ' ');
      word.clear();
      r_numOfStrings++;
    }

    if (TestFile.eof()){
      TestFile.clear();
      TestFile.seekg(0, TestFile.beg);
    }

    r_recs = new string[r_numOfStrings];

    for (unsigned int i = 0; i < r_numOfStrings; i++)
      getline(TestFile, r_recs[i], ' ');
  }

  RecordSet::RecordSet(const RecordSet& record){
    r_numOfStrings = record.r_numOfStrings;

    if (record.r_numOfStrings > 0){
      r_recs = new string[record.r_numOfStrings];
      for (unsigned int i = 0; i < r_numOfStrings; i++)
        r_recs[i] = record.r_recs[i];
    }
  }

  RecordSet& RecordSet::operator=(const RecordSet& record){
    if (this != &record){
      r_numOfStrings = record.r_numOfStrings;

      delete[] r_recs;
      r_recs = nullptr;
      if (record.r_numOfStrings > 0){
        r_recs = new string[record.r_numOfStrings];
        for (unsigned int i = 0; i < r_numOfStrings; i++)
          r_recs[i] = record.r_recs[i];
      }
    }
    return *this;
  }

  

  size_t RecordSet::size(){
    return r_numOfStrings;
  }

  string RecordSet::getRecord(size_t idx){
    if (idx <= r_numOfStrings && r_recs != nullptr)
      return r_recs[idx];
    else
      return "";
  }

  RecordSet::~RecordSet(){
    delete[] r_recs;
  }
}

// Name: Arsham Yaghoobi
// Seneca Student ID: 142927185
// Seneca email: ayaghoobi@yahoo.com
// Date of completion: jan-31-2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_SET_H
#define SDDS_SET_H

#include <cstring>

namespace sdds {
  template<typename T, unsigned int N>
  class Set {
    T s_arr[N];
    size_t s_count;
  public:
    Set() {
      s_count = 0;
    }

    size_t size() const {
      return s_count;
    }

    const T& operator[](size_t idx) const {
      return s_arr[idx];
    }

    void operator+=(const T& item) {
      if (s_count < N) {
        s_arr[s_count] = item;
        s_count++;
      }
    }
  };
}

#endif
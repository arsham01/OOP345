// Name: Arsham Yaghoobi
// Seneca Student ID: 142927185
// Seneca email: ayaghoobi@yahoo.com
// Date of completion: jan-31-2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_SETSUMMABLE_H__
#define SDDS_SETSUMMABLE_H__

#include <iostream>
#include "Set.h"

namespace sdds {
  template<typename T, unsigned int N, typename K, typename V>
  class SetSummable : public Set<T, N> {
  public:
    V accumulate(const K& key) const {
      T type_t;
			V acc = type_t.getInitialValue();

			for (size_t i = 0; i < ((Set<T, N>&) *this).size(); i++) 
			{
				if (key == ((Set<T, N>&)* this)[i].key()) 
				{
					acc = (*this)[i].sum(key, acc);
				}
			}
			return acc;
    }
  };
}
#endif 
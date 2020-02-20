// Name: Arsham Yaghoobi
// Seneca Student ID: 142927185
// Seneca email: ayaghoobi@yahoo.com
// Date of completion: jan-31-2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H

#include <iostream>

namespace sdds {
  template<typename K, typename V>
  class Pair {
    K p_key;
    V p_val;
  public:
    Pair() {
      p_key = {};
      p_val = {};
    }

    Pair(const K& key, const V& value) {
      p_key = key;
      p_val = value;
    }

    const K& key() const {
      return p_key;
    }

    const V& value() const {
      return p_val;
    }

    void display(std::ostream& os) const {
      os << p_key << " : " << p_val << std::endl;
    }
  };

  template<typename K, typename V>
  std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair) {
    pair.display(os);
    return os;
  }
}

#endif 
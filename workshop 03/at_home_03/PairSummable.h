// Name: Arsham Yaghoobi
// Seneca Student ID: 142927185
// Seneca email: ayaghoobi@yahoo.com
// Date of completion: jan-31-2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_PAIRSUMMABLE_H__
#define SDDS_PAIRSUMMABLE_H__

#include "Pair.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

namespace sdds {
  template<typename K, typename V>
  class PairSummable : public Pair<K, V> {
    static V p_val;
    static size_t p_width;
    public:

    static const V& getInitialValue() {
      return p_val;
    }

    PairSummable() : Pair<K, V>() {
			p_width = 0;
		}

    PairSummable(const K& key, const V& value) : Pair<K, V>(key, value) {
      if (p_width < key.size()) {
        p_width = key.size();
			}
    }

    V sum(const K& key, const V& val) const {
      if (this->key() == key) {
        return this->value() + val;
      }
			else {
        return val;
      }
    }

    void display(std::ostream& os) const {
      os.setf(ios::left);
			os.width(p_width);
			Pair<K, V>::display(os);
			os.unsetf(ios::left);
      }
  };

    template<class K, class V>
    size_t PairSummable<K, V>::p_width = 0;

    template<>
    string PairSummable<string, string> ::p_val = "";

    template<>
    int PairSummable<string, int> ::p_val = 0;

    template<>
    std::string PairSummable<std::string, std::string> ::sum(const std::string& key, const std::string& val) const {
        string tst;
        if (this->key() == key) {
            if (val == "") {
                tst = this->value();
            }
						 else {
                tst = val + ", " + this->value();
            }
        }
				 else {
            tst = val;
        }
        return tst;
    }
}
#endif
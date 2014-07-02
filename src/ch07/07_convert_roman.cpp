#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <string>
#include <map>

using namespace std;

template <typename T>
int convert_roman1(map<char, int> M, string roman, T &decimal) {
  int err = 0;

  // check whether roman contains valid alphabets
  // check whether it follows three exception rules
  
  T total = 0;
  
  int last_value = M[roman[0]];
  for(int i = 0, i_max = roman.length(); i < i_max; ++i) {
    int current = M[roman[i]];

    total += current;

    if(last_value < current) {
      total -= 2 * (M[roman[i - 1]]);
    }

    last_value = current;
  }

  decimal = total;

  return err;
}

int main(int argc, char **argv) {

  map<char, int> M {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
  };

  string s1;
  int v1;
  
  s1.assign("XXXXXIIIIIIIII");
  convert_roman1(M, s1, v1);
  printf("%d : %s\n", v1, s1.c_str());

  s1.assign("LVIIII");
  convert_roman1(M, s1, v1);
  printf("%d : %s\n", v1, s1.c_str());

  s1.assign("LIX");
  convert_roman1(M, s1, v1);
  printf("%d : %s\n", v1, s1.c_str());
  
  return 0;
}

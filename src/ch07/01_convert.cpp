#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <algorithm>
#include <limits>
#include <string>

using namespace std;

template <typename T>
int int_to_str1(T in, string &out) {
  int err = 0;

  if(!(numeric_limits<T>::is_integer)) {
    err = -EINVAL;
    return err;
  }

  bool is_negative = false;
  if(numeric_limits<T>::is_signed) {
    if(0 > in) {
      is_negative = true;
      in *= -1;
    }
  }

  out.clear();

  while(in) {
    const char digit = '0' + static_cast<char>(in % 10);
    in /= 10;

    out.push_back(digit);
  }
  
  if(is_negative) {
    out.push_back('-');
  }

  reverse(out.begin(), out.end());
    
  return err;
}

template <typename T>
int str_to_int1(string in, T &out) {
  int err = 0;

  // check errors
  
  bool is_negative = ('-' == in[0]) ? true : false;

  T value = T(0);
  for(int i = (is_negative) ? 1: 0, i_max = in.length(); i < i_max; ++i) {
    value = (in[i] - '0') + value * 10;

    // how about overflow check?
  }

  if(is_negative) {
    value = -value;
  }

  out = value;
    
  return err;
}

int main(int argc, char **argv) {

  int i1 = -123;
  string s1 = "";

  int_to_str1(i1, s1);

  printf("%s\n", s1.c_str());

  str_to_int1(s1, i1);

  printf("%d\n", i1);
  
  return 0;
}

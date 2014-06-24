#include "include/common.h"

template <typename T>
int reverse1(const T in, T &out) {
  int err = 0;

  out = 0;
  for(int i = 0, i_max = sizeof(T) * 8; i < i_max; ++i) {
    T bit = in & (1 << i);
    out |= ((bit >> i) << (sizeof(T) * 8 - 1 - i));
  }
  
  return err;
}

// solution alternative
// consider it as reverse binary divide by 2 and ...

// lookup table

 
int main(int argc, char **argv) {

  int in = 0b101;
  int out = 0;

  reverse1(in, out);
  printf("in is %X out is %X\n", in, out);
  
  return 0;
}

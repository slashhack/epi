#include "include/common.h"

template <typename T>
int find1(const T in, T &out) {
  int err = 0;

  for(int i = 0, i_max = sizeof(T) * 8 - 1; i < i_max; i++) {
    // swap i and i + 1 bit
    // if not the same as in, then return otherwise keep going

    T _i = in & (1 << i);
    T _j = in & (1 << (i + 1));

    _i >>= i;
    _j >>= (i + 1);

    if(_i != _j) {
      out = in;
      out ^= ((1 << i) | (1 << (i + 1)));
      return err;
    }
  }

  return err;
}

int main(int argc, char **argv) {

  int i = 0b01100;
  int j = 0;

  find1(i, j);

  printf("i = %d and j = %d\n", i, j);
  
  return 0;
}

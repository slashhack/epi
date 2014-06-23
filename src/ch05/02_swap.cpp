#include "include/common.h"

template<typename T>
int swap1(T &in, const int i, const int j) {
  int err = 0;

  T _i = in & (1 << i);
  T _j = in & (1 << j);

  in ^= (_i | _j);
  
  _i = ((_i) >> i) << j;
  _j = ((_j) >> j) << i;

  in |= (_i | _j);
  
  return err;
}

int main(int argc, char **argv) {

  int a = 0b100;
  int b = a;
  swap1(b, 0, 2);

  printf("a is %d => %d\n", a, b);
  
  return 0;
}

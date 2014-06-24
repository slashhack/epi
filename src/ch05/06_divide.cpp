#include "include/common.h"


template <typename T>
int divide1(const T x, const T y, T &out) {
  int err = 0;

  T _x(x);
  T result(0);
  
  while(y <= _x) {
    _x -= y;
    ++result;
  }

  out = result;
  
  return err;
}


// solution from book

int main(int argc, char **argv) {

  int x = 0x123;
  int y = 0x12;
  int z = 0;

  divide1(x, y, z);

  printf("%d %d %d\n", x, y, z);

  
  return 0;
}

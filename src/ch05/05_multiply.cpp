#include "include/common.h"

template <typename T>
int multiply1(const T x, const T y, T &out) {
  int err = 0;

  T result = T(0);

  for(int i = 0, i_max = sizeof(T) * 8; i < i_max; ++i) {
    if((y >> i) & T(1)) {
      result += (x << i);
    }
  }

  out = result;
  
  return err;
}

// solution from book
template <typename T>
int multiply2(const T x, const T y, T &out) {
  int err = 0;

  return err;
}

int main(int argc, char **argv) {

  int x = 0x123;
  int y = 0x234;
  int z = 0;

  multiply1(x, y, z);

  printf("%d %d %d\n", x, y, z);
  
  return 0;
}


#include "include/common.h"

template<typename T>
int swap1(const T in, const int i, const int j, T &out) {
  int err = 0;

  T bit_i_value = (in >> i) & T(1);
  T bit_j_value = (in >> j) & T(1);

  T temp = in ^ ((T(1) << i) | (T(1) << j));

  temp |= (bit_i_value << j) | (bit_j_value << i);

  out = temp;
  
  return err;
}

template<typename T>
int swap2(const T in, int i, int j, T &out) {
  int err = 0;

  // similar to swap1 except swap when it requires
  // e.g. i th bit value != j th bit value
  
  return err;
}

int main(int argc, char **argv) {

  int a = 0b100;
  int b = a;
  swap1(a, 1, 2, b);

  printf("a is %d => %d\n", a, b);
  
  return 0;
}

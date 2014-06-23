#include "include/common.h"

template <typename T>
void swap1(T &a, T &b) {
  T temp = b;
  b = a;
  a = temp;
}

template <typename T>
void swap2(T &a, T &b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;

  // shorthand form
  // a ^= b ^= a ^= b; or vice versa
}

// bit operation, set, clear, toggle & test (or get)

// and more minor stuffs

int main(int argc, char **argv) {

  printf("%s\n", argv[0]);

  int a = 1;
  int b = 99;
  swap2(a, b);

  printf("%d %d\n", a, b);
   
  
  return 0;
}

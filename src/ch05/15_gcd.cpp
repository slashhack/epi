#include "include/common.h"

template <typename T>
int gcd1(T x, T y, T &gcd) {
  int err = 0;

  // naive approach
  /* 1. pick the smallest
   * 2. find root of it
   * 3. test whether gcd is divisible for both x and y
   */

  T m = x;
  T M = y;
  if(m > M) {
    M = x;
    m = y;
  }

  T r = sqrt(m);
  // ...
  
  return err;
}

template <typename T>
int gcd2(T x, T y, T &gcd) {
  // gcd(x, y) = gcd(x, y - x) iff x <= y

  // naive recursion

  int err = 0;

  return err;
}

int main(int argc, char **argv) {

  return 0;
}

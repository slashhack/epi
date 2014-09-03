#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

template<typename T>
bool equal(const T a, const T b, const T eps) {
  return (a < b) ? (eps < b - a) : (eps < a - b);
}

template<typename T>
int sqrt1(const T in, T &out) {

  const T EPS = 0.1;
  
  int err = 0;

  T low;
  T high;
  
  if(1.0 < in) {
    low = 1.0;
    high = in;
  } else {
    low = 0.0;
    high = in;
  }

  while(low < high) {
    T mid = (low + high) / 2;

    T square = mid * mid;

    if(equal(in, square, EPS)) {
      out = mid;
      break;
    } else if(in < square) {
      high = mid;
    } else {
      low = mid;
    }
  }

  return err;
}

int main(int argc, char **argv) {

  return 0;
}

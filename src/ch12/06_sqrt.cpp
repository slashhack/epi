#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

template<typename T>
int sqrt1(const T in, T &out) {
  int err = 0;

  T low = 0;
  T high = in;

  T pos = -1;
  
  while(low <= high) {
    T mid = low + (high - low) >> 2;

    T square = mid * mid;

    if(in > square) {
      pos = mid;

      low = mid + 1;
    } else if(in < square) {
      high = mid - 1;
    } else {
      pos = mid;
      break;
    }
  }

  if(-1 != pos) {
    out = pos;
  }

  
  return err;
}

int main(int argc, char **argv) {

  return 0;
}

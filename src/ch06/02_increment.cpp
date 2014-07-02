#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

template <int N>
struct BigInteger {
  enum {
    SIZE = N,
  };
  
  int number[N];
};

typedef BigInteger<10> BigInt10;

int increment1(BigInt10 in, BigInt10 &out) {
  int err = 0;

  int carry_in = 1;
  int carry_out = 0;
  for(int i = in.SIZE - 1; i >= 0; --i) {
    int result = in.number[i] + carry_in;

    if(10 <= result) {
      result -= 10;
      carry_out = 1;
    }

    out.number[i] = result;

    carry_in = carry_out;
    carry_out = 0;
  }

  return err;
}

int main(int argc, char **argv) {

  BigInt10 in;
  BigInt10 out;

  in.number[9] = 3;
  in.number[8] = 2;
  in.number[7] = 1;

  for(int i = 0; i < 10; ++i) {
    in.number[9] = i;
    increment1(in, out);
    
    printf("%d %d %d\n", out.number[7], out.number[8], out.number[9]);
  }
  
  return 0;
}

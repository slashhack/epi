#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

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

template <typename T>
int bit_set(T &bit, int i) {
  int err = 0;

  if(sizeof(T) * 8 <= i) {
    err = -EINVAL;
    return err;
  }

  bit |= (T(1) << i);
  
  return err;
}

template <typename T>
int bit_reset(T &bit, int i) {
  int err = 0;

  if(sizeof(T) * 8 <= i) {
    err = -EINVAL;
    return err;
  }

  bit &= ~(T(1) << i);
  // using xor to reset (a^a = 0)

  return err;
}

template <typename T>
int bit_toggle(T &bit, int i) {
  int err = 0;

  if(sizeof(T) * 8 <= i) {
    err = -EINVAL;
    return err;
  }

  bit ^= (T(1) << i);
  // (0 ^ 1 = 1, 1 ^ 1 = 0)

  return err;
}

template<typename T>
int bit_test(T bit, int i, int &ret) {
  int err = 0;

  if(sizeof(T) * 8 <= i) {
    err = -EINVAL;
    return err;
  }

  ret = static_cast<int>((bit >> i) & T(1));
  
  return err;
}

template <typename T>
int bit_lsb(T in, T &out) {
  int err = 0;

  out = in & ~(in - 1);
  
  return err;
}


int main(int argc, char **argv) {

  int a = 1;
  int b = 99;
  swap2(a, b);

  DBG_BACKTRACE("%d %d\n", a, b);

  return 0;
}

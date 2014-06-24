#include "include/common.h"

template <typename T>
int parity1(const T in, int &out) {
  int err = 0;

  int count = 0;
  for(int i = 0, i_max = sizeof(T) * 8; i < i_max; ++i) {
    if(in & (1 << i)) {
      ++count;
    }
  }

  out = count;
  
  return err;
}

template <typename T>
int parity2(T in, int &out) {
  int err = 0;

  int count = 0;
  while(in) {
    in &= (in - 1);
    ++count;
  }
        
  out = count;

  return err;
}


/*
 * need look up table
 * see meta programming
 */
int lookup_table_3[sizeof(uint32_t) * 8] = { 0 };
void init_lookup_table_3(void) {
  for(int i = 0, i_max = sizeof(uint32_t) * 8; i < i_max; ++i) {
    int parity = -1;
    parity1(i, parity);
    lookup_table_3[i] = parity;
  }
}

template<typename T>
int parity3(const T in, int &out) {
  int err = 0;
  int count = 0;

  for(int i = 0, i_max = sizeof(T); i < i_max; ++i) {
    const int shift = i * 8;
    const T mask = 0xFF << shift;

    count += lookup_table_3[(in & mask) >> shift];
  }
 
  out = count;
  return err;
}

template <typename T>
struct Lookup {
  int table[1 << (sizeof(T) * 8)];

  int init(void) {
    int err = 0;
    
    for(int i = 0, i_max = sizeof(table) / sizeof(table[0]); i < i_max; ++i) {
      T t(i);
      int parity = 0;

      err = parity1(t, parity);
      if(err) {
        return err;
      }

      table[i] = parity;
    }

    return err;
  }

  int query(T t, int &parity) {
    int err = 0;

    parity = table[t];
    
    return err;
  }
};

int main(int argc, char **argv) {

  int in = 1024 - 1;
  int parity = 0;
  parity2(in, parity);
  printf("in = %d has parity %d\n", in, parity);

  init_lookup_table_3();
  parity3(in, parity);
  printf("in = %d has parity %d\n", in, parity);


  Lookup<uint64_t> lookup;
  lookup.init();

  lookup.query(in, parity);
  printf("parity is %d\n", parity);
  
  return 0;
}

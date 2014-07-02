#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <vector>
#include <limits>

using namespace std;

template <typename T>
int primes1(T n, vector<T> &primes) {
  int err = 0;

  vector<T> vec;
  vec.resize(n);
  vec.clear();
  
  for(int i = 2; i < n; ++i) {
    // is_prime(i)

    // push i to vec

  }

  primes.resize(vec.size());
  // copy method

  return err;
}
  
int main(int argc, char **argv) {

  int n1 = 100;
  vector<int> v1;

  primes1(n1, v1);
    
  return 0;
}

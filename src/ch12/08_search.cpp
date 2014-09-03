#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <vector>

#include <algorithm>

using namespace std;

template<typename T>
int search1(const vector<T> v1, const vector<T> v2, const int k, T &out) {
  int err = 0;

  int v1_low = 0;
  int v1_high = min(k, static_cast<int>(v1.size()));

  int v2_low = 0;
  int v2_high = min(k, static_cast<int>(v2.size()));
  
  return err;
}

int main(int argc, char **argv) {

  vector<int> v1({1, 2, 3, 4, 5});
  vector<int> v2({2, 4, 6, 8, 9});

  int k = 3;

  int out = 0;

  search1(v1, v2, k, out);
  
  return 0;
}





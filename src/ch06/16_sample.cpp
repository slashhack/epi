#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <vector>

using namespace std;

template <typename T>
int sample1(vector<T> in, int k, vector<T> &out) {
  int err = 0;

  return err;
}

int main(int argc, char **argv) {

  vector<int> v1;
  for(int i = 0; i < 10; ++i) {
    v1.push_back(i);
  }

  vector<int> v2;

  sample1(v1, 1, v2);
  
  return 0;
}

#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <vector>

using namespace std;

int remove1(vector<int> in, int k, vector<int> &out) {
  int err = 0;

  out.resize(in.size());
  
  int shift = 0;
  for(int i = 0, i_max = in.size(); i < i_max; ++i) {
    if(k == in[i]) {
      ++shift;
    } else {
      out[i - shift] = in[i];
    }
  }
  
  // unnecessary
  for(int i = 0; i < shift; i++) {
    out[in.size() - i - 1] = 0;
  }

  return err;
}

int main(int argc, char **argv) {

  vector<int> v1({5, 3, 7, 11, 2, 3, 13, 5, 7});
  int k1 = 3;

  vector<int> v2;
  remove1(v1, k1, v2);

  for(int i = 0; i < v1.size(); ++i) {
    printf("%d %d\n", i, v2[i]);
  }
  
  return 0;
}

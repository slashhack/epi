#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <vector>

using namespace std;

int unique1(vector<int> in, vector<int> &out, int &count) {
  int err = 0;

  out.resize(in.size());
  
  int unique_count = 1;
  int last_value = in[0];
  out[0] = last_value;

  for(int i = 1, i_max = in.size(); i < i_max; ++i) {
    if(last_value != in[i]) {
      out[unique_count++] = in[i];

      last_value = in[i];
    }
  }

  // fill zeros

  count = unique_count;
  
  return err;
}

int main(int argc, char **argv) {

  vector<int> v1({2, 3, 5, 5, 7, 11, 11, 11, 13});
  vector<int> v2;
  int count = 0;

  unique1(v1, v2, count);

  for(int i = 0; i < v1.size(); ++i) {
    printf("%d of %d : %d\n", i, count, v2[i]);
  }
  
  return 0;
}

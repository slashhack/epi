#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <vector>

using namespace std;

template <typename T>
int permute1(vector<T> in, vector<T> &out) {
  int err = 0;

  vector<int> curr_permute(in.size());
  for(int i = 0, i_max = in.size(); i < i_max; ++i) {
    curr_permute[in[i]] = i;
  }

  // compute next permutation
  for(int i = 0; i < in.size(); ++i) {
    printf("%d %d %d\n", i, in[i], curr_permute[i]);
  }
  
  out.resize(in.size());
  
  
  return err;
}

int main(int argc, char **argv) {

  vector<int> out;
  vector<int> in;
  {
    int arr[] = {2, 0, 1, 3};
    for(int i = 0, i_minx = sizeof(arr) / sizeof(arr[0]); i < i_minx; ++i) {
      in.push_back(arr[i]);
    }
  }

  permute1(in, out);
  
  
  return 0;
}

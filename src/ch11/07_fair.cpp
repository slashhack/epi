#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <vector>

using namespace std;

template<typename T>
int fair1(const vector<T> in, vector<int> &out) {
  int err = 0;

  out.resize(in.size());
  for(auto &i: out) {
    i = -1;
  }

  const int size = in.size();
  int processed = 0;

  while(size != processed) {

    // 0 th element (compare with right)
    if(-1 == out[0]) {
      if(in[0] <= in[1]) {
        out[0] = 1;
        ++processed;
      } else {
        if(-1 != out[1]) {
          out[0] = out[1] + 1;
          ++processed;
        }
      }
    }
    
    // 1 to size - 2 (compare both)
    for(int i = 1, i_max = in.size() - 1; i < i_max; ++i) {
      if(-1 != out[i]) {
        continue;
      }

      // complex logic is it good?
      if(-1 != out[i - 1]) {
        if(-1 != out[i + 1]) {

        } else {

        }
      } else {
        if(-1 != out[i + 1]) {

        } else {

        }
      }
    }

    // size - 1 (compare left)
    if(-1 == out[size - 1]) {
      if(in[size - 2] >= in[size - 1]) {
        out[size - 1] = 1;
        ++processed;
      } else {
        if(-1 != out[size - 2]) {
          out[size - 1] = out[size - 2] + 1;
          ++processed;
        }
      }
    }
  }

  return err;
}

// solution from book

int main(int argc, char **argv) {

  vector<int> in1({3,4,5,2});
  vector<int> out1;

  fair1(in1, out1);


  return 0;
}

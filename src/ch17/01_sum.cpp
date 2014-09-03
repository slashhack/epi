#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <vector>

using namespace std;

template<typename T>
int permute_sum1(const vector<T> &w, const T s, int &cnt) {
  int err = 0;

  int local_cnt = 0;
  if(0 < s) {
    for(int i = 0, i_max = w.size(); i < i_max; ++i) {
      int c = 0;
      permute_sum1(w, s - w[i], c);

      local_cnt += c;
    }
  }

  cnt = local_cnt;

  return err;
};

template<typename T>
int combine_sum1(const vector<T> &w, const T s, int &cnt) {
  int err = 0;

  

  return err;
}

int main(int argc, char **argv) {

  return 0;
}

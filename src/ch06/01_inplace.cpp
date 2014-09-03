#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <vector>

using namespace std;

int get_pivot(vector<int> vec, int &pivot) {
  int err = 0;

  if(vec.empty()) {
    err = -EINVAL;
    return err;
  }

  int any = vec[random() % vec.size()];

  pivot = any;
  
  return err;
}

template<typename T>
int inplace1(int pivot, vector<T> &vec) {
  int err = 0;

  // split vector into three parts, i) <, ii) == and iii) >

  int lt = 0;
  int eq = 0;

  const T p = vec[pivot];

  for(auto i: vec) {
    if(p == i) {
      ++eq;
    } else if(p > i) {
      ++lt;
    }
  }

  int lt_idx = 0;
  int eq_idx = lt;
  int gt_idx = lt + eq;

  for(int i = 0, i_max = vec.size(); i < i_max; ++i) {
    T val = vec[i];

    if(p == val) {

    } else if(p > val) {

    } else {

    }
  }

  
  return err;
}

int main(int argc, char **argv) {

  vector<int> v1;
  for(int i = 0; i < 10; ++i) {
    v1.push_back(i);
  }

  int p1 = 0;
  get_pivot(v1, p1);

  printf("p1 is %d\n", p1);

  inplace1(p1, v1);
  
  return 0;
}

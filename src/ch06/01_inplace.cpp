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

int inplace1(int pivot, vector<int> &vec) {
  int err = 0;

  // split vector into three parts, i) <, ii) == and iii) >

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

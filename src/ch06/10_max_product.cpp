#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <vector>

using namespace std;

template <typename T>
int max_product1(vector<T> vec, T &product) {
  int err = 0;

  if(1 >= vec.size()) {
    err = -EINVAL;
    return err;
  }
  

  return err;
}

int main(int argc, char **argv) {

  vector<int> v1;
  for(int i = 0, i_max = 10; i < i_max; ++i) {
    v1.push_back(random() % 100 - 50);
  }

  int product = 0;
  max_product1(v1, product);

 for(int i = 0, i_max = 10; i < i_max; ++i) {
    printf("%d : %d\n", i, v1[i]);
  }
  
  return 0;
}

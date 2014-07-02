#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <vector>
#include <limits>

using namespace std;

template <typename T>
int lci(vector<T> vec, int &begin, int &end) {

  int err = 0;

  // how about single element case?
  if(vec.empty()) {
    err = -EINVAL;
    return err;
  }

  int priv_begin = 0;
  int priv_end = 0;

  int curr_begin = 0;

  T last_value = numeric_limits<T>::lowest();

  for(int i = 0, i_max = vec.size(); i < i_max; ++i) {
    if(last_value < vec[i]) {
      
    } else {
      if((priv_end - priv_begin) < ((i - 1) - curr_begin)) {
        priv_begin = curr_begin;
        priv_end = i - 1;
      }
      curr_begin = i;
    }
    last_value = vec[i];
  }

  if((priv_end - priv_begin) < ((vec.size() - 1) - curr_begin)) {
    priv_begin = curr_begin;
    priv_end = vec.size() - 1;
  }

  begin = priv_begin;
  end = priv_end;
    
  return err;
}

int main(int argc, char **argv) {

  vector<int> v1;
  for(int i = 0, i_max = 10; i < i_max; ++i) {
    v1.push_back(rand() % 100 - 50);
  }

  int begin = 0;
  int end = 0;
  
  lci(v1, begin, end);

  printf("lci begin %d and end %d\n", begin, end);

  for(int i = 0, i_max = 10; i < i_max; ++i) {
    printf("%d : %d\n", i, v1[i]);
  }

  return 0;
}

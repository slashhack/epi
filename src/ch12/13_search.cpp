#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <vector>
#include <queue>

using namespace std;

template<typename T>
int search1(const vector<T> in, const int k, T &out) {
  int err = 0;

  T min_item;
  int min_idx;

  vector<T> storage;

  for(int i = 0; i < k; ++i) {
    storage.push_back(in[i]);
  }

  min_item = storage[0];
  min_idx = 0;

  for(int i = 0; i < k; ++i) {
    if(min_item > storage[i]) {
      min_item = storage[i];
      min_idx = i;
    }
  }

  for(int i = k, i_max = in.size(); i < i_max; ++i) {
    if(min_item < in[i]) {
      storage.erase(storage.begin() + min_idx);

      storage.push_back(in[i]);

      min_item = in[i];
      min_idx = k - 1;

      for(int j = 0, j_max = k - 1; j < j_max; ++j) {
        if(min_item > storage[j]) {
          min_item = storage[j];
          min_idx = j;
        }
      }
    }
  }
  

  return err;
}

// min heap version

// solution from the book

int main(int argc, char **argv) {

  return 0;
}

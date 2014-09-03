#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <vector>

using namespace std;

template<typename T>
int bsearch1(const vector<T> in, const T target, int &idx) {
  int err = 0;

  int l = 0;
  int h = in.size() - 1;

  int pos = -1;

  while(l <= h) {
    int m = l + (h - l) >> 1;

    if(in[m] > target) {
      h = m - 1;
    } else if(in[m] < target) {
      l = m + 1;
    } else {
      pos = m;
      break;
    }
  }

  if(-1 == pos) {
    // not found
    return err;
  }

  // backward linear search to find the first occurrence of target
  while(0 <= pos) {
    if(in[pos] == target) {
      --pos;
    }
  }
  
  idx = pos + 1;
  
  return err;
}

template<typename T>
int bsearch2(const vector<T> in, const T target, int &idx) {
  int err = 0;

  int l = 0;
  int h = in.size() - 1;

  int pos = -1;
  
  while(l <= h) {
    int m = l + (h - l) >> 1; // prevent overflow

    if(in[m] > target) {
      h = m - 1;
    } else if(in[m] < target) {
      l = m + 1;
    } else {
      pos = m;

      h = m - 1;
    }
  }

  if(-1 != pos) {
    idx = pos;
  } else {
    // not found set a appropriate error
  }
  
  return err;
}

int main(int argc, char **argv) {

  return 0;
}

#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <vector>

using namespace std;

template<typename T>
int intersect1(const vector<T> &a, const vector<T> &b, vector<T> &out) {
  int err = 0;

  if(a.empty() || b.empty()) {
    err = -EINVAL;
    return err;
  }

  int i = 0;
  int j = 0;

  // O(a.size() + b.size())
  while((a.size() > i) && (b.size() > i)) {
    if(a[i] == b[j]) {
      out.emplace_back(a[i]);

      ++i;
      ++j;
    } else if(a[i] < b[j]) {
      ++i;
    } else {
      ++j;
    }
  }
  
  return err;
}

template<typename T>
int intersect2(const vector<T> &a, const vector<T> &b, vector<T> &out) {
  int err = 0;

  // O(a.size() * log(b.size()))
  for(int i = 0, i_max = a.sie(); i < i_max; ++i) {

    const T &t = a[i];
    
    int low = 0;
    int high = b.size();

    while(low <= high) {
      const int mid = low + (high - low) >> 1;
      if(t == b[mid]) {
        out.emplace_back(t);
        break;
      } else if(t < b[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    // binary_search in algorithm.h
  }

  
  return err;
}

int main(int argc, char **argv) {

  return 0;
}

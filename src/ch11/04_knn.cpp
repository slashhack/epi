#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <vector>

using namespace std;

template<typename T>
struct Star {
  int id;

  T x;
  T y;
  T z;
};

template<typename T>
int knn1(const vector<Star<T>> in, const int k, vector<Star<T>> &out) {
  int err = 0;

  // maintain max heap with capacity k + 1
  // whenever max heap is full, then pop a max one
  // note that it can avoid push via comparison
  

  
  return err;
}
  

int main(int argc, char **argv) {

  return 0;
}

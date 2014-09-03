#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <vector>

using namespace std;

template<typename T>
int search1(const vector<T> in, const int k, T &idx) {
  int err = 0;

  int left = 0;
  int right = in.size() - 1;

  srand(time(NULL));

  vector<T> vec(in);
  
  while(left <= right) {

    const int pivot_idx = left + (rand() % (right - left + 1));
    const T pivot = vec[pivot_idx];
    printf("pivot %d\n", pivot);
    swap(vec[pivot_idx], vec[right]);

    vector<T> lt;
    vector<T> gt;

    for(int i = left, i_max = right; i < i_max; ++i) {
      if(pivot > vec[i]) {
        lt.push_back(vec[i]);
      } else {
        gt.push_back(vec[i]);
      }
    }

    const int partition = left + lt.size();
    
    lt.push_back(pivot);
    lt.insert(lt.end(), gt.begin(), gt.end());

    swap_ranges(vec.begin() + left, vec.begin() + right + 1, lt.begin());

    for(auto i: vec) 
      printf("%d\n", i);


    int direction = static_cast<int>(in.size()) - k - partition;
    
    break;
  }

  return err;
}

int main(int argc, char **argv) {

  vector<int> v1({3, 2, 1, 5, 4});
  int k = 3;

  int idx = 0;
  search1(v1, k, idx);
  
  return 0;
}

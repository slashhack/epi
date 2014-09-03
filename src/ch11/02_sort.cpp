#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
int sort1(const vector<T> in, vector<T> &out) {
  int err = 0;

  int k = 1;
  bool ge = true;

  vector<int> forward;
  vector<int> backward;

  forward.push_back(0);
  
  for(int i = 1, i_max = in.size(); i < i_max; ++i) {
    if(ge) {
      if(in[i - 1] > in[i]) {
        ge = false;
        ++k;

        backward.push_back(i - 1);
      }
    } else {
      if(in[i - 1] <= in[i]) {
        ge = true;
        ++k;

        forward.push_back(i - 1);
      }
    }
  }

  out = in;
  
  // sentinal value
  forward.push_back(in.size());
  for(int i = 0, i_max = backward.size(); i < i_max; ++i) {
    reverse(out.begin() + backward[i], out.begin() + forward[i + 1]);
  }
  forward.pop_back();

  // k way merge each index are stored in either forward or backward vector
  vector<int> indices;
  indices.insert(indices.end(), forward.cbegin(), forward.cend());
  indices.insert(indices.end(), backward.cbegin(), backward.cend());
  sort(indices.begin(), indices.end()); // not necessary

  // k way merge using indices on vector out
  
  return err;
}

// refer solution to get a idea
// basic idea is reverse as possible as i can


int main(int argc, char **argv) {

  vector<int> v1({57, 131, 494, 294, 221, 339, 418, 452, 442, 190});
  vector<int> v2;

  sort1(v1, v2);
  
  return 0;
}


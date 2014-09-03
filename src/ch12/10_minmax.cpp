#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <algorithm>

#include <vector>

using namespace std;

template<typename T>
int min_max1(const vector<T> in, pair<T, T> &min_max) {
  int err = 0;

  pair<T, T> m_M;
  // 1 comparisons
  m_M = minmax(in[0], in[1]);

  for(int i = 2, i_max = in.size() - 1; i < i_max; i+=2) {
    // 3 comparisons
    pair<T, T> local = minmax(in[i], in[i + 1]);
    m_M.first = min(m_M.first, local.first);
    m_M.second = max(m_M.second, local.second);
  }

  if(in.size() % 2) {
    T last = in[in.size() - 1];
    // 2 comparisons
    m_M.first = min(m_M.first, last);
    // if min value is changed, then do not need to process further
    m_M.second = max(m_M.second, last);
  }

  min_max = m_M;
  
  return err;
}

int main(int argc, char **argv) {

  vector<int> v1({4,2,3,5,1});
  pair<int, int> min_max;

  min_max1(v1, min_max);

  printf("%d %d\n", min_max.first, min_max.second);
  
  return 0;
}

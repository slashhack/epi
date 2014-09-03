#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <vector>
#include <queue>

using namespace std;

/*
 * median
 * if container contains odd, then the middle one
 * if not, then a mean of two middle values
 */ 

template<typename T>
int median1(vector<T> in, T &median) {
  int err = 0;

  // max heap for smaller half and min heap for larger half
  // maintain balance (size of both heap)

  priority_queue<T, vector<T>, greater<T>> right; // min heap
  priority_queue<T, vector<T>, less<T>> left; // max heap
  
  T m;
  for(T t: in) {
    //min_heap.push(t);
    //max_heap.push(t);
    DBG("push %d\n", t);
    if(left.empty()) {
      left.push(t);
    } else {
      if(t > left.top()) {
        right.push(t);
      } else {
        left.push(t);
      }

      // need to debug size_t (might be related to sign/unsigned
      // conversion but need to figure out why it happens)
      size_t diff = left.size() - right.size(); printf("%d %d %d\n", diff, 2< diff, -2 > diff);
      if(1 < diff) {
        right.push(left.top());
        left.pop();
        DBG("%s\n", "left -> right");
      } else if(-1 > diff) {
        left.push(right.top());
        right.pop();
        DBG("%s\n", "right -> left");
      }
      printf("%d %d\n", left.size(), right.size());
    }
    
    if(left.size() == right.size()) {
      // prevent overflow
      m = static_cast<T>((left.top() + (right.top() - left.top()) / 2));
    } else {
      if(left.size() > right.size()) {
        m = left.top();
      } else {
        m = right.top();
      }
    }
    DBG("m is %d\n", m);
  }

  median = m;

  
  return err;
}

int main(int argc, char **argv) {


  vector<int> a({1, 2, 3});
  int mead = 0;

  median1(a, mead);
  
  return 0;
}

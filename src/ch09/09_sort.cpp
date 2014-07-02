#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <stack>

using namespace std;

// similar to bubble sort
template<typename T>
int sort1(const stack<T> in, stack<T> &out) {
  int err = 0;

  out = in;

  

  return err;
}

template<typename T>
void pop_rec(stack<T> &s) {

  if(!s.empty()) {
    T top = s.top();
    s.pop();

    pop_rec(s);

    sort_rec(s, top);
  }
}

template<typename T>
void sort_rec(stack<T> &s, const T t) {
  if(s.empty()) {
    s.push(t);
  } else {
    if(t > s.top()) {
      s.push(t);
    } else {
      T top = s.top();
      sort_rec(s, t);
      s.push(top);
    }
  }
}

int main(int argc, char **argv) {

  stack<int> in1;
  stack<int> in2;
  
  for(int i: {5, 4, 3, 2, 1}) {
    in1.push(i);
  }

  sort1(in1, in2);

  while(!in2.empty()) {
    printf("%d\n", in2.top());
    in2.pop();
  }
  
  DBG("sizeof in2 is %lu\n", in2.size());
  
  return 0;
}



#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <stack>
#include <array>

using namespace std;

int hanoi1(int n) {
  int err = 0;
  if(0 >= n) {
    err = -EINVAL;
    return err;
  }

  array<stack<int>, 3> pegs;
  for(int i = 0; i < n; ++i) {
    pegs[0].push(n - i);
  }

  hanoi1_helper(pegs, 0, 1, 2);
  
  return err;
}

void hanoi1_helper(array<stack<int>, 3> &pegs, const int src, const int dst, const int temp) {

  int ring = -1;
  
  if(!pegs[src].empty()) {
    // move top ring from src to temp
    pegs[src].top();
    pegs[src].pop();

    pegs[temp].push(ring);
    
    // move src to dst
    hanoi1_helper(pegs, src, dst, temp);
    
    // move temp to dst

    ring = pegs[temp].top();
    pegs[temp].pop();

    pegs[dst].push(ring);
  }
}


int main(int argc, char **argv) {

  return 0;
}

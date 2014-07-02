#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <string>
#include <stack>

using namespace std;

int pbb1(string str, bool matched) {
  // using two stacks

  // phase 1 push target chars to a buffer

  // phase 2 pop one by one try to match
  // if close then pop it and put into another buffer
  // if open then pop from another buffer and test whether matched or
  // not

  int err = 0;

  return err;
}

int pbb2(string str, bool matched) {
  // similar to previous, but complete it by single scan

  int err = 0;

  return err;
}

int main(int argc, char **argv) {

  return 0;
}

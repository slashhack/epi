#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <string>

using namespace std;

int next_sequence1(string in, string &out) {
  int err = 0;

  char lookup = in[0];
  int count = 1;

  out.clear();
  
  // need string buffer or equivalent method to reduce overhead
  for(int i = 1, i_max = in.size(); i < i_max; ++i) {
    if(lookup == in[i]) {
      ++count;
    } else {
      for(auto c: to_string(count)) {
        out.push_back(c);
      }
      out.push_back(lookup);

      lookup = in[i];
      count = 1;
    }
  }

  for(auto c: to_string(count)) {
    out.push_back(c);
  }
  out.push_back(lookup);
  
  return err;
}

int look_and_say1(int n, string &str) {
  int err = 0;

  string curr;
  string next;

  curr.assign("1");
  for(int i = 1; i < n; ++i) {
    next_sequence1(curr, next);
    curr.assign(next);
  }
  str.assign(curr);

  return err;
}

int main(int argc, char **argv) {

  int n1 = 8;
  string s1;

  look_and_say1(n1, s1);

  printf("%d : %s\n", n1, s1.c_str());
        
  return 0;
}

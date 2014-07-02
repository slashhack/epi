#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <algorithm>
#include <string>

using namespace std;

int reverse1(string in, string &out) {
  int err = 0;

  out.assign(in);

  int last_start = 0;
  for(int i = 1, i_max = out.size(); i < i_max; ++i) {
    if(' ' == out[i]) {
      reverse(out.begin() + last_start, out.begin() + i);
      last_start = i + 1;
    }
  }
  reverse(out.begin() + last_start, out.end());

  reverse(out.begin(), out.end());
  
  return err;
}

int main(int argc, char **argv) {

  string s1;
  string s2;

  s1.assign("Alice like Bob");
  
  reverse1(s1, s2);

  printf("%s => %s\n", s1.c_str(), s2.c_str());

  return 0;
}

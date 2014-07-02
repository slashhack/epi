#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <string>

using namespace std;

int encode1(string in, string &out) {
  int err = 0;

  string encoded;
  
  char last_ch = in[0];
  int count = 0;
  for(int i = 1, i_max = in.length(); i < i_max; ++i) {
    if(last_ch == in[i]) {
      ++count;
    } else {
      for(auto ch: to_string(count)) {
        encoded.push_back(ch);
      }
      encoded.push_back(last_ch);

      last_ch = in[i];
      count = 1;
    }
  }

  if(count) {
    for(auto ch: to_string(count)) {
      encoded.push_back(ch);
    }
    encoded.push_back(last_ch);
  }
  
  return err;
}

int decode1(string in, string &out) {
  int err = 0;

  return err;
}

int main(int argc, char **argv) {

  return 0;
}

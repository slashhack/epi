#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <string>

using namespace std;

int modify1(string in, string &out) {

  int err = 0;

  out.assign(in);

  int shift = 0;
  for(int i = 0, i_max = out.length(); i < i_max; ++i) {
    if('b' == out[i]) {
      --shift;
    } else {
      out[i + shift] = out[i];
    }
  }
  size_t current_size = out.size() + shift;    
  out.resize(2 * (current_size));  // assume worst case

  shift = 0;
  // can't replace string from forward because of overlap
  // need to figure out an occurence of character 'a' in the previous
  for(int i = 0; i < current_size; ++i) {
    if('a' == out[i]) {

    } else {
      
    }
  }
  
  
  return err;
}

int main(int argc, char **argv) {


  string in;
  in.assign("abcd");

  string out;

  modify1(in, out);

  printf("len %d str %s\n", out.length(), out.c_str());
  
  return 0;
}

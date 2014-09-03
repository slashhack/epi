#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <string>
#include <map>

#include <algorithm>

using namespace std;

int search1(const string L, const string M, bool searchable) {
  int err = 0;

  // enought storage and so on

  // depending on constraints there are many ways to figure out
  // whether given L is constructible from M

  map<char, int> dict;
  for(int i = 0, i_max = L.length(); i < i_max; ++i) {
    ++dict[L[i]];
  }


  // swap inner and outer loops to reduce time complexity
  for(auto token: dict) {
    int count = 0;
    for(char ch: M) {
      if(token.first == ch) {
        ++count;
      }

      if(token.second <= count) {
        break;
      }
    }

    if(count > token.second) {
      // can't constructible
    }
  }

  // constructible
  
  
  return err;
}

int main(int argc, char **argv) {

  return 0;
}

#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <string>

#include <vector>

using namespace std;

/*
 * compose of 3 dots => nested?
 */ 
int valid_ip1(string addr, vector<string> ips) {
  
  int err = 0;

  // input check using isdigit
  for(int i = 0, i_max = addr.length(); i < i_max; ++i) {
    if(!isdigit(addr[i])) {
      err = -EINVAL;
      return err;
    }
  }
  
  int valid = 0;
  for(int i = 1; i < 4; ++i) {
    
    for(int j = 1; j < 4; ++j) {

      for(int k = 1; k < 4; ++k) {

      }
    }
  }
  
  return err;
}

int main(int argc, char **argv) {

  return 0;
}

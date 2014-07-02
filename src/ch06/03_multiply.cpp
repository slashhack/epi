#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <string>

using namespace std;

int multiply1(string x, string y, string &z) {
  int err = 0;

  if(x.empty() || y.empty()) {
    err = -EINVAL;
    return err;
  }

  bool x_sign = ('-' == x[0] ? true : false);
  bool y_sign = ('-' == y[0] ? true : false);
  bool z_sign = x_sign ^ y_sign;
  
  return err;
}

int main(int argc, char **argv) {

  string a = "-1";
  string b = "1";
  string c = "";

  multiply1(a, b, c);
  
  return 0;
}

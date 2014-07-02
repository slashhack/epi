#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <math.h>

#include <string>

#include <map>
#include <vector>

using namespace std;

int mnemonic1(const map<char, string> M, const string in, vector<string> &out) {
  int err = 0;


  out.clear();
  out.push_back(in);

  return err;
}

int main(int argc, char **argv) {

  map<char, string> M;
  M['0'] = "";
  M['1'] = "";
  M['2'] = "ABC";
  M['3'] = "DEF";
  M['4'] = "GHI";
  M['5'] = "JKL";
  M['6'] = "MNO";
  M['7'] = "PQRS";
  M['8'] = "TUV";
  M['9'] = "WXYZ";

  string in1;
  in1.assign("2276696");

  vector<string> out1;

  mnemonic1(M, in1, out1);

  for(auto s: out1) {
    printf("%s\n", s.c_str());
  }
  printf("Done\n");
  
  return 0;
}

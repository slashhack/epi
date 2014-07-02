#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <string>
#include <stack>

using namespace std;

int pathname1(string in, string &out) {
  int err = 0;

  char * str = new char[in.length() + 1];
  strcpy(str, in.c_str());

  stack<string> path;

  char * token = strtok(str, ",");
  // can't verify whether a path is relative or absolute
  while(token) {
    if(!strcmp(".", token)) {
      // skip current
    } else if(!strcmp("..", token)) {
      // check error whether it tries to pop from an empty
      path.pop();
    } else {
      // validate token
      path.push(token);
    }

    token = strtok(NULL, ",");
  }

  delete[] str;
  
  return err;
}
  
int main(int argc, char **argv) {

  return 0;
}

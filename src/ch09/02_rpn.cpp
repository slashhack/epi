#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <string>
#include <stack>

using namespace std;

template<typename T>
int rpn1(string rpn, T &result) {
  int err = 0;

  stack<T> eval;

  char * rpn_str = new char[rpn.length() + 1];
  strcpy(rpn_str, rpn.c_str());

  const char * first = strtok(rpn_str, ",");
  const char * second = strtok(NULL, ",");
  const char * op = strtok(NULL, ",");
  
  T local(0);

  eval.push(local);
  
  while(true) {

  }
      
  
  return err;
}

int main(int argc, char **argv) {

  int a;
  rpn1("", a);
  
  return 0;
}

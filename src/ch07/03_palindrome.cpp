#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <string>

using namespace std;

int palindrome1(string str, bool &palindrome) {
  int err = 0;

  bool is_palindrome = true;
  
  int f_idx = 0;
  int b_idx = str.length() - 1;

  while(true) {
    while((!isalnum(str[f_idx])) && (f_idx < str.size())) {
      ++f_idx;
    }

    while((!isalnum(str[b_idx])) && (0 <= b_idx)) {
      --b_idx;
    }
    
    if(f_idx > b_idx) {
       break;
    }

    // can be integrated with previous conditional statement
    if(tolower(str[f_idx]) != tolower(str[b_idx])) {
      is_palindrome = false;
      break;
    }

    ++f_idx;
    --b_idx;
  }

  palindrome = is_palindrome;
  
  return err;
}

int main(int argc, char **argv) {

  string str;
  bool palindrome;
  
  str.assign("A man, a plan, a canal, Panama.");
  palindrome1(str, palindrome);
  printf("%d : %s\n", palindrome, str.c_str());

  str.assign("Able was I, ere I saw Elba!");
  palindrome1(str, palindrome);
  printf("%d : %s\n", palindrome, str.c_str());

  str.assign("Ray a Ray");
  palindrome1(str, palindrome);
  printf("%d : %s\n", palindrome, str.c_str());
  
  return 0;
}

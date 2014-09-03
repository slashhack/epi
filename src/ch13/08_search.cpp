#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <vector>
#include <string>
#include <map>

using namespace std;

int search1(const vector<string> words, int &closest) {
  int err = 0;

  int closest_length = words.size();

  map<string, int> dict;
  for(int i = 0, i_max = words.size(); i < i_max; ++i) {
    const string &word = words[i];

    auto it = dict.find(word);
    if(dict.end() != it) {
      int old_pos = it->second;

      int diff = i - old_pos;
      if(closest_length < diff) {
        closest_length = diff;
      }
      
      it->second = i;
    } else {
      dict[word] = i;
    }
  }

  if(words.size() == closest_length) {
    // no closest pair
  }
  
  closest = closest_length;
  
  return err;
}
 
int main(int argc, char **argv) {

  return 0;
}

#include "include/common.h"
#include "include/util.h"
#include "include/dbg.h"

#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int anagram1(const vector<string> words, vector<vector<string>> &anagrams) {
  int err = 0;

  map<string, vector<string>> dict;
  
  for(string word: words) {
    string signature(word);
    sort(signature.begin(), signature.end());

    dict[signature].push_back(word);
  }

  for(auto anagram: dict) {
    if(1 < anagram.second.size()) {
      anagrams.push_back(anagram.second);
    }
  }
  
  return err;
}

int main(int argc, char **argv) {

  return 0;
}

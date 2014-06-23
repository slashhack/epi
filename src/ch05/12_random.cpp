#include "include/common.h"


#include <time.h>

int zero_or_one(void) {
  return ((RAND_MAX / 2) < random()) ? 1 : 0;
}

template <typename T>
int random1(T a, T b, T &number) {
  int err = 0;

  // random number should be a <= number <= b

  // binary tree?
  
  return err;
}


int main(int argc, char **argv) {

  srand(time(NULL));
  
  printf("%d %d %d\n", zero_or_one(), zero_or_one(), zero_or_one());
  
  return 0;
}

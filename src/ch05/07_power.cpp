#include "include/common.h"

template <typename T1, typename T2>
int power1(const T1 x, const T2 y, T1 &out) {
  
  int err = 0;

  T1 result(1);

  for(int i = 0, i_max = sizeof(T2) * 8; i < i_max; ++i) {
    if((y >> i) & 1) {
      //result += (x << i);
      for(int j = 0; j <= i; ++j) {
        result *= x;
      }
    }
  }

  out = result;
  
  return err;
}
  

int main(int argc, char **argv) {

  printf("Hello World\n");

  double x = 1.1;
  int y = 2;
  double z = 0;

  power1(x, y, z);

  printf("%f %d %f\n", x, y, z);

  
  return 0;
}

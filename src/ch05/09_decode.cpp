#include "include/common.h"

int decode1(const char * id, int &idx) {
  int err = 0;

  int value = 0;

  char * id_ptr = (char *) id;
  while(*id_ptr) {
    value = (*id_ptr - 'A' + 1) + value * 26;

    ++id_ptr;
  }

  idx = value;
  

  return err;
}

int main(int argc, char **argv) {

  const char * id = NULL;
  int idx = 0;

  id = "A";
  decode1(id, idx);
  printf("id = %s : %d\n", id, idx);

  id = "B";
  decode1(id, idx);
  printf("id = %s : %d\n", id, idx);

  id = "Z";
  decode1(id, idx);
  printf("id = %s : %d\n", id, idx);

  id = "AA";
  decode1(id, idx);
  printf("id = %s : %d\n", id, idx);
  
  return 0;
}

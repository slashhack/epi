#include "include/common.h"

struct Rectangle {
  float x;
  float y;

  float width;
  float height;
};

int intersect1(Rectangle r1, Rectangle r2, Rectangle &intersect) {
  int err = 0;

  // intersect? how about overlap or inside

  float r1_center_x = r1.x + r1.width / 2;
  float r1_center_y = r1.y + r1.height / 2;

  float r2_center_x = r2.x + r2.width / 2;
  float r2_center_y = r2.y + r2.height / 2;

  //  float center_dist = pow((r1_center_x - r2_center_x), 2) + pow((r1_centey_y - r2_center_y), 2); 
  
  return err;
}

int intersect2(Rectangle r1, Rectangle r2, Rectangle &intersect) {
  int err = 0;

  // with max and min point 
  
  return err;
} 

int main(int argc, char **argv) {

  return 0;
}

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {

  int a = INT_MAX;
  float b = FLT_MAX;
  double c = DBL_MAX;

  printf("Size: %lu\nValue: %d\n\n", sizeof(a), a);
  printf("Size: %lu\nValue: %f\n\n", sizeof(b), b);
  printf("Size: %lu\nValue: %lf\n\n", sizeof(c), c);

  return 0;
}

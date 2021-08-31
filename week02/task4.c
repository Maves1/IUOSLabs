#include <stdio.h>

void mySwapper(int *a, int *b) {
  int c = *b;
  *b = *a;
  *a = c;
}

int main() {

  printf("Enter two integers: \n");

  int a, b;
  scanf("%d %d", &a, &b);

  mySwapper(&a, &b);
  printf("%d %d\n", a, b);

  return 0;
}

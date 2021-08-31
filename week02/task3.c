#include <stdio.h>
#include <string.h>

int main() {

  printf("Enter the height: \n");

  int height;
  scanf("%d", &height);

  int width = 2 * height - 1;
  for (int i = 1; i <= height; i++) {
    int rowStars = 2 * i - 1;
    int rowSpaces = width - rowStars / 2;

    // printf("%d %d\n", rowStars, rowSpaces);

    for (int j = 0; j < rowSpaces; j++) {
      printf(" ");
    }
    for (int j = 0; j < rowStars; j++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}

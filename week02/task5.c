#include <stdio.h>
#include <string.h>

void printTree() {
  int height = 10;

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
}

void printTriangle() {
  int height = 10;

  int width = 2 * height - 1;
  for (int i = 1; i <= height; i++) {
    int rowStars = 2 * i - 1;

    for (int j = 0; j < rowStars; j++) {
      printf("*");
    }

    printf("\n");
  }
}

void printSomething() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("*");
    }
    printf("\n");
  }
}

int main() {

  int mode;
  printf("Enter the number of the figure:\n1. Tree\n2. Right Triangle\n3. Something Strange\n");
  scanf("%d", &mode);
  switch (mode) {
    case 1:
      printTree();
      break;
    case 2:
      printTriangle();
      break;
    case 3:
      printSomething();
      break;
  }


  return 0;
}

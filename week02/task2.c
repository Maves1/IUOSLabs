#include <stdio.h>
#include <string.h>

int main() {

  printf("Enter a string: \n");

  char userString[1000];
  scanf("%s", userString);
  int stringLength = strlen(userString);

  for (int i = stringLength - 1; i >= 0; i--) {
    printf("%c", userString[i]);
  }
  printf("\n");

  return 0;
}

#include <stdio.h>

void bubble_sort(int array[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j > i; j--) {
      if (array[j - 1] > array[j]) {
        int c = array[j - 1];
        array[j - 1] = array[j];
        array[j] = c;
      }
    }
  }
}

int main() {

  int n = 6;
  int arr[] = {5, 6, 1, 4, 23, 11};
  bubble_sort(arr, n);

  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}

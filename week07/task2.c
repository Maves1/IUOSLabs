#include <stdio.h>
#include <stdlib.h>

void createAndDestroyArray(int n) {
    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        arr[i] = i;
        printf("%d ", arr[i]);
    }

    free(arr);
}

int main() {

    int n;

    printf("Enter N:\n");
    scanf("%d", &n);

    createAndDestroyArray(n);

    return 0;
}



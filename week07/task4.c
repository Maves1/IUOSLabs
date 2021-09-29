#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void* wow_realloc(void *ptr, int size, int new_size) {
    if (ptr == NULL) {
        return malloc(new_size);
    }
    if (new_size == 0) {
        free(ptr);
    } else if (new_size > size) {
        void *new_ptr = malloc(new_size);
        memcpy(new_ptr, ptr, size);
        free(ptr);
        return new_ptr;
    } else {
        return ptr;
    }
}

int main() {

    int *arr = malloc(sizeof(int) * 2);
    arr[0] = 1;
    arr[1] = 9;

    int *new_arr = wow_realloc(arr, 8, 16);
    new_arr[2] = 56;
    new_arr[3] = 71;

    for (int i = 0; i < 4; i++) {
        printf("%d ", new_arr[i]);
    }

	return 0;
}

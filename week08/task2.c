#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
 * Findings:
 * When I set the size to ~1Gb, si and so change, and the program is killed after the third "for" is run
 * When the size is ~500Mb, the program is killed after the 6th "for" is run
 *
 * For Task 3:
 * I could see how the amount of free memory decreased, and task2.out was the most memory-eating program
 */

int main() {

    int n = 10;
    int size = 500 * 1024 * 1024;

    int *ptr;
    for (int i = 0; i < n; i++) {
        ptr = malloc(size);
        memset(ptr, 0, size);
        sleep(1);

        printf("Run %d\n", i);
    }

    return 0;
}



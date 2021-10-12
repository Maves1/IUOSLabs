#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/resource.h>

/*
 * Findings:
 *
 */

int main() {

    int n = 10;
    int size = 100 * 1024 * 1024;
    struct rusage *rusage = malloc(sizeof(struct rusage));

    int *ptr;
    for (int i = 0; i < n; i++) {
        ptr = malloc(size);
        memset(ptr, 0, size);
        sleep(1);

        getrusage(RUSAGE_SELF, rusage);
        printf("Data segment memory usage: %li\n", (*rusage).ru_maxrss);

        printf("Run %d\n", i);
    }

    return 0;
}



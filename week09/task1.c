#include <stdlib.h>
#include <stdio.h>
#include <float.h>

int findPage(int n, int *frames, int page) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == page) {
            return i;
        }
    }
    return -1;
}

int findOldestPage(int n, int *frames, int *counters) {
    int min = 1000;
    int minIndex = -1;
    for (int i = 0; i < n; i++) {
        if (counters[i] < min) {
            min = counters[i];
            minIndex = i;
        } else if (counters[i] == min) {
            if (frames[i] < frames[minIndex]) {
                minIndex = i;
            }
        }
    }
    return minIndex;
}

int main() {

    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    int *frames = calloc(n, sizeof(int));
    int *counters = calloc(n, sizeof(int));
    int *r_bits = calloc(n, sizeof(int));

    int hits = 0;
    int misses = 0;
    int totalPages = 0;

    int prevClock = 0;
    for (int i = 0; i < m; i++) {
        int clock, currPage;
        scanf("%d %d", &clock, &currPage);

        if (clock > prevClock) {
            for (int j = 0; j < n; j++) {
                counters[j] = counters[j] >> (clock - prevClock);
                counters[j] = counters[j] | (r_bits[j] << 7);
                r_bits[j] = 0;
            }
            prevClock = clock;
        }

        if (findPage(n, frames, currPage) == -1) {
            misses++;
            if (totalPages < n) {
                frames[totalPages] = currPage;
                r_bits[totalPages] = 1;
                totalPages++;
            } else {
                int minIndex = findOldestPage(n, frames, counters);
                frames[minIndex] = currPage;
                r_bits[minIndex] = 1;
                counters[minIndex] = 0;
            }
            printf("0\n");
        } else {
            hits++;
            int index = findPage(n, frames, currPage);
            r_bits[index] = 1;
            printf("1\n");
        }
    }

    float hmRatio = hits / (float) misses;
    printf("%f\n", hmRatio);

    return 0;
}





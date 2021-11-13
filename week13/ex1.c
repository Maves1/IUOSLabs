#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {

    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("ex1.txt", "w");

    int n, m;
    n = 3;
    m = 5;

    int *totalResources = malloc(sizeof(int) * n);
    int *availableResources = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        fscanf(input, "%d", &totalResources[i]);
    }
    for (int i = 0; i < n; i++) {
        fscanf(input, "%d", &availableResources[i]);
    }

    int *currentlyInUse[m];
    for (int i = 0; i < m; i++) {
        currentlyInUse[i] = malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            fscanf(input, "%d", &currentlyInUse[i][j]);
        }
    }

    int *requested[m];
    for (int i = 0; i < m; i++) {
        requested[i] = malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            fscanf(input, "%d", &requested[i][j]);
        }
    }

    int *satisfied = calloc(sizeof(int) * m, 0);

    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < m; i++) {
            if (satisfied[i] == 0) {
                bool canSatisfy = true;
                for (int j = 0; j < n; j++) {
                    if (requested[i][j] > availableResources[j]) {
                        canSatisfy = false;
                        break;
                    }
                }
                if (canSatisfy) {
                    for (int j = 0; j < n; j++) {
                        availableResources[j] += requested[i][j] + currentlyInUse[i][j];
                    }
                    satisfied[i] = 1;
                    changed = true;
                }
            }
        }
    }

    bool deadlock = false;
    for (int i = 0; i < m; i++) {
        if (satisfied[i] == 0) {
            deadlock = true;
            fprintf(output, "%d ", i + 1);
        }
    }

    if (deadlock) {
        fprintf(output, "\n are deadlocked!\n");
    } else {
        fprintf(output, "\nNo deadlocks!\n");
    }
    
    fclose(input);
    fclose(output);

    return 0;
}

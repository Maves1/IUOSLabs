#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void sortByArrivalTimes(int n, int *arrivalTimes, int *burstTimes) {
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j <= i; j++) {
            if (arrivalTimes[j] < arrivalTimes[j - 1]) {
                int t = arrivalTimes[j];
                arrivalTimes[j] = arrivalTimes[j - 1];
                arrivalTimes[j - 1] = t;

                t = burstTimes[j];
                burstTimes[j] = burstTimes[j - 1];
                burstTimes[j - 1] = t;
            }
        }
    }
}

void calcTimes(int n,
               int *arrivalTimes, int *burstTimes,
               int *waitingTimes, int *completionTimes, int *turnaroundTimes) {
    int quantum = 89;

    waitingTimes[0] = 0;

    int *remBurstTimes = malloc(sizeof(int) * n);
    memcpy(remBurstTimes, burstTimes, sizeof(int) * n);

    int t = arrivalTimes[0];
    int notFinished = n;
    bool hasExecuted = false;
    while (notFinished > 0) {
        hasExecuted = false;
        for (int i = 0; i < n; i++) {
            if (arrivalTimes[i] <= t && remBurstTimes[i] > 0) {
                if (remBurstTimes[i] > quantum) {
                    t += quantum;
                    remBurstTimes[i] -= quantum;
                } else {
                    t += remBurstTimes[i];
                    remBurstTimes[i] = 0;
                    notFinished--;
                    waitingTimes[i] = t - burstTimes[i] - arrivalTimes[i];

                    completionTimes[i] = t;
                    turnaroundTimes[i] = completionTimes[i] - arrivalTimes[i];
                }
                hasExecuted = true;
            }
        }
        if (!hasExecuted && notFinished > 0) {
            t++;
        }
    }

}

int main() {

    int numberOfProcesses = 7;
    int arrivalTimes[numberOfProcesses];
    int burstTimes[numberOfProcesses];

    for (int i = 0; i < numberOfProcesses; i++) {
        scanf("%d", &arrivalTimes[i]);
        scanf("%d", &burstTimes[i]);
    }

    sortByArrivalTimes(numberOfProcesses, arrivalTimes, burstTimes);

    int *waitingTimes = malloc(sizeof(int) * numberOfProcesses);
    int *completionTimes = malloc(sizeof(int) * numberOfProcesses);
    int *turnaroundTimes = malloc(sizeof(int) * numberOfProcesses);

    for (int i = 0; i < numberOfProcesses; i++) {
        waitingTimes[i] = 0;
        completionTimes[i] = 0;
        turnaroundTimes[i] = 0;
    }

    calcTimes(numberOfProcesses, arrivalTimes, burstTimes, waitingTimes, completionTimes, turnaroundTimes);

    float sumOfTurnaroundTimes = 0;
    float sumOfWaitingTimes = 0;
    for (int i = 0; i < numberOfProcesses; i++) {
        printf("Process [%d]: AT: %d WT: %d, TT: %d, CT: %d\n",
               i, arrivalTimes[i], waitingTimes[i], turnaroundTimes[i], completionTimes[i]);
        sumOfTurnaroundTimes += turnaroundTimes[i];
        sumOfWaitingTimes += waitingTimes[i];
    }

    float averageTurnaround = sumOfTurnaroundTimes / numberOfProcesses;
    float averageWaiting = sumOfWaitingTimes / numberOfProcesses;

    printf("Average TT: %f\n", averageTurnaround);
    printf("Average WT: %f\n", averageWaiting);


    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void bubbleSort(int n, int *arrivalTimes, int *burstTimes) {
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

int* getWaitingTimes(int n, int *arrivalTimes, int *burstTimes) {
    int *waitingTimes = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        waitingTimes[i] = arrivalTimes[0] - arrivalTimes[i];
        for (int j = 0; j < i; j++) {
            waitingTimes[i] += burstTimes[j];
        }
    }

    return waitingTimes;
}

int* getTurnaroundTimes(int n, int *burstTimes, int *waitingTimes) {
    int *turnaroundTimes = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        turnaroundTimes[i] = burstTimes[i] + waitingTimes[i];
    }

    return turnaroundTimes;
}

int *getCompletionTimes(int n, int *burstTimes, int *waitingTimes, int *arrivalTimes) {
    int *completionTimes = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        completionTimes[i] = burstTimes[i] + waitingTimes[i] + arrivalTimes[i];
    }

    return completionTimes;
}

int main() {

    int numberOfProcesses = 5;
    int arrivalTimes[numberOfProcesses];
    int burstTimes[numberOfProcesses];

    for (int i = 0; i < numberOfProcesses; i++) {
        scanf("%d", &arrivalTimes[i]);
        scanf("%d", &burstTimes[i]);
    }

    bubbleSort(numberOfProcesses, arrivalTimes, burstTimes);
    int *waitingTimes = getWaitingTimes(numberOfProcesses, arrivalTimes, burstTimes);
    int *turnaroundTimes = getTurnaroundTimes(numberOfProcesses, burstTimes, waitingTimes);
    int *completionTimes = getCompletionTimes(numberOfProcesses, burstTimes, waitingTimes, arrivalTimes);

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



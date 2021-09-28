#include <stdio.h>
#include <stdlib.h>

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

void sortByBurstTimes(int n, int *arrivalTimes, int *burstTimes) {
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j <= i; j++) {
            if (arrivalTimes[j] == arrivalTimes[j - 1]) {
                if (burstTimes[j] < burstTimes[j - 1]) {
                    int t = burstTimes[j];
                    burstTimes[j] = burstTimes[j - 1];
                    burstTimes[j - 1] = t;
                }
            }
        }
    }
}

void calcTimes(int n,
               int *arrivalTimes, int *burstTimes,
               int *waitingTimes, int *completionTimes, int *turnaroundTimes) {

    int sumOfBurstTimes = burstTimes[0];
    int i = 1;
    while (i < n - 1) {
        if (burstTimes[i] < burstTimes[i + 1]) {
            waitingTimes[i] = sumOfBurstTimes - arrivalTimes[i];
            sumOfBurstTimes += burstTimes[i];
            completionTimes[i] = sumOfBurstTimes;
            turnaroundTimes[i] = sumOfBurstTimes - arrivalTimes[i];
        } else {
            if (arrivalTimes[i + 1] <= sumOfBurstTimes) {
                int t = burstTimes[i];
                burstTimes[i] = burstTimes[i + 1];
                burstTimes[i + 1] = t;

                t = arrivalTimes[i];
                arrivalTimes[i] = arrivalTimes[i + 1];
                arrivalTimes[i + 1] = t;

                t = waitingTimes[i];
                waitingTimes[i] = waitingTimes[i + 1];
                waitingTimes[i + 1] = t;

                t = completionTimes[i];
                completionTimes[i] = completionTimes[i + 1];
                completionTimes[i + 1] = t;

                t = turnaroundTimes[i];
                turnaroundTimes[i] = turnaroundTimes[i + 1];
                turnaroundTimes[i + 1] = t;

                waitingTimes[i] = sumOfBurstTimes - arrivalTimes[i];
                sumOfBurstTimes += burstTimes[i];
                completionTimes[i] = sumOfBurstTimes;
                turnaroundTimes[i] = sumOfBurstTimes - arrivalTimes[i];
            }
        }
        i++;
    }
    waitingTimes[n - 1] = sumOfBurstTimes - arrivalTimes[n - 1];
    sumOfBurstTimes += burstTimes[n - 1];
    completionTimes[n - 1] = sumOfBurstTimes;
    turnaroundTimes[n - 1] = sumOfBurstTimes - arrivalTimes[n - 1];
}

int main() {

    int numberOfProcesses = 5;
    int arrivalTimes[numberOfProcesses];
    int burstTimes[numberOfProcesses];

    for (int i = 0; i < numberOfProcesses; i++) {
        scanf("%d", &arrivalTimes[i]);
        scanf("%d", &burstTimes[i]);
    }

    sortByArrivalTimes(numberOfProcesses, arrivalTimes, burstTimes);
    sortByBurstTimes(numberOfProcesses, arrivalTimes, burstTimes);

    printf("\n");
    for (int i = 0; i < numberOfProcesses; i++) {
        printf("%d %d\n", arrivalTimes[i], burstTimes[i]);
    }

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


//    int *waitingTimes = getWaitingTimes(numberOfProcesses, arrivalTimes, burstTimes);
//
//    for (int i = 0; i < numberOfProcesses; i++) {
//        printf("%d\n", waitingTimes[i]);
//    }


    return 0;
}



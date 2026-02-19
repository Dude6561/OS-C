#include <stdio.h>

int main() {

    int numberOfProcesses = 3;
    int burstTime[3] = {5, 3, 8};
    int priority[3] = {2, 1, 3};
    int waitingTime[3];
    int turnAroundTime[3];
    int i, j, temp;

    for(i = 0; i < numberOfProcesses; i++) {
        for(j = i + 1; j < numberOfProcesses; j++) {
            if(priority[i] > priority[j]) {

                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;
            }
        }
    }

    waitingTime[0] = 0;

    for(i = 1; i < numberOfProcesses; i++) {
        waitingTime[i] = waitingTime[i-1] + burstTime[i-1];
    }

    for(i = 0; i < numberOfProcesses; i++) {
        turnAroundTime[i] = waitingTime[i] + burstTime[i];
        printf("Process %d  BT=%d  WT=%d  TAT=%d\n",
               i+1, burstTime[i], waitingTime[i], turnAroundTime[i]);
    }

    return 0;
}

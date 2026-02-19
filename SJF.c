#include <stdio.h>

int main() {

    int numberOfProcesses = 3;
    int burstTime[3] = {6, 2, 8};
    int waitingTime[3];
    int turnAroundTime[3];
    int i, j, temp;

    for(i = 0; i < numberOfProcesses; i++) {
        for(j = i + 1; j < numberOfProcesses; j++) {
            if(burstTime[i] > burstTime[j]) {
                temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;
            }
        }
    }

    waitingTime[0] = 0;

    for(i = 1; i < numberOfProcesses; i++) {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
    }

    for(i = 0; i < numberOfProcesses; i++) {
        turnAroundTime[i] = waitingTime[i] + burstTime[i];
    }

    for(i = 0; i < numberOfProcesses; i++) {
        printf("Process %d  Burst Time=%d  Waiting Time=%d  TurnAround Time=%d\n",
               i + 1, burstTime[i], waitingTime[i], turnAroundTime[i]);
    }

    return 0;
}

#include <stdio.h>
#include <limits.h>

int main() {

    int numberOfProcesses = 3;
    int burstTime[3] = {5, 3, 8};
    int priority[3] = {2, 1, 3};
    int remainingTime[3];
    int waitingTime[3] = {0};
    int turnAroundTime[3];
    int completedProcesses = 0;
    int currentTime = 0;
    int i, highestPriority, selectedProcess;

    for(i = 0; i < numberOfProcesses; i++) {
        remainingTime[i] = burstTime[i];
    }

    while(completedProcesses < numberOfProcesses) {

        highestPriority = INT_MAX;

        for(i = 0; i < numberOfProcesses; i++) {
            if(remainingTime[i] > 0 && priority[i] < highestPriority) {
                highestPriority = priority[i];
                selectedProcess = i;
            }
        }

        remainingTime[selectedProcess]--;
        currentTime++;

        if(remainingTime[selectedProcess] == 0) {
            completedProcesses++;
            turnAroundTime[selectedProcess] = currentTime;
            waitingTime[selectedProcess] =
                turnAroundTime[selectedProcess] - burstTime[selectedProcess];
        }
    }

    for(i = 0; i < numberOfProcesses; i++) {
        printf("Process %d  BT=%d  WT=%d  TAT=%d\n",
               i+1, burstTime[i], waitingTime[i], turnAroundTime[i]);
    }

    return 0;
}

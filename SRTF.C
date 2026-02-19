#include <stdio.h>
#include <limits.h>

int main() {

    int numberOfProcesses = 3;
    int burstTime[3] = {6, 2, 8};
    int remainingTime[3];
    int waitingTime[3] = {0};
    int turnAroundTime[3];
    int completedProcesses = 0;
    int currentTime = 0;
    int i, smallestTime, selectedProcess;

    for(i = 0; i < numberOfProcesses; i++) {
        remainingTime[i] = burstTime[i];
    }

    while(completedProcesses < numberOfProcesses) {

        smallestTime = INT_MAX;

        for(i = 0; i < numberOfProcesses; i++) {
            if(remainingTime[i] > 0 && remainingTime[i] < smallestTime) {
                smallestTime = remainingTime[i];
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
        printf("Process %d  Burst Time=%d  Waiting Time=%d  TurnAround Time=%d\n",
               i + 1, burstTime[i], waitingTime[i], turnAroundTime[i]);
    }

    return 0;
}

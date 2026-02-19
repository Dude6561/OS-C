#include <stdio.h>

int main() {

    int numberOfProcesses = 3;
    int burstTime[3] = {5, 4, 2};
    int remainingTime[3];
    int waitingTime[3] = {0};
    int turnAroundTime[3];
    int timeQuantum = 2;
    int currentTime = 0;
    int processFinished;
    int i;

    for(i = 0; i < numberOfProcesses; i++) {
        remainingTime[i] = burstTime[i];
    }

    do {

        processFinished = 1;

        for(i = 0; i < numberOfProcesses; i++) {

            if(remainingTime[i] > 0) {

                processFinished = 0;

                if(remainingTime[i] > timeQuantum) {
                    currentTime += timeQuantum;
                    remainingTime[i] -= timeQuantum;
                }
                else {
                    currentTime += remainingTime[i];
                    waitingTime[i] = currentTime - burstTime[i];
                    remainingTime[i] = 0;
                }
            }
        }

    } while(processFinished == 0);

    for(i = 0; i < numberOfProcesses; i++) {
        turnAroundTime[i] = burstTime[i] + waitingTime[i];
    }

    for(i = 0; i < numberOfProcesses; i++) {
        printf("Process %d  Burst Time=%d  Waiting Time=%d  TurnAround Time=%d\n",
               i + 1, burstTime[i], waitingTime[i], turnAroundTime[i]);
    }

    return 0;
}

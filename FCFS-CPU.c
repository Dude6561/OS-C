#include <stdio.h>
int main(){
    int i, n=3;
    int brustTime[3]={5,3,8};
    int waitTime[3];
    int turnaroundTime[3];
    int avgWait;
    int avgTurn;

    waitTime[0]=0;
    
    //calcllation of wait time
    for ( i=1; i<n; i++) {
        waitTime[i] = waitTime[i-1] + brustTime[i-1];
    }

    // calculation of turnaround time 
    for(i=0; i<n; i++){
        turnaroundTime[i]= waitTime[i]+brustTime[i];
    }

  printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

for(i = 0; i < n; i++) {
    printf("P%d\t%d\t\t%d\t\t%d\n",
           i + 1,
           brustTime[i],
           waitTime[i],
           turnaroundTime[i]);
}

printf("\nAverage Waiting Time = %d \n",avgWait / n);
printf("\nAverage Turnaround Time = %d\n",avgTurn / n);

    return 0;
}
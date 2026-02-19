#include <stdio.h>

int main() {

    int numberOfProcesses = 3;
    int numberOfResources = 3;

    int allocation[3][3] = {
        {0,1,0},
        {2,0,0},
        {3,0,3}
    };

    int request[3][3] = {
        {0,0,0},
        {2,0,2},
        {0,0,0}
    };

    int available[3] = {0,0,0};
    int finish[3] = {0};
    int i,j;

    int deadlock = 0;

    for(i=0;i<numberOfProcesses;i++) {

        int canExecute = 1;

        for(j=0;j<numberOfResources;j++)
            if(request[i][j] > available[j])
                canExecute = 0;

        if(!canExecute) deadlock = 1;
    }

    if(deadlock)
        printf("Deadlock Detected\n");
    else
        printf("No Deadlock\n");

    return 0;
}

#include <stdio.h>

int main() {
    int numberOfProcesses = 3;
    int numberOfResources = 3;

    int allocation[3][3] = {{0,1,0}, {2,0,0}, {3,0,2}};
    int maximum[3][3] = {{7,5,3}, {3,2,2}, {9,0,2}};
    int available[3] = {3,3,2};
    
    int need[3][3];
    int finish[3] = {0};
    int safeSequence[3];
    int i, j, k = 0;

    // Calculate Need Matrix
    for(i=0; i<numberOfProcesses; i++)
        for(j=0; j<numberOfResources; j++)
            need[i][j] = maximum[i][j] - allocation[i][j];

    int count = 0;
    while(count < numberOfProcesses) {
        int foundAtLeastOne = 0;

        for(i=0; i<numberOfProcesses; i++) {
            if(finish[i] == 0) {
                int canExecute = 1;
                for(j=0; j<numberOfResources; j++) {
                    if(need[i][j] > available[j]) {
                        canExecute = 0;
                        break;
                    }
                }

                if(canExecute) {
                    for(j=0; j<numberOfResources; j++)
                        available[j] += allocation[i][j];

                    safeSequence[k++] = i;
                    finish[i] = 1;
                    count++;
                    foundAtLeastOne = 1; 
                }
            }
        }

        if(foundAtLeastOne == 0) {
            break;
        }
    }

    if(count == numberOfProcesses) {
        printf("System is Safe\nSafe Sequence: ");
        for(i=0; i < numberOfProcesses; i++) 
            printf("P%d ", safeSequence[i]);
        printf("\n");
    } else {
        printf("System is Unsafe (Deadlock detected)\n");
    }

    return 0;
}
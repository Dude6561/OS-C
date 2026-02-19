#include <stdio.h>
#include <stdlib.h>

int main() {

    int requests[5] = {98,183,37,122,14};
    int visited[5] = {0};
    int head = 53;
    int totalMovement = 0;
    int i, j, minDistance, index;

    for(i = 0; i < 5; i++) {

        minDistance = 9999;

        for(j = 0; j < 5; j++) {
            if(!visited[j] && abs(head - requests[j]) < minDistance) {
                minDistance = abs(head - requests[j]);
                index = j;
            }
        }

        totalMovement += minDistance;
        head = requests[index];
        visited[index] = 1;
    }

    printf("Total Head Movement = %d\n", totalMovement);

    return 0;
}

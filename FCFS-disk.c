#include <stdio.h>
#include <stdlib.h> 

int main() {
    int requests[5] = {98, 183, 37, 122, 14};
    int head = 53;
    int totalMovement = 0;
    int i;

    for(i = 0; i < 5; i++) {
        totalMovement += abs(head - requests[i]);
        head = requests[i];
    }

    printf("Total Head Movement = %d\n", totalMovement);

    return 0;
}
#include <stdio.h>

int main() {

    int referenceString[8] = {1,2,3,4,1,2,5,1};
    int frame[3] = {-1,-1,-1};
    int frameSize = 3;
    int pageFaults = 0;
    int i, j, pointer = 0, found;

    for(i = 0; i < 8; i++) {

        found = 0;

        for(j = 0; j < frameSize; j++) {
            if(frame[j] == referenceString[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            frame[pointer] = referenceString[i];
            pointer = (pointer + 1) % frameSize;
            pageFaults++;
        }
    }

    printf("Total Page Faults = %d\n", pageFaults);

    return 0;
}

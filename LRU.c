#include <stdio.h>

int main() {

    int referenceString[8] = {1,2,3,4,1,2,5,1};
    int frame[3] = {-1,-1,-1};
    int recent[3] = {0,0,0};
    int frameSize = 3;
    int pageFaults = 0;
    int i,j,least,replaceIndex,found;

    for(i = 0; i < 8; i++) {

        found = 0;

        for(j = 0; j < frameSize; j++) {
            if(frame[j] == referenceString[i]) {
                recent[j] = i;
                found = 1;
            }
        }

        if(!found) {

            least = recent[0];
            replaceIndex = 0;

            for(j = 1; j < frameSize; j++) {
                if(recent[j] < least) {
                    least = recent[j];
                    replaceIndex = j;
                }
            }

            frame[replaceIndex] = referenceString[i];
            recent[replaceIndex] = i;
            pageFaults++;
        }
    }

    printf("Total Page Faults = %d\n", pageFaults);

    return 0;
}

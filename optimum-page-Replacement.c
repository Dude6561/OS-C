#include <stdio.h>

int main() {

    int referenceString[8] = {1,2,3,4,1,2,5,1};
    int frame[3] = {-1,-1,-1};
    int frameSize = 3;
    int pageFaults = 0;
    int i,j,k,replaceIndex,far,found;

    for(i = 0; i < 8; i++) {

        found = 0;

        for(j = 0; j < frameSize; j++)
            if(frame[j] == referenceString[i])
                found = 1;

        if(!found) {

            far = -1;
            replaceIndex = -1;

            for(j = 0; j < frameSize; j++) {
                int nextUse = -1;

                for(k = i+1; k < 8; k++)
                    if(frame[j] == referenceString[k]) {
                        nextUse = k;
                        break;
                    }

                if(nextUse == -1) {
                    replaceIndex = j;
                    break;
                }

                if(nextUse > far) {
                    far = nextUse;
                    replaceIndex = j;
                }
            }

            frame[replaceIndex] = referenceString[i];
            pageFaults++;
        }
    }

    printf("Total Page Faults = %d\n", pageFaults);

    return 0;
}

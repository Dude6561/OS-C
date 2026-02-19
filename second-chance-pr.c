#include <stdio.h>

void secondChance() {
    int frames, n, pageFaults = 0, pointer = 0;
    
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n], frameArr[frames], refBit[frames];
    for(int i = 0; i < frames; i++) {
        frameArr[i] = -1; 
        refBit[i] = 0;    
    }

    printf("Enter page reference string: ");
    for(int i = 0; i < n; i++) scanf("%d", &pages[i]);

    printf("\nString | Frames\n");
    for(int i = 0; i < n; i++) {
        int hit = 0;
        for(int j = 0; j < frames; j++) {
            if(frameArr[j] == pages[i]) {
                hit = 1;
                refBit[j] = 1; 
                break;
            }
        }

        if(!hit) {
            
            while(refBit[pointer] == 1) {
                refBit[pointer] = 0; 
                pointer = (pointer + 1) % frames;
            }
            frameArr[pointer] = pages[i];
            refBit[pointer] = 0;
            pointer = (pointer + 1) % frames;
            pageFaults++;
        }

        printf("%d      | ", pages[i]);
        for(int j = 0; j < frames; j++) printf("%d ", frameArr[j]);
        printf(hit ? "(Hit)\n" : "(Miss)\n");
    }
    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    secondChance();
    return 0;
}
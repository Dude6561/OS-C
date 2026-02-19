#include <stdio.h>

int main() {
    int req[] = {98, 183, 37, 122, 14};
    int n = 5, head = 53, disk_size = 200;
    int sorted[10], temp, move = 0;

    // 1. Add head and boundaries to the array
    for(int i = 0; i < n; i++) sorted[i] = req[i];
    sorted[n] = head;
    sorted[n+1] = 0;
    sorted[n+2] = disk_size - 1;
    int total = n + 3;

    // 2. Sort the array
    for(int i = 0; i < total; i++) {
        for(int j = i + 1; j < total; j++) {
            if(sorted[i] > sorted[j]) {
                temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }

    // 3. Find head index
    int index;
    for(int i = 0; i < total; i++) if(sorted[i] == head) index = i;

    printf("C-SCAN Sequence: ");
    // Move Right to boundary
    for(int i = index; i < total; i++) {
        printf("%d -> ", sorted[i]);
        if(i != total - 1) move += (sorted[i+1] - sorted[i]);
    }
    // Jump to 0 (distance added)
    move += (sorted[total-1] - sorted[0]);
    
    // Move Right again from 0 to just before initial head
    for(int i = 0; i < index; i++) {
        printf("%d -> ", sorted[i]);
        if(i != index - 1) move += (sorted[i+1] - sorted[i]);
    }

    printf("End\nTotal Head Movement: %d\n", move);
    return 0;
}
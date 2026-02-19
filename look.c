#include <stdio.h>

int main() {
    int req[] = {98, 183, 37, 122, 14};
    int n = 5, head = 53, temp, move = 0;
    int sorted[6];

    for(int i = 0; i < n; i++) sorted[i] = req[i];
    sorted[n] = head;

    for(int i = 0; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(sorted[i] > sorted[j]) {
                temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }

    int index;
    for(int i = 0; i <= n; i++) if(sorted[i] == head) index = i;

    printf("LOOK Sequence: ");
    for(int i = index; i < n; i++) {
        printf("%d ", sorted[i]);
        move += (sorted[i+1] - sorted[i]);
    }
    printf("%d ", sorted[n]);

    move += (sorted[n] - sorted[index-1]);
    for(int i = index - 1; i >= 0; i--) {
        printf("%d ", sorted[i]);
        if(i != 0) move += (sorted[i] - sorted[i-1]);
    }

    printf("\nTotal Head Movement: %d\n", move);
    return 0;
}
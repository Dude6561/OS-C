#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int main() {
    int req[] = {98, 183, 37, 122, 14}, n = 5;
    int head = 53, size = 200, move = 0;
    int sorted[7]; // n + head + boundary

    for(int i=0; i<n; i++) sorted[i] = req[i];
    sorted[n] = head;
    sorted[n+1] = size - 1; // Assuming moving towards high end
    sort(sorted, n + 2);

    int index;
    for(int i=0; i < n+2; i++) if(sorted[i] == head) index = i;

    // Move Right to the end, then Left
    for(int i = index; i < n+1; i++) move += abs(sorted[i+1] - sorted[i]);
    move += abs(sorted[n+1] - sorted[index-1]);
    for(int i = index - 1; i > 0; i--) move += abs(sorted[i] - sorted[i-1]);

    printf("SCAN Total Movement: %d\n", move);
    return 0;
}
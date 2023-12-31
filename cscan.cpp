#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100
#define MAX_CYLINDERS 200

void calculateSeekTime(int requests[], int numRequests, int initialHeadPosition) {
    int totalSeekTime = 0;
    int currentHeadPosition = initialHeadPosition;
    int direction = 1;
    int i,j;
    for (i = 0; i < numRequests - 1; i++) {
        for (j = 0; j < numRequests - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }
    printf("Seek Sequence: %d", currentHeadPosition);

    while (1) {
        int servicedRequests = 0;

        for (i = 0; i < numRequests; i++) {
            if ((direction == 1 && requests[i] >= currentHeadPosition) ||
                (direction == -1 && requests[i] < currentHeadPosition)) {
                totalSeekTime += abs(currentHeadPosition - requests[i]);
                currentHeadPosition = requests[i];
                printf(" -> %d", currentHeadPosition);
                servicedRequests++;
            }
        }

        if (servicedRequests == 0) {
            if (direction == 1) {
                totalSeekTime += abs(currentHeadPosition - MAX_CYLINDERS);
                currentHeadPosition = MAX_CYLINDERS;
            } else {
                totalSeekTime += currentHeadPosition;
                currentHeadPosition = 0;
            }
            printf(" -> %d", currentHeadPosition);
        }
        if (servicedRequests == numRequests) {
            break;
        }
    }

    printf("\nTotal Seek Time: %d\n", totalSeekTime);
}

int main() {
    int numRequests, initialHeadPosition;
    int requests[MAX_REQUESTS];
    int i;
    printf("Enter the number of disk I/O requests: ");
    scanf("%d", &numRequests);
    printf("Enter the initial head position: ");
    scanf("%d", &initialHeadPosition);
    printf("Enter the disk I/O requests:\n");
    for (i = 0; i < numRequests; i++) {
        printf("Request %d: ", i + 1);
        scanf("%d", &requests[i]);
    }
    calculateSeekTime(requests, numRequests, initialHeadPosition);

    return 0;
}

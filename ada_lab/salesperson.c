#include <stdio.h>
#include <limits.h>

#define N 4

int dist[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int calculateDistance(int path[], int n) {
    int totalDistance = 0;
    for (int i = 0; i < n-1; i++) {
        totalDistance += dist[path[i]][path[i+1]];
    }
    totalDistance += dist[path[n-1]][path[0]];  // Return to start city
    return totalDistance;
}

void permute(int path[], int start, int n, int *minDistance, int *bestPath) {
    if (start == n) {
        int currentDistance = calculateDistance(path, n);
        if (currentDistance < *minDistance) {
            *minDistance = currentDistance;
            for (int i = 0; i < n; i++) {
                bestPath[i] = path[i];
            }
        }
    } else {
        for (int i = start; i < n; i++) {
            // Swap
            int temp = path[start];
            path[start] = path[i];
            path[i] = temp;

            permute(path, start + 1, n, minDistance, bestPath);

            // Swap back
            temp = path[start];
            path[start] = path[i];
            path[i] = temp;
        }
    }
}

int main() {
    int path[] = {0, 1, 2, 3};
    int minDistance = INT_MAX;
    int bestPath[N];

    permute(path, 0, N, &minDistance, bestPath);

    printf("Minimum distance: %d\n", minDistance);
    printf("Optimal path: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", bestPath[i]);
    }
    printf("\n");

    return 0;
}


#include <stdio.h>
#include <limits.h>

int cost[4][4] = {
    {9, 2, 7, 8},
    {6, 4, 3, 7},
    {5, 8, 1, 8},
    {7, 6, 9, 4}
};

int calculateCost(int assignment[], int n) {
    int totalCost = 0;
    for (int i = 0; i < n; i++) {
        totalCost += cost[i][assignment[i]];
    }
    return totalCost;
}

void permute(int assignment[], int start, int n, int *minCost, int *bestAssignment) {
    if (start == n) {
        int currentCost = calculateCost(assignment, n);
        if (currentCost < *minCost) {
            *minCost = currentCost;
            for (int i = 0; i < n; i++) {
                bestAssignment[i] = assignment[i];
            }
        }
    } else {
        for (int i = start; i < n; i++) {
            // Swap
            int temp = assignment[start];
            assignment[start] = assignment[i];
            assignment[i] = temp;

            permute(assignment, start + 1, n, minCost, bestAssignment);

            // Swap back
            temp = assignment[start];
            assignment[start] = assignment[i];
            assignment[i] = temp;
        }
    }
}

int main() {
    int n = 4; // Number of workers
    int assignment[] = {0, 1, 2, 3};
    int minCost = INT_MAX;
    int bestAssignment[4];

    permute(assignment, 0, n, &minCost, bestAssignment);

    printf("Minimum cost: %d\n", minCost);
    printf("Optimal assignment: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", bestAssignment[i]);
    }
    printf("\n");

    return 0;
}

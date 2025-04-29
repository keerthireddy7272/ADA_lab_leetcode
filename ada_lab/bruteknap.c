#include <stdio.h>

int knapsack(int values[10], int weights[10], int n, int W) {
    int maxi = 0;

    for (int i = 0; i < (1 << n); i++) {
        int totalw = 0, totalValue = 0;

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                totalw += weights[j];
                totalValue += values[j];
            }
        }

        if (totalw <= W && totalValue > maxi) {
            maxi = totalValue;
        }
    }

    return maxi;
}

int main() {
    int values[10], weights[10];
    int n, W;
    printf("Enter the number of items (max 10): ");
    scanf("%d", &n);

    printf("Enter the profit of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Value[%d]: ", i);
        scanf("%d", &values[i]);
    }
    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Weight[%d]: ", i);
        scanf("%d", &weights[i]);
    }

    printf("Enter the maximum weight capacity of the knapsack: ");
    scanf("%d", &W);

    int maxValue = knapsack(values, weights, n, W);
    printf("Maximum profit in Knapsack = %d\n", maxValue);

    return 0;
}

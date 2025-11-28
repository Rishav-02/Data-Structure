#include <stdio.h>

// Function for max of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// 0/1 Knapsack DP function
int knapsack(int capacity, int weight[], int profit[], int n) {

    //Create dp table
    int dp[n + 1][capacity + 1];

    // Build table dp[][] in bottom-up manner and i and w are indices for items and weights respectively
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {

            // Base case: no item or capacity = 0
            if (i == 0 || w == 0)
                dp[i][w] = 0;// Initialize first row and column to 0

            // Item can be taken
            else if (weight[i - 1] <= w)
                dp[i][w] = max(profit[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);

            // Item cannot be taken
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][capacity];
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n], profit[n];

    printf("Enter weight and profit of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weight[i], &profit[i]);
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    int maxProfit = knapsack(capacity, weight, profit, n);
    printf("\nMaximum Profit = %d\n", maxProfit);

    return 0;
}
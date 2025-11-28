#include <stdio.h>

#define INF 9999
#define MAX 20

int main()
{
    int cost[MAX][MAX];
    int visited[MAX];
    int n, edges = 0;
    int minCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (enter 0 if no edge):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = INF; // Replace 0 (no edge) with large value
        }
    }
    // Mark all vertices as unvisited
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    visited[0] = 1; // Start from vertex 0
    printf("\nEdges in the Minimum Spanning Tree:\n");
    while (edges < n - 1)
    {
        int min = INF, u = -1, v = -1;

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        printf("%d -- %d  (Weight = %d)\n", u, v, min);
        visited[v] = 1;
        minCost += min;
        edges++;
    }

    printf("\nTotal Weight of MST = %d\n", minCost);

    return 0;
}
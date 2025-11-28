#include <stdio.h>

#define INF 9999

int main()
{
    int V;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int dist[V][V];

    printf("Enter adjacency matrix (use 0 for no edge, %d for INF):\n", INF);
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &dist[i][j]);

    // Floyd–Warshall Algorithm core
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    printf("\nAll-Pairs Shortest Path Matrix:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
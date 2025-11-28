#include <stdio.h>

#define INF 9999

int main()
{
    int V;
    printf("Enter no. of vertices: ");
    scanf("%d", &V);

    int g[V][V];
    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &g[i][j]);

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    int dist[V], visited[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int c = 0; c < V - 1; c++)
    {
        int min = INF, u;
        for (int v = 0; v < V; v++)
            if (!visited[v] && dist[v] < min)
                min = dist[v], u = v;

        visited[u] = 1;

        for (int v = 0; v < V; v++)
            if (!visited[v] && g[u][v] && dist[u] + g[u][v] < dist[v])
                dist[v] = dist[u] + g[u][v];
    }

    printf("\nVertex\tDistance from Source %d\n", src);
    for (int i = 0; i < V; i++)
    {
        printf("%d\t\t%d\n", i, dist[i]);
    }

    return 0;
}
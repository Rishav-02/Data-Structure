//BFS with integer vertices using adjacency matrix
#include <stdio.h>

#define MAX 100

void printPath(int parent[], int node) {
    if (parent[node] == -1) {
        printf("%d ", node);
        return;
    }
    printPath(parent, parent[node]);
    printf("%d ", node);
}

void bfsFindPath(int graph[MAX][MAX], int n, int start, int end) {
    int queue[MAX], front = 0, rear = 0;
    int status[MAX] = {0};  // 0: ready, 1: waiting, 2: processed
    int parent[MAX];

    for (int i = 1; i <= n; i++)
        parent[i] = -1;

    queue[rear++] = start;
    status[start] = 1;

    int found = 0;

    while (front < rear) {
        int current = queue[front++];
        status[current] = 2;

        if (current == end) {
            found = 1;
            break;
        }

        for (int i = 1; i <= n; i++) {
            if (graph[current][i] == 1 && status[i] == 0) 
            {
                queue[rear++] = i;
                status[i] = 1;
                parent[i] = current;
            }
        }
    }

    if (found) {
        printf("Path from %d to %d: ", start, end);
        printPath(parent, end);
        printf("\n");
    } else {
        printf("No path found from %d to %d.\n", start, end);
    }
}

int main() {
    int n, edges;
    int graph[MAX][MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (e.g., 1 2):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // Undirected
    }

    int start, end;
    printf("Enter source vertex: ");
    scanf("%d", &start);
    printf("Enter destination vertex: ");
    scanf("%d", &end);

    bfsFindPath(graph, n, start, end);

    return 0;
}
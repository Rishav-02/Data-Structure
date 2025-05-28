//DFS with integer vertices using an adjacency matrix
#include <stdio.h>
#define MAX 100

void push(int stack[], int *top, int value) {
    stack[++(*top)] = value;
}

int pop(int stack[], int *top) {
    return stack[(*top)--];
}

int isEmpty(int top) {
    return top == -1;
}

void DFS(int graph[MAX][MAX], int visited[MAX], int n, int start) {
    int stack[MAX];
    int top = -1;

    push(stack, &top, start);

    while (!isEmpty(top)) {
        int node = pop(stack, &top);

        if (!visited[node]) {
            visited[node] = 1;
            printf("%d ", node);

            for (int i = n - 1; i >= 0; i--) {
                if (graph[node][i] == 1 && !visited[i]) {
                    push(stack, &top, i);
                }
            }
        }
    }
}

int main() {
    int graph[MAX][MAX];
    int visited[MAX] = {0};
    int n, edges;
    int src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1;
        graph[dest][src] = 1; // Undirected
    }

    int start;
    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);

    printf("DFS traversal: ");
    DFS(graph, visited, n, start);

    return 0;
}
//DFS with Character Vertices with Recursion using adjacency matrix
#include <stdio.h>
#define MAX 26  // For vertices A-Z

// Convert char (e.g., 'A') to index (0-25)
int charToIndex(char ch) {
    return ch - 'A';
}

// Convert index back to char (e.g., 0 -> 'A')
char indexToChar(int index) {
    return index + 'A';
}

// Recursive DFS function
void DFS(int graph[MAX][MAX], int visited[MAX], int v, int node) {
    visited[node] = 1;
    printf("%c ", indexToChar(node));

    for (int i = 0; i < v; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            DFS(graph, visited, v, i);
        }
    }
}

int main() {
    int graph[MAX][MAX];
    int visited[MAX] = {0};
    int v, edges;
    char srcChar, destChar;

    printf("Enter number of vertices (max 26): ");
    scanf("%d", &v);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            graph[i][j] = 0;

    printf("Enter edges (like A B):\n");
    for (int i = 0; i < edges; i++) {
        scanf(" %c %c", &srcChar, &destChar);
        int src = charToIndex(srcChar);
        int dest = charToIndex(destChar);
        graph[src][dest] = 1;
        graph[dest][src] = 1; // Undirected graph
    }

    char startChar;
    printf("Enter starting vertex for DFS (like A): ");
    scanf(" %c", &startChar);

    printf("DFS traversal: ");
    DFS(graph, visited, v, charToIndex(startChar));

    return 0;
}
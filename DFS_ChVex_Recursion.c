//DFS with Character Vertices with Recursion using adjacency matrix
#include <stdio.h>
#define MAX 26  // For vertices A-Z

// A -> 65, B -> 66, ..., Z -> 90   ASCII values
// Convert char (e.g., 'A') to index (0-25)
int charToIndex(char ch) {
    return ch - 'A';// 'A' - 'A' = 0 | 'B' - 'A' = 1  | 'Z' - 'A' = 25
}

// Convert index back to char (e.g., 0 -> 'A')
char indexToChar(int index) {
    return index + 'A';// 0 + 'A' = 'A' | 1 + 'A' = 'B' | 25 + 'A' = 'Z'
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
    int visited[MAX] = {0};// Initializes all vertices as unvisited
    int v, edges;
    char srcChar, destChar;
    int isDirected;

    printf("Enter 1 for Directed graph or 0 for Undirceted graph: ");
    scanf("%d", &isDirected);

    printf("Enter number of vertices (max 26): ");
    scanf("%d", &v);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++) {
            graph[i][j] = 0;// Initialize all edges to 0 if there is no path
        }
    }

    printf("Enter edges (like A B):\n");
    for (int i = 0; i < edges; i++) {
        scanf(" %c %c", &srcChar, &destChar);
        int src = charToIndex(srcChar);
        int dest = charToIndex(destChar);
        graph[src][dest] = 1;
        if(!isDirected){
        graph[dest][src] = 1; // Only for Undirected graph
       }
    }
    char startChar;
    printf("Enter starting vertex for DFS (like A): ");
    scanf(" %c", &startChar);

    printf("DFS traversal: ");
    DFS(graph, visited, v, charToIndex(startChar));

    return 0;
}
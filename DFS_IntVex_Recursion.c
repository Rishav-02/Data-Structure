//DFS with Integer Vertices using Recursion in adjacency matrix
#include <stdio.h>
#define MAX 100  

// Recursive DFS function
/* graph: 2D adjacency matrix.
visited: array to keep track of visited vertices.
v: total number of vertices.
node: current node being explored.*/
void DFS(int graph[MAX][MAX], int visited[MAX], int v, int node) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 1; i <= v; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            DFS(graph, visited, v, i);//push
        }
    }
}

int main() {
    int graph[MAX][MAX];// Adjacency matrix to represent the graph
    int visited[MAX] = {0};//initially all vertices are unvisited
    int v, edges;
    int src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &v);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix
    for (int i = 1; i <= v; i++)// i is used to traverse the rows
    {
        for (int j = 1; j <= v; j++)// j is used to traverse the columns
        {
            graph[i][j] = 0;// Initialize all edges to 0 if there is no path
        }
    }
    printf("Enter edges (like 1 2):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1;
        graph[dest][src] = 1; // Only for Undirected graph
    }

    int start;
    printf("Enter starting vertex for DFS (e.g., 1): ");
    scanf("%d", &start);

    printf("DFS traversal: ");
    DFS(graph, visited, v, start);

    return 0;
}
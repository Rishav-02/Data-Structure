//Recursive DFS with Adjacency List
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

/* An array (Node* adjList[MAX]) is used to store the adjacency list for each vertex.
Each element of the array points to a linked list of neighbors (adjacent vertices). */

//Adjacency list is built dynamically using linked lists.
void addEdge(Node* adjList[], int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

//DFSUtil() prints the node, marks visited, then recursively visits neighbors.
void DFSUtil(Node* adjList[], int visited[], int node) {
    visited[node] = 1;
    printf("%d ", node);

    Node* temp = adjList[node];
    while (temp) {
        if (!visited[temp->vertex]) {
            DFSUtil(adjList, visited, temp->vertex);
        }
        temp = temp->next;
    }
}

void DFS(Node* adjList[], int n, int start) {
    int visited[MAX] = {0};
    DFSUtil(adjList, visited, start);
}

int main() {
    Node* adjList[MAX] = {NULL};
    int n, edges, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(adjList, src, dest);
        addEdge(adjList, dest, src);  // Undirected graph
    }

    int start;
    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);

    printf("DFS traversal: ");
    DFS(adjList, n, start);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        Node* temp = adjList[i];
        while (temp) {
            Node* f = temp;
            temp = temp->next;
            free(f);
        }
    }
    return 0;
}
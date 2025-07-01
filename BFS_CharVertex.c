// //BFS with character vertices using adjacency matrix
#include <stdio.h>
#include <string.h>

#define MAX 26  // Max characters from A-Z

int charToIndex(char ch) {
    return ch - 'A';
}

char indexToChar(int idx) {
    return idx + 'A';
}

void printPath(int parent[], int dest) {
    if (parent[dest] == -1) {
        printf("%c ", indexToChar(dest));
        return;
    }
    printPath(parent, parent[dest]);
    printf("%c ", indexToChar(dest));
}

void bfsFindPath(int graph[MAX][MAX], int n, char startChar, char endChar) {
    int queue[MAX], front = 0, rear = 0;
    int status[MAX] = {0};    // 0 = ready, 1 = waiting, 2 = processed
    int parent[MAX];          // To store parent nodes for backtracking

    for (int i = 0; i < MAX; i++)
        parent[i] = -1;

    int start = charToIndex(startChar);
    int end = charToIndex(endChar);

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

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && status[i] == 0) {
                queue[rear++] = i;
                status[i] = 1;
                parent[i] = current;
            }
        }
    }

    if (found) {
        printf("Path from %c to %c: ", startChar, endChar);
        printPath(parent, end);
    } else {
        printf("No path found from %c to %c.\n", startChar, endChar);
    }
}

int main() {
    int n, edges;
    char src, dest;
    int graph[MAX][MAX] = {0};
    int isDirected;

    printf("Enter 1 for Directed graph or 0 for Undirected graph: ");
    scanf("%d", &isDirected);

    printf("Enter number of vertices (max 26): ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (e.g., A B):\n");
    for (int i = 0; i < edges; i++) {
        scanf(" %c %c", &src, &dest);
        int u = charToIndex(src);
        int v = charToIndex(dest);
        graph[u][v] = 1; // Directed edge
        if(!isDirected){
            graph[v][u] = 1; // Undirected
        }
    }

    char startChar, endChar;
    printf("Enter source vertex (e.g., A): ");
    scanf(" %c", &startChar);
    printf("Enter destination vertex (e.g., D): ");
    scanf(" %c", &endChar);

    bfsFindPath(graph, n, startChar, endChar);

    return 0;
}
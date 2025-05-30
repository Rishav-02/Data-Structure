//DFS with Character Vertices in adjacency matrix
#include <stdio.h>
#define MAX 26  // For vertices A-Z

// Convert char (e.g. 'A') to index (0-25)
int charToIndex(char ch) {
    return ch - 'A';
}

// Convert index (0-25) back to char (e.g. 'A')
char indexToChar(int index) {
    return index + 'A';
}

void push(int stack[], int *top, int value) {
    (*top)++;
    stack[*top] = value;
}

int pop(int stack[], int *top) {
    return stack[(*top)--]; // decrements top and returns the value at that index
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
            printf("%c ", indexToChar(node));

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
    char srcChar, destChar;

    printf("Enter number of vertices (max 26): ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter edges (like A B):\n");
    for (int i = 0; i < edges; i++) {
        scanf(" %c %c", &srcChar, &destChar);
        int src = charToIndex(srcChar);
        int dest = charToIndex(destChar);
        graph[src][dest] = 1;
        graph[dest][src] = 1; // Undirected
    }

    char startChar;
    printf("Enter starting vertex for DFS (like A): ");
    scanf(" %c", &startChar);

    printf("DFS traversal: ");
    DFS(graph, visited, n, charToIndex(startChar));

    return 0;
}
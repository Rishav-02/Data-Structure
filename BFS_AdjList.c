// BFS with character vertices using adjacency list
#include <stdio.h>
#include <stdlib.h>

#define MAX 26  // Max characters A-Z

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} AdjList;

typedef struct {
    AdjList array[MAX];
} Graph;

int charToIndex(char ch) {
    return ch - 'A';
}

char indexToChar(int idx) {
    return idx + 'A';
}

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Graph* graph, int src, int dest) {
    // Add edge src -> dest
    Node* node = createNode(dest);
    node->next = graph->array[src].head;
    graph->array[src].head = node;

    // Since undirected, add edge dest -> src
    node = createNode(src);
    node->next = graph->array[dest].head;
    graph->array[dest].head = node;
}

void printPath(int parent[], int dest) {
    if (parent[dest] == -1) {
        printf("%c ", indexToChar(dest));
        return;
    }
    printPath(parent, parent[dest]);
    printf("%c ", indexToChar(dest));
}

void bfsFindPath(Graph* graph, int n, char startChar, char endChar) {
    int queue[MAX], front = 0, rear = 0;
    int status[MAX] = {0};    // 0=ready,1=waiting,2=processed
    int parent[MAX];
    for (int i = 0; i < MAX; i++) parent[i] = -1;

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

        Node* temp = graph->array[current].head;
        while (temp != NULL) {
            int adj = temp->vertex;
            if (status[adj] == 0) {
                queue[rear++] = adj;
                status[adj] = 1;
                parent[adj] = current;
            }
            temp = temp->next;
        }
    }

    if (found) {
        printf("Path from %c to %c: ", startChar, endChar);
        printPath(parent, end);
        printf("\n");
    } else {
        printf("No path found from %c to %c.\n", startChar, endChar);
    }
}

int main() {
    int n, edges;
    char src, dest;
    Graph graph;

    // Initialize graph adjacency lists
    for (int i = 0; i < MAX; i++) {
        graph.array[i].head = NULL;
    }

    printf("Enter number of vertices (max 26): ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (e.g., A B):\n");
    for (int i = 0; i < edges; i++) {
        scanf(" %c %c", &src, &dest);
        addEdge(&graph, charToIndex(src), charToIndex(dest));
    }

    char startChar, endChar;
    printf("Enter source vertex (e.g., A): ");
    scanf(" %c", &startChar);
    printf("Enter destination vertex (e.g., D): ");
    scanf(" %c", &endChar);

    bfsFindPath(&graph, n, startChar, endChar);

    return 0;
}

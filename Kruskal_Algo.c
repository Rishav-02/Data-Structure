#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Edge {
    char src, dest;
    int weight;
};

struct Subset {
    int parent;
    int rank;
};

// Helper to get index of vertex character
int getIndex(char vertex, char vertices[], int V) {
    for (int i = 0; i < V; i++) {
        if (vertices[i] == vertex)
            return i;
    }
    return -1; // Not found
}

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compareEdges(const void* a, const void* b) {
    struct Edge* e1 = (struct Edge*)a;
    struct Edge* e2 = (struct Edge*)b;
    return e1->weight - e2->weight;
}

void Kruskal(struct Edge edges[], int E, char vertices[], int V) {
    struct Edge result[V];
    int e = 0, i = 0;

    qsort(edges, E, sizeof(edges[0]), compareEdges);

    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < E) {
        struct Edge next = edges[i++];

        int x = find(subsets, getIndex(next.src, vertices, V));
        int y = find(subsets, getIndex(next.dest, vertices, V));

        if (x != y) {
            result[e++] = next;
            Union(subsets, x, y);
        }
    }

    printf("\nEdges in the Minimum Spanning Tree:\n");
    int minCost = 0;
    for (i = 0; i < e; ++i) {
        printf("%c -- %c == %d\n", result[i].src, result[i].dest, result[i].weight);
        minCost += result[i].weight;
    }
    printf("Total weight of MST = %d\n", minCost);

    free(subsets);
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    char vertices[MAX];
    printf("Enter vertex names (e.g., A B C ...): ");
    for (int i = 0; i < V; i++)
        scanf(" %c", &vertices[i]);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge edges[MAX];
    printf("Enter edges in format: src dest weight (e.g., A B 10)\n");
    for (int i = 0; i < E; i++) {
        scanf(" %c %c %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    Kruskal(edges, E, vertices, V);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v, w;
} Edge;

int parent[MAX];

// Find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Union of two sets
void unionSet(int x, int y) {
    parent[find(x)] = find(y);
}

// Recursive Kruskal's algorithm
int kruskalRecursive(Edge edges[], int n, int e, int index, int count) {
    if (count == n - 1 || index == e)
        return 0;

    int u = edges[index].u;
    int v = edges[index].v;
    int w = edges[index].w;

    if (find(u) != find(v)) {
        printf("Edge %d - %d with weight %d\n", u, v, w);
        unionSet(u, v);
        return w + kruskalRecursive(edges, n, e, index + 1, count + 1);
    } else {
        return kruskalRecursive(edges, n, e, index + 1, count);
    }
}

// Compare function for sorting edges by weight
int cmp(const void *a, const void *b) {
    return ((Edge *)a)->w - ((Edge *)b)->w;
}

int main() {
    int n, e;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    Edge edges[MAX];

    printf("Enter edges in the format: u v w\n");
    for (int i = 0; i < e; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    // Initialize disjoint sets
    for (int i = 0; i < n; i++)
        parent[i] = i;

    // Sort edges by weight
    qsort(edges, e, sizeof(Edge), cmp);//qsort is used to sort the edges based on their weights

    // Run Kruskal’s algorithm
    printf("\nEdges in the Minimum Spanning Tree:\n");
    int totalWeight = kruskalRecursive(edges, n, e, 0, 0);

    printf("\nTotal Weight of MST = %d\n", totalWeight);

    return 0;
}
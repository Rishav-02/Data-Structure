#include <stdio.h>
#include <stdlib.h>

// Structure to store edges
struct Edge {
    int u, v, w;
};

// Structure to represent a subset for Union-Find
struct Subset {
    int parent;
    int rank;
};

// Compare function for sorting edges by weight
int compare(const void *a, const void *b) {
    struct Edge *e1 = (struct Edge *)a;
    struct Edge *e2 = (struct Edge *)b;
    return e1->w - e2->w;
}

// Find operation of Union-Find (with path compression)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union operation of Union-Find (by rank)
void Union(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank) {
        subsets[rootX].parent = rootY;
    }
    else if (subsets[rootX].rank > subsets[rootY].rank) {
        subsets[rootY].parent = rootX;
    }
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge edges[E];

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    // Sort edges by weight
    qsort(edges, E, sizeof(struct Edge), compare);

    // Create subsets for Union-Find
    struct Subset subsets[V];
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    printf("\nEdges in the Minimum Spanning Tree:\n");

    int mst_weight = 0;
    int edges_used = 0;

    for (int i = 0; i < E && edges_used < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        int setU = find(subsets, u);
        int setV = find(subsets, v);

        // If including edge doesn't form a cycle
        if (setU != setV) {
            printf("%d -- %d == %d\n", u, v, edges[i].w);
            mst_weight += edges[i].w;
            edges_used++;
            Union(subsets, setU, setV);
        }
    }

    printf("\nTotal weight of MST = %d\n", mst_weight);

    return 0;
}
//Represent the weighted edges of a graph using a Min Heap

#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

// Min Heap to store edges based on weight
typedef struct {
    Edge *edges;
    int size;
    int capacity;
} MinHeap;

// Swap two edges
void swap(Edge *a, Edge *b) {
    Edge temp = *a;
    *a = *b;
    *b = temp;
}

// Create a Min Heap with given capacity
MinHeap* create_min_heap(int capacity) {
    MinHeap *heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->edges = (Edge*)malloc(sizeof(Edge) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

// Heapify up
void heapify_up(MinHeap *heap, int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && heap->edges[index].weight < heap->edges[parent].weight) {
        swap(&heap->edges[index], &heap->edges[parent]);
        heapify_up(heap, parent);
    }
}

// Heapify down
void heapify_down(MinHeap *heap, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < heap->size && heap->edges[left].weight < heap->edges[smallest].weight)
        smallest = left;
    if (right < heap->size && heap->edges[right].weight < heap->edges[smallest].weight)
        smallest = right;

    if (smallest != index) {
        swap(&heap->edges[index], &heap->edges[smallest]);
        heapify_down(heap, smallest);
    }
}

// Insert edge into heap
void insert_edge(MinHeap *heap, int src, int dest, int weight) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->edges = realloc(heap->edges, heap->capacity * sizeof(Edge));
    }
    heap->edges[heap->size] = (Edge){src, dest, weight};
    heapify_up(heap, heap->size);
    heap->size++;
}

// Extract edge with minimum weight
Edge extract_min(MinHeap *heap) {
    if (heap->size == 0) {
        printf("Heap is empty!\n");
        return (Edge){-1, -1, -1};
    }
    Edge minEdge = heap->edges[0];
    heap->edges[0] = heap->edges[--heap->size];
    heapify_down(heap, 0);
    return minEdge;
}

// Display heap
void print_heap(MinHeap *heap) {
    printf("Min Heap (Edges by weight):\n");
    for (int i = 0; i < heap->size; i++) {
        printf("(%d -> %d : %d)\n", heap->edges[i].src, heap->edges[i].dest, heap->edges[i].weight);
    }
}

// Free memory
void free_heap(MinHeap *heap) {
    free(heap->edges);
    free(heap);
}

int main() {
    int n;
    printf("Enter number of edges: ");
    scanf("%d", &n);

    MinHeap *heap = create_min_heap(n);

    printf("Enter edges in format: src dest weight\n");
    for (int i = 0; i < n; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        insert_edge(heap, src, dest, weight);
    }

    printf("\nGraph edges stored in Min Heap (by weight):\n");
    print_heap(heap);

    printf("\nExtracting edges in increasing weight:\n");
    while (heap->size > 0) {
        Edge minEdge = extract_min(heap);
        printf("Edge: %d -> %d (Weight: %d)\n", minEdge.src, minEdge.dest, minEdge.weight);
    }

    free_heap(heap);
    return 0;
}
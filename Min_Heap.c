// This program implements a min heap using a dynamic array in C
#include<stdio.h>
#include<stdlib.h>

struct heap{
    int *data;//Pointer to the actual data
    int capacity;//Allocated capacity
    int size;//Number of elements in the heap
}typedef heap;

// Create a new heap with initial capacity
heap* create_heap(int capacity)
{
    heap *temp = (heap*)malloc(sizeof(heap));
    temp->capacity = capacity;
    temp->size = 0;
    temp->data = (int*)malloc(sizeof(int) * capacity);
    return temp;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_up(heap *h, int i)//i is index of the heap
{
    int parent = (i - 1) / 2;
    if(i && h->data[parent] > h->data[i])
    {
        swap(&h->data[i], &h->data[parent]);
        heapify_up(h, parent);
    }
}

// Heapify down (after extract)
void heapify_down(heap *h, int i)//i is index of the heap
{
    int c1 = 2 * i + 1; // left child
    int c2 = 2 * i + 2; // right child
    int minimum = i;

    if(c1 < h->size && h->data[c1] < h->data[minimum])
        minimum = c1;
    if(c2 < h->size && h->data[c2] < h->data[minimum])
        minimum = c2;

    if(minimum != i)
    {
        swap(&h->data[i], &h->data[minimum]);
        heapify_down(h, minimum);
    }
}

// Insert a new element into the heap
void insert(heap *h, int value)
{
    if(h->size == h->capacity)
    {
        printf("Heap is full\n");
        return;
    }
    h->data[h->size] = value;
    h->size++;
    heapify_up(h, h->size - 1);
}

// Extract the minimum element from the heap
//Removes the root element (max or min), restructures heap.
int extract_min(heap *h)
{
    if(h->size == 0)
    {
        printf("Heap is empty\n");
        return -1;
    }
    int min = h->data[0];
    h->data[0] = h->data[h->size - 1];
    h->size--;
    heapify_down(h, 0);
    return min;
}

//Display the heap
void display(heap *h)
{
    for(int i = 0; i < h->size; i++)
    {
        printf("%d ", h->data[i]);
    }
    printf("\n");
}

// Free heap memory
void free_heap(heap *h) {
    free(h->data);
    free(h);
}

int main()
{
    int capacity;
    printf("Enter the capacity of the heap: ");
    scanf("%d", &capacity);
    heap *h = create_heap(capacity);

    int choice, value;
    do
    {
        printf("1. Insert\n2. Extract Min\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(h, value);
                break;
            case 2:
                value = extract_min(h);
                if(value != -1)
                    printf("\nExtracted min: %d\n", value);
                break;
            case 3:
                display(h);
                break;
            case 4:
                free(h->data);
                free(h);
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 4);

    return 0;
}
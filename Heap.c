// This program uses a static array to implement a min heap in C
#include<stdio.h>

//Max. Heap
// void heapify(int *arr, int i, int n)
// {
//     int largest = i;
//     int left = 2 * i + 1;
//     int right = 2 * i + 2;

//     if(left < n && arr[left] > arr[largest])
//         largest = left;

//     if(right < n && arr[right] > arr[largest])
//         largest = right;

//     if(largest != i)
//     {
//         swap(&arr[i], &arr[largest]);
//         heapify(arr, largest, n);
//     }
// }

//swap function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


//Min. Heap
void heapify(int *arr, int i, int n)
{
    int c1 = 2 * i + 1; // left child
    int c2 = 2 * i + 2; // right child
    int minimum = i;

    if(c1 < n && arr[c1] < arr[minimum])
        minimum = c1;
    if(c2 < n && arr[c2] < arr[minimum])
        minimum = c2;

        if(minimum != i)
        {
            swap(&arr[i], &arr[minimum]);
            heapify(arr, minimum, n);
        }
}

//It is used to create a heap from an array
void build_heap(int *arr, int n)
{
    for(int i = n /2; i >=0; i--)
    {
        heapify(arr,i,n);
    }
}

//Extracts the minimum element from the heap
int extract_min(int *arr, int n)
{
    swap(&arr[0], &arr[n-1]);
    n--;
    heapify(arr, 0, n);
    return arr[n];
}

void heap_sort(int *arr, int n)
{
    build_heap(arr, n);
    //sort array in descending order to sort in ascending order use max heap
    for(int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, 0, i);
    }
}       

int main()
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    heap_sort(arr, n);  
    
    printf("After Heap sort: ");

    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
   
    build_heap(arr, n);

    printf("Heapified array: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Extracted minimum: %d\n", extract_min(arr, n));
    printf("Heap after extraction: ");
    for(int i = 0; i < n-1; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
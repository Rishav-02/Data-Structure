#include<stdio.h>

#define MAX 6

void Selection_sort(int [],int);

int main()
{
    int A[MAX],i;

    printf("Enter the Elements: ");
    for(i=0;i<MAX;i++)
    {
        scanf("%d",&A[i]);
    }
    Selection_sort(A,MAX);

    printf("Elements after Sorting: ");
    for(i=0;i<MAX;i++)
    {
        printf("%d ",A[i]);
    }
}

void Selection_sort(int A[],int N)
{
    int i,j,min=0,pos=0;  // "min" to store the minimum value found in each iteration and "pos" to store the position of the minimum value.

    for(i = 0; i < N-1; i++)
    {
        min = A[i];
        pos = i;

        for(j = i+1; j < N; j++)
        {
            if(min > A[j])
            {
                min = A[j];
                pos = j;
            }
        }

        if(pos != i)
        {
            //swap
            A[pos] = A[i];
            A[i] = min;
        }
    }
}

// void Selection_sort(int A[], int N)
// {
//     int i, j, pos, temp;

//     for(i = 0; i < N - 1; i++)
//     {
//         pos = i;  // Assume the first unsorted element is the smallest

//         for(j = i + 1; j < N; j++)
//         {
//             if(A[j] < A[i])  // Find index of the smallest element
//             {
//                 pos = j;
//             }
//         }

//         // Swap only if a smaller element was found
//         if(pos != i)
//         {
//             temp = A[i];
//             A[i] = A[pos];
//             A[pos] = temp;
//         }
//     }
// }

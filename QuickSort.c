#include <stdio.h>

#define MAX 10

void QuickSort(int [],int,int);

int main() {
  
    int A[MAX],i;

    printf("Enter the Elements: ");
    for(i=0;i<MAX;i++)
    {
        scanf("%d",&A[i]);
    }

    QuickSort(A, 0, MAX-1);

    printf("Elements after Sorting: ");
    for(i=0;i<MAX;i++)
    {
        printf("%d ",A[i]);
    }
}

void QuickSort(int A[], int lb, int ub)
{
    int i = lb,j = ub, key = A[lb], temp = 0;

  //Base case for recursion
  if(lb >= ub) {
    return;
  }

  while(i < j) 
{
    while(key >= A[i] && i < j)
    {
        i++;
    }

    while(key < A[j])
    {
        j--;
    }

    if(i < j) 
    {
        //Swapping 
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
  }

  //Swapping the pivot element with the element at index j
  A[lb] = A[j];
  A[j] = key;

  //Recursion for left and right subarrays
  QuickSort(A, lb, j-1);
  QuickSort(A, j+1, ub);
}
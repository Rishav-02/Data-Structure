#include <stdio.h>

#define MAX 10

//Function declarations
void MergeSort(int[],int[],int,int);
void Merge(int[],int[],int,int,int);

int main()
{
    int A[MAX],t[MAX],i;

    printf("Enter the Elements: ");
    for(i=0;i<MAX;i++)
    {
        scanf("%d",&A[i]);
    }

    MergeSort(A,t,0,MAX-1);//function call

    printf("Elements after Sorting: ");
    for(i=0;i<MAX;i++)
    {
        printf("%d ",A[i]);
    }
}

void MergeSort(int A[],int t[],int lb,int ub)
{
    int mid = 0;

    //Base case for recursion
    if(lb < ub)
    {
        mid = (lb + ub)/2;
        MergeSort(A,t,lb,mid);
        MergeSort(A,t,mid+1,ub);
        Merge(A,t,lb,mid,ub);
    }
}

void Merge(int A[],int t[],int lb,int mid,int ub)
{
    int i = lb, j = ub, k = lb, LE = mid;

    // Merging the two subarrays
    while(i <= LE && mid+1 <= ub)
    {
        if(A[i] < A[mid+1])
        {
            t[k] = A[i];
            i++;
            k++;
        }
        else{
            t[k] = A[mid+1];
            k++;
            mid++;
        }
    }

    // Copying the remaining elements from the left subarray
    while(i <= LE)
    {
        t[k] = A[i];
        i++;
        k++;
    }

    // Copying the remaining elements from the right subarray
    while(mid+1 <= ub)
    {
        t[k] = A[mid+1];
        k++;
        mid++;
    }

    // Copying the sorted elements back to the original array from the temporary array
    for(i = 0; i <= ub; i++)
    {
        A[i] = t[i];
    }
}


#include<stdio.h>

#define MAX 6

void Insertion_sort(int [],int);

int main()
{
    int A[MAX],i;

    printf("Enter the Elements: ");
    for(i=0;i<MAX;i++)
    {
        scanf("%d",&A[i]);
    }
    Insertion_sort(A,MAX);

    printf("Elements after Sorting: ");
    for(i=0;i<MAX;i++)
    {
        printf("%d ",A[i]);
    }
}

void  Insertion_sort(int A[],int N)
{
    int i,j,temp;

    for(i=1;i<N;i++)
    {
        temp = A[i];
        j = i-1;

        while(j >= 0 && temp < A[j])
        {
            A[j+1] = A[j];
            j--;
        }

        A[j+1] = temp;
    }
}
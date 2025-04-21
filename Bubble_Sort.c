#include<stdio.h>

#define MAX 6

void Bubble_sort(int [],int);

int main()
{
    int A[MAX],i;

    printf("Enter the Elements: ");
    for(i=0;i<MAX;i++)
    {
        scanf("%d",&A[i]);
    }
    Bubble_sort(A,MAX);

    printf("Elements after Sorting: ");
    for(i=0;i<MAX;i++)
    {
        printf("%d ",A[i]);
    }
}

void Bubble_sort(int A[],int N)
{
    int i,j,temp=0;

    for(i=0;i<N-1;i++)
    {
        for(j=0;j<N-1-i;j++)
        {
            if(A[j] > A[j+1])
            {
                //swap
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}
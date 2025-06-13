//Priority queue implementation using Array(call by value)
#include<stdio.h>

#define MAX 10

int PQEnq(int[],int);
int PQDeq(int[],int);
void Count(int);
void Display(int[],int);

int main()
{
    int PQ[MAX],R=0,ch;

    do{
        printf("\n Press 1 to Insert ");
        printf("\n Press 2 to Delete ");
        printf("\n Press 3 to Count ");
        printf("\n Press 4 to Display ");
        printf("\n Press 5 to Exit ");
        printf("\n Enter your Choice \t");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: R = PQEnq(PQ,R);
            break;

            case 2: R = PQDeq(PQ,R);
            break;

            case 3: Count(R);
            break;

            case 4: Display(PQ,R);
            break;
        }
    } while(ch <= 5);
 return 0;
}


int PQEnq(int PQ[],int R)
{
    int pr,v;

    if(R == MAX - 1)
    {
        printf("\n Queue is Full");
    }
    else
    {
        printf("\nEnter priority and value to insert: ");
        scanf("%d %d",&pr,&v);

        PQ[R] = pr;
        PQ[R+1] = v;
        R = R + 2;
    }
    return R;
}

int PQDeq(int PQ[], int R)
{
    if (R == 0)
    {
        printf("\nQueue is Empty");
        return R;
    }

    // Assume first pair has highest priority
    int minIndex = 0, i;

    // Find index with minimum priority
    for (i = 2; i < R; i = i+2)
    {
        if (PQ[i] < PQ[minIndex])
        {
            minIndex = i;
        }
    }

    printf("\nDeleted Element: Priority = %d, Value = %d", PQ[minIndex], PQ[minIndex + 1]);

    // Shift elements left to fill the gap
    for (i = minIndex; i < R - 2; i += 2)
    {
        PQ[i] = PQ[i + 2];
        PQ[i + 1] = PQ[i + 3];
    }

    R = R-2; // Two elements removed

    return R;
}

void Count(int R)
{
    // Each element has a pair (priority, value) that takes 2 slots i.e half priority and half value
    printf("\nTotal number of elements: %d\n", R / 2);
}

void Display(int PQ[], int R)
{
    if(R == 0)
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        printf("\nElements in Priority Queue:\n");
        for(int i = 0; i < R; i += 2)
        {
            printf("Priority: %d, Value: %d\n", PQ[i], PQ[i+1]);
        }
    }
}
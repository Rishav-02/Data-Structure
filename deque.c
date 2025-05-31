/* DeQue (Double-ended Queue)
What is a deque?
-> A queue where insertion and deletion can be performed 
at both the end (front and rear).
-> Unlike simple queue where insertion is done from rear and deletion
is done from front, deque enables insertion and deletion from both the end.

There are two types of deque:
-> Input restricted deque
    - Insertion at rear
    - Deletion at rear
    - Deletion at front
-> Output restricted deque
    - Insertion at rear
    - Insertion at front
    - Deletion at front
*/

#include<stdio.h>

#define MAX 10

int InsertFromRear(int[],int);
int DeleteFromFront(int[],int,int);
int InsertFromFront(int[],int);
int DeleteFromRear(int[],int,int);
void Display(int[],int,int);

int main()
{
    int DQ[MAX], F=-1,R=-1,ch;

    do{
        printf("\nPress 1 to Insert from Rear end ");
        printf("\nPress 2 to Delete from Front end ");
        printf("\nPress 3 to Insert from Front end ");
        printf("\nPress 4 to Delete from Rear end ");
        printf("\nPress 5 to Display ");
        printf("\nEnter your choice ");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1: R = InsertFromRear(DQ,R);
                if(F == -1)
                F = 0;
            break;

        case 2: F = DeleteFromFront(DQ,F,R);
                if(F == -1)
                R = -1;
            break;

        case 3: F = InsertFromFront(DQ,F);
                if(R == -1)
                R = 0;
            break;

        case 4: R = DeleteFromRear(DQ,F,R);
                if(R == -1)
                F = -1;
            break;

        case 5: Display(DQ,F,R);
            break;
        }
    } while(ch<=5);
}

int InsertFromRear(int DQ[],int R)
{
    int x;

    if(R == MAX -1)
    {
        printf("\n Deque is Full");
    }
    else{
        printf("\n Enter the value to insert at Rear: ");
        scanf("%d",&x);

        R++;
        DQ[R] = x;
    }
    return R;
}

int DeleteFromFront(int DQ[],int F,int R)
{
    if(F == -1 && R == -1)
    {
        printf("\n Deque is Empty");
    }
    else{
        printf("\n Element to be deleted: %d\n",DQ[F]);

        if(F == R)
         F = -1;
        else
         F++;
    }
    return F;
}

int InsertFromFront(int DQ[],int F)
{
   int x;

   if(F == 0)
   {
     printf("\n Cannot insert at front - either Deque is full or uninitialized correctly.");
   }
   else
   {
       printf("\n Enter the value to Insert at Front: ");
       scanf("%d",&x);
       if(F == -1){
        F++;
       }
       else{
       F--;
       }
       DQ[F] = x;
   }
   return F;
}

int DeleteFromRear(int DQ[],int F,int R)
{
    if(F == -1 && R == -1)
    {
        printf("\n Deque is Empty");
    }
    else{
        printf("\n Element to be deleted: %d\n",DQ[R]);

        if(F == R)
         R = -1;
        else
         R--;
    }
    return R;
}

void Display(int DQ[],int F,int R)
{
    if(F == -1 && R == -1)
    {
        printf("\n Deque is Empty");
    }
    else{
        printf("\nElements in Deque: ");
        for(int i = F; i <= R; i++)
        {
            printf("%d \t",DQ[i]);
        }
    }
}
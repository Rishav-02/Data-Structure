//Queue implementation using Linked List (call by value,using single pointer)

#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int data;
    struct Queue *next;
}typedef Q;

//Function Declaration
Q* Enq(Q*);
Q* Deq(Q*,Q*);
void Display(Q*);

int main()
{
    Q *F=NULL, *R = NULL;
    int ch;

    do{
        printf("\n Press 1 to Enqueue ");
        printf("\n Press 2 to Dequeue ");
        printf("\n Press 3 to Display ");
        printf("\n Enter your Choice \t");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: R = Enq(R);
                    if(F == NULL)
                    F=R;
            break;

            case 2: F = Deq(F,R);
                    if(F == NULL)
                    R = NULL;
            break;

            case 3: Display(F);
            break;
        }
    } while(ch <= 3);
}


Q* Enq(Q *R)
{
    int x;
    Q* p = NULL;

    p = (Q*)malloc(sizeof(Q));
    if(p == NULL)
    printf("Queue is full");
    else{
        printf("\n Enter the value to insert ");
        scanf("%d",&x);

        p->data = x;
        if(R == NULL)
        R = p;
        else{
            R->next = p;
            R = p;
        }
        R ->next = NULL;
    }
    return R;
}

Q* Deq(Q *F,Q *R)
{
    Q* p = NULL;

     if(F == NULL && R == NULL)
     printf("\t Queue is Empty");
     else{
         p = F;
         printf("\t %d",p->data);
         F = F->next;
         free(p);
     }
     return F;
}


void Display(Q* F)
{
    if(F == NULL)
    printf("\t Queue is Empty");
    else{
        while(F != NULL)
        {
             printf("\t %d",F->data);
             F = F->next;
        }
    }
}
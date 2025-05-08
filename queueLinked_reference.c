//Queue implementation using Linked List (call by reference,using double pointer)

#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int data;
    struct Queue *next;
}typedef Q;

//Function Declaration
void Enq(Q**, Q**);
void Deq(Q**, Q**);
void Display(Q*);
void Peek(Q* );

int main()
{
    Q *F = NULL, *R = NULL;
    int ch;

    do {
        printf("\n Press 1 to Enqueue ");
        printf("\n Press 2 to Dequeue ");
        printf("\n Press 3 to Display ");
        printf("\n Press 4 to Peek ");
        printf("\n Enter your Choice \t ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1: Enq(&F, &R);
                    break;

            case 2: Deq(&F, &R);
                    break;

            case 3: Display(F);
                    break;

            case 4: Peek(F);
                    break;
        }
    } while (ch <= 4);
    return 0;
}

void Enq(Q **F, Q **R)
{
    int x;
    Q *p;

    p = (Q*)malloc(sizeof(Q));
    if (p == NULL)
        printf("Queue is full");
    else {
        printf("\n Enter the value to insert: ");
        scanf("%d", &x);

        p->data = x;
        p->next = NULL;
        
        if (*R == NULL && *F == NULL) 
        {
            *F = *R = p;
        } else {
            (*R)->next = p;
            *R = p;
        }
    }
}

void Deq(Q **F, Q **R)
{
    Q *p = NULL;
    
    if (*F == NULL && *R == NULL)
        printf("Queue is Empty\n");
    else {
        p = *F;
        printf("Dequeued element: %d\n", p->data);
        *F = (*F)->next;
        free(p);
    }
}

void Display(Q *F)
{
    if (F == NULL)
        printf("Queue is Empty\n");
    else {
        while (F != NULL) {
            printf("\t %d", F->data);
            F = F->next;
        }
        printf("\n");
    }
}


void Peek(Q* F)
{
    if (F == NULL)
        printf("Queue is Empty\n");
    else
        printf("Front element: %d\n", F->data);
}

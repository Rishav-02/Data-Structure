//Stack implementation using Linked List (call by value,using single pointer)
#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int data;
    struct stack *next;
}typedef s;

//Function declaration
s* push(s*);
s* pop(s*);
void display(s*);
void peek(s*);

int main()
{
    s* Top = NULL;
    int ch;

    do{
        printf("\n Press 1 to push ");
        printf("\n Press 2 to pop ");
        printf("\n Press 3 to display ");
        printf("\n Press 4 to peek ");
        printf("\n Enter your choice \t");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: Top = push(Top);// Caller updates Top with the returned value
                    break;

            case 2: Top = pop(Top);
                    break;

            case 3: display(Top);
                    break;

            case 4: peek(Top);
                    break;
        }
    } while(ch <= 4);
}

s* push(s* Tp)
{
    int x;
    s* p = NULL;

    p = (s*)malloc(sizeof(s));
    if(p!=NULL)
    {
        printf("\n Enter the value to insert: ");
        scanf("%d",&x);
        p->data = x;
        p->next = Tp;
        Tp = p;
    }
    return Tp;
}

s* pop(s* Tp)
{
    int x;
    s* p = NULL;

    if(Tp == NULL)
    printf("\nStack is Empty");
    else
    {
        x = Tp->data;
        printf("\t %d",x);
        p = Tp;
        Tp = Tp->next;
        free(p);
    }
    return Tp;
}

void display(s* Tp)
{
    if(Tp == NULL)
    printf("Stack is Empty");
    else
    {
        while(Tp!=NULL)
        {
            printf("\t %d\n",Tp->data);
            Tp = Tp->next;
        }
    }
}

void peek(s* Tp)
{
    if(Tp == NULL)
    printf("Stack is Empty");
    else
    printf("\t %d",Tp->data);
}
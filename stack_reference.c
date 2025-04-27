//Stack Implementation by Array using structure(call by reference)
#include<stdio.h>
#define SIZE 10

struct stack
{
    int arr[SIZE];
    int top;
}typedef Stack;

//function declaration
void push(Stack *);
void pop(Stack *);
void display(Stack *);
void peek(Stack *);

void main()
{
    Stack s;
    int ch;
    s.top=-1;

    do
    {   
        printf("\n Press 1 to push ");
        printf("\n Press 2 to pop ");
        printf("\n Press 3 to display ");
        printf("\n Press 4 to peek ");
        printf("\n Enter Your Choice \t");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: push(&s);
                    break;

            case 2: pop(&s);
                    break;
           
            case 3: display(&s);
                    break;
                
            case 4: peek(&s);
                    break;
        
            default: printf("\n Invalid Choice");
                     break;      
        }
    } while(ch<=4);
}


void push(Stack *p)
{
    int x;
    //p->top in place of s.top(p-> for s. ) 
    if(p->top==SIZE-1)
    {
        printf("\n Stack is Full(OverFlow)");
        return;//if we write "return" then there is no need to write 'else'
    }
    printf("\n Enter value to push : ");
    scanf("%d",&x);
    p->top++;
    p->arr[p->top]=x;
}

void pop(Stack *p)
{
    int x;
    if(p->top==-1)
    {
        printf("\n Stack is Empty(UnderFlow)");
        return;
    }
    x = p->arr[p->top];
    printf("\n popped data is %d",x);
    p->top--;
}

void display(Stack *p)
{
    int i;
    if(p->top==-1)
    {
        printf("\n Stack is Empty");
        return;
    }
    
    // for(i=p->top;i>=0;i--)  loop for search from Top to Bottom
    // {
    //     printf("\t%d",p->arr[i]);
    // }
    for(i=0;i<=p->top;i++) // loop for search from Bottom to Top 
    {
        printf("\t %d", p->arr[i]);
    }
}

void peek(Stack *p)
{
    if(p->top == -1)
    {
        printf("\n Stack is Empty");
        return;
    }
    //top of stack
    printf("\t %d",p->arr[p->top]);
}
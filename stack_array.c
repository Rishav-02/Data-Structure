//Stack Implementation by Array(call by value)
#include<stdio.h>

#define MAX 10

//function declaration
int push(int[],int);
int pop(int[],int);
void display(int[],int);
void peek(int[],int);

void main()
{
    int Stack[MAX],top=-1,ch=0;

    do
    {   
        printf("\n Enter Your Choice ");
        printf("\n Press 1 to push ");
        printf("\n Press 2 to pop ");
        printf("\n Press 3 to display ");
        printf("\n Press 4 to peek\t");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: top = push(Stack,top);
                    break;

            case 2: top = pop(Stack,top);
                    break;
           
            case 3: display(Stack,top);
                    break;
                
            case 4: peek(Stack,top);
                    break;
        
            default: printf("\n Inavlid Choice");
        }
    } while(ch<=4);
}


int push(int Stack[],int top)
{
    int x;
    if(top == MAX-1)
    {
        printf("\n Stack is Full(Overflow) \n");
    }
    else{
    printf("\n Enter value to push : ");
    scanf("%d",&x);
    top++;
    Stack[top]=x;
    }
    return top;
}


int pop(int Stack[],int top)
{
    int x;
    if(top == -1)
    {
        printf("\n Stack is Empty(Underflow) \n");
    }
    else{
        x =Stack[top];
        printf("\n Popped Element: %d\n",x);
        top--;
    }
    return top;
}


void display(int Stack[],int top)
{
    int i;
    if(top == -1)
    {
        printf("\n Stack is Empty \n");
    }
    else{
    
    for(i=top;i>=0;i--)  //loop for search from Top to Bottom
    {
        printf("\t %d\n",Stack[i]);
    }
    // for(i=0;i<=top;i++) // loop for search from Bottom to Top 
    // {
        //     printf("\t %d", Stack[i]);
        // }
    }
}


void peek(int Stack[],int top)
{
    if(top == -1)
    {
        printf("\n Stack is Empty\n");
    }
    else{    
        printf("\t Element at top of Stack: %d\n",Stack[top]);
    }
}
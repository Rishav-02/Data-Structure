//Stack Implementation by Array(call by reference) without structure
#include<stdio.h>

#define MAX 10

// Function declarations with call by reference
void push(int[], int*);
void pop(int[], int*);
void display(int[], int);
void peek(int[], int);

void main()
{
    int Stack[MAX], top = -1, ch = 0;

    do
    {   
        printf("\n Enter Your Choice ");
        printf("\n Press 1 to push ");
        printf("\n Press 2 to pop ");
        printf("\n Press 3 to display ");
        printf("\n Press 4 to peek\t");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: push(Stack, &top);
                    break;

            case 2: pop(Stack, &top);
                    break;
           
            case 3: display(Stack, top);
                    break;
                
            case 4: peek(Stack, top);
                    break;
        
            default: printf("\n Invalid Choice");
        }
    } while(ch <= 4);
}

void push(int Stack[], int *top)
{
    int x;
    if (*top == MAX - 1)
    {
        printf("\n Stack is Full (Overflow) \n");
    }
    else {
        printf("\n Enter value to push: ");
        scanf("%d", &x);
        (*top)++;
        Stack[*top] = x;
    }
}

void pop(int Stack[], int *top)
{
    if (*top == -1)
    {
        printf("\n Stack is Empty (Underflow) \n");
    }
    else {
        printf("\n Popped Element: %d\n", Stack[*top]);
        (*top)--;
    }
}

void display(int Stack[], int top)
{
    if (top == -1)
    {
        printf("\n Stack is Empty \n");
    }
    else {
        for (int i = top; i >= 0; i--)  // loop for search from Top to Bottom
        {
            printf("\t %d\n", Stack[i]);
        }
    }
}

void peek(int Stack[], int top)
{
    if (top == -1)
    {
        printf("\n Stack is Empty\n");
    }
    else {    
        printf("\t Element at top of Stack: %d\n", Stack[top]);
    }
}

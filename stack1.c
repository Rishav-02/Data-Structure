//Stack Implementation by Array(call by address using structure)

#include<stdio.h>
#include<stdlib.h>
#define M 5
struct stack
{
    int stk[M];
    int top;
}typedef Stack;

int push(Stack *);
int pop(Stack *);
void display(Stack *);


int main()
{
    Stack s1;
    s1.top=-1;
    int a,ch;
    while(1)
    {
        printf("\n\t1.Press 1 to Push in Stack\n\t2.Press 2 to Pop in Stack\n\t3.Press 3 to Display in Stack\n\t4.Press 4 to Exit\n\n\tEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            push(&s1);
            break;

            case 2:
            pop(&s1);
            break;

            case 3:
            display(&s1);
            break;

            case 4:
            exit(0);

            default:
            printf("\n\tInavlid choice");
            break;
        }
    }
}


int push(Stack *p)
{
    int a;
    if(p->top==M-1)
    {
        printf("\n\tstack is overflow");
        return 0;
    }
    printf("\n\tenter data to push : ");
    scanf("%d",&a);
    p->top++;
    p->stk[p->top]=a;
}

int pop(Stack *p)
{
    if(p->top==-1)
    {
        printf("\n\tStack is underflow");
    }
    printf("\n\n\tpopped data : %d",p->stk[p->top]);
    p->top--;
}

void display(Stack *p)
{
    int i;
    if(p->top==-1)
    {
        printf("\n\tStack is underflow");
    }
    for(i=p->top;i>=0;i--)
    {
        printf("\n\t%d",p->stk[i]);
    }

}
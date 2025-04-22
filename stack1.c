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
        // system("cls");
        printf("\n\t1. Push I Stack\n\t2. Pop I Stack\n\t3. Display I Stack\n\t4. Exit\n\n\tenter your choice : ");
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
            getch();
            break;

            case 4:
            exit(0);

            default:
            printf("\n\tInavlid choice");
            getch();
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
        getch();
        return;
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
        getch();
        return;
    }
    printf("\n\n\tpopped data : %d",p->stk[p->top]);
    getch();
    p->top--;
}

void display(Stack *p)
{
    int i;
    if(p->top==-1)
    {
        printf("\n\tStack is underflow");

        return;
    }
    for(i=p->top;i>=0;i--)
    {
        printf("\n\t%d",p->stk[i]);
    }

}


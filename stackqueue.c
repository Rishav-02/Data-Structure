//Implement the function of Queue using two Stack
#include<stdio.h>
#define M 5
struct stack
{
    int stk[M];
    int top;
}typedef Stack;

main()
{
    Stack s1,s2;
    int ch,a;
    s1.top=-1;
    s2.top=-1;

    while(1)
    {
        printf("\n\t1. Insert\n\t2. Delete\n\t3. Display\n\t4. Exit\n\n\tEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            if(s1.top==M-1)
            {
                printf("\n\tQueue is full");
                getch();
            }
            else
            {
                printf("\n\tenter element to insert : ");
                scanf("%d",&a);
                push(&s1,a);
            }
            break;

            case 2:
            del(&s1,&s2);
            break;


            case 3:
            disp(&s1);
            getch();
            break;


            case 4:
            exit(0);

            default:
            printf("\n\tInvalid choice");
            getch();
            break;

        }
    }
}


push(Stack *p,int n)
{
    p->top++;
    p->stk[p->top]=n;
}


pop(Stack *p)
{
    int t;
    t=p->stk[p->top];
    p->top--;
    return(t);
}


del(Stack *p,Stack *q)
{
    int i;
    if(p->top==-1)
    {
        printf("\n\n\tqueue is empty");
        getch();
        return;
    }
    while(p->top >= 0)
    {
        push(q,pop(p));
    }

    i=pop(q);
    printf("\n\n\tdeleted data :  %d",i);
    getch();
    while(q->top >= 0)
    {
        push(p,pop(q));
    }

}

disp(Stack *p)
{
    int i;
    if(p->top==-1)
    {
        printf("\n\tqueue is empty");
        return;
    }

    printf("\n\n\t");
    for(i=0;i<=p->top;i++)
    {
        printf("%d  ",p->stk[i]);
    }
}
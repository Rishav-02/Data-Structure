#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coef,expo;
    struct node *next;
}typedef Node;

int main()
{
    int i,ch,a,b;
    Node *head=NULL;
    while(1)
    {
        system("cls");
        printf("\n\t1. Insert\n\t2. Display \n\t3. Evaluate\n\t4. Exit\n\n\tenter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\n\tenter coefficient and exponent : ");
            scanf("%d%d",&a,&b);
            insert(&head,a,b);
            break;

            case 2:
                disp(&head);
                getch();
                break;

            case 3:
            eval(&head);
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


insert(Node **h,int c,int e)
{
    Node *t,*z;
    t=malloc(sizeof(Node));
    t->coef=c;
    t->expo=e;
    t->next=NULL;

    if(*h==NULL)
    {
        *h=t;
        return;
    }
    z=*h;
    while(z->next!=NULL)
    {
        if(z->expo==e)
        {
            z->coef=z->coef+c;
            free(t);
            return;
        }
        z=z->next;
    }
    if(z->expo==e)
    {
        z->coef=z->coef+c;
        free(t);
        return;
    }
    z->next=t;
}


disp(Node **h)
{
    Node *z;
    if(*h==NULL)
    {
        printf("\n\n\tpolynimial is empty");

        return;
    }

    z=*h;
    printf("\n\n\t");
    while(z!=NULL)
    {
        printf("%d - %d   ",z->coef,z->expo);
        z=z->next;
    }
}

eval(Node **h)
{
    int s=0,x,p,i;
    Node *z;
    if(*h==NULL)
    {
        printf("\n\n\tpolynimial is empty");
        getch();
        return;
    }
    z=*h;
    printf("\n\tenter value of x : ");
    scanf("%d",&x);
    while(z!=NULL)
    {
            p=1;
            for(i=1;i<=z->expo;i++)
            {
                p=p*x;
            }
            p=p*z->coef;
            s=s+p;
            z=z->next;
    }
    printf("\n\n\tresult : %d",s);
    getch();
}

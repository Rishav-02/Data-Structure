// Doubly Linked list by inserting and deleting node at right and left hand side(call by value)

#include<stdio.h>
#include<stdlib.h>

struct dlist
{
    int data;
    struct dlist *prev,*next;
}typedef dl;

dl * insertatleft(dl *);
dl * insertatright(dl *);
void display(dl *);
dl * deletefirst(dl *,dl *);
dl * deletelast(dl *,dl *);

int main()
{
    dl *L = NULL, *R = NULL;
    int ch;

    do{
        printf("\n Press 1 to insert at left ");
        printf("\n Press 2 to  insert at right ");
        printf("\n Press 3 to Display ");
        printf("\n Press 4 to  delete at left ");
        printf("\n Press 5 to  delete at right ");
        printf("\n Enter your Choice \t ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: L = insertatleft(L);
                    if(R == NULL)
                    R = L;
            break;

            case 2: R = insertatright(R);
                    if(L == NULL)
                    L = R;
            break;

            case 3: display(L);
            break;

            case 4: L = deletefirst(L,R); 
            break;

            case 5: R = deletelast(R,L);
            break;
        }
    } while(ch<=5);
}


dl * insertatleft(dl *L)
{    
    dl *p = NULL;
    int x;

    p = (dl *)malloc (sizeof(dl));
    if(p!=NULL)
    {
        printf("\n Enter the value to insert ");
        scanf("%d",&x);
        p->data = x;

        if(L == NULL)
        {
            L = p;
            L -> prev = NULL;
        }
        else{
            p -> prev = NULL;
            p -> next = L;
            L -> prev = p;
            L = p;
        }
    }
    return L;
}


dl * insertatright(dl *R)
{
    dl *p = NULL;
    int x;

    p = (dl *)malloc (sizeof(dl));
    if(p != NULL)
    {
        printf("\n Enter the value to insert ");
        scanf("%d",&x);
        p -> data = x;

        if(R == NULL)
        {
            R = p;
            R -> prev = NULL;
        }
        else{
            R -> next = p;
            p -> prev = R;
            R = p;
        }
        R -> next = NULL;
    }
    return R;
}


void display(dl *L)
{
    dl *p;
    if(L == NULL)
    printf("\n List is Empty");

    else{
        p = L;
        while(p != NULL)
        {
            printf("\t %d",p->data);
            p = p->next;
        }
    }
}


dl* deletefirst(dl *L,dl *R)
{
     dl *p;

     if(L == NULL)
     {
        printf("\t List is Empty");
     }

     else if(L->next == NULL)// Only one node
     {
            p = L;
            printf("\t Deleted: %d\n", p->data);
            free(p);
            L = R = NULL;
     }
     else
     {
        p = L;
        L = L->next;
        L -> prev = NULL;
        printf("\t Deleted: %d\n", p->data);
        free(p);
     }
     return L;
}


dl* deletelast(dl *R,dl *L)
{
    dl *p;

    if(R == NULL)
    {
        printf("\t List is Empty");
    }

    else if (R -> prev == NULL)// Only one node
    {
        p = R;
        printf("\t Deleted: %d\n", p->data);
        free(p);
        R = L = NULL;
    }

    else
    {
        p = R;
        R = R -> prev;
        R -> next = NULL;
        printf("\t Deleted: %d\n", p->data);
        free(p);
    }
    return R;
}
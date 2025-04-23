//Single Linked List by Inserting nodes at the left hand side
#include<stdio.h>
#include<stdlib.h>

struct slist{
    int data;
    struct slist *next;
}typedef sl;

int main()
{
    sl *L=NULL,*p=NULL;
    int ch,x,flag,c=0;

    while(1)
    {
        p = (sl*)malloc(sizeof(sl));

        if(p!=NULL)
        {
            printf("\nEnter value to insert: ");
            scanf("%d",&x);
            p->data = x;
            p->next = L;
            L = p;
        }
        printf("\n Enter the choice ");
        scanf("%d",&ch);
        if(ch == 0)
        break;
    }
    //Display
    p = L;
    while(p != NULL)
    {
        printf("\t %d",p->data);
        p = p -> next;
    }
    //Count
     p = L;
     while(p != NULL)
     {
         c++;
         p = p -> next;
     }
     printf("\nTotal number of element are %d \n",c);

    //Prime No.
    p = L;
    while(p != NULL)
    {
       x = p -> data;
       flag = 0, c = 0;
       if(x == 0 || x == 1)
       flag = 1;

        for(int i = 2; i <= x/2; i++)
        {
            if(x % i == 0){
            flag = 1;
            break;
            }
        }
        p = p->next;
    }
    if(flag == 0)
    printf("%d is Prime number ", x);
    else
    printf("%d is not a Prime number", x);
}
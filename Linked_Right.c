//Single Linked List by Inserting nodes at the right hand side
#include<stdio.h>
#include<stdlib.h>

struct slist
{
    int data;
    struct slist *next;
}

main()
{
    struct slist *L=NULL,*R=NULL,*p=NULL;
    int ch,x,c=0;

    while(1) 
    {    
        p = ((struct slist*)malloc(sizeof(struct slist)));

        if(p != NULL)
        {
            printf("Enter value to insert: ");
            scanf("%d",&x);
            p->data = x;
            p->next = NULL;
        }
        if(L == NULL && R == NULL){
            L = R = p;
        }
        else{
            R -> next = p;
            R = p;
        }
        printf("\n Enter your Choice ");
        scanf("%d",&ch);
        if(ch == 0)
        break;
    }        
        //Display
            p = L;
            while(p != NULL)
            {
                printf("\t%d",p->data);
                p = p -> next;
            }
        //Count
            p = L;
            while(p != NULL)
            {
                c++;
                p = p->next;
            }
            printf("\nTotal number of elements: %d\n", c);
}
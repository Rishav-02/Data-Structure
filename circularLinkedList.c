//Circular Linked List by inserting and deleting node at the left and right hand side(call by value)

#include<stdio.h>
#include<stdlib.h>

struct circularLinkedlist
{
    int data;
    struct circularLinkedlist *next;
}typedef cl;

cl * insertatleft(cl *);
cl * insertatright(cl *);
void display(cl *);
cl * deletefirst(cl *);
cl * deletelast(cl *);

int main()
{
    cl *last = NULL;
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
            case 1: last = insertatleft(last);
            break;

            case 2: last = insertatright(last);
            break;

            case 3: display(last);
            break;

            case 4: last = deletefirst(last);
            break;

            case 5: last = deletelast(last);
            break;
        }
    } while(ch<=5);
}


cl * insertatleft(cl * last)
{
    int x;
    cl *p = NULL;
    
    p = (cl*)malloc(sizeof(cl));
    if(p != NULL)
    {
        printf("\n Enter the value to insert ");
        scanf("%d",&x);
        p->data = x;

        if(last == NULL) //Only one node
        {
            last = p;
            last->next = p;
        }
        else
        {
            p->next = last->next;
            last->next = p;
        }
    }
    return last;
}


cl * insertatright(cl * last)
{
    int x;
    cl* p = NULL;
    
    p = (cl*)malloc(sizeof(cl));
    if(p != NULL)
    {
        printf("\n Enter the value to insert ");
        scanf("%d",&x);
        p->data = x;

        if(last == NULL)
        {
            last = p;
            last->next = p;
        }
        else
        {
            p->next = last->next; // Point new node to first node
            last->next = p;       // Last node should now point to the new node
            last = p;             // Update last to the newly added node
        }
    }
    return last;
}

void display(cl* last)
{
    cl *p;

    if(last == NULL)
    {
        printf("\t List is Empty");
        return;
    }

    p = last->next;  // Start from the first node
    do
    {
        printf("\t%d", p->data);
        p = p->next;
    } while (p != last->next);  // Stop when we reach the first node again
    printf("\n");
}


cl * deletefirst(cl * last)
{
    cl *p;
    if(last == NULL)
    {
        printf("\t List is Empty");
        return NULL;
    }
        p = last ->next; //First node
        if(p == last)  //Only one node in the list
        {
               printf("\t %d",p->data);
               free(p);
               return NULL;
        }
        last ->next = p->next; // Update last node to point to second node
        printf("\t %d",p->data);
        free(p);
        return last;
}


cl * deletelast(cl * last)
{
    cl* p;
    if(last == NULL)
    {
        printf("\t List is Empty");
        return NULL;
    }
   
        p = last -> next; //start from first node
        if(p == last) //only one node in the list
        {
            printf("\t %d",p->data);
            free(p);
            return NULL;
        }

        //Find the second-last node
        while(p ->next != last)
        {
            p = p->next;
        }

        p -> next = last->next;// Update second-last node to point to first node
        printf("\t %d",last->data);
        free(last);
    
    return p;// Update last pointer to new last node
}
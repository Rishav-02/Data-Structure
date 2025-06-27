#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;
void insert(node **);
void display(node *);
void sort(node *);
void merge(node *, node *);

int main()
{
    node *left1 = NULL,*right1 = NULL, *left2 = NULL, *right2 = NULL, *left3 = NULL, *right3 = NULL;
    int ch;

    do
    {
        printf("\nEnter choice:\n");
        printf("1. Insert in list1\n");
        printf("2. Display list1\n");
        printf("3. Insert in list2\n");
        printf("4. Display list2\n");
        printf("5. Merge lists\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch){
        case 1:
            insert(&right1);
            if (left1 == NULL)
            {
                left1 = right1;
            }
            break;
        case 2:
            printf("displaying list1\n");
            display(left1);
            break;
        case 3:
            insert(&right2);
            if (left2 == NULL)
            {
                left2 = right2;
            }
            break;
        case 4:
            printf("displaying list2\n");
            display(left2);
            break;
        case 5:
            merge(left1, left2);
        default:
            printf("wrong choice\n");
    }
  } while (ch != 5);
}


void insert(node **right)
{
    node *p = (node *)malloc(sizeof(node));
    int x;
    printf("enter data to be inserted in list\n");
    scanf("%d", &x);
    if (p != NULL)
    {
        p->data = x;
        p->next = NULL;
        if ((*right) != NULL)
            (*right)->next = p;
        (*right) = p;
    }
}
void display(node *left)
{
    node *temp = left;
    if (temp == NULL)
    {
        printf("list is empty\n");
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
void sort(node *left)
{
    node *i = NULL, *j = NULL, *min;
    if (left == NULL || left->next == NULL)
        return;

    for (i = left; i != NULL; i = i->next)
    {
        min = i;
        for (j = i->next; j != NULL; j = j->next)
        {
            if (min->data > j->data)
                min = j;
        }
        int a = min->data;
        min->data = i->data;
        i->data = a;
    }
}
void merge(node *left1, node *left2)
{
    node *left3 = NULL, *right3 = NULL;
    node *p;
    while (left1 != NULL && left2 != NULL)
    {
        p = (node *)malloc(sizeof(node));
        p->next = NULL;
        if (left1->data == left2->data)
        {
            p->data = left1->data;
            left1 = left1->next;
            left2 = left2->next;
        }
        else if (left1->data < left2->data)
        {
            p->data = left1->data;
            left1 = left1->next;
        }
        else
        {
            p->data = left2->data;
            left2 = left2->next;
        }
        if (left3 == NULL && right3 == NULL)
            left3 = right3 = p;
        else
            right3->next = p;
        right3 = p;
    }
    while (left1 != NULL)
    {
        p = (node *)malloc(sizeof(node));
        p->data = left1->data;
        p->next = NULL;
        right3->next = p;
        right3 = p;
        left1 = left1->next;
    }
    while (left2 != NULL)
    {
        p = (node *)malloc(sizeof(node));
        p->data = left2->data;
        p->next = NULL;
        right3->next = p;
        right3 = p;
        left2 = left2->next;
    }
    printf("merged list is:\n");
    display(left3);
}
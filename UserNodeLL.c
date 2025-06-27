#include<stdio.h>
#include<stdlib.h>

typedef struct list{
    int data;
    struct list *next;
}node;

node* insert(node *);
void display(node *);
node* insertAtNth(node *);

int main(){
    node *r=NULL, *h=NULL;
    int ch;
    do{
        printf("1.Insert\n2.Insert at nth position\n3.Display\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: r = insert(r);
            if(h==NULL){
                h = r;
            }
            break;

            case 2: h = insertAtNth(h);
            break;

            case 3: display(h);
            break;
        }
    }while(ch>=1 && ch<=3);
}

//Insert into list
node* insert(node *r){
    node *ptr=NULL;
    int x;
    ptr = (node*)malloc(sizeof(node));
    if(ptr){
        printf("Enter the value to insert: ");
        scanf("%d", &x);
        ptr->data = x;
        ptr->next = NULL;

        if(r==NULL){
            r = ptr;
        }else{
            r->next = ptr;
            r = ptr;
        }
    }else{
        printf("Memory not allocated\n");
    }
    return r;
}

// Display
void display(node *h){
    if(h==NULL){
        printf("List is empty\n");
        return;
    }else{
        node *temp = h;
        printf("\n\t");
        while(temp!=NULL){
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

//InsertNth position
node* insertAtNth(node *h){
    node* ptr = NULL, *temp = NULL;
    ptr = (node*) malloc(sizeof(node));
    int x, info;
    if(ptr){
        if(!h){
            printf("List is empty\n");
            free(ptr);
            return h;
        }

        temp = h;
        printf("\tCurrent List\n");
        while(temp!=NULL){
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        
        printf("\nEnter the node after which you want to insert: ");
        scanf("%d", &x);

        temp = h;
        while(temp!=NULL){
            if(temp->data == x){
                printf("\n Enter value to insert: ");
                scanf("%d", &info);
                ptr->data = info;
                ptr->next = temp->next;
                temp->next = ptr;
                printf("Value inserted\n");
                return h;
            }
            temp = temp->next;
        }
        printf("%d value not found\n");
        free(ptr);
    }else{
        printf("Memory not allocated\n");
    }
    return h;
}
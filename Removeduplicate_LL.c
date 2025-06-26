#include<stdio.h>
#include<stdlib.h>

typedef struct list{
    int data;
    struct list *next;
}node;

node* insert(node*);
node* removeDuplicates(node*);
void displayList(node *);

int main(){
    node *r=NULL, *h=NULL;
    int ch;
    do{
        printf("\n1.Insert in List\n2.Remove duplicates \n3.Display List\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: r = insert(r);
            if(h==NULL){
                h = r;
            }
            break;

            case 2: h = removeDuplicates(h);
            break;

            case 3: displayList(h);
            break;
        }
    }while(ch>=1 && ch<=3);
}

// Insert into list
node* insert(node *r){
    node* ptr = NULL;
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

// Remove duplicates
node* removeDuplicates(node* h){
    node* curr = h;
    node* prev = NULL;
    node* temp = NULL;
    if(h==NULL){
        printf("List is empty\n");
        return h;
    }
    printf("Before removing duplicates\n");
    displayList(curr);
    while(curr!=NULL){
        prev = curr;
        temp = curr->next;
        
        while(temp!=NULL){
            if(curr->data == temp->data){
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }else{
                prev = temp;
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    printf("After removing duplicates\n");
    displayList(h);
    return h;
}

// Display list
void displayList(node *h){
    node* temp = NULL;
    if(h==NULL){
        printf("List is empty\n");
        return;
    }
    temp = h;
    printf("\nNodes in list are\n");
    while(temp!=NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}
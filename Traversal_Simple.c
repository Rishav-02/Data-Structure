// Traversal of Binary Search Tree using Stack without Recursion

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

struct BST
{
    struct BST *left;
    int data;
    struct BST *right;
   
} typedef BST;

// Global stack for traversal
BST* stk[SIZE];
BST* t;  
int top = -1;

void push(BST*);
BST* pop();
void Insert(BST**,int);
void Preorder(BST*);
void Inorder(BST*);
void Postorder(BST*);


int main()
{
    BST *root = NULL;
    int ch,n;    

    do{
        printf("\n Press 1 to Insert ");
        printf("\n Press 2 for Preorder ");
        printf("\n Press 3 for Inorder ");
        printf("\n Press 4 for Postorder ");
        printf("\n Enter your Choice \t");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1: printf("Enter the value to insert ");
                scanf("%d",&n);
                Insert(&root,n);
        break;

        case 2: printf("Preorder: ");
                Preorder(root);
        break;

        case 3: printf("Inorder: ");
                Inorder(root);
        break;

        case 4: printf("Postorder: ");
                Postorder(root);
        break;
        
        default: printf("Invalid Choice");
            break;
        }
    } while(ch<=4);
}


void push(BST* t)
{
    if(top == SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stk[top] = t;
}

BST* pop()
{
    BST* t;

    if(top == -1)
    {
        printf("Stack Underflow\n");
        return NULL;
    }
    t = stk[top];
    top--;
    return t;
}


//Insert and Traversal function Without Recursion
void Insert(BST* *RT, int n)
{
    BST *p,*c,*t = NULL;

    t = (BST *)malloc(sizeof(BST));
    t->data = n;
    t->left = NULL;
    t->right = NULL;

    if(*RT == NULL)
    {        
        *RT = t;
        return;
    }

    p = c = *RT;

    while(c!=NULL)
    {
        if(c->data > n)
        {
            p = c;
            c = p->left;
        }
        else if(c->data < n)
        {
            p = c;
            c = p->right;
        }
        else{
            free(t);
            return;
        }
    }

    if(p->data > n)
    {
        p->left = t;
    }
    else{
        p->right = t;
    }
}


void Preorder(BST *root)
{
   BST *z = root;

   while(1)
   {
      while(z != NULL)
      {
        if(z -> right != NULL)
        {
            push(z -> right);
        }
        printf("%d ", z -> data);
        z = z-> left;
      }

   if(top == -1)
   {
      break;
   }
    z = pop();
   }
}


void Inorder(BST *root)
{
    BST *z = root;

    while(1)
    {
        while(z != NULL)
        {
            push(z);
            z = z -> left;
        }
        if(top == -1)
        {
            break;
        }
        z = pop();
        printf("%d ", z -> data);
        z = z -> right;
    }
}


void Postorder(BST* root) {
    BST* z = root;
    BST* lastVisited = NULL;

    while (top != -1 || z != NULL) {
        if (z != NULL) 
        {
            push(z);
            z = z->left;
        } 
        else 
        {
            BST* peekNode = stk[top];
            if (peekNode->right != NULL && lastVisited != peekNode->right) 
            {
                  z = peekNode->right;
            } 
            else 
            {
                printf("%d ", peekNode->data);
                lastVisited = pop();
            }
        }
    }
}
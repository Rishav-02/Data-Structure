#include<stdio.h>
#include<stdlib.h>

struct BST
{
    struct BST *left;
    int data;
    struct BST *right;
} typedef BST;

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

        case 2: Preorder(root);
        break;

        case 3: Inorder(root);
        break;

        case 4: Postorder(root);
        break;
        
        default: printf("Invalid Choice");
            break;
        }
    } while(ch<=4);
}


//Insert function Without Recursion
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
    if(root != NULL)
    {
        printf("%d ",root->data);
        Preorder(root -> left);
        Preorder(root -> right);
    }
}

void Inorder(BST *root)
{
    if(root != NULL)
    {
        Inorder(root -> left);
        printf("%d ",root->data);
        Inorder(root -> right);
    }
}

void Postorder(BST *root)
{
    if(root != NULL)
    {
        Postorder(root -> left);
        Postorder(root -> right);
        printf("%d ",root->data);
    }
}
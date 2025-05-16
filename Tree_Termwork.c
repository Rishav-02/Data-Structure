#include<stdio.h>
#include<stdlib.h>

struct BST
{
    struct BST *left;
    int data;
    struct BST *right;
} typedef BST;

//Function Declaration
void Insert(BST**,int);
void Preorder(BST*);
void Inorder(BST*);
void Postorder(BST*);
void CountTotalNodes(BST*,int*);
void CountLeafNodes(BST*,int*);
void CountOneChild(BST*,int*);
void CountLeftChild(BST*,int*);


int main()
{
    BST *root = NULL;
    int ch,v;
    int p = 0, ln = 0 , oc = 0, lc = 0;

    do{
        printf("\n Press 1 to Insert ");
        printf("\n Press 2 for Preorder ");
        printf("\n Press 3 for Inorder ");
        printf("\n Press 4 for Postorder ");
        printf("\n Press 5 to Count Total Nodes ");
        printf("\n Press 6 to Count Total Leaf Nodes ");
        printf("\n Press 7 to Count Node which have Only One Child Node ");
        printf("\n Press 8 to Count Node which have Only Left Child Node ");
        printf("\n Enter your Choice \t");
        scanf("%d",&ch);


        switch (ch)
        {
        case 1: printf("Enter the value to insert ");
                scanf("%d",&v);
                Insert(&root,v);
        break;

        case 2: Preorder(root);
        break;

        case 3: Inorder(root);
        break;

        case 4: Postorder(root);
        break;

        case 5: CountTotalNodes(root,&p);
        printf("\nTotal no. of node is %d\n", p);
        break;

        case 6: CountLeafNodes(root,&ln);
        printf("\nTotal no. of Leaf node is %d\n", ln);
        break;
        
        case 7: CountOneChild(root,&oc);
        printf("\nTotal no. of Nodes having only one child %d\n",oc);
        break;

        case 8: CountLeftChild(root,&lc);
        printf("\nTotal no. of Nodes having only left child is %d\n",lc);
        break;
        
        default: printf("Invalid Choice");
            break;
        }
    } while(ch<=8);
}

//Function Defination

void Insert(BST **RT,int v)
{
    BST *p = NULL;

    if(*RT == NULL)
    {
        p = (BST*)malloc(sizeof(BST));
        p->data = v;
        p->left = NULL;
        p->right = NULL;
        *RT = p;
        return;
    }

    else if(v < (*RT)->data)
    {
        Insert(&((*RT)->left),v);
    }

    else if (v > (*RT)->data)
    {
        Insert(&((*RT)->right),v);
    }

    else
    printf("\nElement already present");
    
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

void CountTotalNodes(BST *root,int *p)
{
    if(root != NULL)
    {
        (*p)++;
        CountTotalNodes(root -> left,p);
        CountTotalNodes(root -> right,p);
    }
}

void CountLeafNodes(BST *root,int *ln)
{
    if(root != NULL)
    {

       if(root -> right == NULL && root -> left == NULL)
      {
        (*ln)++;
      }
        CountLeafNodes(root -> left,ln);
        CountLeafNodes(root -> right,ln);
    }
}

void CountOneChild(BST *root,int *oc)
{
    if(root != NULL)
    {
        if(root -> left != NULL && root -> right == NULL)
        {
            (*oc)++;
        }
        else if(root -> left == NULL && root -> right != NULL)
        {
            (*oc)++;
        }
        CountOneChild(root -> left, oc);
        CountOneChild(root -> right, oc);
    }
}

void CountLeftChild(BST* root,int *lc)
{
    if(root != NULL)
    {
        if(root -> left != NULL && root -> right == NULL)
        {
            (*lc)++;
        }

        CountLeftChild(root -> left,lc);
        CountLeftChild(root -> right,lc);
    }
}
//Implement Binary Search Tree(BST) using Double pointer(call by reference)

#include<stdio.h>
#include<stdlib.h>

struct BST
{
    struct BST *left;
    int data;
    struct BST *right;
} typedef BST;

void Create(BST**,int);//Create and Insert
void Preorder(BST*);
void Inorder(BST*);
void Postorder(BST*);
BST* Delete(BST*,int v);
BST* Search(BST*, int v);


int main()
{
    BST *root = NULL;
    int ch,v;

    do{
        printf("\n Press 1 to insert ");
        printf("\n Press 2 for Preorder ");
        printf("\n Press 3 for Inorder ");
        printf("\n Press 4 for Postorder ");
        printf("\n Press 5 to Delete ");
        printf("\n Press 6 to Search ");

        printf("\n Enter your Choice \t");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1: printf("Enter the value to insert ");
                scanf("%d",&v);
                Create(&root,v);
        break;

        case 2: Preorder(root);
        break;

        case 3: Inorder(root);
        break;

        case 4: Postorder(root);
        break;

        case 5:  
        printf("Enter value to delete: ");
        scanf("%d", &v);
        root = Delete(root,v);
        printf("\n Deleted Node is %d\n",v);
        break;

        case 6: 
        printf("Enter value to Search: ");
        scanf("%d",&v);
        BST* p = Search(root,v);
        if(p)
         printf("Node %d is Found\n", p -> data);
        else
         printf("Node %d not Found in BST\n", v);
        break;

        default: printf("Invalid Choice");
        break;
        }
    } while(ch<=8);
}

//With Recursion
void Create(BST* *RT,int v)
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
        Create(&((*RT)->left),v);
    }

    else if (v > (*RT)->data)
    {
        Create(&((*RT)->right),v);
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

//Without Recursion
BST* Delete(BST* root,int v)
{
    BST *p = NULL, *t = NULL, *x = NULL, *c = NULL;
    p = root, x = root;

    //Data of node is equal to value that we want to delete
    if(root -> data == v)
    {
        //Only One Node Present
         if(root -> left == NULL && root -> right == NULL)
         {
            free(root);
            return NULL;
         }

        // Only Left Child of a Node Present
         else if(root -> left != NULL && root -> right == NULL)
         {
            root = root -> left;
            free(p);
            return root;
         }

        // Right Child Present but Left Child may or may not present
         else
         {
            p = p -> right;
            t = p;

            while(p -> left != NULL)
            {
                p = p -> left;
            }

            p -> left = root -> left;
            root = root -> right;
            free(p);
            return root;
         }
    }

    else
    {
        //Data of Node not equal to value that we want to delete
         while(x -> data != v)
         {
            p = x;
            x = (x -> data > v) ? x -> left : x -> right;

            if(x == NULL)
            {
                printf("Value not Found");
                return root;
            }
         }

        //Left and Right Child of Node not present
         if(x -> right == NULL && x -> left == NULL)
         {
            if(p -> data > x -> data)
               p -> left = NULL;
            else
               p -> right = NULL;

               free(x);
               return root;
         }

        //Left child present but right child not present
         else if(x -> left != NULL && x -> right == NULL)
         {
            if(p -> data > x -> data)
             p -> left = x -> left;
            else
             p -> right = x -> left;

             free(x);
             return root;
         }
         
        //Right Child present but Left child may or may not present
         else if(x -> right != NULL)
         {
            t = x -> right;
            c = t;

            while(c -> left != NULL)
            {
                c = c -> left;
            }

            c -> left = x -> left;

            if(p -> data > x -> data)
             p -> left = t;
            else
             p -> right = t;

             free(x);
             return root;
         }
    }
}


BST* Search(BST* root,int v)
{
    BST *c = NULL;
    // p = c = root;
    c = root;

    while(c != NULL)
    {
        if(c -> data == v)
        {
            // printf("Node %d is Found\n", c -> data);
            return c;       
        }

        else if(c -> data > v)
        {
            // p = c ;
            c = c -> left;
        }
        else
        {
            // p = c;
            c = c -> right;
        }
    }
    // printf("Node %d is not Found in the BST\n",v);
    return NULL;

}
//Implement Binary Search Tree(BST) using Single pointer(call by value) and Count Nodes of Tree

#include<stdio.h>
#include<stdlib.h>

struct BST
{
    struct BST *left;
    int data;
    struct BST *right;
} typedef BST;

//function declaration
void Create(BST**,int);
void Count(BST*,int*);
void CountLeafNodes(BST*,int*);
void CountLeftChild(BST*,int*);
void CountRightChild(BST*,int*);
void CountBothChild(BST*,int*);
void CountRightNodes(BST*,int*);
void CountLeftNodes(BST*,int*);
void LargestNode(BST*);
void SmallestNode(BST*);
void CountOneChild(BST*,int*);
BST* InorderSuccessor(BST*,int);
BST* InorderPredecessor(BST*,int);
BST* Delete(BST*,int);
void FindParent(BST*,int);
void Inorder(BST*);

int main()
{
    BST *root = NULL;
    int ch,v;
    int p=0,ln=0,lc=0,rc=0,bc=0,rn=0,ltn=0,oc=0;

    do{
        printf("\n Press 1 to insert ");
        printf("\n Press 2 to Count ");
        printf("\n Press 3 to Count Leaf Node ");
        printf("\n Press 4 to Count Left Child Node ");
        printf("\n Press 5 to Count Right Child Node ");
        printf("\n Press 6 to Count Both Child Node ");
        printf("\n Press 7 to Count Right Node ");
        printf("\n Press 8 to Count Left Node ");
        printf("\n Press 9 to Count Largest Node ");
        printf("\n Press 10 to Count Smallest Node ");
        printf("\n Press 11 to Count Only One Child Node ");
        printf("\n Press 12 for Inorder Successor of Node ");
        printf("\n Press 13 for Inorder Predecessor of Node ");
        printf("\n Press 14 for Delete the Node ");
        printf("\n Press 15 to Find Parent of Node ");
        printf("\n Press 16 to Display Inorder ");
        
        printf("\n Enter your Choice \t");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1: printf("Enter the value to insert ");
                scanf("%d",&v);
                Create(&root,v);
        break;

        //Think of passing a value (like p) as handing someone a photocopy. If they write on it, it doesn’t change your original.
        //But passing the address is like giving them the actual notebook — now if they write in it, your copy shows the change.
//               Concept	                     Reason
//         Pass (p) by value	         Makes a copy — no change in main()
//         Pass (&p) (address)	         Allows Count() to modify the original value in main()
//         Use *p in function	         Dereference the pointer to access or modify the value
        case 2: 
        Count(root,&p);//You are sending the address of p, say 0x100, to the function define below.
        printf("\nTotal no. of node is %d\n", p);
        break;

        case 3: CountLeafNodes(root,&ln);
        printf("\nTotal no. of Leaf node is %d\n", ln);
        break;

        case 4: CountLeftChild(root,&lc);
        printf("\nTotal no. of Nodes having only left child is %d\n",lc);
        break;

        case 5: CountRightChild(root,&rc);
        printf("\nTotal no. of Nodes having only right child is %d\n",rc);
        break;

        case 6: CountBothChild(root,&bc);
        printf("\nTotal no. of Nodes having both the child is %d\n",bc);
        break;

        case 7: CountRightNodes(root -> right,&rn);
        printf("\nTotal no. of Nodes in the right hand side of root node %d\n",rn);
        break;

        case 8: CountLeftNodes(root -> left,&ltn);
        printf("\nTotal no. of Nodes in the left hand side of root node %d\n",ltn);
        break;

        case 9: LargestNode(root);
        break;

        case 10: SmallestNode(root);
        break;

        case 11: CountOneChild(root,&oc);
        printf("\nTotal no. of Nodes having only one child %d\n",oc);
        break;

        case 12:
        printf("\nEnter value to find Inorder Successor: ");
        scanf("%d", &v);
        BST* p = InorderSuccessor(root, v);
        if (p)
        printf("\nInorder Successor of %d is %d\n", v, p->data);
        else
        printf("Inorder Successor of %d does not exist.\n", v);
        break;

        case 13:
        printf("\nEnter value to find Inorder Predecessor: ");
        scanf("%d", &v);
        
            BST* c = InorderPredecessor(root, v);
            if (p)
                printf("\nInorder Predecessor of %d is %d\n", v, c->data);
            else
                printf("Inorder Predecessor of %d does not exist", v);
        break;

        case 14:
        printf("\nEnter value to delete: ");
        scanf("%d", &v);
        root = Delete(root, v);
        printf("\n Deleted Node is %d\n",v);
        break;

        case 15:
        printf("\nEnter value to find parent: ");
        scanf("%d", &v);
        FindParent(root, v);
        break;

        case 16: Inorder(root);
        break;
        
        default: printf("Invalid Choice");
        break;
        }
    } while(ch<=17);
}


//All function defination

void Create(BST **RT,int v)
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

void Count(BST *root,int *p)//*p means: "go to address 0x100 and use the actual value there."
{
    if(root != NULL)
    {
        (*p)++;//It increments the real value at that memory location, which is the original p in main().
        Count(root -> left,p);
        Count(root -> right,p);
    }
}

//We can also pass address using single pointer
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

void CountRightChild(BST* root,int *rc)
{
    if(root != NULL)
    {
        if(root -> left == NULL && root -> right != NULL)
        {
            (*rc)++;
        }
        CountRightChild(root -> left, rc);
        CountRightChild(root -> right, rc);
    }
}

//Common Parent or Having both Children
void CountBothChild(BST *root,int *bc)
{
    if(root != NULL)
    {
        if(root -> left != NULL && root -> right != NULL)
        {
            (*bc)++;
        }
        CountBothChild(root -> left, bc);
        CountBothChild(root -> right, bc);
    }
}

void CountRightNodes(BST *root,int *rn)
{ 
    if(root != NULL)
    {
        (*rn)++;
        CountRightNodes(root -> left,rn);
        CountRightNodes(root -> right,rn);
    }
}

void CountLeftNodes(BST *root,int *ltn)
{
    if(root != NULL)
    {
        (*ltn)++;
        CountLeftNodes(root -> left,ltn);
        CountLeftNodes(root -> right,ltn);
    }
}

void LargestNode(BST *root)
{
    if(root != NULL)
    {
        while (root -> right != NULL)
        {
            root = root -> right;
        }

        printf("\nLargest node in BST is %d\n", root -> data);
    }
}

void SmallestNode(BST *root)
{
    if(root != NULL)
    {
        while (root -> left != NULL)
        {
            root = root -> left;
        }

        printf("\n Smallest node in BST is %d\n", root -> data);
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

BST* InorderSuccessor(BST *root, int val)
{
    BST *p = NULL,*t = NULL,*c = NULL;
    c = root;

    while (c != NULL)
    {
        if (val < c->data)
        {
            p = c;
            c = c->left;
        }
        else if (val > c->data)
        {
            c = c->right;
        }
        else
        {
            // Node with value `val` found
            if (c->right != NULL)
            {
                // Find the minimum in the right subtree
                t = c->right;
                while (t->left != NULL)
                {
                    t = t->left;
                }
                p = t;
            }
            break;
        }
    }

    return p;
}

BST* InorderPredecessor(BST* root, int val) 
{
    BST *p = NULL, *t = NULL, *c = NULL;
    p = root;

    while (p != NULL) 
    {
        if (val > p->data) 
        {
            c = p;
            p = p->right;
        } 
        else if (val < p->data) 
        {
            p = p->left;
        } 
        else 
        {
            if (p->left != NULL) 
            {
                // Find the minimum in the left subtree
                t = p->left;
                while (t->right != NULL)
                {
                    t = t->right;
                }
                c = t;
            }
            break;
        }
    }

    return c;
}

//Using Recursion
BST* Delete(BST* root, int val) {
    BST *p = NULL,*t = NULL;
    p = root;

    if (root == NULL) {
        printf("Value not found in tree.\n");
        return NULL;
    }

    if (val < root->data) {
        root->left = Delete(root->left, val);
    }
    else if (val > root->data) {
        root->right = Delete(root->right, val);
    }
    else {
        // Node to delete found

        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: One child
        else if (root->left == NULL) {
            root = root->right;
            free(p);
            return root;
        }
        else if (root->right == NULL) {
            root = root->left;
            free(p);
            return root;
        }

        // Case 3: Two children
        else {
            // Get inorder successor (minimum in right subtree)
            p = p->right;
            while (p->left != NULL)
                p = p->left;

            // Replace data and delete p
            root->data = p->data;
            root->right = Delete(root->right, p->data);
        }
    }

    return root;
}


void FindParent(BST *root, int val) {
    BST *p = NULL, *c = NULL;
    c = root;

    while (c != NULL) {
        if (val == c->data)
            break;

        p = c;

        if (val < c->data)
            c = c->left;
        else
            c = c->right;
    }

    if (c == NULL) {
        printf("Value %d not found in the tree.\n", val);
    } else if (p == NULL) {
        printf("The node %d is the root node and has no parent.\n", val);
    } else {
        printf("Parent of node %d is %d.\n", val, p->data);
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
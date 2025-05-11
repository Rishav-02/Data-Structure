//Circular Queue Implementation by Array(call by value)
#include<stdio.h>

#define MAX 10
//function declaration
int CQEnq(int[],int,int);
int CQDeq(int[],int,int);
void CQDisplay(int[],int,int);
void CQPeek(int[],int);

void main()
{
    int CQ[MAX],F=-1,R=-1,ch;

    do{
        printf("\n Press 1 to Enqueue ");
        printf("\n Press 2 to Dequeue ");
        printf("\n Press 3 to Display");
        printf("\n Press 4 to Peek ");
        printf("\n Enter Your Choice \t ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: R = CQEnq(CQ,F,R);
                    if(F==-1)
                    F=0;
                break;

            case 2: F = CQDeq(CQ,F,R);
                    if(F==-1)
                    R=-1;
                break;
            
            case 3: CQDisplay(CQ,F,R);
                break;

            case 4: CQPeek(CQ,F);
                break;

            default: printf("\nInvalid Choice");
        }
    } while(ch<=4);
}


int CQEnq(int CQ[],int F,int R)
{
    int x;
    if(((R+1) % MAX) == F)
    {
        printf("\n Queue is Full(OverFlow)");
    }
    else{
        printf("\nEnter the value to insert: ");
        scanf("%d",&x);

        R = (R+1) % MAX;
        CQ[R] = x;
    }
    return R;
}

int CQDeq(int CQ[],int F,int R)
{
    if(F==-1)
    {
        printf("\n Queue is Empty(UnderFlow)");
    }
    else{
        printf(" \t %d ",CQ[F]);
        if(F == R)
        {
            F = -1;
        }        
        F=(F+1) % MAX;
    }
    return F;
}

void CQDisplay(int CQ[],int F,int R)
{
    if(F==-1)
    printf("\n Queue is Empty");
    else{
        while (F!=R)
        {
            printf("\t %d",CQ[F]);
            F=(F+1)%MAX;
        }
        printf("\t %d",CQ[F]);
        
    }
}

void CQPeek(int CQ[],int F)
{
    if(F==-1)
    printf("\n Queue is Empty");
    else{
        printf("\t%d",CQ[F]);
    }
}
// Circular Queue Implementation by Array(call by reference)
#include<stdio.h>

#define MAX 10

void CQEnq(int [],int *,int *);
void CQDeq(int [],int *,int *);
void CQDisplay(int [],int,int);
void CQPeek(int [],int);

void main()
{
    int CQ[MAX],F=-1,R=-1,ch;

    do{
        printf("\n Press 1 to Enqueue ");
        printf("\n Press 2 to Dequeue ");
        printf("\n Press 3 to Display ");
        printf("\n Press 4 to Peek ");
        printf("\n Enter Your Choice \t");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: CQEnq(CQ,&F,&R);
                    break;

            case 2: CQDeq(CQ,&F,&R);
                    break;

            case 3: CQDisplay(CQ,F,R);
                    break;
                
            case 4: CQPeek(CQ,F);
                    break;

            default: printf("\n Invalid Choice");
        }
    } while(ch<=4);
}

void CQEnq(int CQ[],int *F,int *R)
{
    int x;
    if((*R+1) % MAX == *F){
        printf("\n Queue is Full(OverFlow)");
    }
    else{
        printf("\n Enter the value to insert: ");
        scanf("%d",&x);

        *R = (*R+1) % MAX;
        CQ[*R] = x;

        if(*F == -1)
        *F = 0;
    }
}

void CQDeq(int CQ[],int *F,int *R)
{
    if(*F == -1){
    printf("\n Queue is Empty(UnderFlow)");
    }
    else{
        printf("\t%d",CQ[*F]);
        if(*F == *R)
        {
            *F = -1;
            *R = -1;
        }
        else{
            *F = (*F+1) % MAX;
        }

    }
}

void CQDisplay(int CQ[],int F,int R)
{
    if(F == -1)
    printf("\n Queue is Empty");
    else{
        while(F != R)
        {
            printf("\t%d",CQ[F]);
            F = (F+1) % MAX;
        }
        printf("\t%d",CQ[F]);
    }
}

void CQPeek(int CQ[],int F)
{
    if(F == -1){
    printf("\n Queue is Empty");
    }
    else{
        printf("\t%d",CQ[F]);
    }
}

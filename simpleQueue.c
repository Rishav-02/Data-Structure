//Simple Queue Implementation by Array(call by value)
#include<stdio.h>
#define MAX 10

//function declaration
int SQEnq(int[],int);
int SQDeq(int[],int,int);
void disp(int[],int,int);
void peek(int[],int);

void main()
{
    int SQ[MAX],F=-1,R=-1,ch;

    do{
        printf("\n Press 1 to Enqueue ");
        printf("\n Press 2 to Dequeue ");
        printf("\n Press 3 to Display ");
        printf("\n Press 4 to Peek ");
        printf("\n Enter Your Choice \t");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1: R = SQEnq(SQ,R);
                if(F==-1)
                F=0;
            break;
            
        case 2: F = SQDeq(SQ,F,R);
                if(F==-1)
                R=-1;
            break;

        case 3: disp(SQ,F,R);
            break;

        case 4: peek(SQ,F);
            break;
        
        default: printf("\n Invalid Choice");
            break;
        }
        // printf("\n Press 0 to Continue...");
        // scanf("%d",&ch);
    } while (ch<=4);
}


int SQEnq(int SQ[],int R)
{
    int x;
    if(R == MAX - 1)
    printf("Queue is Full(OverFlow)");
    else{
        printf("\n Enter value to insert: ");
        scanf("%d",&x);
        R++;
        SQ[R] = x;
    }
    return R;
}

int SQDeq(int SQ[],int F,int R)
{
    int x;
    if(F==-1 && R==-1)
    printf("Queue is Empty(UnderFlow)");
    else{
        x = SQ[F];
        printf("\nDeleted Element is %d\n",x);

        if(F == R)
        F=-1;
        else 
        F++;
    }
    return F;
}

void disp(int SQ[],int F,int R)
{
    if(F==-1 && R==-1)
    printf("Queue is Empty");
    else{
        for(int i = F; i <= R; i++) {
           printf("\t %d", SQ[i]);
        }
    }
}

void peek(int SQ[],int F)
{
    if(F==-1)
    printf("Queue is Empty");
    else{
        printf("\t %d", SQ[F]);
    }
}
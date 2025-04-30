#include<stdio.h>
#include<string.h>

char stk[100];
int top = -1;

void push(char x)
{
    top++;
    stk[top] = x;
}

char pop()
{
    char x;
    x = stk[top];
    top--;
    return x;
}

int preced(char x)
{
    int p;
    
    switch(x)
    {
        case '^': p=5;
        break;

        case '/': p=4;
        break;

        case '*': p=3;
        break;

        case '+': p=2;
		break;

		case '-': p=1;
		break;

        case '(': p=0;
        break;

        case '#': p=-1;
        break;
    }
    return p;
}

int main()
{
    char infix[100],postfix[100],ch,sc;
    int i,k=0,l;

    printf("Enter infix expression ");
    gets(infix);
    l = strlen(infix);
    push('#');

    for(i=0;i<l;i++)
    {
        sc = infix[i];

        switch(sc)
        {
            case '(': push(sc);
            break;

            case ')': 
                    ch = pop();
                    while(ch!='(')
                  {
                       postfix[k] = ch;
                       k++;
                       ch = pop();
                  }
                  break;

            case '^':
            case '/':
            case '*':
            case '+':
            case '-':
                        while(preced(sc) <= preced(stk[top]))
                        {
                            postfix[k] = pop();
                            k++;
                        }
                        push(sc);
                        break;

            default: postfix[k++] = sc;
            break;
        }
    } 
    while(top > 0)
    {
        postfix[k] = pop();
        k++;
    }

    postfix[k] = '\0';
    printf("Postfix is ");
    puts(postfix);

    return 0;
}
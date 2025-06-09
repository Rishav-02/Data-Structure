//BFS with integer vertices using adjacency list
#include<stdio.h>
#include<stdlib.h>
#define max 10

typedef struct node{
    int dest ;
    struct node *next ;
}node ;

typedef struct graph{
    int numV;
    int visited[max];
    node* list[max];
}graph;

graph* addedge(graph* , int);
void display(graph*,int);
void BFS(graph* , int , int);

int queue[max] , front=0 , rear = 0 ;

void enqueue(int val)
{
    queue[rear++] = val ;
}

int dequeue()
{
  int val = queue[front++];
    return val ;
}

int isempty()
{
    return front==rear;
}

int main()
{
    int v , src , des, ch ;
    printf("\nEnter number of vertices\t");
    scanf("%d",&v);

    graph* g = NULL ;

    do{
       printf("\n1.Create Graph\n2.Display\n3.BFS\n");
       printf("Enter your Choice\t");
       scanf("%d",&ch);
       switch(ch)
       {
        case 1 : g = addedge(g,v);
                 break;
        case 2 : display(g,v);
                 break;
        case 3 : if(g==NULL)
                   printf("\nGraph is Empty\n");
                 else{
                    printf("Enter source and destination\n");
                    scanf("%d%d",&src,&des);
                    printf("\nBFS PATH\n");
                    BFS(g,src,des);
                 }
                 break;
       }
    }while(ch<=3 && ch>0);
}

graph* addedge(graph* g , int v)
{
    g = (graph*)malloc(sizeof(graph));
    if(g)
    {
        g->numV = v ;
        for(int i=0 ; i<v ; i++)
        {
            g->list[i] = NULL ;
            g->visited[i]=0 ;
        }
    }
    int src ;
    printf("\nEnter source (0 to %d) , destination (0 to %d) and (Enter -1 -1 for exiting)\n",v-1,v-1);
    node *newnode ;
    while(1)
    {
        newnode = (node*)malloc(sizeof(node));
        scanf("%d%d",&src,&newnode->dest);

        if(src == -1 || newnode->dest == -1)
         break ;

         newnode->next = g->list[src];
         g->list[src] = newnode ;
    }
    return g;
}

void display(graph *g , int v)
{
    if(g==NULL)
     printf("\nGraph is empty\n");
    else{
        for(int i=0 ; i<v ; i++)
        {
            printf("(vertex %d) : ",i);
            node *tmp = g->list[i];
            while(tmp)
            {
                printf(" %d -> ",tmp->dest);
                tmp = tmp->next;
            }
            printf("NULL\n");
        }
    }
}

void BFS(graph* g , int src , int des)
{
  for(int i=0 ; i<g->numV ; i++)
    g->visited[i]=0 ;

  front=rear = 0 ;
  enqueue(src);
  g->visited[src]=1 ;

  while(!isempty())
  {
    int current = dequeue();
    printf("%d ",current);

    if(des == current)
    {
        printf("Destination %d is reached",current);
        return ;
    }

    node *tmp = g->list[current];
    while(tmp)
    {
      if(!g->visited[tmp->dest])
      {
         enqueue(tmp->dest);
         g->visited[tmp->dest]=1 ;
      }
      tmp=tmp->next ;
    }
  }

  printf("\n No any Path\n");
}
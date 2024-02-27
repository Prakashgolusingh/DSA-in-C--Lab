
#include<stdio.h>
#include<stdlib.h>
struct graph
{
    int V;
    int E;
    int **matrix;
};
struct queue
{
    int size;
    int front;
    int rear;
    int *array;
};
void enqueue(struct queue*,int );
int dequeue(struct queue * );
void dfs(int ,struct graph *,int []);
int main()
{
    int u,v,i,j;
    struct graph *G=(struct graph*)malloc(sizeof(struct graph));
    printf("enter the value of vertex and edges");
    scanf("%d %d",&G->V,&G->E);
    G->matrix=(int **)malloc(sizeof(int*)*G->V);
   // printf("%d %d\n",G->V,G->E);
    for(i=0;i<G->V;i++)
    {
            G->matrix[i]=(int*)malloc(sizeof(int)*G->V);
    }
	 for(i=0;i<G->V;i++)
    {
        for(j=0;j<G->V;j++)
        {
            G->matrix[i][j]=0;
        }
    }
    for(i=0;i<G->E;i++)
    {
        scanf("%d %d",&u,&v);
        G->matrix[u][v]=1;
        G->matrix[v][u]=1;
    }
    int visited[G->V];
    for(i=0;i<G->V;i++)
    {
        visited[i]=1;
    }
    int dfsvisited[G->V];
    for(i=0;i<G->V;i++)
    {
        dfsvisited[i]=1;
    }
    struct queue Q;
    Q.size=0;
    Q.front=-1;
    Q.rear=-1;
    Q.array=(int *)malloc(sizeof(int)*G->V);
    scanf("%d",&u);
    visited[u]=2;
    printf("%d",u);
    enqueue(&Q,u);
    while(Q.size)
    {
        int node=dequeue(&Q);
        visited[node]=3;
        for(j=0;j<G->V;j++)
        {
            if(G->matrix[node][j]==1 && visited[j]==1)
            {
                visited[j]=2;
                printf(" %d",j);
                enqueue(&Q,j);
            }
        }
        node=dequeue(&Q);
        visited[node]=3;
    }
    printf("\n");
    dfs(u,G,dfsvisited);
}
void enqueue(struct queue*q,int a)
{
    q->rear++;
    q->array[q->rear]=a;
    q->size++;
}
int dequeue(struct queue *q)
{
    q->front++;
    q->size--;
    return q->array[q->front];
}
void dfs(int u,struct graph *g,int dfsvisited[])
{
    printf("%d ",u);
   /* for(int j=0;j<g->V;j++)
    {
        printf("%d",dfsvisited[j]);
    }*/
    dfsvisited[u]=2;
    for(int i=0;i<g->V;i++)
    {
        if(g->matrix[u][i]==1 && dfsvisited[i]==1)
            dfs(i,g,dfsvisited);
    }
}

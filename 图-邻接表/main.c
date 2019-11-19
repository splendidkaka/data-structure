#include <stdio.h>
#include <stdlib.h>
#define  MaxVerNum 100
int visited[MaxVerNum];
/***********边表**********/
typedef struct EdgeNode
{
	int adjvex;      //邻接点域
	struct EdgeNode *next;   //指向下一个邻接点的指针域
}EdgeNode;

/*********顶点表*********/
typedef struct
{
	int Vexs;     //顶点的信息
	EdgeNode *first;  //指向第一条边的指针
}VertexNode,AdjList[MaxVerNum];

/*********图结构********/
typedef struct
{
	AdjList adjlist;
	int n,e;  //顶点数和边数
}ALGraph;
/*创建队列用来广度遍历*/
typedef struct node
{
     int data;
     struct node *next;
}Qnode;
typedef struct
{
    Qnode *front,*rear;
}LQueue;
LQueue * creat()
{
    LQueue *q;
    Qnode *p;
    q=malloc(sizeof(LQueue));
    p=malloc(sizeof(Qnode));
    p->next=NULL;
    q->front=p;
    q->rear=p;
    return q;
}
void in_queue(LQueue *q,int x)
{
   Qnode *p;
   p=malloc(sizeof(Qnode));
   p->data=x;
   p->next=NULL;
   q->rear->next=p;     //要从队尾插入
   q->rear=p;
}
int empyt_(LQueue *q)
{
     if(q->rear==q->front)
     return 1;
     else
     return 0;
}
int out_queue(LQueue *q,int *x)
{
       Qnode *p;
           p=q->front->next;
           q->front->next=p->next;
           *x=p->data;
           free(p);
           if(q->front->next==NULL)
           q->rear=q->front;
           return 1;
}


/*********创建图********/
void create_ALGraph(ALGraph *G)
{
	int i, j;
	int a, b;     //相连接的两个顶点序号
	EdgeNode *s;    //边表结点
    s=malloc(sizeof(EdgeNode));
	printf("请输入顶点数和边数\n");
	scanf("%d,%d", &G->n, &G->e);

	printf("建立顶点表:\n");
	for (i = 0; i < G->n; i++)
	{
		getchar();  //吃掉\n
		printf("请输入第%d个顶点的信息:", i + 1);
		scanf("%d", &G->adjlist[i].Vexs);
		G->adjlist[i].first = NULL;
	}
	for (i = 0; i < G->e; i++)
	{
	    getchar();
		printf("请输入相连接的两个顶点下标:");
		scanf("%d%d",&a,&b );
		s = malloc(sizeof(EdgeNode));
		s->adjvex = b;    //边所指向结点的位置
		s->next = G->adjlist[a].first;
		G->adjlist[a].first = s;

		//输入(0 1)在1中也把0编入
		s = malloc(sizeof(EdgeNode));
		s->adjvex = a;    //边所指向结点的位置
		s->next = G->adjlist[b].first;
		G->adjlist[b].first = s;
	}
}

/***********打印边表*********/
/*void print_Graph(ALGraph *G)
{
	int i, j;
	for (i = 0; i < G->nodeNum; i++)
	{
		printf("%d->",i);
		while (1)
		{
			if (G->adjlist[i].edgenext == NULL)
			{
				printf("^");
				break;
			}
			printf("%d->", G->adjlist[i].edgenext->adjvex);
			G->adjlist[i].edgenext = G->adjlist[i].edgenext->next;
		}
		printf("\n");

	}
}
*/

void DFS(ALGraph  *G,int v)
{
	EdgeNode *p;
	p=malloc(sizeof(EdgeNode));
		visited[v] = 1;     //已经访问标记设为
		printf("%d  ", G->adjlist[v].Vexs);
		p = G->adjlist[v].first;   //p指向顶点v的第一条边
		while (p != NULL)
		{
			if (!visited[p->adjvex])
				DFS(G,p->adjvex);
			p = p->next;                   //找vi的下个邻接点
		}
}
void DFSTravel(ALGraph *G)
{
	int i;
	for (i = 0; i < G->n; i++)
		visited[i] = 0;            //开始全没有访问设为0
	for (i = 0; i < G->n; i++)
	{
		if (!visited[i])
			DFS(G, i);
	}
}

void BFS(ALGraph *G)
{
      int i;
      EdgeNode *p;LQueue *q;
      p=malloc(sizeof(EdgeNode));
      q=creat();   //创建队列
      for(i=0;i<G->n;i++)
      {
        visited[i]=0;
      }
      for(i=0;i<G->n;i++)
      {
        if(!visited[i])
        {
            visited[i]=1;
            printf("%d ",G->adjlist[i].Vexs);
            in_queue(q,i);
            while(!empyt_(q))
            {
                out_queue(q,&i);
                p=G->adjlist[i].first;
                while(p)
                {
                    if(!visited[p->adjvex])
                    {
                        visited[p->adjvex]=1;
                        printf("%d ",G->adjlist[p->adjvex].Vexs);
                        in_queue(q,p->adjvex);
                    }
                    p=p->next;
                }
            }
        }
      }
}

void main()
{
	ALGraph *G = malloc(sizeof(ALGraph));
	create_ALGraph(G);
	printf("\nDFS\n");
        DFSTravel(G);
        printf("\nBFS\n");
        BFS(G);
}

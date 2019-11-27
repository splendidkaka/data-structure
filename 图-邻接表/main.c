#include <stdio.h>
#include <stdlib.h>
#define  MaxVerNum 100
int visited[MaxVerNum];
/***********边表**********/
typedef struct EdgeNode
{
	int adjvex;      //邻接点域
	int weight;
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
	int i, j,we;
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
		scanf("%d,%d",&a,&b );
		s = malloc(sizeof(EdgeNode));
		printf("请输入相连接的两个顶点之间的权值:");
		getchar();
		scanf("%d",&we);
		s->adjvex = b;    //边所指向结点的位置
		s->next = G->adjlist[a].first;
		s->weight=we;
		G->adjlist[a].first = s;

		//输入(0 1)在1中也把0编入
		s = malloc(sizeof(EdgeNode));
		s->adjvex = a;    //边所指向结点的位置
		s->next = G->adjlist[b].first;
		s->weight=we;
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
		printf("%d  ", G->adjlist[v].Vexs);
		visited[v] = 1;     //已经访问标记设为
		p = G->adjlist[v].first;   //p指向顶点v的第一条边
		while (p)
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
int getWeight(ALGraph *G, int start, int end)
{
    EdgeNode *node;

    if (start==end)
        return 0;

    node = G->adjlist[start].first;
    while (node!=NULL)
    {
        if (end==node->adjvex)
            return node->weight;
        node = node->next;
    }

    return 65535;
}
void prim(ALGraph *G, int start)
{
    int min,i,j,k,m,n,sum,p;
    int index=0;
    char prims[MaxVerNum];
    int weights[MaxVerNum];

    prims[index++] = G->adjlist[start].Vexs;

    for (i = 0; i < G->n; i++ )
        weights[i] = getWeight(G,start,i);

    for (i = 0; i < G->n; i++)
    {
        if(start == i)
            continue;

        j = 0;
        k = 0;
        min = 65535;
        while (j < G->n)
        {
            if (weights[j] != 0 && weights[j] < min)
            {
                min = weights[j];
                k = j;
            }
            j++;
        }

        prims[index++] = G->adjlist[k].Vexs;
        weights[k] = 0;

        for (j = 0 ; j < G->n; j++)
        {
            p=getWeight(G,k,j);
            if (weights[j] != 0 && p<weights[j])
                weights[j] = p;
        }
    }


   /* sum = 0;
    for (i = 1; i < index; i++)
    {
        min = 65535;

        n = get_position(G, prims[i]);

        for (j = 0; j < i; j++)
        {
            m = get_position(G, prims[j]);
            if (G->weight[m][n]<min)
                min = G->weight[m][n];
        }
        sum += min;
    }

    printf("PRIM(%c)=%d: ", G->Vexs[start], sum);
    */
    for (i = 0; i < index; i++)
        printf("%d ", prims[i]);
    printf("\n");
}
void dijkstra(ALGraph *G, int vs, int prev[], int dist[])
{
    int i,j,k;
    int min;
    int tmp;
    int flag[MaxVerNum];

    for (i = 0; i < G->n; i++)
    {
        flag[i] = 0;
        prev[i] = 0;
        dist[i] = getWeight(G, vs, i);
    }


    flag[vs] = 1;
    dist[vs] = 0;


    for (i = 1; i < G->n; i++)
    {

        min = 65535;
        for (j = 0; j < G->n; j++)
        {
            if (flag[j]==0 && dist[j]<min)
            {
                min = dist[j];
                k = j;
            }
        }

        flag[k] = 1;


        for (j = 0; j < G->n; j++)
        {
            tmp = getWeight(G, k, j);
            tmp = (tmp==65535 ? 65535 : (min + tmp));
            if (flag[j] == 0 && (tmp  < dist[j]) )
            {
                dist[j] = tmp;
                prev[j] = k;
            }
        }
    }

    printf("dijkstra(%d): \n", G->adjlist[vs].Vexs);
    for (i = 0; i < G->n; i++)
        printf("  shortest(%D, %D)=%d\n", G->adjlist[vs].Vexs, G->adjlist[i].Vexs, dist[i]);
}
void main()
{
    int prev[MaxVerNum] = {0};
    int dist[MaxVerNum] = {0};
    EdgeNode *node;
	ALGraph *G = malloc(sizeof(ALGraph));
	create_ALGraph(G);
	printf("\nDFS\n");
        DFSTravel(G);
        printf("\nBFS\n");
        BFS(G);
        printf("\nprim");
        prim(G,0);
        dijkstra(G, 3, prev, dist);
}





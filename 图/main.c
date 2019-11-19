#include <stdio.h>
#include <stdlib.h>
#define MaxVNum 100
#define TRUE 1
#define FALSE 0
int visited[MaxVNum];
typedef struct
{
    int n,e;     //分别为顶点和边数
    char  Vexs[MaxVNum];   //顶点表
    int edges[MaxVNum][MaxVNum];   //邻接矩阵
    int weight[MaxVNum][MaxVNum];  //权值
}MGraph;
/*要利用队列去进行遍历 */
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
/*无向图邻接矩阵的建立*/
void CreatMGraph(MGraph *G)
{
    int i,j,k;
    char ch;
    printf("请输入顶点数和边数\n");
    scanf("%d,%d",&(G->n),&(G->e));
    printf("请输入顶点信息\n");
    //getchar();  //吃\n
    for(i=0;i<G->n;i++)
    {
        getchar();
        scanf("%c",&(G->Vexs[i]));       /*输入顶点信息*/
    }
    for(i=0;i<G->n;i++)
    {
      for(j=0;j<G->n;j++)
      {
        G->edges[i][j]=0;                /*初始化邻接矩阵*/
      }
    }
    printf("请输入每条边对应的2个顶点的序号\n");
    for(k=0;k<G->e;k++)
    {   getchar();
        scanf("%d,%d",&i,&j);
        G->edges[i][j]=G->edges[j][i]=1;//如需建有向图只需 G->edges[i][j]==1
        //getchar();
        //scanf("%d",&(G->weight[i][j]));
        G->weight[i][j]=G->weight[j][i]=10;
    }
    printf("建立完成\n");
}
int search(MGraph *G,char vn)           /*得到当前的顶点在顶点表的下标*/
{
    int i;
    for(i=0;i<G->n;i++)
    if(G->Vexs[i]==vn)
    return i;
}



/*邻接矩阵的广度优先遍历*/
void BFS(MGraph *G)
{
     int i,j;
     LQueue *q;
     q=creat(); /*创建队列*/
     //ch=G->Vexs[index];
    for(i=0;i<G->n;i++)
      visited[i]=FALSE;
    // in_queue(q,index);    /*将该点入列*/
     //visited[index]=TRUE;  /*即将访问将其visted设为1*/
     for(i=0;i<G->n;i++)
  {
    if(!visited[i])
    {
        visited[i]=TRUE;
        printf("%c",G->Vexs[i]);
        in_queue(q,i);
    }
    while(!empyt_(q))
     {
        out_queue(q,&i);
        //i=search(G,ch);
		for (j = 0; j < G->n; j++)
		{
			if (G->edges[i][j]==1 && !visited[j])
			{
				printf("%c",G->Vexs[j]);	
				in_queue(q,j);		
				visited[j] = TRUE;		
			}
		}
      }
     }
}
void BFS_1(MGraph *G)
{
    int i;
    for(i=0;i<G->n;i++)
     visited[i]=FALSE;   //将visted全部设为false
    for(i=0;i<G->n;i++)
    {
        if(!visited[i])
        BFS(G);
    }
}
void DFS(MGraph *G, int v)
{
	int i;
	printf("%c ", G->Vexs[v]);
	visited[v] = TRUE;
	for (i = 0; i < G->n; i++)
		if (G->edges[v][i]==1&&!visited[i])
			DFS(G,i);
}
void DFS_1(MGraph *G)
{
    int i;
    for(i=0;i<G->n;i++)
     visited[i]=FALSE;   //将visted全部设为false
    for(i=0;i<G->n;i++)
    {
        if(!visited[i])
        DFS(G,i);
    }
}
void minispanTree_prim(MGraph *G) {
	//adjvex表示最小权值边的起始顶点，j表示结束顶点
	int min, i, j, k;//会用到的变量
	int adjvex[MaxVNum];//用来存放边的其中一个顶点
	int lowcost[MaxVNum];//用来存放当前已经连通部分的最小权值(对应于adjvex中的顶点)
	lowcost[0] = 0;//初始化第一个数值为0，表示第一个顶点已经加入最小生成树
	adjvex[0] = 0;//第一个顶点下标
	for (i = 1; i < G->n; i++) {
		lowcost[i] = G->weight[0][i];
		adjvex[i] = 0;//一开始最小生成树的顶点只有0
	}
	//初始化完成，接下来开始生成最小生成树
	for (i = 1; i < G->n; i++) {
		//这里表示有n个顶点要弄出n-1条边(包括v0有n个顶点)
		min = 65535;//初始化最小值为无穷
		j = 1;
		k = 0;//k用于存放当前权值最小边的其中一个下标
		while (j < G->n) {
			//循环出了第一个外的全部顶点
			if (lowcost[j] != 0 && lowcost[j] < min) {
				//寻找没有完成（不为0），并且是最小的顶点的下标
				//也就是在可接触的最小权值边(lowcost)中选一个最小的
				min = lowcost[j];
				k = j;
			}
			j++;
		}
		//此时，k存放的就是当前可以接触到的最小权值边的一个顶点
		//adjvex[k]记录的是当前所能接触到的最小权值边的另一个顶点
		printf("（%d,%d）\n", adjvex[k], k);
		lowcost[k] = 0;//表示这个顶点已经加入到最小生成树中
		//接下来要寻找新的可以接触到的最小权值边
		for (j = 1; j < G->n; j++) {
			if (lowcost[j] != 0 && G->weight[k][j] < lowcost[j]) {
				//k表示新的最小生成树顶点，可以通过它来寻找最小权值边
				lowcost[j] = G->weight[k][j];
				adjvex[j] = k;//找到了之后要把其中一个顶点改为k,表示到k的最小权值边
			}
		}
	}
}
//typedef int Pathmatirx1[MaxVNum];
//typedef int ShortPathTable1[MaxVNum];
void ShortestPath_Dijkstra(MGraph *G, int v0, int *P, int *D) {
	int v, w, k, min;
	int final[MaxVNum];
	for (v = 0; v < G->n; v++) {
		final[v] = 0;
		D[v] = G->weight[v0][v];
		P[v] = 0;			
	}

	D[v0] = 0;
	final[v0] = 1;
	for (v = 1; v < G->n; v++) {
		min =65535;
		for (w = 0; w < G->n; w++) {
			if (final[w] == 0 && D[w] < min) {
				k = w;
				min = D[w];
			}
		}
		final[k] = 1;
		for (w = 0; w < G->n; w++) {
			if (final[w] == 0 && (min + G->weight[k][w]) < D[w]) {
				D[w] = min + G->weight[k][w];
				P[w] = k;				
			}
		}
	}
	printf("len:\n");
	for (v = 1; v < G->n; v++) {
		printf("(%d,%d)\n", P[v], v);
	}
}
void Dijkatra(MGraph *G,int s)
{
    int path[MaxVNum];    //是数组下标表示的顶点所经历的前一个顶点
    int dist[MaxVNum];    //是数组下标表示的顶点的最小权值路径和
    //上面两个数组都有作用,和无权最短路径一致，但是无权最短路径可以使用dist是否被设置来判断一个顶点是否被访问，
    //但是这里无法使用，因为dist和普里姆算法中的lowcost一样，是使用贪心算法时，每到一个顶点，我们都会全部更新dist
    //所以我们需要另外一个数组来标志各个顶点是否被访问
    int final[MaxVNum];
    int i,j,k,min;

    //对数据进行初始化
    for (i = 0; i < G->n;i++)
    {
        final[i] = 0;    //0表示该数组下标所表示的顶点未被访问
        path[i] = 0;    //初始化路径数组为0，表示当前每个都是独立的根节点
        dist[i] = G->weight[s][i];    //这一步是重点：初始化路径数组的值为起始v0到各个点的权值
    }
    dist[s] = 0;    //到源点自己的路径为0
    path[s] = s;    //设置源点的前一个顶点就是自己
    final[s] = 1;    //源点被访问过了

    //开始主循环，每次求的v0（s）到某个v顶点的最短路径
    for (i = 0; i < G->n;i++)
    {
        min = 65535;    //和普里姆算法相似
        for (j = 0; j < G->n;j++)    //由于是有向图所以都要从0开始，找到他的每个邻接点
        {
            if (!final[j]&&dist[j]<min)    //若是该顶点没有被访问过，且该点到s点的距离小于min,我们就将min设置为他
            {
                k = j;    //记录下该v到s点的下标和min最小路径
                min = dist[j];
            }
        }

        final[k] = 1;    //将目前找到的距离v0(S)最近的顶点置为1

        for (j = 0; j < G->n;j++)    //修正当前最短路径即距离
        {
            //修正方法就是循环k的每个邻接点,我们作为三角形来看，若是两边之和小于第三边，那我们原来找的那条直接的最短边就失效了，用这两条直接代替
            //所以我们将距离修改，路径设置为他的上一步k,
            if (!final[j]&&(min+G->weight[k][j])<dist[j])
            {
                //说明找到了更短的路径，修改dist和path数组
                dist[j] = min + G->weight[k][j];    //修改当前路径长度
                path[j] = k;
            }
        }
    }

    for (i = 0; i<G->n; i++)
    {
        printf("%d %c-%c\n", dist[i], G->Vexs[path[i]], G->Vexs[i]);
    }
}
main()
{
     int *P;
	 int *D;
	
   MGraph *G;
   G=(MGraph *)malloc(sizeof(MGraph));
   P = (int *)malloc(sizeof(MaxVNum * MaxVNum));
	D = (int *)malloc(sizeof(MaxVNum * MaxVNum));
   CreatMGraph(G);
    printf("广度\n");
     BFS(G);
    printf("\n深度\n");
     DFS_1(G);
     minispanTree_prim(G);

     Dijkatra(G,0);
	//ShortestPath_Dijkstra(G, 0, P, D);
}

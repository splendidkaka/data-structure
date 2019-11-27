#include <stdio.h>
#include <stdlib.h>
#define MaxVNum 100
#define TRUE 1
#define FALSE 0
int visited[MaxVNum];
typedef struct
{
    int n,e;     //�ֱ�Ϊ����ͱ���
    char  Vexs[MaxVNum];   //�����
    int edges[MaxVNum][MaxVNum];   //�ڽӾ���
    int weight[MaxVNum][MaxVNum];  //Ȩֵ
}MGraph;
/*Ҫ���ö���ȥ���б��� */
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
   q->rear->next=p;     //Ҫ�Ӷ�β����
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
/*����ͼ�ڽӾ���Ľ���*/
void CreatMGraph(MGraph *G)
{
    int i,j,k,we;
    char ch;
    printf("�����붥�����ͱ���\n");
    scanf("%d,%d",&(G->n),&(G->e));
    printf("�����붥����Ϣ\n");
    //getchar();  //��\n
    for(i=0;i<G->n;i++)
    {
        getchar();
        scanf("%c",&(G->Vexs[i]));       /*���붥����Ϣ*/
    }
    for(i=0;i<G->n;i++)
    {
      for(j=0;j<G->n;j++)
      {
        G->edges[i][j]=0;                /*��ʼ���ڽӾ���*/
        G->weight[i][j]=G->weight[j][i]=65535;

      }
    }
    for(j=0;j<G->n;j++)
    G->weight[j][j]=0;
    printf("������ÿ���߶�Ӧ��2����������\n");
    for(k=0;k<G->e;k++)
    {   getchar();
        scanf("%d,%d",&i,&j);
        G->edges[i][j]=G->edges[j][i]=1;//���轨����ͼֻ�� G->edges[i][j]==1
        getchar();
        printf("����õ�Ȩֵ");
        scanf("%d",&we);
        G->weight[j][i]=G->weight[i][j]=we;
        //G->weight[i][j]=G->weight[j][i]=10;
    }
    printf("�������\n");
}


/*�ڽӾ���Ĺ�����ȱ���*/
void BFS(MGraph *G)
{
     int i,j,s;
     LQueue *q;
     q=creat(); /*��������*/
     //ch=G->Vexs[index];
    for(i=0;i<G->n;i++)
      visited[i]=FALSE;
    // in_queue(q,index);    /*���õ�����*/
     //visited[index]=TRUE;  /*�������ʽ���visted��Ϊ1*/
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
        out_queue(q,&s);
        //i=search(G,ch);
		for (j = 0; j < G->n; j++)
		{
			if (G->edges[s][j]==1 && !visited[j])
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
     visited[i]=FALSE;   //��vistedȫ����Ϊfalse
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
     visited[i]=FALSE;   //��vistedȫ����Ϊfalse
    for(i=0;i<G->n;i++)
    {
        if(!visited[i])
        DFS(G,i);
    }
}


int get_position(MGraph *G, char ch)
{
    int i;
    for(i=0; i<G->n; i++)
        if(G->Vexs[i]==ch)
            return i;
    return -1;
}
void prim(MGraph *G, int start)
{
    int min,i,j,k,m,n,sum;
    int index=0;
    char prims[MaxVNum];
    int weights[MaxVNum];

    prims[index++] = G->Vexs[start];

    for (i = 0; i < G->n; i++ )
        weights[i] = G->weight[start][i];

    weights[start] = 0;

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

        prims[index++] = G->Vexs[k];
        weights[k] = 0;

        for (j = 0 ; j < G->n; j++)
        {

            if (weights[j] != 0&&(G->weight[k][j])<weights[j])
                weights[j] = G->weight[k][j];
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
        printf("%c ", prims[i]);
    printf("\n");
}
void dijkstra(MGraph *G, int vs, int prev[], int dist[])
{
    int i,j,k;
    int min;
    int tmp;
    int flag[MaxVNum];      // flag[i]=1��ʾ"����vs"��"����i"�����·���ѳɹ���ȡ��

    // ��ʼ��
    for (i = 0; i < G->n; i++)
    {
        flag[i] = 0;              // ����i�����·����û��ȡ����
        prev[i] = 0;              // ����i��ǰ������Ϊ0��
        dist[i] = G->weight[vs][i];// ����i�����·��Ϊ"����vs"��"����i"��Ȩ��
    }

    // ��"����vs"������г�ʼ��
    flag[vs] = 1;
    dist[vs] = 0;

    // ����G.vexnum-1�Σ�ÿ���ҳ�һ����������·����
    for (i = 1; i < G->n; i++)
    {
        // Ѱ�ҵ�ǰ��С��·����
        // ������δ��ȡ���·���Ķ����У��ҵ���vs����Ķ���(k)��
        min = 65535;
        for (j = 0; j < G->n; j++)
        {
            if (flag[j]==0 && dist[j]<min)
            {
                min = dist[j];
                k = j;
            }
        }
        // ���"����k"Ϊ�Ѿ���ȡ�����·��
        flag[k] = 1;

        // ������ǰ���·����ǰ������
        // �������Ѿ�"����k�����·��"֮�󣬸���"δ��ȡ���·���Ķ�������·����ǰ������"��
        for (j = 0; j < G->n; j++)
        {
            tmp = (G->weight[k][j]==65535 ? 65535 : (min + G->weight[k][j])); // ��ֹ���
            if (flag[j] == 0 && (tmp  < dist[j]) )
            {
                dist[j] = tmp;
                prev[j] = k;
            }
        }
    }

    // ��ӡdijkstra���·���Ľ��
    printf("dijkstra(%c): \n", G->Vexs[vs]);
    for (i = 0; i < G->n; i++)
        printf("  shortest(%c, %c)=%d\n", G->Vexs[vs], G->Vexs[i], dist[i]);
}
main()
{
    int prev[MaxVNum] = {0};
    int dist[MaxVNum] = {0};
     int *P;
	 int *D;
	 int i;
   MGraph *G;
   G=(MGraph *)malloc(sizeof(MGraph));
   CreatMGraph(G);
    printf("���\n");
     BFS(G);
    printf("\n���\n");
     DFS_1(G);
     
     printf("\n");
     prim(G,0);

	dijkstra(G, 3, prev, dist);
}

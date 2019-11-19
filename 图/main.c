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
    int i,j,k;
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
      }
    }
    printf("������ÿ���߶�Ӧ��2����������\n");
    for(k=0;k<G->e;k++)
    {   getchar();
        scanf("%d,%d",&i,&j);
        G->edges[i][j]=G->edges[j][i]=1;//���轨����ͼֻ�� G->edges[i][j]==1
        //getchar();
        //scanf("%d",&(G->weight[i][j]));
        G->weight[i][j]=G->weight[j][i]=10;
    }
    printf("�������\n");
}
int search(MGraph *G,char vn)           /*�õ���ǰ�Ķ����ڶ������±�*/
{
    int i;
    for(i=0;i<G->n;i++)
    if(G->Vexs[i]==vn)
    return i;
}



/*�ڽӾ���Ĺ�����ȱ���*/
void BFS(MGraph *G)
{
     int i,j;
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
void minispanTree_prim(MGraph *G) {
	//adjvex��ʾ��СȨֵ�ߵ���ʼ���㣬j��ʾ��������
	int min, i, j, k;//���õ��ı���
	int adjvex[MaxVNum];//������űߵ�����һ������
	int lowcost[MaxVNum];//������ŵ�ǰ�Ѿ���ͨ���ֵ���СȨֵ(��Ӧ��adjvex�еĶ���)
	lowcost[0] = 0;//��ʼ����һ����ֵΪ0����ʾ��һ�������Ѿ�������С������
	adjvex[0] = 0;//��һ�������±�
	for (i = 1; i < G->n; i++) {
		lowcost[i] = G->weight[0][i];
		adjvex[i] = 0;//һ��ʼ��С�������Ķ���ֻ��0
	}
	//��ʼ����ɣ���������ʼ������С������
	for (i = 1; i < G->n; i++) {
		//�����ʾ��n������ҪŪ��n-1����(����v0��n������)
		min = 65535;//��ʼ����СֵΪ����
		j = 1;
		k = 0;//k���ڴ�ŵ�ǰȨֵ��С�ߵ�����һ���±�
		while (j < G->n) {
			//ѭ�����˵�һ�����ȫ������
			if (lowcost[j] != 0 && lowcost[j] < min) {
				//Ѱ��û����ɣ���Ϊ0������������С�Ķ�����±�
				//Ҳ�����ڿɽӴ�����СȨֵ��(lowcost)��ѡһ����С��
				min = lowcost[j];
				k = j;
			}
			j++;
		}
		//��ʱ��k��ŵľ��ǵ�ǰ���ԽӴ�������СȨֵ�ߵ�һ������
		//adjvex[k]��¼���ǵ�ǰ���ܽӴ�������СȨֵ�ߵ���һ������
		printf("��%d,%d��\n", adjvex[k], k);
		lowcost[k] = 0;//��ʾ��������Ѿ����뵽��С��������
		//������ҪѰ���µĿ��ԽӴ�������СȨֵ��
		for (j = 1; j < G->n; j++) {
			if (lowcost[j] != 0 && G->weight[k][j] < lowcost[j]) {
				//k��ʾ�µ���С���������㣬����ͨ������Ѱ����СȨֵ��
				lowcost[j] = G->weight[k][j];
				adjvex[j] = k;//�ҵ���֮��Ҫ������һ�������Ϊk,��ʾ��k����СȨֵ��
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
    int path[MaxVNum];    //�������±��ʾ�Ķ�����������ǰһ������
    int dist[MaxVNum];    //�������±��ʾ�Ķ������СȨֵ·����
    //�����������鶼������,����Ȩ���·��һ�£�������Ȩ���·������ʹ��dist�Ƿ��������ж�һ�������Ƿ񱻷��ʣ�
    //���������޷�ʹ�ã���Ϊdist������ķ�㷨�е�lowcostһ������ʹ��̰���㷨ʱ��ÿ��һ�����㣬���Ƕ���ȫ������dist
    //����������Ҫ����һ����������־���������Ƿ񱻷���
    int final[MaxVNum];
    int i,j,k,min;

    //�����ݽ��г�ʼ��
    for (i = 0; i < G->n;i++)
    {
        final[i] = 0;    //0��ʾ�������±�����ʾ�Ķ���δ������
        path[i] = 0;    //��ʼ��·������Ϊ0����ʾ��ǰÿ�����Ƕ����ĸ��ڵ�
        dist[i] = G->weight[s][i];    //��һ�����ص㣺��ʼ��·�������ֵΪ��ʼv0���������Ȩֵ
    }
    dist[s] = 0;    //��Դ���Լ���·��Ϊ0
    path[s] = s;    //����Դ���ǰһ����������Լ�
    final[s] = 1;    //Դ�㱻���ʹ���

    //��ʼ��ѭ����ÿ�����v0��s����ĳ��v��������·��
    for (i = 0; i < G->n;i++)
    {
        min = 65535;    //������ķ�㷨����
        for (j = 0; j < G->n;j++)    //����������ͼ���Զ�Ҫ��0��ʼ���ҵ�����ÿ���ڽӵ�
        {
            if (!final[j]&&dist[j]<min)    //���Ǹö���û�б����ʹ����Ҹõ㵽s��ľ���С��min,���Ǿͽ�min����Ϊ��
            {
                k = j;    //��¼�¸�v��s����±��min��С·��
                min = dist[j];
            }
        }

        final[k] = 1;    //��Ŀǰ�ҵ��ľ���v0(S)����Ķ�����Ϊ1

        for (j = 0; j < G->n;j++)    //������ǰ���·��������
        {
            //������������ѭ��k��ÿ���ڽӵ�,������Ϊ��������������������֮��С�ڵ����ߣ�������ԭ���ҵ�����ֱ�ӵ���̱߾�ʧЧ�ˣ���������ֱ�Ӵ���
            //�������ǽ������޸ģ�·������Ϊ������һ��k,
            if (!final[j]&&(min+G->weight[k][j])<dist[j])
            {
                //˵���ҵ��˸��̵�·�����޸�dist��path����
                dist[j] = min + G->weight[k][j];    //�޸ĵ�ǰ·������
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
    printf("���\n");
     BFS(G);
    printf("\n���\n");
     DFS_1(G);
     minispanTree_prim(G);

     Dijkatra(G,0);
	//ShortestPath_Dijkstra(G, 0, P, D);
}

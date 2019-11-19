#include <stdio.h>
#include <stdlib.h>
#define  MaxVerNum 100
int visited[MaxVerNum];
/***********�߱�**********/
typedef struct EdgeNode
{
	int adjvex;      //�ڽӵ���
	struct EdgeNode *next;   //ָ����һ���ڽӵ��ָ����
}EdgeNode;

/*********�����*********/
typedef struct
{
	int Vexs;     //�������Ϣ
	EdgeNode *first;  //ָ���һ���ߵ�ָ��
}VertexNode,AdjList[MaxVerNum];

/*********ͼ�ṹ********/
typedef struct
{
	AdjList adjlist;
	int n,e;  //�������ͱ���
}ALGraph;
/*��������������ȱ���*/
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


/*********����ͼ********/
void create_ALGraph(ALGraph *G)
{
	int i, j;
	int a, b;     //�����ӵ������������
	EdgeNode *s;    //�߱���
    s=malloc(sizeof(EdgeNode));
	printf("�����붥�����ͱ���\n");
	scanf("%d,%d", &G->n, &G->e);

	printf("���������:\n");
	for (i = 0; i < G->n; i++)
	{
		getchar();  //�Ե�\n
		printf("�������%d���������Ϣ:", i + 1);
		scanf("%d", &G->adjlist[i].Vexs);
		G->adjlist[i].first = NULL;
	}
	for (i = 0; i < G->e; i++)
	{
	    getchar();
		printf("�����������ӵ����������±�:");
		scanf("%d%d",&a,&b );
		s = malloc(sizeof(EdgeNode));
		s->adjvex = b;    //����ָ�����λ��
		s->next = G->adjlist[a].first;
		G->adjlist[a].first = s;

		//����(0 1)��1��Ҳ��0����
		s = malloc(sizeof(EdgeNode));
		s->adjvex = a;    //����ָ�����λ��
		s->next = G->adjlist[b].first;
		G->adjlist[b].first = s;
	}
}

/***********��ӡ�߱�*********/
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
		visited[v] = 1;     //�Ѿ����ʱ����Ϊ
		printf("%d  ", G->adjlist[v].Vexs);
		p = G->adjlist[v].first;   //pָ�򶥵�v�ĵ�һ����
		while (p != NULL)
		{
			if (!visited[p->adjvex])
				DFS(G,p->adjvex);
			p = p->next;                   //��vi���¸��ڽӵ�
		}
}
void DFSTravel(ALGraph *G)
{
	int i;
	for (i = 0; i < G->n; i++)
		visited[i] = 0;            //��ʼȫû�з�����Ϊ0
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
      q=creat();   //��������
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

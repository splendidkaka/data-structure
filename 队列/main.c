#include <stdio.h>
#include <stdlib.h>
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
     return 0;
     else
     return 1;
}
int out_queue(LQueue *q,int x)
{
       Qnode *p;
           p=q->front->next;
           q->front->next=p->next;
           x=p->data;
           free(p);
           if(q->front->next==NULL)
           q->rear=q->front;
           return 1;
}
void printqueue(LQueue *q)
{
    q->front=q->front->next;
      while(q->front!=NULL)
      {
        printf("%d\n",q->front->data);
        q->front=q->front->next;
      }
}
void  sd(LQueue *q)
{
    int n;
    int flag=1;
    char ch;
    while(flag)
    {

      printf("\n����������");
      ch=getchar();
      switch(ch)
      {
       case 'a':printf("\n������:");
                scanf("%d",&n);
                in_queue(q,n);
                break;
       case 'n': out_queue(q,n);
                 printf("\n������Ϊ%d�Ĳ��˾���:");
                 break;
       case 'q':printf("\nֹͣ�Һ�,ʣ�µĲ��˾���");
                printqueue(q);
                flag=0;
                break;
      }
    }
}
int main(int argc, char *argv[])
{
	LQueue *q,*p;
	int x;
	q=creat();
	p=creat();
	in_queue(q,1);
	in_queue(q,2);
	in_queue(q,3);
	x=out_queue(q,x);
    printqueue(q);	
	printf("�ȳ����е�Ԫ��Ϊ��%d",x);
	sd(p);	
}

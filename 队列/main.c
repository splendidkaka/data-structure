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
   q->rear->next=p;     //要从队尾插入
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

      printf("\n请输入命令");
      ch=getchar();
      switch(ch)
      {
       case 'a':printf("\n病历号:");
                scanf("%d",&n);
                in_queue(q,n);
                break;
       case 'n': out_queue(q,n);
                 printf("\n病历号为%d的病人就诊:");
                 break;
       case 'q':printf("\n停止挂号,剩下的病人就诊");
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
	printf("先出队列的元素为：%d",x);
	sd(p);	
}

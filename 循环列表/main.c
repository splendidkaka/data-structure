#include <stdio.h>
#include <stdlib.h>
typedef struct
{
     int data[100];
     int front,rear;
     int num;
}squeue;
squeue *creat()
{
   squeue *q;
   q=malloc(sizeof(squeue));
   q->front=q->rear=0;q->num=0;
   return q;
}
int in_squeue(squeue *q,int x)
{
    if(q->num==100)
 {   printf("表已满");
    return -1;
 }
 else{ q->num++;
       q->rear=(q->rear+1)%100;
       q->data[q->rear]=x;
       return 1;
 }
}
int out_squeue(squeue *q,int x)
{
   if(q->num==0)
   printf("NULL");
   else
   {  q->front=(q->front+1)%100;
     x=q->data[q->front];
     q->num--;
   }
}
void print(squeue *q)
{
     while(q->rear!=q->front)
     {
        q->front=(q->front+1)%100;
        printf("当前队列的值=%d\n",q->data[q->front]);
     }
}
int main(int argc, char *argv[])
{
    int x;
	  squeue *q;
	  q=creat();
	  in_squeue(q,1);
	  in_squeue(q,2);
	  in_squeue(q,3);
	  in_squeue(q,4);
	  x=out_squeue(q,x);
	  printf("front=%d",q->front);
	  print(q);
	  printf("rear=%d",q->rear);
}

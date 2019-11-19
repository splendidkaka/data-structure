#include <stdio.h>
#include <stdlib.h>
typedef struct LNode
 {
   int data;
   struct LNode *next;
 }LNode,*LinkList;
 LinkList creat()
  {
   LinkList L;
   LNode *s;
   int x;
   L=(LinkList)malloc(sizeof(LNode));
   L->next=NULL;
   s=L;
   scanf("%d",&x);
   while(x!=-1)
   {
     s->next=malloc(sizeof(LNode));
     s->next->data=x;
     s=s->next;
     scanf("%d",&x);
   }
     s->next=NULL;
     return L;
  }
  LinkList get(LinkList L,int i)
  {
    LNode *p=L;
    int j=0;
    while(p->next!=NULL && j<i)
    {
        p=p->next;
        j++;
    }
    if(j==i)
    return p;
    else return NULL;
  }
  int  insert(LinkList L,int i,int x)
  {
     LNode *p,*s;
     p=get(L,i-1);
     if(p==NULL)
     {
        printf("输入错误");
     }
     else
     {
       s=malloc(sizeof(LNode));
       s->data=x;
       s->next=p->next;
       p->next=s;
       return 1;
     }
  }
  int dele(LinkList L,int i)
  {
   LinkList p,s;
   p=get(L,i-1);
   if(p==NULL)
   {
    printf("不存在第i-1个结点");
    return -1;
   }
   else
   {
     s=p->next;
     p->next=s->next;
     free(s);
     return 1;
   }
  }
  void print(LinkList L)
  {
    LinkList p=NULL;
    p=L->next;
    if(p==NULL)
    printf("空表!!!");
    else
    do
    {
     printf("%5d",p->data);
     p=p->next;
    }while(p!=NULL);
    printf("\n");
  }
  LinkList merge(LinkList L,LinkList L2)
  {
    LinkList L3;
    LNode *p,*q,*s;
    p=L->next;q=L2->next;
    L3=L;L3->next=NULL;
    free(L2);
    while(p&&q)
    {
      if(p->data<q->data)
      {s=p;p=p->next;}
      else
      {s=q;q=q->next;}
      s->next=L3->next;
      L3->next=s;
    }
    if(p==NULL)
    p=q;
    while(p)
    {
        s=p;p=p->next;
        s->next=L3->next;
        L3->next=s;
    }
    return L3;
  }
  LinkList reverse(LinkList L)
  {
    LNode *p,*q;
    p=L->next;
    L->next=NULL;
    while(p)
    {
     q=p;p=p->next;
     q->next=L->next;
     L->next=q;
    }
    return L;
  }
  void spit(LinkList L,LinkList L2)
  {
    int i=1;
    LNode *pa1,*pa2,*pb;
    pa1=L->next;
    pa2=L;
    pb=L2;
    while(pa1!=NULL)
{
     while(i%2!=0&&pa1->next!=NULL)
     {
       pa2=pa1;
       pa1=pa1->next;
       i++;
     }
      if(i%2==0)
    {
       pa2->next=pa1->next;
       pb->next=pa1;
       pb=pb->next;
       pa1=pa2->next;
    }
       else
       {
        pa1=pa1->next;
       }
       i++;
}
       pb->next=NULL;
  }
  int len(LinkList L)
  {
     int i=0;
     LinkList q=L;
     while(q->next)
     {
      q=q->next;
      i++;
     }
    return i;
  }
  void circle(LinkList L)
  {
    int i,j=0;
    LinkList p1,p2,p3;
    p2=p1=L;
    i=len(p1);
    while(p1->next!=NULL)
    {
       p1=p1->next;
    }
    p1->next=p2->next;
  while(i!=1)
 {
      p3=p1;
      p1=p1->next;
      j++;
      if(j%3==0)
    {
       printf("%d  ",p1->data);
       i--;
       p3->next=p1->next;
       free(p1);
       p1=p3->next;
       j--;
    }
 }

 printf("%d",p1->data);
  }
LinkList po(LinkList L)
 {
   LinkList q,p;
    q=L->next;
    q->next=NULL;
    return q;
 }
int main(int argc, char *argv[])
{
    LinkList L,L2,L3;
    int x,i,len1=0;
  L=creat();
  printf("数据为: \n");
  print(L);
  printf("请选择 1为插入，2为删除,3为合并表,4为分开,5为倒置,6为约瑟夫环");
  scanf("%d",&x);
  switch(x)
  {
    case 1:{printf("输入要插入的位置和x  ");scanf("%d",&i);scanf("%d",&x); insert(L,i,x);printf("插入后为");print(L);break;}
    case 2:{printf("输入要删的位置  ");scanf("%d",&i);dele(L,i);printf("删除后为");print(L);break;}
    case 3:{L2=creat();printf("合并后为");L3=merge(L,L2);print(L3);break;}
    case 4:{L2=(LinkList)malloc(sizeof(LNode));spit(L,L2);print(L);print(L2);break; }
    case 5:{L=reverse(L); print(L);break;   }
    case 6:{circle(L);break;}
    case 7:{   L=po(L); printf("%d",L->data);  break;}
  }
}

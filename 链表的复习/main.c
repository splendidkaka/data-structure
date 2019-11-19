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
        printf("�������");
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
    printf("�����ڵ�i-1�����");
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
    printf("�ձ�!!!");
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
  printf("����Ϊ: \n");
  print(L);
  printf("��ѡ�� 1Ϊ���룬2Ϊɾ��,3Ϊ�ϲ���,4Ϊ�ֿ�,5Ϊ����,6ΪԼɪ��");
  scanf("%d",&x);
  switch(x)
  {
    case 1:{printf("����Ҫ�����λ�ú�x  ");scanf("%d",&i);scanf("%d",&x); insert(L,i,x);printf("�����Ϊ");print(L);break;}
    case 2:{printf("����Ҫɾ��λ��  ");scanf("%d",&i);dele(L,i);printf("ɾ����Ϊ");print(L);break;}
    case 3:{L2=creat();printf("�ϲ���Ϊ");L3=merge(L,L2);print(L3);break;}
    case 4:{L2=(LinkList)malloc(sizeof(LNode));spit(L,L2);print(L);print(L2);break; }
    case 5:{L=reverse(L); print(L);break;   }
    case 6:{circle(L);break;}
    case 7:{   L=po(L); printf("%d",L->data);  break;}
  }
}

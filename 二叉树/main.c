#include <stdio.h>
#include <stdlib.h>
typedef struct BiTNode
{
   char data;
   struct BiTNode *left,*right;
}BiTNode,*BiTree,*BI;
typedef struct
{
    BI a[100];
    int top;
}stack;
stack* Initstack()
{
    stack *s;
    s=(stack*)malloc(sizeof(stack));
    s->top=0;
    return s;
}
int emptystack(stack *s)
{
    if(s->top==0)
    return 1;
    else
    return 0;
}
BI GetTop(stack *s)
{
    //s->top--;
    return s->a[s->top-1];
}
int push(stack *s,BI t)
{
   if(s->top>=100)
   return 0;
   else
{
   s->a[s->top]=t;
   s->top++;
   return 1;
}
}
int pop(stack *s,BI *t)
{
    if(s->top==0)
    return 0;
    else
   { s->top--;*t=s->a[s->top];return 1;}
}
BiTree creat()
{
    BiTree T;
    char ch;
    scanf("%c",&ch);    //i=0������Ϊ��
    if(ch=='0')
    T=NULL;
    else
    {
        T=(BiTNode*)malloc(sizeof(BiTNode));
        T->data=ch;
        T->left=creat();
        T->right=creat();
    }
    return T;
}
void PreOrder(BiTree T)//����ݹ�
{
   if(T)
   {
    printf("%3c",T->data);
    PreOrder(T->left);
    PreOrder(T->right);
   }
}
void InOrder(BiTree T)//����ݹ�
{
   if(T)
   {
    InOrder(T->left);
    printf("%3c",T->data);
    InOrder(T->right);
   }
}
void PostOrder(BiTree T)//����ݹ�
{
   if(T)
   {
    PostOrder(T->left);
    PostOrder(T->right);
    printf("%3c",T->data);
   }
}
void PreOrderNonRec(BiTree T)//�ǵݹ�ǰ��
{
   stack *s;
   BI p;
   s=Initstack();
   p=T;
   while(p || !emptystack(s) )
  {
	if(p)
	{ printf("%3c",p->data);
      push(s,p);p=p->left;
	}
	else
	{    pop(s,&p);
         p=p->right;
	}
  }
}
/*void PreorderNonRec2( BiTree T)
{
    int top=0;
    BiTree *Stack[100];
    BiTree p;
    p=T;
    while(p||top)
    {
        if(p)
        {
            printf("%3c",p->data);
            Stack[top++]=p;
            p=p->left;
        }
        else
        {
            p=Stack[--top];
            p=p->right;
        }
    }
}  */
void InorderNonRec(BiTree T)//�ǵݹ�ǰ��
{
   stack *s;
   BI p;
   s=Initstack();
   p=T;
   while(p || !emptystack(s) )
  {
	if(p)
	{
      push(s,p);p=p->left;
	}
	else
	{    pop(s,&p);
   	printf("%3c",p->data);
         p=p->right;
	}
  }
}
/*void InorderNonRec2(BiTree T)
{
    int top=0;
    BiTree *Stack[100];
    BiTree p;
    p=T;
    while(p||top)
    {
        if(p)
        {
            Stack[top++]=p;
            p=p->left;
        }
        else
        {
            p=Stack[--top];
            printf("%3c",p->data);
            p=p->right;
        }
    }
}*/
/*void PostorderNonRec2(BiTree T)
{
    int top=0;
    BiTree *Stack[100];
    BiTree p,q;
    p=T;
    q=NULL;
    while(p||top)
    {
        if(p)
        {
            Stack[top++]=p;
            p=p->left;
        }
        else
        {
            p=Stack[top-1];
            if(p->right&&p->right!=q)
            {
                p=p->right;
                Stack[top++]=p;
                p=p->left;
            }
            else
            {
                p=Stack[--top];
                printf("%3c",p->data);
                q=p;
                p=NULL;
            }
        }
    }
}  */
 void PostOrderNonRec(BiTree T)
{

   stack *s; BI p,q;
   s=Initstack();
   p=T;
   q=NULL;
   while(p || s->top )
  {
     if(p)
        {
            push(s,p);
            p=p->left;
        }
        else
        {
            p=GetTop(s);
            if(p->right&&p->right!=q)
            {
                p=p->right;
                push(s,p);
                p=p->left;
            }
        else
        {
            pop(s,&p);
            printf("%3c",p->data);
            q=p;
            p=NULL;
        }
        }
  }
}
void PrintTree(BiTree T,int x)
    {
        int i;
        if(T==NULL)
            return;
        PrintTree(T->right,x+1);
        for( i=0;i<x;i++)
            printf(" ");
        printf("%c\n",T->data);
        PrintTree(T->left,x+1);
    }
int main(int argc, char *argv[])
{
	BiTree T;
	T=creat();
    printf("ǰ�����Ϊ    ");
	PreOrder(T);	
	printf("\n");
	
	printf("�������Ϊ    ");
	InOrder(T);
	printf("\n");
	
	printf("�������Ϊ    ");
	PostOrder(T);
	printf("\n");
	
    printf("ǰ��ǵݹ����Ϊ    ");	
	PreOrderNonRec(T);
	printf("\n");
	
	printf("����ǵݹ����Ϊ    ");	
	InorderNonRec(T);
	printf("\n");
	
	printf("����ǵݹ����Ϊ    ");	
	PostOrderNonRec(T);
	printf("\n------------>�������ҿ�\n");
	PrintTree(T,1);
}

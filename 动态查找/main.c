#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

int searchBST(BiTree T,int x,BiTree *p,BiTree *q)
{
    *p=T;
    while(*p)
    {
      if((*p)->data==x)
        return 1;
      else
        if((*p)->data>x)
        {
            *q=*p;
            *p=(*p)->lchild;
        }
        else
        {
            *q=*p;
            *p=(*p)->rchild;
        }
        
    }
    return 0;
}

int insertBST(BiTree *T,int x)
{
    if(!(*T))
    {
        *T=(BiTree)malloc(sizeof(BiTNode));
        (*T)->data=x;
        (*T)->lchild=(*T)->rchild=NULL;
    }
    if(x==(*T)->data) return 0;
    if(x>(*T)->data) insertBST(&(*T)->rchild,x);
    else insertBST(&(*T)->lchild,x);
}

/*void createBST(BiTree *T)
{
    int x;
    printf("input -1 as end \n");
    scanf("%d",&x);
    while(x!=-1)
    {
        insertBST(&T,x);
        scanf("%d",&x);
    }
}*/
void InOrder(BiTree T)//中序递归
{
   if(T)
   {
    InOrder(T->lchild);
    printf("%3d",T->data);
    InOrder(T->rchild);
   }
}
int main(int argc, char *argv[])
{
	BiTree T,p,q;int x;
	T=NULL;	
    printf("input -1 as end \n");
    scanf("%d",&x);
    while(x!=-1)
    {
        insertBST(&T,x);
        scanf("%d",&x);
    }
    
	InOrder(T);
	printf("\n输入需要查找的数\n");
	scanf("%d",&x);
	if(searchBST(T,x,&q,&p))
	printf("已查到");
	else
	printf("未查到");
	
}

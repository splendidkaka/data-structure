#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
typedef struct
{
    int data[MaxSize+1];
    int last;
}SqList;
void create(SqList *L)
{
   int last,i=0;
   last=L->last;
   while(last>=1)
   {
    getchar();
    scanf("%d",&L->data[i]);
    i++;last--;
   }
}
int SeqSearch(SqList *L,int x)
{
    int i;

    for(i=L->last;i>=0;i--)
    {

        if(L->data[i]==x)
        {
            return i;
        }
    }
}
int BinarySearch(SqList *L,int x)
{
    int mid,low=1,high=L->last;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(L->data[mid]==x)
        return mid;
        if(L->data[mid]<x)
        low=mid+1;
        else
        high=mid-1;
        
    }
}
int BinarySearchRecursion(SqList *L,int x,int low,int high)
{
    int mid;
    mid=(low+high)/2;
    if(low>high)
    return -1;
    if(L->data[mid]==x)
        return mid;
    else if(L->data[mid]<x)
        return  BinarySearchRecursion(L,x,mid+1,high);
    else
        return  BinarySearchRecursion(L,x,low,mid-1);
}
int main(int argc, char *argv[])
{
    int x;
	SqList *L;
	L=malloc(sizeof(SqList));
    printf("输入线性表的长度");
    scanf("%d",&L->last);
	create(L);
	printf("input x\n");
	//getchar();
	//scanf("%d",&x);
	printf("\n%d\n",SeqSearch(L,3));
	printf("\n%d\n",BinarySearch(L,3));
	printf("\n%d\n",BinarySearchRecursion(L,3,1,L->last));
}

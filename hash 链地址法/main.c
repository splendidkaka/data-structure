
#include <stdio.h>
#include <stdlib.h>

#define N 11

typedef struct node
{
    int data;
    struct node *next;
}listnode, *pLinklist;

int insert(pLinklist h, int key)
{
    int value = key % N; /*除留余数法*/
    pLinklist p = &h[value]; /*p指向哈希表中应存的位置,相当于指向链表头*/
    pLinklist q = NULL; /*q生成要存的数据*/

    q = (pLinklist)malloc(sizeof(listnode));
    q->data = key;
    q->next = NULL;
	/*若p->next为NULL，链表头指向空，不走while, head-->q-->NULL
	若p->next不为NULL，如head-->q1-->NULL，若q1>q，不走while,head-->q-->q1-->NULL
	若p->next不为NULL，如head-->q1-->NULL，若q1<q，走while,head-->q1-->q-->NULL 使链表排列是从小到大的*/
    while (p->next && p->next->data < key)
    {
        p = p->next;
    }

    q->next = p->next;
    p->next = q;

    return 0;
}

int contains(pLinklist h, int key)
{
    int value = key % N;
    pLinklist p = h[value].next;

    while (p)
    {
        if (p->data == key)
            return value;
        p = p->next;
    }
    return -1;
}

void show(pLinklist p)
{
    int flag=0;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
        flag=1;
    }
    if(flag==0)
    printf("############");
    printf("\n");
}

int main()
{
    /*哈希表 用链地址法处理冲突 故用节点作为数据结构 数组中节点相当于链表头，不存数据*/
    listnode hash[N] = {{0, NULL}};
    int n;
    /*要存入哈希表的数据*/
    int a[] = {47,7,29,11,16,92,22,8,3,50,37,89,94,21};//{19,14,23,1,68,20,84,27,56,11,10,79};
		int i = 0;
		
    for (i = 0; i < sizeof(a)/sizeof(int); i++)
        insert(hash, a[i]);

    for (i = 0; i < N; i++)
     {
        printf("%d:  ",i);
        show(hash[i].next);
     }
     printf("输入要查找的数");
     scanf("%d",&n);
     if(contains(hash, n))
     {
        printf("%d的键为%d",n,contains(hash, n));
     }
     else
     {
        printf("不存在");
     }
    //printf("** %d\n", contains(hash, 23));
    //printf("** %d\n", contains(hash, 99));

    return 0;
}

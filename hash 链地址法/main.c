
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
    int value = key % N; /*����������*/
    pLinklist p = &h[value]; /*pָ���ϣ����Ӧ���λ��,�൱��ָ������ͷ*/
    pLinklist q = NULL; /*q����Ҫ�������*/

    q = (pLinklist)malloc(sizeof(listnode));
    q->data = key;
    q->next = NULL;
	/*��p->nextΪNULL������ͷָ��գ�����while, head-->q-->NULL
	��p->next��ΪNULL����head-->q1-->NULL����q1>q������while,head-->q-->q1-->NULL
	��p->next��ΪNULL����head-->q1-->NULL����q1<q����while,head-->q1-->q-->NULL ʹ���������Ǵ�С�����*/
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
    /*��ϣ�� ������ַ�������ͻ ���ýڵ���Ϊ���ݽṹ �����нڵ��൱������ͷ����������*/
    listnode hash[N] = {{0, NULL}};
    int n;
    /*Ҫ�����ϣ�������*/
    int a[] = {47,7,29,11,16,92,22,8,3,50,37,89,94,21};//{19,14,23,1,68,20,84,27,56,11,10,79};
		int i = 0;
		
    for (i = 0; i < sizeof(a)/sizeof(int); i++)
        insert(hash, a[i]);

    for (i = 0; i < N; i++)
     {
        printf("%d:  ",i);
        show(hash[i].next);
     }
     printf("����Ҫ���ҵ���");
     scanf("%d",&n);
     if(contains(hash, n))
     {
        printf("%d�ļ�Ϊ%d",n,contains(hash, n));
     }
     else
     {
        printf("������");
     }
    //printf("** %d\n", contains(hash, 23));
    //printf("** %d\n", contains(hash, 99));

    return 0;
}

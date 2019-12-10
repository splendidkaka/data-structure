#include <stdio.h>
#include <stdlib.h>
#define max 100
typedef struct sqlist
{
  int length;
  int data[max];
}sqlist,*SqList;
void InsertSort(SqList L)
{
    int i,j,flag;
    for(i=1;i<L->length;i++)
    {
        if(L->data[i]<L->data[i-1])
        {
            flag=L->data[i];//�õ���ǰҪ�ƶ���Ԫ��
            for(j=i-1;j>=0&&L->data[j]>flag;j--)
                L->data[j+1]=L->data[j];
            L->data[j+1]=flag;
        }
    }
}
void bubblesort(SqList L)
{
    int i,j,n;
    int flag;
    n=L->length;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(L->data[j]>L->data[j+1])
            {
                flag=L->data[j+1];
                L->data[j+1]=L->data[j];
                L->data[j]=flag;
            }
        }
    }
}
void quick_sort(SqList L,int l,int r)
{
    if (l < r)
    {
        int i,j,x;

        i = l;
        j = r;
        x = L->data[i];
        while (i < j)
        {
            while(i < j && L->data[j] > x)
                j--; // ���������ҵ�һ��С��x����
            if(i < j)
                L->data[i++] = L->data[j];
            while(i < j && L->data[i] < x)
                i++; // ���������ҵ�һ������x����
            if(i < j)
                L->data[j--] = L->data[i];
        }
        L->data[i] = x;
        quick_sort(L, l, i-1); /* �ݹ���� */
        quick_sort(L, i+1, r); /* �ݹ���� */
    }
}
void maxheap_down(SqList L, int start, int end)
{
    int c = start;          // ��ǰ(current)�ڵ��λ��
    int l = 2*c + 1;        // ��(left)���ӵ�λ��
    int tmp = L->data[c];         // ��ǰ(current)�ڵ�Ĵ�С
    for (; l <= end; c=l,l=2*l+1)
    {
        // "l"�����ӣ�"l+1"���Һ���
        if ( l < end && L->data[l] < L->data[l+1])
            l++;        // ������������ѡ��ϴ��ߣ���m_heap[l+1]
        if (tmp >= L->data[l])
            break;      // ��������
        else            // ����ֵ
        {
            L->data[c] = L->data[l];
            L->data[l]= tmp;
        }
    }
}

void heap_sort_asc(SqList L, int n)
{
    int i;
    int flag;
    // ��(n/2-1) --> 0��α���������֮�󣬵õ�������ʵ������һ��(���)����ѡ�
    for (i = n / 2 - 1; i >= 0; i--)
        maxheap_down(L, i, n-1);

    // �����һ��Ԫ�ؿ�ʼ�����н��е��������ϵ���С�����ķ�Χֱ����һ��Ԫ��
    for (i = n - 1; i > 0; i--)
    {
        // ����a[0]��a[i]��������a[i]��a[0...i]�����ġ�
        //swap(L->data[0], L->data[i]);
        flag=L->data[i];
        L->data[i]=L->data[0];
        L->data[0]=flag;
        
        
        // ����a[0...i-1]��ʹ��a[0...i-1]��Ȼ��һ�����ѡ�
        // ������֤a[i-1]��a[0...i-1]�е����ֵ��
        maxheap_down(L, 0, i-1);
    }
}

void merge(SqList L, int start, int mid, int end)
{
    int *tmp = (int *)malloc((end-start+1)*sizeof(int));    // tmp�ǻ���2������������ʱ����
    int i = start;          // ��1��������������
    int j = mid + 1;        // ��2��������������
    int k = 0;              // ��ʱ���������

    while(i <= mid && j <= end)
    {
        if (L->data[i] <= L->data[j])
            tmp[k++] = L->data[i++];
        else
            tmp[k++] = L->data[j++];
    }

    while(i <= mid)
        tmp[k++] = L->data[i++];

    while(j <= end)
        tmp[k++] = L->data[j++];

    // ��������Ԫ�أ�ȫ�������ϵ�����a�С�
    for (i = 0; i < k; i++)
        L->data[start + i] = tmp[i];

    free(tmp);
}

void merge_sort_up2down(SqList L, int start, int end)
{
    int mid;
    if(L->data==NULL || start >= end)
        return ;

    mid = (end + start)/2;
    merge_sort_up2down(L, start, mid); // �ݹ�����a[start...mid]
    merge_sort_up2down(L, mid+1, end); // �ݹ�����a[mid+1...end]

    // a[start...mid] �� a[mid...end]����������ռ䣬
    // �����������һ������ռ�a[start...end]
    merge(L, start, mid, end);
}


int main(int argc, char *argv[])
{
    int i,n,x;
	SqList L,L1,L2,L3,L4;
	L=malloc(sizeof(sqlist));
	printf("����n�����к�ֵ\n");
	scanf("%d",&n);
	L->length=n;

	for(i=0;i<L->length;i++)
	{
	  	getchar();
	    scanf("%d",&x);
	    L->data[i]=x;
    }
    L4=L3=L2=L1=L;
    InsertSort(L);
    printf("\nֱ�Ӳ��������:\n");
    for(i=0;i<L->length;i++)
	{
	  	printf("%d",L->data[i]);
    }
    
    bubblesort(L1);
    printf("\nð�������:\n");
    for(i=0;i<L1->length;i++)
	{
	  	printf("%d",L1->data[i]);
    }
    
    
    quick_sort(L2,0,L2->length-1);
    printf("\n���������:\n");
    for(i=0;i<L2->length;i++)
	{
	  	printf("%d",L2->data[i]);
    }
    
    
     heap_sort_asc(L3,L->length);
     printf("\n�������:\n");
    for(i=0;i<L3->length;i++)
	{
	  	printf("%d",L3->data[i]);
    }

    merge_sort_up2down(L,0,L->length-1);
    printf("\n�鲢�����:\n");
    for(i=0;i<L4->length;i++)
	{
	  	printf("%d",L4->data[i]);

    }
}

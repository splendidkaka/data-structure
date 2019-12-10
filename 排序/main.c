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
            flag=L->data[i];//得到当前要移动的元素
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
                j--; // 从右向左找第一个小于x的数
            if(i < j)
                L->data[i++] = L->data[j];
            while(i < j && L->data[i] < x)
                i++; // 从左向右找第一个大于x的数
            if(i < j)
                L->data[j--] = L->data[i];
        }
        L->data[i] = x;
        quick_sort(L, l, i-1); /* 递归调用 */
        quick_sort(L, i+1, r); /* 递归调用 */
    }
}
void maxheap_down(SqList L, int start, int end)
{
    int c = start;          // 当前(current)节点的位置
    int l = 2*c + 1;        // 左(left)孩子的位置
    int tmp = L->data[c];         // 当前(current)节点的大小
    for (; l <= end; c=l,l=2*l+1)
    {
        // "l"是左孩子，"l+1"是右孩子
        if ( l < end && L->data[l] < L->data[l+1])
            l++;        // 左右两孩子中选择较大者，即m_heap[l+1]
        if (tmp >= L->data[l])
            break;      // 调整结束
        else            // 交换值
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
    // 从(n/2-1) --> 0逐次遍历。遍历之后，得到的数组实际上是一个(最大)二叉堆。
    for (i = n / 2 - 1; i >= 0; i--)
        maxheap_down(L, i, n-1);

    // 从最后一个元素开始对序列进行调整，不断的缩小调整的范围直到第一个元素
    for (i = n - 1; i > 0; i--)
    {
        // 交换a[0]和a[i]。交换后，a[i]是a[0...i]中最大的。
        //swap(L->data[0], L->data[i]);
        flag=L->data[i];
        L->data[i]=L->data[0];
        L->data[0]=flag;
        
        
        // 调整a[0...i-1]，使得a[0...i-1]仍然是一个最大堆。
        // 即，保证a[i-1]是a[0...i-1]中的最大值。
        maxheap_down(L, 0, i-1);
    }
}

void merge(SqList L, int start, int mid, int end)
{
    int *tmp = (int *)malloc((end-start+1)*sizeof(int));    // tmp是汇总2个有序区的临时区域
    int i = start;          // 第1个有序区的索引
    int j = mid + 1;        // 第2个有序区的索引
    int k = 0;              // 临时区域的索引

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

    // 将排序后的元素，全部都整合到数组a中。
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
    merge_sort_up2down(L, start, mid); // 递归排序a[start...mid]
    merge_sort_up2down(L, mid+1, end); // 递归排序a[mid+1...end]

    // a[start...mid] 和 a[mid...end]是两个有序空间，
    // 将它们排序成一个有序空间a[start...end]
    merge(L, start, mid, end);
}


int main(int argc, char *argv[])
{
    int i,n,x;
	SqList L,L1,L2,L3,L4;
	L=malloc(sizeof(sqlist));
	printf("输入n个序列和值\n");
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
    printf("\n直接插入排序后:\n");
    for(i=0;i<L->length;i++)
	{
	  	printf("%d",L->data[i]);
    }
    
    bubblesort(L1);
    printf("\n冒泡排序后:\n");
    for(i=0;i<L1->length;i++)
	{
	  	printf("%d",L1->data[i]);
    }
    
    
    quick_sort(L2,0,L2->length-1);
    printf("\n快速排序后:\n");
    for(i=0;i<L2->length;i++)
	{
	  	printf("%d",L2->data[i]);
    }
    
    
     heap_sort_asc(L3,L->length);
     printf("\n堆排序后:\n");
    for(i=0;i<L3->length;i++)
	{
	  	printf("%d",L3->data[i]);
    }

    merge_sort_up2down(L,0,L->length-1);
    printf("\n归并排序后:\n");
    for(i=0;i<L4->length;i++)
	{
	  	printf("%d",L4->data[i]);

    }
}

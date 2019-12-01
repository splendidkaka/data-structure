#include <stdio.h>
#define HashLength 13
//哈希函数
int HashFuc(int i,int length)
{
	return i%length;
}
//线性探测再散列
int *HashReLineExplor(int A[], int k,int h[],int m)//关键字数组、关键字个数、哈希表、哈希表长度
{
    int i,j,loc;
	for ( i = 0; i < m; i++)
		h[i] = NULL;
	for ( j = 0; j < k; j++)
	{
		loc = HashFuc(A[j], HashLength);
		while (h[loc])
		{
			loc=loc++%m;	//寻找第一个空位置
		}
		h[loc] = A[j];
	}
	return h;
}

int main()
{
    int i;
	int Hash[30];//哈希表
	int Key[12] = { 19,14,23,1,68,20,84,27,56,11,10,79 };	//关键字
	HashReLineExplor(Key, 12, Hash, 30);
	for (i = 0; i < 30; i++)
	{
		if (Hash[i])
		{
			printf("第%2d个元素是:%4d\n", i, Hash[i]);
		}
	}
	return 0;
}

#include <stdio.h>
#define HashLength 13
//��ϣ����
int HashFuc(int i,int length)
{
	return i%length;
}
//����̽����ɢ��
int *HashReLineExplor(int A[], int k,int h[],int m)//�ؼ������顢�ؼ��ָ�������ϣ����ϣ����
{
    int i,j,loc;
	for ( i = 0; i < m; i++)
		h[i] = NULL;
	for ( j = 0; j < k; j++)
	{
		loc = HashFuc(A[j], HashLength);
		while (h[loc])
		{
			loc=loc++%m;	//Ѱ�ҵ�һ����λ��
		}
		h[loc] = A[j];
	}
	return h;
}

int main()
{
    int i;
	int Hash[30];//��ϣ��
	int Key[12] = { 19,14,23,1,68,20,84,27,56,11,10,79 };	//�ؼ���
	HashReLineExplor(Key, 12, Hash, 30);
	for (i = 0; i < 30; i++)
	{
		if (Hash[i])
		{
			printf("��%2d��Ԫ����:%4d\n", i, Hash[i]);
		}
	}
	return 0;
}

#include<stdio.h>
int main()
{
	char str[50],*p=str;
    int i,k=0,key=0,sum,a[100]={0};
	gets(str);
	for(i=0;*(p+i)!='\0';i++)
	{
		if((*(p+i)>='0')&&(*(p+i)<='9'))
		{
			sum=k+1;
			a[k]=a[k]*10+*(p+i)-'0';
			key=1;
		}
		else if(key)
		{
   			a[++k]=0;
			key=0;
		}
	}
	for(i=0;i<sum;i++)
	printf("%d\n",a[i]);
	printf("sum=%d\n",sum);	
	return 0;	
}	

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
 char data[30];
 int lenth;
}str;
 str *creat()
 {
    str *s;
    s=malloc(sizeof(str));
    s->lenth=0;
    return s;
 }
void assert_(str *s,char a[])
{
    int i;
   int len=strlen(a);
   s->lenth=len;
   for(i=0;i<len;i++)
   {
      s->data[i]=a[i];
   }
}
int StrConcat(str *s,str *s1,char s2[])
{
   int len_s,len_s1,len_s2,i,j;
   len_s=s->lenth;
   len_s1=s1->lenth;
   for( i=0;i<len_s;i++)
   {
       s2[i]=s->data[i];
   }
    i=0;
   for( j=len_s;j<len_s1+len_s;j++)
   {
       s2[j]=s1->data[i];
       i++;
   }
   s2[j]='\0';
}
int StrSub(char a[],str *s,int i,int len)
{
    int j,k=0;
    for(j=i-1;j<i+len-1;j++)
    {
       a[k]=s->data[j];
       k++;
    }
    a[k]='\0';
}
int StrComp(char *q,char *p)
{
    int i=0;
    while(q[i]==p[i] && q[i]!='\0')i++;
    return (q[i]-p[i]);
}
int StrIndex(char *s,char *s1)
{
    int i=0,j=0;
    while(s[i]!='\0'&&s1[j]!='\0')
     if(s[i]==s1[j])
     { ++i;++j;}
     else
     {i=i-j+1;j=0;}
     if(s1[j]=='\0')
     return i-j;
     else return -1;
}
void show(str *s)
{
   int i;
   for(i=0;i<s->lenth;i++)
   {
    printf("%c",s->data[i]);
   }
   printf("\n");
}
int main(int argc, char *argv[])
{
    int i=0,j,k;
     char a[5],b[5];
	char c[10],d[10],e[10],f[5];
    str *s;
    str *s1;
    s=creat();
    s1=creat();
 	
	 a[0]='a';
	 a[1]='b';
	 a[2]='c';
	 a[3]='d';
	 a[4]='e';
	 a[5]='\0';
	 
     b[0]='f';
     b[1]='g';
     b[2]='h';
     b[3]='i';
     b[4]='j';
     b[5]='\0';

     e[0]='a';
	 e[1]='b';
	 e[2]='a';
	 e[3]='b';
	 e[4]='c';
	 e[5]='a';
	 e[6]='b';
	 e[7]='c';
	 e[8]='a';
	 e[9]='c';
	 e[10]='\0';
	
     f[0]='a';
	 f[1]='b';
	 f[2]='c';
	 f[3]='a';
	 f[4]='c';
	 f[5]='\0';
	 
     assert_(s,a);
     assert_(s1,b);
     StrConcat(s,s1,c);
     printf("主串s1为:");
     show(s);
     printf("s2为:");
     show(s1);
     printf("串连接后为:  ");
    while(c[i]!='\0')
     {
        printf("%c",c[i]);
        i++;
     }
     printf("\n");
     j=2;k=3,i=0;
     StrSub(d,s,j,k);
     printf("取子串结果为:  ");
      while(d[i]!='\0')
     {
        printf("%c",d[i]);
        i++;
     }
     printf("\n");
     printf("该子串在主串的位置为：%d\n",StrIndex(a,d));
     
     printf("a与b的大小为：%d",StrComp(a,b));

     i=0;
      while(e[i]!='\0')
     {
        printf("%c ",e[i]);
        i++;
     }
     i=0;
      while(f[i]!='\0')
     {
        printf("%c",f[i]);
        i++;
     }
     printf("该子串在主串的位置为：%d\n",StrIndex(e,f));
     	
}

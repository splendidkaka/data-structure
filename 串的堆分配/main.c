#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 typedef struct
 {
   char *ch;
   int len;
 }HSting;
int assign(HSting *s,char s1)
{
    int i,j;
   if(s->ch)
    free(s->ch);
    i=strlen(s1);
   if(i==0)
   {
     s->ch=NULL;
     s->len=0;
   }
   else
   {
    s->ch=(char *)malloc(i*sizeof(char));
    for(j=0;j<i;j++)
     {
        s->ch[j]=s1[j];
     }
     s->len=j;
   }
   return 1;
}
int StringCom(HString *s,HString s1)
{
    int i=0;
    while(s->ch[i]==s1->ch[i] &&s->ch[i]!'\0')
    i++;
        return (s->ch[i]-s1->ch[i]);
}
int StrConcat(HsString *s,HSting *s1,char s2[])
{
   int len_s,len_s1,len_s2,i,j;
   len_s=s->len;
   len_s1=s1->len;
   for( i=0;i<len_s;i++)
   {
       s2[i]=s->ch[i];
   }
    i=0;
   for( j=len_s;j<len_s1+len_s;j++)
   {
       s2[j]=s1->ch[i];
       i++;
   }
   s2[j]='\0';
}
int StrSub(char a[],HSting *s,int i,int len1)
{
    int j,k=0;
    for(j=i-1;j<i+len1-1;j++)
    {
       a[k]=s->ch[j];
       k++;
    }
    a[k]='\0';
}
void show(HString *s)
{
   int i;
   for(i=0;i<s->len;i++)
   {
    printf("%c",s->ch[i]);
   }
   printf("\n");
}

int main(int argc, char *argv[])
{
	
}

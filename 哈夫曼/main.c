#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXVALUE 10000
#define MAXLEAF 30
#define MAXNODE MAXLEAF*2-1
typedef struct
{
    int weight;
    int parent;
    int lchild;
    int rchild;
    char data;
}HNode,HuffmanTree[MAXNODE];
typedef struct
{
    char data;
    char code[10];
}HCNODE,HCNode[MAXNODE];
void Creat(HuffmanTree ht)
{ int i;
  for(i=0;i<MAXNODE;i++)
  ht=(HNode*)malloc(sizeof(HNode));
}
void Creat1(HCNode hc)
{ int i;
  for(i=0;i<MAXNODE;i++)
  hc=(HCNODE*)malloc(sizeof(HCNODE));
}
void CrtHuffmanTree(HuffmanTree ht,int w[],char ch[],int n)
{
    int i,j,m1,m2,x1,x2;
    for(i=0;i<2*n-1;i++)
    {
        ht[i].weight=0;
        ht[i].parent=-1;
        ht[i].lchild=-1;
        ht[i].rchild=-1;
        ht[i].data=NULL;
    }
    for(i=0;i<n;i++)ht[i].data=ch[i];
    for(i=0;i<n;i++)ht[i].weight=w[i];
    for(i=0;i<n-1;i++)
    {
        m1=m2=MAXVALUE;
        x1=x2=0;
        for(j=0;j<n+i;j++)
        {
            if(ht[j].weight<m1&&ht[j].parent==-1)
            {
                m2=m1;
                x2=x1;
                x1=j;
                m1=ht[j].weight;
            }
            else if(ht[j].weight<m2&&ht[j].parent==-1)
            {
                m2=ht[j].weight;
                x2=j;
            }
        }
        ht[x1].parent=n+i;ht[x2].parent=n+i;
        ht[n+i].weight=ht[x1].weight+ht[x2].weight;
        ht[n+i].lchild=x1;ht[n+i].rchild=x2;
    }
}
void printhuffmantree(HuffmanTree ht,int n)
{int k;
printf("\n  data  weight   parent   lchild    rchild");
for(k=0;k<2*n-1;k++)
printf("\n  %c   %d      %d         %d         %d",ht[k].data,ht[k].weight,ht[k].parent,ht[k].lchild,ht[k].rchild);
printf("\n");
}

int Code(HuffmanTree HT,HCNode HC)
{
    char str[10];
    char b,t;
	int i = 0,count=0,len,j,k,q,p=0;
	for (;;i++)
	{
	
		int j = i;
		HC[i].data = HT[i].data;
        count=0;
		while (HT[j].parent!=-1)
		{
		
			if (HT[HT[j].parent].lchild == j)  //完成左分支0，右分支1
			{
			    str[count++]='0';                	
			}
			else
			{
				str[count++]='1';
			}
			j = HT[j].parent;
		}
		str[count]='\0';
	    len=strlen(str);
    	for(q=0;q<len/2;q++)
        {	
		t=str[q];
		str[q]=str[len-q-1];
		str[len-q-1]=t;		
        }
        strcpy(HC[i].code,str);
        while(str[p++]!='\0')
        {
            str[p-1]='\0';
        }
	   // for(k=0;k<strlen(str);k++)
		//HC[i].code[k] = str[k];
		if (HT[i].lchild == -1 && HT[i].rchild == -1)continue;
		else break;    //退出条件
	}
	return i;
}
/*void test(HCNode HC)
{
    char str[10];
    char t;
    int len,q;
    str[0]='1';
    str[1]='2';
    str[2]='\0';
	    len=strlen(str);
    	for(q=0;q<len/2;q++)
        {	
		t=str[q];
		str[q]=str[len-q-1];
		str[len-q-1]=t;		
        }
    strcpy(HC[0].code,str);
} */
void Encode(HuffmanTree HT)
{
    int j,i;
    char str[20];
	//string s;
	int root=0;
    printf("input");
    gets(str);
	while (HT[root].parent != -1) root++;
	j = root;
	for (i=0;i<strlen(str);i++)
	{
		if ('0' == str[i])
		{
			j = HT[j].lchild;
		}
		else
		{
			j = HT[j].rchild;
		}
		if (HT[j].lchild == -1 && HT[j].rchild == -1)
		{
			//cout << HT[j].data;
			printf("%c",HT[j].data);
			j = root;
		}
	}
	return 0;
}
main()
{
    char *ch;
    int *w;
    int n,j,k,l,i;
    HuffmanTree ht;
    HCNode hc;
    Creat(ht);
    Creat1(hc);
    printf("请输入字符个数\n");
    scanf("%d",&n);
    w=(int*)malloc(n*sizeof(int));
    ch=(char*)malloc(n*sizeof(char));
    for(j=0;j<n;j++)
    {
        printf("输入第%d个字符的权值",j);
        scanf("%d",&w[j]);

    }
     getchar();
     for(j=0;j<n;j++)
    {
        printf("输入第%d个字符",j);
        scanf("%c",&ch[j]);
        getchar();
    }
    

    CrtHuffmanTree(ht,w,ch,n);
    printhuffmantree(ht,n);
   l=Code(ht,hc);
  for(i=0;i<l;i++)
   {
       printf("%c:",hc[i].data);
       puts(hc[i].code);
   }
   //printf("%c",hc[1].code[0]);

   //test(hc);
   //puts(hc[0].code);
   Encode(ht);
}

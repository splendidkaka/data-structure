#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct
{
 int data[MAXSIZE];
 int top;
}Sestack;
Sestack *creat()
{
  Sestack *s;
  s=malloc(sizeof(Sestack));
  s->top=-1;
  return s;
}
int empty(Sestack *s)
{
   if(s->top==-1)
   return 1;
   else
   return 0;
}
int push(Sestack *s,char x)
{
  if(s->top==MAXSIZE-1)return 0;
  else{
       s->top++;
       s->data[s->top]=x;
       return 1;
  }
}
int push1(Sestack *s,int x)
{
  if(s->top==MAXSIZE-1)return 0;
  else{
       s->top++;
       s->data[s->top]=x;
       return 1;
  }
}
int pop(Sestack *s,char x)
{
   if(empty(s)) return 0;
   else
   {
      x=s->data[s->top];
      s->top--;
   }
   return x;
}
int pop1(Sestack *s,int x)
{
   if(empty(s)) return 0;
   else
   {
      x=s->data[s->top];
      s->top--;
   }
   return x;
}
int top(Sestack *s)
{
  if(empty(s))return 0;
  else return(s->data[s->top]);
}
void output( Sestack *s,int x)
{
  int i;
  for(i=s->top;i>=0;i--)
  printf("%d",s[i]);

}
int judge_inum(char x)
{
   if(x>='0' && x<='9')
     return 1;
   else
   return 0;
}
int reform_num(char x)
{
     int i;
     i=x-48;
     return i;
}
char reform_str(int i)
{
     char a;
     a=i+48;
     return a;
}
int judge_correct(char *s)
{
    char *x;
   int i=1,flag=1;
   Sestack *s1;
   s1=creat();
   while(s[i]!='#'&&flag)
   {
       if(s[i]=='(')
       push(s1,s[i]);
       if(s[i]==')')
       if(pop(s1,x)!='(')
       flag=0;
       i++;
   }
   if(!empty(s1))
   flag=0;
   return flag;
}
int judge_operator(char a,char b)
 {
    if((a=='*'||a=='/')&&(b=='+'||b=='-'))
    return 1;
    else
    return 0;
 }
 void reform_(char *s1,char *s2)
 {
    char a;
    int i,j=0;
    char x;
    Sestack *s;
    s=creat();
    i=1;
    while(s1[i]!='#')
    {
       if(judge_inum(s1[i]))
       {    s2[j]=s1[i];
              j++;
       }
       else
       {
           if(s1[i]=='(')
              push(s,s1[i]);
            if(s1[i]==')')
              while((x=pop(s,a))!='(')
                {
                  s2[j]=x;
                   j++;
                }
                if(s1[i]=='+'||s1[i]=='-'||s1[i]=='*'||s1[i]=='/')
                {
                  while(!(empty(s)||s->data[s->top]=='('||judge_operator(s1[i],s->data[s->top])))
                   s2[j++]=pop(s,a);
                   if((empty(s)||s->data[s->top]=='('||judge_operator(s1[i],s->data[s->top])))
                   
                   push(s,s1[i]);
                }
                 if(!(s1[i]=='+'||s1[i]=='-'||s1[i]=='*'||s1[i]=='/'||s1[i]=='('||s1[i]==')'))
                  printf("错误的运算符");
       }
       i++;
    }
    while(!empty(s))
    s2[j++]=pop(s,a);
    s2[j]='\0';
 }
 int Calculate1(char *s2)
{
    char x;
	int a,b,c,d,i=0;
	Sestack *s;
	s=creat();
	while(s2[i]!='\0')
	{
		if(judge_inum(s2[i]))  //判断是否为数字
		    push(s,s2[i++]);
		else
		{
			b=reform_num(pop(s,x));  //将输入时的字符串转换为数字再计算
			a=reform_num(pop(s,x));
		    switch(s2[i++])
		    {
		    	case'+':c=a+b;push(s,reform_str(c));break;
		    	case'-':c=a-b;push(s,reform_str(c));break;
		    	case'*':c=a*b;push(s,reform_str(c));break;
		    	case'/':c=a/b;push(s,reform_str(c));break;
			}                                            //两两计算完后的结果还存在栈中，a,b先出掉
		}
	}
	d=reform_num(pop(s,x));
	return d;
}
int Calculate2(char *s2)
  {
     char x;
     int a,b,c,d,i=0;
     Sestack *s;
     s=creat();
     while(s2[i]!='\0')
     {
       i++;
     }
     i--;
     while(i>=0)
     {
       if(judge_inum(s2[i]))
        push(s,s2[i--]);
        else
        {
          	a=reform_num(pop(s,x));
      		b=reform_num(pop(s,x));

         switch(s2[i--])
		    {
		    	case'+':c=a+b;push(s,reform_str(c));break;
		    	case'-':c=a-b;push(s,reform_str(c));break;
		    	case'*':c=a*b;push(s,reform_str(c));break;
		    	case'/':c=a/b;push(s,reform_str(c));break;
	         }
	       }
     }
     	d=reform_num(pop(s,x));
        return d;
  }
int Calculate3(char *s2)
 {     char x;
      int  y;
      int  i=0,j=2,n,k=0;
      int a,b,c,d;
      int q1[100];
	  Sestack *s;
	  s=creat();
      StringToInteger(s2,q1);   //要以@结尾
	  while(s2[i]!='\0')
     {
       i++;
     }
     i=i-2;
      while(i>=0)
      {
        if(!(judge_inum(s2[i])))
      {
         if(s2[i]==' '||s2[i]=='@')
          {
             i--;
             n=len(q1[j]);
             push1(s,q1[j--]);
            while(n!=0)
            {
             i--;
             n--;
            }
          }
           else{
             a=(pop1(s,y));
      		 b=(pop1(s,y));
                switch(s2[i--])
		    {
		    	case'+':c=a+b;push1(s,c);break;
		    	case'-':c=a-b;push1(s,c);break;
		    	case'*':c=a*b;push1(s,c);break;
		    	case'/':c=a/b;push1(s,c);break;
	         }
	          }
      }
        else
        {
          n=len(q1[j]);
          push1(s,q1[j--]);
          while(n!=0)
          {
             i--;
             n--;
          }
        }
      }
       /*
      push1(s,q1[2]);
      push1(s,q1[1]);
      a=(pop1(s,y));
	  b=(pop1(s,y));
	  c=a+b;push1(s,c);
	  push1(s,q1[0]);
	  a=(pop1(s,y));
	  b=(pop1(s,y));
	  c=a-b;push1(s,c);*/
      return s->data[0];
 }

int *StringToInteger(char *p,int *q)
{
	int num = 0,i=0;
	while (*p != '\0')
	{
		if ((*p >= '0') && (*p <= '9'))
		{
			num = num * 10 + *p - '0';
		}

        else
      {
       if(num!=0)
   {    q[i]=num;
         num=0;
         i++;
   }
      }
      p++;
	}
      q[i]='\0';
}
int len(int n)
{
    int len1=0;
	  while(n>0){
		len1++;
		n=n/10;
	}
	return len1;
}
int main()
{
	int answer;
	int q1[100];
	char s1[MAXSIZE],s2[MAXSIZE];
	printf("请输入要计算表达式  1为前缀表达式,2为一般表达式,3为后缀表达式,4为多位数表达式:\n");
	scanf("%d",&n);
	getchar();
	gets(s1);
	switch(n)
{	
 case 1:  { answer=Calculate2(s1);printf("最终的结果为%d\n",answer);return 0;break;}
 case 2:	
     {	
	if(!(judge_correct(s1)))
	{
		printf("false 括号出错");
		return 0;
	}
	else
	{   	
	    reform_(s1,s2);
	    printf("后缀表达式为:");
	    puts(s2);
	    answer=Calculate1(s2);
	    printf("最终的结果为%d\n",answer);
	    return 0;
	}
	break;
}
   case	3:
       {answer=Calculate1(s1);printf("最终的结果为%d\n",answer); return 0; break;}
   case 4:   { answer=Calculate3(s1);printf("多位表达式为%d\n:",answer);break;}
}
}

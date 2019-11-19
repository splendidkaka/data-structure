#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct
  {
    int data[MAXSIZE];
    int top;
  }Sestack
Sestack *creat()
{
  Sestack *s;
  s=malloc(sizeof(Sestack));
  s->top=-1;
  return s;
}
int empty(Seqstack *s)
{
   if(s->top==-1)
   return 1;
   else
   return 0;
}
int push(Seqstack *s,int x)
{
  if(s->top==MAXSIZE-1)return 0;
  else{
       s->top++;
       s->data[s->top]=x;
       return 1;
  }
}
int pop(Seqstack *s,int *s)
{
   if(empty(s)) return 0;
   else
   {
      *x=s->data[s->top];
      s->top--;
      return 1;
   }
int top(Seqstack)
{
  if(empty(s))return 0;
  else return(s->data[s->top])
}
}
void output( Sqstack *s,int x)
{
  int i;
  for(i=s->top;i>=0;i--)
  printf("%d",s[i]);
  
}
int main(int argc, char *argv[])
{
    int n,x;
    Seqstack *q,p;
    q=creat();
    printf(" ‰»ÎN");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       scanf("%d",&x);
       push(q,x);
    }
}

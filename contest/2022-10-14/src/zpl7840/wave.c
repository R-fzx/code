#include <stdio.h>

FILE *fp,*fo;

long n,c,hash[25]={0},a[25]={0},s=0;

long dfs(long l)
{
 long i=1,y=n,flag=0;
 
 if(l<=n)
  {
   if(l>2)
    {
     if(a[l-1]>a[l-2])
      i=1,y=a[l-1]-1;
     else 
      i=a[l-1]+1,y=n;
    }
   for(;i<=y;i++)
     if(hash[i]==0)
      {
       hash[i]=1;
       a[l]=i;
       flag=dfs(l+1);
       a[l]=0;
       hash[i]=0;
       if(flag)
        return 1;
      }
  }
 else
  {
   s++;
   if(s==c)
    {
     for(i=1;i<n;i++)
       fprintf(fo,"%ld ",a[i]);
     fprintf(fo,"%ld",a[n]);
     fprintf(fo,"\n");
     return 1;      
    }   
  }
 return 0;
}

void work()
{
 fscanf(fp,"%ld%ld",&n,&c);
 s=0;
 dfs(1);
}

int main()
{
 long n,i,j,k,t;
 
 fp=fopen("wave.in","r");
 fo=fopen("wave.out","w");
 
 fscanf(fp,"%ld",&n);
 
 for(i=1;i<=n;i++)
    work();
 
 fclose(fp);
 fclose(fo);
}

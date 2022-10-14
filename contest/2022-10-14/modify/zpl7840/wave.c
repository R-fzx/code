#include <stdio.h>

long long f[25][25][2]={0};
FILE *fp,*fo;

void work()
{
 long long n,c,i,j,hash[25]={0},flag=1,a[25]={0},o=0,b[25]={0},t,x,y,k;
 
 fscanf(fp,"%I64d%I64d",&n,&c);
 x=n;
 y=1;
 
 for(i=n;i>=n;i--)
   for(j=x;j>=y;j--)
     {
      if(c>f[i][j][1])
       c-=f[i][j][1];
      else
       {
        for(k=n,t=1;k>=1&&t<=j;k--)
          if(hash[k]==0)
           t++;
        k++;
        hash[k]=1;
        fprintf(fo,"%I64d ",k);
        x=i-1;
        y=j;
        flag=0;
        break;
       }
      if(c>f[i][j][0])
       c-=f[i][j][0];
      else
       {
        for(k=n,t=1;k>=1&&t<=j;k--)
          if(hash[k]==0)
           t++;
        k++;
        hash[k]=1;
        fprintf(fo,"%I64d ",k);
        x=j-1;
        y=1;
        flag=1;
        break;
       }
     }
 
 for(i=n-1;i>=1;i--)
   {
    for(j=x;j>=y;j--)
      {
       if(c>f[i][j][1]&&flag==1)
        c-=f[i][j][1];
       else if(flag==1)
        {
         for(k=n,t=1;k>=1&&t<=j;k--)
          if(hash[k]==0)
           t++;
         k++;
         hash[k]=1;
         fprintf(fo,"%I64d ",k);
         x=i-1;
         y=j;
         flag=0;
         break;
        }
       if(c>f[i][j][0]&&flag==0)
        c-=f[i][j][0];
       else if(flag==0)
        {
         for(k=n,t=1;k>=1&&t<=j;k--)
          if(hash[k]==0)
           t++;
         k++;
         hash[k]=1;
         fprintf(fo,"%I64d ",k);
         x=j-1;
         y=1;
         flag=1;
         break;
        }
      }
   }    
 
 fprintf(fo,"\n");
 
}

int main()
{
 long k,i,j,n,sum=0;
 
 fp=fopen("wave.in","r");
 fo=fopen("wave.out","w");
 
 f[1][1][0]=1;
 f[1][1][1]=1;
 
 for(i=2;i<=20;i++)
   for(j=1;j<=i;j++)
     {
      for(k=1;k<j;k++)
       f[i][j][0]+=f[i-1][k][1];
      for(k=j;k<=i-1;k++)
       f[i][j][1]+=f[i-1][k][0];
     }
 
 fscanf(fp,"%I64d",&n);
 for(i=1;i<=n;i++)
   work();
 
 fclose(fp);
 fclose(fo);
 return 0;
}

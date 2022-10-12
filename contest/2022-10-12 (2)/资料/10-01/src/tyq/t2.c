#include<stdio.h>
#include<stdlib.h>
long long a,b,ans,max;
long long g[1000],p[1000],s;
int main()
{
    long long u,i,j,k;
    freopen("t2.in","r",stdin);
    freopen("t2.out","w",stdout);
    
    
    scanf("%I64d%I64d",&a,&b);
    
    while(a!=0&&b!=0)
    {
     memset(g,0,sizeof(g));
     memset(p,0,sizeof(p));
     s=0;
     for(k=3;k<=60;k++)
     {
      s=1;
      if(k==40)
       i++,i--;
      for(i=2;s<=b;i++)
      {
       s=1;
       for(j=0;j<k;j++)
       {
        s*=i;
        if(s>b)
         break;
       }
      if(k==51)
       i++,i--;
       if(s<=b)
        p[k]++;
       else
        break;
      }
      i++,i--;
     }
     p[2]=sqrt(b)+0.0001-1;
     p[1]=b-1;
     
     for(k=60;k>=1;k--)
     {
      if(k==1)
       i++,i--;
      g[k]=p[k];
      for(i=2;i*k<=60;i++)
       g[k]-=g[i*k];
     }
     ans=0;
     for(k=60;k>=1;k--)
      ans+=g[k]*k;

     if(b==6)
      i++,i--;
     b=a-1;
     if(b==1)
     {
      printf("%I64d\n",ans);
      scanf("%I64d%I64d",&a,&b);
      continue;
     }
     memset(g,0,sizeof(g));
     memset(p,0,sizeof(p));
     s=0;
     for(k=3;k<=60;k++)
     {
      s=1;
      for(i=2;s<=b;i++)
      {
       s=1;
       for(j=0;j<k;j++)
       {
        if(s>b)
         break;
        s*=i;
       }
       if(s<=b)
        p[k]++;
      }
      i++,i--;
     }
     p[2]=sqrt(b)+0.0001-1;
     p[1]=b-1;
     
     if(b==2)
      i++,i--;
     for(k=60;k>=1;k--)
     {
      g[k]=p[k];
      for(i=2;i*k<=60;i++)
       g[k]-=g[i*k];
     }
     if(b==2)
      i++,i--;
     for(k=60;k>=1;k--)
      ans-=g[k]*k;
     printf("%I64d\n",ans);
     scanf("%I64d%I64d",&a,&b);
    }
    return 0;
}

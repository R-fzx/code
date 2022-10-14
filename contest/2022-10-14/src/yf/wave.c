#include"stdio.h"
long long i,j,k,l,m,n,c,t;
long long a[100],hash[100];
long long fun(long long now,long long flag,long long tot)
{
  long long i;
  if(tot==n)
    {
      t++;
      if(t==c)return 1;
      return 0;
    }
  if(flag)
    {
      for(i=1;i<now;i++)
        if(hash[i]==0)
          {
            a[tot+1]=i;
            hash[i]=1;
            if(fun(i,1-flag,tot+1))return 1;
            hash[i]=0;
          }
    }
    else for(i=now+1;i<=n;i++)
      if(hash[i]==0)
        {
          a[tot+1]=i;
          hash[i]=1;
          if(fun(i,1-flag,tot+1))return 1;
          hash[i]=0;
        }
  return 0;
}
main()
{
  FILE *fp,*fq;
  fp=fopen("wave.in","r");
  fq=fopen("wave.out","w");
  fscanf(fp,"%I64d",&m);
  for(i=1;i<=m;i++)
    {
      fscanf(fp,"%I64d%I64d",&n,&c);
      t=0;
      for(j=1;j<=n;j++)
        {
          a[1]=j;hash[j]=1;
          if(fun(j,1,1))
            {
              fprintf(fq,"%I64d",a[1]);
              hash[a[1]]=0;
              for(k=2;k<=n;k++)
                {fprintf(fq," %I64d",a[k]);hash[a[k]]=0;}
              fprintf(fq,"\n");
              break;
            }
          if(fun(j,0,1))
            {
              fprintf(fq,"%I64d",a[1]);
              hash[a[1]]=0;
              for(k=2;k<=n;k++)
                {fprintf(fq," %I64d",a[k]);hash[a[k]]=0;}
              fprintf(fq,"\n");
              break;
            }
          hash[j]=0;
        }
    }
  fclose(fp);
  fclose(fq);
  return 0;
}

#include <stdio.h>
FILE *fp,*fo;
long long n,m,i,j,k,l,c,s=0,a[31]={0},hash[31]={0},f[31][31][2]={0};
long long dfs(long long k)
{long long i,j,l;
 if(k<=n)
 {for(i=1;i<a[k-1];i++)
   if(!hash[i]&&(k==2||a[k-2]<a[k-1]))
   {a[k]=i;
    hash[i]=1;
    if(dfs(k+1))return(1);
    a[k]=0;
    hash[i]=0;
   }
          for(i=a[k-1]+1;i<=n;i++)
   if(!hash[i]&&(k==2||a[k-2]>a[k-1]))
   {a[k]=i;
    hash[i]=1;
    if(dfs(k+1))return(1);
    a[k]=0;
    hash[i]=0;
   }
 }else 
 {s++;
  if(c==s)
  {for(j=1;j<n;j++)fprintf(fo,"%d ",a[j]);
   fprintf(fo,"%d\n",a[j]);
   return 1;
  }
 }
 return 0;
} 
long long get(long long p)
{long long i,j;
 for(i=1,j=0;i<=n;i++)
   if(hash[i]==0)
   {j++;
    if(j==p){hash[i]=1;return(i);}
   }
}    
main()
{fp=fopen("wave.in","r");
 fo=fopen("wave.out","w");
 fscanf(fp,"%I64d",&m);
 n=20;
 f[1][1][0]=1;
 f[1][1][1]=1;
 for(i=2;i<=n;i++)
   for(j=1;j<=i;j++)
   {for(k=1;k<j;k++)
      f[i][j][1]+=f[i-1][k][0];
    for(k=j;k<i;k++)
      f[i][j][0]+=f[i-1][k][1];
   }
 for(;m>0;m--)
 {fscanf(fp,"%I64d%I64d",&n,&c);
  if(n==1)fprintf(fo,"1\n");
  else if(n<5)
  {
  s=0;
  for(j=0;j<=n;j++)hash[j]=0;
  for(a[1]=1;a[1]<=n&&s<c;a[1]++){hash[a[1]]=1;dfs(2);hash[a[1]]=0;}
  }else
  {long long s=1;
   a[1]=1;
   for(j=0;j<=n;j++)hash[j]=0;
   for(i=1;i<n;i++)
     if(f[n][i][0]+f[n][i][1]+s>c)break;
   else 
   {a[1]++;
    s+=f[n][i][0]+f[n][i][1];
   }
   hash[a[1]]=1;
   a[2]=1;
   for(i=1;i<n-1;i++)
     if(i<a[1])
     {if(f[n-1][i][0]+s>c)break;
      else 
      {s+=f[n-1][i][0];
       a[2]++;
      }
     }else 
      if(f[n-1][i][1]+s>c)break;
      else {s+=f[n-1][i][1];a[2]++;}
   a[2]=get(a[2]);
   for(i=3;i<=n;i++)
   {long long l=0;
    for(j=1;j<=a[i-1];j++)
     if(!hash[j])l++;
    if(a[i-2]<a[i-1])
    {a[i]=1;
     for(j=1;j<l;j++)
      if(s+f[n-i+1][j][0]>c)break;
     else 
     {s+=f[n-i+1][j][0];
      a[i]++;
     }
    }else 
     {a[i]=l+1;
      for(j=l+1;j<=n-i;j++)
       if(s+f[n-i+1][j][1]>c)break;
      else
      {s+=f[n-i+1][j][1];
       a[i]++;
      }
     }
    a[i]=get(a[i]);
   }      
   fprintf(fo,"%I64d",a[1]);
   for(i=2;i<=n;i++)fprintf(fo," %I64d",a[i]);
   fprintf(fo,"\n");
  }    
  
 } 
 fclose(fp);
 fclose(fo);
} 

#include <stdio.h>
FILE *fp,*fo;
int n,m,i,j,k,l,c,s=0,a[21]={0},hash[21]={0};
int dfs(int k)
{int i,j,l;
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
 
main()
{fp=fopen("wave.in","r");
 fo=fopen("wave.out","w");
 fscanf(fp,"%d",&m);
 for(i=1;i<=m;i++)
 {fscanf(fp,"%d%d",&n,&c);
  s=0;
  for(j=0;j<=n;j++)hash[j]=0;
  for(a[1]=1;a[1]<=n&&s<c;a[1]++){hash[a[1]]=1;dfs(2);hash[a[1]]=0;}
 } 
 fclose(fp);
 fclose(fo);
} 

#include <stdio.h>
int n,m,c;
int hash[51]={0},a[51]={0},ans;
FILE *in,*out;

void dfs(int now,int num)
{
     int i;
     
     if (now<=num)
     {
     for (i=1;i<=num;i++)
     if (hash[i]==0)
     {
        hash[i]=1;
        
        a[now]=i;
        
        if ( now>=3 )
        {
           if (a[now] < a[now-1] && a[now-2]<a[now-1])
              dfs(now+1,num);
           else if (a[now] > a[now-1] && a[now-2]>a[now-1] )
                dfs(now+1,num);
        }
        else
            dfs(now+1,num);
        
        a[now]=0;
        
        hash[i]=0;
        if (ans==c) break;
     }
     }
     else
     {
         ans++;
         if (ans==c)
         {
            for (i=1;i<n;i++)
              fprintf(out,"%d ",a[i]);
            fprintf(out,"%d\n",a[i]);
            return ;
         }
     }
}

main()
{
      int i,j,k;
      
      
      in=fopen("wave.in","r");
      out=fopen("wave.out","w");
        
        fscanf(in,"%d",&m);
        
        for (i=1;i<=m;i++)
        {
            fscanf(in,"%d%d",&n,&c);
            ans=0;
            for (j=0;j<=n;j++)      hash[j]=0;
            dfs(1,n);
        }
        
      fclose(in);
      fclose(out);
}

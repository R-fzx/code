#include <stdio.h>
FILE *out;
int hash[101]={0},ans=0;
int a[101]={0};

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
     }
     }
     else ans++;
}
main()
{
      int i;
      out=fopen("data.out","w");
      
      for (i=3;i<=12;i++)
      {
          ans=0;
          dfs(1,i);
          fprintf(out,"%d\n",ans);
      }
      fclose(out);
}

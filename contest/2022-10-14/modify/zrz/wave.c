#include <stdio.h>
#define MAX 25
long n,hash[MAX]={0},a[MAX]={0},flag=0;
double  c,sum,f[MAX][MAX][3]={0};
FILE *fp,*fo;
double dfs(long i,long j,long k)
{
     long t,p;
     if(i==n+1)
     {
         sum++;
         if(sum==c)
         {
             for(t=1;t<n;t++)
               fprintf(fo,"%ld ",a[t]);
             fprintf(fo,"%ld\n",a[n]);
             flag=1;
             return(0);        
         } 
         else
             return(1);         
     }
     if(flag) return(0);
     if(f[i][j][k]>0)
     {
          if(sum+f[i][j][k]<c)
          {
              sum+=f[i][j][k];
              return(f[i][j][k]);                
          }
     }
     if(k==0)
     {
          for(t=1,p=0;t<=n;t++)
            if(hash[t]==0)
            {
                p++;
                hash[t]=1;
                a[i]=t;
                if(t<a[i-1])  f[i][j][k]+=dfs(i+1,p,1);
                else  f[i][j][k]+=dfs(i+1,p,2);
                hash[t]=0;
                if(flag) break;              
            }    
     }
     else if(k==1)
     {
         for(t=1,p=0;t<=n;t++)
            if(hash[t]==0)
            {
                p++;
                if(t>a[i-1])
                {
                    hash[t]=1;
                    a[i]=t;
                    f[i][j][k]+=dfs(i+1,p,2);
                    hash[t]=0;              
                }
                if(flag) break;
            }     
     }
     else if(k==2)
     {
         for(t=1,p=0;t<=n;t++)
            if(hash[t]==0)
            {
                p++;
                if(t<a[i-1])
                {
                    hash[t]=1;
                    a[i]=t;
                    f[i][j][k]+=dfs(i+1,p,1);
                    hash[t]=0;
                }
                if(flag)  break;                        
            }     
     }
     return(f[i][j][k]);
}
main()
{
     long m,i;
     fp=fopen("wave.in","r");
     fo=fopen("wave.out","w");
     fscanf(fp,"%ld",&m);
     for(;m>0;m--)
     {
          fscanf(fp,"%ld%lf",&n,&c);
          memset(hash,0,sizeof(hash));
          memset(f,0,sizeof(f));
          flag=0;
          sum=0;
          for(i=1;i<=n;i++)
          {
              a[1]=i;
              hash[i]=1;
              dfs(2,i,0); 
              hash[i]=0;
              if(flag)
                 break;                
          }
     } 
     fclose(fp);
     fclose(fo);    
}

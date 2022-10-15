//冗长，dfs与dfs2，p与p2都可以合并，二进制枚举更简洁。 
#include <stdio.h>
#include <stdlib.h>
double max=0.0,x,y,z,sum,aaa;
int i,j,k,n,aa,bb=0;
int a[10],b[10],c[10],d[10],e[10],yes[10];

void dfs(int deep,int alr,int need,double now)
{
     //printf("%d %d %d %lf\n",deep,alr,need,now);
     if (deep>n)
     {
        sum+=now;
        //printf("%lf\n",now);
        return;
     }
     
     int i;
     double y,z;
     
     y=(double)(c[deep]+a[deep]);
     z=y/10.0;
     
     if (need-alr<=n-deep)
        dfs(deep+1,alr,need,now*z);
     
     if (need-alr>0)
     {
        dfs(deep+1,alr+1,need,now*(1-z));
     }
}

double p(void)
{
    int i,j;
    double x=0.0;
    
    j=n/2;
    if (n%2==0)
       j--;
    
    for (i=0; i<=j; i++)
    {
        sum=0.0;
        dfs(1,0,i,1.0);
        //printf("%d %lf\n",i,sum);
        x+=sum;
    }
    
    return x;
}

void dfs2(int deep,int alr,int need,double now,int bsum)
{
     int i;
     double y,z,zz;
     
     if (deep>n)
     {
        //printf("%d\n",bsum);
        y=(double)bsum;
        z=(double)aa;
        zz=z/(z+y);
        sum+=now*zz;
        return;
     }
     
     y=(double)(10-a[deep]-c[deep]);
     z=y/10;
     
     if (need-alr<=n-deep)
        dfs2(deep+1,alr,need,now*(1-z),bsum);
     
     if (need-alr>0)
     {
        dfs2(deep+1,alr+1,need,now*z,bsum+b[deep]);
     }
}

double p2(void)
{
       int i,j;
       double x=0.0;
       
       j=n/2;
       if (n%2!=0)
         j++;
    
       for (i=j; i<=n; i++)
       {
           sum=0.0;
           dfs2(1,0,i,1.0,0);
           //printf("%d %lf\n",i,sum);
           x+=sum;
       }
       
       return x;
}

void youbet(int deep,int sent,int num)
{
     //printf("%d %d %d\n",deep,sent,num);
     double x;
     int i;
     
     if (deep>n)
     {
        x=p()+p2(); 
        if (x>max)
        {
           //printf("%lf\n",x);
           max=x;
           for (i=1; i<=n; i++)
           {
               //printf("%d ",a[i]+c[i]);
               d[i]=c[i]+a[i];
           }
           //printf("\n");
        }
        
        return;
     }
     
     for (i=num-sent; i>=0; i--)
     {
         c[deep]=i;
         if (c[deep]+a[deep]>10)
            c[deep]=10-a[deep];
         youbet(deep+1,sent+i,num);
     }
}

int main()
{
    freopen("assembly.in","r",stdin);
    freopen("assembly.out","w",stdout);
    
    scanf("%d%d%d",&n,&k,&aa);
    
    for (i=1; i<=n; i++)
    {
        scanf("%d%d",&b[i],&a[i]);
        a[i]/=10;
    }
    
    youbet(1,0,k);
    
    //y=max+p2();
    
    printf("%.6lf\n",max);
    //system("pause");
    return 0;
}


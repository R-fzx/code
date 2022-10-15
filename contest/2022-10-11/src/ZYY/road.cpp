#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long i,j,k,n,m,x,y,xx,yy,xxx,yyy;
long long sum=0,allmax1,allmax2,inmax,x1,x2,num1,num2,min=200000003;
long long st[50005][4]={0};
long long visit[300];
long long len[300]={0};
long long fa[300]={0};
long long max[500]={0};
long long p,q;

long long minimum(long long a,long long b)
{
    return a<b?a:b;
}

long long f(long long v)
{
    if (fa[v]==0)
       return v;
    else
        return f(fa[v]);
}

void updown(long long v,long long w,long long l)
{
     if (w==0)
        return;
     
     updown(w,fa[w],len[w]); 
     fa[w]=v;
     len[w]=l;
}

long long pos(long long l,long long r,long long val)
{
    if (l==r)
       return l;
    
    long long mid=(l+r)/2;;
    
    if (max[mid]>val)
       return pos(mid+1,r,val);
    else
        return pos(l,mid,val);
}

void ins(long long val)
{
     long long i,j;
     
     sum++;
     if (sum==1)
        max[1]=val;
     else
     {
         i=pos(1,sum-1,val);
         for (j=sum; j>i; j--)
             max[j]=max[j-1];
         
         max[i]=val;
     } 
}

void del(long long val)
{
     long long i,j;
     
     i=pos(1,sum,val);
     for (j=i; j<sum; j++)
         max[j]=max[j+1];
     sum--;
}

void sw(long long a,long long b)
{
     long long t;
     
     t=st[a][0];
     st[a][0]=st[b][0];
     st[b][0]=t;
     
     t=st[a][1];
     st[a][1]=st[b][1];
     st[b][1]=t;
     
     t=st[a][2];
     st[a][2]=st[b][2];
     st[b][2]=t;
     
     t=st[a][3];
     st[a][3]=st[b][3];
     st[b][3]=t;
}
     

void quicksort(long long l,long long r)
{
     if (l>=r)
        return;
     
     long long mid=(l+r)/2,i=l-1,j=r+1;
     long long val=st[mid][2];
     
     while (1==1)
     {
           do
           {
             i++;
           }while (st[i][2]<val);
           
           do
           {
             j--;
           }while (st[j][2]>val);
           
           if (i<j)
              sw(i,j);
           else break;
     }
     
     quicksort(l,j);
     quicksort(j+1,r);
}

long long dis(long long start,long long now,long long target)
{
    if (now==target)
       return 0;
       
    long long i;
    
    i=dis(start,fa[now],target);
    
    if (len[now]>xx)
    {
       xx=len[now];
       if (start==x)
          num1=now;
       else
           num2=now;
    }
    
    return xx;
}  

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    
    scanf("%I64d%I64d",&n,&m);
    scanf("%I64d%I64d",&p,&q);
    for (i=1; i<=m; i++)
    {
        scanf("%I64d%I64d%I64d%I64d",&st[i][0],&st[i][1],&st[i][2],&st[i][3]);
    }

    quicksort(1,m);
    
    sum=1;
    for (i=1; i<=m; i++)
    {
        if (st[i][0]==st[i][1])
           continue;
        //printf("%I64d  %I64d %I64d %I64d %I64d\n",i,st[i][0],st[i][1],st[i][2],st[i][3]);
        //system("pause");
        x=st[i][0];
        y=st[i][1];
        
        xxx=f(x);
        yyy=f(y);
        if (xxx!=yyy)
        {
           updown(x,fa[x],len[x]);
           fa[x]=y;
           len[x]=st[i][3];
           ins(len[x]);
           if (sum==n)
              min=st[i][2]*p+max[1]*q;
        }
        else
        {
            memset(visit,0,sizeof(visit));
            for (j=x; j!=0; j=fa[j])
                visit[j]=1;
            for (j=y; visit[j]==0; j=fa[j]);
            
            xx=0;
            x1=dis(x,x,j);
            xx=0;
            x2=dis(y,y,j);
            
            if (st[i][3]<x1 || st[i][3]<x2)
            {
               if (x1>x2)
               {
                  fa[num1]=0;
                  updown(x,fa[x],len[x]);
                  fa[x]=y;
                  len[x]=st[i][3];
                  del(x1);
               }
               else
               {
                   fa[num2]=0;
                   updown(y,fa[y],len[y]);
                   fa[y]=x;
                   len[y]=st[i][3];
                   del(x2);
               }
               ins(st[i][3]);
               
               min=minimum(min,st[i][2]*p+max[1]*q);
            }
        }
        
    }
    
    if (m==0 && n>1)
       min=-1;
    printf("%I64d\n",min);
    
    //system("pause");
    return 0;
}

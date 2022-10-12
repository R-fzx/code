#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int k,step,step1,sum1,sum2;
int a[500002],b[500002],c[500002],max[500002],tot[500002];
int n,na,nb,nc;
void qs(int l,int r)
{
     int i,j;
     i=l,j=r;
     step=max[(l+r)/2];
     step1=tot[(l+r)/2];
     while(i<=j)
     {
      while(i<=j&&(max[i]>step||max[i]==step&&tot[i]>step1))
       i++;
      while(i<=j&&(step>max[j]||max[j]==step&&step1>tot[j]))
       j--;
      if(i<=j)
      {
       k=a[i];
       a[i]=a[j];
       a[j]=k; 
       k=b[i];
       b[i]=b[j];
       b[j]=k; 
       k=c[i];
       c[i]=c[j];
       c[j]=k;
       k=max[i];
       max[i]=max[j];
       max[j]=k;
       k=tot[i];
       tot[i]=tot[j];
       tot[j]=k;
       i++,j--; 
      }
     }
     if(i<r)
      qs(i,r);
     if(l<j)
      qs(l,j);
}
int main()
{
    int i,j,t;
    freopen("ゆりっぺ.in","r",stdin);
    freopen("ゆりっぺ.out","w",stdout);
    scanf("%d%d%d%d",&n,&na,&nb,&nc);
    for(i=0;i<n;i++)
    {
     max[i]=-2100000000;
     scanf("%d%d%d",&a[i],&b[i],&c[i]);
     if(max[i]<a[i])
      max[i]=a[i];
     if(max[i]<b[i])
      max[i]=b[i];
     if(max[i]<c[i])
      max[i]=c[i];
     tot[i]=a[i]+b[i]+c[i]; 
    }
    qs(0,n-1);
    
    for(i=0;i<n;i++)
    {
     if(na==0||nb==0||nc==0)
      break;
     sum2+=tot[i];
     if(a[i]==max[i])
     {
      na--,sum1+=a[i];
      continue;
     }
     if(b[i]==max[i])
     {
      nb--,sum1+=b[i];
      continue;
     }
     if(c[i]==max[i])
     {
      nc--,sum1+=c[i];
      continue;
     }
    }
    
    for(j=i;j<n;j++)
    {
     max[j]=-2100000000;
     if(na!=0&&max[j]<a[j])
      max[j]=a[j];
     if(nb!=0&&max[j]<b[j])
      max[j]=b[j];
     if(nc!=0&&max[j]<c[j])
      max[j]=c[j];
    }
    qs(i,n-1);
    
    if(na==0) t=1;
    if(nb==0) t=2;
    if(nc==0) t=3;
    
    for(i=i;i<n;i++)
    {
     if(t==1&&(nb==0||nc==0)||t==2&&(na==0||nc==0)||t==3&&(na==0||nb==0))
      break;
     sum2+=tot[i];
     if(a[i]==max[i])
     {
      na--,sum1+=a[i];
      continue;
     }
     if(b[i]==max[i])
     {
      nb--,sum1+=b[i];
      continue;
     }
     if(c[i]==max[i])
     {
      nc--,sum1+=c[i];
      continue;
     }
    }
    
    for(j=i;j<n;j++)
    {
     max[j]=-2100000000;
     if(na!=0&&max[j]<a[j])
      max[j]=a[j];
     if(nb!=0&&max[j]<b[j])
      max[j]=b[j];
     if(nc!=0&&max[j]<c[j])
      max[j]=c[j];
    }
    qs(i,n-1);
    if(na!=0) t=1;
    if(nb!=0) t=2;
    if(nc!=0) t=3;
    
    for(i=i;i<n;i++)
    {
     if(t==1&&na==0||t==2&&nb==0||t==3&&nc==0)
      break;
     sum2+=tot[i];
     if(a[i]==max[i])
     {
      na--,sum1+=a[i];
      continue;
     }
     if(b[i]==max[i])
     {
      nb--,sum1+=b[i];
      continue;
     }
     if(c[i]==max[i])
     {
      nc--,sum1+=c[i];
      continue;
     }
    }
    printf("%d\n%d\n",sum1,sum2);
    return 0;
}

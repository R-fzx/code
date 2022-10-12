#include<stdio.h>
#include<algorithm>
#define oo -9023372036854775807LL
using namespace std;
int n,a,b,c;
long long sum,f[101][101][101],f1[101][101][101];
struct node
{
       long long a,b,c,sum;
       bool hash;
}sv[500001],d[301];
void sorta(int l,int r)
{
     int i=l,j=r;
     node tmp=sv[l+r>>1],cc;
     if(l>=r)return;
     while(i<=j)
     {
       while(i<=j&&(sv[j].a<tmp.a||sv[j].a==tmp.a&&sv[j].sum<tmp.sum))j--;
       while(i<=j&&(sv[i].a>tmp.a||sv[i].a==tmp.a&&sv[i].sum>tmp.sum))i++;
       if(i>j)continue;
       cc=sv[i];
       sv[i]=sv[j];
       sv[j]=cc;
       i++;
       j--;
     }
     sorta(l,j);
     if(i<a+b+c)sorta(i,r);
}
void sortb(int l,int r)
{
     int i=l,j=r;
     node tmp=sv[l+r>>1],cc;
     if(l>=r)return;
     while(i<=j)
     {
       while(i<=j&&(sv[j].b<tmp.b||sv[j].b==tmp.b&&sv[j].sum<tmp.sum))j--;
       while(i<=j&&(sv[i].b>tmp.b||sv[i].b==tmp.b&&sv[i].sum>tmp.sum))i++;
       if(i>j)continue;
       cc=sv[i];
       sv[i]=sv[j];
       sv[j]=cc;
       i++;
       j--;
     }
     sortb(l,j);
     if(i<a+b+c)sortb(i,r);
}
void sortc(int l,int r)
{
     int i=l,j=r;
     node tmp=sv[l+r>>1],cc;
     if(l>=r)return;
     while(i<=j)
     {
       while(i<=j&&(sv[j].c<tmp.c||sv[j].c==tmp.c&&sv[j].sum<tmp.sum))j--;
       while(i<=j&&(sv[i].c>tmp.c||sv[i].c==tmp.c&&sv[i].sum>tmp.sum))i++;
       if(i>j)continue;
       cc=sv[i];
       sv[i]=sv[j];
       sv[j]=cc;
       i++;
       j--;
     }
     sortc(l,j);
     if(i<a+b+c)sortc(i,r);
}
int main()
{
    freopen("ゆりっぺ.in","r",stdin);
    freopen("ゆりっぺ.out","w",stdout);
    int i,j,k,l;
    long long tmp,tmp1;
    scanf("%d%d%d%d",&n,&a,&b,&c);
    if(a+b+c>n)
    {
      printf("I am a godlike cowcowcow\n");
      return 0;
    }
    for(i=1;i<=n;i++)
    {
      scanf("%I64d%I64d%I64d",&sv[i].a,&sv[i].b,&sv[i].c);
      sv[i].sum=sv[i].a+sv[i].b+sv[i].c;
    }
    sorta(1,n);
    for(i=1;i<=a+b+c;i++)
    {
      sv[i].hash=1;
      d[++sum]=sv[i];
    }
    sortb(1,n);
    j=0;
    for(i=1;i<=n;i++)
    {
      if(sv[i].hash)continue;
      sv[i].hash=1;
      j++;
      d[++sum]=sv[i];
      if(j==a+b+c)break;
    }
    sortc(1,n);
    j=0;
    for(i=1;i<=n;i++)
    {
      if(sv[i].hash)continue;
      j++;
      d[++sum]=sv[i];
      if(j==a+b+c)break;
    }
    n=sum;
    for(i=0;i<=100;i++)for(j=0;j<=100;j++)for(k=0;k<=100;k++)f[i][j][k]=oo;
    f[0][0][0]=0;
    f[1][0][0]=d[1].a;
    f[0][1][0]=d[1].b;
    f[0][0][1]=d[1].c;
    f1[0][0][0]=0;
    f1[1][0][0]=f1[0][1][0]=f1[0][0][1]=d[1].sum;
    for(i=2;i<=n;i++)
    {
      for(j=a;j>=0;j--)
        for(k=b;k>=0;k--)
          for(l=c;l>=0;l--)
          {
            if(j==0&&k==0&&l==0)continue;
            tmp=oo;
            if(j>0&&f[j-1][k][l]!=oo)
              if(f[j-1][k][l]+d[i].a>tmp)
              {
                tmp=f[j-1][k][l]+d[i].a;
                tmp1=f1[j-1][k][l]+d[i].sum;
              }
            if(k>0&&f[j][k-1][l]!=oo)
              if(f[j][k-1][l]+d[i].b>tmp)
              {
                tmp=f[j][k-1][l]+d[i].b;
                tmp1=f1[j][k-1][l]+d[i].sum;
              }
            if(l>0&&f[j][k][l-1]!=oo)
              if(f[j][k][l-1]+d[i].c>tmp)
              {
                tmp=f[j][k][l-1]+d[i].c;
                tmp1=f1[j][k][l-1]+d[i].sum;
              }
            if(f[j][k][l]<tmp)
            {
              f[j][k][l]=tmp;
              f1[j][k][l]=tmp1;
            }
          }
    }
    printf("%I64d\n%I64d\n",f[a][b][c],f1[a][b][c]);
    return 0;
}

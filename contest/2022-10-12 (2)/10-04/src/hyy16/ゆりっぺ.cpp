#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n,a,b,c;
int w,ai,bi,ci;
int i,j,k,l,Now,n2;
long long key,k2,Key,K2;
long long f[105][105][105];
long long f2[105][105][105];
char str[1005];

class people
{
      public:
          long long a,b,c;
          char tag;
          
          inline void read()
          {
               a=b=c=tag=0;
               gets(str);
               Now=0;
               n2=1;
               if (str[Now]=='-') Now++,n2=-1;
               while (str[Now]!=' ') 
               a=a*10+str[Now]-48,Now++;
               a*=n2;
               Now++;
               n2=1;
               if (str[Now]=='-') Now++,n2=-1;
               while (str[Now]!=' ') 
               b=b*10+str[Now]-48,Now++;
               b*=n2;
               Now++;
               n2=1;
               if (str[Now]=='-') Now++,n2=-1;
               while (str[Now]!=' ' && str[Now]!=0) 
               c=c*10+str[Now]-48,Now++;
               c*=n2;
               return;
          }
};

void sort1(int l,int r);
void sort2(int l,int r);
void sort3(int l,int r);

people p[500005];

int main()
{
    freopen("ゆりっぺ.in","r",stdin); freopen("ゆりっぺ.out","w",stdout);
    scanf("%I64d %I64d %I64d %I64d\n",&n,&a,&b,&c);
    w=a+b+c;
    if (w>n)
    {
       printf("I am a godlike cowcowcow\n");
       return 0;
    }
    for(i=1;i<=n;i++)
    p[i].read();
    sort1(1,n);
    for(i=1;i<=w;i++)
       p[i].tag=1;
    sort2(1,n);
    for(i=1;i<=w;i++)
       p[i].tag=1;
    sort3(1,n);
    for(i=1;i<=w;i++)
       p[i].tag=1;
    for(j=0;j<=a;j++)
       for(k=0;k<=b;k++)
          for(l=0;l<=c;l++)
             f[j][k][l]=f2[j][k][l]=-1616161616;
    f[0][0][0]=f2[0][0][0]=0;
    for(i=1;i<=n;i++)
    {
       if (p[i].tag==0) continue;
       ai=p[i].a,bi=p[i].b,ci=p[i].c;
       for(j=a;j>=0;j--)
          for(k=b;k>=0;k--)
             for(l=c;l>=0;l--)
             {
                key=f[j][k][l];
                Key=f2[j][k][l];
                if (j>0)
                {
                   k2=f[j-1][k][l]+ai;
                   K2=f2[j-1][k][l]+ai+bi+ci;
                   if (k2>key || (k2==key && K2>Key)) key=k2,Key=K2;
                }
                if (k>0)
                {
                   k2=f[j][k-1][l]+bi;
                   K2=f2[j][k-1][l]+ai+bi+ci;
                   if (k2>key || (k2==key && K2>Key)) key=k2,Key=K2;
                }
                if (l>0)
                {
                   k2=f[j][k][l-1]+ci;
                   K2=f2[j][k][l-1]+ai+bi+ci;
                   if (k2>key || (k2==key && K2>Key)) key=k2,Key=K2;
                }
                f[j][k][l]=key;
                f2[j][k][l]=Key;
             }
    }
    printf("%I64d\n%I64d\n",f[a][b][c],f2[a][b][c]);
    return 0;
}

void sort1(int l,int r)
{
     if (l>w || r<=w) return;
     long long i=l,j=r,mid;
     people k;
     mid=p[(l+r)>>1].a;
     while (i<=j)
     {
           while (i<=j && p[i].a>mid) i++;
           while (i<=j && p[j].a<mid) j--;
           if (i<=j)
           {
              k=p[i],p[i]=p[j],p[j]=k;
              i++,j--;
           }
     }
     if (l<j) sort1(l,j);
     if (i<r) sort1(i,r);
     return;
}

void sort2(int l,int r)
{
     if (l>w || r<=w) return;
     long long i=l,j=r,mid;
     people k;
     mid=p[(l+r)>>1].b;
     while (i<=j)
     {
           while (i<=j && p[i].b>mid) i++;
           while (i<=j && p[j].b<mid) j--;
           if (i<=j)
           {
              k=p[i],p[i]=p[j],p[j]=k;
              i++,j--;
           }
     }
     if (l<j) sort2(l,j);
     if (i<r) sort2(i,r);
     return;
}

void sort3(int l,int r)
{
     if (l>w || r<=w) return;
     long long i=l,j=r,mid;
     people k;
     mid=p[(l+r)>>1].c;
     while (i<=j)
     {
           while (i<=j && p[i].c>mid) i++;
           while (i<=j && p[j].c<mid) j--;
           if (i<=j)
           {
              k=p[i],p[i]=p[j],p[j]=k;
              i++,j--;
           }
     }
     if (l<j) sort3(l,j);
     if (i<r) sort3(i,r);
     return;
}

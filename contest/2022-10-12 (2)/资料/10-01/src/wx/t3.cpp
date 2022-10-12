#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int max(int x,int y)
{
    if(x>y)return x;
    return y;
}
int N,map[213][213],mod=10000;
struct High
{
       int dat[400],l;
}z[1];
High ans;
void add(High &a,int x)
{
     int i,j,k,s=a.l;
     a.dat[1]+=x;
     for(i=1;i<=s;i++)
     {
      a.dat[i+1]+=a.dat[i]/mod;
      a.dat[i]%=mod;
     }
     a.l=s;
     if(a.dat[s+1]>0)a.l++;
}
void del(High &a,int x)
{
     int i,j,k;
      a.dat[1]-=x;
     for(i=1;i<=a.l;i++)
     {
      while(a.dat[i]<0)
      {
       a.dat[i]+=mod;
       a.dat[i+1]--;
      }
     }
     while(!a.dat[a.l]&&a.l>0)
     a.l--;
}
void low_cheng(High &a,int x)
{
     int i,j,k;
     for(i=1;i<=a.l;i++)
     a.dat[i]*=x;
     for(i=1;i<a.l;i++)
     {
      a.dat[i+1]+=a.dat[i]/mod;
      a.dat[i]%=mod;
     }
     while(a.dat[a.l]>=mod)
     {
      a.dat[a.l+1]+=a.dat[a.l]/mod;
      a.dat[a.l]%=mod;
      a.l++;
     }
}
void low_chu(High &a,int x)
{
     int i,j,k;
     for(i=a.l;i>=1;i--)
     {
      a.dat[i-1]+=(a.dat[i]%x)*mod;
      a.dat[i]=a.dat[i]/x;
     }
     while(!a.dat[a.l])
     a.l--;
}
High C(int a,int b)//C(a,b)
{
     High tmp;
     tmp=z[0];
     tmp.l=tmp.dat[1]=1;
     int i,j,k;
     for(i=b-a;i<=b;i++)
     {
      low_cheng(tmp,b-i-a+b);
      low_chu(tmp,i-b+a+1);
     }
     return tmp;
}
High A(int a,int b)
{
     High tmp;
     tmp=z[0];
     tmp.l=tmp.dat[1]=1;
     int i,j,k;
     for(i=a+1;i<=b;i++)
      low_cheng(tmp,i);
     return tmp;
}
High cheng(High &a,High &b)
{
     int i,j,k,s=a.l+b.l;
     High tmp;
     tmp=z[0];
     for(i=1;i<=a.l;i++)
     for(j=1;j<=b.l;j++)
     tmp.dat[i+j-1]=a.dat[i]*b.dat[j];
     for(i=1;i<s;i++)
     {
      a.dat[i+1]+=a.dat[i]/mod;
      a.dat[i]%=mod;            
     }
     tmp.l=s-1;
     if(tmp.dat[s]>0)
     tmp.l++;
     return tmp;
}
int main()
{
    freopen("t3.in","r",stdin);
    freopen("t3.out","w",stdout);
    int i,j,k;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    for(j=1;j<=N;j++)
    scanf("%d",&map[i][j]);
    ans.l=ans.dat[1]=1;
    for(i=3;i<=N;i++)
    {
     low_cheng(ans,i);
     if(i%2==0)add(ans,1);
     else del(ans,1);
    }
    printf("%d",ans.dat[ans.l]);
    for(i=ans.l-1;i>0;i--)
    printf("%04d",ans.dat[i]);
    return 0;
}

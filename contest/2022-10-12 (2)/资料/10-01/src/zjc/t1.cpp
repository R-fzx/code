#include<stdio.h>
#include<algorithm>
#define mod 10007
using namespace std;
long long f[1000000],ni[3000];
int a[2000][2000],b[2000],c[2000],d[3000],fa[2000],s[2000],n,m,t;
inline long long sumi(int x,int y)
{
    long long z=1;
    for(;y;y>>=1) { if(y&1) z=z*x%mod; x=x*x%mod; }
    return z;
}
inline long long get(long long x,long long y)
{
    int i;
    long long z=1;
    for(i=1;i<=y;i++) z=z*(x+1-i)%mod*ni[i]%mod;
    return z;
}
int main()
{
    freopen("t1.in","r",stdin);
    freopen("t1.out","w",stdout);
    int i,j,l,r,x;
    for(i=1;i<=2000;i++) ni[i]=sumi(i,mod-2);
    scanf("%d",&t);
    while(t--)
    {
      scanf("%d",&n);
      memset(f,0,sizeof(f)),memset(fa,0,sizeof(fa));
      for(i=1;i<=n;i++)
      {
        scanf("%d",&s[i]);
        for(j=1;j<=s[i];j++) scanf("%d",&a[i][j]),fa[a[i][j]]=i;
      }
      for(r=0,i=1;i<=n;i++) { b[i]=s[i]; if(!s[i]) d[++r]=i; }
      for(l=1;l<=r;l++)
      {
        x=d[l],b[fa[x]]--; if(b[fa[x]]==0) d[++r]=fa[x];
        if(!s[x]) { f[x]=c[x]=1; continue; }
        f[x]=f[a[x][s[x]]],c[x]=c[a[x][s[x]]];
        for(j=s[x]-1;j;c[x]+=c[a[x][j]],j--)
          f[x]=f[x]*f[a[x][j]]%mod*get(c[x]+c[a[x][j]]-1,c[x])%mod;
        c[x]++;
      }
      //for(i=1;i<=n;i++) printf("%d ",f[i]); printf("\n");
      //for(i=1;i<=n;i++) printf("%d ",c[i]); printf("\n");
      printf("%I64d\n",f[1]);
    }
    return 0;
}

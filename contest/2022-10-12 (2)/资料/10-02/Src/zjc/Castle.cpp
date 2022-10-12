#include<stdio.h>
#define oo 0x7fffffff
int n,m,d[10000000],e[2000000],v[2000000],last[2000000],succ[2000000],c,hash[2000][2000];
long long ans,a[200000];
bool h[200000];
inline void add(int x,int y,int z) { e[++c]=y,succ[c]=last[x],last[x]=c,v[c]=z; }
int main()
{
    freopen("Castle.in","r",stdin);
    freopen("Castle.out","w",stdout);
    int i,j,k,l,r;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++) hash[i][j]=oo;
    for(i=1;i<=m;i++)
    {
      scanf("%d%d%d",&j,&k,&l);
      if(l<hash[j][k]) hash[j][k]=hash[k][j]=l;
    }
    for(i=1;i<=n;i++) for(j=1;j<=n;j++) if(hash[i][j]!=oo) add(i,j,hash[i][j]);
    /*for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        if(hash[i][j]!=oo) printf("%d %d %d\n",i,j,hash[i][j]);*/
    for(i=2;i<=n;i++) a[i]=oo;
    for(d[1]=1,l=r=1;l<=r;l++)
      for(h[d[l]]=0,i=last[d[l]];i;i=succ[i])
        if(a[e[i]]>a[d[l]]+v[i])
        {
          a[e[i]]=a[d[l]]+v[i];
          if(a[2]==2)
           k++;
          if(!h[e[i]]) d[++r]=e[i],h[e[i]]=1;
        }
    //for(i=1;i<=n;i++) printf("%d\n",a[i]);
    for(ans=1,i=2;i<=n;i++)
    {
      for(k=0,j=last[i];j;j=succ[j])
        if(a[e[j]]+v[j]==a[i]) k++;
      if(k==0)
       ans=0;
      ans=ans*(long long)k%oo;
    }
    printf("%I64d\n",ans);
    return 0;
}

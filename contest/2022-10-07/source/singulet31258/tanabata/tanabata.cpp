#include<cstdio>
#include<algorithm>
#define _ long long
#define N 100001
int i,x,y,n,m,t,r[N],c[N],rs[N],cs[N],rok,cok,med;_ res;
_ rsol(){for(i=1;i<=n;++i)r[i]-=t/n,rs[i]=rs[i-1]+r[i];std::sort(rs+1,rs+n+1);res=0;med=rs[n+1>>1];for(i=1;rs[i]<=med;++i)res+=med-rs[i];while(i<=n)res+=rs[i]-med,++i;return res;}
_ csol(){for(i=1;i<=m;++i)c[i]-=t/m,cs[i]=cs[i-1]+c[i];std::sort(cs+1,cs+m+1);res=0;med=cs[m+1>>1];for(i=1;cs[i]<=med;++i)res+=med-cs[i];while(i<=m)res+=cs[i]-med,++i;return res;}
int main(){freopen("tanabata.in","r",stdin);freopen("tanabata.out","w",stdout);scanf("%d%d%d",&n,&m,&t);for(i=1;i<=t;++i){scanf("%d%d",&x,&y);++r[x];++c[y];}rok=!(t%n);cok=!(t%m);if(rok)if(cok)return!printf("both %lld",rsol()+csol());else return!printf("row %lld",rsol());else if(cok)return!printf("column %lld",csol());else return!printf("impossible");}

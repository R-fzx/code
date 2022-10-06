#include<cstdio>
#define N 200001
#define MOD 1000000009
int n,m,f[N],s[N],a,b,ans;
int find(int x){if(x==f[x])return x;return f[x]=find(f[x]);}
int main(){
	freopen("magician.in","r",stdin);freopen("magician.out","w",stdout);
	scanf("%d%d",&n,&m);for(int i=1;i<=n;++i)f[i]=i,s[i]=1;
	while(m--){
		scanf("%d%d",&a,&b);a=find(a);b=find(b);
		if(a==b)ans=ans<<1|1,ans=ans>=MOD?ans-MOD:ans;
		else if(s[a]>s[b])f[b]=a,s[a]+=s[b];
		else f[a]=b,s[b]+=s[a];
		printf("%d\n",ans);
	}
	return 0;
}

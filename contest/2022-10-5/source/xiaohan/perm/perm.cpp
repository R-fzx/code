#include<bits/stdc++.h>
#define int long long
inline int read()
{	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c))f|=(c=='-'),c=getchar();
	while(isdigit(c))x=x*10+(c&15),c=getchar();
	return f?-x:x;
}
using namespace std;
int sz[15],dl[15],cnt,zs[50]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47},zsgs[55];//15
unsigned int ans;
inline void fjzys(int x)
{	for(register int i=1;i<=15;++i)
		for(register int j=zs[i];j<=x;j*=zs[i])
			zsgs[i]+=x/j;
}
inline void cyzys(int x)
{	for(register int i=1;i<=15;++i)
		for(register int j=zs[i];j<=x;j*=zs[i])
			zsgs[i]-=x/j;
}
inline int ksm(int x,int y)
{	int res=1;
	while(y)
	{	if(y&1)res=res*x;
		x=x*x;
		y>>=1;
	}
	return res;
}
string s;
signed main()
{	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	cin>>s;
	for(register int i=0;i<s.size();++i)
	{	if(sz[s[i]-'0']==0)dl[++cnt]=s[i]-'0';
		sz[s[i]-'0']++;
	}
	sort(dl+1,dl+cnt+1);
	for(register int i=0;i<s.size();++i)
	{	for(register int j=1;j<=cnt&&dl[j]<s[i]-'0';++j)
		{	if(sz[dl[j]]==0)continue;
			sz[dl[j]]--;
			memset(zsgs,0,sizeof(zsgs));
			fjzys(s.size()-1-i);
//						for(register int k=1;k<=15;++k)cout<<zs[k]<<' '<<zsgs[k]<<endl;
			for(register int k=1;k<=cnt;++k)cyzys(sz[dl[k]]);
			sz[dl[j]]++;
			int tmp=1;
			for(register int k=1;k<=15;++k)tmp*=ksm(zs[k],zsgs[k]);
//						for(register int k=1;k<=15;++k)cout<<zs[k]<<' '<<zsgs[k]<<endl;
			ans+=tmp;
//			cout<<ans<<endl;
		}
		sz[s[i]-'0']--;
		
	}
	cout<<ans;
	return 0;
}


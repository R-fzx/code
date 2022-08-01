#include<bits/stdc++.h>
inline int read()
{	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c))f|=(c=='-'),c=getchar();
	while(isdigit(c))x=x*10+(c&15),c=getchar();
	return f?-x:x;
}
using namespace std;
int n,k,ct[205],cnt;
double p,dis[1005][205];
string s[205],S;
map<int,int> mappp;
map<string,int> mapp;
int main()
{	freopen("ppfish.in","r",stdin);
	freopen("ppfish.out","w",stdout);
	n=read();
	for(register int i=1;i<=n;++i)
	{	cin>>s[i];
		mapp[s[i]]=1;
	}
	cin>>S;
	scanf("%lf%d",&p,&k);
	for(register int i=0;i<S.size();++i)
	{	string now="";
		for(register int j=1;j<=20&&i+j-1<S.size();++j)
		{	now+=S[i+j-1];
			if(mapp[now]!=0)mapp[now]++;
		}
	}
	for(register int i=1;i<=n;++i)
		ct[i]=mapp[s[i]];
	sort(ct+1,ct+n+1);
	ct[0]=-1;
	for(register int i=1;i<=n;++i)
		if(ct[i]!=ct[i-1])
		{	cnt++;
			mappp[ct[i]]=cnt;
		}
	dis[0][0]=1;
//	for(register int i=2;i<=cnt;++i)dis[1][i]=1.0;
//	dis[1][1]=p;
	for(register int i=1;i<=cnt;++i)
		for(register int l=1;l<=k;++l)
			dis[i][l]=dis[i][l-1]*p+dis[i-1][l-1]*(1-p);
//			else dis[l][i]=0.0;
	for(register int i=1;i<=n;++i)
	{	int x=mapp[s[i]];
		int xb=mappp[x];
		double ans=0;
		for(register int j=1;j<=k;++j)ans+=dis[xb][j];
		printf("%.3lf ",1-ans);
	}
	return 0;
}


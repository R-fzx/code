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
struct bb
{	int x,y;
}op[205];
int dl[100000],cnt,n,sum[100000],ls[100000],minn1=11474836471,minn2=11474836471;
signed main()
{	freopen("seventeen.in","r",stdin);
	freopen("seventeen.out","w",stdout);
	n=read();
	for(register int i=1;i<=n;++i)op[i].x=read(),op[i].y=read();
	for(register int i=0;i<95000;++i)sum[i]=11474836471;
	sum[50000]=0;
	for(register int i=1;i<=n;++i)
	{	cnt=0;
		for(register int j=0;j<95000;++j)
			if(sum[j]!=11474836471)dl[++cnt]=j;
		for(register int j=0;j<95000;++j)ls[j]=11474836471;
		for(register int j=1;j<=cnt;++j)
		{	ls[dl[j]+op[i].x]=min(ls[dl[j]+op[i].x],min(sum[dl[j]+op[i].x],sum[dl[j]]+(dl[j]-50000)*op[i].x));
			ls[dl[j]-op[i].x]=min(ls[dl[j]-op[i].x],min(sum[dl[j]-op[i].x],sum[dl[j]]-(dl[j]-50000)*op[i].x));
//			cerr<<i<<' '<<dl[j]<<' '<<ls[dl[j]+op[i].x]<<' '<<ls[dl[j]-op[i].x]<<endl;
//			system("pause");
		}
		for(register int j=0;j<95000;++j)
			if(ls[j]!=11474836471)sum[j]=ls[j];
	}
	for(register int i=0;i<95000;++i)minn1=min(minn1,sum[i]);
//	cerr<<minn1; 
	for(register int i=0;i<95000;++i)sum[i]=11474836471;
	sum[50000]=0;
	for(register int i=1;i<=n;++i)
	{	cnt=0;
		for(register int j=0;j<95000;++j)
			if(sum[j]!=11474836471)dl[++cnt]=j;
		for(register int j=0;j<95000;++j)ls[j]=11474836471;
		for(register int j=1;j<=cnt;++j)
		{	ls[dl[j]+op[i].y]=min(ls[dl[j]+op[i].y],min(sum[dl[j]+op[i].y],sum[dl[j]]+(dl[j]-50000)*op[i].y));
			ls[dl[j]-op[i].y]=min(ls[dl[j]-op[i].y],min(sum[dl[j]-op[i].y],sum[dl[j]]-(dl[j]-50000)*op[i].y));
//			cerr<<i<<' '<<dl[j]<<' '<<ls[dl[j]+op[i].x]<<' '<<ls[dl[j]-op[i].x]<<endl;
//			system("pause");
		}
		for(register int j=0;j<95000;++j)
			if(ls[j]!=11474836471)sum[j]=ls[j];
	}
	for(register int i=0;i<95000;++i)minn2=min(minn2,sum[i]);
//	cerr<<minn1; 
	cout<<minn1+minn2<<".00";
	return 0;
}


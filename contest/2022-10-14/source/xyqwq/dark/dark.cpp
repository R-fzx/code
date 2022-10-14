//dark
#include<bits/stdc++.h>
using namespace std;

const int NUM=2e5+5;

int n;
int a[NUM][2];
double ans=1e9*1.0;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

inline double getdis(int x1,int y1,int x2,int y2)
{
	return (double)sqrt((abs(x1-x2)*abs(x1-x2)+abs(x1-x2)*abs(x1-x2))*1.0);
}

signed main()
{
	freopen("dark.in","r",stdin);
	freopen("dark.out","w",stdout);
	
//	cout<<getdis(1,2,2,3); 

	n=read();
	for(int i=1;i<=n;++i)
		a[i][0]=read(),a[i][1]=read();
	
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			ans=min(ans,getdis(a[i][0],a[i][1],a[j][0],a[j][1]));
			
	printf("%.3lf",ans);
	
	return 0;
}


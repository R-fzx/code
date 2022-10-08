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
int k,m,n,X0,Y0;
int main()
{	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	while(cin>>k>>m>>n>>X0>>Y0)
	{	for(register int i=1;i<=k;++i)cin>>X0>>Y0;
		cout<<"Yes\n";
	}
	return 0;
}


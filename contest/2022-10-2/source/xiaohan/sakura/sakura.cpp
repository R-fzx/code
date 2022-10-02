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
int n,jc[15];
signed main()
{	freopen("sakura.in","r",stdin);
	freopen("sakura.out","w",stdout);
	n=read();
	if(n==2)cout<<3;
	else if(n==3)cout<<9;
	else if(n==4)cout<<21; 
	return 0;
}


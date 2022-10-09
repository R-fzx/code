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
int main()
{	//freopen(".in","r",stdin);
	freopen("seventeen.in","w",stdout);
	cout<<200<<endl;
	for(register int i=1;i<=200;++i)cout<<i<<' '<<i<<endl;
	return 0;
}


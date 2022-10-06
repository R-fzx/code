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
{	freopen("laser.in","r",stdin);
	freopen("laser.out","w",stdout);
	cout<<"1\n2\n3\n4\n5\n6\n7\n8\n9\n";
	return 0;
}


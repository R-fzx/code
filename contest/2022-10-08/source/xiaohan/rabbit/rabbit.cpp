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
int n;
int main()
{	freopen("rabbit.in","r",stdin);
	freopen("rabbit.out","w",stdout);
	n=read();
	printf("%d\n",n*(n-1)/2);
	for(register int c=1;c<=n/2;++c)
		 for(register int i=1;i<=n;++i)
		{	int x=i,y=(i+c)%n,z=(i+2*c)%n;
			if(y==0)y=n;
			if(z==0)z=n;
			printf("%d %d %d\n",x,y,z);
		}
	return 0;
}


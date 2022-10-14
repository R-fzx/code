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
int T,n,c,a[205];
int main()
{	freopen("wave.in","r",stdin);
	freopen("wave.out","w",stdout);
	T=read();
	while(T--)
	{	n=read(),c=read();
		int now=0;
		for(register int i=1;i<=n;++i)a[i]=i;
		do
		{	bool flag=0,bj=1;
			if(a[2]>a[1])flag=1;
			else flag=0;
			for(register int i=3;i<=n;++i)
			{	if(flag&&a[i]>a[i-1])bj=0;
				if(!flag&&a[i]<a[i-1])bj=0;
				if(!bj)break;
				flag=1-flag;
			}
			if(bj)now++;
			if(now==c)
			{	for(register int i=1;i<=n;++i)printf("%d ",a[i]);
				break;
			}
		}while(next_permutation(a+1,a+n+1));
		cout<<endl;
	}
	return 0;
}


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
struct bb
{	string c;
}s[25];
int n;
bool operator <(bb a,bb b)
{	if(a.c.size()!=b.c.size())return a.c.size()>b.c.size();
	return a.c>b.c;
	
}
priority_queue<bb> q;
int main()
{	freopen("codes.in","r",stdin);
	freopen("codes.out","w",stdout);
	n=read();
	for(register int i=1;i<=n;++i)cin>>s[i].c,q.push(s[i]);
	while(1)
	{	string a=q.top().c;
		q.pop();
//		cerr<<a<<endl;
//		system("pause");
		if(a==q.top().c)
		{	cout<<a.size()<<endl<<a;
			return 0;
		}
		bb tmp;
		for(register int i=1;i<=n;++i)
		{	tmp.c=a+s[i].c;
			q.push(tmp);
		}
	}
	return 0;
}


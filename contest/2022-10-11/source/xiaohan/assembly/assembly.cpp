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
int n,k,A,b[10],l[10];
double ans,now;
void get_ans(int x,int rs,int sum,double gl)
{	if(x==n+1)
	{	if(rs>=n/2+1)now+=gl;
		else now+=gl*(1.0*A/(A+sum));
		return ;
	}
	get_ans(x+1,rs+1,sum,gl*(l[x]/100.0));
	get_ans(x+1,rs,sum+b[x],gl*(1.0-l[x]/100.0));
	return ;
}
void dfs(int x,int sy)
{	if(x==n)
	{	l[x]+=(sy*10);
		if(l[x]>100)
		{	l[x]-=(sy*10);
			return ;
		}
		now=0.0;
		get_ans(1,0,0,1.0); 
		ans=max(ans,now);
		l[x]-=(sy*10);
		return ;
	}
	for(register int i=0;i<=sy;++i)
	{	l[x]+=(i*10);
		if(l[x]>100)
		{	l[x]-=(i*10);
			break;
		}
		dfs(x+1,sy-i);
		l[x]-=(i*10);
	}
	return ;
}
int main()
{	freopen("assembly.in","r",stdin);
	freopen("assembly.out","w",stdout);
	n=read(),k=read(),A=read();
	for(register int i=1;i<=n;++i)b[i]=read(),l[i]=read();
	dfs(1,k);
	printf("%.6lf",ans);
//	cerr<<clock();
	return 0;
}

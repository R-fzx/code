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
{	double x,y;
}op[200005];
int n;
double ans=2000000.0;
inline bool cmp(bb a,bb b)
{	return a.x==b.x?a.y<b.y:a.x<b.x;
}
inline void get_ans()
{	sort(op+1,op+n+1,cmp);
	for(register int i=1;i<=n;++i)
		for(register int j=1;j<=10&&i+j<=n;++j)
			ans=min(ans,sqrt((op[i].x-op[i+j].x)*(op[i].x-op[i+j].x)+(op[i].y-op[i+j].y)*(op[i].y-op[i+j].y)));
	return ;
}
inline void xuanzhuan(double jiaodu)
{	jiaodu=jiaodu/180.0*acos(-1.0);
	for(register int i=1;i<=n;++i)
	{	double sx=op[i].x,sy=op[i].y,ex,ey;
		ex=sx*cos(jiaodu)-sy*sin(jiaodu);
		ey=sx*sin(jiaodu)+sy*cos(jiaodu);
		op[i].x=ex,op[i].y=ey;
	}
	get_ans();
	return ;
}
signed main()
{	freopen("dark.in","r",stdin);
	freopen("dark.out","w",stdout);
	srand(time(0));
	n=read();
	for(register int i=1;i<=n;++i)op[i].x=double(read()),op[i].y=double(read());
	for(register int i=1;i<=4;++i)xuanzhuan(rand()%360);
	printf("%.3lf",ans/2.0);
//	cerr<<clock();
	return 0;
}


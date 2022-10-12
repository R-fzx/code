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
struct node
{	int w,sum;
}f[2][105][105][105];
struct bb
{	int a,b,c,id;
}op[500005],dl[305];
int n,A,B,C,cnt,tot,sum;
bool bj[500005];
inline bool cmp_a(bb a,bb b){return a.a==b.a?a.a+a.b+a.c>b.a+b.b+b.c:a.a>b.a;}
inline bool cmp_b(bb a,bb b){return a.b==b.b?a.a+a.b+a.c>b.a+b.b+b.c:a.b>b.b;}
inline bool cmp_c(bb a,bb b){return a.c==b.c?a.a+a.b+a.c>b.a+b.b+b.c:a.c>b.c;}
signed main()
{	freopen("ゆりっぺ.in","r",stdin);
	freopen("ゆりっぺ.out","w",stdout);
	n=read(),A=read(),B=read(),C=read();
	if(A+B+C>n)
	{	cout<<"I am a godlike cowcowcow";
		return 0;
	}
	for(register int i=1;i<=n;++i)op[i].a=read(),op[i].b=read(),op[i].c=read(),op[i].id=i;
	tot=0;
	sort(op+1,op+n+1,cmp_a);
	for(register int i=1;tot<3*A&&i<=n;++i)
		if(!bj[op[i].id])
		{	dl[++cnt]=op[i];
//			cerr<<op[i].id<<endl;
//			sum+=op[i].a+op[i].b+op[i].c; 
			bj[op[i].id]=1;
			tot++;
		}
//	cerr<<cnt<<endl;
	tot=0;
	sort(op+1,op+n+1,cmp_b);
	for(register int i=1;tot<3*B&&i<=n;++i)
		if(!bj[op[i].id])
		{	dl[++cnt]=op[i];
//			cerr<<op[i].id<<endl;
//			sum+=op[i].a+op[i].b+op[i].c;
			bj[op[i].id]=1;
			tot++;
		}
//	cerr<<cnt<<endl;
	tot=0;
	sort(op+1,op+n+1,cmp_c);
	for(register int i=1;tot<3*C&&i<=n;++i)
		if(!bj[op[i].id])
		{	dl[++cnt]=op[i];
//			cerr<<op[i].id<<endl;
//			sum+=op[i].a+op[i].b+op[i].c;
			bj[op[i].id]=1;
			tot++;
		}
//	cerr<<cnt<<endl;
	for(register int i=1;i<=cnt;++i)
		for(register int sa=0;sa<=A;++sa)
		for(register int sb=0;sb<=B;++sb)
		for(register int sc=0;sc<=C;++sc)
		{	f[i%2][sa][sb][sc]=f[(i+1)%2][sa][sb][sc];
			if(sa!=0)
			{	if(f[i%2][sa][sb][sc].w<=f[(i+1)%2][sa-1][sb][sc].w+dl[i].a)
				{	if(f[i%2][sa][sb][sc].w==f[(i+1)%2][sa-1][sb][sc].w+dl[i].a)f[i%2][sa][sb][sc].sum=max(f[i%2][sa][sb][sc].sum,f[(i+1)%2][sa-1][sb][sc].sum+dl[i].a+dl[i].b+dl[i].c);
					else f[i%2][sa][sb][sc].w=f[(i+1)%2][sa-1][sb][sc].w+dl[i].a,f[i%2][sa][sb][sc].sum=f[(i+1)%2][sa-1][sb][sc].sum+dl[i].a+dl[i].b+dl[i].c;
				}
			}
			if(sb!=0)
			{	if(f[i%2][sa][sb][sc].w<=f[(i+1)%2][sa][sb-1][sc].w+dl[i].b)
				{	if(f[i%2][sa][sb][sc].w==f[(i+1)%2][sa][sb-1][sc].w+dl[i].b)f[i%2][sa][sb][sc].sum=max(f[i%2][sa][sb][sc].sum,f[(i+1)%2][sa][sb-1][sc].sum+dl[i].a+dl[i].b+dl[i].c);
					else f[i%2][sa][sb][sc].w=f[(i+1)%2][sa][sb-1][sc].w+dl[i].b,f[i%2][sa][sb][sc].sum=f[(i+1)%2][sa][sb-1][sc].sum+dl[i].a+dl[i].b+dl[i].c;
				}
			}
			if(sc!=0)
			{	if(f[i%2][sa][sb][sc].w<=f[(i+1)%2][sa][sb][sc-1].w+dl[i].c)
				{	if(f[i%2][sa][sb][sc].w==f[(i+1)%2][sa][sb][sc-1].w+dl[i].c)f[i%2][sa][sb][sc].sum=max(f[i%2][sa][sb][sc].sum,f[(i+1)%2][sa][sb][sc-1].sum+dl[i].a+dl[i].b+dl[i].c);
					else f[i%2][sa][sb][sc].w=f[(i+1)%2][sa][sb][sc-1].w+dl[i].c,f[i%2][sa][sb][sc].sum=f[(i+1)%2][sa][sb][sc-1].sum+dl[i].a+dl[i].b+dl[i].c;
				}
			}
		}
	cout<<f[cnt%2][A][B][C].w<<endl<<f[cnt%2][A][B][C].sum;
	return 0;
}


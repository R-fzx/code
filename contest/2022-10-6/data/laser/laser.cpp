#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
struct rec{
	__int64 low; int dat,side;
	rec(void){}
	rec(__int64 a,int b,int c):low(a),dat(b),side(c){}
}c[20010];
pair<__int64,__int64> a[10010],b[10010];
#define x first
#define y second
map<__int64,int> hash;
int f[30010][10],n,k,m,tot,link,i,j;
bool g[10][10],v[10];

inline bool operator <(rec a,rec b) {return a.low<b.low;}
inline void change(rec a) {a.side==1?b[a.dat].x--:b[a.dat].y--;}
inline void crash(int v[10])
{
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++)
			if(v[i]&&!v[j]&&g[i][j]) g[i][j]=g[j][i]=0,link-=2;
}

void calc()
{
	int i,j,l,r;
	__int64 now,L,R;
	for(now=-1,i=1;i<=n;i++,now=R)
	{
		l=a[i].x%10,r=a[i].y%10;
		L=a[i].x/10,R=a[i].y/10;
		if(L!=now&&now>0) crash(f[0]),memset(f[0],0,sizeof(f[0]));
		if(L!=R)
		{
			for(j=l;j<=9;j++) f[0][j]++;
			crash(f[0]);
			memset(f[0],0,sizeof(f[0]));
			for(j=1;j<r;j++) f[0][j]++;
		}
		else for(j=l;j<r;j++) f[0][j]++;
	}
	crash(f[0]);
}

bool solve(int k)
{
	__int64 l,r,L,R,pow=1,now;
	int i,j,p,q,num=1;
	memset(f,0,sizeof(f));
	for(m=tot=i=0;i<k;i++) pow*=10;
	for(i=1;i<=n;i++)
	{
		L=a[i].x/pow,R=a[i].y/pow;
		if(!L&&!R) continue;
		l=a[i].x%pow,r=a[i].y%pow;
		b[++m]=make_pair(L+1,R+1);
		c[++tot]=rec(l,m,1),c[++tot]=rec(r,m,2);
	}
	if(!m) return 0;
	hash.clear();
	sort(c+1,c+tot+1);
	for(p=1;p<=tot&&!c[p].low;p++) change(c[p]);
	for(i=1,now=-1;i<=m;i++,now=R)
	{
		l=b[i].x%10,r=b[i].y%10;
		L=b[i].x/10,R=b[i].y/10;
		if(L!=now&&now>0) hash[now]=num++;
		if(L!=R)
		{
			for(j=l;j<=9;j++) f[num][j]++;
			hash[L]=num++;
			for(j=1;j<r;j++) f[num][j]++;
		}
		else for(j=l;j<r;j++) f[num][j]++;
	}
	hash[now]=num++;
	for(i=1;i<num;i++) crash(f[i]);
	for(;p<=tot;p=q)
	{
		for(q=p;q<=tot&&c[q].low==c[p].low;q++)
		{
			change(c[q]);
			now=c[q].side==1?b[c[q].dat].x:b[c[q].dat].y;
			k=now%10,now/=10;
			if(!hash[now]) hash[now]=num++;
			now=hash[now];
			if(c[q].side==1) f[now][k]++; else f[now][k]--;
		}
		for(i=1;i<num;i++) crash(f[i]);
	}
	return 1;
}

int main()
{
	freopen("laser16.in","r",stdin);
	freopen("laser16.out","w",stdout); 
	cin>>n>>k;
	for(i=1;i<=n;i++) scanf("%lld%lld",&a[i].x,&a[i].y),a[i].y++;
	memset(g,1,sizeof(g));
	link=72;
	calc();
	for(i=1;i<k&&solve(i)&&link;i++);
	for(i=1;i<=9;i++)
		if(!v[i])
		{
			cout<<i,v[i]=1;
			for(j=1;j<=9;j++)
				if(!v[j]&&g[i][j]) cout<<j,v[j]=1;
			cout<<endl;
		}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
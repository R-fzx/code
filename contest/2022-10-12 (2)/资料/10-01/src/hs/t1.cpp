#include<stdio.h>
#include<stdlib.h>
void Pre();
void Read();
void Count();
void Write();
int main()
{
	Pre();
	int n;
	freopen("t1.in","r",stdin);
	freopen("t1.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		Read(),
		Count(),
		Write();
	//system("pause");
	return 0;
}

const long long mod=10007;
long long ni[1100]={0};
inline long long Power(long long x,long long k)
{
	long long val=1;
	for(long long i=1,s=x;k;i<<=1,s=s*s%mod)
		if( k&i )	val=val*s%mod,k^=i;
	return val;
}

void Pre()
{
	for(int i=1;i<=1000;i++)
		ni[i]=Power(i,mod-2);
	return;
}

int num_point;
struct ROAD{struct ROAD *next;int p;}road[1100]={0};
struct POINT{struct ROAD *head;int size;long long num;}point[1100]={0};

int use=0;
inline void Link(int x,int y)
{
	struct ROAD *k=&road[use++];
	k->p=y,k->next=point[x].head,point[x].head=k;
	return;
}

void Read()
{
	scanf("%d",&num_point);
	use=0;
	for(int i=1;i<=num_point;i++)	point[i]=point[0];
	for(int k=1,n;k<=num_point;k++)
	{
		scanf("%d",&n);
		for(int i=0,v;i<n;i++)
			scanf("%d",&v),Link(k,v);
	}
	return;
}

inline long long Put(long long n,long long m)
{
	n+=(--m);
	long long val=1;
	for(long long i=0;i<m;i++)
		val=val*(n-i)%mod*ni[i+1]%mod;
	return val;
}
	
void Dfs(int x)
{
	for(struct ROAD *k=point[x].head;k;k=k->next)
		Dfs(k->p);
	point[x].num=1;
	if( point[x].head )
	{
		point[x].num=point[ point[x].head->p ].num;
		point[x].size=point[ point[x].head->p ].size;
		for(struct ROAD *k=point[x].head->next;k;k=k->next)
			point[x].num= point[x].num * point[k->p].num %mod * Put(point[x].size,point[k->p].size) %mod,
			point[x].size+=point[k->p].size;
	}
	point[x].size++;
	return;
}

int ans;
bool root[1100]={0};
void Count()
{
	for(int i=1;i<=num_point;i++)	root[i]=true;
	for(int x=1;x<=num_point;x++)
		for(struct ROAD *k=point[x].head;k;k=k->next)
			root[k->p]=false;
	for(int x=1;x<=num_point;x++)
		if( root[x] )	Dfs(x),ans=point[x].num;
	return;
}

void Write()
{
	printf("%d\n",ans);
	return;
}


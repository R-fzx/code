//garland
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int NUM=505;

struct node
{
	int num,x,y;
}q[NUM*NUM];

int n,lenq,val,ansmax;
int most[NUM][NUM],ans[NUM][NUM];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

inline bool cmp(node a,node b)
{
	return a.num>b.num;
}

inline void print()
{
	for(int i=1;i<=lenq;++i)
			ansmax+=ans[q[i].x][q[i].y]*q[i].num;
			
	cout<<ansmax;
	
	return ;
}

signed main()
{
	freopen("garland.in","r",stdin);
	freopen("garland.out","w",stdout);
	
	n=read();
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			int tempp;
			tempp=read();
			
			if(tempp)
			{
				q[++lenq].num=tempp;
				q[lenq].x=i;
				q[lenq].y=j;
			}
		}
	}
	
	sort(q+1,q+1+lenq,cmp);
	
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			ans[i][j]=read();
			val+=ans[i][j];
		}	
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			most[i][j]=read();
	
	if(val==0)	
	{	
		print();
		return 0;
	}
	
	val=-val;
	
	for(int i=1;i<=lenq;++i)
	{
		int temp=most[q[i].x][q[i].y]-ans[q[i].x][q[i].y];
		
		if(temp>=val)
		{
			ans[q[i].x][q[i].y]+=val;
			print();
			return 0;
		}
		else
		{
			ans[q[i].x][q[i].y]+=temp;
			val-=temp;
		}	
	}
	
	print();
	
	return 0;
}


#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;

const int bigp=10007;
vector <int> tree[1011];
int size[1011],f[1011],c[1011][1011];

void cal(int i)
{
	int nsize=size[i]-2;
	f[i]=1;
	for(vector <int> :: iterator j=tree[i].begin();j!=tree[i].end();++j)
	{
		f[i]=f[i]*f[*j]%bigp*c[nsize][size[*j]-1]%bigp;
		nsize-=size[*j];
	}
}

void solve(int i)
{
	size[i]=1;
	for(vector <int> :: iterator j=tree[i].begin();j!=tree[i].end();++j)
	{
		solve(*j);
		size[i]+=size[*j];
	}
	cal(i);
}

int main()
{
	int T,BK,n,i,j;
	freopen("t1.in","r",stdin);
	freopen("t1.out","w",stdout);
	scanf("%d",&T);
	for(i=0;i<=1000;++i)
	{
		c[i][0]=1;
		for(j=1;j<=i;++j)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%bigp;
	}
	
	for(BK=0;BK<T;++BK)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
		{
			int tot;
			scanf("%d",&tot);
			for(j=0;j<tot;++j)
			{
				int a;
				scanf("%d",&a);
				tree[i].push_back(a);
			}
		}
		solve(1);
		printf("%d\n",f[1]);
		for(i=1;i<=n;++i)
			tree[i].clear();
		memset(size,0,sizeof(size));
		memset(f,0,sizeof(f));
	}
	return 0;
}

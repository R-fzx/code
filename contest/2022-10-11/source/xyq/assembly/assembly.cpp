//assembly
#include<bits/stdc++.h>
using namespace std;

const int NUM=10;

struct node
{
	int b,l;
}c[NUM];

int n,k,a;
double ans;
double f[NUM][NUM][NUM];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

inline bool cmp(node x,node y)
{
	if(x.l>y.l)
		return 1;
	else if(x.l==y.l)
	{
		if(x.b<y.b)
			return 1;
	}
	
	return 0;
}

//inline void dfs(int x,int g,double maxn)
//{
//	int temp;
//	
//	if(x>n)
//	{
//		if(maxn>ans)
//			ans=maxn;
//		return ;
//	}
//	
//	while(g>0)
//	{
//		++temp;
//		
//		if(c[x].l<=90)
//		{
//			cout<<0.01*c[x].l+0.01*(90-c[x].l)*a*1.0/(a+c[x].b)*1.0<<endl; 
//			dfs(c[x].l+10,g-temp*1,maxn+0.01*c[x].l+0.01*(90-c[x].l)*a*1.0/(a+c[x].b)*1.0);
//			dfs(c[x].l,g,maxn+0.01*c[x].l+0.01*(100-c[x].l)*a*1.0/(a+c[x].b)*1.0);
//		}
//		else
//		{
//			dfs(c[x].l,g,maxn+0.01*c[x].l+0.01*(100-c[x].l)*a*1.0/(a+c[x].b)*1.0);
//		}
//	}
//	
//	dfs(c[x].l,g,maxn+0.01*c[x].l+0.01*(100-c[x].l)*a*1.0/(a+c[x].b)*1.0);
//}

signed main()
{
	freopen("assembly.in","r",stdin);
	freopen("assembly.out","w",stdout);
	
	n=read(),k=read(),a=read();
	for(int i=1;i<=n;++i)
		c[i].b=read(),c[i].l=read();
		
//	for(int i=1;i<=n;++i)
//		cout<<c[i].b<<"  "<<c[i].l<<endl;
		
	sort(c+1,c+1+n,cmp);
	
	for(int i=1;i<=n;++i)
	{
		for(int ll=1;ll<=k;++ll)
		{
			for(int j=ll;j<=k;++j)
			{
				int tempmax=0;
				for(int t=1;t<=j-ll+1;++t)
				{
					if(tempmax<f[i-1][j-ll][t])
						tempmax=f[i-1][j-ll][t];
				}
					
				f[i][j][ll]=0.01*(c[i].l+ll*10)+0.01*(max(0,100-ll*10-c[i].l))*((1.0*a)/(1.0*(a+c[i].b)));
//				cout<<0.01*(max(0,100-ll*10-c[i].l))<<endl;
//				if(tempmax>f[i][j][l])
				f[i][j][ll]+=tempmax;
			}
		}
	}
	
//	for(int i=1;i<=n;++i)
//		cout<<c[i].b<<"  "<<c[i].l<<endl;
	
//	dfs(1,k,0.0);

	for(int i=0;i<=k;++i)
	{
		if(f[n][k][i]>ans)
			ans=f[n][k][i];
	}
	
//	for(int i=0;i<=k;++i)
//		cout<<f[n][k][i]<<endl;
	
	printf("%.6lf",ans);
			
	return 0;
}


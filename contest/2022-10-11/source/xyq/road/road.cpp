//road
#include<bits/stdc++.h>
using namespace std;

const int NUM=50005;

struct node
{
	int from,to,val;
}e[NUM];

int n,m,p,q,cnt,num,ans,tail,sum1,sum2;
bool flag=1;
int fa[205];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

inline bool cmp(node a,node b)
{
	return a.val<b.val;
}

inline int dsu_find(int x)
{
	if(fa[x]==x)
		return x;
	
	return fa[x]=dsu_find(fa[x]);
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n=read(),m=read(),p=read(),q=read();
	for(int i=1;i<=m;++i)
	{
		int u,v,a,b;
		u=read(),v=read(),a=read(),b=read();
		
		e[i].from=u;
		e[i].to=v;
		e[i].val=a*p+b*q;
	} 
	
	if(m<n-1)
	{
		cout<<"-1";
		return 0;
	}
	
	sort(e+1,e+1+m,cmp);
	
	for(int i=1;i<=n;++i)
		fa[i]=i;
	
	for(int i=1;i<=m+1;++i)
	{
		if(i>tail)
		{
			if(sum1!=sum2)
			{
				flag=0;
				break;
			}
			
			sum1=0;
			
			for(int j=i;j<=m+1;++j)
			{
				if(e[j].val!=e[i].val)
				{
					tail=j-1;
					break;
				}
				
				if(dsu_find(e[j].from)!=dsu_find(e[j].to))
					++sum1; 
			}
			
			sum2=0;
		}
		
		if(i>m)	
			break;
			
		int findx=dsu_find(e[i].from),findy=dsu_find(e[i].to);
		if(findx!=findy && num!=n-1)
		{
			++sum2;
			++num;
			fa[findx]=fa[findy];
//			cout<<"!!!"<<endl;
			ans=max(ans,e[i].val);
		}
	}
	
	if(flag)
		cout<<ans;
	else
		cout<<"-1";
	
	return 0;
}


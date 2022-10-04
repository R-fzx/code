//puppet
#include<bits/stdc++.h>
using namespace std;

const int NUM=105;

int n;
int a[NUM],p[NUM][NUM],f[NUM];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

signed main()
{
	freopen("puppet.in","r",stdin);
	freopen("puppet.out","w",stdout);
	
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;++i)
			a[i]=read();
		
		sort(a+1,a+1+n);
		
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				bool flag=0;
				for(int k=1;k<=j-i+1;++k)
				{
					int pu1=i,pu2=i+k;
					while(pu2<=j)
					{
						if(a[pu2]-a[pu1]>1)
							flag=1;
							
						++pu1;
						++pu2;
					}
					
					if(abs(a[pu1]-a[i+k-1]<=1))
						flag=1;
						
					if(flag==1)
					{
						p[i][j]=k-1;
						break;
					}
				}
				
            	if(flag==0)
            		p[i][j]=j-i+1;
			}
		}
		
		for(int i=1;i<=n;++i)
			f[i]=0;
		
		for(int i=1;i<=n;++i)
			for(int j=1;j<=i;++j)
				f[i]=max(f[i],f[j-1]+p[j][i]);
				
        cout<<f[n]<<endl;
	}
	
	return 0;
}


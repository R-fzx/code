//rabbit
#include<bits/stdc++.h>
using namespace std;

const int NUM=1005;

int n,ans;
int gx[NUM][NUM],sol[NUM*NUM][5];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

signed main()
{
	freopen("rabbit.in","r",stdin);
	freopen("rabbit.out","w",stdout);
	
	n=read();
	
	if(n==3)
	{
		printf("3\n");
		for(int i=1;i<=3;++i)
			printf("1 2 3\n");
		return 0;
	}
	
	for(int i=1;i<n-1;++i)
	{
		for(int j=i+1;j<n;++j)
		{
			if(gx[i][j]>=3)
			{
				continue;
			}
			
			for(int k=j+1;k<=n;++k)
			{
				if(gx[i][k]>=3 || gx[j][k]>=3)
				{
					continue;
				}
				
				if(gx[i][j]<3 && gx[j][k]<3 && gx[i][k]<3)
				{
					sol[++ans][1]=i;
					sol[ans][2]=j;
					sol[ans][3]=k;
					
					++gx[i][j];
					++gx[i][k];
					++gx[j][k];
					
//					cout<<"!!!!"<<endl;
				}
			}
		}
	}
	
	printf("%d\n",ans);
	for(int i=1;i<=ans;++i)
		printf("%d %d %d\n",sol[i][1],sol[i][2],sol[i][3]);
	
	return 0;
}


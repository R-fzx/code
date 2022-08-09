//snowman
#include<bits/stdc++.h>
using namespace std;

int n,m,maxn;
int a[100005];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

signed main()
{
	freopen("snowman.in","r",stdin);
	freopen("snowman.out","w",stdout);
	
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
		
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			int tempi=i+1,tempj=j+1,tempnum=abs(a[i]-a[j]);
			
//			cout<<tempnum<<endl;
			
			while(abs(a[tempi]-a[tempj])==tempnum)
			{
				maxn=max(maxn,min(tempnum,tempi-i+1));
				++tempi;
				++tempj; 
			}	
		}
	}
	
	cout<<maxn;
		
	fclose(stdin);
	fclose(stdout);

	return 0;
}


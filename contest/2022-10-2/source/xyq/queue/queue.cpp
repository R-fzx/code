//queue
#include<bits/stdc++.h>
using namespace std;

const int NUM=305;

int n,maxn,anst,cnt,tot;
double ans;
int h[NUM],num[1005],a[NUM],taller[NUM],shorter[NUM],sum[NUM],jc[NUM];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

signed main()
{
	freopen("queue.in","r",stdin);
	freopen("queue.out","w",stdout);
	
	n=read();
	cnt=n;
	for(int i=1;i<=n;++i)
	{
		h[i]=read();
		++num[h[i]];
		maxn=max(maxn,h[i]);
	}
	
	sum[1]=1;
	jc[1]=1;
	for(int i=2;i<=n;++i)
	{
		sum[i]=sum[i-1]+i;
		jc[i]=jc[i-1]*i;
	}
	
	for(int i=maxn;i>=1;--i)
	{
		if(num[i])
		{
			a[cnt]=num[i];
			tot+=num[i];
			taller[cnt]=tot-1;
			shorter[cnt]=n-tot+1;
			--cnt;
		}
	}
	
	for(int i=cnt+1;i<=n;++i)
	{
		if(taller[i]==0)
			anst+=sum[i];
		else if(shorter[i]==0)
			anst+=n;
		else
			anst+=a[i]*(taller[i]+shorter[i]*(n-taller[i]-1)+1);
		
//		cout<<"!!!"<<shorter[i]<<endl;
//		cout<<anst<<endl;
	}
	
	anst*=2;
//	cout<<jc[n]<<endl;
	ans=anst*1.0/jc[n];
	
	printf("%.2lf",ans);
	
	return 0;
}


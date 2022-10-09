#include<bits/stdc++.h>
#define int long long
inline int read()
{	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c))f|=(c=='-'),c=getchar();
	while(isdigit(c))x=x*10+(c&15),c=getchar();
	return f?-x:x;
}
using namespace std;
int n,bs,maxn,ans;
double f;
signed main()
{	freopen("baseball.in","r",stdin);
	freopen("baseball.out","w",stdout);
	while(scanf("%d%lf",&n,&f)!=EOF)
	{	ans=1;
		bs=pow(10,n+1);
		maxn=bs*f;
		while(1)
		{	int l=1,r=ans;
			while(l<r)
			{	int mid=(l+r)>>1;
				if(bs*mid/ans>=maxn)r=mid;
				else l=mid+1;
			}
			if((bs*l/ans-maxn>=0&&bs*l/ans-maxn<=4)||(maxn-bs*(l-1)/ans<=5&&maxn-bs*(l-1)/ans>=0))
			{	printf("%lld\n",ans);
//				cerr<<l<<endl;
				break;
			}
			ans++;
//			cerr<<ans<<endl;
		}
	}
	return 0;
}


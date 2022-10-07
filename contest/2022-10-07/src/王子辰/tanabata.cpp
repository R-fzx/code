#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
int n,m,T,ans;
int cnt1[10010],cnt2[10010],a[10010];
int main()
{
	freopen("tanabata.in","r",stdin);
	freopen("tanabata.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1,x,y;i<=T;i++)
	{
		scanf("%d%d",&x,&y);
		cnt1[x]++;
		cnt2[y]++;
	}
	if(T%n==0)
	{
		int tot1=0x7fffffff;
		for(int i=1;i<=n;i++)
		{
			int tot=0;
			memcpy(a,cnt1,sizeof cnt1);
			for(int j=i,cnt=1;cnt<=n;j++,cnt++)
			{
				if(j==n+1) j=1;
				int t=j+1;
				if(t==n+1) t=1;
				a[t]+=a[j]-T/n;
				tot+=abs(a[j]-T/n);
			}
			tot1=min(tot1,tot);
		}
		ans+=tot1;
	}
	if(T%m==0)
	{
		int tot2=0x7fffffff;
		for(int i=1;i<=m;i++)
		{
			int tot=0;
			memcpy(a,cnt2,sizeof cnt2);
			for(int j=i,cnt=1;cnt<=m;j++,cnt++)
			{
				if(j==m+1) j=1;
				int t=j+1;
				if(t==m+1) t=1;
				a[t]+=a[j]-T/m;
				tot+=abs(a[j]-T/m);
			}
			tot2=min(tot2,tot);
		}
		ans+=tot2;
	}
	if(T%n!=0&&T%m!=0) printf("impossible\n");
	else if(T%n==0&&T%m==0) printf("both ");
	else if(T%n==0&&T%m!=0) printf("row ");
	else if(T%n!=0&&T%m==0) printf("column ");
	if(T%m==0||T%n==0) printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

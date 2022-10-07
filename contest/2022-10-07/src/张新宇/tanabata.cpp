#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
int n,m,T,ans;
int pol[1010];
int plt[1010],a[1010];
int main()
{
	freopen("tanabata.in","r",stdin);
	freopen("tanabata.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1,x,y;i<=T;i++)
	{
		scanf("%d%d",&x,&y);
		pol[x]++;
		plt[y]++;
	}
	if(T%n==0)
	{
		int tatal1=0x7fffffff;
		for(int i=1;i<=n;i++)
		{
			int tatal=0;
			memcpy(a,pol,sizeof pol);
			for(int j=i,cnt=1;cnt<=n;j++,cnt++)
			{
				if(j==n+1) j=1;
				int t=j+1;
				if(t==n+1) t=1;
				a[t]+=a[j]-T/n;
				tatal+=abs(a[j]-T/n);
			}
			tatal1=min(tatal1,tatal);
		}
		ans+=tatal1;
	}
	if(T%m==0)
	{
		int tatal2=99999999;
		for(int i=1;i<=m;i++)
		{
			int tatal=0;
			memcpy(a,plt,sizeof plt);
			for(int j=i,cnt=1;cnt<=m;j++,cnt++)
			{
				if(j==m+1) j=1;
				int t=j+1;
				if(t==m+1) t=1;
				a[t]+=a[j]-T/m;
				tatal+=abs(a[j]-T/m);
			}
			tatal2=min(tatal2,tatal);
		}
		ans+=tatal2;
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

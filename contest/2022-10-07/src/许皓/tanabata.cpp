#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int n,m,t,row[100010],col[100010],a[100010];
void read()
{
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1,a,b;i<=t;i++)
	{
		scanf("%d%d",&a,&b);
		row[a]++;
		col[b]++;
	}
}
int cal_row()
{
	int num=t/n;
	int ans=9999999;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) a[j]=row[j];
		int ct=0;
		bool fg=true;
		for(int j=i;fg||j!=i;j++)
		{
			fg=false;
			if(j==n+1) {j=0;continue;}
			if(a[j]!=num)
			{
				int jj=abs(num-a[j]);
				ct=ct+jj;
				if(a[j]<num) a[j+1]=a[j+1]-jj;
				else a[j+1]=a[j+1]+jj;
			}
		}
		ans=min(ans,ct);
	}
	return ans;
}
int cal_col()
{
	int num=t/m;
	int ans=9999999;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++) a[j]=row[j];
		int ct=0;
		bool fg=1;
		for(int j=i;fg||j!=i;j++)
		{
			fg=false;
			if(j==m+1) {j=0;continue;}
			if(a[j]!=num)
			{
				int jj=abs(num-a[j]);
				ct=ct+jj;
				if(a[j]<num) a[j+1]=a[j+1]-jj;
				else a[j+1]=a[j+1]+jj;
			}
		}
		ans=min(ans,ct);
	}
	return ans;
}
void go()
{
	int cnt=0;
	if(t%n==0&&t%m==0)
	{
		printf("both ");
		cnt=cal_row()+cal_col();
		printf("%d",cnt);
	}
	else if(t%n==0&&t%m!=0)
	{
		printf("row ");
		cnt=cal_row();
		printf("%d",cnt);
	}
	else if(t%n!=0&&t%m==0)
	{
		printf("col ");
		cnt=cal_col();
		printf("%d",cnt);
	}
	else printf("impossible");
}
int main()
{
	freopen("tanabata.in","r",stdin);
	freopen("tanabata.out","w",stdout);
	read();
	go();
	//system("pause");
	return 0;
}

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

int n,m,T;
int row[100001],column[100001];
int b[100001];
int flag1,flag2;
int aim1,aim2;
int tot=0;

int main()
{
	freopen("tanabata.in","r",stdin);
	freopen("tanabata.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	if(T%n==0&&T/n) flag1=1;
	if(T%m==0&&T/m) flag2=1;
	for(int i=1,x,y;i<=T;i++)
	{
		scanf("%d%d",&x,&y);
		row[x]++,column[y]++;
		row[x+n]++,column[y+m]++;
	}
	if(flag1==1&&flag2==1) printf("both ");
	else if(flag1==1) printf("row ");
	else if(flag2==1) printf("column ");
	else printf("impossible");
	if(flag1==1)
	{
		aim1=T/n;
		int t=0x3f3f3f3f;
		for(int i=1;i<=n;i++)
		{
			int ans=0;
			for(int j=i;j<=i+n-1;j++) b[j]=row[j];
			for(int j=i;j<i+n-1;j++)
			{
				ans+=abs(b[j]-aim1);
				b[j+1]+=b[j]-aim1;
			}
			t=min(ans,t);
		}
		tot+=t;
	}
	if(flag2==1)
	{
		aim2=T/m;
		int t=0x3f3f3f3f;
		for(int i=1;i<=m;i++)
		{
			int ans=0;
			for(int j=i;j<=i+m-1;j++) b[j]=column[j];
			for(int j=i;j<i+m-1;j++)
			{
				ans+=abs(b[j]-aim2);
				b[j+1]+=b[j]-aim2;
			}
			t=min(ans,t);
		}
		tot+=t;
	}
	if(flag1||flag2)
		printf("%d",tot);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


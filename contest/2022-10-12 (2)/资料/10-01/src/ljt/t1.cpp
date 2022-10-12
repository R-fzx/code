#include<stdio.h>

int t,n;
const int MAX=2000; 
int map[MAX][MAX];
int number[MAX];
int ru[MAX];
int hash[MAX];
int num;

void dfs(int l)
{
	if(l==n)
	{
		num++;
		num=num%10007;
		return;
	}
	for(int i=n;i>0;i--)
	{
		if(!hash[i]&&!ru[i])
		{
			for(int j=1;j<=number[i];j++)
			{
				--ru[map[i][j]];
			}
			hash[i]=1;
			dfs(l+1);
			hash[i]=0;
			for(int j=1;j<=n;j++)
			{
				++ru[map[i][j]];
			}
		}
	}
	return;
}

void doit()
{
	for(int i=2;i<=n;i++)
	{
		ru[i]=1;	
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=number[i];j++)
		{
			for(int k=j+1;k<=number[i];k++)
			{
				if(map[i][j]==map[i][k]+1)
				{
					map[map[i][j]][++number[map[i][j]]]=map[i][k];
					ru[map[i][k]]++;
				}else if(map[i][j]==map[i][k]-1)
				{
					map[map[i][k]][++number[map[i][k]]]=map[i][j];
					ru[map[i][j]]++;
				}
			}
		}
	}
	num=0;
	dfs(0);
	printf("%d\n",num);
}

void init()
{
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&number[i]);
		for(int j=1;j<=number[i];j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
	doit();
}

void tot()
{
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		init();
	}
}

int main()
{
	freopen("t1.in","r",stdin);
	freopen("t1.out","w",stdout);
	tot();
}

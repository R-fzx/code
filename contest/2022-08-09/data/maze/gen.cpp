#include<bits\stdc++.h>
#include<windows.h>
using namespace std;
int n,m,x,k,a[22][22],aa,bb;
bool used[22][22];
int get(int y)
{
	return ((rand()<<11)+rand())%y+1;
}
int main()
{
	srand(GetTickCount());
	int kk = 1000000000;
	n=20;m=20;x=get(kk);k=3;
	for (int i=1;i<=k;i++)
	{
		aa=rand()%n+1;bb=rand()%m+1;
		while((aa==1 && bb==1) || (aa==n && bb==m))
		{
			aa=rand()%n+1;bb=rand()%m+1;
		}
		a[aa][bb]=-1;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (a[i][j]!=-1) a[i][j]=get(kk);
			else a[i][j]=0;
		}
	}
	printf("%d %d %d\n",n,m,x);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}

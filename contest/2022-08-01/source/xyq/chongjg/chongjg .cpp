//3
#include<bits/stdc++.h>
using namespace std;

int n,m;
int co[105][105];
char mapp[27]={' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

void dfs(int x,int y,int lx,int ly)
{
	int tempup=co[lx-1][ly],templeft=co[lx][ly-1],temp,minn=min(x,y);
	
	cout<<tempup<<"  "<<templeft<<endl;
	
	for(int i=1;i<=26;++i)
	{
		if(i!=tempup && i!=templeft)
		{
			temp=i;
			break;
		}
	}
	
	for(int i=lx;i<=lx+minn-1;++i)
		for(int j=ly;j<=ly+minn-1;++j)
			co[i][j]=temp;
	
	if(x==y)
		return ;
	else
	{
		if(x>y)
			dfs(x-y,y,lx+minn-1,ly);
		else
			dfs(x,y-x,lx,ly+minn-1);
	}
}

int main()
{
	freopen("chongjg.in","r",stdin);
	freopen("chongjg.out","w",stdout);
	
	n=read(),m=read();
	
	if(n==m)
	{
		printf("A");
		return 0;
	}
	
	if(n==1 || m==1 || (n==1 && m==1))
	{
		for(int i=1;i<=max(m,n);++i)
		{
			if(i%2!=0)
				cout<<"A";
			else
				cout<<"B";
		}
		
		return 0;
	}
	
	dfs(n,m,1,1);
	
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
			cout<<mapp[co[i][j]];
		cout<<endl;
	}
	
  fclose(stdin);
  fclose(stdout);

	return 0;
}


#include<cstdio>
using namespace std;

int n,m;

void scanff()
{
	scanf("%d%d",&n,&m);
}

int maxt[103][103]={{0}};
int tot=0;

void fang(int x,int y,int color)
{
	int len;
	for(len=0;;len++)
	{
		if(x+len>=n)break;
		if(y+len>=m)break;
		
		int k;
		bool ok=true;
		for(int i=x;i<=x+len+1;i++)
		{
			for(int j=y;j<=y+len+1;j++)
			{
				if(maxt[i][j]!=0){ok=false;break;}
			}
			if(!ok)break;
		}
		if(!ok)break;
		for(int i=x;i<=x+len+1;i++)
		{
			if(maxt[i][y-1]==color||maxt[i][y+len+2]==color){ok=false;break;}
		}
		if(!ok)break;
		for(int i=y;i<=y+len+1;i++)
		{
			if(maxt[x-1][i]==color||maxt[x+len+2][i]==color){ok=false;break;}
		}
		if(!ok)break;
		for(k=1;k<color;k++)
		{
			if(k!=maxt[x][y+len]&&k!=maxt[x-1][y+len+1]&&k!=maxt[x+1][y+len+1]&&k!=maxt[x][y+len+2])
			{ok=false;break;}
		}
		if(!ok)break;
	}
	for(int i=x;i<=x+len;i++)
	{
		for(int j=y;j<=y+len;j++)
		{
			maxt[i][j]=color;
		}
	}
}

void work()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(!maxt[i][j])
			{
				int k;
				for(k=1;k<=tot;k++)
				{
					if(k!=maxt[i][j-1]&&k!=maxt[i-1][j]&&k!=maxt[i+1][j]&&k!=maxt[i][j+1])
					{
						break;
					}
				}
				if(k==tot+1)tot++;
				fang(i,j,k);
			}
		}
	}
}

void printff()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			printf("%c",maxt[i][j]+'A'-1);
		}
		printf("\n");
	}
}

int main()
{
	freopen("chongjg.in","r",stdin);
	freopen("chongjg.out","w",stdout);
	scanff();
	work();
	printff();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<cstdio>
using namespace std;

int n,m;

struct sss
{
	int bian;
	struct sss *next;
}p[100003],nc[200003],*tp,*wei[100003];
int ppp=-1;

int in[100003]={0};
int out[100003]={0};//入度和出度 

void scanff()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)p[i].bian=i,p[i].next=NULL,wei[i]=&p[i];
	int ai,bi;
	for(int i=1;i<=m;i++)//建逆图 
	{
		scanf("%d%d",&ai,&bi);
		tp=&nc[++ppp];tp->bian=bi;tp->next=NULL;
		wei[ai]->next=tp;wei[ai]=tp;
		in[bi]++;
		out[ai]++;
	}
}
//126219597
int f[100003]={0};

int dui[100003]={0};

int hash[100003]={0};//哪些是生产者 
int sum=0;

void dfs(int la)
{
	if(out[la]==0&&!hash[la])
	{
		sum++;
		return;
	}
	struct sss *tp1=&p[la];
	for(;tp1->next!=NULL;)
	{
		tp1=tp1->next;
		dfs(tp1->bian);
	}
}

void work()
{
	for(int i=1;i<=n;i++)
	{
		if(in[i]==0)
		{
			hash[i]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(hash[i])
		{
			dfs(i);
		}
	}
	printf("%d",sum);
}

int main()
{
	freopen("lyx8.in","r",stdin);
	freopen("lyx8.out","w",stdout);
	scanff();
	work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

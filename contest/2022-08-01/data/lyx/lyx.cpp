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
		tp=&nc[++ppp];tp->bian=ai;tp->next=NULL;
		wei[bi]->next=tp;wei[bi]=tp;
		in[ai]++;
		out[bi]++;
	}
}
//126219597
int f[100003]={0};

int dui[100003]={0};

int hash[100003]={0};//哪些是生产者 
int head,tail;
void work()
{
	int head=0,tail=0;
	for(int i=1;i<=n;i++)
	{
		if(out[i]==0)
		{
			hash[i]=1;
		}
		if(in[i]==0&&out[i])
		{
			f[i]=1;
			dui[tail++]=i;
		}
	}
	
	for(;head<tail;)
	{
		int c=dui[head++];
		struct sss *tp1=&p[c];
		for(;tp1->next!=NULL;)
		{
			tp1=tp1->next;
			f[tp1->bian]+=f[c];
			in[tp1->bian]--;
			
			if(!in[tp1->bian])
			dui[tail++]=tp1->bian;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(hash[i])ans+=f[i];
	}
	printf("%d",ans);
}

int main()
{
	freopen("lyx6.in","r",stdin);
	freopen("lyx6.out","w",stdout);
	scanff();
	work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

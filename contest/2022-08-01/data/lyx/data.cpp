#include<cstdio>
#include<ctime>
#include<algorithm>
#include<set>
using namespace std;
char s[11]={"lyx\0.in"};

struct cun
{
	int qian;
	int hou;
};

struct sss
{
	int bian;
	struct sss *next;
}p[100001],*wei[100001];
int n=50000,m=100000;

int tot=0;

struct orz
{
	int ai;
	int bi;
	friend bool operator < (const orz &s1,const orz &s2)
	{
		return s1.ai<s2.ai||(s1.ai==s2.ai&&s1.bi<s2.bi);
	}
}; 
set<orz>ss;
void work()
{
	printf("%d %d\n",n,m);
/*	{
		for(int i=1;i<tot;i++)
		{
			if(rand()%100+1>=70)
			{
				printf("%d %d\n",i,tot);
				m--;
			}
			if(!m)break;
		}
		if(!m)break;
	}*/
	ss.clear();
	for(int i=1;i<=m;i++)
	{
		int a=rand()%n+1,b=rand()%n+1;
		if(a==b)
		{
			i--;
			continue;
		}
		if(a>b)swap(a,b);
		orz yjg;
		yjg.ai=a;yjg.bi=b;
		if(ss.find(yjg)!=ss.end())
		{
			i--;
			continue;
		}
		ss.insert(yjg);
		printf("%d %d\n",a,b);
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int z;
	scanf("%d%d%d",&z,&n,&m);
	for(int i=1;i<=n;i++)
	{
		p[i].next=NULL;
		p[i].bian=i;
		wei[i]=&p[i];
	}
	s[3]='0'+z;
	freopen(s,"w",stdout);
	work();
	fclose(stdout);
	return 0;
}

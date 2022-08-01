#include<cstdio>
#include<ctime>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
int n=100,m=1000000;
struct cuns
{
	char a[21];
	int l;
	friend bool operator <(const cuns &s1,const cuns &s2)
	{
		int a=strcmp(s1.a,s2.a);
		if(a<0)return true;
		return false;
	}
};
set<cuns> s;

char qan[1000001];

void get(char ss[],int len)
{
	for(int i=0;i<len;i++)
	{
		ss[i]='a'+rand()%26;
	}
	ss[len]='\0';
}
void work()
{
	s.clear();
	printf("%d\n",n);
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=i;j++)
		{
			printf("q");
		}
		printf("\n");
	}
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<i;j++)
		{
			printf("q");
		}
		printf("a");
		printf("\n");
	}
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=i-3;j++)
		{
			printf("q");
		}
		printf("orz");
		printf("\n");
	}
	printf("yjg\n");
	for(int i=2;i<=20;i++)
	{
		printf("a");
		for(int j=2;j<=i;j++)
		{
			printf("q");
		}
		printf("\n");
	}
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<i;j++)
		{
			printf("q");
		}
		printf("z");
		printf("\n");
	}
	for(int i=1;i<=m;i++)
	{
		if(rand()%100+1>=93)printf("a");
		else	printf("q");
	}
	printf("\n");
	double p=1-(double)(rand()%20)/100;
	p=0.99;
	int k=rand()%1000+1;
	printf("%.2lf %d\n",p,k);
}

int main()
{
	srand((unsigned)time(NULL));
	freopen("ppfish8.in","w",stdout);
	work();
	fclose(stdout);
	return 0;
}

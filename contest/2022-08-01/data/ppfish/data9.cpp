#include<cstdio>
#include<ctime>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
int n=200,m=1000000;
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

char zan[1000001];

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
			printf("z");
		}
		printf("\n");
	}
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<i;j++)
		{
			printf("z");
		}
		printf("a");
		printf("\n");
	}
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<i;j++)
		{
			printf("z");
		}
		printf("b");
		printf("\n");
	}
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<i;j++)
		{
			printf("z");
		}
		printf("c");
		printf("\n");
	}
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<i;j++)
		{
			printf("z");
		}
		printf("d");
		printf("\n");
	}
	
	
	
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=i;j++)
		{
			printf("j");
		}
		printf("\n");
	}
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<i;j++)
		{
			printf("z");
		}
		printf("e");
		printf("\n");
	}
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<i;j++)
		{
			printf("z");
		}
		printf("f");
		printf("\n");
	}
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<i;j++)
		{
			printf("z");
		}
		printf("g");
		printf("\n");
	}
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<i;j++)
		{
			printf("z");
		}
		printf("h");
		printf("\n");
	}
	for(int i=1;i<=m;i++)
	{
		if(rand()%100+1>=93)printf("a");
		else printf("z");
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
	freopen("ppfish9.in","w",stdout);
	work();
	fclose(stdout);
	return 0;
}

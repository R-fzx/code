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
	for(int i=1;i<=n;i++)
	{
		cuns orz;
		get(orz.a,11);
		orz.l=11;
		if(s.find(orz)!=s.end())
		{
			i--;
		}
		s.insert(orz);
		printf("%s\n",orz.a);
	}
	int sum=0;
	set<cuns>::iterator it;
	for(it=s.begin();it!=s.end();it++)
	{
		int times=rand()%10;
		sum+=times*11;
		if(sum>=m)
		{sum-=times*11;break;}
		for(int i=1;i<=times;i++)
		{
			printf("%s",it->a);
		}
	}
	printf("\n");
	double p=1-(double)(rand()%20)/100;
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

#include<fstream>
#include<cmath>
#include<string.h>
#include<iostream>
using namespace std;
ifstream fin("t2.in");
ofstream fout("t2.out");

long long power(long long a,int b)
{
	if(b==1)return a;
	if(b==0)return 1;
	return power(a,b/2)*power(a,b/2)*power(a,b%2);
}

long long  p[100];
long long g[100];

/*long long check(int k,int p)
{
	long long l=0,r=p;
	while(l<r)
	{
		long long mid=(l+r+1)/2;
		long long t=power(mid,k);
		if(t>p)
		{
			r==mid-1;
		}else
		{
			l=mid;
		}
	}
	return l;
}*/
long long check(long long mi,long long p)
{
	long long mid,l=1,r=p,o,i;
	while(l<r)
	{
		mid=(l+r+1)/2;
		for(o=p,i=1;i<=mi;i++)
			o=o/mid;
		if(o>=1)
			l=mid;
		else
			r=mid-1;
	}
	return l;
}
long long  doit(long long  b)
{
	for(int i=0;i<100;i++)
	{
		p[i]=g[i]=0;
	}
	int k=1;
	for(k=1;k<61;k++)
	{
		p[k]=check(k,b);
	}
	long long answer=0;
	for(int j=k;j>=1;j--)
	{
		g[j]=p[j];
		for(int i=2;i*j<=k;i++)
		{
			p[j]-=p[i*j];
		}
		answer=answer+p[j]*j;
	}
	return answer;
}

int main()
{
	while(1)
	{
		long long a,b;
		fin>>a>>b;
		if(a==0&&b==0)
		{
			break;
		}
		fout<<doit(b)-doit(a-1)<<endl;
	}
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

long N,K,num[10],sum,flag;
bool g[10];
double B[10],L[10],A,z[10],zz[10][2];
double Ans,total;
void Read()
{
	long i,j;
	scanf("%ld%ld%lf",&N,&K,&A);
	for(i=1;i<=N;i++)
		scanf("%lf%lf",&B[i],&L[i]);
}
void Dfs2(long n)
{
	if(n==sum+1)
	{
		long i;
		double j=1,b=0,now=0;
		for(long i=1;i<=sum;i++)
		{
			if(g[i]==false)
			{
				j*=(100.0-zz[i][1])/100.0;
				b+=B[(long)zz[i][0]];
			}
			else
			{
				j*=(zz[i][1])/100.0;
				now++;
			}
		}
		if(now+N-sum>N/2)total+=j;
		else j*=(A/(A+b)),total+=j;
		return;
	}
	g[n]=false;
	Dfs2(n+1);
	g[n]=true;
	Dfs2(n+1);
}
void Work()
{
	memset(z,0,sizeof(z));
	memset(g,false,sizeof(g));
	long i,j,k;
	for(i=1;i<=N;i++)
		z[i]=min(L[i]+num[i]*10.0,100.0);
	
	sum=0;
	for(i=1;i<=N;i++)
		if(z[i]<100){
			zz[++sum][0]=(double)i;
			zz[sum][1]=z[i];
		} 
		else if(z[i]==100)flag++;
	if(flag+flag>N)return ;
	total=0;
	Dfs2(1); 
	if(Ans<total)Ans=total;
}
void Dfs(long n,long k)
{
	if(n==N+1)
	{
		flag=0;
		Work();
		return;
	}
	if(flag+flag>N)return ;
	long i,j;
	for(i=0;i<=k;i++)
	{
		num[n]=i;
		Dfs(n+1,k-i);
		//num[n]=0;
	}
	return;
}
void Write()
{
	printf("%.6lf\n",Ans);
}
int main()
{
	freopen("assembly.in","r",stdin);
	freopen("assembly.out","w",stdout);
	Read();
	Dfs(1,K);
	if(flag+flag>N)printf("1.000000\n");
	else Write();
	return 0;
}

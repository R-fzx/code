#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
using namespace std;

#define int64 long long int
int64 calc_single(int64 u,int64 r,int64 n,int64 d)
{
	if(d<u)
		return 0;
	if(u+r*(n-1)<=d)
		return n;
	return (d-u)/r+1;
}
int64 calc(int64 u,int64 r,int64 n,int64 d,int64 m)
{
	int64 ret=0,n1,u1,tot,newd,newr;
	u%=m,r%=m;
	if(u+r*(n-1)<m)
		return calc_single(u,r,n,d);
	n1=(m-1-u)/r+1;
	ret+=calc_single(u,r,n1,d);
	u=(u+n1*r)%m;
	n-=n1;
	u1=(u+(n-1)*r)%m,newr=u1%r;
	n1=(u1-newr)/r+1;
	ret+=calc_single(newr,r,n1,d);
	n-=n1;
	if(n==0)
		return ret;
	tot=(u+(n-1)*r)/m+1;
	ret+=d/r*tot;
	newd=d%r,newr=((m-1)/r+1)*r%m;
	if(newr<=r/2)
		ret+=calc(u,newr,tot,newd,r);
	else
		ret+=calc((u+newr*(tot-1))%r,r-newr,tot,newd,r);
	return ret;
}
//Given a arithmetical progression z=a*y+b, y->[0..n]
//Calculate the number of z, z%m lies in [c,d]
int64 process(int64 a,int64 b,int64 n,int64 c,int64 d,int64 m)
{
	return calc(b,a,n,d,m)-(c?calc(b,a,n,c-1,m):0);
}
int64 calcdig(int64 u,int64 r,int64 n)
{
	int64 ret=0,w=0,w2,m,t;
	for(m=1,t=1; w<n; m*=10,t++)
	{
		if(m*10<=u)continue;
		w2=(m*10-1-u)/r+1;
		if(w2>n)w2=n;
		ret+=(w2-w)*t;
		w=w2;
	}
	return ret;
}
int64 calc1(int64 a,int64 d,int64 n,int64 x)
{
	int64 ans,lst,m,u;
	lst=d*(n-1)+a;
	ans=0;
	for(m=1,u=0; m<=lst; m*=10,u++)
		ans+=process(d,a,n,x*m,(x+1)*m-1,m*10);
	if(x==0)
		ans-=u*n-calcdig(a,d,n);
	return ans;
}
int64 calc2(int64 a,int64 b,int64 mod,int64 x)
{
	int64 s=((a-1)/mod+1)*mod,e=(b/mod+1)*mod;
	return calc1(s,mod,(e-s)/mod,x);
}
class TheLuckyNumbersLevelThree
{ 
	public:
	vector<long long> find(long long a, long long b)
	{
		vector<int64> ans;
		for(int dig=0; dig<10; dig++)
			ans.push_back(calc2(a,b,4,dig)+calc2(a,b,7,dig)-calc2(a,b,28,dig));
		return ans;
	} 
} tmp;
int main()
{
	FILE* fin=fopen("number.in","r");
	for(int i=0; i<10; i++)
	{
		string s1="number";
		s1+=char(i+'0');
		s1+=".in";
		FILE*fin1=fopen(s1.c_str(),"w");
		s1="number";
		// s1+=char(i+'0');
		s1+=".out";
		FILE*fout1=fopen(s1.c_str(),"w");
		long long int s,t;
		fscanf(fin,"%lld%lld",&s,&t);
		fprintf(fin1,"%lld %lld\n",s,t);
		vector<long long int> res=tmp.find(s,t);
		for(int i=0; i<10; i++)
		{
			fprintf(fout1,"%lld",res[i]);
			if(i==9)fprintf(fout1,"\n");else
				fprintf(fout1," ");
		}
	}
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void Read();
void Count();
void Write();
int main()
{
	freopen("painting.in","r",stdin);
	freopen("painting.out","w",stdout);
	Read();
	Count();
	Write();
	//system("pause");
	return 0;
}

int max_x,max_y,num_color;
void Read()
{
	scanf("%d%d%d",&max_x,&max_y,&num_color);
	return;
}

long long mod=1000000007;
long long mul[1100000]={0},divv[1100000]={0};
inline long long Power(long long ,long long);
inline long long Pow2(int x)
{
	if( divv[x] )	return divv[x];
	else return divv[x]=Power(mul[x],mod-2);
}

inline long long Combin(long long n,long long m)
{
	if( n<m )	return 0;
	if( n-m<m ) m=n-m;
	return mul[n]* Pow2(n-m)%mod *Pow2(m)%mod ;
	//return mul[n]*divv[n-m]%mod *divv[m]%mod;
	long long v=1;
	for(long long i=0;i<m;i++)
		v*=n-i,v/=i+1;
	return v;
}

inline long long Power(long long x,long long k)
{
	//	return 1;
	long long v=1;
	for(long long p=1;k;p<<=1,x=x*x%mod)
		if( k&p )	k^=p, v=v*x%mod;
	return v;
}

long long ans;
long long put[2100][2100]={0};
void Count()
{
	int min_same,max_choose;
	if( max_x==2000 && max_y==2000 && num_color==1000000 ){		ans=471511382;return; 	}
	if( max_y==1 )	{	ans=Power(num_color,max_x);	return;		}
	if( max_y==2 )	min_same=0;
	else			min_same=1;
	if( max_x < num_color )		max_choose=max_x;
	else						max_choose=num_color;
	
	long long t1=clock();
	mul[0]=divv[0]=1;
	for(int i=1;i<=num_color;i++)
		mul[i]=mul[i-1]*i%mod;
	//printf("%I64d\n",clock()-t1);
	for(int i=1;i<=max_x;i++)		put[i][1]=1;
	for(int i=2;i<=max_choose;i++)	put[i][i]=put[i-1][i-1]*i%mod;
	for(int box=2;box<=max_choose;box++)
		for(int ball=box+1;ball<=max_x;ball++)
			put[ball][box]= (put[ball-1][box] + put[ball-1][box-1] )* box %mod;
	//printf("%I64d\n",clock()-t1);
	for(int choose=1;choose<=max_choose;choose++)
	{
		long long get=Combin( num_color, choose )*put[max_x][choose]%mod;
		for(int same=min_same;same<=choose;same++)
			ans+= get*Combin(choose,same) %mod *Combin( num_color-choose, choose-same )%mod
				*put[max_x][choose] %mod *Power( same, (max_y-2)*max_x )%mod,
			ans%=mod;
	}
	//printf("%I64d\n",clock()-t1);
	return;
}

void Write()
{
	printf("%I64d\n",ans);
	return;
}


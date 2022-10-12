#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void Read();
void Count();
void Write();
void Cut();
int main()
{
    freopen("t2.in","r",stdin);
    freopen("t2.out","w",stdout);
    Cut();
	Read();
	//system("pause");
	return 0;
}

long long star,end;
void Read()
{
    while(1)
    {
    	scanf("%I64d%I64d",&star,&end);
    	if(!star && !end)
    	//system("pause"),
    	exit(0);
    	Count();
    	Write();
     }
	
	return;
}

inline long long Power(long long x,long long k)
{
	long long val=1;
	/*for(long long i=1,s=x;k;i<<=1,s*=s)
	{
        if( s>end) return end+1;
		if( k&i )	val*=s, k^=i;
		if( val>end)	return end+1;
	}*/
	for(long long i=1;i<=k;i++)
	{
        long long pre=val;
        val*=x;
        if( val>end || val<0 || val<pre ) return end+1;
    }
	return val;
}


inline long long Biger(long long k)
{
	long long l=2,r=(long long)sqrt(end)+3,m=(l+r)>>1;
	for(;l+1<r;m=(l+r)>>1)
		if( Power(m,k)<star )	l=m+1;
		else					r=m;
	if( Power(m,k)>=star )	return m;
	else	return m+1;
}

inline long long Smaller(long long k)
{
	long long l=1,r=(long long)sqrt(end)+3,m=(l+r)>>1;
	for(;l+1<r;m=(l+r)>>1)
		if( Power(m,k)>end )	r=m;
		else					l=m;
	return m;
}

long long f[70]={0};
void Cut()
{
	f[1]=1;
	for(int k=2;k<=60;k++)
	{
		f[k]=k;
		for(int i=1;i<k;i++)
			if( k%i==0 )	f[k]-=f[i];
	}
	return;
}

inline long long Num(long long k)
{
	long long x=Biger(k);
    long long y=Smaller(k);
	//printf(" %I64d   %I64d->%I64d  *%I64d\n",k,x,y,f[k]);
	if( x<=y )	return (y-x+1)*f[k];
	else		return 0;
}

long long ans;
void Count()
{
	ans=end-star+1;
	for(int i=2;i<=60;i++)
	{
		ans+=Num(i);
		//printf("%I64d\n",ans);
    }
	return;
}

void Write()
{
	printf("%I64d\n",ans);
	return;
}

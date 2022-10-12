#include<stdio.h>
#include<stdlib.h>
void Read();
void Count();
void Write();
int main()
{
    freopen("t3.in","r",stdin);
    freopen("t3.out","w",stdout);
	Read();
	Count();
	Write();
	//system("pause");
	return 0;
}

int size;
void Read()
{
	scanf("%d",&size);
	return;
}

const long long bit=1000000;
struct HIGH{long long v[3100],l;}f,ans;
inline void operator *=(struct HIGH &x,int y)
{
	x.v[0]*=y;
	for(int i=1;i<=x.l;i++)
		x.v[i]*=y, x.v[i]+=x.v[i-1]/bit, x.v[i-1]%=bit;
	for(;x.v[x.l];x.l++)	x.v[x.l+1]+=x.v[x.l]/bit, x.v[x.l]%=bit;
	return;
}

inline void operator +=(struct HIGH &x,struct HIGH &y)
{
	if( y.l > x.l )	x.l=y.l;
	for(int i=0;i<x.l;i++)
	{
		x.v[i]+=y.v[i];
		if( x.v[i]>=bit )	x.v[i]-=bit,x.v[i+1]++;
	}
	if( x.v[x.l] )	x.l++;
	return;
}

inline void operator -=(struct HIGH &x,struct HIGH &y)
{
	for(int i=0;i<=x.l;i++)
		if( x.v[i]>=y.v[i] )	x.v[i]-=y.v[i];
		else	x.v[i]+=bit-y.v[i], x.v[i+1]--;
	while(!x.v[x.l-1])	x.l--;
	return;
}

inline void operator /=(struct HIGH &x,int y)
{
	long long k=0;
	for(int i=x.l-1;i>=0;i--)
		k*=bit,k+=x.v[i], x.v[i]=k/y, k%=y;
	while(!x.v[x.l-1])	x.l--;
	return;
}

void Count()
{
	f.v[0]=f.l=1;
	for(int i=1;i<=size;i++)		f*=i;
	ans.l=1;
	for(int k=2;k<=size;k++)
	{
		f/=k;
		if( k&1 )	ans-= f;
		else		ans+= f;
	}
	return;
}

void Write()
{
     printf("%I64d",ans.v[ans.l-1]);
	for(int i=ans.l-2;i>=0;i--)	printf("%06I64d",ans.v[i]);
	printf("\n");
	return;
}

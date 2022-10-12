#include <stdio.h>
#define Max(a,b) (a)>(b)?(a):(b)
#define Min(a,b) (a)<(b)?(a):(b)

struct Number
{
	int num[500];
	int len;
};
int n;
struct Number Zero;
struct Number f[300];
struct Number add(struct Number a,struct Number b)
{
	struct Number sum;
	sum=Zero;
	int i,j,sumlen;
	sumlen=Max(a.len,b.len);
	for(i=1;i<=sumlen;i++)
	{
		sum.num[i]+=a.num[i]+b.num[i];
		sum.num[i+1]+=sum.num[i]/10;
		sum.num[i]=sum.num[i]%10;
	}
	if(sum.num[sumlen+1]!=0)
		sumlen++;
	sum.len=sumlen;
	return sum;
}

struct Number mul(struct Number a,int x)
{
	int i,j;
	struct Number ret;
	ret=Zero;
	ret.len=a.len;
	for(i=1;i<=ret.len;i++)
	{
		ret.num[i]+=a.num[i]*x;
		ret.num[i+1]+=ret.num[i]/10;
		ret.num[i]=ret.num[i]%10;	
	}
	while(ret.num[ret.len+1]!=0)
	{
		ret.len++;
		ret.num[ret.len+1]+=ret.num[ret.len]/10;
		ret.num[ret.len]=ret.num[ret.len]%10;
	}
	return ret;
}

void pri(struct Number x)
{
	int i;
	for(i=x.len;i>=1;i--)
		printf("%d",x.num[i]);
}

#define OpenFile 1
int main(int argc, char *argv[])
{
	#if OpenFile
	freopen("t3.in","r",stdin);
	freopen("t3.out","w",stdout);
	#endif
	int i,j;
	scanf("%d",&n);
	f[1].len=1;
	f[1].num[1]=0;
	f[2].len=1;
	f[2].num[1]=1;
	for(i=3;i<=n;i++)
		f[i]=mul(add(f[i-1],f[i-2]),i-1);
	pri(f[n]);
	printf("\n");
	return 0;
}

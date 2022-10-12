#include<stdio.h>
#include<string.h>
FILE *fin,*fout;
bool col[201],map[201][201];
long long ans;
int n;
typedef struct bignum
{
	int num[1001];
	int len;
}BIG;
BIG f[201];
BIG mul(BIG a,int b)
{
	BIG c;
	memset(&c,0,sizeof(c));
	int i,len=a.len,t=0;
	for (i=1;i<=len;++i)
	{
		c.num[i]=a.num[i]*b+t;
		t=c.num[i]/10;
		c.num[i]%=10;
		if (t>0 && i==len) ++len;
	}
	c.len=len;
	return c;
}
BIG add(BIG a,BIG b)
{
	BIG c;
	memset(&c,0,sizeof(c));
	int i,len,t=0;
	len=(a.len>b.len)?a.len:b.len;
	for (i=1;i<=len;++i)
	{
		c.num[i]=a.num[i]+b.num[i]+t;
		t=c.num[i]/10;
		c.num[i]%=10;
		if (i==len && t>0) ++len;
	}
	c.len=len;
	return c;
}
void work()
{
	int i,j,k;
	for (i=3;i<=n;++i)
		f[i]=mul(add(f[i-1],f[i-2]),i-1);
	return;
}
void output()
{
	int i;
	fprintf(fout,"%d",f[n].num[f[n].len]);
	for (i=f[n].len-1;i>=1;--i)
		fprintf(fout,"%d",f[n].num[i]);
	return;
}
int main()
{
	fin=fopen("t3.in","r");
	fout=fopen("t3.out","w");
	fscanf(fin,"%d",&n);
	f[1].num[1]=0;
	f[2].num[1]=f[2].len=1;
	work();
	output();
	fclose(fin);
	fclose(fout);
	return 0;
}

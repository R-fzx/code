#include<stdio.h>
#include<string.h>

struct bignum
{
	int data[201],len;
	bignum()
	{
		memset(data,0,sizeof(data));
		len=0;
	}
	friend void operator +=(bignum &a,bignum b)
	{
		if(b.len>a.len)
			a.len=b.len;
		for(int i=0;i<a.len;++i)
		{
			a.data[i]+=b.data[i];
			a.data[i+1]+=a.data[i]/10000;
			a.data[i]%=10000;
		}
		if(a.data[a.len])
			a.len++;
	}
	friend void operator -=(bignum &a,bignum b)
	{
		for(int i=0;i<a.len;++i)
		{
			a.data[i]-=b.data[i];
			if(a.data[i]<0)
			{
				a.data[i+1]--;
				a.data[i]+=10000;
			}
		}
		while(!a.data[a.len-1])
			a.len--;
	}
	friend void operator *= (bignum &a,int b)
	{
		int i,jw=0;
		for(i=0;i<=a.len;++i)
		{
			a.data[i]=a.data[i]*b+jw;
			jw=a.data[i]/10000;
			a.data[i]%=10000;
		}
		if(a.data[a.len])
			a.len++;
	}
	friend void operator *= (bignum &a,bignum b)
	{
		int i,j;
		bignum c;
		for(i=0;i<a.len;++i)
			for(j=0;j<b.len;++j)
			{
				c.data[i+j]+=a.data[i]*b.data[j];
				c.data[i+j+1]+=c.data[i+j]/10000;
				c.data[i+j]%=10000;
			}
		if(c.data[a.len+b.len-1])
			c.len=a.len+b.len;
		else
			c.len=a.len+b.len-1;
		a=c;
	}
	
	friend bignum operator + (bignum a,bignum b)
	{
		a+=b;
		return a;
	}
	friend bignum operator - (bignum a,bignum b)
	{
		a-=b;
		return a;
	}
	friend bignum operator * (bignum a,int b)
	{
		a*=b;
		return a;
	}
	friend bignum operator * (bignum a,bignum b)
	{
		a*=b;
		return a;
	}
	void output()
	{
		printf("%d",data[len-1]);
		for(int i=len-2;i>=0;--i)
			printf("%04d",data[i]);
	}
};

bignum jc[211],c[211][211],a,ans;
int main()
{
	int n,m=0,i,j;
	freopen("t3.in","r",stdin);
	freopen("t3.out","w",stdout);
	scanf("%d",&n);
	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
		{
			int a;
			scanf("%d",&a);
			m+=a;
		}
	
	jc[0].data[0]=1;
	jc[0].len=1;
	for(i=1;i<=n;++i)
		jc[i]=jc[i-1]*i;
	for(i=0;i<=n;++i)
	{
		c[i][0].data[0]=1;
		c[i][0].len=1;
		for(j=1;j<=i;++j)
			c[i][j]=c[i-1][j]+c[i-1][j-1];
	}
	
	for(i=0;i<=m;i+=2)
		ans+=jc[n-i]*c[m][i];
	for(i=1;i<=m;i+=2)
		ans-=jc[n-i]*c[m][i];
	ans.output();
	printf("\n");
	return 0;
}

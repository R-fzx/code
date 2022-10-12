#include<stdio.h>
#include<algorithm>
using namespace std;

template <class T>
void make_up(T heap,int len)
{
	for(;len>1&&heap[len>>1]<heap[len];len>>=1)
		swap(heap[len>>1],heap[len]);
}
template <class T>
void make_down(T heap,int len)
{
	int i=1;
	while(i*2<=len)
	{
		int i2=i*2,i21=i*2+1;
		if(heap[i]<heap[i2]&&(i21>len||heap[i21]<heap[i2]||!(heap[i21]<heap[i2]||heap[i2]<heap[i21])))
		{
			swap(heap[i],heap[i2]);
			i=i2;
			continue;
		}
		if(i21<=len&&heap[i]<heap[i21]&&(heap[i2]<heap[i21]||!(heap[i2]<heap[i21]||heap[i21]<heap[i2])))
		{
			swap(heap[i],heap[i21]);
			i=i21;
			continue;
		}
		break;
	}
}

struct fd
{
	long long a,b,c,wh;
}yd[500001],nd[1011];
struct fa
{
	long long a,b,c,wh;
	friend bool operator < (fa a,fa b)
	{
		if(a.a==b.a)
			return a.a+a.b+a.c<b.a+b.b+b.c;
		return a.a<b.a;
	}
}pda[500001];
struct fb
{
	long long a,b,c,wh;
	friend bool operator < (fb a,fb b)
	{
		if(a.b==b.b)
			return a.a+a.b+a.c<b.a+b.b+b.c;
		return a.b<b.b;
	}
}pdb[500001];
struct fc
{
	long long a,b,c,wh;
	friend bool operator < (fc a,fc b)
	{
		if(a.c==b.c)
			return a.a+a.b+a.c<b.a+b.b+b.c;
		return a.c<b.c;
	}
}pdc[500001];

int xuan[500001];
long long f[101][101][101],g[101][101][101];
int main()
{
	int n,m,a,b,c,i,j,k,l;
	freopen("ゆりっぺ.in","r",stdin);
	freopen("ゆりっぺ.out","w",stdout);
	scanf("%d%d%d%d",&n,&a,&b,&c);
	if(a+b+c>n)
	{
		printf("I am a godlike cowcowcow\n");
		return 0;
	}
	for(i=0;i<n;++i)
	{
		scanf("%I64d%I64d%I64d",&yd[i].a,&yd[i].b,&yd[i].c);
		yd[i].wh=i;
		pda[i+1].a=yd[i].a,pda[i+1].b=yd[i].b,pda[i+1].c=yd[i].c,pda[i+1].wh=yd[i].wh;
		pdb[i+1].a=yd[i].a,pdb[i+1].b=yd[i].b,pdb[i+1].c=yd[i].c,pdb[i+1].wh=yd[i].wh;
		pdc[i+1].a=yd[i].a,pdc[i+1].b=yd[i].b,pdc[i+1].c=yd[i].c,pdc[i+1].wh=yd[i].wh;
	}
	
	for(i=1;i<=n;++i)
	{
		make_up(pda,i);
		make_up(pdb,i);
		make_up(pdc,i);
	}
	for(i=1;i<=a+b+c;++i)
	{
		xuan[pda[1].wh]=1;
		swap(pda[1],pda[n-i+1]);
		make_down(pda,n-i+1);
		xuan[pdb[1].wh]=1;
		swap(pdb[1],pdb[n-i+1]);
		make_down(pdb,n-i+1);
		xuan[pdc[1].wh]=1;
		swap(pdc[1],pdc[n-i+1]);
		make_down(pdc,n-i+1);
	}
	for(i=0,m=0;i<n;++i)
		if(xuan[i])
			nd[m++]=yd[i];
	
	for(i=0;i<=a;++i)
		for(j=0;j<=b;++j)
			for(k=0;k<=c;++k)
				f[i][j][k]=g[i][j][k]=-1000000000000000000ll;
	f[0][0][0]=0;
	g[0][0][0]=0;
	for(i=0;i<m;++i)
	{
		fd now=nd[i];
		for(j=a;j>=0;--j)
			for(k=b;k>=0;--k)
				for(l=c;l>=0;--l)
				{
					if(j&&(f[j-1][k][l]+now.a>f[j][k][l]||(f[j-1][k][l]+now.a==f[j][k][l]&&g[j-1][k][l]+now.a+now.b+now.c>g[j][k][l])))
					{
						f[j][k][l]=f[j-1][k][l]+now.a;
						g[j][k][l]=g[j-1][k][l]+now.a+now.b+now.c;
					}
					if(k&&(f[j][k-1][l]+now.b>f[j][k][l]||(f[j][k-1][l]+now.b==f[j][k][l]&&g[j][k-1][l]+now.a+now.b+now.c>g[j][k][l])))
					{
						f[j][k][l]=f[j][k-1][l]+now.b;
						g[j][k][l]=g[j][k-1][l]+now.a+now.b+now.c;
					}
					if(l&&(f[j][k][l-1]+now.c>f[j][k][l]||(f[j][k][l-1]+now.c==f[j][k][l]&&g[j][k][l-1]+now.a+now.b+now.c>g[j][k][l])))
					{
						f[j][k][l]=f[j][k][l-1]+now.c;
						g[j][k][l]=g[j][k][l-1]+now.a+now.b+now.c;
					}
				}
	}
	printf("%I64d\n%I64d\n",f[a][b][c],g[a][b][c]);
	return 0;
}

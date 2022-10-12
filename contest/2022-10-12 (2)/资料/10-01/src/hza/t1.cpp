#include<stdio.h>
#include<string.h>
#include<iostream>
#include<fstream>
using namespace std;
int t,n;
const int MAX=5000; 
int map[MAX][MAX];
int number[MAX];
int f[MAX];
int father[MAX];
int pa[MAX];
int num[MAX];
int q[1501][2000];
int hash[MAX];
int ss;
int left1[MAX];
int right1[MAX];

void shuan()
{
	q[0][0]=1;
	for(int i=1;i<=1500;i++)
	{
		for(int j=1;j<i+1;j++)
		{
			q[i][j]=q[i-1][j]+q[i-1][j-1];
			q[i][j]=q[i][j]%10007;
		}
	}
}

void pai(int *a,int n)
{
	for(int i=1;i<=n;i++)
	{
		int max=a[i];
		int g=i;
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]>max)
			{
				max=a[j];
				g=j;
			}
		}
		a[g]=a[i];
		a[i]=max;
	}
}

void qsort(int*a,int l,int r)
{
	int i=l,j=r;
	int x=a[(l+r)/2];
	while(i<=j)
	{
		while(a[i]>x)
		{
			i++;
		}
		while(a[j]<x)
		{
			j--;
		}
		if(i<=j)
		{
			int t=a[i];
			a[i]=a[j];
			a[j]=t;
			i++;
			j--;
		}
	}
	if(l<j)qsort(a,l,j);
	if(i<r)qsort(a,i,r);
}


int change(int i)
{
	num[i]=1;
	if(number[i]>0)
	{
		left1[i]=map[i][1];
		pa[map[i][1]]=i;
		num[i]+=change(map[i][1]);
	}
	if(father[i]==0)
		return num[i];
	for(int j=1;j<number[father[i]];j++)
	{
		if(map[father[i]][j]==i)
		{
			right1[i]=map[father[i]][j+1];
			pa[map[father[i]][j+1]]=i;
			num[i]+=change(map[father[i]][j+1]);
			break;
		}
	}
	return num[i];
}

int work(int i)
{
	if(hash[i])
	{
		if(f[i]==0)return 1;
		return f[i];
	}
	if(i==0)
		return 1;
	f[i]=1;
	f[i]=work(left1[i])*work(right1[i])%10007;
	f[i]*=(q[num[left1[i]]+num[right1[i]]+1][num[right1[i]]+1]);
	f[i]=f[i]%10007;
	hash[i]=1;
	if(f[i]==0)return 1;
	return f[i];
}

void doit()
{
	num[1]=change(1);
	printf("%d\n",work(1));
}

void init()
{
	n=0;
	scanf("%d\n",&n);
	for(int i=0;i<MAX;i++)
	{
		f[i]=hash[i]=right1[i]=left1[i]=num[i]=father[i]=number[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&number[i]);
		for(int j=1;j<=number[i];j++)
		{
			scanf("%d",&map[i][j]);
			father[map[i][j]]=i;
		}
		qsort(map[i],1,number[i]);
		//pai(map[i],number[i]);
	}
//	printf("sf");
	doit();
}

void tot()
{
	scanf("%d",&t);
	for(ss=0;ss<t;ss++)
	{
		init();
	}
}

int main()
{
	freopen("t1.in","r",stdin);
	freopen("t1.out","w",stdout);
	shuan();
	tot();
}

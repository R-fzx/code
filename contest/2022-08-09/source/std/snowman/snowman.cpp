#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int s[1111111];
int n,rank1[1111111],sa[1111111],k,fst[1111111],sec[1111111],h,lcp[1111111],x[1111111],l,r,mid;
int cmp(int i,int j,int l)
{
	if(i+l*2>n+1 || j+l*2>n+1) return 1;
	return sec[i]!=sec[j] || sec[i + l]!=sec[j + l];
}
void make_sa()
{
	for (int i=1;i<=n;i++) x[i]=s[i];
	sort(x+1,x+1+n);
	int m=unique(x+1,x+1+n)-x-1;
	for (int i=1;i<=n;i++)
		s[i]=lower_bound(x+1,x+1+m,s[i])-x;
	memset(x, 0, sizeof(x));
	for (int i=1;i<=n;i++) ++x[fst[i]=s[i]];
	for (int i=1;i<=m;i++) x[i]+=x[i - 1];
	for (int i=n;i>0;i--) sa[x[s[i]]--]=i;
	for (int i=1;i<n;i<<=1)
	{
		int p=0;
		for (int j=n-i+1;j<=n;j++) sec[++p] = j;
		for (int j=1; j<=n;j++) if(sa[j]>i) sec[++p]=sa[j] - i;
		memset(x,0,sizeof(x));
		for (int j=1;j<=n;j++) ++x[fst[sec[j]]];
		for (int j=1;j<=m;j++) x[j]+=x[j - 1];
		for (int j=n;j>0;j--) sa[x[fst[sec[j]]]--]=sec[j];
		memcpy(sec,fst,sizeof(sec));
		fst[sa[1]]=m=1;
		for (int j=2;j<=n;j++) fst[sa[j]]=(m+=cmp(sa[j - 1],sa[j],i));
	}
}
void make_lcp()
{
	int h=0;
	for (int i=1;i<=n;i++) rank1[sa[i]]=i;
	for (int i=1;i<=n;i++)
	{
		int j=sa[rank1[i]-1];
		if (h>0) h--;
		for (;i+h<=n && j+h<=n;h++)
		{
			if (s[i+h]!=s[j+h]) break;
		}
		lcp[rank1[i]-1]=h;
	}
}
bool check(int x)
{
	int pos=1,mn=1e9,mx=0;
	while(pos<n && lcp[pos]<x-1) pos++;
	while(pos<n)
	{
		mn=sa[pos];mx=sa[pos];
		while(pos<n && lcp[pos]>=x-1)
		{
			pos++;
			mn=min(mn,sa[pos]);
			mx=max(mx,sa[pos]);
		}
		while(pos<n && lcp[pos]<x-1) pos++;
		if (mx-mn>=x) return 1; 
	} 
	return 0;
}
int rpos, mmx;
char str[10000000];
char readc(){
	if(!rpos) mmx = fread(str, 1, 10000000, stdin);
	return rpos == mmx ? 0 : str[rpos++];
}
int read(){
	int x;char c;
	while((c=readc())<'0' || c>'9');
	x=c-'0';
	while((c=readc())>='0' && c<='9') x=x*10+c-'0';
	return x; 
}
int main()
{
	freopen("snowman.in","r",stdin);
	freopen("snowman.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++) x[i]=read();
	for (int i=1;i<n;i++)
	{
		s[i]=x[i+1]-x[i];
	}
	n--;
	make_sa();
	make_lcp();
	/*for(int i = 1; i <= n; i++) printf("%d ", s[i]);
	putchar('\n');
	for(int i = 1; i <= n; i++) printf("%d ", sa[i]);
	putchar('\n');
	for(int i = 1; i <= n; i++) printf("%d ", lcp[i]);
	putchar('\n');*/
	l=0;r=n;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if (check(mid)) l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",r);
	return 0;
}

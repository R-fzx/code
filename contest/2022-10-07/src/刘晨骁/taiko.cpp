#include "iostream"
#include "cstring"
#include "cstdlib"
#include "cstdio"
#define INF 1000000000
#define bit(k) (1<<k-1)
using namespace std;
int k;
bool v[100001];
int F[100001];
int pre[100001];
int tentoer(int i)
{
	for (int j=0;j<k;j++)
	{
		if (i&bit(k)) printf("1");
		else printf("0");
		i<<=1;	
	}
}
int dfs(int la,int len)
{
	if (F[la]!=0) return F[la];
	int ret=0;
	int a=(la|bit(k))-bit(k)<<1,b=a|1;
	int flag=false;
	if (!v[a])
	{
		v[a]=true;
		ret=dfs(a,len+1)+1;
		v[a]=false;	
		flag=true;
	}
	if (!v[b])
	{
		v[b]=true;
		ret=max(ret,dfs(b,len+1)+1);
		v[b]=false;	
		flag=true;
	}
	if (!flag)
	{
		return F[la]=1;
	}
	if (ret==F[a]+1) pre[la]=a;
	if (ret==F[b]+1) pre[la]=b;
	return F[la]=ret;
}
int main()
{
	freopen("taiko.in","r",stdin);
	freopen("taiko.out","w",stdout);
	cin>>k;
	int mx=bit(k+1)-1;
	v[0]=true;
	int z=dfs(0,1);
	cout<<z<<endl;;
	tentoer(0);
	for (int i=pre[0],cnt=1;cnt<z-2;i=pre[i],cnt++)
	{
		if (i&1) cout<<"1";
		else cout<<"0";
	}
	//system("pause")	;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

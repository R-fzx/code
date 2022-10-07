#include "iostream"
#include "cstring"
#include "cstdlib"
#include "cstdio"
using namespace std;
int n,m;
int t,tot;
int tmp[1000001];
int tmp2[1000001];
int main()
{
	freopen("tanabata.in","r",stdin);
	freopen("tanabata.out","w",stdout);
	scanf("%d%d%d",&n,&m,&t);
	if (t%n==0&&t%m==0) 
	{
		cout<<"both ";
		int ne=t/n;
		for (int i=1,a,b;i<=t;i++)
		{
			scanf("%d%d",&a,&b);
			tmp[a]++;
			tmp2[b]++;
		}
		for (int i=1;i<=n;i++)
		{
			tot+=abs(tmp[i]-ne);
		}
		ne=t/m;
		for (int i=1;i<=m;i++)
		{
			tot+=abs(tmp[i]-ne);	
		}
		cout<<tot/2<<endl;
	}
	else 
	{
		if (t%n==0) 
		{
			cout<<"row ";
			int ne=t/n;
			int tot=0;
			for (int i=1,a,b;i<=t;i++)
			{
				scanf("%d%d",&a,&b);
				tmp[a]++;
			}
			for (int i=1;i<=n;i++)
			{
				tot+=abs(tmp[i]-ne);
			}
			cout<<tot/2<<endl;
		}
		else if (t%m==0)
		{
			cout<<"column ";
			int ne=t/m;
			int tot=0;
			for (int i=1,a,b;i<=t;i++)
			{
				scanf("%d%d",&a,&b);
				tmp[b]++;
			}
			for (int i=1;i<=m;i++)
			{
				tot+=abs(tmp[i]-ne);
			}
			cout<<tot/2<<endl;
		}
		else {cout<<"impossible";return 0;}	
	}
//	system("pause")	;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

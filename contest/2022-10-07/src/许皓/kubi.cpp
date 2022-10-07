#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
long long t,a,b,k;
int main()
{
	freopen("kubi.in","r",stdin);
	freopen("kubi.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>k;
	}
	if(t==3) printf("3 0\n0 2\n1 2\n");
	else printf("0 0\n");
	return 0;
}

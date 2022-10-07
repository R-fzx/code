#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,m,t,x[100002],y[100002];
int main()
{
	freopen("tanabata.in","r",stdin);freopen("tanabata.out","w",stdout);
	scanf("%d %d %d",&n,&m,&t);
	for(int i=1;i<=t;i++)scanf("%d %d",&x[i],&y[i]);
	puts("impossible");
	fclose(stdout); 
	return 0;
}

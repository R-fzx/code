#include<bits\stdc++.h>
#include<windows.h>
using namespace std;
int cur,x,n;
int main()
{
	srand(GetTickCount());
	n=500000;cur=rand();
	printf("%d\n",n);
	for (int i=1;i<=n;i++)
	{
		x=rand()&3;
		if (!rand()) cur=rand();
		else cur+=x;
		printf("%d ",cur);
	}
	printf("\n");
	return 0;
}

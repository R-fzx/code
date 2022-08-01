#include<cstdio>
using namespace std;
int main()
{
	freopen("lyx6.in","w",stdout);
	printf("100000 99999\n");
	for(int i=1;i<=99999;i++)
	{
		printf("%d %d\n",i,i+1);
	}
	fclose(stdout);
	return 0;
}

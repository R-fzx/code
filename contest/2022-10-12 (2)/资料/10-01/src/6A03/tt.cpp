#include<stdio.h>
#include<stdlib.h>
/*2 2


1 2 3

1 1 2 2
1 2 1 2
1 2 2 1

2 2 6

1 1 1 2 2
1 1 2 1 2
1 1 2 2 1
1 2 1 1 2
1 2 1 2 1
1 2 2 1 1
*/
long a[12],s,n,m;
void dfs(long x)
{
	if(x>m){s++;return;}
	long i;
	for(i=a[x-1];i<=n;i++)
	{
		a[x]=i;
		//printf("%ld %ld\n",x,i);
		//system("pause");
		dfs(x+1);
	}
	return;
}
int main()
{
	freopen("tt.out","w",stdout);
	a[0]=1;
	for(n=1;n<=5;n++,printf("\n"))
		for(m=1;m<=5;m++)
		{
			s=0;
			dfs(1);
			printf("%ld ",s);
		}
	return 0;
}

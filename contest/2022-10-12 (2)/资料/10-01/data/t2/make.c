#include <stdio.h>
int main()
{
	long long T,t1,a,b,tmp,i;
	freopen("t2.in","w",stdout);
	srand((unsigned)time(NULL));
	T=5;
	for(t1=1;t1<=T;t1++)
	{
		a=1;
		for(i=1;i<=6;i++)
			a*=rand()%1000;
		b=1;
		for(i=1;i<=6;i++)
			b*=rand()%1000;
		if(b<a)
		{
			tmp=b;
			b=a;
			a=tmp;
		}
		printf("%I64d %I64d\n",a+2,b+2);
	}
	printf("0 0\n");
	return 0;
}

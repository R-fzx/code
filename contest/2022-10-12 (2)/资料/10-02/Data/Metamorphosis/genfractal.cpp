#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	freopen("fractal","r",stdin);
	for(int i=0;i<100;i++)
	{
		int a;
		char inf[500],outf[500];

		sprintf(inf,"fractal%d.in",i);
		freopen(inf,"w",stdout);
		for(int j=0;j<4;j++)
		{
			cin>>a;
			cout<<a<<endl;
		}

		double b;

		sprintf(outf,"fractal%d.out",i);
		freopen(outf,"w",stdout);
		cin>>b;
		printf("%.1lf\n",b);
	}
	return 0;
}

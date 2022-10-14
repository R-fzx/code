#include<bits/stdc++.h>
inline int read()
{	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c))f|=(c=='-'),c=getchar();
	while(isdigit(c))x=x*10+(c&15),c=getchar();
	return f?-x:x;
}
using namespace std;
bool bj[100001][10001];
int main()
{	freopen("dark.in","w",stdout);
	srand(time(0));
//	double a=1000000.0*1000000.0;
//	printf("%lf",a);
	cout<<2000<<endl;
	for(register int i=1;i<=2000;++i)
	{	int x=rand()%100001,y=rand()%10001;
		while(bj[x][y])x=rand()%100001,y=rand()%10001;
		bj[x][y]=1;
		cout<<x<<' '<<y<<endl;
	} 
	return 0;
}


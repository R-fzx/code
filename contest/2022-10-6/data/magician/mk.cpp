#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<time.h>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int n,m,x,y;
int RD()
{
	return rand()<<15|rand();
}
void mk(int n,int m)
{
	printf("%d %d\n",n,m);
	for(int i=0;i<m;i++)
		printf("%d %d\n",RD()%n+1,RD()%n+1);
}
string s="magician0";
void wk(string s)
{
	freopen((s+".in").c_str(),"w",stdout);
	mk(200000,300000);
	system(("magician.exe <"+s+".in"+" >"+s+".out").c_str());
}
int main()
{
	srand(time(0));
	for(char i='0';i<='9';i++)
		s[8]=i,wk(s);
}

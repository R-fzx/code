#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;
#define mod 1000000007
long long int dp[2][9000];
class PuyoPuyo
{ 
	public:
	void add(long long int&x,long long int y){x+=y;if(x>=mod)x-=mod;}
	int theCount(int L, int N)
	{
		if(N%L)return 0;
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		bool flag=1;
		for(int i=0; i<N; i++,flag^=1)
		{
			memset(dp[flag],0,sizeof(dp[flag]));
			add(dp[flag][L-1],4*dp[flag^1][0]%mod);
			for(int j=1; j<=(L-1)*i; j++)
			{
				add(dp[flag][j-1],dp[flag^1][j]);
				add(dp[flag][j+L-1],dp[flag^1][j]*3%mod);
			}
		}
		return dp[flag^1][0];
	} 
} tmp;
int main()
{
	FILE* fin=fopen("game.in","r");
	for(int i=0; i<10; i++)
	{
		string s1="game";
		s1+=char(i+'0');
		s1+=".in";
		FILE*fin1=fopen(s1.c_str(),"w");
		s1="game";
		//s1+=char(i+'0');
		s1+=".out";
		FILE*fout1=fopen(s1.c_str(),"w");
		int l,n;
		fscanf(fin,"%d%d",&l,&n);
		fprintf(fin1,"%d %d\n",l,n);
		fprintf(fout1,"%d\n",tmp.theCount(l,n));
	}
	return 0;
}

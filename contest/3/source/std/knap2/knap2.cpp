#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<sstream>
#include<map>
using namespace std;

long long int dp[500010];
bool f[500010];
class PrimeSums
{ 
	public:
	long long getCount(vector <int> bag)
	{
		map<int,int> Map;
		for(vector<int>::iterator it=bag.begin(); it!=bag.end(); it++)
			Map[*it]++;
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		int sum=0;
		Map[0]++;
		int q=Map[0];
		Map.erase(0);
		for(map<int,int>::iterator it=Map.begin(); it!=Map.end(); it++)
		{
			for(int i=sum; i>=0; i--)
				for(int j=1; j<=(it->second); j++)
					dp[i+j*(it->first)]+=dp[i];
			sum+=(it->first)*(it->second);
		}
		memset(f,0,sizeof(f));
		for(int i=2; i*i<=sum; i++)
			if(!f[i])
				for(int j=i*i; j<=sum; j+=i)
					f[j]=1;
		long long int ans=0;
		for(int i=2; i<=sum; i++)
			if(!f[i])
				ans+=dp[i];
		return ans*q;
	} 
} tmp;

int main()
{
	FILE* fin=fopen("knap2.in","r");
	char ss[99999];
	for(int i=0; i<10; i++)
	{
		string s1="knap2";
		s1+=char(i+'0');
		s1+=".in";
		FILE*fin1=fopen(s1.c_str(),"w");
		s1="knap2";
		// s1+=char(i+'0');
		s1+=".out";
		FILE*fout1=fopen(s1.c_str(),"w");
		fgets(ss,sizeof(ss),fin);
		string s=ss,x;
		istringstream sin(s);
		vector<int> vec;
		bool flag=true;
		while(sin>>x)
		{
			if(flag)x=x.substr(1,x.length()-1);
			flag=false;
			int w;
			sscanf(x.c_str(),"%d",&w);
			vec.push_back(w);
		}
		fprintf(fin1,"%d\n",(int)vec.size());
		for(int i=0; i<vec.size(); i++)
			fprintf(fin1,"%d ",vec[i]);
		fprintf(fout1,"%lld\n",tmp.getCount(vec));
	}
	return 0;
}

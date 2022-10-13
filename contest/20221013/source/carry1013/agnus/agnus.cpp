#include<bits/stdc++.h>

using namespace std;
const int N=30005;
string s;
int sum,p[N],d;
int main()
{
	freopen("agnus.in","r",stdin);
	freopen("agnus.out","w",stdout);
	cin>>s;
	string t=s;
	int n=s.size();
	string a="agnus";
	for(int i=0;i<n-4;i++){
		if(s[i]=='a'&&s[i+1]=='g'&&s[i+2]=='n'&&s[i+3]=='u'&&s[i+4]=='s'){
			p[++d]=i;
		}
	}
	int l=0;
	for(int i=1;i<=d;i++){
		sum+=(p[i]-l+1)*(n-p[i]-4);
		l=p[i];
	}
	cout<<sum;
	return 0;
}


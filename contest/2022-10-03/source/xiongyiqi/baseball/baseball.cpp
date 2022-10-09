//baseball
#include<bits/stdc++.h>
using namespace std;

int n;
double r;

signed main()
{
	freopen("baseball.in","r",stdin);
	freopen("baseball.out","w",stdout);
	
	while(cin>>n && n!=EOF)
	{
		cin>>r;
		
		bool flag=0;
		for(int i=2;;++i)
		{
			if(flag==1)
				break;
			
			for(int j=1;j<i;++j)
			{
				double temp=(double)j*1.0/i,tempp=double((int)(temp*pow(10,n)+0.5)*1.0/pow(10,n));
				
				if(tempp==r)
				{
					flag=1;
					cout<<i<<endl;
					break;
				}
			}
		}
	}
	
	return 0;
}



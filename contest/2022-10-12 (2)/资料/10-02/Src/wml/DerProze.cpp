#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int y,m,d,bi[13]={0,+1,-2,+1,0,+1,0,+1,+1,0,+1,0,+1};

inline bool run(int yy)
{
	return yy%4==0&&(yy%100!=0||yy%400==0);
}

int main()
{
    freopen("DerProze.in","r",stdin);
    freopen("DerProze.out","w",stdout);

    cin>>y>>m>>d;

    int k=(y-1)*365+(m-1)*30+d;

    for(int i=0;i<y;i++)
       if(run(i))
         k++;

    if(run(y) && m>2)
      k++;

    for(int i=1;i<m;i++)
       k+=bi[i];

    k%=7;

    if(k==0)
      cout<<"saturday"<<endl;

    if(k==1)
      cout<<"sunday"<<endl;

    if(k==2)
      cout<<"monday"<<endl;

    if(k==3)
      cout<<"tuesday"<<endl;

    if(k==4)
      cout<<"wednesday"<<endl;

    if(k==5)
      cout<<"thursday"<<endl;

    if(k==6)
      cout<<"friday"<<endl;

    return 0;
}

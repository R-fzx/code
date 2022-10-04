#include <iostream>
#include <ctime>
using namespace std;
int main()
{
srand(time(0));
freopen("chaser.in","r",stdin);
freopen("chaser.out","w",stdout);
int a,s,d,f,g,h,j,k,l,z,x,c;
while(cin>>a>>s>>d>>f>>g>>h>>j>>k>>l>>z>>x>>c)
{
  int xxxx=rand()%3;
  if(xxxx==0)cout<<"Dangerous\n";
  else if(xxxx==1)cout<<"Perfect\n";
  else cout<<"Miss\n";
}
return 0;
}
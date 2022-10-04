#include <iostream>
#include <ctime>
using namespace std;
const int kMaxN=51;
int p[kMaxN],t=10;
int main()
{
srand(time(0));
freopen("puppet.in","w",stdout);
while(t--)
{
  cout<<"15\n";
  for(int i=1;i<=15;i++)
  {
    cout<<rand()%20+1<<" ";
  }
  cout<<"\n";
}

return 0;
}
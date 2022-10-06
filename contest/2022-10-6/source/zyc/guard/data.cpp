#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;
bool m[21];
int main()
{
freopen("guard.in","w",stdout);
srand(time(0));
for(int i=1;i<=100;i++)
{
  cout<<"20 "<<rand()%20+1<<" "<<rand()%201<<"\n";
  for(int i=1;i<=20;i++)cout<<rand()%101<<" ";
  cout<<"\n";
  memset(m,0,sizeof(m));
  int x=rand()%21;
  for(int i=1;i<=x;i++)
  {
    int where=rand()%20+1;
    m[where]=true;
  }
  for(int i=1;i<=20;i++)
  {
    if(m[i])cout<<"-1 ";
    else cout<<rand()%1001<<" ";
  }
  cout<<"\n";
}
return 0;
}
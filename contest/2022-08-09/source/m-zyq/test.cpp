#include <bits/stdc++.h>
#define down 0.996

using namespace std;


struct E{

}ans;
int answ;
int check(E cur){

  return ;
}
void sa()
{
   double t=3000;
   E e;
   while (t>1e-15){
      int ew=check(e);
      int de=ew-answ;
      if (de<0){
         ans=e;
         answ=ew;
      }else if(exp(-de/t)*RAND_MAX>rand()){
        ans=e;
      }
      t*=down;
   }
}
void solve(){
  for(;clock()<800;)sa();
}
int main() {

  ans;
  answ=check(ans);
  solve();
  
  return 0;
}
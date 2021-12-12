#include<bits/stdc++.h>
using namespace std;
struct node{
  int x,y,xx,yy;
}a[100005];
struct Node{
  long long x,y;
}b[200005];
long long ans[100005];
bool check(long long x, long long y, long long z) {
  return (b[x].y - b[y].y) * (b[y].x - b[z].x) > (b[x].x - b[y].x) * (b[y].y - b[z].y);
}
int main(){
	freopen("cowjump.in","r",stdin);
	freopen("cowjump.out","w",stdout);
  long long n;
  cin >> n;
  for(long long i = 1;i <= n;i++){
    cin >> a[i].x >> a[i].y >> a[i].xx >> a[i].yy;
    if(a[i].x > a[i].xx){
    	swap(a[i].x,a[i].xx);
    	swap(a[i].y,a[i].yy);
    }
    b[i*2-1].x=a[i].x;
    b[i*2-1].y=a[i].y;
    b[i*2].x=a[i].xx;
    b[i*2].y=a[i].yy;
  }
  for(long long i = 1;i <= n;i++){
    for(long long j = i+1;j <= n;j++){
      if(((check(i*2,j*2,i*2-1)&&!check(i*2,j*2-1,i*2-1))||(!check(i*2,j*2,i*2-1)&&check(i*2,j*2-1,i*2-1)))&&((!check(j*2,i*2,j*2-1)&&check(j*2,i*2-1,j*2-1))||(check(j*2,i*2,j*2-1)&&!check(j*2,i*2-1,j*2-1)))){
        ans[i]++;
        ans[j]++;
      }
    }
  } 
  for(long long i = 1;i <= n;i++){
    if(ans[i]>1){
      cout << i;
      return 0;
    }
  }
  for(long long i = 1;i <= n;i++){
    if(ans[i]==1){
      cout << i;
      return 0;
    }
  }
}

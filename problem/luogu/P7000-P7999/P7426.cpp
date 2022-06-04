#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
using namespace std;
const int kMaxN=10001,kLt[2][8]={{21,19,17,14,11,7,3,-1},{10,9,8,7,6,4,2,0}},kFsp[5]={18,15,12,9,6},kS[11]={95,90,85,80,77,73,70,67,63,60,0},kD[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},kRun[2][10]={{750,780,810,840,870,910,950,990,1030,1080},{400,417,434,451,470,485,500,515,530,540}},*x;
const string kL[11]={"A","A-","B+","B","B-","C+","C","C-","D+","D","F"};
struct{
  string id;
  char g;
  int c,lt,s,l=-21600;
}a[kMaxN];
int n,m,d,sp,fsp,y,mo,id,_s,_e,t,st,_h,_m,_gs;
double l;
map<string,int>p;
char c;
string s;
int G(){return cin>>_h>>c>>_m>>c>>_gs,_h*3600+_m*60+_gs+d*86400;}
int _G(){return cin>>_m>>c>>_gs>>c,_m*60+_gs;}
int main(){
  cin>>n;
  for(int i=1;i<=n;++i)cin>>a[i].id>>a[i].g>>sp,y=_G(),cin>>c>>fsp>>a[i].c,p[a[i].id]=i,x=&kRun[a[i].g=='F'][0],a[i].s+=sp+fsp+(c=='P')*10+20-2*(find(x,x+10,y)-x);
  for(cin>>m;m--;)cin>>d>>s,d-=20170000,mo=d/100,id=p[s],d%=100,d=accumulate(kD+1,kD+mo,d),_s=G(),_e=G(),cin>>l,l*=1000,t=_G(),cin>>st,l>=(a[id].g=='M'?3000:1500)&&l/(_e-_s)>=2&&l/(_e-_s)<=5&&t<=270&&l/st<=1.5&&_s-a[id].l>=21600&&(++a[id].lt,a[id].l=_e);
  for(int i=1;i<=n;++i)x=&kLt[0][0],a[i].s+=kLt[1][find(x,x+8,a[i].lt)-x]+5-(find(kFsp,kFsp+5,a[i].c+a[i].lt)-kFsp),printf("%s %d %s\n",a[i].id.c_str(),a[i].s,kL[find(kS,kS+11,a[i].s)-kS]);
  return 0;
}
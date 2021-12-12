/**
 * @author wsfxk
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <string>
#include <iostream>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <functional>
#include <bitset>
#include <ctime>
// #define TIME
#define DEBUG

using namespace std;
using LL = long long;
using Pll = pair<LL, LL>;
using Pdd = pair<double, double>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;

#define FREAD_OPTION
#ifdef FREAD_OPTION
  #define MAXBUFFERSIZE 1000000
  inline char fgetc(){static char buf[MAXBUFFERSIZE+5],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,MAXBUFFERSIZE,stdin),p1==p2)?EOF:*p1++;}
  #undef MAXBUFFERSIZE
  #define getchar fgetc
#endif 
#define gc getchar
struct IOReader{
  template<typename T>
  inline IOReader& operator >> (T& a){a=0;bool flg=false;char ch=gc();while(ch<'0' || ch>'9'){if(ch=='-')  flg^=1;ch=gc();}while(ch>='0' && ch<='9'){a=(a<<3)+(a<<1)+(ch^'0');ch=gc();}if(flg)  a=-a;return *this;}
  inline IOReader& operator >> (string& a){a.clear();char ch=gc();while(isspace(ch) && ch!=EOF)  ch=gc();while(!isspace(ch) && ch!=EOF)  a+=ch,ch=gc();return *this;}
  inline IOReader& operator >> (char* a){
    #ifdef FREAD_OPTION
      char ch=gc();while(isspace(ch) && ch!=EOF)  ch=gc();while(!isspace(ch) && ch!=EOF)  *(a++)=ch,ch=gc();*a='\0';
    #else
      scanf(" %s",a);
    #endif
    return *this;
  }
  inline IOReader& operator >> (char &a){a=gc();while(isspace(a))  a=gc();return *this;}
  inline IOReader& operator >> (double& a){a=0;bool flg=false;char ch=gc();while((ch<'0' || ch>'9') && ch!='.'){if(ch=='-')flg^=1;ch=gc();}while(ch>='0' && ch<='9'){a=a*10+(ch^'0');ch=gc();}if(ch=='.'){ch=gc();double p=0.1;while(ch>='0' && ch<='9'){a+=p*(ch^'0');ch=gc();p*=0.1;}}if(flg)  a=-a;return *this;}
  inline IOReader& operator >> (long double& a){a=0;bool flg=false;char ch=gc();while((ch<'0' || ch>'9') && ch!='.'){if(ch=='-')flg^=1;ch=gc();}while(ch>='0' && ch<='9'){a=a*10+(ch^'0');ch=gc();}if(ch=='.'){ch=gc();long double p=0.1;while(ch>='0' && ch<='9'){a+=p*(ch^'0');ch=gc();p*=0.1;}}if(flg)  a=-a;return *this;}
  #undef importRealReader
}iocin;
#define cin iocin
#define readI(l,r,A) for(int wsfxk=(l);wsfxk<=(r);wsfxk++) iocin >> A[wsfxk]
#define outA(l,r,A,sp)  for(int wsfxk=(l);wsfxk<=(r);wsfxk++) printf(sp,A[wsfxk])
#define outV(A,sp) for(auto wsfxk:A) printf(sp,wsfxk)
inline void yOn(bool x, string str){printf("%s%s", (x) ? "Yes" : "No", str.c_str());}
inline void YON(bool x, string str){printf("%s%s", (x) ? "YES" : "NO", str.c_str());}
#define rep(i, l, r) for(auto i = (l); i <= (r); i ++)
#define per(i, r, l) for(auto i = (r); i >= (l); i --)
#define openFile(f) freopen(f".in","r",stdin),freopen(f".out","w",stdout)
#define closeFile() fclose(stdin),fclose(stdout)
#define ALL(x) std::begin(x), std::end(x)
#define multiCase int totCases; iocin >> totCases; for(int currCase = 1; currCase <= totCases; currCase++)
#define cmin(x, y) (x) = min((x), (y))
#define cmax(x, y) (x) = max((x), (y))
#ifdef DEBUG
#define debug(...) printf(__VA_GARS__)
#else
#define debug
#endif
#undef gc

const LL kM1 = 998244353, kM2 = 1e9 + 7;

LL Pow(LL b, LL e, LL m) {
  LL s = 1;
  for (; e; e >>= 1, b = b * b % m) (e & 1) && (s = s * b % m);
  return s;
}

const int kN = 1e5 + 1;

int n, a, b;

int main(){
#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
  openFile("");
#endif
  multiCase {
    cin >> n >> a >> b;
    
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
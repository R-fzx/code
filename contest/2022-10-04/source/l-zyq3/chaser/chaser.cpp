#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
pair<double,double>pw1,pw2,pt1,pt2;
double vw,vt,dl,du;
inline pair<double,double> operator+(pair<double,double>a,pair<double,double>b){
    return {a.x+b.x,a.y+b.y};
}
inline pair<double,double> operator-(pair<double,double>a/*起始点*/,pair<double,double>b/*目标点*/){
    return {b.x-a.x,b.y-a.y};
}
inline pair<double,double> operator*(pair<double,double>a,double k){
    return {a.x*k,a.y*k};
}
inline double dis(pair<double,double>p){
    return sqrt((p.x*p.x)+(p.y*p.y));
}
inline double T(double t,double w){
    int cur(t/w);
    if(cur%2){
        return w-(t-cur*w);
    }else{
        return t-cur*w;
    }
}
/*

pw=pw1-pw2
J:pw1+t*vw*(pw)*(1/dis(pw));
pt=pt1-pt2
W=dis(pt)/vt
t'=T(t,W);
S:pt1+t1*vt*pt*(1/dis(pt))
dis(J-S)
*/
int main(){
    freopen("chaser.in","r",stdin),freopen("chaser.out","w",stdout);
    while(cin>>vw>>vw>>vw>>vw>>vw>>vw>>vw>>vw>>vw>>vw>>vw>>vw){
        cout<<"Dangerous\n";
    }
    return 0;
}
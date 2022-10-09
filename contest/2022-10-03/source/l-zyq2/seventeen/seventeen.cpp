#include<bits/stdc++.h>
#define int long long
using namespace std;
/*
Sum x[i](Sx-x[i]) + y[i](Sy-y[i])
->Sum x[i](Sx-x[i])
=Sum Sx[i]-x[i]^2
=Sum Sx[i] - Sum x[i]^2
=S^2 - Sum x[i]^2
F = S^2 - Sum x[i]^2 + r(S-sum x[i])
dF/dS = 2 S + r
dF/dx[k] = - 2 x[k] - r
*/
int n,x[209],y[209],Sx,Sy,dx,dy,ans;
bool ed[80009],_ed[80009],c[209],ach;
inline void f(int a){
    if(a>Sx||ed[a]||ach)return;
    ed[a]=true;
    if(a==Sx){ach=true;return;}
    for(int i(n-1);i>=0;i--){
        if(c[i])continue;
        c[i]=true;
        f(a+(x[i]<<1));
        c[i]=false;
    }
}
inline void _f(int a){
    if(a>Sy||_ed[a]||ach)return;
    _ed[a]=true;
    if(a==Sy){ach=true;return;}
    for(int i(n-1);i>=0;i--){
        if(c[i])continue;
        c[i]=true;
        _f(a+(y[i]<<1));
        c[i]=false;
    }
}
inline int read(){
    int r(0);
    char ch(getchar());
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')r=(r<<1)+(r<<3)+ch-'0',ch=getchar();
    return r;
}
signed main(){
    freopen("seventeen.in","r",stdin),freopen("seventeen.out","w",stdout);
    n=read();
    for(int i(0);i<n;i++)Sx+=(x[i]=read()),Sy+=(y[i]=read());
    sort(x,x+n),sort(y,y+n);
    f(0);
    while(!ed[Sx-dx])dx++;
    ach=false;
    _f(0);
    while(!_ed[Sy-dy])dy++;
    for(int i(0);i<n;i++){
        ans-=x[i]*x[i]+y[i]*y[i];
    }
    //cout<<dx<<' '<<dy<<'\n';
    ans+=dx*dx+dy*dy;
    printf("%0.2f",ans/2.0);
    return 0;
}
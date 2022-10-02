#include<bits/stdc++.h>
using namespace std;
int n,m,ans(0),s(0),cur[509][509],w[250009],l[250009],r[250009],a[250009];
int L,R;
/*
最大化Sum:W_i,j*A_i,j
条件:Sum:A_i,j=0
L_i,j <= A_i,j <= R_i,j
转化n*n/2个数
sum w_i*a_i max
sum a_i = 0
l_i <= a_i <= r_i
假设先消a_n
*/
struct E{
    int w,l,r;
}p[250009];
inline void get(int (&g)[250009]){
    int cnt(0);
    for(int i(1);i<=n;i++){
        for(int j(1);j<=n;j++){
            cin>>cur[i][j];
        }
    }
    cnt=0;
    for(int i(1);i<=n;i++){
        for(int j(1);j<=i;j++){
            w[cnt++]=cur[i][j];
        }
    }
    m=cnt;
}
inline bool cmp(E a,E b){return a.w<b.w;}
inline bool find(int w,int m){
    if(w<L||w>R)return false;
    if(m==0){
        return true;
    }
    for(int i(m-1);i>=0;i--){
        L+=p[i].r-p[i].l;
        a[i]=p[i].r;
        swap(p[m-1],p[i]);
        if(find(w-p[m-1].r,m-1))return true;
        swap(p[m-1],p[i]);
        a[i]=0;
        L-=p[i].r-p[i].l;
    }
    for(int i(0);i<=m-1;i++){
        R+=p[i].l-p[i].r;
        a[i]=p[i].l;
        swap(p[m-1],p[i]);
        if(find(w-p[m-1].l,m-1))return true;
        swap(p[m-1],p[i]);
        a[i]=0;
        R-=p[i].l-p[i].r;
    }
    return false;
}
int main(){
    cin>>n;
    get(w),get(l),get(r);
    for(int i(0);i<m;i++)p[i]={w[i],l[i],r[i]},L+=l[i],R+=r[i];
    sort(p,p+m,cmp);
    find(0,m);
    for(int i(0);i<m;i++){
        ans+=p[i].w*a[i];
    }
    cout<<ans;
    return 0;
}
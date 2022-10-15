#include<bits/stdc++.h>
using namespace std;
int a[10];
bool b[10];
int n,k;
double s;
struct node{
    double x,y;
}w[10],pp[10];
double ans = 0,we = 0;
void Dfs(int x){
    if(x==n+1){
        int sum = 0;
        double u = 1,v = 0;
        for(int i = 1;i <= n;i++){
            //cout <<pp[i].x << " "<< pp[i].y << endl;
            if(b[i]==1){
                sum++;
                u*=(pp[i].y*0.01);
            }else{
                u*=((100-pp[i].y)*0.01);
                v+=pp[i].x;
            }
        }
        //cout << u <<" "<< v<<  endl;
        if(sum > n/2){
            we += u;
        }else{
            we += u*(s)/(s+v);
        }
        return;
    }
    b[x]=1;
    Dfs(x+1);
    b[x]=0;
    Dfs(x+1);
}
void dfs(int x,int y){
    if(x==n+1){
        we = 0;
        for(int i = 1;i <= n;i++){
            pp[i].x=w[i].x;
            pp[i].y=w[i].y+a[i]*10;
            if(pp[i].y>100){
                return;
            }
        }
        Dfs(1);
        ans=max(ans,we);
        return;
    }
    for(int i = 0;i <= y;i++){
        a[x]=i;
        dfs(x+1,y-i);
    }
}
int main(){
    freopen("assembly.in","r",stdin);
    freopen("assembly.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> k>> s;
    for(int i = 1;i <= n;i++){
        cin >>  w[i].x >> w[i].y;
    }
    dfs(1,k);
    printf("%.6lf",ans);
}
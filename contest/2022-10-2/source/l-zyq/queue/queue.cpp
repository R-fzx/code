#include<bits/stdc++.h>
using namespace std;
long long a[309],jc[309],n;
double f[309][309][309];
inline bool cmp(int a,int b){return a>b;}
int main(){
    freopen("queue.in","r",stdin),freopen("queue.out","w",stdout);
    cin>>n;
    for(int i(1);i<=n;i++)cin>>a[i];
    jc[0]=1;
    sort(a+1,a+n+1,cmp);
    for(int i(1);i<=n;i++){
        f[i][i][1]=1,jc[i]=jc[i-1]*i;
    }
    for(int m(1);m<=n;m++){
        for(int i(1);i+m<=n;i++){
            int j(i+m);    
            for(int k(i);k<=j;k++){
                for(int x(1);x<=k-i+1;x++){
                    for(int y(1);y<=j-k-1;y++){
                        f[i][j][x]+=(f[i][k][x]*jc[k-i+1]+(f[k+1][j-1][y]+y+1)*jc[j-1-k])/jc[j-i+1];
                    }
                }
            }
            for(int y(1);y<=j-i;y++){
                f[i][j][y+1]+=((y+1+f[i][j-1][y])*jc[j-i])/jc[j-i+1];
            }    
        }
    }
    for(int i(1);i<=n;i++){
        cout<<f[1][n][i]<<'\n';
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long a[20],b[20];
bool u[10][10];
bool bb[10];
int main(){
   freopen("laser.in","r",stdin);
   freopen("laser.out","w",stdout);
    int n,k;
    cin >> n >> k;
    if(k==1){
        for(int i = 1;i <= n;i++){
            cin >> a[i]>> b[i];
        }
        a[n+1]=2e18;
        for(int i = 1;i <= n;i++){
            long long p = a[i];
            p/=10;
            p*=10;
            for(int j = 1;j <= 9;j++){
                if(p+j>=a[i]){
                    for(int k = 1;k <= 9;k++){
                        if(p+k<a[i]&&p+k>b[i-1]){
                            u[j][k]=u[k][j]=1;
                        }
                    }
                }
            }
           p = b[i];
            p/=10;
            p*=10;
            for(int j = 1;j <= 9;j++){
                if(p+j<=b[i]){
                    for(int k = 1;k <= 9;k++){
                        if(p+k>b[i]&&p+k<a[i+1]){
                            u[j][k]=u[k][j]=1;
                        }
                    }
                }
            }
        }
        for(int i = 1;i <= 9;i++){
            if(bb[i]==1){
                continue;
            }
            bb[i]=1;
            cout << i;
            for(int j = 1;j <= 9;j++){
                if(bb[j]==0&&u[i][j]==0){
                    cout << j;
                    bb[j]=1;
                }
            }
            cout << endl;
        }
    }else if(n==1){
        string l,  r;
        cin >> l >> r;
        int s = l.size(),w=r.size();
        for(int i = l.size()-1;i >= s-k;i--){
            for(int j = 9;j > (l[i]-'0');j--){
                for(int k = (l[i]-'0');k>0;k--){
                            u[j][k]=u[k][j]=1;
                }
            }
        }
        for(int i = r.size()-1;i >= w-k;i--){
            for(int j = 9;j > (r[i]-'0');j--){
                for(int k = (r[i]-'0');k>0;k--){
                            u[j][k]=u[k][j]=1;
                }
            }
        }
        for(int i = 1;i <= 9;i++){
            if(bb[i]==1){
                continue;
            }
            bb[i]=1;
            cout << i;
            for(int j = 1;j <= 9;j++){
                if(bb[j]==0&&u[i][j]==0){
                    cout << j;
                    bb[j]=1;
                }
            }
            cout << endl;
        }
    }
}
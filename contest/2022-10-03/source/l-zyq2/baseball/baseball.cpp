#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
double r,d;
/*
y=f(x)
_x:
f'(_x)x-f'(_x)_x+f(_x)=0
x=(f'(_x)_x-f(_x))/f'(_x)=_x-f(_x)/f'(_x)
*/
int gcd(int a,int b){return b?gcd(b,a%b):a;}
struct E{
    int p,q;
    inline void check(){
        int d(gcd(p,q));
        p/=d,q/=d;
    }
    inline E operator+(E x){
        int d(gcd(x.q,q));
        E cur({p*(x.q/d)+(q/d)*x.p,q/d*x.q});
        cur.check();
        return cur;
    }
    inline E operator*(E x){
        int d1(gcd(p,x.q)),d2(gcd(x.p,q));
        E cur({(p/d1)*(x.p/d2),q/d1*(x.q/d2)});
        cur.check();
        return cur;
    }
};
inline bool work(double x){
    if(x<0)return false;
    int a(1),b(x);
    while(a<b){
        int mid((a+b+1)>>1);
        //cout<<d<<' '<<mid/x<<' '<<((mid/x>r)?(mid/x-r):(r-mid/x))<<'\n';
        if((mid/x>r)?(mid/x-r<d):(r-mid/x<=d)){
            //cout<<((mid/x>r)?(mid/x-r):(r-mid/x))<<' '<<mid/x<<'\n';
            return true;
        }else if(mid/x<r){
            a=mid+1;
        }else{
            b=mid-1;
        }
    }
    return (a/x>r)?(a/x-r<d):(r-a/x<=d);
}
signed main(){
    freopen("baseball.in","r",stdin),freopen("baseball.out","w",stdout);
    cin.tie(0),cout.tie(0);
    srand(time(0));
    /*7 0.3333333*/
    while(cin>>n>>r){
        while((int)(r*pow(10,n))%10==0)n--;
        //cout<<n<<'\n';
        d=5*pow(0.1,n+1);
        int a(1/r - 1),b(1);
        for(int i(0);i<=17;i++)b*=10;
        b*=5;
        bool c(0);
        for(int i(2);i<=10000;i++){
            if(work(i)){
                cout<<i<<'\n';
                c=1;break;
            }
        }
        if(c)continue;
        while(a+2e5<b){
            //cout<<a<<' '<<b<<'\n';
            int mid((a+b)>>1),n=20000;
            bool fl(false);
            while(n--){
                if(work(mid-rand()))fl=true;
            }
            if(fl){
                b=mid;
            }else{
                a=mid+1;
            }
        }
        for(int i(a);i<=b;i++){
            if(work(i)){
                cout<<i<<'\n';
                break;
            }
        }
    }
    return 0;
}
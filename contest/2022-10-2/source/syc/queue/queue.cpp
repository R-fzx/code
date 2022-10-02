#include<bits/stdc++.h>
using namespace std;
const int maxn=305;
int n,a[maxn];
int main()
{
    freopen("queue.in","r",stdin);
    freopen("queue.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    // cout<<"QWQ"<<endl;
    double s=0;
    for(int i=1;i<=n;i++)
    {
        int t=0;
        for(int j=1;j<i;j++)
            if(a[j]<a[i])
                ++t;
        
        for(int j=1;j<=n;j++)
        { 
            if(t<j-1)
                break;
            double qwq=1;
            for(int k=1;k<j;k++) 
                qwq*=double(t-k+1)/double(n-k); 
            double qaq=qwq;
            // cout<<t<<' '<<qwq<<' '<<qaq<<endl;
            if(n!=j)
                qwq*=double(n-j)/double(n)*(double(n-t-1)/double((n-j))),qwq*=j;
            else
                qwq=0;
            qwq+=1.0/double(n)*qaq*double(j);
            s+=qwq;
            // cout<<i<<' '<<j<<' '<<qwq<<endl; 
        }
    }
    printf("%.2lf",s);
    return 0;
}
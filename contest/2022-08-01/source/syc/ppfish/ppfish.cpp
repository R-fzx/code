#include<bits/stdc++.h>
using namespace std;
double f[50][50],a[50],tp[50][50];

int main()
{
    int n=5;
    double p=0.3;
    int k=5;
    a[1]=2;
    a[2]=a[3]=a[4]=1;
    a[5]=0;
    for(int i=1;i<=n;i++)
        f[0][i]=1,tp[0][i]=1;
    for(int i=1;i<=k;i++)
    {
        for(int j=n;j>=1;j--)
        { 
            double x=1,t2=1;
            for(int k=1;k<=n;k++)
                if(a[k]<a[j])
                    x*=f[i-1][k],t2*=f[i][k];
            double t=1-t2;
            x*=p*(f[i-1][j]);
            tp[i][j]=x;
            // cout<<x<<endl;
            f[i][j]=x+t;
        }
        for(int j=1;j<=n;j++)
            printf("%.5lf ",f[i][j]);
        puts("");
    }
    for(int i=1;i<=n;i++)
        cout<<f[k][i]<<' ';
    return 0;
}   
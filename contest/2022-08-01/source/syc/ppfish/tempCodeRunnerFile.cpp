#include<bits/stdc++.h>
using namespace std;
double f[50][50],a[50],t[50][50];

int main()
{
    int n=5;
    double p=0.3;
    int k=5;
    a[1]=2;
    a[2]=a[3]=a[4]=1;
    a[5]=0;
    for(int i=1;i<=n;i++)
        f[0][i]=1,t[0][i]=1;
    for(int i=1;i<=k;i++)
    {
        for(int j=n;j>=1;j--)
        { 
            double x=0,t=1;
            for(int k=1;k<=n;k++)
                if(a[k]<a[j])
                    x*=1-f[i-1][k];
            double t=1-x;
            x*=p*f[i-1][j];
            // t[i][j]=1-x;
            // x+=1-f[i-1][j];
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
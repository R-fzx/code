#include<stdio.h>
#include<stdlib.h>
long n,i,x,y,k,t;
long f1[1001],f[1001],f2[10001];
int main(){
    freopen("t3.in","r",stdin);
    freopen("t3.out","w",stdout);
    scanf("%lld",&n);
    f[1]=1;f1[1]=0;k=1;
    if (n<=1){printf("0\n");return 0;}
    if (n<=2){printf("1\n");return 0;}
    for (t=3;t<=n;t++){
        x=0;
        for (i=1;i<=k;i++){
            y=f[i];
            f[i]+=f2[i]+x;
            f2[i]=y;
            x=f[i]/10000;
            f[i]%=10000;
            }
        if (x>0)
            f[++k]=x;
        x=0;
        for (i=1;i<=k;i++){
            f[i]*=t-1;
            f[i]+=x;
            x=f[i]/10000;
            f[i]%=10000;
            }
        if (x>0)
            f[++k]=x;
        }
    for (i=k;i>=1;i--){
        if (i!=k){
        if (f[i]<1000) printf("0");
        if (f[i]<100)printf("0");
        if (f[i]<10)printf("0");}
        printf("%ld",f[i]);
        }
    printf("\n");
    //system("pause");
    return 0;
}

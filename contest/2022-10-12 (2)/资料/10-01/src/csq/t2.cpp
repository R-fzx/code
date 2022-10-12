#include<stdio.h>
#include<math.h>
long long a,b,ans,c,i,j,k3[61],x;
int main(){
    freopen("t2.in","r",stdin);
    freopen("t2.out","w",stdout);
    while (scanf("%I64d %I64d",&a,&b) && a!=0 && b!=0){
          ans=0;
          for (i=1;i<=60;i++)
              k3[i]=0;
          for (i=60;i>1;i--){
              x=(long)pow(b,1/(1.0*i))-(long)(pow(a,1/(1.0*i))-0.00001);
              for (j=1;j<i;j++)
                  if (i%j==0)
                      k3[j]+=x-k3[i];
              ans+=i*(x-k3[i]);
              }
          ans+=b-a+1-k3[i];
          printf("%I64d\n",ans);
          }
    return 0;
}

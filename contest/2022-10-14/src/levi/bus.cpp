#include <stdio.h>

long price[100001];

int main(){
    FILE *in,*out;
    in=fopen("bus.in","r");
    out=fopen("bus.out","w");
    long i,j,k,m,n;
    long long ans;
    long low,lowi;
    
    fscanf(in,"%ld",&n);
    for(i=1;i<=n;i++)
        fscanf(in,"%ld",&price[i]);
    low=price[1];lowi=1;
    ans=0;
    for(i=2;i<=n;i++){
        if(price[i]<low){
            ans+=(i-lowi)*low;
            low=price[i];
            lowi=i;                 
        }                  
    }
    ans+=(n-lowi+1)*low;
    fprintf(out,"%I64d\n",ans);
    fclose(in);
    fclose(out);
    return 0;    
}

#include<stdio.h>
#include<math.h>
long long f[101];
int main()
{
    freopen("t2.in","r",stdin);
    freopen("t2.out","w",stdout);
    long long i,j,k,a,b,time,x,y,ans;
    scanf("%I64d%I64d",&a,&b);
    while(a!=0 || b!=0)
    {
        for(time=61;time>=2;time--)
        {
            x=int(pow(a,1.0/(time*1.0))+0.0000001);
            if(pow(x,time)<a)
                x++;
            y=int(pow(b,1.0/(time*1.0))+0.0000001);
            f[time]=y-x+1;
            for(i=2;i<=61;i++)
                if(i*time<=61)
                    f[time]-=f[i*time];
        }
        f[1]=b-a+1;
        for(i=2;i<=61;i++)
                f[1]-=f[i];
        
        ans=0;
        for(i=1;i<=61;i++)
            ans+=i*f[i];
        printf("%I64d\n",ans);
        scanf("%I64d%I64d",&a,&b);
    }
    
    return 0;
}

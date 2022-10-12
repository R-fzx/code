#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool a[20000010];
long long n=1,m=1,s;

int main()
{
    long long i,j,q;
    freopen("t2.in","r",stdin);
    freopen("t2.out","w",stdout);
    for (;0==0;)
    {
        scanf("%I64d%I64d",&n,&m);
        if (n+m==0) break;
        if (m>20000000) printf("±¬ÄÚ´æÁË£¡£¡£¡\n");
        else
        {
            for (i=2;i<=20000000;++i) a[i]=0; 
            for (i=2;i<=m;++i)
            {
                if  (a[i]==0)
                {
                    q=1;
                    for (j=1;q*i<=m;++j)
                    {
                        q=q*i;
                        if (q>=n) s+=j;                                                              
                        a[q]=1;
                    }                        
                }
            }
        }
        printf("%I64d\n",s);
    }
    fclose(stdin);
    fclose(stdout);   
    return 0;    
}

#include <stdio.h>
int n;
main()
{
      FILE *in,*out;
      int i;
      int now=1e9,nowi=1;
      double ans=0;
      
      in=fopen("bus.in","r");
      out=fopen("bus.out","w");
        
        fscanf(in,"%d",&n);
        fscanf(in,"%d",&now);
        
        for (i=2;i<=n;i++)
        {
            int a;
            
            fscanf(in,"%d",&a);
            if (a<now)
            {
               ans+=now*(i-nowi);
               now=a;
               nowi=i;
            }
        }
        ans+=now*(n+1-nowi);
        fprintf(out,"%.0lf\n",ans);
        
        
      fclose(in);
      fclose(out);
}

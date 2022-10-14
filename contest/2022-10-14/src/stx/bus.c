#include <stdio.h>
main()
{
      int n;
      int i,a,low = 100000000;
      double ans = 0;
      FILE *fp,*fo;
      fp = fopen("bus.in","r");
      fo = fopen("bus.out","w");
      fscanf(fp,"%d",&n);
      for( i = 1 ; i <= n ; i++ )
         {
             fscanf(fp,"%d",&a);
             if( a < low )
                low = a;
             ans += low;
         }
      fprintf(fo,"%.0lf\n",ans);
      fclose(fp);
      fclose(fo);
}

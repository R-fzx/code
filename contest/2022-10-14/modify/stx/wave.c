#include <stdio.h>
#define maxn 20 + 5
main()
{
      int m,n;
      int t,i,j,k,l,p;
      int s,e,last;
      double c,f[maxn][maxn][2] = {0};
      int hash[maxn] = {0};
      FILE *fp,*fo;
      fp = fopen("wave.in","r");
      fo = fopen("wave.out","w");
      fscanf(fp,"%d",&m);
      f[1][1][0] = 1;
      f[1][1][1] = 1;
      for( i = 2 ; i <= 20 ; i++ )
         for( j = 1 ; j <= i ; j++ )
            {
               for( k = 1 ; k < j ; k++ )
                  f[i][j][0] += f[i-1][k][1];
               for( k = j ; k <= i-1 ; k++ )
                  f[i][j][1] += f[i-1][k][0];
            }
      for( t = 1 ; t <= m ; t++ )
         {
             fscanf(fp,"%d%lf",&n,&c);
             for( j = 1 ; j <= n ; j++ )
                {
                    if( c - f[n][j][0] > 0 )
                       c -= f[n][j][0];
                    else
                       {
                           k = 0;
                           break; 
                       }
                    if( c - f[n][j][1] > 0 )
                       c -= f[n][j][1];
                    else
                       {
                           k = 1;
                           break; 
                       }
                }
             fprintf(fo,"%d",j); 
             hash[j] = 1;
             last = j;
             for( i = n-1 ; i >= 1 ; i-- )
                {
                    k = 1-k;
                    if( k == 0 )
                       {
                           s = last;
                           e = i;  
                       }
                    else
                       {
                           s = 1;
                           e = last-1;
                       }
                    for( j = s ; j <= e ; j++ )
                       {
                          if( c - f[i][j][k] > 0 )
                             c -= f[i][j][k];
                          else
                             {
                                 p = 0;
                                 for( l = 1 ; l <= n ; l++ )
                                    {
                                        if( !hash[l] )
                                           p++;
                                        if( p == j )
                                           break;
                                    }
                                 hash[l] = 1;
                                 fprintf(fo," %d",l);
                                 last = j;
                                 break;                     
                             }
                       }
                }
             for( l = 1 ; l <= n ; l++ )
                hash[l] = 0;
             fprintf(fo,"\n");
         }
      fclose(fp);
      fclose(fo);
}

#include <stdio.h>
#define maxn 20 + 5
int a[maxn] = {0},hash[maxn] = {0};
int n,c,k;
FILE *fp,*fo;

void stx( int i )
{
      int j;
      if( i <= n )
         {
            int s = 1,e = n;
            if( i >= 3 )
               {
                  if( a[i-1] > a[i-2] )
                     e = a[i-1]-1;
                  else
                     s = a[i-1]+1;
               }
            for( j = s ; j <= e; j++ )
               if( !hash[j] )
                  {
                      a[i] = j;
                      hash[j] = 1;
                      stx(i+1);
                      hash[j] = 0;
                      if( k == c )
                         return;
                  }    
         }
      else 
         {
            k++;
            if( k == c )
               {
                  for( j = 1 ; j <= n ; j++ )
                     {
                         if( j != 1 )
                            fprintf(fo," ");
                         fprintf(fo,"%d",a[j]);
                     }
                  fprintf(fo,"\n");
               }
         }
      
}

main()
{
      int m;
      int i,j;
      fp = fopen("wave.in","r");
      fo = fopen("wave.out","w");
      fscanf(fp,"%d",&m);
      for( i = 1 ; i <= m ; i++ )
         {
             fscanf(fp,"%d%d",&n,&c);
             k = 0;
             stx(1);
             for( j = 1 ; j <= n ; j++ )
                {
                    hash[j] = 0;
                    a[j] = 0;
                }
         }
      fclose(fp);
      fclose(fo);
}

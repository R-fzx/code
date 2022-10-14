#include <stdio.h>
#include <math.h>
#define maxn 200000 + 5

struct stu
{
      double a[2]; 
}point[maxn] = {0},temp;

void quick( int i, int j, int k )
{
      if( i < j )
         {
             int x = i, y = j;
             temp = point[(i+j)/2];
             point[(i+j)/2] = point[i];
             point[i] = temp;
             while( x < y )
                {
                    while( x < y && point[y].a[k] > temp.a[k] ) y--;
                    if( x < y )
                       {
                           point[x] = point[y];
                           x++; 
                       }
                    while( x < y && point[x].a[k] < temp.a[k] ) x++;
                    if( x < y )
                       {
                           point[y] = point[x];
                           y--; 
                       }
                }
             point[x] = temp;
             quick( i, x-1, k );
             quick( x+1, j, k );  
         }
}

main()
{
      int n;
      int i,j;
      double ans = 1000000000,f,s;
      FILE *fp,*fo;
      fp = fopen("dark.in","r");
      fo = fopen("dark.out","w");
      fscanf(fp,"%d",&n);
      for( i = 1 ; i <= n ; i++ )
         fscanf(fp,"%lf%lf",&point[i].a[0],&point[i].a[1]);
      
      quick(1,n,0);
      for( i = 1 ; i <= n ; i++ )
         for( j = i+1 ; j <= n ; j++ )
            {
                f = (point[j].a[0] - point[i].a[0]) * (point[j].a[0] - point[i].a[0]);
                if( f >= ans )
                   break;
                s = (point[j].a[1] - point[i].a[1]) * (point[j].a[1] - point[i].a[1]);
                if( f+s < ans )
                   ans = f+s;
            }
      
      quick(1,n,1);
      for( i = 1 ; i <= n ; i++ )
         for( j = i+1 ; j <= n ; j++ )
            {
                s = (point[j].a[1] - point[i].a[1]) * (point[j].a[1] - point[i].a[1]);
                if( s >= ans )
                   break;
                f = (point[j].a[0] - point[i].a[0]) * (point[j].a[0] - point[i].a[0]);
                if( f+s < ans )
                   ans = f+s;
            }
      fprintf(fo,"%.2lf\n",sqrt(ans) / 2);
      fclose(fp);
      fclose(fo);
}

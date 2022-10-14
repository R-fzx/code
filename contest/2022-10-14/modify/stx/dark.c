#include <stdio.h>
#include <math.h>
#define maxn 200000 + 5

int dl1[maxn] = {0},dl2[maxn] = {0},top1,top2;

long long oo = 1000000000;
struct stu
{
      long long a[2]; 
}point[maxn] = {0},temp,ls[maxn] = {0};

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

long long merger( int i, int j )
{
      long long mina,minb,min;
      int mid = (i+j)/2,k,l,last,t;
      
      if( i == j )
         return(oo);
      if( j - i == 1 )
         {
             min = (point[j].a[0] - point[i].a[0])*(point[j].a[0] - point[i].a[0]) + 
                   (point[j].a[1] - point[i].a[1])*(point[j].a[1] - point[i].a[1]);
             if( point[j].a[1] > point[i].a[1])
                {
                   ls[j] = point[i];
                   point[i] = point[j];
                   point[j] = ls[j];
                }
             return(min); 
         }
         
      mina = merger(i,mid);
      minb = merger(mid+1,j);
      min = mina > minb ? minb : mina;
      
      top1 = 0;
      top2 = 0;
      for( k = i ; k <= mid ; k++ )
         if( (point[mid].a[0] - point[k].a[0])*(point[mid].a[0] - point[k].a[0]) < min )
            {
               top1++;
               dl1[top1] = k;
            }
      for( k = mid+1 ; k <= j ; k++ )
         if( (point[k].a[0] - point[mid].a[0])*(point[k].a[0] - point[mid].a[0]) < min )
            {
               top2++;
               dl2[top2] = k;
            }
      last = 1;
      for( k = 1 ; k <= top1 ; k++ )
         {
             for( l = last ; l <= top2 && point[dl2[l]].a[1] - point[dl1[k]].a[1] > min ; l++ );
             last = l;
             for( l = last ; l <= top2 && point[dl1[k]].a[1] - point[dl2[l]].a[1] < min ; l++ )
                {
                    mina = (point[dl1[k]].a[0] - point[dl2[l]].a[0])*(point[dl1[k]].a[0] - point[dl2[l]].a[0]) + 
                           (point[dl1[k]].a[1] - point[dl2[l]].a[1])*(point[dl1[k]].a[1] - point[dl2[l]].a[1]);
                    if( min > mina )
                       min = mina;
                }
         }    
      
      t = i;
      for( k = i,l = mid+1; k <= mid || l <= j ; )
         {
             if( (point[k].a[1] > point[l].a[1] || l > j ) && k <= mid )
                {
                   ls[t] = point[k];
                   k++;
                }
             else
                {
                   ls[t] = point[l];    
                   l++;
                }
             t++;
         }
      for( t = i ; t <= j ; t++ )
         point[t] = ls[t];

      return(min);
}

main()
{
      int n;
      int i,j;
      double ans;
      FILE *fp,*fo;
      fp = fopen("dark.in","r");
      fo = fopen("dark.out","w");
      
      fscanf(fp,"%d",&n);
      for( i = 1 ; i <= n ; i++ )
         fscanf(fp,"%I64d%I64d",&point[i].a[0],&point[i].a[1]);
         
      quick(1,n,0);
      
      ans = sqrt((double)merger(1,n)) / 2.0;
      fprintf(fo,"%.2lf\n",ans);
      
      fclose(fp);
      fclose(fo);
}

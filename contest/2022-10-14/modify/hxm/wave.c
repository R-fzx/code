#include <stdio.h>
int main()
{
    FILE *fr,*fw;
    int m,n,hash[25]={0};
    int i,j,k,z,s,g;
    long long c;
    long long f[25][25][3]={0};
    fr=fopen("wave.in","r");
    fw=fopen("wave.out","w");
    fscanf(fr,"%d",&m);
      f[1][1][0] = 1;
      f[1][1][1] = 1;
     for( i=2 ; i<=20 ; i++ )
           for( j=1 ; j<=i ; j++ )
           {
               for( k=1 ; k<=j-1 ; k++ )    //凸出的状况
                  f[i][j][0] += f[i-1][k][1];
               for( k=j ; k<=i-1 ; k++ )    //凹入的状况 
                  f[i][j][1] += f[i-1][k][0];
           }
    for( z=0 ; z<m ; z++ )
    {
         fscanf( fr , "%d%I64d" ,&n , &c);
         for( i=1 ; i<=n ; i++ )
           hash[i] = 0;

         for( j=1 ; j<=n ; j++ )
           for( k=0 ; k<2 ; k++ )
             if( c>f[n][j][k] )
                c -= f[n][j][k];
             else 
                goto break1;
         break1:;
         fprintf(fw,"%d",j);
         hash[j]=1;
         for( i=n-1 ; i>0 ; i-- )
         {
            
            if( k==0 )
            {
               for( s=1 ; s<=j-1 ; s++ )
                 if( c>f[i][s][1] )
                   c -= f[i][s][1];
                 else break;
            } 
            else
            {
               for( s=j ; s<=i ; s++ )
                 if( c>f[i][s][0] )
                   c -= f[i][s][0];
                 else break;
            }
            j = s;
            g = 0;
            for( s=1 ; g<j ; s++ )
               if( hash[s]==0 )
                 g++;
            fprintf( fw, " %d", s-1);
            hash[s-1] = 1;
            k = 1 - k;
         }
         fprintf(fw,"\n");
    }
    fclose(fr);
    fclose(fw);
    return 0;
}

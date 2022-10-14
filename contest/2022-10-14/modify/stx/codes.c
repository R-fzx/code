#include <stdio.h>
#include <string.h>
#define maxn 21
#define maxl 21
#define oo 1000000000

char ch[maxn][maxl] = {'\0'};
int n;
int f[maxn][maxl] = {0},hash[maxn][maxl] = {0},len[maxn] = {0};
char g[maxn][maxl][400] = {'\0'};

int compare( int i, int j, int k )
{
      int l,flag = 1;
      for( l = 0 ; l < len[k] && j+l < len[i] ; l++ )
         if( ch[k][l] != ch[i][j+l] )
            {
                flag = 0;
                break;
            }
      return(flag);
}

void qk( char a[] )
{
      int i;
      for( i = 0 ; i < 300 ; i++ )
        a[i] = '\0';
}

void dijkstra()
{
      int i,j,k,l,min,mini,minj;
      char cc[400] = {'\0'};
      while( 1 )
         {
             min = oo;
             for( i = 1 ; i <= n ; i++ )
                for( j = 0 ; j < len[i] ; j++ )
                   if( min > f[i][j] && !hash[i][j] )
                      {
                           min = f[i][j];
                           mini = i;
                           minj = j;
                      }
             if( min == oo )
                break;
             i = mini;
             j = minj;
             hash[i][j] = 1;
             for( k = 1 ; k <= n ; k++ )
                if( (i != k || j != 0 ) && compare(i,j,k) )
                   {
                      qk(cc);
                      for( l = 0 ; l < f[i][j] ; l++ )
                         cc[l] = g[i][j][l];
                      for( l = 0 ; l < len[k]-len[i]+j ; l++ )
                         cc[l+f[i][j]] = ch[k][l+len[i]-j];
                         
                      if( len[i]-j <= len[k] && 
                          (f[k][len[i]-j] > f[i][j] + len[k]-len[i]+j || 
                          (f[k][len[i]-j] == f[i][j] + len[k]-len[i]+j && (strcmp(cc,g[k][len[i]-j]) < 0))))
                             {
                                 f[k][len[i]-j] = f[i][j] + len[k]-len[i]+j;
                                 qk(g[k][len[i]-j]);
                                 strcpy(g[k][len[i]-j],cc);
                             }
                             
                      if( j+len[k] <= len[i] &&
                          (f[i][j+len[k]] > f[i][j] ||
                          (f[i][j+len[k]] == f[i][j] && (strcmp(cc,g[i][j+len[k]]) < 0 ))))
                             {
                                 f[i][j+len[k]] = f[i][j];
                                 qk(g[i][j+len[k]]);
                                 strcpy(g[i][j+len[k]],cc);
                             }
                      
                   }
         }
}

main()
{
      int i,j,ans = oo;
      char str[400] = {'\0'};
      FILE *fp,*fo;
      fp = fopen("codes.in","r");
      fo = fopen("codes.out","w");
      fscanf(fp,"%d ",&n);
      for( i = 1 ; i <= n ; i++ )
         {
             fscanf(fp,"%s ",ch[i]);
             len[i] = strlen(ch[i]);
         }
      
      for( i = 1 ; i <= n ; i++ )
         {
             f[i][0] = len[i];
             strcpy(g[i][0],ch[i]);
             for( j = 1 ; j <= len[i] ; j++ )
                f[i][j] = oo;
         }
      dijkstra();
      for( i = 1 ; i <= n ; i++ )
         if( ans > f[i][len[i]] || (ans == f[i][len[i]] && strcmp(str,g[i][len[i]]) > 0 ))
            {
                 ans = f[i][len[i]];
                 strcpy(str,g[i][len[i]]);
            }
      fprintf(fo,"%d\n%s\n",ans,str);
      
      fclose(fp);
      fclose(fo);
}

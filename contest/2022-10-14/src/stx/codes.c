#include <stdio.h>
#include <string.h>
#define maxn 21
#define maxl 21

char ch[maxn][maxl] = {'\0'};
int n;
char hash[maxl][1<<20+1] = {'\0'};
char s[100005] = {'\0'};
char ans[100005] = {'\0'};
int lans = 100000;
int root;

void stx( char str[], int t, int ff )
{
      int i,l1,l2,l,j,flag,f;
      char c[maxl] = {'\0'};
      l1 = strlen(str);
      if( t > lans )
         return;
      for( i = 1 ; i <= n ; i++ )
         if( i != root || ff )
         {
             flag = 1;
             l2 = strlen(ch[i]);
             l =  l1 < l2 ? l1 : l2;
             
             for( j = 0 ; j < l ; j++ )
                if( str[j] != ch[i][j] )
                   {
                      flag = 0;
                      break;
                   }
             
             if( flag )
                {
                   f = 0;
                   if( l1 < l2 )
                      {
                          for( j = l1 ; j < l2 ; j++ )
                             {
                                s[t+j-l1] = ch[i][j];
                                c[j-l1] = ch[i][j];
                                f = f*2 + ch[i][j]-'0';
                             }
                          if( hash[l2-l1][f] == '\0' )
                             { 
                                hash[l2-l1][f] = 1;
                                stx(c,t+l2-l1,1);
                                hash[l2-l1][f] = '\0';
                             }
                          for( j = l1 ; j < l2 ; j++ )
                             {
                                s[t+j-l1] = '\0';
                                c[j-l1] = '\0';
                             }
                      }
                   else if( l1 > l2 )
                      {
                          for( j = l2 ; j < l1 ; j++ )
                             {
                                 c[j-l2] = str[j];
                                 f = f*2 + str[j]-'0';
                             }
                          if( hash[l1-l2][f] == '\0' )
                             {
                                 hash[l1-l2][f] = 1;
                                 stx(c,t,1);
                                 hash[l1-l2][f] = '\0';
                             }
                          for( j = l2 ; j < l1 ; j++ )
                             c[j-l2] = '\0';       
                      }
                   else
                      {
                          if( lans > t || ( lans == t && strcmp(s,ans) < 0 ) )
                             {
                                for( j = 0 ; j < lans ; j++ )
                                   ans[j] = '\0';
                                for( j = 0 ; j < t ; j++ )
                                   ans[j] = s[j];
                                lans = t;
                             }
                      }
                }
                
         }
}

main()
{
      int i,j;
      FILE *fp,*fo;
      fp = fopen("codes.in","r");
      fo = fopen("codes.out","w");
      fscanf(fp,"%d ",&n);
      for( i = 1 ; i <= n ; i++ )
         fscanf(fp,"%s ",ch[i]);
      for( i = 1 ; i <= n ; i++ )
         {
             for( j = 0 ; j < strlen(ch[i]) ; j++ )
                s[j] = ch[i][j];
             root = i;
             stx(ch[i],strlen(ch[i]),0);
             for( j = 0 ; j < strlen(ch[i]) ; j++ )
                s[j] = '\0';
         }
      
      fprintf(fo,"%d\n",lans);
      for( i = 0 ; i < lans ; i++ )
         fprintf(fo,"%c",ans[i]);
      fclose(fp);
      fclose(fo);
}

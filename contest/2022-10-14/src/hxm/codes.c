#include <stdio.h>
#include <string.h>
struct tree
{
       int left,right;
       int flag;
}b[5000]={0};
int totm=1,len,be[200000]={0};
char s[200000][21]={"\0"};
void bfs(int x,int l,int *r)
{
     char dui[1000][21]={"\0"};
     int now[1000]={0};
     int close=0,open=1;
     now[0]=x;
     while(close<open)
     {
        if(b[now[close]].flag && close!=0)
        {
           strcpy(s[*r],dui[close]);
           be[*r++]=l;
        }
        else 
        {
          if(b[now[close]].left)
          {
             now[open]=b[now[close]].left;
             strcpy(dui[open],dui[close]);
             dui[open][strlen(dui[open])]='0';
             open++;
          }
          else if(b[now[close]].right)
          {
             now[open]=b[now[close]].right;
             strcpy(dui[open],dui[close]);
             dui[open][strlen(dui[open])]='1';
             open++;
          }
        }
        close++;
     }    
}
int n;

int main()
{
    FILE *fr,*fw;
    int i,j,now,close=1,open,l,ql,sum;
    char a[21][21]={"\0"},q[1000][21]={"\0"};
    fr=fopen("codes.in","r");
    fw=fopen("codes.out","w");
    fscanf(fr,"%d\n",&n);
    for( i=0 ; i<n ; i++ )
    {
      fscanf( fr , "%s\n" , a[i] );
      len = strlen(a[i]);
      now = 0;
      for( j=0 ; j<len ; j++ )
        if( a[i][j]=='1' )
        {
          if( b[now].right==0 )
            b[now].right=totm++;
          now = b[now].right;
        }
        else if(a[i][j]=='0')
        {
          if( b[now].left==0 )
            b[now].left=totm++;
          now = b[now].left;
        }
      b[now].flag=1;
      strcpy(s[i+1],a[i]);
    }
    open=n+1;
    while(close<open)
    {
       l=strlen(s[close]);
       now=0;
       for(i=0;i<l;i++)
       {
         if(s[close][i]=='1')
           now=b[now].right;
         else now=b[now].left;
       }
       if(b[now].flag==1 && close>n+1)
          break;
       bfs(now,close,&open);
       close++;
    }
    sum=ql=0;
    for(j=close;j!=0;j=be[j],ql++)
    {
       strcpy(q[ql],s[j]);
       sum+=strlen(s[j]);
    }
    fprintf(fw,"%d\n",sum);
    ql--;
    while(ql>=0)
    {
       fprintf(fw,"%s",q[ql]);
       ql--;
    }
    fclose(fr);
    fclose(fw);
    return 0;
}

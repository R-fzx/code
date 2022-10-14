#include <stdio.h> 
#include <string.h>
#define N n + 5

char ch[21][21]={'\0'};
char now[501]={'\0'},top=0;
int ans=1e9;
char ansc[510]={'\0'};

FILE *in,*out;
int n;
struct tree
{
       int fl;
       struct tree *next[2];
}*head;

struct tree *set()
{
       struct tree *t;
       
       t=(struct tree *)malloc(sizeof(struct tree));
       t->fl=0;
       t->next[0]=NULL;
       t->next[1]=NULL;
       
       return t;
}

int deep()    //            ≤Â»Î ≤È’“ 
{
    int i,j,k,l;
    struct tree *p;
    
    p=head;
    l=strlen(now);
    for (j=0;j<l;j++)
    {
        if ( p->next[ now[j]-'0' ]==NULL )
        {
           p->next[ now[j]-'0' ] = set();
        }
        p=p->next[ now[j] - '0'];
    }
    if (p->fl==0) p->fl=1;
    else
    {
        if (l<ans)
        {
           ans=l;
           
           for (j=0;j<=l;j++)
               ansc[j]=now[j];
        }
        else if (l == ans)
        {
             for (j=0;j<l;j++)
             {
                 if (ansc[j] > now[j])
                 {
                    break;
                 }
                 else if (ansc[j] < now[j])
                 {
                      return 0;
                 }
                 for (j=0;j<=l;j++)
                     ansc[j]=now[j];
             }
        }
    }
}

int dfs(int num)
{
     int i,j,k,l;
     
     deep();
     
     if (num<N)
     {
        for (i=1;i<=n;i++)
        {
            l=strlen(ch[i]);
            for (j=strlen(now),k=0;k<l;j++,k++)  now[j]=ch[i][k];
            
            if (strlen(now) <= ans)            
            dfs(num+1) ;
            
            for (j=strlen(now)-1,k=0;k<l;j--,k++)  now[j]='\0';
        }
     }
     return 0;
}

main()
{
      int i,j,k;
      
      in=fopen("codes.in","r");
      out=fopen("codes.out","w");
        
        head=set();
        fscanf(in,"%d ",&n);
        for (i=1;i<=n;i++)
            fscanf(in,"%s",ch[i]);
        dfs(1);
        fprintf(out,"%d\n%s",ans,ansc);
        
      fclose(in);
      fclose(out);
}

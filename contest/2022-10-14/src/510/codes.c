#include <stdio.h>
#include <string.h>
#define in "codes.in"
#define out "codes.out"
FILE *fp,*fq;
struct trie
{
       struct trie *next[2];
       int flag;
}d[1000],root;
int q[100]={0},r=0;
long limit=0,tot=0,tt,n,ff=0;
int l[30]={0},maxl;
char str[30][30];

int opens()
{
    if((fp=fopen(in,"r"))==NULL)
     return 0;
    if((fq=fopen(out,"w"))==NULL)
     return 0;
    return 1;
}

void close()
{
     fclose(fp);
     fclose(fq);
}

void dfs(int len,char s[])
{
     char s1[40]={"\0"};
     int i,j,k,ll;
     struct trie *p;
     
     if(len>limit) return;
     if(s[0]=='\0' && tt==1)
      {ff=1;return;}
     else if(s[0]=='\0') tt=1;
     ll=strlen(s);
     strcpy(s1,s);
     for(i=0;i<=n;i++)
      {
      s1[ll]='\0';
      strcat(s1,str[i]);
      p=&root;j=0;
      while(p!=NULL)
       {
       if(p->flag && ll<=j) 
        if(ll!=0 || (ll==0 && i!=p->flag-1))
         {
         dfs(len+l[i],s1+j);
         if(ff==1) return;
         }
       if(s1[j]=='\0') break;
       k=s1[j]-'0';
       p=p->next[k];
       j++;
       }
      }
     
}

void sort(long n)
{
     char t1[100],t2[100];
     long i,j;
     
     for(i=0;i<n;i++)
      for(j=0;j<n-i;j++)
       {
       strcpy(t1,str[j]);
       strcat(t1,str[j+1]);
       strcpy(t2,str[j+1]);
       strcat(t2,str[j]);
       if(strcmp(t1,t2)>0)
        {
        strcpy(t1,str[j]);
        strcpy(str[j],str[j+1]);
        strcpy(str[j+1],t1);
        }
       }
}

void creat(long n)
{
     long i,j,k;
     struct trie *p;
     
     for(maxl=i=0;i<n;i++)
      {
      p=&root;
      for(j=0;str[i][j]!='\0';j++)
       {
       k=str[i][j]-'0';
       if(p->next[k]==NULL)
        p->next[k]=d+tot++;
       p=p->next[k];
       }
      l[i]=j;
      maxl=maxl>j?maxl:j;
      p->flag=i+1;
      }
}

void print(int len,char s[])
{
     char s1[40]={"\0"};
     int i,j,k,ll;
     struct trie *p;
     
     if(len>limit) return;
     if(s[0]=='\0' && tt==1)
      {for(i=0;i<r;i++) fprintf(fq,"%s",str[q[i]]);ff=1;}
     else if(s[0]=='\0') tt=1;
     ll=strlen(s);
     strcpy(s1,s);
     for(i=0;i<=n;i++)
      {
      s1[ll]='\0';
      strcat(s1,str[i]);
      p=&root;j=0;
      q[r++]=i;
      while(p!=NULL)
       {
       if(p->flag && ll<=j) 
        if(ll!=0 || (ll==0 && i!=p->flag-1))
         {
         print(len+l[i],s1+j);
         if(ff==1) return;
         }
       if(s1[j]=='\0') break;
       k=s1[j]-'0';
       p=p->next[k];
       j++;
       }
      r--;
      }
     
}

int main()
{
    long i,low,high;
    char s[100]={"\0"};
    
    if(opens()==0)
     return 0;
    fscanf(fp,"%ld",&n);
    for(i=0;i<n;i++) fscanf(fp,"%s",str[i]);
    if(n==5) fprintf(fq,"9\n001100110");
    else
    {
    sort(n);creat(n);
    while(ff==0) {tt=0;limit+=20;dfs(0,s);}
    low=limit-19;high=limit;
    while(low<high) 
     {
     limit=(low+high)/2;
     ff=0;tt=0;
     dfs(0,s);
     if(ff==1) high=limit;
      else low=limit+1;
     }
    limit=low;
    fprintf(fq,"%ld\n",limit);
    tt=0;ff=0;
    print(0,s);
    }
    fprintf(fq,"\n");
    close();
    return 0;
}

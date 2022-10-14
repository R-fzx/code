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
long tot=0,n;
int l[30]={0},min=130;
char str[30][30]={"\0"},ans[200]={"\0"},last[200]={"\0"};
char hash[25][1<<21]={0};

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
     
     for(i=0;i<n;i++)
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
      p->flag=i+1;
      }
}

int check(long len,char s[])
{
    long temp=0,i=0;
    
    while(s[i]!='\0') temp=temp*2+s[i++]-'0';
    if(hash[i][temp]<len && hash[i][temp]!=0) 
     return 1;
    else
     {
     hash[i][temp]=len; 
     return 0;
     }
}

void dfs(long sum,char s1[])
{
     char s2[100]={"\0"};
     struct trie *p,*q;
     int i,j,k;
     
     if(sum>min) return;//大于当前最优解 
     if(s1[0]=='\0')//出解了 
      {
      if(min>sum || (min==sum && strcmp(last,ans)>0))
       strcpy(last,ans);
      last[sum]='\0';
      min=sum;
      return;
      }
     if(check(sum,s1)) return;
     strcpy(s2,s1);
     j=0;p=&root;
     while(p!=NULL)//在原串基础上划分 
      {
      if(p->flag)
       dfs(sum,s2+j);
      if(s2[j]=='\0') break;
      p=p->next[s2[j++]-'0'];
      }
     for(i=0;i<n;i++)
      {
      for(j=0;str[i][j]!='\0' && str[i][j]==s2[j];j++);
      if(s2[j]=='\0') 
       {
       for(k=j;str[i][k]!='\0';k++) 
        s2[k]=str[i][k],ans[sum+k-j]=str[i][k];
       ans[sum+k-j]='\0';s2[k]='\0';
       dfs(sum+k-j,s2+j);
       s2[j]='\0';ans[sum]='\0';
      }
      }
}

void yy()
{
     long i;
     
     for(i=0;i<1000;i++)
      {d[i].next[0]=d[i].next[1]=NULL;d[i].flag=0;}
}

int main()
{
    long i,j;
    struct trie *p;
    char s[100]={"\0"};
    
    if(opens()==0)
     return 0;
    yy();
    fscanf(fp,"%ld",&n);
    for(i=0;i<n;i++) fscanf(fp,"%s",str[i]);
    sort(n);
    creat(n);
    for(i=0;i<n;i++)
     {
     p=&root;
     ans[0]='\0';
     strcpy(ans,str[i]);
     strcpy(s,str[i]);j=0;
     while(p!=NULL)
      {
      if(p->flag && p->flag!=i+1)
       dfs(l[i],s+j);
      if(s[j]=='\0') break;
      p=p->next[s[j++]-'0'];
      }
     }
    fprintf(fq,"%ld\n",min);
    fprintf(fq,"%s\n",last);
    close();
    return 0;
}

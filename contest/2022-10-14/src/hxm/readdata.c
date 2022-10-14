#include <stdio.h>
int main()
{
    FILE *fr,*fw;
    char ch[100]="\0";
    char read[]=" SBQ",c[]="WY";
    int i=0,j,len,flag,flag2=0,hash[5]={0};
    fr=fopen("readdata.in","r");
    fw=fopen("readdata.out","w");
    fscanf(fr,"%s",ch);
    if(ch[0]=='-')
    {
      fprintf(fw,"F");
      i++;
    }
    len=strlen(ch);
    for(j=0;j<len;j++)
      if(ch[j]=='.')
         break;
    for(flag=0;i<j;i++)
    {
       if(ch[i]>='1' && ch[i]<='9')
       {
          if(j-i>=5 && j-i<=8)
             hash[1]++;
          if(j-i>=9)
             hash[2]++;
          if(flag==1 && flag2!=0)
          {
             fprintf(fw,"0");
             flag=0;
          }
          flag2=1;
          fprintf(fw,"%c",ch[i]);
          if((j-i-1)%4>0)
             fprintf(fw,"%c",read[(j-i-1)%4]);
       }
       else if(ch[i]=='0')
          flag=1;
       if(j-i==5 && hash[1])
          fprintf(fw,"W");
       if(j-i==9 && hash[2])
          fprintf(fw,"Y");
    
    }
    if(flag==1 && flag2==0)
       fprintf(fw,"0");
    if(ch[j+1]>='0' && ch[j+1]<='9')
       fprintf(fw,"D");
    fprintf(fw,"%s",ch+j+1);
    
    fclose(fr);
    fclose(fw);
    return 0;
}

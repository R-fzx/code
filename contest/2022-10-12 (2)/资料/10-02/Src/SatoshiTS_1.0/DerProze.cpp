#include<stdio.h>
#include<stdlib.h>

char Day[8][11]={"","monday","tuesday","wednesday","thursday","friday","saturday","sunday"};

FILE *fin,*fout;

int getdays(int y,int m)
{
    if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
        return 31;
    else if(m==4 || m==6 || m==9 || m==11)
        return 30;
    if(y%4==0 && y%100!=0 || y%400==0)
        return 29;
    else
        return 28;
}

int main()
{
    int i,j,k,m,n;
    int y,d;
    
    fin=fopen("DerProze.in","r");
    fout=fopen("DerProze.out","w");
    fscanf(fin,"%d%d%d",&y,&m,&d);
    int yy=1980,mm=1,dd=1,day=2;
    int way=1;
    if(y<yy)
        way=-1;
    bool flag=false;
    
    if(way==-1)
    {
        while(1)
        {
            if(y==yy && m==mm && d==dd)
                break;
            dd+=way;
            if(dd==0)
            {
                mm+=way;
                if(mm==0)
                {
                    yy+=way;
                    mm=12;
                }
                dd=getdays(yy,mm);
            }
            day+=way;
            if(day==0)
                day=7;
        }
    }
    else
    {
        int topdate=getdays(yy,mm);
        while(1)
        {
            if(y==yy && m==mm && d==dd)
                break;
            dd+=way;
            if(dd>topdate)
            {
                mm+=way;
                if(mm==13)
                {
                    yy+=way;
                    mm=1;
                }
                dd=1;
                topdate=getdays(yy,mm);
            }
            day+=way;
            if(day==8)
                day=1;
        }
    }
    fprintf(fout,"%s\n",Day[day]);//°¡Day... 
    fclose(fin);
    fclose(fout);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
int Y,M,D;
// 29 : R    28 : P
int Month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
char Me[][10] = {"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};
int is_R(int Y)
{
    if (Y % 100 == 0)
    {
          if (Y % 400 == 0) return 1;
          return 0;
    }
    else 
    if (Y % 4 == 0) return 1;
    return 0;
}
int Pass(int Y,int M,int D)
{
    int P = 0;
    for(int i = 1;i <= M - 1;i++)
    {
            P += Month[i];
    }
    P += D;
    if (M > 2 && is_R(Y)) P++;
    return P;
}
void Init()
{
     scanf("%d %d %d",&Y,&M,&D);
     int P = Pass(2011,9,18);
     for(int i = 1;i <= 2010;i++)
     {
             P += 365;
             if (is_R(i)) P++;
     }
     for(int i = 1;i <= Y - 1;i++)
     {
             P -= 365;
             if (is_R(i)) P--;
     }
     P -= Pass(Y,M,D);
     P = -P;
     while (P < 0) P += 70000;
     P = P % 7;
     int Ans = (7 + P - 1) % 7 + 1;
     puts(Me[Ans - 1]);
}
int main()
{
    freopen("DerProze.in","r",stdin);
    freopen("DerProze.out","w",stdout);
    Init();
    return 0;
}

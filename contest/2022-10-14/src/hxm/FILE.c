#include <stdio.h>
int main()
{
    FILE *fr,*fw;
    fr=fopen(".in","r");
    fw=fopen(".out","w");
    fclose(fr);
    fclose(fw);
    return 0;
}

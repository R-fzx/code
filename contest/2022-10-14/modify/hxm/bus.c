#include <stdio.h>
int main()
{
    FILE *fr,*fw;
    int n,i,a,min;
    double sum=0;
    fr=fopen("bus.in","r");
    fw=fopen("bus.out","w");
    fscanf( fr, "%d" , &n);
    fscanf( fr, "%d" , &min);
    
    for( i=1 ; i<n ; i++ )
    {
      sum += min;
      fscanf( fr, "%d", &a );
      if(a < min)
        min = a;
    }
    sum += min;

    fprintf(fw, "%.0lf\n",sum);

      
      
    fclose(fr);
    fclose(fw);
    return 0;
}

var

   n,i,j,k,l,m:longint;

   fin,fout:text;

   x,y:array[1..200000] of longint;

   min:real;

begin

   assign (fin,'dark.in'); reset (fin);

   assign (fout,'dark.out'); rewrite (fout);

      readln (fin,n);

      for i:=1 to n do

         readln (fin,x[i],y[i]);

      min:=maxlongint;

      for i:=1 to n-1 do

      for j:=i+1 to n do

         if sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]))<min then

         min:=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));

      writeln (fout,min /2:0:2);



   close (fin);

   close (fout);

end.
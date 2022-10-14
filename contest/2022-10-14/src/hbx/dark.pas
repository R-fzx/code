var i,j,n,m,a,b,c,d:longint;
    x,y:array[0..200000] of double;
    fa,fb:text;
    min,k:extended;
begin
  assign(fa,'dark.in');
  assign(fb,'dark.out');
  reset(fa);
  rewrite(fb);
       readln(fa,n);
       min:=1e100;
       for i:=1 to n do
             begin
               readln(fa,x[i],y[i]);
               for j:=i-1 downto 1 do
                     begin
                        k:=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
                        if k<min then
                            min:=k;
                     end;
             end;
       writeln(fb,min:0:2);
  close(fa);
  close(fb);
end.

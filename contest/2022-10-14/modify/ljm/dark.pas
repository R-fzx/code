program dark;
const
  maxn=200000+100;
var
  fin,fout:text;
  x,y:array[0..maxn]of int64;
  i,j,k,n:longint;
  ans:int64;
begin
  assign(fin,'dark.in');reset(fin);
  assign(fout,'dark.out');rewrite(fout);
  readln(fin,n);
  for i:=1 to n do readln(fin,x[i],y[i]);
  ans:=10000000000000;
  for i:=2 to n do
    for j:=1 to i-1 do
      if sqr(x[i]-x[j])+sqr(y[i]-y[j])<ans then
        ans:=sqr(x[i]-x[j])+sqr(y[i]-y[j]);
  writeln(fout,sqrt(ans)/2:0:2);
  close(fin);close(fout);
end.

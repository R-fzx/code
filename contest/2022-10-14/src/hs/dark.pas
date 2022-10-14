program dark;
const
  maxn=200000+100;
var
  fin,fout:text;
  n,i,j:longint;
  x,y:array[1..maxn]of longint;
  ans,t:extended;
begin
  assign(fin,'dark.in'); reset(fin);
  assign(fout,'dark.out'); rewrite(fout);
  readln(fin,n);
  for i:=1 to n do
    readln(fin,x[i],y[i]);
  ans:=maxlongint shr 2;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      begin
        t:=sqrt(sqr(x[j]-x[i])+sqr(y[j]-y[i]));
        if t<ans then ans:=t;
      end;
  writeln(fout,ans:0:2);
  close(fin); close(fout);
end.
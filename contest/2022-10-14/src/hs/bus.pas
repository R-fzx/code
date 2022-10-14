program bus;
const
  maxn=100000+100;
var
  fin,fout:text;
  n,i:longint;
  ans:int64;
  f:array[0..maxn]of int64;
  a:array[0..maxn]of int64;
function min(x,y:longint):int64;
begin
 if x<y then exit(x)
   else exit(y);
end;
begin
  assign(fin,'bus.in'); reset(fin);
  assign(fout,'bus.out'); rewrite(fout);
  fillchar(f,sizeof(f),30);
  readln(fin,n);
  for i:=1 to n do
    read(fin,a[i]);
  f[1]:=a[1];
  ans:=a[1];
  for i:=2 to n do
    begin
      f[i]:=min(f[i-1],a[i]);
      inc(ans,f[i]);
    end;
  writeln(fout,ans);
  close(fin); close(fout);
end.

const
  inf = 'bus.in';
  ouf = 'bus.out';
  maxn = 1000000 + 5;

var
  i,j,k,n,m,p,q:longint;
  a:array[0..maxn] of longint;
  ans,min:int64;
  f1,f2:text;

begin
  assign(f1,inf); reset(f1);
  assign(f2,ouf); rewrite(f2);

  readln(f1,n);
  for i:=1 to n do
    read(f1,a[i]);
  close(f1);

  min:=maxlongint;
  ans:=0;
  for i:=1 to n do
    begin
      if a[i] < min then min:=a[i];
      ans:=ans + min;
    end;

  writeln(f2,ans);
  close(f2);
end.
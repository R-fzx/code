const
  inf = 'dark.in';
  ouf = 'dark.out';
  maxn = 10000 + 1;

var
  i,j,k,n,m,p,q:longint;
  x,y:array[0..maxn] of double;
  tmp,ans:double;
  f1,f2:text;

function dis(p,q:longint):double;
begin
  exit( sqrt( sqr(x[p] - x[q]) + sqr(y[p] - y[q]) )) ;
end;

begin
  assign(f1,inf); reset(f1);
  assign(f2,ouf); rewrite(f2);

  readln(f1,n);
  for i:=1 to n do
    readln(f1,x[i],y[i]);
  close(f1);

  ans:=dis(1,2);
  for i:=1 to n do
    for j:=i + 1 to n do
      begin
        tmp:=dis(i,j);
        if tmp < ans then ans:=tmp;
      end;

  writeln(f2,ans:0:2);
  close(f2);
end.
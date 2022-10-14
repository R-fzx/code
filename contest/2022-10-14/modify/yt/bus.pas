program ex_1;
var i,j,k,n,m:longint;
    f,g:array[0..100001] of longint;
    ip,op:text;
    ans:int64;
procedure qs(x,y:longint);
var i,j,k:longint;
begin
  i:=x;
  j:=y;
  k:=f[random(y-x)+x];
  repeat
    while f[i]<k do inc(i);
    while f[j]>k do dec(j);
    if i<=j then begin
      f[0]:=f[i]; f[i]:=f[j]; f[j]:=f[0];
      g[0]:=g[i]; g[i]:=g[j]; g[j]:=g[0];
      inc(i);
      dec(j);
    end;
  until i>=j;
  if i<y then qs(i,y);
  if x<j then qs(x,j);
end;
begin
  assign(ip,'bus.in');
  reset(ip);
  assign(op,'bus.out');
  rewrite(op);
  readln(ip,n);
  for i:=1 to n do begin
    read(ip,f[i]);
    g[i]:=i;
  end;
  qs(1,n);
  m:=n+1;
  for i:=1 to n do
    if g[i]<m then begin
      ans:=ans+int64(m-g[i])*int64(f[i]);
      m:=g[i];
    end;

  writeln(op,ans);
  close(ip);
  close(op);
end.

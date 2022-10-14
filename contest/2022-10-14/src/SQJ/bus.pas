program scott;
var
  a,f:array[0..1000000]of longint;
  i,n:longint;
  ans:int64;
  inf,outf:text;
begin
  assign(inf,'bus.in');
  assign(outf,'bus.out');
  reset(inf);
  rewrite(outf);
  readln(inf,n);
  f[0]:=9999999;
  ans:=0;
  for i:=1 to n do begin
    read(inf,a[i]);
    if a[i]<f[i-1] then f[i]:=a[i]
      else f[i]:=f[i-1];
    ans:=ans+f[i];
  end;
  writeln(outf,ans);
  close(inf);
  close(outf);
end.

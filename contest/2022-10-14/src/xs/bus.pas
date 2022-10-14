var
  a:array[1..100001]of longint;
  i,j,m,n,w:longint;
  ans:int64;
  fin,fout:text;
begin
  assign(fin,'bus.in');
  reset(fin);
  assign(fout,'bus.out');
  rewrite(fout);
  readln(fin,n);
  for i:=1 to n do
    read(fin,a[i]);
  a[n+1]:=-1;
  m:=a[1];
  ans:=m;
  for i:=2 to n do
    begin
      if a[i]<m then
        m:=a[i];
      ans:=ans+m;
    end;
  writeln(fout,ans);
  close(fin);
  close(fout);
end.

program ex;
var
  fin,fout:text;
  ans,min,n,x:int64;
  i:longint;
begin
  assign(fin,'bus.in');
  reset(fin);
  assign(fout,'bus.out');
  rewrite(fout);
  readln(fin,n);
  ans:=0;
  min:=maxlongint;
  for i:=1 to n do
  begin
    read(fin,x);
    if x<min then min:=x;
    ans:=ans+min;
  end;
  writeln(fout,ans);
  close(fin);
  close(fout);
end.

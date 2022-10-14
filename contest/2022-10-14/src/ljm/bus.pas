program bus;
var
  fin,fout:text;
  i,j,n:longint;
  k,ans,min:int64;
begin
  assign(fin,'bus.in');reset(fin);
  assign(fout,'bus.out');rewrite(fout);
  readln(fin,n);
  min:=maxlongint shr 3;
  ans:=0;
  for i:=1 to n do
  begin
    read(fin,k);
    if k<min then min:=k;
    ans:=ans+min;
  end;
  writeln(fout,ans);
  close(fin);close(fout);
end.
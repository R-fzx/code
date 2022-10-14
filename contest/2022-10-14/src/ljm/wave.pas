program wave;
const
  maxn=20+3;
var
  fin,fout:text;
  i,n,m:longint;
  c,tot:int64;
  used:array[0..maxn]of boolean;
  a:array[0..maxn]of longint;
procedure search(d:longint);
var
  j:longint;
begin
  if d=n+1 then
  begin
    inc(tot);
    if tot=c then
    begin
      for j:=1 to n-1 do write(fout,a[j],' ');
      writeln(fout,a[n]);
    end;
    exit;
  end;
  if d<=2 then
    for j:=1 to n do
      if not used[j] then
      begin
        used[j]:=true;
        a[d]:=j;
        search(d+1);
        if tot=c then exit;
        used[j]:=false;
      end
      else
  else
    if a[d-1]<a[d-2] then
      for j:=a[d-1]+1 to n do
        if not used[j] then
        begin
          used[j]:=true;
          a[d]:=j;
          search(d+1);
          if tot=c then exit;
          used[j]:=false;
        end
        else
    else
      for j:=a[d-1]-1 downto 1 do
        if not used[j] then
        begin
          used[j]:=true;
          a[d]:=j;
          search(d+1);
          if tot=c then exit;
          used[j]:=false;
        end;
end;

begin
  assign(fin,'wave.in');reset(fin);
  assign(fout,'wave.out');rewrite(fout);
  readln(fin,m);
  for i:=1 to m do
  begin
    readln(fin,n,c);
    tot:=0;
    fillchar(used,sizeof(used),false);
    search(1);
  end;
  close(fin);close(fout);
end.

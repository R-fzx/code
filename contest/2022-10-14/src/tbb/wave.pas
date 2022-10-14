program ex;
var
  fin,fout:text;
  tmp,n,m,l,i:longint;
  tot,c:int64;
  a:array[-1..21] of longint;
  used:array[0..21] of boolean;
procedure dfs(depth:longint);
var
  j:longint;
begin
  if tot=c then exit;
  if depth>n then
  begin
    inc(tot);
    if tot=c then
    begin
      for i:=1 to n do
        write(fout,a[i],' ');
      writeln(fout);
      exit;
    end;
    exit;
  end;

  for j:=1 to n do
  begin
    if tot=c then exit;
    if used[j]=false then
    begin
      if tmp>=2 then
      begin
        if ((j<a[tmp]) and (a[tmp]>a[tmp-1])) or ((j>a[tmp]) and (a[tmp]<a[tmp-1])) then
        begin
          inc(tmp);
          a[tmp]:=j;
          used[j]:=true;
          dfs(depth+1);
          dec(tmp);
          used[j]:=false;
        end
      end
      else
      begin
        inc(tmp);
        a[tmp]:=j;
        used[j]:=true;
        dfs(depth+1);
        dec(tmp);
        used[j]:=false;
      end;
    end;
  end;
end;
begin
  assign(fin,'wave.in');
  reset(fin);
  assign(fout,'wave.out');
  rewrite(fout);
  readln(fin,m);
  for l:=1 to m do
  begin
    readln(fin,n,c);
    fillchar(a,sizeof(a),0);
    fillchar(used,sizeof(used),false);
    tmp:=0;
    tot:=0;
    dfs(1);
  end;
  close(fin);
  close(fout);
end.

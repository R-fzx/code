program ex;
var
  fin,fout:text;
  tmp,n,m,l,i,j,k:longint;
  tot,c:int64;
  used:array[0..21] of boolean;
  f,g:array[0..20,0..20] of int64;
procedure dfs(x,l,r,y:longint;tot:int64);
var
  i,j,k:longint;
begin
  if x=0 then exit;
  if y=0 then
  begin
    for i:=l to r do
      if tot+g[x,i]>=c then begin
        j:=i;
        for k:=1 to n do begin
          if used[k]=false then dec(j);
          if j=0 then break;
        end;
        write(fout,' ',k);
        used[k]:=true;
        dfs(x-1,i,n-1,1-y,tot);
        break;
      end else tot:=tot+g[x,i];
  end else
    for i:=l to r do
      if tot+f[x,i]>=c then begin
        j:=i;
        for k:=1 to n do begin
          if used[k]=false then dec(j);
          if j=0 then break;
        end;
        write(fout,' ',k);
        used[k]:=true;
        dfs(x-1,1,i-1,1-y,tot);
        break;
      end else tot:=tot+f[x,i];
end;
begin
  assign(fin,'wave.in');
  reset(fin);
  assign(fout,'wave.out');
  rewrite(fout);
  readln(fin,m);
  f[1,1]:=int64(1);
  g[1,1]:=int64(1);
  for i:=2 to 20 do
    for j:=1 to i do
    begin
      for k:=1 to j-1 do
        f[i,j]:=g[i-1,k]+f[i,j];
      for k:=j to i-1 do
        g[i,j]:=f[i-1,k]+g[i,j];
    end;
  for i:=1 to m do
  begin
    readln(fin,n,c);
    fillchar(used,sizeof(used),false);
    tot:=0;
    for j:=1 to n do
    begin
      if tot+f[n,j]+g[n,j]>=c then
      begin
        used[j]:=true;
        write(fout,j);
        if f[n,j]+tot>=c then
        begin
          dfs(n-1,1,j-1,0,tot);
        end
        else
          dfs(n-1,j,n-1,1,tot+f[n,j]);
        break;
      end
      else
        tot:=tot+f[n,j]+g[n,j];
    end;
    writeln(fout);
  end;
  close(fin);
  close(fout);
end.

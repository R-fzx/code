var
  inp,outp:text;
  i,j,k,n,m,c,o,t:longint;
  a:array[1..20] of longint;
  used:array[1..20] of boolean;
  f:boolean;

procedure dfs(d:longint);
var
  i,j,k,s:longint;
begin
  if t=c then exit;
  if d>n then
    begin
      inc(t);
      if t=c then
       begin
         for i:=1 to n-1 do write(outp,a[i],' ');
         writeln(outp,a[n]);
         exit;
       end;
      exit;
    end;
  if (d=1)or(d=2) then
    begin
      for i:=1 to n do
       if not used[i] then
        begin
          a[d]:=i;
          used[i]:=true;
          dfs(d+1);
          used[i]:=false;
          a[d]:=0;
        end;
    end
  else
    begin
      if a[d-1]>a[d-2] then
       begin
        for i:=a[d-1]-1 downto 1 do
         if not used[i] then
           begin
             a[d]:=i;
             used[i]:=true;
             dfs(d+1);
             used[i]:=false;
             a[d]:=0;
             if t=c then exit;
           end;
       end
        else
          begin
            for i:=a[d-1]+1 to n do
             if not used[i] then
               begin
                 a[d]:=i;
                 used[i]:=true;
                 dfs(d+1);
                 used[i]:=false;
                 a[d]:=0;
                 if t=c then exit;
               end;
          end;
    end;
end;

begin
  assign(inp,'wave.in');reset(inp);
  assign(outp,'wave.out');rewrite(outp);
  readln(inp,m);
  for o:=1 to m do
    begin
      readln(inp,n,c);
      fillchar(used,sizeof(used),false);
      f:=true;
      t:=0;
      dfs(1);
    end;
  close(inp);close(outp);
end.

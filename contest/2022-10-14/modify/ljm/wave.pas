program wave;
const
  maxn=20+3;
var
  fin,fout:text;
  i,j,k,n,t,m,p,x:longint;
  c:int64;
  f:array[0..maxn,0..maxn,0..1]of int64;
  used:array[0..maxn]of boolean;
function get(u:longint):longint;
var
  l,v:longiwnt;
begin
  v:=0;
  for l:=1 to n do
  begin
    if not used[l] then inc(v);
    if v=u then exit(l);
  end;
end;

begin
  assign(fin,'wave.in');reset(fin);
  assign(fout,'wave.out');rewrite(fout);
  fillchar(f,sizeof(f),0);
  f[1,1,0]:=1; f[1,1,1]:=1;
  for i:=2 to 20 do
    for j:=1 to i do
    begin
      for k:=1 to j-1 do inc(f[i,j,1],f[i-1,k,0]);
      for k:=j to i do inc(f[i,j,0],f[i-1,k,1]);
    end;
  readln(fin,m);
  for t:=1 to m do
  begin
    readln(fin,n,c);
    fillchar(used,sizeof(used),false);
    p:=-1; x:=-1;
    for i:=n downto 1 do
      for j:=1 to i do
      begin
        if (p<>1) and ( (x=-1) or (j>=x) ) then
          if f[i,j,1]<c then dec(c,f[i,j,1])
          else
            begin
              x:=get(j);
              used[x]:=true;
              if p=-1 then write(fout,x)
              else write(fout,' ',x);
              x:=j;
              p:=1;
              break;
            end;
        if (p<>0) and ( (x=-1) or (j<x) ) then
          if f[i,j,0]<c then dec(c,f[i,j,0])
          else
            begin
              x:=get(j);
              used[x]:=true;
              if p=-1 then write(fout,x)
              else write(fout,' ',x);
              p:=0;
              x:=j;
              break;
            end;
      end;
      writeln(fout);
  end;
  close(fin);close(fout);
end.
program scott;
const
  maxx=400;
var
  head:array[0..10000002]of longint;
  next:array[1..10000000]of longint;
  ans,cf:array[0..1000000]of longint;
  hs:array[1..30]of longint;
  ss:array[1..30]of string;
  tot,n,i,j,min:longint;
  inf,outf:text;
  o,p:int64;
  s:string;
procedure dfs(len,h:longint);
var
  hh,kk,x,y:longint;
begin
  if len>i then exit;
  if len=i then begin
    y:=0;
    kk:=head[h];
    if  kk<>0 then begin
      writeln(outf,i);
      for x:=1 to ans[0] do write(outf,ss[ans[x]]);
      writeln(outf);
      close(inf);
      close(outf);
      halt;
    end;
    inc(tot);
    next[tot]:=kk;
    head[h]:=tot;
    exit;
  end;
  for x:=1 to n do begin
    inc(ans[0]);
    ans[ans[0]]:=x;
    hh:=length(ss[x]);
    p:=cf[hh];
    o:=h;
    dfs(len+hh,(((o*p)mod 10000003)+hs[x])mod 10000003);
    dec(ans[0]);
  end;
end;
begin
  assign(inf,'codes.in');
  assign(outf,'codes.out');
  reset(inf);
  rewrite(outf);
  readln(inf,n);
  min:=99999;
  for i:=1 to n do begin
    readln(inf,ss[i]);
    j:=length(ss[i]);
    if min>j then min:=j;
  end;
  for i:=1 to n-1 do begin
    for j:=i+1 to n do begin
      if ss[i]+ss[j]>ss[j]+ss[i] then begin
        s:=ss[i];
        ss[i]:=ss[j];
        ss[j]:=s;
      end;
    end;
  end;
  cf[0]:=1;
  cf[1]:=127;
  for i:=2 to maxx do cf[i]:=(cf[i-1]*127)mod 10000003;
  for i:=1 to n do begin
    hs[i]:=0;
    for j:=1 to length(ss[i]) do begin
      o:=ord(ss[i][j]);
      p:=cf[length(ss[i])-j+1];
      hs[i]:=(hs[i]+o*p)mod 10000003;
    end;
  end;
  for i:=min to maxx do begin
    dfs(0,0);
  end;
  close(inf);
  close(outf);
end.

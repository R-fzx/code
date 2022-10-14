program codes;
type
  tmp=^rec;
  rec=record
    s:string[100];
    next:tmp;
  end;
const
  nd=999997;
  nt=1547;
  maxn=300000;
var
  fin,fout:text;
  n,i,j,e,t,mile,tt:longint;
  st:array[0..20]of string[20];
  ha:array[0..nd-1]of tmp;
  g:array[0..maxn]of string[100];
  len:array[0..maxn]of longint;
  anst,ttt:string;
  anle:longint;
function better(x,y:string):boolean;
var
  l:longint;
begin
  l:=1;
  while true do
    begin
      if(x[l]='0')and(y[l]='1')then exit(true);
      if(x[l]='1')and(y[l]='0')then exit(false);
      inc(l);
    end;
  exit(false);
end;
procedure hash(k:longint; x:string[100]);
var
  z,y:tmp;
begin
  z:=ha[k];
  while z<>nil do
    begin
      if length(z^.s)=length(x) then
        if z^.s=x then
          if(length(x)<anle)or((length(x)=anle)and better(x,anst))then
            begin
              anst:=x;
              anle:=length(x);
              exit;
            end
            else exit;
      z:=z^.next;
    end;
  new(z);
  z^.s:=x;
  z^.next:=ha[k];
  ha[k]:=z;
end;

procedure search(x:string[100]);
var
  k,m,p:int64;
  xx:string[100];
begin
  xx:=x;
  k:=1; m:=0;
  while length(x)>0 do
    begin
      val(x[1],p);
      p:=(p * k)mod nd;
      m:=(m+p) mod nd;
      k:=k*2;
      delete(x,1,1);
    end;
  m:=(m * nt)mod nd;
  hash(m,xx);
end;
begin
  assign(fin,'codes.in'); reset(fin);
  assign(fout,'codes.out'); rewrite(fout);
  anle:=100000; anst:='9999999999999999999999999999999999999999999999999999';
  mile:=21;
  readln(fin,n);
  for i:=1 to n do
    begin
      readln(fin,st[i]);
      if length(st[i])<mile then
        mile:=length(st[i]);
      len[i]:=length(st[i]);
    end;
  for i:=1 to n do
    for j:=i+1 to n do
      if len[j]>len[i] then
        begin
          tt:=len[j]; len[j]:=len[i]; len[i]:=tt;
          ttt:=st[j]; st[j]:=st[i]; st[i]:=ttt;
        end;
  e:=1; t:=1;
  g[0]:='';
  repeat
    if(length(g[e])+mile>anle)and(anle<>0)then break;
    for j:=1 to n do
      begin
        inc(t);
        g[t]:=g[e]+st[j];
        search(g[t]);
      end;
    inc(e);
  until e>=t;
  writeln(fout,anle);
  writeln(fout,anst);
  close(fin); close(fout);
end.


































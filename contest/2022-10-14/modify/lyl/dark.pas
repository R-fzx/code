type
  point=record
          x,y:extended;
        end;
var
  a,dl,ls:array[0..200000]of point;
  i,j,m,n:longint;
  fin,fout:text;
procedure sort(l,r:longint);
var
  i,j:longint;
  mid:extended;
  tmp:point;
begin
  i:=l;
  j:=r;
  mid:=a[random(r-l)+l].x;
  while i<j do
    begin
      while a[i].x<mid do inc(i);
      while a[j].x>mid do dec(j);
      if i<=j then
        begin
          tmp:=a[i];
          a[i]:=a[j];
          a[j]:=tmp;
          inc(i);
          dec(j);
        end;
    end;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
function min(a,b:extended):extended;
begin
  if a<b then min:=a else min:=b;
end;
function calc(l,r:longint):extended;
var
  i,mid,op,cl,t,x,y:longint;
  o,s,v:extended;
begin
  if l=r then
    begin
      calc:=1e40;
      exit;
    end;
  mid:=(l+r)div 2;
  s:=(a[mid].x+a[mid+1].x)/2;
  o:=min(calc(l,mid),calc(mid+1,r));
  t:=mid+1;
  op:=1;
  cl:=0;
  v:=o;
  for i:=l to mid do
    if s-a[i].x<o then
      begin
        while (t<=r)and((a[t].x-s>o)or(a[i].y+o>a[t].y)) do
          begin
            if not(a[t].x-s>o) then
              begin
                inc(cl);
                dl[cl]:=a[t];
              end;
            inc(t);
          end;
        while (op<=cl)and(a[i].y-o>dl[op].y) do
          begin
            inc(op);
          end;
        for j:=op to cl do
          v:=min(v,sqrt(sqr(a[i].x-dl[j].x)+sqr(a[i].y-dl[j].y)));
      end;
  x:=mid+1;
  t:=l-1;;
  for i:=l to mid do
    begin
      while (x<=r)and(a[x].y<a[i].y) do
        begin
          inc(t);
          ls[t]:=a[x];
          inc(x);
        end;
      inc(t);
      ls[t]:=a[i];
    end;
  while (x<=r) do
    begin
      inc(t);
      ls[t]:=a[x];
      inc(x);
    end;
  for i:=l to r do
    a[i]:=ls[i];
  calc:=v;
end;
begin
  assign(fin,'dark.in');
  reset(fin);
  assign(fout,'dark.out');
  rewrite(fout);
  randomize;
  readln(fin,n);
  for i:=1 to n do
    readln(fin,a[i].x,a[i].y);
  sort(1,n);
  writeln(fout,calc(1,n)/2:0:2);
  close(fin);
  close(fout);
end.

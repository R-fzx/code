program ex;
var
  fin,fout:text;
  i,j,n:longint;
  x,y,x1,y1:array[0..200000] of int64;
  min,ans:double;
procedure qs(l,r:longint);
var
  i,j,mid,t:longint;
begin
  i:=l;
  j:=r;
  mid:=x[random(r-l+1)+l];
  repeat
    while x[i]<mid do inc(i);
    while x[j]>mid do dec(j);
    if i<=j then
    begin
      t:=x[i];
      x[i]:=x[j];
      x[j]:=t;
      t:=y[i];
      y[i]:=y[j];
      y[j]:=t;
      inc(i);
      dec(j);
    end;
  until i>j;
  if i<r then qs(i,r);
  if j>l then qs(l,j);
end;
procedure qs1(l,r:longint);
var
  i,j,mid,t:longint;
begin
  i:=l;
  j:=r;
  mid:=y1[random(r-l+1)+l];
  repeat
    while y1[i]<mid do inc(i);
    while y1[j]>mid do dec(j);
    if i<=j then
    begin
      t:=y1[i];
      y1[i]:=y1[j];
      y1[j]:=t;
      t:=x1[i];
      x1[i]:=x1[j];
      x1[j]:=t;
      inc(i);
      dec(j);
    end;
  until i>j;
  if i<r then qs1(i,r);
  if j>l then qs1(l,j);
end;
function dis(a,b:longint):double;
begin
  exit(sqrt(sqr(x[a]-x[b])+sqr(y[a]-y[b])));
end;
function dis1(a,b:longint):double;
begin
  exit(sqrt(sqr(x1[a]-x1[b])+sqr(y1[a]-y1[b])));
end;
function calc(l,r:longint):double;
var
  ans1,ans2:double;
  tot,mid:longint;
begin
  if r-l=1 then exit(dis(l,r));
  if r=l then exit(1e10);
  mid:=(l+r) div 2;
  ans1:=calc(l,mid);
  ans2:=calc(mid+1,r);
  if ans1<ans2 then min:=ans1
  else min:=ans2;
  tot:=0;
  for i:=l to r  do
  begin
    if (x[i]>(x[mid]-min)) and (x[i]<(x[mid]+min)) then
    begin
      inc(tot);
      x1[tot]:=x[i];
      y1[tot]:=y[i];
    end;
  end;
  qs1(1,tot);
  for i:=1 to tot do
  begin
    if i+1<=tot then
      if dis1(i,i+1)<min then min:=dis1(i,i+1);
    if i+2<=tot then
      if dis1(i,i+2)<min then min:=dis1(i,i+2);
    if i+3<=tot then
      if dis1(i,i+3)<min then min:=dis1(i,i+3);
  end;
  if min<ans then ans:=min;
  exit(ans);
end;
begin
  assign(fin,'dark.in');
  reset(fin);
  assign(fout,'dark.out');
  rewrite(fout);
  readln(fin,n);
  ans:=1e11;
  for i:=1 to n do
    readln(fin,x[i],y[i]);
  qs(1,n);
  calc(1,n);
  writeln(fout,(ans/2):0:2);
  close(fin);
  close(fout);
end.

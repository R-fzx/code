var
  a:array[0..200000,1..2] of longint;
  f:array[1..200000] of longint;
  t,i,j,n,k:longint;
  min,s:real;
  ip,op:text;

Procedure qsort(l,r,k:longint);
var i,j,mid:longint;
begin
  i:=l;j:=r;mid:=a[(i+j) div 2,k];
  repeat
    while a[i,k]<mid do inc(i);
    while a[j,k]>mid do dec(j);
    if i<=j then begin
      a[0]:=a[i];
      a[i]:=a[j];
      a[j]:=a[0];
      inc(i);
      dec(j);
    end;
  until i>j;
  if i<r then qsort(i,r,k);
  if l<j then qsort(l,j,k);
end;

begin
  assign(ip,'dark.in'); reset(ip);
  assign(op,'dark.out'); rewrite(op);
  readln(ip,n);
  for i:=1 to n do  read(ip,a[i,1],a[i,2]);
  qsort(1,n,1);
  fillchar(f,sizeof(f),0);
  f[1]:=0;
  t:=a[1,1];
  j:=0;
  for i:=2 to n do
    if a[i,1]<>t then begin
      inc(j);
      f[j]:=i-1;
      t:=a[i,1];
      qsort(f[j-1]+1,f[j],2);
    end;
  inc(j);
  f[j]:=i;
  qsort(f[j-1]+1,f[j],2);
  min:=1000000;
  k:=1;
  for i:=1 to n-1 do begin
    if i=f[k] then inc(k);
    s:=sqr(a[i,1]-a[i+1,1])+sqr(a[i,2]-a[i+1,2]);
    if s=0 then begin
      min:=0;
      break;
    end else s:=sqrt(s);
    if s<min then min:=s;
      for j:=f[k]+1 to f[k+1] do begin
        s:=sqr(a[i,1]-a[j,1])+sqr(a[i,2]-a[j,2]);
        if s=0 then begin
          min:=0;
          break;
       end else s:=sqrt(s);
        if s<min then min:=s;
      end;
  end;
  writeln(op,min:0:2);
  close(ip);
  close(op);
end.

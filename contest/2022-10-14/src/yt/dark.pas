program ex_1;
const
  err=1e-7;
var i,j,k,n,m:longint;
    x,y:array[0..200000] of double;
    len,x1,y1,ct,st:double;
    ip,op:text;

procedure qs(xx,yy:longint);
var i,j,k:longint;
    k1,k2:double;
begin
  i:=xx;
  j:=yy;
  k:=random(yy-xx)+xx;
  k1:=x[k];
  k2:=y[k];
  repeat
    while (x[i]-k1>err)or((abs(x[i]-k1)<err)and(y[i]-k2>err)) do inc(i);
    while (k1-x[j]>err)or((abs(x[j]-k1)<err)and(k2-y[j]>err)) do dec(j);
    if i<=j then begin
      x[0]:=x[i]; x[i]:=x[j]; x[j]:=x[0];
      y[0]:=y[i]; y[i]:=y[j]; y[j]:=y[0];
      inc(i);
      dec(j);
    end;
  until i>=j;
  if i<yy then qs(i,yy);
  if xx<j then qs(xx,j);
end;
begin
  assign(ip,'dark.in');
  reset(ip);
  assign(op,'dark.out');
  rewrite(op);
  readln(ip,n);
  ct:=0.5;
  st:=sqrt(0.75);
  for i:=1 to n do begin
    read(ip,x1);
    read(ip,y1);
    x[i]:=x1*ct-y1*st;
    y[i]:=x1*st+y1*ct;
  end;
  qs(1,n);
  len:=sqrt(sqr(x[2]-x[1])+sqr(y[2]-y[1]));;
  for i:=1 to n do begin
    for j:=i+1 to n do
      if x[j]-x[i]>len then break else
        if sqrt(sqr(x[j]-x[i])+sqr(y[j]-y[i]))<len then
          len:=sqrt(sqr(x[j]-x[i])+sqr(y[j]-y[i]));
  end;
  writeln(op,len/2:0:2);
  close(ip);
  close(op);
end.

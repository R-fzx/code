{$m 64000000}
program ex_1;
const
  err=1e-7;
var i,j,k,n,m:longint;
    x,y,a,b,c,d:array[0..200000] of double;
    ip,op:text;
    ans:double;
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
    while (k1-x[i]>err)or((abs(x[i]-k1)<err)and(k2-y[i]>err)) do inc(i);
    while (x[j]-k1>err)or((abs(x[j]-k1)<err)and(y[j]-k2>err)) do dec(j);
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
function dfs(l,r:longint):double;
var i,j,k,t,ll,rr:longint;
    min,lm,rm,mid:double;
begin
  if r-l<=2 then begin
    min:=maxlongint *maxlongint/2 ;
    for i:=l to r do
      for j:=i+1 to r do
        if sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]))<ans then
          ans:=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
    for i:=l to r do
      for j:=i+1 to r do
        if y[i]>y[j] then begin
          y[0]:=y[i]; y[i]:=y[j]; y[j]:=y[0];
          x[0]:=x[i]; x[i]:=x[j]; x[j]:=x[0];
        end;
    dfs:=ans;
  end else begin
    min:=maxlongint*maxlongint/2;
    k:=(l+r) shr 1;
    mid:=x[k];

    lm:=dfs(l,k);
    rm:=dfs(k+1,r);
    ll:=1;
    rr:=1;
    t:=0;
    for i:=k+1 to r do
      if x[i]-mid<ans then begin
        inc(t);
        a[t]:=x[i];
        b[t]:=y[i];
      end;
    for i:=l to k do begin
      while (y[i]-ans-(b[ll])>err)and(ll<t) do inc(ll);
      rr:=ll;
      while (y[i]+ans-b[ll]>err)and(rr<t) do inc(rr);
      if (ll<=t)and(rr<=t) THEN
      for j:=ll to rr do
        if sqrt(sqr(x[i]-a[j])+sqr(y[i]-b[j]))<ans then
          ans:=sqrt(sqr(x[i]-a[j])+sqr(y[i]-b[j]));
    end;
    t:=0;
    ll:=l;
    rr:=k+1;
    while (ll<=k)and(rr<=r) do
      if y[ll]<y[rr] then begin
        inc(t);
        a[t]:=x[ll];
        b[t]:=y[ll];
        inc(ll);
      end else begin
        inc(t);
        a[t]:=x[rr];
        b[t]:=y[rr];
        inc(rr);
      end;
    while ll<=k do begin
      inc(t);
      a[t]:=x[ll];
      b[t]:=y[ll];
      inc(ll);
    end;
    while rr<=r do begin
      inc(t);
      a[t]:=x[rr];
      b[t]:=y[rr];
      inc(rr);
    end;
    for i:=1 to t do begin
      x[i+l-1]:=a[i];
      y[i+l-1]:=b[i];
    end;
    dfs:=ans;
    if ans=0 then begin
      ans:=ans;
    end;
  end;
end;
begin
  assign(ip,'dark.in');
  reset(ip);
  assign(op,'dark.out');
  rewrite(op);
  readln(ip,n);
  for i:=1 to n do readln(ip,x[i],y[i]);
  qs(1,n);
  ans:=maxlongint *maxlongint;
  writeln(op,dfs(1,n)/2:0:2);
  close(ip);
  close(op);
end.

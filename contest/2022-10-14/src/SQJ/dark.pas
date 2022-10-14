program scott;
var
  x,y:array[1..200000]of longint;
  len:array[1..200000]of real;
  le,mx,my,i,j,n:longint;
  min,k:real;
  inf,outf:text;
function suan(x1,y1,x2,y2:int64):real;
begin
  suan:=sqrt(sqr(x1-x2)+sqr(y1-y2));
end;
procedure qs(l,r:longint);
var
  ll,rr,t:longint;
  mid,tt:real;
begin
  ll:=l;rr:=r;mid:=len[(l+r)div 2];
  repeat
    while (mid>len[ll]) do inc(ll);
    while (mid<len[rr]) do dec(rr);
    if ll<=rr then begin
      tt:=len[ll];
      len[ll]:=len[rr];
      len[rr]:=tt;
      t:=x[ll];
      x[ll]:=x[rr];
      x[rr]:=t;
      t:=y[ll];
      y[ll]:=y[rr];
      y[rr]:=t;
      inc(ll);
      dec(rr);
    end;
  until ll>rr;
  if ll<r then qs(ll,r);
  if l<rr then qs(l,rr);
end;
begin
  assign(inf,'dark.in');
  assign(outf,'dark.out');
  reset(inf);
  rewrite(outf);
  readln(inf,n);
  mx:=9999999;my:=9999999;
  for i:=1 to n do begin
    readln(inf,x[i],y[i]);
    if (x[i]<mx)or((x[i]=mx)and(y[i]<my))then begin
      mx:=x[i];
      my:=y[i];
    end;
  end;
  for i:=1 to n do begin
    len[i]:=suan(x[i],y[i],mx,my);
  end;
  qs(1,n);
  min:=len[2];
  le:=trunc(min);
  for i:=2 to n do begin
    for j:=i+1 to n do begin
      if trunc(len[j]-len[i])>le then break;
      k:=suan(x[i],y[i],x[j],y[j]);
      if k<min then begin
        min:=k;
        le:=trunc(min);
      end;
    end;
  end;
  writeln(outf,min/2:0:2);
  close(inf);
  close(outf);
end.

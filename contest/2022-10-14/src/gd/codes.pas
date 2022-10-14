var fin,fou:text;
    ans,k,min,open,closed,n,i,j:longint;
    ansst,st:string;
    s:array[0..30]of string;
    f:array[0..30,0..30]of longint;
    l:array[0..30]of longint;
    li,lj:array[1..30000]of integer;
    ast:array[0..30,0..30]of string;
begin
assign(fin,'codes.in');
assign(fou,'codes.out');
reset(fin);
rewrite(fou);
  readln(fin,n);
  for i:=1 to n do begin
    readln(fin,s[i]);
    l[i]:=length(s[i]);
    for j:=0 to l[i] do
      f[i,j]:=maxlongint;
  end;
  closed:=0;
  for i:=1 to n do
    for j:=1 to n do begin
      if i=j then continue;
      if pos(s[i],s[j])<>1 then continue;
        f[j,l[j]-l[i]]:=l[i];
        inc(closed);
        li[closed]:=j;
        lj[closed]:=l[j]-l[i];
        ast[j,l[j]-l[i]]:=s[i];
  end;

  open:=0;
  closed:=1;
  min:=maxlongint;
  repeat
    inc(open);
    i:=li[open];
    j:=lj[open];
    st:=copy(s[i],l[i]-j+1,j);
    if j=0 then
      if (length(ast[i,j])<min)or
         ((length(ast[i,j])=min)and(ast[i,j]<ast[ans,0])) then begin
           min:=length(ast[i,j]);
           ans:=i;
      end;
    if length(ast[i,j]+st)>min then continue;
    for k:=1 to n do begin
      if pos(s[k],st)<>1 then continue;
        if (f[i,j-l[k]]=f[i,j]+l[k]) then
          if ast[i,j]+s[k]<ast[i,j-l[k]] then begin
            inc(closed);
            li[closed]:=i;
            lj[closed]:=j-l[k];
            ast[i,j-l[k]]:=ast[i,j]+s[k];
          end;

        if f[i,j-l[k]]>f[i,j]+l[k] then begin
           f[i,j-l[k]]:=f[i,j]+l[k];
          inc(closed);
          li[closed]:=i;
          lj[closed]:=j-l[k];
          ast[i,j-l[k]]:=ast[i,j]+s[k];
        end;
    end;
     for k:=1 to n do begin
      if pos(st,s[k])<>1 then continue;
        if f[k,l[k]-j]=f[i,j]+j then
          if ast[i,j]+st<ast[k,l[k]-j] then begin
            inc(closed);
            li[closed]:=k;
            lj[closed]:=l[k]-j;
            ast[k,l[k]-j]:=ast[i,j]+st;
          end;
        if f[k,l[k]-j]>f[i,j]+j then begin
           f[k,l[k]-j]:=f[i,j]+j;
          inc(closed);
          li[closed]:=k;
          lj[closed]:=l[k]-j;
          ast[k,l[k]-j]:=ast[i,j]+st;
        end;
    end;
  until open=closed;
  writeln(fou,min);
  writeln(fou,ast[ans,0]);
close(fin);
close(fou);
end.
